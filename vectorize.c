#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "h-define.h"
#include "h-type.h"
#include "defines.h"
#include "externs.h"

static const char *TEMP_GAMEFILE = "GAMEMAPS.WL6";
static const char *TEMP_MAPTEMP  = "MAPTEMP.TMP";
static const char *TEMP_HEADFILE = "MAPHEAD.WL6";
static uint16_t RLEW_TAG = 0xABCD;
static uint8_t no_tile = 48;
static uint8_t no_obj  = 0;
static FILE *map_fp = NULL;
static FILE *head_fp = NULL;
static int current_map; // 1 to 60
static int current_offset;
static uint16_t solid_plane[64 * 64 + 8];
static uint16_t thing_plane[64 * 64 + 8];
static const char *level_name;
static uint8_t PL_START = 2;
static uint8_t max_things = 149;

int is_exit(int feat)
{
	return feat == FEAT_MORE;
}

int is_floor(int feat)
{
	return (feat == FEAT_FLOOR 
			|| feat == FEAT_LESS
			|| feat == FEAT_MORE
			|| feat == FEAT_TRAP_HEAD);
}

int is_floor_ish(int feat)
{
	return (feat == FEAT_FLOOR 
			|| feat == FEAT_DOOR_HEAD
			|| feat == FEAT_SECRET
			|| feat == FEAT_LESS
			|| feat == FEAT_MORE
			|| feat == FEAT_TRAP_HEAD);
}

int is_door(int feat) 
{
	return (feat == FEAT_DOOR_HEAD
			|| feat == FEAT_SECRET);
}

static void wolf_put_u16(uint16_t val, FILE *fp)
{
    fputc(val & 0xFF, fp);
    fputc((val >> 8) & 0xFF, fp);
}

static void wolf_put_u32(uint32_t val, FILE *fp)
{
    fputc(val & 0xFF, fp);
    fputc((val >> 8) & 0xFF, fp);
    fputc((val >> 16) & 0xFF, fp);
    fputc((val >> 24) & 0xFF, fp);
}

static void wolf_put_n_string(const char *str, int max_len, FILE *fp)
{
    for (; *str && max_len > 0; max_len--)
    {
        fputc(*str++, fp);
    }

    for (; max_len > 0; max_len--)
    {
        fputc(0, fp);
    }
}

int rle_compress_plane(uint16_t *plane, int src_len)
{
    uint16_t       *dest = plane + PL_START;
    const uint16_t *src  = plane + PL_START;
    const uint16_t *endp = plane + PL_START + (src_len / 2);

    while (src < endp)
    {
        // determine longest run
        int run = 1;

        while (src + run < endp && run < 100 && src[run - 1] == src[run])
        {
            run++;
        }

        if (run > 3)
        {
            // Note: use src[2] since src may == dest, hence src[0] and src[1]
            //       would get overwritten by the tag and count.

            *dest++ = RLEW_TAG; // tag
            *dest++ = run;      // count
            *dest++ = src[2];   // value

            src += run;
        }
        else
        {
            for (; run > 0; run--)
            {
                *dest++ = *src++;
            }
        }
    }

    int dest_len = 2 * (dest - plane);

    plane[0] = dest_len + 2; // compressed size (bytes)
    plane[1] = src_len;      // expanded size (bytes)

    return dest_len + 4;     // total size
}

static void wolf_write_plane(uint16_t *plane, int *offset, int *length)
{
    *offset = (int)ftell(map_fp);

    *length = rle_compress_plane(plane, 64 * 64 * 2);

    fwrite(plane, *length, 1, map_fp);
}

static void wolf_write_blank_plane(int *offset, int *length)
{
    *offset = (int)ftell(map_fp);

    wolf_put_u16(3 * 2 + 2, map_fp);   // compressed size + 2
    wolf_put_u16(64 * 64 * 2, map_fp); // expanded size

    wolf_put_u16(RLEW_TAG, map_fp);    // tag
    wolf_put_u16(64 * 64, map_fp);     // count
    wolf_put_u16(0, map_fp);           // value

    *length = (int)ftell(map_fp);
    *length -= *offset;
}

static void wolf_write_map(void)
{
    wolf_put_n_string("AngWolf", 64, map_fp);

    int plane_offsets[3];
    int plane_lengths[3];

    wolf_write_plane(solid_plane, plane_offsets + 0, plane_lengths + 0);
    wolf_write_plane(thing_plane, plane_offsets + 1, plane_lengths + 1);
    wolf_write_blank_plane(plane_offsets + 2, plane_lengths + 2);

    current_offset = (int)ftell(map_fp);

	wolf_put_u32(plane_offsets[0], map_fp);
    wolf_put_u32(plane_offsets[1], map_fp);
    wolf_put_u32(plane_offsets[2], map_fp);

    wolf_put_u16(plane_lengths[0], map_fp);
    wolf_put_u16(plane_lengths[1], map_fp);
    wolf_put_u16(plane_lengths[2], map_fp);

    // width and height
    wolf_put_u16(64, map_fp);
    wolf_put_u16(64, map_fp);

    wolf_put_n_string("Custom Map", 16, map_fp);

    wolf_put_n_string("!ID!", 4, map_fp);
}

static void wolf_write_head(void)
{
    // offset to map data (info struct)
   wolf_put_u32(current_offset, head_fp);
}

static void wolf_block(int x, int y, int tile, int obj)
{
    solid_plane[PL_START + y * 64 + x] = tile;
    thing_plane[PL_START + y * 64 + x] = obj;
}

static void wolf_finish_maps()
{
    // set remaining map offsets to zero (no map)
    for (; current_map <= 100; current_map++)
    {
        wolf_put_u32(0, head_fp);
    }

    fclose(map_fp);
    fclose(head_fp);

    map_fp = head_fp = NULL;
}

void wolf_start_maps()
{
	map_fp  = fopen(TEMP_GAMEFILE, "wb");
	head_fp = fopen(TEMP_HEADFILE, "wb");

	if (!map_fp || !head_fp)
		abort();

	// the maphead file always begins with the RLE tag
	wolf_put_u16(RLEW_TAG, head_fp);
		
	current_map    = 1;
    current_offset = 0;
}

void wolf_begin_level()
{
	for (int i = 0; i < 64 * 64; i++)
	{
		solid_plane[PL_START + i] = no_tile;
		thing_plane[PL_START + i] = no_obj;
	}
}

void wolf_end_level()
{
	wolf_write_map();
    wolf_write_head();
    current_map++;
}

int check_tile_direction(int x, int y)
{
	int left_x = 0;
	int right_x = 63;
	int top_y = 63;
	int bottom_y = 0;
	if (x > 0)
		left_x = x - 1;
	if (x < 63)
		right_x = x + 1;
	if (y > 0)
		bottom_y = y - 1;
	if (y < 63)
		top_y = y + 1;
	if (!(is_floor_ish(cave_feat[y][left_x]) || is_floor_ish(cave_feat[y][right_x]))) // We want N/S
		return 1;
	else // We want E/W
		return 0;
}

void wolf_do_level_blocks()
{
	for (int x = 0; x < 63; x++)
	{
		for (int y = 0; y < 63; y++)
		{
			int tile = no_tile;
			int obj = no_obj;
			if (is_exit(cave_feat[y][x]))
				tile = 21;
			else if (is_door(cave_feat[y][x]))
				tile = 90 + check_tile_direction(x, y);
			else if (is_floor_ish(cave_feat[y][x]))
				tile = 0;
			else
				tile = 12;
			if (cave_m_idx[y][x])
				obj = cave_m_idx[y][x];
			else if (cave_o_idx[y][x])
				obj = cave_o_idx[y][x];
			wolf_block(x, y, tile, obj);
		}
	}
}

void vectorize() 
{
	wolf_start_maps();
	// TODO: Level count from args
	for (int i = 0; i < 1; i++)
	{
		wolf_begin_level();
		wolf_do_level_blocks();
		wolf_end_level();
	}
	wolf_finish_maps();
}

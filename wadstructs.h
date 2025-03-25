#pragma once

#pragma pack(push, 1)
typedef struct 
{
	char wad_type[4]; /* should be "PWAD" */
	int32_t num_lumps;
	int32_t dir_start;
} Wad_Header;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	int32_t lump_start;
	int32_t lump_size;
	char lump_name[8];
} Lump_Entry;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	int16_t x;
	int16_t y;
	int16_t angle;
	int16_t type;
	int16_t options;
} Thing;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	int16_t from_vertex;
	int16_t to_vertex;
	int16_t flags;
	int16_t type;
	int16_t tag;
	int16_t right_sidedef_idx;
	int16_t left_sidedef_idx; /* -1 if no 2nd sidedef */
} Linedef;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	int16_t x_texture_off;
	int16_t y_texture_off;
	char upper_texture[8];
	char lower_texture[8];
	char normal_texture[8];
	int16_t sector;
} Sidedef;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	int16_t x;
	int16_t y;
} Vertex;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	int16_t floor_height;
	int16_t ceiling_height;
	char floor_texture[8];
	char ceiling_texture[8];
	int16_t brightness;
	int16_t special;
	int16_t tag;
} Sector;
#pragma pack(pop)
#ifndef WADSTRUCTS_H
#define WADSTRUCTS_H

#pragma pack(push, 1)
typedef struct 
{
	char wad_type[4]; /* should be "PWAD" */
	long num_lumps;
	long dir_start;
} Wad_Header;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	long lump_start;
	long lump_size;
	char lump_name[8];
} Lump_Entry;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	short int x;
	short int y;
	short int angle;
	short int type;
	short int options;
} Thing;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	short int from_vertex;
	short int to_vertex;
	short int flags;
	short int type;
	short int tag;
	short int right_sidedef_idx;
	short int left_sidedef_idx; /* -1 if no 2nd sidedef */
} Linedef;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	short int x_texture_off;
	short int y_texture_off;
	char upper_texture[8];
	char lower_texture[8];
	char normal_texture[8];
	short int sector;
} Sidedef;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	short int x;
	short int y;
} Vertex;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	short int floor_height;
	short int ceiling_height;
	char floor_texture[8];
	char ceiling_texture[8];
	short int brightness;
	short int special;
	short int tag;
} Sector;
#pragma pack(pop)

#endif // WADSTRUCTS_H

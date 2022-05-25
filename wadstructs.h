#ifndef __WADSTRUCTS_H_
#define __WADSTRUCTS_H_

typedef struct 
{
	char wad_type[4]; /* should be "PWAD" */
	long num_lumps;
	long dir_start;
} __attribute__((packed)) Wad_Header;

typedef struct 
{
	long lump_start;
	long lump_size;
	char lump_name[8];
} __attribute__((packed)) Lump_Entry;

typedef struct
{
	short int x;
	short int y;
	short int angle;
	short int type;
	short int options;
} __attribute__((packed)) Thing;

typedef struct
{
	short int from_vertex;
	short int to_vertex;
	short int flags;
	short int type;
	short int tag;
	short int right_sidedef_idx;
	short int left_sidedef_idx; /* -1 if no 2nd sidedef */
} __attribute__((packed)) Linedef;

typedef struct
{
	short int x_texture_off;
	short int y_texture_off;
	char upper_texture[8];
	char lower_texture[8];
	char normal_texture[8];
	short int sector;
} __attribute__((packed)) Sidedef;

typedef struct
{
	short int x;
	short int y;
} __attribute__((packed)) Vertex;

typedef struct
{
	short int floor_height;
	short int ceiling_height;
	char floor_texture[8];
	char ceiling_texture[8];
	short int brightness;
	short int special;
	short int tag;
} __attribute__((packed)) Sector;

#endif __WADSTRUCTS_H_

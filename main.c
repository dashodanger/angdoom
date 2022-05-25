#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "h-define.h"
#include "h-type.h"
#include "defines.h"
#include "externs.h"

int main(int argc, char** argv)
{
	int x, y;
	
	srand(time(NULL));

	generate_cave();

	
	for(y=0; y < DUNGEON_HGT; y++) {
		for(x=0; x < DUNGEON_WID; x++) {
			if(cave_feat[y][x] >= FEAT_WALL_EXTRA && cave_feat[y][x] <= FEAT_PERM_SOLID)
				printf("#");
			else if(cave_feat[y][x] >= FEAT_MAGMA && cave_feat[y][x] <= FEAT_QUARTZ_K)
				printf("%%");
			else if(cave_feat[y][x] == FEAT_DOOR_HEAD || cave_feat[y][x] == FEAT_SECRET)
				printf("+");
			else if(cave_feat[y][x] == FEAT_DOOR_TAIL) 
				printf("'");
			else if(cave_feat[y][x] == FEAT_TRAP_HEAD)
				printf("^");
			else if(cave_feat[y][x] == FEAT_LESS)
				printf("<");
			else if(cave_feat[y][x] == FEAT_MORE)
				printf(">");
			else if(cave_feat[y][x] == FEAT_FLOOR) 
				printf(".");
			else if(cave_feat[y][x] == FEAT_FLOOR) 
				printf("?");
		}
		printf("\n");
	}

	/*for(y=0; y < DUNGEON_HGT; y++) {
		for(x=0; x < DUNGEON_WID; x++) {
			printf("%i", cave_sector_map[y][x] % 10);
		}
		printf("\n");
	}*/	

	vectorize();

	return 0;
}

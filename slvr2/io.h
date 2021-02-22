// Header File
// Created 2/16/2021; 8:13:07 AM
// Contains IO routines for reading sprite/palatte/room/level data stored in appvars.

#include<tigcclib.h>

//Opens the file LZDATA\INDEX.LOZ to determine the starting room (If no save is located)
unsigned short load_index(void){
	char path[18];
	sprintf(path,"%s\\INDEX",dir);
	FILE*f=fopen(path,"rb");
	if(!f)return 0;
	unsigned short ret;
	fread(&ret,sizeof(unsigned short),1,f);
	return ret;
}

//Pulls new tile sprite data into RAM. Does not check if already loaded, so can
//be used to reload data in case of corruption
void load_palette(void){
	char path[18];
	sprintf(path,"%s\\LP%d",dir,current_room.palette);
	FILE * f = fopen(path, "rb");
	if(!f)return;
	//read id and check it
	unsigned short id;
	fread(&id,sizeof(unsigned short),1,f);
	if(id!=current_room.palette)return;
	//read in tile sprite data ~> should be padded to make full size
	fread(tilesprites,256*32*sizeof(unsigned short),1,f);
	//read in tile rule data.
	fread(tile_rules,512*sizeof(struct ztile_t),1,f);
	fclose(f);
}

//0 means no shift, 1 up 2 left 3 right 4 down
void load_room(unsigned short which){
	char path[18];
	sprintf(path,"%s\\LR%d",dir,which);
	FILE*f = fopen(path,"rb");
	if(!f)return;
	//read in the id number.
	fread(&current_room.id,sizeof(unsigned short),1,f);
	//check it
	if(which!=current_room.id)return;
	//Read north room
	fread(&current_room.north_room,sizeof(unsigned short),1,f);
	//read east room
	fread(&current_room.east_room,sizeof(unsigned short),1,f);
	//read south room
	fread(&current_room.south_room,sizeof(unsigned short),1,f);
	//lire west room
	fread(&current_room.west_room,sizeof(unsigned short),1,f);
	//Have the palette
	fread(&current_room.palette,sizeof(unsigned short),1,f);
	MoveTo(0,0);
	//printf("%d",current_room.palette);
	//while(!_keytest(RR_2ND));
	//read the tiles
	fread(grid,256*sizeof(unsigned short),1,f);
	//read the clipping data
	fread(clip1,256*sizeof(unsigned char),1,f);
	fread(clip2,256*sizeof(unsigned char),1,f);
	//TODO read and load stair data
	//TODO read and load enemy data
	//TODO read and load doors/warp tiles
	//TODO read and load NPC data
	//Load the new palette if needed.
	if(current_palette!=current_room.palette){
		load_palette();
	}
	fclose(f);
}
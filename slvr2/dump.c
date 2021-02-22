// C Source File
// Created 2/16/2021; 9:57:25 AM

#include <tigcclib.h>

//DUMP program to create data files on calc.
#include "makefiles.h"

void write_palette_Hyrule_Castle(void){
	FILE* f = fopen("LZDATA\\LP3","wb");
	unsigned short id=3;
	fwrite(&id,sizeof(unsigned short),1,f);
	fwrite(hyrule_castle_tile_sprites,256*32*sizeof(unsigned short),1,f);
	fwrite(tiles_hyrule_castle,512*sizeof(struct ztile_t),1,f);
	fclose(f);
}



void write_index(void){
	FILE* f = fopen("LZDATA\\INDEX","wb");
	unsigned short id=0;
	fwrite(&id,sizeof(unsigned short),1,f);
	fclose(f);
}

void write_link(){
	FILE* f = fopen("LZDATA\\PLAYER","wb");
	fwrite(link_pic_light,4*7*16*sizeof(unsigned short),1,f);
	fwrite(link_pic_dark,4*7*16*sizeof(unsigned short),1,f);
	fwrite(link_pic_mask,4*7*16*sizeof(unsigned short),1,f);
	fclose(f);
}

void write_room_0(void){
	FILE* f = fopen("LZDATA\\LR0","wb");
	unsigned short a=0,b=0,c=0,d=0,e=3,g=0;
	fwrite(&g,sizeof(unsigned short),1,f);
	fwrite(&a,sizeof(unsigned short),1,f);
	fwrite(&b,sizeof(unsigned short),1,f);
	fwrite(&c,sizeof(unsigned short),1,f);
	fwrite(&d,sizeof(unsigned short),1,f);
	fwrite(&e,sizeof(unsigned short),1,f);
	unsigned const short grid[16][16]={
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,8,9,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,10,11,0,0,0,0,0,0,0}	
	};
	unsigned const char c1[16][16]={
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,8,9,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	
	};
	unsigned const char c2[16][16]={
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,1,14,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	
	};
	fwrite(grid,256*sizeof(unsigned short),1,f);
	fwrite(c1,256*sizeof(unsigned char),1,f);
	fwrite(c2,256*sizeof(unsigned char),1,f);
}

void t_main(void){
	write_index();
	write_room_0();
	write_palette_Hyrule_Castle();
	write_link();
}
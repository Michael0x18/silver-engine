// Header File
// Created 2/16/2021; 2:10:31 PM
#include<tigcclib.h>

#define LINK_DIR_UP 0
#define LINK_DIR_RIGHT 1
#define LINK_DIR_DOWN 2
#define LINK_DIR_LEFT 3

#define LINK_STATE_NORMAL 0
#define LINK_STATE_WALK 1
#define LINK_STATE_THRUST 2
#define LINK_STATE_THRUST2 3
#define LINK_STATE_FLIP1 4		//---+
#define LINK_STATE_FLIP2 5		//---+----Not implemented yet
#define LINK_STATE_FLIP3 6		//---+
#define LINK_STATE_SPIN1 7		//---+
#define LINK_STATE_SPIN2 8		//---+
#define LINK_STATE_SPIN3 9		//---+
#define LINK_STATE_SPIN4 8		//---+
#define LINK_STATE_SPIN5 11		//---+
#define LINK_STATE_SPIN6 12		//---+
#define LINK_STATE_SPIN7 13		//---+
#define LINK_STATE_SPIN8 14		//---+


unsigned short link_dir;
unsigned short dir_lock;
unsigned short link_state;

//DIR STATE -
static unsigned short link_pic_light[4][7][16];

static unsigned short link_pic_dark[4][7][16];

static unsigned short link_pic_mask[4][7][16];

void draw_player(void* light,void* dark,short x, short y){
	if(link_state<=LINK_STATE_THRUST2){
		Sprite16_AND_R(x,y,16,link_pic_mask[link_dir][link_state],light);
		Sprite16_AND_R(x,y,16,link_pic_mask[link_dir][link_state],dark);
		Sprite16_OR_R(x,y,16,link_pic_light[link_dir][link_state],light);
		Sprite16_OR_R(x,y,16,link_pic_dark[link_dir][link_state],dark);
	}
}

void read_player_sprites(){
	char path[18];
	sprintf(path,"%s\\PLAYER",dir);
	FILE* f = fopen(path,"rb");
	fread(link_pic_light,4*7*16*sizeof(unsigned short),1,f);
	fread(link_pic_dark,4*7*16*sizeof(unsigned short),1,f);
	fread(link_pic_mask,4*7*16*sizeof(unsigned short),1,f);
	fclose(f);
}
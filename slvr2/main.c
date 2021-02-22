// C Source File
// Created 2/12/2021; 10:03:10 AM
// This file, as well as all others in this project, is licensed under the GNU GENERAL PUBLIC LICENSE
#include "main.h"
//Old tilemap engine
//#include "sprites.h"
#include "tile.h"
#include "io.h"
#include "player.h"
#include "clips.h"

INT_HANDLER save_int_1;

#define C89_92V200(x,y) (y)
#define HEIGHT C89_92V200(100,128)
#define WIDTH  C89_92V200(160,240)

void sleep(UINT millis){
	while(millis--){
		pokeIO(0x600005,0b10101);
	}
}

void print_slow(char* s){
	short i = 0;
	short skip = 0;
	while(s[i++]!=0){
		printf("%c",s[i-1]);
		if(skip || _keytest(RR_ALPHA)){
			skip=1;
			continue;
		}
		if(_keytest(RR_2ND) || _keytest(RR_SHIFT)){
			sleep(10);
		}else{
			sleep(25);
		}
	}
}

void run_intro(void){
	ClrScr();
	MoveTo(0,0);
	FontSetSys(0);
	//const char* message = "Long ago, at the beginning of the world,\nthere were two realms, the dark and the\nlight. They fought a constant war for\nmany eons, until finally the Twelve\nMages banded together to drive the\nDarkness from the land. The Darkness\nwas sealed in Daemonheim, and buried\ndeep beneath the earth. The mages, their\njob complete, departed the realm for the\nunknown lands beyond. Thousands of years\npassed, and though their names and\nmemories faded into the mist of\nobscurity and were forgotten, their work\nstood strong. It weathered countless\ncenturies, holding the forces of\nDarkness at bay. But the Evil Beneath\nnever sleeps. The daemon lord Or'kuz had\nsworn to return as he sank beneath the\nsoil. Only the weakening barriers of the\nancient Spell hold him under, and they\nare close to failing.\nMonsters are already rising from below.\nBut all hope is not lost.\nA prophecy, spoken by the first, last,\nand greatest of the twelve, spoken as\nhe boarded the ship which was to bear\nhim forever from the circles of the\nworld, tells of a Champion of the Light\nwho will retrieve the Sword of Ages from\nits hiding place, complete the crown of\nthe first King, and bring eternal peace\nto the Realm of Light by completing the\nwork started by the Twelve...\nFor they sought to destroy Or'kuz, but\nthey could only seal him away.\nGo then, Champion of the Light!\nGo forth, and face your destiny!";
	//print_slow(message);
	//while(!(_keytest(RR_2ND) || _keytest(RR_SHIFT) || _keytest(RR_ESC) || _keytest(RR_DIAMOND))){
	//	sleep(10);
	//}
}

int run_splash(void){
	ClrScr();
	FontSetSys(2);
	MoveTo(0,0);
	printf("SILVER 0.1");
	while(!_keytest(RR_ENTER));
	return 0;
}

unsigned short square1[]={
	0x0000,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x0000,
};
unsigned short square2[]={0x03E0,0x0410,0x0D8C,0x160A,0x15EA,0x17FA,0x13F2,0x0924,0x0924,0x140A,0x27FA,0x2C22,0x1824,0x0F18,0x18FC,0x0FF8};
unsigned short square3[]={~0x03E0,~0x07F0,~0x0FFC,~0x1FFE,~0x1FFE,~0x1FFE,~0x1FFE,~0x0FFC,~0x0FFC,~0x1FFE,~0x3FFE,~0x3FFE,~0x1FFC,~0x0FF8,~0x1FFC,~0x0FF8};

inline short isBit(void* buffer, short x, short y){
	//              32 wide     start block * 2 size
	void* base = buffer+32*y + (x/16)*2;
	unsigned short offset = ((unsigned)x)%16;//Offset from start of base block
	
	unsigned short val = *((unsigned short*)base);
	
	//Number that gets ANDed with the block to test.
	unsigned short test = 1<<offset;
	return ((val&test)>0)?1:0;
}

void draw(){
	//Allocate RAM for the clipping planes
	create_buffers();
	//Fetch player sprites from a file
	read_player_sprites();
	//Initialize player variables
	short player_x = 80;
	short player_y = 50;
	
	//Read the start room data into memory
	load_room(load_index());
	//Update the drawing regions.
	update_draw_planes();
	//Construct the clipping planes for the room.
	//update_clipping_planes();
	//Allocate memory for the BG and FG grayscale vscreen.
	printf(" Allocating RAM");
	void* bloc = malloc(BIG_VSCREEN_SIZE*4+LCD_SIZE*2);
	//The mask doesn't have to be a grayscale one -> saves 4kb of RAM.
	void* bl2 = malloc(BIG_VSCREEN_SIZE);
	//Three Tilemap planes from ExtGraph
	Plane fg_plane,bg_plane,fg_mask;
	printf("ALLOCATED");
	//Link background plane to background tile array.
	bg_plane.matrix=bg_tiles;
	//Tiles are 16x16
	bg_plane.width=16;
	//Link bg plane to the sprite array. TODO ensure that the VScreen is updated when palatte switching.
	bg_plane.sprites=tilesprites;
	//Link the bg plane to the first section of the virtual screen.
	bg_plane.big_vscreen=bloc+LCD_SIZE*2;
	//Force update -> Force update big screen. Needed, because I'm changing the tile sprites.
	
	//Link the foreground plane with the appropriate grid.
	fg_plane.matrix=fg_tiles;
	//Same sized sprites as BG; using bitmasking to achieve sub-sprite rendering.
	fg_plane.width=16;
	//MAYBE shift the sprites if there are some that only show up in plane 1, or plane 2, etc.
	fg_plane.sprites=tilesprites;
	//Link it.
	fg_plane.big_vscreen=bloc+LCD_SIZE*2+BIG_VSCREEN_SIZE*2;//note to self: the *2 is because x2 gray planes.
	//See above.
	fg_plane.force_update=1;
	
	//Link the mask to the tiles.
	fg_mask.matrix=fg_mask_tiles;
	fg_mask.width=16;
	fg_mask.sprites=masks;
	//Buffer isn't as big because it doesn't need to be grayscale.
	fg_mask.big_vscreen=bl2;
	fg_mask.force_update=1;
	
	//TODO add some kind of a check so you don't try to overwrite null buffers.
	printf("Engaging main loop");
	GrayOn();
	printf(" NOW!\n");
	while(1){
		//Initialize window boundary
		short ix = player_x-80;
		short iy = player_y-50;
		//Shift window boundary if off left or top of screen
		if(ix<0)ix=0;
		if(iy<0)iy=0;
		//We're doing this for the 89, so the screen is 160x100.
		if(ix>16*16-160)ix=16*16-160;
		if(iy>16*16-100)iy=16*16-100;
		
		
		//Apply the background plane
		DrawPlane(ix,iy,&bg_plane,bloc,TM_GRPLC89,TM_G16B);
		
		//Ensuite, ecrivez "le player"
		draw_player(bloc,bloc+LCD_SIZE,player_x-ix-8,player_y-iy-8);
		//Sprite16(player_x-ix-8,player_y-iy-8,16,link_pic_dark[0][0],bloc+LCD_SIZE,SPRT_OR);
		//Sprite16(player_x-ix-8,player_y-iy-8,16,square1,bloc+LCD_SIZE,SPRT_XOR);
		
		//Apply foreground plane to virtual buffer
		
		//First apply mask to light plane
		DrawPlane(ix,iy,&fg_mask,bloc,TM_MASK89,TM_16B);
		//Then to dark plane
		DrawPlane(ix,iy,&fg_mask,bloc+LCD_SIZE,TM_MASK89,TM_16B);
		//And finally OR the main plane onto it.
    DrawPlane(ix,iy,&fg_plane,bloc,TM_GOR89,TM_G16B);

		//Quickly move the temporary buffer data into the standard Gray Planes
    FastCopyScreen_R(bloc,GrayGetPlane(LIGHT_PLANE));
    FastCopyScreen_R(bloc+LCD_SIZE,GrayGetPlane(DARK_PLANE));
		
		
		
		//GET PLAYER INPUT========================================================================
		BEGIN_KEYTEST
		short num_arrows=0;
    volatile short esc_hit=0;short i=0;
    for(i;i<5;i++)esc_hit+=_keytest_optimized(RR_ESC)?1:0;
    if(_keytest_optimized(RR_ESC))goto end;
    if(_keytest_optimized(RR_UP)){
    	num_arrows++;
      player_y-=1;
      if(!dir_lock || link_dir==LINK_DIR_UP){
      	dir_lock=1;
      	link_dir=LINK_DIR_UP;
      }
    }else if(dir_lock&&link_dir==LINK_DIR_UP)dir_lock=0;
    if(_keytest_optimized(RR_DOWN)){ // Note to self: 100 is on purpose !
    	num_arrows++;
      player_y+=1;
      if(!dir_lock || link_dir==LINK_DIR_DOWN){
      	dir_lock=1;
      	link_dir=LINK_DIR_DOWN;
      }
    }else if(dir_lock&&link_dir==LINK_DIR_DOWN)dir_lock=0;
    if(_keytest_optimized(RR_LEFT)){
    	num_arrows++;
      player_x-=1;
      if(!dir_lock || link_dir==LINK_DIR_LEFT){
      	dir_lock=1;
      	link_dir=LINK_DIR_LEFT;
      }
    }else if(dir_lock&&link_dir==LINK_DIR_LEFT)dir_lock=0;
    if(_keytest_optimized(RR_RIGHT)){
    	num_arrows++;
      player_x+=1;
      if(!dir_lock || link_dir==LINK_DIR_RIGHT){
      	dir_lock=1;
      	link_dir=LINK_DIR_RIGHT;
      }
    }else if(dir_lock&&link_dir==LINK_DIR_RIGHT)dir_lock=0;
    
    if(num_arrows%2){
			if(link_state==LINK_STATE_NORMAL)
				link_state=LINK_STATE_WALK;
			else if(link_state==LINK_STATE_WALK)
				link_state=LINK_STATE_NORMAL;
		}else{
			link_state=LINK_STATE_NORMAL;
		}
    END_KEYTEST
    //END GET INPUT=============================================
		if(player_x<8){
			player_x=256-8;
			load_room(current_room.west_room);
			update_draw_planes();
			//update_clipping_planes();
		}
		if(player_x>256-8){
			player_x=8;
			load_room(current_room.east_room);
			update_draw_planes();
			//update_clipping_planes();
		}
		if(player_y<8){
			player_y=256-8;
			load_room(current_room.north_room);
			update_draw_planes();
			//update_clipping_planes();
		}
		if(player_y>256-8){
			player_y=8;
			load_room(current_room.south_room);
			update_draw_planes();
			//update_clipping_planes();
		}
		if(player_level==1||player_level==2){
			//if(*(clip_plane_1+(player_y)*512+2*((player_x)-(player_x)%16)&(1<<((player_x)%16)))>0)
			//if(*(unsigned short*)(clip_plane_1+(player_y-4)*512+2*((player_x)-(player_x)%16))&(1<<((player_x)%16)))>0)player_y+=1;
			//if(*(unsigned short*)(clip_plane_1+(player_y+4)*512+2*((player_x)-(player_x)%16))&(1<<((player_x)%16)))>0)player_y-=1;
			//if(*(unsigned short*)(clip_plane_1+(player_y)*512+2*((player_x-4)-(player_x-4)%16))&(1<<((player_x-4)%16)))>0)player_x-=1;
			//if(*(unsigned short*)(clip_plane_1+(player_y)*512+2*((player_x+4)-(player_x+4)%16))&(1<<((player_x+4)%16)))>0)player_x+=1;
			
			//if((*((unsigned short*)(clip_plane_1+(player_y-8)*512+2*((player_x)-(player_x)%16)))&(1<<((player_x)%16)))>0)player_y++;
			//if((*((unsigned short*)(clip_plane_1+(player_y+8)*512+2*((player_x)-(player_x)%16)))&(1<<((player_x)%16)))>0)player_y--;
			//if((*((unsigned short*)(clip_plane_1+(player_y)*512+2*((player_x-8)-(player_x-8)%16)))&(1<<((player_x+8)%16)))>0)player_x++;
			//if((*((unsigned short*)(clip_plane_1+(player_y)*512+2*((player_x+8)-(player_x+8)%16)))&(1<<((player_x+8)%16)))>0)player_x--;
		}
	}
	
	end:
	GrayOff();
	free(bloc);
	free(bl2);
	if(clip_plane_1)free(clip_plane_1);
	if(clip_plane_1)free(clip_plane_2);
	return;
}



void clear_buffers(){
	player_level=1;
	link_state=2;
	link_dir=0;
	dir_lock=0;
	current_room.id=0;
	current_room.north_room=0;
	current_room.east_room=0;
	current_room.south_room=0;
	current_room.west_room=0;
	current_room.palette=0;
	memset((void*)grid,0,256*sizeof(unsigned short));
	memset((void*)fg_tiles,0,256*sizeof(unsigned char));
	memset((void*)fg_mask_tiles,0,256*sizeof(unsigned char));
	memset((void*)bg_tiles,0,256*sizeof(unsigned char));
	memset((void*)tilesprites,0,256*32*sizeof(unsigned short));
	current_palette=0;
	memset((void*)clip1,0,256*sizeof(unsigned char));
	memset((void*)clip2,0,256*sizeof(unsigned char));
}

void process_target(void){
	FontSetSys(1);
	ESI argptr;
  int argtype;
  InitArgPtr (argptr);
  int checked = 0;
  while ((argtype = GetArgType (argptr)) != END_TAG)
    {
      printf("Attempting to fetch Data...\n");
      if (argtype == STR_TAG){
        const char* s = GetStrnArg (argptr);
        char buf[10];
        memset(buf,0,10);
        int i = 0;
        for(i;i<8;i++){
        	if(s[i])
        		buf[i]=s[i];
        	else
        		break;
        }
        checked=1;
        printf("Attempting to fetch data from directory %s\n",buf);
        printf("Press [ON] to abort");
        sleep(1000);
        if(OSCheckBreak()){
        	exit(1);
        }
        memcpy(dir,buf,10);
      }
    }
    if(!checked){
    	printf("Error: No working dir specified. Exiting with signal 1: Argument Error\nUsage: engine(\"dirname\")");
    	sleep(500);
    	exit(1);
    }
}

// Main Function. Somewhat spartan for now, but will spice up later.
void _main(void){
	process_target();
	clear_buffers();
	//Save the first interrupt handler
	save_int_1 = GetIntVec (AUTO_INT_1);
	//Disable modifier key mirroring to screen
	SetIntVec (AUTO_INT_1, DUMMY_HANDLER);
	run_intro();
	int cmd = run_splash();
	if(!cmd){
		//begin main cycle
		draw();
		goto end;
	}
	end:
	//Restore vector
	SetIntVec (AUTO_INT_1, save_int_1);
}


// Header File
// Created 2/15/2021; 11:04:08 AM


//Flags are as follows: {fall_up,fall_right,fall_down,fall_left,does_damage_on_touch,breakable,unused,unused}

struct ztile_t{
	unsigned short id;
	unsigned short plane_1_sprite;
	unsigned short plane_2_mask;
	unsigned short plane_2_sprite;
};



//Currently just the palette for the inside of Hyrule Castle.
static unsigned short tilesprites[256][32];

//Masks are what parts are shown through. A 0 means block and a 1 means transparent.
unsigned const short masks[][16]={
	// 00					0
	// 00
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	// 11					1
	// 11
	{0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF},
	// 10					2
	// 00
	{0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0,0,0,0,0,0,0,0},
	// 01					3
	// 00
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0,0,0,0,0,0,0,0},
	// 00					4
	// 10
	{0,0,0,0,0,0,0,0,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00},
	// 00					5
	// 01
	{0,0,0,0,0,0,0,0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	// 00					6
	// 11
	{0,0,0,0,0,0,0,0,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF},
	// 11					7
	// 00
	{0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0,0,0,0,0,0,0,0},
	// 10					8
	// 10
	{0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00},
	// 01					9
	// 01
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	// 01					10
	// 11
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF},
	// 10					11
	// 11
	{0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF},
	// 11					12
	// 01
	{0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	// 11					13
	// 10
	{0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00,0xFF00},
	// 0/					14
	// /1
	{
	0b0000000000000001,
	0b0000000000000011,
	0b0000000000000111,
	0b0000000000001111,
	0b0000000000011111,
	0b0000000000111111,
	0b0000000001111111,
	0b0000000011111111,
	0b0000000111111111,
	0b0000001111111111,
	0b0000011111111111,
	0b0000111111111111,
	0b0001111111111111,
	0b0011111111111111,
	0b0111111111111111,
	0b1111111111111111
	},
	// |0					15
	// 1|
	{
		0b1000000000000000,
		0b1100000000000000,
		0b1110000000000000,
		0b1111000000000000,
		0b1111100000000000,
		0b1111110000000000,
		0b1111111000000000,
		0b1111111100000000,
		0b1111111110000000,
		0b1111111111000000,
		0b1111111111100000,
		0b1111111111110000,
		0b1111111111111000,
		0b1111111111111100,
		0b1111111111111110,
		0b1111111111111111
	},
	// 1/					16
	// /0
	{
		0b1111111111111111,
		0b1111111111111110,
		0b1111111111111100,
		0b1111111111111000,
		0b1111111111110000,
		0b1111111111100000,
		0b1111111111000000,
		0b1111111110000000,
		0b1111111100000000,
		0b1111111000000000,
		0b1111110000000000,
		0b1111100000000000,
		0b1111000000000000,
		0b1110000000000000,
		0b1100000000000000,
		0b1000000000000000
	},
	// |1					17
	// 0|
	{
		0b1111111111111111,
		0b0111111111111111,
		0b0011111111111111,
		0b0001111111111111,
		0b0000111111111111,
		0b0000011111111111,
		0b0000001111111111,
		0b0000000111111111,
		0b0000000011111111,
		0b0000000001111111,
		0b0000000000111111,
		0b0000000000011111,
		0b0000000000001111,
		0b0000000000000111,
		0b0000000000000011,
		0b0000000000000001
	}
};

unsigned short current_palette;

struct zroom_t{
	unsigned short id;
	unsigned short north_room;
	unsigned short east_room;
	unsigned short south_room;
	unsigned short west_room;
	unsigned short palette;
}current_room;

//contains the rules for which masks and sprites go with which tiles, etc.
struct ztile_t tile_rules[512];

//Contains the tiles found in the room map.
unsigned short grid[16][16];

unsigned char clip1[16][16];
unsigned char clip2[16][16];

//Background plane, contains level 1 tiles
unsigned char bg_tiles[16][16];

//Transparency bitmask for level two plane.
unsigned char fg_tiles[16][16];

//Foreground plane, drawn on top of the level 2 mask.
unsigned char fg_mask_tiles[16][16];


//Uses the values stored in grid to update the draw planes
void update_draw_planes(void){
	register short i,j;
	for(i=0;i<16;i++){
		for(j=0;j<16;j++){
			bg_tiles[i][j]=tile_rules[grid[i][j]].plane_1_sprite;
			fg_mask_tiles[i][j]=tile_rules[grid[i][j]].plane_2_mask;
			fg_tiles[i][j]=tile_rules[grid[i][j]].plane_2_sprite;
		}
	}
	//for(i=0;i<100;i++)
	//	printf("loaded");
	
}


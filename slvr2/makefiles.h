// C Source File
// Created 2/16/2021; 7:12:00 AM

#include <tigcclib.h>

static unsigned short link_pic_light[4][7][16] =
{
	//----------------------------------
	// Pictures of link when facing UP
	//----------------------------------
	{
		{0x0380,0x07C0,0x0420,0x1BD8,0x2E74,0x2E74,0x2F74,0x3F7C,0x1FF8,0x1FFC,0x2FFC,0x2FDC,0x1838,0x1FF8,0x1FCC,0x0FF8},	//Normal
		{0x01C0,0x03E0,0x0420,0x1BD8,0x2E74,0x2E74,0x2EF4,0x3EFC,0x1FF8,0x3FF8,0x3FF4,0x3BF4,0x1C18,0x1FF8,0x33F8,0x1FF0},	//Walk
		{0x0000,0x17F8,0x2FBC,0x3CDC,0x1FE8,0x1E6E,0x1B39,0x1BA9,0x1FEE,0x0FF8,0x1FF0,0x1D90,0x1E90,0x0FF0,0x0788,0x03F8},	//Thrust
		{0x0FE0,0x1210,0x1DEC,0x173A,0x173A,0x1F7E,0x0F7C,0x07B8,0x0FFC,0x0DFE,0x0EF9,0x0F39,0x07FE,0x03C8,0x01CC,0x007C},	//Thrust2
	},

	//-------------------------------------
	// Pictures of link when facing RIGHT
	//-------------------------------------
	{
		{0x07C0,0x0F70,0x1CC8,0x3F9E,0x7B3C,0x7BF0,0x39AC,0x1924,0x0D18,0x0FF0,0x0FF0,0x1E70,0x1E50,0x1FF0,0x0870,0x1FF8},	//Normal
		{0x0000,0x07E0,0x1F3A,0x3CE6,0x3FCE,0x3D9C,0x1DF8,0x1CD6,0x0C92,0x068C,0x07F8,0x0F90,0x1790,0x17F8,0x1384,0x3FFC},	//Walk
		{0x00F8,0x0394,0x064C,0x0CE6,0x39F6,0x7FBF,0x7F9F,0x3F94,0x1FD4,0x0FFC,0x3FFC,0x4FDC,0x4E3E,0x3FF2,0x11E6,0x1FFC},	//Thrust
		{0x0000,0x07E0,0x3E3A,0x78E6,0x7FCE,0x3D9C,0x1DFC,0x1CD6,0x0C92,0x068C,0x07FE,0x1DF9,0x2E79,0x2FFE,0x2788,0x7FFC},	//Thrust2
	},

	//------------------------------------
	// Pictures of link when facing DOWN
	//------------------------------------
	{
		{0x03E0,0x0670,0x0FFC,0x161A,0x15EA,0x17FA,0x1FFE,0x0924,0x0D2C,0x1E1E,0x2FFE,0x2FE6,0x1C24,0x0FF8,0x1CFC,0x0FF8},	//Normal
		{0x03E0,0x0730,0x1FF8,0x2C34,0x2BD4,0x2FF4,0x3FFC,0x1248,0x1A58,0x3C3C,0x3FFA,0x33FA,0x121C,0x0FF8,0x1F9C,0x0FF8},	//Walk
		{0x01E0,0x0330,0x07F8,0x08FC,0x3E3A,0x1F96,0x0FEE,0x0ABE,0x0CBC,0x0E78,0x13F8,0x13E8,0x0FF8,0x07FC,0x018C,0x00F8},	//Thrust
		{0x01F0,0x03B8,0x0F3C,0x173A,0x17FA,0x140A,0x3FFE,0x4BF4,0x2D2C,0x1E18,0x0FFC,0x1EFC,0x1F3C,0x0FE4,0x01E6,0x00FC},	//Thrust2
		{0x0660,0x0990,0x0FF0,0x0FF0,0x1BD8,0x17E8,0x17E8,0x2E74,0x2E74,0x2E74,0x3FFC,0x17E8,0x0BD0,0x0C30,0x07E0,0x03C0},	//Flip1
		{0x0000,0x0660,0x0990,0x1998,0x399C,0x3FFC,0x3FFC,0x3FFC,0x17E8,0x1818,0x1FF8,0x3FFC,0x2FF4,0x2E74,0x17E8,0x03C0},	//Flip2
		{0x0000,0x07E0,0x0DB0,0x1BD8,0x2FF4,0x2A54,0x2814,0x399C,0x1818,0x3C3C,0x3FFC,0x399C,0x399C,0x399C,0x1998,0x0FF0},	//Flip3
	},

	//------------------------------------
	// Pictures of link when facing LEFT
	//------------------------------------
	{
		{0x03E0,0x0EF0,0x1338,0x79FC,0x3CDE,0x0FDE,0x359C,0x2498,0x18B0,0x0FF0,0x0FF0,0x0E78,0x0A78,0x0FF8,0x0E10,0x1FF8},	//Normal
		{0x0000,0x03F0,0x2E7C,0x339E,0x39FE,0x1CDE,0x0FDC,0x359C,0x2498,0x18B0,0x0FF0,0x04F8,0x04F4,0x0FF4,0x10E4,0x1FFE},	//Walk
		{0x0F80,0x14E0,0x1930,0x3398,0x37CE,0x7EFF,0x7CFF,0x14FE,0x15FC,0x1FF8,0x1FFE,0x1DF9,0x3E39,0x27FE,0x33C4,0x1FFC},	//Thrust
		{0x0000,0x07E0,0x5C7C,0x671E,0x73FE,0x39BC,0x3FB8,0x6B38,0x4930,0x3160,0x7FE0,0x9FB8,0x9E74,0x7FF4,0x11E4,0x3FFE},	//Thrust2
	}
};

static unsigned short link_pic_dark[4][7][16] =
{
	//----------------------------------
	// Pictures of link when facing UP
	//----------------------------------
	{
		{0x0380,0x07C0,0x0420,0x1BD8,0x2C34,0x2814,0x2A14,0x2C14,0x1C38,0x1454,0x2494,0x2B0C,0x1008,0x1838,0x1FCC,0x0FF8},	//Normal
		{0x01C0,0x03E0,0x0420,0x1BD8,0x2C34,0x2814,0x2854,0x2834,0x1C38,0x2A28,0x2924,0x30D4,0x1008,0x1C18,0x33F8,0x1FF0},	//Walk
		{0x0000,0x17F8,0x28BC,0x305C,0x13A8,0x166E,0x1239,0x1129,0x10AE,0x09F8,0x1730,0x1110,0x1890,0x0C70,0x0788,0x03F8},	//Thrust
		{0x0FE0,0x1210,0x1DEC,0x161A,0x140A,0x140A,0x0C2C,0x0618,0x0914,0x0892,0x0871,0x0C09,0x063E,0x03C8,0x01CC,0x007C},	//Thrust2
	},

	//-------------------------------------
	// Pictures of link when facing RIGHT
	//-------------------------------------
	{
		{0x07C0,0x0830,0x1048,0x248E,0x4B1C,0x4970,0x29AC,0x1924,0x0908,0x0D10,0x0BF0,0x1250,0x1250,0x1FD0,0x0870,0x1FF8},	//Normal
		{0x0000,0x07E0,0x181A,0x2026,0x2246,0x258C,0x14B8,0x14D6,0x0C92,0x0484,0x07F8,0x0C90,0x1490,0x1678,0x1384,0x3FFC},	//Walk
		{0x00F8,0x0394,0x044C,0x0826,0x38E6,0x48B7,0x449F,0x2094,0x1094,0x0E5C,0x33F4,0x420C,0x440E,0x3E12,0x11E6,0x1FFC},	//Thrust
		{0x0000,0x07E0,0x381A,0x4026,0x4246,0x258C,0x14BC,0x14D6,0x0C92,0x0484,0x07FE,0x1889,0x2849,0x2C7E,0x2788,0x7FFC},	//Thrust2
	},

	//------------------------------------
	// Pictures of link when facing DOWN
	//------------------------------------
	{
		{0x03E0,0x0410,0x0D8C,0x160A,0x15EA,0x17FA,0x13F2,0x0924,0x0924,0x140A,0x27FA,0x2C22,0x1824,0x0F18,0x18FC,0x0FF8},	//Normal
		{0x03E0,0x0410,0x18D8,0x2834,0x2BD4,0x2FF4,0x27E4,0x1248,0x1248,0x2814,0x2FF2,0x221A,0x120C,0x0C78,0x1F8C,0x0FF8},	//Walk
		{0x01E0,0x0210,0x0708,0x08D4,0x3E3A,0x1F92,0x0FE2,0x0AA6,0x08AC,0x0E38,0x11E8,0x1028,0x0C48,0x07FC,0x018C,0x00F8},	//Thrust
		{0x01F0,0x0308,0x0E1C,0x140A,0x177A,0x140A,0x33F2,0x49E4,0x2924,0x1C08,0x0BF4,0x1C24,0x123C,0x0F24,0x01E6,0x00FC},	//Thrust2
		{0x0660,0x0990,0x0E70,0x0990,0x1248,0x1668,0x1428,0x2814,0x2814,0x2814,0x381C,0x1428,0x0BD0,0x0C30,0x07E0,0x03C0},	//Flip1
		{0x0000,0x0660,0x0990,0x1998,0x2994,0x2FF4,0x2994,0x27E4,0x1008,0x1008,0x1998,0x2A54,0x2E74,0x2814,0x1428,0x03C0},	//Flip2
		{0x0000,0x07E0,0x0990,0x1BD8,0x2E74,0x2A54,0x2814,0x2184,0x1008,0x2814,0x27E4,0x2994,0x399C,0x399C,0x1998,0x0FF0},	//Flip3
	},

	//------------------------------------
	// Pictures of link when facing LEFT
	//------------------------------------
	{
		{0x03E0,0x0C10,0x1208,0x7124,0x38D2,0x0E92,0x3594,0x2498,0x1090,0x08B0,0x0FD0,0x0A48,0x0A48,0x0BF8,0x0E10,0x1FF8},	//Normal
		{0x0000,0x03F0,0x2C0C,0x3202,0x3122,0x18D2,0x0E94,0x3594,0x2498,0x1090,0x0FF0,0x0498,0x0494,0x0F34,0x10E4,0x1FFE},	//Walk
		{0x0F80,0x14E0,0x1910,0x3208,0x338E,0x7689,0x7C91,0x1482,0x1484,0x1D38,0x17E6,0x1821,0x3811,0x243E,0x33C4,0x1FFC},	//Thrust
		{0x0000,0x07E0,0x581C,0x6402,0x6242,0x31A4,0x3D28,0x6B28,0x4930,0x2120,0x7FE0,0x9118,0x9214,0x7E34,0x11E4,0x3FFE},	//Thrust2
	}
};

static unsigned short link_pic_mask[4][7][16] =
{
	//----------------------------------
	// Pictures of link when facing UP
	//----------------------------------
	{
		{~0x0380,~0x07C0,~0x07E0,~0x1FF8,~0x3FFC,~0x3FFC,~0x3FFC,~0x3FFC,~0x1FF8,~0x1FFC,~0x3FFC,~0x3FFC,~0x1FF8,~0x1FF8,~0x1FFC,~0x0FF8},	//Normal
		{~0x01C0,~0x03E0,~0x07E0,~0x1FF8,~0x3FFC,~0x3FFC,~0x3FFC,~0x3FFC,~0x1FF8,~0x3FF8,~0x3FFC,~0x3FFC,~0x1FF8,~0x1FF8,~0x3FF8,~0x1FF0},	//Walk
		{~0x0000,~0x17F8,~0x3FFC,~0x3FFC,~0x1FF8,~0x1FFE,~0x1FFF,~0x1FFF,~0x1FFE,~0x0FF8,~0x1FF0,~0x1FF0,~0x1FF0,~0x0FF0,~0x07F8,~0x03F8},	//Thrust
		{~0x0FE0,~0x1FF0,~0x1FFC,~0x1FFE,~0x1FFE,~0x1FFE,~0x0FFC,~0x07F8,~0x0FFC,~0x0FFE,~0x0FFF,~0x0FFF,~0x07FE,~0x03F8,~0x01FC,~0x007C},	//Thrust2
	},

	//-------------------------------------
	// Pictures of link when facing RIGHT
	//-------------------------------------
	{
		{~0x07C0,~0x0FF0,~0x1FF8,~0x3FFE,~0x7FFC,~0x7FF0,~0x3FFC,~0x1FFC,~0x0FF8,~0x0FF0,~0x0FF0,~0x1FF0,~0x1FF0,~0x1FF0,~0x0FF0,~0x1FF8},	//Normal
		{~0x0000,~0x07E0,~0x1FFA,~0x3FFE,~0x3FFE,~0x3FFC,~0x1FF8,~0x1FFE,~0x0FFE,~0x07FC,~0x07F8,~0x0FF0,~0x1FF0,~0x1FF8,~0x1FFC,~0x3FFC},	//Walk
		{~0x00F8,~0x03FC,~0x07FC,~0x0FFE,~0x3FFE,~0x7FFF,~0x7FFF,~0x3FFC,~0x1FFC,~0x0FFC,~0x3FFC,~0x7FFC,~0x7FFE,~0x3FFE,~0x1FFE,~0x1FFC},	//Thrust
		{~0x0000,~0x07E0,~0x3FFA,~0x7FFE,~0x7FFE,~0x3FFC,~0x1FFC,~0x1FFE,~0x0FFE,~0x07FC,~0x07FE,~0x1FFF,~0x3FFF,~0x3FFE,~0x3FF8,~0x7FFC},	//Thrust2
	},

	//------------------------------------
	// Pictures of link when facing DOWN
	//------------------------------------
	{
		{~0x03E0,~0x07F0,~0x0FFC,~0x1FFE,~0x1FFE,~0x1FFE,~0x1FFE,~0x0FFC,~0x0FFC,~0x1FFE,~0x3FFE,~0x3FFE,~0x1FFC,~0x0FF8,~0x1FFC,~0x0FF8},	//Normal
		{~0x03E0,~0x07F0,~0x1FF8,~0x3FFC,~0x3FFC,~0x3FFC,~0x3FFC,~0x1FFC,~0x1FFC,~0x3FFC,~0x3FFE,~0x3FFE,~0x1FFC,~0x0FF8,~0x1FFC,~0x0FF8},	//Walk
		{~0x01E0,~0x03F0,~0x07F8,~0x0FFC,~0x3FFE,~0x1FFE,~0x0FFE,~0x0FFE,~0x0FFC,~0x0FF8,~0x1FF8,~0x1FF8,~0x0FF8,~0x07FC,~0x01FC,~0x00F8},	//Thrust
		{~0x01F0,~0x03F8,~0x0FFC,~0x1FFE,~0x1FFE,~0x1FFE,~0x3FFE,~0x7FFC,~0x3FFC,~0x1FF8,~0x0FFC,~0x1FFC,~0x1FFC,~0x0FFC,~0x01FE,~0x00FC},	//Thrust2
		{~0x0660,~0x0FF0,~0x0FF0,~0x0FF0,~0x1FF8,~0x1FF8,~0x1FF8,~0x3FFC,~0x3FFC,~0x3FFC,~0x3FFC,~0x1FF8,~0x0FF0,~0x0FF0,~0x07E0,~0x03C0},	//Flip1
		{~0x0000,~0x0660,~0x0FF0,~0x1FF8,~0x3FFC,~0x3FFC,~0x3FFC,~0x3FFC,~0x1FF8,~0x1FF8,~0x1FF8,~0x3FFC,~0x3FFC,~0x3FFC,~0x17E8,~0x03C0},	//Flip2
		{~0x0000,~0x07E0,~0x0FF0,~0x1FF8,~0x3FFC,~0x3FFC,~0x3FFC,~0x3FFC,~0x1FF8,~0x3FFC,~0x3FFC,~0x3FFC,~0x3FFC,~0x3FFC,~0x1FF8,~0x0FF0},	//Flip3
	},

	//------------------------------------
	// Pictures of link when facing LEFT
	//------------------------------------
	{
		{~0x03E0,~0x0FF0,~0x1FF8,~0x7FFC,~0x3FFE,~0x0FFE,~0x3FFC,~0x3FF8,~0x1FF0,~0x0FF0,~0x0FF0,~0x0FF8,~0x0FF8,~0x0FF8,~0x0FF0,~0x1FF8},	//Normal
		{~0x0000,~0x03F0,~0x2FFC,~0x3FFE,~0x3FFE,~0x1FFE,~0x0FFC,~0x3FFC,~0x3FF8,~0x1FF0,~0x0FF0,~0x07F8,~0x07FC,~0x0FFC,~0x1FFC,~0x1FFE},	//Walk
		{~0x0F80,~0x1FE0,~0x1FF0,~0x3FF8,~0x3FFE,~0x7FFF,~0x7FFF,~0x1FFE,~0x1FFC,~0x1FF8,~0x1FFE,~0x1FFF,~0x3FFF,~0x3FFE,~0x3FFC,~0x1FFC},	//Thrust
		{~0x0000,~0x07E0,~0x5FFC,~0x7FFE,~0x7FFE,~0x3FFC,~0x3FF8,~0x7FF8,~0x7FF0,~0x3FE0,~0x7FE0,~0xFFF8,~0xFFFC,~0x7FFC,~0x1FFC,~0x3FFE},	//Thrust2
	}
};

//Constant tiles, mostly for test/debug, but open for use anywhere.
#define BLANK_WHITE_TILE_1 {0,0,1,0}
#define BLANK_WHITE_TILE_2 {1,0,0,0}
#define BLANK_BLACK_TILE_1 {2,1,1,0}
#define BLANK_BLACK_TILE_2 {3,0,0,0}

//Hyrule castle tiles

#define HC_NORTH_FACE_COAT_OF_ARMS_UL {4,2,1,0}
#define HC_NORTH_FACE_COAT_OF_ARMS_UR {5,3,1,0}
#define HC_NORTH_FACE_COAT_OF_ARMS_LL {6,4,1,0}
#define HC_NORTH_FACE_COAT_OF_ARMS_LR {7,5,1,0}
#define HC_SOUTH_GATE_UL {8,8,1,0}//facing up, leading down
#define HC_SOUTH_GATE_UR {9,9,1,0}
#define HC_SOUTH_GATE_LL {10,1,3,18}
#define HC_SOUTH_GATE_LR {11,1,2,19}

struct ztile_t{
	unsigned short id;
	unsigned short plane_1_sprite;
	unsigned short plane_2_mask;
	unsigned short plane_2_sprite;
};

struct ztile_t tiles_hyrule_castle[512] = {
	BLANK_WHITE_TILE_1,
	BLANK_WHITE_TILE_2,
	BLANK_BLACK_TILE_1,
	BLANK_BLACK_TILE_2,
	HC_NORTH_FACE_COAT_OF_ARMS_UL,
	HC_NORTH_FACE_COAT_OF_ARMS_UR,
	HC_NORTH_FACE_COAT_OF_ARMS_LL,
	HC_NORTH_FACE_COAT_OF_ARMS_LR,
	HC_SOUTH_GATE_UL,
	HC_SOUTH_GATE_UR,
	HC_SOUTH_GATE_LL,
	HC_SOUTH_GATE_LR
};

//Note to self: These sprites aren't easy to edit in this format. They were:
//Ripped from alttp, passed through iStudio in WINE, passed through tttiler,
//and passed through my interweave script.
static unsigned short hyrule_castle_tile_sprites[256][32]={
	//0:White
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	//1:Black
	{0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF},
	//2: The upper left fourth of the hyrule coat of arms that goes on north facing walls
	{65535, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 65535, 65535, 65535, 65535, 3106, 65535, 6164, 65535, 12424, 65535, 57793, 65535, 17379, 65535, 18038, 65535, 34815, 65150, 36743, 65535},
	//3: The upper right fourth of the hyrule coat of arms that goes on north facing walls
	{65535, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 65535, 65535, 65535, 65535, 17456, 65535, 10264, 65535, 4364, 65535, 33671, 65535, 51138, 65535, 28258, 65535, 65505, 32383, 57841, 65535},
	//4: The lower left fourth of the hyrule coat of arms that goes on north facing walls
	{36659, 65487, 36472, 65463, 36604, 65403, 36607, 65404, 36287, 65151, 36863, 65535, 36863, 65535, 65535, 65535, 0, 32768, 14351, 34800, 12295, 36856, 992, 64543, 1040, 63503, 63503, 0, 448, 0, 992, 0},
	//5: The lower right fourth of the hyrule coat of arms that goes on north facing walls
	{52465, 62463, 7793, 60927, 16241, 57087, 65393, 16127, 64945, 65151, 65521, 65535, 65521, 65535, 65535, 65535, 0, 1, 61468, 4065, 57356, 8177, 1984, 63551, 2080, 61471, 61471, 0, 896, 0, 1984, 0},

	//6: left facing dungeon enterance ul
	{33552, 65535, 33555, 65535, 33566, 65535, 65508, 65531, 33636, 65467, 33536, 65535, 33791, 65535, 33791, 65535, 33541, 65535, 33539, 65535, 33541, 65535, 33539, 65535, 65285, 65535, 33539, 65535, 33541, 65535, 33539, 65535},
	//7: left facing dungeon enterance ur
	{36860, 65528, 61676, 65176, 236, 56984, 8684, 57240, 492, 65432, 8140, 65432, 65436, 65528, 65484, 65432, 236, 152, 236, 152, 236, 152, 204, 152, 156, 248, 204, 152, 236, 152, 236, 152},
	//8: up facing dungeon enterance ul
	{65535, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 65535, 65535, 65535, 65535, 4864, 65535, 6912, 63487, 6912, 65535, 58112, 65535, 8960, 65535, 15274, 59391, 25429, 65535, 17407, 65535},
	//9: up dung ur
	{65535, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 65535, 65535, 65535, 65535, 200, 65535, 216, 65519, 216, 65535, 199, 65535, 196, 65535, 43740, 65511, 21958, 65535, 65474, 65535},
	//10: down dung ul
	{0, 0, 0, 0, 65535, 0, 65535, 65535, 33288, 65535, 63715, 33288, 65015, 33288, 65535, 65535, 34560, 40704, 34560, 65280, 34560, 65280, 34560, 65280, 17152, 65280, 21248, 52992, 17152, 65280, 49920, 65280},
	//11: down dung ur
	{0, 0, 0, 0, 65535, 0, 65535, 65535, 4161, 65535, 50975, 4161, 61375, 4161, 65535, 65535, 225, 249, 225, 255, 225, 255, 225, 255, 194, 255, 202, 243, 194, 255, 195, 255},
	//12: right dung ul
	{16369, 8191, 14095, 6527, 14080, 6523, 14212, 6651, 14208, 6655, 13304, 6655, 14847, 8191, 13311, 6655, 14080, 6400, 14080, 6400, 14080, 6400, 13056, 6400, 14592, 7936, 13056, 6400, 14080, 6400, 14080, 6400},
	//13: r dung ur
	{2241, 65535, 51393, 65535, 30913, 65535, 10239, 57343, 9921, 56831, 193, 65535, 65473, 65535, 65473, 65535, 41153, 65535, 49345, 65535, 41153, 65535, 49345, 65535, 41215, 65535, 49345, 65535, 41153, 65535, 49345, 65535},
	//14: dung entrance base plane1
	{65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535},
	//15: statue top p2
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37833, 40953, 36465, 52275, 58983, 43029, 54891, 45069, 57927, 55323, 26022, 64575, 15996, 63087, 30702, 56283},
	//16: l dung ll
	{33539, 65535, 33541, 65535, 33539, 65535, 65285, 65535, 33539, 65535, 33541, 65535, 33539, 65535, 33541, 65535, 33791, 65535, 33791, 65535, 33536, 65535, 33636, 65467, 65508, 65531, 33566, 65535, 33555, 65535, 33552, 65535},
	//17: l dung lr
	{236, 152, 236, 152, 204, 152, 156, 248, 204, 152, 236, 152, 236, 152, 236, 152, 65484, 65432, 65436, 65528, 8140, 65432, 492, 65432, 8684, 57240, 236, 56984, 61676, 65176, 36860, 65528},
	//18: u dung ll
	{49920, 65280, 17152, 65280, 21248, 52992, 17152, 65280, 34560, 65280, 34560, 65280, 34560, 65280, 34560, 40704, 65535, 65535, 65015, 33288, 63715, 33288, 33288, 65535, 65535, 65535, 65535, 0, 0, 0, 0, 0},
	//19: u dung lr
	{195, 255, 194, 255, 202, 243, 194, 255, 225, 255, 225, 255, 225, 255, 225, 249, 65535, 65535, 61375, 4161, 50975, 4161, 4161, 65535, 65535, 65535, 65535, 0, 0, 0, 0, 0},
	//20: d dung ll
	{17407, 65535, 25429, 65535, 15274, 59391, 8960, 65535, 58112, 65535, 6912, 65535, 6912, 63487, 4864, 65535, 65535, 65535, 65535, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 65535, 65535},
	//21: d dung lr
	{65474, 65535, 43718, 65535, 21980, 65511, 196, 65535, 199, 65535, 216, 65535, 216, 65519, 200, 65535, 65535, 65535, 65535, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 65535, 65535},
	//22: r dung ll
	{14080, 6400, 14080, 6400, 13056, 6400, 14592, 7936, 13056, 6400, 14080, 6400, 14080, 6400, 14080, 6400, 13311, 6655, 14847, 8191, 13304, 6655, 14208, 6655, 14212, 6651, 14080, 6523, 14095, 6527, 16369, 8191},
	//23: r dung lr
	{49345, 65535, 41153, 65535, 49345, 65535, 41215, 65535, 49345, 65535, 41153, 65535, 49345, 65535, 41153, 65535, 65473, 65535, 65473, 65535, 193, 65535, 9921, 56831, 10239, 57343, 30913, 65535, 51393, 65535, 2241, 65535},
	//24: dgray base carpet floor
	{0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535, 0, 65535},
	//25: statue bot p1/2
	{55275, 39513, 40949, 48729, 41579, 58365, 54679, 49647, 46615, 32909, 46697, 32927, 54731, 33017, 58365, 41643, 63479, 46767, 65375, 46781, 65263, 54773, 65015, 41957, 56383, 49149, 49149, 32769, 49155, 32769, 4095, 4095}
};



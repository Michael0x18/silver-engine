// Header File
// Created 2/12/2021; 1:21:29 PM

//Deprecated. New sprite definitions are in tile.h and this file is
//only kept for reference. The ones in tile.h are better able to support
//dynamic palette loading, which will drastically cut down on the program size
//because at this point, I need to keep EVERYTHING I can out of RAM. I've done 
//the calculations (coincidently on the TI-89 I'm using to test it) and I will end
//up with about twenty Kb left over. Meaning the user is expected to have 160Kb of
//free memory.

//Note to self: Sprite interweaving for gray planes is done in order l1 d1 l2 d1 etc. Removing interweaved sprite data means
//Modifying one of the ExtGraph files and recompiling it.

/*static const short sprts[][32]={
	//0:White mask
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	//1:Black mask
	{0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF},
	//2:Sand striped
	{63489,0,57347,0,49159,0,32775,0,32783,0,15,0,31,0,31,0,30,0,62,0,254,0,1020,0,4092,0,16376,0,32736,0,65280,0},
	//3: Wall 1 -> standard four way diagonal block
	{65535, 1, 65533, 3, 65529, 7, 65521, 15, 61441, 15, 61441, 15, 61441, 15, 61441, 15, 61441, 15, 61441, 15, 61441, 15, 61441, 15, 57345, 8191, 49153, 16383, 32769, 32767, 65535, 65535}
};*/

//This one is hyrule castle
static const short sprts[][32]={
	//0:White mask
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	//1:Black mask
	{0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF},
	//2: The upper left fourth of the hyrule coat of arms that goes on north facing walls
	{65535, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 65535, 65535, 65535, 65535, 3106, 65535, 6164, 65535, 12424, 65535, 57793, 65535, 17379, 65535, 18038, 65535, 34815, 65150, 36743, 65535},
	//3: The upper right fourth of the hyrule coat of arms that goes on north facing walls
	{65535, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 2064, 65535, 65535, 65535, 65535, 65535, 17456, 65535, 10264, 65535, 4364, 65535, 33671, 65535, 51138, 65535, 28258, 65535, 65505, 32383, 57841, 65535},
	//4: The lower left fourth of the hyrule coat of arms that goes on north facing walls
	{36659, 65487, 36472, 65463, 36604, 65403, 36607, 65404, 36287, 65151, 36863, 65535, 36863, 65535, 65535, 65535, 0, 32768, 14351, 34800, 12295, 36856, 992, 64543, 1040, 63503, 63503, 0, 448, 0, 992, 0},
	//4: The lower right fourth of the hyrule coat of arms that goes on north facing walls
	{52465, 62463, 7793, 60927, 16241, 57087, 65393, 16127, 64945, 65151, 65521, 65535, 65521, 65535, 65535, 65535, 0, 1, 61468, 4065, 57356, 8177, 1984, 63551, 2080, 61471, 61471, 0, 896, 0, 1984, 0}
};
static char map_layer_1[16][16] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,4,5,2,2,2,2,2,2,2,2,2,2},
};
static char l2_mask[16][16] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
static char map_layer_2[16][16] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0},
{0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
// Header File
// Created 2/12/2021; 10:39:13 AM

/*--------------------------------------------
|          The Advanced RPG Engine
|            (Silver Engine V2)
|  
|  Linking with this engine is extremely easy.
|  All you need to do is provide some files in
|  a folder. Then, you can call engine("dirname")
|  to run it. There are very specific types of
|  files: dirname/index, which contains the start
|  room number, dirname/player, which contains 
|  player sprites, dirname/lp.*, which contains 
|  sprite palettes, and dirname/lr.*, which contains
|  room data. You can have as many rooms and/or sprites
|  as you want; you're only limited by the storage space
|  of the calc.
*/

#include <tigcclib.h>
#include "extgraph.h"
#include "tilemap.h"

char dir[10];

void* graybuffer2;
void* p1l;
void* p1d;
void* p2l;
void* p3d;


void sleep(UINT millis);
void print_slow(char* s);
void run_intro(void);
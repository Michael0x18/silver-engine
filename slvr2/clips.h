// Header File
// Created 2/17/2021; 10:38:34 AM
#include<tigcclib.h>
short player_level=1;

void* clip_plane_1;
void* clip_plane_2;

void create_buffers(){
	clip_plane_1 = malloc(16*16*16*sizeof(unsigned short));
	clip_plane_2 = malloc(16*16*16*sizeof(unsigned short));
}

void update_clipping_planes(void){
	
	//register int i,j,k;
	//for(i=0;i<16;i++){
	//	for(j=0;j<16;j++){
	//		for(k=0;k<16;k++){
	//			*((short*)(clip_plane_1+512*i+32*j+2*k))=masks[clip1[i][j]][k];
	//			*((short*)(clip_plane_2+512*i+32*j+2*k))=masks[clip2[i][j]][k];
	//		}
	//	}
	//}
	MoveTo(0,0);FontSetSys(0);
	register short i,j,k;
	for(i=0;i<16;i++){
		for(j = 0; j < 16; j++){
			for(k = 0; k < 16; k++){
				//printf("Loading Clipping Regions: %d %d %d",i,j,k);
				void* dest1 = clip_plane_1+32*i+2*j*32*k;
				void* src1  = (void*)(&(masks[clip1[i][j]][k]));
				void* dest2 = clip_plane_2+32*i+2*j+32*k;
				void* src2  = (void*)(&(masks[clip2[i][j]][k]));		
				memcpy(dest1,src1,sizeof(unsigned short));
				memcpy(dest2,src2,sizeof(unsigned short));
			}
		}
	}
	printf("Finished Loading planes. Attempting to start engine normally\n");
}
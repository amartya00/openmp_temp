/*
 * main.c
 * Benchmark code to test 32x32 reference image at center of
 * 64x64 source image using SAD
 */

#include <stdio.h>
#include "SAD_32x32.h"
#include "optSAD_32x32.h"


void main(void) {
	unsigned short *mainSourceImg;
	//unsigned short *centerOfMainImg;
	unsigned short *referenceImg;
	unsigned SAD_Result = 0;
	int i;
	int pitch;
	int SIZE1 = 32 * 32;
	int SIZE2 = 64 * 64;
	pitch = 64;

	mainSourceImg = (unsigned short *) 0x80001000;
	referenceImg = (unsigned short *) 0x80000000;
	//centerOfMainImg = (unsigned short *) 0x80002000;
	for (i = 0; i < SIZE2; i++) {
		mainSourceImg[i] = 1;
	}

	for (i = 0; i < SIZE1; i++) {
		referenceImg[i] = 3;
	}

	SAD_Result = optIMG_sad_32x32(mainSourceImg, referenceImg,pitch,16,16,32);
	printf("SAD Result: %d",SAD_Result);
/*
	k=0;
	for (i=16;i<48;i++){
		for (j=16;j<48;j++){
			centerOfMainImg[k]=mainSourceImg[i*32+j];
			k++;
		}
	}
	SAD_Result = IMG_sad_32x32(centerOfMainImg, referenceImg, pitch);
	printf("SAD Result: %d",SAD_Result);
*/

}

/*
 * main.c
 * Benchmark code to test 32x32 reference image at center of
 * 64x64 source image using MAD
 */

#include <stdio.h>
#include "optMAD_32x32.h"


void main(void) {
	unsigned short *mainSourceImg;
	unsigned short *referenceImg;
	unsigned long MAD_Result = 0;
	int i;
	int pitch;
	int SIZE1 = 32 * 32;
	int SIZE2 = 64 * 64;
	pitch = 64;

	mainSourceImg = (unsigned short *) 0x80010000;
	referenceImg = (unsigned short *) 0x80000000;
	for (i = 0; i < SIZE2; i++) {
		mainSourceImg[i] = 1;
	}

	for (i = 0; i < SIZE1; i++) {
		referenceImg[i] = 2;
	}

	MAD_Result = optIMG_mad_32x32(mainSourceImg, referenceImg,pitch,16,16,32);
	printf("MAD Result: %d",MAD_Result);
}

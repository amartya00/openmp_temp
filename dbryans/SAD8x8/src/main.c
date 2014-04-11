/*
 * main.c
 * Benchmark code to test 8x8 reference image at various sections
 * of 16x16 source image using SAD
 */

#include <stdio.h>
#include "mySAD_8x8.h"
#include "optSAD_8x8.h"

void main(void) {
	unsigned short *mainSourceImg;
	//unsigned short *centerOfMainImg;
	unsigned short *referenceImg;
	unsigned SAD_Result = 0;
	int i;
	int pitch;
	int SIZE1 = 8 * 8;
	int SIZE2 = 16 * 16;
	pitch = 16;

	mainSourceImg = (unsigned short *) 0x80000000;
	referenceImg = (unsigned short *) 0x80001000;
	for (i = 0; i < SIZE2; i++) {
		mainSourceImg[i] = 2;
	}

	for (i = 0; i < SIZE1; i++) {
		referenceImg[i] = 1;
	}

	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 0,0,16);
	printf("SAD Result1: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 1,0,16);
	printf("SAD Result2: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 2,0,16);
	printf("SAD Result3: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 3,0,16);
	printf("SAD Result4: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 4,0,16);
	printf("SAD Result5: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 5,0,16);
	printf("SAD Result6: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 6,0,16);
	printf("SAD Result7: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 7,0,16);
	printf("SAD Result8: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 8,0,16);
	printf("SAD Result9: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 1,1,16);
	printf("SAD Result10: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 2,2,16);
	printf("SAD Result11: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 3,3,16);
	printf("SAD Result12: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 4,4,16);
	printf("SAD Result13: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 5,5,16);
	printf("SAD Result14: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 6,6,16);
	printf("SAD Result15: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 7,7,16);
	printf("SAD Result16: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 8,8,16);
	printf("SAD Result17: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 0,8,16);
	printf("SAD Result18: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 7,2,16);
	printf("SAD Result19: %d",SAD_Result);
	SAD_Result = optIMG_sad8x8(mainSourceImg, referenceImg,pitch, 1,5,16);
	printf("SAD Result20: %d",SAD_Result);
	
	printf("End of program");

}

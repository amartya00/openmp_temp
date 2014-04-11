/*
 * main.c
 * Benchmark code to test 32x32 reference image at center of
 * 64x64 source image using MAD
 */
#include <stdio.h>
#include "optMAD_8x8.h"

void main(void) {
	unsigned short *mainSourceImg;
	unsigned short *referenceImg;
	unsigned MAD_Result = 0;
	int i;
	int pitch;
	int SIZE1 = 8 * 8;
	int SIZE2 = 16 * 16;
	pitch = 16;

	mainSourceImg = (unsigned short *) 0x80000000;
	referenceImg = (unsigned short *) 0x80001000;
	for (i = 0; i < SIZE2; i++) {
		mainSourceImg[i] = 1;
	}

	for (i = 0; i < SIZE1; i++) {
		referenceImg[i] = 2;
	}

	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 0,0,16);
	printf("MAD Result1: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 1,0,16);
	printf("MAD Result2: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 2,0,16);
	printf("MAD Result3: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 3,0,16);
	printf("MAD Result4: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 4,0,16);
	printf("MAD Result5: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 5,0,16);
	printf("MAD Result6: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 6,0,16);
	printf("MAD Result7: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 7,0,16);
	printf("MAD Result8: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 8,0,16);
	printf("MAD Result9: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 1,1,16);
	printf("MAD Result10: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 2,2,16);
	printf("MAD Result11: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 3,3,16);
	printf("MAD Result12: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 4,4,16);
	printf("MAD Result13: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 5,5,16);
	printf("MAD Result14: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 6,6,16);
	printf("MAD Result15: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 7,7,16);
	printf("MAD Result16: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 8,8,16);
	printf("MAD Result17: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 0,8,16);
	printf("MAD Result18: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 7,2,16);
	printf("MAD Result19: %d",MAD_Result);
	MAD_Result = optIMG_MAD_8x8(mainSourceImg, referenceImg,pitch, 1,5,16);
	printf("MAD Result20: %d",MAD_Result);

}

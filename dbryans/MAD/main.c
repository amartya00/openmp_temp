#include <stdio.h>
#include "MAD_32x32.h"
#include "myMAD_8x8.h"

#define DDR3_BASE_ADDR 0x80000000
#define SIZE1 64*64
#define SIZE2 32*32
#define A_ADDRESS DDR3_BASE_ADDR
#define B_ADDRESS A_ADDRESS + (SIZE1) * 4

int main(void) {

	unsigned char *mainSourceImg;
	unsigned char *referenceImg;
	unsigned int * restrict MAD_Result;
	int i;
	int sx;
	int sy;
	int pitch;

	mainSourceImg = (unsigned char *) A_ADDRESS;
	referenceImg = (unsigned char *) B_ADDRESS;

	printf("Address of mainSourceImg: %.8X, referenceImg: %.8X", mainSourceImg,
			referenceImg);
	printf("Initializing arrays and performing vector add\n");
	for (i = 0; i < SIZE1; i++) {
		mainSourceImg[i] = 0;
	}

	for (i = 0; i < SIZE2; i++) {
		referenceImg[i] = 0;
	}

	pitch = 32;
	sx = 4;
	sy = 4;
	MAD_Result[0] = 0;
	MAD_Result[1] = 0;

	referenceImg[0] = 1;
	referenceImg[1] = 2;
	referenceImg[2] = 3;
	mainSourceImg[1] = 1;
	mainSourceImg[2] = 2;
	mainSourceImg[3] = 3;

	IMG_mad_32x32(mainSourceImg, referenceImg, pitch, sx, sy, MAD_Result);

	printf("MAD results: 0x%08X, %d\n", MAD_Result[0], MAD_Result[1]);

	referenceImg[0] = 0;
	referenceImg[1] = 0;
	referenceImg[2] = 0;
	mainSourceImg[0] = 1;
	mainSourceImg[1] = 2;
	mainSourceImg[2] = 3;
	mainSourceImg[3] = 0;

	IMG_mad_32x32(mainSourceImg, referenceImg, pitch, sx, sy, MAD_Result);

	printf("MAD results: 0x%08X, %d\n", MAD_Result[0], MAD_Result[1]);

	referenceImg[0] = 1;
	referenceImg[1] = 2;
	referenceImg[2] = 3;
	mainSourceImg[0] = 0;
	mainSourceImg[1] = 1;
	mainSourceImg[2] = 2;
	mainSourceImg[3] = 3;

	pitch=8;

	IMG_myMad_8x8(mainSourceImg, referenceImg, pitch, sx, sy, MAD_Result);
	IMG_mad_8x8(mainSourceImg, referenceImg, pitch, sx, sy, MAD_Result);
	IMG_myMad_8x8(mainSourceImg, referenceImg, pitch, sx, sy, MAD_Result);

	printf("MAD results: 0x%08X, %d\n", MAD_Result[0], MAD_Result[1]);

	referenceImg[0] = 0;
	referenceImg[1] = 0;
	referenceImg[2] = 0;
	mainSourceImg[0] = 1;
	mainSourceImg[1] = 2;
	mainSourceImg[2] = 3;
	mainSourceImg[3] = 0;

	IMG_mad_8x8(mainSourceImg, referenceImg, pitch, sx, sy, MAD_Result);

	printf("MAD results: 0x%08X, %d\n", MAD_Result[0], MAD_Result[1]);

	return 0;

}

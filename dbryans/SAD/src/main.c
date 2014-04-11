#include <stdio.h>
#include "SAD_32x32.h"
#include "mySAD_8x8.h"
#include "mySAD_16x16.h"

#include "split.h"


int main(void) {

	unsigned char *mainSourceImg;
	unsigned char *referenceImg;
	unsigned SAD_Result = 0;
	int i;
	int pitch;
	int SIZE1=32*32;
	int SIZE2=64*64;

	mainSourceImg = (unsigned char *)0x80000000;
	referenceImg = (unsigned char *) 0x80001000;
	for (i = 0; i < SIZE1; i++) {
		mainSourceImg[i] = i;
	}

	for (i = 0; i < SIZE2; i++) {
		referenceImg[i] = i;
	}

	pitch=8;

	referenceImg[0]=101;

	SAD_Result = IMG_sad_16x16(mainSourceImg, referenceImg, pitch);
	SAD_Result = IMG_mySad_16x16(mainSourceImg, referenceImg, pitch);
	SAD_Result = IMG_sad_8x8(mainSourceImg, referenceImg, pitch);
	SAD_Result = IMG_mySad_8x8(mainSourceImg, referenceImg, pitch);
	return 0;

}

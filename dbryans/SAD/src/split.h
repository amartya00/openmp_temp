/*
 * split.h
 *
 *  Created on: Aug 3, 2012
 *      Author: Dorian
 */

#ifndef SPLIT_H_
#define SPLIT_H_

unsigned splitSAD_32x32(const unsigned char *restrict srcImg, /* 8x8 source block   */
const unsigned char *restrict refImg, /* Reference image    */
int pitch /* Width of ref image */
) {
	unsigned char *srcImg1;
	unsigned char *srcImg2;
	unsigned char *srcImg3;
	unsigned char *srcImg4;
	unsigned char *refImg1;
	unsigned char *refImg2;
	unsigned char *refImg3;
	unsigned char *refImg4;
	srcImg1 = (unsigned char *) 0x80002000;
	srcImg2 = (unsigned char *) 0x80002200;
	srcImg3 = (unsigned char *) 0x80002400;
	srcImg4 = (unsigned char *) 0x80002600;
	refImg1 = (unsigned char *) 0x80002800;
	refImg2 = (unsigned char *) 0x80002A00;
	refImg3 = (unsigned char *) 0x80002C00;
	refImg4 = (unsigned char *) 0x80002E00;




	unsigned SAD;

	int i, j;
	int k = 0;

	//First partition
	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			srcImg1[k] = srcImg[j + i * 16];
			refImg1[k] = refImg[j + i * 16];
			k++;
		}
	}

	k = 0;
	//Second partition
	for (i = 0; i < 16; i++) {
		for (j = 16; j < 32; j++) {
			srcImg2[k] = srcImg[j + i * 16];
			refImg2[k] = refImg[j + i * 16];
			k++;
		}
	}

	k = 0;
	//Third partition
	for (i = 16; i < 32; i++) {
		for (j = 0; j < 16; j++) {
			srcImg3[k] = srcImg[j + i * 16];
			refImg3[k] = refImg[j + i * 16];
			k++;
		}
	}

	k = 0;
	//Fourth partition
	for (i = 16; i < 32; i++) {
		for (j = 16; j < 32; j++) {
			srcImg4[k] = srcImg[j + i * 16];
			refImg4[k] = refImg[j + i * 16];
			k++;
		}
	}


	//Add all the sad results together
	SAD  = IMG_sad_16x16(srcImg1, refImg1, pitch);
	SAD += IMG_sad_16x16(srcImg2, refImg2, pitch);
	SAD += IMG_sad_16x16(srcImg3, refImg3, pitch);
	SAD += IMG_sad_16x16(srcImg4, refImg4, pitch);

	return SAD;


}


#endif /* SPLIT_H_ */

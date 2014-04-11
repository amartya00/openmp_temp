/*
 * SAD_32x32.h
 *
 *  Created on: Jul 31, 2012
 *      Author: Dorian
 *
 *     Based on the code from IMG_sad_8x8_cn.c provided by the TI image library version 3.1.1.0
 */

#ifndef SAD_32x32_H_
#define SAD_32x32_H_

unsigned IMG_sad_32x32(const unsigned char *restrict srcImg, /* 8x8 source block   */
const unsigned char *restrict refImg, /* Reference image    */
int pitch /* Width of ref image */
) {
	int i, j;
	unsigned sad = 0;

#ifndef NOASSUME
    _nassert(pitch >= 32);
    _nassert((int)srcImg % 32 == 0);
#endif

	for (i = 0; i < 32; i++) {
		for (j = 0; j < 32; j++) {
			sad += abs(srcImg[j + i * 32] - refImg[j + i * pitch]);
		}
	}
	return sad;

}

#endif /* SAD_32x32_H_ */

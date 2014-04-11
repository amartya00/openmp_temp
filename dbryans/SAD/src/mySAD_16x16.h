/*
 * mySAD_16x16.h
 *
 *  Created on: Aug 3, 2012
 *      Author: Dorian
 */

#ifndef MYSAD_16X16_H_
#define MYSAD_16X16_H_

unsigned IMG_mySad_16x16(const unsigned char *restrict srcImg, /* 8x8 source block   */
const unsigned char *restrict refImg, /* Reference image    */
int pitch /* Width of ref image */
) {
	int i, j;
	unsigned sad = 0;

#ifndef NOASSUME
    _nassert(pitch >= 16);
    _nassert((int)srcImg % 16 == 0);
#endif

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			sad += abs(srcImg[j + i * 16] - refImg[j + i * pitch]);
		}
	}
	return sad;

}


#endif /* MYSAD_16X16_H_ */

/*
 * mySAD_8x8.h
 *
 *  Created on: Aug 3, 2012
 *      Author: Dorian
 */

#ifndef MYSAD_8X8_H_
#define MYSAD_8X8_H_

unsigned IMG_mySad_8x8(const unsigned short *restrict srcImg, /* 8x8 source block   */
const unsigned short *restrict refImg, /* Reference image    */
int pitch /* Width of ref image */
) {
	int i, j;
	unsigned sad = 0;

#ifndef NOASSUME
    _nassert(pitch >= 8);
    _nassert((int)srcImg % 8 == 0);
#endif

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			sad += abs(srcImg[j + i * 8] - refImg[j + i * pitch]);
		}
	}
	return sad;

}


#endif /* MYSAD_8X8_H_ */

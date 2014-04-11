/*
 * optSAD_8x8.h
 *
 *  Created on: Aug 6, 2012
 *      Author: Dorian
 */

#ifndef OPTSAD_8X8_H_
#define OPTSAD_8X8_H_

unsigned optIMG_sad8x8(const unsigned short *restrict srcImg, /* 8x8 source block   */
const unsigned short *restrict refImg, /* Reference image    */
int pitch, /*width of main image*/
int x, /* x coordinate of starting point*/
int y,/* y coordinate of starting point*/
int s /*length of one side of square*/
) {
	int i,j,k;
	unsigned sad = 0;

#ifndef NOASSUME
    _nassert(pitch >= 8);
    _nassert((int)srcImg % 8 == 0);
#endif
    k=0;
	for (i = y; i < (y+s); i++) {
		for (j = x; j < (x+s); j++) {
			sad += abs(srcImg[j + i * pitch] - refImg[k]);
			k++;
		}
	}
	return sad;

}


#endif /* OPTSAD_8X8_H_ */

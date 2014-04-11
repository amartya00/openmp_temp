/*
 * optSAD_32x32.h
 *
 *  Created on: Aug 6, 2012
 *      Author: Dorian
 */

#ifndef OPTSAD_32X32_H_
#define OPTSAD_32X32_H_


unsigned optIMG_sad_32x32(const unsigned short *restrict srcImg, /* 8x8 source block   */
const unsigned short *restrict refImg, /* Reference image    */
int pitch, /*width of main image*/
int x, /* x coordinate of starting point*/
int y,/* y coordinate of starting point*/
int s /*length of one side of square*/
) {
	int i,j,k;
	unsigned sad=0;


#ifndef NOASSUME
    _nassert(pitch >= 32);
    _nassert((int)srcImg % 32 == 0);
#endif
    i=0;
    j=0;
    k=0;
    for (i = y; i < (y+s); i++) {
		for (j = x; j < (x+s); j++) {
			sad += abs(srcImg[(j+x) + (i+y) * pitch] - refImg[k]);
			k++;
		}
	}
	return sad;
}

#endif /* OPTSAD_32X32_H_ */

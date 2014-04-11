/*
 * optMAD_8x8.h
 *
 *  Created on: Aug 17, 2012
 *      Author: Dorian
 */

#ifndef OPTMAD_8X8_H_
#define OPTMAD_8X8_H_

unsigned optIMG_MAD_8x8(const unsigned short *restrict srcImg, /* 8x8 source block   */
const unsigned short *restrict refImg, /* Reference image    */
int pitch, /*width of main image*/
int x, /* x coordinate of starting point*/
int y,/* y coordinate of starting point*/
int s /*length of one side of square*/
) {
	int i,j,k;
	unsigned mad=0;


#ifndef NOASSUME
    _nassert(pitch >= 8);
    _nassert((int)srcImg % 8 == 0);
#endif
    i=0;
    j=0;
    k=0;
    printf("x:%d y:%d\n",x,y);
	// for (i = y; i < (y+s); i++) {
    for (i = 0; i < s; i++) {
		// for (j = x; j < (x+s); j++) {
		for (j = 0; j < s; j++) {
			mad += abs(srcImg[(j+x) + (i+y) * pitch] - refImg[k]);
			k++;
		}
	}
    mad= mad/64; //8x8=64
	return mad;

}



#endif /* OPTMAD_8X8_H_ */

/*
 * optMAD_32x32.h
 *
 *  Created on: Aug 17, 2012
 *      Author: Dorian
 */

#ifndef OPTMAD_32X32_H_
#define OPTMAD_32X32_H_

unsigned optIMG_mad_32x32(const unsigned short *restrict srcImg, /* 8x8 source block   */
const unsigned short *restrict refImg, /* Reference image    */
int pitch, /*width of main image*/
int x, /* x coordinate of starting point*/
int y,/* y coordinate of starting point*/
int s /*length of one side of square*/
) {
	int i,j,k;
	unsigned long mad=0;


#ifndef NOASSUME
    _nassert(pitch >= 32);
    _nassert((int)srcImg % 32 == 0);
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
    mad= mad/1024 ; //32x32=1024
	return mad;

}


#endif /* OPTMAD_32X32_H_ */

/*
 * MAD_8x8_OMP.c
 *
 *  Created on: Jan 24, 2013
 *      Author: Dorian
 */



#include "SAD_32x32_OMP.h"

int MAD_8x8_OMP (unsigned short *ii, unsigned short *act_block, int h_length)
{
	int i,j;
		int mad=0;
		unsigned short *kk;
		kk= act_block;
		i= 8;
		while (i--){
		for (j=0;j<8;j++) mad+= abs(*(ii+j)-*(kk+j));
		ii+=h_length;
		kk+=8;
		}
		mad= mad/64 ; //8x8=64
		return mad;

}

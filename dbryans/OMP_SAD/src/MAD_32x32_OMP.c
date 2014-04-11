/*
 * MAD_32x32_OMP.c
 *
 *  Created on: Jan 24, 2013
 *      Author: Dorian
 */


#include "SAD_32x32_OMP.h"

int MAD_32x32_OMP (unsigned short *ii, unsigned short *act_block, int h_length)
{
	int i,j;
		int mad=0;
		unsigned short *kk;
		kk= act_block;
		i= 32;
		while (i--){
		for (j=0;j<32;j++) mad+= abs(*(ii+j)-*(kk+j));
		ii+=h_length;
		kk+=32;
		}
		mad= mad/1024 ; //32x32=1024
		return mad;

}

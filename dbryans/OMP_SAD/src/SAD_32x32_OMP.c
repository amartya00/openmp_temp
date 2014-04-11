/*
 * SAD_32x32_OMP.c
 *
 *  Created on: Jan 16, 2013
 *      Author: Dorian
 */

#include "SAD_32x32_OMP.h"

int SAD_32x32_OMP (unsigned short *ii, unsigned short *act_block, int h_length)
{
	int i,j;
		int sad=0;
		unsigned short *kk;
		kk= act_block;
		i= 32;
		while (i--){
		for (j=0;j<32;j++) sad+= abs(*(ii+j)-*(kk+j));
		ii+=h_length;
		kk+=32;
		}
		return sad;

}

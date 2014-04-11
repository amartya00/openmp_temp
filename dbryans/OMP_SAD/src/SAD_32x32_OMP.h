/*
 * SAD_32x32_OMP.h
 *
 *  Created on: Jan 8, 2013
 *      Author: Dorian
 */
#include <ti/omp/omp.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

#ifndef SAD_32X32_OMP_H_
#define SAD_32X32_OMP_H_
#define NTHREADS  8

int SAD_32x32_OMP (unsigned short *ii, unsigned short *act_block, int h_length);
int SAD_8x8_OMP (unsigned short *ii, unsigned short *act_block, int h_length);
int MAD_32x32_OMP (unsigned short *ii, unsigned short *act_block, int h_length);
int MAD_8x8_OMP (unsigned short *ii, unsigned short *act_block, int h_length);

#endif /* SAD_32X32_OMP_H_ */

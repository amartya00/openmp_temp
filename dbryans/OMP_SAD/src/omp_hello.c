/******************************************************************************
 * FILE: omp_hello.c
 * DESCRIPTION:
 *   OpenMP Example - Hello World - C/C++ Version
 *   In this simple example, the master thread forks a parallel region.
 *   All threads in the team obtain their unique thread number and print it.
 *   The master thread only prints the total number of threads.  Two OpenMP
 *   library routines are used to obtain the number of threads and each
 *   thread's number.
 * AUTHOR: Blaise Barney  5/99
 * LAST REVISED: 04/06/05
 ******************************************************************************/
#include <ti/omp/omp.h>
#include <xdc/runtime/Timestamp.h>

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include "SAD_32x32_OMP.h"
#define FEATURE_ROWS (unsigned short) 32
#define FEATURE_COLS (unsigned short) 32
#define IMG_ROWS (unsigned short) 1080
#define IMG_COLS (unsigned short) 1960
#define OUTPUT_ROWS (IMG_ROWS) - (FEATURE_ROWS)
#define OUTPUT_COLS (IMG_COLS) - (FEATURE_COLS)
// #define SIZE (x-n)*(y-m)

void main() {

	unsigned *SAD_Result1;
	// unsigned SAD_Result1[(OUTPUT_COLS)*(OUTPUT_ROWS)];
	// unsigned SAD_Result2[1];
	unsigned short *mainSourceImg;
	unsigned short *referenceImg;
	int row, col, i,j;

	unsigned long delta = 0;
	unsigned int timestamp = 0;

	//Initialize Main Image and Reference Image
	//SAD_Result1 = (unsigned *) 0xA1200000;
	//SAD_Result2 = (unsigned *) 0xA1220000;
	mainSourceImg = (unsigned short *) 0xA2100000;
	SAD_Result1 = (unsigned  *) 0xA4000000;

	for (i = 0; i < (IMG_COLS)*(IMG_ROWS); i++) {
		mainSourceImg[i] = i;
	}

	// referenceImg = (unsigned short *) 0xA2000000;

	for (i = 0; i < (FEATURE_COLS)*(FEATURE_ROWS); i++) {
		referenceImg[i] = i;
	}
	timestamp = Timestamp_get32();
//Sweep through all of Main Image using all 8 cores
#pragma omp parallel shared(mainSourceImg, referenceImg, SAD_Result1) private(row)
	{

 #pragma omp for schedule (dynamic,1) private(col) nowait
//#pragma omp for private(col)
		for (row = 0; row < OUTPUT_ROWS; row++) {
			for (col = 0; col < OUTPUT_COLS; col++)
				// SAD_Result1[(OUTPUT_COLS*row)+col] = SAD_32x32_OMP(
						// mainSourceImg + ((OUTPUT_COLS*row)+col), referenceImg, IMG_ROWS);
				for (i = 0; i < FEATURE_COLS; i++)
					for(j=0; j < FEATURE_ROWS; j++)
						SAD_Result1[(OUTPUT_COLS)*row+col] += abs(mainSourceImg[(row+i)*(IMG_COLS)+col+j] - referenceImg[i*(FEATURE_COLS)+j]);

		}

	}

	delta = Timestamp_get32() - timestamp;

	printf("# of Clock Cycles for multi core: %lu\n", delta);
	printf("Time: %fms\n", ((float)delta)/1000000);

	 printf("At single core\n");
	 timestamp = Timestamp_get32();
	for (row = 0; row < OUTPUT_ROWS; row++) {
				for (col = 0; col < OUTPUT_COLS; col++)
					// SAD_Result1[(OUTPUT_COLS*row)+col] = SAD_32x32_OMP(
							// mainSourceImg + ((OUTPUT_COLS*row)+col), referenceImg, IMG_ROWS);
					for (i = 0; i < FEATURE_COLS; i++)
						for(j=0; j < FEATURE_ROWS; j++)
							SAD_Result1[(OUTPUT_COLS)*row+col] += abs(mainSourceImg[(row+i)*(IMG_COLS)+col+j] - referenceImg[i*(FEATURE_COLS)+j]);

			}
	 delta = Timestamp_get32() - timestamp;

	 printf("# of Clock Cycles for single core: %lu\n", delta);
	 printf("Time: %fms\n", ((float)delta)/1000000);
	 printf("DONE!\n");

//	for (i = 0; i < SIZE; i++) {
//			printf("SAD_Result 8 cores | SAD_Result 1 core: %d | %d\n ", SAD_Result1[i],SAD_Result2[i]);
//		}
}

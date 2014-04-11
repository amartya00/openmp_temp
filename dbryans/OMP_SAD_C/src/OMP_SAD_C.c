/*
 ============================================================================
 Name        : OMP_SAD_C.c
 Author      : Dorian Fernandez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <assert.h>
#include <time.h>
#include <omp.h>
#include <sys/time.h>
//#include "SAD_32x32_OMP.h"
#define FEATURE_ROWS (unsigned short) 32
#define FEATURE_COLS (unsigned short) 32
#define IMG_ROWS (unsigned short) 1080
#define IMG_COLS (unsigned short) 1960 	
#define OUTPUT_ROWS (IMG_ROWS) - (FEATURE_ROWS)
#define OUTPUT_COLS (IMG_COLS) - (FEATURE_COLS)
#define SIZE (OUTPUT_COLS)*(OUTPUT_ROWS)

// #define NUM_THREADS (unsigned int)8
// #define CHUNK_SIZE (OUTPUT_ROWS)/(NUM_THREADS)

int main(void) {
	printf("At the beginning\n");
	int result_size = SIZE;
	unsigned int SAD_Result1[SIZE];
	// unsigned SAD_Result1[(OUTPUT_COLS)*(OUTPUT_ROWS)];
	// unsigned SAD_Result2[1];
	unsigned short mainSourceImg[(IMG_COLS) * (IMG_ROWS)];
	unsigned short referenceImg[(FEATURE_COLS) * (FEATURE_ROWS)];
	int row, col, i, j;
	struct timeval start,end;

	// omp_set_num_threads(NUM_THREADS);
	//unsigned int delta = 0;
	//unsigned int timestamp = 0;

	//Initialize Main Image and Reference Image
	//SAD_Result1 = (unsigned *) 0xA1200000;
	//SAD_Result2 = (unsigned *) 0xA1220000;
	//mainSourceImg = (unsigned short *) 0xA2100000;
	//SAD_Result1 = (unsigned  *) 0xA4000000;

	for (i = 0; i < (IMG_COLS) * (IMG_ROWS); i++) {
		mainSourceImg[i] = i;
	}
	// referenceImg = (unsigned short *) 0xA2000000;

	for (i = 0; i < (FEATURE_COLS) * (FEATURE_ROWS); i++) {
		referenceImg[i] = i;
	}
	//timestamp = Timestamp_get32();

	//Sweep through all of Main Image using all 8 cores
	// printf("\n Spawning %d threads for SAD\n", NUM_THREADS);
	gettimeofday(&start,NULL);
#pragma omp parallel shared(mainSourceImg, referenceImg, SAD_Result1) private(row,col,i,j)
	{

		// #pragma omp for schedule (dynamic,1) private(col) nowait
// #pragma omp for schedule(static,CHUNK_SIZE)
#pragma omp for schedule(static)
		for (row = 0; row < OUTPUT_ROWS; row++) {
			for (col = 0; col < OUTPUT_COLS; col++)
				// SAD_Result1[(OUTPUT_COLS*row)+col] = SAD_32x32_OMP(
				// mainSourceImg + ((OUTPUT_COLS*row)+col), referenceImg, IMG_ROWS);
				for (i = 0; i < FEATURE_COLS; i++)
					for (j = 0; j < FEATURE_ROWS; j++)
						SAD_Result1[(OUTPUT_COLS) * row + col] += abs(
								mainSourceImg[(row + i) * (IMG_COLS) + col + j]
										- referenceImg[i * (FEATURE_COLS) + j]);

		}

	}

	gettimeofday(&end,NULL);
	printf(" took %0.6f seconds.\n", (end.tv_sec + end.tv_usec/1.e6) - (start.tv_sec + start.tv_usec/1.e6));
	//delta = Timestamp_get32() - timestamp;

//		printf("# of Clock Cycles: %d\n", j);
	//printf("Time: %fms\n", ((float)delta)/1000000);

	// timestamp = Timestamp_get32();

	gettimeofday(&start,NULL);
	for (row = 0; row < OUTPUT_ROWS; row++) {
		for (col = 0; col < OUTPUT_COLS; col++)
			// SAD_Result1[(OUTPUT_COLS*row)+col] = SAD_32x32_OMP(
			// mainSourceImg + ((OUTPUT_COLS*row)+col), referenceImg, IMG_ROWS);
			for (i = 0; i < FEATURE_COLS; i++)
				for (j = 0; j < FEATURE_ROWS; j++)
					SAD_Result1[(OUTPUT_COLS) * row + col] += abs(
							mainSourceImg[(row + i) * (IMG_COLS) + col + j]
									- referenceImg[i * (FEATURE_COLS) + j]);

	}
	gettimeofday(&end,NULL);
	printf(" took %0.6f seconds.\n", (end.tv_sec + end.tv_usec/1.e6) - (start.tv_sec + start.tv_usec/1.e6));
	// delta = Timestamp_get32() - timestamp;

	// printf("# of Clock Cycles: %d\n", delta);
	// printf("Time: %fms\n", ((float)delta)/1000000);

		// for (i = 0; i < SIZE; i++) {
				// printf("SAD_Result 8 cores | SAD_Result 1 core: %d | %d\n ", SAD_Result1[i],SAD_Result2[i]);
			// }

	return 0;
}



//#include <ti/omp/omp.h>

#include <string.h>
#include <assert.h>
#include <stdio.h>

#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

#define DDR3_BASE_ADDR 0x80000000
#define SIZE 0x10000
/* #define A_ADDRESS DDR3_BASE_ADDR */
/* #define B_ADDRESS A_ADDRESS + (SIZE) * 4 */
/* #define C_ADDRESS B_ADDRESS + (SIZE) * 4 */

#define IMG_IN_ADDRESS  0x80000000
#define IMG_OUT_ADDRESS 0x85000000

#define IMG_COLS (unsigned short)1920
#define IMG_ROWS (unsigned short)1080

#define FEATURE_SIZE (unsigned short)4


#define OUTPUT_ROWS IMG_ROWS - FEATURE_SIZE + 1
#define OUTPUT_COLS IMG_COLS - FEATURE_SIZE + 1

#define NTHREADS  8
#define CHUNK_SIZE (OUTPUT_ROWS)/(NTHREADS)

void img_conv (void)  
{
    
    int nthreads;
    nthreads = NTHREADS;
    //omp_set_num_threads(nthreads);
    int i, j, k ,l;
    unsigned short *imgIn, featureIn[FEATURE_SIZE][FEATURE_SIZE];
    unsigned int *imgOut;

    //unsigned long long startTime64 = 0;
    //unsigned long long endTime64 = 0;

    //unsigned long long delta = 0;
    unsigned int delta    = 0;
    //unsigned int delta_lo = 0;
    //unsigned int delta_hi = 0;
    unsigned int timestamp = 0;


    unsigned temp = 0;

    Types_Timestamp64 startTime, endTime;


    imgIn = (unsigned short *)IMG_IN_ADDRESS;
    imgOut = (unsigned int *)IMG_OUT_ADDRESS;

    

    // some image initialization
    for (i=0; i < IMG_ROWS; i++){
        temp = 0;
        for(j = 0; j < IMG_COLS; j++){
            temp = temp +1;
            imgIn[i*IMG_COLS + j] = temp;
        }
    }

    /* Some feature initializations */
    for (i=0; i < FEATURE_SIZE; i++){
        temp = 0;
        for(j = 0; j < FEATURE_SIZE; j++){
            temp = temp +1;
            featureIn[i][j] = temp;
        }
    }

    
    timestamp = Timestamp_get32();
    //Timestamp_get64(&startTime);

    //#pragma omp parallel shared(imgIn, imgOut) private(i,j,k,l)
    {

        //#pragma omp for 
        for (i=0; i < OUTPUT_ROWS; i++){
            for (j=0; j < OUTPUT_COLS; j++){
                for (k = 0; k < FEATURE_SIZE; k++){
                    for (l = 0; l < FEATURE_SIZE; l++){
                        temp += imgIn[(i+k)*IMG_COLS + (j+l)] * featureIn[k][l];
                        //imgOut[i][j] += imgIn[i+k][j+l] * featureIn[k][l];
                    }
                }
                imgOut[i*OUTPUT_COLS + j] = temp;
                temp = 0;
            }
        }
    }  /* end of parallel section */

    //Timestamp_get64(&endTime);

    //startTime64 = ((unsigned long long)(startTime.hi<<32)) || (startTime.lo);
    //endTime64 = ((unsigned long long )(endTime.hi<<32)) || (endTime.lo);
    delta = Timestamp_get32() - timestamp;    
    //delta_lo = endTime.lo - startTime.lo;
    //delta_hi = endTime.hi - startTime.hi;

    
    //printf("\n# of Clock Cycles: %d (high), %d (low)\n", delta_hi, delta_lo);
    printf("\nexecution time: %0.2fms\n", (float)delta/1000000);
}
 

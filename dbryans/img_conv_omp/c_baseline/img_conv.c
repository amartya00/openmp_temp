#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define IMG_COLS 1200
#define IMG_ROWS 720
#define FEATURE_SIZE 16
#define OUTPUT_ROWS IMG_ROWS - FEATURE_SIZE + 1
#define OUTPUT_COLS IMG_COLS - FEATURE_SIZE + 1

#define NTHREADS  8

double timerval () {
    struct timeval st;
    gettimeofday(&st, NULL);
    return (st.tv_sec+st.tv_usec*1e-6);
}

double totaltimesec (double start, double stop) {
    return (stop-start);
}

void main (void)  
{
    
    int nthreads;
    nthreads = NTHREADS;
    omp_set_num_threads(nthreads);
    int i, chunk, j, k ,l;
    unsigned short imgIn[IMG_ROWS][IMG_COLS], featureIn[FEATURE_SIZE][FEATURE_SIZE];
    unsigned imgOut[OUTPUT_ROWS][OUTPUT_COLS];
    
    double startTime = 0;
    double endTime = 0;

    unsigned temp = 0;
    unsigned check;

    /* Some feature initializations */
    for (i=0; i < FEATURE_SIZE; i++){
        temp = 0;
        for(j = 0; j < FEATURE_SIZE; j++){
            temp = temp +1;
            featureIn[i][j] = temp;
        }
    }

    for (i=0; i < IMG_ROWS; i++){
        temp = 0;
        for(j = 0; j < IMG_COLS; j++){
            temp = temp +1;
            imgIn[i][j] = temp;
        }
    }

    printf("\n Finished init\n");

    startTime = timerval();
#pragma omp parallel shared(imgIn, imgOut) private(i,j,k,l)
    {

#pragma omp for 
        for (i=0; i < OUTPUT_ROWS; i++){
            for (j=0; j < OUTPUT_COLS; j++){
                for (k = 0; k < FEATURE_SIZE; k++){
                    for (l = 0; l < FEATURE_SIZE; l++){
                        // imgOut[i*OUTPUT_COLS + j] += imgIn[(i+k)*IMG_COLS + (j+l)] * featureIn[k*FEATURE_SIZE + l];
                        imgOut[i][j] += imgIn[i+k][j+l] * featureIn[k][l];
                    }
                }
            }
        }
    }  /* end of parallel section */
    endTime = timerval();
    printf (" \nelapsed time in seconds: %.8f\n", (endTime - startTime));

    printf("\n In calc\n");
    for (i=0; i < OUTPUT_ROWS; i++){
        for (j=0; j < OUTPUT_COLS; j++){
            for (k = 0; k < FEATURE_SIZE; k++){
                for (l = 0; l < FEATURE_SIZE; l++){
                    check += imgIn[i+k][j+l] * featureIn[k][l];
                }
            }
            printf ("\n%d",check);
            if (check != imgOut[i][j])
                printf("\nError\n");
            check = 0;
        }
    }
            
}
 

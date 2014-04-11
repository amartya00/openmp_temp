

#include "img_conv.h"

void img_conv (void)  
{
    
    int nthreads;
    nthreads = NTHREADS;

    

    int i, j, k ,l;
    unsigned short * restrict imgIn;
    short * restrict featureIn;
    unsigned int *restrict imgOut;

    uint64_t start_time, end_time;
    
    unsigned short tid = 0;

    unsigned int sum = 0;

    int temp = 0;

    unsigned int imgAddr = 0;
    unsigned int featureAddr = 0;

    unsigned int temp_sum = 0;

    long long imgInPix_64 = 0;
    long long featureInPix_64 = 0;

    unsigned short *imgPtr;
    short *featurePtr;
    
    int idx = 0;

    omp_set_num_threads(nthreads);

    imgIn = (unsigned short * )IMG_IN_ADDRESS;
    
    featureIn = (short * )FEATURE_ADDRESS;
    
    imgOut = (unsigned int *)IMG_OUT_ADDRESS;
    
    
    // some image initialization
    for (i=0; i < IMG_ROWS; i++){
        temp = 0;
        for(j = 0; j < IMG_COLS; j++){
            temp = temp +1;
            // imgIn[i*IMG_COLS + j] = temp;
            imgIn[i*IMG_COLS + j] = 1;
        }
    }
    
    /* Some feature initializations */
    for (i=0; i < FEATURE_SIZE; i++){
        temp = 0;
        for(j = 0; j < FEATURE_SIZE; j++){
            temp = temp +1;
            featureIn[i*(FEATURE_SIZE) + j] = temp;
            // featureIn[i*(FEATURE_SIZE) + j] = 1;
        }
    }

    
    start_time = _itoll(TSCH,TSCL);

    temp = 0;
#pragma omp parallel shared(imgIn, imgOut) private(i,j,k,l, temp, imgInPix_64, featureInPix_64)
    {
        // tid = omp_get_thread_num();
#pragma omp for
        for (i = 0; i < OUTPUT_ROWS; i++){
            // idx = i*(IMG_COLS);
            for (j = 0; j < OUTPUT_COLS; j++){
                // idx = idx + j;
                for (k = 0; k < FEATURE_SIZE; k++){
                    // imgPtr = (unsigned short *)((IMG_IN_ADDRESS) + 2*(idx+k*(IMG_COLS)));
                    // featurePtr = (short *)((FEATURE_ADDRESS) + 2*k*(FEATURE_SIZE));
                    // featurePtr = (short *)(0x83000004);
                        for (l = 0; l < FEATURE_SIZE-1; l += 4){
                            
                            imgInPix_64 = _mem8(&imgIn[(i+k)*(IMG_COLS) + j +l]);
                            featureInPix_64 = _mem8(&featureIn[k*(FEATURE_SIZE)+l]);
                            
                            // imgInPix_64 = _mem8(imgPtr+l);
                            // featureInPix_64 = _mem8(featurePtr+l);
                            temp += _dotpsu4h(imgInPix_64, featureInPix_64);
                        
                       // imgOut[i][j] += imgIn[i+k][j+l] * featureIn[k][l];
                   }

                    temp += imgIn[(i+k)*IMG_COLS + (j) + (FEATURE_SIZE)-1] * featureIn[k*(FEATURE_SIZE) + (FEATURE_SIZE)-1];
                    // printf("final:%d;\n",temp);
                }
                imgOut[i*(OUTPUT_COLS) + j] = temp;
                temp = 0;
            }
        }
    }  /* end of parallel section */

    
        end_time = _itoll(TSCH,TSCL);
        printf("cycle count:%lld\n", end_time-start_time);    
    //printf("\n execution time: %0.2fms\n", (float)delta/1000000);
}
 

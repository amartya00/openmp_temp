

#include "img_conv.h"

void img_conv (void)  
{
    
    int nthreads;
    nthreads = NTHREADS;

    

    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    
    unsigned short * restrict imgIn;
    unsigned short * restrict imgInL2;
    short featureIn[(FEATURE_SIZE) * (FEATURE_SIZE)];

    unsigned int *restrict imgOut;
    unsigned int *restrict imgOutMSMC;

    uint64_t start_time, end_time;
    
    unsigned int featureAddr = 0;

    unsigned int temp_sum = 0;

    long long imgInPix_64 = 0;
    long long featureInPix_64 = 0;

    unsigned short *imgPtr;
    short *featurePtr;
    
    int idx = 0;

    // omp_set_num_threads(nthreads);

    imgIn = (unsigned short * )IMG_IN_ADDRESS;

    imgInL2Seg0 = (unsigned short * )IMG_IN_L2_SEG0_ADDRESS;
    imgInL2Seg1 = (unsigned short * )IMG_IN_L2_SEG1_ADDRESS;
    
    // featureIn = (short * )FEATURE_ADDRESS;
    
    imgOutMSMCSeg0 = (unsigned int *)IMG_OUT_MSMC_SEG0_ADDRESS;
    imgOutMSMCSeg1 = (unsigned int *)IMG_OUT_MSMC_SEG0_ADDRESS;

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

    printf("starting conv\n");
    for (m = 0; m < (OUTPUT_ROWS)/(WINDOW_ROWS - FEATURE_SIZE); m++) {
        for (n = 0; n < (OUTPUT_COLS)/(WINDOW_COLS - FEATURE_SIZE); n++) {

            if (n%2) {
                edmaInitiateXfer( imgInL2Seg0, imgIn+m*(OUTPUT_COLS)+n*(WINDOW_COLS-FEATURE_SIZE), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                                                   SRCBIDX, DSTBIDX, 1,
                                                   1, 0, 1);
                kernel(imgInL2Seg1, featureIn, imgOutMSMCSeg1);
                // edmaWait4Completion(1);
                edmaInitiateXfer( imgOut+m*(WINDOW_ROWS-FEATURE_SIZE)*(OUTPUT_COLS)+n*(WINDOW_COLS-FEATURE_SIZE), imgOutMSMCSeg0, (int)(2*NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                                  2*(DSTBIDX), 2*(SRCBIDX), 1,
                                  1, 1, 1);
                edmaWait4Completion(0);
                edmaWait4Completion(1);
            }
            else {
                edmaInitiateXfer( imgInL2Seg1, imgIn+m*(OUTPUT_COLS)+n*(WINDOW_COLS-FEATURE_SIZE), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                                                   SRCBIDX, DSTBIDX, 1,
                                                   1, 0, 1);
                kernel(imgInL2Seg0, featureIn, imgOutMSMCSeg0);
                edmaInitiateXfer( imgOut+m*(WINDOW_ROWS-FEATURE_SIZE)*(OUTPUT_COLS)+n*(WINDOW_COLS-FEATURE_SIZE), imgOutMSMCSeg1, (int)(2*NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                              2*(DSTBIDX), 2*(SRCBIDX), 1,
                                  1, 1, 1);
                edmaWait4Completion(0);
                edmaWait4Completion(1);
            }
            


        }
    }
                 
    end_time = _itoll(TSCH,TSCL);
    printf("cycle count:%lld\n", end_time-start_time);    
    //printf("\n execution time: %0.2fms\n", (float)delta/1000000);
}
 

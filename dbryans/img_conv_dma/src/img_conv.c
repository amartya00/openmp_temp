#include "img_conv.h"



int img_conv(unsigned short *imgIn, unsigned int *imgOut, unsigned short *featureIn, unsigned short imgRows, unsigned short imgCols, unsigned short featureSize){

    unsigned short i = 0;
    unsigned short j = 0;
    unsigned short k = 0;
    unsigned short l = 0;
    unsigned int *imgOutL2;
    unsigned int chunkSize = 0;
    unsigned int temp = 0;
    unsigned short tid = 0;

    // chunkSize = (imgRows)/(NTHREADS);

    imgOutL2 = (unsigned int*)(L2SRAM_ADDR);

    //printf("\n In img_conv");
    
    /* for (i = 0; i < imgRows; i++){ */
    /*     for (j = 0; j < imgCols; j++){ */
    /*         imgOutL2[i*imgCols + j] = imgIn[i*imgCols +j]; */
    /*     } */
    /* } */

    //#pragma omp parallel shared(imgIn, imgOut) private(i,j,k,l, temp)
    {
        //tid = omp_get_thread_num();
        //for (i = tid*(chunkSize); i < (tid+1)*(chunkSize); i++){
        for (i = tid*(chunkSize); i < (tid+1)*(chunkSize); i++){
            for (j=0; j < imgCols; j++){
                for (k = 0; k < featureSize; k++){
                    for (l = 0; l < featureSize; l++){
                        temp += abs((imgIn[(i+k)*imgCols + (j+l)] - featureIn[k*featureSize+l]));
                        //imgOut[i][j] += imgIn[i+k][j+l] * featureIn[k][l];
                    }
                }
                imgOutL2[i*imgCols + j] = temp;
                 temp = 0;
            }
        }

    }  /* end of parallel section */

    edmaInitiateXfer( imgOut, imgOutL2, (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
          SRCBIDX, DSTBIDX, 1,
          1, 1, 1);
    edmaWait4Completion(1);

    return 0;
}










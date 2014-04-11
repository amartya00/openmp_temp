#include "img_pass_thru.h"


int img_pass_thru(unsigned short *imgIn, unsigned int *imgOut, unsigned short imgRows, unsigned short imgCols, unsigned short featureSize){

    unsigned short i = 0;
    unsigned short j = 0;
    unsigned int *imgOutL2;

    imgOutL2 = (unsigned int*)(L2SRAM_ADDR);

    //printf("\n In img_conv");
    
    for (i = 0; i < imgRows; i++){
        for (j = 0; j < imgCols; j++){
            imgOutL2[i*imgCols + j] = imgIn[i*imgCols +j];
            /* imgOut[i*imgCols + j] = imgIn[i*imgCols +j]; */
        }
    }

    /* for (i = 0; i < imgRows; i++){ */
    /*     for (j = 0; j < imgCols; j++){ */
    /*         imgOut[i*imgCols + j] = imgOutL2[i*imgCols +j]; */
    /*     } */
    /* } */
    edmaInitiateXfer( imgOut, imgOutL2, (unsigned short)(NUM_BYTES), (unsigned short)(NUM_ARRAY), (unsigned short)(NUM_FRAMES),
          SRCBIDX, DSTBIDX, 1,
          1, 1, 1);
    edmaWait4Completion(1);

    return 0;
}










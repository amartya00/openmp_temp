#include <stdio.h>
// #include "man.h"
// #include "img_write.h"

 #include <xdc/runtime/Timestamp.h>
#include "edma.h"

#define NUM_COLS 1024
#define NUM_ROWS 720
#define SHIFT (0)

/* #define L2SRAM_ADDR_SEG0 0x82000000 */
/* #define L2SRAM_ADDR_SEG1 0x83000000 */

#define NUM_BYTES 1024*32 -1
#define NUM_ARRAY 4
#define NUM_FRAMES 1
#define SRCBIDX NUM_BYTES
#define DSTBIDX NUM_BYTES

#define DMA_TX_SIZE (NUM_BYTES) * (NUM_ARRAY)
#define L2SRAM_ADDR_SEG_I0 0x00800000
#define L2SRAM_ADDR_SEG_I1 (L2SRAM_ADDR_SEG_I0) + (DMA_TX_SIZE)
#define L2SRAM_ADDR_SEG_O0 (L2SRAM_ADDR_SEG_I1) + (DMA_TX_SIZE)
#define L2SRAM_ADDR_SEG_O1 (L2SRAM_ADDR_SEG_O0) + (DMA_TX_SIZE)

#define IMG_SIZE (NUM_COLS) * (NUM_ROWS)
#define NUM_DMA_TX (IMG_SIZE) / (DMA_TX_SIZE)

#define CHUNK_SIZE 3*(NUM_COLS)
#define NUM_RUNS (DMA_TX_SIZE) / (CHUNK_SIZE)

// #define L2SRAM_ADDR_SEG1 0x00830000

/* #define NUM_BYTES 8 */
/* #define NUM_ARRAY 1024*32 - 1 */
/* #define NUM_FRAMES 1 */
/* #define SRCBIDX NUM_BYTES */
/* #define DSTBIDX NUM_BYTES */

int test (void){

    unsigned int i =0;
    unsigned int j =0;
    
    // const unsigned char *in;
    const unsigned char *in;
    unsigned char *out;

    unsigned int delta = 0;
    unsigned int timestamp = 0;

    unsigned char *l2Mem0;
    unsigned char *l2Mem1;

    unsigned char *outL2Mem0;
    unsigned char *outL2Mem1;

    unsigned char *ddr3Mem0;
    unsigned char *ddr3Mem1;

    unsigned char mask[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    in  = (unsigned char *)(0x80000000);
    out = (unsigned char *)(0x81000000);

    unsigned short  theta = 280;

    l2Mem0 = (unsigned char *)(L2SRAM_ADDR_SEG_I0);
    l2Mem1 = (unsigned char *)(L2SRAM_ADDR_SEG_I1);

    outL2Mem0 = (unsigned char *)(L2SRAM_ADDR_SEG_O0);
    outL2Mem1 = (unsigned char *)(L2SRAM_ADDR_SEG_O1);

    ddr3Mem0 = (unsigned char *)(0x84000000);
    ddr3Mem1 = (unsigned char *)(0x85000000);

    /* // generate horizontal gradient */
    /* for (i = 0; i < NUM_ROWS; i++) { */
    /*     // if (i > 511) pix = 255; */
    /*     // else pix = 0; */
    /*     for (j = 0; j < NUM_COLS; j++){ */
    /*         in[i*NUM_COLS + j] = (j) & (unsigned int)(0xFF); */
    /*     } */
    /* } */

    //check CPU copy from DDR3 to L2SRAM 
    /* for (i = 0; i < (NUM_ROWS)/2; i++) { */
    /*     // if (i > 511) pix = 255; */
    /*     // else pix = 0; */
    /*     for (j = 0; j < NUM_COLS; j++){ */
    /*         l2Mem0[i*NUM_COLS + j] = in[i*NUM_COLS + j]; */
    /*     } */
    /* } */
    
    edmaInit();
    timestamp = Timestamp_get32();

    edmaInitiateXfer( l2Mem0, in+0*(DMA_TX_SIZE), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
          SRCBIDX, DSTBIDX, 1,
          1, 0, 1);
    edmaWait4Completion(0);

    for (i = 0; i < NUM_DMA_TX; i++) {

        if ((i & (unsigned int)(0x01)) == 0){
            edmaInitiateXfer( l2Mem1, in+((i+1)*(DMA_TX_SIZE)), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                              SRCBIDX, DSTBIDX, 1,
                              1, 0, 1);
            if (i != 0)
                edmaInitiateXfer(out+((i-1)*(DMA_TX_SIZE)), outL2Mem1,(int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                  SRCBIDX, DSTBIDX, 1,
                  1, 1, 1);
            for (j = 0; j < NUM_RUNS; j++) IMG_conv_3x3_i8_c8s(l2Mem0 + j*(CHUNK_SIZE), outL2Mem0+j*(NUM_COLS), (int)NUM_COLS, mask, (int)SHIFT);
            if (i != 0)
                 edmaWait4Completion(1);
            edmaWait4Completion(0);

        }
        else {
            edmaInitiateXfer( l2Mem0, in+((i+1)*(DMA_TX_SIZE)), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                              SRCBIDX, DSTBIDX, 1,
                              1, 0, 1);
            edmaInitiateXfer(out+((i-1)*(DMA_TX_SIZE)), outL2Mem0,(int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                             SRCBIDX, DSTBIDX, 1,
                             1, 1, 1);
            for (j = 0; j < NUM_RUNS; j++) IMG_conv_3x3_i8_c8s(l2Mem1 + j*(CHUNK_SIZE), outL2Mem1+j*(NUM_COLS), (int)NUM_COLS, mask, (int)SHIFT);
            edmaWait4Completion(0);
            edmaWait4Completion(1);
        }
    }
    edmaInitiateXfer(out+((NUM_DMA_TX-1)*(DMA_TX_SIZE)), outL2Mem1,(int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                  SRCBIDX, DSTBIDX, 1,
                  1, 1, 1);
    edmaWait4Completion(1);

    edmaClose();

    delta = Timestamp_get32() - timestamp;
    // printf("# of Clock Cycles: %d", *timestamp);
    printf("# of Clock Cycles: %d\n", delta);
    printf("Time: %fms\n", ((float)delta)/1000000);


    timestamp = Timestamp_get32();
    for (j = 0; j < NUM_RUNS; j++) IMG_conv_3x3_i8_c8s(l2Mem1 + j*(CHUNK_SIZE), outL2Mem1+j*(NUM_COLS), (int)NUM_COLS, mask, (int)SHIFT);
    delta = Timestamp_get32() - timestamp;
    printf("# of Clock Cycles: %d\n", delta);
    printf("Time: %fms\n", ((float)delta)/1000000);

    timestamp = Timestamp_get32();
    IMG_conv_3x3_i8_c8s(l2Mem1 + 0*(CHUNK_SIZE), outL2Mem1+ 0*(NUM_COLS), (int)NUM_COLS, mask, (int)SHIFT);
    delta = Timestamp_get32() - timestamp;
    printf("# of Clock Cycles: %d\n", delta);
    printf("Time: %fms\n", ((float)delta)/1000000);
        
    /* printf("Num DMA error = %d\n", error); */
    /* // img_write(out, 1024, 1024); */
    return 0;
    
}


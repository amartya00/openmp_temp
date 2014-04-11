#include <stdio.h>

#include <xdc/runtime/Timestamp.h>
#include "edma.h"

#define NUM_COLS 1920
#define NUM_ROWS 1080

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

#define IMG_SIZE (NUM_COLS) * (NUM_ROWS) * 2
#define NUM_DMA_TX (IMG_SIZE) / (DMA_TX_SIZE)

int test (void){

    unsigned int i =0;
    unsigned int j =0;
    
    // const unsigned char *in;
    const unsigned short *in;
    unsigned short *out;

    unsigned int delta = 0;
    unsigned int timestamp = 0;

    unsigned short *l2Mem0;
    unsigned short *l2Mem1;

    unsigned short *outL2Mem0;
    unsigned short *outL2Mem1;

    unsigned short *ddr3Mem0;
    unsigned short *ddr3Mem1;

    in  = (unsigned short *)(0x80000000);
    out = (unsigned short *)(0x82000000);


    l2Mem0 = (unsigned short *)(L2SRAM_ADDR_SEG_I0);
    l2Mem1 = (unsigned short *)(L2SRAM_ADDR_SEG_I1);

    outL2Mem0 = (unsigned short *)(L2SRAM_ADDR_SEG_O0);
    outL2Mem1 = (unsigned short *)(L2SRAM_ADDR_SEG_O1);

    ddr3Mem0 = (unsigned short *)(0x84000000);
    ddr3Mem1 = (unsigned short *)(0x85000000);

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

    edmaInitiateXfer( l2Mem0, in+0*(DMA_TX_SIZE)/2, (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
          SRCBIDX, DSTBIDX, 1,
          1, 0, 1);
    edmaWait4Completion(0);

    for (i = 0; i < NUM_DMA_TX; i++) {

        if ((i & (unsigned int)(0x01)) == 0){
            edmaInitiateXfer( l2Mem1, in+((i+1)*(DMA_TX_SIZE)/2), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                              SRCBIDX, DSTBIDX, 1,
                              1, 0, 1);
            if (i != 0)
                edmaInitiateXfer(out+((i-1)*(DMA_TX_SIZE)/2), outL2Mem1,(int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                  SRCBIDX, DSTBIDX, 1,
                  1, 1, 1);
            IMG_sobel_3x3_16 (l2Mem0, outL2Mem0, (short)(NUM_COLS), (short)((NUM_ROWS)/(NUM_DMA_TX)));
            if (i != 0)
                 edmaWait4Completion(1);
            edmaWait4Completion(0);

        }
        else {
            edmaInitiateXfer( l2Mem0, in+((i+1)*(DMA_TX_SIZE)/2), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                              SRCBIDX, DSTBIDX, 1,
                              1, 0, 1);
            edmaInitiateXfer(out+((i-1)*(DMA_TX_SIZE)/2), outL2Mem0,(int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                             SRCBIDX, DSTBIDX, 1,
                             1, 1, 1);
            IMG_sobel_3x3_16 (l2Mem1, outL2Mem1, (short)(NUM_COLS), (short)((NUM_ROWS)/(NUM_DMA_TX)));
            edmaWait4Completion(0);
            edmaWait4Completion(1);
        }
    }
    edmaInitiateXfer(out+((NUM_DMA_TX-1)*(DMA_TX_SIZE)/2), outL2Mem1,(int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                  SRCBIDX, DSTBIDX, 1,
                  1, 1, 1);
    edmaWait4Completion(1);
    edmaClose();

    delta = Timestamp_get32() - timestamp;
    printf("# of Clock Cycles: %d\n", delta);
    printf("L2 Ping pong time: %0.2fms\n", (float)delta/1000000);    
    printf("Transfer speed: %0.2fMB/s\n", (float)(IMG_SIZE)*1000/delta);

    timestamp = Timestamp_get32();
    IMG_sobel_3x3_16 (l2Mem0, outL2Mem0, (short)(NUM_COLS), (short)((NUM_ROWS)/(NUM_DMA_TX)));
    delta = Timestamp_get32() - timestamp;
    printf("# of Clock Cycles L2: %d\n", delta);
    printf("L2 time: %0.2fms\n", (float)delta/1000000);

    timestamp = Timestamp_get32();    
    // IMG_sobel_3x3_16 (in, ddr3Mem0, (short)(NUM_COLS), (short)((NUM_ROWS)/(NUM_DMA_TX)));
    IMG_sobel_3x3_16 (in, ddr3Mem1, (short)(NUM_COLS), (short)(NUM_ROWS));    
    delta = Timestamp_get32() - timestamp;
    printf("# of Clock Cycles DDR3: %d\n", delta);
    printf("DDR3 time: %0.2fms\n", (float)delta/1000000);
    
    return 0;
}


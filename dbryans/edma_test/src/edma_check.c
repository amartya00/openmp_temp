#include <stdio.h>

#include <xdc/runtime/Timestamp.h>
#include "edma.h"
#include <ti/sysbios/family/c66/Cache.h>

/* #define L2SRAM_ADDR_SEG0 0x00820000 */
/* #define L2SRAM_ADDR_SEG1 0x00840000 */

#define NUM_BYTES 1920*17
#define NUM_ARRAY 9
#define NUM_FRAMES 1
#define SRCBIDX NUM_BYTES
#define DSTBIDX NUM_BYTES

#define L2SRAM_OFFSET 0x31000
#define L2SRAM_CORE0 0x10800000 + L2SRAM_OFFSET
#define L2SRAM_CORE1 0x11800000 + L2SRAM_OFFSET
#define L2SRAM_CORE2 0x12800000 + L2SRAM_OFFSET
#define L2SRAM_CORE3 0x13800000 + L2SRAM_OFFSET
#define L2SRAM_CORE4 0x14800000 + L2SRAM_OFFSET
#define L2SRAM_CORE5 0x15800000 + L2SRAM_OFFSET
#define L2SRAM_CORE6 0x16800000 + L2SRAM_OFFSET
#define L2SRAM_CORE7 0x17800000 + L2SRAM_OFFSET




/* #define NUM_COLS 1024 */
/* #define NUM_ROWS 1024 */

int edma_check (unsigned tid){

    EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;
    printf("In edma_check\n");
    
    /* Cache_Size size; */

    //size.l2Size = Cache_L2Size_0K;
    // size.l1pSize = Cache_L1Size_0K;
    // size.l1dSize = Cache_L1Size_0K;
    
    // Cache_setSize(&size);
    /* unsigned int i =0; */
    /* unsigned int j =0; */
    
    const unsigned char *in;
    unsigned char *out;
    unsigned int delta = 0;
    unsigned int timestamp = 0;

    unsigned char *l2Mem0;
    unsigned char *l2Mem1;
    unsigned int out_addr[8] = {L2SRAM_CORE0, L2SRAM_CORE1,L2SRAM_CORE2,L2SRAM_CORE3,L2SRAM_CORE4,L2SRAM_CORE5,L2SRAM_CORE6,L2SRAM_CORE7};

    /* unsigned char *ddr3Mem0; */
    /* unsigned char *ddr3Mem1; */

    in  = (unsigned char *)(0x82000000);
    out = (unsigned char *)(out_addr[tid]);
    //out = (unsigned char *)(0x800000);

    /* unsigned short  theta = 280; */

    /* l2Mem0 = (unsigned char *)(L2SRAM_ADDR_SEG0); */
    /* l2Mem1 = (unsigned char *)(L2SRAM_ADDR_SEG1); */

    /* ddr3Mem0 = (unsigned char *)(0x84000000); */
    /* ddr3Mem1 = (unsigned char *)(0x85000000); */

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
    

    timestamp = Timestamp_get32();

    edmaResult = edmaInitiateXfer( out, in+tid*(NUM_ARRAY)*(NUM_BYTES), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
          SRCBIDX, DSTBIDX, 1,
          1, 1, 1);
    /*if (edmaResult == EDMA3_DRV_SOK)
        printf("\n DMA init TX successfull");
    else
        printf("\n DMA init TX Fail");*/
    /* edmaInitiateXfer( l2Mem1, in+1*(NUM_ARRAY)*(NUM_BYTES), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES), */
    /*       SRCBIDX, DSTBIDX, 1, */
    /*       1, 0, 1); */
    /* edmaWait4Completion(1); */
    edmaWait4Completion(1);

    

    delta = Timestamp_get32() - timestamp;
    // printf("# of Clock Cycles: %d", *timestamp);
    // printf("# of Clock Cycles: %d\n", *delta);
    printf("\n Time: %fms", (float)delta/1000000);
    return 0;
}


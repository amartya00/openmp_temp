#include <stdio.h>

#include <xdc/runtime/Timestamp.h>
#include "edma.h"
#include <ti/sysbios/family/c66/Cache.h>

#include <ti/omp/omp.h>
#define OUTPUT_ROWS 1080
#define OUTPUT_COLS 1920

#define WINDOW_ROWS 135
#define WINDOW_COLS 480

/* #define L2SRAM_ADDR_SEG0 0x00820000 */
/* #define L2SRAM_ADDR_SEG1 0x00840000 */

#define NUM_BYTES 2*(WINDOW_COLS)
#define NUM_ARRAY WINDOW_ROWS
#define NUM_FRAMES 1
#define SRCBIDX 2*(OUTPUT_COLS)
#define DSTBIDX NUM_BYTES

#define L2SRAM_OFFSET 0x00030978
// #define L2SRAM_OFFSET 0x0000000
#define L2SRAM_CORE0 0x10800000 + L2SRAM_OFFSET
#define L2SRAM_CORE1 0x11800000 + L2SRAM_OFFSET
#define L2SRAM_CORE2 0x12800000 + L2SRAM_OFFSET
#define L2SRAM_CORE3 0x13800000 + L2SRAM_OFFSET
#define L2SRAM_CORE4 0x14800000 + L2SRAM_OFFSET
#define L2SRAM_CORE5 0x15800000 + L2SRAM_OFFSET
#define L2SRAM_CORE6 0x16800000 + L2SRAM_OFFSET
#define L2SRAM_CORE7 0x17800000 + L2SRAM_OFFSET

#define DDR3_ADDR0 0x83400000
#define DDR3_ADDR1 0x84000000
#define DDR3_ADDR2 0x84400000
#define DDR3_ADDR3 0x85000000
#define DDR3_ADDR4 0x85400000
#define DDR3_ADDR5 0x86000000
#define DDR3_ADDR6 0x86400000
#define DDR3_ADDR7 0x87000000

#define BLOCK (unsigned short) 1


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
    
    unsigned short *in;
    unsigned short *out;
    unsigned int delta = 0;
    unsigned int timestamp = 0;

    unsigned char *l2Mem0;
    unsigned char *l2Mem1;
    unsigned int out_addr[8] = {L2SRAM_CORE0, L2SRAM_CORE1,L2SRAM_CORE2,L2SRAM_CORE3,L2SRAM_CORE4, L2SRAM_CORE5, L2SRAM_CORE6, L2SRAM_CORE7};
    // unsigned int out_addr[8] = {DDR3_ADDR0, DDR3_ADDR1, DDR3_ADDR2, DDR3_ADDR3, DDR3_ADDR4, DDR3_ADDR5, DDR3_ADDR6, DDR3_ADDR7};

    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int temp = 0;
    /* unsigned char *ddr3Mem0; */
    /* unsigned char *ddr3Mem1; */

    in  = (unsigned short *)(0x82000000);
    out = (unsigned short *)(out_addr[0]);

    
    for (i=0; i < OUTPUT_ROWS; i++){
        temp = 0;
        for(j = 0; j < OUTPUT_COLS; j++){
            temp = temp +1;
            in[i*OUTPUT_COLS + j] = temp;
        }
    }
    out = (unsigned short *)(out_addr[tid]);

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

    // edmaResult = edmaInitiateXfer( out, in+tid*(NUM_ARRAY)*(NUM_BYTES), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
    // #pragma omp parallel for shared(in) private(m,n,out)
    // for (m = 0; m < (OUTPUT_ROWS)/(WINDOW_ROWS); m++) {
    // out = (unsigned short *) out_addr[m];
    // for (n = 0; n < (OUTPUT_COLS)/(WINDOW_COLS); n++) {
    edmaResult = edmaInitiateXfer( out, in+tid*(OUTPUT_COLS)+(BLOCK)*(WINDOW_COLS), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES),
                                                   SRCBIDX, DSTBIDX, 1,
                                                   1, 1, 1);
            edmaWait4Completion(1);
            // }
        // }
    if (edmaResult == EDMA3_DRV_SOK)
        printf("\n DMA init TX successfull");
    else
        printf("\n DMA init TX Fail");
    /* edmaInitiateXfer( l2Mem1, in+1*(NUM_ARRAY)*(NUM_BYTES), (int)(NUM_BYTES), (int)(NUM_ARRAY), (int)(NUM_FRAMES), */
    /*       SRCBIDX, DSTBIDX, 1, */
    /*       1, 0, 1); */
    /* edmaWait4Completion(1); */


    

    delta = Timestamp_get32() - timestamp;
    // printf("# of Clock Cycles: %d", *timestamp);
    // printf("# of Clock Cycles: %d\n", *delta);
    printf("\n Time: %fms", (float)delta/1000000);
    return 0;
}


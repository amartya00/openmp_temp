
#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>

#include <stdio.h>


#include "edma.h"
#include "util.h"

#define NTHREADS  1

#define IMG_IN_ADDRESS  0x82000000
#define IMG_OUT_ADDRESS 0x86000000
#define FEATURE_ADDRESS 0x83000000

#define MSMC_ADDR   0x0c000000
#define EDMA_TEST_ADDR   0x88000000
#define L2SRAM_ADDR 0x008308f8


#define NUM_ROWS_MSMC (MSMC_SIZE)/((PIXEL_SIZE_IN)*(IMG_COLS))
#define NUM_ROWS_L2   (L2SRAM_SIZE)/((PIXEL_SIZE_OUT)*(OUTPUT_COLS))

#define NUM_BYTES  (unsigned short) 32640
#define NUM_ARRAY  (NUM_BYTES)/((NUM_ROWS_MSMC)*(PIXEL_SIZE_IN))
#define NUM_FRAMES 1
#define SRCBIDX    NUM_BYTES
#define DSTBIDX    NUM_BYTES

// #define NUM_BYTES 1920*17
// #define NUM_ARRAY 9
// #define NUM_FRAMES 1
// #define SRCBIDX NUM_BYTES
// #define DSTBIDX NUM_BYTES


#define NUM_MSMC_TX (IMG_ROWS)/(NUM_ROWS_MSMC)+1
#define NUM_L2_TX   (NUM_ROWS_MSMC)/(NUM_ROWS_L2)

int img_conv(unsigned short *imgIn, unsigned int *imgOut, unsigned short* featureIn,unsigned short imgRows, unsigned short imgCols, unsigned short featureSize);

#define CHUNK_SIZE (NUM_ROWS_MSMC-FEATURE_SIZE)/(NTHREADS)


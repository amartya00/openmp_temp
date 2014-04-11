#define IMG_ROWS (unsigned short) 1080
#define IMG_COLS (unsigned short) 1920

#define FEATURE_SIZE (unsigned short) 25

#define OUTPUT_ROWS IMG_ROWS - FEATURE_SIZE + 1
#define OUTPUT_COLS IMG_COLS - FEATURE_SIZE + 1

#define PIXEL_SIZE_IN  (unsigned short) 16
#define PIXEL_SIZE_OUT (unsigned short) 32

#define MSMC_SIZE (unsigned int) 0x00300000 //for omp
//#define MSMC_SIZE (unsigned int) 0x00400000
#define L2SRAM_SIZE (unsigned int) 0x0002f708

#include <ti/csl/csl_cacheAux.h>
#include <c6x.h>
#include <ti/omp/omp.h>

// #define NTHREADS (int) 8


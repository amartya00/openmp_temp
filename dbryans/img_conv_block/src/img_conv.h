#include "util.h"
// #include <ti/omp/omp.h>

// #define DDR3_BASE_ADDR 0x80000000

/* #define A_ADDRESS DDR3_BASE_ADDR */
/* #define B_ADDRESS A_ADDRESS + (SIZE) * 4 */
/* #define C_ADDRESS B_ADDRESS + (SIZE) * 4 */
#define IMG_IN_ADDRESS  0x82000000
#define IMG_OUT_ADDRESS 0x86000000
#define FEATURE_ADDRESS 0x83000000

#define IMG_IN_L2_SEG0_ADDRESS  0x00800000
#define IMG_IN_L2_SEG1_ADDRESS  0x00800000 + (NUM_BYTES)*(WINDOW_ROWS)

#define IMG_OUT_MSMC_SEG0_ADDRESS  0x0c000000
#define IMG_OUT_MSMC_SEG1_ADDRESS  0x0c000000 + 2*(NUM_BYTES)*(WINDOW_ROWS)


#define NTHREADS  8
#define CHUNK_SIZE (OUTPUT_ROWS)/(NTHREADS)

// unsigned int dotp(unsigned short *restrict a, short *restrict b);

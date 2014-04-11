#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>

//#include <ti/omp/omp.h>

#include <stdio.h>

#include <c6x.h>

#define X_ADDR (0x80000000)
#define Y_ADDR (0x81000000)
#define Z_ADDR (0x82000000)

#define X_ORIG_ADDR (0x83000000)
#define Y_ORIG_ADDR (0x84000000)
#define Z_ORIG_ADDR (0x85000000)

#define NEW_X_ADDR (0x86000000)
#define NEW_Y_ADDR (0x87000000)
#define NEW_Z_ADDR (0x88000000)

#define IMG_IN_ADDR (0x89000000)

#define KERNEL_SIZE 6 //(2^6 is the actual size)

#define NUM_ROWS (unsigned short)332
#define NUM_COLS (unsigned short)464
#define NUM_PIX  (NUM_ROWS)*(NUM_COLS)

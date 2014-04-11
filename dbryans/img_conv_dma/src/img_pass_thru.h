#include <string.h>
#include <assert.h>
#include <stdio.h>

#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

#include "util.h"

#include "edma.h"

#define L2SRAM_ADDR 0x00800000

#define NUM_ROWS_L2   (L2SRAM_SIZE)/(PIXEL_SIZE_OUT*IMG_COLS)

#define NUM_BYTES 65536/2 -1
#define NUM_ARRAY (NUM_BYTES)/(NUM_ROWS_L2*PIXEL_SIZE_OUT)
#define NUM_FRAMES 1
#define SRCBIDX NUM_BYTES
#define DSTBIDX NUM_BYTES

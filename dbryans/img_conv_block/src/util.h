#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>

#include<stdio.h>

#include <string.h>
#include <assert.h>
#include <stdio.h>

#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>
#include <c6x.h>

#define IMG_COLS (unsigned short)1920
#define IMG_ROWS (unsigned short)1080

#define FEATURE_SIZE (unsigned short) 25

#define OUTPUT_ROWS IMG_ROWS - FEATURE_SIZE + 1
#define OUTPUT_COLS IMG_COLS - FEATURE_SIZE + 1

#define WINDOW_ROWS 270
#define WINDOW_COLS 480


#define NUM_BYTES 2*(WINDOW_COLS)
#define NUM_ARRAY WINDOW_ROWS
#define NUM_FRAMES 1
#define SRCBIDX NUM_BYTES + 2*(WINDOW_COLS) //actually stride
#define DSTBIDX NUM_BYTES


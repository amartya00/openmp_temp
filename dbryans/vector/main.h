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

// #define DDR3_BASE_ADDR 0x80000000
#define SIZE (unsigned short) 25
#define A_ADDRESS 0x80000000
#define B_ADDRESS 0x81000000

int vector_stream_sp(void);



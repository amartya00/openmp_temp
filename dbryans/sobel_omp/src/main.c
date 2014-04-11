
#include <ti/omp/omp.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <xdc/runtime/Timestamp.h>

#define NUM_COLS 1920
#define NUM_ROWS 1080

#define NTHREADS  1
#define ROWS_PER_THREAD (NUM_ROWS)/(NTHREADS)

int main (void){

    const unsigned short *in;
    unsigned short *out;

    unsigned int delta = 0;
    unsigned int timestamp = 0;

    int nthreads = 0;
    int tid = 0;

    nthreads = NTHREADS;
    omp_set_num_threads(nthreads);

    in  = (unsigned short*)(0x80000000);
    out = (unsigned short*)(0x81000000);


    /* for (i = 0; i < NUM_ROWS; i++) { */
    /*     // if (i > 511) pix = 255; */
    /*     // else pix = 0; */
    /*     for (j = 0; j < NUM_COLS; j++){ */
    /*         in[i*NUM_COLS + j] = j & (unsigned int)(0xFF); */
    /*     } */
    /* } */
    
    
    timestamp = Timestamp_get32();

#pragma omp parallel shared(in, out)
    {
    tid = omp_get_thread_num();
    // Optimized image procesing kernel from TI C66x image libraries
    IMG_sobel_3x3_16 (in+tid*(ROWS_PER_THREAD)*(NUM_COLS), 
    out+tid*(ROWS_PER_THREAD)*(NUM_COLS), (unsigned short)(NUM_COLS), 
    (unsigned short) (ROWS_PER_THREAD));
    
    }

    delta = Timestamp_get32() - timestamp;
    
    //printf("# of Clock Cycles: %d", *timestamp);
    printf("# of Clock Cycles: %d\n", delta);
    printf("Time: %fms\n", ((float)delta)/1000000);
    // img_write(out, 1024, 1024);
    return 0;
    
}


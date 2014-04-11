
#include <ti/omp/omp.h>

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <xdc/runtime/Timestamp.h>

#define DDR3_BASE_ADDR 0x80000000
#define SIZE 0x1000000
/* #define A_ADDRESS DDR3_BASE_ADDR */
/* #define B_ADDRESS A_ADDRESS + (SIZE) * 4 */
/* #define C_ADDRESS B_ADDRESS + (SIZE) * 4 */

#define A_ADDRESS 0x80000000
#define B_ADDRESS 0x81000000
#define C_ADDRESS 0x82000000

#define NTHREADS  8
#define CHUNKSIZE (SIZE)/(NTHREADS)

void main (void)  
{
    
    int nthreads;
    nthreads = NTHREADS;
    omp_set_num_threads(nthreads);
    int i, chunk;
    unsigned int *a, *b, *c;

    a = (unsigned int *)A_ADDRESS;
    b = (unsigned int *)B_ADDRESS;

    c = (unsigned int *)C_ADDRESS;

    /* Some initializations */
    for (i=0; i < SIZE; i++){
        a[i] = i;
        b[i] = i;
    }
    chunk = CHUNKSIZE;

    unsigned int delta = 0;
    unsigned int timestamp = 0;
    
    timestamp = Timestamp_get32();
    

#pragma omp parallel shared(a,b,c,chunk) private(i)
    {

#pragma omp for schedule(dynamic,chunk) nowait
        for (i=0; i < SIZE; i++)
            c[i] = a[i] + b[i];

    }  /* end of parallel section */

    delta = Timestamp_get32() - timestamp;
    printf("\n a[%d] --> %d + b[%d] -- > %d = c[%d] = %d", (int) SIZE -1, a[SIZE-1], (int) SIZE-1 ,b[SIZE-1], (int) SIZE-1, c[SIZE-1]);
    printf("\n# of Clock Cycles: %d\n", delta);
    printf("\nexecution time: %0.2fms\n", (float)delta/1000000);
}
 

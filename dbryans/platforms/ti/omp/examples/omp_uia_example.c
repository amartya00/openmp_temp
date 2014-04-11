/******************************************************************************
* FILE: omp_uia_example.c
* DESCRIPTION:
*   OpenMP/UIA Example 
*   This example has been derived in part from the EPCC benchmarks:
*   http://www2.epcc.ed.ac.uk/computing/research_activities/openmpbench/
*       openmp_index.html
* AUTHOR: Shreyas Prasad  9/19/11
******************************************************************************/
#include <ti/omp/omp.h>

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

#include <xdc/std.h>
#include <xdc/runtime/Log.h>
#include <ti/ipc/MultiProc.h>

#include <ti/uia/events/UIABenchmark.h>

#define NUMLOOPS 1000
#define DELAYLENGTH 1000

void delay(int delaylength)
{

    int  i; 
    volatile float a=0.; 

    for (i=0; i<delaylength; i++) a+=i; 

} 

void main()
{
    int numProcs, i, n;
    numProcs = MultiProc_getNumProcessors();


    /* GENERATE REFERENCE TIME */ 
    Log_write2(UIABenchmark_start, (xdc_IArg)"Reference time start", NULL);
    for (i = 0; i < NUMLOOPS; i++) {
        delay(DELAYLENGTH);
    }
    Log_write2(UIABenchmark_stop, (xdc_IArg)"Reference time stop", NULL);
    
    for (n = 1; n <= numProcs; n++) {
        omp_set_num_threads(n);
        Log_write2(UIABenchmark_start, (xdc_IArg)"OMP PARALLEL FOR start, using %d cores", i);
        /* Fork a team of threads giving them their own copies of variables */
        #pragma omp parallel for
        for (i = 0; i < NUMLOOPS; i++) {
            delay(DELAYLENGTH);
        }
        Log_write2(UIABenchmark_stop, (xdc_IArg)"OMP PARALLEL FOR stop, using %d cores", i);
    }

}


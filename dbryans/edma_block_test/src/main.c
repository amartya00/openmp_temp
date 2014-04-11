
/*  ======== main.c ========
*/

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>

#include <stdio.h>

#include <ti/omp/omp.h>

#include "edma.h"

#define NTHREADS  8

int edma_check (unsigned tid);

/*
 *  ======== taskFxn ========
 */
/* Void taskFxn(UArg a0, UArg a1) */
/* { */
/*     printf("enter taskFxn()\n"); */

/*     // Task_sleep(10); */
/*     edma_check(); */

/*     printf("exit taskFxn()\n"); */
/* } */

/*
 *  ======== main ========
 */
Void main()
{ 
    /* Task_Handle task; */
    /* Error_Block eb; */

    printf("enter main()\n");

    int nthreads = 0;
    unsigned int tid = 0;
    EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;

    nthreads = NTHREADS;
    omp_set_num_threads(nthreads);

    edmaResult = edmaInit();
    if(edmaResult != EDMA3_DRV_SOK)
    {
        System_printf("Failed to allocate DMA resources\n");
        System_abort("\n");
     }
    else
        printf("EDMA init successful");

    /* Error_init(&eb); */
    /* task = Task_create(taskFxn, NULL, &eb); */
    /* if (task == NULL) { */
    /*     printf("Task_create() failed!\n"); */
    /*     BIOS_exit(0); */
    /* } */

    /* BIOS_start();     /\* enable interrupts and start SYS/BIOS *\/ */

#pragma omp parallel private(nthreads, tid)
    {
        tid = omp_get_thread_num();
        printf("Hello World from thread = %d\n", tid);
        edma_check(tid);
    }

    edmaClose();
}

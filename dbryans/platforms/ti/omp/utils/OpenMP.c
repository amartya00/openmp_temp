/*
 * Copyright (c) 2012, Texas Instruments Incorporated
 * http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*
 *  ======== OpenMP.c ========
 */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/timers/timer64/Timer.h>

#include <ti/ipc/MultiProc.h>
#include <ti/ipc/ListMP.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/SharedRegion.h>
#include <ti/ipc/GateMP.h>
#include <ti/ipc/Ipc.h>

#include <ti/omp/libgomp.h>
#include <ti/omp/utils/SemaphoreMP.h>

#include <ti/omp/config/sysbios/proc.h>

#include "package/internal/OpenMP.xdc.h"
#include <ti/omp/navigator/Navigator.h>
#include <stdlib.h>



// Defined in the C6000 RTS
extern void __TI_cpp_init(void);

typedef struct {
    MessageQ_MsgHeader header;
    Bool isPending;  /* Used to ack the thread spawn request */
    Ptr startData;
    Fxn fn;
    SizeT stackSize;
    Bool terminate;
} OpenMP_SpawnElem;

/* Must go into non-cached shared memory */
static volatile UInt16 OpenMP_threadsPerCore[MAXPROCS];
static volatile OpenMP_SpawnElem OpenMP_threadSpawnElems[MAXPROCS];
static volatile UInt32 OpenMP_threadSpawnQIds[MAXPROCS];

#pragma DATA_SECTION(OpenMP_threadsPerCore, "gomp_data")
#pragma DATA_SECTION(OpenMP_threadSpawnElems, "gomp_data")
#pragma DATA_SECTION(OpenMP_threadSpawnQIds, "gomp_data")

/*!
 *  ======== OpenMP_masterTask ========
 */
Void OpenMP_masterTask(UArg arg0, UArg arg1)
{
    SemaphoreMP_Params semParams;
	UInt16 baseId = MultiProc_getBaseIdOfCluster();
    Int status;
    SharedRegion_Entry srEntry;
    Task_Params taskParams;
	Int i;


    SharedRegion_getEntry(1, &srEntry);
    srEntry.isValid = TRUE;
    SharedRegion_setEntry(1, &srEntry);
    
    //status = Ipc_start();
    /* Call Ipc_start() */
    status = Ipc_start();
    if (status < 0) {
      System_abort("Ipc_start failed!\n");
	}
        
    /* get region 0 information */
    SharedRegion_getEntry(0, &srEntry);

    /* if srEntry is not valid then return */
    if (srEntry.isValid == FALSE) {
      return;
    }
    
    /* Must attach to owner first to get default GateMP */
    if (MultiProc_self() != srEntry.ownerProcId) {
      do {
        status = Ipc_attach(srEntry.ownerProcId);
      } while (status == Ipc_E_NOTREADY);
            
       if (status < 0) {
        System_abort("ERROR: Ipc_start failed in OpenMP_masterTask\n");
       }
    }

    
    /* Must attach to owner first to get default GateMP */
        for (i = 0; i < MultiProc_getNumProcsInCluster(); i++, baseId++) {
            
			if ((baseId == MultiProc_self()) || (baseId == srEntry.ownerProcId)) {
                continue;
            }
        
            /* Skip the processor if there are no interrupt lines to it */
            if (Notify_numIntLines(baseId) == 0) {
                continue;
            }

            /* call Ipc_attach for every remote processor */
            do {
                status = Ipc_attach(baseId);
            } while (status == Ipc_E_NOTREADY);
            
            
           if (status < 0) {
             System_abort("ERROR: Ipc_start failed in OpenMP_masterTask\n");
           }
       }
    
   
    OpenMP_module->useSharedHeap = true;
    
    /* Store the handle to the default remote gate */
    OpenMP_module->gate = (ti_sdo_ipc_GateMP_Handle)GateMP_getDefaultRemote();
    
    /* Ensure that Ipc_start succeeded */
    if (status < 0) {
        System_abort("ERROR: Ipc_start failed in OpenMP_masterTask\n");
    }

    /* Initialize the SemaphoreMP module */
    SemaphoreMP_start();
    init_Navigator();
    OpenMP_module->threadSpawnQ = Create_Queue();
    OpenMP_threadSpawnQIds[MultiProc_self()-MultiProc_getBaseIdOfCluster()] = OpenMP_module->threadSpawnQ;
    
    if (MultiProc_self() == MultiProc_getBaseIdOfCluster()) {
        /* Keep track of the number of OMP threads the local core is running */
        OpenMP_threadsPerCore[0]++;
        
        /* Call compiler-lowered 'main' function */
        Task_Params_init(&taskParams);
        taskParams.priority = OpenMP_threadPriority;
        if (OpenMP_stackRegionId != -1) {
            taskParams.stackHeap = SharedRegion_getHeap(OpenMP_stackRegionId);
        }
        taskParams.stackSize = OpenMP_stackSize;
        taskParams.env       = (xdc_Ptr)-1; /* Indicate TLS required for task */
        Task_create(OpenMP_mainTask, &taskParams, NULL);
    }
	 OpenMP_threadSpawnLoop();

}

/*!
 *  ======== OpenMP_mainTask ========
 */
Void OpenMP_mainTask(UArg arg0, UArg arg1) 
{
    UInt i;
    
    initialize_critical();
    initialize_env();
    
    if (getenv("OMP_STACKSIZE") == NULL) {
        gomp_thread_attr_setstacksize (&gomp_thread_attr, OpenMP_stackSize);
    }
    
    initialize_team();

    /* Execute the user-supplied 'main' function */
    
    OpenMP_masterFxn();


	 /* 
     *  main() has returned.
     *  Tell the remote OpenMP_masterTask threads to terminate
     */
}


Void OpenMP_mainTaskExit(void *arg __attribute__((unused)))
{
	
	int i;
    for (i = 1; i < MultiProc_getNumProcsInCluster(); i++) {
        
        /* All the other fields of the thread spawn message don't matter */
        while (OpenMP_threadSpawnElems[i].isPending == true)
		{
			Task_yield();
		}
		OpenMP_threadSpawnElems[i].terminate = true;
		OpenMP_threadSpawnElems[i].isPending = true;
        queue_push_elem(OpenMP_threadSpawnQIds[i], (MessageQ_MsgHeader *)&(OpenMP_threadSpawnElems[i].header));
		while(!Queue_empty(OpenMP_threadSpawnQIds[i]));
       
    }
	team_destructor();
    BIOS_exit(0);
}
/*!
 *  ======== OpenMP_threadSpawnTask ========
 */
//Void OpenMP_threadSpawnTask(UArg arg0, UArg arg1)
Void OpenMP_threadSpawnLoop(Void)
{
    Task_Params params;
	Int status; 
    OpenMP_SpawnElem *elem;
    
    Task_Params_init(&params);

	if (OpenMP_stackRegionId != -1) {
        /* Thread stack should be placed in shared region */
        params.stackHeap = SharedRegion_getHeap(OpenMP_stackRegionId);
    }
    
    while (1) {
        /* Get a thread spawn request */

    	elem =  (Ptr ) queue_pop_elem_wait( OpenMP_module->threadSpawnQ);
		ti_sysbios_knl_Task_deleteTerminatedTasksFunc();

		//if(tsk != NULL)
		//	Task_delete(&tsk);
		if (elem->terminate) {
            /* main() complete, nothing else to do */
            BIOS_exit(0);
        }


        /* Initialize Task params. Set env  to -1  for TLS required */
        params.arg0 = (UArg)elem->startData;
        params.stackSize = elem->stackSize;
        params.env = -1;
        params.priority = OpenMP_threadPriority;
        
        /* Spawn a new thread locally */
        Task_create((Task_FuncPtr)elem->fn, &params, NULL);
        
        /* Free the elem */
        elem->isPending = FALSE;
    }
}

/*!
 *  ======== OpenMP_createThread ========
 */
Void OpenMP_createThread(Fxn fn, Ptr startData, SizeT stackSize) 
{
    UInt min = (UInt)-1;
    UInt16 minProcId;
    Int status, i;
    UInt key;
    
    /* Need to protect accesses to OpenMP_threadsPerCore by other threads */
    key = GateMP_enter((GateMP_Handle)OpenMP_module->gate);
    /* Determine the proc ID for the core with fewest # of worker threads */
    for (i = 0; i < MultiProc_getNumProcsInCluster(); i++) {
        if (OpenMP_threadsPerCore[i] < min) {
            min = OpenMP_threadsPerCore[i];
            minProcId = i;
        }
    }
    OpenMP_threadsPerCore[minProcId]++;
    
    /* Spin waiting for the previous message to be used up */
    while (OpenMP_threadSpawnElems[minProcId].isPending == true) {
        GateMP_leave((GateMP_Handle)OpenMP_module->gate, key);
        /* Yield to allow OpenMP_threadSpawnTask to run if ready */
        Task_yield();
        key = GateMP_enter((GateMP_Handle)OpenMP_module->gate);
    };
    
 //   MessageQ_staticMsgInit((MessageQ_MsgHeader *)&(OpenMP_threadSpawnElems[minProcId].header), sizeof(OpenMP_SpawnElem));
    OpenMP_threadSpawnElems[minProcId].startData = startData;
    OpenMP_threadSpawnElems[minProcId].fn = fn;
    OpenMP_threadSpawnElems[minProcId].stackSize = stackSize;
    OpenMP_threadSpawnElems[minProcId].isPending = true;
	OpenMP_threadSpawnElems[minProcId].terminate = false;
    
    /* 
     *  Safe to leave the gate here since any other thread trying to use the
     *  same control message will spin on the 'isPending' flag
     */
    GateMP_leave((GateMP_Handle)OpenMP_module->gate, key);

    queue_push_elem(OpenMP_threadSpawnQIds[minProcId], (MessageQ_MsgHeader *)&(OpenMP_threadSpawnElems[minProcId].header));

}

/*!
 *  ======== OpenMP_setProcId ========
 */
Void OpenMP_setProcId()
{
    extern cregister volatile UInt DNUM;
    
    if (DNUM >= (MultiProc_getBaseIdOfCluster() + MultiProc_getNumProcsInCluster()) || DNUM < MultiProc_getBaseIdOfCluster() ) { 
        BIOS_exit(0); /* This core is not used */
    }

    /* Set the local ID to DNUM + BaseIdOfCluster */
    MultiProc_setLocalId(DNUM);
}
Uint32 Threads_in_release(Uint32 Hnd)
{

	return Queue_get_num_elem(Hnd) ;
}
/*!
 *  ======== OpenMP_exitThread ========
 */
Void OpenMP_exitThread(void *arg __attribute__((unused)))
{
	extern cregister volatile UInt DNUM; 
	int id=MultiProc_self() - MultiProc_getBaseIdOfCluster();
	/* Need to protect accesses to OpenMP_threadsPerCore by other threads */
    UInt key = GateMP_enter((GateMP_Handle)OpenMP_module->gate);
    OpenMP_threadsPerCore[id]--;
    GateMP_leave((GateMP_Handle)OpenMP_module->gate, key);
}

/*!
 *  ======== OpenMP_useSharedHeap ========
 */
Bool OpenMP_useSharedHeap()
{
    return OpenMP_module->useSharedHeap;
}
/*!
 *  ======== OpenMP_getTimerCount ========
 */
UInt32 OpenMP_getTimerCount()
{
    return (Timer_getCount(OpenMP_module->sharedTimer));
}

/*!
 *  ======== OpenMP_getTimerFreq ========
 */
Void OpenMP_getTimerFreq(Types_FreqHz *freq)
{
    Timer_getFreq(OpenMP_module->sharedTimer, freq);
}


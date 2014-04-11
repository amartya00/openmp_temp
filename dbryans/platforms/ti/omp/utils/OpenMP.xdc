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
 *  ======== OpenMP.xdc ========
 */

import ti.sdo.ipc.MessageQ;
import ti.omp.utils.SemaphoreMP;
import ti.omp.navigator.Navigator;
import ti.sdo.ipc.GateMP;
import ti.sysbios.timers.timer64.Timer;
import ti.sysbios.knl.Task;

import xdc.runtime.Diags;
import xdc.runtime.Log;
import xdc.runtime.Assert;
import xdc.runtime.Types;


/*! 
 *  ======== OpenMP ========
 *  Main OpenMP module
 * 
 *  This module must be used (via xdc.useModule) by all SYS/BIOS OpenMP 
 *  applications. System-wide initialization is performed before the 
 *  user-supplied main() function is executed as a SYS/BIOS Task. 
 *
 */
module OpenMP
{
    /*! Idle function type definition. */
    typedef Void (*FuncPtr)();

    /*!
     *  ======== masterFxn ========
     *  The main() function in the user's application
     */
    config FuncPtr masterFxn = "&main";
    
    /*!
     *  @_nodoc
     *  This is deprecated!
     *
     *  Specifies the default number of threads to use in parallel regions. If 
     *  undefined one thread per CPU online is used. 
     */
    config bool singleThreadPerCore = true;

	/*!
     *
     *  Set to false if the QMSS will be initialized by application.
	 *  By default the QMSS will be initialized by OpenMP run-time  if this parameter is not set to false.
	 *  Please note OpenMP run-time requires QMSS to be initialized before main during reset function.
     */
    config bool qmssInit = true;

	/*!
     *
     *  Set the QMSS Mem-Region to be used by OpenMP. 
	 *  By default it is set to -1 ( Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED )
     */
    config Int32 qmssMemRegion = -1;


	/*!
     *
     *  Set the QMSS Start Index to be used by OpenMP. 
	 *  By default it is set to 0 
     */
    config UInt32 qmssStartIndex = 0;

	/*!
     *
     *  Set the QMSS Destination Queue Number to be used by OpenMP. 
	 *  By default it is set to -1 ( QMSS_PARAM_NOT_SPECIFIED )
     */
    config Int32 qmssDestQueueNum = -1;
	
	
    /*!
     *  Set the default thread stack size in MAUs. This is different from 
     *  pthread_attr_setstacksize which gets the number of bytes as an argument.
     */
    config SizeT stackSize = 8192;
    
    /*!
     *  Size of the SharedRegion 0 heap
     */
    config SizeT ipcHeapSize = 0x80000;

	/*!
     *  SharedRegion heap from which thread stacks will be allocated
     *
     *  If value is set to -1, then the local heap will be used to allocate
     *  thread stacks.
     */
    config Int stackRegionId = 0;

   /*!
     *  Internal OpenMP Osal will be used if set to true.
     *
     *  If value is set to false, then the application need to provide OSAL layer.
     */
    config bool internalOsal = true;

	/*!
     *  CPPI HW Semaphore
     *
     */
    config UInt cppiHwSem = 3;

	/*!
     *  QMSS HW Semaphore
     *
     */
    config UInt qmssHwSem = 4;

	/*!
     *  QMSS HW Semaphore
     *
     */
    config UInt ompHwSem = 5;

	/*!
     *  MPAX Segment Index. Default segment index is 3
     *
     */
    config UInt mpaxIndex = 3;

	/*!
     *  MPAX Physical Address. Default is 0x0C000000
     *
     */

	config  UInt32 mpaxRaddr = 0x0C000000;


	config bool autoDnldCore = true ;
	
    
    
    /*!
     *  OpenMP thread priority
     *
     *  All OpenMP thread Tasks (including the thread configured with 
     *  {@link #masterFxn} will use this Task priority.
     */
    config Int threadPriority = 1;
	
    
    /*!
     *  Non-cached MSMC Alias.
     *
     *  See ti/omp/config/sysbios/preinit.c for more information about this.
     */
    config UInt32 noncachedMsmcAlias = 0xa0000000;

	 /*!
     *  Base ID of clusters
     *
     *  
     */
    config UInt baseIdOfCluster = 0;


    /*!
     *  Enables/disables memory consistency calls at implicit and explicit
     *  flush points in the OpenMP runtime
     */
    config bool enableMemoryConsistency = true;

    
    /*! Set number of processors for IPC to use */
    metaonly Void setNumProcessors(UInt16 numProcessors);
    
    /*!
     *  Use maximum # of processors available on the device
     */
    metaonly Void setMaxProcessors();
    
    /*!
     *  @_nodoc
     *  Used by gomp_thread APIs to spawn remote threads
     */
    @DirectCall 
    Void createThread(Fxn fn, Ptr startData, SizeT stackSize);
   
   /*!
     *  @_nodoc
     *  Used for house-keeping when local thread exits.
     */
	Void exitThread(void *arg);

	/*!
     *  @_nodoc
     *  Used for terminating the main task
     */
	Void mainTaskExit(void *arg);

    /*!
     *  @_nodoc
     *  Used by HeapOMP to switch to using Shared Region heap for allocation
     */
    Bool useSharedHeap();
    @DirectCall 
    UInt32 getTimerCount();
    
    /*!
     *  @_nodoc
     *  Used by ti/omp/config/sysbios/time.h to get shared timer frequency 
     */
    @DirectCall 
    Void getTimerFreq(Types.FreqHz *freq);
    
internal:

    /*!
     *  Initializes infrastructure needed to spawn OpenMP threads  
     *
     *  This task does the following: 
     *  - Calls Ipc_start
     *  - Creates the local thread spawn queue
     *  - Calls threadSpawnLoop that waits for thread spawn requests
     */
    Void masterTask(UArg arg0, UArg arg1);

    /*!
     *  Routine that blocks waiting for thread spawn requests to arrive
     *
     *  This task blocks on a MessageQ belonging to the local core waiting for
     *  incoming thread spawn requests.  When it receives a message (via 
     *  MessageQ_get), it either creates the thread using parameters contained
     *  within the message or it terminates the local core.
     */
    Void threadSpawnLoop();
    
    /*!
     *  Calls libgomp initialization routines and calls user 'main' function
     *
     *  The 'mainTask' performs global initialization that must be only
     *  performed by a single core (i.e. CORE0).  It first calls libgomp 
     *  initialization routines.  It then calls the user-supplied main() 
     *  function (configurable via OpenMP.masterFxn).  Once main() returns, 
     *  this task helps terminate the application on each core by sending
     *  termination messages to each remote core.
     *
     *  The stack for this task is allocated from the heap identified by 
     *  OpenMP.stackRegionid.
     */
    Void mainTask(UArg arg0, UArg arg1);
    
    /*!
     *  Sets the local MultiProc ID based on the DNUM value
     */
    Void setProcId();

	
    
    struct Module_State {
        SemaphoreMP.Handle  masterTaskSem;
	    UInt32              threadSpawnQ;
        Bool                useSharedHeap;
		GateMP.Handle       gate;
        Timer.Handle        sharedTimer;
    };
}

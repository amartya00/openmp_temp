/*
 * Navigator.c
 *
 *  Created on: july 25, 2011
 *      Author: Darmoul Wajdi
 *
 */

#include <xdc/std.h>
#include <stdbool.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <ti/ipc/MultiProc.h>
#include <ti/sysbios/family/c66/Cache.h>
#include <ti/sysbios/knl/Task.h>
/* QMSS LLD include */
#include <ti/drv/qmss/qmss_drv.h>
//#include <ti/drv/qmss/qmss_firmware.h>

/* CPPI LLD include */
#include <ti/drv/cppi/cppi_drv.h>
#include <ti/drv/cppi/cppi_desc.h>
#include <c6x.h>
/* CSL RL includes */
#include <ti/csl/csl_chip.h>
#include <ti/csl/src/intc/csl_intc.h>
#include <ti/csl/src/intc/csl_intcAux.h>
#include <ti/csl/csl_cacheAux.h>
#include <ti/csl/csl_qm_queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <ti/csl/csl_xmcAux.h>
#include <ti/omp/utils/OpenMP.h>
#include "Navigator_h.h"
#include "package/internal/Navigator.xdc.h"

/************************ USER DEFINES ********************/
#define INTERNAL_LINKING_RAM
//#define L2_CACHE
//#define MAPPED_VIRTUAL_ADDRESS      0x81000000

//#define NUMBER_OF_CORES             8
//#define SYSINIT                     0

//#define QMSS_FREE_QUE_NUM			899
#define NUM_FREE_DESC         		8192
#define NUM_EVENT_DESC				256
#define SIZE_EVENT_DESC				32

/* MPAX segment 2 registers */
//#define XMPAXL2                     0x08000010
//#define XMPAXH2                     0x08000014

/************************ GLOBAL VARIABLES ********************/
#pragma DATA_SECTION ( linkingRAM0,".qmss");
#pragma DATA_ALIGN (linkingRAM0, 16)
UInt64              linkingRAM0[NUM_FREE_DESC];
/* Descriptor pool [Size of descriptor * Number of descriptors] */
#pragma DATA_SECTION ( eventDesc,".qmss");
#pragma DATA_ALIGN (eventDesc, 16)
UInt8                   eventDesc[SIZE_EVENT_DESC * NUM_EVENT_DESC];
/* CPDMA configuration */
#pragma DATA_SECTION ( cpdmaCfg,".qmss");
Cppi_CpDmaInitCfg       cpdmaCfg;
/* QMSS configuration */
#pragma DATA_SECTION ( qmssInitConfig,".qmss");
Qmss_InitCfg            qmssInitConfig;
/* Memory region configuration information */
#pragma DATA_SECTION ( memInfo,".qmss");
Qmss_MemRegInfo         memInfo;
#pragma DATA_SECTION ( eventDescCfg,".Nav_init");
Qmss_DescCfg 			eventDescCfg;

/* Descriptor configuration */
#pragma DATA_SECTION ( descCfg,".qmss");
Cppi_DescCfg        descCfg;

#pragma DATA_SECTION ( cppiHnd,".qmss");
Cppi_Handle             cppiHnd;
#pragma DATA_SECTION ( completionQueHnd,".qmss");
volatile Uint32           completionQueHnd;
#pragma DATA_SECTION ( eventQueHnd,".qmss");
volatile Uint32			eventQueHnd;
#pragma DATA_SECTION ( EventFreeDescHnd,".qmss");
volatile Uint32 			EventFreeDescHnd;
#pragma DATA_SECTION ( releaseHnd,".qmss");
volatile Uint32 			releaseHnd;
#pragma DATA_SECTION (isQMSSInitialized, ".qmss");
volatile UInt32             isQMSSInitialized;
#pragma DATA_SECTION (release, ".qmss");
volatile UInt32             release;

#pragma DATA_SECTION (runCount, ".qmss");
volatile Uint32                      runCount;

/************************ EXTERN VARIABLES ********************/

/* QMSS device specific configuration */
extern Qmss_GlobalConfigParams  omp_qmssGblCfgParams;
/* CPPI device specific configuration */
extern Cppi_GlobalConfigParams  omp_cppiGblCfgParams;

/**
 *  @b Description
 *  @n
 *      Utility function which converts a local GEM L2 memory address
 *      to global memory address.
 *
 *  @param[in]  addr
 *      Local address to be converted
 *
 *  @retval
 *      Computed L2 global Address
 */
static UInt32 l2_global_address (UInt32 addr)
{
	UInt32 coreNum;

	/* Get the core number. */
	coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);

	/* Compute the global address. */
	return (addr + (0x10000000 + (coreNum * 0x1000000)));
}


static Int32 sysInit (Void)
{
    Qmss_Result             result;
    UInt32                  numAllocated;
    UInt8                   isAllocated;
    UInt32                  coreNum;
#ifdef L2_CACHE
    uint32_t                *xmpaxPtr;
#endif

   // System_printf ("\n-----------------------Initializing---------------------------\n");
    coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);

    /* Reset the variable to indicate to other cores system init is not yet done */
    isQMSSInitialized = 0;
    release = 0;
    /* Initilaize the number of times the test was run to zero */
    runCount = 0;
	/* If QMSS is not initialized by system */
	if(OpenMP_qmssInit == true)
	{

#ifdef L2_CACHE
    /* Set L2 cache to 512KB */
    CACHE_setL2Size (CACHE_64KCACHE);
#endif

    memset ((Void *) &qmssInitConfig, 0, sizeof (Qmss_InitCfg));
    memset ((Void *) &linkingRAM0, 0, sizeof (linkingRAM0));
    /* Set up the linking RAM. Use the internal Linking RAM.
     * LLD will configure the internal linking RAM address and maximum internal linking RAM size if
     * a value of zero is specified.
     * Linking RAM1 is not used */

#ifdef INTERNAL_LINKING_RAM
    qmssInitConfig.linkingRAM0Base = 0;
    qmssInitConfig.linkingRAM0Size = 0;
    qmssInitConfig.linkingRAM1Base = 0;
    qmssInitConfig.maxDescNum      = NUM_FREE_DESC;
#else
    //qmssInitConfig.linkingRAM0Base = (UInt32) l2_global_address((Uint32)&linkingRAM0[0]);
    qmssInitConfig.linkingRAM0Base = (Uint32)&linkingRAM0[0];
    qmssInitConfig.linkingRAM0Size = 0x3FFF;
    qmssInitConfig.linkingRAM1Base = 0;
    qmssInitConfig.maxDescNum      = NUM_FREE_DESC;
#endif

#ifdef xdc_target__bigEndian
    qmssInitConfig.pdspFirmware[0].pdspId = Qmss_PdspId_PDSP1;
    qmssInitConfig.pdspFirmware[0].firmware = (void *) &acc48_be;
    qmssInitConfig.pdspFirmware[0].size = sizeof (acc48_be);
#else
   // qmssInitConfig.pdspFirmware[0].pdspId = Qmss_PdspId_PDSP1;
   // qmssInitConfig.pdspFirmware[0].firmware = (void *) &acc48_le;
   // qmssInitConfig.pdspFirmware[0].size = sizeof (acc48_le);
#endif

    /* Initialize Queue Manager SubSystem */
    result = Qmss_init (&qmssInitConfig, &omp_qmssGblCfgParams);
    if (result != QMSS_SOK)
    {
        System_printf ("Error Core %d : Initializing Queue Manager SubSystem error code : %d\n", coreNum, result);
        return -1;
    }

    /* Start Queue Manager SubSystem */
    result = Qmss_start ();
    if (result != QMSS_SOK)
    {
        System_printf ("Core %d : Error starting Queue Manager error code : %d\n", coreNum, result);
    }
	}
    /* Set up QMSS CPDMA configuration */
    memset ((Void *) &cpdmaCfg, 0, sizeof (Cppi_CpDmaInitCfg));
    cpdmaCfg.dmaNum = Cppi_CpDma_QMSS_CPDMA;

    /* Open QMSS CPDMA */
    cppiHnd = (Cppi_Handle) Cppi_open (&cpdmaCfg);
    if (cppiHnd == NULL)
    {
        System_printf ("Error Core %d : Initializing QMSS CPPI CPDMA %d\n", coreNum, cpdmaCfg.dmaNum);
        return -1;
    }

    /* Setup memory region for event descriptors */
    memset ((Void *) &eventDesc, 0, SIZE_EVENT_DESC * NUM_EVENT_DESC);
    memInfo.descBase = (UInt32 *) l2_global_address ((UInt32) eventDesc);
    memInfo.descSize = SIZE_EVENT_DESC;
    memInfo.descNum = NUM_EVENT_DESC;
    memInfo.manageDescFlag = Qmss_ManageDesc_MANAGE_DESCRIPTOR;
    memInfo.memRegion = OpenMP_qmssMemRegion; //Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED;
    memInfo.startIndex = OpenMP_qmssStartIndex;

    result = Qmss_insertMemoryRegion (&memInfo);
    if (result < QMSS_SOK)
    {
        System_printf ("Error Core %d : Inserting memory region %d error code : %d\n", coreNum, memInfo.memRegion, result);
    }

       /* Setup the descriptors for receive free queue */
    descCfg.memRegion = result;
    descCfg.descNum = NUM_EVENT_DESC;
    descCfg.destQueueNum = OpenMP_qmssDestQueueNum;//QMSS_PARAM_NOT_SPECIFIED;// QMSS_FREE_QUE_NUM;
    descCfg.queueType = Qmss_QueueType_GENERAL_PURPOSE_QUEUE;
    descCfg.initDesc = Cppi_InitDesc_BYPASS_INIT;
    descCfg.descType = Cppi_DescType_MONOLITHIC;
    descCfg.epibPresent = Cppi_EPIB_EPIB_PRESENT;
	descCfg.cfg.mono.dataOffset = 0;

       /* Initialize the descriptors and push to monolithic free Queue */
       if ((EventFreeDescHnd  = Cppi_initDescriptor (&descCfg, &numAllocated)) < 0)
   	{
           System_printf ("Error Core %d : Initializing monolithic descriptor error code: %d \n", coreNum, EventFreeDescHnd );
   		return -1;
   	}
       result = Qmss_getQueueEntryCount (EventFreeDescHnd);
       eventQueHnd = Create_Queue();
       completionQueHnd =  Create_Queue();
       releaseHnd = Create_Queue();
    /* Indicate to other cores system init is done */
    isQMSSInitialized = 1;

#ifdef L2_CACHE
    /* Writeback L2 */
    CACHE_wbL2 ((void *) &isQMSSInitialized, 4, CACHE_WAIT);
#else
    /* Writeback L1D */
    CACHE_wbL1d ((void *) &isQMSSInitialized, 4, CACHE_WAIT);
#endif
   // printQueueStats ("After Initialization");
    return 0;
}
/**
 *  @b Description
 *  @n
 *      Function initializes the common queue handles opened by producer core on consumer cores
 *
 *  @retval
 *      Not Applicable
 */
static Void getsysHandles (Void)
{
    UInt8           isAllocated;
    volatile Qmss_Result     result;
    UInt32       coreNum;
    Cppi_Desc           *desc;
    /* Start Queue Manager SubSystem */
    coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);

    do{
#ifdef L2_CACHE
        /* Invalidate L2 */
        CACHE_invL2 ((void *) &isQMSSInitialized, 4, CACHE_WAIT);
#else
        CACHE_invL1d ((void *) &isQMSSInitialized, 4, CACHE_WAIT);
#endif
    } while (isQMSSInitialized == 0);


    result = Qmss_start ();
    if (result != QMSS_SOK)
    {
        System_printf ("Core %d : Error starting Queue Manager error code : %d\n", coreNum, result);
		return;
    }
    if ((eventQueHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE,eventQueHnd, &isAllocated)) < 0)
        {
            System_printf ("Error Core %d : Opening event Queue Number\n", coreNum);
    		return;
        }

    if ((releaseHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE,releaseHnd, &isAllocated)) < 0)
        {
            System_printf ("Error Core %d : Opening releaseHnd Number\n", coreNum);
    		return;
        }

    if ((completionQueHnd= Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE,completionQueHnd, &isAllocated)) < 0)
        {
            System_printf ("Error Core %d : Opening completion Queue Number\n", coreNum);
    		return;
        }

    if ((EventFreeDescHnd= Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE,EventFreeDescHnd, &isAllocated)) < 0)
            {
                System_printf ("Error Core %d : Free Desc Queue Number\n", coreNum);
        		return;
            }
	if((desc = Qmss_queuePop (EventFreeDescHnd))!=NULL){

 		Qmss_queuePushDesc (completionQueHnd, (UInt32 *) desc);
 	}
	else {

		System_printf ("Error  pushing completion in QMSS\n");
	}
}

Uint32 Create_Queue()
{
	Uint32 Hnd;
	UInt8           isAllocated;
    Uint32			coreNum;

	coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);
    if ((Hnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE,  QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
      	{
              System_printf ("Error Core %d : Opening  event Queue Number\n", coreNum);
      		return 0;
      	}
    Qmss_queueEmpty (Hnd);
    return Hnd;
}
Uint32 Open_Queue(volatile Uint32 Hnd)
{
	UInt8           isAllocated;
    if ((Hnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, Hnd, &isAllocated)) < 0)
      	{
              System_printf ("Error Opening semaphore Queue \n");
      	}
	return Hnd;
}

void Close_Queue(volatile Uint32 Hnd)
{
	 Qmss_Result     result;
	 Cppi_Desc           *desc;
	 volatile UInt32   temp;
	 temp=Qmss_getQueueEntryCount (Hnd);
	 while((temp=Qmss_getQueueEntryCount (Hnd))!= 0){

		   if ((desc = (Cppi_Desc *) Qmss_queuePop (Hnd)) != NULL)
		   {
				 /* Push descriptor to sync free queue */
				 Qmss_queuePushDesc (EventFreeDescHnd, (UInt32 *) desc);
		   }
		   else{
			   System_printf ("Error empting queue\n");
		   }
	 }

	    if ((result = Qmss_queueClose (Hnd)) != CPPI_SOK)
	    {

	        if (result > 0)
	        {
	            while (result != CPPI_SOK)
	            {
	                result = Qmss_queueClose (Hnd);

	            }
	        }
	    }

}
void queue_push_elem(volatile Uint32 Hnd,volatile Uint32 elem)
{

	 Cppi_Desc          *desc;
	 UInt32				info;


   if ((desc = (Cppi_Desc *) Qmss_queuePop (EventFreeDescHnd)) != NULL)
   {
		 /* Push descriptor to sync free queue */
		 info= elem;
		 Cppi_setSoftwareInfo0  ( Cppi_DescType_MONOLITHIC, (Cppi_Desc *) desc, info);
		 Qmss_queuePushDesc (Hnd, (UInt32 *) desc);
   }
   else{
	   System_printf ("Error Core: pushing  element into queue\n");

   }
}
void queue_push_elem_event(volatile Uint32 Hnd,volatile Uint32 elem)
{

	 Cppi_Desc           *desc;
	 UInt32				info;


   if ((desc = (Cppi_Desc *) Qmss_queuePop (EventFreeDescHnd)) != NULL)
   {
		 /* Push descriptor to sync free queue */
		 info= elem;
		 Cppi_setSoftwareInfo0  ( Cppi_DescType_MONOLITHIC, (Cppi_Desc *) desc, info);
		 Qmss_queuePushDesc (Hnd, (UInt32 *) desc);
   }
   else{
	   System_printf ("Error Core: pushing  element into queue\n");

   }
}

Ptr queue_pop_elem(volatile Uint32 Hnd)
{
	Ptr info;
	Cppi_Desc           *desc;

	if((desc = Qmss_queuePop (Hnd))!=NULL)
	{
		info=  (Ptr)Cppi_getSoftwareInfo0  ( Cppi_DescType_MONOLITHIC,(Cppi_Desc *) desc);
		Qmss_queuePushDesc (EventFreeDescHnd, (UInt32 *) desc);
		return info;
	}
	else{
		return 0;
	}
}
Ptr queue_pop_elem_wait(volatile Uint32 Hnd)
{
	Ptr info;
	Cppi_Desc           *desc;

	while((  Qmss_getQueueEntryCount (Hnd))== 0){
		Task_yield();
	}
	if((desc = Qmss_queuePop (Hnd))!=NULL)
	{
		info=  (Ptr)Cppi_getSoftwareInfo0  ( Cppi_DescType_MONOLITHIC,(Cppi_Desc *) desc);
		Qmss_queuePushDesc (EventFreeDescHnd, (UInt32 *) desc);
		return info;
	}
	else{
		return 0;
	}
}
bool Queue_empty(volatile Uint32 Hnd)
{
	if(Qmss_getQueueEntryCount (Hnd)== 0) return true;
	else return false;
}
bool Queue_Count_Equal(volatile Uint32 Hnd, volatile Uint32 value)
{
	if(Qmss_getQueueEntryCount (Hnd)== value) return true;
	else return false;
}
Uint32 Queue_get_num_elem(volatile Uint32 Hnd)
{
	return Qmss_getQueueEntryCount (Hnd);
}

void Barrier_wait(volatile Uint32 total,volatile Uint32 Hnd)
{

	volatile Cppi_Desc           *desc;
	UInt8 				isAllocated;
	volatile UInt32  temp  = 0;
	volatile UInt32  temp2  = total;


    if ((Hnd= Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE,Hnd, &isAllocated)) < 0)
        {
            System_printf ("Error: Opening barrier Queue Number\n");
    		return;
        }

	if ((desc = ( Cppi_Desc *) Qmss_queuePop (EventFreeDescHnd)) != NULL)
	   {
		 /* Push descriptor to sync free queue */
		   Qmss_queuePushDesc (Hnd, (UInt32 *) desc);
		   while((( Qmss_getQueueEntryCount (Hnd))!=total) & ((Qmss_getQueueEntryCount (Hnd))!=0)){}
	   }
		else {
			System_printf ("Error  pushing barrier in QMSS\n");
		}
	   while(( Qmss_getQueueEntryCount (Hnd))!=0)
	   {
		   if((desc = (Cppi_Desc *) Qmss_queuePop (Hnd)) != NULL)
			   {
			 /* Push descriptor to sync free queue */
				 Qmss_queuePushDesc (EventFreeDescHnd, (UInt32 *) desc);
		   }
	   }
}
void Queue_wait_for_release(volatile Uint32 Hnd)
{

	Cppi_Desc           *desc;

	if (( desc =  (Cppi_Desc *) Qmss_queuePop (EventFreeDescHnd)) != NULL)
		   {
			 /* Push descriptor to sync free queue */
				 Qmss_queuePushDesc (Hnd, (UInt32 *) desc);
		   }
		else {

			System_printf ("Error  pushing at wait_for_release in QMSS\n");
		}
	while(release== 0){}
	if(( desc = ( Cppi_Desc *)Qmss_queuePop (Hnd)) !=NULL)
	{
		Qmss_queuePushDesc (EventFreeDescHnd, (UInt32 *) desc);
	}
	else {

		System_printf ("Error  pushing at wait_for_release release free in QMSS\n");
	}
	while(release== 1){}
	
}

void Queue_release_threads(volatile Uint32 total,volatile Uint32 Hnd)
{
	volatile UInt32		 temp;
	temp=0;
	while(  (temp=Qmss_getQueueEntryCount (Hnd)) < (total-1)){}
	release=1;
	while((temp=Qmss_getQueueEntryCount (Hnd))!= 0){}
	release=0;
}

void init_Navigator(){


	    volatile UInt32     count;
	    volatile UInt32  	result;
        Uint32 coreNum;

	    /* Get the core number. */
		coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);

	    /* Core 0 is treated as the producer core that
	     * Initializes the system
	     * setups the configuration
	     */

	    /* Initializes the system */
	    if (coreNum == MultiProc_getBaseIdOfCluster())
	    {
	        if (sysInit () < 0)
	        {
	            System_printf ("Error Core %d : Initializing QMSS\n", coreNum);
	            return;
	        }
	        while((result = Qmss_getQueueEntryCount (completionQueHnd))!= (MultiProc_getNumProcsInCluster()-1)){}
	        Qmss_queueEmpty (completionQueHnd);
	    }
	    else
	    {
	        /* Get the handle for common queues on consumer cores */
	    	getsysHandles ();
	    	return;
	    }
}

UInt32 Queue_threads_count(volatile Uint32 Hnd)
{
	return(Qmss_getQueueEntryCount (Hnd));
}

Void sysExit (Void)
{
    Qmss_Result     result;


    /* Close the queues */

    if ((result = Qmss_queueClose (completionQueHnd)) != CPPI_SOK)
    {
        if (result > 0)
        {
            while (result != CPPI_SOK)
            {
                result = Qmss_queueClose (completionQueHnd);

            }
        }
    }
    else

    if ((result = Qmss_queueClose (eventQueHnd)) != CPPI_SOK)
    {
        if (result > 0)
        {
            while (result != CPPI_SOK)
            {
                result = Qmss_queueClose (eventQueHnd);

            }
       }
    }
    else

    if ((result = Qmss_queueClose (EventFreeDescHnd)) != CPPI_SOK)
    {
        if (result > 0)
        {
            while (result != CPPI_SOK)
            {
                result = Qmss_queueClose (EventFreeDescHnd);
            }
        }
    }
    /* Close CPPI CPDMA instance */
    if ((result = Cppi_close (cppiHnd)) != CPPI_SOK){}
    /* Deinitialize CPPI LLD */
    if ((result = Cppi_exit ()) != CPPI_SOK){}

}

/* --COPYRIGHT--,BSD
 * Copyright (c)  2012, Texas Instruments Incorporated
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
 *  ======== SemaphoreMP.c ========
 */
 
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Startup.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/hal/Cache.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/sdo/ipc/_Ipc.h>
#include <ti/sdo/utils/_MultiProc.h>
#include <ti/sdo/utils/_NameServer.h>
#include <ti/sdo/ipc/_GateMP.h>
#include <ti/sdo/ipc/_ListMP.h>
#include <ti/sdo/ipc/_SharedRegion.h>
#include <ti/sdo/ipc/_Notify.h>

#include <ti/omp/utils/ThreadLocal.h>

#include "package/internal/SemaphoreMP.xdc.h"

/* Global module state. Should be placed in shared memory */
ThreadLocal_Key SemaphoreMP_pendElemKey = (ThreadLocal_Key)~0;
#pragma DATA_SECTION(SemaphoreMP_pendElemKey, "gomp_data")

Void SemaphoreMP_start()
{
    if (MultiProc_self() == 0 && SemaphoreMP_pendElemKey == (ThreadLocal_Key)~0) {
        ThreadLocal_key_create(&SemaphoreMP_pendElemKey, NULL); //TODO destructor function
    }
}

/*
 *  ======== SemaphoreMP_registerEvent ========
 */
Int SemaphoreMP_registerEvent(UArg arg, UInt16 remoteProcId) 
{
    Int status;
    
    status = Notify_registerEvent(remoteProcId, 0, SemaphoreMP_notifyEventId, 
            SemaphoreMP_cbFxn, NULL);
            
    Assert_isTrue(status >= 0, ti_sdo_ipc_Ipc_A_internal);
    
    return (0);
}

/*
 *  ======== SemaphoreMP_Instance_init ========
 */
Int SemaphoreMP_Instance_init(SemaphoreMP_Object *obj, Int count,
        const SemaphoreMP_Params *params, Error_Block *eb)
{
    Ptr localAddr;
    Int status;
    IHeap_Handle regionHeap;
    ListMP_Params listMPParams;
    SharedRegion_SRPtr sharedShmBase;
    
    if (params->openFlag) {
        /* Open by sharedAddr */
        obj->objType = ti_sdo_ipc_Ipc_ObjType_OPENDYNAMIC;
        obj->attrs = (SemaphoreMP_Attrs *)params->sharedAddr;
        obj->regionId = SharedRegion_getId(obj->attrs);
        obj->cacheEnabled = SharedRegion_isCacheEnabled(obj->regionId);
    
        obj->mode = (SemaphoreMP_Mode)obj->attrs->mode;
    
        regionHeap = SharedRegion_getHeap(obj->regionId);
        Assert_isTrue(regionHeap != NULL, ti_sdo_ipc_SharedRegion_A_noHeap);
    
        /* get the local address of the SRPtr */
        localAddr = SharedRegion_getPtr(obj->attrs->gateMPAddr);
        status = GateMP_openByAddr(localAddr, (GateMP_Handle *)&(obj->gate));
        if (status < 0) {
            return (1);
        }
        
        /* Open the ListMP */
        localAddr = (Ptr)_Ipc_roundup(
            (UInt32)obj->attrs + sizeof(SemaphoreMP_Attrs), 
            SharedRegion_getCacheLineSize(obj->regionId));
        status = ListMP_openByAddr(localAddr, (ListMP_Handle *)&(obj->pendQ));
        if (status < 0) {
            /* obj->freeList set to NULL */
            return (4);
        }

        return (0);
    }

    /* init the gate */
    if (params->gate != NULL) {
        obj->gate = params->gate;
    }
    else {
        obj->gate = (ti_sdo_ipc_GateMP_Handle)GateMP_getDefaultRemote();
    }
    obj->mode = params->mode;
    
    if (params->sharedAddr == NULL) {
        /* Creating using a shared region ID */                
        obj->objType = ti_sdo_ipc_Ipc_ObjType_CREATEDYNAMIC_REGION;
        obj->regionId = params->regionId;
        obj->cacheEnabled = SharedRegion_isCacheEnabled(obj->regionId);
                
        /* Need to allocate from the heap */
        obj->allocSize = SemaphoreMP_sharedMemReq(params);
            
        regionHeap = SharedRegion_getHeap(obj->regionId);
        Assert_isTrue(regionHeap != NULL, ti_sdo_ipc_SharedRegion_A_noHeap);

        /* The region heap will take care of the alignment */
        obj->attrs = Memory_alloc(regionHeap, obj->allocSize, 0, eb);
        if (obj->attrs == NULL) {
            return (2);
        }
    }
    else {
        /* Creating using sharedAddr */
        obj->regionId = SharedRegion_getId(params->sharedAddr);
                    
        /* Assert that the buffer is in a valid shared region */
        Assert_isTrue(obj->regionId != SharedRegion_INVALIDREGIONID, 
                      ti_sdo_ipc_Ipc_A_addrNotInSharedRegion);
        
        /* Assert that sharedAddr is cache aligned */
        Assert_isTrue(((UInt32)params->sharedAddr % 
                      SharedRegion_getCacheLineSize(obj->regionId) == 0),
                      ti_sdo_ipc_Ipc_A_addrNotCacheAligned);
                
        /* set object's cacheEnabled, objType, and attrs  */
        obj->cacheEnabled = SharedRegion_isCacheEnabled(obj->regionId);
        obj->objType = ti_sdo_ipc_Ipc_ObjType_CREATEDYNAMIC;
        obj->attrs = (SemaphoreMP_Attrs *)params->sharedAddr;
    }
    
    /* Store the GateMP sharedAddr in the SemaphoreMP Attrs */
    obj->attrs->gateMPAddr = ti_sdo_ipc_GateMP_getSharedAddr(obj->gate);
    obj->attrs->mode = (Bits16)obj->mode;
    obj->attrs->count = count;
    
    /* Create the freeList */
    ListMP_Params_init(&listMPParams);
    listMPParams.sharedAddr = (Ptr)_Ipc_roundup((UInt32)obj->attrs +
            sizeof(SemaphoreMP_Attrs), 
            SharedRegion_getCacheLineSize(obj->regionId));
    listMPParams.gate = (GateMP_Handle)obj->gate;
    obj->pendQ = (ti_sdo_ipc_ListMP_Handle)ListMP_create(&listMPParams);
    if (obj->pendQ == NULL) {
        return (3);
    }
    
    /* Last thing, set the status */
    obj->attrs->status = SemaphoreMP_CREATED;
    if (obj->cacheEnabled) {
        Cache_wbInv(obj->attrs, sizeof(SemaphoreMP_Attrs), Cache_Type_ALL, 
                TRUE);
    }
    
    /* Add entry to NameServer */
    if (params->name != NULL) {
        /* We will store a shared pointer in the NameServer */
        sharedShmBase = SharedRegion_getSRPtr(obj->attrs,
                                              obj->regionId);
        obj->nsKey = NameServer_addUInt32((NameServer_Handle)
                SemaphoreMP_module->nameServer, params->name,
                (UInt32)sharedShmBase);
        if (obj->nsKey == NULL) {
            /* NameServer_addUInt32 failed */
            return (4); 
        }
    }
    
    return (0);
}

/*
 *  ======== SemaphoreMP_Instance_finalize ========
 */
Void SemaphoreMP_Instance_finalize(SemaphoreMP_Object *obj, Int status)
{
    if (obj->objType & (ti_sdo_ipc_Ipc_ObjType_CREATEDYNAMIC |
                        ti_sdo_ipc_Ipc_ObjType_CREATEDYNAMIC_REGION)) {
        /* SemaphoreMP is being deleted */
        /* Remove entry from NameServer */
        if (obj->nsKey != NULL) {
            NameServer_removeEntry((NameServer_Handle)
                    SemaphoreMP_module->nameServer, obj->nsKey);
        }

        /* Set status to 'not created' */
        obj->attrs->status = 0;
        if (obj->cacheEnabled) {
            Cache_wbInv(obj->attrs, sizeof(SemaphoreMP_Attrs), 
                    Cache_Type_ALL, TRUE);
        }

        /* Delete the pendQ. If NULL, then ListMP_create failed. */
        if (obj->pendQ != NULL) {
            ListMP_delete((ListMP_Handle *)&(obj->pendQ));
        }

        /*
         *  Free the shared memory back to the region SemaphoreMP. If NULL, then
         *  the Memory_alloc failed.
         */
        if (obj->objType == ti_sdo_ipc_Ipc_ObjType_CREATEDYNAMIC_REGION &&
            obj->attrs != NULL) {
            Memory_free(SharedRegion_getHeap(obj->regionId), obj->attrs, 
                    obj->allocSize);
        }
    }
    else {
        /* SemaphoreMP is being closed */
        /* Close the pendQ. If NULL, then ListMP_openByAddr failed. */
        if (obj->pendQ != NULL) {
            ListMP_close((ListMP_Handle *)&(obj->pendQ));
        }
        
        /* Close the gate. If NULL, then GateMP_openByAddr failed. */
        if (obj->gate != NULL) {
            GateMP_close((GateMP_Handle *)&(obj->gate));
        }
    }
}


/*
 *  ======== SemaphoreMP_close ========
 */
Void SemaphoreMP_close(SemaphoreMP_Handle *handlePtr)
{
    SemaphoreMP_delete(handlePtr);
}

/*
 *  ======== SemaphoreMP_pend ========
 */
Bool SemaphoreMP_pend(SemaphoreMP_Object *obj)
{
    UInt tskKey;
    SemaphoreMP_PendElem *elem;
    IArg gateMPKey;

    /* Check for correct calling context */
    Assert_isTrue((BIOS_getThreadType() == BIOS_ThreadType_Task),
                    SemaphoreMP_A_badContext);

    elem = ThreadLocal_getspecific(SemaphoreMP_pendElemKey);
    if (elem == NULL) {
        /* 
         * Choose region zero (instead of the region that contains the 
         * SemaphoreMP) since region zero is always accessible by all cores
         */
        elem = Memory_alloc(SharedRegion_getHeap(0), 
                sizeof(SemaphoreMP_PendElem), 0, NULL);
        ThreadLocal_setspecific(SemaphoreMP_pendElemKey, elem);
    }
    
    /* Enter the gate */
    gateMPKey = GateMP_enter((GateMP_Handle)obj->gate);

    if (obj->cacheEnabled) {
        Cache_inv(obj->attrs, sizeof(SemaphoreMP_Attrs), Cache_Type_ALL, TRUE);
    }
    
    /* check semaphore count */
    if (obj->attrs->count == 0) {
        /* lock task scheduler */
        tskKey = Task_disable();

        /* get task handle and block tsk */
        elem->task = (Bits32)Task_self();
        elem->procId = MultiProc_self();
        
        Task_block((Task_Handle)elem->task);
        
        if (obj->cacheEnabled) {
            Cache_wbInv(elem, sizeof(SemaphoreMP_PendElem), Cache_Type_ALL, TRUE);
        }

        /* add it to pendQ */
        ListMP_putTail((ListMP_Handle)obj->pendQ, (ListMP_Elem *)elem);

        /* Leave the gate */
        GateMP_leave((GateMP_Handle)obj->gate, gateMPKey);

        Task_restore(tskKey);/* the calling task will switch out here */

        return (TRUE);
    }
    else {
        obj->attrs->count--;
        if (obj->cacheEnabled) {
            Cache_wbInv(obj->attrs, sizeof(SemaphoreMP_Attrs), Cache_Type_ALL, 
                    TRUE);
        }

        /* Leave the gate */
        GateMP_leave((GateMP_Handle)obj->gate, gateMPKey);

        return (TRUE);
    }
}

/*
 *  ======== SemaphoreMP_post ========
 */
Void SemaphoreMP_post(SemaphoreMP_Object *obj)
{
    UInt tskKey;
    SemaphoreMP_PendElem *elem;
    IArg gateMPKey;
    Int status;

    /* Enter the gate */
    gateMPKey = GateMP_enter((GateMP_Handle)obj->gate);

    if (ListMP_empty((ListMP_Handle)obj->pendQ)) {
        if (obj->mode == SemaphoreMP_Mode_BINARY) {
            obj->attrs->count = 1;
        }
        else {
            obj->attrs->count++;
        }
        if (obj->cacheEnabled) {
            Cache_wbInv(obj->attrs, sizeof(SemaphoreMP_Attrs), Cache_Type_ALL,
                    TRUE);
        }
            
        /* Leave the gate */
        GateMP_leave((GateMP_Handle)obj->gate, gateMPKey);
        
        return;
    }

    /* lock task scheduler */
    tskKey = Task_disable();

    /* dequeue tsk from semaphore queue */
    elem = (SemaphoreMP_PendElem *)ListMP_getHead((ListMP_Handle)obj->pendQ);
    
    if (elem->procId != MultiProc_self()) {
        /* Unblock remote task */
        status = Notify_sendEvent(elem->procId, 0, SemaphoreMP_notifyEventId, 
                elem->task, TRUE);
        Assert_isTrue(status >= 0, ti_sdo_ipc_Ipc_A_internal);
    }
    else {
        /* put task back into readyQ */
        Task_unblock((Task_Handle)elem->task);
    }

    /* Leave the gate */
    GateMP_leave((GateMP_Handle)obj->gate, gateMPKey);

    Task_restore(tskKey);
}

/*
 *  ======== SemaphoreMP_sharedMemReq ========
 */
SizeT SemaphoreMP_sharedMemReq(const SemaphoreMP_Params *params)
{
    SizeT memReq, minAlign;
    ListMP_Params listMPParams;
    UInt16 regionId;
    
    if (params->sharedAddr == NULL) {
        regionId = params->regionId;
    }
    else {
        regionId = SharedRegion_getId(params->sharedAddr);
    }
    
    Assert_isTrue(regionId != SharedRegion_INVALIDREGIONID, 
            ti_sdo_ipc_Ipc_A_internal);
            
    minAlign = SharedRegion_getCacheLineSize(regionId);
    
    memReq = _Ipc_roundup(sizeof(SemaphoreMP_Attrs), minAlign);
    
    /*
     *  Add size of ListMP Attrs.  No need to init params since it's not used
     *  to create.
     */
    ListMP_Params_init(&listMPParams);
    listMPParams.regionId = regionId;
    memReq += ListMP_sharedMemReq(&listMPParams);
    
    return (memReq);
}

/*
 *  ======== SemaphoreMP_open ========
 */
Int SemaphoreMP_open(String name,
                   SemaphoreMP_Handle *handlePtr)
{
    SharedRegion_SRPtr sharedShmBase;
    Int status;
    Ptr sharedAddr;
    Error_Block eb;

    Error_init(&eb);

    /* Assert that a pointer has been supplied */
    Assert_isTrue(handlePtr != NULL, ti_sdo_ipc_Ipc_A_nullArgument);

    /* Assert that a name has been supplied */
    Assert_isTrue(name != NULL, ti_sdo_ipc_Ipc_A_invParam);

    /* Open by name */
    status = NameServer_getUInt32((NameServer_Handle)
            SemaphoreMP_module->nameServer, name, &sharedShmBase, NULL);

    if (status < 0) {
        /* Name not found. */
        *handlePtr = NULL;
        return (-1); //TODO
    }

    sharedAddr = SharedRegion_getPtr(sharedShmBase);

    status = SemaphoreMP_openByAddr(sharedAddr, handlePtr);

    return (status);
}

/*
 *  ======== SemaphoreMP_openByAddr ========
 */
Int SemaphoreMP_openByAddr(Ptr sharedAddr,
                           SemaphoreMP_Handle *handlePtr)
{
    SemaphoreMP_Params params;
    SemaphoreMP_Attrs *attrs;
    Int status;
    Error_Block eb;

    Error_init(&eb);

    SemaphoreMP_Params_init(&params);

    /* Tell Instance_init() that we're opening */
    params.openFlag = TRUE;

    params.sharedAddr = sharedAddr;
    attrs = (SemaphoreMP_Attrs *)sharedAddr;

    if (SharedRegion_isCacheEnabled(SharedRegion_getId(sharedAddr))) {
        Cache_inv(attrs, sizeof(SemaphoreMP_Attrs), Cache_Type_ALL, TRUE);
    }

    if (attrs->status != SemaphoreMP_CREATED) {
        *handlePtr = NULL;
        status = -1; //SemaphoreMP_E_NOTFOUND;
    }
    else {
        *handlePtr = SemaphoreMP_create(0, &params, &eb);
        if (*handlePtr == NULL) {
            status = -1; //SemaphoreMP_E_FAIL;
        }
        else {
            status = 0; //SemaphoreMP_S_SUCCESS;
        }
    }

    return (status);
}


/*
 *  ======== SemaphoreMP_cbFxn ========
 */
Void SemaphoreMP_cbFxn(UInt16 procId, UInt16 lineId, UInt32 eventId, 
                       UArg arg, UInt32 payload)
{
    Task_Handle task;
    UInt tskKey;
    
    task = (Task_Handle)payload;
    
    /* lock task scheduler */
    tskKey = Task_disable();
    
    /* put task back into readyQ */
    Task_unblock(task);
    
    /* Force the task scheduler to run */
    Task_restore(tskKey);
}

/*
 *  ======== SemaphoreMP_getCount ========
 */
Int SemaphoreMP_getCount(SemaphoreMP_Object *obj)
{
    return (obj->attrs->count);
}


Void QMSS_SemaphoreMP_destroy(SemaphoreMP_Object *obj)
{
	Close_Queue(obj->QMSS_sem_Hnd);
}
Void QMSS_SemaphoreMP_init(SemaphoreMP_Object *obj, Int count)
{
	int i;
	obj->QMSS_sem_Hnd = Create_Queue();
	for(i=0 ; i< count ; i++) {
		queue_push_elem(obj->QMSS_sem_Hnd ,1);
	}
}

Void QMSS_SemaphoreMP_pend(SemaphoreMP_Object *obj)
{
	obj->QMSS_sem_Hnd = Open_Queue(obj->QMSS_sem_Hnd);
    while(queue_pop_elem(obj->QMSS_sem_Hnd)==0);

}
Void QMSS_SemaphoreMP_post(SemaphoreMP_Object *obj)
{
   queue_push_elem(obj->QMSS_sem_Hnd ,1);
}

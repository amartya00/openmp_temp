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
 *  ======== ThreadLocal.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Gate.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/BIOS.h>
#include <stdio.h>
#include <ti/ipc/GateMP.h>
#include <ti/omp/utils/OpenMP.h>

#include "package/internal/ThreadLocal.xdc.h"

/* Must go into shared memory */
ThreadLocal_DestructFxn ThreadLocal_destructors[ThreadLocal_MAXKEYS];
Bits16 ThreadLocal_usedKeys = 0x0;
#pragma DATA_SECTION(ThreadLocal_destructors, "gomp_data")
#pragma DATA_SECTION(ThreadLocal_usedKeys, "gomp_data")

/*!
 *  ======== ThreadLocal_key_create ========
 */
Int ThreadLocal_key_create(ThreadLocal_Key *keyPtr, 
        ThreadLocal_DestructFxn destructor) 
{
    ThreadLocal_Key key = ~0;
    UInt i;
    UInt gatekey;
    GateMP_Handle gateHandle;

    gateHandle = GateMP_getDefaultRemote();
    gatekey = (long long)GateMP_enter(gateHandle);

    for (i = 0; i < ThreadLocal_MAXKEYS; i++) {
        if (((1 << i) & ThreadLocal_usedKeys) == 0) {
            key = i;
            ThreadLocal_usedKeys |= (1 << i);
            ThreadLocal_destructors[key] = destructor;
            *keyPtr = key;
            break;
        }
    }

    GateMP_leave(gateHandle, (UInt)gatekey);

    if (key == ~0) {
        return (-1); /* Failure, no more keys left */
    }
    
    return (0); /* Success */
}

/*!
 *  ======== key_delete ========
 */
Int ThreadLocal_key_delete(ThreadLocal_Key key)
{
    Assert_isTrue(key < ThreadLocal_MAXKEYS && 
            ((1 << key) & ThreadLocal_usedKeys), 
            ThreadLocal_A_invalidKey);
            
    ThreadLocal_usedKeys &= ~(1 << key);
            
    return (0);
}

/*!
 *  ======== ThreadLocal_setspecific ========
 */
Int ThreadLocal_setspecific(ThreadLocal_Key key, const Void *val)
{
    Void **tskValues;
    
    Assert_isTrue(key < ThreadLocal_MAXKEYS && 
            ((1 << key) & ThreadLocal_usedKeys), 
            ThreadLocal_A_invalidKey);
    Assert_isTrue(BIOS_getThreadType() == BIOS_ThreadType_Task, 
            ThreadLocal_A_invalidContext);
    
    tskValues = (Void **)Task_getHookContext(Task_self(), 
            ThreadLocal_module->contextId);

    Assert_isTrue(tskValues != NULL, NULL);
            
    tskValues[key] = (Void *)val;
    
    return (0);
}

/*!
 *  ======== ThreadLocal_getspecific ========
 */
Void *ThreadLocal_getspecific(ThreadLocal_Key key)
{
    Void **tskValues;
    
    Assert_isTrue(key < ThreadLocal_MAXKEYS && 
            ((1 << key) & ThreadLocal_usedKeys), 
            ThreadLocal_A_invalidKey);
    Assert_isTrue(BIOS_getThreadType() == BIOS_ThreadType_Task, 
            ThreadLocal_A_invalidContext);
    
    tskValues = (Void **)Task_getHookContext(Task_self(), 
            ThreadLocal_module->contextId);
    
    return (tskValues[key]);
}


/*!
 *  ======== ThreadLocal_createFxn ========
 */
Void ThreadLocal_createFxn(Task_Handle tsk, Error_Block *eb)
{
    Void **tskValues;
    
    tskValues = Memory_calloc(NULL, sizeof(Void *) * ThreadLocal_MAXKEYS, 0, 
            eb);
	    #if 0
        printf("(Core = %d) ThreadLocal_createFxn: tsk = 0x%x\n",
                                                 MultiProc_self(), tsk);
        #endif
    
    Task_setHookContext(tsk, ThreadLocal_module->contextId, tskValues);
}

/*!
 *  ======== ThreadLocal_exitFxn ========
 */
Void ThreadLocal_exitFxn(Task_Handle tsk)
{
    Void **tskValues;
    UInt i;
    
    tskValues = (Void **)Task_getHookContext(tsk, 
            ThreadLocal_module->contextId);
    
    for (i = 0; i < ThreadLocal_MAXKEYS; i++) {
        if ((((1 << i) & ThreadLocal_usedKeys) != 0) /* Key exists */
                && ThreadLocal_destructors[i] != NULL /* Destructor exists */
                && tskValues[i] != NULL /* Value exists */) {
            /* Call the destructor with the corresponding value */
            ThreadLocal_destructors[i](tskValues[i]);
	    }
    }

		#if 0
        printf("(Core = %d) ThreadLocal_exitFxn: tsk = 0x%x\n",
                                                 MultiProc_self(), tsk);
        #endif

    
    /* Free values array */
    Memory_free(NULL, tskValues, sizeof(Void *) * ThreadLocal_MAXKEYS);
}

/*!
 *  ======== ThreadLocal_registerFxn ========
 */
Void ThreadLocal_registerFxn(Int id)
{    
    ThreadLocal_module->contextId = id;
}



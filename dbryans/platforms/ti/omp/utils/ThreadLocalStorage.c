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
 *  ======== ThreadLocalStorage.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/ipc/SharedRegion.h>
#include <xdc/runtime/IHeap.h>

#include <xdc/runtime/System.h>
#include <ti/ipc/MultiProc.h>

#include "package/internal/ThreadLocalStorage.xdc.h"

/* Defined in the C6000 RTS */
extern void   __TI_tls_init(void * TLS_block_addr);
extern size_t __TI_tls_block_size();

#define TLSSIZE (__TI_tls_block_size())

/* There is a currentTP per core, stored in core local memory */
#pragma DATA_SECTION (__TI_tls_currentTP, ".tls_tp")
Ptr __TI_tls_currentTP;

/*!
 *  ======== isTLSRequired ========
 */
static inline Bool isTLSRequired(Task_Handle tsk)
{
    /* If a task requires TLS,tsk->env must be set to -1 during task creation */
    if (TLSSIZE == 0 || tsk->env != (xdc_Ptr)-1)
        return FALSE;

    return TRUE;
}

/*!
 *  ======== ThreadLocalStorage_createFxn ========
 */
Void ThreadLocalStorage_createFxn(Task_Handle tsk, Error_Block *eb)
{
    Ptr tls = NULL;

    if (isTLSRequired(tsk))
    {
        Error_init(eb);

        /* If heapOmpHandle is NULL, Memory_alloc will use defaultHeapInstance
         * Align of 0 implies default alignment
         */
        tls = Memory_alloc(ThreadLocalStorage_module->heapOmpHandle, 
                           TLSSIZE, 0, eb);

        /* 'eb' will be checked in Task_postInit() function in Task.c file to 
         * make sure it does not contain an error. If there's an error, then 
         * Task_create() give up and will return NULL.
         */
        if (tls != NULL);
            __TI_tls_init(tls);

        #if 0
        System_printf("(Core = %d) tlsCreateFxn: tsk = 0x%x, tls = 0x%x\n",
                                                 MultiProc_self(), tsk, tls);
        #endif
    }

    Task_setHookContext(tsk, ThreadLocalStorage_module->contextId, tls);
}

/*!
 *  ======== ThreadLocalStorage_deleteFxn ========
 */
Void ThreadLocalStorage_deleteFxn(Task_Handle tsk)
{
    Ptr tls = Task_getHookContext(tsk, ThreadLocalStorage_module->contextId);

    #if 0
    System_printf("(Core = %d) tlsDeleteFxn: tsk = 0x%x, tls = 0x%x\n",
                                                 MultiProc_self(), tsk, tls);
    #endif

    if (tls != NULL)
        Memory_free(ThreadLocalStorage_module->heapOmpHandle, tls, TLSSIZE);
}

/*!
 *  ======== ThreadLocalStorage_switchFxn ========
 */
Void ThreadLocalStorage_switchFxn(Task_Handle from, Task_Handle to)
{
    /* To minimize the footprint of __c6xabi_get_tp(), the switch function 
     * initializes the currentTP to that of the task. __c6xabi_get_tp()
     * just returns the value stored in currentTP.
     */
    __TI_tls_currentTP = Task_getHookContext(to, 
                                          ThreadLocalStorage_module->contextId);
}

/*!
 *  ======== ThreadLocalStorage_registerFxn ========
 */
Void ThreadLocalStorage_registerFxn(Int id)
{    
    ThreadLocalStorage_module->contextId = id;
}



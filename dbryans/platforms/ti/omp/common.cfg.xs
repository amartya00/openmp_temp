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
 *  ======== common.cfg.xs ========
 */
var OpenMP = xdc.useModule('ti.omp.utils.OpenMP');
OpenMP.stackSize = 0x8000;
OpenMP.ipcHeapSize = 0x80000;

var System = xdc.useModule("xdc.runtime.System");
var SysMin = xdc.useModule("xdc.runtime.SysMin");
System.SupportProxy = SysMin;
SysMin.bufSize = 0x8000;

var Task = xdc.useModule('ti.sysbios.knl.Task');
Task.deleteTerminatedTasks = true;



//
// Setup HeapOMP
//

// Initialize HeapMem parameters
var HeapOMP      = xdc.useModule('ti.omp.utils.HeapOMP');
var HeapMem      = xdc.useModule('ti.sysbios.heaps.HeapMem');
var heapMemParams = new HeapMem.Params();
heapMemParams.size = HeapOMP.localHeapSize;

// Create a HeapOMP instance
var heapOmpParams = new HeapOMP.Params();
heapOmpParams.localHeap = HeapMem.create(heapMemParams)
heapOmpParams.sRegionId = HeapOMP.sharedRegionId;

// Setup defaultHeapInstance to a HeapOMP instance
var Memory       = xdc.useModule('xdc.runtime.Memory');
if (Memory.defaultHeapInstance)
    Program.$logWarning("Memory.defaultHeapInstance already set!", this);

Memory.defaultHeapInstance = HeapOMP.create(heapOmpParams)



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
 *  ======== Navigator.xs ========
 */
var Memory 
var HeapMem 
var HeapBuf 
var Task 
var Swi 
/* Load and use the CPPI and QMSS packages */
var Cppi 
var Qmss 
/* Use the CSL module and indicate that INTC library will be used. */
var cslSettings 

/*
 *  ======== module$use ========
 */
function module$use()
{

    Memory = xdc.useModule('xdc.runtime.Memory');
    BIOS = xdc.useModule('ti.sysbios.BIOS');
    HeapMem = xdc.useModule('ti.sysbios.heaps.HeapMem');
    HeapBuf = xdc.useModule('ti.sysbios.heaps.HeapBuf');
    Task = xdc.useModule('ti.sysbios.knl.Task');
    Swi = xdc.useModule('ti.sysbios.knl.Swi');
    Cppi = xdc.loadPackage('ti.drv.cppi'); 
    Qmss = xdc.loadPackage('ti.drv.qmss'); 
    cslSettings = xdc.useModule ('ti.csl.Settings');

    cslSettings.useCSLIntcLib = true;
}

function memorySetup()
{
    var sectsToRelocate = {
	  "Nav_init"    :     Program.platform.dataMemory,
        ".init_array" :     Program.platform.stackMemory,
        ".qmss" :           Program.platform.dataMemory,
        ".shareddata" :     Program.platform.dataMemory,
        ".cppi" :           Program.platform.stackMemory,
    }
    
    for (var sect in sectsToRelocate) {
       if (Program.sectMap[sect] === undefined) {
           Program.sectMap[sect] = new Program.SectionSpec();
           Program.sectMap[sect].loadSegment = sectsToRelocate[sect];
       }
    }
}








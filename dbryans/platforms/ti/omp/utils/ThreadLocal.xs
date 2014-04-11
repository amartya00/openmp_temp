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
 *  ======== ThreadLocal.xs ========
 */

/*
 *  ======== module$use ========
 */
function module$use()
{
    var Task = xdc.useModule('ti.sysbios.knl.Task');
    var GateMP = xdc.useModule('ti.sdo.ipc.GateMP');
    
    Task.addHookSet({
        registerFxn: '&ti_omp_utils_ThreadLocal_registerFxn__F',
        createFxn: '&ti_omp_utils_ThreadLocal_createFxn__F',
        exitFxn: '&ti_omp_utils_ThreadLocal_exitFxn__F',
    });

}


/*
 *  ======== module$static$init ========
 */
function module$static$init(mod, params)
{
    mod.contextId = -1;
}

/*
 *  ======== viewKeyValues ========
 */
function viewKeyValues(view)
{
    var Program = xdc.useModule('xdc.rov.Program');
    var ThreadLocal = xdc.useModule('ti.omp.utils.ThreadLocal');
    var Task = xdc.useModule('ti.sysbios.knl.Task');
    
    var taskRawView = Program.scanRawview('ti.sysbios.knl.Task');
    for each (tskObj in taskRawView.instStates) {
        var veyValueView = Program.newViewStruct('ti.omp.utils.ThreadLocal',
                'KeyValueView');
    }
}

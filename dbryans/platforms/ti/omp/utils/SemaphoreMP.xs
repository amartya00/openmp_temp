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
 *  ======== SemaphoreMP.xs ========
 */

var SemaphoreMP = null;

var BIOS = null;
var Task = null;

var Ipc = null;
var ListMP = null;
var GateMP = null;
var SharedRegion = null;
var MultiProc = null;
var NameServer = null;

var ThreadLocal = null;

/*
 *  ======== module$use ========
 */
function module$use()
{
    SemaphoreMP = this;

    BIOS = xdc.useModule('ti.sysbios.BIOS');
    Task = xdc.useModule('ti.sysbios.knl.Task');
    
    Ipc = xdc.useModule('ti.sdo.ipc.Ipc');
    ListMP = xdc.useModule('ti.sdo.ipc.ListMP');
    GateMP = xdc.useModule('ti.sdo.ipc.GateMP');
    SharedRegion = xdc.useModule('ti.sdo.ipc.SharedRegion');
    
    NameServer = xdc.useModule('ti.sdo.utils.NameServer');
    MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');
    
    ThreadLocal = xdc.useModule('ti.omp.utils.ThreadLocal');
    
    var fxn = new Ipc.UserFxn;
    fxn.attach = '&ti_omp_utils_SemaphoreMP_registerEvent__I';
    fxn.detach = null;
    Ipc.addUserFxn(fxn, 0x1);
}

/*
 *  ======== module$static$init ========
 */
function module$static$init(mod, params)
{
    mod.nameServer = null;
    mod.pendElemKey = -1;
    
    SemaphoreMP.nameSrvPrms.maxRuntimeEntries = params.maxRuntimeEntries;
    SemaphoreMP.nameSrvPrms.maxNameLen        = params.maxNameLen;
    SemaphoreMP.nameSrvPrms.tableSection      = params.tableSection;

    /*
     *  Get the current number of created static instances of this module.
     *  Note: if user creates a static instance after this point and
     *        expects to use NameServer, this is a problem.
     */
    var instCount = this.$instances.length;

    /* create NameServer here only if no static instances are created */
    if (instCount == 0) {
        mod.nameServer = NameServer.create("SemaphoreMP", 
                SemaphoreMP.nameSrvPrms);
    }
}


/*
 *  ======== viewInitBasic ========
 */
function viewInitBasic(view, obj)
{
    var NameServer      = xdc.useModule('ti.sdo.utils.NameServer');
    var SemaphoreMP     = xdc.useModule('ti.omp.utils.SemaphoreMP');
    var Ipc             = xdc.useModule('ti.sdo.ipc.Ipc');
    var SharedRegion    = xdc.useModule('ti.sdo.ipc.SharedRegion');
    var MultiProc       = xdc.useModule('ti.sdo.utils.MultiProc');
    
    /* view.name */
    view.name = NameServer.getName$view("SemaphoreMP", 
        SharedRegion.getSRPtrMeta$view(obj.attrs));

    /* view.objType */
    view.objType = Ipc.getObjTypeStr$view(obj.objType);
    
    /* view.gate */
    view.gate = obj.gate;
    
    /* view.mode */
    switch (obj.mode) {
        case SemaphoreMP.Mode_COUNTING:
            view.mode = "Counting";
            break;
        case SemaphoreMP.Mode_BINARY:
            view.mode = "Binary";
            break;
    }

    
    try {
        var attrs = Program.fetchStruct(SemaphoreMP.Attrs$fetchDesc,
                                        obj.attrs.$addr, false);
        
        /* view.count */
        view.count = attrs.count;
        
        var dataViews = Program.scanInstanceDataView('ti.sdo.ipc.ListMP',
            'Lists');

        var listDataView = null;
        for each (var dataView in dataViews) {
            if (dataView.label.match(Number(obj.pendQ).toString(16))) {
                listDataView = dataView;
            }
        }
        
        for (var i = 0; i < listDataView.elements.length; i++) {
            var pendElem = Program.fetchStruct(SemaphoreMP.PendElem$fetchDesc,
                    $addr(listDataView.elements[i].addr), false);
            pendString = "0x" + Number(pendElem.task).toString(16) + " (" 
                    + MultiProc.getName$view(pendElem.procId) + ")";
            view.pendedTasks.$add(pendString);
        }
    }
    catch(e) {
        print(e);
    }
}

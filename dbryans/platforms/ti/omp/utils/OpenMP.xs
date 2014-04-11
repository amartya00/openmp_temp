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
 *  ======== OpenMP.xs ========
 */

var OpenMP;
 
var Task;
var BIOS;
var Semaphore;
var Memory;
var SemaphoreMP;
var Memory;
var SharedRegion;
var Navigator;
var Ipc;

/*
 *  ======== module$meta$init ========
 */
function module$meta$init()
{
    /* Only process during "cfg" phase */
    if (xdc.om.$name != "cfg") {
        return;
    }
    
    var MultiProcSetup = xdc.module('ti.sdo.ipc.family.c647x.MultiProcSetup');
    MultiProcSetup.configureProcId = false;

    /* 
     * Default to max number of processors. User can override this 
     * via OpenMP.setNumProcessors in .cfg if necessary
     */
    //cannot be overridded - Multiproc sets MultiProc.numProcsInCluster in 
    //a static manner
    setMaxProcessors();
}

/*
 *  ======== module$use ========
 */
function module$use()
{
    OpenMP = this;
    Navigator   = xdc.useModule('ti.omp.navigator.Navigator');
    /* Task that does the notify sending */
    BIOS        = xdc.useModule('ti.sysbios.BIOS');
    Task        = xdc.useModule('ti.sysbios.knl.Task');
    Semaphore   = xdc.useModule('ti.sysbios.knl.Semaphore');

    SemaphoreMP = xdc.useModule('ti.omp.utils.SemaphoreMP');
    
    /* For omp_get_wtime */
    Timer       = xdc.useModule('ti.sysbios.timers.timer64.Timer');
    Memory      = xdc.useModule('xdc.runtime.Memory');
    
    Ipc         = xdc.useModule('ti.sdo.ipc.Ipc');
  //  Ipc.procSync = Ipc.ProcSync_ALL;
    
    var Reset = xdc.useModule('xdc.runtime.Reset');
    Reset.fxns[Reset.fxns.length++] = "&_system_pre_init";
	if (OpenMP.autoDnldCore == true) {
	   Reset.fxns[Reset.fxns.length++] = "&siu_ibl_download_core";
	}
	
    
    var Startup = xdc.useModule('xdc.runtime.Startup');
    Startup.lastFxns.$add(BIOS.start);
    Startup.firstFxns.$add(OpenMP.setProcId);

    xdc.loadPackage('ti.omp');
    
    memorySetup();
	
    if (OpenMP.$written("singleThreadPerCore") == true) {
        this.$logWarning("OpenMP.singleThreadPerCore has been deprecated " +
        "as of OMP 1.00.00.22.  This configuration no longer has any effect " +
        "on the runtime", this);
    }
}

/*
 *  ======== memorySetup ========
 */
function memorySetup()
{
    /* place .cio and .sysmem sections into local memory */
    var sectsToRelocate = ['.cio', '.sysmem', '.args'];
    for each (var sect in sectsToRelocate) {
        if (Program.sectMap[sect] === undefined) {
            Program.sectMap[sect] = new Program.SectionSpec();
            Program.sectMap[sect].loadSegment = Program.platform.stackMemory;
        }
    }

    /* place constant sections into code memory (i.e. cached shared memory ) */
    var sectsToRelocate = ['.const', '.switch', '.cinit'];
    for each (var sect in sectsToRelocate) {
       if (Program.sectMap[sect] === undefined) {
           Program.sectMap[sect] = new Program.SectionSpec();
           Program.sectMap[sect].loadSegment = Program.platform.codeMemory;
       }
    }

	Program.sectMap[".text:_c_int00"] = {loadSegment: Program.platform.codeMemory, loadAlign:0x400};

    //var dataMem = Program.cpu.memoryMap[Program.platform.dataMemory];

    var dataMem = Program.cpu.memoryMap["MSMCSRAM_NOCACHE"];
    var shmBase0    = dataMem.base;
    var shmLen0     = OpenMP.ipcHeapSize;
    var shmLen1     = dataMem.len - shmLen0;
    
    if (Program.build.target.$name.match(/C66/)) {
        /* Disable cache for mapped MSMC RAM */
        var Cache = xdc.module('ti.sysbios.family.c66.Cache');
        Cache.setMarMeta(dataMem.base, dataMem.len, 0x00000000);
    }
    
    SharedRegion = xdc.useModule('ti.sdo.ipc.SharedRegion');

    /* Need to account for MultiProc.baseIdOfCluster */
    var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');

    var id = 0;
    if (MultiProc.baseIdOfCluster != undefined) {
        id = MultiProc.baseIdOfCluster;
    }
    
    /* Used for IPC shared state */
    SharedRegion.setEntryMeta(
            0,
            {   base: shmBase0,
                len:  shmLen0,
                ownerProcId: id,
                isValid: true,
                cacheLineSize: 0, 
                cacheEnable: false,
                name: "SL2_RAM",
            }
    );

    /* Used for libgomp shared state/code */
    SharedRegion.setEntryMeta(
            1,
            {   base: shmBase0 + shmLen0,
                len:  shmLen1,
                ownerProcId: id,
                cacheLineSize: 0,
                cacheEnable: false,
                createHeap: false,
                isValid: false,
                name: "local",
            }
    );
}

/*
 *  ======== module$static$init ========
 */
function module$static$init(mod, params)
{
    OpenMP = this;
    tskParams = new Task.Params();

    tskParams.stackSize = OpenMP.stackSize;
    Task.create('&ti_omp_utils_OpenMP_masterTask__I');
    
    mod.masterTaskSem = null;
    mod.threadSpawnQ = null;
    mod.useSharedHeap = false;
	/* Created at runtime */
    mod.gate = null;
    
    var TimerCapsule = xdc.loadCapsule('ti/sysbios/timers/timer64/Timer.xs');
    var OMPTimerId = TimerCapsule.deviceTable[Program.cpu.catalogName]
            [Program.cpu.deviceName].numLocalTimers;
    
    /* sets core 0 to init and release shared timer */
    Timer.timerSettings[OMPTimerId].ownerCoreId = OpenMP.baseIdOfCluster;
    var params = new Timer.Params();
    params.periodType = Timer.PeriodType_COUNTS;
    params.period = 0xFFFFFFFF;
    mod.sharedTimer = Timer.create(OMPTimerId, null, params);
}

/*
 *  ======== setNumProcessors ========
 */
function setNumProcessors(numProcessors)
{
    OpenMP = this;
    var MultiProc   = xdc.useModule('ti.sdo.utils.MultiProc');
    var Settings    = xdc.useModule('ti.sdo.ipc.family.Settings');
    
    var procNames =  Settings.getDeviceProcNames().sort();

    if (procNames.length < numProcessors) {
        throw("ERROR: Too many processors: " + numProcessors);
    }
    MultiProc.baseIdOfCluster = OpenMP.baseIdOfCluster;
    MultiProc.numProcessors = procNames.length;
	MultiProc.numProcsInCluster = numProcessors;
    MultiProc.setConfig(null, procNames.slice(OpenMP.baseIdOfCluster, numProcessors)); 
}

/*
 *  ======== setMaxProcessors ========
 */
function setMaxProcessors()
{
    var MultiProc   = xdc.useModule('ti.sdo.utils.MultiProc');
    var Settings    = xdc.useModule('ti.sdo.ipc.family.Settings');

    var procNames =  Settings.getDeviceProcNames().sort();
    
    MultiProc.setConfig(null, procNames); 
}


/*
 *  ======== module$validate ========
 */
function module$validate()
{
    if (OpenMP.masterFxn == null) {
        OpenMP.$logFatal("OpenMP.masterFxn cannot be NULL", OpenMP);
    }

    if (OpenMP.noncachedMsmcAlias & 0x0fffffff) {
        OpenMP.$logFatal("OpenMP.noncachedMsmcAlias & 0x0fffffff " +
            "should be '0'", OpenMP);
    }
}

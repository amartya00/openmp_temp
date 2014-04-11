/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"/media/work_/F5/TMS320C6678-Benchmarks/benchmarks/edma_test/Release/configPkg/package/cfg/app_pe66.oe66"
-l"/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo/ti/omp/utils/lib/release/ti.omp.utils.ae66"
-l"/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo/ti/omp/utils/lib/release/ti.omp.utils.C6678.ae66"
-l"/opt/ti/ipc_1_24_03_32/packages/ti/sdo/ipc/lib/instrumented_e66/ipc/ipc.lib"
-l"/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo/ti/omp/navigator/lib/release/ti.omp.navigator.ae66"
-l"/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo/ti/omp/navigator/lib/release/ti.omp.navigatorOsal.ae66"
-l"/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo/ti/omp/navigator/lib/release/ti.omp.navigator.C6678.ae66"
-l"/opt/ti/pdk_C6678_1_1_2_5/packages/ti/csl/lib/ti.csl.ae66"
-l"/opt/ti/pdk_C6678_1_1_2_5/packages/ti/csl/lib/ti.csl.intc.ae66"
-l"/opt/ti/pdk_C6678_1_1_2_5/packages/ti/drv/cppi/lib/ti.drv.cppi.ae66"
-l"/opt/ti/pdk_C6678_1_1_2_5/packages/ti/drv/qmss/lib/ti.drv.qmss.ae66"
-l"/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo/ti/omp/lib/release/ti.omp.ae66"
-l"/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo/ti/omp/config/sysbios/lib/release/ti.omp.config.sysbios.ae66"
-l"/opt/ti/edma3_lld_02_11_05_02/packages/ti/sdo/edma3/drv/sample/lib/c6678-evm/66/release/edma3_lld_drv_sample.ae66"
-l"/opt/ti/edma3_lld_02_11_05_02/packages/ti/sdo/edma3/drv/lib/66/release/edma3_lld_drv.ae66"
-l"/opt/ti/edma3_lld_02_11_05_02/packages/ti/sdo/edma3/rm/lib/c6678-evm/66/release/edma3_lld_rm.ae66"
-l"/opt/ti/bios_6_33_06_50/packages/ti/sysbios/lib/instrumented_e66/sysbios/sysbios.lib"
-l"/opt/ti/xdctools_3_23_04_60/packages/ti/targets/rts6000/lib/ti.targets.rts6000.ae66"
-l"/opt/ti/xdctools_3_23_04_60/packages/ti/targets/rts6000/lib/boot.ae66"

--retain="*(xdc.meta)"


--args 0x0
-heap  0x0
-stack 0x1000

MEMORY
{
    MSMCSRAM (RWX) : org = 0xc000000, len = 0x300000
    L1DSRAM (RW) : org = 0xf00000, len = 0x4000
    L2SRAM (RWX) : org = 0x800000, len = 0x60000
    DDR3 (RWX) : org = 0x80000000, len = 0x20000000
    MSMCSRAM_NOCACHE (RWX) : org = 0xa0300000, len = 0x100000
    MSMCSRAM_CACHE (RWX) : org = 0xc300000, len = 0x100000
}

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from ti.targets.elf (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from ti.targets.rts6000 (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from ti.sysbios (null): */

/* Content from xdc.services.getset (null): */

/* Content from ti.sdo.edma3.rm (null): */

/* Content from ti.sdo.edma3.drv (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sdo.edma3.drv.sample (null): */

/* Content from ti.sysbios.family.c66 (null): */

/* Content from ti.sysbios.family.c64p (null): */

/* Content from ti.sysbios.family.c66.tci66xx (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sdo.ipc.interfaces (null): */

/* Content from ti.sysbios.syncs (null): */

/* Content from ti.sdo.ipc.family (null): */

/* Content from ti.sdo.utils (null): */

/* Content from ti.omp.config.sysbios (null): */

/* Content from ti.omp (ti/omp/linkcmd.xdt): */


SECTIONS
{
    /* 
     *  If building on C66x devices and if the codeMemory and dataMemory aren't
     *  the same segment we need to load the .neardata and .fardata (non-const
     *  initialized near/far global variables) into codeMemory and run from
     *  dataMemory.  This is because dataMemory isn't guaranteed to be writable
     *  by the loader at boot-time: it could be a non-cached MSMC alias in
     *  case it is made available only after the alias as been created at
     *  startup-time. 
     */


    /* 
     *  The .far & .fardata sections of the RTSC genenerated 'C' file (appname)
     *  and the RTS libraries (*rts*.lib) consist of global variables that must
     *  be local to each core.  These sections are therefore placed in the
     *  'Program.platform.stackMemory' segment which is required to be set to
     *  memory local to each core.
     */
    .localfar :
    {
        "app_pe66.oe66" (.far)
        "*rts*.lib" (.far)
        "app_pe66.oe66" (.fardata)
        "*rts*.lib" (.fardata)
    } > L2SRAM


    /*
     * Place the TLS sections to avoid warnings from the linker related to
     * defailt placement.
     */
    .TI.tls         >   MSMCSRAM
    .TI.tls_init    >   MSMCSRAM

}
SECTIONS
{
    gomp_data                load       >> MSMCSRAM_NOCACHE
    .Nav_init	     load 	>> L2SRAM	
    .init_array: 	     load 	>> L2SRAM
    .qmss: 		     load 	>> MSMCSRAM_NOCACHE
    .shareddata:	     load	>> MSMCSRAM_NOCACHE
    .cppi: 		     load 	>> MSMCSRAM
}

/* Content from ti.sysbios.timers.timer64 (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.family.c62 (null): */

/* Content from ti.sysbios.family.c64p.tci6488 (null): */

/* Content from ti.drv.qmss (null): */

/* Content from ti.drv.cppi (null): */

/* Content from ti.csl (null): */

/* Content from ti.omp.navigator (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.platforms.generic (null): */

/* Content from evmc6678Omp (null): */

/* Content from ti.sdo.ipc.family.c647x (null): */

/* Content from ti.sdo.ipc.notifyDrivers (null): */

/* Content from ti.sdo.ipc (ti/sdo/ipc/linkcmd.xdt): */

SECTIONS
{
    ti.sdo.ipc.SharedRegion_0:  { . += 0x80000;} run > 0xa0300000, type = NOLOAD
    ti.sdo.ipc.SharedRegion_2:  { . += 0x1000000;} run > 0x90000000, type = NOLOAD
}


/* Content from ti.sdo.ipc.heaps (null): */

/* Content from ti.sdo.ipc.transports (null): */

/* Content from ti.sdo.ipc.nsremote (null): */

/* Content from ti.omp.utils (null): */

/* Content from ti.sdo.ipc.gates (null): */

/* Content from configPkg (null): */


/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;
TSK_idle = ti_sysbios_knl_Task_Object__table__V + 0;

SECTIONS
{
    .text: load >> MSMCSRAM
    .ti.decompress: load > MSMCSRAM
    .stack: load > L2SRAM
    GROUP: load > MSMCSRAM
    {
        .bss:
        .neardata:
        .rodata:
    }
    .cinit: load > MSMCSRAM
    .pinit: load >> MSMCSRAM
    .init_array: load > MSMCSRAM
    .const: load >> MSMCSRAM
    .data: load >> MSMCSRAM
    .fardata: load >> MSMCSRAM
    .switch: load >> MSMCSRAM
    .sysmem: load > L2SRAM
    .far: load >> MSMCSRAM
    .args: load > L2SRAM align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> L2SRAM
    .ti.handler_table: load > MSMCSRAM
    ddr: load >> DDR3
    .vecs: load >> MSMCSRAM
    .text:_c_int00: load >> MSMCSRAM align = 0x400
    .tls_tp: load >> L2SRAM
    xdc.meta: load >> MSMCSRAM, type = COPY

}
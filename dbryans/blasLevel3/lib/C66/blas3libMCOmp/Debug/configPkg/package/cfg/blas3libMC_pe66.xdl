/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"C:\ti\delivered\blasLevel3\lib\C66\blas3libMCOmp\Debug\configPkg\package\cfg\blas3libMC_pe66.oe66"
-l"C:\ti\pdk_C6678_1_1_0_2\packages\ti\csl\lib\ti.csl.ae66"
-l"C:\ti\bios_6_33_04_39\packages\ti\sysbios\lib\instrumented_e66\sysbios\sysbios.lib"
-l"C:\ti\xdctools_3_23_03_53\packages\ti\targets\rts6000\lib\ti.targets.rts6000.ae66"
-l"C:\ti\xdctools_3_23_03_53\packages\ti\targets\rts6000\lib\boot.ae66"

--retain="*(xdc.meta)"


--args 0x0
-heap  0x0
-stack 0x8000

MEMORY
{
    L2SRAM : org = 0x800000, len = 0x80000
    DDR3 : org = 0x80000000, len = 0x20000000
    MSMCSRAM : org = 0xc000000, len = 0x100000
    MSMCSRAM_NOCACHE : org = 0xa0100000, len = 0x300000
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

/* Content from ti.csl (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.family.c66 (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.c64p (null): */

/* Content from ti.sysbios.family.c66.tci66xx (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.family.c62 (null): */

/* Content from ti.sysbios.timers.timer64 (null): */

/* Content from ti.sysbios.family.c64p.tci6488 (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.platforms.generic (null): */

/* Content from ti.omp.examples.platforms.evm6678 (null): */

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
    GROUP: load > MSMCSRAM_NOCACHE
    {
        .bss:
        .neardata:
        .rodata:
    }
    .cinit: load > MSMCSRAM_NOCACHE
    .pinit: load >> MSMCSRAM_NOCACHE
    .init_array: load > MSMCSRAM_NOCACHE
    .const: load >> MSMCSRAM_NOCACHE
    .data: load >> MSMCSRAM_NOCACHE
    .fardata: load >> MSMCSRAM_NOCACHE
    .switch: load >> MSMCSRAM_NOCACHE
    .sysmem: load > MSMCSRAM_NOCACHE
    .far: load >> MSMCSRAM_NOCACHE
    .args: load > MSMCSRAM_NOCACHE align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> MSMCSRAM_NOCACHE
    .ti.handler_table: load > MSMCSRAM_NOCACHE
    l2Heap: load >> L2SRAM
    l1Heap: load >> L1DSRAM
    msmcHeap0: load >> MSMCSRAM
    msmcHeap1: load >> MSMCSRAM
    msmcHeap2: load >> MSMCSRAM
    msmcHeap3: load >> MSMCSRAM
    msmcHeap4: load >> MSMCSRAM
    msmcHeap5: load >> MSMCSRAM
    msmcHeap6: load >> MSMCSRAM
    msmcHeap7: load >> MSMCSRAM
    .dmaMem: load >> MSMCSRAM_NOCACHE
    .vecs: load >> MSMCSRAM
    xdc.meta: load >> MSMCSRAM_NOCACHE, type = COPY

}

/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/bilinear_omp/Release/configPkg/package/cfg/omp_config_pe66.oe66"
-l"/opt/ti/bios_6_34_02_18/packages/ti/sysbios/lib/sysbios/instrumented/sysbios.ae66"
-l"/opt/ti/xdctools_3_24_05_48/packages/ti/targets/rts6000/lib/ti.targets.rts6000.ae66"
-l"/opt/ti/xdctools_3_24_05_48/packages/ti/targets/rts6000/lib/boot.ae66"

--retain="*(xdc.meta)"


--args 0x0
-heap  0x0
-stack 0x1000

MEMORY
{
    L2SRAM (RWX) : org = 0x800000, len = 0x40000
    MSMCSRAM (RWX) : org = 0xc000000, len = 0x400000
    DDR3 (RWX) : org = 0x80000000, len = 0x20000000
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

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.family.c66 (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.c64p (null): */

/* Content from ti.sysbios.family.c66.tci66xx (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.family.c62 (null): */

/* Content from ti.sysbios.timers.timer64 (null): */

/* Content from ti.sysbios.family.c64p.tci6488 (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.platforms.generic (null): */

/* Content from evmc6678sc (null): */

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
    .stack: load > MSMCSRAM
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
    .sysmem: load > MSMCSRAM
    .far: load >> MSMCSRAM
    .args: load > MSMCSRAM align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> MSMCSRAM
    .ti.handler_table: load > MSMCSRAM
    .vecs: load >> MSMCSRAM
    xdc.meta: load >> MSMCSRAM, type = COPY

}

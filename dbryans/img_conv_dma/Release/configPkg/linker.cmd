/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/img_conv_dma/Release/configPkg/package/cfg/img_conv_dma_pe66.oe66"
-l"/opt/ti/edma3_lld_02_11_05_02/packages/ti/sdo/edma3/drv/sample/lib/c6678-evm/66/release/edma3_lld_drv_sample.ae66"
-l"/opt/ti/edma3_lld_02_11_05_02/packages/ti/sdo/edma3/drv/lib/66/release/edma3_lld_drv.ae66"
-l"/opt/ti/edma3_lld_02_11_05_02/packages/ti/sdo/edma3/rm/lib/c6678-evm/66/release/edma3_lld_rm.ae66"
-l"/opt/ti/bios_6_34_02_18/packages/ti/sysbios/lib/sysbios/instrumented/sysbios.ae66"
-l"/opt/ti/xdctools_3_24_05_48/packages/ti/targets/rts6000/lib/ti.targets.rts6000.ae66"
-l"/opt/ti/xdctools_3_24_05_48/packages/ti/targets/rts6000/lib/boot.ae66"

--retain="*(xdc.meta)"


--args 0x0
-heap  0x0
-stack 0x1000

MEMORY
{
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

/* Content from ti.sdo.edma3.rm (null): */

/* Content from ti.sdo.edma3.drv (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sdo.edma3.drv.sample (null): */

/* Content from ti.sysbios.family.c66 (null): */

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

/* Content from emvc6678sc_ddr (null): */

/* Content from configPkg (null): */


/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;
TSK_idle = ti_sysbios_knl_Task_Object__table__V + 0;

SECTIONS
{
    .text: load >> DDR3
    .ti.decompress: load > DDR3
    .stack: load > DDR3
    GROUP: load > DDR3
    {
        .bss:
        .neardata:
        .rodata:
    }
    .cinit: load > DDR3
    .pinit: load >> DDR3
    .init_array: load > DDR3
    .const: load >> DDR3
    .data: load >> DDR3
    .fardata: load >> DDR3
    .switch: load >> DDR3
    .sysmem: load > DDR3
    .far: load >> DDR3
    .args: load > DDR3 align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> DDR3
    .ti.handler_table: load > DDR3
    .vecs: load >> DDR3
    xdc.meta: load >> DDR3, type = COPY

}

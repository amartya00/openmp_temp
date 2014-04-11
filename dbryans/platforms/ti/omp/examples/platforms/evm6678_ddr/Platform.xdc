metaonly module Platform inherits xdc.platform.IPlatform {

    config ti.platforms.generic.Platform.Instance CPU =
        ti.platforms.generic.Platform.create("CPU", {
            clockRate:      1000,                                       
            catalogName:    "ti.catalog.c6000",
            deviceName:     "TMS320C6678",
            customMemoryMap: [
                ["L2SRAM",   {name: "L2SRAM",    base: 0x00800000, len: 0x00050000, access: "RW"}],
                ["DDR3",     {name: "DDR3",      base: 0x80000000, len: 0x01000000, access: "RX"}],
                ["DDR3_DATA",     {name: "DDR3_DATA",      base: 0x81000000, len: 0x08000000, access: "RW"}],
                ["APP_HEAPOMP",   {name: "APP_HEAPOMP",    base: 0x89000000, len: 0x08000000, access: "RW"}],
                ["MSMCSRAM", {name: "MSMCSRAM",  base: 0x0C000000, len: 0x00100000}],
                ["MSMCSRAM_NOCACHE", {name: "MSMCSRAM_NOCACHE", base: 0xA0100000, len: 0x00300000}],
            ],
            l1DMode:"32k",
            l1PMode:"32k",
            l2Mode:"128k",
    });
    
instance :
    
    override config string codeMemory  = "DDR3";   
    override config string dataMemory  = "DDR3_DATA";
    override config string stackMemory = "L2SRAM";
}

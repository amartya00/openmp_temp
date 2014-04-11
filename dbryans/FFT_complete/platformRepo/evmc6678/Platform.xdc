/*!
 * File generated by platform wizard. DO NOT MODIFY
 *
 */

metaonly module Platform inherits xdc.platform.IPlatform {

    config ti.platforms.generic.Platform.Instance CPU =
        ti.platforms.generic.Platform.create("CPU", {
            clockRate:      1000,                                       
            catalogName:    "ti.catalog.c6000",
            deviceName:     "TMS320C6678",
            externalMemoryMap: 
           [          
                ["DDR3", 
                     {
                        name: "DDR3",
                        base: 0x80000000,                    
                        len: 0x20000000,                    
                        space: "code/data",
                        access: "RWX",
                     }
                ],
           ],
          l2Mode:"128k",
          l1PMode:"32k",
          l1DMode:"32k",

    });
    
instance :
    
    override config string codeMemory  = "DDR3";   
    override config string dataMemory  = "DDR3";                                
    override config string stackMemory = "DDR3";
    
}

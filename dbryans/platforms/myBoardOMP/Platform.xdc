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
 */

metaonly module Platform inherits xdc.platform.IPlatform {

    config ti.platforms.generic.Platform.Instance CPU =
        ti.platforms.generic.Platform.create("CPU", {
            clockRate:      1000,                                       
            catalogName:    "ti.catalog.c6000",
            deviceName:     "TMS320C6678",
            customMemoryMap: [
                ["L2SRAM",  
                      {name: "L2SRAM",    base: 0x00800000, len: 0x00050000, access: "RW"}],
                ["DDR3",    
                      {name: "DDR3",      base: 0x80000000, len: 0x01000000, access: "RX"}],
                ["DDR3_DATA",     
                      {name: "DDR3_DATA",      base: 0x81000000, len: 0x08000000, access: "RW"}],
                ["APP_HEAPOMP",   
                       {name: "APP_HEAPOMP",    base: 0x89000000, len: 0x10000000, access: "RW"}],
                ["MSMCSRAM",
                        {name: "MSMCSRAM",  base: 0x0C000000, len: 0x00100000}],
                ["MSMCSRAM_NOCACHE", 
                        {name: "MSMCSRAM_NOCACHE", base: 0xA0100000, len: 0x00300000}],
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

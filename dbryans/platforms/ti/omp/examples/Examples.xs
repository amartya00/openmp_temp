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
var platforms = ["6670", "6678"];

var ompExamples = {
    "omp_hello" : {
        title: "Hello world example",
        fileList: [
            { path: "omp_hello.c" },
            { path: "omp_config.cfg" },
        ],
        description: "This is a simple 'hello world' example that prints the thread ID for each thread executed. Must be loaded & run on cores 0-3 (4 cores)",
    },
    "omp_matvec" : {
        title: "OpenMP matrix vector multiplication example",
        fileList: [
            { path: "omp_matvec.c" },
            { path: "omp_config.cfg" },
        ],
        description: "This example demonstrates matrix multiplication split onto multiple threads loaded/run on cores 0-3 (4 cores)",
    },
    "omp_uia_example" : {
        title: "Example that demonstrates using UIA with OMP",
        fileList: [
            { path: "omp_uia_example.c" },
            { path: "omp_uia_example.cfg" },
        ],
        description: "This example demonstrates using UIA to analyze an OMP core.  This example should be loaded/run on cores 0-3 (4 cores)",
    },
}


/*
 *  ======== module$meta$init ========
 */
function module$meta$init()
{
    var Examples = xdc.module('ti.omp.examples.Examples');
    
    for each (var platform in platforms) {
        Examples.templateGroupArr.$add({
            id          : "ti.omp.examples.root.c" + platform,
            name        : "C" + platform + " Examples",
            description : "C" + platform + "-specific IPC Examples",
            groups      : ["ti.omp.examples.root"]
        });

        switch(platform) {
            case "6670":
			    var pdk_release = "com.ti.biosmcsdk.pdk.C6670";
				var myTarget = "ti.targets.elf.C66" 
				break;

            case "6678":
			    var pdk_release = "com.ti.biosmcsdk.pdk.C6678L";
                var myTarget = "ti.targets.elf.C66" 
                break;
            default:
                throw("Error\n");    
        }

        for each (var example in ompExamples) {
		   if (example.title.toString().match("UIA"))
		    var tempArray = [ "com.ti.rtsc.SYSBIOS", "com.ti.rtsc.IPC",pdk_release,"com.ti.uia" ];
           else
		    var tempArray = [ "com.ti.rtsc.SYSBIOS", "com.ti.rtsc.IPC",pdk_release];

            Examples.templateArr.$add({
                title: example.title,
                fileList: example.fileList,
                description: example.description,
                buildProfile: "debug",
				compilerBuildOptions: " --omp ",
                platform: "ti.omp.examples.platforms.evm" + platform,
                target:   myTarget,
                isHybrid: true,
                filterArr: [
                    { deviceFamily: "C6000", toolChain: "TI" },
                ],
                requiredProducts: tempArray,
                groups : ["ti.omp.examples.root.c" + platform],
                linkerCommandFile: ""
            });
        }
        
    }
}


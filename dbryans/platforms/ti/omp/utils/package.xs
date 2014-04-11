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
 *  ======== package.xs ========
 */

/*
 *  ======== close ========
 */
function close()
{
    Program.exportModule('ti.omp.utils.SemaphoreMP');
    Program.exportModule('ti.omp.utils.ThreadLocal');
    Program.exportModule('ti.omp.utils.ThreadLocalStorage');
    Program.exportModule('ti.omp.utils.HeapOMP');

    Program.exportModule('ti.sysbios.knl.Task');
    Program.exportModule('ti.sysbios.knl.Semaphore');
    Program.exportModule('ti.sysbios.gates.GateMutex');

    Program.exportModule('ti.sysbios.timers.timer64.Timer');
}

/*
 *  ======== Package.getLibs ========
 *  This function is called when a program's configuration files are
 *  being generated and it returns the name of a library appropriate
 *  for the program's configuration.
 */
function getLibs(prog)
{
    var suffix = prog.build.target.findSuffix(this);
	
    var packageName = "ti.omp.utils";
    
    var ompProfile = "release";
    if (this.profile == "debug") {
        ompProfile = "debug";
    }
   
    if (suffix == null) {
        /* no matching lib found in this package, return "" */
        $trace("Unable to locate a compatible library, returning none.",
                1, ['getLibs']);
        return ("");
    }

    /* the location of the libraries are in lib/<profile> */
    var lib = "lib/" + ompProfile + "/" + packageName + ".a" + suffix;

    /*
     * If the requested profile doesn't exist, we return the 'release' library.
     */
    if (!java.io.File(this.packageBase + lib).exists()) {
        $trace("Unable to locate lib for requested '" + this.profile +
                "' profile.  Using 'release' profile.", 1, ['getLibs']);
        lib = "lib/release/" + packageName + ".a" + suffix;
    }
	/* Target specific library */
	if( String(Program.cpu.deviceName).match("TMS320C6678"))
	{
	   lib += "\;lib/" + ompProfile + "/" + packageName + ".C6678.a" + suffix;

	}
	else if( String(Program.cpu.deviceName).match("TMS320C6670"))
	{
	   lib += "\;lib/" + ompProfile + "/" + packageName + ".C6670.a" + suffix;
	}
	else
	{
	  $trace("Device "+Program.cpu.deviceName+" not supported");
	}

    return (lib);
}

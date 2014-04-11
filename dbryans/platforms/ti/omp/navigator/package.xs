/*
 *  ======== package.xs ========
 *
 *! Revision History
 *! ================
 */


/*
 *  ======== getLibs ========
 */
function getLibs(prog)
{
    var suffix = prog.build.target.findSuffix(this);
    
    var ompProfile = "release";
    if (this.profile == "debug") {
        ompProfile = "debug";
    }

	var packageName="ti.omp.navigator";
   
    if (suffix == null) {
        /* no matching lib found in this package, return "" */
        $trace("Unable to locate a compatible library, returning none.",
                1, ['getLibs']);
        return ("");
    }

    /* the location of the libraries are in lib/<profile>/* */
    var lib = "lib/" + ompProfile + "/"+packageName+".a" + suffix;

    /*
     * If the requested profile doesn't exist, we return the 'release' library.
     */
    if (!java.io.File(this.packageBase + lib).exists()) {
        $trace("Unable to locate lib for requested '" + this.profile +
                "' profile.  Using 'release' profile.", 1, ['getLibs']);
        lib = "lib/release/ti.omp.navigator.a" + suffix;
    }
	OpenMP = xdc.module('ti.omp.utils.OpenMP');
	if(OpenMP.internalOsal == true)
	 lib+="\;lib/" + ompProfile + "/ti.omp.navigatorOsal.a" + suffix;

	
	 /* Platform specific library */
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


/*
 *  ======== package.xs ========
 *
 *! Revision History
 *! ================
 */

/*
 *  ======== getSects ========
 */
function getSects()
{
    return "ti/omp/linkcmd.xdt";
}

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
   
    if (suffix == null) {
        /* no matching lib found in this package, return "" */
        $trace("Unable to locate a compatible library, returning none.",
                1, ['getLibs']);
        return ("");
    }

    /* the location of the libraries are in lib/<profile>/* */
    var lib = "lib/" + ompProfile + "/ti.omp.a" + suffix;

    /*
     * If the requested profile doesn't exist, we return the 'release' library.
     */
    if (!java.io.File(this.packageBase + lib).exists()) {
        $trace("Unable to locate lib for requested '" + this.profile +
                "' profile.  Using 'release' profile.", 1, ['getLibs']);
        lib = "lib/release/ti.omp.a" + suffix;
    }

    return (lib);
}


The following instructions assume that you have installed the files in INSTALL_DIR.

Contents:
INSTALL_DIR/docs: Doxygen documentation. You will find doxygen output at 
                             INSTALL_DIR/docs/doxygen/BLAS3C66.chm or
                             INSTALL_DIR/docs/doxygen/html/index.html
 - INSTALL_DIR/docs: Doxygen documentation.
 - INSTALL_DIR/inc: Header files.
 - INSTALL_DIR/lib/C66/blas3libMCOmp: Precompiled library for multi-core APIs that uses openMP
 - INSTALL_DIR/lib/C66/blas3libSCOmp: Precompiled library for single core API (multi-core ready through openMP).
 - INSTALL_DIR/platformRepo: C6678 platform files used for project.
 - INSTALL_DIR/src/singleCore/dataMove: Different types of data re-arranagements needed by various modules.
 - INSTALL_DIR/src/singleCore/kernels: C66 optimized kernels used in the BLAS implementations.
 - INSTALL_DIR/src/singleCore/x<blas3_function>: Implementation of various single core BLAS level 3 functions.
 - INSTALL_DIR/src/multiCore/x<blas3_function>: Implementation of various multi core BLAS level 3 functions.
 - INSTALL_DIR/src/util: Utility functions for memory, cache and DMA.
 - INSTALL_DIR/test/ccsProj_C6678: CCS 5.2 project definitions.
 - INSTALL_DIR/test/params: Various parameter definitions used in test package.
 - INSTALL_DIR/test/src: Baseline test bench.
 - INSTALL_DIR/test/src/util: Various utilities used by test bench.
 - INSTALL_DIR/test/src/x<blas3_function>: various BLAS level 3 functiona test bench.
 - INSTALL_DIR/test/blas3_param_*.txt: defines parameter files to be used by test benches of various projects.

Supported BLAS Level 3 Functionalities:

        =========================================
        | Level 3 BLAS     |          Types     |
        -----------------------------------------
        |  xGEMM           |    c, d, s, z      |
        -----------------------------------------
        |  xSYMM           |    c, d, s, z      |
        -----------------------------------------
        |  xHEMM           |    c, z            |
        -----------------------------------------
        |  xSYRK           |    c, d, s, z      |
        -----------------------------------------
        |  xHERK           |    c, z            |
        -----------------------------------------
        |  xSYR2K          |    c, d, s, z      |
        -----------------------------------------
        |  xHER2K          |    c, z            |
        -----------------------------------------
        |  xTRMM           |    c, d, s, z      |
        -----------------------------------------
        |  xTRSM           |    c, d, s, z      |
        -----------------------------------------

Both single-core and multi-core APIs are provided. The single core APIs can be distributed across multiple cores through OPENMP pragmas.
The multi-core API uses a pre-defined distribution through openMP pragmas. The test bench
reads a parameter file which contains the list of tests to be performed. Associated with the test is also another parameter
file under the INSTALL_DIR/test/params directory that defines the particular parameters used in the test. A reference output
for each test bench run has also been supplied at INSTALL_DIR/test/params/refResults.

Constrained on the code usage:
The internal kernels compute m_kernel x n_kernel of the output (C) matrix at a time putting some constraints on the sizes of the matrices. 
The values of m_kernel and n_kernel are dependent of data type and are tabulated below

          ===================================
          | type | m_kernel       | n_kernel|  
          -----------------------------------
          |  C    |     2         |     4   |
          -----------------------------------
          |  D    |     4         |     4   |
          -----------------------------------
          |  S    |     4         |     8   |
          -----------------------------------
          |  Z    |     1         |     1   |
           ----------------------------------

The single core will produce correct output for any values of m and n. However, it will write its output in blocks of data size 
m_kernel x n_kernel, thereby modifying some extra values in memory unless the sizes are appropriately chosen. 
Some APis also calculate the transpose of the desired matrix internally and writes it back in original form. 
In addition, to maintain cache coherency across cores, the APIs perform a cache write back after the output is computed. 
The APis also invalidate any other memory that it uses to ensure cache coherency between calls.  The APIs assume column first
memory arrangement of data.

In multi-core application, the matrices are divided into blocks which are operated independently by different cores.
The starting address of all the input/output matrix blocks should be aligned to cache line size. All the columns in the block will also
need to be aligned with cache line size.

In order to guarantee safe operation by all cores, The block sizes should be made a multiple of cache line size of L2 memory (128 bytes).

Before any of the APIs are used, edmaInit() needs to be called to setup the DMA resource. 
This needs to be called only once before any of the APIs are called. edmaClose() can be used to release the DMA resources. 
If the APIs are used as part of a larger program which uses other DMA resources, then DMA resources may need to be adjusted
to avoid conflicts of usage.

For multi-core API, omp_set_num_threads() should be used to set the number of cores/threads to run.

Tools needed:
Code Composer Studio (CCS) 5.2 available at http://processors.wiki.ti.com/index.php/Download_CCS#Code_Composer_Studio_Version_5_Downloads 

BIOS MCSDK 2.1.0.2 beta available for selective engagement (you will be notified where to get it).
The followings are useful documentation for use of BIOS MCSDK:
http://processors.wiki.ti.com/index.php/BIOS_MCSDK_2.0_Getting_Started_Guide, 
http://processors.wiki.ti.com/index.php/BIOS_MCSDK_2.0_User_Guide

Code Generation tool (CGT): version 7.4.0A12012 as distributed with MC SDK 2.1.0.1. Please ensure that the CGT is installed before importing the projects.

The following components of the BIOS MCSDK are used with this project
- EDMA3 LLD: 2.11.05.02 (direct memory access controller driver)
- PDK-6678: 1.1.0.2 (platform development kit)
- IPC: 1.24.02.27 (inter processor communication)
- OMP: 1.01.02.03 beta (opneMP runtime); 

Tokens used in the code:
The following token pre-defines are used in the code. This can be used to turn on or off certain features in the code during compilation.
PROFILE_CYCLES: To enable GFLOPS profiling.
DMA_COPYA: If defined, uses DMA to transfer matrix A between DDR3 memory and internal memory. Otherwise, uses CPU memcpy.
DMA_COPYB: If defined, uses DMA to transfer matrix B between DDR3 memory and internal memory. Otherwise, uses CPU memcpy.
_OPENMP: This will be turned on automatically if the "openMP" compiler feature is turned on in project properties. A non-openMP version only works on core 0.
VERIFICATION: If verification with a reference implementation is desired. Currently, the reference implementation is based on LIBFLAME from University of 
Texas available at http://z.cs.utexas.edu/wiki/flame.wiki/FrontPage/. This package has BLAS in C derived from FORTRAN to C conversion tool. 
There are several places the environment variable LIBFLAME_INSTALL_DIR need to be set. One is in the CCS itself. 
Go to Windows->Preferences->General->Workspace->Linked Resources. If the variable LIBFLAME_INSTALL_DIR is there, edit its value to point to your libflame installation. 
Otherwise, define the new variable LIBFLAME_INSTALL_DIR to point to your libflame installation. The other place is in the project itself. 
Go to project property->biuld->environment. Again, if the variable LIBFLAME_INSTALL_DIR is there, edit its value to point to your libflame installation. 
Otherwise, define the new variable LIBFLAME_INSTALL_DIR to point to your libflame installation. Note that the latter step needs to be done for each project
 that uses the reference code and each configuration (debug and release) for the project. You may need to retstart CCS after these values are set to take these values into effect.

Pre-defined projects:
The following projects are pre-defined in the supplied codebase and can be imported in CCS using CCS->file->import->Code Composer Studio->Existing CCS/CCE Eclipse project.
blas3libMCOmp: to create the libraries for multi-core core APIs; Will require the following single library to build an application
blas3libSCOmp: to create the libraries based on single core APIs (multi-core ready through openMP).
testBlasOmp: Used for multi-core implementation and verification using opneMP.
testBlasOmpNoReference: Used for multi-core core implementation and performance evaluation using openMP; does not use the reference code mentioned above.

Note that in release mode, the GFLOPS profiling and DMA data movements are turned on by default. They are not used in debug mode. 
The configuration files associated with these projects also illustrate the internal memory usage of each core by the APIs.

The projects can be built through CCS. To run the code, launch the evm configuration (see MC-SDK documentation mentioned earlier).

To run the single code, connect core #0 and load the binary on core #0 and run the code.

To run the eight core openMP code, connect core #0 through core #7 (you will find it useful to group these cores so you can connect and load in a single click) and 
load the binary on all the cores (core #0 through #7).  Cores #1 through #7 should be running and you need to start only core #0 manually to produce output.

Using Pre-compiled libraries:
To use the pre-compile library in INSTALL_DIR/lib, follow the project definitions in one of the test projects. Specifically, one needs to
- add the INSTALL_DIR/lib/C66/blas3lib.cfg in the configuration file for the executable project. This file defines the SYSBIOS 
  and memory configurations needed for the best performance. One can use the xdc.loadCapsule comand in configuration file
  as used in the projects.
- add this library for linking in the project.
- add the edma libraries for linking in the project.

Resetting the hardware in CCS:
Sometimes it is useful to reset the hardware specially for abnormal exits from the code.
Follow the following procedure to reset the evm.
reset each core: highlight each core (or group of cores); from CCS, use Run->reset->CPU reset
reset system: highlight core #0, from CCS, use Run->reset->system reset and then 
From CCS, also use Script->EVMC6678L Init Functions->Global_Default_Setup
You can now load the binary as above and rerun the code.

References:
Some of the techniques used in this code base are described in the following references
1. Goto, K. and Van De Geijn, R., "Anatomy of High-Performance Matrix Multiplication," ACM Transactions on Mathematical Software, Vol. 34, No. 3, Article 12, May 2008.
2. Goto, K. and Van De Geijn, R., "High-Performance Implementation of the Level-3 BLAS," ACM Transactions on Mathematical Software, Vol. 35, No. 1, Article 4, July 2008.

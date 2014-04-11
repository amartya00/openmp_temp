This repository contains example code for batch FFT and 2-D FFT processing 
on TI's TMS320C6678 processor. The attached projects are designed to work 
with TI's IDE (code composer stuido or CCS) and C6678EVM.

Tools needed:
=============
Code Composer Studio (CCS) 5.2 available at 
http://processors.wiki.ti.com/index.php/Download_CCS#Code_Composer_Studio_Version_5_Downloads 

BIOS MCSDK 2.1.0.3 available at 
http://software-dl.ti.com/sdoemb/sdoemb_public_sw/bios_mcsdk/02_01_00_03/index_FDS.html. 

The followings are useful documentation for use of BIOS MCSDK:
http://processors.wiki.ti.com/index.php/BIOS_MCSDK_2.0_Getting_Started_Guide, 
http://processors.wiki.ti.com/index.php/BIOS_MCSDK_2.0_User_Guide

Code Generation tool (CGT): version 7.4.0 available at 
https://www-a.ti.com/downloads/sds_support/TICodegenerationTools/download.htm. 
Please ensure that the CGT is installed before importing the projects.

The following components of the BIOS MCSDK are used with this project
- EDMA3 LLD: 2.11.05.02 (direct memory access controller driver)
- PDK-6678: 1.1.0.3 (platform development kit)
- IPC: 1.24.02.27 (inter processor communication)
- OMP: 1.01.02.06 (opneMP runtime); 
- DSPLIB: 3.1.0.0 (for FFT and transpose functions)

Tokens used in the code:
========================
The following token pre-defines are used in the code. This can be used to turn on or off 
certain features in the code during compilation.

PROFILE_CYCLES: To enable cycle profiling or benchmarking.

NETIO: This token is used on faster data transfer using the tftp protocol 
and Ethernet port and is used for transferring large files. Without this token, 
The code will read data over USB/JTAG port which limits the speed of file I/O.

_OPENMP: This will be turned on automatically if the "openMP" compiler feature is 
turned on in project properties (--openmp flag in the compiler). 
A non-openMP version only works on core 0.

Pre-defined projects:
=====================
The following projects are pre-defined (for the FFT testbench) in the supplied codebase and 
can be imported in CCS using CCS->file->import->Code Composer Studio->Existing CCS/CCE Eclipse project.

testFFT: uses openMP to run across parallel cores; uses fread/dwrite for file I/O.

testFFTNet: uses openMP to run across parallel cores; uses tftp protocol 
and Ethernet port for transferring files.

testFFTNetNOOMP: Runs on single core without openMP; uses tftp protocol 
and Ethernet port for transferring files.

The projects can be built through CCS. To run the code, launch the evm configuration (see MC-SDK documentation mentioned earlier).

Running the code:
=================
To run the single code (for project testFFTNetNOOMP), connect core #0 and 
load the binary on core #0 and run the code.

To run the openMP code (for projects testFFT and testFFTNET), follow the following procedure
- group core#0 into group #1; group cores #1 through #7 into group #2
- connect group #1 (core #0 only); do not connect the cores in group 2
- perform a soft reset on core #0:
This can be done by highlighting core #0 and following Run->reset->system reset.
This needs to be done everytime the code is run; otherwise, the ethernet port
will not be configured properly
- load the symbols on the cores in group #2 (cores #1 through #7)
- load the binary on group # 1 (core #0)
- run the code from group #1;

Using the tftp protocol and Ethernet port for transferring large file
=====================================================================
This method has only been tested on windows based systems.
Since transferring large files using fwrite and fread over USB/JTAG is slow,
an alternate mechanism has been created using Ethernet and tftp protocol.
The code in the netio directories can create a networking task and then run
tftp server on the board. This has been setup to operate using the
following procesdure
- The PC IP needs to be set static at 128.168.2.101. THE EVM IP is
set at 128.168.2.100. 
- Connect the ethernet port of the EVM to the ethernet port of PC
using cat5e wire.
- Sometimes, other connectivity like WLAN intereferes and in that case, 
disable WLAN.
- Sometimes, the firewall prevents data transfer and in that case, 
disbale the firewall.
- Run a tftp server on the PC. The code has been tested with the tftp32
server on windows available at http://tftpd32.jounin.net/
- Set the "current directory" of the tftp server to point to 
"INSTALL_DIR/test". The file names to be transferred are set to be relative
to this directory.
- Now run the code using procedure mentioned above.


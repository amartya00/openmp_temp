/*
 * Copyright (C) 2009-2011 Texas Instruments Incorporated - http://www.ti.com/
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

/*
 *   @file  netStart.c  
 *
 *   @brief   
 *      this application sets up the EVM as an HTTP server allowing various
 *  		DSP applications to show visual results via standard Web browser.
 *			The application can be flashed on EVMs with FLASH memories.
 *
 */
 
/*--------------------------------------------------------------------------
 * Adapted from High Performance DSP Utility Application
 *--------------------------------------------------------------------------*/

#include "netStart.h"
#include "../netStaticIp.h"

#include <ti/sysbios/knl/Semaphore.h>
#include <xdc/runtime/System.h>
#include <ti/csl/csl_cacheAux.h>

#include "resource_mgr.h"

/**************************************************************************
**  Local Typedef Declarations
***************************************************************************/

#define STATICIP   0
#define DHCPSERVER 1
#define DHCPCLIENT 2

/**************************************************************************
**  Build options
***************************************************************************/

/* define to include telnet */
#undef	INCLUDE_TELNET_SERVICE
//#define	INCLUDE_TELNET_SERVICE

/**************************************************************************
** IP Stack - NDK Routines
***************************************************************************/

/* Our NETCTRL callback functions */
static void   NetworkOpen();
static void   NetworkClose();
static void   NetworkIPAddr( IPN IPAddr, uint32_t IfIdx, uint32_t fAdd );

/*  Reporting function - IP stack calls it to give us updates */
static void   ServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, HANDLE hCfgEntry );

/**************************************************************************
** Configuration
****************************************************************************/

char  HostName[CFG_HOSTNAME_MAX];		// Host name we will use in a DHCP Request
char *LocalIPAddr = "0.0.0.0";          // Set to "0.0.0.0" for DHCP client option
char *PCStaticIP  = PCSTATIC_IP_ADDRESS;    // Static IP address for host PC
char *EVMStaticIP = EVMSTATIC_IP_ADDRESS;  //    "   IP     "   for EVM
char *LocalIPMask = "255.255.255.0";    // Mask for DHCP Server option
char *GatewayIP   = "0.0.0.0";    // Not used when using DHCP
char *DomainName  = "demo.net";         // Not used when using DHCP
char *DNSServer   = "0.0.0.0";          // Used when set to anything but zero

HANDLE            hCfg;					// Handle to our IP stack configuration

#ifdef INCLUDE_TELNET_SERVICE
CI_SERVICE_TELNET telnet;				// Configuration data for telnet including handle
#endif
CI_SERVICE_HTTP   http;					// Configuration data for http including handle
CI_SERVICE_DHCPC dhcpservice;			// Configuration data for dhcp client including handle
    
uint8_t DHCP_OPTIONS[] = { DHCPOPT_SERVER_IDENTIFIER, DHCPOPT_ROUTER };

/* Status of the call to initialize the platform */
int32_t pform_status;

/* Holds information about the Platform we are running on */
platform_info	gPlatformInfo;

extern  int32_t res_mgr_init_qmss_global(uint32_t max_num_desc);

/*************************************************************************
 *  @b EVM_init()
 * 
 *  @n
 *  Initializes the platform hardware. This routine is configured to start in 
 * 	the evm.cfg configuration file. It is the first routine that BIOS 
 * 	calls and is executed before Main is called. If you are debugging within
 *  CCS the default option in your target configuration file may be to execute 
 *  all code up until Main as the image loads. To debug this you should disable
 *  that option. 
 *
 *  @param[in]  None
 * 
 *  @retval
 *      None
 ************************************************************************/
void EVM_init()
{
	platform_init_flags  	sFlags;
	platform_init_config 	sConfig;
    
    if (platform_get_coreid() != 0) {
        return;
    }

	/* 
	 * You can choose what to initialize on the platform by setting the following 
	 * flags. Things like the DDR, PLL, etc should have been set by the boot loader.
	*/
	memset( (void *) &sFlags,  0, sizeof(platform_init_flags));
	memset( (void *) &sConfig, 0, sizeof(platform_init_config));
 	
	sFlags.pll  = 0;	/* PLLs for clocking  	*/
	sFlags.ddr  = 0;   	/* External memory 		*/
    sFlags.tcsl = 1;	/* Time stamp counter 	*/
    sFlags.phy  = 1;	/* Ethernet 			*/
  	sFlags.ecc  = 0;	/* Memory ECC 			*/

    sConfig.pllm = 0;	/* Use libraries default clock divisor */
 
	pform_status = platform_init(&sFlags, &sConfig);
	
	/* If we initialized the platform okay */
	if (pform_status != Platform_EOK) {
		/* Initialization of the platform failed... die */
		platform_write("Platform failed to initialize. Error code %d \n", pform_status);
		platform_write("We will die in an infinite loop... \n");		
		while (1) {
			(void) platform_led(1, PLATFORM_LED_ON, PLATFORM_USER_LED_CLASS);
			(void) platform_delay(50000);
			(void) platform_led(1, PLATFORM_LED_OFF, PLATFORM_USER_LED_CLASS);
			(void) platform_delay(50000);     
		}
	}

	return;
}

#define MAX_NUM_DESC_OTHER 1024

// Initialize QMSS to run this application:
void lld_init(void)
{
    QMSS_CFG_T      qmss_cfg;

    /* Initialize QMSS */
    if (platform_get_coreid() == 0)
    {
        qmss_cfg.master_core        = 1;
    }
    else
    {
        return;
    }

    res_mgr_init_qmss_global (MAX_NUM_DESC_OTHER + MAX_NUM_DESC);

    qmss_cfg.max_num_desc       = MAX_NUM_DESC;
    qmss_cfg.desc_size          = MAX_DESC_SIZE;
    qmss_cfg.mem_region         = Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED;
    if (res_mgr_init_qmss (&qmss_cfg) != 0)
    {
        goto close_n_exit;
    }

close_n_exit:
   // data cache invalidate from master core
   CACHE_wbInvAllL1d(CACHE_WAIT);
   CACHE_wbInvAllL2(CACHE_WAIT);
    return;
}

/*************************************************************************
 *  @b netStart()
 *
 *  @n
 *  	
 *  This is the main task for the application.  It will configure and 
 *  start the IP Stack along with our services such as HTTP, DHCP and 
 * 	Telnet. This thread is configured to start in evm.cfg configuration 
 * 	file and it is called from BIOS.
 *
 *  @param[in]  None
 * 
 *  @retval
 *      None
 ************************************************************************/
int netStart()
{
    int32_t         rc;
    uint32_t		i, j;
    CPPI_CFG_T      cppi_cfg;
#if 1

	/* Get information about the platform so we can use it in various places */
	memset( (void *) &gPlatformInfo, 0, sizeof(platform_info));
	(void) platform_get_info(&gPlatformInfo);

	(void) platform_uart_init();
	(void) platform_uart_set_baudrate(115200);
	(void) platform_write_configure(PLATFORM_WRITE_PRINTF);

	/* Clear the state of the User LEDs to OFF */
	for (i=0; i < gPlatformInfo.led[PLATFORM_USER_LED_CLASS].count; i++) {
		(void) platform_led(i, PLATFORM_LED_OFF, PLATFORM_USER_LED_CLASS);
	}

#endif

	// Initialize the components required to run this application:
    //  (1) CPPI
    //  (2) Packet Accelerator
    //
    // Initialize CPPI
    if (platform_get_coreid() == 0)
    {
        cppi_cfg.master_core        = 1;
    }
    else
    {
        cppi_cfg.master_core        = 0;
    }
    cppi_cfg.dma_num            = Cppi_CpDma_PASS_CPDMA;
    cppi_cfg.num_tx_queues      = NUM_PA_TX_QUEUES;
    cppi_cfg.num_rx_channels    = NUM_PA_RX_CHANNELS;
    if (res_mgr_init_cppi (&cppi_cfg) != 0)
    {
        platform_write ("Failed to initialize CPPI subsystem \n");
        goto main_exit;
    }
    else
    {
    	platform_write ("CPPI successfully initialized \n");
    }


    if (res_mgr_init_pass()!= 0) {
        platform_write ("Failed to initialize the Packet Accelerator \n");
        goto main_exit;
    }
    else
    {
    	platform_write ("PA successfully initialized \n");
    }

	/* Start the NDK stack - The stack will start the Ethernet driver */
 	rc = NC_SystemOpen( NC_PRIORITY_HIGH, NC_OPMODE_INTERRUPT );

    if( rc ) {
        platform_write("NC_SystemOpen Failed (%d). Will die in an infinite loop so you need to reset...\n",rc);
        for(;;);
    }

    /* Print out application's banner on CCS console */
    platform_write("TI NDK SETUP\n");

    /*
     * Create and build the system configuration from scratch.
    */

    /* Create a new configuration */
    hCfg = CfgNew();
    if( !hCfg )
    {
        platform_write("Unable to create configuration\n");
        goto main_exit;
    }

    /* Create our host name: Its board name + last 6 digits of the serial number.
     * Since the serial number is in I2C it can be altered or even not there so
     * we have to take into account that it may not be what we expect.
     */
    strcpy (HostName, "SAR_Demo");
    i = strlen(HostName);
    j = strlen(gPlatformInfo.serial_nbr);

    if (j > 0) {
    	if (j > 6) {
    		memcpy (&HostName[i], &gPlatformInfo.serial_nbr[j-6], 6);
    		HostName[i+7] = '\0';
    	}
    	else {
    		memcpy (&HostName[i], gPlatformInfo.serial_nbr, j);
    		HostName[i+j+1] = '\0';
    	}
    }
    
    /* Validate the length of the supplied names */
    if( strlen( DomainName ) >= CFG_DOMAIN_MAX ||
        strlen( HostName ) >= CFG_HOSTNAME_MAX )
    {
        platform_write("Domain or Host Name too long\n");
        goto main_exit;
    }

    platform_write("Setting hostname to %s \n", HostName);

    platform_write("MAC Address: %02X-%02X-%02X-%02X-%02X-%02X \n",
        	gPlatformInfo.emac.efuse_mac_address[0], gPlatformInfo.emac.efuse_mac_address[1],
        	gPlatformInfo.emac.efuse_mac_address[2], gPlatformInfo.emac.efuse_mac_address[3],
        	gPlatformInfo.emac.efuse_mac_address[4], gPlatformInfo.emac.efuse_mac_address[5]);

    /* Add our global hostname to hCfg (to be claimed in all connected domains) */
    CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_DHCP_HOSTNAME, 0,
                 strlen(HostName), (uint8_t *)HostName, 0 );

  	/* 
  	** Read User SW 1 
  	** If user SW 1 = OFF position: static IP mode (default), SW 1 = ON: client mode
  	*/
    if (!platform_get_switch_state(1)) {

   		CI_IPNET NA;
        CI_ROUTE RT;
        IPN      IPTmp;

        /* Setup an IP address to this EVM */
        bzero( &NA, sizeof(NA) );
        NA.IPAddr  = inet_addr(EVMStaticIP);
        NA.IPMask  = inet_addr(LocalIPMask);
        strcpy( NA.Domain, DomainName );
        
        /* Add the address to interface 1 */
        CfgAddEntry( hCfg, CFGTAG_IPNET, 1, 0, sizeof(CI_IPNET), (uint8_t *)&NA, 0 );

        /* Add the default gateway (back to user PC) */
        bzero( &RT, sizeof(RT) );
        RT.IPDestAddr = inet_addr(PCStaticIP);
        RT.IPDestMask = inet_addr(LocalIPMask);
        RT.IPGateAddr = inet_addr(GatewayIP);
 
        /* Add the route */
        CfgAddEntry( hCfg, CFGTAG_ROUTE, 0, 0, sizeof(CI_ROUTE), (uint8_t *)&RT, 0 );

        /* Manually add the DNS server when specified */
        IPTmp = inet_addr(DNSServer);
        if( IPTmp )
            CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_DHCP_DOMAINNAMESERVER,
                         0, sizeof(IPTmp), (uint8_t *)&IPTmp, 0 );
                         
		platform_write("EVM in StaticIP mode at %s\n",EVMStaticIP);
		platform_write("Set IP address of PC to %s\n", PCStaticIP);                                           
    }
    else {
        platform_write("Configuring DHCP client\n");
        
        bzero( &dhcpservice, sizeof(dhcpservice) );
        dhcpservice.cisargs.Mode   = CIS_FLG_IFIDXVALID;
        dhcpservice.cisargs.IfIdx  = 1;
        dhcpservice.cisargs.pCbSrv = &ServiceReport;
        dhcpservice.param.pOptions = DHCP_OPTIONS;
        dhcpservice.param.len = 2;
        CfgAddEntry( hCfg, CFGTAG_SERVICE, CFGITEM_SERVICE_DHCPCLIENT, 0,
                     sizeof(dhcpservice), (uint8_t *)&dhcpservice, &(dhcpservice.cisargs.hService) );
    }

#ifdef INCLUDE_TELNET_SERVICE
    /* Specify TELNET service */
    bzero( &telnet, sizeof(telnet) );
    telnet.cisargs.IPAddr = INADDR_ANY;
    telnet.cisargs.pCbSrv = &ServiceReport;
    telnet.param.MaxCon   = 2;
    telnet.param.Callback = &ConsoleOpen;
    CfgAddEntry( hCfg, CFGTAG_SERVICE, CFGITEM_SERVICE_TELNET, 0,
                 sizeof(telnet), (uint8_t *)&telnet, &(telnet.cisargs.hService) );
#endif

    /* Create RAM based WEB files for HTTP */
    //AddWebFiles();

    /* Specify HTTP service */
    bzero( &http, sizeof(http) );
    http.cisargs.IPAddr = INADDR_ANY;
    http.cisargs.pCbSrv = &ServiceReport;
    CfgAddEntry( hCfg, CFGTAG_SERVICE, CFGITEM_SERVICE_HTTP, 0,
                 sizeof(http), (uint8_t *)&http, &(http.cisargs.hService) );

    /*
    ** Configure IPStack/OS Options
    */

    /* Set debug message level */
    rc = DBG_WARN;
    CfgAddEntry( hCfg, CFGTAG_OS, CFGITEM_OS_DBGPRINTLEVEL,
                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

    /*
    ** This code sets up the TCP and UDP buffer sizes
    ** (Note 8192 is actually the default. This code is here to
    ** illustrate how the buffer and limit sizes are configured.)
    */

    /* TCP Transmit buffer size */
    rc = 1024;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPTXBUF,
                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

    /* TCP Receive buffer size (copy mode) */
    rc = 1024;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPRXBUF,
                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

    /* TCP Receive limit (non-copy mode) */
    rc = 1024;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPRXLIMIT,
                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

    /* UDP Receive limit */
    rc = 1024;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKUDPRXLIMIT,
                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

#if 0
    /* TCP Keep Idle (10 seconds) */
    rc = 100;
    /*   This is the time a connection is idle before TCP will probe */
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_TCPKEEPIDLE,
                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

    /* TCP Keep Interval (1 second)
       This is the time between TCP KEEP probes */
    rc = 10;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_TCPKEEPINTVL,
                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

    /* TCP Max Keep Idle (5 seconds)
       This is the TCP KEEP will probe before dropping the connection */
    rc = 50;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_TCPKEEPMAXIDLE,
                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );
#endif

    /*
    ** Boot the system using this configuration
    **
    ** We keep booting until the function returns 0. This allows
    ** us to have a "reboot" command.
    */

    do
    {
        rc = NC_NetStart( hCfg, NetworkOpen, NetworkClose, NetworkIPAddr );
    } while( rc > 0 );

	platform_write("Done with this utility. Shutting things down\n");
 
	/* Free the WEB files */
    //RemoveWebFiles();


    /* Delete Configuration */
    CfgFree( hCfg );

    /*  Close the OS */
main_exit:
	platform_write("Exiting the system\n");
    NC_SystemClose();
    return(0);
}

void netClose()
{
  NC_SystemClose();
}
/*************************************************************************
 *  @b NetworkOpen()
 *
 *  @n
 *  	
 *  This function is called after the Network stack has started..
 *
 *  @param[in]  None
 * 
 *  @retval
 *      None
 ************************************************************************/
static void NetworkOpen()
{
	extern Semaphore_Handle gSemNetIfSync;
    /* Create our local servers */
    
    System_printf("NetworkOpen()\n");
    Semaphore_post( gSemNetIfSync );
    return;
}

/*************************************************************************
 *  @b NetworkClose()
 *
 *  @n
 * 
 *  This function is called when the network is shutting down,
 * 	or when it no longer has any IP addresses assigned to it.
 *
 *  @param[in]  None
 * 
 *  @retval
 *      None
 ************************************************************************/
static void NetworkClose()
{
#ifdef INCLUDE_TELNET_SERVICE
    /* Kill any active console */
    ConsoleClose();
#endif

	return;
}

/*************************************************************************
 *  @b NetworkIPAddr( IPN IPAddr, uint IfIdx, uint fAdd )
 *
 *  @n
 * 
 *  This function is called whenever an IP address binding is
 *  added or removed from the system.
 *
 *  @param[in] 
 * 	IPAddr - The IP address we are adding or removing.
 * 
 *  @param[in] 
 * 	IfIdx - Interface index (number). Used for multicast.
 * 
 *  @param[in] 
 * 	fAdd -  True if we added the interface, false if its being removed.
 * 
 *  @retval
 *      None
 ************************************************************************/

static void NetworkIPAddr( IPN IPAddr, uint32_t IfIdx, uint32_t fAdd )
{
    static uint32_t fAddGroups = 0;
    IPN 			IPTmp;

    if( fAdd )
        platform_write("Network Added: ");
    else
        platform_write("Network Removed: ");

    /* Print a message */
    IPTmp = ntohl( IPAddr );
    platform_write("If-%d:%d.%d.%d.%d \n", IfIdx,
            (uint8_t)(IPTmp>>24)&0xFF, (uint8_t)(IPTmp>>16)&0xFF,
            (uint8_t)(IPTmp>>8)&0xFF, (uint8_t)IPTmp&0xFF );


    /* This is a good time to join any multicast group we require */
    if( fAdd && !fAddGroups )
    {
        fAddGroups = 1;
/*      IGMPJoinHostGroup( inet_addr("224.1.2.3"), IfIdx ); */
    }   

	return;
}

/*************************************************************************
 *  @b DHCP_reset( uint IfIdx, uint fOwnTask )
 *
 *  @n
 * 
 *  This function is called whenever an IP address binding is
 *  added or removed from the system.
 *
 *  @param[in] 
 * 	IfIdx - Interface index (number) that is using DHCP. 
 * 
 *  @param[in] 
 * 	fOwnTask -  Set when called on a new task thread (via TaskCreate()).
 * 
 *  @retval
 *      None
 ************************************************************************/
void DHCP_reset( uint32_t IfIdx, uint32_t fOwnTask )
{
    CI_SERVICE_DHCPC dhcpc;
    HANDLE 			h;
    int32_t    		rc,tmp;
    uint32_t   		idx;

    /* If we were called from a newly created task thread, allow
       the entity that created us to complete */
    if( fOwnTask ) {
        TaskSleep(500);
    }
 
    /* Find DHCP on the supplied interface */
    for(idx=1; ; idx++)
    {
        /* Find a DHCP entry */
        rc = CfgGetEntry( 0, CFGTAG_SERVICE, CFGITEM_SERVICE_DHCPCLIENT,
                          idx, &h );
        if( rc != 1 )
            goto RESET_EXIT;

        /* Get DHCP entry data */
        tmp = sizeof(dhcpc);
        rc = CfgEntryGetData( h, &tmp, (uint8_t *)&dhcpc );

        /* If not the right entry, continue */
        if( (rc<=0) || dhcpc.cisargs.IfIdx != IfIdx )
        {
            CfgEntryDeRef(h);
            h = 0;
            continue;
        }

        /* This is the entry we want! */

        /* Remove the current DHCP service */
        CfgRemoveEntry( 0, h );

        /* Specify DHCP Service on specified IF */
        bzero( &dhcpc, sizeof(dhcpc) );
        dhcpc.cisargs.Mode   = CIS_FLG_IFIDXVALID;
        dhcpc.cisargs.IfIdx  = IfIdx;
        dhcpc.cisargs.pCbSrv = &ServiceReport;
        CfgAddEntry( 0, CFGTAG_SERVICE, CFGITEM_SERVICE_DHCPCLIENT, 0,
                     sizeof(dhcpc), (uint8_t *)&dhcpc, 0 );
        break;
    }

RESET_EXIT:
    /* If we are a function, return, otherwise, call TaskExit() */
    if( fOwnTask )
        TaskExit();
    
    return;
}


/*************************************************************************
 *  @b ServiceReport( uint Item, uint Status, uint Report, HANDLE h )
 *
 *  @n
 * 
 *  Here's a quick example of using service status updates from the IP
 *  Stack. Lets store the states of the services so we can refrence them 
 *  elsehwere (e.g. the information Page).
 *  The defines for the services are in the NDK header file netcfg.h
 *
 *  @param[in] 
 * 	Item - The service that is reporting (ie Telnet, HTTP, DHCP, etc).
 * 
 *  @param[in] 
 * 	Status - Overall status of that service.
 * 
 *  @param[in] 
 * 	Report - What its reporting.
 * 
 *  @param[in] 
 * 	Handle - Handle to  the Service.
 * 
 *  @retval
 *      None
 ************************************************************************/
void CheckDHCPOptions();

/* These arrays are order dependent based on defines in the NDK header files */
char *ReportStr[] = { "","Running","Updated","Complete","Fault" };
char *StatusStr[] = { "Disabled","Waiting","IPTerm","Failed","Enabled" };

Service_state_s ServiceStatus [CFGITEM_SERVICE_MAX] = {
		{"Telnet", 0, 0},
		{"THTTP", 0, 0},
		{"NAT", 0, 0},
		{"DHCPS", 0, 0},
		{"DHCPC", 0, 0},
		{"DNS", 0, 0}
		};

static void ServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, HANDLE h )
{

	/* Save off the status */
	ServiceStatus[Item-1].status = Status;
	ServiceStatus[Item-1].report = Report;

    platform_write("Service Status: %-9s: %-9s: %-9s: %03d\n",
            ServiceStatus[Item-1].name, StatusStr[ServiceStatus[Item-1].status],
            ReportStr[ServiceStatus[Item-1].report/256], Report&0xFF );

    /*
    // Example of adding to the DHCP configuration space
    //
    // When using the DHCP client, the client has full control over access
    // to the first 256 entries in the CFGTAG_SYSINFO space.
    //
    // Note that the DHCP client will erase all CFGTAG_SYSINFO tags except
    // CFGITEM_DHCP_HOSTNAME. If the application needs to keep manual
    // entries in the DHCP tag range, then the code to maintain them should
    // be placed here.
    //
    // Here, we want to manually add a DNS server to the configuration, but
    // we can only do it once DHCP has finished its programming.
    */
    if( Item == CFGITEM_SERVICE_DHCPCLIENT &&
        Status == CIS_SRV_STATUS_ENABLED &&
        (Report == (NETTOOLS_STAT_RUNNING|DHCPCODE_IPADD) ||
         Report == (NETTOOLS_STAT_RUNNING|DHCPCODE_IPRENEW)) )
    {
        IPN IPTmp;

        /* Manually add the DNS server when specified */
        IPTmp = inet_addr(DNSServer);
        if( IPTmp )
            CfgAddEntry( 0, CFGTAG_SYSINFO, CFGITEM_DHCP_DOMAINNAMESERVER,
                         0, sizeof(IPTmp), (uint8_t *)&IPTmp, 0 );
#if 0        
        /* We can now check on what the DHCP server supplied in 
           response to our DHCP option tags. */
        CheckDHCPOptions();   
#endif
                     
    }

    /* Reset DHCP client service on failure */
    if( Item==CFGITEM_SERVICE_DHCPCLIENT && (Report&~0xFF)==NETTOOLS_STAT_FAULT )
    {
        CI_SERVICE_DHCPC dhcpc;
        int tmp;

        /* Get DHCP entry data (for index to pass to DHCP_reset). */
        tmp = sizeof(dhcpc);
        CfgEntryGetData( h, &tmp, (uint8_t *)&dhcpc );

        /* Create the task to reset DHCP on its designated IF
           We must use TaskCreate instead of just calling the function as
           we are in a callback function. */
        TaskCreate( DHCP_reset, "DHCPreset", OS_TASKPRINORM, 0x1000,
                    dhcpc.cisargs.IfIdx, 1, 0 );
    }
    
    return;
}

/*************************************************************************
 *  @b CheckDHCPOptions()
 *
 *  @n
 * 
 *  Checks the DHCP Options and configures them.
 *
 *  @param[in] 
 * 	None
 * 
 *  @retval
 *      None
 ************************************************************************/
void CheckDHCPOptions()
{
    char 	IPString[16];
    IPN  	IPAddr;
    int32_t  i, rc;

    /*
     *  Now scan for DHCPOPT_SERVER_IDENTIFIER via configuration
     */
    platform_write("\nDHCP Server ID:\n");
    for(i=1;;i++)
    {
        /* Try and get a DNS server */
        rc = CfgGetImmediate( 0, CFGTAG_SYSINFO, DHCPOPT_SERVER_IDENTIFIER,
                              i, 4, (uint8_t *)&IPAddr );
        if( rc != 4 )
            break;

        /* We got something */

        /* Convert IP to a string */
        NtIPN2Str( IPAddr, IPString );
        platform_write("DHCP Server %d = '%s'\n", i, IPString);
    }
    if( i==1 )
        platform_write("None\n\n");
    else
        platform_write("\n");

    /*  Now scan for DHCPOPT_ROUTER via the configuration */
    platform_write("Router Information:\n");
    for(i=1;;i++)
    {
        /* Try and get a DNS server */
        rc = CfgGetImmediate( 0, CFGTAG_SYSINFO, DHCPOPT_ROUTER,
                              i, 4, (uint8_t *)&IPAddr );
        if( rc != 4 )
            break;

        /* We got something */

        /* Convert IP to a string */
        NtIPN2Str( IPAddr, IPString );
        platform_write("Router %d = '%s'\n", i, IPString);
    }
    if( i==1 )
        platform_write("None\n\n");
    else
        platform_write("\n");
    
    return;
}


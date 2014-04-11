/**
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 *  @file   netIoIf.c
 *  @brief  implementation for ethernet I/O based on TFTP protocol
 *
 */

#include <stdlib.h>
#include <netmain.h>
#include <_stack.h>
#include "tftpifLocal.h"

#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>

#define C6678

#ifdef C6678 //QM LLD header for C6678
#include <ti/drv/qmss/qmss_acc.h>
#endif

#include "../netIoIf.h"

IPN gDataSrcIPN;

// **************************************************************************************
static inline int_least32_t ConStrToIPN( uint_least8_t *str, IPN *pIPN )
{
  uint_least8_t   *buffer;
  struct in_addr in1;
  int_least32_t    retcode = 0;

  // If the string is an IP, we're done
  if( inet_aton( (char *) str, &in1 ) )
  {
     *pIPN = in1.s_addr;
      return(1);
  }

  // All the DNS functions need a scrap buffer
  buffer = mmAlloc( 512 );
  if( buffer )
  {
    // We can treat buffer as a HOSTENT structure after
    // DNSGetHostByXxx calls
    HOSTENT *phe = (HOSTENT *)buffer;

    retcode = DNSGetHostByName( (char *) str, buffer, 512 );
    if( !retcode && phe->h_addrcnt )
    {
#ifndef _INCLUDE_IPv6_CODE
      *pIPN = phe->h_addr[0];
#else
      pIPN = (IPN *)phe->h_addr_list[0];
#endif
      retcode = 1;
    }
    else
      retcode = 0;

    mmFree( buffer );
  }
  return( retcode );
}

// **************************************************************************************
uint_least32_t netIOGetBuf(const uint_least8_t *fileName, uint_least8_t *buf, const int_least32_t bytesToRead)
{
  int_least32_t rc;
  uint_least32_t bytesRead;
  uint_least16_t errorCode;
  extern Semaphore_Handle gSemBackEndIfSync;

#ifdef C6678
  volatile uint16_t timerConstant;
  volatile uint16_t timerConstantOrig;

  timerConstant = 110; // tftp operates faster with this value
  if (Qmss_configureAccTimer(Qmss_PdspId_PDSP1, timerConstant) != QMSS_ACC_SOK)
  {
    System_abort("Error Programming timer constant to PDSP1\n");
  }
#endif

  bytesRead = bytesToRead;
  System_printf("loadBuf(), starting to read %d bytes from %s\n", bytesToRead, fileName);
  rc = NtTftpRecvLocal( gDataSrcIPN, (char *) fileName, (char *) buf, &bytesRead, &errorCode );
  Task_sleep(1000);

  if (rc >= 0) {
    System_printf( "loadBuf(): Read %d bytes from %s\n", bytesRead, fileName );
  }
  else {
    System_printf("read error: %d %d\n", errorCode, rc);
    System_abort("loadBuf: failed to read data\n");
  }

#ifdef C6678
  // set PDSP time constant back to nominal value
  timerConstant = 4375;
  if (Qmss_configureAccTimer(Qmss_PdspId_PDSP1, timerConstant) != QMSS_ACC_SOK)
  {
    System_abort("Error Programming timer constant to PDSP1\n");
  }
#endif

  return(bytesRead);
}

uint_least32_t netIOPutBuf(const uint_least8_t *fileName, const uint_least8_t *buf, const int_least32_t bytesToSend)
{
  int_least32_t rc;
  uint_least32_t bytesSent;
  uint_least16_t errorCode;

#ifdef C6678
  volatile uint16_t timerConstant;

  // reduce QM PDSP time constant to improve TFTP throughput
  timerConstant = 110;  // tftp operates faster with this value
  if (Qmss_configureAccTimer(Qmss_PdspId_PDSP1, timerConstant) != QMSS_ACC_SOK)
  {
    System_abort("Error Programming timer constant to PDSP1\n");
  }
#endif

  bytesSent = bytesToSend;
  System_printf("sendBuf(), starting to write %d bytes to %s\n", bytesToSend, fileName);
  rc = NtTftpSendLocal( gDataSrcIPN, (char *) fileName, (char *) buf, &bytesSent, &errorCode );
  Task_sleep(1000);

  if (rc >= 0) {
    System_printf( "sendBuf(): sent %d bytes to %s\n", bytesSent, fileName );
  }
  else {
    System_printf("read error: %d %d\n", errorCode, rc);
    System_abort("sendBuf: failed to read data");
  }

#ifdef C6678
  // set PDSP time constant back to nominal value
  timerConstant = 4375;
  if (Qmss_configureAccTimer(Qmss_PdspId_PDSP1, timerConstant) != QMSS_ACC_SOK)
  {
    System_abort("Error Programming timer constant to PDSP1\n");
  }
#endif

  return(bytesSent);
}

// **************************************************************************************
void netIOInit( const uint_least8_t *pIpAddr )
{

  fdOpenSession( TaskSelf() );

  if( !ConStrToIPN((uint_least8_t *)pIpAddr, &(gDataSrcIPN)) ) {
    System_abort("FrontEndIf_init: invalid IP address of data source\n");
  }

}

void netIOClose()
{

  fdCloseSession( TaskSelf() );
}

/*=================================================================================
CHREC Internal Distribution License, Version 1.0

Modified Simplified BSD license with additional limited distribution restriction.
Use the following license at the top of your files:


  Copyright (c) {{2012,2013}} NSF Center for High-Performance Reconfigurable
  Computing (CHREC), University of Florida.  This work was supported in
  part by the I/UCRC Program of the National Science Foundation under
  Grant Nos. EEC-0642422 and IIP-1161022.

  CHREC Internal Distribution License, Version 1.0. All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
  3. Redistributions are permitted ONLY within CHREC via its university sites and
     its industry and government members.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=================================================================================*/

/*=================================================================================
Author: Barath Ramesh
Version: 
Description: Vector multiplication synthetic benchmark.  This 
    Benchmark was designed to test the C6678 TI DSP architectures.  It is based of 
    chrec-f5-spfp-neon benchmarkinf

=================================================================================*/ 
  
#include "vector_stream.h"


//===========================================================//
//vector stream Function                                     //
//Description: kernel function                               //
//Inputs: NONE                                               //
//Outputs:int                                                //
//===========================================================//
int vector_stream_int16(void){

    double totalOps, timeUsed, throughput, totalCycles;
    uint64_t start_time, end_time;

    short seed = 100;

    int i = 0;

    //Vectors to be added with their initialization
    //Vector stream 1 (v)
    long long v1 = _itoll(seed,seed);
    long long v2 = _itoll(seed,seed);
    long long v3 = _itoll(1,1);
    long long v4 = _itoll(2,2);
    long long v5 = _itoll(3,3);
    long long v6 = _itoll(4,4);
    long long v7 = _itoll(5,5);
    long long v8 = _itoll(6,6);
    long long v9 = _itoll(7,7);
    long long v10 = _itoll(8,8);
    long long v11 = _itoll(9,9);
    long long v12 = _itoll(10,10);
    long long v13 = _itoll(11,11);
    long long v14 = _itoll(12,12);
    long long v15 = _itoll(13,13);
    long long v16 = _itoll(1,1);
    long long v17 = _itoll(2,2);
    long long v18 = _itoll(3,3);
    long long v19 = _itoll(4,4);
    long long v20 = _itoll(5,5);
    long long v21 = _itoll(6,1);
    long long v22 = _itoll(7,7);

    
    /* //Vector stream 2 (u) */
    long long u1 = _itoll(seed,seed);
    long long u2 = _itoll(seed,seed);
    long long u3 = _itoll(1,1);
    long long u4 = _itoll(2,2);
    long long u5 = _itoll(3,3);
    long long u6 = _itoll(4,4);
    long long u7 = _itoll(5,5);
    long long u8 = _itoll(6,6);
    long long u9 = _itoll(7,7);
    long long u10 = _itoll(8,8);
    long long u11 = _itoll(9,9);
    long long u12 = _itoll(10,10);

    //Vector stream for mult (x)
    __x128_t x1 = _ito128(seed,seed,seed,seed);
    __x128_t x2 = _ito128(seed,seed,seed,seed);
    __x128_t x3 = _ito128(1,1,1,1);     
    __x128_t x4 = _ito128(2,2,2,2);     
    __x128_t x5 = _ito128(3,3,3,3);     
    __x128_t x6 = _ito128(4,4,4,4);     
    __x128_t x7 = _ito128(5,5,5,5);     
    __x128_t x8 = _ito128(6,6,6,6);     
    __x128_t x9 = _ito128(7,7,7,7);     
    __x128_t x10 = _ito128(8,8,8,8);    
    __x128_t x11 = _ito128(9,9,9,9);    
    __x128_t x12 = _ito128(10,10,10,10);


    
    start_time = _itoll(TSCH,TSCL);

    //Adding and multiplying loop
    for(i = 0; i < nTimes; i++){

        x3 = _dmpy2(_lo128(x1),_lo128(x2));
        x4 = _dmpy2(_lo128(x1),_lo128(x3));
        x5 = _dmpy2(_lo128(x1),_lo128(x4));
        x6 = _dmpy2(_lo128(x1),_lo128(x5));
        x7 = _dmpy2(_lo128(x1),_lo128(x6));
        x8 = _dmpy2(_lo128(x1),_lo128(x6));
        x9 = _dmpy2(_lo128(x1),_lo128(x8));
        x10 = _dmpy2(_lo128(x1),_lo128(x9));
        x11 = _dmpy2(_lo128(x1),_lo128(x10));
        x12 = _dmpy2(_lo128(x1),_lo128(x11));
        x1 = _dmpy2(_lo128(x1),_lo128(x12));
        v3 = _dadd2(v1,v2);
        u3 = _dadd2(u1,u2);
        v4 = _dadd2(v1,v3);
        u4 = _dadd2(u1,u3);
        v5 = _dadd2(v1,v4);
        u5 = _dadd2(u1,u4);
        v6 = _dadd2(v1,v5);
        u6 = _dadd2(u1,u5);
        v7 = _dadd2(v1,v6);
        u7 = _dadd2(u1,u6);
        v8 = _dadd2(v1,v7);
        u8 = _dadd2(u1,u7);
        v9 = _dadd2(v1,v8);
        u9 = _dadd2(u1,u8);
        v10 = _dadd2(v1,v9);
        u10 = _dadd2(u1,u9);
        v11 = _dadd2(v1,v10);
        u11 = _dadd2(u1,u10);
        v12 = _dadd2(v1,v11);
        u12 = _dadd2(u1,u11);
        v1 = _dadd2(v1,v12);
        u1 = _dadd2(u1,u12);


    }
    
    //Stop cycle counter
    end_time = _itoll(TSCH,TSCL);

    //Total operations preformed
    totalOps = (4*33);
    
    //Cycle calculation
    totalCycles = end_time -start_time;
    
    //Throughput calculation
    timeUsed = (double) totalCycles/nTimes;
    throughput = (double) (totalOps*1000)/timeUsed;
    
    //Printing vectors to prevent compiler optimizing them away due to a "non-use" condition

    printf("x1:%df\n", _get32_128(x1,2));
    printf("u1:%ld\n", u1);
    printf("v1:%ld\n", v1);
    /* std::cout << *((long long int *)&v1)  << " _ "<< *((long long int *)&v12) << " _ "<< *((long long int *)&v2) << std::endl; */
    /* std::cout << *((long long int *)&u1)  << " _ "<< *((long long int *)&u12) << " _ "<< *((long long int *)&u3) << std::endl; */
    /* std::cout << *((long long int *)&_lo128(x1))  << " _ "<< *((long long int *)&x12) << " _ "<< *((long long int *)&x2) << std::endl; */
    
    //Print throughput outputs

    printf("MOPS SPFP time used:%f\n", timeUsed);
    printf("Throughput:%f\n", throughput);
    /* std::cout << timeUsed << ":" << throughput << " (MOPS) SPFP" << std::endl; */

    //Return 0, program successful
    return 0;
}










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
int vector_stream_sp(void){

    double totalOps, timeUsed, throughput, totalCycles;
    uint64_t start_time, end_time;

    float seed1 = 100.0;
    float seed2 = 100.0;

    int i = 0;

    //Vectors to be added with their initialization
    //Vector stream 1 (v)
	__float2_t v1 = _ftof2(seed1, seed1);
	__float2_t v2 = _ftof2(seed2, seed2);
	__float2_t v3 = _ftof2(1, 1);
	__float2_t v4 = _ftof2(2, 2);
	__float2_t v5 = _ftof2(3, 3);
	__float2_t v6 = _ftof2(4, 4);
	__float2_t v7 = _ftof2(5, 5);
	__float2_t v8 = _ftof2(6, 6);
	__float2_t v9 = _ftof2(7, 7);
	__float2_t v10 = _ftof2(8, 8);
	__float2_t v11 = _ftof2(9, 9);
	__float2_t v12 = _ftof2(10, 10);
	__float2_t v13 = _ftof2(11, 11);
	__float2_t v14 = _ftof2(12, 12);
	__float2_t v15 = _ftof2(13, 13);
	__float2_t v16 = _ftof2(1, 1);
	__float2_t v17 = _ftof2(2, 2);
	__float2_t v18 = _ftof2(3, 3);
	__float2_t v19 = _ftof2(4, 4);
	__float2_t v20 = _ftof2(5, 5);
	__float2_t v21 = _ftof2(6, 6);
	__float2_t v22 = _ftof2(7, 7);

	//Vector stream 2 (u)
	__float2_t u1 = _ftof2(seed1, seed1);
	__float2_t u2 = _ftof2(seed2, seed2);
	__float2_t u3 = _ftof2(1, 1);
	__float2_t u4 = _ftof2(2, 2);
	__float2_t u5 = _ftof2(3, 3);
	__float2_t u6 = _ftof2(4, 4);
	__float2_t u7 = _ftof2(5, 5);
	__float2_t u8 = _ftof2(6, 6);
	__float2_t u9 = _ftof2(7, 7);
	__float2_t u10 = _ftof2(8, 8);
	__float2_t u11 = _ftof2(9, 9);
	__float2_t u12 = _ftof2(10, 10);
	__float2_t u13 = _ftof2(11, 11);



//	//Vector stream 2 (u)
//	__float2_t c1;
//	__float2_t c2;
//	__float2_t c3;
//	__float2_t c4;
//	__float2_t c5;
//	__float2_t c6;
//	__float2_t c7;
//	__float2_t c8;
//	__float2_t c9;
//	__float2_t c10;
//	__float2_t c11;
//	__float2_t c12;
//	__float2_t c13;
//	__float2_t c14;
//	__float2_t c15;
//	__float2_t c16;
//	__float2_t c17;
//	__float2_t c18;
//	__float2_t c19;
//	__float2_t c20;
//	__float2_t c21;
//	__float2_t c22;
//	__float2_t c23;
//	__float2_t c24;
//	__float2_t c25;
//	__float2_t c26;
//	__float2_t c27;
//	__float2_t c28;
//	__float2_t c29;
//	__float2_t c30;
//	__float2_t c31;
//	__float2_t c32;
//	__float2_t c33;



    //Vector stream for mult (x)
    __x128_t x1 = _fto128(seed1,seed1,seed1,seed1);
    __x128_t x2 = _fto128(seed2,seed2,seed2,seed2);
    __x128_t x3 = _fto128(1,1,1,1);     
    __x128_t x4 = _fto128(2,2,2,2);     
    __x128_t x5 = _fto128(3,3,3,3);     
    __x128_t x6 = _fto128(4,4,4,4);     
    __x128_t x7 = _fto128(5,5,5,5);     
    __x128_t x8 = _fto128(6,6,6,6);     
    __x128_t x9 = _fto128(7,7,7,7);     
    __x128_t x10 = _fto128(8,8,8,8);    
    __x128_t x11 = _fto128(9,9,9,9);    
    __x128_t x12 = _fto128(10,10,10,10);
    __x128_t x13 = _fto128(11,11,11,11);     
    __x128_t x14 = _fto128(12,12,12,12);     
    __x128_t x15 = _fto128(13,13,13,13);     
    __x128_t x16 = _fto128(14,14,14,14);     
    __x128_t x17 = _fto128(15,15,15,15);     
    __x128_t x18 = _fto128(16,16,16,16);     
    __x128_t x19 = _fto128(17,17,17,17);     
    __x128_t x20 = _fto128(18,18,18,18);    
    __x128_t x21 = _fto128(19,19,19,19);    
    __x128_t x22 = _fto128(20,20,20,20);
    __x128_t x23 = _fto128(21,21,21,21);    
    __x128_t x24 = _fto128(22,22,22,22);    
    __x128_t x25 = _fto128(23,23,23,23);
    __x128_t x26 = _fto128(24,24,24,24);     
    __x128_t x27 = _fto128(25,25,25,25);     
    __x128_t x28 = _fto128(26,26,26,26);     
    __x128_t x29 = _fto128(27,27,27,27);     
    __x128_t x30 = _fto128(28,28,28,28);     
    __x128_t x31 = _fto128(29,29,29,29);     
    __x128_t x32 = _fto128(30,30,30,30);     
    __x128_t x33 = _fto128(31,31,31,31);     
    __x128_t x34 = _fto128(32,32,32,32);     
    __x128_t x35 = _fto128(33,33,33,33);
    __x128_t x36 = _fto128(34,34,34,34);

    
    start_time = _itoll(TSCH,TSCL);
#pragma MUST_ITERATE(nTimes,nTimes);
//#pragma UNROLL(2);

    //Adding and multiplying loop
    for(i = 0; i < nTimes; i++){

//
		
		
		// v5 = _daddsp(v1, v4);
		// u5 = _daddsp(u1, u4);
		// v7 = _daddsp(v1, v6);
		// u7 = _daddsp(u1, u6);
		// v9 = _daddsp(v1, v8);
		// u9 = _daddsp(u1, u8);
//		v11 = _daddsp(v1, v10);
//		u11 = _daddsp(u1, u10);
//		v13 = _daddsp(v1, v12);
//		u13 = _daddsp(u1, u12);
//		v10 = _daddsp(v1, v9);
//		u10 = _daddsp(u1, u9);
//		v11 = _daddsp(v1, v10);
//		u11 = _daddsp(u1, u10);
//		v12 = _daddsp(v1, v11);
//		u12 = _daddsp(u1, u11);
//		v6 = _daddsp(v1, v5);
//		u6 = _daddsp(u1, u5);
//		v7 = _daddsp(v1, v6);
//		u7 = _daddsp(u1, u6);
//		v1 = _daddsp(v1, v12);
//		u1 = _daddsp(u1, u12);
//		v8 = _daddsp(v1, v7);
//		u8 = _daddsp(u1, u7);
//		v9 = _daddsp(v1, v8);
//		u9 = _daddsp(u1, u8);
//		v10 = _daddsp(v1, v9);
//		u10 = _daddsp(u1, u9);
//		v11 = _daddsp(v1, v10);
//		u11 = _daddsp(u1, u10);
//		v12 = _daddsp(v1, v11);
//		u12 = _daddsp(u1, u11);
//		v3 = _daddsp(v1, v2);
//		u3 = _daddsp(u1, u2);
//		v4 = _daddsp(v1, v3);
//		u4 = _daddsp(u1, u3);




        x8 = _qmpysp(x1,x2);
		v3 = _daddsp(v1, v2);
        // x9 = _qmpysp(x4,x3);
		// u3 = _daddsp(u1, u2);
        // x4 = _qmpysp(x1,x2);
        // x5 = _qmpysp(x1,x3);
//        x6 = _qmpysp(x1,x2);
//        x7 = _qmpysp(x1,x3);
//        x8 = _qmpysp(x1,x4);
//        x9 = _qmpysp(x1,x5);
//        x10 = _qmpysp(x1,x6);
//        x11 = _qmpysp(x1,x7);
//        x12 = _qmpysp(x1,x8);
//        x13 = _qmpysp(x1,x9);
//        x14 = _qmpysp(x1,x10);
//        x15 = _qmpysp(x1,x11);
//        x16 = _qmpysp(x1,x12);
//        x17 = _qmpysp(x1,x13);
//        x18 = _qmpysp(x1,x14);
//        x19 = _qmpysp(x1,x15);
//        x20 = _qmpysp(x1,x16);
//        x21 = _qmpysp(x1,x17);
//        x22 = _qmpysp(x1,x18);
//        x23 = _qmpysp(x1,x19);
//        x24 = _qmpysp(x1,x20);
//        x25 = _qmpysp(x1,x21);
//        x26 = _qmpysp(x1,x22);
//        x27 = _qmpysp(x1,x23);
//        x28 = _qmpysp(x1,x24);
//        x29 = _qmpysp(x1,x25);
//        x30 = _qmpysp(x1,x26);
//        x31 = _qmpysp(x1,x27);
//        x32 = _qmpysp(x1,x28);
//        x33 = _qmpysp(x1,x29);
//        x34 = _qmpysp(x1,x30);
//        x35 = _qmpysp(x1,x31);
//        x36 = _qmpysp(x1,x32);


//        c1= _dinthspu (0);
//        c2= _dinthspu (0);
//        c3= _dinthspu (0);
//        c4= _dinthspu (0);
//        c5= _dinthspu (0);
//        c6= _dinthspu (0);
//        c7= _dinthspu (0);
//        c8= _dinthspu (0);
//        c9= _dinthspu (0);
//        c10= _dinthspu (0);
//        c11= _dinthspu (0);
//        c12= _dinthspu (0);
//        c13= _dinthspu (0);
//        c14= _dinthspu (0);
//        c15= _dinthspu (0);
//        c16= _dinthspu (0);
//        c17= _dinthspu (0);
//        c18= _dinthspu (0);
//        c19= _dinthspu (0);
//        c20= _dinthspu (0);
//        c21= _dinthspu (0);
//        c22= _dinthspu (0);
//        c23= _dinthspu (0);
//        c24= _dinthspu (0);
//        c25= _dinthspu (0);
//        c26= _dinthspu (0);
//        c27= _dinthspu (0);
//        c28= _dinthspu (0);
//        c29= _dinthspu (0);
//        c30= _dinthspu (0);
//        c31= _dinthspu (0);
//        c32= _dinthspu (0);
//        c33= _dinthspu (0);
    }
    
    //Stop cycle counter
    end_time = _itoll(TSCH,TSCL);

    //Total operations performed
    totalOps = (32);
    
    //Cycle calculation
    totalCycles = end_time -start_time;
    
    //Throughput calculation
    timeUsed = (double) totalCycles/nTimes;
    throughput = (double) totalOps*1000/timeUsed;
    
    //Printing vectors to prevent compiler optimizing them away due to a "non-use" condition

    printf("x1:%f\n", _get32_128(x4,2));
    printf("x1:%f\n", _get32_128(x5,2));
    printf("x1:%f\n", _get32_128(x6,2));
    printf("x1:%f\n", _get32_128(x7,2));
    printf("x1:%f\n", _get32_128(x8,2));
    printf("x1:%f\n", _get32_128(x9,2));
    printf("x1:%f\n", _get32_128(x10,2));
    printf("x1:%f\n", _get32_128(x11,2));
    printf("x1:%f\n", _get32_128(x12,2));
    printf("x1:%f\n", _get32_128(x13,2));
    printf("x1:%f\n", _get32_128(x14,2));
    printf("x1:%f\n", _get32_128(x15,2));
    printf("x1:%f\n", _get32_128(x16,2));
    printf("x1:%f\n", _get32_128(x17,2));
    printf("x1:%f\n", _get32_128(x18,2));
    printf("x1:%f\n", _get32_128(x19,2));
    printf("x1:%f\n", _get32_128(x20,2));
    printf("x1:%f\n", _get32_128(x21,2));
    printf("x1:%f\n", _get32_128(x22,2));
    printf("x1:%f\n", _get32_128(x23,2));
    printf("x1:%f\n", _get32_128(x24,2));
    printf("x1:%f\n", _get32_128(x25,2));
    printf("x1:%f\n", _get32_128(x26,2));
    printf("x1:%f\n", _get32_128(x27,2));
    printf("x1:%f\n", _get32_128(x28,2));
    printf("x1:%f\n", _get32_128(x29,2));
    printf("x1:%f\n", _get32_128(x30,2));
    printf("x1:%f\n", _get32_128(x31,2));
    printf("x1:%f\n", _get32_128(x32,2));
    printf("x1:%f\n", _get32_128(x33,2));
    printf("x1:%f\n", _get32_128(x34,2));
    printf("x1:%f\n", _get32_128(x35,2));
    printf("x1:%f\n", _get32_128(x36,2));


    printf("v3:%f\n", v3);
    printf("u3:%f\n", u3);
    printf("v3:%f\n", v5);
    printf("u3:%f\n", u5);
    printf("v3:%f\n", v7);
    printf("u3:%f\n", u7);
    printf("v3:%f\n", v9);
    printf("u3:%f\n", u9);
    printf("v3:%f\n", v11);
    printf("u3:%f\n", u11);
    printf("v3:%f\n", v13);
    printf("u3:%f\n", u13);
    //printf("c33:%f\n", c33);

    /* std::cout << *((long long int *)&v1)  << " _ "<< *((long long int *)&v12) << " _ "<< *((long long int *)&v2) << std::endl; */
    /* std::cout << *((long long int *)&u1)  << " _ "<< *((long long int *)&u12) << " _ "<< *((long long int *)&u3) << std::endl; */
    /* std::cout << *((long long int *)&x1)  << " _ "<< *((long long int *)&x12) << " _ "<< *((long long int *)&x2) << std::endl; */
    
    //Print throughput outputs

    printf("MOPS SPFP time used:%f\n", timeUsed);
    printf("Throughput:%f\n", throughput);
    /* std::cout << timeUsed << ":" << throughput << " (MOPS) SPFP" << std::endl; */

    //Return 0, program successful
    return 0;
}










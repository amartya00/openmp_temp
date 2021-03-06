;******************************************************************************
;* TMS320C6x C/C++ Codegen                                          PC v7.4.2 *
;* Date/Time created: Fri Sep 06 17:28:56 2013                                *
;******************************************************************************
	.compiler_opts --abi=eabi --c64p_l1d_workaround=off --endian=little --hll_source=on --long_precision_bits=32 --mem_model:code=near --mem_model:const=data --mem_model:data=far_aggregates --object_format=elf --silicon_version=6600 --symdebug:dwarf_version=3 --symdebug:skeletal 

;******************************************************************************
;* GLOBAL FILE PARAMETERS                                                     *
;*                                                                            *
;*   Architecture      : TMS320C66xx                                          *
;*   Optimization      : Enabled at level 3                                   *
;*   Optimizing for    : Speed                                                *
;*                       Based on options: -o3, no -ms                        *
;*   Endian            : Little                                               *
;*   Interrupt Thrshld : Disabled                                             *
;*   Data Access Model : Far Aggregate Data                                   *
;*   Pipelining        : Enabled                                              *
;*   Speculate Loads   : Enabled with threshold = 0                           *
;*   Memory Aliases    : Presume are aliases (pessimistic)                    *
;*   Debug Info        : DWARF Debug for Program Analysis w/Optimization      *
;*                                                                            *
;******************************************************************************

	.asg	A15, FP
	.asg	B14, DP
	.asg	B15, SP
	.global	$bss


$C$DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr $C$DW$CU, DW_AT_name("../src/vector_stream_sp.c")
	.dwattr $C$DW$CU, DW_AT_producer("TI TMS320C6x C/C++ Codegen PC v7.4.2 Copyright (c) 1996-2012 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("A:\F5\TMS320C6678-Benchmarks\benchmarks\vector_stream\Release")

$C$DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("_itoll")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("_itoll")
	.dwattr $C$DW$1, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
	.dwattr $C$DW$1, DW_AT_decl_file("C:/ti/include/c6x.h")
	.dwattr $C$DW$1, DW_AT_decl_line(0xdf)
	.dwattr $C$DW$1, DW_AT_decl_column(0x0b)
$C$DW$2	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$2, DW_AT_type(*$C$DW$T$11)
$C$DW$3	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$3, DW_AT_type(*$C$DW$T$11)
	.dwendtag $C$DW$1


$C$DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("_ftod")
	.dwattr $C$DW$4, DW_AT_TI_symbol_name("_ftod")
	.dwattr $C$DW$4, DW_AT_type(*$C$DW$T$17)
	.dwattr $C$DW$4, DW_AT_declaration
	.dwattr $C$DW$4, DW_AT_external
	.dwattr $C$DW$4, DW_AT_decl_file("C:/ti/include/c6x.h")
	.dwattr $C$DW$4, DW_AT_decl_line(0xde)
	.dwattr $C$DW$4, DW_AT_decl_column(0x0b)
$C$DW$5	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$5, DW_AT_type(*$C$DW$T$16)
$C$DW$6	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$6, DW_AT_type(*$C$DW$T$16)
	.dwendtag $C$DW$4


$C$DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("_daddsp")
	.dwattr $C$DW$7, DW_AT_TI_symbol_name("_daddsp")
	.dwattr $C$DW$7, DW_AT_type(*$C$DW$T$543)
	.dwattr $C$DW$7, DW_AT_declaration
	.dwattr $C$DW$7, DW_AT_external
	.dwattr $C$DW$7, DW_AT_decl_file("C:/ti/include/c6x.h")
	.dwattr $C$DW$7, DW_AT_decl_line(0x1a8)
	.dwattr $C$DW$7, DW_AT_decl_column(0x0c)
$C$DW$8	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$8, DW_AT_type(*$C$DW$T$543)
$C$DW$9	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$9, DW_AT_type(*$C$DW$T$543)
	.dwendtag $C$DW$7


$C$DW$10	.dwtag  DW_TAG_subprogram, DW_AT_name("printf")
	.dwattr $C$DW$10, DW_AT_TI_symbol_name("printf")
	.dwattr $C$DW$10, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$10, DW_AT_declaration
	.dwattr $C$DW$10, DW_AT_external
	.dwattr $C$DW$10, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$10, DW_AT_decl_line(0xb8)
	.dwattr $C$DW$10, DW_AT_decl_column(0x19)
$C$DW$11	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$11, DW_AT_type(*$C$DW$T$427)
$C$DW$12	.dwtag  DW_TAG_unspecified_parameters
	.dwendtag $C$DW$10


$C$DW$13	.dwtag  DW_TAG_subprogram, DW_AT_name("_qmpysp")
	.dwattr $C$DW$13, DW_AT_TI_symbol_name("_qmpysp")
	.dwattr $C$DW$13, DW_AT_type(*$C$DW$T$462)
	.dwattr $C$DW$13, DW_AT_declaration
	.dwattr $C$DW$13, DW_AT_external
	.dwattr $C$DW$13, DW_AT_decl_file("C:/ti/include/c6x.h")
	.dwattr $C$DW$13, DW_AT_decl_line(0x1cb)
	.dwattr $C$DW$13, DW_AT_decl_column(0x16)
$C$DW$14	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$14, DW_AT_type(*$C$DW$T$462)
$C$DW$15	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$15, DW_AT_type(*$C$DW$T$462)
	.dwendtag $C$DW$13


$C$DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("_fto128")
	.dwattr $C$DW$16, DW_AT_TI_symbol_name("_fto128")
	.dwattr $C$DW$16, DW_AT_type(*$C$DW$T$462)
	.dwattr $C$DW$16, DW_AT_declaration
	.dwattr $C$DW$16, DW_AT_external
	.dwattr $C$DW$16, DW_AT_decl_file("C:/ti/include/c6x.h")
	.dwattr $C$DW$16, DW_AT_decl_line(0x1d0)
	.dwattr $C$DW$16, DW_AT_decl_column(0x16)
$C$DW$17	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$17, DW_AT_type(*$C$DW$T$16)
$C$DW$18	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$18, DW_AT_type(*$C$DW$T$16)
$C$DW$19	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$19, DW_AT_type(*$C$DW$T$16)
$C$DW$20	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$20, DW_AT_type(*$C$DW$T$16)
	.dwendtag $C$DW$16


$C$DW$21	.dwtag  DW_TAG_subprogram, DW_AT_name("_get32_128")
	.dwattr $C$DW$21, DW_AT_TI_symbol_name("_get32_128")
	.dwattr $C$DW$21, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$21, DW_AT_declaration
	.dwattr $C$DW$21, DW_AT_external
	.dwattr $C$DW$21, DW_AT_decl_file("C:/ti/include/c6x.h")
	.dwattr $C$DW$21, DW_AT_decl_line(0x1d9)
	.dwattr $C$DW$21, DW_AT_decl_column(0x15)
$C$DW$22	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$22, DW_AT_type(*$C$DW$T$462)
$C$DW$23	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$23, DW_AT_type(*$C$DW$T$11)
	.dwendtag $C$DW$21

;	C:\ti\bin\opt6x.exe C:\\Users\\Barath\\AppData\\Local\\Temp\\086682 C:\\Users\\Barath\\AppData\\Local\\Temp\\086684 
	.sect	".text"
	.clink
	.global	vector_stream_sp

$C$DW$24	.dwtag  DW_TAG_subprogram, DW_AT_name("vector_stream_sp")
	.dwattr $C$DW$24, DW_AT_low_pc(vector_stream_sp)
	.dwattr $C$DW$24, DW_AT_high_pc(0x00)
	.dwattr $C$DW$24, DW_AT_TI_symbol_name("vector_stream_sp")
	.dwattr $C$DW$24, DW_AT_external
	.dwattr $C$DW$24, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$24, DW_AT_TI_begin_file("../src/vector_stream_sp.c")
	.dwattr $C$DW$24, DW_AT_TI_begin_line(0x38)
	.dwattr $C$DW$24, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$24, DW_AT_decl_file("../src/vector_stream_sp.c")
	.dwattr $C$DW$24, DW_AT_decl_line(0x38)
	.dwattr $C$DW$24, DW_AT_decl_column(0x05)
	.dwattr $C$DW$24, DW_AT_TI_max_frame_size(0xd0)
	.dwattr $C$DW$24, DW_AT_frame_base[DW_OP_breg31 208]
	.dwattr $C$DW$24, DW_AT_TI_skeletal
	.dwpsn	file "../src/vector_stream_sp.c",line 56,column 27,is_stmt,address vector_stream_sp,isa 0

;******************************************************************************
;* FUNCTION NAME: vector_stream_sp                                            *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B0,*
;*                           B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,SP,   *
;*                           A16,A17,A18,A19,A20,A21,A22,A23,A24,A25,A26,A27, *
;*                           A28,A29,A30,A31,B16,B17,B18,B19,B20,B21,B22,B23, *
;*                           B24,B25,B26,B27,B28,B29,B30,B31                  *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B0,*
;*                           B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,DP,SP,*
;*                           A16,A17,A18,A19,A20,A21,A22,A23,A24,A25,A26,A27, *
;*                           A28,A29,A30,A31,B16,B17,B18,B19,B20,B21,B22,B23, *
;*                           B24,B25,B26,B27,B28,B29,B30,B31                  *
;*   Local Frame Size  : 32 Args + 132 Auto + 40 Save = 204 byte              *
;******************************************************************************
vector_stream_sp:
;** --------------------------------------------------------------------------*
;** 143	-----------------------    C$4 = 100.0F;
;** 143	-----------------------    x1 = _fto128(C$4, C$4, C$4, C$4);
;** 144	-----------------------    x2 = _fto128(C$4, C$4, C$4, C$4);
;** 147	-----------------------    C$3 = 3.0F;
;** 147	-----------------------    x5 = _fto128(C$3, C$3, C$3, C$3);
;** 148	-----------------------    C$32 = 4.0F;
;** 148	-----------------------    x6 = _fto128(C$32, C$32, C$32, C$32);
;** 152	-----------------------    C$31 = 8.0F;
;** 152	-----------------------    x10 = _fto128(C$31, C$31, C$31, C$31);
;** 153	-----------------------    C$30 = 9.0F;
;** 153	-----------------------    x11 = _fto128(C$30, C$30, C$30, C$30);
;** 154	-----------------------    C$29 = 10.0F;
;** 154	-----------------------    x12 = _fto128(C$29, C$29, C$29, C$29);
;** 155	-----------------------    C$28 = 11.0F;
;** 155	-----------------------    x13 = _fto128(C$28, C$28, C$28, C$28);
;** 156	-----------------------    C$27 = 12.0F;
;** 156	-----------------------    x14 = _fto128(C$27, C$27, C$27, C$27);
;** 157	-----------------------    C$26 = 13.0F;
;** 157	-----------------------    x15 = _fto128(C$26, C$26, C$26, C$26);
;** 158	-----------------------    C$25 = 14.0F;
;** 158	-----------------------    x16 = _fto128(C$25, C$25, C$25, C$25);
;** 159	-----------------------    C$24 = 15.0F;
;** 159	-----------------------    x17 = _fto128(C$24, C$24, C$24, C$24);
;** 160	-----------------------    C$23 = 16.0F;
;** 160	-----------------------    x18 = _fto128(C$23, C$23, C$23, C$23);
;** 161	-----------------------    C$22 = 17.0F;
;** 161	-----------------------    x19 = _fto128(C$22, C$22, C$22, C$22);
;** 162	-----------------------    C$21 = 18.0F;
;** 162	-----------------------    x20 = _fto128(C$21, C$21, C$21, C$21);
;** 163	-----------------------    C$20 = 19.0F;
;** 163	-----------------------    x21 = _fto128(C$20, C$20, C$20, C$20);
;** 164	-----------------------    C$19 = 20.0F;
;** 164	-----------------------    x22 = _fto128(C$19, C$19, C$19, C$19);
;** 165	-----------------------    C$18 = 21.0F;
;** 165	-----------------------    x23 = _fto128(C$18, C$18, C$18, C$18);
;** 166	-----------------------    C$17 = 22.0F;
;** 166	-----------------------    x24 = _fto128(C$17, C$17, C$17, C$17);
;** 167	-----------------------    C$16 = 23.0F;
;** 167	-----------------------    x25 = _fto128(C$16, C$16, C$16, C$16);
;** 168	-----------------------    C$15 = 24.0F;
;** 168	-----------------------    x26 = _fto128(C$15, C$15, C$15, C$15);
;** 169	-----------------------    C$14 = 25.0F;
;** 169	-----------------------    x27 = _fto128(C$14, C$14, C$14, C$14);
;** 170	-----------------------    C$13 = 26.0F;
;** 170	-----------------------    x28 = _fto128(C$13, C$13, C$13, C$13);
;** 171	-----------------------    C$12 = 27.0F;
;** 171	-----------------------    x29 = _fto128(C$12, C$12, C$12, C$12);
;** 172	-----------------------    C$11 = 28.0F;
;** 172	-----------------------    x30 = _fto128(C$11, C$11, C$11, C$11);
;** 173	-----------------------    C$10 = 29.0F;
;** 173	-----------------------    x31 = _fto128(C$10, C$10, C$10, C$10);
;** 174	-----------------------    C$9 = 30.0F;
;** 174	-----------------------    x32 = _fto128(C$9, C$9, C$9, C$9);
;** 175	-----------------------    C$8 = 31.0F;
;** 175	-----------------------    x33 = _fto128(C$8, C$8, C$8, C$8);
;** 176	-----------------------    C$7 = 32.0F;
;** 176	-----------------------    x34 = _fto128(C$7, C$7, C$7, C$7);
;** 177	-----------------------    C$6 = 33.0F;
;** 177	-----------------------    x35 = _fto128(C$6, C$6, C$6, C$6);
;** 178	-----------------------    C$5 = 34.0F;
;** 178	-----------------------    x36 = _fto128(C$5, C$5, C$5, C$5);
;** 181	-----------------------    start_time = _itoll(TSCH, TSCL);
;**  	-----------------------    C$2 = _ftod(C$4, C$4);
;**  	-----------------------    U$117 = _daddsp(C$2, C$2);
;**  	-----------------------    U$119 = U$117;
;**  	-----------------------    U$121 = _daddsp(C$2, _ftod(C$3, C$3));
;**  	-----------------------    U$123 = U$121;
;** 184	-----------------------    L$1 = 10000000;
;**  	-----------------------    #pragma MUST_ITERATE(10000000, 10000000, 10000000)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
           STW     .D2T1   A14,*SP--(8)      ; |56| 
           STDW    .D2T2   B13:B12,*SP--     ; |56| 
           STDW    .D2T2   B11:B10,*SP--     ; |56| 

           STDW    .D2T1   A13:A12,*SP--     ; |56| 
||         ZERO    .L2     B7

           STDW    .D2T1   A11:A10,*SP--     ; |56| 
||         MVKH    .S2     0x42c80000,B7
||         ZERO    .L1     A3

           ADDK    .S2     -168,SP           ; |56| 
||         MVKH    .S1     0x40400000,A3
||         MV      .L1X    B3,A14            ; |56| 

           STW     .D2T1   A3,*+SP(84)       ; |147| 
||         MV      .L1X    B7,A19            ; |143| 

           ZERO    .L1     A4
||         STW     .D2T1   A3,*+SP(80)       ; |147| 
||         MV      .S1X    B7,A5             ; |143| 

           MVKH    .S1     0x40800000,A4
||         STW     .D2T1   A3,*+SP(92)       ; |147| 
||         MV      .L1X    B7,A6             ; |143| 

           STW     .D2T1   A4,*+SP(108)      ; |148| 
||         MV      .L1X    B7,A7             ; |143| 

           STW     .D2T1   A4,*+SP(96)       ; |148| 
||         MV      .L1X    B7,A28            ; |143| 

           STW     .D2T1   A4,*+SP(100)      ; |148| 
||         MV      .L1X    B7,A29            ; |143| 

           STW     .D2T1   A4,*+SP(104)      ; |148| 
||         MV      .L1X    B7,A18            ; |143| 

           STW     .D2T1   A3,*+SP(88)       ; |147| 
||         MV      .L1X    B7,A4             ; |143| 
||         MV      .L2     B7,B6             ; |143| 
||         MVC     .S2     TSCL,B9           ; |181| 

           MVC     .S2     TSCH,B8           ; |181| 

           MV      .L1     A3,A8
||         MV      .S1     A3,A9

           DADDSP  .L1X    B7:B6,A9:A8,A9:A8
||         DADDSP  .L2     B7:B6,B7:B6,B5:B4

           MVKL    .S2     0x989680,B0
           MVKH    .S2     0x989680,B0
           NOP             1
	.dwpsn	file "../src/vector_stream_sp.c",line 184,column 0,is_stmt,isa 0

           DADD    .L2X    0,A9:A8,B7:B6
||         DADD    .L1X    0,B5:B4,A17:A16

;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*
;*      Loop found in file               : ../src/vector_stream_sp.c
;*      Loop source line                 : 184
;*      Loop opening brace source line   : 184
;*      Loop closing brace source line   : 297
;*      Known Minimum Trip Count         : 10000000                    
;*      Known Max Trip Count Factor      : 10000000
;*      Loop Carried Dependency Bound(^) : 8
;*      Unpartitioned Resource Bound     : 4
;*      Partitioned Resource Bound(*)    : 4
;*      Resource Partition:
;*                                A-side   B-side
;*      .L units                     0        0     
;*      .S units                     1        0     
;*      .D units                     0        0     
;*      .M units                     3        4*    
;*      .X cross paths               2        0     
;*      .T address paths             0        0     
;*      Long read paths              0        0     
;*      Long write paths             0        0     
;*      Logical  ops (.LS)           4        2     (.L or .S unit)
;*      Addition ops (.LSD)          0        0     (.L or .S or .D unit)
;*      Bound(.L .S .LS)             3        1     
;*      Bound(.L .S .D .LS .LSD)     2        1     
;*
;*      Searching for software pipeline schedule at ...
;*         ii = 8  Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 21/16
;*                   Max Cond Regs Live :  1/0 
;*         ii = 8  Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 23/24
;*                   Max Cond Regs Live :  1/0 
;*         ii = 8  Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 25/24
;*                   Max Cond Regs Live :  1/0 
;*         ii = 8  Did not find schedule
;*         ii = 9  Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 21/20
;*                   Max Cond Regs Live :  1/0 
;*         ii = 9  Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 21/18
;*                   Max Cond Regs Live :  1/0 
;*         ii = 9  Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 25/22
;*                   Max Cond Regs Live :  1/0 
;*         ii = 9  Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 25/24
;*                   Max Cond Regs Live :  1/0 
;*         ii = 9  Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 25/22
;*                   Max Cond Regs Live :  1/0 
;*         ii = 9  Did not find schedule
;*         ii = 10 Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 21/16
;*                   Max Cond Regs Live :  1/0 
;*         ii = 10 Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 21/20
;*                   Max Cond Regs Live :  1/0 
;*         ii = 10 Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 25/18
;*                   Max Cond Regs Live :  1/0 
;*         ii = 10 Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 25/20
;*                   Max Cond Regs Live :  1/0 
;*         ii = 10 Cannot allocate machine registers
;*                   Regs Live Always   : 13/12 (A/B-side)
;*                   Max Regs Live      : 23/20
;*                   Max Cond Regs Live :  1/0 
;*         ii = 10 Did not find schedule
;*      Disqualified loop: Did not find schedule
;*----------------------------------------------------------------------------*
$C$L1:    
$C$DW$L$vector_stream_sp$2$B:
;**	-----------------------g2:
;** 187	-----------------------    v3 = U$117;
;** 188	-----------------------    u3 = U$119;
;** 189	-----------------------    v6 = U$121;
;** 190	-----------------------    u6 = U$123;
;** 228	-----------------------    x3 = _qmpysp(x1, x2);
;** 229	-----------------------    x4 = _qmpysp(x5, x6);
;** 230	-----------------------    x5 = _qmpysp(x3, x1);
;** 231	-----------------------    x6 = _qmpysp(x4, x2);
;** 232	-----------------------    x7 = _qmpysp(x1, x3);
;** 233	-----------------------    x8 = _qmpysp(x1, x6);
;** 234	-----------------------    x9 = _qmpysp(x1, x7);
;** 184	-----------------------    if ( L$1 = L$1-1 ) goto g2;
           DADD    .L1     0,A19:A18,A31:A30
           QMPYSP  .M1     A31:A30:A29:A28,A7:A6:A5:A4,A23:A22:A21:A20 ; |228| 
           LDDW    .D2T1   *+SP(88),A27:A26  ; |228| 
           LDDW    .D2T1   *+SP(80),A25:A24  ; |228| 
           DADD    .L1     0,A17:A16,A11:A10 ; |188| 
           STDW    .D2T1   A23:A22,*+SP(56)  ; |228| 
           LDDW    .D2T1   *+SP(104),A23:A22 ; |228| 
           STDW    .D2T1   A21:A20,*+SP(48)  ; |228| 
           LDDW    .D2T1   *+SP(96),A21:A20  ; |228| 
           DADD    .L2     0,B5:B4,B13:B12   ; |187| 
           SUB     .L2     B0,1,B0           ; |184| 
           DADD    .L2     0,B7:B6,B11:B10   ; |190| 
           DADD    .L1     0,A9:A8,A13:A12   ; |189| 
           QMPYSP  .M1     A27:A26:A25:A24,A23:A22:A21:A20,A23:A22:A21:A20 ; |229| 
           DADD    .L1     0,A19:A18,A27:A26
           DADD    .L1     0,A29:A28,A25:A24
           NOP             1
           STDW    .D2T1   A23:A22,*+SP(72)  ; |229| 
           LDDW    .D2T1   *+SP(56),A23:A22
           STDW    .D2T1   A21:A20,*+SP(64)  ; |229| 
           LDDW    .D2T1   *+SP(48),A21:A20
           NOP             4
           QMPYSP  .M1     A27:A26:A25:A24,A23:A22:A21:A20,A23:A22:A21:A20 ; |232| 
           LDDW    .D2T1   *+SP(56),A27:A26
           LDDW    .D2T1   *+SP(48),A25:A24
           NOP             1
           STDW    .D2T1   A23:A22,*+SP(120) ; |232| 
           LDDW    .D2T1   *+SP(72),A23:A22  ; |232| 
           STDW    .D2T1   A21:A20,*+SP(112) ; |232| 
           LDDW    .D2T1   *+SP(64),A21:A20  ; |232| 
           NOP             4
           QMPYSP  .M1     A23:A22:A21:A20,A7:A6:A5:A4,A23:A22:A21:A20 ; |231| 
           NOP             3

           STDW    .D2T1   A23:A22,*+SP(104) ; |231| 
||         DADD    .L1     0,A19:A18,A23:A22

           STDW    .D2T1   A21:A20,*+SP(96)  ; |231| 
||         DADD    .L1     0,A29:A28,A21:A20

           QMPYSP  .M1     A27:A26:A25:A24,A23:A22:A21:A20,A23:A22:A21:A20 ; |230| 
           DADD    .L1     0,A29:A28,A25:A24 ; |230| 
           DADD    .L1     0,A19:A18,A27:A26 ; |230| 
           NOP             1
           STDW    .D2T1   A23:A22,*+SP(88)  ; |230| 
           STDW    .D2T1   A21:A20,*+SP(80)  ; |230| 
           LDDW    .D2T1   *+SP(120),A23:A22 ; |230| 
           LDDW    .D2T1   *+SP(112),A21:A20 ; |230| 
           NOP             4
           QMPYSP  .M1     A27:A26:A25:A24,A23:A22:A21:A20,A23:A22:A21:A20 ; |234| 
           NOP             3
           STDW    .D2T1   A23:A22,*+SP(152) ; |234| 
           LDDW    .D2T1   *+SP(104),A23:A22 ; |234| 
           STDW    .D2T1   A21:A20,*+SP(144) ; |234| 
           LDDW    .D2T1   *+SP(96),A21:A20  ; |234| 
           NOP             4

   [ B0]   BNOP    .S1     $C$L1,3           ; |184| 
||         QMPYSP  .M1     A27:A26:A25:A24,A23:A22:A21:A20,A23:A22:A21:A20 ; |233| 

           STDW    .D2T1   A23:A22,*+SP(136) ; |233| 
	.dwpsn	file "../src/vector_stream_sp.c",line 297,column 0,is_stmt,isa 0
           STDW    .D2T1   A21:A20,*+SP(128) ; |233| 
           ; BRANCHCC OCCURS {$C$L1}         ; |184| 
$C$DW$L$vector_stream_sp$2$E:
;** --------------------------------------------------------------------------*
;** 300	-----------------------    end_time = _itoll(TSCH, TSCL);
;** --------------------------------------------------------------------------*
;** 309	-----------------------    timeUsed = (double)(end_time-start_time)/1e+07;
;** 310	-----------------------    throughput = 1.36e+05/timeUsed;
;** 314	-----------------------    printf((const char *)"x1:%f\n", _get32_128(x1, 2u));
;** 315	-----------------------    printf((const char *)"x9:%f\n", _get32_128(x9, 2u));
;** 316	-----------------------    printf((const char *)"v6:%f\n", v6);
;** 317	-----------------------    printf((const char *)"u6:%f\n", u6);
;** 318	-----------------------    printf((const char *)"v3:%f\n", v3);
;** 319	-----------------------    printf((const char *)"u3:%f\n", u3);
;** 321	-----------------------    printf((const char *)(C$1 = "%f\n"), x3);
;** 322	-----------------------    printf((const char *)C$1, x4);
           MVC     .S2     TSCL,B4           ; |300| 
           MVC     .S2     TSCH,B6           ; |300| 
           SUBU    .L2     B4,B9,B5:B4       ; |309| 

           EXT     .S2     B5,24,24,B6       ; |309| 
||         SUB     .L2     B6,B8,B5          ; |309| 

           ADD     .L2     B5,B6,B5          ; |309| 
           NOP             1
$C$DW$25	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$25, DW_AT_low_pc(0x00)
	.dwattr $C$DW$25, DW_AT_name("__c6xabi_fltulld")
	.dwattr $C$DW$25, DW_AT_TI_call

           CALLP   .S2     __c6xabi_fltulld,B3
||         DADD    .L1X    0,B5:B4,A5:A4     ; |309| 

$C$RL1:    ; CALL OCCURS {__c6xabi_fltulld} {0}  ; |309| 
;** --------------------------------------------------------------------------*
           MVKL    .S2     0x416312d0,B5
           MVKH    .S2     0x416312d0,B5
$C$DW$26	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$26, DW_AT_low_pc(0x00)
	.dwattr $C$DW$26, DW_AT_name("__c6xabi_divd")
	.dwattr $C$DW$26, DW_AT_TI_call

           CALLP   .S2     __c6xabi_divd,B3
||         ZERO    .L2     B4                ; |309| 

$C$RL2:    ; CALL OCCURS {__c6xabi_divd} {0}  ; |309| 

           DADD    .L2X    0,A5:A4,B5:B4     ; |309| 
||         MVKL    .S1     0x41009a00,A5

$C$DW$27	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$27, DW_AT_low_pc(0x00)
	.dwattr $C$DW$27, DW_AT_name("__c6xabi_divd")
	.dwattr $C$DW$27, DW_AT_TI_call

           CALLP   .S2     __c6xabi_divd,B3
||         STDW    .D2T2   B5:B4,*+SP(40)    ; |309| 
||         MVKH    .S1     0x41009a00,A5
||         ZERO    .L1     A4                ; |310| 

$C$RL3:    ; CALL OCCURS {__c6xabi_divd} {0}  ; |310| 
           ZERO    .L1     A3

           MVKL    .S2     $C$SL1+0,B4
||         MVKH    .S1     0x42c80000,A3
||         STDW    .D2T1   A5:A4,*+SP(160)   ; |310| 

           MVKH    .S2     $C$SL1+0,B4
||         STW     .D2T1   A3,*+SP(8)        ; |314| 

$C$DW$28	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$28, DW_AT_low_pc(0x00)
	.dwattr $C$DW$28, DW_AT_name("printf")
	.dwattr $C$DW$28, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STW     .D2T2   B4,*+SP(4)        ; |314| 

$C$RL4:    ; CALL OCCURS {printf} {0}        ; |314| 
           LDW     .D2T1   *+SP(152),A3      ; |315| 
           MVKL    .S1     $C$SL2+0,A4
           MVKH    .S1     $C$SL2+0,A4
           STW     .D2T1   A4,*+SP(4)        ; |315| 
           NOP             1
$C$DW$29	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$29, DW_AT_low_pc(0x00)
	.dwattr $C$DW$29, DW_AT_name("printf")
	.dwattr $C$DW$29, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STW     .D2T1   A3,*+SP(8)        ; |315| 

$C$RL5:    ; CALL OCCURS {printf} {0}        ; |315| 
           MVKL    .S2     $C$SL3+0,B4

           MVKH    .S2     $C$SL3+0,B4
||         STDW    .D2T1   A13:A12,*+SP(8)   ; |316| 

$C$DW$30	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$30, DW_AT_low_pc(0x00)
	.dwattr $C$DW$30, DW_AT_name("printf")
	.dwattr $C$DW$30, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STW     .D2T2   B4,*+SP(4)        ; |316| 

$C$RL6:    ; CALL OCCURS {printf} {0}        ; |316| 
           MVKL    .S1     $C$SL4+0,A3

           MVKH    .S1     $C$SL4+0,A3
||         STDW    .D2T2   B11:B10,*+SP(8)   ; |317| 

$C$DW$31	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$31, DW_AT_low_pc(0x00)
	.dwattr $C$DW$31, DW_AT_name("printf")
	.dwattr $C$DW$31, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STW     .D2T1   A3,*+SP(4)        ; |317| 

$C$RL7:    ; CALL OCCURS {printf} {0}        ; |317| 
           MVKL    .S1     $C$SL5+0,A3

           MVKH    .S1     $C$SL5+0,A3
||         STDW    .D2T2   B13:B12,*+SP(8)   ; |318| 

$C$DW$32	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$32, DW_AT_low_pc(0x00)
	.dwattr $C$DW$32, DW_AT_name("printf")
	.dwattr $C$DW$32, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STW     .D2T1   A3,*+SP(4)        ; |318| 

$C$RL8:    ; CALL OCCURS {printf} {0}        ; |318| 
           MVKL    .S1     $C$SL6+0,A3

           MVKH    .S1     $C$SL6+0,A3
||         STDW    .D2T1   A11:A10,*+SP(8)   ; |319| 

$C$DW$33	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$33, DW_AT_low_pc(0x00)
	.dwattr $C$DW$33, DW_AT_name("printf")
	.dwattr $C$DW$33, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STW     .D2T1   A3,*+SP(4)        ; |319| 

$C$RL9:    ; CALL OCCURS {printf} {0}        ; |319| 
           LDDW    .D2T1   *+SP(48),A5:A4    ; |321| 
           MVKL    .S2     $C$SL7+0,B10
           MVKH    .S2     $C$SL7+0,B10
           STW     .D2T2   B10,*+SP(4)       ; |321| 
           NOP             1
           STDW    .D2T1   A5:A4,*+SP(16)    ; |321| 
           LDDW    .D2T1   *+SP(56),A5:A4    ; |321| 
           NOP             4
$C$DW$34	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$34, DW_AT_low_pc(0x00)
	.dwattr $C$DW$34, DW_AT_name("printf")
	.dwattr $C$DW$34, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STDW    .D2T1   A5:A4,*+SP(24)    ; |321| 

$C$RL10:   ; CALL OCCURS {printf} {0}        ; |321| 
           LDDW    .D2T1   *+SP(64),A5:A4    ; |321| 
           STW     .D2T2   B10,*+SP(4)       ; |322| 
           NOP             3
           STDW    .D2T1   A5:A4,*+SP(16)    ; |322| 
           LDDW    .D2T1   *+SP(72),A5:A4    ; |322| 
           NOP             4
$C$DW$35	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$35, DW_AT_low_pc(0x00)
	.dwattr $C$DW$35, DW_AT_name("printf")
	.dwattr $C$DW$35, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STDW    .D2T1   A5:A4,*+SP(24)    ; |322| 

$C$RL11:   ; CALL OCCURS {printf} {0}        ; |322| 
;** --------------------------------------------------------------------------*
           LDDW    .D2T2   *+SP(160),B13:B12 ; |322| 
;** --------------------------------------------------------------------------*
;** 323	-----------------------    printf((const char *)C$1, x5);
;** 324	-----------------------    printf((const char *)C$1, x6);
;** 325	-----------------------    printf((const char *)C$1, x7);
;** 326	-----------------------    printf((const char *)C$1, x8);
;** 327	-----------------------    printf((const char *)C$1, x9);
;** 335	-----------------------    printf((const char *)"MOPS SPFP time used:%f\n", timeUsed);
;** 336	-----------------------    printf((const char *)"Throughput:%f\n", throughput);
;** 340	-----------------------    return 0;
           LDDW    .D2T1   *+SP(80),A5:A4
           STW     .D2T2   B10,*+SP(4)       ; |323| 
           NOP             3
           STDW    .D2T1   A5:A4,*+SP(16)    ; |323| 
           LDDW    .D2T1   *+SP(88),A5:A4    ; |323| 
           NOP             4
$C$DW$36	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$36, DW_AT_low_pc(0x00)
	.dwattr $C$DW$36, DW_AT_name("printf")
	.dwattr $C$DW$36, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STDW    .D2T1   A5:A4,*+SP(24)    ; |323| 

$C$RL12:   ; CALL OCCURS {printf} {0}        ; |323| 
;** --------------------------------------------------------------------------*
           LDDW    .D2T1   *+SP(96),A5:A4    ; |323| 
           STW     .D2T2   B10,*+SP(4)       ; |324| 
           NOP             3
           STDW    .D2T1   A5:A4,*+SP(16)    ; |324| 
           LDDW    .D2T1   *+SP(104),A5:A4   ; |324| 
           NOP             4
$C$DW$37	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$37, DW_AT_low_pc(0x00)
	.dwattr $C$DW$37, DW_AT_name("printf")
	.dwattr $C$DW$37, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STDW    .D2T1   A5:A4,*+SP(24)    ; |324| 

$C$RL13:   ; CALL OCCURS {printf} {0}        ; |324| 
           LDDW    .D2T1   *+SP(112),A5:A4   ; |324| 
           STW     .D2T2   B10,*+SP(4)       ; |325| 
           NOP             3
           STDW    .D2T1   A5:A4,*+SP(16)    ; |325| 
           LDDW    .D2T1   *+SP(120),A5:A4   ; |325| 
           NOP             4
$C$DW$38	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$38, DW_AT_low_pc(0x00)
	.dwattr $C$DW$38, DW_AT_name("printf")
	.dwattr $C$DW$38, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STDW    .D2T1   A5:A4,*+SP(24)    ; |325| 

$C$RL14:   ; CALL OCCURS {printf} {0}        ; |325| 
           LDDW    .D2T1   *+SP(128),A5:A4   ; |325| 
           STW     .D2T2   B10,*+SP(4)       ; |326| 
           NOP             3
           STDW    .D2T1   A5:A4,*+SP(16)    ; |326| 
           LDDW    .D2T1   *+SP(136),A5:A4   ; |326| 
           NOP             4
$C$DW$39	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$39, DW_AT_low_pc(0x00)
	.dwattr $C$DW$39, DW_AT_name("printf")
	.dwattr $C$DW$39, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STDW    .D2T1   A5:A4,*+SP(24)    ; |326| 

$C$RL15:   ; CALL OCCURS {printf} {0}        ; |326| 
           LDDW    .D2T1   *+SP(144),A5:A4   ; |326| 
           STW     .D2T2   B10,*+SP(4)       ; |327| 
           NOP             3
           STDW    .D2T1   A5:A4,*+SP(16)    ; |327| 
           LDDW    .D2T1   *+SP(152),A5:A4   ; |327| 
           NOP             4
$C$DW$40	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$40, DW_AT_low_pc(0x00)
	.dwattr $C$DW$40, DW_AT_name("printf")
	.dwattr $C$DW$40, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STDW    .D2T1   A5:A4,*+SP(24)    ; |327| 

$C$RL16:   ; CALL OCCURS {printf} {0}        ; |327| 
           LDDW    .D2T2   *+SP(40),B5:B4    ; |335| 
           MVKL    .S1     $C$SL8+0,A3
           MVKH    .S1     $C$SL8+0,A3
           STW     .D2T1   A3,*+SP(4)        ; |335| 
           NOP             1
$C$DW$41	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$41, DW_AT_low_pc(0x00)
	.dwattr $C$DW$41, DW_AT_name("printf")
	.dwattr $C$DW$41, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STDW    .D2T2   B5:B4,*+SP(8)     ; |335| 

$C$RL17:   ; CALL OCCURS {printf} {0}        ; |335| 
           MVKL    .S2     $C$SL9+0,B4

           MVKH    .S2     $C$SL9+0,B4
||         STDW    .D2T2   B13:B12,*+SP(8)   ; |336| 

$C$DW$42	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$42, DW_AT_low_pc(0x00)
	.dwattr $C$DW$42, DW_AT_name("printf")
	.dwattr $C$DW$42, DW_AT_TI_call

           CALLP   .S2     printf,B3
||         STW     .D2T2   B4,*+SP(4)        ; |336| 

$C$RL18:   ; CALL OCCURS {printf} {0}        ; |336| 
;** --------------------------------------------------------------------------*
           ADDK    .S2     168,SP            ; |341| 
           LDDW    .D2T1   *++SP,A11:A10     ; |341| 
           LDDW    .D2T1   *++SP,A13:A12     ; |341| 

           LDDW    .D2T2   *++SP,B11:B10     ; |341| 
||         MV      .L2X    A14,B3            ; |341| 

$C$DW$43	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$43, DW_AT_low_pc(0x04)
	.dwattr $C$DW$43, DW_AT_TI_return

           LDDW    .D2T2   *++SP,B13:B12     ; |341| 
||         RET     .S2     B3                ; |341| 

           LDW     .D2T1   *++SP(8),A14      ; |341| 
           ZERO    .L1     A4                ; |340| 
	.dwpsn	file "../src/vector_stream_sp.c",line 341,column 1,is_stmt,isa 0
           NOP             3
           ; BRANCH OCCURS {B3}              ; |341| 

$C$DW$44	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$44, DW_AT_name("A:\F5\TMS320C6678-Benchmarks\benchmarks\vector_stream\Release\vector_stream_sp.asm:$C$L1:1:1378502938")
	.dwattr $C$DW$44, DW_AT_TI_begin_file("../src/vector_stream_sp.c")
	.dwattr $C$DW$44, DW_AT_TI_begin_line(0xb8)
	.dwattr $C$DW$44, DW_AT_TI_end_line(0x129)
$C$DW$45	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$45, DW_AT_low_pc($C$DW$L$vector_stream_sp$2$B)
	.dwattr $C$DW$45, DW_AT_high_pc($C$DW$L$vector_stream_sp$2$E)
	.dwendtag $C$DW$44

	.dwattr $C$DW$24, DW_AT_TI_end_file("../src/vector_stream_sp.c")
	.dwattr $C$DW$24, DW_AT_TI_end_line(0x155)
	.dwattr $C$DW$24, DW_AT_TI_end_column(0x01)
	.dwendtag $C$DW$24

;******************************************************************************
;* STRINGS                                                                    *
;******************************************************************************
	.sect	".const:.string"
$C$SL1:	.string	"x1:%f",10,0
$C$SL2:	.string	"x9:%f",10,0
$C$SL3:	.string	"v6:%f",10,0
$C$SL4:	.string	"u6:%f",10,0
$C$SL5:	.string	"v3:%f",10,0
$C$SL6:	.string	"u3:%f",10,0
$C$SL7:	.string	"%f",10,0
$C$SL8:	.string	"MOPS SPFP time used:%f",10,0
$C$SL9:	.string	"Throughput:%f",10,0
;*****************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                             *
;*****************************************************************************
	.global	printf
	.global	__c6xabi_divd
	.global	__c6xabi_fltulld

;******************************************************************************
;* BUILD ATTRIBUTES                                                           *
;******************************************************************************
	.battr "TI", Tag_File, 1, Tag_Long_Precision_Bits(2)
	.battr "TI", Tag_File, 1, Tag_Bitfield_layout(2)
	.battr "TI", Tag_File, 1, Tag_ABI_enum_size(2)
	.battr "c6xabi", Tag_File, 1, Tag_ABI_wchar_t(1)
	.battr "c6xabi", Tag_File, 1, Tag_ABI_array_object_alignment(0)
	.battr "c6xabi", Tag_File, 1, Tag_ABI_array_object_align_expected(0)
	.battr "c6xabi", Tag_File, 1, Tag_ABI_PIC(0)
	.battr "c6xabi", Tag_File, 1, Tag_ABI_PID(0)
	.battr "c6xabi", Tag_File, 1, Tag_ABI_DSBT(0)
	.battr "c6xabi", Tag_File, 1, Tag_ABI_stack_align_needed(0)
	.battr "c6xabi", Tag_File, 1, Tag_ABI_stack_align_preserved(0)
	.battr "TI", Tag_File, 1, Tag_Tramps_Use_SOC(1)

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************

$C$DW$T$82	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$82, DW_AT_byte_size(0x18)
$C$DW$46	.dwtag  DW_TAG_member
	.dwattr $C$DW$46, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$46, DW_AT_name("fd")
	.dwattr $C$DW$46, DW_AT_TI_symbol_name("fd")
	.dwattr $C$DW$46, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$46, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$46, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$46, DW_AT_decl_line(0x49)
	.dwattr $C$DW$46, DW_AT_decl_column(0x0b)
$C$DW$47	.dwtag  DW_TAG_member
	.dwattr $C$DW$47, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$47, DW_AT_name("buf")
	.dwattr $C$DW$47, DW_AT_TI_symbol_name("buf")
	.dwattr $C$DW$47, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$47, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$47, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$47, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$47, DW_AT_decl_column(0x16)
$C$DW$48	.dwtag  DW_TAG_member
	.dwattr $C$DW$48, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$48, DW_AT_name("pos")
	.dwattr $C$DW$48, DW_AT_TI_symbol_name("pos")
	.dwattr $C$DW$48, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$48, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$48, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$48, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$48, DW_AT_decl_column(0x16)
$C$DW$49	.dwtag  DW_TAG_member
	.dwattr $C$DW$49, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$49, DW_AT_name("bufend")
	.dwattr $C$DW$49, DW_AT_TI_symbol_name("bufend")
	.dwattr $C$DW$49, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$49, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$49, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$49, DW_AT_decl_line(0x4c)
	.dwattr $C$DW$49, DW_AT_decl_column(0x16)
$C$DW$50	.dwtag  DW_TAG_member
	.dwattr $C$DW$50, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$50, DW_AT_name("buff_stop")
	.dwattr $C$DW$50, DW_AT_TI_symbol_name("buff_stop")
	.dwattr $C$DW$50, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$50, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$50, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$50, DW_AT_decl_line(0x4d)
	.dwattr $C$DW$50, DW_AT_decl_column(0x16)
$C$DW$51	.dwtag  DW_TAG_member
	.dwattr $C$DW$51, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$51, DW_AT_name("flags")
	.dwattr $C$DW$51, DW_AT_TI_symbol_name("flags")
	.dwattr $C$DW$51, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$51, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$51, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$51, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$51, DW_AT_decl_column(0x16)
	.dwendtag $C$DW$T$82

	.dwattr $C$DW$T$82, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$T$82, DW_AT_decl_line(0x48)
	.dwattr $C$DW$T$82, DW_AT_decl_column(0x10)
$C$DW$T$245	.dwtag  DW_TAG_typedef, DW_AT_name("FILE")
	.dwattr $C$DW$T$245, DW_AT_type(*$C$DW$T$82)
	.dwattr $C$DW$T$245, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$245, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$T$245, DW_AT_decl_line(0x4f)
	.dwattr $C$DW$T$245, DW_AT_decl_column(0x03)
$C$DW$T$2	.dwtag  DW_TAG_unspecified_type
	.dwattr $C$DW$T$2, DW_AT_name("void")
$C$DW$T$3	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$3, DW_AT_type(*$C$DW$T$2)
	.dwattr $C$DW$T$3, DW_AT_address_class(0x20)
$C$DW$T$135	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Ptr")
	.dwattr $C$DW$T$135, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$T$135, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$135, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$135, DW_AT_decl_line(0x2e)
	.dwattr $C$DW$T$135, DW_AT_decl_column(0x1a)
$C$DW$T$246	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__gateObj")
	.dwattr $C$DW$T$246, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$246, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$246, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$246, DW_AT_decl_line(0x7c)
	.dwattr $C$DW$T$246, DW_AT_decl_column(0x11)
$C$DW$T$247	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__gatePrms")
	.dwattr $C$DW$T$247, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$247, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$247, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$247, DW_AT_decl_line(0x80)
	.dwattr $C$DW$T$247, DW_AT_decl_column(0x11)
$C$DW$T$248	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__loggerObj")
	.dwattr $C$DW$T$248, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$248, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$248, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$248, DW_AT_decl_line(0x8c)
	.dwattr $C$DW$T$248, DW_AT_decl_column(0x11)
$C$DW$T$249	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Object__table")
	.dwattr $C$DW$T$249, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$249, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$249, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$249, DW_AT_decl_line(0xb4)
	.dwattr $C$DW$T$249, DW_AT_decl_column(0x11)
$C$DW$T$250	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__gateObj")
	.dwattr $C$DW$T$250, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$250, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$250, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$250, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$T$250, DW_AT_decl_column(0x11)
$C$DW$T$251	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__gatePrms")
	.dwattr $C$DW$T$251, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$251, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$251, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$251, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$T$251, DW_AT_decl_column(0x11)
$C$DW$T$252	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__loggerObj")
	.dwattr $C$DW$T$252, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$252, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$252, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$252, DW_AT_decl_line(0x6a)
	.dwattr $C$DW$T$252, DW_AT_decl_column(0x11)
$C$DW$T$253	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Object__table")
	.dwattr $C$DW$T$253, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$253, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$253, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$253, DW_AT_decl_line(0x92)
	.dwattr $C$DW$T$253, DW_AT_decl_column(0x11)
$C$DW$T$254	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__gateObj")
	.dwattr $C$DW$T$254, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$254, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$254, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$254, DW_AT_decl_line(0x58)
	.dwattr $C$DW$T$254, DW_AT_decl_column(0x11)
$C$DW$T$255	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__gatePrms")
	.dwattr $C$DW$T$255, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$255, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$255, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$255, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$T$255, DW_AT_decl_column(0x11)
$C$DW$T$256	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__loggerObj")
	.dwattr $C$DW$T$256, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$256, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$256, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$256, DW_AT_decl_line(0x68)
	.dwattr $C$DW$T$256, DW_AT_decl_column(0x11)
$C$DW$T$257	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Object__table")
	.dwattr $C$DW$T$257, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$257, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$257, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$257, DW_AT_decl_line(0x90)
	.dwattr $C$DW$T$257, DW_AT_decl_column(0x11)
$C$DW$T$258	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__gateObj")
	.dwattr $C$DW$T$258, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$258, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$258, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$258, DW_AT_decl_line(0x54)
	.dwattr $C$DW$T$258, DW_AT_decl_column(0x11)
$C$DW$T$259	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__gatePrms")
	.dwattr $C$DW$T$259, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$259, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$259, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$259, DW_AT_decl_line(0x58)
	.dwattr $C$DW$T$259, DW_AT_decl_column(0x11)
$C$DW$T$260	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__loggerObj")
	.dwattr $C$DW$T$260, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$260, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$260, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$260, DW_AT_decl_line(0x64)
	.dwattr $C$DW$T$260, DW_AT_decl_column(0x11)
$C$DW$T$261	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Object__table")
	.dwattr $C$DW$T$261, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$261, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$261, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$261, DW_AT_decl_line(0x8c)
	.dwattr $C$DW$T$261, DW_AT_decl_column(0x11)
$C$DW$T$262	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__gateObj")
	.dwattr $C$DW$T$262, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$262, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$262, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$262, DW_AT_decl_line(0x66)
	.dwattr $C$DW$T$262, DW_AT_decl_column(0x11)
$C$DW$T$263	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__gatePrms")
	.dwattr $C$DW$T$263, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$263, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$263, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$263, DW_AT_decl_line(0x6a)
	.dwattr $C$DW$T$263, DW_AT_decl_column(0x11)
$C$DW$T$264	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__loggerObj")
	.dwattr $C$DW$T$264, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$264, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$264, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$264, DW_AT_decl_line(0x76)
	.dwattr $C$DW$T$264, DW_AT_decl_column(0x11)
$C$DW$T$265	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Object__table")
	.dwattr $C$DW$T$265, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$265, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$265, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$265, DW_AT_decl_line(0x9e)
	.dwattr $C$DW$T$265, DW_AT_decl_column(0x11)
$C$DW$T$266	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__gateObj")
	.dwattr $C$DW$T$266, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$266, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$266, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$266, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$T$266, DW_AT_decl_column(0x11)
$C$DW$T$267	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__gatePrms")
	.dwattr $C$DW$T$267, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$267, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$267, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$267, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$T$267, DW_AT_decl_column(0x11)
$C$DW$T$268	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__loggerObj")
	.dwattr $C$DW$T$268, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$268, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$268, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$268, DW_AT_decl_line(0x6a)
	.dwattr $C$DW$T$268, DW_AT_decl_column(0x11)
$C$DW$T$269	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Object__table")
	.dwattr $C$DW$T$269, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$269, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$269, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$269, DW_AT_decl_line(0x92)
	.dwattr $C$DW$T$269, DW_AT_decl_column(0x11)
$C$DW$T$270	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__gateObj")
	.dwattr $C$DW$T$270, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$270, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$270, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$270, DW_AT_decl_line(0x51)
	.dwattr $C$DW$T$270, DW_AT_decl_column(0x11)
$C$DW$T$271	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__gatePrms")
	.dwattr $C$DW$T$271, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$271, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$271, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$271, DW_AT_decl_line(0x55)
	.dwattr $C$DW$T$271, DW_AT_decl_column(0x11)
$C$DW$T$272	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerObj")
	.dwattr $C$DW$T$272, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$272, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$272, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$272, DW_AT_decl_line(0x61)
	.dwattr $C$DW$T$272, DW_AT_decl_column(0x11)
$C$DW$T$273	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Object__table")
	.dwattr $C$DW$T$273, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$273, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$273, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$273, DW_AT_decl_line(0x89)
	.dwattr $C$DW$T$273, DW_AT_decl_column(0x11)
$C$DW$T$274	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__gateObj")
	.dwattr $C$DW$T$274, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$274, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$274, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$274, DW_AT_decl_line(0xda)
	.dwattr $C$DW$T$274, DW_AT_decl_column(0x11)
$C$DW$T$275	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__gatePrms")
	.dwattr $C$DW$T$275, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$275, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$275, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$275, DW_AT_decl_line(0xde)
	.dwattr $C$DW$T$275, DW_AT_decl_column(0x11)
$C$DW$T$276	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__loggerObj")
	.dwattr $C$DW$T$276, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$276, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$276, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$276, DW_AT_decl_line(0xea)
	.dwattr $C$DW$T$276, DW_AT_decl_column(0x11)
$C$DW$T$277	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Object__table")
	.dwattr $C$DW$T$277, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$277, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$277, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$277, DW_AT_decl_line(0x112)
	.dwattr $C$DW$T$277, DW_AT_decl_column(0x11)
$C$DW$T$280	.dwtag  DW_TAG_typedef, DW_AT_name("Ptr")
	.dwattr $C$DW$T$280, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$280, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$280, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$280, DW_AT_decl_line(0xe4)
	.dwattr $C$DW$T$280, DW_AT_decl_column(0x19)

$C$DW$T$139	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$139, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$139, DW_AT_language(DW_LANG_C)
$C$DW$52	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$52, DW_AT_type(*$C$DW$T$3)
$C$DW$53	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$53, DW_AT_type(*$C$DW$T$136)
$C$DW$54	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$54, DW_AT_type(*$C$DW$T$136)
$C$DW$55	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$55, DW_AT_type(*$C$DW$T$138)
	.dwendtag $C$DW$T$139

$C$DW$T$140	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$140, DW_AT_type(*$C$DW$T$139)
	.dwattr $C$DW$T$140, DW_AT_address_class(0x20)
$C$DW$T$278	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IHeap_alloc_FxnT")
	.dwattr $C$DW$T$278, DW_AT_type(*$C$DW$T$140)
	.dwattr $C$DW$T$278, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$278, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$T$278, DW_AT_decl_line(0xa2)
	.dwattr $C$DW$T$278, DW_AT_decl_column(0x13)
$C$DW$T$279	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_HeapProxy_alloc_FxnT")
	.dwattr $C$DW$T$279, DW_AT_type(*$C$DW$T$140)
	.dwattr $C$DW$T$279, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$279, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$279, DW_AT_decl_line(0x10c)
	.dwattr $C$DW$T$279, DW_AT_decl_column(0x13)

$C$DW$T$192	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$192, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$192, DW_AT_language(DW_LANG_C)
$C$DW$56	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$56, DW_AT_type(*$C$DW$T$191)
$C$DW$57	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$57, DW_AT_type(*$C$DW$T$136)
$C$DW$58	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$58, DW_AT_type(*$C$DW$T$136)
$C$DW$59	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$59, DW_AT_type(*$C$DW$T$138)
	.dwendtag $C$DW$T$192

$C$DW$T$193	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$193, DW_AT_type(*$C$DW$T$192)
	.dwattr $C$DW$T$193, DW_AT_address_class(0x20)

$C$DW$T$228	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$228, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$228, DW_AT_language(DW_LANG_C)
$C$DW$60	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$60, DW_AT_type(*$C$DW$T$135)
$C$DW$61	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$61, DW_AT_type(*$C$DW$T$136)
$C$DW$62	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$62, DW_AT_type(*$C$DW$T$227)
$C$DW$63	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$63, DW_AT_type(*$C$DW$T$227)
$C$DW$64	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$64, DW_AT_type(*$C$DW$T$136)
$C$DW$65	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$65, DW_AT_type(*$C$DW$T$138)
	.dwendtag $C$DW$T$228

$C$DW$T$229	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$229, DW_AT_type(*$C$DW$T$228)
	.dwattr $C$DW$T$229, DW_AT_address_class(0x20)

$C$DW$T$240	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$240, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$T$240, DW_AT_language(DW_LANG_C)
$C$DW$66	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$66, DW_AT_type(*$C$DW$T$135)
$C$DW$67	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$67, DW_AT_type(*$C$DW$T$136)
$C$DW$68	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$68, DW_AT_type(*$C$DW$T$227)
$C$DW$69	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$69, DW_AT_type(*$C$DW$T$239)
$C$DW$70	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$70, DW_AT_type(*$C$DW$T$136)
$C$DW$71	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$71, DW_AT_type(*$C$DW$T$138)
	.dwendtag $C$DW$T$240

$C$DW$T$241	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$241, DW_AT_type(*$C$DW$T$240)
	.dwattr $C$DW$T$241, DW_AT_address_class(0x20)
$C$DW$T$227	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$227, DW_AT_type(*$C$DW$T$135)

$C$DW$T$123	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$123, DW_AT_language(DW_LANG_C)
$C$DW$72	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$72, DW_AT_type(*$C$DW$T$3)
$C$DW$73	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$73, DW_AT_type(*$C$DW$T$88)
	.dwendtag $C$DW$T$123

$C$DW$T$124	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$124, DW_AT_type(*$C$DW$T$123)
	.dwattr $C$DW$T$124, DW_AT_address_class(0x20)
$C$DW$T$281	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IGateProvider_leave_FxnT")
	.dwattr $C$DW$T$281, DW_AT_type(*$C$DW$T$124)
	.dwattr $C$DW$T$281, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$281, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$T$281, DW_AT_decl_line(0xad)
	.dwattr $C$DW$T$281, DW_AT_decl_column(0x14)
$C$DW$T$282	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Main_Module_GateProxy_leave_FxnT")
	.dwattr $C$DW$T$282, DW_AT_type(*$C$DW$T$124)
	.dwattr $C$DW$T$282, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$282, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$282, DW_AT_decl_line(0x111)
	.dwattr $C$DW$T$282, DW_AT_decl_column(0x14)
$C$DW$T$127	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$127, DW_AT_type(*$C$DW$T$2)
$C$DW$T$128	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$128, DW_AT_type(*$C$DW$T$127)
	.dwattr $C$DW$T$128, DW_AT_address_class(0x20)

$C$DW$T$141	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$141, DW_AT_language(DW_LANG_C)
$C$DW$74	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$74, DW_AT_type(*$C$DW$T$3)
$C$DW$75	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$75, DW_AT_type(*$C$DW$T$135)
$C$DW$76	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$76, DW_AT_type(*$C$DW$T$136)
	.dwendtag $C$DW$T$141

$C$DW$T$142	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$142, DW_AT_type(*$C$DW$T$141)
	.dwattr $C$DW$T$142, DW_AT_address_class(0x20)
$C$DW$T$283	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IHeap_free_FxnT")
	.dwattr $C$DW$T$283, DW_AT_type(*$C$DW$T$142)
	.dwattr $C$DW$T$283, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$283, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$T$283, DW_AT_decl_line(0xa9)
	.dwattr $C$DW$T$283, DW_AT_decl_column(0x14)
$C$DW$T$284	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_HeapProxy_free_FxnT")
	.dwattr $C$DW$T$284, DW_AT_type(*$C$DW$T$142)
	.dwattr $C$DW$T$284, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$284, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$284, DW_AT_decl_line(0x113)
	.dwattr $C$DW$T$284, DW_AT_decl_column(0x14)

$C$DW$T$147	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$147, DW_AT_language(DW_LANG_C)
$C$DW$77	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$77, DW_AT_type(*$C$DW$T$3)
$C$DW$78	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$78, DW_AT_type(*$C$DW$T$146)
	.dwendtag $C$DW$T$147

$C$DW$T$148	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$148, DW_AT_type(*$C$DW$T$147)
	.dwattr $C$DW$T$148, DW_AT_address_class(0x20)
$C$DW$T$285	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IHeap_getStats_FxnT")
	.dwattr $C$DW$T$285, DW_AT_type(*$C$DW$T$148)
	.dwattr $C$DW$T$285, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$285, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$T$285, DW_AT_decl_line(0xb7)
	.dwattr $C$DW$T$285, DW_AT_decl_column(0x14)
$C$DW$T$286	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_HeapProxy_getStats_FxnT")
	.dwattr $C$DW$T$286, DW_AT_type(*$C$DW$T$148)
	.dwattr $C$DW$T$286, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$286, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$286, DW_AT_decl_line(0x121)
	.dwattr $C$DW$T$286, DW_AT_decl_column(0x14)

$C$DW$T$167	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$167, DW_AT_language(DW_LANG_C)
$C$DW$79	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$79, DW_AT_type(*$C$DW$T$166)
	.dwendtag $C$DW$T$167

$C$DW$T$168	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$168, DW_AT_type(*$C$DW$T$167)
	.dwattr $C$DW$T$168, DW_AT_address_class(0x20)
$C$DW$T$287	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampClient_get64_FxnT")
	.dwattr $C$DW$T$287, DW_AT_type(*$C$DW$T$168)
	.dwattr $C$DW$T$287, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$287, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$T$287, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$T$287, DW_AT_decl_column(0x14)
$C$DW$T$288	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampProvider_get64_FxnT")
	.dwattr $C$DW$T$288, DW_AT_type(*$C$DW$T$168)
	.dwattr $C$DW$T$288, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$288, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$T$288, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$T$288, DW_AT_decl_column(0x14)

$C$DW$T$171	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$171, DW_AT_language(DW_LANG_C)
$C$DW$80	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$80, DW_AT_type(*$C$DW$T$170)
	.dwendtag $C$DW$T$171

$C$DW$T$172	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$172, DW_AT_type(*$C$DW$T$171)
	.dwattr $C$DW$T$172, DW_AT_address_class(0x20)
$C$DW$T$289	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampClient_getFreq_FxnT")
	.dwattr $C$DW$T$289, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$T$289, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$289, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$T$289, DW_AT_decl_line(0x81)
	.dwattr $C$DW$T$289, DW_AT_decl_column(0x14)
$C$DW$T$290	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampProvider_getFreq_FxnT")
	.dwattr $C$DW$T$290, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$T$290, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$290, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$T$290, DW_AT_decl_line(0x81)
	.dwattr $C$DW$T$290, DW_AT_decl_column(0x14)

$C$DW$T$179	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$179, DW_AT_language(DW_LANG_C)
$C$DW$81	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$81, DW_AT_type(*$C$DW$T$176)
$C$DW$82	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$82, DW_AT_type(*$C$DW$T$88)
	.dwendtag $C$DW$T$179

$C$DW$T$180	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$180, DW_AT_type(*$C$DW$T$179)
	.dwattr $C$DW$T$180, DW_AT_address_class(0x20)

$C$DW$T$194	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$194, DW_AT_language(DW_LANG_C)
$C$DW$83	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$83, DW_AT_type(*$C$DW$T$191)
$C$DW$84	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$84, DW_AT_type(*$C$DW$T$135)
$C$DW$85	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$85, DW_AT_type(*$C$DW$T$136)
	.dwendtag $C$DW$T$194

$C$DW$T$195	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$195, DW_AT_type(*$C$DW$T$194)
	.dwattr $C$DW$T$195, DW_AT_address_class(0x20)

$C$DW$T$198	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$198, DW_AT_language(DW_LANG_C)
$C$DW$86	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$86, DW_AT_type(*$C$DW$T$191)
$C$DW$87	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$87, DW_AT_type(*$C$DW$T$146)
	.dwendtag $C$DW$T$198

$C$DW$T$199	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$199, DW_AT_type(*$C$DW$T$198)
	.dwattr $C$DW$T$199, DW_AT_address_class(0x20)

$C$DW$T$230	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$230, DW_AT_language(DW_LANG_C)
$C$DW$88	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$88, DW_AT_type(*$C$DW$T$135)
	.dwendtag $C$DW$T$230

$C$DW$T$231	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$231, DW_AT_type(*$C$DW$T$230)
	.dwattr $C$DW$T$231, DW_AT_address_class(0x20)

$C$DW$T$292	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$292, DW_AT_language(DW_LANG_C)
$C$DW$89	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$89, DW_AT_type(*$C$DW$T$135)
$C$DW$90	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$90, DW_AT_type(*$C$DW$T$291)
$C$DW$91	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$91, DW_AT_type(*$C$DW$T$217)
	.dwendtag $C$DW$T$292

$C$DW$T$293	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$293, DW_AT_type(*$C$DW$T$292)
	.dwattr $C$DW$T$293, DW_AT_address_class(0x20)
$C$DW$T$294	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_LoggerFxn0")
	.dwattr $C$DW$T$294, DW_AT_type(*$C$DW$T$293)
	.dwattr $C$DW$T$294, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$294, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$294, DW_AT_decl_line(0x8c)
	.dwattr $C$DW$T$294, DW_AT_decl_column(0x14)
$C$DW$T$295	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__loggerFxn0")
	.dwattr $C$DW$T$295, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$T$295, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$295, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$295, DW_AT_decl_line(0x90)
	.dwattr $C$DW$T$295, DW_AT_decl_column(0x26)
$C$DW$T$296	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__loggerFxn0")
	.dwattr $C$DW$T$296, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$T$296, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$296, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$296, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$T$296, DW_AT_decl_column(0x26)
$C$DW$T$297	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__loggerFxn0")
	.dwattr $C$DW$T$297, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$T$297, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$297, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$297, DW_AT_decl_line(0x6c)
	.dwattr $C$DW$T$297, DW_AT_decl_column(0x26)
$C$DW$T$298	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn0")
	.dwattr $C$DW$T$298, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$T$298, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$298, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$298, DW_AT_decl_line(0x68)
	.dwattr $C$DW$T$298, DW_AT_decl_column(0x26)
$C$DW$T$299	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__loggerFxn0")
	.dwattr $C$DW$T$299, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$T$299, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$299, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$299, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$T$299, DW_AT_decl_column(0x26)
$C$DW$T$300	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__loggerFxn0")
	.dwattr $C$DW$T$300, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$T$300, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$300, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$300, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$T$300, DW_AT_decl_column(0x26)
$C$DW$T$301	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn0")
	.dwattr $C$DW$T$301, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$T$301, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$301, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$301, DW_AT_decl_line(0x65)
	.dwattr $C$DW$T$301, DW_AT_decl_column(0x26)
$C$DW$T$302	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__loggerFxn0")
	.dwattr $C$DW$T$302, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$T$302, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$302, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$302, DW_AT_decl_line(0xee)
	.dwattr $C$DW$T$302, DW_AT_decl_column(0x26)

$C$DW$T$303	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$303, DW_AT_language(DW_LANG_C)
$C$DW$92	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$92, DW_AT_type(*$C$DW$T$135)
$C$DW$93	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$93, DW_AT_type(*$C$DW$T$291)
$C$DW$94	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$94, DW_AT_type(*$C$DW$T$217)
$C$DW$95	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$95, DW_AT_type(*$C$DW$T$88)
	.dwendtag $C$DW$T$303

$C$DW$T$304	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$304, DW_AT_type(*$C$DW$T$303)
	.dwattr $C$DW$T$304, DW_AT_address_class(0x20)
$C$DW$T$305	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_LoggerFxn1")
	.dwattr $C$DW$T$305, DW_AT_type(*$C$DW$T$304)
	.dwattr $C$DW$T$305, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$305, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$305, DW_AT_decl_line(0x8f)
	.dwattr $C$DW$T$305, DW_AT_decl_column(0x14)
$C$DW$T$306	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__loggerFxn1")
	.dwattr $C$DW$T$306, DW_AT_type(*$C$DW$T$305)
	.dwattr $C$DW$T$306, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$306, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$306, DW_AT_decl_line(0x94)
	.dwattr $C$DW$T$306, DW_AT_decl_column(0x26)
$C$DW$T$307	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__loggerFxn1")
	.dwattr $C$DW$T$307, DW_AT_type(*$C$DW$T$305)
	.dwattr $C$DW$T$307, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$307, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$307, DW_AT_decl_line(0x72)
	.dwattr $C$DW$T$307, DW_AT_decl_column(0x26)
$C$DW$T$308	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__loggerFxn1")
	.dwattr $C$DW$T$308, DW_AT_type(*$C$DW$T$305)
	.dwattr $C$DW$T$308, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$308, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$308, DW_AT_decl_line(0x70)
	.dwattr $C$DW$T$308, DW_AT_decl_column(0x26)
$C$DW$T$309	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn1")
	.dwattr $C$DW$T$309, DW_AT_type(*$C$DW$T$305)
	.dwattr $C$DW$T$309, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$309, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$309, DW_AT_decl_line(0x6c)
	.dwattr $C$DW$T$309, DW_AT_decl_column(0x26)
$C$DW$T$310	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__loggerFxn1")
	.dwattr $C$DW$T$310, DW_AT_type(*$C$DW$T$305)
	.dwattr $C$DW$T$310, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$310, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$310, DW_AT_decl_line(0x7e)
	.dwattr $C$DW$T$310, DW_AT_decl_column(0x26)
$C$DW$T$311	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__loggerFxn1")
	.dwattr $C$DW$T$311, DW_AT_type(*$C$DW$T$305)
	.dwattr $C$DW$T$311, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$311, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$311, DW_AT_decl_line(0x72)
	.dwattr $C$DW$T$311, DW_AT_decl_column(0x26)
$C$DW$T$312	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn1")
	.dwattr $C$DW$T$312, DW_AT_type(*$C$DW$T$305)
	.dwattr $C$DW$T$312, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$312, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$312, DW_AT_decl_line(0x69)
	.dwattr $C$DW$T$312, DW_AT_decl_column(0x26)
$C$DW$T$313	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__loggerFxn1")
	.dwattr $C$DW$T$313, DW_AT_type(*$C$DW$T$305)
	.dwattr $C$DW$T$313, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$313, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$313, DW_AT_decl_line(0xf2)
	.dwattr $C$DW$T$313, DW_AT_decl_column(0x26)

$C$DW$T$314	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$314, DW_AT_language(DW_LANG_C)
$C$DW$96	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$96, DW_AT_type(*$C$DW$T$135)
$C$DW$97	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$97, DW_AT_type(*$C$DW$T$291)
$C$DW$98	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$98, DW_AT_type(*$C$DW$T$217)
$C$DW$99	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$99, DW_AT_type(*$C$DW$T$88)
$C$DW$100	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$100, DW_AT_type(*$C$DW$T$88)
	.dwendtag $C$DW$T$314

$C$DW$T$315	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$315, DW_AT_type(*$C$DW$T$314)
	.dwattr $C$DW$T$315, DW_AT_address_class(0x20)
$C$DW$T$316	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_LoggerFxn2")
	.dwattr $C$DW$T$316, DW_AT_type(*$C$DW$T$315)
	.dwattr $C$DW$T$316, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$316, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$316, DW_AT_decl_line(0x92)
	.dwattr $C$DW$T$316, DW_AT_decl_column(0x14)
$C$DW$T$317	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__loggerFxn2")
	.dwattr $C$DW$T$317, DW_AT_type(*$C$DW$T$316)
	.dwattr $C$DW$T$317, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$317, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$317, DW_AT_decl_line(0x98)
	.dwattr $C$DW$T$317, DW_AT_decl_column(0x26)
$C$DW$T$318	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__loggerFxn2")
	.dwattr $C$DW$T$318, DW_AT_type(*$C$DW$T$316)
	.dwattr $C$DW$T$318, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$318, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$318, DW_AT_decl_line(0x76)
	.dwattr $C$DW$T$318, DW_AT_decl_column(0x26)
$C$DW$T$319	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__loggerFxn2")
	.dwattr $C$DW$T$319, DW_AT_type(*$C$DW$T$316)
	.dwattr $C$DW$T$319, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$319, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$319, DW_AT_decl_line(0x74)
	.dwattr $C$DW$T$319, DW_AT_decl_column(0x26)
$C$DW$T$320	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn2")
	.dwattr $C$DW$T$320, DW_AT_type(*$C$DW$T$316)
	.dwattr $C$DW$T$320, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$320, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$320, DW_AT_decl_line(0x70)
	.dwattr $C$DW$T$320, DW_AT_decl_column(0x26)
$C$DW$T$321	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__loggerFxn2")
	.dwattr $C$DW$T$321, DW_AT_type(*$C$DW$T$316)
	.dwattr $C$DW$T$321, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$321, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$321, DW_AT_decl_line(0x82)
	.dwattr $C$DW$T$321, DW_AT_decl_column(0x26)
$C$DW$T$322	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__loggerFxn2")
	.dwattr $C$DW$T$322, DW_AT_type(*$C$DW$T$316)
	.dwattr $C$DW$T$322, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$322, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$322, DW_AT_decl_line(0x76)
	.dwattr $C$DW$T$322, DW_AT_decl_column(0x26)
$C$DW$T$323	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn2")
	.dwattr $C$DW$T$323, DW_AT_type(*$C$DW$T$316)
	.dwattr $C$DW$T$323, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$323, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$323, DW_AT_decl_line(0x6d)
	.dwattr $C$DW$T$323, DW_AT_decl_column(0x26)
$C$DW$T$324	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__loggerFxn2")
	.dwattr $C$DW$T$324, DW_AT_type(*$C$DW$T$316)
	.dwattr $C$DW$T$324, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$324, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$324, DW_AT_decl_line(0xf6)
	.dwattr $C$DW$T$324, DW_AT_decl_column(0x26)

$C$DW$T$325	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$325, DW_AT_language(DW_LANG_C)
$C$DW$101	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$101, DW_AT_type(*$C$DW$T$135)
$C$DW$102	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$102, DW_AT_type(*$C$DW$T$291)
$C$DW$103	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$103, DW_AT_type(*$C$DW$T$217)
$C$DW$104	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$104, DW_AT_type(*$C$DW$T$88)
$C$DW$105	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$105, DW_AT_type(*$C$DW$T$88)
$C$DW$106	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$106, DW_AT_type(*$C$DW$T$88)
$C$DW$107	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$107, DW_AT_type(*$C$DW$T$88)
	.dwendtag $C$DW$T$325

$C$DW$T$326	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$326, DW_AT_type(*$C$DW$T$325)
	.dwattr $C$DW$T$326, DW_AT_address_class(0x20)
$C$DW$T$327	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_LoggerFxn4")
	.dwattr $C$DW$T$327, DW_AT_type(*$C$DW$T$326)
	.dwattr $C$DW$T$327, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$327, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$327, DW_AT_decl_line(0x95)
	.dwattr $C$DW$T$327, DW_AT_decl_column(0x14)
$C$DW$T$328	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__loggerFxn4")
	.dwattr $C$DW$T$328, DW_AT_type(*$C$DW$T$327)
	.dwattr $C$DW$T$328, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$328, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$328, DW_AT_decl_line(0x9c)
	.dwattr $C$DW$T$328, DW_AT_decl_column(0x26)
$C$DW$T$329	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__loggerFxn4")
	.dwattr $C$DW$T$329, DW_AT_type(*$C$DW$T$327)
	.dwattr $C$DW$T$329, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$329, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$329, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$T$329, DW_AT_decl_column(0x26)
$C$DW$T$330	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__loggerFxn4")
	.dwattr $C$DW$T$330, DW_AT_type(*$C$DW$T$327)
	.dwattr $C$DW$T$330, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$330, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$330, DW_AT_decl_line(0x78)
	.dwattr $C$DW$T$330, DW_AT_decl_column(0x26)
$C$DW$T$331	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn4")
	.dwattr $C$DW$T$331, DW_AT_type(*$C$DW$T$327)
	.dwattr $C$DW$T$331, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$331, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$331, DW_AT_decl_line(0x74)
	.dwattr $C$DW$T$331, DW_AT_decl_column(0x26)
$C$DW$T$332	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__loggerFxn4")
	.dwattr $C$DW$T$332, DW_AT_type(*$C$DW$T$327)
	.dwattr $C$DW$T$332, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$332, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$332, DW_AT_decl_line(0x86)
	.dwattr $C$DW$T$332, DW_AT_decl_column(0x26)
$C$DW$T$333	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__loggerFxn4")
	.dwattr $C$DW$T$333, DW_AT_type(*$C$DW$T$327)
	.dwattr $C$DW$T$333, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$333, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$333, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$T$333, DW_AT_decl_column(0x26)
$C$DW$T$334	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn4")
	.dwattr $C$DW$T$334, DW_AT_type(*$C$DW$T$327)
	.dwattr $C$DW$T$334, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$334, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$334, DW_AT_decl_line(0x71)
	.dwattr $C$DW$T$334, DW_AT_decl_column(0x26)
$C$DW$T$335	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__loggerFxn4")
	.dwattr $C$DW$T$335, DW_AT_type(*$C$DW$T$327)
	.dwattr $C$DW$T$335, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$335, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$335, DW_AT_decl_line(0xfa)
	.dwattr $C$DW$T$335, DW_AT_decl_column(0x26)

$C$DW$T$336	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$336, DW_AT_language(DW_LANG_C)
$C$DW$108	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$108, DW_AT_type(*$C$DW$T$135)
$C$DW$109	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$109, DW_AT_type(*$C$DW$T$291)
$C$DW$110	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$110, DW_AT_type(*$C$DW$T$217)
$C$DW$111	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$111, DW_AT_type(*$C$DW$T$88)
$C$DW$112	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$112, DW_AT_type(*$C$DW$T$88)
$C$DW$113	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$113, DW_AT_type(*$C$DW$T$88)
$C$DW$114	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$114, DW_AT_type(*$C$DW$T$88)
$C$DW$115	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$115, DW_AT_type(*$C$DW$T$88)
$C$DW$116	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$116, DW_AT_type(*$C$DW$T$88)
$C$DW$117	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$117, DW_AT_type(*$C$DW$T$88)
$C$DW$118	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$118, DW_AT_type(*$C$DW$T$88)
	.dwendtag $C$DW$T$336

$C$DW$T$337	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$337, DW_AT_type(*$C$DW$T$336)
	.dwattr $C$DW$T$337, DW_AT_address_class(0x20)
$C$DW$T$338	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_LoggerFxn8")
	.dwattr $C$DW$T$338, DW_AT_type(*$C$DW$T$337)
	.dwattr $C$DW$T$338, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$338, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$338, DW_AT_decl_line(0x98)
	.dwattr $C$DW$T$338, DW_AT_decl_column(0x14)
$C$DW$T$339	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__loggerFxn8")
	.dwattr $C$DW$T$339, DW_AT_type(*$C$DW$T$338)
	.dwattr $C$DW$T$339, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$339, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$339, DW_AT_decl_line(0xa0)
	.dwattr $C$DW$T$339, DW_AT_decl_column(0x26)
$C$DW$T$340	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__loggerFxn8")
	.dwattr $C$DW$T$340, DW_AT_type(*$C$DW$T$338)
	.dwattr $C$DW$T$340, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$340, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$340, DW_AT_decl_line(0x7e)
	.dwattr $C$DW$T$340, DW_AT_decl_column(0x26)
$C$DW$T$341	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__loggerFxn8")
	.dwattr $C$DW$T$341, DW_AT_type(*$C$DW$T$338)
	.dwattr $C$DW$T$341, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$341, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$341, DW_AT_decl_line(0x7c)
	.dwattr $C$DW$T$341, DW_AT_decl_column(0x26)
$C$DW$T$342	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn8")
	.dwattr $C$DW$T$342, DW_AT_type(*$C$DW$T$338)
	.dwattr $C$DW$T$342, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$342, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$342, DW_AT_decl_line(0x78)
	.dwattr $C$DW$T$342, DW_AT_decl_column(0x26)
$C$DW$T$343	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__loggerFxn8")
	.dwattr $C$DW$T$343, DW_AT_type(*$C$DW$T$338)
	.dwattr $C$DW$T$343, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$343, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$343, DW_AT_decl_line(0x8a)
	.dwattr $C$DW$T$343, DW_AT_decl_column(0x26)
$C$DW$T$344	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__loggerFxn8")
	.dwattr $C$DW$T$344, DW_AT_type(*$C$DW$T$338)
	.dwattr $C$DW$T$344, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$344, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$344, DW_AT_decl_line(0x7e)
	.dwattr $C$DW$T$344, DW_AT_decl_column(0x26)
$C$DW$T$345	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn8")
	.dwattr $C$DW$T$345, DW_AT_type(*$C$DW$T$338)
	.dwattr $C$DW$T$345, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$345, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$345, DW_AT_decl_line(0x75)
	.dwattr $C$DW$T$345, DW_AT_decl_column(0x26)
$C$DW$T$346	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__loggerFxn8")
	.dwattr $C$DW$T$346, DW_AT_type(*$C$DW$T$338)
	.dwattr $C$DW$T$346, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$346, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$346, DW_AT_decl_line(0xfe)
	.dwattr $C$DW$T$346, DW_AT_decl_column(0x26)

$C$DW$T$347	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$347, DW_AT_language(DW_LANG_C)
$C$DW$119	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$119, DW_AT_type(*$C$DW$T$138)
	.dwendtag $C$DW$T$347

$C$DW$T$348	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$348, DW_AT_type(*$C$DW$T$347)
	.dwattr $C$DW$T$348, DW_AT_address_class(0x20)
$C$DW$T$349	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Error_HookFxn")
	.dwattr $C$DW$T$349, DW_AT_type(*$C$DW$T$348)
	.dwattr $C$DW$T$349, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$349, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$349, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$T$349, DW_AT_decl_column(0x14)
$C$DW$T$350	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_raiseHook")
	.dwattr $C$DW$T$350, DW_AT_type(*$C$DW$T$349)
	.dwattr $C$DW$T$350, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$350, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$350, DW_AT_decl_line(0xcd)
	.dwattr $C$DW$T$350, DW_AT_decl_column(0x23)
$C$DW$T$4	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$4, DW_AT_encoding(DW_ATE_boolean)
	.dwattr $C$DW$T$4, DW_AT_name("bool")
	.dwattr $C$DW$T$4, DW_AT_byte_size(0x01)
$C$DW$T$5	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$5, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$5, DW_AT_name("signed char")
	.dwattr $C$DW$T$5, DW_AT_byte_size(0x01)
$C$DW$T$361	.dwtag  DW_TAG_typedef, DW_AT_name("int8_t")
	.dwattr $C$DW$T$361, DW_AT_type(*$C$DW$T$5)
	.dwattr $C$DW$T$361, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$361, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$361, DW_AT_decl_line(0x2a)
	.dwattr $C$DW$T$361, DW_AT_decl_column(0x1d)
$C$DW$T$362	.dwtag  DW_TAG_typedef, DW_AT_name("int_least8_t")
	.dwattr $C$DW$T$362, DW_AT_type(*$C$DW$T$361)
	.dwattr $C$DW$T$362, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$362, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$362, DW_AT_decl_line(0x39)
	.dwattr $C$DW$T$362, DW_AT_decl_column(0x17)
$C$DW$T$363	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Int8")
	.dwattr $C$DW$T$363, DW_AT_type(*$C$DW$T$362)
	.dwattr $C$DW$T$363, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$363, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$363, DW_AT_decl_line(0x6d)
	.dwattr $C$DW$T$363, DW_AT_decl_column(0x19)
$C$DW$T$364	.dwtag  DW_TAG_typedef, DW_AT_name("Int8")
	.dwattr $C$DW$T$364, DW_AT_type(*$C$DW$T$363)
	.dwattr $C$DW$T$364, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$364, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$364, DW_AT_decl_line(0xe0)
	.dwattr $C$DW$T$364, DW_AT_decl_column(0x19)
$C$DW$T$6	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr $C$DW$T$6, DW_AT_name("unsigned char")
	.dwattr $C$DW$T$6, DW_AT_byte_size(0x01)
$C$DW$T$81	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$81, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$81, DW_AT_address_class(0x20)
$C$DW$T$366	.dwtag  DW_TAG_typedef, DW_AT_name("uint8_t")
	.dwattr $C$DW$T$366, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$366, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$366, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$366, DW_AT_decl_line(0x2b)
	.dwattr $C$DW$T$366, DW_AT_decl_column(0x1c)
$C$DW$T$369	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least8_t")
	.dwattr $C$DW$T$369, DW_AT_type(*$C$DW$T$366)
	.dwattr $C$DW$T$369, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$369, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$369, DW_AT_decl_line(0x3a)
	.dwattr $C$DW$T$369, DW_AT_decl_column(0x16)
$C$DW$T$370	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UInt8")
	.dwattr $C$DW$T$370, DW_AT_type(*$C$DW$T$369)
	.dwattr $C$DW$T$370, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$370, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$370, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$T$370, DW_AT_decl_column(0x19)
$C$DW$T$371	.dwtag  DW_TAG_typedef, DW_AT_name("UInt8")
	.dwattr $C$DW$T$371, DW_AT_type(*$C$DW$T$370)
	.dwattr $C$DW$T$371, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$371, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$371, DW_AT_decl_line(0xe7)
	.dwattr $C$DW$T$371, DW_AT_decl_column(0x19)
$C$DW$T$372	.dwtag  DW_TAG_typedef, DW_AT_name("Uint8")
	.dwattr $C$DW$T$372, DW_AT_type(*$C$DW$T$370)
	.dwattr $C$DW$T$372, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$372, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$372, DW_AT_decl_line(0xf4)
	.dwattr $C$DW$T$372, DW_AT_decl_column(0x19)
$C$DW$T$367	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Bits8")
	.dwattr $C$DW$T$367, DW_AT_type(*$C$DW$T$366)
	.dwattr $C$DW$T$367, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$367, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$367, DW_AT_decl_line(0x8a)
	.dwattr $C$DW$T$367, DW_AT_decl_column(0x19)
$C$DW$T$368	.dwtag  DW_TAG_typedef, DW_AT_name("Bits8")
	.dwattr $C$DW$T$368, DW_AT_type(*$C$DW$T$367)
	.dwattr $C$DW$T$368, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$368, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$368, DW_AT_decl_line(0x108)
	.dwattr $C$DW$T$368, DW_AT_decl_column(0x19)
$C$DW$T$237	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UChar")
	.dwattr $C$DW$T$237, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$237, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$237, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$237, DW_AT_decl_line(0x1e)
	.dwattr $C$DW$T$237, DW_AT_decl_column(0x19)
$C$DW$T$365	.dwtag  DW_TAG_typedef, DW_AT_name("UChar")
	.dwattr $C$DW$T$365, DW_AT_type(*$C$DW$T$237)
	.dwattr $C$DW$T$365, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$365, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$365, DW_AT_decl_line(0xce)
	.dwattr $C$DW$T$365, DW_AT_decl_column(0x19)
$C$DW$T$238	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$238, DW_AT_type(*$C$DW$T$237)
$C$DW$T$239	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$239, DW_AT_type(*$C$DW$T$238)
	.dwattr $C$DW$T$239, DW_AT_address_class(0x20)
$C$DW$T$7	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$7, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$7, DW_AT_name("wchar_t")
	.dwattr $C$DW$T$7, DW_AT_byte_size(0x02)
$C$DW$T$8	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$8, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$8, DW_AT_name("short")
	.dwattr $C$DW$T$8, DW_AT_byte_size(0x02)
$C$DW$T$375	.dwtag  DW_TAG_typedef, DW_AT_name("int16_t")
	.dwattr $C$DW$T$375, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$T$375, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$375, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$375, DW_AT_decl_line(0x2c)
	.dwattr $C$DW$T$375, DW_AT_decl_column(0x1d)
$C$DW$T$376	.dwtag  DW_TAG_typedef, DW_AT_name("int_least16_t")
	.dwattr $C$DW$T$376, DW_AT_type(*$C$DW$T$375)
	.dwattr $C$DW$T$376, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$376, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$376, DW_AT_decl_line(0x3c)
	.dwattr $C$DW$T$376, DW_AT_decl_column(0x17)
$C$DW$T$377	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Int16")
	.dwattr $C$DW$T$377, DW_AT_type(*$C$DW$T$376)
	.dwattr $C$DW$T$377, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$377, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$377, DW_AT_decl_line(0x6f)
	.dwattr $C$DW$T$377, DW_AT_decl_column(0x19)
$C$DW$T$378	.dwtag  DW_TAG_typedef, DW_AT_name("Int16")
	.dwattr $C$DW$T$378, DW_AT_type(*$C$DW$T$377)
	.dwattr $C$DW$T$378, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$378, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$378, DW_AT_decl_line(0xe1)
	.dwattr $C$DW$T$378, DW_AT_decl_column(0x19)
$C$DW$T$373	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Short")
	.dwattr $C$DW$T$373, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$T$373, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$373, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$373, DW_AT_decl_line(0x1f)
	.dwattr $C$DW$T$373, DW_AT_decl_column(0x19)
$C$DW$T$374	.dwtag  DW_TAG_typedef, DW_AT_name("Short")
	.dwattr $C$DW$T$374, DW_AT_type(*$C$DW$T$373)
	.dwattr $C$DW$T$374, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$374, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$374, DW_AT_decl_line(0xcf)
	.dwattr $C$DW$T$374, DW_AT_decl_column(0x19)
$C$DW$T$9	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$9, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$9, DW_AT_name("unsigned short")
	.dwattr $C$DW$T$9, DW_AT_byte_size(0x02)
$C$DW$T$90	.dwtag  DW_TAG_typedef, DW_AT_name("uint16_t")
	.dwattr $C$DW$T$90, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$90, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$90, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$90, DW_AT_decl_line(0x2d)
	.dwattr $C$DW$T$90, DW_AT_decl_column(0x1c)
$C$DW$T$91	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least16_t")
	.dwattr $C$DW$T$91, DW_AT_type(*$C$DW$T$90)
	.dwattr $C$DW$T$91, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$91, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$91, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$T$91, DW_AT_decl_column(0x16)
$C$DW$T$92	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UInt16")
	.dwattr $C$DW$T$92, DW_AT_type(*$C$DW$T$91)
	.dwattr $C$DW$T$92, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$92, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$92, DW_AT_decl_line(0x70)
	.dwattr $C$DW$T$92, DW_AT_decl_column(0x19)
$C$DW$T$424	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_maxDepth")
	.dwattr $C$DW$T$424, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$T$424, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$424, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$424, DW_AT_decl_line(0xd5)
	.dwattr $C$DW$T$424, DW_AT_decl_column(0x14)
$C$DW$T$423	.dwtag  DW_TAG_typedef, DW_AT_name("UInt16")
	.dwattr $C$DW$T$423, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$T$423, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$423, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$423, DW_AT_decl_line(0xe8)
	.dwattr $C$DW$T$423, DW_AT_decl_column(0x19)
$C$DW$T$425	.dwtag  DW_TAG_typedef, DW_AT_name("Uint16")
	.dwattr $C$DW$T$425, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$T$425, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$425, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$425, DW_AT_decl_line(0xf5)
	.dwattr $C$DW$T$425, DW_AT_decl_column(0x19)
$C$DW$T$216	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Bits16")
	.dwattr $C$DW$T$216, DW_AT_type(*$C$DW$T$90)
	.dwattr $C$DW$T$216, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$216, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$216, DW_AT_decl_line(0x8d)
	.dwattr $C$DW$T$216, DW_AT_decl_column(0x19)
$C$DW$T$422	.dwtag  DW_TAG_typedef, DW_AT_name("Bits16")
	.dwattr $C$DW$T$422, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$T$422, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$422, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$422, DW_AT_decl_line(0x10c)
	.dwattr $C$DW$T$422, DW_AT_decl_column(0x19)
$C$DW$T$404	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$404, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$T$404, DW_AT_address_class(0x20)
$C$DW$T$405	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__diagsMask")
	.dwattr $C$DW$T$405, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$T$405, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$405, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$405, DW_AT_decl_line(0x78)
	.dwattr $C$DW$T$405, DW_AT_decl_column(0x15)
$C$DW$T$406	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__diagsMask")
	.dwattr $C$DW$T$406, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$T$406, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$406, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$406, DW_AT_decl_line(0x56)
	.dwattr $C$DW$T$406, DW_AT_decl_column(0x15)
$C$DW$T$407	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__diagsMask")
	.dwattr $C$DW$T$407, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$T$407, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$407, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$407, DW_AT_decl_line(0x54)
	.dwattr $C$DW$T$407, DW_AT_decl_column(0x15)
$C$DW$T$408	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__diagsMask")
	.dwattr $C$DW$T$408, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$T$408, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$408, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$408, DW_AT_decl_line(0x50)
	.dwattr $C$DW$T$408, DW_AT_decl_column(0x15)
$C$DW$T$409	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__diagsMask")
	.dwattr $C$DW$T$409, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$T$409, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$409, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$409, DW_AT_decl_line(0x62)
	.dwattr $C$DW$T$409, DW_AT_decl_column(0x15)
$C$DW$T$410	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__diagsMask")
	.dwattr $C$DW$T$410, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$T$410, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$410, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$410, DW_AT_decl_line(0x56)
	.dwattr $C$DW$T$410, DW_AT_decl_column(0x15)
$C$DW$T$411	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsMask")
	.dwattr $C$DW$T$411, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$T$411, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$411, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$411, DW_AT_decl_line(0x4d)
	.dwattr $C$DW$T$411, DW_AT_decl_column(0x15)
$C$DW$T$412	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__diagsMask")
	.dwattr $C$DW$T$412, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$T$412, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$412, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$412, DW_AT_decl_line(0xd6)
	.dwattr $C$DW$T$412, DW_AT_decl_column(0x15)
$C$DW$T$224	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_DiagsMask")
	.dwattr $C$DW$T$224, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$T$224, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$224, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$224, DW_AT_decl_line(0x41)
	.dwattr $C$DW$T$224, DW_AT_decl_column(0x14)
$C$DW$T$217	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_ModuleId")
	.dwattr $C$DW$T$217, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$T$217, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$217, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$217, DW_AT_decl_line(0x3e)
	.dwattr $C$DW$T$217, DW_AT_decl_column(0x14)
$C$DW$T$413	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__id")
	.dwattr $C$DW$T$413, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$413, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$413, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$413, DW_AT_decl_line(0x84)
	.dwattr $C$DW$T$413, DW_AT_decl_column(0x24)
$C$DW$T$414	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__id")
	.dwattr $C$DW$T$414, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$414, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$414, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$414, DW_AT_decl_line(0x62)
	.dwattr $C$DW$T$414, DW_AT_decl_column(0x24)
$C$DW$T$415	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__id")
	.dwattr $C$DW$T$415, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$415, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$415, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$415, DW_AT_decl_line(0x60)
	.dwattr $C$DW$T$415, DW_AT_decl_column(0x24)
$C$DW$T$416	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__id")
	.dwattr $C$DW$T$416, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$416, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$416, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$416, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$T$416, DW_AT_decl_column(0x24)
$C$DW$T$417	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__id")
	.dwattr $C$DW$T$417, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$417, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$417, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$417, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$T$417, DW_AT_decl_column(0x24)
$C$DW$T$418	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__id")
	.dwattr $C$DW$T$418, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$418, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$418, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$418, DW_AT_decl_line(0x62)
	.dwattr $C$DW$T$418, DW_AT_decl_column(0x24)
$C$DW$T$419	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__id")
	.dwattr $C$DW$T$419, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$419, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$419, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$419, DW_AT_decl_line(0x59)
	.dwattr $C$DW$T$419, DW_AT_decl_column(0x24)
$C$DW$T$420	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__id")
	.dwattr $C$DW$T$420, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$420, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$420, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$420, DW_AT_decl_line(0xe2)
	.dwattr $C$DW$T$420, DW_AT_decl_column(0x24)
$C$DW$T$421	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_RopeId")
	.dwattr $C$DW$T$421, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$T$421, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$421, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$421, DW_AT_decl_line(0x56)
	.dwattr $C$DW$T$421, DW_AT_decl_column(0x14)
$C$DW$T$379	.dwtag  DW_TAG_typedef, DW_AT_name("wchar_t")
	.dwattr $C$DW$T$379, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$379, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$379, DW_AT_decl_file("C:/ti/include/stddef.h")
	.dwattr $C$DW$T$379, DW_AT_decl_line(0x3c)
	.dwattr $C$DW$T$379, DW_AT_decl_column(0x1a)
$C$DW$T$117	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Bool")
	.dwattr $C$DW$T$117, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$117, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$117, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$117, DW_AT_decl_line(0x2d)
	.dwattr $C$DW$T$117, DW_AT_decl_column(0x19)
$C$DW$T$401	.dwtag  DW_TAG_typedef, DW_AT_name("Bool")
	.dwattr $C$DW$T$401, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$401, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$401, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$401, DW_AT_decl_line(0xdf)
	.dwattr $C$DW$T$401, DW_AT_decl_column(0x19)
$C$DW$T$380	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__loggerDefined")
	.dwattr $C$DW$T$380, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$380, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$380, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$380, DW_AT_decl_line(0x88)
	.dwattr $C$DW$T$380, DW_AT_decl_column(0x12)
$C$DW$T$381	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__loggerDefined")
	.dwattr $C$DW$T$381, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$381, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$381, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$381, DW_AT_decl_line(0x66)
	.dwattr $C$DW$T$381, DW_AT_decl_column(0x12)
$C$DW$T$382	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__loggerDefined")
	.dwattr $C$DW$T$382, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$382, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$382, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$382, DW_AT_decl_line(0x64)
	.dwattr $C$DW$T$382, DW_AT_decl_column(0x12)
$C$DW$T$383	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__loggerDefined")
	.dwattr $C$DW$T$383, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$383, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$383, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$383, DW_AT_decl_line(0x60)
	.dwattr $C$DW$T$383, DW_AT_decl_column(0x12)
$C$DW$T$384	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__loggerDefined")
	.dwattr $C$DW$T$384, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$384, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$384, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$384, DW_AT_decl_line(0x72)
	.dwattr $C$DW$T$384, DW_AT_decl_column(0x12)
$C$DW$T$385	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__loggerDefined")
	.dwattr $C$DW$T$385, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$385, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$385, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$385, DW_AT_decl_line(0x66)
	.dwattr $C$DW$T$385, DW_AT_decl_column(0x12)
$C$DW$T$386	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerDefined")
	.dwattr $C$DW$T$386, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$386, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$386, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$386, DW_AT_decl_line(0x5d)
	.dwattr $C$DW$T$386, DW_AT_decl_column(0x12)
$C$DW$T$387	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__loggerDefined")
	.dwattr $C$DW$T$387, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$387, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$387, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$387, DW_AT_decl_line(0xe6)
	.dwattr $C$DW$T$387, DW_AT_decl_column(0x12)

$C$DW$T$119	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$119, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$119, DW_AT_language(DW_LANG_C)
$C$DW$120	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$120, DW_AT_type(*$C$DW$T$118)
	.dwendtag $C$DW$T$119

$C$DW$T$120	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$120, DW_AT_type(*$C$DW$T$119)
	.dwattr $C$DW$T$120, DW_AT_address_class(0x20)
$C$DW$T$388	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IGateProvider_query_FxnT")
	.dwattr $C$DW$T$388, DW_AT_type(*$C$DW$T$120)
	.dwattr $C$DW$T$388, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$388, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$T$388, DW_AT_decl_line(0x9f)
	.dwattr $C$DW$T$388, DW_AT_decl_column(0x14)

$C$DW$T$143	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$143, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$143, DW_AT_language(DW_LANG_C)
$C$DW$121	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$121, DW_AT_type(*$C$DW$T$3)
	.dwendtag $C$DW$T$143

$C$DW$T$144	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$144, DW_AT_type(*$C$DW$T$143)
	.dwattr $C$DW$T$144, DW_AT_address_class(0x20)
$C$DW$T$389	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IHeap_isBlocking_FxnT")
	.dwattr $C$DW$T$389, DW_AT_type(*$C$DW$T$144)
	.dwattr $C$DW$T$389, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$389, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$T$389, DW_AT_decl_line(0xb0)
	.dwattr $C$DW$T$389, DW_AT_decl_column(0x14)
$C$DW$T$390	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_HeapProxy_isBlocking_FxnT")
	.dwattr $C$DW$T$390, DW_AT_type(*$C$DW$T$144)
	.dwattr $C$DW$T$390, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$390, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$390, DW_AT_decl_line(0x11a)
	.dwattr $C$DW$T$390, DW_AT_decl_column(0x14)

$C$DW$T$196	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$196, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$196, DW_AT_language(DW_LANG_C)
$C$DW$122	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$122, DW_AT_type(*$C$DW$T$191)
	.dwendtag $C$DW$T$196

$C$DW$T$197	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$197, DW_AT_type(*$C$DW$T$196)
	.dwattr $C$DW$T$197, DW_AT_address_class(0x20)

$C$DW$T$391	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$391, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$391, DW_AT_language(DW_LANG_C)
$C$DW$T$392	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$392, DW_AT_type(*$C$DW$T$391)
	.dwattr $C$DW$T$392, DW_AT_address_class(0x20)
$C$DW$T$393	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__startupDoneFxn")
	.dwattr $C$DW$T$393, DW_AT_type(*$C$DW$T$392)
	.dwattr $C$DW$T$393, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$393, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$393, DW_AT_decl_line(0xa4)
	.dwattr $C$DW$T$393, DW_AT_decl_column(0x14)
$C$DW$T$394	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__startupDoneFxn")
	.dwattr $C$DW$T$394, DW_AT_type(*$C$DW$T$392)
	.dwattr $C$DW$T$394, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$394, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$394, DW_AT_decl_line(0x82)
	.dwattr $C$DW$T$394, DW_AT_decl_column(0x14)
$C$DW$T$395	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__startupDoneFxn")
	.dwattr $C$DW$T$395, DW_AT_type(*$C$DW$T$392)
	.dwattr $C$DW$T$395, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$395, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$395, DW_AT_decl_line(0x80)
	.dwattr $C$DW$T$395, DW_AT_decl_column(0x14)
$C$DW$T$396	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__startupDoneFxn")
	.dwattr $C$DW$T$396, DW_AT_type(*$C$DW$T$392)
	.dwattr $C$DW$T$396, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$396, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$396, DW_AT_decl_line(0x7c)
	.dwattr $C$DW$T$396, DW_AT_decl_column(0x14)
$C$DW$T$397	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__startupDoneFxn")
	.dwattr $C$DW$T$397, DW_AT_type(*$C$DW$T$392)
	.dwattr $C$DW$T$397, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$397, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$397, DW_AT_decl_line(0x8e)
	.dwattr $C$DW$T$397, DW_AT_decl_column(0x14)
$C$DW$T$398	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__startupDoneFxn")
	.dwattr $C$DW$T$398, DW_AT_type(*$C$DW$T$392)
	.dwattr $C$DW$T$398, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$398, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$398, DW_AT_decl_line(0x82)
	.dwattr $C$DW$T$398, DW_AT_decl_column(0x14)
$C$DW$T$399	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__startupDoneFxn")
	.dwattr $C$DW$T$399, DW_AT_type(*$C$DW$T$392)
	.dwattr $C$DW$T$399, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$399, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$399, DW_AT_decl_line(0x79)
	.dwattr $C$DW$T$399, DW_AT_decl_column(0x14)
$C$DW$T$400	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__startupDoneFxn")
	.dwattr $C$DW$T$400, DW_AT_type(*$C$DW$T$392)
	.dwattr $C$DW$T$400, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$400, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$400, DW_AT_decl_line(0x102)
	.dwattr $C$DW$T$400, DW_AT_decl_column(0x14)
$C$DW$T$402	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UShort")
	.dwattr $C$DW$T$402, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$402, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$402, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$402, DW_AT_decl_line(0x20)
	.dwattr $C$DW$T$402, DW_AT_decl_column(0x19)
$C$DW$T$403	.dwtag  DW_TAG_typedef, DW_AT_name("UShort")
	.dwattr $C$DW$T$403, DW_AT_type(*$C$DW$T$402)
	.dwattr $C$DW$T$403, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$403, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$403, DW_AT_decl_line(0xd0)
	.dwattr $C$DW$T$403, DW_AT_decl_column(0x19)
$C$DW$T$10	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$10, DW_AT_name("int")
	.dwattr $C$DW$T$10, DW_AT_byte_size(0x04)

$C$DW$T$431	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$431, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$431, DW_AT_language(DW_LANG_C)
$C$DW$T$432	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$432, DW_AT_type(*$C$DW$T$431)
	.dwattr $C$DW$T$432, DW_AT_address_class(0x20)
$C$DW$T$433	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Fxn")
	.dwattr $C$DW$T$433, DW_AT_type(*$C$DW$T$432)
	.dwattr $C$DW$T$433, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$433, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$433, DW_AT_decl_line(0x42)
	.dwattr $C$DW$T$433, DW_AT_decl_column(0x1d)
$C$DW$T$434	.dwtag  DW_TAG_typedef, DW_AT_name("Fxn")
	.dwattr $C$DW$T$434, DW_AT_type(*$C$DW$T$433)
	.dwattr $C$DW$T$434, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$434, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$434, DW_AT_decl_line(0xe3)
	.dwattr $C$DW$T$434, DW_AT_decl_column(0x19)
$C$DW$T$459	.dwtag  DW_TAG_typedef, DW_AT_name("fpos_t")
	.dwattr $C$DW$T$459, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$459, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$459, DW_AT_decl_file("C:/ti/include/stdio.h")
	.dwattr $C$DW$T$459, DW_AT_decl_line(0x53)
	.dwattr $C$DW$T$459, DW_AT_decl_column(0x0d)
$C$DW$T$83	.dwtag  DW_TAG_typedef, DW_AT_name("int32_t")
	.dwattr $C$DW$T$83, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$83, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$83, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$83, DW_AT_decl_line(0x2e)
	.dwattr $C$DW$T$83, DW_AT_decl_column(0x1d)

$C$DW$T$84	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$84, DW_AT_type(*$C$DW$T$83)
	.dwattr $C$DW$T$84, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$84, DW_AT_byte_size(0x10)
$C$DW$123	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$123, DW_AT_upper_bound(0x03)
	.dwendtag $C$DW$T$84

$C$DW$T$448	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast16_t")
	.dwattr $C$DW$T$448, DW_AT_type(*$C$DW$T$83)
	.dwattr $C$DW$T$448, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$448, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$448, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$T$448, DW_AT_decl_column(0x17)
$C$DW$T$449	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast32_t")
	.dwattr $C$DW$T$449, DW_AT_type(*$C$DW$T$83)
	.dwattr $C$DW$T$449, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$449, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$449, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$T$449, DW_AT_decl_column(0x17)
$C$DW$T$450	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast8_t")
	.dwattr $C$DW$T$450, DW_AT_type(*$C$DW$T$83)
	.dwattr $C$DW$T$450, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$450, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$450, DW_AT_decl_line(0x49)
	.dwattr $C$DW$T$450, DW_AT_decl_column(0x17)
$C$DW$T$451	.dwtag  DW_TAG_typedef, DW_AT_name("int_least32_t")
	.dwattr $C$DW$T$451, DW_AT_type(*$C$DW$T$83)
	.dwattr $C$DW$T$451, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$451, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$451, DW_AT_decl_line(0x3e)
	.dwattr $C$DW$T$451, DW_AT_decl_column(0x17)
$C$DW$T$452	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Int32")
	.dwattr $C$DW$T$452, DW_AT_type(*$C$DW$T$451)
	.dwattr $C$DW$T$452, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$452, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$452, DW_AT_decl_line(0x71)
	.dwattr $C$DW$T$452, DW_AT_decl_column(0x19)
$C$DW$T$453	.dwtag  DW_TAG_typedef, DW_AT_name("Int32")
	.dwattr $C$DW$T$453, DW_AT_type(*$C$DW$T$452)
	.dwattr $C$DW$T$453, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$453, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$453, DW_AT_decl_line(0xe2)
	.dwattr $C$DW$T$453, DW_AT_decl_column(0x19)
$C$DW$T$87	.dwtag  DW_TAG_typedef, DW_AT_name("intptr_t")
	.dwattr $C$DW$T$87, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$87, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$87, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$87, DW_AT_decl_line(0x58)
	.dwattr $C$DW$T$87, DW_AT_decl_column(0x1a)
$C$DW$T$88	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_IArg")
	.dwattr $C$DW$T$88, DW_AT_type(*$C$DW$T$87)
	.dwattr $C$DW$T$88, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$88, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$88, DW_AT_decl_line(0x99)
	.dwattr $C$DW$T$88, DW_AT_decl_column(0x19)
$C$DW$T$454	.dwtag  DW_TAG_typedef, DW_AT_name("IArg")
	.dwattr $C$DW$T$454, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$T$454, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$454, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$454, DW_AT_decl_line(0xdd)
	.dwattr $C$DW$T$454, DW_AT_decl_column(0x19)
$C$DW$T$455	.dwtag  DW_TAG_typedef, DW_AT_name("__T1_xdc_runtime_Error_Block__xtra")
	.dwattr $C$DW$T$455, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$T$455, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$455, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$455, DW_AT_decl_line(0x59)
	.dwattr $C$DW$T$455, DW_AT_decl_column(0x12)
$C$DW$T$456	.dwtag  DW_TAG_typedef, DW_AT_name("__T1_xdc_runtime_Error_Data__arg")
	.dwattr $C$DW$T$456, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$T$456, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$456, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$456, DW_AT_decl_line(0x51)
	.dwattr $C$DW$T$456, DW_AT_decl_column(0x12)

$C$DW$T$101	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$101, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$T$101, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$101, DW_AT_byte_size(0x10)
$C$DW$124	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$124, DW_AT_upper_bound(0x03)
	.dwendtag $C$DW$T$101

$C$DW$T$102	.dwtag  DW_TAG_typedef, DW_AT_name("__ARRAY1_xdc_runtime_Error_Block__xtra")
	.dwattr $C$DW$T$102, DW_AT_type(*$C$DW$T$101)
	.dwattr $C$DW$T$102, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$102, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$102, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$T$102, DW_AT_decl_column(0x12)
$C$DW$T$103	.dwtag  DW_TAG_typedef, DW_AT_name("__TA_xdc_runtime_Error_Block__xtra")
	.dwattr $C$DW$T$103, DW_AT_type(*$C$DW$T$102)
	.dwattr $C$DW$T$103, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$103, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$103, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$T$103, DW_AT_decl_column(0x30)

$C$DW$T$105	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$105, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$T$105, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$105, DW_AT_byte_size(0x08)
$C$DW$125	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$125, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$105

$C$DW$T$106	.dwtag  DW_TAG_typedef, DW_AT_name("__ARRAY1_xdc_runtime_Error_Data__arg")
	.dwattr $C$DW$T$106, DW_AT_type(*$C$DW$T$105)
	.dwattr $C$DW$T$106, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$106, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$106, DW_AT_decl_line(0x52)
	.dwattr $C$DW$T$106, DW_AT_decl_column(0x12)
$C$DW$T$107	.dwtag  DW_TAG_typedef, DW_AT_name("__TA_xdc_runtime_Error_Data__arg")
	.dwattr $C$DW$T$107, DW_AT_type(*$C$DW$T$106)
	.dwattr $C$DW$T$107, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$107, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$107, DW_AT_decl_line(0x53)
	.dwattr $C$DW$T$107, DW_AT_decl_column(0x2e)

$C$DW$T$121	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$121, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$T$121, DW_AT_language(DW_LANG_C)
$C$DW$126	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$126, DW_AT_type(*$C$DW$T$3)
	.dwendtag $C$DW$T$121

$C$DW$T$122	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$122, DW_AT_type(*$C$DW$T$121)
	.dwattr $C$DW$T$122, DW_AT_address_class(0x20)
$C$DW$T$457	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IGateProvider_enter_FxnT")
	.dwattr $C$DW$T$457, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$T$457, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$457, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$T$457, DW_AT_decl_line(0xa6)
	.dwattr $C$DW$T$457, DW_AT_decl_column(0x14)
$C$DW$T$458	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Main_Module_GateProxy_enter_FxnT")
	.dwattr $C$DW$T$458, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$T$458, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$458, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$458, DW_AT_decl_line(0x10a)
	.dwattr $C$DW$T$458, DW_AT_decl_column(0x14)

$C$DW$T$177	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$177, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$T$177, DW_AT_language(DW_LANG_C)
$C$DW$127	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$127, DW_AT_type(*$C$DW$T$176)
	.dwendtag $C$DW$T$177

$C$DW$T$178	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$178, DW_AT_type(*$C$DW$T$177)
	.dwattr $C$DW$T$178, DW_AT_address_class(0x20)
$C$DW$T$460	.dwtag  DW_TAG_typedef, DW_AT_name("ptrdiff_t")
	.dwattr $C$DW$T$460, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$460, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$460, DW_AT_decl_file("C:/ti/include/stddef.h")
	.dwattr $C$DW$T$460, DW_AT_decl_line(0x31)
	.dwattr $C$DW$T$460, DW_AT_decl_column(0x1c)
$C$DW$T$435	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Arg")
	.dwattr $C$DW$T$435, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$435, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$435, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$435, DW_AT_decl_line(0x23)
	.dwattr $C$DW$T$435, DW_AT_decl_column(0x15)
$C$DW$T$436	.dwtag  DW_TAG_typedef, DW_AT_name("Arg")
	.dwattr $C$DW$T$436, DW_AT_type(*$C$DW$T$435)
	.dwattr $C$DW$T$436, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$436, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$436, DW_AT_decl_line(0xf1)
	.dwattr $C$DW$T$436, DW_AT_decl_column(0x19)
$C$DW$T$118	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Int")
	.dwattr $C$DW$T$118, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$118, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$118, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$118, DW_AT_decl_line(0x21)
	.dwattr $C$DW$T$118, DW_AT_decl_column(0x19)
$C$DW$T$437	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Object__count")
	.dwattr $C$DW$T$437, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$437, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$437, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$437, DW_AT_decl_line(0xa8)
	.dwattr $C$DW$T$437, DW_AT_decl_column(0x11)
$C$DW$T$438	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Object__count")
	.dwattr $C$DW$T$438, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$438, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$438, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$438, DW_AT_decl_line(0x86)
	.dwattr $C$DW$T$438, DW_AT_decl_column(0x11)
$C$DW$T$439	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Object__count")
	.dwattr $C$DW$T$439, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$439, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$439, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$439, DW_AT_decl_line(0x84)
	.dwattr $C$DW$T$439, DW_AT_decl_column(0x11)
$C$DW$T$440	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Object__count")
	.dwattr $C$DW$T$440, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$440, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$440, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$440, DW_AT_decl_line(0x80)
	.dwattr $C$DW$T$440, DW_AT_decl_column(0x11)
$C$DW$T$441	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Object__count")
	.dwattr $C$DW$T$441, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$441, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$441, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$441, DW_AT_decl_line(0x92)
	.dwattr $C$DW$T$441, DW_AT_decl_column(0x11)
$C$DW$T$442	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Object__count")
	.dwattr $C$DW$T$442, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$442, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$442, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$442, DW_AT_decl_line(0x86)
	.dwattr $C$DW$T$442, DW_AT_decl_column(0x11)
$C$DW$T$443	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Object__count")
	.dwattr $C$DW$T$443, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$443, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$443, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$443, DW_AT_decl_line(0x7d)
	.dwattr $C$DW$T$443, DW_AT_decl_column(0x11)
$C$DW$T$444	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Object__count")
	.dwattr $C$DW$T$444, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$444, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$444, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$444, DW_AT_decl_line(0x106)
	.dwattr $C$DW$T$444, DW_AT_decl_column(0x11)
$C$DW$T$445	.dwtag  DW_TAG_typedef, DW_AT_name("Int")
	.dwattr $C$DW$T$445, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$445, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$445, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$445, DW_AT_decl_line(0xd1)
	.dwattr $C$DW$T$445, DW_AT_decl_column(0x19)
$C$DW$T$446	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Long")
	.dwattr $C$DW$T$446, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$446, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$446, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$446, DW_AT_decl_line(0x23)
	.dwattr $C$DW$T$446, DW_AT_decl_column(0x19)
$C$DW$T$447	.dwtag  DW_TAG_typedef, DW_AT_name("Long")
	.dwattr $C$DW$T$447, DW_AT_type(*$C$DW$T$446)
	.dwattr $C$DW$T$447, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$447, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$447, DW_AT_decl_line(0xd3)
	.dwattr $C$DW$T$447, DW_AT_decl_column(0x19)
$C$DW$T$11	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$11, DW_AT_name("unsigned int")
	.dwattr $C$DW$T$11, DW_AT_byte_size(0x04)
$C$DW$T$126	.dwtag  DW_TAG_typedef, DW_AT_name("size_t")
	.dwattr $C$DW$T$126, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$126, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$126, DW_AT_decl_file("C:/ti/include/string.h")
	.dwattr $C$DW$T$126, DW_AT_decl_line(0x39)
	.dwattr $C$DW$T$126, DW_AT_decl_column(0x19)
$C$DW$T$136	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_SizeT")
	.dwattr $C$DW$T$136, DW_AT_type(*$C$DW$T$126)
	.dwattr $C$DW$T$136, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$136, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$136, DW_AT_decl_line(0x28)
	.dwattr $C$DW$T$136, DW_AT_decl_column(0x19)
$C$DW$T$502	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Object__sizeof")
	.dwattr $C$DW$T$502, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$502, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$502, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$502, DW_AT_decl_line(0xb0)
	.dwattr $C$DW$T$502, DW_AT_decl_column(0x13)
$C$DW$T$503	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Object__sizeof")
	.dwattr $C$DW$T$503, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$503, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$503, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$503, DW_AT_decl_line(0x8e)
	.dwattr $C$DW$T$503, DW_AT_decl_column(0x13)
$C$DW$T$504	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Object__sizeof")
	.dwattr $C$DW$T$504, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$504, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$504, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$504, DW_AT_decl_line(0x8c)
	.dwattr $C$DW$T$504, DW_AT_decl_column(0x13)
$C$DW$T$505	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Object__sizeof")
	.dwattr $C$DW$T$505, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$505, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$505, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$505, DW_AT_decl_line(0x88)
	.dwattr $C$DW$T$505, DW_AT_decl_column(0x13)
$C$DW$T$506	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Object__sizeof")
	.dwattr $C$DW$T$506, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$506, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$506, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$506, DW_AT_decl_line(0x9a)
	.dwattr $C$DW$T$506, DW_AT_decl_column(0x13)
$C$DW$T$507	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Object__sizeof")
	.dwattr $C$DW$T$507, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$507, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$507, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$507, DW_AT_decl_line(0x8e)
	.dwattr $C$DW$T$507, DW_AT_decl_column(0x13)
$C$DW$T$508	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Object__sizeof")
	.dwattr $C$DW$T$508, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$508, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$508, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$508, DW_AT_decl_line(0x85)
	.dwattr $C$DW$T$508, DW_AT_decl_column(0x13)
$C$DW$T$509	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Object__sizeof")
	.dwattr $C$DW$T$509, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$509, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$509, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$509, DW_AT_decl_line(0x10e)
	.dwattr $C$DW$T$509, DW_AT_decl_column(0x13)
$C$DW$T$510	.dwtag  DW_TAG_typedef, DW_AT_name("SizeT")
	.dwattr $C$DW$T$510, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$T$510, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$510, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$510, DW_AT_decl_line(0xda)
	.dwattr $C$DW$T$510, DW_AT_decl_column(0x19)
$C$DW$T$94	.dwtag  DW_TAG_typedef, DW_AT_name("uint32_t")
	.dwattr $C$DW$T$94, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$94, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$94, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$94, DW_AT_decl_line(0x2f)
	.dwattr $C$DW$T$94, DW_AT_decl_column(0x1c)
$C$DW$T$494	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast16_t")
	.dwattr $C$DW$T$494, DW_AT_type(*$C$DW$T$94)
	.dwattr $C$DW$T$494, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$494, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$494, DW_AT_decl_line(0x4c)
	.dwattr $C$DW$T$494, DW_AT_decl_column(0x16)
$C$DW$T$495	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast32_t")
	.dwattr $C$DW$T$495, DW_AT_type(*$C$DW$T$94)
	.dwattr $C$DW$T$495, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$495, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$495, DW_AT_decl_line(0x4f)
	.dwattr $C$DW$T$495, DW_AT_decl_column(0x16)
$C$DW$T$496	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast8_t")
	.dwattr $C$DW$T$496, DW_AT_type(*$C$DW$T$94)
	.dwattr $C$DW$T$496, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$496, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$496, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$T$496, DW_AT_decl_column(0x16)
$C$DW$T$497	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least32_t")
	.dwattr $C$DW$T$497, DW_AT_type(*$C$DW$T$94)
	.dwattr $C$DW$T$497, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$497, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$497, DW_AT_decl_line(0x3f)
	.dwattr $C$DW$T$497, DW_AT_decl_column(0x16)
$C$DW$T$498	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UInt32")
	.dwattr $C$DW$T$498, DW_AT_type(*$C$DW$T$497)
	.dwattr $C$DW$T$498, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$498, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$498, DW_AT_decl_line(0x72)
	.dwattr $C$DW$T$498, DW_AT_decl_column(0x19)
$C$DW$T$499	.dwtag  DW_TAG_typedef, DW_AT_name("UInt32")
	.dwattr $C$DW$T$499, DW_AT_type(*$C$DW$T$498)
	.dwattr $C$DW$T$499, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$499, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$499, DW_AT_decl_line(0xe9)
	.dwattr $C$DW$T$499, DW_AT_decl_column(0x19)
$C$DW$T$500	.dwtag  DW_TAG_typedef, DW_AT_name("Uint32")
	.dwattr $C$DW$T$500, DW_AT_type(*$C$DW$T$498)
	.dwattr $C$DW$T$500, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$500, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$500, DW_AT_decl_line(0xf6)
	.dwattr $C$DW$T$500, DW_AT_decl_column(0x19)
$C$DW$T$95	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Bits32")
	.dwattr $C$DW$T$95, DW_AT_type(*$C$DW$T$94)
	.dwattr $C$DW$T$95, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$95, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$95, DW_AT_decl_line(0x90)
	.dwattr $C$DW$T$95, DW_AT_decl_column(0x19)
$C$DW$T$493	.dwtag  DW_TAG_typedef, DW_AT_name("Bits32")
	.dwattr $C$DW$T$493, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$493, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$493, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$493, DW_AT_decl_line(0x110)
	.dwattr $C$DW$T$493, DW_AT_decl_column(0x19)
$C$DW$T$470	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__diagsEnabled")
	.dwattr $C$DW$T$470, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$470, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$470, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$470, DW_AT_decl_line(0x70)
	.dwattr $C$DW$T$470, DW_AT_decl_column(0x14)
$C$DW$T$471	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Module__diagsIncluded")
	.dwattr $C$DW$T$471, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$471, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$471, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$471, DW_AT_decl_line(0x74)
	.dwattr $C$DW$T$471, DW_AT_decl_column(0x14)
$C$DW$T$472	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__diagsEnabled")
	.dwattr $C$DW$T$472, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$472, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$472, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$472, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$T$472, DW_AT_decl_column(0x14)
$C$DW$T$473	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Module__diagsIncluded")
	.dwattr $C$DW$T$473, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$473, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$473, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$473, DW_AT_decl_line(0x52)
	.dwattr $C$DW$T$473, DW_AT_decl_column(0x14)
$C$DW$T$474	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__diagsEnabled")
	.dwattr $C$DW$T$474, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$474, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$474, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$474, DW_AT_decl_line(0x4c)
	.dwattr $C$DW$T$474, DW_AT_decl_column(0x14)
$C$DW$T$475	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module__diagsIncluded")
	.dwattr $C$DW$T$475, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$475, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$475, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$475, DW_AT_decl_line(0x50)
	.dwattr $C$DW$T$475, DW_AT_decl_column(0x14)
$C$DW$T$476	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__diagsEnabled")
	.dwattr $C$DW$T$476, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$476, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$476, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$476, DW_AT_decl_line(0x48)
	.dwattr $C$DW$T$476, DW_AT_decl_column(0x14)
$C$DW$T$477	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Module__diagsIncluded")
	.dwattr $C$DW$T$477, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$477, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$477, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$477, DW_AT_decl_line(0x4c)
	.dwattr $C$DW$T$477, DW_AT_decl_column(0x14)
$C$DW$T$478	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__diagsEnabled")
	.dwattr $C$DW$T$478, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$478, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$478, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$478, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$T$478, DW_AT_decl_column(0x14)
$C$DW$T$479	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Module__diagsIncluded")
	.dwattr $C$DW$T$479, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$479, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$479, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$479, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$T$479, DW_AT_decl_column(0x14)
$C$DW$T$480	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__diagsEnabled")
	.dwattr $C$DW$T$480, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$480, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$480, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$480, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$T$480, DW_AT_decl_column(0x14)
$C$DW$T$481	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Module__diagsIncluded")
	.dwattr $C$DW$T$481, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$481, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$481, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$481, DW_AT_decl_line(0x52)
	.dwattr $C$DW$T$481, DW_AT_decl_column(0x14)
$C$DW$T$482	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsEnabled")
	.dwattr $C$DW$T$482, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$482, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$482, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$482, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$482, DW_AT_decl_column(0x14)
$C$DW$T$483	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsIncluded")
	.dwattr $C$DW$T$483, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$483, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$483, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$483, DW_AT_decl_line(0x49)
	.dwattr $C$DW$T$483, DW_AT_decl_column(0x14)
$C$DW$T$484	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__diagsEnabled")
	.dwattr $C$DW$T$484, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$484, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$484, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$484, DW_AT_decl_line(0xce)
	.dwattr $C$DW$T$484, DW_AT_decl_column(0x14)
$C$DW$T$485	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Module__diagsIncluded")
	.dwattr $C$DW$T$485, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$485, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$485, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$485, DW_AT_decl_line(0xd2)
	.dwattr $C$DW$T$485, DW_AT_decl_column(0x14)

$C$DW$T$163	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$163, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$163, DW_AT_language(DW_LANG_C)
$C$DW$T$164	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$164, DW_AT_type(*$C$DW$T$163)
	.dwattr $C$DW$T$164, DW_AT_address_class(0x20)
$C$DW$T$486	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampClient_get32_FxnT")
	.dwattr $C$DW$T$486, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$T$486, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$486, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$T$486, DW_AT_decl_line(0x73)
	.dwattr $C$DW$T$486, DW_AT_decl_column(0x16)
$C$DW$T$487	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampProvider_get32_FxnT")
	.dwattr $C$DW$T$487, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$T$487, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$487, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$T$487, DW_AT_decl_line(0x73)
	.dwattr $C$DW$T$487, DW_AT_decl_column(0x16)
$C$DW$T$96	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Error_Id")
	.dwattr $C$DW$T$96, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$96, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$96, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error__prologue.h")
	.dwattr $C$DW$T$96, DW_AT_decl_line(0x12)
	.dwattr $C$DW$T$96, DW_AT_decl_column(0x14)
$C$DW$T$488	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_E_generic")
	.dwattr $C$DW$T$488, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$T$488, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$488, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$488, DW_AT_decl_line(0xb9)
	.dwattr $C$DW$T$488, DW_AT_decl_column(0x1e)
$C$DW$T$489	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_E_memory")
	.dwattr $C$DW$T$489, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$T$489, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$489, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$489, DW_AT_decl_line(0xbe)
	.dwattr $C$DW$T$489, DW_AT_decl_column(0x1e)
$C$DW$T$490	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_E_msgCode")
	.dwattr $C$DW$T$490, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$T$490, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$490, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$490, DW_AT_decl_line(0xc3)
	.dwattr $C$DW$T$490, DW_AT_decl_column(0x1e)
$C$DW$T$491	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_Event")
	.dwattr $C$DW$T$491, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$491, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$491, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$491, DW_AT_decl_line(0x44)
	.dwattr $C$DW$T$491, DW_AT_decl_column(0x14)
$C$DW$T$492	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_EventId")
	.dwattr $C$DW$T$492, DW_AT_type(*$C$DW$T$491)
	.dwattr $C$DW$T$492, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$492, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$492, DW_AT_decl_line(0x47)
	.dwattr $C$DW$T$492, DW_AT_decl_column(0x21)
$C$DW$T$291	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_LogEvent")
	.dwattr $C$DW$T$291, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$291, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$291, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$291, DW_AT_decl_line(0x89)
	.dwattr $C$DW$T$291, DW_AT_decl_column(0x14)
$C$DW$T$206	.dwtag  DW_TAG_typedef, DW_AT_name("uintptr_t")
	.dwattr $C$DW$T$206, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$206, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$206, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$206, DW_AT_decl_line(0x59)
	.dwattr $C$DW$T$206, DW_AT_decl_column(0x1a)
$C$DW$T$207	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UArg")
	.dwattr $C$DW$T$207, DW_AT_type(*$C$DW$T$206)
	.dwattr $C$DW$T$207, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$207, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$207, DW_AT_decl_line(0x9a)
	.dwattr $C$DW$T$207, DW_AT_decl_column(0x19)
$C$DW$T$501	.dwtag  DW_TAG_typedef, DW_AT_name("UArg")
	.dwattr $C$DW$T$501, DW_AT_type(*$C$DW$T$207)
	.dwattr $C$DW$T$501, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$501, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$501, DW_AT_decl_line(0xde)
	.dwattr $C$DW$T$501, DW_AT_decl_column(0x19)
$C$DW$T$208	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_Size")
	.dwattr $C$DW$T$208, DW_AT_type(*$C$DW$T$207)
	.dwattr $C$DW$T$208, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$208, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$208, DW_AT_decl_line(0x46)
	.dwattr $C$DW$T$208, DW_AT_decl_column(0x12)
$C$DW$T$465	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UInt")
	.dwattr $C$DW$T$465, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$465, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$465, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$465, DW_AT_decl_line(0x22)
	.dwattr $C$DW$T$465, DW_AT_decl_column(0x19)
$C$DW$T$466	.dwtag  DW_TAG_typedef, DW_AT_name("UInt")
	.dwattr $C$DW$T$466, DW_AT_type(*$C$DW$T$465)
	.dwattr $C$DW$T$466, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$466, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$466, DW_AT_decl_line(0xd2)
	.dwattr $C$DW$T$466, DW_AT_decl_column(0x19)
$C$DW$T$467	.dwtag  DW_TAG_typedef, DW_AT_name("Uns")
	.dwattr $C$DW$T$467, DW_AT_type(*$C$DW$T$465)
	.dwattr $C$DW$T$467, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$467, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$467, DW_AT_decl_line(0xf7)
	.dwattr $C$DW$T$467, DW_AT_decl_column(0x19)
$C$DW$T$468	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_ULong")
	.dwattr $C$DW$T$468, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$468, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$468, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$468, DW_AT_decl_line(0x24)
	.dwattr $C$DW$T$468, DW_AT_decl_column(0x19)
$C$DW$T$469	.dwtag  DW_TAG_typedef, DW_AT_name("ULong")
	.dwattr $C$DW$T$469, DW_AT_type(*$C$DW$T$468)
	.dwattr $C$DW$T$469, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$469, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$469, DW_AT_decl_line(0xd4)
	.dwattr $C$DW$T$469, DW_AT_decl_column(0x19)
$C$DW$T$12	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$12, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$12, DW_AT_name("__int40_t")
	.dwattr $C$DW$T$12, DW_AT_byte_size(0x08)
	.dwattr $C$DW$T$12, DW_AT_bit_size(0x28)
	.dwattr $C$DW$T$12, DW_AT_bit_offset(0x18)
$C$DW$T$511	.dwtag  DW_TAG_typedef, DW_AT_name("int40_t")
	.dwattr $C$DW$T$511, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$T$511, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$511, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$511, DW_AT_decl_line(0x31)
	.dwattr $C$DW$T$511, DW_AT_decl_column(0x21)
$C$DW$T$512	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast40_t")
	.dwattr $C$DW$T$512, DW_AT_type(*$C$DW$T$511)
	.dwattr $C$DW$T$512, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$512, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$512, DW_AT_decl_line(0x51)
	.dwattr $C$DW$T$512, DW_AT_decl_column(0x17)
$C$DW$T$513	.dwtag  DW_TAG_typedef, DW_AT_name("int_least40_t")
	.dwattr $C$DW$T$513, DW_AT_type(*$C$DW$T$511)
	.dwattr $C$DW$T$513, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$513, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$513, DW_AT_decl_line(0x41)
	.dwattr $C$DW$T$513, DW_AT_decl_column(0x17)
$C$DW$T$514	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Int40")
	.dwattr $C$DW$T$514, DW_AT_type(*$C$DW$T$513)
	.dwattr $C$DW$T$514, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$514, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$514, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$T$514, DW_AT_decl_column(0x1d)
$C$DW$T$515	.dwtag  DW_TAG_typedef, DW_AT_name("Int40")
	.dwattr $C$DW$T$515, DW_AT_type(*$C$DW$T$514)
	.dwattr $C$DW$T$515, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$515, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$515, DW_AT_decl_line(0x81)
	.dwattr $C$DW$T$515, DW_AT_decl_column(0x1d)
$C$DW$T$13	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$13, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$13, DW_AT_name("unsigned __int40_t")
	.dwattr $C$DW$T$13, DW_AT_byte_size(0x08)
	.dwattr $C$DW$T$13, DW_AT_bit_size(0x28)
	.dwattr $C$DW$T$13, DW_AT_bit_offset(0x18)
$C$DW$T$516	.dwtag  DW_TAG_typedef, DW_AT_name("uint40_t")
	.dwattr $C$DW$T$516, DW_AT_type(*$C$DW$T$13)
	.dwattr $C$DW$T$516, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$516, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$516, DW_AT_decl_line(0x32)
	.dwattr $C$DW$T$516, DW_AT_decl_column(0x20)
$C$DW$T$517	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast40_t")
	.dwattr $C$DW$T$517, DW_AT_type(*$C$DW$T$516)
	.dwattr $C$DW$T$517, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$517, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$517, DW_AT_decl_line(0x52)
	.dwattr $C$DW$T$517, DW_AT_decl_column(0x16)
$C$DW$T$518	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least40_t")
	.dwattr $C$DW$T$518, DW_AT_type(*$C$DW$T$516)
	.dwattr $C$DW$T$518, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$518, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$518, DW_AT_decl_line(0x42)
	.dwattr $C$DW$T$518, DW_AT_decl_column(0x16)
$C$DW$T$519	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UInt40")
	.dwattr $C$DW$T$519, DW_AT_type(*$C$DW$T$518)
	.dwattr $C$DW$T$519, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$519, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$519, DW_AT_decl_line(0x7b)
	.dwattr $C$DW$T$519, DW_AT_decl_column(0x1d)
$C$DW$T$520	.dwtag  DW_TAG_typedef, DW_AT_name("UInt40")
	.dwattr $C$DW$T$520, DW_AT_type(*$C$DW$T$519)
	.dwattr $C$DW$T$520, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$520, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$520, DW_AT_decl_line(0x82)
	.dwattr $C$DW$T$520, DW_AT_decl_column(0x1d)
$C$DW$T$14	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$14, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$14, DW_AT_name("long long")
	.dwattr $C$DW$T$14, DW_AT_byte_size(0x08)
$C$DW$T$524	.dwtag  DW_TAG_typedef, DW_AT_name("int64_t")
	.dwattr $C$DW$T$524, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$524, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$524, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$524, DW_AT_decl_line(0x34)
	.dwattr $C$DW$T$524, DW_AT_decl_column(0x21)
$C$DW$T$525	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast64_t")
	.dwattr $C$DW$T$525, DW_AT_type(*$C$DW$T$524)
	.dwattr $C$DW$T$525, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$525, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$525, DW_AT_decl_line(0x54)
	.dwattr $C$DW$T$525, DW_AT_decl_column(0x17)
$C$DW$T$526	.dwtag  DW_TAG_typedef, DW_AT_name("int_least64_t")
	.dwattr $C$DW$T$526, DW_AT_type(*$C$DW$T$524)
	.dwattr $C$DW$T$526, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$526, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$526, DW_AT_decl_line(0x44)
	.dwattr $C$DW$T$526, DW_AT_decl_column(0x17)
$C$DW$T$527	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Int64")
	.dwattr $C$DW$T$527, DW_AT_type(*$C$DW$T$526)
	.dwattr $C$DW$T$527, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$527, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$527, DW_AT_decl_line(0x75)
	.dwattr $C$DW$T$527, DW_AT_decl_column(0x1d)
$C$DW$T$528	.dwtag  DW_TAG_typedef, DW_AT_name("Int64")
	.dwattr $C$DW$T$528, DW_AT_type(*$C$DW$T$527)
	.dwattr $C$DW$T$528, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$528, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$528, DW_AT_decl_line(0xff)
	.dwattr $C$DW$T$528, DW_AT_decl_column(0x19)
$C$DW$T$529	.dwtag  DW_TAG_typedef, DW_AT_name("intmax_t")
	.dwattr $C$DW$T$529, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$529, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$529, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$529, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$T$529, DW_AT_decl_column(0x20)
$C$DW$T$522	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_LLong")
	.dwattr $C$DW$T$522, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$522, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$522, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$522, DW_AT_decl_line(0x7f)
	.dwattr $C$DW$T$522, DW_AT_decl_column(0x21)
$C$DW$T$523	.dwtag  DW_TAG_typedef, DW_AT_name("LLong")
	.dwattr $C$DW$T$523, DW_AT_type(*$C$DW$T$522)
	.dwattr $C$DW$T$523, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$523, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$523, DW_AT_decl_line(0xd5)
	.dwattr $C$DW$T$523, DW_AT_decl_column(0x19)
$C$DW$T$15	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$15, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$15, DW_AT_name("unsigned long long")
	.dwattr $C$DW$T$15, DW_AT_byte_size(0x08)
$C$DW$T$532	.dwtag  DW_TAG_typedef, DW_AT_name("uint64_t")
	.dwattr $C$DW$T$532, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$532, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$532, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$532, DW_AT_decl_line(0x35)
	.dwattr $C$DW$T$532, DW_AT_decl_column(0x20)
$C$DW$T$535	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast64_t")
	.dwattr $C$DW$T$535, DW_AT_type(*$C$DW$T$532)
	.dwattr $C$DW$T$535, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$535, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$535, DW_AT_decl_line(0x55)
	.dwattr $C$DW$T$535, DW_AT_decl_column(0x16)
$C$DW$T$536	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least64_t")
	.dwattr $C$DW$T$536, DW_AT_type(*$C$DW$T$532)
	.dwattr $C$DW$T$536, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$536, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$536, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$536, DW_AT_decl_column(0x16)
$C$DW$T$537	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_UInt64")
	.dwattr $C$DW$T$537, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$T$537, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$537, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$537, DW_AT_decl_line(0x76)
	.dwattr $C$DW$T$537, DW_AT_decl_column(0x1e)
$C$DW$T$538	.dwtag  DW_TAG_typedef, DW_AT_name("UInt64")
	.dwattr $C$DW$T$538, DW_AT_type(*$C$DW$T$537)
	.dwattr $C$DW$T$538, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$538, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$538, DW_AT_decl_line(0x100)
	.dwattr $C$DW$T$538, DW_AT_decl_column(0x19)
$C$DW$T$533	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Bits64")
	.dwattr $C$DW$T$533, DW_AT_type(*$C$DW$T$532)
	.dwattr $C$DW$T$533, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$533, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/ti/targets/std.h")
	.dwattr $C$DW$T$533, DW_AT_decl_line(0x93)
	.dwattr $C$DW$T$533, DW_AT_decl_column(0x19)
$C$DW$T$534	.dwtag  DW_TAG_typedef, DW_AT_name("Bits64")
	.dwattr $C$DW$T$534, DW_AT_type(*$C$DW$T$533)
	.dwattr $C$DW$T$534, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$534, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$534, DW_AT_decl_line(0x114)
	.dwattr $C$DW$T$534, DW_AT_decl_column(0x19)
$C$DW$T$539	.dwtag  DW_TAG_typedef, DW_AT_name("uintmax_t")
	.dwattr $C$DW$T$539, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$539, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$539, DW_AT_decl_file("C:/ti/include/stdint.h")
	.dwattr $C$DW$T$539, DW_AT_decl_line(0x5d)
	.dwattr $C$DW$T$539, DW_AT_decl_column(0x20)
$C$DW$T$530	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_ULLong")
	.dwattr $C$DW$T$530, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$530, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$530, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$530, DW_AT_decl_line(0x80)
	.dwattr $C$DW$T$530, DW_AT_decl_column(0x21)
$C$DW$T$531	.dwtag  DW_TAG_typedef, DW_AT_name("ULLong")
	.dwattr $C$DW$T$531, DW_AT_type(*$C$DW$T$530)
	.dwattr $C$DW$T$531, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$531, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$531, DW_AT_decl_line(0xd6)
	.dwattr $C$DW$T$531, DW_AT_decl_column(0x19)
$C$DW$T$16	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$16, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$16, DW_AT_name("float")
	.dwattr $C$DW$T$16, DW_AT_byte_size(0x04)
$C$DW$T$541	.dwtag  DW_TAG_typedef, DW_AT_name("float32_t")
	.dwattr $C$DW$T$541, DW_AT_type(*$C$DW$T$16)
	.dwattr $C$DW$T$541, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$541, DW_AT_decl_file("C:\ti\include\vect.h")
	.dwattr $C$DW$T$541, DW_AT_decl_line(0x30)
	.dwattr $C$DW$T$541, DW_AT_decl_column(0x0f)
$C$DW$T$86	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Float")
	.dwattr $C$DW$T$86, DW_AT_type(*$C$DW$T$16)
	.dwattr $C$DW$T$86, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$86, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$86, DW_AT_decl_line(0x25)
	.dwattr $C$DW$T$86, DW_AT_decl_column(0x19)
$C$DW$T$540	.dwtag  DW_TAG_typedef, DW_AT_name("Float")
	.dwattr $C$DW$T$540, DW_AT_type(*$C$DW$T$86)
	.dwattr $C$DW$T$540, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$540, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$540, DW_AT_decl_line(0xd7)
	.dwattr $C$DW$T$540, DW_AT_decl_column(0x19)
$C$DW$T$17	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$17, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$17, DW_AT_name("double")
	.dwattr $C$DW$T$17, DW_AT_byte_size(0x08)
$C$DW$T$543	.dwtag  DW_TAG_typedef, DW_AT_name("__float2_t")
	.dwattr $C$DW$T$543, DW_AT_type(*$C$DW$T$17)
	.dwattr $C$DW$T$543, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$543, DW_AT_decl_file("C:/ti/include/c6x.h")
	.dwattr $C$DW$T$543, DW_AT_decl_line(0x5f)
	.dwattr $C$DW$T$543, DW_AT_decl_column(0x14)
$C$DW$T$545	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Double")
	.dwattr $C$DW$T$545, DW_AT_type(*$C$DW$T$17)
	.dwattr $C$DW$T$545, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$545, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$545, DW_AT_decl_line(0x26)
	.dwattr $C$DW$T$545, DW_AT_decl_column(0x19)
$C$DW$T$546	.dwtag  DW_TAG_typedef, DW_AT_name("Double")
	.dwattr $C$DW$T$546, DW_AT_type(*$C$DW$T$545)
	.dwattr $C$DW$T$546, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$546, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$546, DW_AT_decl_line(0xd8)
	.dwattr $C$DW$T$546, DW_AT_decl_column(0x19)
$C$DW$T$18	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$18, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$18, DW_AT_name("long double")
	.dwattr $C$DW$T$18, DW_AT_byte_size(0x08)
$C$DW$T$547	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_LDouble")
	.dwattr $C$DW$T$547, DW_AT_type(*$C$DW$T$18)
	.dwattr $C$DW$T$547, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$547, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$547, DW_AT_decl_line(0x27)
	.dwattr $C$DW$T$547, DW_AT_decl_column(0x19)
$C$DW$T$548	.dwtag  DW_TAG_typedef, DW_AT_name("LDouble")
	.dwattr $C$DW$T$548, DW_AT_type(*$C$DW$T$547)
	.dwattr $C$DW$T$548, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$548, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$548, DW_AT_decl_line(0xd9)
	.dwattr $C$DW$T$548, DW_AT_decl_column(0x19)
$C$DW$T$97	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$97, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$97, DW_AT_name("signed char")
	.dwattr $C$DW$T$97, DW_AT_byte_size(0x01)
$C$DW$T$98	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$98, DW_AT_type(*$C$DW$T$97)
	.dwattr $C$DW$T$98, DW_AT_address_class(0x20)
$C$DW$T$549	.dwtag  DW_TAG_typedef, DW_AT_name("va_list")
	.dwattr $C$DW$T$549, DW_AT_type(*$C$DW$T$98)
	.dwattr $C$DW$T$549, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$549, DW_AT_decl_file("C:/ti/include/stdarg.h")
	.dwattr $C$DW$T$549, DW_AT_decl_line(0x2f)
	.dwattr $C$DW$T$549, DW_AT_decl_column(0x12)
$C$DW$T$550	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_VaList")
	.dwattr $C$DW$T$550, DW_AT_type(*$C$DW$T$549)
	.dwattr $C$DW$T$550, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$550, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$550, DW_AT_decl_line(0x29)
	.dwattr $C$DW$T$550, DW_AT_decl_column(0x19)
$C$DW$T$551	.dwtag  DW_TAG_typedef, DW_AT_name("VaList")
	.dwattr $C$DW$T$551, DW_AT_type(*$C$DW$T$550)
	.dwattr $C$DW$T$551, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$551, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$551, DW_AT_decl_line(0xdb)
	.dwattr $C$DW$T$551, DW_AT_decl_column(0x19)
$C$DW$T$99	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_String")
	.dwattr $C$DW$T$99, DW_AT_type(*$C$DW$T$98)
	.dwattr $C$DW$T$99, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$99, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$99, DW_AT_decl_line(0x2f)
	.dwattr $C$DW$T$99, DW_AT_decl_column(0x1a)
$C$DW$T$552	.dwtag  DW_TAG_typedef, DW_AT_name("String")
	.dwattr $C$DW$T$552, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$T$552, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$552, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$552, DW_AT_decl_line(0xe5)
	.dwattr $C$DW$T$552, DW_AT_decl_column(0x19)
$C$DW$T$426	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$426, DW_AT_type(*$C$DW$T$97)
$C$DW$T$427	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$427, DW_AT_type(*$C$DW$T$426)
	.dwattr $C$DW$T$427, DW_AT_address_class(0x20)
$C$DW$T$553	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_Char")
	.dwattr $C$DW$T$553, DW_AT_type(*$C$DW$T$97)
	.dwattr $C$DW$T$553, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$553, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$553, DW_AT_decl_line(0x1d)
	.dwattr $C$DW$T$553, DW_AT_decl_column(0x19)
$C$DW$T$554	.dwtag  DW_TAG_typedef, DW_AT_name("Char")
	.dwattr $C$DW$T$554, DW_AT_type(*$C$DW$T$553)
	.dwattr $C$DW$T$554, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$554, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$554, DW_AT_decl_line(0xcd)
	.dwattr $C$DW$T$554, DW_AT_decl_column(0x19)

$C$DW$T$85	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$85, DW_AT_name("__simd128_int32_t")
	.dwattr $C$DW$T$85, DW_AT_byte_size(0x10)
$C$DW$128	.dwtag  DW_TAG_member
	.dwattr $C$DW$128, DW_AT_type(*$C$DW$T$84)
	.dwattr $C$DW$128, DW_AT_name("_v")
	.dwattr $C$DW$128, DW_AT_TI_symbol_name("_v")
	.dwattr $C$DW$128, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$128, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$128, DW_AT_decl_file("C:\ti\include\vect.h")
	.dwattr $C$DW$128, DW_AT_decl_line(0x44)
	.dwattr $C$DW$128, DW_AT_decl_column(0x01)
	.dwendtag $C$DW$T$85

	.dwattr $C$DW$T$85, DW_AT_decl_file("C:\ti\include\vect.h")
	.dwattr $C$DW$T$85, DW_AT_decl_line(0x44)
	.dwattr $C$DW$T$85, DW_AT_decl_column(0x01)
$C$DW$T$461	.dwtag  DW_TAG_typedef, DW_AT_name("int32x4_t")
	.dwattr $C$DW$T$461, DW_AT_type(*$C$DW$T$85)
	.dwattr $C$DW$T$461, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$461, DW_AT_decl_file("C:\ti\include\vect.h")
	.dwattr $C$DW$T$461, DW_AT_decl_line(0x44)
	.dwattr $C$DW$T$461, DW_AT_decl_column(0x01)
$C$DW$T$462	.dwtag  DW_TAG_typedef, DW_AT_name("__x128_t")
	.dwattr $C$DW$T$462, DW_AT_type(*$C$DW$T$461)
	.dwattr $C$DW$T$462, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$462, DW_AT_decl_file("C:\ti\include\vect.h")
	.dwattr $C$DW$T$462, DW_AT_decl_line(0x46)
	.dwattr $C$DW$T$462, DW_AT_decl_column(0x13)

$C$DW$T$89	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$89, DW_AT_name("xdc_FloatData")
	.dwattr $C$DW$T$89, DW_AT_byte_size(0x04)
$C$DW$129	.dwtag  DW_TAG_member
	.dwattr $C$DW$129, DW_AT_type(*$C$DW$T$86)
	.dwattr $C$DW$129, DW_AT_name("f")
	.dwattr $C$DW$129, DW_AT_TI_symbol_name("f")
	.dwattr $C$DW$129, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$129, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$129, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$129, DW_AT_decl_line(0xa6)
	.dwattr $C$DW$129, DW_AT_decl_column(0x0f)
$C$DW$130	.dwtag  DW_TAG_member
	.dwattr $C$DW$130, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$130, DW_AT_name("a")
	.dwattr $C$DW$130, DW_AT_TI_symbol_name("a")
	.dwattr $C$DW$130, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$130, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$130, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$130, DW_AT_decl_line(0xa7)
	.dwattr $C$DW$130, DW_AT_decl_column(0x0f)
	.dwendtag $C$DW$T$89

	.dwattr $C$DW$T$89, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$89, DW_AT_decl_line(0xa5)
	.dwattr $C$DW$T$89, DW_AT_decl_column(0x0f)
$C$DW$T$557	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_FloatData")
	.dwattr $C$DW$T$557, DW_AT_type(*$C$DW$T$89)
	.dwattr $C$DW$T$557, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$557, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/std.h")
	.dwattr $C$DW$T$557, DW_AT_decl_line(0xa8)
	.dwattr $C$DW$T$557, DW_AT_decl_column(0x03)

$C$DW$T$19	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$19, DW_AT_name("xdc_runtime_Core_ObjDesc")
	.dwattr $C$DW$T$19, DW_AT_declaration
	.dwendtag $C$DW$T$19

	.dwattr $C$DW$T$19, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$19, DW_AT_decl_line(0x1c)
	.dwattr $C$DW$T$19, DW_AT_decl_column(0x10)
$C$DW$T$558	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Core_ObjDesc")
	.dwattr $C$DW$T$558, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$558, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$558, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$558, DW_AT_decl_line(0x1c)
	.dwattr $C$DW$T$558, DW_AT_decl_column(0x29)

$C$DW$T$20	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$20, DW_AT_name("xdc_runtime_Diags_DictElem")
	.dwattr $C$DW$T$20, DW_AT_declaration
	.dwendtag $C$DW$T$20

	.dwattr $C$DW$T$20, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$20, DW_AT_decl_line(0x27)
	.dwattr $C$DW$T$20, DW_AT_decl_column(0x10)
$C$DW$T$559	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Diags_DictElem")
	.dwattr $C$DW$T$559, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$T$559, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$559, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$559, DW_AT_decl_line(0x27)
	.dwattr $C$DW$T$559, DW_AT_decl_column(0x2b)

$C$DW$T$104	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$104, DW_AT_name("xdc_runtime_Error_Block")
	.dwattr $C$DW$T$104, DW_AT_byte_size(0x30)
$C$DW$131	.dwtag  DW_TAG_member
	.dwattr $C$DW$131, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$131, DW_AT_name("unused")
	.dwattr $C$DW$131, DW_AT_TI_symbol_name("unused")
	.dwattr $C$DW$131, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$131, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$131, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$131, DW_AT_decl_line(0x5d)
	.dwattr $C$DW$131, DW_AT_decl_column(0x10)
$C$DW$132	.dwtag  DW_TAG_member
	.dwattr $C$DW$132, DW_AT_type(*$C$DW$T$93)
	.dwattr $C$DW$132, DW_AT_name("data")
	.dwattr $C$DW$132, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$132, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$132, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$132, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$132, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$132, DW_AT_decl_column(0x1c)
$C$DW$133	.dwtag  DW_TAG_member
	.dwattr $C$DW$133, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$133, DW_AT_name("id")
	.dwattr $C$DW$133, DW_AT_TI_symbol_name("id")
	.dwattr $C$DW$133, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$133, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$133, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$133, DW_AT_decl_line(0x5f)
	.dwattr $C$DW$133, DW_AT_decl_column(0x1a)
$C$DW$134	.dwtag  DW_TAG_member
	.dwattr $C$DW$134, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$134, DW_AT_name("msg")
	.dwattr $C$DW$134, DW_AT_TI_symbol_name("msg")
	.dwattr $C$DW$134, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$134, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$134, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$134, DW_AT_decl_line(0x60)
	.dwattr $C$DW$134, DW_AT_decl_column(0x10)
$C$DW$135	.dwtag  DW_TAG_member
	.dwattr $C$DW$135, DW_AT_type(*$C$DW$T$100)
	.dwattr $C$DW$135, DW_AT_name("site")
	.dwattr $C$DW$135, DW_AT_TI_symbol_name("site")
	.dwattr $C$DW$135, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$135, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$135, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$135, DW_AT_decl_line(0x61)
	.dwattr $C$DW$135, DW_AT_decl_column(0x1c)
$C$DW$136	.dwtag  DW_TAG_member
	.dwattr $C$DW$136, DW_AT_type(*$C$DW$T$103)
	.dwattr $C$DW$136, DW_AT_name("xtra")
	.dwattr $C$DW$136, DW_AT_TI_symbol_name("xtra")
	.dwattr $C$DW$136, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$136, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$136, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$136, DW_AT_decl_line(0x62)
	.dwattr $C$DW$136, DW_AT_decl_column(0x28)
	.dwendtag $C$DW$T$104

	.dwattr $C$DW$T$104, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$104, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$T$104, DW_AT_decl_column(0x08)
$C$DW$T$137	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Error_Block")
	.dwattr $C$DW$T$137, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$T$137, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$137, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$137, DW_AT_decl_line(0x2e)
	.dwattr $C$DW$T$137, DW_AT_decl_column(0x28)
$C$DW$T$138	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$138, DW_AT_type(*$C$DW$T$137)
	.dwattr $C$DW$T$138, DW_AT_address_class(0x20)

$C$DW$T$108	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$108, DW_AT_name("xdc_runtime_Error_Data")
	.dwattr $C$DW$T$108, DW_AT_byte_size(0x08)
$C$DW$137	.dwtag  DW_TAG_member
	.dwattr $C$DW$137, DW_AT_type(*$C$DW$T$107)
	.dwattr $C$DW$137, DW_AT_name("arg")
	.dwattr $C$DW$137, DW_AT_TI_symbol_name("arg")
	.dwattr $C$DW$137, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$137, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$137, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$137, DW_AT_decl_line(0x55)
	.dwattr $C$DW$137, DW_AT_decl_column(0x26)
	.dwendtag $C$DW$T$108

	.dwattr $C$DW$T$108, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$108, DW_AT_decl_line(0x54)
	.dwattr $C$DW$T$108, DW_AT_decl_column(0x08)
$C$DW$T$93	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Error_Data")
	.dwattr $C$DW$T$93, DW_AT_type(*$C$DW$T$108)
	.dwattr $C$DW$T$93, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$93, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$93, DW_AT_decl_line(0x2d)
	.dwattr $C$DW$T$93, DW_AT_decl_column(0x27)

$C$DW$T$21	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$21, DW_AT_name("xdc_runtime_Error_Module_State")
	.dwattr $C$DW$T$21, DW_AT_declaration
	.dwendtag $C$DW$T$21

	.dwattr $C$DW$T$21, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$21, DW_AT_decl_line(0x2f)
	.dwattr $C$DW$T$21, DW_AT_decl_column(0x10)
$C$DW$T$560	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Error_Module_State")
	.dwattr $C$DW$T$560, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$T$560, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$560, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$560, DW_AT_decl_line(0x2f)
	.dwattr $C$DW$T$560, DW_AT_decl_column(0x2f)

$C$DW$T$561	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$561, DW_AT_name("xdc_runtime_Error_Policy")
	.dwattr $C$DW$T$561, DW_AT_byte_size(0x04)
$C$DW$138	.dwtag  DW_TAG_enumerator, DW_AT_name("xdc_runtime_Error_TERMINATE"), DW_AT_const_value(0x00)
	.dwattr $C$DW$138, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$138, DW_AT_decl_line(0x43)
	.dwattr $C$DW$138, DW_AT_decl_column(0x05)
$C$DW$139	.dwtag  DW_TAG_enumerator, DW_AT_name("xdc_runtime_Error_UNWIND"), DW_AT_const_value(0x01)
	.dwattr $C$DW$139, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$139, DW_AT_decl_line(0x44)
	.dwattr $C$DW$139, DW_AT_decl_column(0x05)
	.dwendtag $C$DW$T$561

	.dwattr $C$DW$T$561, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$561, DW_AT_decl_line(0x42)
	.dwattr $C$DW$T$561, DW_AT_decl_column(0x06)
$C$DW$T$562	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Error_Policy")
	.dwattr $C$DW$T$562, DW_AT_type(*$C$DW$T$561)
	.dwattr $C$DW$T$562, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$562, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$562, DW_AT_decl_line(0x46)
	.dwattr $C$DW$T$562, DW_AT_decl_column(0x27)
$C$DW$T$563	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_policy")
	.dwattr $C$DW$T$563, DW_AT_type(*$C$DW$T$562)
	.dwattr $C$DW$T$563, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$563, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$563, DW_AT_decl_line(0xc8)
	.dwattr $C$DW$T$563, DW_AT_decl_column(0x22)

$C$DW$T$22	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$22, DW_AT_name("xdc_runtime_GateNull_Fxns__")
	.dwattr $C$DW$T$22, DW_AT_declaration
	.dwendtag $C$DW$T$22

	.dwattr $C$DW$T$22, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$22, DW_AT_decl_line(0x43)
	.dwattr $C$DW$T$22, DW_AT_decl_column(0x10)
$C$DW$T$564	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_GateNull_Fxns__")
	.dwattr $C$DW$T$564, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$T$564, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$564, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$564, DW_AT_decl_line(0x43)
	.dwattr $C$DW$T$564, DW_AT_decl_column(0x2c)
$C$DW$T$565	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$565, DW_AT_type(*$C$DW$T$564)
$C$DW$T$566	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$566, DW_AT_type(*$C$DW$T$565)
	.dwattr $C$DW$T$566, DW_AT_address_class(0x20)
$C$DW$T$567	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_GateNull_Module")
	.dwattr $C$DW$T$567, DW_AT_type(*$C$DW$T$566)
	.dwattr $C$DW$T$567, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$567, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$567, DW_AT_decl_line(0x44)
	.dwattr $C$DW$T$567, DW_AT_decl_column(0x2c)

$C$DW$T$23	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$23, DW_AT_name("xdc_runtime_GateNull_Object")
	.dwattr $C$DW$T$23, DW_AT_declaration
	.dwendtag $C$DW$T$23

	.dwattr $C$DW$T$23, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$23, DW_AT_decl_line(0x46)
	.dwattr $C$DW$T$23, DW_AT_decl_column(0x10)
$C$DW$T$568	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_GateNull_Object")
	.dwattr $C$DW$T$568, DW_AT_type(*$C$DW$T$23)
	.dwattr $C$DW$T$568, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$568, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$568, DW_AT_decl_line(0x46)
	.dwattr $C$DW$T$568, DW_AT_decl_column(0x2c)
$C$DW$T$569	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$569, DW_AT_type(*$C$DW$T$568)
	.dwattr $C$DW$T$569, DW_AT_address_class(0x20)
$C$DW$T$570	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_GateNull_Handle")
	.dwattr $C$DW$T$570, DW_AT_type(*$C$DW$T$569)
	.dwattr $C$DW$T$570, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$570, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$570, DW_AT_decl_line(0x48)
	.dwattr $C$DW$T$570, DW_AT_decl_column(0x26)
$C$DW$T$571	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_GateNull_Instance")
	.dwattr $C$DW$T$571, DW_AT_type(*$C$DW$T$569)
	.dwattr $C$DW$T$571, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$571, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$571, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$T$571, DW_AT_decl_column(0x26)

$C$DW$T$24	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$24, DW_AT_name("xdc_runtime_GateNull_Object__")
	.dwattr $C$DW$T$24, DW_AT_declaration
	.dwendtag $C$DW$T$24

	.dwattr $C$DW$T$24, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$24, DW_AT_decl_line(0x49)
	.dwattr $C$DW$T$24, DW_AT_decl_column(0x10)
$C$DW$T$572	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_GateNull_Instance_State")
	.dwattr $C$DW$T$572, DW_AT_type(*$C$DW$T$24)
	.dwattr $C$DW$T$572, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$572, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$572, DW_AT_decl_line(0x49)
	.dwattr $C$DW$T$572, DW_AT_decl_column(0x2e)

$C$DW$T$25	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$25, DW_AT_name("xdc_runtime_GateNull_Params")
	.dwattr $C$DW$T$25, DW_AT_declaration
	.dwendtag $C$DW$T$25

	.dwattr $C$DW$T$25, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$25, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$25, DW_AT_decl_column(0x10)
$C$DW$T$573	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_GateNull_Params")
	.dwattr $C$DW$T$573, DW_AT_type(*$C$DW$T$25)
	.dwattr $C$DW$T$573, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$573, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$573, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$573, DW_AT_decl_column(0x2c)

$C$DW$T$26	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$26, DW_AT_name("xdc_runtime_GateNull_Struct")
	.dwattr $C$DW$T$26, DW_AT_declaration
	.dwendtag $C$DW$T$26

	.dwattr $C$DW$T$26, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$26, DW_AT_decl_line(0x47)
	.dwattr $C$DW$T$26, DW_AT_decl_column(0x10)
$C$DW$T$574	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_GateNull_Struct")
	.dwattr $C$DW$T$574, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$T$574, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$574, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$574, DW_AT_decl_line(0x47)
	.dwattr $C$DW$T$574, DW_AT_decl_column(0x2c)

$C$DW$T$27	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$27, DW_AT_name("xdc_runtime_HeapMin_Fxns__")
	.dwattr $C$DW$T$27, DW_AT_declaration
	.dwendtag $C$DW$T$27

	.dwattr $C$DW$T$27, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$27, DW_AT_decl_line(0x99)
	.dwattr $C$DW$T$27, DW_AT_decl_column(0x10)
$C$DW$T$575	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapMin_Fxns__")
	.dwattr $C$DW$T$575, DW_AT_type(*$C$DW$T$27)
	.dwattr $C$DW$T$575, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$575, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$575, DW_AT_decl_line(0x99)
	.dwattr $C$DW$T$575, DW_AT_decl_column(0x2b)
$C$DW$T$576	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$576, DW_AT_type(*$C$DW$T$575)
$C$DW$T$577	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$577, DW_AT_type(*$C$DW$T$576)
	.dwattr $C$DW$T$577, DW_AT_address_class(0x20)
$C$DW$T$578	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapMin_Module")
	.dwattr $C$DW$T$578, DW_AT_type(*$C$DW$T$577)
	.dwattr $C$DW$T$578, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$578, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$578, DW_AT_decl_line(0x9a)
	.dwattr $C$DW$T$578, DW_AT_decl_column(0x2b)

$C$DW$T$28	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$28, DW_AT_name("xdc_runtime_HeapMin_Object")
	.dwattr $C$DW$T$28, DW_AT_declaration
	.dwendtag $C$DW$T$28

	.dwattr $C$DW$T$28, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$28, DW_AT_decl_line(0x9c)
	.dwattr $C$DW$T$28, DW_AT_decl_column(0x10)
$C$DW$T$579	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapMin_Object")
	.dwattr $C$DW$T$579, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$T$579, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$579, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$579, DW_AT_decl_line(0x9c)
	.dwattr $C$DW$T$579, DW_AT_decl_column(0x2b)
$C$DW$T$580	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$580, DW_AT_type(*$C$DW$T$579)
	.dwattr $C$DW$T$580, DW_AT_address_class(0x20)
$C$DW$T$581	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapMin_Handle")
	.dwattr $C$DW$T$581, DW_AT_type(*$C$DW$T$580)
	.dwattr $C$DW$T$581, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$581, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$581, DW_AT_decl_line(0x9e)
	.dwattr $C$DW$T$581, DW_AT_decl_column(0x25)
$C$DW$T$582	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapMin_Instance")
	.dwattr $C$DW$T$582, DW_AT_type(*$C$DW$T$580)
	.dwattr $C$DW$T$582, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$582, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$582, DW_AT_decl_line(0xa0)
	.dwattr $C$DW$T$582, DW_AT_decl_column(0x25)

$C$DW$T$29	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$29, DW_AT_name("xdc_runtime_HeapMin_Object__")
	.dwattr $C$DW$T$29, DW_AT_declaration
	.dwendtag $C$DW$T$29

	.dwattr $C$DW$T$29, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$29, DW_AT_decl_line(0x9f)
	.dwattr $C$DW$T$29, DW_AT_decl_column(0x10)
$C$DW$T$583	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapMin_Instance_State")
	.dwattr $C$DW$T$583, DW_AT_type(*$C$DW$T$29)
	.dwattr $C$DW$T$583, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$583, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$583, DW_AT_decl_line(0x9f)
	.dwattr $C$DW$T$583, DW_AT_decl_column(0x2d)

$C$DW$T$30	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$30, DW_AT_name("xdc_runtime_HeapMin_Params")
	.dwattr $C$DW$T$30, DW_AT_declaration
	.dwendtag $C$DW$T$30

	.dwattr $C$DW$T$30, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$30, DW_AT_decl_line(0x9b)
	.dwattr $C$DW$T$30, DW_AT_decl_column(0x10)
$C$DW$T$584	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapMin_Params")
	.dwattr $C$DW$T$584, DW_AT_type(*$C$DW$T$30)
	.dwattr $C$DW$T$584, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$584, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$584, DW_AT_decl_line(0x9b)
	.dwattr $C$DW$T$584, DW_AT_decl_column(0x2b)

$C$DW$T$31	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$31, DW_AT_name("xdc_runtime_HeapMin_Struct")
	.dwattr $C$DW$T$31, DW_AT_declaration
	.dwendtag $C$DW$T$31

	.dwattr $C$DW$T$31, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$31, DW_AT_decl_line(0x9d)
	.dwattr $C$DW$T$31, DW_AT_decl_column(0x10)
$C$DW$T$585	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapMin_Struct")
	.dwattr $C$DW$T$585, DW_AT_type(*$C$DW$T$31)
	.dwattr $C$DW$T$585, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$585, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$585, DW_AT_decl_line(0x9d)
	.dwattr $C$DW$T$585, DW_AT_decl_column(0x2b)

$C$DW$T$32	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$32, DW_AT_name("xdc_runtime_HeapStd_Fxns__")
	.dwattr $C$DW$T$32, DW_AT_declaration
	.dwendtag $C$DW$T$32

	.dwattr $C$DW$T$32, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$32, DW_AT_decl_line(0xa7)
	.dwattr $C$DW$T$32, DW_AT_decl_column(0x10)
$C$DW$T$586	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Fxns__")
	.dwattr $C$DW$T$586, DW_AT_type(*$C$DW$T$32)
	.dwattr $C$DW$T$586, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$586, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$586, DW_AT_decl_line(0xa7)
	.dwattr $C$DW$T$586, DW_AT_decl_column(0x2b)
$C$DW$T$587	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$587, DW_AT_type(*$C$DW$T$586)
$C$DW$T$588	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$588, DW_AT_type(*$C$DW$T$587)
	.dwattr $C$DW$T$588, DW_AT_address_class(0x20)
$C$DW$T$589	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Module")
	.dwattr $C$DW$T$589, DW_AT_type(*$C$DW$T$588)
	.dwattr $C$DW$T$589, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$589, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$589, DW_AT_decl_line(0xa8)
	.dwattr $C$DW$T$589, DW_AT_decl_column(0x2b)

$C$DW$T$33	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$33, DW_AT_name("xdc_runtime_HeapStd_Module_State")
	.dwattr $C$DW$T$33, DW_AT_declaration
	.dwendtag $C$DW$T$33

	.dwattr $C$DW$T$33, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$33, DW_AT_decl_line(0xa6)
	.dwattr $C$DW$T$33, DW_AT_decl_column(0x10)
$C$DW$T$590	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Module_State")
	.dwattr $C$DW$T$590, DW_AT_type(*$C$DW$T$33)
	.dwattr $C$DW$T$590, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$590, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$590, DW_AT_decl_line(0xa6)
	.dwattr $C$DW$T$590, DW_AT_decl_column(0x31)

$C$DW$T$34	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$34, DW_AT_name("xdc_runtime_HeapStd_Object")
	.dwattr $C$DW$T$34, DW_AT_declaration
	.dwendtag $C$DW$T$34

	.dwattr $C$DW$T$34, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$34, DW_AT_decl_line(0xaa)
	.dwattr $C$DW$T$34, DW_AT_decl_column(0x10)
$C$DW$T$591	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Object")
	.dwattr $C$DW$T$591, DW_AT_type(*$C$DW$T$34)
	.dwattr $C$DW$T$591, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$591, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$591, DW_AT_decl_line(0xaa)
	.dwattr $C$DW$T$591, DW_AT_decl_column(0x2b)
$C$DW$T$592	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$592, DW_AT_type(*$C$DW$T$591)
	.dwattr $C$DW$T$592, DW_AT_address_class(0x20)
$C$DW$T$593	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Handle")
	.dwattr $C$DW$T$593, DW_AT_type(*$C$DW$T$592)
	.dwattr $C$DW$T$593, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$593, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$593, DW_AT_decl_line(0xac)
	.dwattr $C$DW$T$593, DW_AT_decl_column(0x25)
$C$DW$T$594	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Instance")
	.dwattr $C$DW$T$594, DW_AT_type(*$C$DW$T$592)
	.dwattr $C$DW$T$594, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$594, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$594, DW_AT_decl_line(0xae)
	.dwattr $C$DW$T$594, DW_AT_decl_column(0x25)

$C$DW$T$35	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$35, DW_AT_name("xdc_runtime_HeapStd_Object__")
	.dwattr $C$DW$T$35, DW_AT_declaration
	.dwendtag $C$DW$T$35

	.dwattr $C$DW$T$35, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$35, DW_AT_decl_line(0xad)
	.dwattr $C$DW$T$35, DW_AT_decl_column(0x10)
$C$DW$T$595	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Instance_State")
	.dwattr $C$DW$T$595, DW_AT_type(*$C$DW$T$35)
	.dwattr $C$DW$T$595, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$595, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$595, DW_AT_decl_line(0xad)
	.dwattr $C$DW$T$595, DW_AT_decl_column(0x2d)

$C$DW$T$36	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$36, DW_AT_name("xdc_runtime_HeapStd_Params")
	.dwattr $C$DW$T$36, DW_AT_declaration
	.dwendtag $C$DW$T$36

	.dwattr $C$DW$T$36, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$36, DW_AT_decl_line(0xa9)
	.dwattr $C$DW$T$36, DW_AT_decl_column(0x10)
$C$DW$T$596	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Params")
	.dwattr $C$DW$T$596, DW_AT_type(*$C$DW$T$36)
	.dwattr $C$DW$T$596, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$596, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$596, DW_AT_decl_line(0xa9)
	.dwattr $C$DW$T$596, DW_AT_decl_column(0x2b)

$C$DW$T$37	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$37, DW_AT_name("xdc_runtime_HeapStd_Struct")
	.dwattr $C$DW$T$37, DW_AT_declaration
	.dwendtag $C$DW$T$37

	.dwattr $C$DW$T$37, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$37, DW_AT_decl_line(0xab)
	.dwattr $C$DW$T$37, DW_AT_decl_column(0x10)
$C$DW$T$597	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_HeapStd_Struct")
	.dwattr $C$DW$T$597, DW_AT_type(*$C$DW$T$37)
	.dwattr $C$DW$T$597, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$597, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$597, DW_AT_decl_line(0xab)
	.dwattr $C$DW$T$597, DW_AT_decl_column(0x2b)

$C$DW$T$38	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$38, DW_AT_name("xdc_runtime_IFilterLogger_Fxns__")
	.dwattr $C$DW$T$38, DW_AT_declaration
	.dwendtag $C$DW$T$38

	.dwattr $C$DW$T$38, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$38, DW_AT_decl_line(0x5f)
	.dwattr $C$DW$T$38, DW_AT_decl_column(0x10)
$C$DW$T$109	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IFilterLogger_Fxns__")
	.dwattr $C$DW$T$109, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$T$109, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$109, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$109, DW_AT_decl_line(0x5f)
	.dwattr $C$DW$T$109, DW_AT_decl_column(0x31)
$C$DW$T$110	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$110, DW_AT_type(*$C$DW$T$109)
	.dwattr $C$DW$T$110, DW_AT_address_class(0x20)
$C$DW$T$598	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$598, DW_AT_type(*$C$DW$T$109)
$C$DW$T$599	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$599, DW_AT_type(*$C$DW$T$598)
	.dwattr $C$DW$T$599, DW_AT_address_class(0x20)
$C$DW$T$600	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IFilterLogger_Module")
	.dwattr $C$DW$T$600, DW_AT_type(*$C$DW$T$599)
	.dwattr $C$DW$T$600, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$600, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$600, DW_AT_decl_line(0x60)
	.dwattr $C$DW$T$600, DW_AT_decl_column(0x31)

$C$DW$T$39	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$39, DW_AT_name("xdc_runtime_IFilterLogger_Params")
	.dwattr $C$DW$T$39, DW_AT_declaration
	.dwendtag $C$DW$T$39

	.dwattr $C$DW$T$39, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$39, DW_AT_decl_line(0x61)
	.dwattr $C$DW$T$39, DW_AT_decl_column(0x10)
$C$DW$T$601	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IFilterLogger_Params")
	.dwattr $C$DW$T$601, DW_AT_type(*$C$DW$T$39)
	.dwattr $C$DW$T$601, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$601, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$601, DW_AT_decl_line(0x61)
	.dwattr $C$DW$T$601, DW_AT_decl_column(0x31)

$C$DW$T$111	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$111, DW_AT_name("xdc_runtime_IFilterLogger___Object")
	.dwattr $C$DW$T$111, DW_AT_byte_size(0x08)
$C$DW$140	.dwtag  DW_TAG_member
	.dwattr $C$DW$140, DW_AT_type(*$C$DW$T$110)
	.dwattr $C$DW$140, DW_AT_name("__fxns")
	.dwattr $C$DW$140, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$140, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$140, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$140, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$140, DW_AT_decl_line(0x62)
	.dwattr $C$DW$140, DW_AT_decl_column(0x57)
$C$DW$141	.dwtag  DW_TAG_member
	.dwattr $C$DW$141, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$141, DW_AT_name("__label")
	.dwattr $C$DW$141, DW_AT_TI_symbol_name("__label")
	.dwattr $C$DW$141, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$141, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$141, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$141, DW_AT_decl_line(0x62)
	.dwattr $C$DW$141, DW_AT_decl_column(0x6a)
	.dwendtag $C$DW$T$111

	.dwattr $C$DW$T$111, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$111, DW_AT_decl_line(0x62)
	.dwattr $C$DW$T$111, DW_AT_decl_column(0x10)
$C$DW$T$602	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$602, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$T$602, DW_AT_address_class(0x20)
$C$DW$T$603	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IFilterLogger_Handle")
	.dwattr $C$DW$T$603, DW_AT_type(*$C$DW$T$602)
	.dwattr $C$DW$T$603, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$603, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$603, DW_AT_decl_line(0x62)
	.dwattr $C$DW$T$603, DW_AT_decl_column(0x76)

$C$DW$T$125	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$125, DW_AT_name("xdc_runtime_IGateProvider_Fxns__")
	.dwattr $C$DW$T$125, DW_AT_byte_size(0x24)
$C$DW$142	.dwtag  DW_TAG_member
	.dwattr $C$DW$142, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$142, DW_AT_name("__base")
	.dwattr $C$DW$142, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$142, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$142, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$142, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$142, DW_AT_decl_line(0x59)
	.dwattr $C$DW$142, DW_AT_decl_column(0x1d)
$C$DW$143	.dwtag  DW_TAG_member
	.dwattr $C$DW$143, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$143, DW_AT_name("__sysp")
	.dwattr $C$DW$143, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$143, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$143, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$143, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$143, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$143, DW_AT_decl_column(0x27)
$C$DW$144	.dwtag  DW_TAG_member
	.dwattr $C$DW$144, DW_AT_type(*$C$DW$T$120)
	.dwattr $C$DW$144, DW_AT_name("query")
	.dwattr $C$DW$144, DW_AT_TI_symbol_name("query")
	.dwattr $C$DW$144, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$144, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$144, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$144, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$144, DW_AT_decl_column(0x10)
$C$DW$145	.dwtag  DW_TAG_member
	.dwattr $C$DW$145, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$145, DW_AT_name("enter")
	.dwattr $C$DW$145, DW_AT_TI_symbol_name("enter")
	.dwattr $C$DW$145, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$145, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$145, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$145, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$145, DW_AT_decl_column(0x10)
$C$DW$146	.dwtag  DW_TAG_member
	.dwattr $C$DW$146, DW_AT_type(*$C$DW$T$124)
	.dwattr $C$DW$146, DW_AT_name("leave")
	.dwattr $C$DW$146, DW_AT_TI_symbol_name("leave")
	.dwattr $C$DW$146, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$146, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$146, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$146, DW_AT_decl_line(0x5d)
	.dwattr $C$DW$146, DW_AT_decl_column(0x10)
$C$DW$147	.dwtag  DW_TAG_member
	.dwattr $C$DW$147, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$147, DW_AT_name("__sfxns")
	.dwattr $C$DW$147, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$147, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$147, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$147, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$147, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$147, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$125

	.dwattr $C$DW$T$125, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$T$125, DW_AT_decl_line(0x58)
	.dwattr $C$DW$T$125, DW_AT_decl_column(0x08)
$C$DW$T$132	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IGateProvider_Fxns__")
	.dwattr $C$DW$T$132, DW_AT_type(*$C$DW$T$125)
	.dwattr $C$DW$T$132, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$132, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$132, DW_AT_decl_line(0x3a)
	.dwattr $C$DW$T$132, DW_AT_decl_column(0x31)
$C$DW$T$133	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$133, DW_AT_type(*$C$DW$T$132)
	.dwattr $C$DW$T$133, DW_AT_address_class(0x20)
$C$DW$T$604	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$604, DW_AT_type(*$C$DW$T$132)
$C$DW$T$605	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$605, DW_AT_type(*$C$DW$T$604)
	.dwattr $C$DW$T$605, DW_AT_address_class(0x20)
$C$DW$T$606	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IGateProvider_Module")
	.dwattr $C$DW$T$606, DW_AT_type(*$C$DW$T$605)
	.dwattr $C$DW$T$606, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$606, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$606, DW_AT_decl_line(0x3b)
	.dwattr $C$DW$T$606, DW_AT_decl_column(0x31)

$C$DW$T$131	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$131, DW_AT_name("xdc_runtime_IGateProvider_Params")
	.dwattr $C$DW$T$131, DW_AT_byte_size(0x10)
$C$DW$148	.dwtag  DW_TAG_member
	.dwattr $C$DW$148, DW_AT_type(*$C$DW$T$126)
	.dwattr $C$DW$148, DW_AT_name("__size")
	.dwattr $C$DW$148, DW_AT_TI_symbol_name("__size")
	.dwattr $C$DW$148, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$148, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$148, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$148, DW_AT_decl_line(0x4c)
	.dwattr $C$DW$148, DW_AT_decl_column(0x0c)
$C$DW$149	.dwtag  DW_TAG_member
	.dwattr $C$DW$149, DW_AT_type(*$C$DW$T$128)
	.dwattr $C$DW$149, DW_AT_name("__self")
	.dwattr $C$DW$149, DW_AT_TI_symbol_name("__self")
	.dwattr $C$DW$149, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$149, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$149, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$149, DW_AT_decl_line(0x4d)
	.dwattr $C$DW$149, DW_AT_decl_column(0x11)
$C$DW$150	.dwtag  DW_TAG_member
	.dwattr $C$DW$150, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$150, DW_AT_name("__fxns")
	.dwattr $C$DW$150, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$150, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$150, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$150, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$150, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$150, DW_AT_decl_column(0x0b)
$C$DW$151	.dwtag  DW_TAG_member
	.dwattr $C$DW$151, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$151, DW_AT_name("instance")
	.dwattr $C$DW$151, DW_AT_TI_symbol_name("instance")
	.dwattr $C$DW$151, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$151, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$151, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$151, DW_AT_decl_line(0x4f)
	.dwattr $C$DW$151, DW_AT_decl_column(0x23)
	.dwendtag $C$DW$T$131

	.dwattr $C$DW$T$131, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IGateProvider.h")
	.dwattr $C$DW$T$131, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$T$131, DW_AT_decl_column(0x08)
$C$DW$T$607	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IGateProvider_Params")
	.dwattr $C$DW$T$607, DW_AT_type(*$C$DW$T$131)
	.dwattr $C$DW$T$607, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$607, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$607, DW_AT_decl_line(0x3c)
	.dwattr $C$DW$T$607, DW_AT_decl_column(0x31)

$C$DW$T$134	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$134, DW_AT_name("xdc_runtime_IGateProvider___Object")
	.dwattr $C$DW$T$134, DW_AT_byte_size(0x08)
$C$DW$152	.dwtag  DW_TAG_member
	.dwattr $C$DW$152, DW_AT_type(*$C$DW$T$133)
	.dwattr $C$DW$152, DW_AT_name("__fxns")
	.dwattr $C$DW$152, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$152, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$152, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$152, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$152, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$152, DW_AT_decl_column(0x57)
$C$DW$153	.dwtag  DW_TAG_member
	.dwattr $C$DW$153, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$153, DW_AT_name("__label")
	.dwattr $C$DW$153, DW_AT_TI_symbol_name("__label")
	.dwattr $C$DW$153, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$153, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$153, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$153, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$153, DW_AT_decl_column(0x6a)
	.dwendtag $C$DW$T$134

	.dwattr $C$DW$T$134, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$134, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$T$134, DW_AT_decl_column(0x10)
$C$DW$T$175	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$175, DW_AT_type(*$C$DW$T$134)
	.dwattr $C$DW$T$175, DW_AT_address_class(0x20)
$C$DW$T$608	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IGateProvider_Handle")
	.dwattr $C$DW$T$608, DW_AT_type(*$C$DW$T$175)
	.dwattr $C$DW$T$608, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$608, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$608, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$T$608, DW_AT_decl_column(0x76)
$C$DW$T$609	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Module_GateProxy_Handle")
	.dwattr $C$DW$T$609, DW_AT_type(*$C$DW$T$175)
	.dwattr $C$DW$T$609, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$609, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$609, DW_AT_decl_line(0x136)
	.dwattr $C$DW$T$609, DW_AT_decl_column(0x34)
$C$DW$T$176	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Main_Module_GateProxy_Handle")
	.dwattr $C$DW$T$176, DW_AT_type(*$C$DW$T$175)
	.dwattr $C$DW$T$176, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$176, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$176, DW_AT_decl_line(0x146)
	.dwattr $C$DW$T$176, DW_AT_decl_column(0x34)
$C$DW$T$610	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_System_Module_GateProxy_Handle")
	.dwattr $C$DW$T$610, DW_AT_type(*$C$DW$T$175)
	.dwattr $C$DW$T$610, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$610, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$610, DW_AT_decl_line(0x15f)
	.dwattr $C$DW$T$610, DW_AT_decl_column(0x34)

$C$DW$T$149	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$149, DW_AT_name("xdc_runtime_IHeap_Fxns__")
	.dwattr $C$DW$T$149, DW_AT_byte_size(0x28)
$C$DW$154	.dwtag  DW_TAG_member
	.dwattr $C$DW$154, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$154, DW_AT_name("__base")
	.dwattr $C$DW$154, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$154, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$154, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$154, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$154, DW_AT_decl_line(0x55)
	.dwattr $C$DW$154, DW_AT_decl_column(0x1d)
$C$DW$155	.dwtag  DW_TAG_member
	.dwattr $C$DW$155, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$155, DW_AT_name("__sysp")
	.dwattr $C$DW$155, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$155, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$155, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$155, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$155, DW_AT_decl_line(0x56)
	.dwattr $C$DW$155, DW_AT_decl_column(0x27)
$C$DW$156	.dwtag  DW_TAG_member
	.dwattr $C$DW$156, DW_AT_type(*$C$DW$T$140)
	.dwattr $C$DW$156, DW_AT_name("alloc")
	.dwattr $C$DW$156, DW_AT_TI_symbol_name("alloc")
	.dwattr $C$DW$156, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$156, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$156, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$156, DW_AT_decl_line(0x57)
	.dwattr $C$DW$156, DW_AT_decl_column(0x0f)
$C$DW$157	.dwtag  DW_TAG_member
	.dwattr $C$DW$157, DW_AT_type(*$C$DW$T$142)
	.dwattr $C$DW$157, DW_AT_name("free")
	.dwattr $C$DW$157, DW_AT_TI_symbol_name("free")
	.dwattr $C$DW$157, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$157, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$157, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$157, DW_AT_decl_line(0x58)
	.dwattr $C$DW$157, DW_AT_decl_column(0x10)
$C$DW$158	.dwtag  DW_TAG_member
	.dwattr $C$DW$158, DW_AT_type(*$C$DW$T$144)
	.dwattr $C$DW$158, DW_AT_name("isBlocking")
	.dwattr $C$DW$158, DW_AT_TI_symbol_name("isBlocking")
	.dwattr $C$DW$158, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$158, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$158, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$158, DW_AT_decl_line(0x59)
	.dwattr $C$DW$158, DW_AT_decl_column(0x10)
$C$DW$159	.dwtag  DW_TAG_member
	.dwattr $C$DW$159, DW_AT_type(*$C$DW$T$148)
	.dwattr $C$DW$159, DW_AT_name("getStats")
	.dwattr $C$DW$159, DW_AT_TI_symbol_name("getStats")
	.dwattr $C$DW$159, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$159, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$159, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$159, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$159, DW_AT_decl_column(0x10)
$C$DW$160	.dwtag  DW_TAG_member
	.dwattr $C$DW$160, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$160, DW_AT_name("__sfxns")
	.dwattr $C$DW$160, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$160, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$160, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$160, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$160, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$160, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$149

	.dwattr $C$DW$T$149, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$T$149, DW_AT_decl_line(0x54)
	.dwattr $C$DW$T$149, DW_AT_decl_column(0x08)
$C$DW$T$151	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IHeap_Fxns__")
	.dwattr $C$DW$T$151, DW_AT_type(*$C$DW$T$149)
	.dwattr $C$DW$T$151, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$151, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$151, DW_AT_decl_line(0x90)
	.dwattr $C$DW$T$151, DW_AT_decl_column(0x29)
$C$DW$T$152	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$152, DW_AT_type(*$C$DW$T$151)
	.dwattr $C$DW$T$152, DW_AT_address_class(0x20)
$C$DW$T$611	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$611, DW_AT_type(*$C$DW$T$151)
$C$DW$T$612	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$612, DW_AT_type(*$C$DW$T$611)
	.dwattr $C$DW$T$612, DW_AT_address_class(0x20)
$C$DW$T$613	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IHeap_Module")
	.dwattr $C$DW$T$613, DW_AT_type(*$C$DW$T$612)
	.dwattr $C$DW$T$613, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$613, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$613, DW_AT_decl_line(0x91)
	.dwattr $C$DW$T$613, DW_AT_decl_column(0x29)

$C$DW$T$150	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$150, DW_AT_name("xdc_runtime_IHeap_Params")
	.dwattr $C$DW$T$150, DW_AT_byte_size(0x10)
$C$DW$161	.dwtag  DW_TAG_member
	.dwattr $C$DW$161, DW_AT_type(*$C$DW$T$126)
	.dwattr $C$DW$161, DW_AT_name("__size")
	.dwattr $C$DW$161, DW_AT_TI_symbol_name("__size")
	.dwattr $C$DW$161, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$161, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$161, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$161, DW_AT_decl_line(0x48)
	.dwattr $C$DW$161, DW_AT_decl_column(0x0c)
$C$DW$162	.dwtag  DW_TAG_member
	.dwattr $C$DW$162, DW_AT_type(*$C$DW$T$128)
	.dwattr $C$DW$162, DW_AT_name("__self")
	.dwattr $C$DW$162, DW_AT_TI_symbol_name("__self")
	.dwattr $C$DW$162, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$162, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$162, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$162, DW_AT_decl_line(0x49)
	.dwattr $C$DW$162, DW_AT_decl_column(0x11)
$C$DW$163	.dwtag  DW_TAG_member
	.dwattr $C$DW$163, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$163, DW_AT_name("__fxns")
	.dwattr $C$DW$163, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$163, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$163, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$163, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$163, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$163, DW_AT_decl_column(0x0b)
$C$DW$164	.dwtag  DW_TAG_member
	.dwattr $C$DW$164, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$164, DW_AT_name("instance")
	.dwattr $C$DW$164, DW_AT_TI_symbol_name("instance")
	.dwattr $C$DW$164, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$164, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$164, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$164, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$164, DW_AT_decl_column(0x23)
	.dwendtag $C$DW$T$150

	.dwattr $C$DW$T$150, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IHeap.h")
	.dwattr $C$DW$T$150, DW_AT_decl_line(0x47)
	.dwattr $C$DW$T$150, DW_AT_decl_column(0x08)
$C$DW$T$614	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IHeap_Params")
	.dwattr $C$DW$T$614, DW_AT_type(*$C$DW$T$150)
	.dwattr $C$DW$T$614, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$614, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$614, DW_AT_decl_line(0x92)
	.dwattr $C$DW$T$614, DW_AT_decl_column(0x29)

$C$DW$T$153	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$153, DW_AT_name("xdc_runtime_IHeap___Object")
	.dwattr $C$DW$T$153, DW_AT_byte_size(0x08)
$C$DW$165	.dwtag  DW_TAG_member
	.dwattr $C$DW$165, DW_AT_type(*$C$DW$T$152)
	.dwattr $C$DW$165, DW_AT_name("__fxns")
	.dwattr $C$DW$165, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$165, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$165, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$165, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$165, DW_AT_decl_line(0x93)
	.dwattr $C$DW$165, DW_AT_decl_column(0x47)
$C$DW$166	.dwtag  DW_TAG_member
	.dwattr $C$DW$166, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$166, DW_AT_name("__label")
	.dwattr $C$DW$166, DW_AT_TI_symbol_name("__label")
	.dwattr $C$DW$166, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$166, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$166, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$166, DW_AT_decl_line(0x93)
	.dwattr $C$DW$166, DW_AT_decl_column(0x5a)
	.dwendtag $C$DW$T$153

	.dwattr $C$DW$T$153, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$153, DW_AT_decl_line(0x93)
	.dwattr $C$DW$T$153, DW_AT_decl_column(0x10)
$C$DW$T$190	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$190, DW_AT_type(*$C$DW$T$153)
	.dwattr $C$DW$T$190, DW_AT_address_class(0x20)
$C$DW$T$615	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IHeap_Handle")
	.dwattr $C$DW$T$615, DW_AT_type(*$C$DW$T$190)
	.dwattr $C$DW$T$615, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$615, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$615, DW_AT_decl_line(0x93)
	.dwattr $C$DW$T$615, DW_AT_decl_column(0x66)
$C$DW$T$616	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Error_Object__heap")
	.dwattr $C$DW$T$616, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$616, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$616, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Error.h")
	.dwattr $C$DW$T$616, DW_AT_decl_line(0xac)
	.dwattr $C$DW$T$616, DW_AT_decl_column(0x22)
$C$DW$T$617	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Module_GateProxy_Object__heap")
	.dwattr $C$DW$T$617, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$617, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$617, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$617, DW_AT_decl_line(0x8a)
	.dwattr $C$DW$T$617, DW_AT_decl_column(0x22)
$C$DW$T$618	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Main_Object__heap")
	.dwattr $C$DW$T$618, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$618, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$618, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Main.h")
	.dwattr $C$DW$T$618, DW_AT_decl_line(0x88)
	.dwattr $C$DW$T$618, DW_AT_decl_column(0x22)
$C$DW$T$619	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_HeapProxy_Object__heap")
	.dwattr $C$DW$T$619, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$619, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$619, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$619, DW_AT_decl_line(0x84)
	.dwattr $C$DW$T$619, DW_AT_decl_column(0x22)
$C$DW$T$620	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_Object__heap")
	.dwattr $C$DW$T$620, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$620, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$620, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$620, DW_AT_decl_line(0x96)
	.dwattr $C$DW$T$620, DW_AT_decl_column(0x22)
$C$DW$T$621	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Memory_defaultHeapInstance")
	.dwattr $C$DW$T$621, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$621, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$621, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$621, DW_AT_decl_line(0xa3)
	.dwattr $C$DW$T$621, DW_AT_decl_column(0x22)
$C$DW$T$622	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_Object__heap")
	.dwattr $C$DW$T$622, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$622, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$622, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$622, DW_AT_decl_line(0x8a)
	.dwattr $C$DW$T$622, DW_AT_decl_column(0x22)
$C$DW$T$623	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Timestamp_SupportProxy_Object__heap")
	.dwattr $C$DW$T$623, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$623, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$623, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$623, DW_AT_decl_line(0x81)
	.dwattr $C$DW$T$623, DW_AT_decl_column(0x22)
$C$DW$T$624	.dwtag  DW_TAG_typedef, DW_AT_name("CT__xdc_runtime_Types_Object__heap")
	.dwattr $C$DW$T$624, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$624, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$624, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$624, DW_AT_decl_line(0x10a)
	.dwattr $C$DW$T$624, DW_AT_decl_column(0x22)
$C$DW$T$191	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_HeapProxy_Handle")
	.dwattr $C$DW$T$191, DW_AT_type(*$C$DW$T$190)
	.dwattr $C$DW$T$191, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$191, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$191, DW_AT_decl_line(0x14f)
	.dwattr $C$DW$T$191, DW_AT_decl_column(0x2c)

$C$DW$T$154	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$154, DW_AT_name("xdc_runtime_IInstance_Fxns__")
	.dwattr $C$DW$T$154, DW_AT_byte_size(0x18)
$C$DW$167	.dwtag  DW_TAG_member
	.dwattr $C$DW$167, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$167, DW_AT_name("__base")
	.dwattr $C$DW$167, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$167, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$167, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$167, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IInstance.h")
	.dwattr $C$DW$167, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$167, DW_AT_decl_column(0x1d)
$C$DW$168	.dwtag  DW_TAG_member
	.dwattr $C$DW$168, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$168, DW_AT_name("__sysp")
	.dwattr $C$DW$168, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$168, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$168, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$168, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IInstance.h")
	.dwattr $C$DW$168, DW_AT_decl_line(0x4f)
	.dwattr $C$DW$168, DW_AT_decl_column(0x27)
$C$DW$169	.dwtag  DW_TAG_member
	.dwattr $C$DW$169, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$169, DW_AT_name("__sfxns")
	.dwattr $C$DW$169, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$169, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$169, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$169, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IInstance.h")
	.dwattr $C$DW$169, DW_AT_decl_line(0x50)
	.dwattr $C$DW$169, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$154

	.dwattr $C$DW$T$154, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IInstance.h")
	.dwattr $C$DW$T$154, DW_AT_decl_line(0x4d)
	.dwattr $C$DW$T$154, DW_AT_decl_column(0x08)
$C$DW$T$156	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IInstance_Fxns__")
	.dwattr $C$DW$T$156, DW_AT_type(*$C$DW$T$154)
	.dwattr $C$DW$T$156, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$156, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$156, DW_AT_decl_line(0x123)
	.dwattr $C$DW$T$156, DW_AT_decl_column(0x2d)
$C$DW$T$157	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$157, DW_AT_type(*$C$DW$T$156)
	.dwattr $C$DW$T$157, DW_AT_address_class(0x20)
$C$DW$T$625	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$625, DW_AT_type(*$C$DW$T$156)
$C$DW$T$626	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$626, DW_AT_type(*$C$DW$T$625)
	.dwattr $C$DW$T$626, DW_AT_address_class(0x20)
$C$DW$T$627	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IInstance_Module")
	.dwattr $C$DW$T$627, DW_AT_type(*$C$DW$T$626)
	.dwattr $C$DW$T$627, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$627, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$627, DW_AT_decl_line(0x124)
	.dwattr $C$DW$T$627, DW_AT_decl_column(0x2d)

$C$DW$T$155	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$155, DW_AT_name("xdc_runtime_IInstance_Params")
	.dwattr $C$DW$T$155, DW_AT_byte_size(0x08)
$C$DW$170	.dwtag  DW_TAG_member
	.dwattr $C$DW$170, DW_AT_type(*$C$DW$T$126)
	.dwattr $C$DW$170, DW_AT_name("__size")
	.dwattr $C$DW$170, DW_AT_TI_symbol_name("__size")
	.dwattr $C$DW$170, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$170, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$170, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IInstance.h")
	.dwattr $C$DW$170, DW_AT_decl_line(0x43)
	.dwattr $C$DW$170, DW_AT_decl_column(0x0c)
$C$DW$171	.dwtag  DW_TAG_member
	.dwattr $C$DW$171, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$171, DW_AT_name("name")
	.dwattr $C$DW$171, DW_AT_TI_symbol_name("name")
	.dwattr $C$DW$171, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$171, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$171, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IInstance.h")
	.dwattr $C$DW$171, DW_AT_decl_line(0x44)
	.dwattr $C$DW$171, DW_AT_decl_column(0x10)
	.dwendtag $C$DW$T$155

	.dwattr $C$DW$T$155, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IInstance.h")
	.dwattr $C$DW$T$155, DW_AT_decl_line(0x42)
	.dwattr $C$DW$T$155, DW_AT_decl_column(0x08)
$C$DW$T$129	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IInstance_Params")
	.dwattr $C$DW$T$129, DW_AT_type(*$C$DW$T$155)
	.dwattr $C$DW$T$129, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$129, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$129, DW_AT_decl_line(0x125)
	.dwattr $C$DW$T$129, DW_AT_decl_column(0x2d)
$C$DW$T$130	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$130, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$T$130, DW_AT_address_class(0x20)

$C$DW$T$158	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$158, DW_AT_name("xdc_runtime_IInstance___Object")
	.dwattr $C$DW$T$158, DW_AT_byte_size(0x08)
$C$DW$172	.dwtag  DW_TAG_member
	.dwattr $C$DW$172, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$172, DW_AT_name("__fxns")
	.dwattr $C$DW$172, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$172, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$172, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$172, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$172, DW_AT_decl_line(0x126)
	.dwattr $C$DW$172, DW_AT_decl_column(0x4f)
$C$DW$173	.dwtag  DW_TAG_member
	.dwattr $C$DW$173, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$173, DW_AT_name("__label")
	.dwattr $C$DW$173, DW_AT_TI_symbol_name("__label")
	.dwattr $C$DW$173, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$173, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$173, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$173, DW_AT_decl_line(0x126)
	.dwattr $C$DW$173, DW_AT_decl_column(0x62)
	.dwendtag $C$DW$T$158

	.dwattr $C$DW$T$158, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$158, DW_AT_decl_line(0x126)
	.dwattr $C$DW$T$158, DW_AT_decl_column(0x10)
$C$DW$T$628	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$628, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$T$628, DW_AT_address_class(0x20)
$C$DW$T$629	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IInstance_Handle")
	.dwattr $C$DW$T$629, DW_AT_type(*$C$DW$T$628)
	.dwattr $C$DW$T$629, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$629, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$629, DW_AT_decl_line(0x126)
	.dwattr $C$DW$T$629, DW_AT_decl_column(0x6e)

$C$DW$T$40	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$40, DW_AT_name("xdc_runtime_ILogger_Fxns__")
	.dwattr $C$DW$T$40, DW_AT_declaration
	.dwendtag $C$DW$T$40

	.dwattr $C$DW$T$40, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$40, DW_AT_decl_line(0x56)
	.dwattr $C$DW$T$40, DW_AT_decl_column(0x10)
$C$DW$T$159	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ILogger_Fxns__")
	.dwattr $C$DW$T$159, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$T$159, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$159, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$159, DW_AT_decl_line(0x56)
	.dwattr $C$DW$T$159, DW_AT_decl_column(0x2b)
$C$DW$T$160	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$160, DW_AT_type(*$C$DW$T$159)
	.dwattr $C$DW$T$160, DW_AT_address_class(0x20)
$C$DW$T$630	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$630, DW_AT_type(*$C$DW$T$159)
$C$DW$T$631	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$631, DW_AT_type(*$C$DW$T$630)
	.dwattr $C$DW$T$631, DW_AT_address_class(0x20)
$C$DW$T$632	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ILogger_Module")
	.dwattr $C$DW$T$632, DW_AT_type(*$C$DW$T$631)
	.dwattr $C$DW$T$632, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$632, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$632, DW_AT_decl_line(0x57)
	.dwattr $C$DW$T$632, DW_AT_decl_column(0x2b)

$C$DW$T$41	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$41, DW_AT_name("xdc_runtime_ILogger_Params")
	.dwattr $C$DW$T$41, DW_AT_declaration
	.dwendtag $C$DW$T$41

	.dwattr $C$DW$T$41, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$41, DW_AT_decl_line(0x58)
	.dwattr $C$DW$T$41, DW_AT_decl_column(0x10)
$C$DW$T$633	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ILogger_Params")
	.dwattr $C$DW$T$633, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$633, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$633, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$633, DW_AT_decl_line(0x58)
	.dwattr $C$DW$T$633, DW_AT_decl_column(0x2b)

$C$DW$T$161	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$161, DW_AT_name("xdc_runtime_ILogger___Object")
	.dwattr $C$DW$T$161, DW_AT_byte_size(0x08)
$C$DW$174	.dwtag  DW_TAG_member
	.dwattr $C$DW$174, DW_AT_type(*$C$DW$T$160)
	.dwattr $C$DW$174, DW_AT_name("__fxns")
	.dwattr $C$DW$174, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$174, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$174, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$174, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$174, DW_AT_decl_line(0x59)
	.dwattr $C$DW$174, DW_AT_decl_column(0x4b)
$C$DW$175	.dwtag  DW_TAG_member
	.dwattr $C$DW$175, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$175, DW_AT_name("__label")
	.dwattr $C$DW$175, DW_AT_TI_symbol_name("__label")
	.dwattr $C$DW$175, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$175, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$175, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$175, DW_AT_decl_line(0x59)
	.dwattr $C$DW$175, DW_AT_decl_column(0x5e)
	.dwendtag $C$DW$T$161

	.dwattr $C$DW$T$161, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$161, DW_AT_decl_line(0x59)
	.dwattr $C$DW$T$161, DW_AT_decl_column(0x10)
$C$DW$T$634	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$634, DW_AT_type(*$C$DW$T$161)
	.dwattr $C$DW$T$634, DW_AT_address_class(0x20)
$C$DW$T$635	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ILogger_Handle")
	.dwattr $C$DW$T$635, DW_AT_type(*$C$DW$T$634)
	.dwattr $C$DW$T$635, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$635, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$635, DW_AT_decl_line(0x59)
	.dwattr $C$DW$T$635, DW_AT_decl_column(0x6a)

$C$DW$T$162	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$162, DW_AT_name("xdc_runtime_IModule_Fxns__")
	.dwattr $C$DW$T$162, DW_AT_byte_size(0x18)
$C$DW$176	.dwtag  DW_TAG_member
	.dwattr $C$DW$176, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$176, DW_AT_name("__base")
	.dwattr $C$DW$176, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$176, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$176, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$176, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IModule.h")
	.dwattr $C$DW$176, DW_AT_decl_line(0x46)
	.dwattr $C$DW$176, DW_AT_decl_column(0x1d)
$C$DW$177	.dwtag  DW_TAG_member
	.dwattr $C$DW$177, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$177, DW_AT_name("__sysp")
	.dwattr $C$DW$177, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$177, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$177, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$177, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IModule.h")
	.dwattr $C$DW$177, DW_AT_decl_line(0x47)
	.dwattr $C$DW$177, DW_AT_decl_column(0x27)
$C$DW$178	.dwtag  DW_TAG_member
	.dwattr $C$DW$178, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$178, DW_AT_name("__sfxns")
	.dwattr $C$DW$178, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$178, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$178, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$178, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IModule.h")
	.dwattr $C$DW$178, DW_AT_decl_line(0x48)
	.dwattr $C$DW$178, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$162

	.dwattr $C$DW$T$162, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/IModule.h")
	.dwattr $C$DW$T$162, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$162, DW_AT_decl_column(0x08)
$C$DW$T$636	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IModule_Fxns__")
	.dwattr $C$DW$T$636, DW_AT_type(*$C$DW$T$162)
	.dwattr $C$DW$T$636, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$636, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$636, DW_AT_decl_line(0x10)
	.dwattr $C$DW$T$636, DW_AT_decl_column(0x2b)
$C$DW$T$637	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$637, DW_AT_type(*$C$DW$T$636)
$C$DW$T$638	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$638, DW_AT_type(*$C$DW$T$637)
	.dwattr $C$DW$T$638, DW_AT_address_class(0x20)
$C$DW$T$639	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_IModule_Module")
	.dwattr $C$DW$T$639, DW_AT_type(*$C$DW$T$638)
	.dwattr $C$DW$T$639, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$639, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$639, DW_AT_decl_line(0x11)
	.dwattr $C$DW$T$639, DW_AT_decl_column(0x2b)

$C$DW$T$42	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$42, DW_AT_name("xdc_runtime_ISystemSupport_Fxns__")
	.dwattr $C$DW$T$42, DW_AT_declaration
	.dwendtag $C$DW$T$42

	.dwattr $C$DW$T$42, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$42, DW_AT_decl_line(0xce)
	.dwattr $C$DW$T$42, DW_AT_decl_column(0x10)
$C$DW$T$640	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ISystemSupport_Fxns__")
	.dwattr $C$DW$T$640, DW_AT_type(*$C$DW$T$42)
	.dwattr $C$DW$T$640, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$640, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$640, DW_AT_decl_line(0xce)
	.dwattr $C$DW$T$640, DW_AT_decl_column(0x32)
$C$DW$T$641	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$641, DW_AT_type(*$C$DW$T$640)
$C$DW$T$642	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$642, DW_AT_type(*$C$DW$T$641)
	.dwattr $C$DW$T$642, DW_AT_address_class(0x20)
$C$DW$T$643	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ISystemSupport_Module")
	.dwattr $C$DW$T$643, DW_AT_type(*$C$DW$T$642)
	.dwattr $C$DW$T$643, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$643, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$643, DW_AT_decl_line(0xcf)
	.dwattr $C$DW$T$643, DW_AT_decl_column(0x32)

$C$DW$T$173	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$173, DW_AT_name("xdc_runtime_ITimestampClient_Fxns__")
	.dwattr $C$DW$T$173, DW_AT_byte_size(0x24)
$C$DW$179	.dwtag  DW_TAG_member
	.dwattr $C$DW$179, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$179, DW_AT_name("__base")
	.dwattr $C$DW$179, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$179, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$179, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$179, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$179, DW_AT_decl_line(0x45)
	.dwattr $C$DW$179, DW_AT_decl_column(0x1d)
$C$DW$180	.dwtag  DW_TAG_member
	.dwattr $C$DW$180, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$180, DW_AT_name("__sysp")
	.dwattr $C$DW$180, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$180, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$180, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$180, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$180, DW_AT_decl_line(0x46)
	.dwattr $C$DW$180, DW_AT_decl_column(0x27)
$C$DW$181	.dwtag  DW_TAG_member
	.dwattr $C$DW$181, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$181, DW_AT_name("get32")
	.dwattr $C$DW$181, DW_AT_TI_symbol_name("get32")
	.dwattr $C$DW$181, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$181, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$181, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$181, DW_AT_decl_line(0x47)
	.dwattr $C$DW$181, DW_AT_decl_column(0x12)
$C$DW$182	.dwtag  DW_TAG_member
	.dwattr $C$DW$182, DW_AT_type(*$C$DW$T$168)
	.dwattr $C$DW$182, DW_AT_name("get64")
	.dwattr $C$DW$182, DW_AT_TI_symbol_name("get64")
	.dwattr $C$DW$182, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$182, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$182, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$182, DW_AT_decl_line(0x48)
	.dwattr $C$DW$182, DW_AT_decl_column(0x10)
$C$DW$183	.dwtag  DW_TAG_member
	.dwattr $C$DW$183, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$183, DW_AT_name("getFreq")
	.dwattr $C$DW$183, DW_AT_TI_symbol_name("getFreq")
	.dwattr $C$DW$183, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$183, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$183, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$183, DW_AT_decl_line(0x49)
	.dwattr $C$DW$183, DW_AT_decl_column(0x10)
$C$DW$184	.dwtag  DW_TAG_member
	.dwattr $C$DW$184, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$184, DW_AT_name("__sfxns")
	.dwattr $C$DW$184, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$184, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$184, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$184, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$184, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$184, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$173

	.dwattr $C$DW$T$173, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampClient.h")
	.dwattr $C$DW$T$173, DW_AT_decl_line(0x44)
	.dwattr $C$DW$T$173, DW_AT_decl_column(0x08)
$C$DW$T$644	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampClient_Fxns__")
	.dwattr $C$DW$T$644, DW_AT_type(*$C$DW$T$173)
	.dwattr $C$DW$T$644, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$644, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$644, DW_AT_decl_line(0xed)
	.dwattr $C$DW$T$644, DW_AT_decl_column(0x34)
$C$DW$T$645	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$645, DW_AT_type(*$C$DW$T$644)
$C$DW$T$646	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$646, DW_AT_type(*$C$DW$T$645)
	.dwattr $C$DW$T$646, DW_AT_address_class(0x20)
$C$DW$T$647	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampClient_Module")
	.dwattr $C$DW$T$647, DW_AT_type(*$C$DW$T$646)
	.dwattr $C$DW$T$647, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$647, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$647, DW_AT_decl_line(0xee)
	.dwattr $C$DW$T$647, DW_AT_decl_column(0x34)

$C$DW$T$174	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$174, DW_AT_name("xdc_runtime_ITimestampProvider_Fxns__")
	.dwattr $C$DW$T$174, DW_AT_byte_size(0x24)
$C$DW$185	.dwtag  DW_TAG_member
	.dwattr $C$DW$185, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$185, DW_AT_name("__base")
	.dwattr $C$DW$185, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$185, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$185, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$185, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$185, DW_AT_decl_line(0x45)
	.dwattr $C$DW$185, DW_AT_decl_column(0x1d)
$C$DW$186	.dwtag  DW_TAG_member
	.dwattr $C$DW$186, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$186, DW_AT_name("__sysp")
	.dwattr $C$DW$186, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$186, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$186, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$186, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$186, DW_AT_decl_line(0x46)
	.dwattr $C$DW$186, DW_AT_decl_column(0x27)
$C$DW$187	.dwtag  DW_TAG_member
	.dwattr $C$DW$187, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$187, DW_AT_name("get32")
	.dwattr $C$DW$187, DW_AT_TI_symbol_name("get32")
	.dwattr $C$DW$187, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$187, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$187, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$187, DW_AT_decl_line(0x47)
	.dwattr $C$DW$187, DW_AT_decl_column(0x12)
$C$DW$188	.dwtag  DW_TAG_member
	.dwattr $C$DW$188, DW_AT_type(*$C$DW$T$168)
	.dwattr $C$DW$188, DW_AT_name("get64")
	.dwattr $C$DW$188, DW_AT_TI_symbol_name("get64")
	.dwattr $C$DW$188, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$188, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$188, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$188, DW_AT_decl_line(0x48)
	.dwattr $C$DW$188, DW_AT_decl_column(0x10)
$C$DW$189	.dwtag  DW_TAG_member
	.dwattr $C$DW$189, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$189, DW_AT_name("getFreq")
	.dwattr $C$DW$189, DW_AT_TI_symbol_name("getFreq")
	.dwattr $C$DW$189, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$189, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$189, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$189, DW_AT_decl_line(0x49)
	.dwattr $C$DW$189, DW_AT_decl_column(0x10)
$C$DW$190	.dwtag  DW_TAG_member
	.dwattr $C$DW$190, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$190, DW_AT_name("__sfxns")
	.dwattr $C$DW$190, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$190, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$190, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$190, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$190, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$190, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$174

	.dwattr $C$DW$T$174, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/ITimestampProvider.h")
	.dwattr $C$DW$T$174, DW_AT_decl_line(0x44)
	.dwattr $C$DW$T$174, DW_AT_decl_column(0x08)
$C$DW$T$648	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampProvider_Fxns__")
	.dwattr $C$DW$T$648, DW_AT_type(*$C$DW$T$174)
	.dwattr $C$DW$T$648, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$648, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$648, DW_AT_decl_line(0xfb)
	.dwattr $C$DW$T$648, DW_AT_decl_column(0x36)
$C$DW$T$649	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$649, DW_AT_type(*$C$DW$T$648)
$C$DW$T$650	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$650, DW_AT_type(*$C$DW$T$649)
	.dwattr $C$DW$T$650, DW_AT_address_class(0x20)
$C$DW$T$651	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_ITimestampProvider_Module")
	.dwattr $C$DW$T$651, DW_AT_type(*$C$DW$T$650)
	.dwattr $C$DW$T$651, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$651, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$651, DW_AT_decl_line(0xfc)
	.dwattr $C$DW$T$651, DW_AT_decl_column(0x36)

$C$DW$T$43	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$43, DW_AT_name("xdc_runtime_Log_EventRec")
	.dwattr $C$DW$T$43, DW_AT_declaration
	.dwendtag $C$DW$T$43

	.dwattr $C$DW$T$43, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$43, DW_AT_decl_line(0x50)
	.dwattr $C$DW$T$43, DW_AT_decl_column(0x10)
$C$DW$T$652	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Log_EventRec")
	.dwattr $C$DW$T$652, DW_AT_type(*$C$DW$T$43)
	.dwattr $C$DW$T$652, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$652, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$652, DW_AT_decl_line(0x50)
	.dwattr $C$DW$T$652, DW_AT_decl_column(0x29)

$C$DW$T$44	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$44, DW_AT_name("xdc_runtime_LoggerBuf_Entry")
	.dwattr $C$DW$T$44, DW_AT_declaration
	.dwendtag $C$DW$T$44

	.dwattr $C$DW$T$44, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$44, DW_AT_decl_line(0x68)
	.dwattr $C$DW$T$44, DW_AT_decl_column(0x10)
$C$DW$T$653	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Entry")
	.dwattr $C$DW$T$653, DW_AT_type(*$C$DW$T$44)
	.dwattr $C$DW$T$653, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$653, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$653, DW_AT_decl_line(0x68)
	.dwattr $C$DW$T$653, DW_AT_decl_column(0x2c)

$C$DW$T$45	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$45, DW_AT_name("xdc_runtime_LoggerBuf_Fxns__")
	.dwattr $C$DW$T$45, DW_AT_declaration
	.dwendtag $C$DW$T$45

	.dwattr $C$DW$T$45, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$45, DW_AT_decl_line(0x6a)
	.dwattr $C$DW$T$45, DW_AT_decl_column(0x10)
$C$DW$T$654	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Fxns__")
	.dwattr $C$DW$T$654, DW_AT_type(*$C$DW$T$45)
	.dwattr $C$DW$T$654, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$654, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$654, DW_AT_decl_line(0x6a)
	.dwattr $C$DW$T$654, DW_AT_decl_column(0x2d)
$C$DW$T$655	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$655, DW_AT_type(*$C$DW$T$654)
$C$DW$T$656	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$656, DW_AT_type(*$C$DW$T$655)
	.dwattr $C$DW$T$656, DW_AT_address_class(0x20)
$C$DW$T$657	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Module")
	.dwattr $C$DW$T$657, DW_AT_type(*$C$DW$T$656)
	.dwattr $C$DW$T$657, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$657, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$657, DW_AT_decl_line(0x6b)
	.dwattr $C$DW$T$657, DW_AT_decl_column(0x2d)

$C$DW$T$46	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$46, DW_AT_name("xdc_runtime_LoggerBuf_Module_GateProxy_Fxns__")
	.dwattr $C$DW$T$46, DW_AT_declaration
	.dwendtag $C$DW$T$46

	.dwattr $C$DW$T$46, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$46, DW_AT_decl_line(0x133)
	.dwattr $C$DW$T$46, DW_AT_decl_column(0x10)
$C$DW$T$658	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Module_GateProxy_Fxns__")
	.dwattr $C$DW$T$658, DW_AT_type(*$C$DW$T$46)
	.dwattr $C$DW$T$658, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$658, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$658, DW_AT_decl_line(0x133)
	.dwattr $C$DW$T$658, DW_AT_decl_column(0x3e)
$C$DW$T$659	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$659, DW_AT_type(*$C$DW$T$658)
$C$DW$T$660	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$660, DW_AT_type(*$C$DW$T$659)
	.dwattr $C$DW$T$660, DW_AT_address_class(0x20)
$C$DW$T$661	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Module_GateProxy_Module")
	.dwattr $C$DW$T$661, DW_AT_type(*$C$DW$T$660)
	.dwattr $C$DW$T$661, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$661, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$661, DW_AT_decl_line(0x134)
	.dwattr $C$DW$T$661, DW_AT_decl_column(0x3e)

$C$DW$T$47	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$47, DW_AT_name("xdc_runtime_LoggerBuf_Module_GateProxy_Params")
	.dwattr $C$DW$T$47, DW_AT_declaration
	.dwendtag $C$DW$T$47

	.dwattr $C$DW$T$47, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$47, DW_AT_decl_line(0x135)
	.dwattr $C$DW$T$47, DW_AT_decl_column(0x10)
$C$DW$T$662	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Module_GateProxy_Params")
	.dwattr $C$DW$T$662, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$662, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$662, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$662, DW_AT_decl_line(0x135)
	.dwattr $C$DW$T$662, DW_AT_decl_column(0x3e)

$C$DW$T$48	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$48, DW_AT_name("xdc_runtime_LoggerBuf_Module_State")
	.dwattr $C$DW$T$48, DW_AT_declaration
	.dwendtag $C$DW$T$48

	.dwattr $C$DW$T$48, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$48, DW_AT_decl_line(0x69)
	.dwattr $C$DW$T$48, DW_AT_decl_column(0x10)
$C$DW$T$663	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Module_State")
	.dwattr $C$DW$T$663, DW_AT_type(*$C$DW$T$48)
	.dwattr $C$DW$T$663, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$663, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$663, DW_AT_decl_line(0x69)
	.dwattr $C$DW$T$663, DW_AT_decl_column(0x33)

$C$DW$T$49	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$49, DW_AT_name("xdc_runtime_LoggerBuf_Object")
	.dwattr $C$DW$T$49, DW_AT_declaration
	.dwendtag $C$DW$T$49

	.dwattr $C$DW$T$49, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$49, DW_AT_decl_line(0x6d)
	.dwattr $C$DW$T$49, DW_AT_decl_column(0x10)
$C$DW$T$664	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Object")
	.dwattr $C$DW$T$664, DW_AT_type(*$C$DW$T$49)
	.dwattr $C$DW$T$664, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$664, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$664, DW_AT_decl_line(0x6d)
	.dwattr $C$DW$T$664, DW_AT_decl_column(0x2d)
$C$DW$T$665	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$665, DW_AT_type(*$C$DW$T$664)
	.dwattr $C$DW$T$665, DW_AT_address_class(0x20)
$C$DW$T$666	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Handle")
	.dwattr $C$DW$T$666, DW_AT_type(*$C$DW$T$665)
	.dwattr $C$DW$T$666, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$666, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$666, DW_AT_decl_line(0x6f)
	.dwattr $C$DW$T$666, DW_AT_decl_column(0x27)
$C$DW$T$667	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Instance")
	.dwattr $C$DW$T$667, DW_AT_type(*$C$DW$T$665)
	.dwattr $C$DW$T$667, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$667, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$667, DW_AT_decl_line(0x71)
	.dwattr $C$DW$T$667, DW_AT_decl_column(0x27)

$C$DW$T$50	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$50, DW_AT_name("xdc_runtime_LoggerBuf_Object__")
	.dwattr $C$DW$T$50, DW_AT_declaration
	.dwendtag $C$DW$T$50

	.dwattr $C$DW$T$50, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$50, DW_AT_decl_line(0x70)
	.dwattr $C$DW$T$50, DW_AT_decl_column(0x10)
$C$DW$T$668	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Instance_State")
	.dwattr $C$DW$T$668, DW_AT_type(*$C$DW$T$50)
	.dwattr $C$DW$T$668, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$668, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$668, DW_AT_decl_line(0x70)
	.dwattr $C$DW$T$668, DW_AT_decl_column(0x2f)

$C$DW$T$51	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$51, DW_AT_name("xdc_runtime_LoggerBuf_Params")
	.dwattr $C$DW$T$51, DW_AT_declaration
	.dwendtag $C$DW$T$51

	.dwattr $C$DW$T$51, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$51, DW_AT_decl_line(0x6c)
	.dwattr $C$DW$T$51, DW_AT_decl_column(0x10)
$C$DW$T$669	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Params")
	.dwattr $C$DW$T$669, DW_AT_type(*$C$DW$T$51)
	.dwattr $C$DW$T$669, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$669, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$669, DW_AT_decl_line(0x6c)
	.dwattr $C$DW$T$669, DW_AT_decl_column(0x2d)

$C$DW$T$52	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$52, DW_AT_name("xdc_runtime_LoggerBuf_Struct")
	.dwattr $C$DW$T$52, DW_AT_declaration
	.dwendtag $C$DW$T$52

	.dwattr $C$DW$T$52, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$52, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$T$52, DW_AT_decl_column(0x10)
$C$DW$T$670	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_Struct")
	.dwattr $C$DW$T$670, DW_AT_type(*$C$DW$T$52)
	.dwattr $C$DW$T$670, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$670, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$670, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$T$670, DW_AT_decl_column(0x2d)

$C$DW$T$53	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$53, DW_AT_name("xdc_runtime_LoggerBuf_TimestampProxy_Fxns__")
	.dwattr $C$DW$T$53, DW_AT_declaration
	.dwendtag $C$DW$T$53

	.dwattr $C$DW$T$53, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$53, DW_AT_decl_line(0x12c)
	.dwattr $C$DW$T$53, DW_AT_decl_column(0x10)
$C$DW$T$671	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_TimestampProxy_Fxns__")
	.dwattr $C$DW$T$671, DW_AT_type(*$C$DW$T$53)
	.dwattr $C$DW$T$671, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$671, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$671, DW_AT_decl_line(0x12c)
	.dwattr $C$DW$T$671, DW_AT_decl_column(0x3c)
$C$DW$T$672	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$672, DW_AT_type(*$C$DW$T$671)
$C$DW$T$673	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$673, DW_AT_type(*$C$DW$T$672)
	.dwattr $C$DW$T$673, DW_AT_address_class(0x20)
$C$DW$T$674	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerBuf_TimestampProxy_Module")
	.dwattr $C$DW$T$674, DW_AT_type(*$C$DW$T$673)
	.dwattr $C$DW$T$674, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$674, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$674, DW_AT_decl_line(0x12d)
	.dwattr $C$DW$T$674, DW_AT_decl_column(0x3c)

$C$DW$T$54	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$54, DW_AT_name("xdc_runtime_LoggerSys_Fxns__")
	.dwattr $C$DW$T$54, DW_AT_declaration
	.dwendtag $C$DW$T$54

	.dwattr $C$DW$T$54, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$54, DW_AT_decl_line(0x77)
	.dwattr $C$DW$T$54, DW_AT_decl_column(0x10)
$C$DW$T$675	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_Fxns__")
	.dwattr $C$DW$T$675, DW_AT_type(*$C$DW$T$54)
	.dwattr $C$DW$T$675, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$675, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$675, DW_AT_decl_line(0x77)
	.dwattr $C$DW$T$675, DW_AT_decl_column(0x2d)
$C$DW$T$676	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$676, DW_AT_type(*$C$DW$T$675)
$C$DW$T$677	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$677, DW_AT_type(*$C$DW$T$676)
	.dwattr $C$DW$T$677, DW_AT_address_class(0x20)
$C$DW$T$678	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_Module")
	.dwattr $C$DW$T$678, DW_AT_type(*$C$DW$T$677)
	.dwattr $C$DW$T$678, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$678, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$678, DW_AT_decl_line(0x78)
	.dwattr $C$DW$T$678, DW_AT_decl_column(0x2d)

$C$DW$T$55	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$55, DW_AT_name("xdc_runtime_LoggerSys_Object")
	.dwattr $C$DW$T$55, DW_AT_declaration
	.dwendtag $C$DW$T$55

	.dwattr $C$DW$T$55, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$55, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$T$55, DW_AT_decl_column(0x10)
$C$DW$T$679	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_Object")
	.dwattr $C$DW$T$679, DW_AT_type(*$C$DW$T$55)
	.dwattr $C$DW$T$679, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$679, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$679, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$T$679, DW_AT_decl_column(0x2d)
$C$DW$T$680	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$680, DW_AT_type(*$C$DW$T$679)
	.dwattr $C$DW$T$680, DW_AT_address_class(0x20)
$C$DW$T$681	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_Handle")
	.dwattr $C$DW$T$681, DW_AT_type(*$C$DW$T$680)
	.dwattr $C$DW$T$681, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$681, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$681, DW_AT_decl_line(0x7c)
	.dwattr $C$DW$T$681, DW_AT_decl_column(0x27)
$C$DW$T$682	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_Instance")
	.dwattr $C$DW$T$682, DW_AT_type(*$C$DW$T$680)
	.dwattr $C$DW$T$682, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$682, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$682, DW_AT_decl_line(0x7e)
	.dwattr $C$DW$T$682, DW_AT_decl_column(0x27)

$C$DW$T$56	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$56, DW_AT_name("xdc_runtime_LoggerSys_Object__")
	.dwattr $C$DW$T$56, DW_AT_declaration
	.dwendtag $C$DW$T$56

	.dwattr $C$DW$T$56, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$56, DW_AT_decl_line(0x7d)
	.dwattr $C$DW$T$56, DW_AT_decl_column(0x10)
$C$DW$T$683	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_Instance_State")
	.dwattr $C$DW$T$683, DW_AT_type(*$C$DW$T$56)
	.dwattr $C$DW$T$683, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$683, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$683, DW_AT_decl_line(0x7d)
	.dwattr $C$DW$T$683, DW_AT_decl_column(0x2f)

$C$DW$T$57	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$57, DW_AT_name("xdc_runtime_LoggerSys_Params")
	.dwattr $C$DW$T$57, DW_AT_declaration
	.dwendtag $C$DW$T$57

	.dwattr $C$DW$T$57, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$57, DW_AT_decl_line(0x79)
	.dwattr $C$DW$T$57, DW_AT_decl_column(0x10)
$C$DW$T$684	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_Params")
	.dwattr $C$DW$T$684, DW_AT_type(*$C$DW$T$57)
	.dwattr $C$DW$T$684, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$684, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$684, DW_AT_decl_line(0x79)
	.dwattr $C$DW$T$684, DW_AT_decl_column(0x2d)

$C$DW$T$58	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$58, DW_AT_name("xdc_runtime_LoggerSys_Struct")
	.dwattr $C$DW$T$58, DW_AT_declaration
	.dwendtag $C$DW$T$58

	.dwattr $C$DW$T$58, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$58, DW_AT_decl_line(0x7b)
	.dwattr $C$DW$T$58, DW_AT_decl_column(0x10)
$C$DW$T$685	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_Struct")
	.dwattr $C$DW$T$685, DW_AT_type(*$C$DW$T$58)
	.dwattr $C$DW$T$685, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$685, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$685, DW_AT_decl_line(0x7b)
	.dwattr $C$DW$T$685, DW_AT_decl_column(0x2d)

$C$DW$T$59	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$59, DW_AT_name("xdc_runtime_LoggerSys_TimestampProxy_Fxns__")
	.dwattr $C$DW$T$59, DW_AT_declaration
	.dwendtag $C$DW$T$59

	.dwattr $C$DW$T$59, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$59, DW_AT_decl_line(0x13c)
	.dwattr $C$DW$T$59, DW_AT_decl_column(0x10)
$C$DW$T$686	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_TimestampProxy_Fxns__")
	.dwattr $C$DW$T$686, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$T$686, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$686, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$686, DW_AT_decl_line(0x13c)
	.dwattr $C$DW$T$686, DW_AT_decl_column(0x3c)
$C$DW$T$687	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$687, DW_AT_type(*$C$DW$T$686)
$C$DW$T$688	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$688, DW_AT_type(*$C$DW$T$687)
	.dwattr $C$DW$T$688, DW_AT_address_class(0x20)
$C$DW$T$689	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_LoggerSys_TimestampProxy_Module")
	.dwattr $C$DW$T$689, DW_AT_type(*$C$DW$T$688)
	.dwattr $C$DW$T$689, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$689, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$689, DW_AT_decl_line(0x13d)
	.dwattr $C$DW$T$689, DW_AT_decl_column(0x3c)

$C$DW$T$181	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$181, DW_AT_name("xdc_runtime_Main_Module_GateProxy_Fxns__")
	.dwattr $C$DW$T$181, DW_AT_byte_size(0x24)
$C$DW$191	.dwtag  DW_TAG_member
	.dwattr $C$DW$191, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$191, DW_AT_name("__base")
	.dwattr $C$DW$191, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$191, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$191, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$191, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$191, DW_AT_decl_line(0xb0)
	.dwattr $C$DW$191, DW_AT_decl_column(0x1d)
$C$DW$192	.dwtag  DW_TAG_member
	.dwattr $C$DW$192, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$192, DW_AT_name("__sysp")
	.dwattr $C$DW$192, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$192, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$192, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$192, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$192, DW_AT_decl_line(0xb1)
	.dwattr $C$DW$192, DW_AT_decl_column(0x27)
$C$DW$193	.dwtag  DW_TAG_member
	.dwattr $C$DW$193, DW_AT_type(*$C$DW$T$120)
	.dwattr $C$DW$193, DW_AT_name("query")
	.dwattr $C$DW$193, DW_AT_TI_symbol_name("query")
	.dwattr $C$DW$193, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$193, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$193, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$193, DW_AT_decl_line(0xb2)
	.dwattr $C$DW$193, DW_AT_decl_column(0x10)
$C$DW$194	.dwtag  DW_TAG_member
	.dwattr $C$DW$194, DW_AT_type(*$C$DW$T$178)
	.dwattr $C$DW$194, DW_AT_name("enter")
	.dwattr $C$DW$194, DW_AT_TI_symbol_name("enter")
	.dwattr $C$DW$194, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$194, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$194, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$194, DW_AT_decl_line(0xb3)
	.dwattr $C$DW$194, DW_AT_decl_column(0x10)
$C$DW$195	.dwtag  DW_TAG_member
	.dwattr $C$DW$195, DW_AT_type(*$C$DW$T$180)
	.dwattr $C$DW$195, DW_AT_name("leave")
	.dwattr $C$DW$195, DW_AT_TI_symbol_name("leave")
	.dwattr $C$DW$195, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$195, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$195, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$195, DW_AT_decl_line(0xb4)
	.dwattr $C$DW$195, DW_AT_decl_column(0x10)
$C$DW$196	.dwtag  DW_TAG_member
	.dwattr $C$DW$196, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$196, DW_AT_name("__sfxns")
	.dwattr $C$DW$196, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$196, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$196, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$196, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$196, DW_AT_decl_line(0xb5)
	.dwattr $C$DW$196, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$181

	.dwattr $C$DW$T$181, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$181, DW_AT_decl_line(0xaf)
	.dwattr $C$DW$T$181, DW_AT_decl_column(0x08)
$C$DW$T$183	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Main_Module_GateProxy_Fxns__")
	.dwattr $C$DW$T$183, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$T$183, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$183, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$183, DW_AT_decl_line(0x143)
	.dwattr $C$DW$T$183, DW_AT_decl_column(0x39)
$C$DW$T$184	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$184, DW_AT_type(*$C$DW$T$183)
$C$DW$T$185	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$185, DW_AT_type(*$C$DW$T$184)
	.dwattr $C$DW$T$185, DW_AT_address_class(0x20)
$C$DW$T$690	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Main_Module_GateProxy_Module")
	.dwattr $C$DW$T$690, DW_AT_type(*$C$DW$T$185)
	.dwattr $C$DW$T$690, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$690, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$690, DW_AT_decl_line(0x144)
	.dwattr $C$DW$T$690, DW_AT_decl_column(0x39)

$C$DW$T$182	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$182, DW_AT_name("xdc_runtime_Main_Module_GateProxy_Params")
	.dwattr $C$DW$T$182, DW_AT_byte_size(0x18)
$C$DW$197	.dwtag  DW_TAG_member
	.dwattr $C$DW$197, DW_AT_type(*$C$DW$T$126)
	.dwattr $C$DW$197, DW_AT_name("__size")
	.dwattr $C$DW$197, DW_AT_TI_symbol_name("__size")
	.dwattr $C$DW$197, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$197, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$197, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$197, DW_AT_decl_line(0x9c)
	.dwattr $C$DW$197, DW_AT_decl_column(0x0c)
$C$DW$198	.dwtag  DW_TAG_member
	.dwattr $C$DW$198, DW_AT_type(*$C$DW$T$128)
	.dwattr $C$DW$198, DW_AT_name("__self")
	.dwattr $C$DW$198, DW_AT_TI_symbol_name("__self")
	.dwattr $C$DW$198, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$198, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$198, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$198, DW_AT_decl_line(0x9d)
	.dwattr $C$DW$198, DW_AT_decl_column(0x11)
$C$DW$199	.dwtag  DW_TAG_member
	.dwattr $C$DW$199, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$199, DW_AT_name("__fxns")
	.dwattr $C$DW$199, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$199, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$199, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$199, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$199, DW_AT_decl_line(0x9e)
	.dwattr $C$DW$199, DW_AT_decl_column(0x0b)
$C$DW$200	.dwtag  DW_TAG_member
	.dwattr $C$DW$200, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$200, DW_AT_name("instance")
	.dwattr $C$DW$200, DW_AT_TI_symbol_name("instance")
	.dwattr $C$DW$200, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$200, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$200, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$200, DW_AT_decl_line(0x9f)
	.dwattr $C$DW$200, DW_AT_decl_column(0x23)
$C$DW$201	.dwtag  DW_TAG_member
	.dwattr $C$DW$201, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$201, DW_AT_name("__iprms")
	.dwattr $C$DW$201, DW_AT_TI_symbol_name("__iprms")
	.dwattr $C$DW$201, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$201, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$201, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$201, DW_AT_decl_line(0xa0)
	.dwattr $C$DW$201, DW_AT_decl_column(0x22)
	.dwendtag $C$DW$T$182

	.dwattr $C$DW$T$182, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$182, DW_AT_decl_line(0x9b)
	.dwattr $C$DW$T$182, DW_AT_decl_column(0x08)
$C$DW$T$691	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Main_Module_GateProxy_Params")
	.dwattr $C$DW$T$691, DW_AT_type(*$C$DW$T$182)
	.dwattr $C$DW$T$691, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$691, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$691, DW_AT_decl_line(0x145)
	.dwattr $C$DW$T$691, DW_AT_decl_column(0x39)

$C$DW$T$189	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$189, DW_AT_name("xdc_runtime_Main_Module_GateProxy_Struct")
	.dwattr $C$DW$T$189, DW_AT_byte_size(0x08)
$C$DW$202	.dwtag  DW_TAG_member
	.dwattr $C$DW$202, DW_AT_type(*$C$DW$T$185)
	.dwattr $C$DW$202, DW_AT_name("__fxns")
	.dwattr $C$DW$202, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$202, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$202, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$202, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$202, DW_AT_decl_line(0xa5)
	.dwattr $C$DW$202, DW_AT_decl_column(0x35)
$C$DW$203	.dwtag  DW_TAG_member
	.dwattr $C$DW$203, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$203, DW_AT_name("__name")
	.dwattr $C$DW$203, DW_AT_TI_symbol_name("__name")
	.dwattr $C$DW$203, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$203, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$203, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$203, DW_AT_decl_line(0xa6)
	.dwattr $C$DW$203, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$189

	.dwattr $C$DW$T$189, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Main_Module_GateProxy.h")
	.dwattr $C$DW$T$189, DW_AT_decl_line(0xa4)
	.dwattr $C$DW$T$189, DW_AT_decl_column(0x08)

$C$DW$T$200	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$200, DW_AT_name("xdc_runtime_Memory_HeapProxy_Fxns__")
	.dwattr $C$DW$T$200, DW_AT_byte_size(0x28)
$C$DW$204	.dwtag  DW_TAG_member
	.dwattr $C$DW$204, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$204, DW_AT_name("__base")
	.dwattr $C$DW$204, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$204, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$204, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$204, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$204, DW_AT_decl_line(0xaa)
	.dwattr $C$DW$204, DW_AT_decl_column(0x1d)
$C$DW$205	.dwtag  DW_TAG_member
	.dwattr $C$DW$205, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$205, DW_AT_name("__sysp")
	.dwattr $C$DW$205, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$205, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$205, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$205, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$205, DW_AT_decl_line(0xab)
	.dwattr $C$DW$205, DW_AT_decl_column(0x27)
$C$DW$206	.dwtag  DW_TAG_member
	.dwattr $C$DW$206, DW_AT_type(*$C$DW$T$193)
	.dwattr $C$DW$206, DW_AT_name("alloc")
	.dwattr $C$DW$206, DW_AT_TI_symbol_name("alloc")
	.dwattr $C$DW$206, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$206, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$206, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$206, DW_AT_decl_line(0xac)
	.dwattr $C$DW$206, DW_AT_decl_column(0x0f)
$C$DW$207	.dwtag  DW_TAG_member
	.dwattr $C$DW$207, DW_AT_type(*$C$DW$T$195)
	.dwattr $C$DW$207, DW_AT_name("free")
	.dwattr $C$DW$207, DW_AT_TI_symbol_name("free")
	.dwattr $C$DW$207, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$207, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$207, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$207, DW_AT_decl_line(0xad)
	.dwattr $C$DW$207, DW_AT_decl_column(0x10)
$C$DW$208	.dwtag  DW_TAG_member
	.dwattr $C$DW$208, DW_AT_type(*$C$DW$T$197)
	.dwattr $C$DW$208, DW_AT_name("isBlocking")
	.dwattr $C$DW$208, DW_AT_TI_symbol_name("isBlocking")
	.dwattr $C$DW$208, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$208, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$208, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$208, DW_AT_decl_line(0xae)
	.dwattr $C$DW$208, DW_AT_decl_column(0x10)
$C$DW$209	.dwtag  DW_TAG_member
	.dwattr $C$DW$209, DW_AT_type(*$C$DW$T$199)
	.dwattr $C$DW$209, DW_AT_name("getStats")
	.dwattr $C$DW$209, DW_AT_TI_symbol_name("getStats")
	.dwattr $C$DW$209, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$209, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$209, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$209, DW_AT_decl_line(0xaf)
	.dwattr $C$DW$209, DW_AT_decl_column(0x10)
$C$DW$210	.dwtag  DW_TAG_member
	.dwattr $C$DW$210, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$210, DW_AT_name("__sfxns")
	.dwattr $C$DW$210, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$210, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$210, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$210, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$210, DW_AT_decl_line(0xb0)
	.dwattr $C$DW$210, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$200

	.dwattr $C$DW$T$200, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$200, DW_AT_decl_line(0xa9)
	.dwattr $C$DW$T$200, DW_AT_decl_column(0x08)
$C$DW$T$202	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_HeapProxy_Fxns__")
	.dwattr $C$DW$T$202, DW_AT_type(*$C$DW$T$200)
	.dwattr $C$DW$T$202, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$202, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$202, DW_AT_decl_line(0x14c)
	.dwattr $C$DW$T$202, DW_AT_decl_column(0x34)
$C$DW$T$203	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$203, DW_AT_type(*$C$DW$T$202)
$C$DW$T$204	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$204, DW_AT_type(*$C$DW$T$203)
	.dwattr $C$DW$T$204, DW_AT_address_class(0x20)
$C$DW$T$692	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_HeapProxy_Module")
	.dwattr $C$DW$T$692, DW_AT_type(*$C$DW$T$204)
	.dwattr $C$DW$T$692, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$692, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$692, DW_AT_decl_line(0x14d)
	.dwattr $C$DW$T$692, DW_AT_decl_column(0x34)

$C$DW$T$201	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$201, DW_AT_name("xdc_runtime_Memory_HeapProxy_Params")
	.dwattr $C$DW$T$201, DW_AT_byte_size(0x18)
$C$DW$211	.dwtag  DW_TAG_member
	.dwattr $C$DW$211, DW_AT_type(*$C$DW$T$126)
	.dwattr $C$DW$211, DW_AT_name("__size")
	.dwattr $C$DW$211, DW_AT_TI_symbol_name("__size")
	.dwattr $C$DW$211, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$211, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$211, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$211, DW_AT_decl_line(0x96)
	.dwattr $C$DW$211, DW_AT_decl_column(0x0c)
$C$DW$212	.dwtag  DW_TAG_member
	.dwattr $C$DW$212, DW_AT_type(*$C$DW$T$128)
	.dwattr $C$DW$212, DW_AT_name("__self")
	.dwattr $C$DW$212, DW_AT_TI_symbol_name("__self")
	.dwattr $C$DW$212, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$212, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$212, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$212, DW_AT_decl_line(0x97)
	.dwattr $C$DW$212, DW_AT_decl_column(0x11)
$C$DW$213	.dwtag  DW_TAG_member
	.dwattr $C$DW$213, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$213, DW_AT_name("__fxns")
	.dwattr $C$DW$213, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$213, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$213, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$213, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$213, DW_AT_decl_line(0x98)
	.dwattr $C$DW$213, DW_AT_decl_column(0x0b)
$C$DW$214	.dwtag  DW_TAG_member
	.dwattr $C$DW$214, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$214, DW_AT_name("instance")
	.dwattr $C$DW$214, DW_AT_TI_symbol_name("instance")
	.dwattr $C$DW$214, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$214, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$214, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$214, DW_AT_decl_line(0x99)
	.dwattr $C$DW$214, DW_AT_decl_column(0x23)
$C$DW$215	.dwtag  DW_TAG_member
	.dwattr $C$DW$215, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$215, DW_AT_name("__iprms")
	.dwattr $C$DW$215, DW_AT_TI_symbol_name("__iprms")
	.dwattr $C$DW$215, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$215, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$215, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$215, DW_AT_decl_line(0x9a)
	.dwattr $C$DW$215, DW_AT_decl_column(0x22)
	.dwendtag $C$DW$T$201

	.dwattr $C$DW$T$201, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$201, DW_AT_decl_line(0x95)
	.dwattr $C$DW$T$201, DW_AT_decl_column(0x08)
$C$DW$T$693	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_HeapProxy_Params")
	.dwattr $C$DW$T$693, DW_AT_type(*$C$DW$T$201)
	.dwattr $C$DW$T$693, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$693, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$693, DW_AT_decl_line(0x14e)
	.dwattr $C$DW$T$693, DW_AT_decl_column(0x34)

$C$DW$T$205	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$205, DW_AT_name("xdc_runtime_Memory_HeapProxy_Struct")
	.dwattr $C$DW$T$205, DW_AT_byte_size(0x08)
$C$DW$216	.dwtag  DW_TAG_member
	.dwattr $C$DW$216, DW_AT_type(*$C$DW$T$204)
	.dwattr $C$DW$216, DW_AT_name("__fxns")
	.dwattr $C$DW$216, DW_AT_TI_symbol_name("__fxns")
	.dwattr $C$DW$216, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$216, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$216, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$216, DW_AT_decl_line(0x9f)
	.dwattr $C$DW$216, DW_AT_decl_column(0x30)
$C$DW$217	.dwtag  DW_TAG_member
	.dwattr $C$DW$217, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$217, DW_AT_name("__name")
	.dwattr $C$DW$217, DW_AT_TI_symbol_name("__name")
	.dwattr $C$DW$217, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$217, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$217, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$217, DW_AT_decl_line(0xa0)
	.dwattr $C$DW$217, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$205

	.dwattr $C$DW$T$205, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Memory_HeapProxy.h")
	.dwattr $C$DW$T$205, DW_AT_decl_line(0x9e)
	.dwattr $C$DW$T$205, DW_AT_decl_column(0x08)

$C$DW$T$60	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$60, DW_AT_name("xdc_runtime_Memory_Module_State")
	.dwattr $C$DW$T$60, DW_AT_declaration
	.dwendtag $C$DW$T$60

	.dwattr $C$DW$T$60, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$60, DW_AT_decl_line(0x8a)
	.dwattr $C$DW$T$60, DW_AT_decl_column(0x10)
$C$DW$T$694	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_Module_State")
	.dwattr $C$DW$T$694, DW_AT_type(*$C$DW$T$60)
	.dwattr $C$DW$T$694, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$694, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$694, DW_AT_decl_line(0x8a)
	.dwattr $C$DW$T$694, DW_AT_decl_column(0x30)

$C$DW$T$209	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$209, DW_AT_name("xdc_runtime_Memory_Stats")
	.dwattr $C$DW$T$209, DW_AT_byte_size(0x0c)
$C$DW$218	.dwtag  DW_TAG_member
	.dwattr $C$DW$218, DW_AT_type(*$C$DW$T$208)
	.dwattr $C$DW$218, DW_AT_name("totalSize")
	.dwattr $C$DW$218, DW_AT_TI_symbol_name("totalSize")
	.dwattr $C$DW$218, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$218, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$218, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$218, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$218, DW_AT_decl_column(0x1d)
$C$DW$219	.dwtag  DW_TAG_member
	.dwattr $C$DW$219, DW_AT_type(*$C$DW$T$208)
	.dwattr $C$DW$219, DW_AT_name("totalFreeSize")
	.dwattr $C$DW$219, DW_AT_TI_symbol_name("totalFreeSize")
	.dwattr $C$DW$219, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$219, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$219, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$219, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$219, DW_AT_decl_column(0x1d)
$C$DW$220	.dwtag  DW_TAG_member
	.dwattr $C$DW$220, DW_AT_type(*$C$DW$T$208)
	.dwattr $C$DW$220, DW_AT_name("largestFreeSize")
	.dwattr $C$DW$220, DW_AT_TI_symbol_name("largestFreeSize")
	.dwattr $C$DW$220, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$220, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$220, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$220, DW_AT_decl_line(0x4c)
	.dwattr $C$DW$220, DW_AT_decl_column(0x1d)
	.dwendtag $C$DW$T$209

	.dwattr $C$DW$T$209, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Memory.h")
	.dwattr $C$DW$T$209, DW_AT_decl_line(0x49)
	.dwattr $C$DW$T$209, DW_AT_decl_column(0x08)
$C$DW$T$145	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Memory_Stats")
	.dwattr $C$DW$T$145, DW_AT_type(*$C$DW$T$209)
	.dwattr $C$DW$T$145, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$145, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$145, DW_AT_decl_line(0x89)
	.dwattr $C$DW$T$145, DW_AT_decl_column(0x29)
$C$DW$T$146	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$146, DW_AT_type(*$C$DW$T$145)
	.dwattr $C$DW$T$146, DW_AT_address_class(0x20)

$C$DW$T$61	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$61, DW_AT_name("xdc_runtime_Registry_Module_State")
	.dwattr $C$DW$T$61, DW_AT_declaration
	.dwendtag $C$DW$T$61

	.dwattr $C$DW$T$61, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$61, DW_AT_decl_line(0xb4)
	.dwattr $C$DW$T$61, DW_AT_decl_column(0x10)
$C$DW$T$695	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Registry_Module_State")
	.dwattr $C$DW$T$695, DW_AT_type(*$C$DW$T$61)
	.dwattr $C$DW$T$695, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$695, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$695, DW_AT_decl_line(0xb4)
	.dwattr $C$DW$T$695, DW_AT_decl_column(0x32)

$C$DW$T$62	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$62, DW_AT_name("xdc_runtime_Rta_CommandPacket")
	.dwattr $C$DW$T$62, DW_AT_declaration
	.dwendtag $C$DW$T$62

	.dwattr $C$DW$T$62, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$62, DW_AT_decl_line(0xba)
	.dwattr $C$DW$T$62, DW_AT_decl_column(0x10)
$C$DW$T$696	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Rta_CommandPacket")
	.dwattr $C$DW$T$696, DW_AT_type(*$C$DW$T$62)
	.dwattr $C$DW$T$696, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$696, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$696, DW_AT_decl_line(0xba)
	.dwattr $C$DW$T$696, DW_AT_decl_column(0x2e)

$C$DW$T$63	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$63, DW_AT_name("xdc_runtime_Rta_ResponsePacket")
	.dwattr $C$DW$T$63, DW_AT_declaration
	.dwendtag $C$DW$T$63

	.dwattr $C$DW$T$63, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$63, DW_AT_decl_line(0xbb)
	.dwattr $C$DW$T$63, DW_AT_decl_column(0x10)
$C$DW$T$697	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Rta_ResponsePacket")
	.dwattr $C$DW$T$697, DW_AT_type(*$C$DW$T$63)
	.dwattr $C$DW$T$697, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$697, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$697, DW_AT_decl_line(0xbb)
	.dwattr $C$DW$T$697, DW_AT_decl_column(0x2f)

$C$DW$T$64	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$64, DW_AT_name("xdc_runtime_Startup_Module_State")
	.dwattr $C$DW$T$64, DW_AT_declaration
	.dwendtag $C$DW$T$64

	.dwattr $C$DW$T$64, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$64, DW_AT_decl_line(0xc1)
	.dwattr $C$DW$T$64, DW_AT_decl_column(0x10)
$C$DW$T$698	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Startup_Module_State")
	.dwattr $C$DW$T$698, DW_AT_type(*$C$DW$T$64)
	.dwattr $C$DW$T$698, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$698, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$698, DW_AT_decl_line(0xc1)
	.dwattr $C$DW$T$698, DW_AT_decl_column(0x31)

$C$DW$T$65	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$65, DW_AT_name("xdc_runtime_SysMin_Fxns__")
	.dwattr $C$DW$T$65, DW_AT_declaration
	.dwendtag $C$DW$T$65

	.dwattr $C$DW$T$65, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$65, DW_AT_decl_line(0xdd)
	.dwattr $C$DW$T$65, DW_AT_decl_column(0x10)
$C$DW$T$699	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_SysMin_Fxns__")
	.dwattr $C$DW$T$699, DW_AT_type(*$C$DW$T$65)
	.dwattr $C$DW$T$699, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$699, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$699, DW_AT_decl_line(0xdd)
	.dwattr $C$DW$T$699, DW_AT_decl_column(0x2a)
$C$DW$T$700	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$700, DW_AT_type(*$C$DW$T$699)
$C$DW$T$701	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$701, DW_AT_type(*$C$DW$T$700)
	.dwattr $C$DW$T$701, DW_AT_address_class(0x20)
$C$DW$T$702	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_SysMin_Module")
	.dwattr $C$DW$T$702, DW_AT_type(*$C$DW$T$701)
	.dwattr $C$DW$T$702, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$702, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$702, DW_AT_decl_line(0xde)
	.dwattr $C$DW$T$702, DW_AT_decl_column(0x2a)

$C$DW$T$66	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$66, DW_AT_name("xdc_runtime_SysMin_Module_State")
	.dwattr $C$DW$T$66, DW_AT_declaration
	.dwendtag $C$DW$T$66

	.dwattr $C$DW$T$66, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$66, DW_AT_decl_line(0xdc)
	.dwattr $C$DW$T$66, DW_AT_decl_column(0x10)
$C$DW$T$703	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_SysMin_Module_State")
	.dwattr $C$DW$T$703, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$T$703, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$703, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$703, DW_AT_decl_line(0xdc)
	.dwattr $C$DW$T$703, DW_AT_decl_column(0x30)

$C$DW$T$67	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$67, DW_AT_name("xdc_runtime_SysStd_Fxns__")
	.dwattr $C$DW$T$67, DW_AT_declaration
	.dwendtag $C$DW$T$67

	.dwattr $C$DW$T$67, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$67, DW_AT_decl_line(0xd5)
	.dwattr $C$DW$T$67, DW_AT_decl_column(0x10)
$C$DW$T$704	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_SysStd_Fxns__")
	.dwattr $C$DW$T$704, DW_AT_type(*$C$DW$T$67)
	.dwattr $C$DW$T$704, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$704, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$704, DW_AT_decl_line(0xd5)
	.dwattr $C$DW$T$704, DW_AT_decl_column(0x2a)
$C$DW$T$705	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$705, DW_AT_type(*$C$DW$T$704)
$C$DW$T$706	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$706, DW_AT_type(*$C$DW$T$705)
	.dwattr $C$DW$T$706, DW_AT_address_class(0x20)
$C$DW$T$707	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_SysStd_Module")
	.dwattr $C$DW$T$707, DW_AT_type(*$C$DW$T$706)
	.dwattr $C$DW$T$707, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$707, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$707, DW_AT_decl_line(0xd6)
	.dwattr $C$DW$T$707, DW_AT_decl_column(0x2a)

$C$DW$T$68	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$68, DW_AT_name("xdc_runtime_System_Module_GateProxy_Fxns__")
	.dwattr $C$DW$T$68, DW_AT_declaration
	.dwendtag $C$DW$T$68

	.dwattr $C$DW$T$68, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$68, DW_AT_decl_line(0x15c)
	.dwattr $C$DW$T$68, DW_AT_decl_column(0x10)
$C$DW$T$708	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_System_Module_GateProxy_Fxns__")
	.dwattr $C$DW$T$708, DW_AT_type(*$C$DW$T$68)
	.dwattr $C$DW$T$708, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$708, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$708, DW_AT_decl_line(0x15c)
	.dwattr $C$DW$T$708, DW_AT_decl_column(0x3b)
$C$DW$T$709	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$709, DW_AT_type(*$C$DW$T$708)
$C$DW$T$710	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$710, DW_AT_type(*$C$DW$T$709)
	.dwattr $C$DW$T$710, DW_AT_address_class(0x20)
$C$DW$T$711	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_System_Module_GateProxy_Module")
	.dwattr $C$DW$T$711, DW_AT_type(*$C$DW$T$710)
	.dwattr $C$DW$T$711, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$711, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$711, DW_AT_decl_line(0x15d)
	.dwattr $C$DW$T$711, DW_AT_decl_column(0x3b)

$C$DW$T$69	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$69, DW_AT_name("xdc_runtime_System_Module_GateProxy_Params")
	.dwattr $C$DW$T$69, DW_AT_declaration
	.dwendtag $C$DW$T$69

	.dwattr $C$DW$T$69, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$69, DW_AT_decl_line(0x15e)
	.dwattr $C$DW$T$69, DW_AT_decl_column(0x10)
$C$DW$T$712	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_System_Module_GateProxy_Params")
	.dwattr $C$DW$T$712, DW_AT_type(*$C$DW$T$69)
	.dwattr $C$DW$T$712, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$712, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$712, DW_AT_decl_line(0x15e)
	.dwattr $C$DW$T$712, DW_AT_decl_column(0x3b)

$C$DW$T$70	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$70, DW_AT_name("xdc_runtime_System_Module_State")
	.dwattr $C$DW$T$70, DW_AT_declaration
	.dwendtag $C$DW$T$70

	.dwattr $C$DW$T$70, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$70, DW_AT_decl_line(0xc8)
	.dwattr $C$DW$T$70, DW_AT_decl_column(0x10)
$C$DW$T$713	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_System_Module_State")
	.dwattr $C$DW$T$713, DW_AT_type(*$C$DW$T$70)
	.dwattr $C$DW$T$713, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$713, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$713, DW_AT_decl_line(0xc8)
	.dwattr $C$DW$T$713, DW_AT_decl_column(0x30)

$C$DW$T$71	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$71, DW_AT_name("xdc_runtime_System_ParseData")
	.dwattr $C$DW$T$71, DW_AT_declaration
	.dwendtag $C$DW$T$71

	.dwattr $C$DW$T$71, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$71, DW_AT_decl_line(0xc7)
	.dwattr $C$DW$T$71, DW_AT_decl_column(0x10)
$C$DW$T$714	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_System_ParseData")
	.dwattr $C$DW$T$714, DW_AT_type(*$C$DW$T$71)
	.dwattr $C$DW$T$714, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$714, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$714, DW_AT_decl_line(0xc7)
	.dwattr $C$DW$T$714, DW_AT_decl_column(0x2d)

$C$DW$T$72	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$72, DW_AT_name("xdc_runtime_System_SupportProxy_Fxns__")
	.dwattr $C$DW$T$72, DW_AT_declaration
	.dwendtag $C$DW$T$72

	.dwattr $C$DW$T$72, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$72, DW_AT_decl_line(0x155)
	.dwattr $C$DW$T$72, DW_AT_decl_column(0x10)
$C$DW$T$715	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_System_SupportProxy_Fxns__")
	.dwattr $C$DW$T$715, DW_AT_type(*$C$DW$T$72)
	.dwattr $C$DW$T$715, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$715, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$715, DW_AT_decl_line(0x155)
	.dwattr $C$DW$T$715, DW_AT_decl_column(0x37)
$C$DW$T$716	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$716, DW_AT_type(*$C$DW$T$715)
$C$DW$T$717	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$717, DW_AT_type(*$C$DW$T$716)
	.dwattr $C$DW$T$717, DW_AT_address_class(0x20)
$C$DW$T$718	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_System_SupportProxy_Module")
	.dwattr $C$DW$T$718, DW_AT_type(*$C$DW$T$717)
	.dwattr $C$DW$T$718, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$718, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$718, DW_AT_decl_line(0x156)
	.dwattr $C$DW$T$718, DW_AT_decl_column(0x37)

$C$DW$T$73	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$73, DW_AT_name("xdc_runtime_Text_MatchVisState")
	.dwattr $C$DW$T$73, DW_AT_declaration
	.dwendtag $C$DW$T$73

	.dwattr $C$DW$T$73, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$73, DW_AT_decl_line(0xe5)
	.dwattr $C$DW$T$73, DW_AT_decl_column(0x10)
$C$DW$T$719	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Text_MatchVisState")
	.dwattr $C$DW$T$719, DW_AT_type(*$C$DW$T$73)
	.dwattr $C$DW$T$719, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$719, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$719, DW_AT_decl_line(0xe5)
	.dwattr $C$DW$T$719, DW_AT_decl_column(0x2f)

$C$DW$T$74	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$74, DW_AT_name("xdc_runtime_Text_Module_State")
	.dwattr $C$DW$T$74, DW_AT_declaration
	.dwendtag $C$DW$T$74

	.dwattr $C$DW$T$74, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$74, DW_AT_decl_line(0xe7)
	.dwattr $C$DW$T$74, DW_AT_decl_column(0x10)
$C$DW$T$720	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Text_Module_State")
	.dwattr $C$DW$T$720, DW_AT_type(*$C$DW$T$74)
	.dwattr $C$DW$T$720, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$720, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$720, DW_AT_decl_line(0xe7)
	.dwattr $C$DW$T$720, DW_AT_decl_column(0x2e)

$C$DW$T$75	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$75, DW_AT_name("xdc_runtime_Text_Node")
	.dwattr $C$DW$T$75, DW_AT_declaration
	.dwendtag $C$DW$T$75

	.dwattr $C$DW$T$75, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$75, DW_AT_decl_line(0xe4)
	.dwattr $C$DW$T$75, DW_AT_decl_column(0x10)
$C$DW$T$721	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Text_Node")
	.dwattr $C$DW$T$721, DW_AT_type(*$C$DW$T$75)
	.dwattr $C$DW$T$721, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$721, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$721, DW_AT_decl_line(0xe4)
	.dwattr $C$DW$T$721, DW_AT_decl_column(0x26)

$C$DW$T$76	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$76, DW_AT_name("xdc_runtime_Text_PrintVisState")
	.dwattr $C$DW$T$76, DW_AT_declaration
	.dwendtag $C$DW$T$76

	.dwattr $C$DW$T$76, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$76, DW_AT_decl_line(0xe6)
	.dwattr $C$DW$T$76, DW_AT_decl_column(0x10)
$C$DW$T$722	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Text_PrintVisState")
	.dwattr $C$DW$T$722, DW_AT_type(*$C$DW$T$76)
	.dwattr $C$DW$T$722, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$722, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$722, DW_AT_decl_line(0xe6)
	.dwattr $C$DW$T$722, DW_AT_decl_column(0x2f)

$C$DW$T$77	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$77, DW_AT_name("xdc_runtime_TimestampNull_Fxns__")
	.dwattr $C$DW$T$77, DW_AT_declaration
	.dwendtag $C$DW$T$77

	.dwattr $C$DW$T$77, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$77, DW_AT_decl_line(0x102)
	.dwattr $C$DW$T$77, DW_AT_decl_column(0x10)
$C$DW$T$723	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_TimestampNull_Fxns__")
	.dwattr $C$DW$T$723, DW_AT_type(*$C$DW$T$77)
	.dwattr $C$DW$T$723, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$723, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$723, DW_AT_decl_line(0x102)
	.dwattr $C$DW$T$723, DW_AT_decl_column(0x31)
$C$DW$T$724	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$724, DW_AT_type(*$C$DW$T$723)
$C$DW$T$725	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$725, DW_AT_type(*$C$DW$T$724)
	.dwattr $C$DW$T$725, DW_AT_address_class(0x20)
$C$DW$T$726	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_TimestampNull_Module")
	.dwattr $C$DW$T$726, DW_AT_type(*$C$DW$T$725)
	.dwattr $C$DW$T$726, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$726, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$726, DW_AT_decl_line(0x103)
	.dwattr $C$DW$T$726, DW_AT_decl_column(0x31)

$C$DW$T$78	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$78, DW_AT_name("xdc_runtime_TimestampStd_Fxns__")
	.dwattr $C$DW$T$78, DW_AT_declaration
	.dwendtag $C$DW$T$78

	.dwattr $C$DW$T$78, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$78, DW_AT_decl_line(0x109)
	.dwattr $C$DW$T$78, DW_AT_decl_column(0x10)
$C$DW$T$727	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_TimestampStd_Fxns__")
	.dwattr $C$DW$T$727, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$T$727, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$727, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$727, DW_AT_decl_line(0x109)
	.dwattr $C$DW$T$727, DW_AT_decl_column(0x30)
$C$DW$T$728	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$728, DW_AT_type(*$C$DW$T$727)
$C$DW$T$729	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$729, DW_AT_type(*$C$DW$T$728)
	.dwattr $C$DW$T$729, DW_AT_address_class(0x20)
$C$DW$T$730	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_TimestampStd_Module")
	.dwattr $C$DW$T$730, DW_AT_type(*$C$DW$T$729)
	.dwattr $C$DW$T$730, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$730, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$730, DW_AT_decl_line(0x10a)
	.dwattr $C$DW$T$730, DW_AT_decl_column(0x30)

$C$DW$T$210	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$210, DW_AT_name("xdc_runtime_Timestamp_Fxns__")
	.dwattr $C$DW$T$210, DW_AT_byte_size(0x24)
$C$DW$221	.dwtag  DW_TAG_member
	.dwattr $C$DW$221, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$221, DW_AT_name("__base")
	.dwattr $C$DW$221, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$221, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$221, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$221, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$221, DW_AT_decl_line(0x9c)
	.dwattr $C$DW$221, DW_AT_decl_column(0x1d)
$C$DW$222	.dwtag  DW_TAG_member
	.dwattr $C$DW$222, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$222, DW_AT_name("__sysp")
	.dwattr $C$DW$222, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$222, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$222, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$222, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$222, DW_AT_decl_line(0x9d)
	.dwattr $C$DW$222, DW_AT_decl_column(0x27)
$C$DW$223	.dwtag  DW_TAG_member
	.dwattr $C$DW$223, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$223, DW_AT_name("get32")
	.dwattr $C$DW$223, DW_AT_TI_symbol_name("get32")
	.dwattr $C$DW$223, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$223, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$223, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$223, DW_AT_decl_line(0x9e)
	.dwattr $C$DW$223, DW_AT_decl_column(0x12)
$C$DW$224	.dwtag  DW_TAG_member
	.dwattr $C$DW$224, DW_AT_type(*$C$DW$T$168)
	.dwattr $C$DW$224, DW_AT_name("get64")
	.dwattr $C$DW$224, DW_AT_TI_symbol_name("get64")
	.dwattr $C$DW$224, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$224, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$224, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$224, DW_AT_decl_line(0x9f)
	.dwattr $C$DW$224, DW_AT_decl_column(0x10)
$C$DW$225	.dwtag  DW_TAG_member
	.dwattr $C$DW$225, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$225, DW_AT_name("getFreq")
	.dwattr $C$DW$225, DW_AT_TI_symbol_name("getFreq")
	.dwattr $C$DW$225, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$225, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$225, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$225, DW_AT_decl_line(0xa0)
	.dwattr $C$DW$225, DW_AT_decl_column(0x10)
$C$DW$226	.dwtag  DW_TAG_member
	.dwattr $C$DW$226, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$226, DW_AT_name("__sfxns")
	.dwattr $C$DW$226, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$226, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$226, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$226, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$226, DW_AT_decl_line(0xa1)
	.dwattr $C$DW$226, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$210

	.dwattr $C$DW$T$210, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Timestamp.h")
	.dwattr $C$DW$T$210, DW_AT_decl_line(0x9b)
	.dwattr $C$DW$T$210, DW_AT_decl_column(0x08)
$C$DW$T$731	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Timestamp_Fxns__")
	.dwattr $C$DW$T$731, DW_AT_type(*$C$DW$T$210)
	.dwattr $C$DW$T$731, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$731, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$731, DW_AT_decl_line(0xf4)
	.dwattr $C$DW$T$731, DW_AT_decl_column(0x2d)
$C$DW$T$732	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$732, DW_AT_type(*$C$DW$T$731)
$C$DW$T$733	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$733, DW_AT_type(*$C$DW$T$732)
	.dwattr $C$DW$T$733, DW_AT_address_class(0x20)
$C$DW$T$734	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Timestamp_Module")
	.dwattr $C$DW$T$734, DW_AT_type(*$C$DW$T$733)
	.dwattr $C$DW$T$734, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$734, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$734, DW_AT_decl_line(0xf5)
	.dwattr $C$DW$T$734, DW_AT_decl_column(0x2d)

$C$DW$T$211	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$211, DW_AT_name("xdc_runtime_Timestamp_SupportProxy_Fxns__")
	.dwattr $C$DW$T$211, DW_AT_byte_size(0x24)
$C$DW$227	.dwtag  DW_TAG_member
	.dwattr $C$DW$227, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$227, DW_AT_name("__base")
	.dwattr $C$DW$227, DW_AT_TI_symbol_name("__base")
	.dwattr $C$DW$227, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$227, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$227, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$227, DW_AT_decl_line(0x93)
	.dwattr $C$DW$227, DW_AT_decl_column(0x1d)
$C$DW$228	.dwtag  DW_TAG_member
	.dwattr $C$DW$228, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$228, DW_AT_name("__sysp")
	.dwattr $C$DW$228, DW_AT_TI_symbol_name("__sysp")
	.dwattr $C$DW$228, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$228, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$228, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$228, DW_AT_decl_line(0x94)
	.dwattr $C$DW$228, DW_AT_decl_column(0x27)
$C$DW$229	.dwtag  DW_TAG_member
	.dwattr $C$DW$229, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$229, DW_AT_name("get32")
	.dwattr $C$DW$229, DW_AT_TI_symbol_name("get32")
	.dwattr $C$DW$229, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$229, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$229, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$229, DW_AT_decl_line(0x95)
	.dwattr $C$DW$229, DW_AT_decl_column(0x12)
$C$DW$230	.dwtag  DW_TAG_member
	.dwattr $C$DW$230, DW_AT_type(*$C$DW$T$168)
	.dwattr $C$DW$230, DW_AT_name("get64")
	.dwattr $C$DW$230, DW_AT_TI_symbol_name("get64")
	.dwattr $C$DW$230, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$230, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$230, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$230, DW_AT_decl_line(0x96)
	.dwattr $C$DW$230, DW_AT_decl_column(0x10)
$C$DW$231	.dwtag  DW_TAG_member
	.dwattr $C$DW$231, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$231, DW_AT_name("getFreq")
	.dwattr $C$DW$231, DW_AT_TI_symbol_name("getFreq")
	.dwattr $C$DW$231, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$231, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$231, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$231, DW_AT_decl_line(0x97)
	.dwattr $C$DW$231, DW_AT_decl_column(0x10)
$C$DW$232	.dwtag  DW_TAG_member
	.dwattr $C$DW$232, DW_AT_type(*$C$DW$T$114)
	.dwattr $C$DW$232, DW_AT_name("__sfxns")
	.dwattr $C$DW$232, DW_AT_TI_symbol_name("__sfxns")
	.dwattr $C$DW$232, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$232, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$232, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$232, DW_AT_decl_line(0x98)
	.dwattr $C$DW$232, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$211

	.dwattr $C$DW$T$211, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/Timestamp_SupportProxy.h")
	.dwattr $C$DW$T$211, DW_AT_decl_line(0x92)
	.dwattr $C$DW$T$211, DW_AT_decl_column(0x08)
$C$DW$T$735	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Timestamp_SupportProxy_Fxns__")
	.dwattr $C$DW$T$735, DW_AT_type(*$C$DW$T$211)
	.dwattr $C$DW$T$735, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$735, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$735, DW_AT_decl_line(0x165)
	.dwattr $C$DW$T$735, DW_AT_decl_column(0x3a)
$C$DW$T$736	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$736, DW_AT_type(*$C$DW$T$735)
$C$DW$T$737	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$737, DW_AT_type(*$C$DW$T$736)
	.dwattr $C$DW$T$737, DW_AT_address_class(0x20)
$C$DW$T$738	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Timestamp_SupportProxy_Module")
	.dwattr $C$DW$T$738, DW_AT_type(*$C$DW$T$737)
	.dwattr $C$DW$T$738, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$738, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$738, DW_AT_decl_line(0x166)
	.dwattr $C$DW$T$738, DW_AT_decl_column(0x3a)

$C$DW$T$212	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$212, DW_AT_name("xdc_runtime_Types_Base")
	.dwattr $C$DW$T$212, DW_AT_byte_size(0x04)
$C$DW$233	.dwtag  DW_TAG_member
	.dwattr $C$DW$233, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$233, DW_AT_name("base")
	.dwattr $C$DW$233, DW_AT_TI_symbol_name("base")
	.dwattr $C$DW$233, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$233, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$233, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$233, DW_AT_decl_line(0xb5)
	.dwattr $C$DW$233, DW_AT_decl_column(0x1d)
	.dwendtag $C$DW$T$212

	.dwattr $C$DW$T$212, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$212, DW_AT_decl_line(0xb4)
	.dwattr $C$DW$T$212, DW_AT_decl_column(0x08)
$C$DW$T$112	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_Base")
	.dwattr $C$DW$T$112, DW_AT_type(*$C$DW$T$212)
	.dwattr $C$DW$T$112, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$112, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$112, DW_AT_decl_line(0x11b)
	.dwattr $C$DW$T$112, DW_AT_decl_column(0x27)
$C$DW$T$113	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$113, DW_AT_type(*$C$DW$T$112)
	.dwattr $C$DW$T$113, DW_AT_address_class(0x20)

$C$DW$T$79	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$79, DW_AT_name("xdc_runtime_Types_CordAddr__")
	.dwattr $C$DW$T$79, DW_AT_declaration
	.dwendtag $C$DW$T$79

	.dwattr $C$DW$T$79, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$79, DW_AT_decl_line(0x110)
	.dwattr $C$DW$T$79, DW_AT_decl_column(0x10)
$C$DW$T$186	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_CordAddr__")
	.dwattr $C$DW$T$186, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$186, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$186, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$186, DW_AT_decl_line(0x110)
	.dwattr $C$DW$T$186, DW_AT_decl_column(0x2d)
$C$DW$T$187	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$187, DW_AT_type(*$C$DW$T$186)
	.dwattr $C$DW$T$187, DW_AT_address_class(0x20)
$C$DW$T$188	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_CordAddr")
	.dwattr $C$DW$T$188, DW_AT_type(*$C$DW$T$187)
	.dwattr $C$DW$T$188, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$188, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$188, DW_AT_decl_line(0x4d)
	.dwattr $C$DW$T$188, DW_AT_decl_column(0x27)

$C$DW$T$739	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$739, DW_AT_name("xdc_runtime_Types_CreatePolicy")
	.dwattr $C$DW$T$739, DW_AT_byte_size(0x04)
$C$DW$234	.dwtag  DW_TAG_enumerator, DW_AT_name("xdc_runtime_Types_STATIC_POLICY"), DW_AT_const_value(0x00)
	.dwattr $C$DW$234, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$234, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$234, DW_AT_decl_column(0x05)
$C$DW$235	.dwtag  DW_TAG_enumerator, DW_AT_name("xdc_runtime_Types_CREATE_POLICY"), DW_AT_const_value(0x01)
	.dwattr $C$DW$235, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$235, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$235, DW_AT_decl_column(0x05)
$C$DW$236	.dwtag  DW_TAG_enumerator, DW_AT_name("xdc_runtime_Types_DELETE_POLICY"), DW_AT_const_value(0x02)
	.dwattr $C$DW$236, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$236, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$236, DW_AT_decl_column(0x05)
	.dwendtag $C$DW$T$739

	.dwattr $C$DW$T$739, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$739, DW_AT_decl_line(0x59)
	.dwattr $C$DW$T$739, DW_AT_decl_column(0x06)
$C$DW$T$740	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_CreatePolicy")
	.dwattr $C$DW$T$740, DW_AT_type(*$C$DW$T$739)
	.dwattr $C$DW$T$740, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$740, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$740, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$T$740, DW_AT_decl_column(0x2d)

$C$DW$T$213	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$213, DW_AT_name("xdc_runtime_Types_FreqHz")
	.dwattr $C$DW$T$213, DW_AT_byte_size(0x08)
$C$DW$237	.dwtag  DW_TAG_member
	.dwattr $C$DW$237, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$237, DW_AT_name("hi")
	.dwattr $C$DW$237, DW_AT_TI_symbol_name("hi")
	.dwattr $C$DW$237, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$237, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$237, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$237, DW_AT_decl_line(0x77)
	.dwattr $C$DW$237, DW_AT_decl_column(0x10)
$C$DW$238	.dwtag  DW_TAG_member
	.dwattr $C$DW$238, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$238, DW_AT_name("lo")
	.dwattr $C$DW$238, DW_AT_TI_symbol_name("lo")
	.dwattr $C$DW$238, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$238, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$238, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$238, DW_AT_decl_line(0x78)
	.dwattr $C$DW$238, DW_AT_decl_column(0x10)
	.dwendtag $C$DW$T$213

	.dwattr $C$DW$T$213, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$213, DW_AT_decl_line(0x76)
	.dwattr $C$DW$T$213, DW_AT_decl_column(0x08)
$C$DW$T$169	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_FreqHz")
	.dwattr $C$DW$T$169, DW_AT_type(*$C$DW$T$213)
	.dwattr $C$DW$T$169, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$169, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$169, DW_AT_decl_line(0x115)
	.dwattr $C$DW$T$169, DW_AT_decl_column(0x29)
$C$DW$T$170	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$170, DW_AT_type(*$C$DW$T$169)
	.dwattr $C$DW$T$170, DW_AT_address_class(0x20)

$C$DW$T$80	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$80, DW_AT_name("xdc_runtime_Types_GateRef__")
	.dwattr $C$DW$T$80, DW_AT_declaration
	.dwendtag $C$DW$T$80

	.dwattr $C$DW$T$80, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$80, DW_AT_decl_line(0x111)
	.dwattr $C$DW$T$80, DW_AT_decl_column(0x10)
$C$DW$T$741	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_GateRef__")
	.dwattr $C$DW$T$741, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$T$741, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$741, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$741, DW_AT_decl_line(0x111)
	.dwattr $C$DW$T$741, DW_AT_decl_column(0x2c)
$C$DW$T$742	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$742, DW_AT_type(*$C$DW$T$741)
	.dwattr $C$DW$T$742, DW_AT_address_class(0x20)
$C$DW$T$743	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_GateRef")
	.dwattr $C$DW$T$743, DW_AT_type(*$C$DW$T$742)
	.dwattr $C$DW$T$743, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$743, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$743, DW_AT_decl_line(0x53)
	.dwattr $C$DW$T$743, DW_AT_decl_column(0x26)

$C$DW$T$215	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$215, DW_AT_name("xdc_runtime_Types_InstHdr")
	.dwattr $C$DW$T$215, DW_AT_byte_size(0x08)
$C$DW$239	.dwtag  DW_TAG_member
	.dwattr $C$DW$239, DW_AT_type(*$C$DW$T$214)
	.dwattr $C$DW$239, DW_AT_name("link")
	.dwattr $C$DW$239, DW_AT_TI_symbol_name("link")
	.dwattr $C$DW$239, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$239, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$239, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$239, DW_AT_decl_line(0xa8)
	.dwattr $C$DW$239, DW_AT_decl_column(0x1c)
	.dwendtag $C$DW$T$215

	.dwattr $C$DW$T$215, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$215, DW_AT_decl_line(0xa7)
	.dwattr $C$DW$T$215, DW_AT_decl_column(0x08)
$C$DW$T$744	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_InstHdr")
	.dwattr $C$DW$T$744, DW_AT_type(*$C$DW$T$215)
	.dwattr $C$DW$T$744, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$744, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$744, DW_AT_decl_line(0x119)
	.dwattr $C$DW$T$744, DW_AT_decl_column(0x2a)

$C$DW$T$218	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$218, DW_AT_name("xdc_runtime_Types_Label")
	.dwattr $C$DW$T$218, DW_AT_byte_size(0x10)
$C$DW$240	.dwtag  DW_TAG_member
	.dwattr $C$DW$240, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$240, DW_AT_name("handle")
	.dwattr $C$DW$240, DW_AT_TI_symbol_name("handle")
	.dwattr $C$DW$240, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$240, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$240, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$240, DW_AT_decl_line(0x62)
	.dwattr $C$DW$240, DW_AT_decl_column(0x0d)
$C$DW$241	.dwtag  DW_TAG_member
	.dwattr $C$DW$241, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$241, DW_AT_name("modId")
	.dwattr $C$DW$241, DW_AT_TI_symbol_name("modId")
	.dwattr $C$DW$241, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$241, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$241, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$241, DW_AT_decl_line(0x63)
	.dwattr $C$DW$241, DW_AT_decl_column(0x20)
$C$DW$242	.dwtag  DW_TAG_member
	.dwattr $C$DW$242, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$242, DW_AT_name("iname")
	.dwattr $C$DW$242, DW_AT_TI_symbol_name("iname")
	.dwattr $C$DW$242, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$242, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$242, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$242, DW_AT_decl_line(0x64)
	.dwattr $C$DW$242, DW_AT_decl_column(0x10)
$C$DW$243	.dwtag  DW_TAG_member
	.dwattr $C$DW$243, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$243, DW_AT_name("named")
	.dwattr $C$DW$243, DW_AT_TI_symbol_name("named")
	.dwattr $C$DW$243, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$243, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$243, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$243, DW_AT_decl_line(0x65)
	.dwattr $C$DW$243, DW_AT_decl_column(0x0e)
	.dwendtag $C$DW$T$218

	.dwattr $C$DW$T$218, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$218, DW_AT_decl_line(0x61)
	.dwattr $C$DW$T$218, DW_AT_decl_column(0x08)
$C$DW$T$232	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_Label")
	.dwattr $C$DW$T$232, DW_AT_type(*$C$DW$T$218)
	.dwattr $C$DW$T$232, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$232, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$232, DW_AT_decl_line(0x112)
	.dwattr $C$DW$T$232, DW_AT_decl_column(0x28)
$C$DW$T$233	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$233, DW_AT_type(*$C$DW$T$232)
	.dwattr $C$DW$T$233, DW_AT_address_class(0x20)

$C$DW$T$234	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$234, DW_AT_type(*$C$DW$T$233)
	.dwattr $C$DW$T$234, DW_AT_language(DW_LANG_C)
$C$DW$244	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$244, DW_AT_type(*$C$DW$T$135)
$C$DW$245	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$245, DW_AT_type(*$C$DW$T$233)
	.dwendtag $C$DW$T$234

$C$DW$T$235	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$235, DW_AT_type(*$C$DW$T$234)
	.dwattr $C$DW$T$235, DW_AT_address_class(0x20)

$C$DW$T$220	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$220, DW_AT_name("xdc_runtime_Types_Link")
	.dwattr $C$DW$T$220, DW_AT_byte_size(0x08)
$C$DW$246	.dwtag  DW_TAG_member
	.dwattr $C$DW$246, DW_AT_type(*$C$DW$T$219)
	.dwattr $C$DW$246, DW_AT_name("next")
	.dwattr $C$DW$246, DW_AT_TI_symbol_name("next")
	.dwattr $C$DW$246, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$246, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$246, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$246, DW_AT_decl_line(0xa2)
	.dwattr $C$DW$246, DW_AT_decl_column(0x1d)
$C$DW$247	.dwtag  DW_TAG_member
	.dwattr $C$DW$247, DW_AT_type(*$C$DW$T$219)
	.dwattr $C$DW$247, DW_AT_name("prev")
	.dwattr $C$DW$247, DW_AT_TI_symbol_name("prev")
	.dwattr $C$DW$247, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$247, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$247, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$247, DW_AT_decl_line(0xa3)
	.dwattr $C$DW$247, DW_AT_decl_column(0x1d)
	.dwendtag $C$DW$T$220

	.dwattr $C$DW$T$220, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$220, DW_AT_decl_line(0xa1)
	.dwattr $C$DW$T$220, DW_AT_decl_column(0x08)
$C$DW$T$214	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_Link")
	.dwattr $C$DW$T$214, DW_AT_type(*$C$DW$T$220)
	.dwattr $C$DW$T$214, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$214, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$214, DW_AT_decl_line(0x118)
	.dwattr $C$DW$T$214, DW_AT_decl_column(0x27)
$C$DW$T$219	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$219, DW_AT_type(*$C$DW$T$214)
	.dwattr $C$DW$T$219, DW_AT_address_class(0x20)

$C$DW$T$221	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$221, DW_AT_name("xdc_runtime_Types_PrmsHdr")
	.dwattr $C$DW$T$221, DW_AT_byte_size(0x10)
$C$DW$248	.dwtag  DW_TAG_member
	.dwattr $C$DW$248, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$248, DW_AT_name("size")
	.dwattr $C$DW$248, DW_AT_TI_symbol_name("size")
	.dwattr $C$DW$248, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$248, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$248, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$248, DW_AT_decl_line(0xad)
	.dwattr $C$DW$248, DW_AT_decl_column(0x0f)
$C$DW$249	.dwtag  DW_TAG_member
	.dwattr $C$DW$249, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$249, DW_AT_name("self")
	.dwattr $C$DW$249, DW_AT_TI_symbol_name("self")
	.dwattr $C$DW$249, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$249, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$249, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$249, DW_AT_decl_line(0xae)
	.dwattr $C$DW$249, DW_AT_decl_column(0x0d)
$C$DW$250	.dwtag  DW_TAG_member
	.dwattr $C$DW$250, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$250, DW_AT_name("modFxns")
	.dwattr $C$DW$250, DW_AT_TI_symbol_name("modFxns")
	.dwattr $C$DW$250, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$250, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$250, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$250, DW_AT_decl_line(0xaf)
	.dwattr $C$DW$250, DW_AT_decl_column(0x0d)
$C$DW$251	.dwtag  DW_TAG_member
	.dwattr $C$DW$251, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$251, DW_AT_name("instPrms")
	.dwattr $C$DW$251, DW_AT_TI_symbol_name("instPrms")
	.dwattr $C$DW$251, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$251, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$251, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$251, DW_AT_decl_line(0xb0)
	.dwattr $C$DW$251, DW_AT_decl_column(0x0d)
	.dwendtag $C$DW$T$221

	.dwattr $C$DW$T$221, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$221, DW_AT_decl_line(0xac)
	.dwattr $C$DW$T$221, DW_AT_decl_column(0x08)
$C$DW$T$745	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_PrmsHdr")
	.dwattr $C$DW$T$745, DW_AT_type(*$C$DW$T$221)
	.dwattr $C$DW$T$745, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$745, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$745, DW_AT_decl_line(0x11a)
	.dwattr $C$DW$T$745, DW_AT_decl_column(0x2a)

$C$DW$T$225	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$225, DW_AT_name("xdc_runtime_Types_RegDesc")
	.dwattr $C$DW$T$225, DW_AT_byte_size(0x0c)
$C$DW$252	.dwtag  DW_TAG_member
	.dwattr $C$DW$252, DW_AT_type(*$C$DW$T$223)
	.dwattr $C$DW$252, DW_AT_name("next")
	.dwattr $C$DW$252, DW_AT_TI_symbol_name("next")
	.dwattr $C$DW$252, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$252, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$252, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$252, DW_AT_decl_line(0x7d)
	.dwattr $C$DW$252, DW_AT_decl_column(0x20)
$C$DW$253	.dwtag  DW_TAG_member
	.dwattr $C$DW$253, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$253, DW_AT_name("modName")
	.dwattr $C$DW$253, DW_AT_TI_symbol_name("modName")
	.dwattr $C$DW$253, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$253, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$253, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$253, DW_AT_decl_line(0x7e)
	.dwattr $C$DW$253, DW_AT_decl_column(0x10)
$C$DW$254	.dwtag  DW_TAG_member
	.dwattr $C$DW$254, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$254, DW_AT_name("id")
	.dwattr $C$DW$254, DW_AT_TI_symbol_name("id")
	.dwattr $C$DW$254, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$254, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$254, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$254, DW_AT_decl_line(0x7f)
	.dwattr $C$DW$254, DW_AT_decl_column(0x20)
$C$DW$255	.dwtag  DW_TAG_member
	.dwattr $C$DW$255, DW_AT_type(*$C$DW$T$224)
	.dwattr $C$DW$255, DW_AT_name("mask")
	.dwattr $C$DW$255, DW_AT_TI_symbol_name("mask")
	.dwattr $C$DW$255, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$255, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$255, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$255, DW_AT_decl_line(0x80)
	.dwattr $C$DW$255, DW_AT_decl_column(0x21)
	.dwendtag $C$DW$T$225

	.dwattr $C$DW$T$225, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$225, DW_AT_decl_line(0x7c)
	.dwattr $C$DW$T$225, DW_AT_decl_column(0x08)
$C$DW$T$222	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_RegDesc")
	.dwattr $C$DW$T$222, DW_AT_type(*$C$DW$T$225)
	.dwattr $C$DW$T$222, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$222, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$222, DW_AT_decl_line(0x116)
	.dwattr $C$DW$T$222, DW_AT_decl_column(0x2a)
$C$DW$T$223	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$223, DW_AT_type(*$C$DW$T$222)
	.dwattr $C$DW$T$223, DW_AT_address_class(0x20)

$C$DW$T$226	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$226, DW_AT_name("xdc_runtime_Types_Site")
	.dwattr $C$DW$T$226, DW_AT_byte_size(0x0c)
$C$DW$256	.dwtag  DW_TAG_member
	.dwattr $C$DW$256, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$256, DW_AT_name("mod")
	.dwattr $C$DW$256, DW_AT_TI_symbol_name("mod")
	.dwattr $C$DW$256, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$256, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$256, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$256, DW_AT_decl_line(0x6a)
	.dwattr $C$DW$256, DW_AT_decl_column(0x20)
$C$DW$257	.dwtag  DW_TAG_member
	.dwattr $C$DW$257, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$257, DW_AT_name("file")
	.dwattr $C$DW$257, DW_AT_TI_symbol_name("file")
	.dwattr $C$DW$257, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$257, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$257, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$257, DW_AT_decl_line(0x6b)
	.dwattr $C$DW$257, DW_AT_decl_column(0x10)
$C$DW$258	.dwtag  DW_TAG_member
	.dwattr $C$DW$258, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$258, DW_AT_name("line")
	.dwattr $C$DW$258, DW_AT_TI_symbol_name("line")
	.dwattr $C$DW$258, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$258, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$258, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$258, DW_AT_decl_line(0x6c)
	.dwattr $C$DW$258, DW_AT_decl_column(0x0d)
	.dwendtag $C$DW$T$226

	.dwattr $C$DW$T$226, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$226, DW_AT_decl_line(0x69)
	.dwattr $C$DW$T$226, DW_AT_decl_column(0x08)
$C$DW$T$100	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_Site")
	.dwattr $C$DW$T$100, DW_AT_type(*$C$DW$T$226)
	.dwattr $C$DW$T$100, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$100, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$100, DW_AT_decl_line(0x113)
	.dwattr $C$DW$T$100, DW_AT_decl_column(0x27)

$C$DW$T$236	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$236, DW_AT_name("xdc_runtime_Types_SysFxns")
	.dwattr $C$DW$T$236, DW_AT_byte_size(0x10)
$C$DW$259	.dwtag  DW_TAG_member
	.dwattr $C$DW$259, DW_AT_type(*$C$DW$T$229)
	.dwattr $C$DW$259, DW_AT_name("__create")
	.dwattr $C$DW$259, DW_AT_TI_symbol_name("__create")
	.dwattr $C$DW$259, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$259, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$259, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$259, DW_AT_decl_line(0xba)
	.dwattr $C$DW$259, DW_AT_decl_column(0x0f)
$C$DW$260	.dwtag  DW_TAG_member
	.dwattr $C$DW$260, DW_AT_type(*$C$DW$T$231)
	.dwattr $C$DW$260, DW_AT_name("__delete")
	.dwattr $C$DW$260, DW_AT_TI_symbol_name("__delete")
	.dwattr $C$DW$260, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$260, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$260, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$260, DW_AT_decl_line(0xbb)
	.dwattr $C$DW$260, DW_AT_decl_column(0x10)
$C$DW$261	.dwtag  DW_TAG_member
	.dwattr $C$DW$261, DW_AT_type(*$C$DW$T$235)
	.dwattr $C$DW$261, DW_AT_name("__label")
	.dwattr $C$DW$261, DW_AT_TI_symbol_name("__label")
	.dwattr $C$DW$261, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$261, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$261, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$261, DW_AT_decl_line(0xbc)
	.dwattr $C$DW$261, DW_AT_decl_column(0x20)
$C$DW$262	.dwtag  DW_TAG_member
	.dwattr $C$DW$262, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$262, DW_AT_name("__mid")
	.dwattr $C$DW$262, DW_AT_TI_symbol_name("__mid")
	.dwattr $C$DW$262, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$262, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$262, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$262, DW_AT_decl_line(0xbd)
	.dwattr $C$DW$262, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$236

	.dwattr $C$DW$T$236, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$236, DW_AT_decl_line(0xb9)
	.dwattr $C$DW$T$236, DW_AT_decl_column(0x08)
$C$DW$T$746	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_SysFxns")
	.dwattr $C$DW$T$746, DW_AT_type(*$C$DW$T$236)
	.dwattr $C$DW$T$746, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$746, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$746, DW_AT_decl_line(0x11c)
	.dwattr $C$DW$T$746, DW_AT_decl_column(0x2a)

$C$DW$T$242	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$242, DW_AT_name("xdc_runtime_Types_SysFxns2")
	.dwattr $C$DW$T$242, DW_AT_byte_size(0x10)
$C$DW$263	.dwtag  DW_TAG_member
	.dwattr $C$DW$263, DW_AT_type(*$C$DW$T$241)
	.dwattr $C$DW$263, DW_AT_name("__create")
	.dwattr $C$DW$263, DW_AT_TI_symbol_name("__create")
	.dwattr $C$DW$263, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$263, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$263, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$263, DW_AT_decl_line(0xc2)
	.dwattr $C$DW$263, DW_AT_decl_column(0x0f)
$C$DW$264	.dwtag  DW_TAG_member
	.dwattr $C$DW$264, DW_AT_type(*$C$DW$T$231)
	.dwattr $C$DW$264, DW_AT_name("__delete")
	.dwattr $C$DW$264, DW_AT_TI_symbol_name("__delete")
	.dwattr $C$DW$264, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$264, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$264, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$264, DW_AT_decl_line(0xc3)
	.dwattr $C$DW$264, DW_AT_decl_column(0x10)
$C$DW$265	.dwtag  DW_TAG_member
	.dwattr $C$DW$265, DW_AT_type(*$C$DW$T$235)
	.dwattr $C$DW$265, DW_AT_name("__label")
	.dwattr $C$DW$265, DW_AT_TI_symbol_name("__label")
	.dwattr $C$DW$265, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$265, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$265, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$265, DW_AT_decl_line(0xc4)
	.dwattr $C$DW$265, DW_AT_decl_column(0x20)
$C$DW$266	.dwtag  DW_TAG_member
	.dwattr $C$DW$266, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$266, DW_AT_name("__mid")
	.dwattr $C$DW$266, DW_AT_TI_symbol_name("__mid")
	.dwattr $C$DW$266, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$266, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$266, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$266, DW_AT_decl_line(0xc5)
	.dwattr $C$DW$266, DW_AT_decl_column(0x20)
	.dwendtag $C$DW$T$242

	.dwattr $C$DW$T$242, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$242, DW_AT_decl_line(0xc1)
	.dwattr $C$DW$T$242, DW_AT_decl_column(0x08)
$C$DW$T$114	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_SysFxns2")
	.dwattr $C$DW$T$114, DW_AT_type(*$C$DW$T$242)
	.dwattr $C$DW$T$114, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$114, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$114, DW_AT_decl_line(0x11d)
	.dwattr $C$DW$T$114, DW_AT_decl_column(0x2b)
$C$DW$T$115	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$115, DW_AT_type(*$C$DW$T$114)
$C$DW$T$116	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$116, DW_AT_type(*$C$DW$T$115)
	.dwattr $C$DW$T$116, DW_AT_address_class(0x20)

$C$DW$T$243	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$243, DW_AT_name("xdc_runtime_Types_Timestamp64")
	.dwattr $C$DW$T$243, DW_AT_byte_size(0x08)
$C$DW$267	.dwtag  DW_TAG_member
	.dwattr $C$DW$267, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$267, DW_AT_name("hi")
	.dwattr $C$DW$267, DW_AT_TI_symbol_name("hi")
	.dwattr $C$DW$267, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$267, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$267, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$267, DW_AT_decl_line(0x71)
	.dwattr $C$DW$267, DW_AT_decl_column(0x10)
$C$DW$268	.dwtag  DW_TAG_member
	.dwattr $C$DW$268, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$268, DW_AT_name("lo")
	.dwattr $C$DW$268, DW_AT_TI_symbol_name("lo")
	.dwattr $C$DW$268, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$268, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$268, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$268, DW_AT_decl_line(0x72)
	.dwattr $C$DW$268, DW_AT_decl_column(0x10)
	.dwendtag $C$DW$T$243

	.dwattr $C$DW$T$243, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$243, DW_AT_decl_line(0x70)
	.dwattr $C$DW$T$243, DW_AT_decl_column(0x08)
$C$DW$T$165	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_Timestamp64")
	.dwattr $C$DW$T$165, DW_AT_type(*$C$DW$T$243)
	.dwattr $C$DW$T$165, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$165, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$165, DW_AT_decl_line(0x114)
	.dwattr $C$DW$T$165, DW_AT_decl_column(0x2e)
$C$DW$T$166	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$166, DW_AT_type(*$C$DW$T$165)
	.dwattr $C$DW$T$166, DW_AT_address_class(0x20)

$C$DW$T$244	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$244, DW_AT_name("xdc_runtime_Types_Vec")
	.dwattr $C$DW$T$244, DW_AT_byte_size(0x08)
$C$DW$269	.dwtag  DW_TAG_member
	.dwattr $C$DW$269, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$269, DW_AT_name("len")
	.dwattr $C$DW$269, DW_AT_TI_symbol_name("len")
	.dwattr $C$DW$269, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$269, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$269, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$269, DW_AT_decl_line(0x9c)
	.dwattr $C$DW$269, DW_AT_decl_column(0x0d)
$C$DW$270	.dwtag  DW_TAG_member
	.dwattr $C$DW$270, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$270, DW_AT_name("arr")
	.dwattr $C$DW$270, DW_AT_TI_symbol_name("arr")
	.dwattr $C$DW$270, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$270, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$270, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$270, DW_AT_decl_line(0x9d)
	.dwattr $C$DW$270, DW_AT_decl_column(0x0d)
	.dwendtag $C$DW$T$244

	.dwattr $C$DW$T$244, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/Types.h")
	.dwattr $C$DW$T$244, DW_AT_decl_line(0x9b)
	.dwattr $C$DW$T$244, DW_AT_decl_column(0x08)
$C$DW$T$747	.dwtag  DW_TAG_typedef, DW_AT_name("xdc_runtime_Types_Vec")
	.dwattr $C$DW$T$747, DW_AT_type(*$C$DW$T$244)
	.dwattr $C$DW$T$747, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$747, DW_AT_decl_file("C:/ti/xdctools_3_23_03_53/packages/xdc/runtime/package/package.defs.h")
	.dwattr $C$DW$T$747, DW_AT_decl_line(0x117)
	.dwattr $C$DW$T$747, DW_AT_decl_column(0x26)
	.dwattr $C$DW$CU, DW_AT_language(DW_LANG_C)
	.dwendtag $C$DW$CU


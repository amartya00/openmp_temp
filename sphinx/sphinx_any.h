/*
$Log: sphinx_any.h,v $
Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: sphinx_any.h,v 1.1.1.1 1999/05/11 16:50:02 srtaylor Exp $ */
#ifndef ANY
#define ANY
#include <stdio.h>

/* ============================== Debugging ================================ */
#define NDEBUGL 1

/* Level 0: always */
#if NDEBUGL >= 0
#define NDebug0(A) A
#else
#define NDebug0(A) 
#endif

/* Level 1: statistics and messages with minimal impact on speed */
#if NDEBUGL >= 1
#define NDebug1(A) A
#else
#define NDebug1(A) 
#endif

/* Level 2: Debugging and checks with tolerable volume of output */
#if NDEBUGL >= 2
#define NDebug2(A) A
#else
#define NDebug2(A) 
#endif

/* Level 3: Current focus */
#if NDEBUGL >= 3
#define NDebug3(A) A
#else
#define NDebug3(A) 
#endif

/* Level 4: Extreme detail */
#if NDEBUGL >= 4
#define NDebug4(A) A
#else
#define NDebug4(A) 
#endif

/* #define NFAILASSERT */
/* complain if condition is not true */
#ifdef NFAILASSERT
#define NAssert(c) if(!(c)){printf(\
   "\nAssertion violation %s:%u:" #c "\n", __FILE__, __LINE__); printf("%d", *(int*)0);}
#else
#define NAssert(c) if(!(c)){printf(\
   "\nAssertion violation %s:%u:" #c "\n", __FILE__, __LINE__);}
#endif


#define NAssert0(c) NDebug0(NAssert(c))
#define NAssert1(c) NDebug1(NAssert(c))
#define NAssert2(c) NDebug2(NAssert(c))
#define NAssert3(c) NDebug3(NAssert(c))
#define NAssert4(c) NDebug4(NAssert(c))


/* ============================== utility macros =========================== */

#define NAbs(x)    ((x) >= 0  ? (x) : -(x))

#define NMax(x, y) ((x) > (y) ? (x) :  (y))

#define NMin(x, y) ((x) > (y) ? (y) :  (x))

#define NRound(x)  (int)((x) + 0.5)

#endif


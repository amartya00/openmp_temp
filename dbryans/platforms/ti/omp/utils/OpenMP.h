/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y30
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     FUNCTION DECLARATIONS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_omp_utils_OpenMP__include
#define ti_omp_utils_OpenMP__include

#ifndef __nested__
#define __nested__
#define ti_omp_utils_OpenMP__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_omp_utils_OpenMP___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/omp/utils/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <ti/sdo/ipc/MessageQ.h>
#include <ti/sdo/ipc/GateMP.h>
#include <ti/omp/navigator/Navigator.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/timers/timer64/Timer.h>
#include <xdc/runtime/Diags.h>
#include <ti/omp/utils/SemaphoreMP.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Types.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef xdc_Void (*ti_omp_utils_OpenMP_FuncPtr)(void);


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_omp_utils_OpenMP_Module__diagsEnabled;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__diagsEnabled ti_omp_utils_OpenMP_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_omp_utils_OpenMP_Module__diagsIncluded;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__diagsIncluded ti_omp_utils_OpenMP_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_omp_utils_OpenMP_Module__diagsMask;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__diagsMask ti_omp_utils_OpenMP_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_omp_utils_OpenMP_Module__gateObj;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__gateObj ti_omp_utils_OpenMP_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_omp_utils_OpenMP_Module__gatePrms;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__gatePrms ti_omp_utils_OpenMP_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_omp_utils_OpenMP_Module__id;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__id ti_omp_utils_OpenMP_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_omp_utils_OpenMP_Module__loggerDefined;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__loggerDefined ti_omp_utils_OpenMP_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_omp_utils_OpenMP_Module__loggerObj;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__loggerObj ti_omp_utils_OpenMP_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_omp_utils_OpenMP_Module__loggerFxn0;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__loggerFxn0 ti_omp_utils_OpenMP_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_omp_utils_OpenMP_Module__loggerFxn1;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__loggerFxn1 ti_omp_utils_OpenMP_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_omp_utils_OpenMP_Module__loggerFxn2;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__loggerFxn2 ti_omp_utils_OpenMP_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_omp_utils_OpenMP_Module__loggerFxn4;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__loggerFxn4 ti_omp_utils_OpenMP_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_omp_utils_OpenMP_Module__loggerFxn8;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__loggerFxn8 ti_omp_utils_OpenMP_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_omp_utils_OpenMP_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Module__startupDoneFxn ti_omp_utils_OpenMP_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_omp_utils_OpenMP_Object__count;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Object__count ti_omp_utils_OpenMP_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_omp_utils_OpenMP_Object__heap;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Object__heap ti_omp_utils_OpenMP_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_omp_utils_OpenMP_Object__sizeof;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Object__sizeof ti_omp_utils_OpenMP_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_omp_utils_OpenMP_Object__table;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_Object__table ti_omp_utils_OpenMP_Object__table__C;

/* masterFxn */
#define ti_omp_utils_OpenMP_masterFxn (ti_omp_utils_OpenMP_masterFxn__C)
typedef ti_omp_utils_OpenMP_FuncPtr CT__ti_omp_utils_OpenMP_masterFxn;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_masterFxn ti_omp_utils_OpenMP_masterFxn__C;

/* singleThreadPerCore */
#ifdef ti_omp_utils_OpenMP_singleThreadPerCore__D
#define ti_omp_utils_OpenMP_singleThreadPerCore (ti_omp_utils_OpenMP_singleThreadPerCore__D)
#else
#define ti_omp_utils_OpenMP_singleThreadPerCore (ti_omp_utils_OpenMP_singleThreadPerCore__C)
typedef xdc_Bool CT__ti_omp_utils_OpenMP_singleThreadPerCore;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_singleThreadPerCore ti_omp_utils_OpenMP_singleThreadPerCore__C;
#endif

/* qmssInit */
#ifdef ti_omp_utils_OpenMP_qmssInit__D
#define ti_omp_utils_OpenMP_qmssInit (ti_omp_utils_OpenMP_qmssInit__D)
#else
#define ti_omp_utils_OpenMP_qmssInit (ti_omp_utils_OpenMP_qmssInit__C)
typedef xdc_Bool CT__ti_omp_utils_OpenMP_qmssInit;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_qmssInit ti_omp_utils_OpenMP_qmssInit__C;
#endif

/* qmssMemRegion */
#ifdef ti_omp_utils_OpenMP_qmssMemRegion__D
#define ti_omp_utils_OpenMP_qmssMemRegion (ti_omp_utils_OpenMP_qmssMemRegion__D)
#else
#define ti_omp_utils_OpenMP_qmssMemRegion (ti_omp_utils_OpenMP_qmssMemRegion__C)
typedef xdc_Int32 CT__ti_omp_utils_OpenMP_qmssMemRegion;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_qmssMemRegion ti_omp_utils_OpenMP_qmssMemRegion__C;
#endif

/* qmssStartIndex */
#ifdef ti_omp_utils_OpenMP_qmssStartIndex__D
#define ti_omp_utils_OpenMP_qmssStartIndex (ti_omp_utils_OpenMP_qmssStartIndex__D)
#else
#define ti_omp_utils_OpenMP_qmssStartIndex (ti_omp_utils_OpenMP_qmssStartIndex__C)
typedef xdc_UInt32 CT__ti_omp_utils_OpenMP_qmssStartIndex;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_qmssStartIndex ti_omp_utils_OpenMP_qmssStartIndex__C;
#endif

/* qmssDestQueueNum */
#ifdef ti_omp_utils_OpenMP_qmssDestQueueNum__D
#define ti_omp_utils_OpenMP_qmssDestQueueNum (ti_omp_utils_OpenMP_qmssDestQueueNum__D)
#else
#define ti_omp_utils_OpenMP_qmssDestQueueNum (ti_omp_utils_OpenMP_qmssDestQueueNum__C)
typedef xdc_Int32 CT__ti_omp_utils_OpenMP_qmssDestQueueNum;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_qmssDestQueueNum ti_omp_utils_OpenMP_qmssDestQueueNum__C;
#endif

/* stackSize */
#ifdef ti_omp_utils_OpenMP_stackSize__D
#define ti_omp_utils_OpenMP_stackSize (ti_omp_utils_OpenMP_stackSize__D)
#else
#define ti_omp_utils_OpenMP_stackSize (ti_omp_utils_OpenMP_stackSize__C)
typedef xdc_SizeT CT__ti_omp_utils_OpenMP_stackSize;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_stackSize ti_omp_utils_OpenMP_stackSize__C;
#endif

/* ipcHeapSize */
#ifdef ti_omp_utils_OpenMP_ipcHeapSize__D
#define ti_omp_utils_OpenMP_ipcHeapSize (ti_omp_utils_OpenMP_ipcHeapSize__D)
#else
#define ti_omp_utils_OpenMP_ipcHeapSize (ti_omp_utils_OpenMP_ipcHeapSize__C)
typedef xdc_SizeT CT__ti_omp_utils_OpenMP_ipcHeapSize;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_ipcHeapSize ti_omp_utils_OpenMP_ipcHeapSize__C;
#endif

/* stackRegionId */
#ifdef ti_omp_utils_OpenMP_stackRegionId__D
#define ti_omp_utils_OpenMP_stackRegionId (ti_omp_utils_OpenMP_stackRegionId__D)
#else
#define ti_omp_utils_OpenMP_stackRegionId (ti_omp_utils_OpenMP_stackRegionId__C)
typedef xdc_Int CT__ti_omp_utils_OpenMP_stackRegionId;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_stackRegionId ti_omp_utils_OpenMP_stackRegionId__C;
#endif

/* internalOsal */
#ifdef ti_omp_utils_OpenMP_internalOsal__D
#define ti_omp_utils_OpenMP_internalOsal (ti_omp_utils_OpenMP_internalOsal__D)
#else
#define ti_omp_utils_OpenMP_internalOsal (ti_omp_utils_OpenMP_internalOsal__C)
typedef xdc_Bool CT__ti_omp_utils_OpenMP_internalOsal;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_internalOsal ti_omp_utils_OpenMP_internalOsal__C;
#endif

/* cppiHwSem */
#ifdef ti_omp_utils_OpenMP_cppiHwSem__D
#define ti_omp_utils_OpenMP_cppiHwSem (ti_omp_utils_OpenMP_cppiHwSem__D)
#else
#define ti_omp_utils_OpenMP_cppiHwSem (ti_omp_utils_OpenMP_cppiHwSem__C)
typedef xdc_UInt CT__ti_omp_utils_OpenMP_cppiHwSem;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_cppiHwSem ti_omp_utils_OpenMP_cppiHwSem__C;
#endif

/* qmssHwSem */
#ifdef ti_omp_utils_OpenMP_qmssHwSem__D
#define ti_omp_utils_OpenMP_qmssHwSem (ti_omp_utils_OpenMP_qmssHwSem__D)
#else
#define ti_omp_utils_OpenMP_qmssHwSem (ti_omp_utils_OpenMP_qmssHwSem__C)
typedef xdc_UInt CT__ti_omp_utils_OpenMP_qmssHwSem;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_qmssHwSem ti_omp_utils_OpenMP_qmssHwSem__C;
#endif

/* ompHwSem */
#ifdef ti_omp_utils_OpenMP_ompHwSem__D
#define ti_omp_utils_OpenMP_ompHwSem (ti_omp_utils_OpenMP_ompHwSem__D)
#else
#define ti_omp_utils_OpenMP_ompHwSem (ti_omp_utils_OpenMP_ompHwSem__C)
typedef xdc_UInt CT__ti_omp_utils_OpenMP_ompHwSem;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_ompHwSem ti_omp_utils_OpenMP_ompHwSem__C;
#endif

/* mpaxIndex */
#ifdef ti_omp_utils_OpenMP_mpaxIndex__D
#define ti_omp_utils_OpenMP_mpaxIndex (ti_omp_utils_OpenMP_mpaxIndex__D)
#else
#define ti_omp_utils_OpenMP_mpaxIndex (ti_omp_utils_OpenMP_mpaxIndex__C)
typedef xdc_UInt CT__ti_omp_utils_OpenMP_mpaxIndex;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_mpaxIndex ti_omp_utils_OpenMP_mpaxIndex__C;
#endif

/* mpaxRaddr */
#ifdef ti_omp_utils_OpenMP_mpaxRaddr__D
#define ti_omp_utils_OpenMP_mpaxRaddr (ti_omp_utils_OpenMP_mpaxRaddr__D)
#else
#define ti_omp_utils_OpenMP_mpaxRaddr (ti_omp_utils_OpenMP_mpaxRaddr__C)
typedef xdc_UInt32 CT__ti_omp_utils_OpenMP_mpaxRaddr;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_mpaxRaddr ti_omp_utils_OpenMP_mpaxRaddr__C;
#endif

/* autoDnldCore */
#ifdef ti_omp_utils_OpenMP_autoDnldCore__D
#define ti_omp_utils_OpenMP_autoDnldCore (ti_omp_utils_OpenMP_autoDnldCore__D)
#else
#define ti_omp_utils_OpenMP_autoDnldCore (ti_omp_utils_OpenMP_autoDnldCore__C)
typedef xdc_Bool CT__ti_omp_utils_OpenMP_autoDnldCore;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_autoDnldCore ti_omp_utils_OpenMP_autoDnldCore__C;
#endif

/* threadPriority */
#ifdef ti_omp_utils_OpenMP_threadPriority__D
#define ti_omp_utils_OpenMP_threadPriority (ti_omp_utils_OpenMP_threadPriority__D)
#else
#define ti_omp_utils_OpenMP_threadPriority (ti_omp_utils_OpenMP_threadPriority__C)
typedef xdc_Int CT__ti_omp_utils_OpenMP_threadPriority;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_threadPriority ti_omp_utils_OpenMP_threadPriority__C;
#endif

/* noncachedMsmcAlias */
#ifdef ti_omp_utils_OpenMP_noncachedMsmcAlias__D
#define ti_omp_utils_OpenMP_noncachedMsmcAlias (ti_omp_utils_OpenMP_noncachedMsmcAlias__D)
#else
#define ti_omp_utils_OpenMP_noncachedMsmcAlias (ti_omp_utils_OpenMP_noncachedMsmcAlias__C)
typedef xdc_UInt32 CT__ti_omp_utils_OpenMP_noncachedMsmcAlias;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_noncachedMsmcAlias ti_omp_utils_OpenMP_noncachedMsmcAlias__C;
#endif

/* baseIdOfCluster */
#ifdef ti_omp_utils_OpenMP_baseIdOfCluster__D
#define ti_omp_utils_OpenMP_baseIdOfCluster (ti_omp_utils_OpenMP_baseIdOfCluster__D)
#else
#define ti_omp_utils_OpenMP_baseIdOfCluster (ti_omp_utils_OpenMP_baseIdOfCluster__C)
typedef xdc_UInt CT__ti_omp_utils_OpenMP_baseIdOfCluster;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_baseIdOfCluster ti_omp_utils_OpenMP_baseIdOfCluster__C;
#endif

/* enableMemoryConsistency */
#ifdef ti_omp_utils_OpenMP_enableMemoryConsistency__D
#define ti_omp_utils_OpenMP_enableMemoryConsistency (ti_omp_utils_OpenMP_enableMemoryConsistency__D)
#else
#define ti_omp_utils_OpenMP_enableMemoryConsistency (ti_omp_utils_OpenMP_enableMemoryConsistency__C)
typedef xdc_Bool CT__ti_omp_utils_OpenMP_enableMemoryConsistency;
__extern __FAR__ const CT__ti_omp_utils_OpenMP_enableMemoryConsistency ti_omp_utils_OpenMP_enableMemoryConsistency__C;
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_omp_utils_OpenMP_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_omp_utils_OpenMP_Module__startupDone__S, "ti_omp_utils_OpenMP_Module__startupDone")
__extern xdc_Bool ti_omp_utils_OpenMP_Module__startupDone__S( void );

/* createThread__E */
#define ti_omp_utils_OpenMP_createThread ti_omp_utils_OpenMP_createThread__E
xdc__CODESECT(ti_omp_utils_OpenMP_createThread__E, "ti_omp_utils_OpenMP_createThread")
__extern xdc_Void ti_omp_utils_OpenMP_createThread__E( xdc_Fxn fn, xdc_Ptr startData, xdc_SizeT stackSize );
xdc__CODESECT(ti_omp_utils_OpenMP_createThread__F, "ti_omp_utils_OpenMP_createThread")
__extern xdc_Void ti_omp_utils_OpenMP_createThread__F( xdc_Fxn fn, xdc_Ptr startData, xdc_SizeT stackSize );
__extern xdc_Void ti_omp_utils_OpenMP_createThread__R( xdc_Fxn fn, xdc_Ptr startData, xdc_SizeT stackSize );

/* exitThread__E */
#define ti_omp_utils_OpenMP_exitThread ti_omp_utils_OpenMP_exitThread__E
xdc__CODESECT(ti_omp_utils_OpenMP_exitThread__E, "ti_omp_utils_OpenMP_exitThread")
__extern xdc_Void ti_omp_utils_OpenMP_exitThread__E( xdc_Void* arg );
xdc__CODESECT(ti_omp_utils_OpenMP_exitThread__F, "ti_omp_utils_OpenMP_exitThread")
__extern xdc_Void ti_omp_utils_OpenMP_exitThread__F( xdc_Void* arg );
__extern xdc_Void ti_omp_utils_OpenMP_exitThread__R( xdc_Void* arg );

/* mainTaskExit__E */
#define ti_omp_utils_OpenMP_mainTaskExit ti_omp_utils_OpenMP_mainTaskExit__E
xdc__CODESECT(ti_omp_utils_OpenMP_mainTaskExit__E, "ti_omp_utils_OpenMP_mainTaskExit")
__extern xdc_Void ti_omp_utils_OpenMP_mainTaskExit__E( xdc_Void* arg );
xdc__CODESECT(ti_omp_utils_OpenMP_mainTaskExit__F, "ti_omp_utils_OpenMP_mainTaskExit")
__extern xdc_Void ti_omp_utils_OpenMP_mainTaskExit__F( xdc_Void* arg );
__extern xdc_Void ti_omp_utils_OpenMP_mainTaskExit__R( xdc_Void* arg );

/* useSharedHeap__E */
#define ti_omp_utils_OpenMP_useSharedHeap ti_omp_utils_OpenMP_useSharedHeap__E
xdc__CODESECT(ti_omp_utils_OpenMP_useSharedHeap__E, "ti_omp_utils_OpenMP_useSharedHeap")
__extern xdc_Bool ti_omp_utils_OpenMP_useSharedHeap__E( void );
xdc__CODESECT(ti_omp_utils_OpenMP_useSharedHeap__F, "ti_omp_utils_OpenMP_useSharedHeap")
__extern xdc_Bool ti_omp_utils_OpenMP_useSharedHeap__F( void );
__extern xdc_Bool ti_omp_utils_OpenMP_useSharedHeap__R( void );

/* getTimerCount__E */
#define ti_omp_utils_OpenMP_getTimerCount ti_omp_utils_OpenMP_getTimerCount__E
xdc__CODESECT(ti_omp_utils_OpenMP_getTimerCount__E, "ti_omp_utils_OpenMP_getTimerCount")
__extern xdc_UInt32 ti_omp_utils_OpenMP_getTimerCount__E( void );
xdc__CODESECT(ti_omp_utils_OpenMP_getTimerCount__F, "ti_omp_utils_OpenMP_getTimerCount")
__extern xdc_UInt32 ti_omp_utils_OpenMP_getTimerCount__F( void );
__extern xdc_UInt32 ti_omp_utils_OpenMP_getTimerCount__R( void );

/* getTimerFreq__E */
#define ti_omp_utils_OpenMP_getTimerFreq ti_omp_utils_OpenMP_getTimerFreq__E
xdc__CODESECT(ti_omp_utils_OpenMP_getTimerFreq__E, "ti_omp_utils_OpenMP_getTimerFreq")
__extern xdc_Void ti_omp_utils_OpenMP_getTimerFreq__E( xdc_runtime_Types_FreqHz* freq );
xdc__CODESECT(ti_omp_utils_OpenMP_getTimerFreq__F, "ti_omp_utils_OpenMP_getTimerFreq")
__extern xdc_Void ti_omp_utils_OpenMP_getTimerFreq__F( xdc_runtime_Types_FreqHz* freq );
__extern xdc_Void ti_omp_utils_OpenMP_getTimerFreq__R( xdc_runtime_Types_FreqHz* freq );

/* masterTask__I */
#define ti_omp_utils_OpenMP_masterTask ti_omp_utils_OpenMP_masterTask__I
xdc__CODESECT(ti_omp_utils_OpenMP_masterTask__I, "ti_omp_utils_OpenMP_masterTask")
__extern xdc_Void ti_omp_utils_OpenMP_masterTask__I( xdc_UArg arg0, xdc_UArg arg1 );

/* threadSpawnLoop__I */
#define ti_omp_utils_OpenMP_threadSpawnLoop ti_omp_utils_OpenMP_threadSpawnLoop__I
xdc__CODESECT(ti_omp_utils_OpenMP_threadSpawnLoop__I, "ti_omp_utils_OpenMP_threadSpawnLoop")
__extern xdc_Void ti_omp_utils_OpenMP_threadSpawnLoop__I( void );

/* mainTask__I */
#define ti_omp_utils_OpenMP_mainTask ti_omp_utils_OpenMP_mainTask__I
xdc__CODESECT(ti_omp_utils_OpenMP_mainTask__I, "ti_omp_utils_OpenMP_mainTask")
__extern xdc_Void ti_omp_utils_OpenMP_mainTask__I( xdc_UArg arg0, xdc_UArg arg1 );

/* setProcId__I */
#define ti_omp_utils_OpenMP_setProcId ti_omp_utils_OpenMP_setProcId__I
xdc__CODESECT(ti_omp_utils_OpenMP_setProcId__I, "ti_omp_utils_OpenMP_setProcId")
__extern xdc_Void ti_omp_utils_OpenMP_setProcId__I( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_omp_utils_OpenMP_Module_startupDone() ti_omp_utils_OpenMP_Module__startupDone__S()

/* Object_heap */
#define ti_omp_utils_OpenMP_Object_heap() ti_omp_utils_OpenMP_Object__heap__C

/* Module_heap */
#define ti_omp_utils_OpenMP_Module_heap() ti_omp_utils_OpenMP_Object__heap__C

/* Module_id */
static inline CT__ti_omp_utils_OpenMP_Module__id ti_omp_utils_OpenMP_Module_id( void ) 
{
    return ti_omp_utils_OpenMP_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_omp_utils_OpenMP_Module_hasMask( void ) 
{
    return ti_omp_utils_OpenMP_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_omp_utils_OpenMP_Module_getMask( void ) 
{
    return ti_omp_utils_OpenMP_Module__diagsMask__C != NULL ? *ti_omp_utils_OpenMP_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_omp_utils_OpenMP_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_omp_utils_OpenMP_Module__diagsMask__C != NULL) *ti_omp_utils_OpenMP_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_omp_utils_OpenMP__top__
#undef __nested__
#endif

#endif /* ti_omp_utils_OpenMP__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_omp_utils_OpenMP__internalaccess))

#ifndef ti_omp_utils_OpenMP__include_state
#define ti_omp_utils_OpenMP__include_state

/* Module_State */
struct ti_omp_utils_OpenMP_Module_State {
    ti_omp_utils_SemaphoreMP_Handle masterTaskSem;
    xdc_UInt32 threadSpawnQ;
    xdc_Bool useSharedHeap;
    ti_sdo_ipc_GateMP_Handle gate;
    ti_sysbios_timers_timer64_Timer_Handle sharedTimer;
};

/* Module__state__V */
extern struct ti_omp_utils_OpenMP_Module_State__ ti_omp_utils_OpenMP_Module__state__V;

#endif /* ti_omp_utils_OpenMP__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_omp_utils_OpenMP__nolocalnames)

#ifndef ti_omp_utils_OpenMP__localnames__done
#define ti_omp_utils_OpenMP__localnames__done

/* module prefix */
#define OpenMP_FuncPtr ti_omp_utils_OpenMP_FuncPtr
#define OpenMP_Module_State ti_omp_utils_OpenMP_Module_State
#define OpenMP_masterFxn ti_omp_utils_OpenMP_masterFxn
#define OpenMP_singleThreadPerCore ti_omp_utils_OpenMP_singleThreadPerCore
#define OpenMP_qmssInit ti_omp_utils_OpenMP_qmssInit
#define OpenMP_qmssMemRegion ti_omp_utils_OpenMP_qmssMemRegion
#define OpenMP_qmssStartIndex ti_omp_utils_OpenMP_qmssStartIndex
#define OpenMP_qmssDestQueueNum ti_omp_utils_OpenMP_qmssDestQueueNum
#define OpenMP_stackSize ti_omp_utils_OpenMP_stackSize
#define OpenMP_ipcHeapSize ti_omp_utils_OpenMP_ipcHeapSize
#define OpenMP_stackRegionId ti_omp_utils_OpenMP_stackRegionId
#define OpenMP_internalOsal ti_omp_utils_OpenMP_internalOsal
#define OpenMP_cppiHwSem ti_omp_utils_OpenMP_cppiHwSem
#define OpenMP_qmssHwSem ti_omp_utils_OpenMP_qmssHwSem
#define OpenMP_ompHwSem ti_omp_utils_OpenMP_ompHwSem
#define OpenMP_mpaxIndex ti_omp_utils_OpenMP_mpaxIndex
#define OpenMP_mpaxRaddr ti_omp_utils_OpenMP_mpaxRaddr
#define OpenMP_autoDnldCore ti_omp_utils_OpenMP_autoDnldCore
#define OpenMP_threadPriority ti_omp_utils_OpenMP_threadPriority
#define OpenMP_noncachedMsmcAlias ti_omp_utils_OpenMP_noncachedMsmcAlias
#define OpenMP_baseIdOfCluster ti_omp_utils_OpenMP_baseIdOfCluster
#define OpenMP_enableMemoryConsistency ti_omp_utils_OpenMP_enableMemoryConsistency
#define OpenMP_createThread ti_omp_utils_OpenMP_createThread
#define OpenMP_exitThread ti_omp_utils_OpenMP_exitThread
#define OpenMP_mainTaskExit ti_omp_utils_OpenMP_mainTaskExit
#define OpenMP_useSharedHeap ti_omp_utils_OpenMP_useSharedHeap
#define OpenMP_getTimerCount ti_omp_utils_OpenMP_getTimerCount
#define OpenMP_getTimerFreq ti_omp_utils_OpenMP_getTimerFreq
#define OpenMP_Module_name ti_omp_utils_OpenMP_Module_name
#define OpenMP_Module_id ti_omp_utils_OpenMP_Module_id
#define OpenMP_Module_startup ti_omp_utils_OpenMP_Module_startup
#define OpenMP_Module_startupDone ti_omp_utils_OpenMP_Module_startupDone
#define OpenMP_Module_hasMask ti_omp_utils_OpenMP_Module_hasMask
#define OpenMP_Module_getMask ti_omp_utils_OpenMP_Module_getMask
#define OpenMP_Module_setMask ti_omp_utils_OpenMP_Module_setMask
#define OpenMP_Object_heap ti_omp_utils_OpenMP_Object_heap
#define OpenMP_Module_heap ti_omp_utils_OpenMP_Module_heap

#endif /* ti_omp_utils_OpenMP__localnames__done */
#endif

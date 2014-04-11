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
 *     CREATE ARGS
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
 *     FUNCTION DECLARATIONS
 *     FUNCTION SELECTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_omp_utils_SemaphoreMP__include
#define ti_omp_utils_SemaphoreMP__include

#ifndef __nested__
#define __nested__
#define ti_omp_utils_SemaphoreMP__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_omp_utils_SemaphoreMP___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/omp/utils/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <ti/sdo/ipc/GateMP.h>
#include <ti/sdo/ipc/SharedRegion.h>
#include <ti/sdo/utils/NameServer.h>
#include <ti/omp/utils/ThreadLocal.h>
#include <ti/sdo/ipc/Ipc.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Assert.h>
#include <ti/sdo/ipc/ListMP.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Mode */
enum ti_omp_utils_SemaphoreMP_Mode {
    ti_omp_utils_SemaphoreMP_Mode_COUNTING,
    ti_omp_utils_SemaphoreMP_Mode_BINARY
};
typedef enum ti_omp_utils_SemaphoreMP_Mode ti_omp_utils_SemaphoreMP_Mode;


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_omp_utils_SemaphoreMP_Args__create {
    xdc_Int count;
} ti_omp_utils_SemaphoreMP_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* CREATED */
#define ti_omp_utils_SemaphoreMP_CREATED (0xabcd1234)

/* Attrs */
struct ti_omp_utils_SemaphoreMP_Attrs {
    xdc_Bits32 status;
    ti_sdo_ipc_SharedRegion_SRPtr gateMPAddr;
    xdc_Bits16 count;
    xdc_Bits16 mode;
};

/* PendElem */
struct ti_omp_utils_SemaphoreMP_PendElem {
    ti_sdo_ipc_ListMP_Elem elem;
    xdc_Bits16 procId;
    xdc_Bits32 task;
};


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_omp_utils_SemaphoreMP_Module__diagsEnabled;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__diagsEnabled ti_omp_utils_SemaphoreMP_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_omp_utils_SemaphoreMP_Module__diagsIncluded;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__diagsIncluded ti_omp_utils_SemaphoreMP_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_omp_utils_SemaphoreMP_Module__diagsMask;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__diagsMask ti_omp_utils_SemaphoreMP_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_omp_utils_SemaphoreMP_Module__gateObj;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__gateObj ti_omp_utils_SemaphoreMP_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_omp_utils_SemaphoreMP_Module__gatePrms;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__gatePrms ti_omp_utils_SemaphoreMP_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_omp_utils_SemaphoreMP_Module__id;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__id ti_omp_utils_SemaphoreMP_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_omp_utils_SemaphoreMP_Module__loggerDefined;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__loggerDefined ti_omp_utils_SemaphoreMP_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_omp_utils_SemaphoreMP_Module__loggerObj;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__loggerObj ti_omp_utils_SemaphoreMP_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn0;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn0 ti_omp_utils_SemaphoreMP_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn1;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn1 ti_omp_utils_SemaphoreMP_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn2;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn2 ti_omp_utils_SemaphoreMP_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn4;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn4 ti_omp_utils_SemaphoreMP_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn8;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__loggerFxn8 ti_omp_utils_SemaphoreMP_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_omp_utils_SemaphoreMP_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Module__startupDoneFxn ti_omp_utils_SemaphoreMP_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_omp_utils_SemaphoreMP_Object__count;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Object__count ti_omp_utils_SemaphoreMP_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_omp_utils_SemaphoreMP_Object__heap;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Object__heap ti_omp_utils_SemaphoreMP_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_omp_utils_SemaphoreMP_Object__sizeof;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Object__sizeof ti_omp_utils_SemaphoreMP_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_omp_utils_SemaphoreMP_Object__table;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_Object__table ti_omp_utils_SemaphoreMP_Object__table__C;

/* A_invTimeout */
#define ti_omp_utils_SemaphoreMP_A_invTimeout (ti_omp_utils_SemaphoreMP_A_invTimeout__C)
typedef xdc_runtime_Assert_Id CT__ti_omp_utils_SemaphoreMP_A_invTimeout;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_A_invTimeout ti_omp_utils_SemaphoreMP_A_invTimeout__C;

/* A_badContext */
#define ti_omp_utils_SemaphoreMP_A_badContext (ti_omp_utils_SemaphoreMP_A_badContext__C)
typedef xdc_runtime_Assert_Id CT__ti_omp_utils_SemaphoreMP_A_badContext;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_A_badContext ti_omp_utils_SemaphoreMP_A_badContext__C;

/* notifyEventId */
#ifdef ti_omp_utils_SemaphoreMP_notifyEventId__D
#define ti_omp_utils_SemaphoreMP_notifyEventId (ti_omp_utils_SemaphoreMP_notifyEventId__D)
#else
#define ti_omp_utils_SemaphoreMP_notifyEventId (ti_omp_utils_SemaphoreMP_notifyEventId__C)
typedef xdc_UInt CT__ti_omp_utils_SemaphoreMP_notifyEventId;
__extern __FAR__ const CT__ti_omp_utils_SemaphoreMP_notifyEventId ti_omp_utils_SemaphoreMP_notifyEventId__C;
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_omp_utils_SemaphoreMP_Params {
    size_t __size;
    const void* __self;
    void* __fxns;
    xdc_runtime_IInstance_Params* instance;
    ti_omp_utils_SemaphoreMP_Mode mode;
    ti_sdo_ipc_GateMP_Handle gate;
    xdc_Bool openFlag;
    xdc_Ptr sharedAddr;
    xdc_String name;
    xdc_UInt16 regionId;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_omp_utils_SemaphoreMP_Struct {
    ti_omp_utils_SemaphoreMP_Attrs* __f0;
    ti_omp_utils_SemaphoreMP_Mode __f1;
    ti_sdo_ipc_GateMP_Handle __f2;
    ti_sdo_ipc_Ipc_ObjType __f3;
    xdc_Ptr __f4;
    xdc_Bool __f5;
    xdc_UInt16 __f6;
    xdc_SizeT __f7;
    ti_sdo_ipc_ListMP_Handle __f8;
    xdc_UInt32 __f9;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_omp_utils_SemaphoreMP_Module_startup( state ) (-1)

/* Instance_init__F */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Instance_init__F, "ti_omp_utils_SemaphoreMP_Instance_init")
__extern int ti_omp_utils_SemaphoreMP_Instance_init__F( ti_omp_utils_SemaphoreMP_Object*, xdc_Int count, const ti_omp_utils_SemaphoreMP_Params*, xdc_runtime_Error_Block* );

/* Instance_finalize__F */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Instance_finalize__F, "ti_omp_utils_SemaphoreMP_Instance_finalize")
__extern void ti_omp_utils_SemaphoreMP_Instance_finalize__F( ti_omp_utils_SemaphoreMP_Object* , int );

/* Instance_init__R */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Instance_init__R, "ti_omp_utils_SemaphoreMP_Instance_init")
__extern int ti_omp_utils_SemaphoreMP_Instance_init__R( ti_omp_utils_SemaphoreMP_Object*, xdc_Int count, const ti_omp_utils_SemaphoreMP_Params*, xdc_runtime_Error_Block* );

/* Instance_finalize__R */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Instance_finalize__R, "ti_omp_utils_SemaphoreMP_Instance_finalize")
__extern void ti_omp_utils_SemaphoreMP_Instance_finalize__R( ti_omp_utils_SemaphoreMP_Object* , int );

/* Handle__label__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Handle__label__S, "ti_omp_utils_SemaphoreMP_Handle__label")
__extern xdc_runtime_Types_Label* ti_omp_utils_SemaphoreMP_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Module__startupDone__S, "ti_omp_utils_SemaphoreMP_Module__startupDone")
__extern xdc_Bool ti_omp_utils_SemaphoreMP_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Object__create__S, "ti_omp_utils_SemaphoreMP_Object__create")
__extern xdc_Ptr ti_omp_utils_SemaphoreMP_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar* __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb );

/* Object__delete__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Object__delete__S, "ti_omp_utils_SemaphoreMP_Object__delete")
__extern xdc_Void ti_omp_utils_SemaphoreMP_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Object__destruct__S, "ti_omp_utils_SemaphoreMP_Object__destruct")
__extern xdc_Void ti_omp_utils_SemaphoreMP_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Object__get__S, "ti_omp_utils_SemaphoreMP_Object__get")
__extern xdc_Ptr ti_omp_utils_SemaphoreMP_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Object__first__S, "ti_omp_utils_SemaphoreMP_Object__first")
__extern xdc_Ptr ti_omp_utils_SemaphoreMP_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Object__next__S, "ti_omp_utils_SemaphoreMP_Object__next")
__extern xdc_Ptr ti_omp_utils_SemaphoreMP_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_omp_utils_SemaphoreMP_Params__init__S, "ti_omp_utils_SemaphoreMP_Params__init")
__extern xdc_Void ti_omp_utils_SemaphoreMP_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz );

/* open__E */
#define ti_omp_utils_SemaphoreMP_open ti_omp_utils_SemaphoreMP_open__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_open__E, "ti_omp_utils_SemaphoreMP_open")
__extern xdc_Int ti_omp_utils_SemaphoreMP_open__E( xdc_String name, ti_omp_utils_SemaphoreMP_Handle* handlePtr );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_open__F, "ti_omp_utils_SemaphoreMP_open")
__extern xdc_Int ti_omp_utils_SemaphoreMP_open__F( xdc_String name, ti_omp_utils_SemaphoreMP_Handle* handlePtr );
__extern xdc_Int ti_omp_utils_SemaphoreMP_open__R( xdc_String name, ti_omp_utils_SemaphoreMP_Handle* handlePtr );

/* openByAddr__E */
#define ti_omp_utils_SemaphoreMP_openByAddr ti_omp_utils_SemaphoreMP_openByAddr__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_openByAddr__E, "ti_omp_utils_SemaphoreMP_openByAddr")
__extern xdc_Int ti_omp_utils_SemaphoreMP_openByAddr__E( xdc_Ptr sharedAddr, ti_omp_utils_SemaphoreMP_Handle* handlePtr );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_openByAddr__F, "ti_omp_utils_SemaphoreMP_openByAddr")
__extern xdc_Int ti_omp_utils_SemaphoreMP_openByAddr__F( xdc_Ptr sharedAddr, ti_omp_utils_SemaphoreMP_Handle* handlePtr );
__extern xdc_Int ti_omp_utils_SemaphoreMP_openByAddr__R( xdc_Ptr sharedAddr, ti_omp_utils_SemaphoreMP_Handle* handlePtr );

/* close__E */
#define ti_omp_utils_SemaphoreMP_close ti_omp_utils_SemaphoreMP_close__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_close__E, "ti_omp_utils_SemaphoreMP_close")
__extern xdc_Void ti_omp_utils_SemaphoreMP_close__E( ti_omp_utils_SemaphoreMP_Handle* handle );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_close__F, "ti_omp_utils_SemaphoreMP_close")
__extern xdc_Void ti_omp_utils_SemaphoreMP_close__F( ti_omp_utils_SemaphoreMP_Handle* handle );
__extern xdc_Void ti_omp_utils_SemaphoreMP_close__R( ti_omp_utils_SemaphoreMP_Handle* handle );

/* sharedMemReq__E */
#define ti_omp_utils_SemaphoreMP_sharedMemReq ti_omp_utils_SemaphoreMP_sharedMemReq__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_sharedMemReq__E, "ti_omp_utils_SemaphoreMP_sharedMemReq")
__extern xdc_SizeT ti_omp_utils_SemaphoreMP_sharedMemReq__E( const ti_omp_utils_SemaphoreMP_Params* params );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_sharedMemReq__F, "ti_omp_utils_SemaphoreMP_sharedMemReq")
__extern xdc_SizeT ti_omp_utils_SemaphoreMP_sharedMemReq__F( const ti_omp_utils_SemaphoreMP_Params* params );
__extern xdc_SizeT ti_omp_utils_SemaphoreMP_sharedMemReq__R( const ti_omp_utils_SemaphoreMP_Params* params );

/* start__E */
#define ti_omp_utils_SemaphoreMP_start ti_omp_utils_SemaphoreMP_start__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_start__E, "ti_omp_utils_SemaphoreMP_start")
__extern xdc_Void ti_omp_utils_SemaphoreMP_start__E( void );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_start__F, "ti_omp_utils_SemaphoreMP_start")
__extern xdc_Void ti_omp_utils_SemaphoreMP_start__F( void );
__extern xdc_Void ti_omp_utils_SemaphoreMP_start__R( void );

/* getCount__E */
#define ti_omp_utils_SemaphoreMP_getCount ti_omp_utils_SemaphoreMP_getCount__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_getCount__E, "ti_omp_utils_SemaphoreMP_getCount")
__extern xdc_Int ti_omp_utils_SemaphoreMP_getCount__E( ti_omp_utils_SemaphoreMP_Handle __inst );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_getCount__F, "ti_omp_utils_SemaphoreMP_getCount")
__extern xdc_Int ti_omp_utils_SemaphoreMP_getCount__F( ti_omp_utils_SemaphoreMP_Object* __inst );
__extern xdc_Int ti_omp_utils_SemaphoreMP_getCount__R( ti_omp_utils_SemaphoreMP_Handle __inst );

/* pend__E */
#define ti_omp_utils_SemaphoreMP_pend ti_omp_utils_SemaphoreMP_pend__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_pend__E, "ti_omp_utils_SemaphoreMP_pend")
__extern xdc_Bool ti_omp_utils_SemaphoreMP_pend__E( ti_omp_utils_SemaphoreMP_Handle __inst );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_pend__F, "ti_omp_utils_SemaphoreMP_pend")
__extern xdc_Bool ti_omp_utils_SemaphoreMP_pend__F( ti_omp_utils_SemaphoreMP_Object* __inst );
__extern xdc_Bool ti_omp_utils_SemaphoreMP_pend__R( ti_omp_utils_SemaphoreMP_Handle __inst );

/* post__E */
#define ti_omp_utils_SemaphoreMP_post ti_omp_utils_SemaphoreMP_post__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_post__E, "ti_omp_utils_SemaphoreMP_post")
__extern xdc_Void ti_omp_utils_SemaphoreMP_post__E( ti_omp_utils_SemaphoreMP_Handle __inst );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_post__F, "ti_omp_utils_SemaphoreMP_post")
__extern xdc_Void ti_omp_utils_SemaphoreMP_post__F( ti_omp_utils_SemaphoreMP_Object* __inst );
__extern xdc_Void ti_omp_utils_SemaphoreMP_post__R( ti_omp_utils_SemaphoreMP_Handle __inst );

/* reset__E */
#define ti_omp_utils_SemaphoreMP_reset ti_omp_utils_SemaphoreMP_reset__E
xdc__CODESECT(ti_omp_utils_SemaphoreMP_reset__E, "ti_omp_utils_SemaphoreMP_reset")
__extern xdc_Void ti_omp_utils_SemaphoreMP_reset__E( ti_omp_utils_SemaphoreMP_Handle __inst );
xdc__CODESECT(ti_omp_utils_SemaphoreMP_reset__F, "ti_omp_utils_SemaphoreMP_reset")
__extern xdc_Void ti_omp_utils_SemaphoreMP_reset__F( ti_omp_utils_SemaphoreMP_Object* __inst );
__extern xdc_Void ti_omp_utils_SemaphoreMP_reset__R( ti_omp_utils_SemaphoreMP_Handle __inst );

/* cbFxn__I */
#define ti_omp_utils_SemaphoreMP_cbFxn ti_omp_utils_SemaphoreMP_cbFxn__I
xdc__CODESECT(ti_omp_utils_SemaphoreMP_cbFxn__I, "ti_omp_utils_SemaphoreMP_cbFxn")
__extern xdc_Void ti_omp_utils_SemaphoreMP_cbFxn__I( xdc_UInt16 procId, xdc_UInt16 lineId, xdc_UInt32 eventId, xdc_UArg arg, xdc_UInt32 payload );

/* registerEvent__I */
#define ti_omp_utils_SemaphoreMP_registerEvent ti_omp_utils_SemaphoreMP_registerEvent__I
xdc__CODESECT(ti_omp_utils_SemaphoreMP_registerEvent__I, "ti_omp_utils_SemaphoreMP_registerEvent")
__extern xdc_Int ti_omp_utils_SemaphoreMP_registerEvent__I( xdc_UArg arg, xdc_UInt16 procId );


/*
 * ======== FUNCTION SELECTORS ========
 */

/* getCount_{FxnT,fxnP} */
typedef xdc_Int (*ti_omp_utils_SemaphoreMP_getCount_FxnT)(void*);
static inline ti_omp_utils_SemaphoreMP_getCount_FxnT ti_omp_utils_SemaphoreMP_getCount_fxnP( void )
{
    return (ti_omp_utils_SemaphoreMP_getCount_FxnT)ti_omp_utils_SemaphoreMP_getCount; 
}

/* pend_{FxnT,fxnP} */
typedef xdc_Bool (*ti_omp_utils_SemaphoreMP_pend_FxnT)(void*);
static inline ti_omp_utils_SemaphoreMP_pend_FxnT ti_omp_utils_SemaphoreMP_pend_fxnP( void )
{
    return (ti_omp_utils_SemaphoreMP_pend_FxnT)ti_omp_utils_SemaphoreMP_pend; 
}

/* post_{FxnT,fxnP} */
typedef xdc_Void (*ti_omp_utils_SemaphoreMP_post_FxnT)(void*);
static inline ti_omp_utils_SemaphoreMP_post_FxnT ti_omp_utils_SemaphoreMP_post_fxnP( void )
{
    return (ti_omp_utils_SemaphoreMP_post_FxnT)ti_omp_utils_SemaphoreMP_post; 
}

/* reset_{FxnT,fxnP} */
typedef xdc_Void (*ti_omp_utils_SemaphoreMP_reset_FxnT)(void*);
static inline ti_omp_utils_SemaphoreMP_reset_FxnT ti_omp_utils_SemaphoreMP_reset_fxnP( void )
{
    return (ti_omp_utils_SemaphoreMP_reset_FxnT)ti_omp_utils_SemaphoreMP_reset; 
}


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_omp_utils_SemaphoreMP_Module_startupDone() ti_omp_utils_SemaphoreMP_Module__startupDone__S()

/* Object_heap */
#define ti_omp_utils_SemaphoreMP_Object_heap() ti_omp_utils_SemaphoreMP_Object__heap__C

/* Module_heap */
#define ti_omp_utils_SemaphoreMP_Module_heap() ti_omp_utils_SemaphoreMP_Object__heap__C

/* Module_id */
static inline CT__ti_omp_utils_SemaphoreMP_Module__id ti_omp_utils_SemaphoreMP_Module_id( void ) 
{
    return ti_omp_utils_SemaphoreMP_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_omp_utils_SemaphoreMP_Module_hasMask( void ) 
{
    return ti_omp_utils_SemaphoreMP_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_omp_utils_SemaphoreMP_Module_getMask( void ) 
{
    return ti_omp_utils_SemaphoreMP_Module__diagsMask__C != NULL ? *ti_omp_utils_SemaphoreMP_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_omp_utils_SemaphoreMP_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_omp_utils_SemaphoreMP_Module__diagsMask__C != NULL) *ti_omp_utils_SemaphoreMP_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_omp_utils_SemaphoreMP_Params_init( ti_omp_utils_SemaphoreMP_Params* prms ) 
{
    if (prms) {
        ti_omp_utils_SemaphoreMP_Params__init__S(prms, 0, sizeof(ti_omp_utils_SemaphoreMP_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_omp_utils_SemaphoreMP_Params_copy( ti_omp_utils_SemaphoreMP_Params* dst, const ti_omp_utils_SemaphoreMP_Params* src ) 
{
    if (dst) {
        ti_omp_utils_SemaphoreMP_Params__init__S(dst, (xdc_Ptr)src, sizeof(ti_omp_utils_SemaphoreMP_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_omp_utils_SemaphoreMP_Object_count() ti_omp_utils_SemaphoreMP_Object__count__C

/* Object_sizeof */
#define ti_omp_utils_SemaphoreMP_Object_sizeof() ti_omp_utils_SemaphoreMP_Object__sizeof__C

/* Object_get */
static inline ti_omp_utils_SemaphoreMP_Handle ti_omp_utils_SemaphoreMP_Object_get( ti_omp_utils_SemaphoreMP_Instance_State* oarr, int i ) 
{
    return (ti_omp_utils_SemaphoreMP_Handle)ti_omp_utils_SemaphoreMP_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_omp_utils_SemaphoreMP_Handle ti_omp_utils_SemaphoreMP_Object_first( void )
{
    return (ti_omp_utils_SemaphoreMP_Handle)ti_omp_utils_SemaphoreMP_Object__first__S();
}

/* Object_next */
static inline ti_omp_utils_SemaphoreMP_Handle ti_omp_utils_SemaphoreMP_Object_next( ti_omp_utils_SemaphoreMP_Object* obj )
{
    return (ti_omp_utils_SemaphoreMP_Handle)ti_omp_utils_SemaphoreMP_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label* ti_omp_utils_SemaphoreMP_Handle_label( ti_omp_utils_SemaphoreMP_Handle inst, xdc_runtime_Types_Label* lab )
{
    return ti_omp_utils_SemaphoreMP_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline String ti_omp_utils_SemaphoreMP_Handle_name( ti_omp_utils_SemaphoreMP_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_omp_utils_SemaphoreMP_Handle__label__S(inst, &lab)->iname;
}

/* create */
static inline ti_omp_utils_SemaphoreMP_Handle ti_omp_utils_SemaphoreMP_create( xdc_Int count, const ti_omp_utils_SemaphoreMP_Params* __prms, xdc_runtime_Error_Block* __eb )
{
    ti_omp_utils_SemaphoreMP_Args__create __args;
    __args.count = count;
    return (ti_omp_utils_SemaphoreMP_Handle)ti_omp_utils_SemaphoreMP_Object__create__S(0, 0, &__args, (const xdc_UChar*)__prms, sizeof(ti_omp_utils_SemaphoreMP_Params), __eb);
}

/* construct */
static inline void ti_omp_utils_SemaphoreMP_construct( ti_omp_utils_SemaphoreMP_Struct* __obj, xdc_Int count, const ti_omp_utils_SemaphoreMP_Params* __prms, xdc_runtime_Error_Block* __eb )
{
    ti_omp_utils_SemaphoreMP_Args__create __args;
    __args.count = count;
    ti_omp_utils_SemaphoreMP_Object__create__S(__obj, sizeof (ti_omp_utils_SemaphoreMP_Struct), &__args, (const xdc_UChar*)__prms, sizeof(ti_omp_utils_SemaphoreMP_Params), __eb);
}

/* delete */
static inline void ti_omp_utils_SemaphoreMP_delete( ti_omp_utils_SemaphoreMP_Handle* instp )
{
    ti_omp_utils_SemaphoreMP_Object__delete__S(instp);
}

/* destruct */
static inline void ti_omp_utils_SemaphoreMP_destruct( ti_omp_utils_SemaphoreMP_Struct* obj )
{
    ti_omp_utils_SemaphoreMP_Object__destruct__S(obj);
}

/* handle */
static inline ti_omp_utils_SemaphoreMP_Handle ti_omp_utils_SemaphoreMP_handle( ti_omp_utils_SemaphoreMP_Struct* str )
{
    return (ti_omp_utils_SemaphoreMP_Handle)str;
}

/* struct */
static inline ti_omp_utils_SemaphoreMP_Struct* ti_omp_utils_SemaphoreMP_struct( ti_omp_utils_SemaphoreMP_Handle inst )
{
    return (ti_omp_utils_SemaphoreMP_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_omp_utils_SemaphoreMP__top__
#undef __nested__
#endif

#endif /* ti_omp_utils_SemaphoreMP__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_omp_utils_SemaphoreMP__internalaccess))

#ifndef ti_omp_utils_SemaphoreMP__include_state
#define ti_omp_utils_SemaphoreMP__include_state

/* Module_State */
struct ti_omp_utils_SemaphoreMP_Module_State {
    ti_sdo_utils_NameServer_Handle nameServer;
    ti_omp_utils_ThreadLocal_Key pendElemKey;
};

/* Module__state__V */
extern struct ti_omp_utils_SemaphoreMP_Module_State__ ti_omp_utils_SemaphoreMP_Module__state__V;

/* Object */
struct ti_omp_utils_SemaphoreMP_Object {
    ti_omp_utils_SemaphoreMP_Attrs* attrs;
    ti_omp_utils_SemaphoreMP_Mode mode;
    ti_sdo_ipc_GateMP_Handle gate;
    ti_sdo_ipc_Ipc_ObjType objType;
    xdc_Ptr nsKey;
    xdc_Bool cacheEnabled;
    xdc_UInt16 regionId;
    xdc_SizeT allocSize;
    ti_sdo_ipc_ListMP_Handle pendQ;
    xdc_UInt32 QMSS_sem_Hnd;
};

#endif /* ti_omp_utils_SemaphoreMP__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_omp_utils_SemaphoreMP__nolocalnames)

#ifndef ti_omp_utils_SemaphoreMP__localnames__done
#define ti_omp_utils_SemaphoreMP__localnames__done

/* module prefix */
#define SemaphoreMP_Instance ti_omp_utils_SemaphoreMP_Instance
#define SemaphoreMP_Handle ti_omp_utils_SemaphoreMP_Handle
#define SemaphoreMP_Module ti_omp_utils_SemaphoreMP_Module
#define SemaphoreMP_Object ti_omp_utils_SemaphoreMP_Object
#define SemaphoreMP_Struct ti_omp_utils_SemaphoreMP_Struct
#define SemaphoreMP_Mode ti_omp_utils_SemaphoreMP_Mode
#define SemaphoreMP_CREATED ti_omp_utils_SemaphoreMP_CREATED
#define SemaphoreMP_Attrs ti_omp_utils_SemaphoreMP_Attrs
#define SemaphoreMP_PendElem ti_omp_utils_SemaphoreMP_PendElem
#define SemaphoreMP_Instance_State ti_omp_utils_SemaphoreMP_Instance_State
#define SemaphoreMP_Module_State ti_omp_utils_SemaphoreMP_Module_State
#define SemaphoreMP_Mode_COUNTING ti_omp_utils_SemaphoreMP_Mode_COUNTING
#define SemaphoreMP_Mode_BINARY ti_omp_utils_SemaphoreMP_Mode_BINARY
#define SemaphoreMP_A_invTimeout ti_omp_utils_SemaphoreMP_A_invTimeout
#define SemaphoreMP_A_badContext ti_omp_utils_SemaphoreMP_A_badContext
#define SemaphoreMP_notifyEventId ti_omp_utils_SemaphoreMP_notifyEventId
#define SemaphoreMP_Params ti_omp_utils_SemaphoreMP_Params
#define SemaphoreMP_open ti_omp_utils_SemaphoreMP_open
#define SemaphoreMP_openByAddr ti_omp_utils_SemaphoreMP_openByAddr
#define SemaphoreMP_close ti_omp_utils_SemaphoreMP_close
#define SemaphoreMP_sharedMemReq ti_omp_utils_SemaphoreMP_sharedMemReq
#define SemaphoreMP_start ti_omp_utils_SemaphoreMP_start
#define SemaphoreMP_getCount ti_omp_utils_SemaphoreMP_getCount
#define SemaphoreMP_getCount_fxnP ti_omp_utils_SemaphoreMP_getCount_fxnP
#define SemaphoreMP_getCount_FxnT ti_omp_utils_SemaphoreMP_getCount_FxnT
#define SemaphoreMP_pend ti_omp_utils_SemaphoreMP_pend
#define SemaphoreMP_pend_fxnP ti_omp_utils_SemaphoreMP_pend_fxnP
#define SemaphoreMP_pend_FxnT ti_omp_utils_SemaphoreMP_pend_FxnT
#define SemaphoreMP_post ti_omp_utils_SemaphoreMP_post
#define SemaphoreMP_post_fxnP ti_omp_utils_SemaphoreMP_post_fxnP
#define SemaphoreMP_post_FxnT ti_omp_utils_SemaphoreMP_post_FxnT
#define SemaphoreMP_reset ti_omp_utils_SemaphoreMP_reset
#define SemaphoreMP_reset_fxnP ti_omp_utils_SemaphoreMP_reset_fxnP
#define SemaphoreMP_reset_FxnT ti_omp_utils_SemaphoreMP_reset_FxnT
#define SemaphoreMP_Module_name ti_omp_utils_SemaphoreMP_Module_name
#define SemaphoreMP_Module_id ti_omp_utils_SemaphoreMP_Module_id
#define SemaphoreMP_Module_startup ti_omp_utils_SemaphoreMP_Module_startup
#define SemaphoreMP_Module_startupDone ti_omp_utils_SemaphoreMP_Module_startupDone
#define SemaphoreMP_Module_hasMask ti_omp_utils_SemaphoreMP_Module_hasMask
#define SemaphoreMP_Module_getMask ti_omp_utils_SemaphoreMP_Module_getMask
#define SemaphoreMP_Module_setMask ti_omp_utils_SemaphoreMP_Module_setMask
#define SemaphoreMP_Object_heap ti_omp_utils_SemaphoreMP_Object_heap
#define SemaphoreMP_Module_heap ti_omp_utils_SemaphoreMP_Module_heap
#define SemaphoreMP_construct ti_omp_utils_SemaphoreMP_construct
#define SemaphoreMP_create ti_omp_utils_SemaphoreMP_create
#define SemaphoreMP_handle ti_omp_utils_SemaphoreMP_handle
#define SemaphoreMP_struct ti_omp_utils_SemaphoreMP_struct
#define SemaphoreMP_Handle_label ti_omp_utils_SemaphoreMP_Handle_label
#define SemaphoreMP_Handle_name ti_omp_utils_SemaphoreMP_Handle_name
#define SemaphoreMP_Instance_init ti_omp_utils_SemaphoreMP_Instance_init
#define SemaphoreMP_Object_count ti_omp_utils_SemaphoreMP_Object_count
#define SemaphoreMP_Object_get ti_omp_utils_SemaphoreMP_Object_get
#define SemaphoreMP_Object_first ti_omp_utils_SemaphoreMP_Object_first
#define SemaphoreMP_Object_next ti_omp_utils_SemaphoreMP_Object_next
#define SemaphoreMP_Object_sizeof ti_omp_utils_SemaphoreMP_Object_sizeof
#define SemaphoreMP_Params_copy ti_omp_utils_SemaphoreMP_Params_copy
#define SemaphoreMP_Params_init ti_omp_utils_SemaphoreMP_Params_init
#define SemaphoreMP_Instance_finalize ti_omp_utils_SemaphoreMP_Instance_finalize
#define SemaphoreMP_delete ti_omp_utils_SemaphoreMP_delete
#define SemaphoreMP_destruct ti_omp_utils_SemaphoreMP_destruct

#endif /* ti_omp_utils_SemaphoreMP__localnames__done */
#endif

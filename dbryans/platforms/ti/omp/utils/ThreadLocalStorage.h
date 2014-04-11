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

#ifndef ti_omp_utils_ThreadLocalStorage__include
#define ti_omp_utils_ThreadLocalStorage__include

#ifndef __nested__
#define __nested__
#define ti_omp_utils_ThreadLocalStorage__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_omp_utils_ThreadLocalStorage___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/omp/utils/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/IHeap.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Types.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_omp_utils_ThreadLocalStorage_Module__diagsEnabled;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__diagsEnabled ti_omp_utils_ThreadLocalStorage_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_omp_utils_ThreadLocalStorage_Module__diagsIncluded;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__diagsIncluded ti_omp_utils_ThreadLocalStorage_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_omp_utils_ThreadLocalStorage_Module__diagsMask;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__diagsMask ti_omp_utils_ThreadLocalStorage_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_omp_utils_ThreadLocalStorage_Module__gateObj;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__gateObj ti_omp_utils_ThreadLocalStorage_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_omp_utils_ThreadLocalStorage_Module__gatePrms;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__gatePrms ti_omp_utils_ThreadLocalStorage_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_omp_utils_ThreadLocalStorage_Module__id;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__id ti_omp_utils_ThreadLocalStorage_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_omp_utils_ThreadLocalStorage_Module__loggerDefined;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__loggerDefined ti_omp_utils_ThreadLocalStorage_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_omp_utils_ThreadLocalStorage_Module__loggerObj;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__loggerObj ti_omp_utils_ThreadLocalStorage_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn0;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn0 ti_omp_utils_ThreadLocalStorage_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn1;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn1 ti_omp_utils_ThreadLocalStorage_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn2;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn2 ti_omp_utils_ThreadLocalStorage_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn4;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn4 ti_omp_utils_ThreadLocalStorage_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn8;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__loggerFxn8 ti_omp_utils_ThreadLocalStorage_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_omp_utils_ThreadLocalStorage_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Module__startupDoneFxn ti_omp_utils_ThreadLocalStorage_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_omp_utils_ThreadLocalStorage_Object__count;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Object__count ti_omp_utils_ThreadLocalStorage_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_omp_utils_ThreadLocalStorage_Object__heap;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Object__heap ti_omp_utils_ThreadLocalStorage_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_omp_utils_ThreadLocalStorage_Object__sizeof;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Object__sizeof ti_omp_utils_ThreadLocalStorage_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_omp_utils_ThreadLocalStorage_Object__table;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_Object__table ti_omp_utils_ThreadLocalStorage_Object__table__C;

/* heapOmpHandle */
#define ti_omp_utils_ThreadLocalStorage_heapOmpHandle (ti_omp_utils_ThreadLocalStorage_heapOmpHandle__C)
typedef xdc_runtime_IHeap_Handle CT__ti_omp_utils_ThreadLocalStorage_heapOmpHandle;
__extern __FAR__ const CT__ti_omp_utils_ThreadLocalStorage_heapOmpHandle ti_omp_utils_ThreadLocalStorage_heapOmpHandle__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_omp_utils_ThreadLocalStorage_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_Module__startupDone__S, "ti_omp_utils_ThreadLocalStorage_Module__startupDone")
__extern xdc_Bool ti_omp_utils_ThreadLocalStorage_Module__startupDone__S( void );

/* createFxn__E */
#define ti_omp_utils_ThreadLocalStorage_createFxn ti_omp_utils_ThreadLocalStorage_createFxn__E
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_createFxn__E, "ti_omp_utils_ThreadLocalStorage_createFxn")
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_createFxn__E( ti_sysbios_knl_Task_Handle tsk, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_createFxn__F, "ti_omp_utils_ThreadLocalStorage_createFxn")
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_createFxn__F( ti_sysbios_knl_Task_Handle tsk, xdc_runtime_Error_Block* eb );
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_createFxn__R( ti_sysbios_knl_Task_Handle tsk, xdc_runtime_Error_Block* eb );

/* switchFxn__E */
#define ti_omp_utils_ThreadLocalStorage_switchFxn ti_omp_utils_ThreadLocalStorage_switchFxn__E
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_switchFxn__E, "ti_omp_utils_ThreadLocalStorage_switchFxn")
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_switchFxn__E( ti_sysbios_knl_Task_Handle from, ti_sysbios_knl_Task_Handle to );
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_switchFxn__F, "ti_omp_utils_ThreadLocalStorage_switchFxn")
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_switchFxn__F( ti_sysbios_knl_Task_Handle from, ti_sysbios_knl_Task_Handle to );
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_switchFxn__R( ti_sysbios_knl_Task_Handle from, ti_sysbios_knl_Task_Handle to );

/* deleteFxn__E */
#define ti_omp_utils_ThreadLocalStorage_deleteFxn ti_omp_utils_ThreadLocalStorage_deleteFxn__E
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_deleteFxn__E, "ti_omp_utils_ThreadLocalStorage_deleteFxn")
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_deleteFxn__E( ti_sysbios_knl_Task_Handle tsk );
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_deleteFxn__F, "ti_omp_utils_ThreadLocalStorage_deleteFxn")
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_deleteFxn__F( ti_sysbios_knl_Task_Handle tsk );
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_deleteFxn__R( ti_sysbios_knl_Task_Handle tsk );

/* registerFxn__E */
#define ti_omp_utils_ThreadLocalStorage_registerFxn ti_omp_utils_ThreadLocalStorage_registerFxn__E
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_registerFxn__E, "ti_omp_utils_ThreadLocalStorage_registerFxn")
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_registerFxn__E( xdc_Int id );
xdc__CODESECT(ti_omp_utils_ThreadLocalStorage_registerFxn__F, "ti_omp_utils_ThreadLocalStorage_registerFxn")
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_registerFxn__F( xdc_Int id );
__extern xdc_Void ti_omp_utils_ThreadLocalStorage_registerFxn__R( xdc_Int id );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_omp_utils_ThreadLocalStorage_Module_startupDone() ti_omp_utils_ThreadLocalStorage_Module__startupDone__S()

/* Object_heap */
#define ti_omp_utils_ThreadLocalStorage_Object_heap() ti_omp_utils_ThreadLocalStorage_Object__heap__C

/* Module_heap */
#define ti_omp_utils_ThreadLocalStorage_Module_heap() ti_omp_utils_ThreadLocalStorage_Object__heap__C

/* Module_id */
static inline CT__ti_omp_utils_ThreadLocalStorage_Module__id ti_omp_utils_ThreadLocalStorage_Module_id( void ) 
{
    return ti_omp_utils_ThreadLocalStorage_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_omp_utils_ThreadLocalStorage_Module_hasMask( void ) 
{
    return ti_omp_utils_ThreadLocalStorage_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_omp_utils_ThreadLocalStorage_Module_getMask( void ) 
{
    return ti_omp_utils_ThreadLocalStorage_Module__diagsMask__C != NULL ? *ti_omp_utils_ThreadLocalStorage_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_omp_utils_ThreadLocalStorage_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_omp_utils_ThreadLocalStorage_Module__diagsMask__C != NULL) *ti_omp_utils_ThreadLocalStorage_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_omp_utils_ThreadLocalStorage__top__
#undef __nested__
#endif

#endif /* ti_omp_utils_ThreadLocalStorage__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_omp_utils_ThreadLocalStorage__internalaccess))

#ifndef ti_omp_utils_ThreadLocalStorage__include_state
#define ti_omp_utils_ThreadLocalStorage__include_state

/* Module_State */
struct ti_omp_utils_ThreadLocalStorage_Module_State {
    xdc_UInt contextId;
    xdc_runtime_IHeap_Handle heapOmpHandle;
};

/* Module__state__V */
extern struct ti_omp_utils_ThreadLocalStorage_Module_State__ ti_omp_utils_ThreadLocalStorage_Module__state__V;

#endif /* ti_omp_utils_ThreadLocalStorage__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_omp_utils_ThreadLocalStorage__nolocalnames)

#ifndef ti_omp_utils_ThreadLocalStorage__localnames__done
#define ti_omp_utils_ThreadLocalStorage__localnames__done

/* module prefix */
#define ThreadLocalStorage_Module_State ti_omp_utils_ThreadLocalStorage_Module_State
#define ThreadLocalStorage_heapOmpHandle ti_omp_utils_ThreadLocalStorage_heapOmpHandle
#define ThreadLocalStorage_createFxn ti_omp_utils_ThreadLocalStorage_createFxn
#define ThreadLocalStorage_switchFxn ti_omp_utils_ThreadLocalStorage_switchFxn
#define ThreadLocalStorage_deleteFxn ti_omp_utils_ThreadLocalStorage_deleteFxn
#define ThreadLocalStorage_registerFxn ti_omp_utils_ThreadLocalStorage_registerFxn
#define ThreadLocalStorage_Module_name ti_omp_utils_ThreadLocalStorage_Module_name
#define ThreadLocalStorage_Module_id ti_omp_utils_ThreadLocalStorage_Module_id
#define ThreadLocalStorage_Module_startup ti_omp_utils_ThreadLocalStorage_Module_startup
#define ThreadLocalStorage_Module_startupDone ti_omp_utils_ThreadLocalStorage_Module_startupDone
#define ThreadLocalStorage_Module_hasMask ti_omp_utils_ThreadLocalStorage_Module_hasMask
#define ThreadLocalStorage_Module_getMask ti_omp_utils_ThreadLocalStorage_Module_getMask
#define ThreadLocalStorage_Module_setMask ti_omp_utils_ThreadLocalStorage_Module_setMask
#define ThreadLocalStorage_Object_heap ti_omp_utils_ThreadLocalStorage_Object_heap
#define ThreadLocalStorage_Module_heap ti_omp_utils_ThreadLocalStorage_Module_heap

#endif /* ti_omp_utils_ThreadLocalStorage__localnames__done */
#endif

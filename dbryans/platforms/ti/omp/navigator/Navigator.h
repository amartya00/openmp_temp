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

#ifndef ti_omp_navigator_Navigator__include
#define ti_omp_navigator_Navigator__include

#ifndef __nested__
#define __nested__
#define ti_omp_navigator_Navigator__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_omp_navigator_Navigator___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/omp/navigator/package/package.defs.h>

#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Nav_Ptr */
typedef xdc_Void (*ti_omp_navigator_Navigator_Nav_Ptr)(xdc_UArg, xdc_UArg);


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_omp_navigator_Navigator_Module__diagsEnabled;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__diagsEnabled ti_omp_navigator_Navigator_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_omp_navigator_Navigator_Module__diagsIncluded;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__diagsIncluded ti_omp_navigator_Navigator_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_omp_navigator_Navigator_Module__diagsMask;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__diagsMask ti_omp_navigator_Navigator_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_omp_navigator_Navigator_Module__gateObj;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__gateObj ti_omp_navigator_Navigator_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_omp_navigator_Navigator_Module__gatePrms;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__gatePrms ti_omp_navigator_Navigator_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_omp_navigator_Navigator_Module__id;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__id ti_omp_navigator_Navigator_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_omp_navigator_Navigator_Module__loggerDefined;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__loggerDefined ti_omp_navigator_Navigator_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_omp_navigator_Navigator_Module__loggerObj;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__loggerObj ti_omp_navigator_Navigator_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_omp_navigator_Navigator_Module__loggerFxn0;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__loggerFxn0 ti_omp_navigator_Navigator_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_omp_navigator_Navigator_Module__loggerFxn1;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__loggerFxn1 ti_omp_navigator_Navigator_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_omp_navigator_Navigator_Module__loggerFxn2;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__loggerFxn2 ti_omp_navigator_Navigator_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_omp_navigator_Navigator_Module__loggerFxn4;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__loggerFxn4 ti_omp_navigator_Navigator_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_omp_navigator_Navigator_Module__loggerFxn8;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__loggerFxn8 ti_omp_navigator_Navigator_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_omp_navigator_Navigator_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Module__startupDoneFxn ti_omp_navigator_Navigator_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_omp_navigator_Navigator_Object__count;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Object__count ti_omp_navigator_Navigator_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_omp_navigator_Navigator_Object__heap;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Object__heap ti_omp_navigator_Navigator_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_omp_navigator_Navigator_Object__sizeof;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Object__sizeof ti_omp_navigator_Navigator_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_omp_navigator_Navigator_Object__table;
__extern __FAR__ const CT__ti_omp_navigator_Navigator_Object__table ti_omp_navigator_Navigator_Object__table__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_omp_navigator_Navigator_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_omp_navigator_Navigator_Module__startupDone__S, "ti_omp_navigator_Navigator_Module__startupDone")
__extern xdc_Bool ti_omp_navigator_Navigator_Module__startupDone__S( void );

/* init_Navigator__E */
#define ti_omp_navigator_Navigator_init_Navigator ti_omp_navigator_Navigator_init_Navigator__E
xdc__CODESECT(ti_omp_navigator_Navigator_init_Navigator__E, "ti_omp_navigator_Navigator_init_Navigator")
__extern xdc_Void ti_omp_navigator_Navigator_init_Navigator__E( void );
xdc__CODESECT(ti_omp_navigator_Navigator_init_Navigator__F, "ti_omp_navigator_Navigator_init_Navigator")
__extern xdc_Void ti_omp_navigator_Navigator_init_Navigator__F( void );
__extern xdc_Void ti_omp_navigator_Navigator_init_Navigator__R( void );

/* queue_pop_elem__E */
#define ti_omp_navigator_Navigator_queue_pop_elem ti_omp_navigator_Navigator_queue_pop_elem__E
xdc__CODESECT(ti_omp_navigator_Navigator_queue_pop_elem__E, "ti_omp_navigator_Navigator_queue_pop_elem")
__extern xdc_Ptr ti_omp_navigator_Navigator_queue_pop_elem__E( xdc_UInt32 Hnd );
xdc__CODESECT(ti_omp_navigator_Navigator_queue_pop_elem__F, "ti_omp_navigator_Navigator_queue_pop_elem")
__extern xdc_Ptr ti_omp_navigator_Navigator_queue_pop_elem__F( xdc_UInt32 Hnd );
__extern xdc_Ptr ti_omp_navigator_Navigator_queue_pop_elem__R( xdc_UInt32 Hnd );

/* queue_pop_elem_wait__E */
#define ti_omp_navigator_Navigator_queue_pop_elem_wait ti_omp_navigator_Navigator_queue_pop_elem_wait__E
xdc__CODESECT(ti_omp_navigator_Navigator_queue_pop_elem_wait__E, "ti_omp_navigator_Navigator_queue_pop_elem_wait")
__extern xdc_Ptr ti_omp_navigator_Navigator_queue_pop_elem_wait__E( xdc_UInt32 Hnd );
xdc__CODESECT(ti_omp_navigator_Navigator_queue_pop_elem_wait__F, "ti_omp_navigator_Navigator_queue_pop_elem_wait")
__extern xdc_Ptr ti_omp_navigator_Navigator_queue_pop_elem_wait__F( xdc_UInt32 Hnd );
__extern xdc_Ptr ti_omp_navigator_Navigator_queue_pop_elem_wait__R( xdc_UInt32 Hnd );

/* Queue_get_num_elem__E */
#define ti_omp_navigator_Navigator_Queue_get_num_elem ti_omp_navigator_Navigator_Queue_get_num_elem__E
xdc__CODESECT(ti_omp_navigator_Navigator_Queue_get_num_elem__E, "ti_omp_navigator_Navigator_Queue_get_num_elem")
__extern xdc_UInt32 ti_omp_navigator_Navigator_Queue_get_num_elem__E( xdc_UInt32 Hnd );
xdc__CODESECT(ti_omp_navigator_Navigator_Queue_get_num_elem__F, "ti_omp_navigator_Navigator_Queue_get_num_elem")
__extern xdc_UInt32 ti_omp_navigator_Navigator_Queue_get_num_elem__F( xdc_UInt32 Hnd );
__extern xdc_UInt32 ti_omp_navigator_Navigator_Queue_get_num_elem__R( xdc_UInt32 Hnd );

/* queue_push_elem__E */
#define ti_omp_navigator_Navigator_queue_push_elem ti_omp_navigator_Navigator_queue_push_elem__E
xdc__CODESECT(ti_omp_navigator_Navigator_queue_push_elem__E, "ti_omp_navigator_Navigator_queue_push_elem")
__extern xdc_Void ti_omp_navigator_Navigator_queue_push_elem__E( xdc_UInt32 Hnd, xdc_UInt32 elem );
xdc__CODESECT(ti_omp_navigator_Navigator_queue_push_elem__F, "ti_omp_navigator_Navigator_queue_push_elem")
__extern xdc_Void ti_omp_navigator_Navigator_queue_push_elem__F( xdc_UInt32 Hnd, xdc_UInt32 elem );
__extern xdc_Void ti_omp_navigator_Navigator_queue_push_elem__R( xdc_UInt32 Hnd, xdc_UInt32 elem );

/* Barrier_wait__E */
#define ti_omp_navigator_Navigator_Barrier_wait ti_omp_navigator_Navigator_Barrier_wait__E
xdc__CODESECT(ti_omp_navigator_Navigator_Barrier_wait__E, "ti_omp_navigator_Navigator_Barrier_wait")
__extern xdc_Void ti_omp_navigator_Navigator_Barrier_wait__E( volatile xdc_UInt32 total, volatile xdc_UInt32 Hnd );
xdc__CODESECT(ti_omp_navigator_Navigator_Barrier_wait__F, "ti_omp_navigator_Navigator_Barrier_wait")
__extern xdc_Void ti_omp_navigator_Navigator_Barrier_wait__F( volatile xdc_UInt32 total, volatile xdc_UInt32 Hnd );
__extern xdc_Void ti_omp_navigator_Navigator_Barrier_wait__R( volatile xdc_UInt32 total, volatile xdc_UInt32 Hnd );

/* Queue_Barrier_wait__E */
#define ti_omp_navigator_Navigator_Queue_Barrier_wait ti_omp_navigator_Navigator_Queue_Barrier_wait__E
xdc__CODESECT(ti_omp_navigator_Navigator_Queue_Barrier_wait__E, "ti_omp_navigator_Navigator_Queue_Barrier_wait")
__extern xdc_Void ti_omp_navigator_Navigator_Queue_Barrier_wait__E( xdc_UInt32* bar );
xdc__CODESECT(ti_omp_navigator_Navigator_Queue_Barrier_wait__F, "ti_omp_navigator_Navigator_Queue_Barrier_wait")
__extern xdc_Void ti_omp_navigator_Navigator_Queue_Barrier_wait__F( xdc_UInt32* bar );
__extern xdc_Void ti_omp_navigator_Navigator_Queue_Barrier_wait__R( xdc_UInt32* bar );

/* wait_for_release__E */
#define ti_omp_navigator_Navigator_wait_for_release ti_omp_navigator_Navigator_wait_for_release__E
xdc__CODESECT(ti_omp_navigator_Navigator_wait_for_release__E, "ti_omp_navigator_Navigator_wait_for_release")
__extern xdc_Void ti_omp_navigator_Navigator_wait_for_release__E( xdc_UInt32* bar );
xdc__CODESECT(ti_omp_navigator_Navigator_wait_for_release__F, "ti_omp_navigator_Navigator_wait_for_release")
__extern xdc_Void ti_omp_navigator_Navigator_wait_for_release__F( xdc_UInt32* bar );
__extern xdc_Void ti_omp_navigator_Navigator_wait_for_release__R( xdc_UInt32* bar );

/* wait_threads_release__E */
#define ti_omp_navigator_Navigator_wait_threads_release ti_omp_navigator_Navigator_wait_threads_release__E
xdc__CODESECT(ti_omp_navigator_Navigator_wait_threads_release__E, "ti_omp_navigator_Navigator_wait_threads_release")
__extern xdc_Void ti_omp_navigator_Navigator_wait_threads_release__E( xdc_UInt32* bar );
xdc__CODESECT(ti_omp_navigator_Navigator_wait_threads_release__F, "ti_omp_navigator_Navigator_wait_threads_release")
__extern xdc_Void ti_omp_navigator_Navigator_wait_threads_release__F( xdc_UInt32* bar );
__extern xdc_Void ti_omp_navigator_Navigator_wait_threads_release__R( xdc_UInt32* bar );

/* Close_Queue__E */
#define ti_omp_navigator_Navigator_Close_Queue ti_omp_navigator_Navigator_Close_Queue__E
xdc__CODESECT(ti_omp_navigator_Navigator_Close_Queue__E, "ti_omp_navigator_Navigator_Close_Queue")
__extern xdc_Void ti_omp_navigator_Navigator_Close_Queue__E( xdc_UInt32 Hnd );
xdc__CODESECT(ti_omp_navigator_Navigator_Close_Queue__F, "ti_omp_navigator_Navigator_Close_Queue")
__extern xdc_Void ti_omp_navigator_Navigator_Close_Queue__F( xdc_UInt32 Hnd );
__extern xdc_Void ti_omp_navigator_Navigator_Close_Queue__R( xdc_UInt32 Hnd );

/* sysExit__E */
#define ti_omp_navigator_Navigator_sysExit ti_omp_navigator_Navigator_sysExit__E
xdc__CODESECT(ti_omp_navigator_Navigator_sysExit__E, "ti_omp_navigator_Navigator_sysExit")
__extern xdc_Void ti_omp_navigator_Navigator_sysExit__E( void );
xdc__CODESECT(ti_omp_navigator_Navigator_sysExit__F, "ti_omp_navigator_Navigator_sysExit")
__extern xdc_Void ti_omp_navigator_Navigator_sysExit__F( void );
__extern xdc_Void ti_omp_navigator_Navigator_sysExit__R( void );

/* Create_Queue__E */
#define ti_omp_navigator_Navigator_Create_Queue ti_omp_navigator_Navigator_Create_Queue__E
xdc__CODESECT(ti_omp_navigator_Navigator_Create_Queue__E, "ti_omp_navigator_Navigator_Create_Queue")
__extern xdc_UInt32 ti_omp_navigator_Navigator_Create_Queue__E( void );
xdc__CODESECT(ti_omp_navigator_Navigator_Create_Queue__F, "ti_omp_navigator_Navigator_Create_Queue")
__extern xdc_UInt32 ti_omp_navigator_Navigator_Create_Queue__F( void );
__extern xdc_UInt32 ti_omp_navigator_Navigator_Create_Queue__R( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_omp_navigator_Navigator_Module_startupDone() ti_omp_navigator_Navigator_Module__startupDone__S()

/* Object_heap */
#define ti_omp_navigator_Navigator_Object_heap() ti_omp_navigator_Navigator_Object__heap__C

/* Module_heap */
#define ti_omp_navigator_Navigator_Module_heap() ti_omp_navigator_Navigator_Object__heap__C

/* Module_id */
static inline CT__ti_omp_navigator_Navigator_Module__id ti_omp_navigator_Navigator_Module_id( void ) 
{
    return ti_omp_navigator_Navigator_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_omp_navigator_Navigator_Module_hasMask( void ) 
{
    return ti_omp_navigator_Navigator_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_omp_navigator_Navigator_Module_getMask( void ) 
{
    return ti_omp_navigator_Navigator_Module__diagsMask__C != NULL ? *ti_omp_navigator_Navigator_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_omp_navigator_Navigator_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_omp_navigator_Navigator_Module__diagsMask__C != NULL) *ti_omp_navigator_Navigator_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_omp_navigator_Navigator__top__
#undef __nested__
#endif

#endif /* ti_omp_navigator_Navigator__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_omp_navigator_Navigator__internalaccess))

#ifndef ti_omp_navigator_Navigator__include_state
#define ti_omp_navigator_Navigator__include_state


#endif /* ti_omp_navigator_Navigator__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_omp_navigator_Navigator__nolocalnames)

#ifndef ti_omp_navigator_Navigator__localnames__done
#define ti_omp_navigator_Navigator__localnames__done

/* module prefix */
#define Navigator_Nav_Ptr ti_omp_navigator_Navigator_Nav_Ptr
#define Navigator_init_Navigator ti_omp_navigator_Navigator_init_Navigator
#define Navigator_queue_pop_elem ti_omp_navigator_Navigator_queue_pop_elem
#define Navigator_queue_pop_elem_wait ti_omp_navigator_Navigator_queue_pop_elem_wait
#define Navigator_Queue_get_num_elem ti_omp_navigator_Navigator_Queue_get_num_elem
#define Navigator_queue_push_elem ti_omp_navigator_Navigator_queue_push_elem
#define Navigator_Barrier_wait ti_omp_navigator_Navigator_Barrier_wait
#define Navigator_Queue_Barrier_wait ti_omp_navigator_Navigator_Queue_Barrier_wait
#define Navigator_wait_for_release ti_omp_navigator_Navigator_wait_for_release
#define Navigator_wait_threads_release ti_omp_navigator_Navigator_wait_threads_release
#define Navigator_Close_Queue ti_omp_navigator_Navigator_Close_Queue
#define Navigator_sysExit ti_omp_navigator_Navigator_sysExit
#define Navigator_Create_Queue ti_omp_navigator_Navigator_Create_Queue
#define Navigator_Module_name ti_omp_navigator_Navigator_Module_name
#define Navigator_Module_id ti_omp_navigator_Navigator_Module_id
#define Navigator_Module_startup ti_omp_navigator_Navigator_Module_startup
#define Navigator_Module_startupDone ti_omp_navigator_Navigator_Module_startupDone
#define Navigator_Module_hasMask ti_omp_navigator_Navigator_Module_hasMask
#define Navigator_Module_getMask ti_omp_navigator_Navigator_Module_getMask
#define Navigator_Module_setMask ti_omp_navigator_Navigator_Module_setMask
#define Navigator_Object_heap ti_omp_navigator_Navigator_Object_heap
#define Navigator_Module_heap ti_omp_navigator_Navigator_Module_heap

#endif /* ti_omp_navigator_Navigator__localnames__done */
#endif

/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y30
 */

#ifndef ti_omp_utils_OpenMP__INTERNAL__
#define ti_omp_utils_OpenMP__INTERNAL__

#ifndef ti_omp_utils_OpenMP__internalaccess
#define ti_omp_utils_OpenMP__internalaccess
#endif

#include <ti/omp/utils/OpenMP.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* createThread */
#undef ti_omp_utils_OpenMP_createThread
#define ti_omp_utils_OpenMP_createThread ti_omp_utils_OpenMP_createThread__E

/* exitThread */
#undef ti_omp_utils_OpenMP_exitThread
#define ti_omp_utils_OpenMP_exitThread ti_omp_utils_OpenMP_exitThread__F

/* mainTaskExit */
#undef ti_omp_utils_OpenMP_mainTaskExit
#define ti_omp_utils_OpenMP_mainTaskExit ti_omp_utils_OpenMP_mainTaskExit__F

/* useSharedHeap */
#undef ti_omp_utils_OpenMP_useSharedHeap
#define ti_omp_utils_OpenMP_useSharedHeap ti_omp_utils_OpenMP_useSharedHeap__F

/* getTimerCount */
#undef ti_omp_utils_OpenMP_getTimerCount
#define ti_omp_utils_OpenMP_getTimerCount ti_omp_utils_OpenMP_getTimerCount__E

/* getTimerFreq */
#undef ti_omp_utils_OpenMP_getTimerFreq
#define ti_omp_utils_OpenMP_getTimerFreq ti_omp_utils_OpenMP_getTimerFreq__E

/* masterTask */
#define OpenMP_masterTask ti_omp_utils_OpenMP_masterTask__I

/* threadSpawnLoop */
#define OpenMP_threadSpawnLoop ti_omp_utils_OpenMP_threadSpawnLoop__I

/* mainTask */
#define OpenMP_mainTask ti_omp_utils_OpenMP_mainTask__I

/* setProcId */
#define OpenMP_setProcId ti_omp_utils_OpenMP_setProcId__I

/* Module_startup */
#undef ti_omp_utils_OpenMP_Module_startup
#define ti_omp_utils_OpenMP_Module_startup ti_omp_utils_OpenMP_Module_startup__F

/* Instance_init */
#undef ti_omp_utils_OpenMP_Instance_init
#define ti_omp_utils_OpenMP_Instance_init ti_omp_utils_OpenMP_Instance_init__F

/* Instance_finalize */
#undef ti_omp_utils_OpenMP_Instance_finalize
#define ti_omp_utils_OpenMP_Instance_finalize ti_omp_utils_OpenMP_Instance_finalize__F

/* module */
#define OpenMP_module ((ti_omp_utils_OpenMP_Module_State *)(xdc__MODOBJADDR__(ti_omp_utils_OpenMP_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_omp_utils_OpenMP__cplusplus)
#define module ((ti_omp_utils_OpenMP_Module_State *)(xdc__MODOBJADDR__(ti_omp_utils_OpenMP_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_omp_utils_OpenMP_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_omp_utils_OpenMP_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_omp_utils_OpenMP_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_omp_utils_OpenMP_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_omp_utils_OpenMP_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_omp_utils_OpenMP_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_omp_utils_OpenMP_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_omp_utils_OpenMP_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_omp_utils_OpenMP_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_omp_utils_OpenMP_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_omp_utils_OpenMP_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_omp_utils_OpenMP_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_omp_utils_OpenMP_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_omp_utils_OpenMP_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_omp_utils_OpenMP_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_omp_utils_OpenMP_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_omp_utils_OpenMP_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_omp_utils_OpenMP_Module_GateProxy_query


#endif /* ti_omp_utils_OpenMP__INTERNAL____ */

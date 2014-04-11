/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y30
 */

#ifndef ti_omp_utils_SemaphoreMP__INTERNAL__
#define ti_omp_utils_SemaphoreMP__INTERNAL__

#ifndef ti_omp_utils_SemaphoreMP__internalaccess
#define ti_omp_utils_SemaphoreMP__internalaccess
#endif

#include <ti/omp/utils/SemaphoreMP.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* open */
#undef ti_omp_utils_SemaphoreMP_open
#define ti_omp_utils_SemaphoreMP_open ti_omp_utils_SemaphoreMP_open__F

/* openByAddr */
#undef ti_omp_utils_SemaphoreMP_openByAddr
#define ti_omp_utils_SemaphoreMP_openByAddr ti_omp_utils_SemaphoreMP_openByAddr__F

/* close */
#undef ti_omp_utils_SemaphoreMP_close
#define ti_omp_utils_SemaphoreMP_close ti_omp_utils_SemaphoreMP_close__F

/* sharedMemReq */
#undef ti_omp_utils_SemaphoreMP_sharedMemReq
#define ti_omp_utils_SemaphoreMP_sharedMemReq ti_omp_utils_SemaphoreMP_sharedMemReq__F

/* start */
#undef ti_omp_utils_SemaphoreMP_start
#define ti_omp_utils_SemaphoreMP_start ti_omp_utils_SemaphoreMP_start__F

/* getCount */
#undef ti_omp_utils_SemaphoreMP_getCount
#define ti_omp_utils_SemaphoreMP_getCount ti_omp_utils_SemaphoreMP_getCount__E

/* pend */
#undef ti_omp_utils_SemaphoreMP_pend
#define ti_omp_utils_SemaphoreMP_pend ti_omp_utils_SemaphoreMP_pend__E

/* post */
#undef ti_omp_utils_SemaphoreMP_post
#define ti_omp_utils_SemaphoreMP_post ti_omp_utils_SemaphoreMP_post__E

/* reset */
#undef ti_omp_utils_SemaphoreMP_reset
#define ti_omp_utils_SemaphoreMP_reset ti_omp_utils_SemaphoreMP_reset__E

/* cbFxn */
#define SemaphoreMP_cbFxn ti_omp_utils_SemaphoreMP_cbFxn__I

/* registerEvent */
#define SemaphoreMP_registerEvent ti_omp_utils_SemaphoreMP_registerEvent__I

/* Module_startup */
#undef ti_omp_utils_SemaphoreMP_Module_startup
#define ti_omp_utils_SemaphoreMP_Module_startup ti_omp_utils_SemaphoreMP_Module_startup__F

/* Instance_init */
#undef ti_omp_utils_SemaphoreMP_Instance_init
#define ti_omp_utils_SemaphoreMP_Instance_init ti_omp_utils_SemaphoreMP_Instance_init__F

/* Instance_finalize */
#undef ti_omp_utils_SemaphoreMP_Instance_finalize
#define ti_omp_utils_SemaphoreMP_Instance_finalize ti_omp_utils_SemaphoreMP_Instance_finalize__F

/* module */
#define SemaphoreMP_module ((ti_omp_utils_SemaphoreMP_Module_State *)(xdc__MODOBJADDR__(ti_omp_utils_SemaphoreMP_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_omp_utils_SemaphoreMP__cplusplus)
#define module ((ti_omp_utils_SemaphoreMP_Module_State *)(xdc__MODOBJADDR__(ti_omp_utils_SemaphoreMP_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_omp_utils_SemaphoreMP_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_omp_utils_SemaphoreMP_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_omp_utils_SemaphoreMP_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_omp_utils_SemaphoreMP_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_omp_utils_SemaphoreMP_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_omp_utils_SemaphoreMP_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_omp_utils_SemaphoreMP_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_omp_utils_SemaphoreMP_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_omp_utils_SemaphoreMP_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_omp_utils_SemaphoreMP_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_omp_utils_SemaphoreMP_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_omp_utils_SemaphoreMP_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_omp_utils_SemaphoreMP_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_omp_utils_SemaphoreMP_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_omp_utils_SemaphoreMP_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_omp_utils_SemaphoreMP_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_omp_utils_SemaphoreMP_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_omp_utils_SemaphoreMP_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_ti.omp.utils.SemaphoreMP"
typedef char ti_omp_utils_SemaphoreMP_Object__sizingError[sizeof(ti_omp_utils_SemaphoreMP_Object) > sizeof(ti_omp_utils_SemaphoreMP_Struct) ? -1 : 1];


#endif /* ti_omp_utils_SemaphoreMP__INTERNAL____ */

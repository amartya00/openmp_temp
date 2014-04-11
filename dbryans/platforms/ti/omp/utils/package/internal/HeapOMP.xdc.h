/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y30
 */

#ifndef ti_omp_utils_HeapOMP__INTERNAL__
#define ti_omp_utils_HeapOMP__INTERNAL__

#ifndef ti_omp_utils_HeapOMP__internalaccess
#define ti_omp_utils_HeapOMP__internalaccess
#endif

#include <ti/omp/utils/HeapOMP.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* isBlocking */
#undef ti_omp_utils_HeapOMP_isBlocking
#define ti_omp_utils_HeapOMP_isBlocking ti_omp_utils_HeapOMP_isBlocking__F

/* getStats */
#undef ti_omp_utils_HeapOMP_getStats
#define ti_omp_utils_HeapOMP_getStats ti_omp_utils_HeapOMP_getStats__E

/* alloc */
#undef ti_omp_utils_HeapOMP_alloc
#define ti_omp_utils_HeapOMP_alloc ti_omp_utils_HeapOMP_alloc__E

/* free */
#undef ti_omp_utils_HeapOMP_free
#define ti_omp_utils_HeapOMP_free ti_omp_utils_HeapOMP_free__E

/* Module_startup */
#undef ti_omp_utils_HeapOMP_Module_startup
#define ti_omp_utils_HeapOMP_Module_startup ti_omp_utils_HeapOMP_Module_startup__F

/* Instance_init */
#undef ti_omp_utils_HeapOMP_Instance_init
#define ti_omp_utils_HeapOMP_Instance_init ti_omp_utils_HeapOMP_Instance_init__F

/* Instance_finalize */
#undef ti_omp_utils_HeapOMP_Instance_finalize
#define ti_omp_utils_HeapOMP_Instance_finalize ti_omp_utils_HeapOMP_Instance_finalize__F

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_omp_utils_HeapOMP_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_omp_utils_HeapOMP_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_omp_utils_HeapOMP_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_omp_utils_HeapOMP_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_omp_utils_HeapOMP_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_omp_utils_HeapOMP_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_omp_utils_HeapOMP_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_omp_utils_HeapOMP_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_omp_utils_HeapOMP_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_omp_utils_HeapOMP_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_omp_utils_HeapOMP_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_omp_utils_HeapOMP_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_omp_utils_HeapOMP_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_omp_utils_HeapOMP_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_omp_utils_HeapOMP_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_omp_utils_HeapOMP_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_omp_utils_HeapOMP_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_omp_utils_HeapOMP_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_ti.omp.utils.HeapOMP"
typedef char ti_omp_utils_HeapOMP_Object__sizingError[sizeof(ti_omp_utils_HeapOMP_Object) > sizeof(ti_omp_utils_HeapOMP_Struct) ? -1 : 1];


#endif /* ti_omp_utils_HeapOMP__INTERNAL____ */

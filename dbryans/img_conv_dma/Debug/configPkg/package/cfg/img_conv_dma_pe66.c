/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y44
 */

#define __nested__
#define __config__

#include <xdc/std.h>

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     MODULE INCLUDES
 *     
 *     <module-name> INTERNALS
 *     <module-name> INHERITS
 *     <module-name> VTABLE
 *     <module-name> PATCH TABLE
 *     <module-name> DECLARATIONS
 *     <module-name> OBJECT OFFSETS
 *     <module-name> TEMPLATES
 *     <module-name> INITIALIZERS
 *     <module-name> FUNCTION STUBS
 *     <module-name> PROXY BODY
 *     <module-name> OBJECT DESCRIPTOR
 *     <module-name> SYSTEM FUNCTIONS
 *     <module-name> PRAGMAS
 *     
 *     INITIALIZATION ENTRY POINT
 *     PROGRAM GLOBALS
 *     CLINK DIRECTIVES
 */


/*
 * ======== MODULE INCLUDES ========
 */

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/family/c62/IntrinsicsSupport.h>
#include <ti/sysbios/family/c62/TaskSupport.h>
#include <ti/sysbios/family/c64p/EventCombiner.h>
#include <ti/sysbios/family/c64p/Exception.h>
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/TimestampProvider.h>
#include <ti/sysbios/family/c64p/tci6488/TimerSupport.h>
#include <ti/sysbios/family/c66/Cache.h>
#include <ti/sysbios/family/c66/tci66xx/CpIntc.h>
#include <ti/sysbios/gates/GateHwi.h>
#include <ti/sysbios/gates/GateMutex.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/hal/Timer.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Idle.h>
#include <ti/sysbios/knl/Intrinsics.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/timers/timer64/Timer.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Core.h>
#include <xdc/runtime/Defaults.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Gate.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Main.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/SysMin.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Text.h>
#include <xdc/runtime/Timestamp.h>


/*
 * ======== ti.sysbios.BIOS INTERNALS ========
 */


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_BIOS_RtsGateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_BIOS_RtsGateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_BIOS_RtsGateProxy_Module__ ti_sysbios_BIOS_RtsGateProxy_Module__root__V;

/* @@@ ti_sysbios_knl_Queue_Object__ */
typedef struct ti_sysbios_knl_Queue_Object__ {
    ti_sysbios_knl_Queue_Elem elem;
} ti_sysbios_knl_Queue_Object__;

/* @@@ ti_sysbios_knl_Queue_Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Queue_Object__ obj;
} ti_sysbios_knl_Queue_Object2__;

/* @@@ ti_sysbios_knl_Semaphore_Object__ */
typedef struct ti_sysbios_knl_Semaphore_Object__ {
    ti_sysbios_knl_Event_Handle event;
    xdc_UInt eventId;
    ti_sysbios_knl_Semaphore_Mode mode;
    volatile xdc_UInt16 count;
    ti_sysbios_knl_Queue_Object__ Object_field_pendQ;
} ti_sysbios_knl_Semaphore_Object__;

/* @@@ ti_sysbios_knl_Semaphore_Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Semaphore_Object__ obj;
} ti_sysbios_knl_Semaphore_Object2__;

/* Object__ */
typedef struct ti_sysbios_gates_GateMutex_Object__ {
    const ti_sysbios_gates_GateMutex_Fxns__* __fxns;
    ti_sysbios_knl_Task_Handle owner;
    ti_sysbios_knl_Semaphore_Object__ Object_field_sem;
} ti_sysbios_gates_GateMutex_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_gates_GateMutex_Object__ obj;
} ti_sysbios_gates_GateMutex_Object2__;

/* Object */
typedef ti_sysbios_gates_GateMutex_Object__ ti_sysbios_BIOS_RtsGateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_BIOS_RtsGateProxy_Object__ obj;
} ti_sysbios_BIOS_RtsGateProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_BIOS_RtsGateProxy___VERS
    #define ti_sysbios_BIOS_RtsGateProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_BIOS_RtsGateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.c62.IntrinsicsSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c62.TaskSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.EventCombiner INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.Exception INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_c64p_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_c64p_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_family_c64p_Hwi_Module__ ti_sysbios_family_c64p_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_c64p_Hwi_Object__ {
    const ti_sysbios_family_c64p_Hwi_Fxns__* __fxns;
    xdc_Bits16 disableMask;
    xdc_Bits16 restoreMask;
    xdc_UArg arg;
    ti_sysbios_family_c64p_Hwi_FuncPtr fxn;
    ti_sysbios_family_c64p_Hwi_Irp irp;
    __TA_ti_sysbios_family_c64p_Hwi_Instance_State__hookEnv hookEnv;
} ti_sysbios_family_c64p_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_c64p_Hwi_Object__ obj;
} ti_sysbios_family_c64p_Hwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_family_c64p_Hwi___VERS
    #define ti_sysbios_family_c64p_Hwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_family_c64p_Hwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.tci6488.TimerSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c66.Cache INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c66.tci66xx.CpIntc INTERNALS ========
 */


/*
 * ======== ti.sysbios.gates.GateHwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_gates_GateHwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_gates_GateHwi_Module__;

/* Module__root__V */
extern ti_sysbios_gates_GateHwi_Module__ ti_sysbios_gates_GateHwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_gates_GateHwi_Object__ {
    const ti_sysbios_gates_GateHwi_Fxns__* __fxns;
} ti_sysbios_gates_GateHwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_gates_GateHwi_Object__ obj;
} ti_sysbios_gates_GateHwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_gates_GateHwi___VERS
    #define ti_sysbios_gates_GateHwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_gates_GateHwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.gates.GateMutex INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_gates_GateMutex_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_gates_GateMutex_Module__;

/* Module__root__V */
extern ti_sysbios_gates_GateMutex_Module__ ti_sysbios_gates_GateMutex_Module__root__V;

/* <-- ti_sysbios_gates_GateMutex_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_gates_GateMutex___VERS
    #define ti_sysbios_gates_GateMutex___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_gates_GateMutex___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Hwi_Module__ ti_sysbios_hal_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_hal_Hwi_Object__ {
    const ti_sysbios_hal_Hwi_Fxns__* __fxns;
    ti_sysbios_hal_Hwi_HwiProxy_Handle pi;
} ti_sysbios_hal_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Hwi_Object__ obj;
} ti_sysbios_hal_Hwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Hwi___VERS
    #define ti_sysbios_hal_Hwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Hwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Hwi_HwiProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Hwi_HwiProxy_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Hwi_HwiProxy_Module__ ti_sysbios_hal_Hwi_HwiProxy_Module__root__V;

/* <-- ti_sysbios_family_c64p_Hwi_Object */

/* Object */
typedef ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_hal_Hwi_HwiProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Hwi_HwiProxy_Object__ obj;
} ti_sysbios_hal_Hwi_HwiProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Hwi_HwiProxy___VERS
    #define ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Timer INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Timer_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Timer_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Timer_Module__ ti_sysbios_hal_Timer_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_hal_Timer_Object__ {
    const ti_sysbios_hal_Timer_Fxns__* __fxns;
    ti_sysbios_hal_Timer_TimerProxy_Handle pi;
} ti_sysbios_hal_Timer_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Timer_Object__ obj;
} ti_sysbios_hal_Timer_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Timer___VERS
    #define ti_sysbios_hal_Timer___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Timer___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Timer_TimerProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Timer_TimerProxy_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Timer_TimerProxy_Module__ ti_sysbios_hal_Timer_TimerProxy_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_timers_timer64_Timer_Object__ {
    const ti_sysbios_timers_timer64_Timer_Fxns__* __fxns;
    xdc_Bool staticInst;
    xdc_Int id;
    ti_sysbios_timers_timer64_Timer_Half half;
    xdc_UInt tcrInit;
    xdc_UInt emumgtInit;
    xdc_UInt gpioIntEn;
    xdc_UInt gpioDatDir;
    ti_sysbios_interfaces_ITimer_RunMode runMode;
    ti_sysbios_interfaces_ITimer_StartMode startMode;
    xdc_UInt period;
    ti_sysbios_interfaces_ITimer_PeriodType periodType;
    xdc_UInt prescalar;
    xdc_UInt intNum;
    xdc_UArg arg;
    ti_sysbios_hal_Hwi_FuncPtr tickFxn;
    xdc_runtime_Types_FreqHz extFreq;
    ti_sysbios_hal_Hwi_Handle hwi;
} ti_sysbios_timers_timer64_Timer_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_timers_timer64_Timer_Object__ obj;
} ti_sysbios_timers_timer64_Timer_Object2__;

/* Object */
typedef ti_sysbios_timers_timer64_Timer_Object__ ti_sysbios_hal_Timer_TimerProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Timer_TimerProxy_Object__ obj;
} ti_sysbios_hal_Timer_TimerProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Timer_TimerProxy___VERS
    #define ti_sysbios_hal_Timer_TimerProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Timer_TimerProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.heaps.HeapMem INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_heaps_HeapMem_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_heaps_HeapMem_Module__;

/* Module__root__V */
extern ti_sysbios_heaps_HeapMem_Module__ ti_sysbios_heaps_HeapMem_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_heaps_HeapMem_Object__ {
    const ti_sysbios_heaps_HeapMem_Fxns__* __fxns;
    xdc_runtime_Memory_Size align;
    __TA_ti_sysbios_heaps_HeapMem_Instance_State__buf buf;
    ti_sysbios_heaps_HeapMem_Header head;
    xdc_SizeT minBlockAlign;
} ti_sysbios_heaps_HeapMem_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_heaps_HeapMem_Object__ obj;
} ti_sysbios_heaps_HeapMem_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_heaps_HeapMem___VERS
    #define ti_sysbios_heaps_HeapMem___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_heaps_HeapMem___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateMutex_Object */

/* Object */
typedef ti_sysbios_gates_GateMutex_Object__ ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__ obj;
} ti_sysbios_heaps_HeapMem_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_heaps_HeapMem_Module_GateProxy___VERS
    #define ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Clock INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Clock_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Clock_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Clock_Module__ ti_sysbios_knl_Clock_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* Object__ */
typedef struct ti_sysbios_knl_Clock_Object__ {
    ti_sysbios_knl_Queue_Elem elem;
    xdc_UInt32 timeout;
    xdc_UInt32 currTimeout;
    xdc_UInt32 period;
    volatile xdc_Bool active;
    ti_sysbios_knl_Clock_FuncPtr fxn;
    xdc_UArg arg;
} ti_sysbios_knl_Clock_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Clock_Object__ obj;
} ti_sysbios_knl_Clock_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Clock___VERS
    #define ti_sysbios_knl_Clock___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Clock___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Idle INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Queue INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Queue_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Queue_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Queue_Module__ ti_sysbios_knl_Queue_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Queue___VERS
    #define ti_sysbios_knl_Queue___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Queue___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Semaphore INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Semaphore_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Semaphore_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Semaphore_Module__ ti_sysbios_knl_Semaphore_Module__root__V;

/* <-- ti_sysbios_knl_Semaphore_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Semaphore___VERS
    #define ti_sysbios_knl_Semaphore___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Semaphore___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Swi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Swi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Swi_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Swi_Module__ ti_sysbios_knl_Swi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_knl_Swi_Object__ {
    ti_sysbios_knl_Queue_Elem qElem;
    ti_sysbios_knl_Swi_FuncPtr fxn;
    xdc_UArg arg0;
    xdc_UArg arg1;
    xdc_UInt priority;
    xdc_UInt mask;
    xdc_Bool posted;
    xdc_UInt initTrigger;
    xdc_UInt trigger;
    ti_sysbios_knl_Queue_Handle readyQ;
    __TA_ti_sysbios_knl_Swi_Instance_State__hookEnv hookEnv;
} ti_sysbios_knl_Swi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Swi_Object__ obj;
} ti_sysbios_knl_Swi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Swi___VERS
    #define ti_sysbios_knl_Swi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Swi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Task INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Task_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Task_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Task_Module__ ti_sysbios_knl_Task_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* Object__ */
typedef struct ti_sysbios_knl_Task_Object__ {
    ti_sysbios_knl_Queue_Elem qElem;
    volatile xdc_Int priority;
    xdc_UInt mask;
    xdc_Ptr context;
    ti_sysbios_knl_Task_Mode mode;
    ti_sysbios_knl_Task_PendElem* pendElem;
    xdc_SizeT stackSize;
    __TA_ti_sysbios_knl_Task_Instance_State__stack stack;
    xdc_runtime_IHeap_Handle stackHeap;
    ti_sysbios_knl_Task_FuncPtr fxn;
    xdc_UArg arg0;
    xdc_UArg arg1;
    xdc_Ptr env;
    __TA_ti_sysbios_knl_Task_Instance_State__hookEnv hookEnv;
    xdc_Bool vitalTaskFlag;
    ti_sysbios_knl_Queue_Handle readyQ;
    xdc_UInt curCoreId;
    xdc_UInt affinity;
} ti_sysbios_knl_Task_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Task_Object__ obj;
} ti_sysbios_knl_Task_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Task___VERS
    #define ti_sysbios_knl_Task___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Task___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Task_SupportProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.timers.timer64.Timer INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_timers_timer64_Timer_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_timers_timer64_Timer_Module__;

/* Module__root__V */
extern ti_sysbios_timers_timer64_Timer_Module__ ti_sysbios_timers_timer64_Timer_Module__root__V;

/* <-- ti_sysbios_timers_timer64_Timer_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_timers_timer64_Timer___VERS
    #define ti_sysbios_timers_timer64_Timer___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_timers_timer64_Timer___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.timers.timer64.Timer_TimerSupportProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Assert INTERNALS ========
 */


/*
 * ======== xdc.runtime.Core INTERNALS ========
 */


/*
 * ======== xdc.runtime.Defaults INTERNALS ========
 */


/*
 * ======== xdc.runtime.Diags INTERNALS ========
 */


/*
 * ======== xdc.runtime.Error INTERNALS ========
 */


/*
 * ======== xdc.runtime.Gate INTERNALS ========
 */


/*
 * ======== xdc.runtime.Log INTERNALS ========
 */


/*
 * ======== xdc.runtime.Main INTERNALS ========
 */


/*
 * ======== xdc.runtime.Main_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_Main_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_Main_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_Main_Module_GateProxy_Module__ xdc_runtime_Main_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_Main_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_Main_Module_GateProxy_Object__ obj;
} xdc_runtime_Main_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_Main_Module_GateProxy___VERS
    #define xdc_runtime_Main_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_Main_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.Memory INTERNALS ========
 */


/*
 * ======== xdc.runtime.Memory_HeapProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_Memory_HeapProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_Memory_HeapProxy_Module__;

/* Module__root__V */
extern xdc_runtime_Memory_HeapProxy_Module__ xdc_runtime_Memory_HeapProxy_Module__root__V;

/* <-- ti_sysbios_heaps_HeapMem_Object */

/* Object */
typedef ti_sysbios_heaps_HeapMem_Object__ xdc_runtime_Memory_HeapProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_Memory_HeapProxy_Object__ obj;
} xdc_runtime_Memory_HeapProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_Memory_HeapProxy___VERS
    #define xdc_runtime_Memory_HeapProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_Memory_HeapProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.Registry INTERNALS ========
 */


/*
 * ======== xdc.runtime.Startup INTERNALS ========
 */


/*
 * ======== xdc.runtime.SysMin INTERNALS ========
 */


/*
 * ======== xdc.runtime.System INTERNALS ========
 */


/*
 * ======== xdc.runtime.System_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_System_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_System_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_System_Module_GateProxy_Module__ xdc_runtime_System_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_System_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_System_Module_GateProxy_Object__ obj;
} xdc_runtime_System_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_System_Module_GateProxy___VERS
    #define xdc_runtime_System_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_System_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.System_SupportProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Text INTERNALS ========
 */


/*
 * ======== xdc.runtime.Timestamp INTERNALS ========
 */


/*
 * ======== xdc.runtime.Timestamp_SupportProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.tci6488.TimerSupport INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
__FAR__ const xdc_runtime_Types_Base ti_sysbios_interfaces_ITimerSupport_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== ti.sysbios.gates.GateHwi INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IGateProvider_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== ti.sysbios.gates.GateMutex INHERITS ========
 */



/*
 * ======== ti.sysbios.heaps.HeapMem INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IHeap_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== xdc.runtime.SysMin INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_ISystemSupport_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== xdc.runtime.Timestamp INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_ITimestampClient_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== ti.sysbios.family.c64p.tci6488.TimerSupport VTABLE ========
 */

/* Module__FXNS__C */
const ti_sysbios_family_c64p_tci6488_TimerSupport_Fxns__ ti_sysbios_family_c64p_tci6488_TimerSupport_Module__FXNS__C = {
    (void*)&ti_sysbios_interfaces_ITimerSupport_Interface__BASE__C, /* base__ */
    &ti_sysbios_family_c64p_tci6488_TimerSupport_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_family_c64p_tci6488_TimerSupport_enable__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x8032, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.gates.GateHwi VTABLE ========
 */

/* Module__FXNS__C */
const ti_sysbios_gates_GateHwi_Fxns__ ti_sysbios_gates_GateHwi_Module__FXNS__C = {
    (void*)&xdc_runtime_IGateProvider_Interface__BASE__C, /* base__ */
    &ti_sysbios_gates_GateHwi_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_gates_GateHwi_query__E,
    ti_sysbios_gates_GateHwi_enter__E,
    ti_sysbios_gates_GateHwi_leave__E,
    {
        ti_sysbios_gates_GateHwi_Object__create__S,
        ti_sysbios_gates_GateHwi_Object__delete__S,
        ti_sysbios_gates_GateHwi_Handle__label__S,
        0x8029, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.gates.GateMutex VTABLE ========
 */

/* Module__FXNS__C */
const ti_sysbios_gates_GateMutex_Fxns__ ti_sysbios_gates_GateMutex_Module__FXNS__C = {
    (void*)&xdc_runtime_IGateProvider_Interface__BASE__C, /* base__ */
    &ti_sysbios_gates_GateMutex_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_gates_GateMutex_query__E,
    ti_sysbios_gates_GateMutex_enter__E,
    ti_sysbios_gates_GateMutex_leave__E,
    {
        ti_sysbios_gates_GateMutex_Object__create__S,
        ti_sysbios_gates_GateMutex_Object__delete__S,
        ti_sysbios_gates_GateMutex_Handle__label__S,
        0x802a, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.heaps.HeapMem VTABLE ========
 */

/* Module__FXNS__C */
const ti_sysbios_heaps_HeapMem_Fxns__ ti_sysbios_heaps_HeapMem_Module__FXNS__C = {
    (void*)&xdc_runtime_IHeap_Interface__BASE__C, /* base__ */
    &ti_sysbios_heaps_HeapMem_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_heaps_HeapMem_alloc__E,
    ti_sysbios_heaps_HeapMem_free__E,
    ti_sysbios_heaps_HeapMem_isBlocking__E,
    ti_sysbios_heaps_HeapMem_getStats__E,
    {
        ti_sysbios_heaps_HeapMem_Object__create__S,
        ti_sysbios_heaps_HeapMem_Object__delete__S,
        ti_sysbios_heaps_HeapMem_Handle__label__S,
        0x8034, /* __mid */
    } /* __sfxns */
};


/*
 * ======== xdc.runtime.SysMin VTABLE ========
 */

/* Module__FXNS__C */
const xdc_runtime_SysMin_Fxns__ xdc_runtime_SysMin_Module__FXNS__C = {
    (void*)&xdc_runtime_ISystemSupport_Interface__BASE__C, /* base__ */
    &xdc_runtime_SysMin_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_SysMin_abort__E,
    xdc_runtime_SysMin_exit__E,
    xdc_runtime_SysMin_flush__E,
    xdc_runtime_SysMin_putch__E,
    xdc_runtime_SysMin_ready__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x800e, /* __mid */
    } /* __sfxns */
};


/*
 * ======== xdc.runtime.Timestamp VTABLE ========
 */

/* Module__FXNS__C */
const xdc_runtime_Timestamp_Fxns__ xdc_runtime_Timestamp_Module__FXNS__C = {
    (void*)&xdc_runtime_ITimestampClient_Interface__BASE__C, /* base__ */
    &xdc_runtime_Timestamp_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_Timestamp_get32__E,
    xdc_runtime_Timestamp_get64__E,
    xdc_runtime_Timestamp_getFreq__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x8010, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.BIOS DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_BIOS_Module_State__ {
    xdc_runtime_Types_FreqHz cpuFreq;
    xdc_UInt rtsGateCount;
    xdc_IArg rtsGateKey;
    ti_sysbios_BIOS_RtsGateProxy_Handle rtsGate;
    ti_sysbios_BIOS_ThreadType threadType;
    __TA_ti_sysbios_BIOS_Module_State__smpThreadType smpThreadType;
    ti_sysbios_BIOS_StartFuncPtr startFunc;
} ti_sysbios_BIOS_Module_State__;

/* --> ti_sysbios_BIOS_startFunc */
extern xdc_Void ti_sysbios_BIOS_startFunc(xdc_Void);

/* Module__state__V */
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V;


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c62.IntrinsicsSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c62.TaskSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c64p.EventCombiner DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_EventCombiner_Module_State__ {
    __TA_ti_sysbios_family_c64p_EventCombiner_Module_State__dispatchTab dispatchTab;
} ti_sysbios_family_c64p_EventCombiner_Module_State__;

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* Module__state__V */
ti_sysbios_family_c64p_EventCombiner_Module_State__ ti_sysbios_family_c64p_EventCombiner_Module__state__V;


/*
 * ======== ti.sysbios.family.c64p.Exception DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_Exception_Module_State__ {
    xdc_Bits32 efr;
    xdc_Bits32 nrp;
    xdc_Bits32 ntsr;
    xdc_Bits32 ierr;
    ti_sysbios_family_c64p_Exception_FuncPtr returnHook;
    ti_sysbios_family_c64p_Exception_Context* excContext;
    __TA_ti_sysbios_family_c64p_Exception_Module_State__scratch scratch;
    xdc_Char* isrStack;
} ti_sysbios_family_c64p_Exception_Module_State__;

/* Module__state__V */
ti_sysbios_family_c64p_Exception_Module_State__ ti_sysbios_family_c64p_Exception_Module__state__V;


/*
 * ======== ti.sysbios.family.c64p.Hwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_family_c64p_Hwi_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_Hwi_Module_State__ {
    __TA_ti_sysbios_family_c64p_Hwi_Module_State__intEvents intEvents;
    xdc_Bits16 ierMask;
    volatile xdc_Int intNum;
    xdc_Char* taskSP;
    xdc_Char* isrStack;
    xdc_Ptr vectorTableBase;
    xdc_Ptr bss;
    __TA_ti_sysbios_family_c64p_Hwi_Module_State__dispatchTable dispatchTable;
} ti_sysbios_family_c64p_Hwi_Module_State__;

/* --> ti_sysbios_family_c64p_Hwi0 */
extern void* ti_sysbios_family_c64p_Hwi0;

/* --> __TI_STATIC_BASE */
extern void* __TI_STATIC_BASE;

/* Module__state__V */
ti_sysbios_family_c64p_Hwi_Module_State__ ti_sysbios_family_c64p_Hwi_Module__state__V;

/* --> ti_sysbios_knl_Swi_disable__E */
extern xdc_UInt ti_sysbios_knl_Swi_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Swi_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Swi_restoreHwi__E(xdc_UInt);

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Task_restoreHwi__E(xdc_UInt);


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c64p.tci6488.TimerSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c66.Cache DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c66.tci66xx.CpIntc DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__ {
    __TA_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__controller controller;
    __TA_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__initSIER initSIER;
    __TA_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__hostIntToSysInt hostIntToSysInt;
    __TA_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__dispatchTab dispatchTab;
} ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__;

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_controller__A */
__T1_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__controller ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_controller__A[4];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_initSIER__A */
__T1_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__initSIER ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_initSIER__A[5];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_hostIntToSysInt__A */
__T1_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__hostIntToSysInt ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_hostIntToSysInt__A[76];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_unused */
extern xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused(xdc_UArg);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_dispatchTab__A */
__T1_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__dispatchTab ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_dispatchTab__A[160];

/* Module__state__V */
ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__ ti_sysbios_family_c66_tci66xx_CpIntc_Module__state__V;

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__A[160];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_0__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_0__A[25];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_1__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_1__A[25];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_2__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_2__A[25];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_3__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_3__A[25];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_4__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_4__A[25];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_5__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_5__A[25];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_6__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_6__A[25];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_7__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_7__A[25];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__A */
const __T2_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__A[8];

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_eventId__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_eventId ti_sysbios_family_c66_tci66xx_CpIntc_eventId__A[25];


/*
 * ======== ti.sysbios.gates.GateHwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_gates_GateHwi_Object__ ti_sysbios_gates_GateHwi_Object__table__V[1];


/*
 * ======== ti.sysbios.gates.GateMutex DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_gates_GateMutex_Object__ ti_sysbios_gates_GateMutex_Object__table__V[2];


/*
 * ======== ti.sysbios.hal.Hwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_hal_Hwi_Object__ ti_sysbios_hal_Hwi_Object__table__V[1];


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.Timer DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_hal_Timer_Object__ ti_sysbios_hal_Timer_Object__table__V[1];


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem DECLARATIONS ========
 */

#ifdef __ICC430__
    #pragma data_alignment=8
#endif
/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096];
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A, 8);
#endif
#ifdef __GNUC__
#if __GNUC__ >= 4
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096] __attribute__ ((aligned(8)));
#endif
#endif

/* Object__table__V */
ti_sysbios_heaps_HeapMem_Object__ ti_sysbios_heaps_HeapMem_Object__table__V[1];


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Clock DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_knl_Clock_Module_State__ {
    volatile xdc_UInt32 ticks;
    xdc_UInt swiCount;
    ti_sysbios_hal_Timer_Handle timer;
    ti_sysbios_knl_Swi_Handle swi;
    xdc_UInt32 periodCounts;
    volatile xdc_UInt numTickSkip;
    xdc_UInt32 skipsWorkFunc;
    xdc_Bool inWorkFunc;
    ti_sysbios_knl_Queue_Object__ Object_field_clockQ;
} ti_sysbios_knl_Clock_Module_State__;

/* Module__state__V */
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V;


/*
 * ======== ti.sysbios.knl.Idle DECLARATIONS ========
 */

/* --> ti_sysbios_hal_Hwi_checkStack */
extern xdc_Void ti_sysbios_hal_Hwi_checkStack(xdc_Void);

/* --> ti_sysbios_knl_Idle_funcList__A */
const __T1_ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__A[1];

/* --> ti_sysbios_knl_Idle_coreList__A */
const __T1_ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__A[1];


/*
 * ======== ti.sysbios.knl.Intrinsics DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Queue DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Semaphore DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Swi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Swi_Module_State__ {
    xdc_Bool locked;
    xdc_UInt curSet;
    xdc_UInt curTrigger;
    ti_sysbios_knl_Swi_Handle curSwi;
    ti_sysbios_knl_Queue_Handle curQ;
    __TA_ti_sysbios_knl_Swi_Module_State__readyQ readyQ;
    __TA_ti_sysbios_knl_Swi_Module_State__constructedSwis constructedSwis;
} ti_sysbios_knl_Swi_Module_State__;

/* --> ti_sysbios_knl_Swi_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Swi_Module_State__readyQ ti_sysbios_knl_Swi_Module_State_0_readyQ__A[16];

/* Module__state__V */
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V;

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restore__E */
extern xdc_Void ti_sysbios_knl_Task_restore__E(xdc_UInt);


/*
 * ======== ti.sysbios.knl.Task DECLARATIONS ========
 */

#ifdef __ICC430__
    #pragma data_alignment=8
#endif
/* --> ti_sysbios_knl_Task_Instance_State_0_stack__A */
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048];
#ifdef __ti__sect
    #pragma DATA_SECTION(ti_sysbios_knl_Task_Instance_State_0_stack__A, ".far:taskStackSection");
#endif
#ifdef __GNUC__
#if __GNUC__ >= 4
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048] __attribute__ ((section(".far:taskStackSection")));
#endif
#endif
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_knl_Task_Instance_State_0_stack__A, 8);
#endif
#ifdef __GNUC__
#if __GNUC__ >= 4
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048] __attribute__ ((aligned(8)));
#endif
#endif

/* --> ti_sysbios_knl_Task_Instance_State_0_hookEnv__A */
__T1_ti_sysbios_knl_Task_Instance_State__hookEnv ti_sysbios_knl_Task_Instance_State_0_hookEnv__A[1];

/* Object__table__V */
ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Task_Module_State__ {
    xdc_Bool locked;
    volatile xdc_UInt curSet;
    xdc_Bool workFlag;
    xdc_UInt vitalTasks;
    ti_sysbios_knl_Task_Handle curTask;
    ti_sysbios_knl_Queue_Handle curQ;
    __TA_ti_sysbios_knl_Task_Module_State__readyQ readyQ;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurSet smpCurSet;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurMask smpCurMask;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurTask smpCurTask;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurQ smpCurQ;
    __TA_ti_sysbios_knl_Task_Module_State__smpReadyQ smpReadyQ;
    __TA_ti_sysbios_knl_Task_Module_State__idleTask idleTask;
    __TA_ti_sysbios_knl_Task_Module_State__constructedTasks constructedTasks;
    ti_sysbios_knl_Queue_Object__ Object_field_inactiveQ;
    ti_sysbios_knl_Queue_Object__ Object_field_terminatedQ;
} ti_sysbios_knl_Task_Module_State__;

/* --> ti_sysbios_knl_Task_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Task_Module_State__readyQ ti_sysbios_knl_Task_Module_State_0_readyQ__A[16];

/* --> ti_sysbios_knl_Task_Module_State_0_idleTask__A */
__T1_ti_sysbios_knl_Task_Module_State__idleTask ti_sysbios_knl_Task_Module_State_0_idleTask__A[1];

/* Module__state__V */
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V;

/* --> ti_sysbios_knl_Task_checkStacks */
extern xdc_Void ti_sysbios_knl_Task_checkStacks(ti_sysbios_knl_Task_Handle,ti_sysbios_knl_Task_Handle);

/* --> ti_sysbios_knl_Task_hooks__A */
const __T1_ti_sysbios_knl_Task_hooks ti_sysbios_knl_Task_hooks__A[1];


/*
 * ======== ti.sysbios.knl.Task_SupportProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.timers.timer64.Timer DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_timers_timer64_Timer_Object__ ti_sysbios_timers_timer64_Timer_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_timers_timer64_Timer_Module_State__ {
    xdc_Bits32 availMask;
    __TA_ti_sysbios_timers_timer64_Timer_Module_State__intFreqs intFreqs;
    __TA_ti_sysbios_timers_timer64_Timer_Module_State__gctrl gctrl;
    __TA_ti_sysbios_timers_timer64_Timer_Module_State__device device;
    __TA_ti_sysbios_timers_timer64_Timer_Module_State__handles handles;
} ti_sysbios_timers_timer64_Timer_Module_State__;

/* --> ti_sysbios_timers_timer64_Timer_Module_State_0_intFreqs__A */
__T1_ti_sysbios_timers_timer64_Timer_Module_State__intFreqs ti_sysbios_timers_timer64_Timer_Module_State_0_intFreqs__A[16];

/* --> ti_sysbios_timers_timer64_Timer_Module_State_0_gctrl__A */
__T1_ti_sysbios_timers_timer64_Timer_Module_State__gctrl ti_sysbios_timers_timer64_Timer_Module_State_0_gctrl__A[16];

/* --> ti_sysbios_timers_timer64_Timer_Module_State_0_device__A */
__T1_ti_sysbios_timers_timer64_Timer_Module_State__device ti_sysbios_timers_timer64_Timer_Module_State_0_device__A[32];

/* --> ti_sysbios_timers_timer64_Timer_Module_State_0_handles__A */
__T1_ti_sysbios_timers_timer64_Timer_Module_State__handles ti_sysbios_timers_timer64_Timer_Module_State_0_handles__A[32];

/* Module__state__V */
ti_sysbios_timers_timer64_Timer_Module_State__ ti_sysbios_timers_timer64_Timer_Module__state__V;

/* --> ti_sysbios_timers_timer64_Timer_timerSettings__A */
const __T1_ti_sysbios_timers_timer64_Timer_timerSettings ti_sysbios_timers_timer64_Timer_timerSettings__A[16];


/*
 * ======== ti.sysbios.timers.timer64.Timer_TimerSupportProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Assert DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Core DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Defaults DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Diags DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Error DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Error_Module_State__ {
    xdc_UInt16 count;
} xdc_runtime_Error_Module_State__;

/* Module__state__V */
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V;


/*
 * ======== xdc.runtime.Gate DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Log DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Main DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Main_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Memory DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Memory_Module_State__ {
    xdc_SizeT maxDefaultTypeAlign;
} xdc_runtime_Memory_Module_State__;

/* Module__state__V */
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V;


/*
 * ======== xdc.runtime.Memory_HeapProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Registry DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Registry_Module_State__ {
    xdc_runtime_Registry_Desc* listHead;
    xdc_runtime_Types_ModuleId curId;
} xdc_runtime_Registry_Module_State__;

/* Module__state__V */
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V;


/*
 * ======== xdc.runtime.Startup DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Startup_Module_State__ {
    xdc_Int* stateTab;
    xdc_Bool execFlag;
    xdc_Bool rtsDoneFlag;
} xdc_runtime_Startup_Module_State__;

/* Module__state__V */
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V;

/* --> ti_sysbios_hal_Hwi_initStack */
extern xdc_Void ti_sysbios_hal_Hwi_initStack(xdc_Void);

/* --> xdc_runtime_Startup_firstFxns__A */
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[2];

/* --> xdc_runtime_Startup_lastFxns__A */
const __T1_xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__A[1];

/* --> xdc_runtime_System_Module_startup__E */
extern xdc_Int xdc_runtime_System_Module_startup__E(xdc_Int);

/* --> xdc_runtime_SysMin_Module_startup__E */
extern xdc_Int xdc_runtime_SysMin_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_EventCombiner_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_EventCombiner_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_Exception_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_Exception_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_TimestampProvider_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_TimestampProvider_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_startup__E */
extern xdc_Int ti_sysbios_family_c66_tci66xx_CpIntc_Module_startup__E(xdc_Int);

/* --> ti_sysbios_hal_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_hal_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_hal_Timer_Module_startup__E */
extern xdc_Int ti_sysbios_hal_Timer_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Clock_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Clock_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Swi_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Swi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Task_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Task_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c66_Cache_Module_startup__E */
extern xdc_Int ti_sysbios_family_c66_Cache_Module_startup__E(xdc_Int);

/* --> ti_sysbios_timers_timer64_Timer_Module_startup__E */
extern xdc_Int ti_sysbios_timers_timer64_Timer_Module_startup__E(xdc_Int);

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[14];

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[14];


/*
 * ======== xdc.runtime.SysMin DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_SysMin_Module_State__ {
    __TA_xdc_runtime_SysMin_Module_State__outbuf outbuf;
    xdc_UInt outidx;
    xdc_Bool wrapped;
} xdc_runtime_SysMin_Module_State__;

/* --> xdc_runtime_SysMin_Module_State_0_outbuf__A */
__T1_xdc_runtime_SysMin_Module_State__outbuf xdc_runtime_SysMin_Module_State_0_outbuf__A[1024];

/* Module__state__V */
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V;

/* --> xdc_runtime_SysMin_output__I */
extern xdc_Void xdc_runtime_SysMin_output__I(xdc_Char*,xdc_UInt);


/*
 * ======== xdc.runtime.System DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_System_Module_State__ {
    __TA_xdc_runtime_System_Module_State__atexitHandlers atexitHandlers;
    xdc_Int numAtexitHandlers;
    xdc_Int exitStatus;
} xdc_runtime_System_Module_State__;

/* --> xdc_runtime_System_Module_State_0_atexitHandlers__A */
__T1_xdc_runtime_System_Module_State__atexitHandlers xdc_runtime_System_Module_State_0_atexitHandlers__A[8];

/* Module__state__V */
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V;

/* --> xdc_runtime_System_printfExtend__I */
extern xdc_Int xdc_runtime_System_printfExtend__I(xdc_Char**,xdc_Char**,xdc_VaList*,xdc_runtime_System_ParseData*);


/*
 * ======== xdc.runtime.System_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.System_SupportProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Text DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Text_Module_State__ {
    xdc_Ptr charBase;
    xdc_Ptr nodeBase;
} xdc_runtime_Text_Module_State__;

/* Module__state__V */
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V;

/* --> xdc_runtime_Text_charTab__A */
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[5201];

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[53];


/*
 * ======== xdc.runtime.Timestamp DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Timestamp_SupportProxy DECLARATIONS ========
 */


/*
 * ======== OBJECT OFFSETS ========
 */

__FAR__ const xdc_SizeT ti_sysbios_gates_GateMutex_Instance_State_sem__O = offsetof(ti_sysbios_gates_GateMutex_Object__, Object_field_sem);


/*
 * ======== OBJECT OFFSETS ========
 */

__FAR__ const xdc_SizeT ti_sysbios_knl_Clock_Module_State_clockQ__O = offsetof(ti_sysbios_knl_Clock_Module_State__, Object_field_clockQ);


/*
 * ======== OBJECT OFFSETS ========
 */

__FAR__ const xdc_SizeT ti_sysbios_knl_Semaphore_Instance_State_pendQ__O = offsetof(ti_sysbios_knl_Semaphore_Object__, Object_field_pendQ);


/*
 * ======== OBJECT OFFSETS ========
 */

__FAR__ const xdc_SizeT ti_sysbios_knl_Task_Module_State_inactiveQ__O = offsetof(ti_sysbios_knl_Task_Module_State__, Object_field_inactiveQ);
__FAR__ const xdc_SizeT ti_sysbios_knl_Task_Module_State_terminatedQ__O = offsetof(ti_sysbios_knl_Task_Module_State__, Object_field_terminatedQ);


/*
 * ======== xdc.cfg.Program TEMPLATE ========
 */

/*
 *  ======== __ASM__ ========
 *  Define absolute path prefix for this executable's
 *  configuration generated files.
 */
xdc__META(__ASM__, "@(#)__ASM__ = /media/work__/F5/TMS320C6678-Benchmarks/benchmarks/img_conv_dma/Debug/configPkg/package/cfg/img_conv_dma_pe66");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = 66");

/*
 *  ======== __PLAT__ ========
 *  Define the name of the platform that can run this executable.  This
 *  symbol is used by platform independent "exec" commands
 */
xdc__META(__PLAT__, "@(#)__PLAT__ = evmc6678omp_ddr");

/*
 *  ======== __TARG__ ========
 *  Define the name of the target used to build this executable.
 */
xdc__META(__TARG__, "@(#)__TARG__ = ti.targets.elf.C66");

/*
 *  ======== __TRDR__ ========
 *  Define the name of the class that can read/parse this executable.
 */
xdc__META(__TRDR__, "@(#)__TRDR__ = ti.targets.omf.elf.Elf32");


/*
 * ======== xdc.runtime.Diags TEMPLATE ========
 */



/*
 * ======== xdc.runtime.Startup TEMPLATE ========
 */

/*
 *  ======== MODULE STARTUP DONE FUNCTIONS ========
 */
xdc_Bool xdc_runtime_System_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[0] < 0;
}
xdc_Bool xdc_runtime_SysMin_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[1] < 0;
}
xdc_Bool ti_sysbios_family_c64p_EventCombiner_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[2] < 0;
}
xdc_Bool ti_sysbios_family_c64p_Exception_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[3] < 0;
}
xdc_Bool ti_sysbios_family_c64p_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[4] < 0;
}
xdc_Bool ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[5] < 0;
}
xdc_Bool ti_sysbios_family_c66_tci66xx_CpIntc_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[6] < 0;
}
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[7] < 0;
}
xdc_Bool ti_sysbios_hal_Timer_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[8] < 0;
}
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[9] < 0;
}
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[10] < 0;
}
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[11] < 0;
}
xdc_Bool ti_sysbios_family_c66_Cache_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[12] < 0;
}
xdc_Bool ti_sysbios_timers_timer64_Timer_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[13] < 0;
}

/* 
 * Startup_exec__I is an internal entry point called by target/platform
 * boot code. Boot code is not brought into a partial-link assembly. So,
 * without this pragma, whole program optimizers would otherwise optimize-out
 * this function.
 */
#ifdef __ti__
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_exec__I);
#endif

#ifdef __GNUC__
#if __GNUC__ >= 4
xdc_Void xdc_runtime_Startup_exec__I(void) __attribute__ ((externally_visible));
#endif
#endif

/*
 *  ======== xdc_runtime_Startup_exec__I ========
 *  Initialize all used modules that have startup functions
 */
xdc_Void xdc_runtime_Startup_exec__I(void)
{
    xdc_Int state[14];
    xdc_runtime_Startup_startModsFxn__C(state, 14);
}

/*
 * ======== xdc.runtime.Reset TEMPLATE ========
 */

/* 
 * Startup_reset__I is an internal entry point called by target/platform
 * boot code. Boot code is not brought into a partial-link assembly. So,
 * without this pragma, whole program optimizers would otherwise optimize-out
 * this function.
 */
#ifdef __ti__
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_reset__I);
#endif

#ifdef __GNUC__
#if __GNUC__ >= 4
xdc_Void xdc_runtime_Startup_reset__I(void) __attribute__ ((externally_visible));
#endif
#endif


/*
 *  ======== xdc_runtime_Startup_reset__I ========
 *  This function is called by bootstrap initialization code as early as
 *  possible in the startup process.  This function calls all functions in
 *  the Reset.fxns array _as well as_ Startup.resetFxn (if it's non-NULL)
 */
xdc_Void xdc_runtime_Startup_reset__I(void)
{
}

/*
 * ======== xdc.runtime.System TEMPLATE ========
 */


#include <xdc/std.h>
#include <limits.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Text.h>
#include <xdc/runtime/Assert.h>

/*
 *  ======== System_printfExtend__I ========
 *  This function processes optional extended formats of printf.
 *  
 *  It returns the number of characters added to the result.
 *
 *  Precision (maximum string length) is not supported for %$S.
 *
 *  Right-justified (which is default) minimum width is not supported
 *  for %$L, %$S, or %$F.
 */
Int xdc_runtime_System_printfExtend__I(Char **pbuf, Char **pfmt, 
    VaList *pva, xdc_runtime_System_ParseData *parse)
{
    Char    *fmt = *pfmt;
    Int     res;
    Char    c;
    Bool    found = FALSE;
    
    /* 
     * Create a local variable 'va' to ensure that the dereference of
     * pva only occurs once.
     */
    va_list va = *pva;
    
    res = 0;

    c = *fmt++;
    *pfmt = *pfmt + 1;

    
    if (c == '$') {
        c = *fmt++;
        *pfmt = *pfmt + 1;
        
        if (c == 'L') {
            xdc_runtime_Types_Label *lab = parse->aFlag ? 
                (xdc_runtime_Types_Label *)iargToPtr(va_arg(va, IArg)) :
                (xdc_runtime_Types_Label *)va_arg(va, void *);
            
            /* 
             * Call Text_putLab to write out the label, taking the precision 
             * into account.
             */
            res = xdc_runtime_Text_putLab(lab, pbuf, parse->precis);
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr.
             */
            parse->len = 0;
            
            /* Update the minimum width field. */
            parse->width -= res;
            
            found = TRUE;
        }
        
        if (c == 'F') {
            xdc_runtime_Types_Site site;
            
            /* Retrieve the file name string from the argument list */
            site.file = parse->aFlag ? (Char *) iargToPtr(va_arg(va, IArg)) :
                                       (Char *) va_arg(va, Char *);
            
            /* Retrieve the line number from the argument list. */
            site.line = parse->aFlag ? (Int) va_arg(va, IArg) : 
                                       (Int) va_arg(va, Int);
            
            /* 
             * Omit the 'mod' field, set it to 0.
             * '0' is a safe sentinel value - the IDs for named modules are 
             * 0x8000 and higher, and the IDs for unnamed modules go from 0x1
             * to 0x7fff.
             */
            site.mod = 0;
            
            /* 
             * Call putSite to format the file and line number.
             * If a precision was specified, it will be used as the maximum
             * string lengrth.
             */
            res = xdc_runtime_Text_putSite(&site, pbuf, parse->precis);
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr.
             */
            parse->len = 0;
       
            /* Update the minimum width field */
            parse->width -= res;
            
            found = TRUE;
        }
        
        if (c == 'S') {
            /* Retrieve the format string from the argument list */
            parse->ptr = parse->aFlag ? 
                (Char *) iargToPtr(va_arg(va, IArg)) :
                (Char *) va_arg(va, Char *);
            
            /* Update pva before passing it to doPrint. */
            *pva = va;
            
            /* Perform the recursive format. System_doPrint does not advance
             * the buffer pointer, so it has to be done explicitly.
             */
            res = xdc_runtime_System_doPrint__I(*pbuf, parse->ptr, pva, parse->aFlag);
            if (*pbuf) {
                *pbuf += res;
            }
            
            /* Update the temporary variable with any changes to *pva */
            va = *pva;
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr
             */
            parse->len = 0;

            /* Update the minimum width field */
            parse->width -= res;
            
            /* Indicate that we were able to interpret the specifier */
            found = TRUE;
        }
        
    }

    if (c == 'f') {
        /* support arguments _after_ optional float support */
        if (parse->aFlag) {
            (void)va_arg(va, IArg);
        }
        else {
            (void)va_arg(va, double);
        }
    }    

    if (found == FALSE) {
        /* other character (like %) copy to output */
        *(parse->ptr) = c;
        parse->len = 1;
    }

    /*
     * Before returning, we must update the value of pva. We use a label here
     * so that all return points will go through this update.
     * The 'goto end' is here to ensure that there is always a reference to the
     * label (to avoid the compiler complaining). 
     */
    goto end; 
end:
    *pva = va;
    return (res);
}

/*
 * ======== xdc.runtime.SysMin TEMPLATE ========
 */


#if defined(__ti__) || (defined(gnu_targets_STD_) && defined(xdc_target__os_undefined))
extern int HOSTwrite(int, const char *, unsigned);
#elif defined(__ICC430__)
#include <yfuns.h>
#define HOSTwrite(x,y,z) __write((x),(unsigned char *)(y),(z))
#else
#include <stdio.h>
#endif

/*
 *  ======== SysMin_output__I ========
 *  HOSTWrite only writes a max of N chars at a time. The amount it writes
 *  is returned. This function loops until the entire buffer is written.
 *  Being a static function allows it to conditionally compile out.
 */
Void xdc_runtime_SysMin_output__I(Char *buf, UInt size)
{
#if defined(__ti__) || (defined(gnu_targets_STD_) && defined(xdc_target__os_undefined)) || defined (__ICC430__)
    Int printCount;
    
    while (size != 0) {
        printCount = HOSTwrite(1, buf, size);
        if ((printCount <= 0) || (printCount > size)) {
            break;  /* ensure we never get stuck in an infinite loop */
        }
        size -= printCount;
        buf = buf + printCount;
    }    
#else
    fwrite(buf, 1, size, stdout);
#endif
}

/*
 * ======== xdc.runtime.Text TEMPLATE ========
 */


/*
 *  ======== xdc_runtime_Text_visitRope__I ========
 *  This function is indirectly called within Text.c through
 *  the visitRopeFxn configuration parameter of xdc.runtime.Text.
 */
Void xdc_runtime_Text_visitRope__I(xdc_runtime_Text_RopeId rope,
    xdc_Fxn visFxn, xdc_Ptr visState)
{
    xdc_String stack[6];
    xdc_runtime_Text_visitRope2__I(rope, visFxn, visState, stack);
}


/*
 * ======== ti.sysbios.family.c64p.Hwi TEMPLATE ========
 */


asm("           .sect \".vecs\"         ");
asm("           .align 0x400            ");
asm("           .nocmp                  ");
asm("           .global ti_sysbios_family_c64p_Hwi0          ");
asm("ti_sysbios_family_c64p_Hwi0:                            ");
asm("           .global ti_sysbios_family_c64p_Hwi_int0         ");
asm("           .global _c_int00         ");
asm("ti_sysbios_family_c64p_Hwi_int0:                           ");
asm("           nop                     ");
asm("           nop                     ");
asm("           nop                     ");
asm("           mvkl    _c_int00, b0     ");
asm("           mvkh    _c_int00, b0     ");
asm("           b       b0              ");
asm("           nop                     ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int1         ");
asm("           .global ti_sysbios_family_c64p_Exception_dispatch__E         ");
asm("ti_sysbios_family_c64p_Hwi_int1:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     1, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Exception_dispatch__E, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Exception_dispatch__E, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int2         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int2         ");
asm("ti_sysbios_family_c64p_Hwi_int2:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     2, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int2, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int2, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int3         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int3         ");
asm("ti_sysbios_family_c64p_Hwi_int3:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     3, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int3, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int3, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int4         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int4         ");
asm("ti_sysbios_family_c64p_Hwi_int4:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     4, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int4, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int4, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int5         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int5         ");
asm("ti_sysbios_family_c64p_Hwi_int5:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     5, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int5, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int5, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int6         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int6         ");
asm("ti_sysbios_family_c64p_Hwi_int6:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     6, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int6, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int6, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int7         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int7         ");
asm("ti_sysbios_family_c64p_Hwi_int7:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     7, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int7, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int7, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int8         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int8         ");
asm("ti_sysbios_family_c64p_Hwi_int8:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     8, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int8, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int8, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int9         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int9         ");
asm("ti_sysbios_family_c64p_Hwi_int9:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     9, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int9, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int9, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int10         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int10         ");
asm("ti_sysbios_family_c64p_Hwi_int10:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     10, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int10, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int10, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int11         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int11         ");
asm("ti_sysbios_family_c64p_Hwi_int11:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     11, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int11, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int11, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int12         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int12         ");
asm("ti_sysbios_family_c64p_Hwi_int12:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     12, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int12, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int12, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int13         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int13         ");
asm("ti_sysbios_family_c64p_Hwi_int13:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     13, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int13, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int13, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int14         ");
asm("           .global ti_sysbios_family_c64p_Hwi_dispatchAlways         ");
asm("ti_sysbios_family_c64p_Hwi_int14:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     14, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int15         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int15         ");
asm("ti_sysbios_family_c64p_Hwi_int15:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     15, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int15, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int15, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");



/*
 * ======== ti.sysbios.BIOS TEMPLATE ========
 */

Void ti_sysbios_BIOS_exitFunc__I(Int);

extern Void ti_sysbios_BIOS_registerRTSLock();

Void ti_sysbios_BIOS_startFunc__I()
{
    xdc_runtime_System_atexit(
        (xdc_runtime_System_AtexitHandler)ti_sysbios_BIOS_exitFunc__I);
    ti_sysbios_BIOS_registerRTSLock();
    ti_sysbios_hal_Hwi_startup();
    ti_sysbios_hal_Timer_startup();
    ti_sysbios_knl_Swi_startup();
    ti_sysbios_knl_Task_startup();
}

#if defined(__ti__)
#include <_lock.h>
#endif

Void ti_sysbios_BIOS_exitFunc__I(Int notused)
{
    ti_sysbios_knl_Swi_disable();
    ti_sysbios_knl_Task_disable();
    ti_sysbios_BIOS_setThreadType(ti_sysbios_BIOS_ThreadType_Main);

#if defined(__ti__)
    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGate != NULL) {
        _register_lock(_nop);
        _register_unlock(_nop);
    }
#endif
}



#if defined(__ti__)

#pragma FUNC_EXT_CALLED(malloc);
#pragma FUNC_EXT_CALLED(memalign);
#pragma FUNC_EXT_CALLED(free);
#pragma FUNC_EXT_CALLED(calloc);
#pragma FUNC_EXT_CALLED(realloc);

#define ATTRIBUTE

#elif defined(__ICC430__)

#define ATTRIBUTE

#else

#define ATTRIBUTE __attribute__ ((used))

#endif


#include <xdc/std.h>

#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>

#if !defined(__ICC430__)
#include <stdlib.h>
#endif

#include <string.h>

/* malloc header */
typedef struct Header {
    Ptr   actualBuf;
    UArg  size;
} Header;

/*
 *  ======== malloc ========
 */
Void ATTRIBUTE *malloc(SizeT size)
{
    Header *packet;
    xdc_runtime_Error_Block eb;

    xdc_runtime_Error_init(&eb);

    if (size == 0) {
        return (NULL);
    }

    packet = (Header *)xdc_runtime_Memory_alloc(NULL,
        (SizeT)(size + sizeof(Header)), 0, &eb);

    if (packet == NULL) {
        return (NULL);
    }

    packet->actualBuf = (Ptr)packet;
    packet->size = size + sizeof(Header);

    return (packet + 1);
}

/*
 *  ======== memalign ========
 *  mirrors the memalign() function from the TI run-time library
 */
Void ATTRIBUTE *memalign(SizeT alignment, SizeT size)
{
    Header                      *packet;
    Void                        *tmp;
    xdc_runtime_Error_Block     eb;

    xdc_runtime_Error_init(&eb);

    if (size == 0) {
        return (NULL);
    }

    /*
     * If alignment is not a power of two or is less than the minimum
     * alignment of malloc(), then simply return what malloc() returns.
     * (same as behaviour as RTS library's memalign())
     * Note: HeapMem's header is the same as this header after it is raised
     * to a power of 2.
     */
    if (alignment <= sizeof(Header) || (alignment & (alignment-1))) {
        return malloc(size);
    }

    /*
     * Allocate 'align + size' so that we have room for the 'packet'
     * and can return an aligned buffer.
     */
    tmp = xdc_runtime_Memory_alloc(NULL, alignment + size,
        (SizeT)alignment, &eb);

    if (tmp == NULL) {
        return (NULL);
    }

    packet = (Header *)((char *)tmp + alignment - sizeof(Header));

    packet->actualBuf = tmp;
    packet->size = size + sizeof(Header);

    return (packet + 1);
}

/*
 *  ======== calloc ========
 */
Void ATTRIBUTE *calloc(SizeT nmemb, SizeT size)
{
    SizeT       nbytes;
    Ptr         retval;

    nbytes = nmemb * size;

    retval = malloc(nbytes);
    if (retval != NULL) {
        (Void)memset(retval, (Int)'\0', nbytes);
    }

    return (retval);
}

/*
 *  ======== free ========
 */
Void ATTRIBUTE free(Void *ptr)
{
    Header      *packet;

    if (ptr != NULL) {
        packet = ((Header *)ptr) - 1;

        xdc_runtime_Memory_free(NULL, (Ptr)packet->actualBuf,
            (packet->size + ((char*)packet - (char*)packet->actualBuf)));
    }
}

/*
 *  ======== realloc ========
 */
Void ATTRIBUTE *realloc(Void *ptr, SizeT size)
{
    Ptr         retval;
    Header      *packet;
    SizeT       oldSize;

    if (ptr == NULL) {
        retval = malloc(size);
    }
    else if (size == 0) {
        free(ptr);
        retval = NULL;
    }
    else {
        packet = (Header *)ptr - 1;
        retval = malloc(size);
        if (retval != NULL) {
            oldSize = packet->size - sizeof(Header);
            (Void)memcpy(retval, ptr, (size < oldSize) ? size : oldSize);
            free(ptr);
        }
    }

    return (retval);
}


/*
 * ======== ti.sysbios.Build TEMPLATE ========
 */


/*
 * ======== ti.sdo.edma3.rm.RM TEMPLATE ========
 */


/* Resource Manager Internal Header Files */
#include <ti/sdo/edma3/rm/src/edma3resmgr.h>

/**
 * Maximum Resource Manager Instances supported by the EDMA3 Package.
 * USE THE SAME VALUE FOR BOTH THE #DEFINE AND CONST UNSIGNED INT BELOW.
 */

/**
 * Maximum Resource Manager Instances supported by the EDMA3 Package.
 * This #define is needed for array declarations.
 */
#define MAX_EDMA3_RM_INSTANCES 8

/* This const is required to access this constant in other header files */
const unsigned int EDMA3_MAX_RM_INSTANCES = 8;

EDMA3_RM_InstanceInitConfig userInstInitConfigArray[EDMA3_MAX_EDMA3_INSTANCES][MAX_EDMA3_RM_INSTANCES];
EDMA3_RM_Instance resMgrInstanceArray[EDMA3_MAX_EDMA3_INSTANCES][MAX_EDMA3_RM_INSTANCES];


/* These pointers will be used to refer the above mentioned arrays. */
EDMA3_RM_Instance *resMgrInstance = (EDMA3_RM_Instance *)resMgrInstanceArray;
EDMA3_RM_InstanceInitConfig *userInitConfig = (EDMA3_RM_InstanceInitConfig *)userInstInitConfigArray;

/* Pointer to the above mentioned 2-D arrays, used for address calculation purpose */
EDMA3_RM_Instance *ptrRMIArray = (EDMA3_RM_Instance *)resMgrInstanceArray;
EDMA3_RM_InstanceInitConfig *ptrInitCfgArray = (EDMA3_RM_InstanceInitConfig *)userInstInitConfigArray;





/*
 * ======== ti.sysbios.hal.Hwi TEMPLATE ========
 */

#ifdef __ti__
    #pragma FUNC_EXT_CALLED(ti_sysbios_hal_Hwi_HwiProxy_disable__E);
    #pragma FUNC_EXT_CALLED(ti_sysbios_hal_Hwi_HwiProxy_enable__E);
    #pragma FUNC_EXT_CALLED(ti_sysbios_hal_Hwi_HwiProxy_restore__E);
#endif

/*
 * ======== ti.sysbios.knl.Clock TEMPLATE ========
 */

Void ti_sysbios_knl_Clock_doTick__I(UArg arg)
{
    /* update system time */
    (&ti_sysbios_knl_Clock_Module__state__V)->ticks++;

    ti_sysbios_knl_Clock_logTick__E();

    if (!ti_sysbios_knl_Queue_empty(ti_sysbios_knl_Clock_Module_State_clockQ())) {
        (&ti_sysbios_knl_Clock_Module__state__V)->swiCount++;

        ti_sysbios_knl_Swi_post((&ti_sysbios_knl_Clock_Module__state__V)->swi);

    }
}

/*
 * ======== ti.sysbios.BIOS INITIALIZERS ========
 */

/* Module__state__V */
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V = {
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x3b9aca00,  /* lo */
    },  /* cpuFreq */
    (xdc_UInt)0x0,  /* rtsGateCount */
    ((xdc_IArg)(0x0)),  /* rtsGateKey */
    (ti_sysbios_BIOS_RtsGateProxy_Handle)&ti_sysbios_gates_GateMutex_Object__table__V[1],  /* rtsGate */
    ti_sysbios_BIOS_ThreadType_Main,  /* threadType */
    ((void*)0),  /* smpThreadType */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_BIOS_startFunc)),  /* startFunc */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsEnabled ti_sysbios_BIOS_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsIncluded ti_sysbios_BIOS_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsMask ti_sysbios_BIOS_Module__diagsMask__C = ((CT__ti_sysbios_BIOS_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__gateObj ti_sysbios_BIOS_Module__gateObj__C = ((CT__ti_sysbios_BIOS_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__gatePrms ti_sysbios_BIOS_Module__gatePrms__C = ((CT__ti_sysbios_BIOS_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__id ti_sysbios_BIOS_Module__id__C = (xdc_Bits16)0x8018;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerDefined ti_sysbios_BIOS_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerObj ti_sysbios_BIOS_Module__loggerObj__C = ((CT__ti_sysbios_BIOS_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn0 ti_sysbios_BIOS_Module__loggerFxn0__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn1 ti_sysbios_BIOS_Module__loggerFxn1__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn2 ti_sysbios_BIOS_Module__loggerFxn2__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn4 ti_sysbios_BIOS_Module__loggerFxn4__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn8 ti_sysbios_BIOS_Module__loggerFxn8__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__startupDoneFxn ti_sysbios_BIOS_Module__startupDoneFxn__C = ((CT__ti_sysbios_BIOS_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_BIOS_Object__count ti_sysbios_BIOS_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_BIOS_Object__heap ti_sysbios_BIOS_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_BIOS_Object__sizeof ti_sysbios_BIOS_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_BIOS_Object__table ti_sysbios_BIOS_Object__table__C = 0;

/* smpEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_smpEnabled ti_sysbios_BIOS_smpEnabled__C = 0;

/* cpuFreq__C */
__FAR__ const CT__ti_sysbios_BIOS_cpuFreq ti_sysbios_BIOS_cpuFreq__C = {
    (xdc_Bits32)0x0,  /* hi */
    (xdc_Bits32)0x3b9aca00,  /* lo */
};

/* taskEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_taskEnabled ti_sysbios_BIOS_taskEnabled__C = 1;

/* swiEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_swiEnabled ti_sysbios_BIOS_swiEnabled__C = 1;

/* clockEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_clockEnabled ti_sysbios_BIOS_clockEnabled__C = 1;

/* heapSize__C */
__FAR__ const CT__ti_sysbios_BIOS_heapSize ti_sysbios_BIOS_heapSize__C = (xdc_SizeT)0x1000;

/* heapSection__C */
__FAR__ const CT__ti_sysbios_BIOS_heapSection ti_sysbios_BIOS_heapSection__C = 0;

/* heapTrackEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_heapTrackEnabled ti_sysbios_BIOS_heapTrackEnabled__C = 0;

/* installedErrorHook__C */
__FAR__ const CT__ti_sysbios_BIOS_installedErrorHook ti_sysbios_BIOS_installedErrorHook__C = ((CT__ti_sysbios_BIOS_installedErrorHook)((xdc_Fxn)xdc_runtime_Error_print__E));


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.family.c62.IntrinsicsSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__id ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C = (xdc_Bits16)0x802d;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__count ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__heap ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__table ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.c62.TaskSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsMask ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__gateObj ti_sysbios_family_c62_TaskSupport_Module__gateObj__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__gatePrms ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__id ti_sysbios_family_c62_TaskSupport_Module__id__C = (xdc_Bits16)0x802c;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerDefined ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerObj ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__count ti_sysbios_family_c62_TaskSupport_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__heap ti_sysbios_family_c62_TaskSupport_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__sizeof ti_sysbios_family_c62_TaskSupport_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__table ti_sysbios_family_c62_TaskSupport_Object__table__C = 0;

/* defaultStackSize__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_defaultStackSize ti_sysbios_family_c62_TaskSupport_defaultStackSize__C = (xdc_SizeT)0x800;

/* stackAlignment__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_stackAlignment ti_sysbios_family_c62_TaskSupport_stackAlignment__C = (xdc_UInt)0x8;


/*
 * ======== ti.sysbios.family.c64p.EventCombiner INITIALIZERS ========
 */

/* Module__state__V */
ti_sysbios_family_c64p_EventCombiner_Module_State__ ti_sysbios_family_c64p_EventCombiner_Module__state__V = {
    {
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x0)),  /* arg */
        },  /* [0] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1)),  /* arg */
        },  /* [1] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2)),  /* arg */
        },  /* [2] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3)),  /* arg */
        },  /* [3] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4)),  /* arg */
        },  /* [4] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5)),  /* arg */
        },  /* [5] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6)),  /* arg */
        },  /* [6] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7)),  /* arg */
        },  /* [7] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x8)),  /* arg */
        },  /* [8] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x9)),  /* arg */
        },  /* [9] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xa)),  /* arg */
        },  /* [10] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xb)),  /* arg */
        },  /* [11] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xc)),  /* arg */
        },  /* [12] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xd)),  /* arg */
        },  /* [13] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xe)),  /* arg */
        },  /* [14] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xf)),  /* arg */
        },  /* [15] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x10)),  /* arg */
        },  /* [16] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x11)),  /* arg */
        },  /* [17] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x12)),  /* arg */
        },  /* [18] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x13)),  /* arg */
        },  /* [19] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x14)),  /* arg */
        },  /* [20] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x15)),  /* arg */
        },  /* [21] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x16)),  /* arg */
        },  /* [22] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x17)),  /* arg */
        },  /* [23] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x18)),  /* arg */
        },  /* [24] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x19)),  /* arg */
        },  /* [25] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1a)),  /* arg */
        },  /* [26] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1b)),  /* arg */
        },  /* [27] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1c)),  /* arg */
        },  /* [28] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1d)),  /* arg */
        },  /* [29] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1e)),  /* arg */
        },  /* [30] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1f)),  /* arg */
        },  /* [31] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x20)),  /* arg */
        },  /* [32] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x21)),  /* arg */
        },  /* [33] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x22)),  /* arg */
        },  /* [34] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x23)),  /* arg */
        },  /* [35] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x24)),  /* arg */
        },  /* [36] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x25)),  /* arg */
        },  /* [37] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x26)),  /* arg */
        },  /* [38] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x27)),  /* arg */
        },  /* [39] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x28)),  /* arg */
        },  /* [40] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x29)),  /* arg */
        },  /* [41] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2a)),  /* arg */
        },  /* [42] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2b)),  /* arg */
        },  /* [43] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2c)),  /* arg */
        },  /* [44] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2d)),  /* arg */
        },  /* [45] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2e)),  /* arg */
        },  /* [46] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2f)),  /* arg */
        },  /* [47] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x30)),  /* arg */
        },  /* [48] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x31)),  /* arg */
        },  /* [49] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x32)),  /* arg */
        },  /* [50] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x33)),  /* arg */
        },  /* [51] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x34)),  /* arg */
        },  /* [52] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x35)),  /* arg */
        },  /* [53] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x36)),  /* arg */
        },  /* [54] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x37)),  /* arg */
        },  /* [55] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x38)),  /* arg */
        },  /* [56] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x39)),  /* arg */
        },  /* [57] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3a)),  /* arg */
        },  /* [58] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3b)),  /* arg */
        },  /* [59] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3c)),  /* arg */
        },  /* [60] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3d)),  /* arg */
        },  /* [61] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3e)),  /* arg */
        },  /* [62] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3f)),  /* arg */
        },  /* [63] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x40)),  /* arg */
        },  /* [64] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x41)),  /* arg */
        },  /* [65] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x42)),  /* arg */
        },  /* [66] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x43)),  /* arg */
        },  /* [67] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x44)),  /* arg */
        },  /* [68] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x45)),  /* arg */
        },  /* [69] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x46)),  /* arg */
        },  /* [70] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x47)),  /* arg */
        },  /* [71] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x48)),  /* arg */
        },  /* [72] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x49)),  /* arg */
        },  /* [73] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4a)),  /* arg */
        },  /* [74] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4b)),  /* arg */
        },  /* [75] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4c)),  /* arg */
        },  /* [76] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4d)),  /* arg */
        },  /* [77] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4e)),  /* arg */
        },  /* [78] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4f)),  /* arg */
        },  /* [79] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x50)),  /* arg */
        },  /* [80] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x51)),  /* arg */
        },  /* [81] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x52)),  /* arg */
        },  /* [82] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x53)),  /* arg */
        },  /* [83] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x54)),  /* arg */
        },  /* [84] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x55)),  /* arg */
        },  /* [85] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x56)),  /* arg */
        },  /* [86] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x57)),  /* arg */
        },  /* [87] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x58)),  /* arg */
        },  /* [88] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x59)),  /* arg */
        },  /* [89] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5a)),  /* arg */
        },  /* [90] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5b)),  /* arg */
        },  /* [91] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5c)),  /* arg */
        },  /* [92] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5d)),  /* arg */
        },  /* [93] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5e)),  /* arg */
        },  /* [94] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5f)),  /* arg */
        },  /* [95] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x60)),  /* arg */
        },  /* [96] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x61)),  /* arg */
        },  /* [97] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x62)),  /* arg */
        },  /* [98] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x63)),  /* arg */
        },  /* [99] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x64)),  /* arg */
        },  /* [100] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x65)),  /* arg */
        },  /* [101] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x66)),  /* arg */
        },  /* [102] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x67)),  /* arg */
        },  /* [103] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x68)),  /* arg */
        },  /* [104] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x69)),  /* arg */
        },  /* [105] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6a)),  /* arg */
        },  /* [106] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6b)),  /* arg */
        },  /* [107] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6c)),  /* arg */
        },  /* [108] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6d)),  /* arg */
        },  /* [109] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6e)),  /* arg */
        },  /* [110] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6f)),  /* arg */
        },  /* [111] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x70)),  /* arg */
        },  /* [112] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x71)),  /* arg */
        },  /* [113] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x72)),  /* arg */
        },  /* [114] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x73)),  /* arg */
        },  /* [115] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x74)),  /* arg */
        },  /* [116] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x75)),  /* arg */
        },  /* [117] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x76)),  /* arg */
        },  /* [118] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x77)),  /* arg */
        },  /* [119] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x78)),  /* arg */
        },  /* [120] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x79)),  /* arg */
        },  /* [121] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7a)),  /* arg */
        },  /* [122] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7b)),  /* arg */
        },  /* [123] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7c)),  /* arg */
        },  /* [124] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7d)),  /* arg */
        },  /* [125] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7e)),  /* arg */
        },  /* [126] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7f)),  /* arg */
        },  /* [127] */
    },  /* dispatchTab */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__diagsEnabled ti_sysbios_family_c64p_EventCombiner_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__diagsIncluded ti_sysbios_family_c64p_EventCombiner_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__diagsMask ti_sysbios_family_c64p_EventCombiner_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__gateObj ti_sysbios_family_c64p_EventCombiner_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__gatePrms ti_sysbios_family_c64p_EventCombiner_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__id ti_sysbios_family_c64p_EventCombiner_Module__id__C = (xdc_Bits16)0x8014;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerDefined ti_sysbios_family_c64p_EventCombiner_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerObj ti_sysbios_family_c64p_EventCombiner_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Object__count ti_sysbios_family_c64p_EventCombiner_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Object__heap ti_sysbios_family_c64p_EventCombiner_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Object__sizeof ti_sysbios_family_c64p_EventCombiner_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Object__table ti_sysbios_family_c64p_EventCombiner_Object__table__C = 0;

/* E_unpluggedEvent__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_E_unpluggedEvent ti_sysbios_family_c64p_EventCombiner_E_unpluggedEvent__C = (((xdc_runtime_Error_Id)2909) << 16 | 0);

/* EVTMASK__C */
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_EVTMASK ti_sysbios_family_c64p_EventCombiner_EVTMASK__C = {
    (xdc_Bits32)(-0x0 - 1),  /* [0] */
    (xdc_Bits32)(-0x0 - 1),  /* [1] */
    (xdc_Bits32)(-0x0 - 1),  /* [2] */
    (xdc_Bits32)(-0x0 - 1),  /* [3] */
};


/*
 * ======== ti.sysbios.family.c64p.Exception INITIALIZERS ========
 */

/* Module__state__V */
ti_sysbios_family_c64p_Exception_Module_State__ ti_sysbios_family_c64p_Exception_Module__state__V = {
    (xdc_Bits32)0x0,  /* efr */
    (xdc_Bits32)0x0,  /* nrp */
    (xdc_Bits32)0x0,  /* ntsr */
    (xdc_Bits32)0x0,  /* ierr */
    ((xdc_Void(*)(xdc_Void))0),  /* returnHook */
    ((ti_sysbios_family_c64p_Exception_Context*)0),  /* excContext */
    {
        (xdc_Char)0x0,  /* [0] */
        (xdc_Char)0x0,  /* [1] */
        (xdc_Char)0x0,  /* [2] */
        (xdc_Char)0x0,  /* [3] */
        (xdc_Char)0x0,  /* [4] */
        (xdc_Char)0x0,  /* [5] */
        (xdc_Char)0x0,  /* [6] */
        (xdc_Char)0x0,  /* [7] */
        (xdc_Char)0x0,  /* [8] */
        (xdc_Char)0x0,  /* [9] */
        (xdc_Char)0x0,  /* [10] */
        (xdc_Char)0x0,  /* [11] */
        (xdc_Char)0x0,  /* [12] */
        (xdc_Char)0x0,  /* [13] */
        (xdc_Char)0x0,  /* [14] */
        (xdc_Char)0x0,  /* [15] */
    },  /* scratch */
    ((xdc_Char*)0),  /* isrStack */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsEnabled ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C = (xdc_Bits32)0x190;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsIncluded ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C = (xdc_Bits32)0x190;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsMask ti_sysbios_family_c64p_Exception_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_Exception_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__gateObj ti_sysbios_family_c64p_Exception_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_Exception_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__gatePrms ti_sysbios_family_c64p_Exception_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_Exception_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__id ti_sysbios_family_c64p_Exception_Module__id__C = (xdc_Bits16)0x8015;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerDefined ti_sysbios_family_c64p_Exception_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerObj ti_sysbios_family_c64p_Exception_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn0 ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn1 ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn2 ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn4 ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn8 ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__startupDoneFxn ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_Exception_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__count ti_sysbios_family_c64p_Exception_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__heap ti_sysbios_family_c64p_Exception_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__sizeof ti_sysbios_family_c64p_Exception_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__table ti_sysbios_family_c64p_Exception_Object__table__C = 0;

/* E_exceptionMin__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_E_exceptionMin ti_sysbios_family_c64p_Exception_E_exceptionMin__C = (((xdc_runtime_Error_Id)2950) << 16 | 0);

/* E_exceptionMax__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_E_exceptionMax ti_sysbios_family_c64p_Exception_E_exceptionMax__C = (((xdc_runtime_Error_Id)3092) << 16 | 0);

/* enableExternalMPC__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_enableExternalMPC ti_sysbios_family_c64p_Exception_enableExternalMPC__C = 0;

/* enablePrint__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_enablePrint ti_sysbios_family_c64p_Exception_enablePrint__C = 1;

/* exceptionHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_exceptionHook ti_sysbios_family_c64p_Exception_exceptionHook__C = ((CT__ti_sysbios_family_c64p_Exception_exceptionHook)0);

/* internalHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_internalHook ti_sysbios_family_c64p_Exception_internalHook__C = ((CT__ti_sysbios_family_c64p_Exception_internalHook)0);

/* externalHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_externalHook ti_sysbios_family_c64p_Exception_externalHook__C = ((CT__ti_sysbios_family_c64p_Exception_externalHook)0);

/* nmiHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_nmiHook ti_sysbios_family_c64p_Exception_nmiHook__C = ((CT__ti_sysbios_family_c64p_Exception_nmiHook)0);

/* returnHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_returnHook ti_sysbios_family_c64p_Exception_returnHook__C = ((CT__ti_sysbios_family_c64p_Exception_returnHook)0);


/*
 * ======== ti.sysbios.family.c64p.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c64p_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_family_c64p_Hwi_Params ti_sysbios_family_c64p_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_c64p_Hwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_c64p_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)0x0,  /* priority */
    (xdc_Bits16)0x0,  /* disableMask */
    (xdc_Bits16)0x0,  /* restoreMask */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_c64p_Hwi_Module__ ti_sysbios_family_c64p_Hwi_Module__root__V = {
    {&ti_sysbios_family_c64p_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_c64p_Hwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_family_c64p_Hwi_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (xdc_Bits16)0x4000,  /* disableMask */
        (xdc_Bits16)0x4000,  /* restoreMask */
        ((xdc_UArg)0),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_doTick__I)),  /* fxn */
        ((xdc_UArg)0),  /* irp */
        ((void*)0),  /* hookEnv */
    },
};

/* Module__state__V */
ti_sysbios_family_c64p_Hwi_Module_State__ ti_sysbios_family_c64p_Hwi_Module__state__V = {
    {
        (xdc_Char)(-0x0 - 1),  /* [0] */
        (xdc_Char)(-0x0 - 1),  /* [1] */
        (xdc_Char)(-0x0 - 1),  /* [2] */
        (xdc_Char)(-0x0 - 1),  /* [3] */
        (xdc_Char)(-0x0 - 1),  /* [4] */
        (xdc_Char)(-0x0 - 1),  /* [5] */
        (xdc_Char)(-0x0 - 1),  /* [6] */
        (xdc_Char)(-0x0 - 1),  /* [7] */
        (xdc_Char)(-0x0 - 1),  /* [8] */
        (xdc_Char)(-0x0 - 1),  /* [9] */
        (xdc_Char)(-0x0 - 1),  /* [10] */
        (xdc_Char)(-0x0 - 1),  /* [11] */
        (xdc_Char)(-0x0 - 1),  /* [12] */
        (xdc_Char)(-0x0 - 1),  /* [13] */
        (xdc_Char)0x40,  /* [14] */
        (xdc_Char)(-0x0 - 1),  /* [15] */
    },  /* intEvents */
    (xdc_Bits16)0x4003,  /* ierMask */
    (xdc_Int)0x0,  /* intNum */
    ((xdc_Char*)0),  /* taskSP */
    ((xdc_Char*)0),  /* isrStack */
    ((xdc_Ptr)((void*)&ti_sysbios_family_c64p_Hwi0)),  /* vectorTableBase */
    ((xdc_Ptr)((void*)&__TI_STATIC_BASE)),  /* bss */
    {
        0,  /* [0] */
        0,  /* [1] */
        0,  /* [2] */
        0,  /* [3] */
        0,  /* [4] */
        0,  /* [5] */
        0,  /* [6] */
        0,  /* [7] */
        0,  /* [8] */
        0,  /* [9] */
        0,  /* [10] */
        0,  /* [11] */
        0,  /* [12] */
        0,  /* [13] */
        (ti_sysbios_family_c64p_Hwi_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[0],  /* [14] */
        0,  /* [15] */
    },  /* dispatchTable */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsEnabled ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsIncluded ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsMask ti_sysbios_family_c64p_Hwi_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__gateObj ti_sysbios_family_c64p_Hwi_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__gatePrms ti_sysbios_family_c64p_Hwi_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__id ti_sysbios_family_c64p_Hwi_Module__id__C = (xdc_Bits16)0x8016;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerDefined ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerObj ti_sysbios_family_c64p_Hwi_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn0 ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn1 ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn2 ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn4 ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn8 ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__count ti_sysbios_family_c64p_Hwi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__heap ti_sysbios_family_c64p_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__sizeof ti_sysbios_family_c64p_Hwi_Object__sizeof__C = sizeof(ti_sysbios_family_c64p_Hwi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__table ti_sysbios_family_c64p_Hwi_Object__table__C = ti_sysbios_family_c64p_Hwi_Object__table__V;

/* dispatcherAutoNestingSupport__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* E_alreadyDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_E_alreadyDefined ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C = (((xdc_runtime_Error_Id)3134) << 16 | 0);

/* E_handleNotFound__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_E_handleNotFound ti_sysbios_family_c64p_Hwi_E_handleNotFound__C = (((xdc_runtime_Error_Id)3182) << 16 | 0);

/* LM_begin__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_LM_begin ti_sysbios_family_c64p_Hwi_LM_begin__C = (((xdc_runtime_Log_Event)3877) << 16 | 768);

/* LD_end__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_LD_end ti_sysbios_family_c64p_Hwi_LD_end__C = (((xdc_runtime_Log_Event)3947) << 16 | 512);

/* enableException__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_enableException ti_sysbios_family_c64p_Hwi_enableException__C = 1;

/* swiDisable__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_swiDisable ti_sysbios_family_c64p_Hwi_swiDisable__C = ((CT__ti_sysbios_family_c64p_Hwi_swiDisable)((xdc_Fxn)ti_sysbios_knl_Swi_disable__E));

/* swiRestoreHwi__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_swiRestoreHwi ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C = ((CT__ti_sysbios_family_c64p_Hwi_swiRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Swi_restoreHwi__E));

/* taskDisable__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_taskDisable ti_sysbios_family_c64p_Hwi_taskDisable__C = ((CT__ti_sysbios_family_c64p_Hwi_taskDisable)((xdc_Fxn)ti_sysbios_knl_Task_disable__E));

/* taskRestoreHwi__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_taskRestoreHwi ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C = ((CT__ti_sysbios_family_c64p_Hwi_taskRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Task_restoreHwi__E));

/* hooks__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_hooks ti_sysbios_family_c64p_Hwi_hooks__C = {0, 0};


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__gateObj ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__id ti_sysbios_family_c64p_TimestampProvider_Module__id__C = (xdc_Bits16)0x8017;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__count ti_sysbios_family_c64p_TimestampProvider_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__heap ti_sysbios_family_c64p_TimestampProvider_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__sizeof ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__table ti_sysbios_family_c64p_TimestampProvider_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.c64p.tci6488.TimerSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsEnabled ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsIncluded ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsMask ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gateObj ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gatePrms ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__id ti_sysbios_family_c64p_tci6488_TimerSupport_Module__id__C = (xdc_Bits16)0x8032;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerDefined ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerObj ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn0 ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn1 ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn2 ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn4 ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn8 ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__startupDoneFxn ti_sysbios_family_c64p_tci6488_TimerSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Object__count ti_sysbios_family_c64p_tci6488_TimerSupport_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Object__heap ti_sysbios_family_c64p_tci6488_TimerSupport_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Object__sizeof ti_sysbios_family_c64p_tci6488_TimerSupport_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_tci6488_TimerSupport_Object__table ti_sysbios_family_c64p_tci6488_TimerSupport_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.c66.Cache INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__diagsEnabled ti_sysbios_family_c66_Cache_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__diagsIncluded ti_sysbios_family_c66_Cache_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__diagsMask ti_sysbios_family_c66_Cache_Module__diagsMask__C = ((CT__ti_sysbios_family_c66_Cache_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__gateObj ti_sysbios_family_c66_Cache_Module__gateObj__C = ((CT__ti_sysbios_family_c66_Cache_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__gatePrms ti_sysbios_family_c66_Cache_Module__gatePrms__C = ((CT__ti_sysbios_family_c66_Cache_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__id ti_sysbios_family_c66_Cache_Module__id__C = (xdc_Bits16)0x8027;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerDefined ti_sysbios_family_c66_Cache_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerObj ti_sysbios_family_c66_Cache_Module__loggerObj__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn0 ti_sysbios_family_c66_Cache_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn1 ti_sysbios_family_c66_Cache_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn2 ti_sysbios_family_c66_Cache_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn4 ti_sysbios_family_c66_Cache_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn8 ti_sysbios_family_c66_Cache_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__startupDoneFxn ti_sysbios_family_c66_Cache_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c66_Cache_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Object__count ti_sysbios_family_c66_Cache_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Object__heap ti_sysbios_family_c66_Cache_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Object__sizeof ti_sysbios_family_c66_Cache_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_Object__table ti_sysbios_family_c66_Cache_Object__table__C = 0;

/* initSize__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_initSize ti_sysbios_family_c66_Cache_initSize__C = {
    ti_sysbios_family_c66_Cache_L1Size_32K,  /* l1pSize */
    ti_sysbios_family_c66_Cache_L1Size_32K,  /* l1dSize */
    ti_sysbios_family_c66_Cache_L2Size_256K,  /* l2Size */
};

/* atomicBlockSize__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_atomicBlockSize ti_sysbios_family_c66_Cache_atomicBlockSize__C = (xdc_UInt32)0x400;

/* marvalues__C */
__FAR__ const CT__ti_sysbios_family_c66_Cache_marvalues ti_sysbios_family_c66_Cache_marvalues__C = {
    (xdc_UInt32)0x1,  /* [0] */
    (xdc_UInt32)0x0,  /* [1] */
    (xdc_UInt32)0x0,  /* [2] */
    (xdc_UInt32)0x0,  /* [3] */
    (xdc_UInt32)0x0,  /* [4] */
    (xdc_UInt32)0x0,  /* [5] */
    (xdc_UInt32)0x0,  /* [6] */
    (xdc_UInt32)0x0,  /* [7] */
    (xdc_UInt32)0x0,  /* [8] */
    (xdc_UInt32)0x0,  /* [9] */
    (xdc_UInt32)0x0,  /* [10] */
    (xdc_UInt32)0x0,  /* [11] */
    (xdc_UInt32)0xd,  /* [12] */
    (xdc_UInt32)0xd,  /* [13] */
    (xdc_UInt32)0xd,  /* [14] */
    (xdc_UInt32)0xd,  /* [15] */
    (xdc_UInt32)0xc,  /* [16] */
    (xdc_UInt32)0xc,  /* [17] */
    (xdc_UInt32)0xc,  /* [18] */
    (xdc_UInt32)0xc,  /* [19] */
    (xdc_UInt32)0xc,  /* [20] */
    (xdc_UInt32)0xc,  /* [21] */
    (xdc_UInt32)0xc,  /* [22] */
    (xdc_UInt32)0xc,  /* [23] */
    (xdc_UInt32)0xc,  /* [24] */
    (xdc_UInt32)0xc,  /* [25] */
    (xdc_UInt32)0xc,  /* [26] */
    (xdc_UInt32)0xc,  /* [27] */
    (xdc_UInt32)0xc,  /* [28] */
    (xdc_UInt32)0xc,  /* [29] */
    (xdc_UInt32)0xc,  /* [30] */
    (xdc_UInt32)0xc,  /* [31] */
    (xdc_UInt32)0xc,  /* [32] */
    (xdc_UInt32)0xc,  /* [33] */
    (xdc_UInt32)0xc,  /* [34] */
    (xdc_UInt32)0xc,  /* [35] */
    (xdc_UInt32)0xc,  /* [36] */
    (xdc_UInt32)0xc,  /* [37] */
    (xdc_UInt32)0xc,  /* [38] */
    (xdc_UInt32)0xc,  /* [39] */
    (xdc_UInt32)0xc,  /* [40] */
    (xdc_UInt32)0xc,  /* [41] */
    (xdc_UInt32)0xc,  /* [42] */
    (xdc_UInt32)0xc,  /* [43] */
    (xdc_UInt32)0xc,  /* [44] */
    (xdc_UInt32)0xc,  /* [45] */
    (xdc_UInt32)0xc,  /* [46] */
    (xdc_UInt32)0xc,  /* [47] */
    (xdc_UInt32)0xc,  /* [48] */
    (xdc_UInt32)0xc,  /* [49] */
    (xdc_UInt32)0xc,  /* [50] */
    (xdc_UInt32)0xc,  /* [51] */
    (xdc_UInt32)0xc,  /* [52] */
    (xdc_UInt32)0xc,  /* [53] */
    (xdc_UInt32)0xc,  /* [54] */
    (xdc_UInt32)0xc,  /* [55] */
    (xdc_UInt32)0xc,  /* [56] */
    (xdc_UInt32)0xc,  /* [57] */
    (xdc_UInt32)0xc,  /* [58] */
    (xdc_UInt32)0xc,  /* [59] */
    (xdc_UInt32)0xc,  /* [60] */
    (xdc_UInt32)0xc,  /* [61] */
    (xdc_UInt32)0xc,  /* [62] */
    (xdc_UInt32)0xc,  /* [63] */
    (xdc_UInt32)0xc,  /* [64] */
    (xdc_UInt32)0xc,  /* [65] */
    (xdc_UInt32)0xc,  /* [66] */
    (xdc_UInt32)0xc,  /* [67] */
    (xdc_UInt32)0xc,  /* [68] */
    (xdc_UInt32)0xc,  /* [69] */
    (xdc_UInt32)0xc,  /* [70] */
    (xdc_UInt32)0xc,  /* [71] */
    (xdc_UInt32)0xc,  /* [72] */
    (xdc_UInt32)0xc,  /* [73] */
    (xdc_UInt32)0xc,  /* [74] */
    (xdc_UInt32)0xc,  /* [75] */
    (xdc_UInt32)0xc,  /* [76] */
    (xdc_UInt32)0xc,  /* [77] */
    (xdc_UInt32)0xc,  /* [78] */
    (xdc_UInt32)0xc,  /* [79] */
    (xdc_UInt32)0xc,  /* [80] */
    (xdc_UInt32)0xc,  /* [81] */
    (xdc_UInt32)0xc,  /* [82] */
    (xdc_UInt32)0xc,  /* [83] */
    (xdc_UInt32)0xc,  /* [84] */
    (xdc_UInt32)0xc,  /* [85] */
    (xdc_UInt32)0xc,  /* [86] */
    (xdc_UInt32)0xc,  /* [87] */
    (xdc_UInt32)0xc,  /* [88] */
    (xdc_UInt32)0xc,  /* [89] */
    (xdc_UInt32)0xc,  /* [90] */
    (xdc_UInt32)0xc,  /* [91] */
    (xdc_UInt32)0xc,  /* [92] */
    (xdc_UInt32)0xc,  /* [93] */
    (xdc_UInt32)0xc,  /* [94] */
    (xdc_UInt32)0xc,  /* [95] */
    (xdc_UInt32)0xc,  /* [96] */
    (xdc_UInt32)0xc,  /* [97] */
    (xdc_UInt32)0xc,  /* [98] */
    (xdc_UInt32)0xc,  /* [99] */
    (xdc_UInt32)0xc,  /* [100] */
    (xdc_UInt32)0xc,  /* [101] */
    (xdc_UInt32)0xc,  /* [102] */
    (xdc_UInt32)0xc,  /* [103] */
    (xdc_UInt32)0xc,  /* [104] */
    (xdc_UInt32)0xc,  /* [105] */
    (xdc_UInt32)0xc,  /* [106] */
    (xdc_UInt32)0xc,  /* [107] */
    (xdc_UInt32)0xc,  /* [108] */
    (xdc_UInt32)0xc,  /* [109] */
    (xdc_UInt32)0xc,  /* [110] */
    (xdc_UInt32)0xc,  /* [111] */
    (xdc_UInt32)0xc,  /* [112] */
    (xdc_UInt32)0xc,  /* [113] */
    (xdc_UInt32)0xc,  /* [114] */
    (xdc_UInt32)0xc,  /* [115] */
    (xdc_UInt32)0xc,  /* [116] */
    (xdc_UInt32)0xc,  /* [117] */
    (xdc_UInt32)0xc,  /* [118] */
    (xdc_UInt32)0xc,  /* [119] */
    (xdc_UInt32)0xc,  /* [120] */
    (xdc_UInt32)0xc,  /* [121] */
    (xdc_UInt32)0xc,  /* [122] */
    (xdc_UInt32)0xc,  /* [123] */
    (xdc_UInt32)0xc,  /* [124] */
    (xdc_UInt32)0xc,  /* [125] */
    (xdc_UInt32)0xc,  /* [126] */
    (xdc_UInt32)0xc,  /* [127] */
    (xdc_UInt32)0x3,  /* [128] */
    (xdc_UInt32)0x3,  /* [129] */
    (xdc_UInt32)0x3,  /* [130] */
    (xdc_UInt32)0x3,  /* [131] */
    (xdc_UInt32)0x3,  /* [132] */
    (xdc_UInt32)0x3,  /* [133] */
    (xdc_UInt32)0x3,  /* [134] */
    (xdc_UInt32)0x3,  /* [135] */
    (xdc_UInt32)0x3,  /* [136] */
    (xdc_UInt32)0x3,  /* [137] */
    (xdc_UInt32)0x3,  /* [138] */
    (xdc_UInt32)0x3,  /* [139] */
    (xdc_UInt32)0x3,  /* [140] */
    (xdc_UInt32)0x3,  /* [141] */
    (xdc_UInt32)0x3,  /* [142] */
    (xdc_UInt32)0x3,  /* [143] */
    (xdc_UInt32)0x3,  /* [144] */
    (xdc_UInt32)0x3,  /* [145] */
    (xdc_UInt32)0x3,  /* [146] */
    (xdc_UInt32)0x3,  /* [147] */
    (xdc_UInt32)0x3,  /* [148] */
    (xdc_UInt32)0x3,  /* [149] */
    (xdc_UInt32)0x3,  /* [150] */
    (xdc_UInt32)0x3,  /* [151] */
    (xdc_UInt32)0x3,  /* [152] */
    (xdc_UInt32)0x3,  /* [153] */
    (xdc_UInt32)0x3,  /* [154] */
    (xdc_UInt32)0x3,  /* [155] */
    (xdc_UInt32)0x3,  /* [156] */
    (xdc_UInt32)0x3,  /* [157] */
    (xdc_UInt32)0x3,  /* [158] */
    (xdc_UInt32)0x3,  /* [159] */
    (xdc_UInt32)0xd,  /* [160] */
    (xdc_UInt32)0xc,  /* [161] */
    (xdc_UInt32)0xc,  /* [162] */
    (xdc_UInt32)0xc,  /* [163] */
    (xdc_UInt32)0xc,  /* [164] */
    (xdc_UInt32)0xc,  /* [165] */
    (xdc_UInt32)0xc,  /* [166] */
    (xdc_UInt32)0xc,  /* [167] */
    (xdc_UInt32)0xc,  /* [168] */
    (xdc_UInt32)0xc,  /* [169] */
    (xdc_UInt32)0xc,  /* [170] */
    (xdc_UInt32)0xc,  /* [171] */
    (xdc_UInt32)0xc,  /* [172] */
    (xdc_UInt32)0xc,  /* [173] */
    (xdc_UInt32)0xc,  /* [174] */
    (xdc_UInt32)0xc,  /* [175] */
    (xdc_UInt32)0xc,  /* [176] */
    (xdc_UInt32)0xc,  /* [177] */
    (xdc_UInt32)0xc,  /* [178] */
    (xdc_UInt32)0xc,  /* [179] */
    (xdc_UInt32)0xc,  /* [180] */
    (xdc_UInt32)0xc,  /* [181] */
    (xdc_UInt32)0xc,  /* [182] */
    (xdc_UInt32)0xc,  /* [183] */
    (xdc_UInt32)0xc,  /* [184] */
    (xdc_UInt32)0xc,  /* [185] */
    (xdc_UInt32)0xc,  /* [186] */
    (xdc_UInt32)0xc,  /* [187] */
    (xdc_UInt32)0xc,  /* [188] */
    (xdc_UInt32)0xc,  /* [189] */
    (xdc_UInt32)0xc,  /* [190] */
    (xdc_UInt32)0xc,  /* [191] */
    (xdc_UInt32)0xc,  /* [192] */
    (xdc_UInt32)0xc,  /* [193] */
    (xdc_UInt32)0xc,  /* [194] */
    (xdc_UInt32)0xc,  /* [195] */
    (xdc_UInt32)0xc,  /* [196] */
    (xdc_UInt32)0xc,  /* [197] */
    (xdc_UInt32)0xc,  /* [198] */
    (xdc_UInt32)0xc,  /* [199] */
    (xdc_UInt32)0xc,  /* [200] */
    (xdc_UInt32)0xc,  /* [201] */
    (xdc_UInt32)0xc,  /* [202] */
    (xdc_UInt32)0xc,  /* [203] */
    (xdc_UInt32)0xc,  /* [204] */
    (xdc_UInt32)0xc,  /* [205] */
    (xdc_UInt32)0xc,  /* [206] */
    (xdc_UInt32)0xc,  /* [207] */
    (xdc_UInt32)0xc,  /* [208] */
    (xdc_UInt32)0xc,  /* [209] */
    (xdc_UInt32)0xc,  /* [210] */
    (xdc_UInt32)0xc,  /* [211] */
    (xdc_UInt32)0xc,  /* [212] */
    (xdc_UInt32)0xc,  /* [213] */
    (xdc_UInt32)0xc,  /* [214] */
    (xdc_UInt32)0xc,  /* [215] */
    (xdc_UInt32)0xc,  /* [216] */
    (xdc_UInt32)0xc,  /* [217] */
    (xdc_UInt32)0xc,  /* [218] */
    (xdc_UInt32)0xc,  /* [219] */
    (xdc_UInt32)0xc,  /* [220] */
    (xdc_UInt32)0xc,  /* [221] */
    (xdc_UInt32)0xc,  /* [222] */
    (xdc_UInt32)0xc,  /* [223] */
    (xdc_UInt32)0xc,  /* [224] */
    (xdc_UInt32)0xc,  /* [225] */
    (xdc_UInt32)0xc,  /* [226] */
    (xdc_UInt32)0xc,  /* [227] */
    (xdc_UInt32)0xc,  /* [228] */
    (xdc_UInt32)0xc,  /* [229] */
    (xdc_UInt32)0xc,  /* [230] */
    (xdc_UInt32)0xc,  /* [231] */
    (xdc_UInt32)0xc,  /* [232] */
    (xdc_UInt32)0xc,  /* [233] */
    (xdc_UInt32)0xc,  /* [234] */
    (xdc_UInt32)0xc,  /* [235] */
    (xdc_UInt32)0xc,  /* [236] */
    (xdc_UInt32)0xc,  /* [237] */
    (xdc_UInt32)0xc,  /* [238] */
    (xdc_UInt32)0xc,  /* [239] */
    (xdc_UInt32)0xc,  /* [240] */
    (xdc_UInt32)0xc,  /* [241] */
    (xdc_UInt32)0xc,  /* [242] */
    (xdc_UInt32)0xc,  /* [243] */
    (xdc_UInt32)0xc,  /* [244] */
    (xdc_UInt32)0xc,  /* [245] */
    (xdc_UInt32)0xc,  /* [246] */
    (xdc_UInt32)0xc,  /* [247] */
    (xdc_UInt32)0xc,  /* [248] */
    (xdc_UInt32)0xc,  /* [249] */
    (xdc_UInt32)0xc,  /* [250] */
    (xdc_UInt32)0xc,  /* [251] */
    (xdc_UInt32)0xc,  /* [252] */
    (xdc_UInt32)0xc,  /* [253] */
    (xdc_UInt32)0xc,  /* [254] */
    (xdc_UInt32)0xc,  /* [255] */
};


/*
 * ======== ti.sysbios.family.c66.tci66xx.CpIntc INITIALIZERS ========
 */

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_controller__A */
__T1_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__controller ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_controller__A[4] = {
    ((ti_sysbios_family_c66_tci66xx_CpIntc_RegisterMap*)((void*)0x2600000)),  /* [0] */
    ((ti_sysbios_family_c66_tci66xx_CpIntc_RegisterMap*)((void*)0x2604000)),  /* [1] */
    ((ti_sysbios_family_c66_tci66xx_CpIntc_RegisterMap*)((void*)0x2608000)),  /* [2] */
    ((ti_sysbios_family_c66_tci66xx_CpIntc_RegisterMap*)((void*)0x260c000)),  /* [3] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_initSIER__A */
__T1_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__initSIER ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_initSIER__A[5] = {
    (xdc_Bits32)0x0,  /* [0] */
    (xdc_Bits32)0x0,  /* [1] */
    (xdc_Bits32)0x0,  /* [2] */
    (xdc_Bits32)0x0,  /* [3] */
    (xdc_Bits32)0x0,  /* [4] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_hostIntToSysInt__A */
__T1_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__hostIntToSysInt ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_hostIntToSysInt__A[76] = {
    (xdc_UInt8)(-0x0 - 1),  /* [0] */
    (xdc_UInt8)(-0x0 - 1),  /* [1] */
    (xdc_UInt8)(-0x0 - 1),  /* [2] */
    (xdc_UInt8)(-0x0 - 1),  /* [3] */
    (xdc_UInt8)(-0x0 - 1),  /* [4] */
    (xdc_UInt8)(-0x0 - 1),  /* [5] */
    (xdc_UInt8)(-0x0 - 1),  /* [6] */
    (xdc_UInt8)(-0x0 - 1),  /* [7] */
    (xdc_UInt8)(-0x0 - 1),  /* [8] */
    (xdc_UInt8)(-0x0 - 1),  /* [9] */
    (xdc_UInt8)(-0x0 - 1),  /* [10] */
    (xdc_UInt8)(-0x0 - 1),  /* [11] */
    (xdc_UInt8)(-0x0 - 1),  /* [12] */
    (xdc_UInt8)(-0x0 - 1),  /* [13] */
    (xdc_UInt8)(-0x0 - 1),  /* [14] */
    (xdc_UInt8)(-0x0 - 1),  /* [15] */
    (xdc_UInt8)(-0x0 - 1),  /* [16] */
    (xdc_UInt8)(-0x0 - 1),  /* [17] */
    (xdc_UInt8)(-0x0 - 1),  /* [18] */
    (xdc_UInt8)(-0x0 - 1),  /* [19] */
    (xdc_UInt8)(-0x0 - 1),  /* [20] */
    (xdc_UInt8)(-0x0 - 1),  /* [21] */
    (xdc_UInt8)(-0x0 - 1),  /* [22] */
    (xdc_UInt8)(-0x0 - 1),  /* [23] */
    (xdc_UInt8)(-0x0 - 1),  /* [24] */
    (xdc_UInt8)(-0x0 - 1),  /* [25] */
    (xdc_UInt8)(-0x0 - 1),  /* [26] */
    (xdc_UInt8)(-0x0 - 1),  /* [27] */
    (xdc_UInt8)(-0x0 - 1),  /* [28] */
    (xdc_UInt8)(-0x0 - 1),  /* [29] */
    (xdc_UInt8)(-0x0 - 1),  /* [30] */
    (xdc_UInt8)(-0x0 - 1),  /* [31] */
    (xdc_UInt8)(-0x0 - 1),  /* [32] */
    (xdc_UInt8)(-0x0 - 1),  /* [33] */
    (xdc_UInt8)(-0x0 - 1),  /* [34] */
    (xdc_UInt8)(-0x0 - 1),  /* [35] */
    (xdc_UInt8)(-0x0 - 1),  /* [36] */
    (xdc_UInt8)(-0x0 - 1),  /* [37] */
    (xdc_UInt8)(-0x0 - 1),  /* [38] */
    (xdc_UInt8)(-0x0 - 1),  /* [39] */
    (xdc_UInt8)(-0x0 - 1),  /* [40] */
    (xdc_UInt8)(-0x0 - 1),  /* [41] */
    (xdc_UInt8)(-0x0 - 1),  /* [42] */
    (xdc_UInt8)(-0x0 - 1),  /* [43] */
    (xdc_UInt8)(-0x0 - 1),  /* [44] */
    (xdc_UInt8)(-0x0 - 1),  /* [45] */
    (xdc_UInt8)(-0x0 - 1),  /* [46] */
    (xdc_UInt8)(-0x0 - 1),  /* [47] */
    (xdc_UInt8)(-0x0 - 1),  /* [48] */
    (xdc_UInt8)(-0x0 - 1),  /* [49] */
    (xdc_UInt8)(-0x0 - 1),  /* [50] */
    (xdc_UInt8)(-0x0 - 1),  /* [51] */
    (xdc_UInt8)(-0x0 - 1),  /* [52] */
    (xdc_UInt8)(-0x0 - 1),  /* [53] */
    (xdc_UInt8)(-0x0 - 1),  /* [54] */
    (xdc_UInt8)(-0x0 - 1),  /* [55] */
    (xdc_UInt8)(-0x0 - 1),  /* [56] */
    (xdc_UInt8)(-0x0 - 1),  /* [57] */
    (xdc_UInt8)(-0x0 - 1),  /* [58] */
    (xdc_UInt8)(-0x0 - 1),  /* [59] */
    (xdc_UInt8)(-0x0 - 1),  /* [60] */
    (xdc_UInt8)(-0x0 - 1),  /* [61] */
    (xdc_UInt8)(-0x0 - 1),  /* [62] */
    (xdc_UInt8)(-0x0 - 1),  /* [63] */
    (xdc_UInt8)(-0x0 - 1),  /* [64] */
    (xdc_UInt8)(-0x0 - 1),  /* [65] */
    (xdc_UInt8)(-0x0 - 1),  /* [66] */
    (xdc_UInt8)(-0x0 - 1),  /* [67] */
    (xdc_UInt8)(-0x0 - 1),  /* [68] */
    (xdc_UInt8)(-0x0 - 1),  /* [69] */
    (xdc_UInt8)(-0x0 - 1),  /* [70] */
    (xdc_UInt8)(-0x0 - 1),  /* [71] */
    (xdc_UInt8)(-0x0 - 1),  /* [72] */
    (xdc_UInt8)(-0x0 - 1),  /* [73] */
    (xdc_UInt8)(-0x0 - 1),  /* [74] */
    (xdc_UInt8)(-0x0 - 1),  /* [75] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_dispatchTab__A */
__T1_ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__dispatchTab ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_dispatchTab__A[160] = {
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg */
    },  /* [0] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x1)),  /* arg */
    },  /* [1] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x2)),  /* arg */
    },  /* [2] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x3)),  /* arg */
    },  /* [3] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x4)),  /* arg */
    },  /* [4] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x5)),  /* arg */
    },  /* [5] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x6)),  /* arg */
    },  /* [6] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x7)),  /* arg */
    },  /* [7] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x8)),  /* arg */
    },  /* [8] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x9)),  /* arg */
    },  /* [9] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0xa)),  /* arg */
    },  /* [10] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0xb)),  /* arg */
    },  /* [11] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0xc)),  /* arg */
    },  /* [12] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0xd)),  /* arg */
    },  /* [13] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0xe)),  /* arg */
    },  /* [14] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0xf)),  /* arg */
    },  /* [15] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x10)),  /* arg */
    },  /* [16] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x11)),  /* arg */
    },  /* [17] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x12)),  /* arg */
    },  /* [18] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x13)),  /* arg */
    },  /* [19] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x14)),  /* arg */
    },  /* [20] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x15)),  /* arg */
    },  /* [21] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x16)),  /* arg */
    },  /* [22] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x17)),  /* arg */
    },  /* [23] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x18)),  /* arg */
    },  /* [24] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x19)),  /* arg */
    },  /* [25] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x1a)),  /* arg */
    },  /* [26] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x1b)),  /* arg */
    },  /* [27] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x1c)),  /* arg */
    },  /* [28] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x1d)),  /* arg */
    },  /* [29] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x1e)),  /* arg */
    },  /* [30] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x1f)),  /* arg */
    },  /* [31] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x20)),  /* arg */
    },  /* [32] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x21)),  /* arg */
    },  /* [33] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x22)),  /* arg */
    },  /* [34] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x23)),  /* arg */
    },  /* [35] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x24)),  /* arg */
    },  /* [36] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x25)),  /* arg */
    },  /* [37] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x26)),  /* arg */
    },  /* [38] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x27)),  /* arg */
    },  /* [39] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x28)),  /* arg */
    },  /* [40] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x29)),  /* arg */
    },  /* [41] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x2a)),  /* arg */
    },  /* [42] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x2b)),  /* arg */
    },  /* [43] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x2c)),  /* arg */
    },  /* [44] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x2d)),  /* arg */
    },  /* [45] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x2e)),  /* arg */
    },  /* [46] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x2f)),  /* arg */
    },  /* [47] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x30)),  /* arg */
    },  /* [48] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x31)),  /* arg */
    },  /* [49] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x32)),  /* arg */
    },  /* [50] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x33)),  /* arg */
    },  /* [51] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x34)),  /* arg */
    },  /* [52] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x35)),  /* arg */
    },  /* [53] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x36)),  /* arg */
    },  /* [54] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x37)),  /* arg */
    },  /* [55] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x38)),  /* arg */
    },  /* [56] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x39)),  /* arg */
    },  /* [57] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x3a)),  /* arg */
    },  /* [58] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x3b)),  /* arg */
    },  /* [59] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x3c)),  /* arg */
    },  /* [60] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x3d)),  /* arg */
    },  /* [61] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x3e)),  /* arg */
    },  /* [62] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x3f)),  /* arg */
    },  /* [63] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x40)),  /* arg */
    },  /* [64] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x41)),  /* arg */
    },  /* [65] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x42)),  /* arg */
    },  /* [66] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x43)),  /* arg */
    },  /* [67] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x44)),  /* arg */
    },  /* [68] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x45)),  /* arg */
    },  /* [69] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x46)),  /* arg */
    },  /* [70] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x47)),  /* arg */
    },  /* [71] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x48)),  /* arg */
    },  /* [72] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x49)),  /* arg */
    },  /* [73] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x4a)),  /* arg */
    },  /* [74] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x4b)),  /* arg */
    },  /* [75] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x4c)),  /* arg */
    },  /* [76] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x4d)),  /* arg */
    },  /* [77] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x4e)),  /* arg */
    },  /* [78] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x4f)),  /* arg */
    },  /* [79] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x50)),  /* arg */
    },  /* [80] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x51)),  /* arg */
    },  /* [81] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x52)),  /* arg */
    },  /* [82] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x53)),  /* arg */
    },  /* [83] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x54)),  /* arg */
    },  /* [84] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x55)),  /* arg */
    },  /* [85] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x56)),  /* arg */
    },  /* [86] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x57)),  /* arg */
    },  /* [87] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x58)),  /* arg */
    },  /* [88] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x59)),  /* arg */
    },  /* [89] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x5a)),  /* arg */
    },  /* [90] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x5b)),  /* arg */
    },  /* [91] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x5c)),  /* arg */
    },  /* [92] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x5d)),  /* arg */
    },  /* [93] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x5e)),  /* arg */
    },  /* [94] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x5f)),  /* arg */
    },  /* [95] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x60)),  /* arg */
    },  /* [96] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x61)),  /* arg */
    },  /* [97] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x62)),  /* arg */
    },  /* [98] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x63)),  /* arg */
    },  /* [99] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x64)),  /* arg */
    },  /* [100] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x65)),  /* arg */
    },  /* [101] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x66)),  /* arg */
    },  /* [102] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x67)),  /* arg */
    },  /* [103] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x68)),  /* arg */
    },  /* [104] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x69)),  /* arg */
    },  /* [105] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x6a)),  /* arg */
    },  /* [106] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x6b)),  /* arg */
    },  /* [107] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x6c)),  /* arg */
    },  /* [108] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x6d)),  /* arg */
    },  /* [109] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x6e)),  /* arg */
    },  /* [110] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x6f)),  /* arg */
    },  /* [111] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x70)),  /* arg */
    },  /* [112] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x71)),  /* arg */
    },  /* [113] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x72)),  /* arg */
    },  /* [114] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x73)),  /* arg */
    },  /* [115] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x74)),  /* arg */
    },  /* [116] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x75)),  /* arg */
    },  /* [117] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x76)),  /* arg */
    },  /* [118] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x77)),  /* arg */
    },  /* [119] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x78)),  /* arg */
    },  /* [120] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x79)),  /* arg */
    },  /* [121] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x7a)),  /* arg */
    },  /* [122] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x7b)),  /* arg */
    },  /* [123] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x7c)),  /* arg */
    },  /* [124] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x7d)),  /* arg */
    },  /* [125] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x7e)),  /* arg */
    },  /* [126] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x7f)),  /* arg */
    },  /* [127] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x80)),  /* arg */
    },  /* [128] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x81)),  /* arg */
    },  /* [129] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x82)),  /* arg */
    },  /* [130] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x83)),  /* arg */
    },  /* [131] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x84)),  /* arg */
    },  /* [132] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x85)),  /* arg */
    },  /* [133] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x86)),  /* arg */
    },  /* [134] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x87)),  /* arg */
    },  /* [135] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x88)),  /* arg */
    },  /* [136] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x89)),  /* arg */
    },  /* [137] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x8a)),  /* arg */
    },  /* [138] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x8b)),  /* arg */
    },  /* [139] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x8c)),  /* arg */
    },  /* [140] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x8d)),  /* arg */
    },  /* [141] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x8e)),  /* arg */
    },  /* [142] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x8f)),  /* arg */
    },  /* [143] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x90)),  /* arg */
    },  /* [144] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x91)),  /* arg */
    },  /* [145] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x92)),  /* arg */
    },  /* [146] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x93)),  /* arg */
    },  /* [147] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x94)),  /* arg */
    },  /* [148] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x95)),  /* arg */
    },  /* [149] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x96)),  /* arg */
    },  /* [150] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x97)),  /* arg */
    },  /* [151] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x98)),  /* arg */
    },  /* [152] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x99)),  /* arg */
    },  /* [153] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x9a)),  /* arg */
    },  /* [154] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x9b)),  /* arg */
    },  /* [155] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x9c)),  /* arg */
    },  /* [156] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x9d)),  /* arg */
    },  /* [157] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x9e)),  /* arg */
    },  /* [158] */
    {
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_unused)),  /* fxn */
        ((xdc_UArg)(0x9f)),  /* arg */
    },  /* [159] */
};

/* Module__state__V */
ti_sysbios_family_c66_tci66xx_CpIntc_Module_State__ ti_sysbios_family_c66_tci66xx_CpIntc_Module__state__V = {
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_controller__A),  /* controller */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_initSIER__A),  /* initSIER */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_hostIntToSysInt__A),  /* hostIntToSysInt */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_Module_State_0_dispatchTab__A),  /* dispatchTab */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__A[160] = {
    (xdc_UInt8)(-0x0 - 1),  /* [0] */
    (xdc_UInt8)(-0x0 - 1),  /* [1] */
    (xdc_UInt8)(-0x0 - 1),  /* [2] */
    (xdc_UInt8)(-0x0 - 1),  /* [3] */
    (xdc_UInt8)(-0x0 - 1),  /* [4] */
    (xdc_UInt8)(-0x0 - 1),  /* [5] */
    (xdc_UInt8)(-0x0 - 1),  /* [6] */
    (xdc_UInt8)(-0x0 - 1),  /* [7] */
    (xdc_UInt8)(-0x0 - 1),  /* [8] */
    (xdc_UInt8)(-0x0 - 1),  /* [9] */
    (xdc_UInt8)(-0x0 - 1),  /* [10] */
    (xdc_UInt8)(-0x0 - 1),  /* [11] */
    (xdc_UInt8)(-0x0 - 1),  /* [12] */
    (xdc_UInt8)(-0x0 - 1),  /* [13] */
    (xdc_UInt8)(-0x0 - 1),  /* [14] */
    (xdc_UInt8)(-0x0 - 1),  /* [15] */
    (xdc_UInt8)(-0x0 - 1),  /* [16] */
    (xdc_UInt8)(-0x0 - 1),  /* [17] */
    (xdc_UInt8)(-0x0 - 1),  /* [18] */
    (xdc_UInt8)(-0x0 - 1),  /* [19] */
    (xdc_UInt8)(-0x0 - 1),  /* [20] */
    (xdc_UInt8)(-0x0 - 1),  /* [21] */
    (xdc_UInt8)(-0x0 - 1),  /* [22] */
    (xdc_UInt8)(-0x0 - 1),  /* [23] */
    (xdc_UInt8)(-0x0 - 1),  /* [24] */
    (xdc_UInt8)(-0x0 - 1),  /* [25] */
    (xdc_UInt8)(-0x0 - 1),  /* [26] */
    (xdc_UInt8)(-0x0 - 1),  /* [27] */
    (xdc_UInt8)(-0x0 - 1),  /* [28] */
    (xdc_UInt8)(-0x0 - 1),  /* [29] */
    (xdc_UInt8)(-0x0 - 1),  /* [30] */
    (xdc_UInt8)(-0x0 - 1),  /* [31] */
    (xdc_UInt8)(-0x0 - 1),  /* [32] */
    (xdc_UInt8)(-0x0 - 1),  /* [33] */
    (xdc_UInt8)(-0x0 - 1),  /* [34] */
    (xdc_UInt8)(-0x0 - 1),  /* [35] */
    (xdc_UInt8)(-0x0 - 1),  /* [36] */
    (xdc_UInt8)(-0x0 - 1),  /* [37] */
    (xdc_UInt8)(-0x0 - 1),  /* [38] */
    (xdc_UInt8)(-0x0 - 1),  /* [39] */
    (xdc_UInt8)(-0x0 - 1),  /* [40] */
    (xdc_UInt8)(-0x0 - 1),  /* [41] */
    (xdc_UInt8)(-0x0 - 1),  /* [42] */
    (xdc_UInt8)(-0x0 - 1),  /* [43] */
    (xdc_UInt8)(-0x0 - 1),  /* [44] */
    (xdc_UInt8)(-0x0 - 1),  /* [45] */
    (xdc_UInt8)(-0x0 - 1),  /* [46] */
    (xdc_UInt8)(-0x0 - 1),  /* [47] */
    (xdc_UInt8)(-0x0 - 1),  /* [48] */
    (xdc_UInt8)(-0x0 - 1),  /* [49] */
    (xdc_UInt8)(-0x0 - 1),  /* [50] */
    (xdc_UInt8)(-0x0 - 1),  /* [51] */
    (xdc_UInt8)(-0x0 - 1),  /* [52] */
    (xdc_UInt8)(-0x0 - 1),  /* [53] */
    (xdc_UInt8)(-0x0 - 1),  /* [54] */
    (xdc_UInt8)(-0x0 - 1),  /* [55] */
    (xdc_UInt8)(-0x0 - 1),  /* [56] */
    (xdc_UInt8)(-0x0 - 1),  /* [57] */
    (xdc_UInt8)(-0x0 - 1),  /* [58] */
    (xdc_UInt8)(-0x0 - 1),  /* [59] */
    (xdc_UInt8)(-0x0 - 1),  /* [60] */
    (xdc_UInt8)(-0x0 - 1),  /* [61] */
    (xdc_UInt8)(-0x0 - 1),  /* [62] */
    (xdc_UInt8)(-0x0 - 1),  /* [63] */
    (xdc_UInt8)(-0x0 - 1),  /* [64] */
    (xdc_UInt8)(-0x0 - 1),  /* [65] */
    (xdc_UInt8)(-0x0 - 1),  /* [66] */
    (xdc_UInt8)(-0x0 - 1),  /* [67] */
    (xdc_UInt8)(-0x0 - 1),  /* [68] */
    (xdc_UInt8)(-0x0 - 1),  /* [69] */
    (xdc_UInt8)(-0x0 - 1),  /* [70] */
    (xdc_UInt8)(-0x0 - 1),  /* [71] */
    (xdc_UInt8)(-0x0 - 1),  /* [72] */
    (xdc_UInt8)(-0x0 - 1),  /* [73] */
    (xdc_UInt8)(-0x0 - 1),  /* [74] */
    (xdc_UInt8)(-0x0 - 1),  /* [75] */
    (xdc_UInt8)(-0x0 - 1),  /* [76] */
    (xdc_UInt8)(-0x0 - 1),  /* [77] */
    (xdc_UInt8)(-0x0 - 1),  /* [78] */
    (xdc_UInt8)(-0x0 - 1),  /* [79] */
    (xdc_UInt8)(-0x0 - 1),  /* [80] */
    (xdc_UInt8)(-0x0 - 1),  /* [81] */
    (xdc_UInt8)(-0x0 - 1),  /* [82] */
    (xdc_UInt8)(-0x0 - 1),  /* [83] */
    (xdc_UInt8)(-0x0 - 1),  /* [84] */
    (xdc_UInt8)(-0x0 - 1),  /* [85] */
    (xdc_UInt8)(-0x0 - 1),  /* [86] */
    (xdc_UInt8)(-0x0 - 1),  /* [87] */
    (xdc_UInt8)(-0x0 - 1),  /* [88] */
    (xdc_UInt8)(-0x0 - 1),  /* [89] */
    (xdc_UInt8)(-0x0 - 1),  /* [90] */
    (xdc_UInt8)(-0x0 - 1),  /* [91] */
    (xdc_UInt8)(-0x0 - 1),  /* [92] */
    (xdc_UInt8)(-0x0 - 1),  /* [93] */
    (xdc_UInt8)(-0x0 - 1),  /* [94] */
    (xdc_UInt8)(-0x0 - 1),  /* [95] */
    (xdc_UInt8)(-0x0 - 1),  /* [96] */
    (xdc_UInt8)(-0x0 - 1),  /* [97] */
    (xdc_UInt8)(-0x0 - 1),  /* [98] */
    (xdc_UInt8)(-0x0 - 1),  /* [99] */
    (xdc_UInt8)(-0x0 - 1),  /* [100] */
    (xdc_UInt8)(-0x0 - 1),  /* [101] */
    (xdc_UInt8)(-0x0 - 1),  /* [102] */
    (xdc_UInt8)(-0x0 - 1),  /* [103] */
    (xdc_UInt8)(-0x0 - 1),  /* [104] */
    (xdc_UInt8)(-0x0 - 1),  /* [105] */
    (xdc_UInt8)(-0x0 - 1),  /* [106] */
    (xdc_UInt8)(-0x0 - 1),  /* [107] */
    (xdc_UInt8)(-0x0 - 1),  /* [108] */
    (xdc_UInt8)(-0x0 - 1),  /* [109] */
    (xdc_UInt8)(-0x0 - 1),  /* [110] */
    (xdc_UInt8)(-0x0 - 1),  /* [111] */
    (xdc_UInt8)(-0x0 - 1),  /* [112] */
    (xdc_UInt8)(-0x0 - 1),  /* [113] */
    (xdc_UInt8)(-0x0 - 1),  /* [114] */
    (xdc_UInt8)(-0x0 - 1),  /* [115] */
    (xdc_UInt8)(-0x0 - 1),  /* [116] */
    (xdc_UInt8)(-0x0 - 1),  /* [117] */
    (xdc_UInt8)(-0x0 - 1),  /* [118] */
    (xdc_UInt8)(-0x0 - 1),  /* [119] */
    (xdc_UInt8)(-0x0 - 1),  /* [120] */
    (xdc_UInt8)(-0x0 - 1),  /* [121] */
    (xdc_UInt8)(-0x0 - 1),  /* [122] */
    (xdc_UInt8)(-0x0 - 1),  /* [123] */
    (xdc_UInt8)(-0x0 - 1),  /* [124] */
    (xdc_UInt8)(-0x0 - 1),  /* [125] */
    (xdc_UInt8)(-0x0 - 1),  /* [126] */
    (xdc_UInt8)(-0x0 - 1),  /* [127] */
    (xdc_UInt8)(-0x0 - 1),  /* [128] */
    (xdc_UInt8)(-0x0 - 1),  /* [129] */
    (xdc_UInt8)(-0x0 - 1),  /* [130] */
    (xdc_UInt8)(-0x0 - 1),  /* [131] */
    (xdc_UInt8)(-0x0 - 1),  /* [132] */
    (xdc_UInt8)(-0x0 - 1),  /* [133] */
    (xdc_UInt8)(-0x0 - 1),  /* [134] */
    (xdc_UInt8)(-0x0 - 1),  /* [135] */
    (xdc_UInt8)(-0x0 - 1),  /* [136] */
    (xdc_UInt8)(-0x0 - 1),  /* [137] */
    (xdc_UInt8)(-0x0 - 1),  /* [138] */
    (xdc_UInt8)(-0x0 - 1),  /* [139] */
    (xdc_UInt8)(-0x0 - 1),  /* [140] */
    (xdc_UInt8)(-0x0 - 1),  /* [141] */
    (xdc_UInt8)(-0x0 - 1),  /* [142] */
    (xdc_UInt8)(-0x0 - 1),  /* [143] */
    (xdc_UInt8)(-0x0 - 1),  /* [144] */
    (xdc_UInt8)(-0x0 - 1),  /* [145] */
    (xdc_UInt8)(-0x0 - 1),  /* [146] */
    (xdc_UInt8)(-0x0 - 1),  /* [147] */
    (xdc_UInt8)(-0x0 - 1),  /* [148] */
    (xdc_UInt8)(-0x0 - 1),  /* [149] */
    (xdc_UInt8)(-0x0 - 1),  /* [150] */
    (xdc_UInt8)(-0x0 - 1),  /* [151] */
    (xdc_UInt8)(-0x0 - 1),  /* [152] */
    (xdc_UInt8)(-0x0 - 1),  /* [153] */
    (xdc_UInt8)(-0x0 - 1),  /* [154] */
    (xdc_UInt8)(-0x0 - 1),  /* [155] */
    (xdc_UInt8)(-0x0 - 1),  /* [156] */
    (xdc_UInt8)(-0x0 - 1),  /* [157] */
    (xdc_UInt8)(-0x0 - 1),  /* [158] */
    (xdc_UInt8)(-0x0 - 1),  /* [159] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_0__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_0__A[25] = {
    (xdc_UInt8)0x20,  /* [0] */
    (xdc_UInt8)0x21,  /* [1] */
    (xdc_UInt8)0x22,  /* [2] */
    (xdc_UInt8)0x23,  /* [3] */
    (xdc_UInt8)0x24,  /* [4] */
    (xdc_UInt8)0x25,  /* [5] */
    (xdc_UInt8)0x26,  /* [6] */
    (xdc_UInt8)0x27,  /* [7] */
    (xdc_UInt8)0x28,  /* [8] */
    (xdc_UInt8)0x29,  /* [9] */
    (xdc_UInt8)0x2a,  /* [10] */
    (xdc_UInt8)0x2,  /* [11] */
    (xdc_UInt8)0x3,  /* [12] */
    (xdc_UInt8)0x4,  /* [13] */
    (xdc_UInt8)0x5,  /* [14] */
    (xdc_UInt8)0x6,  /* [15] */
    (xdc_UInt8)0x7,  /* [16] */
    (xdc_UInt8)0x0,  /* [17] */
    (xdc_UInt8)0x1,  /* [18] */
    (xdc_UInt8)0x8,  /* [19] */
    (xdc_UInt8)0x9,  /* [20] */
    (xdc_UInt8)0x10,  /* [21] */
    (xdc_UInt8)0x11,  /* [22] */
    (xdc_UInt8)0x18,  /* [23] */
    (xdc_UInt8)0x19,  /* [24] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_1__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_1__A[25] = {
    (xdc_UInt8)0x2b,  /* [0] */
    (xdc_UInt8)0x2c,  /* [1] */
    (xdc_UInt8)0x2d,  /* [2] */
    (xdc_UInt8)0x2e,  /* [3] */
    (xdc_UInt8)0x2f,  /* [4] */
    (xdc_UInt8)0x30,  /* [5] */
    (xdc_UInt8)0x31,  /* [6] */
    (xdc_UInt8)0x32,  /* [7] */
    (xdc_UInt8)0x33,  /* [8] */
    (xdc_UInt8)0x34,  /* [9] */
    (xdc_UInt8)0x35,  /* [10] */
    (xdc_UInt8)0xa,  /* [11] */
    (xdc_UInt8)0xb,  /* [12] */
    (xdc_UInt8)0xc,  /* [13] */
    (xdc_UInt8)0xd,  /* [14] */
    (xdc_UInt8)0xe,  /* [15] */
    (xdc_UInt8)0xf,  /* [16] */
    (xdc_UInt8)0x0,  /* [17] */
    (xdc_UInt8)0x1,  /* [18] */
    (xdc_UInt8)0x8,  /* [19] */
    (xdc_UInt8)0x9,  /* [20] */
    (xdc_UInt8)0x10,  /* [21] */
    (xdc_UInt8)0x11,  /* [22] */
    (xdc_UInt8)0x18,  /* [23] */
    (xdc_UInt8)0x19,  /* [24] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_2__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_2__A[25] = {
    (xdc_UInt8)0x36,  /* [0] */
    (xdc_UInt8)0x37,  /* [1] */
    (xdc_UInt8)0x38,  /* [2] */
    (xdc_UInt8)0x39,  /* [3] */
    (xdc_UInt8)0x3a,  /* [4] */
    (xdc_UInt8)0x3b,  /* [5] */
    (xdc_UInt8)0x3c,  /* [6] */
    (xdc_UInt8)0x3d,  /* [7] */
    (xdc_UInt8)0x3e,  /* [8] */
    (xdc_UInt8)0x3f,  /* [9] */
    (xdc_UInt8)0x40,  /* [10] */
    (xdc_UInt8)0x12,  /* [11] */
    (xdc_UInt8)0x13,  /* [12] */
    (xdc_UInt8)0x14,  /* [13] */
    (xdc_UInt8)0x15,  /* [14] */
    (xdc_UInt8)0x16,  /* [15] */
    (xdc_UInt8)0x17,  /* [16] */
    (xdc_UInt8)0x0,  /* [17] */
    (xdc_UInt8)0x1,  /* [18] */
    (xdc_UInt8)0x8,  /* [19] */
    (xdc_UInt8)0x9,  /* [20] */
    (xdc_UInt8)0x10,  /* [21] */
    (xdc_UInt8)0x11,  /* [22] */
    (xdc_UInt8)0x18,  /* [23] */
    (xdc_UInt8)0x19,  /* [24] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_3__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_3__A[25] = {
    (xdc_UInt8)0x41,  /* [0] */
    (xdc_UInt8)0x42,  /* [1] */
    (xdc_UInt8)0x43,  /* [2] */
    (xdc_UInt8)0x44,  /* [3] */
    (xdc_UInt8)0x45,  /* [4] */
    (xdc_UInt8)0x46,  /* [5] */
    (xdc_UInt8)0x47,  /* [6] */
    (xdc_UInt8)0x48,  /* [7] */
    (xdc_UInt8)0x49,  /* [8] */
    (xdc_UInt8)0x4a,  /* [9] */
    (xdc_UInt8)0x4b,  /* [10] */
    (xdc_UInt8)0x1a,  /* [11] */
    (xdc_UInt8)0x1b,  /* [12] */
    (xdc_UInt8)0x1c,  /* [13] */
    (xdc_UInt8)0x1d,  /* [14] */
    (xdc_UInt8)0x1e,  /* [15] */
    (xdc_UInt8)0x1f,  /* [16] */
    (xdc_UInt8)0x0,  /* [17] */
    (xdc_UInt8)0x1,  /* [18] */
    (xdc_UInt8)0x8,  /* [19] */
    (xdc_UInt8)0x9,  /* [20] */
    (xdc_UInt8)0x10,  /* [21] */
    (xdc_UInt8)0x11,  /* [22] */
    (xdc_UInt8)0x18,  /* [23] */
    (xdc_UInt8)0x19,  /* [24] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_4__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_4__A[25] = {
    (xdc_UInt8)0x20,  /* [0] */
    (xdc_UInt8)0x21,  /* [1] */
    (xdc_UInt8)0x22,  /* [2] */
    (xdc_UInt8)0x23,  /* [3] */
    (xdc_UInt8)0x24,  /* [4] */
    (xdc_UInt8)0x25,  /* [5] */
    (xdc_UInt8)0x26,  /* [6] */
    (xdc_UInt8)0x27,  /* [7] */
    (xdc_UInt8)0x28,  /* [8] */
    (xdc_UInt8)0x29,  /* [9] */
    (xdc_UInt8)0x2a,  /* [10] */
    (xdc_UInt8)0x2,  /* [11] */
    (xdc_UInt8)0x3,  /* [12] */
    (xdc_UInt8)0x4,  /* [13] */
    (xdc_UInt8)0x5,  /* [14] */
    (xdc_UInt8)0x6,  /* [15] */
    (xdc_UInt8)0x7,  /* [16] */
    (xdc_UInt8)0x0,  /* [17] */
    (xdc_UInt8)0x1,  /* [18] */
    (xdc_UInt8)0x8,  /* [19] */
    (xdc_UInt8)0x9,  /* [20] */
    (xdc_UInt8)0x10,  /* [21] */
    (xdc_UInt8)0x11,  /* [22] */
    (xdc_UInt8)0x18,  /* [23] */
    (xdc_UInt8)0x19,  /* [24] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_5__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_5__A[25] = {
    (xdc_UInt8)0x2b,  /* [0] */
    (xdc_UInt8)0x2c,  /* [1] */
    (xdc_UInt8)0x2d,  /* [2] */
    (xdc_UInt8)0x2e,  /* [3] */
    (xdc_UInt8)0x2f,  /* [4] */
    (xdc_UInt8)0x30,  /* [5] */
    (xdc_UInt8)0x31,  /* [6] */
    (xdc_UInt8)0x32,  /* [7] */
    (xdc_UInt8)0x33,  /* [8] */
    (xdc_UInt8)0x34,  /* [9] */
    (xdc_UInt8)0x35,  /* [10] */
    (xdc_UInt8)0xa,  /* [11] */
    (xdc_UInt8)0xb,  /* [12] */
    (xdc_UInt8)0xc,  /* [13] */
    (xdc_UInt8)0xd,  /* [14] */
    (xdc_UInt8)0xe,  /* [15] */
    (xdc_UInt8)0xf,  /* [16] */
    (xdc_UInt8)0x0,  /* [17] */
    (xdc_UInt8)0x1,  /* [18] */
    (xdc_UInt8)0x8,  /* [19] */
    (xdc_UInt8)0x9,  /* [20] */
    (xdc_UInt8)0x10,  /* [21] */
    (xdc_UInt8)0x11,  /* [22] */
    (xdc_UInt8)0x18,  /* [23] */
    (xdc_UInt8)0x19,  /* [24] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_6__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_6__A[25] = {
    (xdc_UInt8)0x36,  /* [0] */
    (xdc_UInt8)0x37,  /* [1] */
    (xdc_UInt8)0x38,  /* [2] */
    (xdc_UInt8)0x39,  /* [3] */
    (xdc_UInt8)0x3a,  /* [4] */
    (xdc_UInt8)0x3b,  /* [5] */
    (xdc_UInt8)0x3c,  /* [6] */
    (xdc_UInt8)0x3d,  /* [7] */
    (xdc_UInt8)0x3e,  /* [8] */
    (xdc_UInt8)0x3f,  /* [9] */
    (xdc_UInt8)0x40,  /* [10] */
    (xdc_UInt8)0x12,  /* [11] */
    (xdc_UInt8)0x13,  /* [12] */
    (xdc_UInt8)0x14,  /* [13] */
    (xdc_UInt8)0x15,  /* [14] */
    (xdc_UInt8)0x16,  /* [15] */
    (xdc_UInt8)0x17,  /* [16] */
    (xdc_UInt8)0x0,  /* [17] */
    (xdc_UInt8)0x1,  /* [18] */
    (xdc_UInt8)0x8,  /* [19] */
    (xdc_UInt8)0x9,  /* [20] */
    (xdc_UInt8)0x10,  /* [21] */
    (xdc_UInt8)0x11,  /* [22] */
    (xdc_UInt8)0x18,  /* [23] */
    (xdc_UInt8)0x19,  /* [24] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_7__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_7__A[25] = {
    (xdc_UInt8)0x41,  /* [0] */
    (xdc_UInt8)0x42,  /* [1] */
    (xdc_UInt8)0x43,  /* [2] */
    (xdc_UInt8)0x44,  /* [3] */
    (xdc_UInt8)0x45,  /* [4] */
    (xdc_UInt8)0x46,  /* [5] */
    (xdc_UInt8)0x47,  /* [6] */
    (xdc_UInt8)0x48,  /* [7] */
    (xdc_UInt8)0x49,  /* [8] */
    (xdc_UInt8)0x4a,  /* [9] */
    (xdc_UInt8)0x4b,  /* [10] */
    (xdc_UInt8)0x1a,  /* [11] */
    (xdc_UInt8)0x1b,  /* [12] */
    (xdc_UInt8)0x1c,  /* [13] */
    (xdc_UInt8)0x1d,  /* [14] */
    (xdc_UInt8)0x1e,  /* [15] */
    (xdc_UInt8)0x1f,  /* [16] */
    (xdc_UInt8)0x0,  /* [17] */
    (xdc_UInt8)0x1,  /* [18] */
    (xdc_UInt8)0x8,  /* [19] */
    (xdc_UInt8)0x9,  /* [20] */
    (xdc_UInt8)0x10,  /* [21] */
    (xdc_UInt8)0x11,  /* [22] */
    (xdc_UInt8)0x18,  /* [23] */
    (xdc_UInt8)0x19,  /* [24] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__A */
const __T2_ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__A[8] = {
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_0__A),  /* [0] */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_1__A),  /* [1] */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_2__A),  /* [2] */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_3__A),  /* [3] */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_4__A),  /* [4] */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_5__A),  /* [5] */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_6__A),  /* [6] */
    ((void*)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_7__A),  /* [7] */
};

/* --> ti_sysbios_family_c66_tci66xx_CpIntc_eventId__A */
const __T1_ti_sysbios_family_c66_tci66xx_CpIntc_eventId ti_sysbios_family_c66_tci66xx_CpIntc_eventId__A[25] = {
    (xdc_UInt8)0x15,  /* [0] */
    (xdc_UInt8)0x16,  /* [1] */
    (xdc_UInt8)0x17,  /* [2] */
    (xdc_UInt8)0x18,  /* [3] */
    (xdc_UInt8)0x19,  /* [4] */
    (xdc_UInt8)0x1a,  /* [5] */
    (xdc_UInt8)0x1b,  /* [6] */
    (xdc_UInt8)0x1c,  /* [7] */
    (xdc_UInt8)0x1d,  /* [8] */
    (xdc_UInt8)0x1e,  /* [9] */
    (xdc_UInt8)0x1f,  /* [10] */
    (xdc_UInt8)0x3e,  /* [11] */
    (xdc_UInt8)0x3f,  /* [12] */
    (xdc_UInt8)0x5c,  /* [13] */
    (xdc_UInt8)0x5d,  /* [14] */
    (xdc_UInt8)0x5e,  /* [15] */
    (xdc_UInt8)0x5f,  /* [16] */
    (xdc_UInt8)0x66,  /* [17] */
    (xdc_UInt8)0x67,  /* [18] */
    (xdc_UInt8)0x68,  /* [19] */
    (xdc_UInt8)0x69,  /* [20] */
    (xdc_UInt8)0x6a,  /* [21] */
    (xdc_UInt8)0x6b,  /* [22] */
    (xdc_UInt8)0x6c,  /* [23] */
    (xdc_UInt8)0x6d,  /* [24] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsEnabled ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsIncluded ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsMask ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsMask__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__gateObj ti_sysbios_family_c66_tci66xx_CpIntc_Module__gateObj__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__gatePrms ti_sysbios_family_c66_tci66xx_CpIntc_Module__gatePrms__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__id ti_sysbios_family_c66_tci66xx_CpIntc_Module__id__C = (xdc_Bits16)0x801b;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerDefined ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerObj ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerObj__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn0 ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn1 ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn2 ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn4 ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn8 ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__startupDoneFxn ti_sysbios_family_c66_tci66xx_CpIntc_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Object__count ti_sysbios_family_c66_tci66xx_CpIntc_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Object__heap ti_sysbios_family_c66_tci66xx_CpIntc_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Object__sizeof ti_sysbios_family_c66_tci66xx_CpIntc_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_Object__table ti_sysbios_family_c66_tci66xx_CpIntc_Object__table__C = 0;

/* E_unpluggedSysInt__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_E_unpluggedSysInt ti_sysbios_family_c66_tci66xx_CpIntc_E_unpluggedSysInt__C = (((xdc_runtime_Error_Id)3227) << 16 | 0);

/* numSysInts__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_numSysInts ti_sysbios_family_c66_tci66xx_CpIntc_numSysInts__C = (xdc_UInt32)0xa0;

/* numEvents__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_numEvents ti_sysbios_family_c66_tci66xx_CpIntc_numEvents__C = (xdc_UInt32)0x19;

/* numStatusRegs__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_numStatusRegs ti_sysbios_family_c66_tci66xx_CpIntc_numStatusRegs__C = (xdc_Int)5.96875;

/* sysIntToHostInt__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt)ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__A);

/* hostIntToEventId__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId)ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__A);

/* eventId__C */
__FAR__ const CT__ti_sysbios_family_c66_tci66xx_CpIntc_eventId ti_sysbios_family_c66_tci66xx_CpIntc_eventId__C = ((CT__ti_sysbios_family_c66_tci66xx_CpIntc_eventId)ti_sysbios_family_c66_tci66xx_CpIntc_eventId__A);


/*
 * ======== ti.sysbios.gates.GateHwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateHwi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_gates_GateHwi_Params ti_sysbios_gates_GateHwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_gates_GateHwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_gates_GateHwi_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_gates_GateHwi_Module__ ti_sysbios_gates_GateHwi_Module__root__V = {
    {&ti_sysbios_gates_GateHwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_gates_GateHwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_gates_GateHwi_Object__ ti_sysbios_gates_GateHwi_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_gates_GateHwi_Module__FXNS__C,
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsEnabled ti_sysbios_gates_GateHwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsIncluded ti_sysbios_gates_GateHwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsMask ti_sysbios_gates_GateHwi_Module__diagsMask__C = ((CT__ti_sysbios_gates_GateHwi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__gateObj ti_sysbios_gates_GateHwi_Module__gateObj__C = ((CT__ti_sysbios_gates_GateHwi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__gatePrms ti_sysbios_gates_GateHwi_Module__gatePrms__C = ((CT__ti_sysbios_gates_GateHwi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__id ti_sysbios_gates_GateHwi_Module__id__C = (xdc_Bits16)0x8029;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerDefined ti_sysbios_gates_GateHwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerObj ti_sysbios_gates_GateHwi_Module__loggerObj__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn0 ti_sysbios_gates_GateHwi_Module__loggerFxn0__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn1 ti_sysbios_gates_GateHwi_Module__loggerFxn1__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn2 ti_sysbios_gates_GateHwi_Module__loggerFxn2__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn4 ti_sysbios_gates_GateHwi_Module__loggerFxn4__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn8 ti_sysbios_gates_GateHwi_Module__loggerFxn8__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__startupDoneFxn ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_gates_GateHwi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__count ti_sysbios_gates_GateHwi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__heap ti_sysbios_gates_GateHwi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__sizeof ti_sysbios_gates_GateHwi_Object__sizeof__C = sizeof(ti_sysbios_gates_GateHwi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__table ti_sysbios_gates_GateHwi_Object__table__C = ti_sysbios_gates_GateHwi_Object__table__V;


/*
 * ======== ti.sysbios.gates.GateMutex INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateMutex_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_gates_GateMutex_Params ti_sysbios_gates_GateMutex_Object__PARAMS__C = {
    sizeof (ti_sysbios_gates_GateMutex_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_gates_GateMutex_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_gates_GateMutex_Module__ ti_sysbios_gates_GateMutex_Module__root__V = {
    {&ti_sysbios_gates_GateMutex_Module__root__V.link,  /* link.next */
    &ti_sysbios_gates_GateMutex_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_gates_GateMutex_Object__ ti_sysbios_gates_GateMutex_Object__table__V[2] = {
    {/* instance#0 */
        &ti_sysbios_gates_GateMutex_Module__FXNS__C,
        0,  /* owner */
        {
            0,  /* event */
            (xdc_UInt)0x1,  /* eventId */
            ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
            (xdc_UInt16)0x1,  /* count */
            {
                {
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[0].Object_field_sem.Object_field_pendQ.elem)),  /* next */
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[0].Object_field_sem.Object_field_pendQ.elem)),  /* prev */
                },  /* elem */
            },  /* Object_field_pendQ */
        },  /* Object_field_sem */
    },
    {/* instance#1 */
        &ti_sysbios_gates_GateMutex_Module__FXNS__C,
        0,  /* owner */
        {
            0,  /* event */
            (xdc_UInt)0x1,  /* eventId */
            ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
            (xdc_UInt16)0x1,  /* count */
            {
                {
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[1].Object_field_sem.Object_field_pendQ.elem)),  /* next */
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[1].Object_field_sem.Object_field_pendQ.elem)),  /* prev */
                },  /* elem */
            },  /* Object_field_pendQ */
        },  /* Object_field_sem */
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsEnabled ti_sysbios_gates_GateMutex_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsIncluded ti_sysbios_gates_GateMutex_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsMask ti_sysbios_gates_GateMutex_Module__diagsMask__C = ((CT__ti_sysbios_gates_GateMutex_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__gateObj ti_sysbios_gates_GateMutex_Module__gateObj__C = ((CT__ti_sysbios_gates_GateMutex_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__gatePrms ti_sysbios_gates_GateMutex_Module__gatePrms__C = ((CT__ti_sysbios_gates_GateMutex_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__id ti_sysbios_gates_GateMutex_Module__id__C = (xdc_Bits16)0x802a;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerDefined ti_sysbios_gates_GateMutex_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerObj ti_sysbios_gates_GateMutex_Module__loggerObj__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn0 ti_sysbios_gates_GateMutex_Module__loggerFxn0__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn1 ti_sysbios_gates_GateMutex_Module__loggerFxn1__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn2 ti_sysbios_gates_GateMutex_Module__loggerFxn2__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn4 ti_sysbios_gates_GateMutex_Module__loggerFxn4__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn8 ti_sysbios_gates_GateMutex_Module__loggerFxn8__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__startupDoneFxn ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C = ((CT__ti_sysbios_gates_GateMutex_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__count ti_sysbios_gates_GateMutex_Object__count__C = 2;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__heap ti_sysbios_gates_GateMutex_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__sizeof ti_sysbios_gates_GateMutex_Object__sizeof__C = sizeof(ti_sysbios_gates_GateMutex_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__table ti_sysbios_gates_GateMutex_Object__table__C = ti_sysbios_gates_GateMutex_Object__table__V;

/* A_badContext__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_A_badContext ti_sysbios_gates_GateMutex_A_badContext__C = (((xdc_runtime_Assert_Id)1755) << 16 | 16);


/*
 * ======== ti.sysbios.hal.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_hal_Hwi_Params ti_sysbios_hal_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_hal_Hwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_hal_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)(-0x0 - 1),  /* priority */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_hal_Hwi_Module__ ti_sysbios_hal_Hwi_Module__root__V = {
    {&ti_sysbios_hal_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_hal_Hwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_hal_Hwi_Object__ ti_sysbios_hal_Hwi_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (ti_sysbios_hal_Hwi_HwiProxy_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[0],  /* pi */
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsEnabled ti_sysbios_hal_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsIncluded ti_sysbios_hal_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsMask ti_sysbios_hal_Hwi_Module__diagsMask__C = ((CT__ti_sysbios_hal_Hwi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__gateObj ti_sysbios_hal_Hwi_Module__gateObj__C = ((CT__ti_sysbios_hal_Hwi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__gatePrms ti_sysbios_hal_Hwi_Module__gatePrms__C = ((CT__ti_sysbios_hal_Hwi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__id ti_sysbios_hal_Hwi_Module__id__C = (xdc_Bits16)0x801d;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerDefined ti_sysbios_hal_Hwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerObj ti_sysbios_hal_Hwi_Module__loggerObj__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__startupDoneFxn ti_sysbios_hal_Hwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_Hwi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__count ti_sysbios_hal_Hwi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__heap ti_sysbios_hal_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__sizeof ti_sysbios_hal_Hwi_Object__sizeof__C = sizeof(ti_sysbios_hal_Hwi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__table ti_sysbios_hal_Hwi_Object__table__C = ti_sysbios_hal_Hwi_Object__table__V;

/* dispatcherAutoNestingSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherSwiSupport ti_sysbios_hal_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherTaskSupport ti_sysbios_hal_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* E_stackOverflow__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_E_stackOverflow ti_sysbios_hal_Hwi_E_stackOverflow__C = (((xdc_runtime_Error_Id)3280) << 16 | 0);


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.hal.Timer INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Timer_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_hal_Timer_Params ti_sysbios_hal_Timer_Object__PARAMS__C = {
    sizeof (ti_sysbios_hal_Timer_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_hal_Timer_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)0),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_hal_Timer_Module__ ti_sysbios_hal_Timer_Module__root__V = {
    {&ti_sysbios_hal_Timer_Module__root__V.link,  /* link.next */
    &ti_sysbios_hal_Timer_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_hal_Timer_Object__ ti_sysbios_hal_Timer_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (ti_sysbios_hal_Timer_TimerProxy_Handle)&ti_sysbios_timers_timer64_Timer_Object__table__V[0],  /* pi */
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__diagsEnabled ti_sysbios_hal_Timer_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__diagsIncluded ti_sysbios_hal_Timer_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__diagsMask ti_sysbios_hal_Timer_Module__diagsMask__C = ((CT__ti_sysbios_hal_Timer_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__gateObj ti_sysbios_hal_Timer_Module__gateObj__C = ((CT__ti_sysbios_hal_Timer_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__gatePrms ti_sysbios_hal_Timer_Module__gatePrms__C = ((CT__ti_sysbios_hal_Timer_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__id ti_sysbios_hal_Timer_Module__id__C = (xdc_Bits16)0x801e;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerDefined ti_sysbios_hal_Timer_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerObj ti_sysbios_hal_Timer_Module__loggerObj__C = ((CT__ti_sysbios_hal_Timer_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn0 ti_sysbios_hal_Timer_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn1 ti_sysbios_hal_Timer_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn2 ti_sysbios_hal_Timer_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn4 ti_sysbios_hal_Timer_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn8 ti_sysbios_hal_Timer_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__startupDoneFxn ti_sysbios_hal_Timer_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_Timer_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Object__count ti_sysbios_hal_Timer_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Object__heap ti_sysbios_hal_Timer_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Object__sizeof ti_sysbios_hal_Timer_Object__sizeof__C = sizeof(ti_sysbios_hal_Timer_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Object__table ti_sysbios_hal_Timer_Object__table__C = ti_sysbios_hal_Timer_Object__table__V;


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_heaps_HeapMem_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_heaps_HeapMem_Params ti_sysbios_heaps_HeapMem_Object__PARAMS__C = {
    sizeof (ti_sysbios_heaps_HeapMem_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_heaps_HeapMem_Object__PARAMS__C.__iprms, /* instance */
    (xdc_SizeT)0x0,  /* minBlockAlign */
    ((xdc_Ptr)(0x0)),  /* buf */
    ((xdc_UArg)(0x0)),  /* size */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096];

/* Module__root__V */
ti_sysbios_heaps_HeapMem_Module__ ti_sysbios_heaps_HeapMem_Module__root__V = {
    {&ti_sysbios_heaps_HeapMem_Module__root__V.link,  /* link.next */
    &ti_sysbios_heaps_HeapMem_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_heaps_HeapMem_Object__ ti_sysbios_heaps_HeapMem_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_heaps_HeapMem_Module__FXNS__C,
        ((xdc_UArg)(0x8)),  /* align */
        ((void*)ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A),  /* buf */
        {
            ((ti_sysbios_heaps_HeapMem_Header*)0),  /* next */
            ((xdc_UArg)(0x1000)),  /* size */
        },  /* head */
        (xdc_SizeT)0x8,  /* minBlockAlign */
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsEnabled ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsIncluded ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsMask ti_sysbios_heaps_HeapMem_Module__diagsMask__C = ((CT__ti_sysbios_heaps_HeapMem_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gateObj ti_sysbios_heaps_HeapMem_Module__gateObj__C = ((CT__ti_sysbios_heaps_HeapMem_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateMutex_Object__table__V[0]));

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gatePrms ti_sysbios_heaps_HeapMem_Module__gatePrms__C = ((CT__ti_sysbios_heaps_HeapMem_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module__id__C = (xdc_Bits16)0x8034;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerDefined ti_sysbios_heaps_HeapMem_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerObj ti_sysbios_heaps_HeapMem_Module__loggerObj__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__startupDoneFxn ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C = ((CT__ti_sysbios_heaps_HeapMem_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__count ti_sysbios_heaps_HeapMem_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__heap ti_sysbios_heaps_HeapMem_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__sizeof ti_sysbios_heaps_HeapMem_Object__sizeof__C = sizeof(ti_sysbios_heaps_HeapMem_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__table ti_sysbios_heaps_HeapMem_Object__table__C = ti_sysbios_heaps_HeapMem_Object__table__V;

/* A_zeroBlock__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_zeroBlock ti_sysbios_heaps_HeapMem_A_zeroBlock__C = (((xdc_runtime_Assert_Id)2328) << 16 | 16);

/* A_heapSize__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_heapSize ti_sysbios_heaps_HeapMem_A_heapSize__C = (((xdc_runtime_Assert_Id)2364) << 16 | 16);

/* A_align__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_align ti_sysbios_heaps_HeapMem_A_align__C = (((xdc_runtime_Assert_Id)2409) << 16 | 16);

/* E_memory__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_E_memory ti_sysbios_heaps_HeapMem_E_memory__C = (((xdc_runtime_Error_Id)3665) << 16 | 0);

/* A_invalidFree__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_invalidFree ti_sysbios_heaps_HeapMem_A_invalidFree__C = (((xdc_runtime_Assert_Id)2300) << 16 | 16);

/* reqAlign__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_reqAlign ti_sysbios_heaps_HeapMem_reqAlign__C = (xdc_Int)0x8;


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Clock INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Clock_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Clock_Params ti_sysbios_knl_Clock_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Clock_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Clock_Object__PARAMS__C.__iprms, /* instance */
    0,  /* startFlag */
    (xdc_UInt)0x0,  /* period */
    ((xdc_UArg)0),  /* arg */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Clock_Module__ ti_sysbios_knl_Clock_Module__root__V = {
    {&ti_sysbios_knl_Clock_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Clock_Module__root__V.link},  /* link.prev */
};

/* Module__state__V */
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V = {
    (xdc_UInt32)0x0,  /* ticks */
    (xdc_UInt)0x0,  /* swiCount */
    (ti_sysbios_hal_Timer_Handle)&ti_sysbios_hal_Timer_Object__table__V[0],  /* timer */
    (ti_sysbios_knl_Swi_Handle)&ti_sysbios_knl_Swi_Object__table__V[0],  /* swi */
    (xdc_UInt32)0x0,  /* periodCounts */
    (xdc_UInt)0x0,  /* numTickSkip */
    (xdc_UInt32)0x0,  /* skipsWorkFunc */
    0,  /* inWorkFunc */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Module__state__V.Object_field_clockQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Module__state__V.Object_field_clockQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_clockQ */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsEnabled ti_sysbios_knl_Clock_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsIncluded ti_sysbios_knl_Clock_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsMask ti_sysbios_knl_Clock_Module__diagsMask__C = ((CT__ti_sysbios_knl_Clock_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__gateObj ti_sysbios_knl_Clock_Module__gateObj__C = ((CT__ti_sysbios_knl_Clock_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__gatePrms ti_sysbios_knl_Clock_Module__gatePrms__C = ((CT__ti_sysbios_knl_Clock_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__id ti_sysbios_knl_Clock_Module__id__C = (xdc_Bits16)0x8020;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerDefined ti_sysbios_knl_Clock_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerObj ti_sysbios_knl_Clock_Module__loggerObj__C = ((CT__ti_sysbios_knl_Clock_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn0 ti_sysbios_knl_Clock_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn1 ti_sysbios_knl_Clock_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn2 ti_sysbios_knl_Clock_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn4 ti_sysbios_knl_Clock_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn8 ti_sysbios_knl_Clock_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__startupDoneFxn ti_sysbios_knl_Clock_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Clock_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Object__count ti_sysbios_knl_Clock_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Object__heap ti_sysbios_knl_Clock_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Object__sizeof ti_sysbios_knl_Clock_Object__sizeof__C = sizeof(ti_sysbios_knl_Clock_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Object__table ti_sysbios_knl_Clock_Object__table__C = 0;

/* LW_delayed__C */
__FAR__ const CT__ti_sysbios_knl_Clock_LW_delayed ti_sysbios_knl_Clock_LW_delayed__C = (((xdc_runtime_Log_Event)3965) << 16 | 1024);

/* LM_tick__C */
__FAR__ const CT__ti_sysbios_knl_Clock_LM_tick ti_sysbios_knl_Clock_LM_tick__C = (((xdc_runtime_Log_Event)3987) << 16 | 768);

/* LM_begin__C */
__FAR__ const CT__ti_sysbios_knl_Clock_LM_begin ti_sysbios_knl_Clock_LM_begin__C = (((xdc_runtime_Log_Event)4005) << 16 | 768);

/* A_clockDisabled__C */
__FAR__ const CT__ti_sysbios_knl_Clock_A_clockDisabled ti_sysbios_knl_Clock_A_clockDisabled__C = (((xdc_runtime_Assert_Id)355) << 16 | 16);

/* A_badThreadType__C */
__FAR__ const CT__ti_sysbios_knl_Clock_A_badThreadType ti_sysbios_knl_Clock_A_badThreadType__C = (((xdc_runtime_Assert_Id)436) << 16 | 16);

/* tickSource__C */
__FAR__ const CT__ti_sysbios_knl_Clock_tickSource ti_sysbios_knl_Clock_tickSource__C = ti_sysbios_knl_Clock_TickSource_TIMER;

/* tickMode__C */
__FAR__ const CT__ti_sysbios_knl_Clock_tickMode ti_sysbios_knl_Clock_tickMode__C = ti_sysbios_knl_Clock_TickMode_PERIODIC;

/* timerId__C */
__FAR__ const CT__ti_sysbios_knl_Clock_timerId ti_sysbios_knl_Clock_timerId__C = (xdc_UInt)(-0x0 - 1);

/* tickPeriod__C */
__FAR__ const CT__ti_sysbios_knl_Clock_tickPeriod ti_sysbios_knl_Clock_tickPeriod__C = (xdc_UInt32)0x3e8;


/*
 * ======== ti.sysbios.knl.Idle INITIALIZERS ========
 */

/* --> ti_sysbios_knl_Idle_funcList__A */
const __T1_ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__A[1] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_hal_Hwi_checkStack)),  /* [0] */
};

/* --> ti_sysbios_knl_Idle_coreList__A */
const __T1_ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__A[1] = {
    (xdc_UInt)0x0,  /* [0] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsEnabled ti_sysbios_knl_Idle_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsIncluded ti_sysbios_knl_Idle_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsMask ti_sysbios_knl_Idle_Module__diagsMask__C = ((CT__ti_sysbios_knl_Idle_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__gateObj ti_sysbios_knl_Idle_Module__gateObj__C = ((CT__ti_sysbios_knl_Idle_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__gatePrms ti_sysbios_knl_Idle_Module__gatePrms__C = ((CT__ti_sysbios_knl_Idle_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__id ti_sysbios_knl_Idle_Module__id__C = (xdc_Bits16)0x8021;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerDefined ti_sysbios_knl_Idle_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerObj ti_sysbios_knl_Idle_Module__loggerObj__C = ((CT__ti_sysbios_knl_Idle_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn0 ti_sysbios_knl_Idle_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn1 ti_sysbios_knl_Idle_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn2 ti_sysbios_knl_Idle_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn4 ti_sysbios_knl_Idle_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn8 ti_sysbios_knl_Idle_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__startupDoneFxn ti_sysbios_knl_Idle_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Idle_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Object__count ti_sysbios_knl_Idle_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Object__heap ti_sysbios_knl_Idle_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Object__sizeof ti_sysbios_knl_Idle_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Object__table ti_sysbios_knl_Idle_Object__table__C = 0;

/* funcList__C */
__FAR__ const CT__ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__C = {1, ((__T1_ti_sysbios_knl_Idle_funcList*)ti_sysbios_knl_Idle_funcList__A)};

/* coreList__C */
__FAR__ const CT__ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__C = {1, ((__T1_ti_sysbios_knl_Idle_coreList*)ti_sysbios_knl_Idle_coreList__A)};


/*
 * ======== ti.sysbios.knl.Intrinsics INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsEnabled ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsIncluded ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsMask ti_sysbios_knl_Intrinsics_Module__diagsMask__C = ((CT__ti_sysbios_knl_Intrinsics_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__gateObj ti_sysbios_knl_Intrinsics_Module__gateObj__C = ((CT__ti_sysbios_knl_Intrinsics_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__gatePrms ti_sysbios_knl_Intrinsics_Module__gatePrms__C = ((CT__ti_sysbios_knl_Intrinsics_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__id ti_sysbios_knl_Intrinsics_Module__id__C = (xdc_Bits16)0x8022;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerDefined ti_sysbios_knl_Intrinsics_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerObj ti_sysbios_knl_Intrinsics_Module__loggerObj__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn0 ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn1 ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn2 ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn4 ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn8 ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__startupDoneFxn ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Intrinsics_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__count ti_sysbios_knl_Intrinsics_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__heap ti_sysbios_knl_Intrinsics_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__sizeof ti_sysbios_knl_Intrinsics_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__table ti_sysbios_knl_Intrinsics_Object__table__C = 0;


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Queue INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Queue_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Queue_Params ti_sysbios_knl_Queue_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Queue_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Queue_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Queue_Module__ ti_sysbios_knl_Queue_Module__root__V = {
    {&ti_sysbios_knl_Queue_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Queue_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsEnabled ti_sysbios_knl_Queue_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsIncluded ti_sysbios_knl_Queue_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsMask ti_sysbios_knl_Queue_Module__diagsMask__C = ((CT__ti_sysbios_knl_Queue_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__gateObj ti_sysbios_knl_Queue_Module__gateObj__C = ((CT__ti_sysbios_knl_Queue_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__gatePrms ti_sysbios_knl_Queue_Module__gatePrms__C = ((CT__ti_sysbios_knl_Queue_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__id ti_sysbios_knl_Queue_Module__id__C = (xdc_Bits16)0x8023;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerDefined ti_sysbios_knl_Queue_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerObj ti_sysbios_knl_Queue_Module__loggerObj__C = ((CT__ti_sysbios_knl_Queue_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn0 ti_sysbios_knl_Queue_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn1 ti_sysbios_knl_Queue_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn2 ti_sysbios_knl_Queue_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn4 ti_sysbios_knl_Queue_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn8 ti_sysbios_knl_Queue_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__startupDoneFxn ti_sysbios_knl_Queue_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Queue_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Object__count ti_sysbios_knl_Queue_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Object__heap ti_sysbios_knl_Queue_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Object__sizeof ti_sysbios_knl_Queue_Object__sizeof__C = sizeof(ti_sysbios_knl_Queue_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Object__table ti_sysbios_knl_Queue_Object__table__C = 0;


/*
 * ======== ti.sysbios.knl.Semaphore INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Semaphore_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Semaphore_Params ti_sysbios_knl_Semaphore_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Semaphore_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Semaphore_Object__PARAMS__C.__iprms, /* instance */
    0,  /* event */
    (xdc_UInt)0x1,  /* eventId */
    ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Semaphore_Module__ ti_sysbios_knl_Semaphore_Module__root__V = {
    {&ti_sysbios_knl_Semaphore_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Semaphore_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsEnabled ti_sysbios_knl_Semaphore_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsIncluded ti_sysbios_knl_Semaphore_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsMask ti_sysbios_knl_Semaphore_Module__diagsMask__C = ((CT__ti_sysbios_knl_Semaphore_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gateObj ti_sysbios_knl_Semaphore_Module__gateObj__C = ((CT__ti_sysbios_knl_Semaphore_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gatePrms ti_sysbios_knl_Semaphore_Module__gatePrms__C = ((CT__ti_sysbios_knl_Semaphore_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__id ti_sysbios_knl_Semaphore_Module__id__C = (xdc_Bits16)0x8024;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerDefined ti_sysbios_knl_Semaphore_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerObj ti_sysbios_knl_Semaphore_Module__loggerObj__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__startupDoneFxn ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Semaphore_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__count ti_sysbios_knl_Semaphore_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__heap ti_sysbios_knl_Semaphore_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__sizeof ti_sysbios_knl_Semaphore_Object__sizeof__C = sizeof(ti_sysbios_knl_Semaphore_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__table ti_sysbios_knl_Semaphore_Object__table__C = 0;

/* LM_post__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_post ti_sysbios_knl_Semaphore_LM_post__C = (((xdc_runtime_Log_Event)4037) << 16 | 768);

/* LM_pend__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_pend ti_sysbios_knl_Semaphore_LM_pend__C = (((xdc_runtime_Log_Event)4067) << 16 | 768);

/* A_noEvents__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_noEvents ti_sysbios_knl_Semaphore_A_noEvents__C = (((xdc_runtime_Assert_Id)756) << 16 | 16);

/* A_invTimeout__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_invTimeout ti_sysbios_knl_Semaphore_A_invTimeout__C = (((xdc_runtime_Assert_Id)811) << 16 | 16);

/* A_badContext__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_badContext ti_sysbios_knl_Semaphore_A_badContext__C = (((xdc_runtime_Assert_Id)635) << 16 | 16);

/* A_overflow__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_overflow ti_sysbios_knl_Semaphore_A_overflow__C = (((xdc_runtime_Assert_Id)876) << 16 | 16);

/* supportsEvents__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_supportsEvents ti_sysbios_knl_Semaphore_supportsEvents__C = 0;

/* eventPost__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_eventPost ti_sysbios_knl_Semaphore_eventPost__C = ((CT__ti_sysbios_knl_Semaphore_eventPost)0);

/* eventSync__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_eventSync ti_sysbios_knl_Semaphore_eventSync__C = ((CT__ti_sysbios_knl_Semaphore_eventSync)0);


/*
 * ======== ti.sysbios.knl.Swi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Swi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Swi_Params ti_sysbios_knl_Swi_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Swi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Swi_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_UArg)(0x0)),  /* arg0 */
    ((xdc_UArg)(0x0)),  /* arg1 */
    (xdc_UInt)(-0x0 - 1),  /* priority */
    (xdc_UInt)0x0,  /* trigger */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Swi_Module__ ti_sysbios_knl_Swi_Module__root__V = {
    {&ti_sysbios_knl_Swi_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Swi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Object__table__V[0].qElem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Object__table__V[0].qElem)),  /* prev */
        },  /* qElem */
        ((xdc_Void(*)(xdc_UArg,xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_workFunc__E)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg0 */
        ((xdc_UArg)(0x0)),  /* arg1 */
        (xdc_UInt)0xf,  /* priority */
        (xdc_UInt)0x8000,  /* mask */
        0,  /* posted */
        (xdc_UInt)0x0,  /* initTrigger */
        (xdc_UInt)0x0,  /* trigger */
        (ti_sysbios_knl_Queue_Handle)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15],  /* readyQ */
        ((void*)0),  /* hookEnv */
    },
};

/* --> ti_sysbios_knl_Swi_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Swi_Module_State__readyQ ti_sysbios_knl_Swi_Module_State_0_readyQ__A[16] = {
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[0].elem)),  /* prev */
        },  /* elem */
    },  /* [0] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[1].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[1].elem)),  /* prev */
        },  /* elem */
    },  /* [1] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[2].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[2].elem)),  /* prev */
        },  /* elem */
    },  /* [2] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[3].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[3].elem)),  /* prev */
        },  /* elem */
    },  /* [3] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[4].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[4].elem)),  /* prev */
        },  /* elem */
    },  /* [4] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[5].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[5].elem)),  /* prev */
        },  /* elem */
    },  /* [5] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[6].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[6].elem)),  /* prev */
        },  /* elem */
    },  /* [6] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[7].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[7].elem)),  /* prev */
        },  /* elem */
    },  /* [7] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[8].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[8].elem)),  /* prev */
        },  /* elem */
    },  /* [8] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[9].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[9].elem)),  /* prev */
        },  /* elem */
    },  /* [9] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[10].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[10].elem)),  /* prev */
        },  /* elem */
    },  /* [10] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[11].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[11].elem)),  /* prev */
        },  /* elem */
    },  /* [11] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[12].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[12].elem)),  /* prev */
        },  /* elem */
    },  /* [12] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[13].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[13].elem)),  /* prev */
        },  /* elem */
    },  /* [13] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[14].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[14].elem)),  /* prev */
        },  /* elem */
    },  /* [14] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15].elem)),  /* prev */
        },  /* elem */
    },  /* [15] */
};

/* Module__state__V */
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V = {
    1,  /* locked */
    (xdc_UInt)0x0,  /* curSet */
    (xdc_UInt)0x0,  /* curTrigger */
    0,  /* curSwi */
    0,  /* curQ */
    ((void*)ti_sysbios_knl_Swi_Module_State_0_readyQ__A),  /* readyQ */
    ((void*)0),  /* constructedSwis */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsEnabled ti_sysbios_knl_Swi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsIncluded ti_sysbios_knl_Swi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsMask ti_sysbios_knl_Swi_Module__diagsMask__C = ((CT__ti_sysbios_knl_Swi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__gateObj ti_sysbios_knl_Swi_Module__gateObj__C = ((CT__ti_sysbios_knl_Swi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__gatePrms ti_sysbios_knl_Swi_Module__gatePrms__C = ((CT__ti_sysbios_knl_Swi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__id ti_sysbios_knl_Swi_Module__id__C = (xdc_Bits16)0x8025;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerDefined ti_sysbios_knl_Swi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerObj ti_sysbios_knl_Swi_Module__loggerObj__C = ((CT__ti_sysbios_knl_Swi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn0 ti_sysbios_knl_Swi_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn1 ti_sysbios_knl_Swi_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn2 ti_sysbios_knl_Swi_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn4 ti_sysbios_knl_Swi_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn8 ti_sysbios_knl_Swi_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__startupDoneFxn ti_sysbios_knl_Swi_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Swi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Object__count ti_sysbios_knl_Swi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Object__heap ti_sysbios_knl_Swi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Object__sizeof ti_sysbios_knl_Swi_Object__sizeof__C = sizeof(ti_sysbios_knl_Swi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Object__table ti_sysbios_knl_Swi_Object__table__C = ti_sysbios_knl_Swi_Object__table__V;

/* LM_begin__C */
__FAR__ const CT__ti_sysbios_knl_Swi_LM_begin ti_sysbios_knl_Swi_LM_begin__C = (((xdc_runtime_Log_Event)4110) << 16 | 768);

/* LD_end__C */
__FAR__ const CT__ti_sysbios_knl_Swi_LD_end ti_sysbios_knl_Swi_LD_end__C = (((xdc_runtime_Log_Event)4157) << 16 | 512);

/* LM_post__C */
__FAR__ const CT__ti_sysbios_knl_Swi_LM_post ti_sysbios_knl_Swi_LM_post__C = (((xdc_runtime_Log_Event)4175) << 16 | 768);

/* A_swiDisabled__C */
__FAR__ const CT__ti_sysbios_knl_Swi_A_swiDisabled ti_sysbios_knl_Swi_A_swiDisabled__C = (((xdc_runtime_Assert_Id)930) << 16 | 16);

/* A_badPriority__C */
__FAR__ const CT__ti_sysbios_knl_Swi_A_badPriority ti_sysbios_knl_Swi_A_badPriority__C = (((xdc_runtime_Assert_Id)987) << 16 | 16);

/* numPriorities__C */
__FAR__ const CT__ti_sysbios_knl_Swi_numPriorities ti_sysbios_knl_Swi_numPriorities__C = (xdc_UInt)0x10;

/* hooks__C */
__FAR__ const CT__ti_sysbios_knl_Swi_hooks ti_sysbios_knl_Swi_hooks__C = {0, 0};

/* taskDisable__C */
__FAR__ const CT__ti_sysbios_knl_Swi_taskDisable ti_sysbios_knl_Swi_taskDisable__C = ((CT__ti_sysbios_knl_Swi_taskDisable)((xdc_Fxn)ti_sysbios_knl_Task_disable__E));

/* taskRestore__C */
__FAR__ const CT__ti_sysbios_knl_Swi_taskRestore ti_sysbios_knl_Swi_taskRestore__C = ((CT__ti_sysbios_knl_Swi_taskRestore)((xdc_Fxn)ti_sysbios_knl_Task_restore__E));

/* numConstructedSwis__C */
__FAR__ const CT__ti_sysbios_knl_Swi_numConstructedSwis ti_sysbios_knl_Swi_numConstructedSwis__C = (xdc_UInt)0x0;


/*
 * ======== ti.sysbios.knl.Task INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Task_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Task_Params ti_sysbios_knl_Task_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Task_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Task_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_UArg)(0x0)),  /* arg0 */
    ((xdc_UArg)(0x0)),  /* arg1 */
    (xdc_Int)0x1,  /* priority */
    ((xdc_Ptr)0),  /* stack */
    (xdc_SizeT)0x0,  /* stackSize */
    0,  /* stackHeap */
    ((xdc_Ptr)0),  /* env */
    1,  /* vitalTaskFlag */
    (xdc_UInt)0x0,  /* affinity */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_knl_Task_Instance_State_0_stack__A */
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048];

/* --> ti_sysbios_knl_Task_Instance_State_0_hookEnv__A */
__T1_ti_sysbios_knl_Task_Instance_State__hookEnv ti_sysbios_knl_Task_Instance_State_0_hookEnv__A[1];

/* Module__root__V */
ti_sysbios_knl_Task_Module__ ti_sysbios_knl_Task_Module__root__V = {
    {&ti_sysbios_knl_Task_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Task_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Object__table__V[0].qElem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Object__table__V[0].qElem)),  /* prev */
        },  /* qElem */
        (xdc_Int)0x0,  /* priority */
        (xdc_UInt)0x1,  /* mask */
        ((xdc_Ptr)0),  /* context */
        ti_sysbios_knl_Task_Mode_INACTIVE,  /* mode */
        ((ti_sysbios_knl_Task_PendElem*)0),  /* pendElem */
        (xdc_SizeT)0x800,  /* stackSize */
        ((void*)ti_sysbios_knl_Task_Instance_State_0_stack__A),  /* stack */
        0,  /* stackHeap */
        ((xdc_Void(*)(xdc_UArg,xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Idle_loop__E)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg0 */
        ((xdc_UArg)(0x0)),  /* arg1 */
        ((xdc_Ptr)0),  /* env */
        ((void*)ti_sysbios_knl_Task_Instance_State_0_hookEnv__A),  /* hookEnv */
        1,  /* vitalTaskFlag */
        0,  /* readyQ */
        (xdc_UInt)0x0,  /* curCoreId */
        (xdc_UInt)0x0,  /* affinity */
    },
};

/* --> ti_sysbios_knl_Task_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Task_Module_State__readyQ ti_sysbios_knl_Task_Module_State_0_readyQ__A[16] = {
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[0].elem)),  /* prev */
        },  /* elem */
    },  /* [0] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[1].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[1].elem)),  /* prev */
        },  /* elem */
    },  /* [1] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[2].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[2].elem)),  /* prev */
        },  /* elem */
    },  /* [2] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[3].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[3].elem)),  /* prev */
        },  /* elem */
    },  /* [3] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[4].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[4].elem)),  /* prev */
        },  /* elem */
    },  /* [4] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[5].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[5].elem)),  /* prev */
        },  /* elem */
    },  /* [5] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[6].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[6].elem)),  /* prev */
        },  /* elem */
    },  /* [6] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[7].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[7].elem)),  /* prev */
        },  /* elem */
    },  /* [7] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[8].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[8].elem)),  /* prev */
        },  /* elem */
    },  /* [8] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[9].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[9].elem)),  /* prev */
        },  /* elem */
    },  /* [9] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[10].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[10].elem)),  /* prev */
        },  /* elem */
    },  /* [10] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[11].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[11].elem)),  /* prev */
        },  /* elem */
    },  /* [11] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[12].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[12].elem)),  /* prev */
        },  /* elem */
    },  /* [12] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[13].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[13].elem)),  /* prev */
        },  /* elem */
    },  /* [13] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[14].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[14].elem)),  /* prev */
        },  /* elem */
    },  /* [14] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[15].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[15].elem)),  /* prev */
        },  /* elem */
    },  /* [15] */
};

/* --> ti_sysbios_knl_Task_Module_State_0_idleTask__A */
__T1_ti_sysbios_knl_Task_Module_State__idleTask ti_sysbios_knl_Task_Module_State_0_idleTask__A[1] = {
    (ti_sysbios_knl_Task_Handle)&ti_sysbios_knl_Task_Object__table__V[0],  /* [0] */
};

/* Module__state__V */
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V = {
    1,  /* locked */
    (xdc_UInt)0x0,  /* curSet */
    0,  /* workFlag */
    (xdc_UInt)0x1,  /* vitalTasks */
    0,  /* curTask */
    0,  /* curQ */
    ((void*)ti_sysbios_knl_Task_Module_State_0_readyQ__A),  /* readyQ */
    ((void*)0),  /* smpCurSet */
    ((void*)0),  /* smpCurMask */
    ((void*)0),  /* smpCurTask */
    ((void*)0),  /* smpCurQ */
    ((void*)0),  /* smpReadyQ */
    ((void*)ti_sysbios_knl_Task_Module_State_0_idleTask__A),  /* idleTask */
    ((void*)0),  /* constructedTasks */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_inactiveQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_inactiveQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_inactiveQ */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_terminatedQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_terminatedQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_terminatedQ */
};

/* --> ti_sysbios_knl_Task_hooks__A */
const __T1_ti_sysbios_knl_Task_hooks ti_sysbios_knl_Task_hooks__A[1] = {
    {
        ((xdc_Void(*)(xdc_Int))0),  /* registerFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle,xdc_runtime_Error_Block*))0),  /* createFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle))0),  /* readyFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle,ti_sysbios_knl_Task_Handle))((xdc_Fxn)ti_sysbios_knl_Task_checkStacks)),  /* switchFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle))0),  /* exitFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle))0),  /* deleteFxn */
    },  /* [0] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsEnabled ti_sysbios_knl_Task_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsIncluded ti_sysbios_knl_Task_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsMask ti_sysbios_knl_Task_Module__diagsMask__C = ((CT__ti_sysbios_knl_Task_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__gateObj ti_sysbios_knl_Task_Module__gateObj__C = ((CT__ti_sysbios_knl_Task_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__gatePrms ti_sysbios_knl_Task_Module__gatePrms__C = ((CT__ti_sysbios_knl_Task_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__id ti_sysbios_knl_Task_Module__id__C = (xdc_Bits16)0x8026;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerDefined ti_sysbios_knl_Task_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerObj ti_sysbios_knl_Task_Module__loggerObj__C = ((CT__ti_sysbios_knl_Task_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn0 ti_sysbios_knl_Task_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn1 ti_sysbios_knl_Task_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn2 ti_sysbios_knl_Task_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn4 ti_sysbios_knl_Task_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn8 ti_sysbios_knl_Task_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__startupDoneFxn ti_sysbios_knl_Task_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Task_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Task_Object__count ti_sysbios_knl_Task_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Task_Object__heap ti_sysbios_knl_Task_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Task_Object__sizeof ti_sysbios_knl_Task_Object__sizeof__C = sizeof(ti_sysbios_knl_Task_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Task_Object__table ti_sysbios_knl_Task_Object__table__C = ti_sysbios_knl_Task_Object__table__V;

/* LM_switch__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_switch ti_sysbios_knl_Task_LM_switch__C = (((xdc_runtime_Log_Event)4215) << 16 | 768);

/* LM_sleep__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_sleep ti_sysbios_knl_Task_LM_sleep__C = (((xdc_runtime_Log_Event)4283) << 16 | 768);

/* LD_ready__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_ready ti_sysbios_knl_Task_LD_ready__C = (((xdc_runtime_Log_Event)4328) << 16 | 512);

/* LD_block__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_block ti_sysbios_knl_Task_LD_block__C = (((xdc_runtime_Log_Event)4369) << 16 | 512);

/* LM_yield__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_yield ti_sysbios_knl_Task_LM_yield__C = (((xdc_runtime_Log_Event)4401) << 16 | 768);

/* LM_setPri__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_setPri ti_sysbios_knl_Task_LM_setPri__C = (((xdc_runtime_Log_Event)4449) << 16 | 768);

/* LD_exit__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_exit ti_sysbios_knl_Task_LD_exit__C = (((xdc_runtime_Log_Event)4505) << 16 | 512);

/* LM_setAffinity__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_setAffinity ti_sysbios_knl_Task_LM_setAffinity__C = (((xdc_runtime_Log_Event)4536) << 16 | 768);

/* LM_schedule__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_schedule ti_sysbios_knl_Task_LM_schedule__C = (((xdc_runtime_Log_Event)4619) << 16 | 1024);

/* LM_noWork__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_noWork ti_sysbios_knl_Task_LM_noWork__C = (((xdc_runtime_Log_Event)4705) << 16 | 1024);

/* E_stackOverflow__C */
__FAR__ const CT__ti_sysbios_knl_Task_E_stackOverflow ti_sysbios_knl_Task_E_stackOverflow__C = (((xdc_runtime_Error_Id)3317) << 16 | 0);

/* E_spOutOfBounds__C */
__FAR__ const CT__ti_sysbios_knl_Task_E_spOutOfBounds ti_sysbios_knl_Task_E_spOutOfBounds__C = (((xdc_runtime_Error_Id)3360) << 16 | 0);

/* E_deleteNotAllowed__C */
__FAR__ const CT__ti_sysbios_knl_Task_E_deleteNotAllowed ti_sysbios_knl_Task_E_deleteNotAllowed__C = (((xdc_runtime_Error_Id)3411) << 16 | 0);

/* A_badThreadType__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badThreadType ti_sysbios_knl_Task_A_badThreadType__C = (((xdc_runtime_Assert_Id)1036) << 16 | 16);

/* A_badTaskState__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badTaskState ti_sysbios_knl_Task_A_badTaskState__C = (((xdc_runtime_Assert_Id)1105) << 16 | 16);

/* A_noPendElem__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_noPendElem ti_sysbios_knl_Task_A_noPendElem__C = (((xdc_runtime_Assert_Id)1159) << 16 | 16);

/* A_taskDisabled__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_taskDisabled ti_sysbios_knl_Task_A_taskDisabled__C = (((xdc_runtime_Assert_Id)1213) << 16 | 16);

/* A_badPriority__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badPriority ti_sysbios_knl_Task_A_badPriority__C = (((xdc_runtime_Assert_Id)1276) << 16 | 16);

/* A_badTimeout__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badTimeout ti_sysbios_knl_Task_A_badTimeout__C = (((xdc_runtime_Assert_Id)1326) << 16 | 16);

/* A_badAffinity__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badAffinity ti_sysbios_knl_Task_A_badAffinity__C = (((xdc_runtime_Assert_Id)1361) << 16 | 16);

/* numPriorities__C */
__FAR__ const CT__ti_sysbios_knl_Task_numPriorities ti_sysbios_knl_Task_numPriorities__C = (xdc_UInt)0x10;

/* defaultStackSize__C */
__FAR__ const CT__ti_sysbios_knl_Task_defaultStackSize ti_sysbios_knl_Task_defaultStackSize__C = (xdc_SizeT)0x800;

/* defaultStackHeap__C */
__FAR__ const CT__ti_sysbios_knl_Task_defaultStackHeap ti_sysbios_knl_Task_defaultStackHeap__C = 0;

/* allBlockedFunc__C */
__FAR__ const CT__ti_sysbios_knl_Task_allBlockedFunc ti_sysbios_knl_Task_allBlockedFunc__C = ((CT__ti_sysbios_knl_Task_allBlockedFunc)0);

/* initStackFlag__C */
__FAR__ const CT__ti_sysbios_knl_Task_initStackFlag ti_sysbios_knl_Task_initStackFlag__C = 1;

/* deleteTerminatedTasks__C */
__FAR__ const CT__ti_sysbios_knl_Task_deleteTerminatedTasks ti_sysbios_knl_Task_deleteTerminatedTasks__C = 0;

/* hooks__C */
__FAR__ const CT__ti_sysbios_knl_Task_hooks ti_sysbios_knl_Task_hooks__C = {1, ((__T1_ti_sysbios_knl_Task_hooks*)ti_sysbios_knl_Task_hooks__A)};

/* numConstructedTasks__C */
__FAR__ const CT__ti_sysbios_knl_Task_numConstructedTasks ti_sysbios_knl_Task_numConstructedTasks__C = (xdc_UInt)0x0;

/* startupHookFunc__C */
__FAR__ const CT__ti_sysbios_knl_Task_startupHookFunc ti_sysbios_knl_Task_startupHookFunc__C = ((CT__ti_sysbios_knl_Task_startupHookFunc)0);


/*
 * ======== ti.sysbios.knl.Task_SupportProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.timers.timer64.Timer INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_timers_timer64_Timer_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_timers_timer64_Timer_Params ti_sysbios_timers_timer64_Timer_Object__PARAMS__C = {
    sizeof (ti_sysbios_timers_timer64_Timer_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_timers_timer64_Timer_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)0),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    {
        (xdc_Bits8)0x0,  /* tien */
        (xdc_Bits8)0x0,  /* invout */
        (xdc_Bits8)0x0,  /* invin */
        (xdc_UInt8)0x1,  /* pwid */
        (xdc_Bits8)0x0,  /* cp */
    },  /* controlInit */
    {
        0,  /* free */
        0,  /* soft */
    },  /* emuMgtInit */
    {
        (xdc_Bits8)0x0,  /* gpint12_eni */
        (xdc_Bits8)0x0,  /* gpint12_eno */
        (xdc_Bits8)0x0,  /* gpint12_invi */
        (xdc_Bits8)0x0,  /* gpint12_invo */
        (xdc_Bits8)0x0,  /* gpint34_eni */
        (xdc_Bits8)0x0,  /* gpint34_eno */
        (xdc_Bits8)0x0,  /* gpint34_invi */
        (xdc_Bits8)0x0,  /* gpint34_invo */
        (xdc_Bits8)0x0,  /* gpio_eni12 */
        (xdc_Bits8)0x0,  /* gpio_eno12 */
        (xdc_Bits8)0x0,  /* gpio_eni34 */
        (xdc_Bits8)0x0,  /* gpio_eno34 */
    },  /* gpioIntEn */
    {
        (xdc_Bits8)0x0,  /* gpio_dati12 */
        (xdc_Bits8)0x0,  /* gpio_dato12 */
        (xdc_Bits8)0x0,  /* gpio_dati34 */
        (xdc_Bits8)0x0,  /* gpio_dato34 */
        (xdc_Bits8)0x0,  /* gpio_diri12 */
        (xdc_Bits8)0x0,  /* gpio_diro12 */
        (xdc_Bits8)0x0,  /* gpio_diri34 */
        (xdc_Bits8)0x0,  /* gpio_diro34 */
    },  /* gpioDatDir */
    ti_sysbios_timers_timer64_Timer_Half_DEFAULT,  /* half */
    ((ti_sysbios_hal_Hwi_Params*)0),  /* hwiParams */
    (xdc_Int)(-0x0 - 1),  /* intNum */
    (xdc_UInt)0x0,  /* prescalar */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_timers_timer64_Timer_Module__ ti_sysbios_timers_timer64_Timer_Module__root__V = {
    {&ti_sysbios_timers_timer64_Timer_Module__root__V.link,  /* link.next */
    &ti_sysbios_timers_timer64_Timer_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_timers_timer64_Timer_Object__ ti_sysbios_timers_timer64_Timer_Object__table__V[1] = {
    {/* instance#0 */
        0,
        1,  /* staticInst */
        (xdc_Int)(-0x0 - 1),  /* id */
        ti_sysbios_timers_timer64_Timer_Half_LOWER,  /* half */
        (xdc_UInt)0x10,  /* tcrInit */
        (xdc_UInt)0x0,  /* emumgtInit */
        (xdc_UInt)0x0,  /* gpioIntEn */
        (xdc_UInt)0x0,  /* gpioDatDir */
        ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
        ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
        (xdc_UInt)0x3e8,  /* period */
        ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
        (xdc_UInt)0x0,  /* prescalar */
        (xdc_UInt)0xe,  /* intNum */
        ((xdc_UArg)0),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_doTick__I)),  /* tickFxn */
        {
            (xdc_Bits32)0x0,  /* hi */
            (xdc_Bits32)0x0,  /* lo */
        },  /* extFreq */
        (ti_sysbios_hal_Hwi_Handle)&ti_sysbios_hal_Hwi_Object__table__V[0],  /* hwi */
    },
};

/* --> ti_sysbios_timers_timer64_Timer_Module_State_0_intFreqs__A */
__T1_ti_sysbios_timers_timer64_Timer_Module_State__intFreqs ti_sysbios_timers_timer64_Timer_Module_State_0_intFreqs__A[16] = {
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [0] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [1] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [2] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [3] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [4] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [5] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [6] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [7] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [8] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [9] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [10] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [11] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [12] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [13] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [14] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)1.6666666666666666E8,  /* lo */
    },  /* [15] */
};

/* --> ti_sysbios_timers_timer64_Timer_Module_State_0_gctrl__A */
__T1_ti_sysbios_timers_timer64_Timer_Module_State__gctrl ti_sysbios_timers_timer64_Timer_Module_State_0_gctrl__A[16] = {
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [0] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [1] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [2] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [3] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [4] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [5] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [6] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [7] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [8] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [9] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [10] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [11] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [12] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [13] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [14] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [15] */
};

/* --> ti_sysbios_timers_timer64_Timer_Module_State_0_device__A */
__T1_ti_sysbios_timers_timer64_Timer_Module_State__device ti_sysbios_timers_timer64_Timer_Module_State_0_device__A[32] = {
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x2200000)),  /* baseAddr */
    },  /* [0] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x2200000)),  /* baseAddr */
    },  /* [1] */
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x2210000)),  /* baseAddr */
    },  /* [2] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x2210000)),  /* baseAddr */
    },  /* [3] */
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x2220000)),  /* baseAddr */
    },  /* [4] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x2220000)),  /* baseAddr */
    },  /* [5] */
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x2230000)),  /* baseAddr */
    },  /* [6] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x2230000)),  /* baseAddr */
    },  /* [7] */
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x2240000)),  /* baseAddr */
    },  /* [8] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x2240000)),  /* baseAddr */
    },  /* [9] */
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x2250000)),  /* baseAddr */
    },  /* [10] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x2250000)),  /* baseAddr */
    },  /* [11] */
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x2260000)),  /* baseAddr */
    },  /* [12] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x2260000)),  /* baseAddr */
    },  /* [13] */
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x2270000)),  /* baseAddr */
    },  /* [14] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x2270000)),  /* baseAddr */
    },  /* [15] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x42,  /* eventId */
        ((xdc_Ptr)((void*)0x2280000)),  /* baseAddr */
    },  /* [16] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x43,  /* eventId */
        ((xdc_Ptr)((void*)0x2280000)),  /* baseAddr */
    },  /* [17] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x44,  /* eventId */
        ((xdc_Ptr)((void*)0x2290000)),  /* baseAddr */
    },  /* [18] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x45,  /* eventId */
        ((xdc_Ptr)((void*)0x2290000)),  /* baseAddr */
    },  /* [19] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x46,  /* eventId */
        ((xdc_Ptr)((void*)0x22a0000)),  /* baseAddr */
    },  /* [20] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x47,  /* eventId */
        ((xdc_Ptr)((void*)0x22a0000)),  /* baseAddr */
    },  /* [21] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x48,  /* eventId */
        ((xdc_Ptr)((void*)0x22b0000)),  /* baseAddr */
    },  /* [22] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x49,  /* eventId */
        ((xdc_Ptr)((void*)0x22b0000)),  /* baseAddr */
    },  /* [23] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x4a,  /* eventId */
        ((xdc_Ptr)((void*)0x22c0000)),  /* baseAddr */
    },  /* [24] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x4b,  /* eventId */
        ((xdc_Ptr)((void*)0x22c0000)),  /* baseAddr */
    },  /* [25] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x4c,  /* eventId */
        ((xdc_Ptr)((void*)0x22d0000)),  /* baseAddr */
    },  /* [26] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x4d,  /* eventId */
        ((xdc_Ptr)((void*)0x22d0000)),  /* baseAddr */
    },  /* [27] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x4e,  /* eventId */
        ((xdc_Ptr)((void*)0x22e0000)),  /* baseAddr */
    },  /* [28] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x4f,  /* eventId */
        ((xdc_Ptr)((void*)0x22e0000)),  /* baseAddr */
    },  /* [29] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x50,  /* eventId */
        ((xdc_Ptr)((void*)0x22f0000)),  /* baseAddr */
    },  /* [30] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x51,  /* eventId */
        ((xdc_Ptr)((void*)0x22f0000)),  /* baseAddr */
    },  /* [31] */
};

/* --> ti_sysbios_timers_timer64_Timer_Module_State_0_handles__A */
__T1_ti_sysbios_timers_timer64_Timer_Module_State__handles ti_sysbios_timers_timer64_Timer_Module_State_0_handles__A[32] = {
    (ti_sysbios_timers_timer64_Timer_Handle)&ti_sysbios_timers_timer64_Timer_Object__table__V[0],  /* [0] */
    0,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
    0,  /* [4] */
    0,  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    0,  /* [8] */
    0,  /* [9] */
    0,  /* [10] */
    0,  /* [11] */
    0,  /* [12] */
    0,  /* [13] */
    0,  /* [14] */
    0,  /* [15] */
    0,  /* [16] */
    0,  /* [17] */
    0,  /* [18] */
    0,  /* [19] */
    0,  /* [20] */
    0,  /* [21] */
    0,  /* [22] */
    0,  /* [23] */
    0,  /* [24] */
    0,  /* [25] */
    0,  /* [26] */
    0,  /* [27] */
    0,  /* [28] */
    0,  /* [29] */
    0,  /* [30] */
    0,  /* [31] */
};

/* Module__state__V */
ti_sysbios_timers_timer64_Timer_Module_State__ ti_sysbios_timers_timer64_Timer_Module__state__V = {
    (xdc_Bits32)(-0x0 - 1),  /* availMask */
    ((void*)ti_sysbios_timers_timer64_Timer_Module_State_0_intFreqs__A),  /* intFreqs */
    ((void*)ti_sysbios_timers_timer64_Timer_Module_State_0_gctrl__A),  /* gctrl */
    ((void*)ti_sysbios_timers_timer64_Timer_Module_State_0_device__A),  /* device */
    ((void*)ti_sysbios_timers_timer64_Timer_Module_State_0_handles__A),  /* handles */
};

/* --> ti_sysbios_timers_timer64_Timer_timerSettings__A */
const __T1_ti_sysbios_timers_timer64_Timer_timerSettings ti_sysbios_timers_timer64_Timer_timerSettings__A[16] = {
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [0] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [1] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [2] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [3] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [4] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [5] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [6] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [7] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [8] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [9] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [10] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [11] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [12] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [13] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [14] */
    {
        ti_sysbios_timers_timer64_Timer_Mode_UNCHAINED,  /* mode */
        1,  /* master */
        (xdc_UInt16)0x0,  /* ownerCoreId */
    },  /* [15] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__diagsEnabled ti_sysbios_timers_timer64_Timer_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__diagsIncluded ti_sysbios_timers_timer64_Timer_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__diagsMask ti_sysbios_timers_timer64_Timer_Module__diagsMask__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__gateObj ti_sysbios_timers_timer64_Timer_Module__gateObj__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__gatePrms ti_sysbios_timers_timer64_Timer_Module__gatePrms__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__id ti_sysbios_timers_timer64_Timer_Module__id__C = (xdc_Bits16)0x8030;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__loggerDefined ti_sysbios_timers_timer64_Timer_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__loggerObj ti_sysbios_timers_timer64_Timer_Module__loggerObj__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn0 ti_sysbios_timers_timer64_Timer_Module__loggerFxn0__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn1 ti_sysbios_timers_timer64_Timer_Module__loggerFxn1__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn2 ti_sysbios_timers_timer64_Timer_Module__loggerFxn2__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn4 ti_sysbios_timers_timer64_Timer_Module__loggerFxn4__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn8 ti_sysbios_timers_timer64_Timer_Module__loggerFxn8__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Module__startupDoneFxn ti_sysbios_timers_timer64_Timer_Module__startupDoneFxn__C = ((CT__ti_sysbios_timers_timer64_Timer_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Object__count ti_sysbios_timers_timer64_Timer_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Object__heap ti_sysbios_timers_timer64_Timer_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Object__sizeof ti_sysbios_timers_timer64_Timer_Object__sizeof__C = sizeof(ti_sysbios_timers_timer64_Timer_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_Object__table ti_sysbios_timers_timer64_Timer_Object__table__C = ti_sysbios_timers_timer64_Timer_Object__table__V;

/* A_notAvailable__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_A_notAvailable ti_sysbios_timers_timer64_Timer_A_notAvailable__C = (((xdc_runtime_Assert_Id)1825) << 16 | 16);

/* E_invalidTimer__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_E_invalidTimer ti_sysbios_timers_timer64_Timer_E_invalidTimer__C = (((xdc_runtime_Error_Id)3484) << 16 | 0);

/* E_notAvailable__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_E_notAvailable ti_sysbios_timers_timer64_Timer_E_notAvailable__C = (((xdc_runtime_Error_Id)3520) << 16 | 0);

/* E_cannotSupport__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_E_cannotSupport ti_sysbios_timers_timer64_Timer_E_cannotSupport__C = (((xdc_runtime_Error_Id)3559) << 16 | 0);

/* anyMask__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_anyMask ti_sysbios_timers_timer64_Timer_anyMask__C = (xdc_Bits32)0xffffffff;

/* defaultHalf__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_defaultHalf ti_sysbios_timers_timer64_Timer_defaultHalf__C = ti_sysbios_timers_timer64_Timer_Half_LOWER;

/* timerSettings__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_timerSettings ti_sysbios_timers_timer64_Timer_timerSettings__C = ((CT__ti_sysbios_timers_timer64_Timer_timerSettings)ti_sysbios_timers_timer64_Timer_timerSettings__A);

/* startupNeeded__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_startupNeeded ti_sysbios_timers_timer64_Timer_startupNeeded__C = 1;

/* freqDivisor__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_freqDivisor ti_sysbios_timers_timer64_Timer_freqDivisor__C = (xdc_UInt)0x6;

/* numTimerDevices__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_numTimerDevices ti_sysbios_timers_timer64_Timer_numTimerDevices__C = (xdc_Int)0x20;

/* numLocalTimers__C */
__FAR__ const CT__ti_sysbios_timers_timer64_Timer_numLocalTimers ti_sysbios_timers_timer64_Timer_numLocalTimers__C = (xdc_Int)0x8;


/*
 * ======== ti.sysbios.timers.timer64.Timer_TimerSupportProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Assert INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Assert_Module__diagsEnabled xdc_runtime_Assert_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Assert_Module__diagsIncluded xdc_runtime_Assert_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Assert_Module__diagsMask xdc_runtime_Assert_Module__diagsMask__C = ((CT__xdc_runtime_Assert_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Assert_Module__gateObj xdc_runtime_Assert_Module__gateObj__C = ((CT__xdc_runtime_Assert_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Assert_Module__gatePrms xdc_runtime_Assert_Module__gatePrms__C = ((CT__xdc_runtime_Assert_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Assert_Module__id xdc_runtime_Assert_Module__id__C = (xdc_Bits16)0x8002;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerDefined xdc_runtime_Assert_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerObj xdc_runtime_Assert_Module__loggerObj__C = ((CT__xdc_runtime_Assert_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn0 xdc_runtime_Assert_Module__loggerFxn0__C = ((CT__xdc_runtime_Assert_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn1 xdc_runtime_Assert_Module__loggerFxn1__C = ((CT__xdc_runtime_Assert_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn2 xdc_runtime_Assert_Module__loggerFxn2__C = ((CT__xdc_runtime_Assert_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn4 xdc_runtime_Assert_Module__loggerFxn4__C = ((CT__xdc_runtime_Assert_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn8 xdc_runtime_Assert_Module__loggerFxn8__C = ((CT__xdc_runtime_Assert_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Assert_Module__startupDoneFxn xdc_runtime_Assert_Module__startupDoneFxn__C = ((CT__xdc_runtime_Assert_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Assert_Object__count xdc_runtime_Assert_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Assert_Object__heap xdc_runtime_Assert_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Assert_Object__sizeof xdc_runtime_Assert_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Assert_Object__table xdc_runtime_Assert_Object__table__C = 0;

/* E_assertFailed__C */
__FAR__ const CT__xdc_runtime_Assert_E_assertFailed xdc_runtime_Assert_E_assertFailed__C = (((xdc_runtime_Error_Id)2669) << 16 | 0);


/*
 * ======== xdc.runtime.Core INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Core_Module__diagsEnabled xdc_runtime_Core_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Core_Module__diagsIncluded xdc_runtime_Core_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Core_Module__diagsMask xdc_runtime_Core_Module__diagsMask__C = ((CT__xdc_runtime_Core_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Core_Module__gateObj xdc_runtime_Core_Module__gateObj__C = ((CT__xdc_runtime_Core_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Core_Module__gatePrms xdc_runtime_Core_Module__gatePrms__C = ((CT__xdc_runtime_Core_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Core_Module__id xdc_runtime_Core_Module__id__C = (xdc_Bits16)0x8003;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerDefined xdc_runtime_Core_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerObj xdc_runtime_Core_Module__loggerObj__C = ((CT__xdc_runtime_Core_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn0 xdc_runtime_Core_Module__loggerFxn0__C = ((CT__xdc_runtime_Core_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn1 xdc_runtime_Core_Module__loggerFxn1__C = ((CT__xdc_runtime_Core_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn2 xdc_runtime_Core_Module__loggerFxn2__C = ((CT__xdc_runtime_Core_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn4 xdc_runtime_Core_Module__loggerFxn4__C = ((CT__xdc_runtime_Core_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn8 xdc_runtime_Core_Module__loggerFxn8__C = ((CT__xdc_runtime_Core_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Core_Module__startupDoneFxn xdc_runtime_Core_Module__startupDoneFxn__C = ((CT__xdc_runtime_Core_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Core_Object__count xdc_runtime_Core_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Core_Object__heap xdc_runtime_Core_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Core_Object__sizeof xdc_runtime_Core_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Core_Object__table xdc_runtime_Core_Object__table__C = 0;

/* A_initializedParams__C */
__FAR__ const CT__xdc_runtime_Core_A_initializedParams xdc_runtime_Core_A_initializedParams__C = (((xdc_runtime_Assert_Id)1) << 16 | 16);


/*
 * ======== xdc.runtime.Defaults INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsEnabled xdc_runtime_Defaults_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsIncluded xdc_runtime_Defaults_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsMask xdc_runtime_Defaults_Module__diagsMask__C = ((CT__xdc_runtime_Defaults_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__gateObj xdc_runtime_Defaults_Module__gateObj__C = ((CT__xdc_runtime_Defaults_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__gatePrms xdc_runtime_Defaults_Module__gatePrms__C = ((CT__xdc_runtime_Defaults_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__id xdc_runtime_Defaults_Module__id__C = (xdc_Bits16)0x8004;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerDefined xdc_runtime_Defaults_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerObj xdc_runtime_Defaults_Module__loggerObj__C = ((CT__xdc_runtime_Defaults_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn0 xdc_runtime_Defaults_Module__loggerFxn0__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn1 xdc_runtime_Defaults_Module__loggerFxn1__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn2 xdc_runtime_Defaults_Module__loggerFxn2__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn4 xdc_runtime_Defaults_Module__loggerFxn4__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn8 xdc_runtime_Defaults_Module__loggerFxn8__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__startupDoneFxn xdc_runtime_Defaults_Module__startupDoneFxn__C = ((CT__xdc_runtime_Defaults_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Defaults_Object__count xdc_runtime_Defaults_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Defaults_Object__heap xdc_runtime_Defaults_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Defaults_Object__sizeof xdc_runtime_Defaults_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Defaults_Object__table xdc_runtime_Defaults_Object__table__C = 0;


/*
 * ======== xdc.runtime.Diags INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Diags_Module__diagsEnabled xdc_runtime_Diags_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Diags_Module__diagsIncluded xdc_runtime_Diags_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Diags_Module__diagsMask xdc_runtime_Diags_Module__diagsMask__C = ((CT__xdc_runtime_Diags_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Diags_Module__gateObj xdc_runtime_Diags_Module__gateObj__C = ((CT__xdc_runtime_Diags_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Diags_Module__gatePrms xdc_runtime_Diags_Module__gatePrms__C = ((CT__xdc_runtime_Diags_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Diags_Module__id xdc_runtime_Diags_Module__id__C = (xdc_Bits16)0x8005;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerDefined xdc_runtime_Diags_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerObj xdc_runtime_Diags_Module__loggerObj__C = ((CT__xdc_runtime_Diags_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn0 xdc_runtime_Diags_Module__loggerFxn0__C = ((CT__xdc_runtime_Diags_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn1 xdc_runtime_Diags_Module__loggerFxn1__C = ((CT__xdc_runtime_Diags_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn2 xdc_runtime_Diags_Module__loggerFxn2__C = ((CT__xdc_runtime_Diags_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn4 xdc_runtime_Diags_Module__loggerFxn4__C = ((CT__xdc_runtime_Diags_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn8 xdc_runtime_Diags_Module__loggerFxn8__C = ((CT__xdc_runtime_Diags_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Diags_Module__startupDoneFxn xdc_runtime_Diags_Module__startupDoneFxn__C = ((CT__xdc_runtime_Diags_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Diags_Object__count xdc_runtime_Diags_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Diags_Object__heap xdc_runtime_Diags_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Diags_Object__sizeof xdc_runtime_Diags_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Diags_Object__table xdc_runtime_Diags_Object__table__C = 0;

/* setMaskEnabled__C */
__FAR__ const CT__xdc_runtime_Diags_setMaskEnabled xdc_runtime_Diags_setMaskEnabled__C = 0;

/* dictBase__C */
__FAR__ const CT__xdc_runtime_Diags_dictBase xdc_runtime_Diags_dictBase__C = ((CT__xdc_runtime_Diags_dictBase)0);


/*
 * ======== xdc.runtime.Error INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V = {
    (xdc_UInt16)0x0,  /* count */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Error_Module__diagsEnabled xdc_runtime_Error_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Error_Module__diagsIncluded xdc_runtime_Error_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Error_Module__diagsMask xdc_runtime_Error_Module__diagsMask__C = ((CT__xdc_runtime_Error_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Error_Module__gateObj xdc_runtime_Error_Module__gateObj__C = ((CT__xdc_runtime_Error_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Error_Module__gatePrms xdc_runtime_Error_Module__gatePrms__C = ((CT__xdc_runtime_Error_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Error_Module__id xdc_runtime_Error_Module__id__C = (xdc_Bits16)0x8006;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerDefined xdc_runtime_Error_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerObj xdc_runtime_Error_Module__loggerObj__C = ((CT__xdc_runtime_Error_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn0 xdc_runtime_Error_Module__loggerFxn0__C = ((CT__xdc_runtime_Error_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn1 xdc_runtime_Error_Module__loggerFxn1__C = ((CT__xdc_runtime_Error_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn2 xdc_runtime_Error_Module__loggerFxn2__C = ((CT__xdc_runtime_Error_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn4 xdc_runtime_Error_Module__loggerFxn4__C = ((CT__xdc_runtime_Error_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn8 xdc_runtime_Error_Module__loggerFxn8__C = ((CT__xdc_runtime_Error_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Error_Module__startupDoneFxn xdc_runtime_Error_Module__startupDoneFxn__C = ((CT__xdc_runtime_Error_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Error_Object__count xdc_runtime_Error_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Error_Object__heap xdc_runtime_Error_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Error_Object__sizeof xdc_runtime_Error_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Error_Object__table xdc_runtime_Error_Object__table__C = 0;

/* E_generic__C */
__FAR__ const CT__xdc_runtime_Error_E_generic xdc_runtime_Error_E_generic__C = (((xdc_runtime_Error_Id)2691) << 16 | 0);

/* E_memory__C */
__FAR__ const CT__xdc_runtime_Error_E_memory xdc_runtime_Error_E_memory__C = (((xdc_runtime_Error_Id)2695) << 16 | 0);

/* E_msgCode__C */
__FAR__ const CT__xdc_runtime_Error_E_msgCode xdc_runtime_Error_E_msgCode__C = (((xdc_runtime_Error_Id)2729) << 16 | 0);

/* policy__C */
__FAR__ const CT__xdc_runtime_Error_policy xdc_runtime_Error_policy__C = xdc_runtime_Error_UNWIND;

/* raiseHook__C */
__FAR__ const CT__xdc_runtime_Error_raiseHook xdc_runtime_Error_raiseHook__C = ((CT__xdc_runtime_Error_raiseHook)((xdc_Fxn)ti_sysbios_BIOS_errorRaiseHook__I));

/* maxDepth__C */
__FAR__ const CT__xdc_runtime_Error_maxDepth xdc_runtime_Error_maxDepth__C = (xdc_UInt16)0x10;


/*
 * ======== xdc.runtime.Gate INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Gate_Module__diagsEnabled xdc_runtime_Gate_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Gate_Module__diagsIncluded xdc_runtime_Gate_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Gate_Module__diagsMask xdc_runtime_Gate_Module__diagsMask__C = ((CT__xdc_runtime_Gate_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Gate_Module__gateObj xdc_runtime_Gate_Module__gateObj__C = ((CT__xdc_runtime_Gate_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Gate_Module__gatePrms xdc_runtime_Gate_Module__gatePrms__C = ((CT__xdc_runtime_Gate_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Gate_Module__id xdc_runtime_Gate_Module__id__C = (xdc_Bits16)0x8007;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerDefined xdc_runtime_Gate_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerObj xdc_runtime_Gate_Module__loggerObj__C = ((CT__xdc_runtime_Gate_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn0 xdc_runtime_Gate_Module__loggerFxn0__C = ((CT__xdc_runtime_Gate_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn1 xdc_runtime_Gate_Module__loggerFxn1__C = ((CT__xdc_runtime_Gate_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn2 xdc_runtime_Gate_Module__loggerFxn2__C = ((CT__xdc_runtime_Gate_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn4 xdc_runtime_Gate_Module__loggerFxn4__C = ((CT__xdc_runtime_Gate_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn8 xdc_runtime_Gate_Module__loggerFxn8__C = ((CT__xdc_runtime_Gate_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Gate_Module__startupDoneFxn xdc_runtime_Gate_Module__startupDoneFxn__C = ((CT__xdc_runtime_Gate_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Gate_Object__count xdc_runtime_Gate_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Gate_Object__heap xdc_runtime_Gate_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Gate_Object__sizeof xdc_runtime_Gate_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Gate_Object__table xdc_runtime_Gate_Object__table__C = 0;


/*
 * ======== xdc.runtime.Log INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Log_Module__diagsEnabled xdc_runtime_Log_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Log_Module__diagsIncluded xdc_runtime_Log_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Log_Module__diagsMask xdc_runtime_Log_Module__diagsMask__C = ((CT__xdc_runtime_Log_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Log_Module__gateObj xdc_runtime_Log_Module__gateObj__C = ((CT__xdc_runtime_Log_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Log_Module__gatePrms xdc_runtime_Log_Module__gatePrms__C = ((CT__xdc_runtime_Log_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Log_Module__id xdc_runtime_Log_Module__id__C = (xdc_Bits16)0x8008;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerDefined xdc_runtime_Log_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerObj xdc_runtime_Log_Module__loggerObj__C = ((CT__xdc_runtime_Log_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn0 xdc_runtime_Log_Module__loggerFxn0__C = ((CT__xdc_runtime_Log_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn1 xdc_runtime_Log_Module__loggerFxn1__C = ((CT__xdc_runtime_Log_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn2 xdc_runtime_Log_Module__loggerFxn2__C = ((CT__xdc_runtime_Log_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn4 xdc_runtime_Log_Module__loggerFxn4__C = ((CT__xdc_runtime_Log_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn8 xdc_runtime_Log_Module__loggerFxn8__C = ((CT__xdc_runtime_Log_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Log_Module__startupDoneFxn xdc_runtime_Log_Module__startupDoneFxn__C = ((CT__xdc_runtime_Log_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Log_Object__count xdc_runtime_Log_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Log_Object__heap xdc_runtime_Log_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Log_Object__sizeof xdc_runtime_Log_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Log_Object__table xdc_runtime_Log_Object__table__C = 0;

/* L_construct__C */
__FAR__ const CT__xdc_runtime_Log_L_construct xdc_runtime_Log_L_construct__C = (((xdc_runtime_Log_Event)3701) << 16 | 4);

/* L_create__C */
__FAR__ const CT__xdc_runtime_Log_L_create xdc_runtime_Log_L_create__C = (((xdc_runtime_Log_Event)3725) << 16 | 4);

/* L_destruct__C */
__FAR__ const CT__xdc_runtime_Log_L_destruct xdc_runtime_Log_L_destruct__C = (((xdc_runtime_Log_Event)3746) << 16 | 4);

/* L_delete__C */
__FAR__ const CT__xdc_runtime_Log_L_delete xdc_runtime_Log_L_delete__C = (((xdc_runtime_Log_Event)3765) << 16 | 4);

/* L_error__C */
__FAR__ const CT__xdc_runtime_Log_L_error xdc_runtime_Log_L_error__C = (((xdc_runtime_Log_Event)3782) << 16 | 192);

/* L_warning__C */
__FAR__ const CT__xdc_runtime_Log_L_warning xdc_runtime_Log_L_warning__C = (((xdc_runtime_Log_Event)3796) << 16 | 224);

/* L_info__C */
__FAR__ const CT__xdc_runtime_Log_L_info xdc_runtime_Log_L_info__C = (((xdc_runtime_Log_Event)3812) << 16 | 16384);

/* L_start__C */
__FAR__ const CT__xdc_runtime_Log_L_start xdc_runtime_Log_L_start__C = (((xdc_runtime_Log_Event)3819) << 16 | 32768);

/* L_stop__C */
__FAR__ const CT__xdc_runtime_Log_L_stop xdc_runtime_Log_L_stop__C = (((xdc_runtime_Log_Event)3830) << 16 | 32768);

/* L_startInstance__C */
__FAR__ const CT__xdc_runtime_Log_L_startInstance xdc_runtime_Log_L_startInstance__C = (((xdc_runtime_Log_Event)3840) << 16 | 32768);

/* L_stopInstance__C */
__FAR__ const CT__xdc_runtime_Log_L_stopInstance xdc_runtime_Log_L_stopInstance__C = (((xdc_runtime_Log_Event)3859) << 16 | 32768);


/*
 * ======== xdc.runtime.Main INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Main_Module__diagsEnabled xdc_runtime_Main_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Main_Module__diagsIncluded xdc_runtime_Main_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Main_Module__diagsMask xdc_runtime_Main_Module__diagsMask__C = ((CT__xdc_runtime_Main_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Main_Module__gateObj xdc_runtime_Main_Module__gateObj__C = ((CT__xdc_runtime_Main_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Main_Module__gatePrms xdc_runtime_Main_Module__gatePrms__C = ((CT__xdc_runtime_Main_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Main_Module__id xdc_runtime_Main_Module__id__C = (xdc_Bits16)0x8009;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerDefined xdc_runtime_Main_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerObj xdc_runtime_Main_Module__loggerObj__C = ((CT__xdc_runtime_Main_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn0 xdc_runtime_Main_Module__loggerFxn0__C = ((CT__xdc_runtime_Main_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn1 xdc_runtime_Main_Module__loggerFxn1__C = ((CT__xdc_runtime_Main_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn2 xdc_runtime_Main_Module__loggerFxn2__C = ((CT__xdc_runtime_Main_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn4 xdc_runtime_Main_Module__loggerFxn4__C = ((CT__xdc_runtime_Main_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn8 xdc_runtime_Main_Module__loggerFxn8__C = ((CT__xdc_runtime_Main_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Main_Module__startupDoneFxn xdc_runtime_Main_Module__startupDoneFxn__C = ((CT__xdc_runtime_Main_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Main_Object__count xdc_runtime_Main_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Main_Object__heap xdc_runtime_Main_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Main_Object__sizeof xdc_runtime_Main_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Main_Object__table xdc_runtime_Main_Object__table__C = 0;


/*
 * ======== xdc.runtime.Main_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Memory INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V = {
    (xdc_SizeT)0x8,  /* maxDefaultTypeAlign */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Memory_Module__diagsEnabled xdc_runtime_Memory_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Memory_Module__diagsIncluded xdc_runtime_Memory_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Memory_Module__diagsMask xdc_runtime_Memory_Module__diagsMask__C = ((CT__xdc_runtime_Memory_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Memory_Module__gateObj xdc_runtime_Memory_Module__gateObj__C = ((CT__xdc_runtime_Memory_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Memory_Module__gatePrms xdc_runtime_Memory_Module__gatePrms__C = ((CT__xdc_runtime_Memory_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Memory_Module__id xdc_runtime_Memory_Module__id__C = (xdc_Bits16)0x800a;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerDefined xdc_runtime_Memory_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerObj xdc_runtime_Memory_Module__loggerObj__C = ((CT__xdc_runtime_Memory_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn0 xdc_runtime_Memory_Module__loggerFxn0__C = ((CT__xdc_runtime_Memory_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn1 xdc_runtime_Memory_Module__loggerFxn1__C = ((CT__xdc_runtime_Memory_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn2 xdc_runtime_Memory_Module__loggerFxn2__C = ((CT__xdc_runtime_Memory_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn4 xdc_runtime_Memory_Module__loggerFxn4__C = ((CT__xdc_runtime_Memory_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn8 xdc_runtime_Memory_Module__loggerFxn8__C = ((CT__xdc_runtime_Memory_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Memory_Module__startupDoneFxn xdc_runtime_Memory_Module__startupDoneFxn__C = ((CT__xdc_runtime_Memory_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Memory_Object__count xdc_runtime_Memory_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Memory_Object__heap xdc_runtime_Memory_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Memory_Object__sizeof xdc_runtime_Memory_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Memory_Object__table xdc_runtime_Memory_Object__table__C = 0;

/* defaultHeapInstance__C */
__FAR__ const CT__xdc_runtime_Memory_defaultHeapInstance xdc_runtime_Memory_defaultHeapInstance__C = (xdc_runtime_IHeap_Handle)&ti_sysbios_heaps_HeapMem_Object__table__V[0];


/*
 * ======== xdc.runtime.Memory_HeapProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Registry INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V = {
    ((xdc_runtime_Types_RegDesc*)0),  /* listHead */
    (xdc_Bits16)0x7fff,  /* curId */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Registry_Module__diagsEnabled xdc_runtime_Registry_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Registry_Module__diagsIncluded xdc_runtime_Registry_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Registry_Module__diagsMask xdc_runtime_Registry_Module__diagsMask__C = ((CT__xdc_runtime_Registry_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Registry_Module__gateObj xdc_runtime_Registry_Module__gateObj__C = ((CT__xdc_runtime_Registry_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Registry_Module__gatePrms xdc_runtime_Registry_Module__gatePrms__C = ((CT__xdc_runtime_Registry_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Registry_Module__id xdc_runtime_Registry_Module__id__C = (xdc_Bits16)0x800b;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerDefined xdc_runtime_Registry_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerObj xdc_runtime_Registry_Module__loggerObj__C = ((CT__xdc_runtime_Registry_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn0 xdc_runtime_Registry_Module__loggerFxn0__C = ((CT__xdc_runtime_Registry_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn1 xdc_runtime_Registry_Module__loggerFxn1__C = ((CT__xdc_runtime_Registry_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn2 xdc_runtime_Registry_Module__loggerFxn2__C = ((CT__xdc_runtime_Registry_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn4 xdc_runtime_Registry_Module__loggerFxn4__C = ((CT__xdc_runtime_Registry_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn8 xdc_runtime_Registry_Module__loggerFxn8__C = ((CT__xdc_runtime_Registry_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Registry_Module__startupDoneFxn xdc_runtime_Registry_Module__startupDoneFxn__C = ((CT__xdc_runtime_Registry_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Registry_Object__count xdc_runtime_Registry_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Registry_Object__heap xdc_runtime_Registry_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Registry_Object__sizeof xdc_runtime_Registry_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Registry_Object__table xdc_runtime_Registry_Object__table__C = 0;


/*
 * ======== xdc.runtime.Startup INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V = {
    ((xdc_Int*)0),  /* stateTab */
    0,  /* execFlag */
    0,  /* rtsDoneFlag */
};

/* --> xdc_runtime_Startup_firstFxns__A */
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[2] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_heaps_HeapMem_init__I)),  /* [0] */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_hal_Hwi_initStack)),  /* [1] */
};

/* --> xdc_runtime_Startup_lastFxns__A */
const __T1_xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__A[1] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)xdc_runtime_System_lastFxn__I)),  /* [0] */
};

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[14] = {
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_System_Module_startup__E)),  /* [0] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_SysMin_Module_startup__E)),  /* [1] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_Module_startup__E)),  /* [2] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_Exception_Module_startup__E)),  /* [3] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_Hwi_Module_startup__E)),  /* [4] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_TimestampProvider_Module_startup__E)),  /* [5] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c66_tci66xx_CpIntc_Module_startup__E)),  /* [6] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_hal_Hwi_Module_startup__E)),  /* [7] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_hal_Timer_Module_startup__E)),  /* [8] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Clock_Module_startup__E)),  /* [9] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Swi_Module_startup__E)),  /* [10] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Task_Module_startup__E)),  /* [11] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c66_Cache_Module_startup__E)),  /* [12] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_timers_timer64_Timer_Module_startup__E)),  /* [13] */
};

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[14] = {
    1,  /* [0] */
    1,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
    0,  /* [4] */
    1,  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    0,  /* [8] */
    0,  /* [9] */
    0,  /* [10] */
    0,  /* [11] */
    0,  /* [12] */
    0,  /* [13] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Startup_Module__diagsEnabled xdc_runtime_Startup_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Startup_Module__diagsIncluded xdc_runtime_Startup_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Startup_Module__diagsMask xdc_runtime_Startup_Module__diagsMask__C = ((CT__xdc_runtime_Startup_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Startup_Module__gateObj xdc_runtime_Startup_Module__gateObj__C = ((CT__xdc_runtime_Startup_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Startup_Module__gatePrms xdc_runtime_Startup_Module__gatePrms__C = ((CT__xdc_runtime_Startup_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Startup_Module__id xdc_runtime_Startup_Module__id__C = (xdc_Bits16)0x800c;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerDefined xdc_runtime_Startup_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerObj xdc_runtime_Startup_Module__loggerObj__C = ((CT__xdc_runtime_Startup_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn0 xdc_runtime_Startup_Module__loggerFxn0__C = ((CT__xdc_runtime_Startup_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn1 xdc_runtime_Startup_Module__loggerFxn1__C = ((CT__xdc_runtime_Startup_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn2 xdc_runtime_Startup_Module__loggerFxn2__C = ((CT__xdc_runtime_Startup_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn4 xdc_runtime_Startup_Module__loggerFxn4__C = ((CT__xdc_runtime_Startup_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn8 xdc_runtime_Startup_Module__loggerFxn8__C = ((CT__xdc_runtime_Startup_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Startup_Module__startupDoneFxn xdc_runtime_Startup_Module__startupDoneFxn__C = ((CT__xdc_runtime_Startup_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Startup_Object__count xdc_runtime_Startup_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Startup_Object__heap xdc_runtime_Startup_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Startup_Object__sizeof xdc_runtime_Startup_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Startup_Object__table xdc_runtime_Startup_Object__table__C = 0;

/* maxPasses__C */
__FAR__ const CT__xdc_runtime_Startup_maxPasses xdc_runtime_Startup_maxPasses__C = (xdc_Int)0x20;

/* firstFxns__C */
__FAR__ const CT__xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__C = {2, ((__T1_xdc_runtime_Startup_firstFxns*)xdc_runtime_Startup_firstFxns__A)};

/* lastFxns__C */
__FAR__ const CT__xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__C = {1, ((__T1_xdc_runtime_Startup_lastFxns*)xdc_runtime_Startup_lastFxns__A)};

/* startModsFxn__C */
__FAR__ const CT__xdc_runtime_Startup_startModsFxn xdc_runtime_Startup_startModsFxn__C = ((CT__xdc_runtime_Startup_startModsFxn)((xdc_Fxn)xdc_runtime_Startup_startMods__I));

/* execImpl__C */
__FAR__ const CT__xdc_runtime_Startup_execImpl xdc_runtime_Startup_execImpl__C = ((CT__xdc_runtime_Startup_execImpl)((xdc_Fxn)xdc_runtime_Startup_exec__I));

/* sfxnTab__C */
__FAR__ const CT__xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__C = ((CT__xdc_runtime_Startup_sfxnTab)xdc_runtime_Startup_sfxnTab__A);

/* sfxnRts__C */
__FAR__ const CT__xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__C = ((CT__xdc_runtime_Startup_sfxnRts)xdc_runtime_Startup_sfxnRts__A);


/*
 * ======== xdc.runtime.SysMin INITIALIZERS ========
 */

/* --> xdc_runtime_SysMin_Module_State_0_outbuf__A */
__T1_xdc_runtime_SysMin_Module_State__outbuf xdc_runtime_SysMin_Module_State_0_outbuf__A[1024];

/* Module__state__V */
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V = {
    ((void*)xdc_runtime_SysMin_Module_State_0_outbuf__A),  /* outbuf */
    (xdc_UInt)0x0,  /* outidx */
    0,  /* wrapped */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsEnabled xdc_runtime_SysMin_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsIncluded xdc_runtime_SysMin_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsMask xdc_runtime_SysMin_Module__diagsMask__C = ((CT__xdc_runtime_SysMin_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__gateObj xdc_runtime_SysMin_Module__gateObj__C = ((CT__xdc_runtime_SysMin_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__gatePrms xdc_runtime_SysMin_Module__gatePrms__C = ((CT__xdc_runtime_SysMin_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__id xdc_runtime_SysMin_Module__id__C = (xdc_Bits16)0x800e;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerDefined xdc_runtime_SysMin_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerObj xdc_runtime_SysMin_Module__loggerObj__C = ((CT__xdc_runtime_SysMin_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn0 xdc_runtime_SysMin_Module__loggerFxn0__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn1 xdc_runtime_SysMin_Module__loggerFxn1__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn2 xdc_runtime_SysMin_Module__loggerFxn2__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn4 xdc_runtime_SysMin_Module__loggerFxn4__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn8 xdc_runtime_SysMin_Module__loggerFxn8__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__startupDoneFxn xdc_runtime_SysMin_Module__startupDoneFxn__C = ((CT__xdc_runtime_SysMin_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_SysMin_Object__count xdc_runtime_SysMin_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_SysMin_Object__heap xdc_runtime_SysMin_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_SysMin_Object__sizeof xdc_runtime_SysMin_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_SysMin_Object__table xdc_runtime_SysMin_Object__table__C = 0;

/* bufSize__C */
__FAR__ const CT__xdc_runtime_SysMin_bufSize xdc_runtime_SysMin_bufSize__C = (xdc_SizeT)0x400;

/* flushAtExit__C */
__FAR__ const CT__xdc_runtime_SysMin_flushAtExit xdc_runtime_SysMin_flushAtExit__C = 1;

/* outputFxn__C */
__FAR__ const CT__xdc_runtime_SysMin_outputFxn xdc_runtime_SysMin_outputFxn__C = ((CT__xdc_runtime_SysMin_outputFxn)0);

/* outputFunc__C */
__FAR__ const CT__xdc_runtime_SysMin_outputFunc xdc_runtime_SysMin_outputFunc__C = ((CT__xdc_runtime_SysMin_outputFunc)((xdc_Fxn)xdc_runtime_SysMin_output__I));


/*
 * ======== xdc.runtime.System INITIALIZERS ========
 */

/* --> xdc_runtime_System_Module_State_0_atexitHandlers__A */
__T1_xdc_runtime_System_Module_State__atexitHandlers xdc_runtime_System_Module_State_0_atexitHandlers__A[8] = {
    ((xdc_Void(*)(xdc_Int))0),  /* [0] */
    ((xdc_Void(*)(xdc_Int))0),  /* [1] */
    ((xdc_Void(*)(xdc_Int))0),  /* [2] */
    ((xdc_Void(*)(xdc_Int))0),  /* [3] */
    ((xdc_Void(*)(xdc_Int))0),  /* [4] */
    ((xdc_Void(*)(xdc_Int))0),  /* [5] */
    ((xdc_Void(*)(xdc_Int))0),  /* [6] */
    ((xdc_Void(*)(xdc_Int))0),  /* [7] */
};

/* Module__state__V */
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V = {
    ((void*)xdc_runtime_System_Module_State_0_atexitHandlers__A),  /* atexitHandlers */
    (xdc_Int)0x0,  /* numAtexitHandlers */
    (xdc_Int)0xcafe,  /* exitStatus */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_System_Module__diagsEnabled xdc_runtime_System_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_System_Module__diagsIncluded xdc_runtime_System_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_System_Module__diagsMask xdc_runtime_System_Module__diagsMask__C = ((CT__xdc_runtime_System_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_System_Module__gateObj xdc_runtime_System_Module__gateObj__C = ((CT__xdc_runtime_System_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_System_Module__gatePrms xdc_runtime_System_Module__gatePrms__C = ((CT__xdc_runtime_System_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_System_Module__id xdc_runtime_System_Module__id__C = (xdc_Bits16)0x800d;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerDefined xdc_runtime_System_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerObj xdc_runtime_System_Module__loggerObj__C = ((CT__xdc_runtime_System_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn0 xdc_runtime_System_Module__loggerFxn0__C = ((CT__xdc_runtime_System_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn1 xdc_runtime_System_Module__loggerFxn1__C = ((CT__xdc_runtime_System_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn2 xdc_runtime_System_Module__loggerFxn2__C = ((CT__xdc_runtime_System_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn4 xdc_runtime_System_Module__loggerFxn4__C = ((CT__xdc_runtime_System_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn8 xdc_runtime_System_Module__loggerFxn8__C = ((CT__xdc_runtime_System_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_System_Module__startupDoneFxn xdc_runtime_System_Module__startupDoneFxn__C = ((CT__xdc_runtime_System_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_System_Object__count xdc_runtime_System_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_System_Object__heap xdc_runtime_System_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_System_Object__sizeof xdc_runtime_System_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_System_Object__table xdc_runtime_System_Object__table__C = 0;

/* A_cannotFitIntoArg__C */
__FAR__ const CT__xdc_runtime_System_A_cannotFitIntoArg xdc_runtime_System_A_cannotFitIntoArg__C = (((xdc_runtime_Assert_Id)307) << 16 | 16);

/* maxAtexitHandlers__C */
__FAR__ const CT__xdc_runtime_System_maxAtexitHandlers xdc_runtime_System_maxAtexitHandlers__C = (xdc_Int)0x8;

/* extendFxn__C */
__FAR__ const CT__xdc_runtime_System_extendFxn xdc_runtime_System_extendFxn__C = ((CT__xdc_runtime_System_extendFxn)((xdc_Fxn)xdc_runtime_System_printfExtend__I));


/*
 * ======== xdc.runtime.System_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.System_SupportProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Text INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V = {
    ((xdc_Ptr)((void*)&xdc_runtime_Text_charTab__A[0])),  /* charBase */
    ((xdc_Ptr)((void*)&xdc_runtime_Text_nodeTab__A[0])),  /* nodeBase */
};

/* --> xdc_runtime_Text_charTab__A */
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[5201] = {
    (xdc_Char)0x0,  /* [0] */
    (xdc_Char)0x41,  /* [1] */
    (xdc_Char)0x5f,  /* [2] */
    (xdc_Char)0x69,  /* [3] */
    (xdc_Char)0x6e,  /* [4] */
    (xdc_Char)0x69,  /* [5] */
    (xdc_Char)0x74,  /* [6] */
    (xdc_Char)0x69,  /* [7] */
    (xdc_Char)0x61,  /* [8] */
    (xdc_Char)0x6c,  /* [9] */
    (xdc_Char)0x69,  /* [10] */
    (xdc_Char)0x7a,  /* [11] */
    (xdc_Char)0x65,  /* [12] */
    (xdc_Char)0x64,  /* [13] */
    (xdc_Char)0x50,  /* [14] */
    (xdc_Char)0x61,  /* [15] */
    (xdc_Char)0x72,  /* [16] */
    (xdc_Char)0x61,  /* [17] */
    (xdc_Char)0x6d,  /* [18] */
    (xdc_Char)0x73,  /* [19] */
    (xdc_Char)0x3a,  /* [20] */
    (xdc_Char)0x20,  /* [21] */
    (xdc_Char)0x75,  /* [22] */
    (xdc_Char)0x6e,  /* [23] */
    (xdc_Char)0x69,  /* [24] */
    (xdc_Char)0x6e,  /* [25] */
    (xdc_Char)0x69,  /* [26] */
    (xdc_Char)0x74,  /* [27] */
    (xdc_Char)0x69,  /* [28] */
    (xdc_Char)0x61,  /* [29] */
    (xdc_Char)0x6c,  /* [30] */
    (xdc_Char)0x69,  /* [31] */
    (xdc_Char)0x7a,  /* [32] */
    (xdc_Char)0x65,  /* [33] */
    (xdc_Char)0x64,  /* [34] */
    (xdc_Char)0x20,  /* [35] */
    (xdc_Char)0x50,  /* [36] */
    (xdc_Char)0x61,  /* [37] */
    (xdc_Char)0x72,  /* [38] */
    (xdc_Char)0x61,  /* [39] */
    (xdc_Char)0x6d,  /* [40] */
    (xdc_Char)0x73,  /* [41] */
    (xdc_Char)0x20,  /* [42] */
    (xdc_Char)0x73,  /* [43] */
    (xdc_Char)0x74,  /* [44] */
    (xdc_Char)0x72,  /* [45] */
    (xdc_Char)0x75,  /* [46] */
    (xdc_Char)0x63,  /* [47] */
    (xdc_Char)0x74,  /* [48] */
    (xdc_Char)0x0,  /* [49] */
    (xdc_Char)0x48,  /* [50] */
    (xdc_Char)0x65,  /* [51] */
    (xdc_Char)0x61,  /* [52] */
    (xdc_Char)0x70,  /* [53] */
    (xdc_Char)0x4d,  /* [54] */
    (xdc_Char)0x69,  /* [55] */
    (xdc_Char)0x6e,  /* [56] */
    (xdc_Char)0x5f,  /* [57] */
    (xdc_Char)0x63,  /* [58] */
    (xdc_Char)0x72,  /* [59] */
    (xdc_Char)0x65,  /* [60] */
    (xdc_Char)0x61,  /* [61] */
    (xdc_Char)0x74,  /* [62] */
    (xdc_Char)0x65,  /* [63] */
    (xdc_Char)0x20,  /* [64] */
    (xdc_Char)0x63,  /* [65] */
    (xdc_Char)0x61,  /* [66] */
    (xdc_Char)0x6e,  /* [67] */
    (xdc_Char)0x6e,  /* [68] */
    (xdc_Char)0x6f,  /* [69] */
    (xdc_Char)0x74,  /* [70] */
    (xdc_Char)0x20,  /* [71] */
    (xdc_Char)0x68,  /* [72] */
    (xdc_Char)0x61,  /* [73] */
    (xdc_Char)0x76,  /* [74] */
    (xdc_Char)0x65,  /* [75] */
    (xdc_Char)0x20,  /* [76] */
    (xdc_Char)0x61,  /* [77] */
    (xdc_Char)0x20,  /* [78] */
    (xdc_Char)0x7a,  /* [79] */
    (xdc_Char)0x65,  /* [80] */
    (xdc_Char)0x72,  /* [81] */
    (xdc_Char)0x6f,  /* [82] */
    (xdc_Char)0x20,  /* [83] */
    (xdc_Char)0x73,  /* [84] */
    (xdc_Char)0x69,  /* [85] */
    (xdc_Char)0x7a,  /* [86] */
    (xdc_Char)0x65,  /* [87] */
    (xdc_Char)0x20,  /* [88] */
    (xdc_Char)0x76,  /* [89] */
    (xdc_Char)0x61,  /* [90] */
    (xdc_Char)0x6c,  /* [91] */
    (xdc_Char)0x75,  /* [92] */
    (xdc_Char)0x65,  /* [93] */
    (xdc_Char)0x0,  /* [94] */
    (xdc_Char)0x48,  /* [95] */
    (xdc_Char)0x65,  /* [96] */
    (xdc_Char)0x61,  /* [97] */
    (xdc_Char)0x70,  /* [98] */
    (xdc_Char)0x53,  /* [99] */
    (xdc_Char)0x74,  /* [100] */
    (xdc_Char)0x64,  /* [101] */
    (xdc_Char)0x5f,  /* [102] */
    (xdc_Char)0x63,  /* [103] */
    (xdc_Char)0x72,  /* [104] */
    (xdc_Char)0x65,  /* [105] */
    (xdc_Char)0x61,  /* [106] */
    (xdc_Char)0x74,  /* [107] */
    (xdc_Char)0x65,  /* [108] */
    (xdc_Char)0x20,  /* [109] */
    (xdc_Char)0x63,  /* [110] */
    (xdc_Char)0x61,  /* [111] */
    (xdc_Char)0x6e,  /* [112] */
    (xdc_Char)0x6e,  /* [113] */
    (xdc_Char)0x6f,  /* [114] */
    (xdc_Char)0x74,  /* [115] */
    (xdc_Char)0x20,  /* [116] */
    (xdc_Char)0x68,  /* [117] */
    (xdc_Char)0x61,  /* [118] */
    (xdc_Char)0x76,  /* [119] */
    (xdc_Char)0x65,  /* [120] */
    (xdc_Char)0x20,  /* [121] */
    (xdc_Char)0x61,  /* [122] */
    (xdc_Char)0x20,  /* [123] */
    (xdc_Char)0x7a,  /* [124] */
    (xdc_Char)0x65,  /* [125] */
    (xdc_Char)0x72,  /* [126] */
    (xdc_Char)0x6f,  /* [127] */
    (xdc_Char)0x20,  /* [128] */
    (xdc_Char)0x73,  /* [129] */
    (xdc_Char)0x69,  /* [130] */
    (xdc_Char)0x7a,  /* [131] */
    (xdc_Char)0x65,  /* [132] */
    (xdc_Char)0x20,  /* [133] */
    (xdc_Char)0x76,  /* [134] */
    (xdc_Char)0x61,  /* [135] */
    (xdc_Char)0x6c,  /* [136] */
    (xdc_Char)0x75,  /* [137] */
    (xdc_Char)0x65,  /* [138] */
    (xdc_Char)0x0,  /* [139] */
    (xdc_Char)0x48,  /* [140] */
    (xdc_Char)0x65,  /* [141] */
    (xdc_Char)0x61,  /* [142] */
    (xdc_Char)0x70,  /* [143] */
    (xdc_Char)0x53,  /* [144] */
    (xdc_Char)0x74,  /* [145] */
    (xdc_Char)0x64,  /* [146] */
    (xdc_Char)0x20,  /* [147] */
    (xdc_Char)0x69,  /* [148] */
    (xdc_Char)0x6e,  /* [149] */
    (xdc_Char)0x73,  /* [150] */
    (xdc_Char)0x74,  /* [151] */
    (xdc_Char)0x61,  /* [152] */
    (xdc_Char)0x6e,  /* [153] */
    (xdc_Char)0x63,  /* [154] */
    (xdc_Char)0x65,  /* [155] */
    (xdc_Char)0x20,  /* [156] */
    (xdc_Char)0x74,  /* [157] */
    (xdc_Char)0x6f,  /* [158] */
    (xdc_Char)0x74,  /* [159] */
    (xdc_Char)0x61,  /* [160] */
    (xdc_Char)0x6c,  /* [161] */
    (xdc_Char)0x46,  /* [162] */
    (xdc_Char)0x72,  /* [163] */
    (xdc_Char)0x65,  /* [164] */
    (xdc_Char)0x65,  /* [165] */
    (xdc_Char)0x53,  /* [166] */
    (xdc_Char)0x69,  /* [167] */
    (xdc_Char)0x7a,  /* [168] */
    (xdc_Char)0x65,  /* [169] */
    (xdc_Char)0x20,  /* [170] */
    (xdc_Char)0x69,  /* [171] */
    (xdc_Char)0x73,  /* [172] */
    (xdc_Char)0x20,  /* [173] */
    (xdc_Char)0x67,  /* [174] */
    (xdc_Char)0x72,  /* [175] */
    (xdc_Char)0x65,  /* [176] */
    (xdc_Char)0x61,  /* [177] */
    (xdc_Char)0x74,  /* [178] */
    (xdc_Char)0x65,  /* [179] */
    (xdc_Char)0x72,  /* [180] */
    (xdc_Char)0x20,  /* [181] */
    (xdc_Char)0x74,  /* [182] */
    (xdc_Char)0x68,  /* [183] */
    (xdc_Char)0x61,  /* [184] */
    (xdc_Char)0x6e,  /* [185] */
    (xdc_Char)0x20,  /* [186] */
    (xdc_Char)0x73,  /* [187] */
    (xdc_Char)0x74,  /* [188] */
    (xdc_Char)0x61,  /* [189] */
    (xdc_Char)0x72,  /* [190] */
    (xdc_Char)0x74,  /* [191] */
    (xdc_Char)0x69,  /* [192] */
    (xdc_Char)0x6e,  /* [193] */
    (xdc_Char)0x67,  /* [194] */
    (xdc_Char)0x20,  /* [195] */
    (xdc_Char)0x73,  /* [196] */
    (xdc_Char)0x69,  /* [197] */
    (xdc_Char)0x7a,  /* [198] */
    (xdc_Char)0x65,  /* [199] */
    (xdc_Char)0x0,  /* [200] */
    (xdc_Char)0x48,  /* [201] */
    (xdc_Char)0x65,  /* [202] */
    (xdc_Char)0x61,  /* [203] */
    (xdc_Char)0x70,  /* [204] */
    (xdc_Char)0x53,  /* [205] */
    (xdc_Char)0x74,  /* [206] */
    (xdc_Char)0x64,  /* [207] */
    (xdc_Char)0x5f,  /* [208] */
    (xdc_Char)0x61,  /* [209] */
    (xdc_Char)0x6c,  /* [210] */
    (xdc_Char)0x6c,  /* [211] */
    (xdc_Char)0x6f,  /* [212] */
    (xdc_Char)0x63,  /* [213] */
    (xdc_Char)0x20,  /* [214] */
    (xdc_Char)0x2d,  /* [215] */
    (xdc_Char)0x20,  /* [216] */
    (xdc_Char)0x72,  /* [217] */
    (xdc_Char)0x65,  /* [218] */
    (xdc_Char)0x71,  /* [219] */
    (xdc_Char)0x75,  /* [220] */
    (xdc_Char)0x65,  /* [221] */
    (xdc_Char)0x73,  /* [222] */
    (xdc_Char)0x74,  /* [223] */
    (xdc_Char)0x65,  /* [224] */
    (xdc_Char)0x64,  /* [225] */
    (xdc_Char)0x20,  /* [226] */
    (xdc_Char)0x61,  /* [227] */
    (xdc_Char)0x6c,  /* [228] */
    (xdc_Char)0x69,  /* [229] */
    (xdc_Char)0x67,  /* [230] */
    (xdc_Char)0x6e,  /* [231] */
    (xdc_Char)0x6d,  /* [232] */
    (xdc_Char)0x65,  /* [233] */
    (xdc_Char)0x6e,  /* [234] */
    (xdc_Char)0x74,  /* [235] */
    (xdc_Char)0x20,  /* [236] */
    (xdc_Char)0x69,  /* [237] */
    (xdc_Char)0x73,  /* [238] */
    (xdc_Char)0x20,  /* [239] */
    (xdc_Char)0x67,  /* [240] */
    (xdc_Char)0x72,  /* [241] */
    (xdc_Char)0x65,  /* [242] */
    (xdc_Char)0x61,  /* [243] */
    (xdc_Char)0x74,  /* [244] */
    (xdc_Char)0x65,  /* [245] */
    (xdc_Char)0x72,  /* [246] */
    (xdc_Char)0x20,  /* [247] */
    (xdc_Char)0x74,  /* [248] */
    (xdc_Char)0x68,  /* [249] */
    (xdc_Char)0x61,  /* [250] */
    (xdc_Char)0x6e,  /* [251] */
    (xdc_Char)0x20,  /* [252] */
    (xdc_Char)0x61,  /* [253] */
    (xdc_Char)0x6c,  /* [254] */
    (xdc_Char)0x6c,  /* [255] */
    (xdc_Char)0x6f,  /* [256] */
    (xdc_Char)0x77,  /* [257] */
    (xdc_Char)0x65,  /* [258] */
    (xdc_Char)0x64,  /* [259] */
    (xdc_Char)0x0,  /* [260] */
    (xdc_Char)0x41,  /* [261] */
    (xdc_Char)0x5f,  /* [262] */
    (xdc_Char)0x69,  /* [263] */
    (xdc_Char)0x6e,  /* [264] */
    (xdc_Char)0x76,  /* [265] */
    (xdc_Char)0x61,  /* [266] */
    (xdc_Char)0x6c,  /* [267] */
    (xdc_Char)0x69,  /* [268] */
    (xdc_Char)0x64,  /* [269] */
    (xdc_Char)0x4c,  /* [270] */
    (xdc_Char)0x6f,  /* [271] */
    (xdc_Char)0x67,  /* [272] */
    (xdc_Char)0x67,  /* [273] */
    (xdc_Char)0x65,  /* [274] */
    (xdc_Char)0x72,  /* [275] */
    (xdc_Char)0x3a,  /* [276] */
    (xdc_Char)0x20,  /* [277] */
    (xdc_Char)0x54,  /* [278] */
    (xdc_Char)0x68,  /* [279] */
    (xdc_Char)0x65,  /* [280] */
    (xdc_Char)0x20,  /* [281] */
    (xdc_Char)0x6c,  /* [282] */
    (xdc_Char)0x6f,  /* [283] */
    (xdc_Char)0x67,  /* [284] */
    (xdc_Char)0x67,  /* [285] */
    (xdc_Char)0x65,  /* [286] */
    (xdc_Char)0x72,  /* [287] */
    (xdc_Char)0x20,  /* [288] */
    (xdc_Char)0x69,  /* [289] */
    (xdc_Char)0x64,  /* [290] */
    (xdc_Char)0x20,  /* [291] */
    (xdc_Char)0x25,  /* [292] */
    (xdc_Char)0x64,  /* [293] */
    (xdc_Char)0x20,  /* [294] */
    (xdc_Char)0x69,  /* [295] */
    (xdc_Char)0x73,  /* [296] */
    (xdc_Char)0x20,  /* [297] */
    (xdc_Char)0x69,  /* [298] */
    (xdc_Char)0x6e,  /* [299] */
    (xdc_Char)0x76,  /* [300] */
    (xdc_Char)0x61,  /* [301] */
    (xdc_Char)0x6c,  /* [302] */
    (xdc_Char)0x69,  /* [303] */
    (xdc_Char)0x64,  /* [304] */
    (xdc_Char)0x2e,  /* [305] */
    (xdc_Char)0x0,  /* [306] */
    (xdc_Char)0x41,  /* [307] */
    (xdc_Char)0x5f,  /* [308] */
    (xdc_Char)0x63,  /* [309] */
    (xdc_Char)0x61,  /* [310] */
    (xdc_Char)0x6e,  /* [311] */
    (xdc_Char)0x6e,  /* [312] */
    (xdc_Char)0x6f,  /* [313] */
    (xdc_Char)0x74,  /* [314] */
    (xdc_Char)0x46,  /* [315] */
    (xdc_Char)0x69,  /* [316] */
    (xdc_Char)0x74,  /* [317] */
    (xdc_Char)0x49,  /* [318] */
    (xdc_Char)0x6e,  /* [319] */
    (xdc_Char)0x74,  /* [320] */
    (xdc_Char)0x6f,  /* [321] */
    (xdc_Char)0x41,  /* [322] */
    (xdc_Char)0x72,  /* [323] */
    (xdc_Char)0x67,  /* [324] */
    (xdc_Char)0x3a,  /* [325] */
    (xdc_Char)0x20,  /* [326] */
    (xdc_Char)0x73,  /* [327] */
    (xdc_Char)0x69,  /* [328] */
    (xdc_Char)0x7a,  /* [329] */
    (xdc_Char)0x65,  /* [330] */
    (xdc_Char)0x6f,  /* [331] */
    (xdc_Char)0x66,  /* [332] */
    (xdc_Char)0x28,  /* [333] */
    (xdc_Char)0x46,  /* [334] */
    (xdc_Char)0x6c,  /* [335] */
    (xdc_Char)0x6f,  /* [336] */
    (xdc_Char)0x61,  /* [337] */
    (xdc_Char)0x74,  /* [338] */
    (xdc_Char)0x29,  /* [339] */
    (xdc_Char)0x20,  /* [340] */
    (xdc_Char)0x3e,  /* [341] */
    (xdc_Char)0x20,  /* [342] */
    (xdc_Char)0x73,  /* [343] */
    (xdc_Char)0x69,  /* [344] */
    (xdc_Char)0x7a,  /* [345] */
    (xdc_Char)0x65,  /* [346] */
    (xdc_Char)0x6f,  /* [347] */
    (xdc_Char)0x66,  /* [348] */
    (xdc_Char)0x28,  /* [349] */
    (xdc_Char)0x41,  /* [350] */
    (xdc_Char)0x72,  /* [351] */
    (xdc_Char)0x67,  /* [352] */
    (xdc_Char)0x29,  /* [353] */
    (xdc_Char)0x0,  /* [354] */
    (xdc_Char)0x41,  /* [355] */
    (xdc_Char)0x5f,  /* [356] */
    (xdc_Char)0x63,  /* [357] */
    (xdc_Char)0x6c,  /* [358] */
    (xdc_Char)0x6f,  /* [359] */
    (xdc_Char)0x63,  /* [360] */
    (xdc_Char)0x6b,  /* [361] */
    (xdc_Char)0x44,  /* [362] */
    (xdc_Char)0x69,  /* [363] */
    (xdc_Char)0x73,  /* [364] */
    (xdc_Char)0x61,  /* [365] */
    (xdc_Char)0x62,  /* [366] */
    (xdc_Char)0x6c,  /* [367] */
    (xdc_Char)0x65,  /* [368] */
    (xdc_Char)0x64,  /* [369] */
    (xdc_Char)0x3a,  /* [370] */
    (xdc_Char)0x20,  /* [371] */
    (xdc_Char)0x43,  /* [372] */
    (xdc_Char)0x61,  /* [373] */
    (xdc_Char)0x6e,  /* [374] */
    (xdc_Char)0x6e,  /* [375] */
    (xdc_Char)0x6f,  /* [376] */
    (xdc_Char)0x74,  /* [377] */
    (xdc_Char)0x20,  /* [378] */
    (xdc_Char)0x63,  /* [379] */
    (xdc_Char)0x72,  /* [380] */
    (xdc_Char)0x65,  /* [381] */
    (xdc_Char)0x61,  /* [382] */
    (xdc_Char)0x74,  /* [383] */
    (xdc_Char)0x65,  /* [384] */
    (xdc_Char)0x20,  /* [385] */
    (xdc_Char)0x61,  /* [386] */
    (xdc_Char)0x20,  /* [387] */
    (xdc_Char)0x63,  /* [388] */
    (xdc_Char)0x6c,  /* [389] */
    (xdc_Char)0x6f,  /* [390] */
    (xdc_Char)0x63,  /* [391] */
    (xdc_Char)0x6b,  /* [392] */
    (xdc_Char)0x20,  /* [393] */
    (xdc_Char)0x69,  /* [394] */
    (xdc_Char)0x6e,  /* [395] */
    (xdc_Char)0x73,  /* [396] */
    (xdc_Char)0x74,  /* [397] */
    (xdc_Char)0x61,  /* [398] */
    (xdc_Char)0x6e,  /* [399] */
    (xdc_Char)0x63,  /* [400] */
    (xdc_Char)0x65,  /* [401] */
    (xdc_Char)0x20,  /* [402] */
    (xdc_Char)0x77,  /* [403] */
    (xdc_Char)0x68,  /* [404] */
    (xdc_Char)0x65,  /* [405] */
    (xdc_Char)0x6e,  /* [406] */
    (xdc_Char)0x20,  /* [407] */
    (xdc_Char)0x42,  /* [408] */
    (xdc_Char)0x49,  /* [409] */
    (xdc_Char)0x4f,  /* [410] */
    (xdc_Char)0x53,  /* [411] */
    (xdc_Char)0x2e,  /* [412] */
    (xdc_Char)0x63,  /* [413] */
    (xdc_Char)0x6c,  /* [414] */
    (xdc_Char)0x6f,  /* [415] */
    (xdc_Char)0x63,  /* [416] */
    (xdc_Char)0x6b,  /* [417] */
    (xdc_Char)0x45,  /* [418] */
    (xdc_Char)0x6e,  /* [419] */
    (xdc_Char)0x61,  /* [420] */
    (xdc_Char)0x62,  /* [421] */
    (xdc_Char)0x6c,  /* [422] */
    (xdc_Char)0x65,  /* [423] */
    (xdc_Char)0x64,  /* [424] */
    (xdc_Char)0x20,  /* [425] */
    (xdc_Char)0x69,  /* [426] */
    (xdc_Char)0x73,  /* [427] */
    (xdc_Char)0x20,  /* [428] */
    (xdc_Char)0x66,  /* [429] */
    (xdc_Char)0x61,  /* [430] */
    (xdc_Char)0x6c,  /* [431] */
    (xdc_Char)0x73,  /* [432] */
    (xdc_Char)0x65,  /* [433] */
    (xdc_Char)0x2e,  /* [434] */
    (xdc_Char)0x0,  /* [435] */
    (xdc_Char)0x41,  /* [436] */
    (xdc_Char)0x5f,  /* [437] */
    (xdc_Char)0x62,  /* [438] */
    (xdc_Char)0x61,  /* [439] */
    (xdc_Char)0x64,  /* [440] */
    (xdc_Char)0x54,  /* [441] */
    (xdc_Char)0x68,  /* [442] */
    (xdc_Char)0x72,  /* [443] */
    (xdc_Char)0x65,  /* [444] */
    (xdc_Char)0x61,  /* [445] */
    (xdc_Char)0x64,  /* [446] */
    (xdc_Char)0x54,  /* [447] */
    (xdc_Char)0x79,  /* [448] */
    (xdc_Char)0x70,  /* [449] */
    (xdc_Char)0x65,  /* [450] */
    (xdc_Char)0x3a,  /* [451] */
    (xdc_Char)0x20,  /* [452] */
    (xdc_Char)0x43,  /* [453] */
    (xdc_Char)0x61,  /* [454] */
    (xdc_Char)0x6e,  /* [455] */
    (xdc_Char)0x6e,  /* [456] */
    (xdc_Char)0x6f,  /* [457] */
    (xdc_Char)0x74,  /* [458] */
    (xdc_Char)0x20,  /* [459] */
    (xdc_Char)0x63,  /* [460] */
    (xdc_Char)0x72,  /* [461] */
    (xdc_Char)0x65,  /* [462] */
    (xdc_Char)0x61,  /* [463] */
    (xdc_Char)0x74,  /* [464] */
    (xdc_Char)0x65,  /* [465] */
    (xdc_Char)0x2f,  /* [466] */
    (xdc_Char)0x64,  /* [467] */
    (xdc_Char)0x65,  /* [468] */
    (xdc_Char)0x6c,  /* [469] */
    (xdc_Char)0x65,  /* [470] */
    (xdc_Char)0x74,  /* [471] */
    (xdc_Char)0x65,  /* [472] */
    (xdc_Char)0x20,  /* [473] */
    (xdc_Char)0x61,  /* [474] */
    (xdc_Char)0x20,  /* [475] */
    (xdc_Char)0x43,  /* [476] */
    (xdc_Char)0x6c,  /* [477] */
    (xdc_Char)0x6f,  /* [478] */
    (xdc_Char)0x63,  /* [479] */
    (xdc_Char)0x6b,  /* [480] */
    (xdc_Char)0x20,  /* [481] */
    (xdc_Char)0x66,  /* [482] */
    (xdc_Char)0x72,  /* [483] */
    (xdc_Char)0x6f,  /* [484] */
    (xdc_Char)0x6d,  /* [485] */
    (xdc_Char)0x20,  /* [486] */
    (xdc_Char)0x48,  /* [487] */
    (xdc_Char)0x77,  /* [488] */
    (xdc_Char)0x69,  /* [489] */
    (xdc_Char)0x20,  /* [490] */
    (xdc_Char)0x6f,  /* [491] */
    (xdc_Char)0x72,  /* [492] */
    (xdc_Char)0x20,  /* [493] */
    (xdc_Char)0x53,  /* [494] */
    (xdc_Char)0x77,  /* [495] */
    (xdc_Char)0x69,  /* [496] */
    (xdc_Char)0x20,  /* [497] */
    (xdc_Char)0x74,  /* [498] */
    (xdc_Char)0x68,  /* [499] */
    (xdc_Char)0x72,  /* [500] */
    (xdc_Char)0x65,  /* [501] */
    (xdc_Char)0x61,  /* [502] */
    (xdc_Char)0x64,  /* [503] */
    (xdc_Char)0x2e,  /* [504] */
    (xdc_Char)0x0,  /* [505] */
    (xdc_Char)0x41,  /* [506] */
    (xdc_Char)0x5f,  /* [507] */
    (xdc_Char)0x6e,  /* [508] */
    (xdc_Char)0x75,  /* [509] */
    (xdc_Char)0x6c,  /* [510] */
    (xdc_Char)0x6c,  /* [511] */
    (xdc_Char)0x45,  /* [512] */
    (xdc_Char)0x76,  /* [513] */
    (xdc_Char)0x65,  /* [514] */
    (xdc_Char)0x6e,  /* [515] */
    (xdc_Char)0x74,  /* [516] */
    (xdc_Char)0x4d,  /* [517] */
    (xdc_Char)0x61,  /* [518] */
    (xdc_Char)0x73,  /* [519] */
    (xdc_Char)0x6b,  /* [520] */
    (xdc_Char)0x73,  /* [521] */
    (xdc_Char)0x3a,  /* [522] */
    (xdc_Char)0x20,  /* [523] */
    (xdc_Char)0x6f,  /* [524] */
    (xdc_Char)0x72,  /* [525] */
    (xdc_Char)0x4d,  /* [526] */
    (xdc_Char)0x61,  /* [527] */
    (xdc_Char)0x73,  /* [528] */
    (xdc_Char)0x6b,  /* [529] */
    (xdc_Char)0x20,  /* [530] */
    (xdc_Char)0x61,  /* [531] */
    (xdc_Char)0x6e,  /* [532] */
    (xdc_Char)0x64,  /* [533] */
    (xdc_Char)0x20,  /* [534] */
    (xdc_Char)0x61,  /* [535] */
    (xdc_Char)0x6e,  /* [536] */
    (xdc_Char)0x64,  /* [537] */
    (xdc_Char)0x4d,  /* [538] */
    (xdc_Char)0x61,  /* [539] */
    (xdc_Char)0x73,  /* [540] */
    (xdc_Char)0x6b,  /* [541] */
    (xdc_Char)0x20,  /* [542] */
    (xdc_Char)0x61,  /* [543] */
    (xdc_Char)0x72,  /* [544] */
    (xdc_Char)0x65,  /* [545] */
    (xdc_Char)0x20,  /* [546] */
    (xdc_Char)0x6e,  /* [547] */
    (xdc_Char)0x75,  /* [548] */
    (xdc_Char)0x6c,  /* [549] */
    (xdc_Char)0x6c,  /* [550] */
    (xdc_Char)0x2e,  /* [551] */
    (xdc_Char)0x0,  /* [552] */
    (xdc_Char)0x41,  /* [553] */
    (xdc_Char)0x5f,  /* [554] */
    (xdc_Char)0x6e,  /* [555] */
    (xdc_Char)0x75,  /* [556] */
    (xdc_Char)0x6c,  /* [557] */
    (xdc_Char)0x6c,  /* [558] */
    (xdc_Char)0x45,  /* [559] */
    (xdc_Char)0x76,  /* [560] */
    (xdc_Char)0x65,  /* [561] */
    (xdc_Char)0x6e,  /* [562] */
    (xdc_Char)0x74,  /* [563] */
    (xdc_Char)0x49,  /* [564] */
    (xdc_Char)0x64,  /* [565] */
    (xdc_Char)0x3a,  /* [566] */
    (xdc_Char)0x20,  /* [567] */
    (xdc_Char)0x70,  /* [568] */
    (xdc_Char)0x6f,  /* [569] */
    (xdc_Char)0x73,  /* [570] */
    (xdc_Char)0x74,  /* [571] */
    (xdc_Char)0x65,  /* [572] */
    (xdc_Char)0x64,  /* [573] */
    (xdc_Char)0x20,  /* [574] */
    (xdc_Char)0x65,  /* [575] */
    (xdc_Char)0x76,  /* [576] */
    (xdc_Char)0x65,  /* [577] */
    (xdc_Char)0x6e,  /* [578] */
    (xdc_Char)0x74,  /* [579] */
    (xdc_Char)0x49,  /* [580] */
    (xdc_Char)0x64,  /* [581] */
    (xdc_Char)0x20,  /* [582] */
    (xdc_Char)0x69,  /* [583] */
    (xdc_Char)0x73,  /* [584] */
    (xdc_Char)0x20,  /* [585] */
    (xdc_Char)0x6e,  /* [586] */
    (xdc_Char)0x75,  /* [587] */
    (xdc_Char)0x6c,  /* [588] */
    (xdc_Char)0x6c,  /* [589] */
    (xdc_Char)0x2e,  /* [590] */
    (xdc_Char)0x0,  /* [591] */
    (xdc_Char)0x41,  /* [592] */
    (xdc_Char)0x5f,  /* [593] */
    (xdc_Char)0x65,  /* [594] */
    (xdc_Char)0x76,  /* [595] */
    (xdc_Char)0x65,  /* [596] */
    (xdc_Char)0x6e,  /* [597] */
    (xdc_Char)0x74,  /* [598] */
    (xdc_Char)0x49,  /* [599] */
    (xdc_Char)0x6e,  /* [600] */
    (xdc_Char)0x55,  /* [601] */
    (xdc_Char)0x73,  /* [602] */
    (xdc_Char)0x65,  /* [603] */
    (xdc_Char)0x3a,  /* [604] */
    (xdc_Char)0x20,  /* [605] */
    (xdc_Char)0x45,  /* [606] */
    (xdc_Char)0x76,  /* [607] */
    (xdc_Char)0x65,  /* [608] */
    (xdc_Char)0x6e,  /* [609] */
    (xdc_Char)0x74,  /* [610] */
    (xdc_Char)0x20,  /* [611] */
    (xdc_Char)0x6f,  /* [612] */
    (xdc_Char)0x62,  /* [613] */
    (xdc_Char)0x6a,  /* [614] */
    (xdc_Char)0x65,  /* [615] */
    (xdc_Char)0x63,  /* [616] */
    (xdc_Char)0x74,  /* [617] */
    (xdc_Char)0x20,  /* [618] */
    (xdc_Char)0x61,  /* [619] */
    (xdc_Char)0x6c,  /* [620] */
    (xdc_Char)0x72,  /* [621] */
    (xdc_Char)0x65,  /* [622] */
    (xdc_Char)0x61,  /* [623] */
    (xdc_Char)0x64,  /* [624] */
    (xdc_Char)0x79,  /* [625] */
    (xdc_Char)0x20,  /* [626] */
    (xdc_Char)0x69,  /* [627] */
    (xdc_Char)0x6e,  /* [628] */
    (xdc_Char)0x20,  /* [629] */
    (xdc_Char)0x75,  /* [630] */
    (xdc_Char)0x73,  /* [631] */
    (xdc_Char)0x65,  /* [632] */
    (xdc_Char)0x2e,  /* [633] */
    (xdc_Char)0x0,  /* [634] */
    (xdc_Char)0x41,  /* [635] */
    (xdc_Char)0x5f,  /* [636] */
    (xdc_Char)0x62,  /* [637] */
    (xdc_Char)0x61,  /* [638] */
    (xdc_Char)0x64,  /* [639] */
    (xdc_Char)0x43,  /* [640] */
    (xdc_Char)0x6f,  /* [641] */
    (xdc_Char)0x6e,  /* [642] */
    (xdc_Char)0x74,  /* [643] */
    (xdc_Char)0x65,  /* [644] */
    (xdc_Char)0x78,  /* [645] */
    (xdc_Char)0x74,  /* [646] */
    (xdc_Char)0x3a,  /* [647] */
    (xdc_Char)0x20,  /* [648] */
    (xdc_Char)0x62,  /* [649] */
    (xdc_Char)0x61,  /* [650] */
    (xdc_Char)0x64,  /* [651] */
    (xdc_Char)0x20,  /* [652] */
    (xdc_Char)0x63,  /* [653] */
    (xdc_Char)0x61,  /* [654] */
    (xdc_Char)0x6c,  /* [655] */
    (xdc_Char)0x6c,  /* [656] */
    (xdc_Char)0x69,  /* [657] */
    (xdc_Char)0x6e,  /* [658] */
    (xdc_Char)0x67,  /* [659] */
    (xdc_Char)0x20,  /* [660] */
    (xdc_Char)0x63,  /* [661] */
    (xdc_Char)0x6f,  /* [662] */
    (xdc_Char)0x6e,  /* [663] */
    (xdc_Char)0x74,  /* [664] */
    (xdc_Char)0x65,  /* [665] */
    (xdc_Char)0x78,  /* [666] */
    (xdc_Char)0x74,  /* [667] */
    (xdc_Char)0x2e,  /* [668] */
    (xdc_Char)0x20,  /* [669] */
    (xdc_Char)0x4d,  /* [670] */
    (xdc_Char)0x75,  /* [671] */
    (xdc_Char)0x73,  /* [672] */
    (xdc_Char)0x74,  /* [673] */
    (xdc_Char)0x20,  /* [674] */
    (xdc_Char)0x62,  /* [675] */
    (xdc_Char)0x65,  /* [676] */
    (xdc_Char)0x20,  /* [677] */
    (xdc_Char)0x63,  /* [678] */
    (xdc_Char)0x61,  /* [679] */
    (xdc_Char)0x6c,  /* [680] */
    (xdc_Char)0x6c,  /* [681] */
    (xdc_Char)0x65,  /* [682] */
    (xdc_Char)0x64,  /* [683] */
    (xdc_Char)0x20,  /* [684] */
    (xdc_Char)0x66,  /* [685] */
    (xdc_Char)0x72,  /* [686] */
    (xdc_Char)0x6f,  /* [687] */
    (xdc_Char)0x6d,  /* [688] */
    (xdc_Char)0x20,  /* [689] */
    (xdc_Char)0x61,  /* [690] */
    (xdc_Char)0x20,  /* [691] */
    (xdc_Char)0x54,  /* [692] */
    (xdc_Char)0x61,  /* [693] */
    (xdc_Char)0x73,  /* [694] */
    (xdc_Char)0x6b,  /* [695] */
    (xdc_Char)0x2e,  /* [696] */
    (xdc_Char)0x0,  /* [697] */
    (xdc_Char)0x4d,  /* [698] */
    (xdc_Char)0x61,  /* [699] */
    (xdc_Char)0x69,  /* [700] */
    (xdc_Char)0x6c,  /* [701] */
    (xdc_Char)0x62,  /* [702] */
    (xdc_Char)0x6f,  /* [703] */
    (xdc_Char)0x78,  /* [704] */
    (xdc_Char)0x5f,  /* [705] */
    (xdc_Char)0x63,  /* [706] */
    (xdc_Char)0x72,  /* [707] */
    (xdc_Char)0x65,  /* [708] */
    (xdc_Char)0x61,  /* [709] */
    (xdc_Char)0x74,  /* [710] */
    (xdc_Char)0x65,  /* [711] */
    (xdc_Char)0x27,  /* [712] */
    (xdc_Char)0x73,  /* [713] */
    (xdc_Char)0x20,  /* [714] */
    (xdc_Char)0x62,  /* [715] */
    (xdc_Char)0x75,  /* [716] */
    (xdc_Char)0x66,  /* [717] */
    (xdc_Char)0x53,  /* [718] */
    (xdc_Char)0x69,  /* [719] */
    (xdc_Char)0x7a,  /* [720] */
    (xdc_Char)0x65,  /* [721] */
    (xdc_Char)0x20,  /* [722] */
    (xdc_Char)0x70,  /* [723] */
    (xdc_Char)0x61,  /* [724] */
    (xdc_Char)0x72,  /* [725] */
    (xdc_Char)0x61,  /* [726] */
    (xdc_Char)0x6d,  /* [727] */
    (xdc_Char)0x65,  /* [728] */
    (xdc_Char)0x74,  /* [729] */
    (xdc_Char)0x65,  /* [730] */
    (xdc_Char)0x72,  /* [731] */
    (xdc_Char)0x20,  /* [732] */
    (xdc_Char)0x69,  /* [733] */
    (xdc_Char)0x73,  /* [734] */
    (xdc_Char)0x20,  /* [735] */
    (xdc_Char)0x69,  /* [736] */
    (xdc_Char)0x6e,  /* [737] */
    (xdc_Char)0x76,  /* [738] */
    (xdc_Char)0x61,  /* [739] */
    (xdc_Char)0x6c,  /* [740] */
    (xdc_Char)0x69,  /* [741] */
    (xdc_Char)0x64,  /* [742] */
    (xdc_Char)0x20,  /* [743] */
    (xdc_Char)0x28,  /* [744] */
    (xdc_Char)0x74,  /* [745] */
    (xdc_Char)0x6f,  /* [746] */
    (xdc_Char)0x6f,  /* [747] */
    (xdc_Char)0x20,  /* [748] */
    (xdc_Char)0x73,  /* [749] */
    (xdc_Char)0x6d,  /* [750] */
    (xdc_Char)0x61,  /* [751] */
    (xdc_Char)0x6c,  /* [752] */
    (xdc_Char)0x6c,  /* [753] */
    (xdc_Char)0x29,  /* [754] */
    (xdc_Char)0x0,  /* [755] */
    (xdc_Char)0x41,  /* [756] */
    (xdc_Char)0x5f,  /* [757] */
    (xdc_Char)0x6e,  /* [758] */
    (xdc_Char)0x6f,  /* [759] */
    (xdc_Char)0x45,  /* [760] */
    (xdc_Char)0x76,  /* [761] */
    (xdc_Char)0x65,  /* [762] */
    (xdc_Char)0x6e,  /* [763] */
    (xdc_Char)0x74,  /* [764] */
    (xdc_Char)0x73,  /* [765] */
    (xdc_Char)0x3a,  /* [766] */
    (xdc_Char)0x20,  /* [767] */
    (xdc_Char)0x54,  /* [768] */
    (xdc_Char)0x68,  /* [769] */
    (xdc_Char)0x65,  /* [770] */
    (xdc_Char)0x20,  /* [771] */
    (xdc_Char)0x45,  /* [772] */
    (xdc_Char)0x76,  /* [773] */
    (xdc_Char)0x65,  /* [774] */
    (xdc_Char)0x6e,  /* [775] */
    (xdc_Char)0x74,  /* [776] */
    (xdc_Char)0x2e,  /* [777] */
    (xdc_Char)0x73,  /* [778] */
    (xdc_Char)0x75,  /* [779] */
    (xdc_Char)0x70,  /* [780] */
    (xdc_Char)0x70,  /* [781] */
    (xdc_Char)0x6f,  /* [782] */
    (xdc_Char)0x72,  /* [783] */
    (xdc_Char)0x74,  /* [784] */
    (xdc_Char)0x73,  /* [785] */
    (xdc_Char)0x45,  /* [786] */
    (xdc_Char)0x76,  /* [787] */
    (xdc_Char)0x65,  /* [788] */
    (xdc_Char)0x6e,  /* [789] */
    (xdc_Char)0x74,  /* [790] */
    (xdc_Char)0x73,  /* [791] */
    (xdc_Char)0x20,  /* [792] */
    (xdc_Char)0x66,  /* [793] */
    (xdc_Char)0x6c,  /* [794] */
    (xdc_Char)0x61,  /* [795] */
    (xdc_Char)0x67,  /* [796] */
    (xdc_Char)0x20,  /* [797] */
    (xdc_Char)0x69,  /* [798] */
    (xdc_Char)0x73,  /* [799] */
    (xdc_Char)0x20,  /* [800] */
    (xdc_Char)0x64,  /* [801] */
    (xdc_Char)0x69,  /* [802] */
    (xdc_Char)0x73,  /* [803] */
    (xdc_Char)0x61,  /* [804] */
    (xdc_Char)0x62,  /* [805] */
    (xdc_Char)0x6c,  /* [806] */
    (xdc_Char)0x65,  /* [807] */
    (xdc_Char)0x64,  /* [808] */
    (xdc_Char)0x2e,  /* [809] */
    (xdc_Char)0x0,  /* [810] */
    (xdc_Char)0x41,  /* [811] */
    (xdc_Char)0x5f,  /* [812] */
    (xdc_Char)0x69,  /* [813] */
    (xdc_Char)0x6e,  /* [814] */
    (xdc_Char)0x76,  /* [815] */
    (xdc_Char)0x54,  /* [816] */
    (xdc_Char)0x69,  /* [817] */
    (xdc_Char)0x6d,  /* [818] */
    (xdc_Char)0x65,  /* [819] */
    (xdc_Char)0x6f,  /* [820] */
    (xdc_Char)0x75,  /* [821] */
    (xdc_Char)0x74,  /* [822] */
    (xdc_Char)0x3a,  /* [823] */
    (xdc_Char)0x20,  /* [824] */
    (xdc_Char)0x43,  /* [825] */
    (xdc_Char)0x61,  /* [826] */
    (xdc_Char)0x6e,  /* [827] */
    (xdc_Char)0x27,  /* [828] */
    (xdc_Char)0x74,  /* [829] */
    (xdc_Char)0x20,  /* [830] */
    (xdc_Char)0x75,  /* [831] */
    (xdc_Char)0x73,  /* [832] */
    (xdc_Char)0x65,  /* [833] */
    (xdc_Char)0x20,  /* [834] */
    (xdc_Char)0x42,  /* [835] */
    (xdc_Char)0x49,  /* [836] */
    (xdc_Char)0x4f,  /* [837] */
    (xdc_Char)0x53,  /* [838] */
    (xdc_Char)0x5f,  /* [839] */
    (xdc_Char)0x45,  /* [840] */
    (xdc_Char)0x56,  /* [841] */
    (xdc_Char)0x45,  /* [842] */
    (xdc_Char)0x4e,  /* [843] */
    (xdc_Char)0x54,  /* [844] */
    (xdc_Char)0x5f,  /* [845] */
    (xdc_Char)0x41,  /* [846] */
    (xdc_Char)0x43,  /* [847] */
    (xdc_Char)0x51,  /* [848] */
    (xdc_Char)0x55,  /* [849] */
    (xdc_Char)0x49,  /* [850] */
    (xdc_Char)0x52,  /* [851] */
    (xdc_Char)0x45,  /* [852] */
    (xdc_Char)0x44,  /* [853] */
    (xdc_Char)0x20,  /* [854] */
    (xdc_Char)0x77,  /* [855] */
    (xdc_Char)0x69,  /* [856] */
    (xdc_Char)0x74,  /* [857] */
    (xdc_Char)0x68,  /* [858] */
    (xdc_Char)0x20,  /* [859] */
    (xdc_Char)0x74,  /* [860] */
    (xdc_Char)0x68,  /* [861] */
    (xdc_Char)0x69,  /* [862] */
    (xdc_Char)0x73,  /* [863] */
    (xdc_Char)0x20,  /* [864] */
    (xdc_Char)0x53,  /* [865] */
    (xdc_Char)0x65,  /* [866] */
    (xdc_Char)0x6d,  /* [867] */
    (xdc_Char)0x61,  /* [868] */
    (xdc_Char)0x70,  /* [869] */
    (xdc_Char)0x68,  /* [870] */
    (xdc_Char)0x6f,  /* [871] */
    (xdc_Char)0x72,  /* [872] */
    (xdc_Char)0x65,  /* [873] */
    (xdc_Char)0x2e,  /* [874] */
    (xdc_Char)0x0,  /* [875] */
    (xdc_Char)0x41,  /* [876] */
    (xdc_Char)0x5f,  /* [877] */
    (xdc_Char)0x6f,  /* [878] */
    (xdc_Char)0x76,  /* [879] */
    (xdc_Char)0x65,  /* [880] */
    (xdc_Char)0x72,  /* [881] */
    (xdc_Char)0x66,  /* [882] */
    (xdc_Char)0x6c,  /* [883] */
    (xdc_Char)0x6f,  /* [884] */
    (xdc_Char)0x77,  /* [885] */
    (xdc_Char)0x3a,  /* [886] */
    (xdc_Char)0x20,  /* [887] */
    (xdc_Char)0x43,  /* [888] */
    (xdc_Char)0x6f,  /* [889] */
    (xdc_Char)0x75,  /* [890] */
    (xdc_Char)0x6e,  /* [891] */
    (xdc_Char)0x74,  /* [892] */
    (xdc_Char)0x20,  /* [893] */
    (xdc_Char)0x68,  /* [894] */
    (xdc_Char)0x61,  /* [895] */
    (xdc_Char)0x73,  /* [896] */
    (xdc_Char)0x20,  /* [897] */
    (xdc_Char)0x65,  /* [898] */
    (xdc_Char)0x78,  /* [899] */
    (xdc_Char)0x63,  /* [900] */
    (xdc_Char)0x65,  /* [901] */
    (xdc_Char)0x65,  /* [902] */
    (xdc_Char)0x64,  /* [903] */
    (xdc_Char)0x65,  /* [904] */
    (xdc_Char)0x64,  /* [905] */
    (xdc_Char)0x20,  /* [906] */
    (xdc_Char)0x36,  /* [907] */
    (xdc_Char)0x35,  /* [908] */
    (xdc_Char)0x35,  /* [909] */
    (xdc_Char)0x33,  /* [910] */
    (xdc_Char)0x35,  /* [911] */
    (xdc_Char)0x20,  /* [912] */
    (xdc_Char)0x61,  /* [913] */
    (xdc_Char)0x6e,  /* [914] */
    (xdc_Char)0x64,  /* [915] */
    (xdc_Char)0x20,  /* [916] */
    (xdc_Char)0x72,  /* [917] */
    (xdc_Char)0x6f,  /* [918] */
    (xdc_Char)0x6c,  /* [919] */
    (xdc_Char)0x6c,  /* [920] */
    (xdc_Char)0x65,  /* [921] */
    (xdc_Char)0x64,  /* [922] */
    (xdc_Char)0x20,  /* [923] */
    (xdc_Char)0x6f,  /* [924] */
    (xdc_Char)0x76,  /* [925] */
    (xdc_Char)0x65,  /* [926] */
    (xdc_Char)0x72,  /* [927] */
    (xdc_Char)0x2e,  /* [928] */
    (xdc_Char)0x0,  /* [929] */
    (xdc_Char)0x41,  /* [930] */
    (xdc_Char)0x5f,  /* [931] */
    (xdc_Char)0x73,  /* [932] */
    (xdc_Char)0x77,  /* [933] */
    (xdc_Char)0x69,  /* [934] */
    (xdc_Char)0x44,  /* [935] */
    (xdc_Char)0x69,  /* [936] */
    (xdc_Char)0x73,  /* [937] */
    (xdc_Char)0x61,  /* [938] */
    (xdc_Char)0x62,  /* [939] */
    (xdc_Char)0x6c,  /* [940] */
    (xdc_Char)0x65,  /* [941] */
    (xdc_Char)0x64,  /* [942] */
    (xdc_Char)0x3a,  /* [943] */
    (xdc_Char)0x20,  /* [944] */
    (xdc_Char)0x43,  /* [945] */
    (xdc_Char)0x61,  /* [946] */
    (xdc_Char)0x6e,  /* [947] */
    (xdc_Char)0x6e,  /* [948] */
    (xdc_Char)0x6f,  /* [949] */
    (xdc_Char)0x74,  /* [950] */
    (xdc_Char)0x20,  /* [951] */
    (xdc_Char)0x63,  /* [952] */
    (xdc_Char)0x72,  /* [953] */
    (xdc_Char)0x65,  /* [954] */
    (xdc_Char)0x61,  /* [955] */
    (xdc_Char)0x74,  /* [956] */
    (xdc_Char)0x65,  /* [957] */
    (xdc_Char)0x20,  /* [958] */
    (xdc_Char)0x61,  /* [959] */
    (xdc_Char)0x20,  /* [960] */
    (xdc_Char)0x53,  /* [961] */
    (xdc_Char)0x77,  /* [962] */
    (xdc_Char)0x69,  /* [963] */
    (xdc_Char)0x20,  /* [964] */
    (xdc_Char)0x77,  /* [965] */
    (xdc_Char)0x68,  /* [966] */
    (xdc_Char)0x65,  /* [967] */
    (xdc_Char)0x6e,  /* [968] */
    (xdc_Char)0x20,  /* [969] */
    (xdc_Char)0x53,  /* [970] */
    (xdc_Char)0x77,  /* [971] */
    (xdc_Char)0x69,  /* [972] */
    (xdc_Char)0x20,  /* [973] */
    (xdc_Char)0x69,  /* [974] */
    (xdc_Char)0x73,  /* [975] */
    (xdc_Char)0x20,  /* [976] */
    (xdc_Char)0x64,  /* [977] */
    (xdc_Char)0x69,  /* [978] */
    (xdc_Char)0x73,  /* [979] */
    (xdc_Char)0x61,  /* [980] */
    (xdc_Char)0x62,  /* [981] */
    (xdc_Char)0x6c,  /* [982] */
    (xdc_Char)0x65,  /* [983] */
    (xdc_Char)0x64,  /* [984] */
    (xdc_Char)0x2e,  /* [985] */
    (xdc_Char)0x0,  /* [986] */
    (xdc_Char)0x41,  /* [987] */
    (xdc_Char)0x5f,  /* [988] */
    (xdc_Char)0x62,  /* [989] */
    (xdc_Char)0x61,  /* [990] */
    (xdc_Char)0x64,  /* [991] */
    (xdc_Char)0x50,  /* [992] */
    (xdc_Char)0x72,  /* [993] */
    (xdc_Char)0x69,  /* [994] */
    (xdc_Char)0x6f,  /* [995] */
    (xdc_Char)0x72,  /* [996] */
    (xdc_Char)0x69,  /* [997] */
    (xdc_Char)0x74,  /* [998] */
    (xdc_Char)0x79,  /* [999] */
    (xdc_Char)0x3a,  /* [1000] */
    (xdc_Char)0x20,  /* [1001] */
    (xdc_Char)0x41,  /* [1002] */
    (xdc_Char)0x6e,  /* [1003] */
    (xdc_Char)0x20,  /* [1004] */
    (xdc_Char)0x69,  /* [1005] */
    (xdc_Char)0x6e,  /* [1006] */
    (xdc_Char)0x76,  /* [1007] */
    (xdc_Char)0x61,  /* [1008] */
    (xdc_Char)0x6c,  /* [1009] */
    (xdc_Char)0x69,  /* [1010] */
    (xdc_Char)0x64,  /* [1011] */
    (xdc_Char)0x20,  /* [1012] */
    (xdc_Char)0x53,  /* [1013] */
    (xdc_Char)0x77,  /* [1014] */
    (xdc_Char)0x69,  /* [1015] */
    (xdc_Char)0x20,  /* [1016] */
    (xdc_Char)0x70,  /* [1017] */
    (xdc_Char)0x72,  /* [1018] */
    (xdc_Char)0x69,  /* [1019] */
    (xdc_Char)0x6f,  /* [1020] */
    (xdc_Char)0x72,  /* [1021] */
    (xdc_Char)0x69,  /* [1022] */
    (xdc_Char)0x74,  /* [1023] */
    (xdc_Char)0x79,  /* [1024] */
    (xdc_Char)0x20,  /* [1025] */
    (xdc_Char)0x77,  /* [1026] */
    (xdc_Char)0x61,  /* [1027] */
    (xdc_Char)0x73,  /* [1028] */
    (xdc_Char)0x20,  /* [1029] */
    (xdc_Char)0x75,  /* [1030] */
    (xdc_Char)0x73,  /* [1031] */
    (xdc_Char)0x65,  /* [1032] */
    (xdc_Char)0x64,  /* [1033] */
    (xdc_Char)0x2e,  /* [1034] */
    (xdc_Char)0x0,  /* [1035] */
    (xdc_Char)0x41,  /* [1036] */
    (xdc_Char)0x5f,  /* [1037] */
    (xdc_Char)0x62,  /* [1038] */
    (xdc_Char)0x61,  /* [1039] */
    (xdc_Char)0x64,  /* [1040] */
    (xdc_Char)0x54,  /* [1041] */
    (xdc_Char)0x68,  /* [1042] */
    (xdc_Char)0x72,  /* [1043] */
    (xdc_Char)0x65,  /* [1044] */
    (xdc_Char)0x61,  /* [1045] */
    (xdc_Char)0x64,  /* [1046] */
    (xdc_Char)0x54,  /* [1047] */
    (xdc_Char)0x79,  /* [1048] */
    (xdc_Char)0x70,  /* [1049] */
    (xdc_Char)0x65,  /* [1050] */
    (xdc_Char)0x3a,  /* [1051] */
    (xdc_Char)0x20,  /* [1052] */
    (xdc_Char)0x43,  /* [1053] */
    (xdc_Char)0x61,  /* [1054] */
    (xdc_Char)0x6e,  /* [1055] */
    (xdc_Char)0x6e,  /* [1056] */
    (xdc_Char)0x6f,  /* [1057] */
    (xdc_Char)0x74,  /* [1058] */
    (xdc_Char)0x20,  /* [1059] */
    (xdc_Char)0x63,  /* [1060] */
    (xdc_Char)0x72,  /* [1061] */
    (xdc_Char)0x65,  /* [1062] */
    (xdc_Char)0x61,  /* [1063] */
    (xdc_Char)0x74,  /* [1064] */
    (xdc_Char)0x65,  /* [1065] */
    (xdc_Char)0x2f,  /* [1066] */
    (xdc_Char)0x64,  /* [1067] */
    (xdc_Char)0x65,  /* [1068] */
    (xdc_Char)0x6c,  /* [1069] */
    (xdc_Char)0x65,  /* [1070] */
    (xdc_Char)0x74,  /* [1071] */
    (xdc_Char)0x65,  /* [1072] */
    (xdc_Char)0x20,  /* [1073] */
    (xdc_Char)0x61,  /* [1074] */
    (xdc_Char)0x20,  /* [1075] */
    (xdc_Char)0x74,  /* [1076] */
    (xdc_Char)0x61,  /* [1077] */
    (xdc_Char)0x73,  /* [1078] */
    (xdc_Char)0x6b,  /* [1079] */
    (xdc_Char)0x20,  /* [1080] */
    (xdc_Char)0x66,  /* [1081] */
    (xdc_Char)0x72,  /* [1082] */
    (xdc_Char)0x6f,  /* [1083] */
    (xdc_Char)0x6d,  /* [1084] */
    (xdc_Char)0x20,  /* [1085] */
    (xdc_Char)0x48,  /* [1086] */
    (xdc_Char)0x77,  /* [1087] */
    (xdc_Char)0x69,  /* [1088] */
    (xdc_Char)0x20,  /* [1089] */
    (xdc_Char)0x6f,  /* [1090] */
    (xdc_Char)0x72,  /* [1091] */
    (xdc_Char)0x20,  /* [1092] */
    (xdc_Char)0x53,  /* [1093] */
    (xdc_Char)0x77,  /* [1094] */
    (xdc_Char)0x69,  /* [1095] */
    (xdc_Char)0x20,  /* [1096] */
    (xdc_Char)0x74,  /* [1097] */
    (xdc_Char)0x68,  /* [1098] */
    (xdc_Char)0x72,  /* [1099] */
    (xdc_Char)0x65,  /* [1100] */
    (xdc_Char)0x61,  /* [1101] */
    (xdc_Char)0x64,  /* [1102] */
    (xdc_Char)0x2e,  /* [1103] */
    (xdc_Char)0x0,  /* [1104] */
    (xdc_Char)0x41,  /* [1105] */
    (xdc_Char)0x5f,  /* [1106] */
    (xdc_Char)0x62,  /* [1107] */
    (xdc_Char)0x61,  /* [1108] */
    (xdc_Char)0x64,  /* [1109] */
    (xdc_Char)0x54,  /* [1110] */
    (xdc_Char)0x61,  /* [1111] */
    (xdc_Char)0x73,  /* [1112] */
    (xdc_Char)0x6b,  /* [1113] */
    (xdc_Char)0x53,  /* [1114] */
    (xdc_Char)0x74,  /* [1115] */
    (xdc_Char)0x61,  /* [1116] */
    (xdc_Char)0x74,  /* [1117] */
    (xdc_Char)0x65,  /* [1118] */
    (xdc_Char)0x3a,  /* [1119] */
    (xdc_Char)0x20,  /* [1120] */
    (xdc_Char)0x43,  /* [1121] */
    (xdc_Char)0x61,  /* [1122] */
    (xdc_Char)0x6e,  /* [1123] */
    (xdc_Char)0x27,  /* [1124] */
    (xdc_Char)0x74,  /* [1125] */
    (xdc_Char)0x20,  /* [1126] */
    (xdc_Char)0x64,  /* [1127] */
    (xdc_Char)0x65,  /* [1128] */
    (xdc_Char)0x6c,  /* [1129] */
    (xdc_Char)0x65,  /* [1130] */
    (xdc_Char)0x74,  /* [1131] */
    (xdc_Char)0x65,  /* [1132] */
    (xdc_Char)0x20,  /* [1133] */
    (xdc_Char)0x61,  /* [1134] */
    (xdc_Char)0x20,  /* [1135] */
    (xdc_Char)0x74,  /* [1136] */
    (xdc_Char)0x61,  /* [1137] */
    (xdc_Char)0x73,  /* [1138] */
    (xdc_Char)0x6b,  /* [1139] */
    (xdc_Char)0x20,  /* [1140] */
    (xdc_Char)0x69,  /* [1141] */
    (xdc_Char)0x6e,  /* [1142] */
    (xdc_Char)0x20,  /* [1143] */
    (xdc_Char)0x52,  /* [1144] */
    (xdc_Char)0x55,  /* [1145] */
    (xdc_Char)0x4e,  /* [1146] */
    (xdc_Char)0x4e,  /* [1147] */
    (xdc_Char)0x49,  /* [1148] */
    (xdc_Char)0x4e,  /* [1149] */
    (xdc_Char)0x47,  /* [1150] */
    (xdc_Char)0x20,  /* [1151] */
    (xdc_Char)0x73,  /* [1152] */
    (xdc_Char)0x74,  /* [1153] */
    (xdc_Char)0x61,  /* [1154] */
    (xdc_Char)0x74,  /* [1155] */
    (xdc_Char)0x65,  /* [1156] */
    (xdc_Char)0x2e,  /* [1157] */
    (xdc_Char)0x0,  /* [1158] */
    (xdc_Char)0x41,  /* [1159] */
    (xdc_Char)0x5f,  /* [1160] */
    (xdc_Char)0x6e,  /* [1161] */
    (xdc_Char)0x6f,  /* [1162] */
    (xdc_Char)0x50,  /* [1163] */
    (xdc_Char)0x65,  /* [1164] */
    (xdc_Char)0x6e,  /* [1165] */
    (xdc_Char)0x64,  /* [1166] */
    (xdc_Char)0x45,  /* [1167] */
    (xdc_Char)0x6c,  /* [1168] */
    (xdc_Char)0x65,  /* [1169] */
    (xdc_Char)0x6d,  /* [1170] */
    (xdc_Char)0x3a,  /* [1171] */
    (xdc_Char)0x20,  /* [1172] */
    (xdc_Char)0x4e,  /* [1173] */
    (xdc_Char)0x6f,  /* [1174] */
    (xdc_Char)0x74,  /* [1175] */
    (xdc_Char)0x20,  /* [1176] */
    (xdc_Char)0x65,  /* [1177] */
    (xdc_Char)0x6e,  /* [1178] */
    (xdc_Char)0x6f,  /* [1179] */
    (xdc_Char)0x75,  /* [1180] */
    (xdc_Char)0x67,  /* [1181] */
    (xdc_Char)0x68,  /* [1182] */
    (xdc_Char)0x20,  /* [1183] */
    (xdc_Char)0x69,  /* [1184] */
    (xdc_Char)0x6e,  /* [1185] */
    (xdc_Char)0x66,  /* [1186] */
    (xdc_Char)0x6f,  /* [1187] */
    (xdc_Char)0x20,  /* [1188] */
    (xdc_Char)0x74,  /* [1189] */
    (xdc_Char)0x6f,  /* [1190] */
    (xdc_Char)0x20,  /* [1191] */
    (xdc_Char)0x64,  /* [1192] */
    (xdc_Char)0x65,  /* [1193] */
    (xdc_Char)0x6c,  /* [1194] */
    (xdc_Char)0x65,  /* [1195] */
    (xdc_Char)0x74,  /* [1196] */
    (xdc_Char)0x65,  /* [1197] */
    (xdc_Char)0x20,  /* [1198] */
    (xdc_Char)0x42,  /* [1199] */
    (xdc_Char)0x4c,  /* [1200] */
    (xdc_Char)0x4f,  /* [1201] */
    (xdc_Char)0x43,  /* [1202] */
    (xdc_Char)0x4b,  /* [1203] */
    (xdc_Char)0x45,  /* [1204] */
    (xdc_Char)0x44,  /* [1205] */
    (xdc_Char)0x20,  /* [1206] */
    (xdc_Char)0x74,  /* [1207] */
    (xdc_Char)0x61,  /* [1208] */
    (xdc_Char)0x73,  /* [1209] */
    (xdc_Char)0x6b,  /* [1210] */
    (xdc_Char)0x2e,  /* [1211] */
    (xdc_Char)0x0,  /* [1212] */
    (xdc_Char)0x41,  /* [1213] */
    (xdc_Char)0x5f,  /* [1214] */
    (xdc_Char)0x74,  /* [1215] */
    (xdc_Char)0x61,  /* [1216] */
    (xdc_Char)0x73,  /* [1217] */
    (xdc_Char)0x6b,  /* [1218] */
    (xdc_Char)0x44,  /* [1219] */
    (xdc_Char)0x69,  /* [1220] */
    (xdc_Char)0x73,  /* [1221] */
    (xdc_Char)0x61,  /* [1222] */
    (xdc_Char)0x62,  /* [1223] */
    (xdc_Char)0x6c,  /* [1224] */
    (xdc_Char)0x65,  /* [1225] */
    (xdc_Char)0x64,  /* [1226] */
    (xdc_Char)0x3a,  /* [1227] */
    (xdc_Char)0x20,  /* [1228] */
    (xdc_Char)0x43,  /* [1229] */
    (xdc_Char)0x61,  /* [1230] */
    (xdc_Char)0x6e,  /* [1231] */
    (xdc_Char)0x6e,  /* [1232] */
    (xdc_Char)0x6f,  /* [1233] */
    (xdc_Char)0x74,  /* [1234] */
    (xdc_Char)0x20,  /* [1235] */
    (xdc_Char)0x63,  /* [1236] */
    (xdc_Char)0x72,  /* [1237] */
    (xdc_Char)0x65,  /* [1238] */
    (xdc_Char)0x61,  /* [1239] */
    (xdc_Char)0x74,  /* [1240] */
    (xdc_Char)0x65,  /* [1241] */
    (xdc_Char)0x20,  /* [1242] */
    (xdc_Char)0x61,  /* [1243] */
    (xdc_Char)0x20,  /* [1244] */
    (xdc_Char)0x74,  /* [1245] */
    (xdc_Char)0x61,  /* [1246] */
    (xdc_Char)0x73,  /* [1247] */
    (xdc_Char)0x6b,  /* [1248] */
    (xdc_Char)0x20,  /* [1249] */
    (xdc_Char)0x77,  /* [1250] */
    (xdc_Char)0x68,  /* [1251] */
    (xdc_Char)0x65,  /* [1252] */
    (xdc_Char)0x6e,  /* [1253] */
    (xdc_Char)0x20,  /* [1254] */
    (xdc_Char)0x74,  /* [1255] */
    (xdc_Char)0x61,  /* [1256] */
    (xdc_Char)0x73,  /* [1257] */
    (xdc_Char)0x6b,  /* [1258] */
    (xdc_Char)0x69,  /* [1259] */
    (xdc_Char)0x6e,  /* [1260] */
    (xdc_Char)0x67,  /* [1261] */
    (xdc_Char)0x20,  /* [1262] */
    (xdc_Char)0x69,  /* [1263] */
    (xdc_Char)0x73,  /* [1264] */
    (xdc_Char)0x20,  /* [1265] */
    (xdc_Char)0x64,  /* [1266] */
    (xdc_Char)0x69,  /* [1267] */
    (xdc_Char)0x73,  /* [1268] */
    (xdc_Char)0x61,  /* [1269] */
    (xdc_Char)0x62,  /* [1270] */
    (xdc_Char)0x6c,  /* [1271] */
    (xdc_Char)0x65,  /* [1272] */
    (xdc_Char)0x64,  /* [1273] */
    (xdc_Char)0x2e,  /* [1274] */
    (xdc_Char)0x0,  /* [1275] */
    (xdc_Char)0x41,  /* [1276] */
    (xdc_Char)0x5f,  /* [1277] */
    (xdc_Char)0x62,  /* [1278] */
    (xdc_Char)0x61,  /* [1279] */
    (xdc_Char)0x64,  /* [1280] */
    (xdc_Char)0x50,  /* [1281] */
    (xdc_Char)0x72,  /* [1282] */
    (xdc_Char)0x69,  /* [1283] */
    (xdc_Char)0x6f,  /* [1284] */
    (xdc_Char)0x72,  /* [1285] */
    (xdc_Char)0x69,  /* [1286] */
    (xdc_Char)0x74,  /* [1287] */
    (xdc_Char)0x79,  /* [1288] */
    (xdc_Char)0x3a,  /* [1289] */
    (xdc_Char)0x20,  /* [1290] */
    (xdc_Char)0x41,  /* [1291] */
    (xdc_Char)0x6e,  /* [1292] */
    (xdc_Char)0x20,  /* [1293] */
    (xdc_Char)0x69,  /* [1294] */
    (xdc_Char)0x6e,  /* [1295] */
    (xdc_Char)0x76,  /* [1296] */
    (xdc_Char)0x61,  /* [1297] */
    (xdc_Char)0x6c,  /* [1298] */
    (xdc_Char)0x69,  /* [1299] */
    (xdc_Char)0x64,  /* [1300] */
    (xdc_Char)0x20,  /* [1301] */
    (xdc_Char)0x74,  /* [1302] */
    (xdc_Char)0x61,  /* [1303] */
    (xdc_Char)0x73,  /* [1304] */
    (xdc_Char)0x6b,  /* [1305] */
    (xdc_Char)0x20,  /* [1306] */
    (xdc_Char)0x70,  /* [1307] */
    (xdc_Char)0x72,  /* [1308] */
    (xdc_Char)0x69,  /* [1309] */
    (xdc_Char)0x6f,  /* [1310] */
    (xdc_Char)0x72,  /* [1311] */
    (xdc_Char)0x69,  /* [1312] */
    (xdc_Char)0x74,  /* [1313] */
    (xdc_Char)0x79,  /* [1314] */
    (xdc_Char)0x20,  /* [1315] */
    (xdc_Char)0x77,  /* [1316] */
    (xdc_Char)0x61,  /* [1317] */
    (xdc_Char)0x73,  /* [1318] */
    (xdc_Char)0x20,  /* [1319] */
    (xdc_Char)0x75,  /* [1320] */
    (xdc_Char)0x73,  /* [1321] */
    (xdc_Char)0x65,  /* [1322] */
    (xdc_Char)0x64,  /* [1323] */
    (xdc_Char)0x2e,  /* [1324] */
    (xdc_Char)0x0,  /* [1325] */
    (xdc_Char)0x41,  /* [1326] */
    (xdc_Char)0x5f,  /* [1327] */
    (xdc_Char)0x62,  /* [1328] */
    (xdc_Char)0x61,  /* [1329] */
    (xdc_Char)0x64,  /* [1330] */
    (xdc_Char)0x54,  /* [1331] */
    (xdc_Char)0x69,  /* [1332] */
    (xdc_Char)0x6d,  /* [1333] */
    (xdc_Char)0x65,  /* [1334] */
    (xdc_Char)0x6f,  /* [1335] */
    (xdc_Char)0x75,  /* [1336] */
    (xdc_Char)0x74,  /* [1337] */
    (xdc_Char)0x3a,  /* [1338] */
    (xdc_Char)0x20,  /* [1339] */
    (xdc_Char)0x43,  /* [1340] */
    (xdc_Char)0x61,  /* [1341] */
    (xdc_Char)0x6e,  /* [1342] */
    (xdc_Char)0x27,  /* [1343] */
    (xdc_Char)0x74,  /* [1344] */
    (xdc_Char)0x20,  /* [1345] */
    (xdc_Char)0x73,  /* [1346] */
    (xdc_Char)0x6c,  /* [1347] */
    (xdc_Char)0x65,  /* [1348] */
    (xdc_Char)0x65,  /* [1349] */
    (xdc_Char)0x70,  /* [1350] */
    (xdc_Char)0x20,  /* [1351] */
    (xdc_Char)0x46,  /* [1352] */
    (xdc_Char)0x4f,  /* [1353] */
    (xdc_Char)0x52,  /* [1354] */
    (xdc_Char)0x45,  /* [1355] */
    (xdc_Char)0x56,  /* [1356] */
    (xdc_Char)0x45,  /* [1357] */
    (xdc_Char)0x52,  /* [1358] */
    (xdc_Char)0x2e,  /* [1359] */
    (xdc_Char)0x0,  /* [1360] */
    (xdc_Char)0x41,  /* [1361] */
    (xdc_Char)0x5f,  /* [1362] */
    (xdc_Char)0x62,  /* [1363] */
    (xdc_Char)0x61,  /* [1364] */
    (xdc_Char)0x64,  /* [1365] */
    (xdc_Char)0x41,  /* [1366] */
    (xdc_Char)0x66,  /* [1367] */
    (xdc_Char)0x66,  /* [1368] */
    (xdc_Char)0x69,  /* [1369] */
    (xdc_Char)0x6e,  /* [1370] */
    (xdc_Char)0x69,  /* [1371] */
    (xdc_Char)0x74,  /* [1372] */
    (xdc_Char)0x79,  /* [1373] */
    (xdc_Char)0x3a,  /* [1374] */
    (xdc_Char)0x20,  /* [1375] */
    (xdc_Char)0x49,  /* [1376] */
    (xdc_Char)0x6e,  /* [1377] */
    (xdc_Char)0x76,  /* [1378] */
    (xdc_Char)0x61,  /* [1379] */
    (xdc_Char)0x6c,  /* [1380] */
    (xdc_Char)0x69,  /* [1381] */
    (xdc_Char)0x64,  /* [1382] */
    (xdc_Char)0x20,  /* [1383] */
    (xdc_Char)0x61,  /* [1384] */
    (xdc_Char)0x66,  /* [1385] */
    (xdc_Char)0x66,  /* [1386] */
    (xdc_Char)0x69,  /* [1387] */
    (xdc_Char)0x6e,  /* [1388] */
    (xdc_Char)0x69,  /* [1389] */
    (xdc_Char)0x74,  /* [1390] */
    (xdc_Char)0x79,  /* [1391] */
    (xdc_Char)0x2e,  /* [1392] */
    (xdc_Char)0x0,  /* [1393] */
    (xdc_Char)0x41,  /* [1394] */
    (xdc_Char)0x5f,  /* [1395] */
    (xdc_Char)0x7a,  /* [1396] */
    (xdc_Char)0x65,  /* [1397] */
    (xdc_Char)0x72,  /* [1398] */
    (xdc_Char)0x6f,  /* [1399] */
    (xdc_Char)0x54,  /* [1400] */
    (xdc_Char)0x69,  /* [1401] */
    (xdc_Char)0x6d,  /* [1402] */
    (xdc_Char)0x65,  /* [1403] */
    (xdc_Char)0x6f,  /* [1404] */
    (xdc_Char)0x75,  /* [1405] */
    (xdc_Char)0x74,  /* [1406] */
    (xdc_Char)0x3a,  /* [1407] */
    (xdc_Char)0x20,  /* [1408] */
    (xdc_Char)0x54,  /* [1409] */
    (xdc_Char)0x69,  /* [1410] */
    (xdc_Char)0x6d,  /* [1411] */
    (xdc_Char)0x65,  /* [1412] */
    (xdc_Char)0x6f,  /* [1413] */
    (xdc_Char)0x75,  /* [1414] */
    (xdc_Char)0x74,  /* [1415] */
    (xdc_Char)0x20,  /* [1416] */
    (xdc_Char)0x76,  /* [1417] */
    (xdc_Char)0x61,  /* [1418] */
    (xdc_Char)0x6c,  /* [1419] */
    (xdc_Char)0x75,  /* [1420] */
    (xdc_Char)0x65,  /* [1421] */
    (xdc_Char)0x20,  /* [1422] */
    (xdc_Char)0x61,  /* [1423] */
    (xdc_Char)0x6e,  /* [1424] */
    (xdc_Char)0x6e,  /* [1425] */
    (xdc_Char)0x6f,  /* [1426] */
    (xdc_Char)0x74,  /* [1427] */
    (xdc_Char)0x20,  /* [1428] */
    (xdc_Char)0x62,  /* [1429] */
    (xdc_Char)0x65,  /* [1430] */
    (xdc_Char)0x20,  /* [1431] */
    (xdc_Char)0x7a,  /* [1432] */
    (xdc_Char)0x65,  /* [1433] */
    (xdc_Char)0x72,  /* [1434] */
    (xdc_Char)0x6f,  /* [1435] */
    (xdc_Char)0x0,  /* [1436] */
    (xdc_Char)0x41,  /* [1437] */
    (xdc_Char)0x5f,  /* [1438] */
    (xdc_Char)0x69,  /* [1439] */
    (xdc_Char)0x6e,  /* [1440] */
    (xdc_Char)0x76,  /* [1441] */
    (xdc_Char)0x61,  /* [1442] */
    (xdc_Char)0x6c,  /* [1443] */
    (xdc_Char)0x69,  /* [1444] */
    (xdc_Char)0x64,  /* [1445] */
    (xdc_Char)0x4b,  /* [1446] */
    (xdc_Char)0x65,  /* [1447] */
    (xdc_Char)0x79,  /* [1448] */
    (xdc_Char)0x3a,  /* [1449] */
    (xdc_Char)0x20,  /* [1450] */
    (xdc_Char)0x74,  /* [1451] */
    (xdc_Char)0x68,  /* [1452] */
    (xdc_Char)0x65,  /* [1453] */
    (xdc_Char)0x20,  /* [1454] */
    (xdc_Char)0x6b,  /* [1455] */
    (xdc_Char)0x65,  /* [1456] */
    (xdc_Char)0x79,  /* [1457] */
    (xdc_Char)0x20,  /* [1458] */
    (xdc_Char)0x6d,  /* [1459] */
    (xdc_Char)0x75,  /* [1460] */
    (xdc_Char)0x73,  /* [1461] */
    (xdc_Char)0x74,  /* [1462] */
    (xdc_Char)0x20,  /* [1463] */
    (xdc_Char)0x62,  /* [1464] */
    (xdc_Char)0x65,  /* [1465] */
    (xdc_Char)0x20,  /* [1466] */
    (xdc_Char)0x73,  /* [1467] */
    (xdc_Char)0x65,  /* [1468] */
    (xdc_Char)0x74,  /* [1469] */
    (xdc_Char)0x20,  /* [1470] */
    (xdc_Char)0x74,  /* [1471] */
    (xdc_Char)0x6f,  /* [1472] */
    (xdc_Char)0x20,  /* [1473] */
    (xdc_Char)0x61,  /* [1474] */
    (xdc_Char)0x20,  /* [1475] */
    (xdc_Char)0x6e,  /* [1476] */
    (xdc_Char)0x6f,  /* [1477] */
    (xdc_Char)0x6e,  /* [1478] */
    (xdc_Char)0x2d,  /* [1479] */
    (xdc_Char)0x64,  /* [1480] */
    (xdc_Char)0x65,  /* [1481] */
    (xdc_Char)0x66,  /* [1482] */
    (xdc_Char)0x61,  /* [1483] */
    (xdc_Char)0x75,  /* [1484] */
    (xdc_Char)0x6c,  /* [1485] */
    (xdc_Char)0x74,  /* [1486] */
    (xdc_Char)0x20,  /* [1487] */
    (xdc_Char)0x76,  /* [1488] */
    (xdc_Char)0x61,  /* [1489] */
    (xdc_Char)0x6c,  /* [1490] */
    (xdc_Char)0x75,  /* [1491] */
    (xdc_Char)0x65,  /* [1492] */
    (xdc_Char)0x0,  /* [1493] */
    (xdc_Char)0x41,  /* [1494] */
    (xdc_Char)0x5f,  /* [1495] */
    (xdc_Char)0x62,  /* [1496] */
    (xdc_Char)0x61,  /* [1497] */
    (xdc_Char)0x64,  /* [1498] */
    (xdc_Char)0x43,  /* [1499] */
    (xdc_Char)0x6f,  /* [1500] */
    (xdc_Char)0x6e,  /* [1501] */
    (xdc_Char)0x74,  /* [1502] */
    (xdc_Char)0x65,  /* [1503] */
    (xdc_Char)0x78,  /* [1504] */
    (xdc_Char)0x74,  /* [1505] */
    (xdc_Char)0x3a,  /* [1506] */
    (xdc_Char)0x20,  /* [1507] */
    (xdc_Char)0x62,  /* [1508] */
    (xdc_Char)0x61,  /* [1509] */
    (xdc_Char)0x64,  /* [1510] */
    (xdc_Char)0x20,  /* [1511] */
    (xdc_Char)0x63,  /* [1512] */
    (xdc_Char)0x61,  /* [1513] */
    (xdc_Char)0x6c,  /* [1514] */
    (xdc_Char)0x6c,  /* [1515] */
    (xdc_Char)0x69,  /* [1516] */
    (xdc_Char)0x6e,  /* [1517] */
    (xdc_Char)0x67,  /* [1518] */
    (xdc_Char)0x20,  /* [1519] */
    (xdc_Char)0x63,  /* [1520] */
    (xdc_Char)0x6f,  /* [1521] */
    (xdc_Char)0x6e,  /* [1522] */
    (xdc_Char)0x74,  /* [1523] */
    (xdc_Char)0x65,  /* [1524] */
    (xdc_Char)0x78,  /* [1525] */
    (xdc_Char)0x74,  /* [1526] */
    (xdc_Char)0x2e,  /* [1527] */
    (xdc_Char)0x20,  /* [1528] */
    (xdc_Char)0x4d,  /* [1529] */
    (xdc_Char)0x61,  /* [1530] */
    (xdc_Char)0x79,  /* [1531] */
    (xdc_Char)0x20,  /* [1532] */
    (xdc_Char)0x6e,  /* [1533] */
    (xdc_Char)0x6f,  /* [1534] */
    (xdc_Char)0x74,  /* [1535] */
    (xdc_Char)0x20,  /* [1536] */
    (xdc_Char)0x62,  /* [1537] */
    (xdc_Char)0x65,  /* [1538] */
    (xdc_Char)0x20,  /* [1539] */
    (xdc_Char)0x65,  /* [1540] */
    (xdc_Char)0x6e,  /* [1541] */
    (xdc_Char)0x74,  /* [1542] */
    (xdc_Char)0x65,  /* [1543] */
    (xdc_Char)0x72,  /* [1544] */
    (xdc_Char)0x65,  /* [1545] */
    (xdc_Char)0x64,  /* [1546] */
    (xdc_Char)0x20,  /* [1547] */
    (xdc_Char)0x66,  /* [1548] */
    (xdc_Char)0x72,  /* [1549] */
    (xdc_Char)0x6f,  /* [1550] */
    (xdc_Char)0x6d,  /* [1551] */
    (xdc_Char)0x20,  /* [1552] */
    (xdc_Char)0x61,  /* [1553] */
    (xdc_Char)0x20,  /* [1554] */
    (xdc_Char)0x68,  /* [1555] */
    (xdc_Char)0x61,  /* [1556] */
    (xdc_Char)0x72,  /* [1557] */
    (xdc_Char)0x64,  /* [1558] */
    (xdc_Char)0x77,  /* [1559] */
    (xdc_Char)0x61,  /* [1560] */
    (xdc_Char)0x72,  /* [1561] */
    (xdc_Char)0x65,  /* [1562] */
    (xdc_Char)0x20,  /* [1563] */
    (xdc_Char)0x69,  /* [1564] */
    (xdc_Char)0x6e,  /* [1565] */
    (xdc_Char)0x74,  /* [1566] */
    (xdc_Char)0x65,  /* [1567] */
    (xdc_Char)0x72,  /* [1568] */
    (xdc_Char)0x72,  /* [1569] */
    (xdc_Char)0x75,  /* [1570] */
    (xdc_Char)0x70,  /* [1571] */
    (xdc_Char)0x74,  /* [1572] */
    (xdc_Char)0x20,  /* [1573] */
    (xdc_Char)0x74,  /* [1574] */
    (xdc_Char)0x68,  /* [1575] */
    (xdc_Char)0x72,  /* [1576] */
    (xdc_Char)0x65,  /* [1577] */
    (xdc_Char)0x61,  /* [1578] */
    (xdc_Char)0x64,  /* [1579] */
    (xdc_Char)0x2e,  /* [1580] */
    (xdc_Char)0x0,  /* [1581] */
    (xdc_Char)0x41,  /* [1582] */
    (xdc_Char)0x5f,  /* [1583] */
    (xdc_Char)0x62,  /* [1584] */
    (xdc_Char)0x61,  /* [1585] */
    (xdc_Char)0x64,  /* [1586] */
    (xdc_Char)0x43,  /* [1587] */
    (xdc_Char)0x6f,  /* [1588] */
    (xdc_Char)0x6e,  /* [1589] */
    (xdc_Char)0x74,  /* [1590] */
    (xdc_Char)0x65,  /* [1591] */
    (xdc_Char)0x78,  /* [1592] */
    (xdc_Char)0x74,  /* [1593] */
    (xdc_Char)0x3a,  /* [1594] */
    (xdc_Char)0x20,  /* [1595] */
    (xdc_Char)0x62,  /* [1596] */
    (xdc_Char)0x61,  /* [1597] */
    (xdc_Char)0x64,  /* [1598] */
    (xdc_Char)0x20,  /* [1599] */
    (xdc_Char)0x63,  /* [1600] */
    (xdc_Char)0x61,  /* [1601] */
    (xdc_Char)0x6c,  /* [1602] */
    (xdc_Char)0x6c,  /* [1603] */
    (xdc_Char)0x69,  /* [1604] */
    (xdc_Char)0x6e,  /* [1605] */
    (xdc_Char)0x67,  /* [1606] */
    (xdc_Char)0x20,  /* [1607] */
    (xdc_Char)0x63,  /* [1608] */
    (xdc_Char)0x6f,  /* [1609] */
    (xdc_Char)0x6e,  /* [1610] */
    (xdc_Char)0x74,  /* [1611] */
    (xdc_Char)0x65,  /* [1612] */
    (xdc_Char)0x78,  /* [1613] */
    (xdc_Char)0x74,  /* [1614] */
    (xdc_Char)0x2e,  /* [1615] */
    (xdc_Char)0x20,  /* [1616] */
    (xdc_Char)0x4d,  /* [1617] */
    (xdc_Char)0x61,  /* [1618] */
    (xdc_Char)0x79,  /* [1619] */
    (xdc_Char)0x20,  /* [1620] */
    (xdc_Char)0x6e,  /* [1621] */
    (xdc_Char)0x6f,  /* [1622] */
    (xdc_Char)0x74,  /* [1623] */
    (xdc_Char)0x20,  /* [1624] */
    (xdc_Char)0x62,  /* [1625] */
    (xdc_Char)0x65,  /* [1626] */
    (xdc_Char)0x20,  /* [1627] */
    (xdc_Char)0x65,  /* [1628] */
    (xdc_Char)0x6e,  /* [1629] */
    (xdc_Char)0x74,  /* [1630] */
    (xdc_Char)0x65,  /* [1631] */
    (xdc_Char)0x72,  /* [1632] */
    (xdc_Char)0x65,  /* [1633] */
    (xdc_Char)0x64,  /* [1634] */
    (xdc_Char)0x20,  /* [1635] */
    (xdc_Char)0x66,  /* [1636] */
    (xdc_Char)0x72,  /* [1637] */
    (xdc_Char)0x6f,  /* [1638] */
    (xdc_Char)0x6d,  /* [1639] */
    (xdc_Char)0x20,  /* [1640] */
    (xdc_Char)0x61,  /* [1641] */
    (xdc_Char)0x20,  /* [1642] */
    (xdc_Char)0x73,  /* [1643] */
    (xdc_Char)0x6f,  /* [1644] */
    (xdc_Char)0x66,  /* [1645] */
    (xdc_Char)0x74,  /* [1646] */
    (xdc_Char)0x77,  /* [1647] */
    (xdc_Char)0x61,  /* [1648] */
    (xdc_Char)0x72,  /* [1649] */
    (xdc_Char)0x65,  /* [1650] */
    (xdc_Char)0x20,  /* [1651] */
    (xdc_Char)0x6f,  /* [1652] */
    (xdc_Char)0x72,  /* [1653] */
    (xdc_Char)0x20,  /* [1654] */
    (xdc_Char)0x68,  /* [1655] */
    (xdc_Char)0x61,  /* [1656] */
    (xdc_Char)0x72,  /* [1657] */
    (xdc_Char)0x64,  /* [1658] */
    (xdc_Char)0x77,  /* [1659] */
    (xdc_Char)0x61,  /* [1660] */
    (xdc_Char)0x72,  /* [1661] */
    (xdc_Char)0x65,  /* [1662] */
    (xdc_Char)0x20,  /* [1663] */
    (xdc_Char)0x69,  /* [1664] */
    (xdc_Char)0x6e,  /* [1665] */
    (xdc_Char)0x74,  /* [1666] */
    (xdc_Char)0x65,  /* [1667] */
    (xdc_Char)0x72,  /* [1668] */
    (xdc_Char)0x72,  /* [1669] */
    (xdc_Char)0x75,  /* [1670] */
    (xdc_Char)0x70,  /* [1671] */
    (xdc_Char)0x74,  /* [1672] */
    (xdc_Char)0x20,  /* [1673] */
    (xdc_Char)0x74,  /* [1674] */
    (xdc_Char)0x68,  /* [1675] */
    (xdc_Char)0x72,  /* [1676] */
    (xdc_Char)0x65,  /* [1677] */
    (xdc_Char)0x61,  /* [1678] */
    (xdc_Char)0x64,  /* [1679] */
    (xdc_Char)0x2e,  /* [1680] */
    (xdc_Char)0x0,  /* [1681] */
    (xdc_Char)0x41,  /* [1682] */
    (xdc_Char)0x5f,  /* [1683] */
    (xdc_Char)0x62,  /* [1684] */
    (xdc_Char)0x61,  /* [1685] */
    (xdc_Char)0x64,  /* [1686] */
    (xdc_Char)0x43,  /* [1687] */
    (xdc_Char)0x6f,  /* [1688] */
    (xdc_Char)0x6e,  /* [1689] */
    (xdc_Char)0x74,  /* [1690] */
    (xdc_Char)0x65,  /* [1691] */
    (xdc_Char)0x78,  /* [1692] */
    (xdc_Char)0x74,  /* [1693] */
    (xdc_Char)0x3a,  /* [1694] */
    (xdc_Char)0x20,  /* [1695] */
    (xdc_Char)0x62,  /* [1696] */
    (xdc_Char)0x61,  /* [1697] */
    (xdc_Char)0x64,  /* [1698] */
    (xdc_Char)0x20,  /* [1699] */
    (xdc_Char)0x63,  /* [1700] */
    (xdc_Char)0x61,  /* [1701] */
    (xdc_Char)0x6c,  /* [1702] */
    (xdc_Char)0x6c,  /* [1703] */
    (xdc_Char)0x69,  /* [1704] */
    (xdc_Char)0x6e,  /* [1705] */
    (xdc_Char)0x67,  /* [1706] */
    (xdc_Char)0x20,  /* [1707] */
    (xdc_Char)0x63,  /* [1708] */
    (xdc_Char)0x6f,  /* [1709] */
    (xdc_Char)0x6e,  /* [1710] */
    (xdc_Char)0x74,  /* [1711] */
    (xdc_Char)0x65,  /* [1712] */
    (xdc_Char)0x78,  /* [1713] */
    (xdc_Char)0x74,  /* [1714] */
    (xdc_Char)0x2e,  /* [1715] */
    (xdc_Char)0x20,  /* [1716] */
    (xdc_Char)0x53,  /* [1717] */
    (xdc_Char)0x65,  /* [1718] */
    (xdc_Char)0x65,  /* [1719] */
    (xdc_Char)0x20,  /* [1720] */
    (xdc_Char)0x47,  /* [1721] */
    (xdc_Char)0x61,  /* [1722] */
    (xdc_Char)0x74,  /* [1723] */
    (xdc_Char)0x65,  /* [1724] */
    (xdc_Char)0x4d,  /* [1725] */
    (xdc_Char)0x75,  /* [1726] */
    (xdc_Char)0x74,  /* [1727] */
    (xdc_Char)0x65,  /* [1728] */
    (xdc_Char)0x78,  /* [1729] */
    (xdc_Char)0x50,  /* [1730] */
    (xdc_Char)0x72,  /* [1731] */
    (xdc_Char)0x69,  /* [1732] */
    (xdc_Char)0x20,  /* [1733] */
    (xdc_Char)0x41,  /* [1734] */
    (xdc_Char)0x50,  /* [1735] */
    (xdc_Char)0x49,  /* [1736] */
    (xdc_Char)0x20,  /* [1737] */
    (xdc_Char)0x64,  /* [1738] */
    (xdc_Char)0x6f,  /* [1739] */
    (xdc_Char)0x63,  /* [1740] */
    (xdc_Char)0x20,  /* [1741] */
    (xdc_Char)0x66,  /* [1742] */
    (xdc_Char)0x6f,  /* [1743] */
    (xdc_Char)0x72,  /* [1744] */
    (xdc_Char)0x20,  /* [1745] */
    (xdc_Char)0x64,  /* [1746] */
    (xdc_Char)0x65,  /* [1747] */
    (xdc_Char)0x74,  /* [1748] */
    (xdc_Char)0x61,  /* [1749] */
    (xdc_Char)0x69,  /* [1750] */
    (xdc_Char)0x6c,  /* [1751] */
    (xdc_Char)0x73,  /* [1752] */
    (xdc_Char)0x2e,  /* [1753] */
    (xdc_Char)0x0,  /* [1754] */
    (xdc_Char)0x41,  /* [1755] */
    (xdc_Char)0x5f,  /* [1756] */
    (xdc_Char)0x62,  /* [1757] */
    (xdc_Char)0x61,  /* [1758] */
    (xdc_Char)0x64,  /* [1759] */
    (xdc_Char)0x43,  /* [1760] */
    (xdc_Char)0x6f,  /* [1761] */
    (xdc_Char)0x6e,  /* [1762] */
    (xdc_Char)0x74,  /* [1763] */
    (xdc_Char)0x65,  /* [1764] */
    (xdc_Char)0x78,  /* [1765] */
    (xdc_Char)0x74,  /* [1766] */
    (xdc_Char)0x3a,  /* [1767] */
    (xdc_Char)0x20,  /* [1768] */
    (xdc_Char)0x62,  /* [1769] */
    (xdc_Char)0x61,  /* [1770] */
    (xdc_Char)0x64,  /* [1771] */
    (xdc_Char)0x20,  /* [1772] */
    (xdc_Char)0x63,  /* [1773] */
    (xdc_Char)0x61,  /* [1774] */
    (xdc_Char)0x6c,  /* [1775] */
    (xdc_Char)0x6c,  /* [1776] */
    (xdc_Char)0x69,  /* [1777] */
    (xdc_Char)0x6e,  /* [1778] */
    (xdc_Char)0x67,  /* [1779] */
    (xdc_Char)0x20,  /* [1780] */
    (xdc_Char)0x63,  /* [1781] */
    (xdc_Char)0x6f,  /* [1782] */
    (xdc_Char)0x6e,  /* [1783] */
    (xdc_Char)0x74,  /* [1784] */
    (xdc_Char)0x65,  /* [1785] */
    (xdc_Char)0x78,  /* [1786] */
    (xdc_Char)0x74,  /* [1787] */
    (xdc_Char)0x2e,  /* [1788] */
    (xdc_Char)0x20,  /* [1789] */
    (xdc_Char)0x53,  /* [1790] */
    (xdc_Char)0x65,  /* [1791] */
    (xdc_Char)0x65,  /* [1792] */
    (xdc_Char)0x20,  /* [1793] */
    (xdc_Char)0x47,  /* [1794] */
    (xdc_Char)0x61,  /* [1795] */
    (xdc_Char)0x74,  /* [1796] */
    (xdc_Char)0x65,  /* [1797] */
    (xdc_Char)0x4d,  /* [1798] */
    (xdc_Char)0x75,  /* [1799] */
    (xdc_Char)0x74,  /* [1800] */
    (xdc_Char)0x65,  /* [1801] */
    (xdc_Char)0x78,  /* [1802] */
    (xdc_Char)0x20,  /* [1803] */
    (xdc_Char)0x41,  /* [1804] */
    (xdc_Char)0x50,  /* [1805] */
    (xdc_Char)0x49,  /* [1806] */
    (xdc_Char)0x20,  /* [1807] */
    (xdc_Char)0x64,  /* [1808] */
    (xdc_Char)0x6f,  /* [1809] */
    (xdc_Char)0x63,  /* [1810] */
    (xdc_Char)0x20,  /* [1811] */
    (xdc_Char)0x66,  /* [1812] */
    (xdc_Char)0x6f,  /* [1813] */
    (xdc_Char)0x72,  /* [1814] */
    (xdc_Char)0x20,  /* [1815] */
    (xdc_Char)0x64,  /* [1816] */
    (xdc_Char)0x65,  /* [1817] */
    (xdc_Char)0x74,  /* [1818] */
    (xdc_Char)0x61,  /* [1819] */
    (xdc_Char)0x69,  /* [1820] */
    (xdc_Char)0x6c,  /* [1821] */
    (xdc_Char)0x73,  /* [1822] */
    (xdc_Char)0x2e,  /* [1823] */
    (xdc_Char)0x0,  /* [1824] */
    (xdc_Char)0x41,  /* [1825] */
    (xdc_Char)0x5f,  /* [1826] */
    (xdc_Char)0x6e,  /* [1827] */
    (xdc_Char)0x6f,  /* [1828] */
    (xdc_Char)0x74,  /* [1829] */
    (xdc_Char)0x41,  /* [1830] */
    (xdc_Char)0x76,  /* [1831] */
    (xdc_Char)0x61,  /* [1832] */
    (xdc_Char)0x69,  /* [1833] */
    (xdc_Char)0x6c,  /* [1834] */
    (xdc_Char)0x61,  /* [1835] */
    (xdc_Char)0x62,  /* [1836] */
    (xdc_Char)0x6c,  /* [1837] */
    (xdc_Char)0x65,  /* [1838] */
    (xdc_Char)0x3a,  /* [1839] */
    (xdc_Char)0x20,  /* [1840] */
    (xdc_Char)0x73,  /* [1841] */
    (xdc_Char)0x74,  /* [1842] */
    (xdc_Char)0x61,  /* [1843] */
    (xdc_Char)0x74,  /* [1844] */
    (xdc_Char)0x69,  /* [1845] */
    (xdc_Char)0x63,  /* [1846] */
    (xdc_Char)0x20,  /* [1847] */
    (xdc_Char)0x63,  /* [1848] */
    (xdc_Char)0x72,  /* [1849] */
    (xdc_Char)0x65,  /* [1850] */
    (xdc_Char)0x61,  /* [1851] */
    (xdc_Char)0x74,  /* [1852] */
    (xdc_Char)0x65,  /* [1853] */
    (xdc_Char)0x64,  /* [1854] */
    (xdc_Char)0x20,  /* [1855] */
    (xdc_Char)0x74,  /* [1856] */
    (xdc_Char)0x69,  /* [1857] */
    (xdc_Char)0x6d,  /* [1858] */
    (xdc_Char)0x65,  /* [1859] */
    (xdc_Char)0x72,  /* [1860] */
    (xdc_Char)0x20,  /* [1861] */
    (xdc_Char)0x6e,  /* [1862] */
    (xdc_Char)0x6f,  /* [1863] */
    (xdc_Char)0x74,  /* [1864] */
    (xdc_Char)0x20,  /* [1865] */
    (xdc_Char)0x61,  /* [1866] */
    (xdc_Char)0x76,  /* [1867] */
    (xdc_Char)0x61,  /* [1868] */
    (xdc_Char)0x69,  /* [1869] */
    (xdc_Char)0x6c,  /* [1870] */
    (xdc_Char)0x61,  /* [1871] */
    (xdc_Char)0x62,  /* [1872] */
    (xdc_Char)0x6c,  /* [1873] */
    (xdc_Char)0x65,  /* [1874] */
    (xdc_Char)0x0,  /* [1875] */
    (xdc_Char)0x62,  /* [1876] */
    (xdc_Char)0x75,  /* [1877] */
    (xdc_Char)0x66,  /* [1878] */
    (xdc_Char)0x20,  /* [1879] */
    (xdc_Char)0x70,  /* [1880] */
    (xdc_Char)0x61,  /* [1881] */
    (xdc_Char)0x72,  /* [1882] */
    (xdc_Char)0x61,  /* [1883] */
    (xdc_Char)0x6d,  /* [1884] */
    (xdc_Char)0x65,  /* [1885] */
    (xdc_Char)0x74,  /* [1886] */
    (xdc_Char)0x65,  /* [1887] */
    (xdc_Char)0x72,  /* [1888] */
    (xdc_Char)0x20,  /* [1889] */
    (xdc_Char)0x63,  /* [1890] */
    (xdc_Char)0x61,  /* [1891] */
    (xdc_Char)0x6e,  /* [1892] */
    (xdc_Char)0x6e,  /* [1893] */
    (xdc_Char)0x6f,  /* [1894] */
    (xdc_Char)0x74,  /* [1895] */
    (xdc_Char)0x20,  /* [1896] */
    (xdc_Char)0x62,  /* [1897] */
    (xdc_Char)0x65,  /* [1898] */
    (xdc_Char)0x20,  /* [1899] */
    (xdc_Char)0x6e,  /* [1900] */
    (xdc_Char)0x75,  /* [1901] */
    (xdc_Char)0x6c,  /* [1902] */
    (xdc_Char)0x6c,  /* [1903] */
    (xdc_Char)0x0,  /* [1904] */
    (xdc_Char)0x62,  /* [1905] */
    (xdc_Char)0x75,  /* [1906] */
    (xdc_Char)0x66,  /* [1907] */
    (xdc_Char)0x20,  /* [1908] */
    (xdc_Char)0x6e,  /* [1909] */
    (xdc_Char)0x6f,  /* [1910] */
    (xdc_Char)0x74,  /* [1911] */
    (xdc_Char)0x20,  /* [1912] */
    (xdc_Char)0x70,  /* [1913] */
    (xdc_Char)0x72,  /* [1914] */
    (xdc_Char)0x6f,  /* [1915] */
    (xdc_Char)0x70,  /* [1916] */
    (xdc_Char)0x65,  /* [1917] */
    (xdc_Char)0x72,  /* [1918] */
    (xdc_Char)0x6c,  /* [1919] */
    (xdc_Char)0x79,  /* [1920] */
    (xdc_Char)0x20,  /* [1921] */
    (xdc_Char)0x61,  /* [1922] */
    (xdc_Char)0x6c,  /* [1923] */
    (xdc_Char)0x69,  /* [1924] */
    (xdc_Char)0x67,  /* [1925] */
    (xdc_Char)0x6e,  /* [1926] */
    (xdc_Char)0x65,  /* [1927] */
    (xdc_Char)0x64,  /* [1928] */
    (xdc_Char)0x0,  /* [1929] */
    (xdc_Char)0x61,  /* [1930] */
    (xdc_Char)0x6c,  /* [1931] */
    (xdc_Char)0x69,  /* [1932] */
    (xdc_Char)0x67,  /* [1933] */
    (xdc_Char)0x6e,  /* [1934] */
    (xdc_Char)0x20,  /* [1935] */
    (xdc_Char)0x70,  /* [1936] */
    (xdc_Char)0x61,  /* [1937] */
    (xdc_Char)0x72,  /* [1938] */
    (xdc_Char)0x61,  /* [1939] */
    (xdc_Char)0x6d,  /* [1940] */
    (xdc_Char)0x65,  /* [1941] */
    (xdc_Char)0x74,  /* [1942] */
    (xdc_Char)0x65,  /* [1943] */
    (xdc_Char)0x72,  /* [1944] */
    (xdc_Char)0x20,  /* [1945] */
    (xdc_Char)0x6d,  /* [1946] */
    (xdc_Char)0x75,  /* [1947] */
    (xdc_Char)0x73,  /* [1948] */
    (xdc_Char)0x74,  /* [1949] */
    (xdc_Char)0x20,  /* [1950] */
    (xdc_Char)0x62,  /* [1951] */
    (xdc_Char)0x65,  /* [1952] */
    (xdc_Char)0x20,  /* [1953] */
    (xdc_Char)0x30,  /* [1954] */
    (xdc_Char)0x20,  /* [1955] */
    (xdc_Char)0x6f,  /* [1956] */
    (xdc_Char)0x72,  /* [1957] */
    (xdc_Char)0x20,  /* [1958] */
    (xdc_Char)0x61,  /* [1959] */
    (xdc_Char)0x20,  /* [1960] */
    (xdc_Char)0x70,  /* [1961] */
    (xdc_Char)0x6f,  /* [1962] */
    (xdc_Char)0x77,  /* [1963] */
    (xdc_Char)0x65,  /* [1964] */
    (xdc_Char)0x72,  /* [1965] */
    (xdc_Char)0x20,  /* [1966] */
    (xdc_Char)0x6f,  /* [1967] */
    (xdc_Char)0x66,  /* [1968] */
    (xdc_Char)0x20,  /* [1969] */
    (xdc_Char)0x32,  /* [1970] */
    (xdc_Char)0x20,  /* [1971] */
    (xdc_Char)0x3e,  /* [1972] */
    (xdc_Char)0x3d,  /* [1973] */
    (xdc_Char)0x20,  /* [1974] */
    (xdc_Char)0x74,  /* [1975] */
    (xdc_Char)0x68,  /* [1976] */
    (xdc_Char)0x65,  /* [1977] */
    (xdc_Char)0x20,  /* [1978] */
    (xdc_Char)0x76,  /* [1979] */
    (xdc_Char)0x61,  /* [1980] */
    (xdc_Char)0x6c,  /* [1981] */
    (xdc_Char)0x75,  /* [1982] */
    (xdc_Char)0x65,  /* [1983] */
    (xdc_Char)0x20,  /* [1984] */
    (xdc_Char)0x6f,  /* [1985] */
    (xdc_Char)0x66,  /* [1986] */
    (xdc_Char)0x20,  /* [1987] */
    (xdc_Char)0x4d,  /* [1988] */
    (xdc_Char)0x65,  /* [1989] */
    (xdc_Char)0x6d,  /* [1990] */
    (xdc_Char)0x6f,  /* [1991] */
    (xdc_Char)0x72,  /* [1992] */
    (xdc_Char)0x79,  /* [1993] */
    (xdc_Char)0x5f,  /* [1994] */
    (xdc_Char)0x67,  /* [1995] */
    (xdc_Char)0x65,  /* [1996] */
    (xdc_Char)0x74,  /* [1997] */
    (xdc_Char)0x4d,  /* [1998] */
    (xdc_Char)0x61,  /* [1999] */
    (xdc_Char)0x78,  /* [2000] */
    (xdc_Char)0x44,  /* [2001] */
    (xdc_Char)0x65,  /* [2002] */
    (xdc_Char)0x66,  /* [2003] */
    (xdc_Char)0x61,  /* [2004] */
    (xdc_Char)0x75,  /* [2005] */
    (xdc_Char)0x6c,  /* [2006] */
    (xdc_Char)0x74,  /* [2007] */
    (xdc_Char)0x54,  /* [2008] */
    (xdc_Char)0x79,  /* [2009] */
    (xdc_Char)0x70,  /* [2010] */
    (xdc_Char)0x65,  /* [2011] */
    (xdc_Char)0x41,  /* [2012] */
    (xdc_Char)0x6c,  /* [2013] */
    (xdc_Char)0x69,  /* [2014] */
    (xdc_Char)0x67,  /* [2015] */
    (xdc_Char)0x6e,  /* [2016] */
    (xdc_Char)0x28,  /* [2017] */
    (xdc_Char)0x29,  /* [2018] */
    (xdc_Char)0x0,  /* [2019] */
    (xdc_Char)0x61,  /* [2020] */
    (xdc_Char)0x6c,  /* [2021] */
    (xdc_Char)0x69,  /* [2022] */
    (xdc_Char)0x67,  /* [2023] */
    (xdc_Char)0x6e,  /* [2024] */
    (xdc_Char)0x20,  /* [2025] */
    (xdc_Char)0x70,  /* [2026] */
    (xdc_Char)0x61,  /* [2027] */
    (xdc_Char)0x72,  /* [2028] */
    (xdc_Char)0x61,  /* [2029] */
    (xdc_Char)0x6d,  /* [2030] */
    (xdc_Char)0x65,  /* [2031] */
    (xdc_Char)0x74,  /* [2032] */
    (xdc_Char)0x65,  /* [2033] */
    (xdc_Char)0x72,  /* [2034] */
    (xdc_Char)0x20,  /* [2035] */
    (xdc_Char)0x31,  /* [2036] */
    (xdc_Char)0x29,  /* [2037] */
    (xdc_Char)0x20,  /* [2038] */
    (xdc_Char)0x6d,  /* [2039] */
    (xdc_Char)0x75,  /* [2040] */
    (xdc_Char)0x73,  /* [2041] */
    (xdc_Char)0x74,  /* [2042] */
    (xdc_Char)0x20,  /* [2043] */
    (xdc_Char)0x62,  /* [2044] */
    (xdc_Char)0x65,  /* [2045] */
    (xdc_Char)0x20,  /* [2046] */
    (xdc_Char)0x30,  /* [2047] */
    (xdc_Char)0x20,  /* [2048] */
    (xdc_Char)0x6f,  /* [2049] */
    (xdc_Char)0x72,  /* [2050] */
    (xdc_Char)0x20,  /* [2051] */
    (xdc_Char)0x61,  /* [2052] */
    (xdc_Char)0x20,  /* [2053] */
    (xdc_Char)0x70,  /* [2054] */
    (xdc_Char)0x6f,  /* [2055] */
    (xdc_Char)0x77,  /* [2056] */
    (xdc_Char)0x65,  /* [2057] */
    (xdc_Char)0x72,  /* [2058] */
    (xdc_Char)0x20,  /* [2059] */
    (xdc_Char)0x6f,  /* [2060] */
    (xdc_Char)0x66,  /* [2061] */
    (xdc_Char)0x20,  /* [2062] */
    (xdc_Char)0x32,  /* [2063] */
    (xdc_Char)0x20,  /* [2064] */
    (xdc_Char)0x61,  /* [2065] */
    (xdc_Char)0x6e,  /* [2066] */
    (xdc_Char)0x64,  /* [2067] */
    (xdc_Char)0x20,  /* [2068] */
    (xdc_Char)0x32,  /* [2069] */
    (xdc_Char)0x29,  /* [2070] */
    (xdc_Char)0x20,  /* [2071] */
    (xdc_Char)0x6e,  /* [2072] */
    (xdc_Char)0x6f,  /* [2073] */
    (xdc_Char)0x74,  /* [2074] */
    (xdc_Char)0x20,  /* [2075] */
    (xdc_Char)0x67,  /* [2076] */
    (xdc_Char)0x72,  /* [2077] */
    (xdc_Char)0x65,  /* [2078] */
    (xdc_Char)0x61,  /* [2079] */
    (xdc_Char)0x74,  /* [2080] */
    (xdc_Char)0x65,  /* [2081] */
    (xdc_Char)0x72,  /* [2082] */
    (xdc_Char)0x20,  /* [2083] */
    (xdc_Char)0x74,  /* [2084] */
    (xdc_Char)0x68,  /* [2085] */
    (xdc_Char)0x61,  /* [2086] */
    (xdc_Char)0x6e,  /* [2087] */
    (xdc_Char)0x20,  /* [2088] */
    (xdc_Char)0x74,  /* [2089] */
    (xdc_Char)0x68,  /* [2090] */
    (xdc_Char)0x65,  /* [2091] */
    (xdc_Char)0x20,  /* [2092] */
    (xdc_Char)0x68,  /* [2093] */
    (xdc_Char)0x65,  /* [2094] */
    (xdc_Char)0x61,  /* [2095] */
    (xdc_Char)0x70,  /* [2096] */
    (xdc_Char)0x73,  /* [2097] */
    (xdc_Char)0x20,  /* [2098] */
    (xdc_Char)0x61,  /* [2099] */
    (xdc_Char)0x6c,  /* [2100] */
    (xdc_Char)0x69,  /* [2101] */
    (xdc_Char)0x67,  /* [2102] */
    (xdc_Char)0x6e,  /* [2103] */
    (xdc_Char)0x6d,  /* [2104] */
    (xdc_Char)0x65,  /* [2105] */
    (xdc_Char)0x6e,  /* [2106] */
    (xdc_Char)0x74,  /* [2107] */
    (xdc_Char)0x0,  /* [2108] */
    (xdc_Char)0x62,  /* [2109] */
    (xdc_Char)0x6c,  /* [2110] */
    (xdc_Char)0x6f,  /* [2111] */
    (xdc_Char)0x63,  /* [2112] */
    (xdc_Char)0x6b,  /* [2113] */
    (xdc_Char)0x53,  /* [2114] */
    (xdc_Char)0x69,  /* [2115] */
    (xdc_Char)0x7a,  /* [2116] */
    (xdc_Char)0x65,  /* [2117] */
    (xdc_Char)0x20,  /* [2118] */
    (xdc_Char)0x63,  /* [2119] */
    (xdc_Char)0x61,  /* [2120] */
    (xdc_Char)0x6e,  /* [2121] */
    (xdc_Char)0x6e,  /* [2122] */
    (xdc_Char)0x6f,  /* [2123] */
    (xdc_Char)0x74,  /* [2124] */
    (xdc_Char)0x20,  /* [2125] */
    (xdc_Char)0x62,  /* [2126] */
    (xdc_Char)0x65,  /* [2127] */
    (xdc_Char)0x20,  /* [2128] */
    (xdc_Char)0x7a,  /* [2129] */
    (xdc_Char)0x65,  /* [2130] */
    (xdc_Char)0x72,  /* [2131] */
    (xdc_Char)0x6f,  /* [2132] */
    (xdc_Char)0x0,  /* [2133] */
    (xdc_Char)0x6e,  /* [2134] */
    (xdc_Char)0x75,  /* [2135] */
    (xdc_Char)0x6d,  /* [2136] */
    (xdc_Char)0x42,  /* [2137] */
    (xdc_Char)0x6c,  /* [2138] */
    (xdc_Char)0x6f,  /* [2139] */
    (xdc_Char)0x63,  /* [2140] */
    (xdc_Char)0x6b,  /* [2141] */
    (xdc_Char)0x73,  /* [2142] */
    (xdc_Char)0x20,  /* [2143] */
    (xdc_Char)0x63,  /* [2144] */
    (xdc_Char)0x61,  /* [2145] */
    (xdc_Char)0x6e,  /* [2146] */
    (xdc_Char)0x6e,  /* [2147] */
    (xdc_Char)0x6f,  /* [2148] */
    (xdc_Char)0x74,  /* [2149] */
    (xdc_Char)0x20,  /* [2150] */
    (xdc_Char)0x62,  /* [2151] */
    (xdc_Char)0x65,  /* [2152] */
    (xdc_Char)0x20,  /* [2153] */
    (xdc_Char)0x7a,  /* [2154] */
    (xdc_Char)0x65,  /* [2155] */
    (xdc_Char)0x72,  /* [2156] */
    (xdc_Char)0x6f,  /* [2157] */
    (xdc_Char)0x0,  /* [2158] */
    (xdc_Char)0x62,  /* [2159] */
    (xdc_Char)0x75,  /* [2160] */
    (xdc_Char)0x66,  /* [2161] */
    (xdc_Char)0x53,  /* [2162] */
    (xdc_Char)0x69,  /* [2163] */
    (xdc_Char)0x7a,  /* [2164] */
    (xdc_Char)0x65,  /* [2165] */
    (xdc_Char)0x20,  /* [2166] */
    (xdc_Char)0x63,  /* [2167] */
    (xdc_Char)0x61,  /* [2168] */
    (xdc_Char)0x6e,  /* [2169] */
    (xdc_Char)0x6e,  /* [2170] */
    (xdc_Char)0x6f,  /* [2171] */
    (xdc_Char)0x74,  /* [2172] */
    (xdc_Char)0x20,  /* [2173] */
    (xdc_Char)0x62,  /* [2174] */
    (xdc_Char)0x65,  /* [2175] */
    (xdc_Char)0x20,  /* [2176] */
    (xdc_Char)0x7a,  /* [2177] */
    (xdc_Char)0x65,  /* [2178] */
    (xdc_Char)0x72,  /* [2179] */
    (xdc_Char)0x6f,  /* [2180] */
    (xdc_Char)0x0,  /* [2181] */
    (xdc_Char)0x48,  /* [2182] */
    (xdc_Char)0x65,  /* [2183] */
    (xdc_Char)0x61,  /* [2184] */
    (xdc_Char)0x70,  /* [2185] */
    (xdc_Char)0x42,  /* [2186] */
    (xdc_Char)0x75,  /* [2187] */
    (xdc_Char)0x66,  /* [2188] */
    (xdc_Char)0x5f,  /* [2189] */
    (xdc_Char)0x63,  /* [2190] */
    (xdc_Char)0x72,  /* [2191] */
    (xdc_Char)0x65,  /* [2192] */
    (xdc_Char)0x61,  /* [2193] */
    (xdc_Char)0x74,  /* [2194] */
    (xdc_Char)0x65,  /* [2195] */
    (xdc_Char)0x27,  /* [2196] */
    (xdc_Char)0x73,  /* [2197] */
    (xdc_Char)0x20,  /* [2198] */
    (xdc_Char)0x62,  /* [2199] */
    (xdc_Char)0x75,  /* [2200] */
    (xdc_Char)0x66,  /* [2201] */
    (xdc_Char)0x53,  /* [2202] */
    (xdc_Char)0x69,  /* [2203] */
    (xdc_Char)0x7a,  /* [2204] */
    (xdc_Char)0x65,  /* [2205] */
    (xdc_Char)0x20,  /* [2206] */
    (xdc_Char)0x70,  /* [2207] */
    (xdc_Char)0x61,  /* [2208] */
    (xdc_Char)0x72,  /* [2209] */
    (xdc_Char)0x61,  /* [2210] */
    (xdc_Char)0x6d,  /* [2211] */
    (xdc_Char)0x65,  /* [2212] */
    (xdc_Char)0x74,  /* [2213] */
    (xdc_Char)0x65,  /* [2214] */
    (xdc_Char)0x72,  /* [2215] */
    (xdc_Char)0x20,  /* [2216] */
    (xdc_Char)0x69,  /* [2217] */
    (xdc_Char)0x73,  /* [2218] */
    (xdc_Char)0x20,  /* [2219] */
    (xdc_Char)0x69,  /* [2220] */
    (xdc_Char)0x6e,  /* [2221] */
    (xdc_Char)0x76,  /* [2222] */
    (xdc_Char)0x61,  /* [2223] */
    (xdc_Char)0x6c,  /* [2224] */
    (xdc_Char)0x69,  /* [2225] */
    (xdc_Char)0x64,  /* [2226] */
    (xdc_Char)0x20,  /* [2227] */
    (xdc_Char)0x28,  /* [2228] */
    (xdc_Char)0x74,  /* [2229] */
    (xdc_Char)0x6f,  /* [2230] */
    (xdc_Char)0x6f,  /* [2231] */
    (xdc_Char)0x20,  /* [2232] */
    (xdc_Char)0x73,  /* [2233] */
    (xdc_Char)0x6d,  /* [2234] */
    (xdc_Char)0x61,  /* [2235] */
    (xdc_Char)0x6c,  /* [2236] */
    (xdc_Char)0x6c,  /* [2237] */
    (xdc_Char)0x29,  /* [2238] */
    (xdc_Char)0x0,  /* [2239] */
    (xdc_Char)0x43,  /* [2240] */
    (xdc_Char)0x61,  /* [2241] */
    (xdc_Char)0x6e,  /* [2242] */
    (xdc_Char)0x6e,  /* [2243] */
    (xdc_Char)0x6f,  /* [2244] */
    (xdc_Char)0x74,  /* [2245] */
    (xdc_Char)0x20,  /* [2246] */
    (xdc_Char)0x63,  /* [2247] */
    (xdc_Char)0x61,  /* [2248] */
    (xdc_Char)0x6c,  /* [2249] */
    (xdc_Char)0x6c,  /* [2250] */
    (xdc_Char)0x20,  /* [2251] */
    (xdc_Char)0x48,  /* [2252] */
    (xdc_Char)0x65,  /* [2253] */
    (xdc_Char)0x61,  /* [2254] */
    (xdc_Char)0x70,  /* [2255] */
    (xdc_Char)0x42,  /* [2256] */
    (xdc_Char)0x75,  /* [2257] */
    (xdc_Char)0x66,  /* [2258] */
    (xdc_Char)0x5f,  /* [2259] */
    (xdc_Char)0x66,  /* [2260] */
    (xdc_Char)0x72,  /* [2261] */
    (xdc_Char)0x65,  /* [2262] */
    (xdc_Char)0x65,  /* [2263] */
    (xdc_Char)0x20,  /* [2264] */
    (xdc_Char)0x77,  /* [2265] */
    (xdc_Char)0x68,  /* [2266] */
    (xdc_Char)0x65,  /* [2267] */
    (xdc_Char)0x6e,  /* [2268] */
    (xdc_Char)0x20,  /* [2269] */
    (xdc_Char)0x6e,  /* [2270] */
    (xdc_Char)0x6f,  /* [2271] */
    (xdc_Char)0x20,  /* [2272] */
    (xdc_Char)0x62,  /* [2273] */
    (xdc_Char)0x6c,  /* [2274] */
    (xdc_Char)0x6f,  /* [2275] */
    (xdc_Char)0x63,  /* [2276] */
    (xdc_Char)0x6b,  /* [2277] */
    (xdc_Char)0x73,  /* [2278] */
    (xdc_Char)0x20,  /* [2279] */
    (xdc_Char)0x68,  /* [2280] */
    (xdc_Char)0x61,  /* [2281] */
    (xdc_Char)0x76,  /* [2282] */
    (xdc_Char)0x65,  /* [2283] */
    (xdc_Char)0x20,  /* [2284] */
    (xdc_Char)0x62,  /* [2285] */
    (xdc_Char)0x65,  /* [2286] */
    (xdc_Char)0x65,  /* [2287] */
    (xdc_Char)0x6e,  /* [2288] */
    (xdc_Char)0x20,  /* [2289] */
    (xdc_Char)0x61,  /* [2290] */
    (xdc_Char)0x6c,  /* [2291] */
    (xdc_Char)0x6c,  /* [2292] */
    (xdc_Char)0x6f,  /* [2293] */
    (xdc_Char)0x63,  /* [2294] */
    (xdc_Char)0x61,  /* [2295] */
    (xdc_Char)0x74,  /* [2296] */
    (xdc_Char)0x65,  /* [2297] */
    (xdc_Char)0x64,  /* [2298] */
    (xdc_Char)0x0,  /* [2299] */
    (xdc_Char)0x41,  /* [2300] */
    (xdc_Char)0x5f,  /* [2301] */
    (xdc_Char)0x69,  /* [2302] */
    (xdc_Char)0x6e,  /* [2303] */
    (xdc_Char)0x76,  /* [2304] */
    (xdc_Char)0x61,  /* [2305] */
    (xdc_Char)0x6c,  /* [2306] */
    (xdc_Char)0x69,  /* [2307] */
    (xdc_Char)0x64,  /* [2308] */
    (xdc_Char)0x46,  /* [2309] */
    (xdc_Char)0x72,  /* [2310] */
    (xdc_Char)0x65,  /* [2311] */
    (xdc_Char)0x65,  /* [2312] */
    (xdc_Char)0x3a,  /* [2313] */
    (xdc_Char)0x20,  /* [2314] */
    (xdc_Char)0x49,  /* [2315] */
    (xdc_Char)0x6e,  /* [2316] */
    (xdc_Char)0x76,  /* [2317] */
    (xdc_Char)0x61,  /* [2318] */
    (xdc_Char)0x6c,  /* [2319] */
    (xdc_Char)0x69,  /* [2320] */
    (xdc_Char)0x64,  /* [2321] */
    (xdc_Char)0x20,  /* [2322] */
    (xdc_Char)0x66,  /* [2323] */
    (xdc_Char)0x72,  /* [2324] */
    (xdc_Char)0x65,  /* [2325] */
    (xdc_Char)0x65,  /* [2326] */
    (xdc_Char)0x0,  /* [2327] */
    (xdc_Char)0x41,  /* [2328] */
    (xdc_Char)0x5f,  /* [2329] */
    (xdc_Char)0x7a,  /* [2330] */
    (xdc_Char)0x65,  /* [2331] */
    (xdc_Char)0x72,  /* [2332] */
    (xdc_Char)0x6f,  /* [2333] */
    (xdc_Char)0x42,  /* [2334] */
    (xdc_Char)0x6c,  /* [2335] */
    (xdc_Char)0x6f,  /* [2336] */
    (xdc_Char)0x63,  /* [2337] */
    (xdc_Char)0x6b,  /* [2338] */
    (xdc_Char)0x3a,  /* [2339] */
    (xdc_Char)0x20,  /* [2340] */
    (xdc_Char)0x43,  /* [2341] */
    (xdc_Char)0x61,  /* [2342] */
    (xdc_Char)0x6e,  /* [2343] */
    (xdc_Char)0x6e,  /* [2344] */
    (xdc_Char)0x6f,  /* [2345] */
    (xdc_Char)0x74,  /* [2346] */
    (xdc_Char)0x20,  /* [2347] */
    (xdc_Char)0x61,  /* [2348] */
    (xdc_Char)0x6c,  /* [2349] */
    (xdc_Char)0x6c,  /* [2350] */
    (xdc_Char)0x6f,  /* [2351] */
    (xdc_Char)0x63,  /* [2352] */
    (xdc_Char)0x61,  /* [2353] */
    (xdc_Char)0x74,  /* [2354] */
    (xdc_Char)0x65,  /* [2355] */
    (xdc_Char)0x20,  /* [2356] */
    (xdc_Char)0x73,  /* [2357] */
    (xdc_Char)0x69,  /* [2358] */
    (xdc_Char)0x7a,  /* [2359] */
    (xdc_Char)0x65,  /* [2360] */
    (xdc_Char)0x20,  /* [2361] */
    (xdc_Char)0x30,  /* [2362] */
    (xdc_Char)0x0,  /* [2363] */
    (xdc_Char)0x41,  /* [2364] */
    (xdc_Char)0x5f,  /* [2365] */
    (xdc_Char)0x68,  /* [2366] */
    (xdc_Char)0x65,  /* [2367] */
    (xdc_Char)0x61,  /* [2368] */
    (xdc_Char)0x70,  /* [2369] */
    (xdc_Char)0x53,  /* [2370] */
    (xdc_Char)0x69,  /* [2371] */
    (xdc_Char)0x7a,  /* [2372] */
    (xdc_Char)0x65,  /* [2373] */
    (xdc_Char)0x3a,  /* [2374] */
    (xdc_Char)0x20,  /* [2375] */
    (xdc_Char)0x52,  /* [2376] */
    (xdc_Char)0x65,  /* [2377] */
    (xdc_Char)0x71,  /* [2378] */
    (xdc_Char)0x75,  /* [2379] */
    (xdc_Char)0x65,  /* [2380] */
    (xdc_Char)0x73,  /* [2381] */
    (xdc_Char)0x74,  /* [2382] */
    (xdc_Char)0x65,  /* [2383] */
    (xdc_Char)0x64,  /* [2384] */
    (xdc_Char)0x20,  /* [2385] */
    (xdc_Char)0x68,  /* [2386] */
    (xdc_Char)0x65,  /* [2387] */
    (xdc_Char)0x61,  /* [2388] */
    (xdc_Char)0x70,  /* [2389] */
    (xdc_Char)0x20,  /* [2390] */
    (xdc_Char)0x73,  /* [2391] */
    (xdc_Char)0x69,  /* [2392] */
    (xdc_Char)0x7a,  /* [2393] */
    (xdc_Char)0x65,  /* [2394] */
    (xdc_Char)0x20,  /* [2395] */
    (xdc_Char)0x69,  /* [2396] */
    (xdc_Char)0x73,  /* [2397] */
    (xdc_Char)0x20,  /* [2398] */
    (xdc_Char)0x74,  /* [2399] */
    (xdc_Char)0x6f,  /* [2400] */
    (xdc_Char)0x6f,  /* [2401] */
    (xdc_Char)0x20,  /* [2402] */
    (xdc_Char)0x73,  /* [2403] */
    (xdc_Char)0x6d,  /* [2404] */
    (xdc_Char)0x61,  /* [2405] */
    (xdc_Char)0x6c,  /* [2406] */
    (xdc_Char)0x6c,  /* [2407] */
    (xdc_Char)0x0,  /* [2408] */
    (xdc_Char)0x41,  /* [2409] */
    (xdc_Char)0x5f,  /* [2410] */
    (xdc_Char)0x61,  /* [2411] */
    (xdc_Char)0x6c,  /* [2412] */
    (xdc_Char)0x69,  /* [2413] */
    (xdc_Char)0x67,  /* [2414] */
    (xdc_Char)0x6e,  /* [2415] */
    (xdc_Char)0x3a,  /* [2416] */
    (xdc_Char)0x20,  /* [2417] */
    (xdc_Char)0x52,  /* [2418] */
    (xdc_Char)0x65,  /* [2419] */
    (xdc_Char)0x71,  /* [2420] */
    (xdc_Char)0x75,  /* [2421] */
    (xdc_Char)0x65,  /* [2422] */
    (xdc_Char)0x73,  /* [2423] */
    (xdc_Char)0x74,  /* [2424] */
    (xdc_Char)0x65,  /* [2425] */
    (xdc_Char)0x64,  /* [2426] */
    (xdc_Char)0x20,  /* [2427] */
    (xdc_Char)0x61,  /* [2428] */
    (xdc_Char)0x6c,  /* [2429] */
    (xdc_Char)0x69,  /* [2430] */
    (xdc_Char)0x67,  /* [2431] */
    (xdc_Char)0x6e,  /* [2432] */
    (xdc_Char)0x20,  /* [2433] */
    (xdc_Char)0x69,  /* [2434] */
    (xdc_Char)0x73,  /* [2435] */
    (xdc_Char)0x20,  /* [2436] */
    (xdc_Char)0x6e,  /* [2437] */
    (xdc_Char)0x6f,  /* [2438] */
    (xdc_Char)0x74,  /* [2439] */
    (xdc_Char)0x20,  /* [2440] */
    (xdc_Char)0x61,  /* [2441] */
    (xdc_Char)0x20,  /* [2442] */
    (xdc_Char)0x70,  /* [2443] */
    (xdc_Char)0x6f,  /* [2444] */
    (xdc_Char)0x77,  /* [2445] */
    (xdc_Char)0x65,  /* [2446] */
    (xdc_Char)0x72,  /* [2447] */
    (xdc_Char)0x20,  /* [2448] */
    (xdc_Char)0x6f,  /* [2449] */
    (xdc_Char)0x66,  /* [2450] */
    (xdc_Char)0x20,  /* [2451] */
    (xdc_Char)0x32,  /* [2452] */
    (xdc_Char)0x0,  /* [2453] */
    (xdc_Char)0x49,  /* [2454] */
    (xdc_Char)0x6e,  /* [2455] */
    (xdc_Char)0x76,  /* [2456] */
    (xdc_Char)0x61,  /* [2457] */
    (xdc_Char)0x6c,  /* [2458] */
    (xdc_Char)0x69,  /* [2459] */
    (xdc_Char)0x64,  /* [2460] */
    (xdc_Char)0x20,  /* [2461] */
    (xdc_Char)0x62,  /* [2462] */
    (xdc_Char)0x6c,  /* [2463] */
    (xdc_Char)0x6f,  /* [2464] */
    (xdc_Char)0x63,  /* [2465] */
    (xdc_Char)0x6b,  /* [2466] */
    (xdc_Char)0x20,  /* [2467] */
    (xdc_Char)0x61,  /* [2468] */
    (xdc_Char)0x64,  /* [2469] */
    (xdc_Char)0x64,  /* [2470] */
    (xdc_Char)0x72,  /* [2471] */
    (xdc_Char)0x65,  /* [2472] */
    (xdc_Char)0x73,  /* [2473] */
    (xdc_Char)0x73,  /* [2474] */
    (xdc_Char)0x20,  /* [2475] */
    (xdc_Char)0x6f,  /* [2476] */
    (xdc_Char)0x6e,  /* [2477] */
    (xdc_Char)0x20,  /* [2478] */
    (xdc_Char)0x74,  /* [2479] */
    (xdc_Char)0x68,  /* [2480] */
    (xdc_Char)0x65,  /* [2481] */
    (xdc_Char)0x20,  /* [2482] */
    (xdc_Char)0x66,  /* [2483] */
    (xdc_Char)0x72,  /* [2484] */
    (xdc_Char)0x65,  /* [2485] */
    (xdc_Char)0x65,  /* [2486] */
    (xdc_Char)0x2e,  /* [2487] */
    (xdc_Char)0x20,  /* [2488] */
    (xdc_Char)0x46,  /* [2489] */
    (xdc_Char)0x61,  /* [2490] */
    (xdc_Char)0x69,  /* [2491] */
    (xdc_Char)0x6c,  /* [2492] */
    (xdc_Char)0x65,  /* [2493] */
    (xdc_Char)0x64,  /* [2494] */
    (xdc_Char)0x20,  /* [2495] */
    (xdc_Char)0x74,  /* [2496] */
    (xdc_Char)0x6f,  /* [2497] */
    (xdc_Char)0x20,  /* [2498] */
    (xdc_Char)0x66,  /* [2499] */
    (xdc_Char)0x72,  /* [2500] */
    (xdc_Char)0x65,  /* [2501] */
    (xdc_Char)0x65,  /* [2502] */
    (xdc_Char)0x20,  /* [2503] */
    (xdc_Char)0x62,  /* [2504] */
    (xdc_Char)0x6c,  /* [2505] */
    (xdc_Char)0x6f,  /* [2506] */
    (xdc_Char)0x63,  /* [2507] */
    (xdc_Char)0x6b,  /* [2508] */
    (xdc_Char)0x20,  /* [2509] */
    (xdc_Char)0x62,  /* [2510] */
    (xdc_Char)0x61,  /* [2511] */
    (xdc_Char)0x63,  /* [2512] */
    (xdc_Char)0x6b,  /* [2513] */
    (xdc_Char)0x20,  /* [2514] */
    (xdc_Char)0x74,  /* [2515] */
    (xdc_Char)0x6f,  /* [2516] */
    (xdc_Char)0x20,  /* [2517] */
    (xdc_Char)0x68,  /* [2518] */
    (xdc_Char)0x65,  /* [2519] */
    (xdc_Char)0x61,  /* [2520] */
    (xdc_Char)0x70,  /* [2521] */
    (xdc_Char)0x2e,  /* [2522] */
    (xdc_Char)0x0,  /* [2523] */
    (xdc_Char)0x41,  /* [2524] */
    (xdc_Char)0x5f,  /* [2525] */
    (xdc_Char)0x64,  /* [2526] */
    (xdc_Char)0x6f,  /* [2527] */
    (xdc_Char)0x75,  /* [2528] */
    (xdc_Char)0x62,  /* [2529] */
    (xdc_Char)0x6c,  /* [2530] */
    (xdc_Char)0x65,  /* [2531] */
    (xdc_Char)0x46,  /* [2532] */
    (xdc_Char)0x72,  /* [2533] */
    (xdc_Char)0x65,  /* [2534] */
    (xdc_Char)0x65,  /* [2535] */
    (xdc_Char)0x3a,  /* [2536] */
    (xdc_Char)0x20,  /* [2537] */
    (xdc_Char)0x48,  /* [2538] */
    (xdc_Char)0x65,  /* [2539] */
    (xdc_Char)0x61,  /* [2540] */
    (xdc_Char)0x70,  /* [2541] */
    (xdc_Char)0x20,  /* [2542] */
    (xdc_Char)0x61,  /* [2543] */
    (xdc_Char)0x6c,  /* [2544] */
    (xdc_Char)0x72,  /* [2545] */
    (xdc_Char)0x65,  /* [2546] */
    (xdc_Char)0x61,  /* [2547] */
    (xdc_Char)0x64,  /* [2548] */
    (xdc_Char)0x79,  /* [2549] */
    (xdc_Char)0x20,  /* [2550] */
    (xdc_Char)0x66,  /* [2551] */
    (xdc_Char)0x72,  /* [2552] */
    (xdc_Char)0x65,  /* [2553] */
    (xdc_Char)0x65,  /* [2554] */
    (xdc_Char)0x0,  /* [2555] */
    (xdc_Char)0x41,  /* [2556] */
    (xdc_Char)0x5f,  /* [2557] */
    (xdc_Char)0x62,  /* [2558] */
    (xdc_Char)0x75,  /* [2559] */
    (xdc_Char)0x66,  /* [2560] */
    (xdc_Char)0x4f,  /* [2561] */
    (xdc_Char)0x76,  /* [2562] */
    (xdc_Char)0x65,  /* [2563] */
    (xdc_Char)0x72,  /* [2564] */
    (xdc_Char)0x66,  /* [2565] */
    (xdc_Char)0x6c,  /* [2566] */
    (xdc_Char)0x6f,  /* [2567] */
    (xdc_Char)0x77,  /* [2568] */
    (xdc_Char)0x3a,  /* [2569] */
    (xdc_Char)0x20,  /* [2570] */
    (xdc_Char)0x42,  /* [2571] */
    (xdc_Char)0x75,  /* [2572] */
    (xdc_Char)0x66,  /* [2573] */
    (xdc_Char)0x66,  /* [2574] */
    (xdc_Char)0x65,  /* [2575] */
    (xdc_Char)0x72,  /* [2576] */
    (xdc_Char)0x20,  /* [2577] */
    (xdc_Char)0x6f,  /* [2578] */
    (xdc_Char)0x76,  /* [2579] */
    (xdc_Char)0x65,  /* [2580] */
    (xdc_Char)0x72,  /* [2581] */
    (xdc_Char)0x66,  /* [2582] */
    (xdc_Char)0x6c,  /* [2583] */
    (xdc_Char)0x6f,  /* [2584] */
    (xdc_Char)0x77,  /* [2585] */
    (xdc_Char)0x0,  /* [2586] */
    (xdc_Char)0x41,  /* [2587] */
    (xdc_Char)0x5f,  /* [2588] */
    (xdc_Char)0x6e,  /* [2589] */
    (xdc_Char)0x6f,  /* [2590] */
    (xdc_Char)0x74,  /* [2591] */
    (xdc_Char)0x45,  /* [2592] */
    (xdc_Char)0x6d,  /* [2593] */
    (xdc_Char)0x70,  /* [2594] */
    (xdc_Char)0x74,  /* [2595] */
    (xdc_Char)0x79,  /* [2596] */
    (xdc_Char)0x3a,  /* [2597] */
    (xdc_Char)0x20,  /* [2598] */
    (xdc_Char)0x48,  /* [2599] */
    (xdc_Char)0x65,  /* [2600] */
    (xdc_Char)0x61,  /* [2601] */
    (xdc_Char)0x70,  /* [2602] */
    (xdc_Char)0x20,  /* [2603] */
    (xdc_Char)0x6e,  /* [2604] */
    (xdc_Char)0x6f,  /* [2605] */
    (xdc_Char)0x74,  /* [2606] */
    (xdc_Char)0x20,  /* [2607] */
    (xdc_Char)0x65,  /* [2608] */
    (xdc_Char)0x6d,  /* [2609] */
    (xdc_Char)0x70,  /* [2610] */
    (xdc_Char)0x74,  /* [2611] */
    (xdc_Char)0x79,  /* [2612] */
    (xdc_Char)0x0,  /* [2613] */
    (xdc_Char)0x41,  /* [2614] */
    (xdc_Char)0x5f,  /* [2615] */
    (xdc_Char)0x6e,  /* [2616] */
    (xdc_Char)0x75,  /* [2617] */
    (xdc_Char)0x6c,  /* [2618] */
    (xdc_Char)0x6c,  /* [2619] */
    (xdc_Char)0x4f,  /* [2620] */
    (xdc_Char)0x62,  /* [2621] */
    (xdc_Char)0x6a,  /* [2622] */
    (xdc_Char)0x65,  /* [2623] */
    (xdc_Char)0x63,  /* [2624] */
    (xdc_Char)0x74,  /* [2625] */
    (xdc_Char)0x3a,  /* [2626] */
    (xdc_Char)0x20,  /* [2627] */
    (xdc_Char)0x48,  /* [2628] */
    (xdc_Char)0x65,  /* [2629] */
    (xdc_Char)0x61,  /* [2630] */
    (xdc_Char)0x70,  /* [2631] */
    (xdc_Char)0x54,  /* [2632] */
    (xdc_Char)0x72,  /* [2633] */
    (xdc_Char)0x61,  /* [2634] */
    (xdc_Char)0x63,  /* [2635] */
    (xdc_Char)0x6b,  /* [2636] */
    (xdc_Char)0x5f,  /* [2637] */
    (xdc_Char)0x70,  /* [2638] */
    (xdc_Char)0x72,  /* [2639] */
    (xdc_Char)0x69,  /* [2640] */
    (xdc_Char)0x6e,  /* [2641] */
    (xdc_Char)0x74,  /* [2642] */
    (xdc_Char)0x48,  /* [2643] */
    (xdc_Char)0x65,  /* [2644] */
    (xdc_Char)0x61,  /* [2645] */
    (xdc_Char)0x70,  /* [2646] */
    (xdc_Char)0x20,  /* [2647] */
    (xdc_Char)0x63,  /* [2648] */
    (xdc_Char)0x61,  /* [2649] */
    (xdc_Char)0x6c,  /* [2650] */
    (xdc_Char)0x6c,  /* [2651] */
    (xdc_Char)0x65,  /* [2652] */
    (xdc_Char)0x64,  /* [2653] */
    (xdc_Char)0x20,  /* [2654] */
    (xdc_Char)0x77,  /* [2655] */
    (xdc_Char)0x69,  /* [2656] */
    (xdc_Char)0x74,  /* [2657] */
    (xdc_Char)0x68,  /* [2658] */
    (xdc_Char)0x20,  /* [2659] */
    (xdc_Char)0x6e,  /* [2660] */
    (xdc_Char)0x75,  /* [2661] */
    (xdc_Char)0x6c,  /* [2662] */
    (xdc_Char)0x6c,  /* [2663] */
    (xdc_Char)0x20,  /* [2664] */
    (xdc_Char)0x6f,  /* [2665] */
    (xdc_Char)0x62,  /* [2666] */
    (xdc_Char)0x6a,  /* [2667] */
    (xdc_Char)0x0,  /* [2668] */
    (xdc_Char)0x61,  /* [2669] */
    (xdc_Char)0x73,  /* [2670] */
    (xdc_Char)0x73,  /* [2671] */
    (xdc_Char)0x65,  /* [2672] */
    (xdc_Char)0x72,  /* [2673] */
    (xdc_Char)0x74,  /* [2674] */
    (xdc_Char)0x69,  /* [2675] */
    (xdc_Char)0x6f,  /* [2676] */
    (xdc_Char)0x6e,  /* [2677] */
    (xdc_Char)0x20,  /* [2678] */
    (xdc_Char)0x66,  /* [2679] */
    (xdc_Char)0x61,  /* [2680] */
    (xdc_Char)0x69,  /* [2681] */
    (xdc_Char)0x6c,  /* [2682] */
    (xdc_Char)0x75,  /* [2683] */
    (xdc_Char)0x72,  /* [2684] */
    (xdc_Char)0x65,  /* [2685] */
    (xdc_Char)0x25,  /* [2686] */
    (xdc_Char)0x73,  /* [2687] */
    (xdc_Char)0x25,  /* [2688] */
    (xdc_Char)0x73,  /* [2689] */
    (xdc_Char)0x0,  /* [2690] */
    (xdc_Char)0x25,  /* [2691] */
    (xdc_Char)0x24,  /* [2692] */
    (xdc_Char)0x53,  /* [2693] */
    (xdc_Char)0x0,  /* [2694] */
    (xdc_Char)0x6f,  /* [2695] */
    (xdc_Char)0x75,  /* [2696] */
    (xdc_Char)0x74,  /* [2697] */
    (xdc_Char)0x20,  /* [2698] */
    (xdc_Char)0x6f,  /* [2699] */
    (xdc_Char)0x66,  /* [2700] */
    (xdc_Char)0x20,  /* [2701] */
    (xdc_Char)0x6d,  /* [2702] */
    (xdc_Char)0x65,  /* [2703] */
    (xdc_Char)0x6d,  /* [2704] */
    (xdc_Char)0x6f,  /* [2705] */
    (xdc_Char)0x72,  /* [2706] */
    (xdc_Char)0x79,  /* [2707] */
    (xdc_Char)0x3a,  /* [2708] */
    (xdc_Char)0x20,  /* [2709] */
    (xdc_Char)0x68,  /* [2710] */
    (xdc_Char)0x65,  /* [2711] */
    (xdc_Char)0x61,  /* [2712] */
    (xdc_Char)0x70,  /* [2713] */
    (xdc_Char)0x3d,  /* [2714] */
    (xdc_Char)0x30,  /* [2715] */
    (xdc_Char)0x78,  /* [2716] */
    (xdc_Char)0x25,  /* [2717] */
    (xdc_Char)0x78,  /* [2718] */
    (xdc_Char)0x2c,  /* [2719] */
    (xdc_Char)0x20,  /* [2720] */
    (xdc_Char)0x73,  /* [2721] */
    (xdc_Char)0x69,  /* [2722] */
    (xdc_Char)0x7a,  /* [2723] */
    (xdc_Char)0x65,  /* [2724] */
    (xdc_Char)0x3d,  /* [2725] */
    (xdc_Char)0x25,  /* [2726] */
    (xdc_Char)0x75,  /* [2727] */
    (xdc_Char)0x0,  /* [2728] */
    (xdc_Char)0x25,  /* [2729] */
    (xdc_Char)0x73,  /* [2730] */
    (xdc_Char)0x20,  /* [2731] */
    (xdc_Char)0x30,  /* [2732] */
    (xdc_Char)0x78,  /* [2733] */
    (xdc_Char)0x25,  /* [2734] */
    (xdc_Char)0x78,  /* [2735] */
    (xdc_Char)0x0,  /* [2736] */
    (xdc_Char)0x45,  /* [2737] */
    (xdc_Char)0x5f,  /* [2738] */
    (xdc_Char)0x62,  /* [2739] */
    (xdc_Char)0x61,  /* [2740] */
    (xdc_Char)0x64,  /* [2741] */
    (xdc_Char)0x4c,  /* [2742] */
    (xdc_Char)0x65,  /* [2743] */
    (xdc_Char)0x76,  /* [2744] */
    (xdc_Char)0x65,  /* [2745] */
    (xdc_Char)0x6c,  /* [2746] */
    (xdc_Char)0x3a,  /* [2747] */
    (xdc_Char)0x20,  /* [2748] */
    (xdc_Char)0x42,  /* [2749] */
    (xdc_Char)0x61,  /* [2750] */
    (xdc_Char)0x64,  /* [2751] */
    (xdc_Char)0x20,  /* [2752] */
    (xdc_Char)0x66,  /* [2753] */
    (xdc_Char)0x69,  /* [2754] */
    (xdc_Char)0x6c,  /* [2755] */
    (xdc_Char)0x74,  /* [2756] */
    (xdc_Char)0x65,  /* [2757] */
    (xdc_Char)0x72,  /* [2758] */
    (xdc_Char)0x20,  /* [2759] */
    (xdc_Char)0x6c,  /* [2760] */
    (xdc_Char)0x65,  /* [2761] */
    (xdc_Char)0x76,  /* [2762] */
    (xdc_Char)0x65,  /* [2763] */
    (xdc_Char)0x6c,  /* [2764] */
    (xdc_Char)0x20,  /* [2765] */
    (xdc_Char)0x76,  /* [2766] */
    (xdc_Char)0x61,  /* [2767] */
    (xdc_Char)0x6c,  /* [2768] */
    (xdc_Char)0x75,  /* [2769] */
    (xdc_Char)0x65,  /* [2770] */
    (xdc_Char)0x3a,  /* [2771] */
    (xdc_Char)0x20,  /* [2772] */
    (xdc_Char)0x25,  /* [2773] */
    (xdc_Char)0x64,  /* [2774] */
    (xdc_Char)0x0,  /* [2775] */
    (xdc_Char)0x66,  /* [2776] */
    (xdc_Char)0x72,  /* [2777] */
    (xdc_Char)0x65,  /* [2778] */
    (xdc_Char)0x65,  /* [2779] */
    (xdc_Char)0x28,  /* [2780] */
    (xdc_Char)0x29,  /* [2781] */
    (xdc_Char)0x20,  /* [2782] */
    (xdc_Char)0x69,  /* [2783] */
    (xdc_Char)0x6e,  /* [2784] */
    (xdc_Char)0x76,  /* [2785] */
    (xdc_Char)0x61,  /* [2786] */
    (xdc_Char)0x6c,  /* [2787] */
    (xdc_Char)0x69,  /* [2788] */
    (xdc_Char)0x64,  /* [2789] */
    (xdc_Char)0x20,  /* [2790] */
    (xdc_Char)0x69,  /* [2791] */
    (xdc_Char)0x6e,  /* [2792] */
    (xdc_Char)0x20,  /* [2793] */
    (xdc_Char)0x67,  /* [2794] */
    (xdc_Char)0x72,  /* [2795] */
    (xdc_Char)0x6f,  /* [2796] */
    (xdc_Char)0x77,  /* [2797] */
    (xdc_Char)0x74,  /* [2798] */
    (xdc_Char)0x68,  /* [2799] */
    (xdc_Char)0x2d,  /* [2800] */
    (xdc_Char)0x6f,  /* [2801] */
    (xdc_Char)0x6e,  /* [2802] */
    (xdc_Char)0x6c,  /* [2803] */
    (xdc_Char)0x79,  /* [2804] */
    (xdc_Char)0x20,  /* [2805] */
    (xdc_Char)0x48,  /* [2806] */
    (xdc_Char)0x65,  /* [2807] */
    (xdc_Char)0x61,  /* [2808] */
    (xdc_Char)0x70,  /* [2809] */
    (xdc_Char)0x4d,  /* [2810] */
    (xdc_Char)0x69,  /* [2811] */
    (xdc_Char)0x6e,  /* [2812] */
    (xdc_Char)0x0,  /* [2813] */
    (xdc_Char)0x54,  /* [2814] */
    (xdc_Char)0x68,  /* [2815] */
    (xdc_Char)0x65,  /* [2816] */
    (xdc_Char)0x20,  /* [2817] */
    (xdc_Char)0x52,  /* [2818] */
    (xdc_Char)0x54,  /* [2819] */
    (xdc_Char)0x53,  /* [2820] */
    (xdc_Char)0x20,  /* [2821] */
    (xdc_Char)0x68,  /* [2822] */
    (xdc_Char)0x65,  /* [2823] */
    (xdc_Char)0x61,  /* [2824] */
    (xdc_Char)0x70,  /* [2825] */
    (xdc_Char)0x20,  /* [2826] */
    (xdc_Char)0x69,  /* [2827] */
    (xdc_Char)0x73,  /* [2828] */
    (xdc_Char)0x20,  /* [2829] */
    (xdc_Char)0x75,  /* [2830] */
    (xdc_Char)0x73,  /* [2831] */
    (xdc_Char)0x65,  /* [2832] */
    (xdc_Char)0x64,  /* [2833] */
    (xdc_Char)0x20,  /* [2834] */
    (xdc_Char)0x75,  /* [2835] */
    (xdc_Char)0x70,  /* [2836] */
    (xdc_Char)0x2e,  /* [2837] */
    (xdc_Char)0x20,  /* [2838] */
    (xdc_Char)0x45,  /* [2839] */
    (xdc_Char)0x78,  /* [2840] */
    (xdc_Char)0x61,  /* [2841] */
    (xdc_Char)0x6d,  /* [2842] */
    (xdc_Char)0x69,  /* [2843] */
    (xdc_Char)0x6e,  /* [2844] */
    (xdc_Char)0x65,  /* [2845] */
    (xdc_Char)0x20,  /* [2846] */
    (xdc_Char)0x50,  /* [2847] */
    (xdc_Char)0x72,  /* [2848] */
    (xdc_Char)0x6f,  /* [2849] */
    (xdc_Char)0x67,  /* [2850] */
    (xdc_Char)0x72,  /* [2851] */
    (xdc_Char)0x61,  /* [2852] */
    (xdc_Char)0x6d,  /* [2853] */
    (xdc_Char)0x2e,  /* [2854] */
    (xdc_Char)0x68,  /* [2855] */
    (xdc_Char)0x65,  /* [2856] */
    (xdc_Char)0x61,  /* [2857] */
    (xdc_Char)0x70,  /* [2858] */
    (xdc_Char)0x2e,  /* [2859] */
    (xdc_Char)0x0,  /* [2860] */
    (xdc_Char)0x45,  /* [2861] */
    (xdc_Char)0x5f,  /* [2862] */
    (xdc_Char)0x62,  /* [2863] */
    (xdc_Char)0x61,  /* [2864] */
    (xdc_Char)0x64,  /* [2865] */
    (xdc_Char)0x43,  /* [2866] */
    (xdc_Char)0x6f,  /* [2867] */
    (xdc_Char)0x6d,  /* [2868] */
    (xdc_Char)0x6d,  /* [2869] */
    (xdc_Char)0x61,  /* [2870] */
    (xdc_Char)0x6e,  /* [2871] */
    (xdc_Char)0x64,  /* [2872] */
    (xdc_Char)0x3a,  /* [2873] */
    (xdc_Char)0x20,  /* [2874] */
    (xdc_Char)0x52,  /* [2875] */
    (xdc_Char)0x65,  /* [2876] */
    (xdc_Char)0x63,  /* [2877] */
    (xdc_Char)0x65,  /* [2878] */
    (xdc_Char)0x69,  /* [2879] */
    (xdc_Char)0x76,  /* [2880] */
    (xdc_Char)0x65,  /* [2881] */
    (xdc_Char)0x64,  /* [2882] */
    (xdc_Char)0x20,  /* [2883] */
    (xdc_Char)0x69,  /* [2884] */
    (xdc_Char)0x6e,  /* [2885] */
    (xdc_Char)0x76,  /* [2886] */
    (xdc_Char)0x61,  /* [2887] */
    (xdc_Char)0x6c,  /* [2888] */
    (xdc_Char)0x69,  /* [2889] */
    (xdc_Char)0x64,  /* [2890] */
    (xdc_Char)0x20,  /* [2891] */
    (xdc_Char)0x63,  /* [2892] */
    (xdc_Char)0x6f,  /* [2893] */
    (xdc_Char)0x6d,  /* [2894] */
    (xdc_Char)0x6d,  /* [2895] */
    (xdc_Char)0x61,  /* [2896] */
    (xdc_Char)0x6e,  /* [2897] */
    (xdc_Char)0x64,  /* [2898] */
    (xdc_Char)0x2c,  /* [2899] */
    (xdc_Char)0x20,  /* [2900] */
    (xdc_Char)0x69,  /* [2901] */
    (xdc_Char)0x64,  /* [2902] */
    (xdc_Char)0x3a,  /* [2903] */
    (xdc_Char)0x20,  /* [2904] */
    (xdc_Char)0x25,  /* [2905] */
    (xdc_Char)0x64,  /* [2906] */
    (xdc_Char)0x2e,  /* [2907] */
    (xdc_Char)0x0,  /* [2908] */
    (xdc_Char)0x45,  /* [2909] */
    (xdc_Char)0x5f,  /* [2910] */
    (xdc_Char)0x75,  /* [2911] */
    (xdc_Char)0x6e,  /* [2912] */
    (xdc_Char)0x70,  /* [2913] */
    (xdc_Char)0x6c,  /* [2914] */
    (xdc_Char)0x75,  /* [2915] */
    (xdc_Char)0x67,  /* [2916] */
    (xdc_Char)0x67,  /* [2917] */
    (xdc_Char)0x65,  /* [2918] */
    (xdc_Char)0x64,  /* [2919] */
    (xdc_Char)0x45,  /* [2920] */
    (xdc_Char)0x76,  /* [2921] */
    (xdc_Char)0x65,  /* [2922] */
    (xdc_Char)0x6e,  /* [2923] */
    (xdc_Char)0x74,  /* [2924] */
    (xdc_Char)0x3a,  /* [2925] */
    (xdc_Char)0x20,  /* [2926] */
    (xdc_Char)0x45,  /* [2927] */
    (xdc_Char)0x76,  /* [2928] */
    (xdc_Char)0x65,  /* [2929] */
    (xdc_Char)0x6e,  /* [2930] */
    (xdc_Char)0x74,  /* [2931] */
    (xdc_Char)0x23,  /* [2932] */
    (xdc_Char)0x20,  /* [2933] */
    (xdc_Char)0x25,  /* [2934] */
    (xdc_Char)0x64,  /* [2935] */
    (xdc_Char)0x20,  /* [2936] */
    (xdc_Char)0x69,  /* [2937] */
    (xdc_Char)0x73,  /* [2938] */
    (xdc_Char)0x20,  /* [2939] */
    (xdc_Char)0x75,  /* [2940] */
    (xdc_Char)0x6e,  /* [2941] */
    (xdc_Char)0x70,  /* [2942] */
    (xdc_Char)0x6c,  /* [2943] */
    (xdc_Char)0x75,  /* [2944] */
    (xdc_Char)0x67,  /* [2945] */
    (xdc_Char)0x67,  /* [2946] */
    (xdc_Char)0x65,  /* [2947] */
    (xdc_Char)0x64,  /* [2948] */
    (xdc_Char)0x0,  /* [2949] */
    (xdc_Char)0x45,  /* [2950] */
    (xdc_Char)0x5f,  /* [2951] */
    (xdc_Char)0x65,  /* [2952] */
    (xdc_Char)0x78,  /* [2953] */
    (xdc_Char)0x63,  /* [2954] */
    (xdc_Char)0x65,  /* [2955] */
    (xdc_Char)0x70,  /* [2956] */
    (xdc_Char)0x74,  /* [2957] */
    (xdc_Char)0x69,  /* [2958] */
    (xdc_Char)0x6f,  /* [2959] */
    (xdc_Char)0x6e,  /* [2960] */
    (xdc_Char)0x4d,  /* [2961] */
    (xdc_Char)0x69,  /* [2962] */
    (xdc_Char)0x6e,  /* [2963] */
    (xdc_Char)0x3a,  /* [2964] */
    (xdc_Char)0x20,  /* [2965] */
    (xdc_Char)0x70,  /* [2966] */
    (xdc_Char)0x63,  /* [2967] */
    (xdc_Char)0x20,  /* [2968] */
    (xdc_Char)0x3d,  /* [2969] */
    (xdc_Char)0x20,  /* [2970] */
    (xdc_Char)0x30,  /* [2971] */
    (xdc_Char)0x78,  /* [2972] */
    (xdc_Char)0x25,  /* [2973] */
    (xdc_Char)0x30,  /* [2974] */
    (xdc_Char)0x38,  /* [2975] */
    (xdc_Char)0x78,  /* [2976] */
    (xdc_Char)0x2c,  /* [2977] */
    (xdc_Char)0x20,  /* [2978] */
    (xdc_Char)0x73,  /* [2979] */
    (xdc_Char)0x70,  /* [2980] */
    (xdc_Char)0x20,  /* [2981] */
    (xdc_Char)0x3d,  /* [2982] */
    (xdc_Char)0x20,  /* [2983] */
    (xdc_Char)0x30,  /* [2984] */
    (xdc_Char)0x78,  /* [2985] */
    (xdc_Char)0x25,  /* [2986] */
    (xdc_Char)0x30,  /* [2987] */
    (xdc_Char)0x38,  /* [2988] */
    (xdc_Char)0x78,  /* [2989] */
    (xdc_Char)0x2e,  /* [2990] */
    (xdc_Char)0xa,  /* [2991] */
    (xdc_Char)0x54,  /* [2992] */
    (xdc_Char)0x6f,  /* [2993] */
    (xdc_Char)0x20,  /* [2994] */
    (xdc_Char)0x73,  /* [2995] */
    (xdc_Char)0x65,  /* [2996] */
    (xdc_Char)0x65,  /* [2997] */
    (xdc_Char)0x20,  /* [2998] */
    (xdc_Char)0x6d,  /* [2999] */
    (xdc_Char)0x6f,  /* [3000] */
    (xdc_Char)0x72,  /* [3001] */
    (xdc_Char)0x65,  /* [3002] */
    (xdc_Char)0x20,  /* [3003] */
    (xdc_Char)0x65,  /* [3004] */
    (xdc_Char)0x78,  /* [3005] */
    (xdc_Char)0x63,  /* [3006] */
    (xdc_Char)0x65,  /* [3007] */
    (xdc_Char)0x70,  /* [3008] */
    (xdc_Char)0x74,  /* [3009] */
    (xdc_Char)0x69,  /* [3010] */
    (xdc_Char)0x6f,  /* [3011] */
    (xdc_Char)0x6e,  /* [3012] */
    (xdc_Char)0x20,  /* [3013] */
    (xdc_Char)0x64,  /* [3014] */
    (xdc_Char)0x65,  /* [3015] */
    (xdc_Char)0x74,  /* [3016] */
    (xdc_Char)0x61,  /* [3017] */
    (xdc_Char)0x69,  /* [3018] */
    (xdc_Char)0x6c,  /* [3019] */
    (xdc_Char)0x2c,  /* [3020] */
    (xdc_Char)0x20,  /* [3021] */
    (xdc_Char)0x75,  /* [3022] */
    (xdc_Char)0x73,  /* [3023] */
    (xdc_Char)0x65,  /* [3024] */
    (xdc_Char)0x20,  /* [3025] */
    (xdc_Char)0x52,  /* [3026] */
    (xdc_Char)0x4f,  /* [3027] */
    (xdc_Char)0x56,  /* [3028] */
    (xdc_Char)0x20,  /* [3029] */
    (xdc_Char)0x6f,  /* [3030] */
    (xdc_Char)0x72,  /* [3031] */
    (xdc_Char)0x20,  /* [3032] */
    (xdc_Char)0x73,  /* [3033] */
    (xdc_Char)0x65,  /* [3034] */
    (xdc_Char)0x74,  /* [3035] */
    (xdc_Char)0x20,  /* [3036] */
    (xdc_Char)0x27,  /* [3037] */
    (xdc_Char)0x74,  /* [3038] */
    (xdc_Char)0x69,  /* [3039] */
    (xdc_Char)0x2e,  /* [3040] */
    (xdc_Char)0x73,  /* [3041] */
    (xdc_Char)0x79,  /* [3042] */
    (xdc_Char)0x73,  /* [3043] */
    (xdc_Char)0x62,  /* [3044] */
    (xdc_Char)0x69,  /* [3045] */
    (xdc_Char)0x6f,  /* [3046] */
    (xdc_Char)0x73,  /* [3047] */
    (xdc_Char)0x2e,  /* [3048] */
    (xdc_Char)0x66,  /* [3049] */
    (xdc_Char)0x61,  /* [3050] */
    (xdc_Char)0x6d,  /* [3051] */
    (xdc_Char)0x69,  /* [3052] */
    (xdc_Char)0x6c,  /* [3053] */
    (xdc_Char)0x79,  /* [3054] */
    (xdc_Char)0x2e,  /* [3055] */
    (xdc_Char)0x63,  /* [3056] */
    (xdc_Char)0x36,  /* [3057] */
    (xdc_Char)0x34,  /* [3058] */
    (xdc_Char)0x70,  /* [3059] */
    (xdc_Char)0x2e,  /* [3060] */
    (xdc_Char)0x45,  /* [3061] */
    (xdc_Char)0x78,  /* [3062] */
    (xdc_Char)0x63,  /* [3063] */
    (xdc_Char)0x65,  /* [3064] */
    (xdc_Char)0x70,  /* [3065] */
    (xdc_Char)0x74,  /* [3066] */
    (xdc_Char)0x69,  /* [3067] */
    (xdc_Char)0x6f,  /* [3068] */
    (xdc_Char)0x6e,  /* [3069] */
    (xdc_Char)0x2e,  /* [3070] */
    (xdc_Char)0x65,  /* [3071] */
    (xdc_Char)0x6e,  /* [3072] */
    (xdc_Char)0x61,  /* [3073] */
    (xdc_Char)0x62,  /* [3074] */
    (xdc_Char)0x6c,  /* [3075] */
    (xdc_Char)0x65,  /* [3076] */
    (xdc_Char)0x50,  /* [3077] */
    (xdc_Char)0x72,  /* [3078] */
    (xdc_Char)0x69,  /* [3079] */
    (xdc_Char)0x6e,  /* [3080] */
    (xdc_Char)0x74,  /* [3081] */
    (xdc_Char)0x20,  /* [3082] */
    (xdc_Char)0x3d,  /* [3083] */
    (xdc_Char)0x20,  /* [3084] */
    (xdc_Char)0x74,  /* [3085] */
    (xdc_Char)0x72,  /* [3086] */
    (xdc_Char)0x75,  /* [3087] */
    (xdc_Char)0x65,  /* [3088] */
    (xdc_Char)0x3b,  /* [3089] */
    (xdc_Char)0x27,  /* [3090] */
    (xdc_Char)0x0,  /* [3091] */
    (xdc_Char)0x45,  /* [3092] */
    (xdc_Char)0x5f,  /* [3093] */
    (xdc_Char)0x65,  /* [3094] */
    (xdc_Char)0x78,  /* [3095] */
    (xdc_Char)0x63,  /* [3096] */
    (xdc_Char)0x65,  /* [3097] */
    (xdc_Char)0x70,  /* [3098] */
    (xdc_Char)0x74,  /* [3099] */
    (xdc_Char)0x69,  /* [3100] */
    (xdc_Char)0x6f,  /* [3101] */
    (xdc_Char)0x6e,  /* [3102] */
    (xdc_Char)0x4d,  /* [3103] */
    (xdc_Char)0x61,  /* [3104] */
    (xdc_Char)0x78,  /* [3105] */
    (xdc_Char)0x3a,  /* [3106] */
    (xdc_Char)0x20,  /* [3107] */
    (xdc_Char)0x70,  /* [3108] */
    (xdc_Char)0x63,  /* [3109] */
    (xdc_Char)0x20,  /* [3110] */
    (xdc_Char)0x3d,  /* [3111] */
    (xdc_Char)0x20,  /* [3112] */
    (xdc_Char)0x30,  /* [3113] */
    (xdc_Char)0x78,  /* [3114] */
    (xdc_Char)0x25,  /* [3115] */
    (xdc_Char)0x30,  /* [3116] */
    (xdc_Char)0x38,  /* [3117] */
    (xdc_Char)0x78,  /* [3118] */
    (xdc_Char)0x2c,  /* [3119] */
    (xdc_Char)0x20,  /* [3120] */
    (xdc_Char)0x73,  /* [3121] */
    (xdc_Char)0x70,  /* [3122] */
    (xdc_Char)0x20,  /* [3123] */
    (xdc_Char)0x3d,  /* [3124] */
    (xdc_Char)0x20,  /* [3125] */
    (xdc_Char)0x30,  /* [3126] */
    (xdc_Char)0x78,  /* [3127] */
    (xdc_Char)0x25,  /* [3128] */
    (xdc_Char)0x30,  /* [3129] */
    (xdc_Char)0x38,  /* [3130] */
    (xdc_Char)0x78,  /* [3131] */
    (xdc_Char)0x2e,  /* [3132] */
    (xdc_Char)0x0,  /* [3133] */
    (xdc_Char)0x45,  /* [3134] */
    (xdc_Char)0x5f,  /* [3135] */
    (xdc_Char)0x61,  /* [3136] */
    (xdc_Char)0x6c,  /* [3137] */
    (xdc_Char)0x72,  /* [3138] */
    (xdc_Char)0x65,  /* [3139] */
    (xdc_Char)0x61,  /* [3140] */
    (xdc_Char)0x64,  /* [3141] */
    (xdc_Char)0x79,  /* [3142] */
    (xdc_Char)0x44,  /* [3143] */
    (xdc_Char)0x65,  /* [3144] */
    (xdc_Char)0x66,  /* [3145] */
    (xdc_Char)0x69,  /* [3146] */
    (xdc_Char)0x6e,  /* [3147] */
    (xdc_Char)0x65,  /* [3148] */
    (xdc_Char)0x64,  /* [3149] */
    (xdc_Char)0x3a,  /* [3150] */
    (xdc_Char)0x20,  /* [3151] */
    (xdc_Char)0x48,  /* [3152] */
    (xdc_Char)0x77,  /* [3153] */
    (xdc_Char)0x69,  /* [3154] */
    (xdc_Char)0x20,  /* [3155] */
    (xdc_Char)0x61,  /* [3156] */
    (xdc_Char)0x6c,  /* [3157] */
    (xdc_Char)0x72,  /* [3158] */
    (xdc_Char)0x65,  /* [3159] */
    (xdc_Char)0x61,  /* [3160] */
    (xdc_Char)0x64,  /* [3161] */
    (xdc_Char)0x79,  /* [3162] */
    (xdc_Char)0x20,  /* [3163] */
    (xdc_Char)0x64,  /* [3164] */
    (xdc_Char)0x65,  /* [3165] */
    (xdc_Char)0x66,  /* [3166] */
    (xdc_Char)0x69,  /* [3167] */
    (xdc_Char)0x6e,  /* [3168] */
    (xdc_Char)0x65,  /* [3169] */
    (xdc_Char)0x64,  /* [3170] */
    (xdc_Char)0x3a,  /* [3171] */
    (xdc_Char)0x20,  /* [3172] */
    (xdc_Char)0x69,  /* [3173] */
    (xdc_Char)0x6e,  /* [3174] */
    (xdc_Char)0x74,  /* [3175] */
    (xdc_Char)0x72,  /* [3176] */
    (xdc_Char)0x23,  /* [3177] */
    (xdc_Char)0x20,  /* [3178] */
    (xdc_Char)0x25,  /* [3179] */
    (xdc_Char)0x64,  /* [3180] */
    (xdc_Char)0x0,  /* [3181] */
    (xdc_Char)0x45,  /* [3182] */
    (xdc_Char)0x5f,  /* [3183] */
    (xdc_Char)0x68,  /* [3184] */
    (xdc_Char)0x61,  /* [3185] */
    (xdc_Char)0x6e,  /* [3186] */
    (xdc_Char)0x64,  /* [3187] */
    (xdc_Char)0x6c,  /* [3188] */
    (xdc_Char)0x65,  /* [3189] */
    (xdc_Char)0x4e,  /* [3190] */
    (xdc_Char)0x6f,  /* [3191] */
    (xdc_Char)0x74,  /* [3192] */
    (xdc_Char)0x46,  /* [3193] */
    (xdc_Char)0x6f,  /* [3194] */
    (xdc_Char)0x75,  /* [3195] */
    (xdc_Char)0x6e,  /* [3196] */
    (xdc_Char)0x64,  /* [3197] */
    (xdc_Char)0x3a,  /* [3198] */
    (xdc_Char)0x20,  /* [3199] */
    (xdc_Char)0x48,  /* [3200] */
    (xdc_Char)0x77,  /* [3201] */
    (xdc_Char)0x69,  /* [3202] */
    (xdc_Char)0x20,  /* [3203] */
    (xdc_Char)0x68,  /* [3204] */
    (xdc_Char)0x61,  /* [3205] */
    (xdc_Char)0x6e,  /* [3206] */
    (xdc_Char)0x64,  /* [3207] */
    (xdc_Char)0x6c,  /* [3208] */
    (xdc_Char)0x65,  /* [3209] */
    (xdc_Char)0x20,  /* [3210] */
    (xdc_Char)0x6e,  /* [3211] */
    (xdc_Char)0x6f,  /* [3212] */
    (xdc_Char)0x74,  /* [3213] */
    (xdc_Char)0x20,  /* [3214] */
    (xdc_Char)0x66,  /* [3215] */
    (xdc_Char)0x6f,  /* [3216] */
    (xdc_Char)0x75,  /* [3217] */
    (xdc_Char)0x6e,  /* [3218] */
    (xdc_Char)0x64,  /* [3219] */
    (xdc_Char)0x3a,  /* [3220] */
    (xdc_Char)0x20,  /* [3221] */
    (xdc_Char)0x30,  /* [3222] */
    (xdc_Char)0x78,  /* [3223] */
    (xdc_Char)0x25,  /* [3224] */
    (xdc_Char)0x78,  /* [3225] */
    (xdc_Char)0x0,  /* [3226] */
    (xdc_Char)0x45,  /* [3227] */
    (xdc_Char)0x5f,  /* [3228] */
    (xdc_Char)0x75,  /* [3229] */
    (xdc_Char)0x6e,  /* [3230] */
    (xdc_Char)0x70,  /* [3231] */
    (xdc_Char)0x6c,  /* [3232] */
    (xdc_Char)0x75,  /* [3233] */
    (xdc_Char)0x67,  /* [3234] */
    (xdc_Char)0x67,  /* [3235] */
    (xdc_Char)0x65,  /* [3236] */
    (xdc_Char)0x64,  /* [3237] */
    (xdc_Char)0x53,  /* [3238] */
    (xdc_Char)0x79,  /* [3239] */
    (xdc_Char)0x73,  /* [3240] */
    (xdc_Char)0x49,  /* [3241] */
    (xdc_Char)0x6e,  /* [3242] */
    (xdc_Char)0x74,  /* [3243] */
    (xdc_Char)0x3a,  /* [3244] */
    (xdc_Char)0x20,  /* [3245] */
    (xdc_Char)0x53,  /* [3246] */
    (xdc_Char)0x79,  /* [3247] */
    (xdc_Char)0x73,  /* [3248] */
    (xdc_Char)0x74,  /* [3249] */
    (xdc_Char)0x65,  /* [3250] */
    (xdc_Char)0x6d,  /* [3251] */
    (xdc_Char)0x20,  /* [3252] */
    (xdc_Char)0x49,  /* [3253] */
    (xdc_Char)0x6e,  /* [3254] */
    (xdc_Char)0x74,  /* [3255] */
    (xdc_Char)0x65,  /* [3256] */
    (xdc_Char)0x72,  /* [3257] */
    (xdc_Char)0x72,  /* [3258] */
    (xdc_Char)0x75,  /* [3259] */
    (xdc_Char)0x70,  /* [3260] */
    (xdc_Char)0x74,  /* [3261] */
    (xdc_Char)0x23,  /* [3262] */
    (xdc_Char)0x20,  /* [3263] */
    (xdc_Char)0x25,  /* [3264] */
    (xdc_Char)0x64,  /* [3265] */
    (xdc_Char)0x20,  /* [3266] */
    (xdc_Char)0x69,  /* [3267] */
    (xdc_Char)0x73,  /* [3268] */
    (xdc_Char)0x20,  /* [3269] */
    (xdc_Char)0x75,  /* [3270] */
    (xdc_Char)0x6e,  /* [3271] */
    (xdc_Char)0x70,  /* [3272] */
    (xdc_Char)0x6c,  /* [3273] */
    (xdc_Char)0x75,  /* [3274] */
    (xdc_Char)0x67,  /* [3275] */
    (xdc_Char)0x67,  /* [3276] */
    (xdc_Char)0x65,  /* [3277] */
    (xdc_Char)0x64,  /* [3278] */
    (xdc_Char)0x0,  /* [3279] */
    (xdc_Char)0x45,  /* [3280] */
    (xdc_Char)0x5f,  /* [3281] */
    (xdc_Char)0x73,  /* [3282] */
    (xdc_Char)0x74,  /* [3283] */
    (xdc_Char)0x61,  /* [3284] */
    (xdc_Char)0x63,  /* [3285] */
    (xdc_Char)0x6b,  /* [3286] */
    (xdc_Char)0x4f,  /* [3287] */
    (xdc_Char)0x76,  /* [3288] */
    (xdc_Char)0x65,  /* [3289] */
    (xdc_Char)0x72,  /* [3290] */
    (xdc_Char)0x66,  /* [3291] */
    (xdc_Char)0x6c,  /* [3292] */
    (xdc_Char)0x6f,  /* [3293] */
    (xdc_Char)0x77,  /* [3294] */
    (xdc_Char)0x3a,  /* [3295] */
    (xdc_Char)0x20,  /* [3296] */
    (xdc_Char)0x49,  /* [3297] */
    (xdc_Char)0x53,  /* [3298] */
    (xdc_Char)0x52,  /* [3299] */
    (xdc_Char)0x20,  /* [3300] */
    (xdc_Char)0x73,  /* [3301] */
    (xdc_Char)0x74,  /* [3302] */
    (xdc_Char)0x61,  /* [3303] */
    (xdc_Char)0x63,  /* [3304] */
    (xdc_Char)0x6b,  /* [3305] */
    (xdc_Char)0x20,  /* [3306] */
    (xdc_Char)0x6f,  /* [3307] */
    (xdc_Char)0x76,  /* [3308] */
    (xdc_Char)0x65,  /* [3309] */
    (xdc_Char)0x72,  /* [3310] */
    (xdc_Char)0x66,  /* [3311] */
    (xdc_Char)0x6c,  /* [3312] */
    (xdc_Char)0x6f,  /* [3313] */
    (xdc_Char)0x77,  /* [3314] */
    (xdc_Char)0x2e,  /* [3315] */
    (xdc_Char)0x0,  /* [3316] */
    (xdc_Char)0x45,  /* [3317] */
    (xdc_Char)0x5f,  /* [3318] */
    (xdc_Char)0x73,  /* [3319] */
    (xdc_Char)0x74,  /* [3320] */
    (xdc_Char)0x61,  /* [3321] */
    (xdc_Char)0x63,  /* [3322] */
    (xdc_Char)0x6b,  /* [3323] */
    (xdc_Char)0x4f,  /* [3324] */
    (xdc_Char)0x76,  /* [3325] */
    (xdc_Char)0x65,  /* [3326] */
    (xdc_Char)0x72,  /* [3327] */
    (xdc_Char)0x66,  /* [3328] */
    (xdc_Char)0x6c,  /* [3329] */
    (xdc_Char)0x6f,  /* [3330] */
    (xdc_Char)0x77,  /* [3331] */
    (xdc_Char)0x3a,  /* [3332] */
    (xdc_Char)0x20,  /* [3333] */
    (xdc_Char)0x54,  /* [3334] */
    (xdc_Char)0x61,  /* [3335] */
    (xdc_Char)0x73,  /* [3336] */
    (xdc_Char)0x6b,  /* [3337] */
    (xdc_Char)0x20,  /* [3338] */
    (xdc_Char)0x30,  /* [3339] */
    (xdc_Char)0x78,  /* [3340] */
    (xdc_Char)0x25,  /* [3341] */
    (xdc_Char)0x78,  /* [3342] */
    (xdc_Char)0x20,  /* [3343] */
    (xdc_Char)0x73,  /* [3344] */
    (xdc_Char)0x74,  /* [3345] */
    (xdc_Char)0x61,  /* [3346] */
    (xdc_Char)0x63,  /* [3347] */
    (xdc_Char)0x6b,  /* [3348] */
    (xdc_Char)0x20,  /* [3349] */
    (xdc_Char)0x6f,  /* [3350] */
    (xdc_Char)0x76,  /* [3351] */
    (xdc_Char)0x65,  /* [3352] */
    (xdc_Char)0x72,  /* [3353] */
    (xdc_Char)0x66,  /* [3354] */
    (xdc_Char)0x6c,  /* [3355] */
    (xdc_Char)0x6f,  /* [3356] */
    (xdc_Char)0x77,  /* [3357] */
    (xdc_Char)0x2e,  /* [3358] */
    (xdc_Char)0x0,  /* [3359] */
    (xdc_Char)0x45,  /* [3360] */
    (xdc_Char)0x5f,  /* [3361] */
    (xdc_Char)0x73,  /* [3362] */
    (xdc_Char)0x70,  /* [3363] */
    (xdc_Char)0x4f,  /* [3364] */
    (xdc_Char)0x75,  /* [3365] */
    (xdc_Char)0x74,  /* [3366] */
    (xdc_Char)0x4f,  /* [3367] */
    (xdc_Char)0x66,  /* [3368] */
    (xdc_Char)0x42,  /* [3369] */
    (xdc_Char)0x6f,  /* [3370] */
    (xdc_Char)0x75,  /* [3371] */
    (xdc_Char)0x6e,  /* [3372] */
    (xdc_Char)0x64,  /* [3373] */
    (xdc_Char)0x73,  /* [3374] */
    (xdc_Char)0x3a,  /* [3375] */
    (xdc_Char)0x20,  /* [3376] */
    (xdc_Char)0x54,  /* [3377] */
    (xdc_Char)0x61,  /* [3378] */
    (xdc_Char)0x73,  /* [3379] */
    (xdc_Char)0x6b,  /* [3380] */
    (xdc_Char)0x20,  /* [3381] */
    (xdc_Char)0x30,  /* [3382] */
    (xdc_Char)0x78,  /* [3383] */
    (xdc_Char)0x25,  /* [3384] */
    (xdc_Char)0x78,  /* [3385] */
    (xdc_Char)0x20,  /* [3386] */
    (xdc_Char)0x73,  /* [3387] */
    (xdc_Char)0x74,  /* [3388] */
    (xdc_Char)0x61,  /* [3389] */
    (xdc_Char)0x63,  /* [3390] */
    (xdc_Char)0x6b,  /* [3391] */
    (xdc_Char)0x20,  /* [3392] */
    (xdc_Char)0x65,  /* [3393] */
    (xdc_Char)0x72,  /* [3394] */
    (xdc_Char)0x72,  /* [3395] */
    (xdc_Char)0x6f,  /* [3396] */
    (xdc_Char)0x72,  /* [3397] */
    (xdc_Char)0x2c,  /* [3398] */
    (xdc_Char)0x20,  /* [3399] */
    (xdc_Char)0x53,  /* [3400] */
    (xdc_Char)0x50,  /* [3401] */
    (xdc_Char)0x20,  /* [3402] */
    (xdc_Char)0x3d,  /* [3403] */
    (xdc_Char)0x20,  /* [3404] */
    (xdc_Char)0x30,  /* [3405] */
    (xdc_Char)0x78,  /* [3406] */
    (xdc_Char)0x25,  /* [3407] */
    (xdc_Char)0x78,  /* [3408] */
    (xdc_Char)0x2e,  /* [3409] */
    (xdc_Char)0x0,  /* [3410] */
    (xdc_Char)0x45,  /* [3411] */
    (xdc_Char)0x5f,  /* [3412] */
    (xdc_Char)0x64,  /* [3413] */
    (xdc_Char)0x65,  /* [3414] */
    (xdc_Char)0x6c,  /* [3415] */
    (xdc_Char)0x65,  /* [3416] */
    (xdc_Char)0x74,  /* [3417] */
    (xdc_Char)0x65,  /* [3418] */
    (xdc_Char)0x4e,  /* [3419] */
    (xdc_Char)0x6f,  /* [3420] */
    (xdc_Char)0x74,  /* [3421] */
    (xdc_Char)0x41,  /* [3422] */
    (xdc_Char)0x6c,  /* [3423] */
    (xdc_Char)0x6c,  /* [3424] */
    (xdc_Char)0x6f,  /* [3425] */
    (xdc_Char)0x77,  /* [3426] */
    (xdc_Char)0x65,  /* [3427] */
    (xdc_Char)0x64,  /* [3428] */
    (xdc_Char)0x3a,  /* [3429] */
    (xdc_Char)0x20,  /* [3430] */
    (xdc_Char)0x54,  /* [3431] */
    (xdc_Char)0x61,  /* [3432] */
    (xdc_Char)0x73,  /* [3433] */
    (xdc_Char)0x6b,  /* [3434] */
    (xdc_Char)0x20,  /* [3435] */
    (xdc_Char)0x30,  /* [3436] */
    (xdc_Char)0x78,  /* [3437] */
    (xdc_Char)0x25,  /* [3438] */
    (xdc_Char)0x78,  /* [3439] */
    (xdc_Char)0x2e,  /* [3440] */
    (xdc_Char)0x0,  /* [3441] */
    (xdc_Char)0x45,  /* [3442] */
    (xdc_Char)0x5f,  /* [3443] */
    (xdc_Char)0x70,  /* [3444] */
    (xdc_Char)0x72,  /* [3445] */
    (xdc_Char)0x69,  /* [3446] */
    (xdc_Char)0x6f,  /* [3447] */
    (xdc_Char)0x72,  /* [3448] */
    (xdc_Char)0x69,  /* [3449] */
    (xdc_Char)0x74,  /* [3450] */
    (xdc_Char)0x79,  /* [3451] */
    (xdc_Char)0x3a,  /* [3452] */
    (xdc_Char)0x20,  /* [3453] */
    (xdc_Char)0x54,  /* [3454] */
    (xdc_Char)0x68,  /* [3455] */
    (xdc_Char)0x72,  /* [3456] */
    (xdc_Char)0x65,  /* [3457] */
    (xdc_Char)0x61,  /* [3458] */
    (xdc_Char)0x64,  /* [3459] */
    (xdc_Char)0x20,  /* [3460] */
    (xdc_Char)0x70,  /* [3461] */
    (xdc_Char)0x72,  /* [3462] */
    (xdc_Char)0x69,  /* [3463] */
    (xdc_Char)0x6f,  /* [3464] */
    (xdc_Char)0x72,  /* [3465] */
    (xdc_Char)0x69,  /* [3466] */
    (xdc_Char)0x74,  /* [3467] */
    (xdc_Char)0x79,  /* [3468] */
    (xdc_Char)0x20,  /* [3469] */
    (xdc_Char)0x69,  /* [3470] */
    (xdc_Char)0x73,  /* [3471] */
    (xdc_Char)0x20,  /* [3472] */
    (xdc_Char)0x69,  /* [3473] */
    (xdc_Char)0x6e,  /* [3474] */
    (xdc_Char)0x76,  /* [3475] */
    (xdc_Char)0x61,  /* [3476] */
    (xdc_Char)0x6c,  /* [3477] */
    (xdc_Char)0x69,  /* [3478] */
    (xdc_Char)0x64,  /* [3479] */
    (xdc_Char)0x20,  /* [3480] */
    (xdc_Char)0x25,  /* [3481] */
    (xdc_Char)0x64,  /* [3482] */
    (xdc_Char)0x0,  /* [3483] */
    (xdc_Char)0x45,  /* [3484] */
    (xdc_Char)0x5f,  /* [3485] */
    (xdc_Char)0x69,  /* [3486] */
    (xdc_Char)0x6e,  /* [3487] */
    (xdc_Char)0x76,  /* [3488] */
    (xdc_Char)0x61,  /* [3489] */
    (xdc_Char)0x6c,  /* [3490] */
    (xdc_Char)0x69,  /* [3491] */
    (xdc_Char)0x64,  /* [3492] */
    (xdc_Char)0x54,  /* [3493] */
    (xdc_Char)0x69,  /* [3494] */
    (xdc_Char)0x6d,  /* [3495] */
    (xdc_Char)0x65,  /* [3496] */
    (xdc_Char)0x72,  /* [3497] */
    (xdc_Char)0x3a,  /* [3498] */
    (xdc_Char)0x20,  /* [3499] */
    (xdc_Char)0x49,  /* [3500] */
    (xdc_Char)0x6e,  /* [3501] */
    (xdc_Char)0x76,  /* [3502] */
    (xdc_Char)0x61,  /* [3503] */
    (xdc_Char)0x6c,  /* [3504] */
    (xdc_Char)0x69,  /* [3505] */
    (xdc_Char)0x64,  /* [3506] */
    (xdc_Char)0x20,  /* [3507] */
    (xdc_Char)0x54,  /* [3508] */
    (xdc_Char)0x69,  /* [3509] */
    (xdc_Char)0x6d,  /* [3510] */
    (xdc_Char)0x65,  /* [3511] */
    (xdc_Char)0x72,  /* [3512] */
    (xdc_Char)0x20,  /* [3513] */
    (xdc_Char)0x49,  /* [3514] */
    (xdc_Char)0x64,  /* [3515] */
    (xdc_Char)0x20,  /* [3516] */
    (xdc_Char)0x25,  /* [3517] */
    (xdc_Char)0x64,  /* [3518] */
    (xdc_Char)0x0,  /* [3519] */
    (xdc_Char)0x45,  /* [3520] */
    (xdc_Char)0x5f,  /* [3521] */
    (xdc_Char)0x6e,  /* [3522] */
    (xdc_Char)0x6f,  /* [3523] */
    (xdc_Char)0x74,  /* [3524] */
    (xdc_Char)0x41,  /* [3525] */
    (xdc_Char)0x76,  /* [3526] */
    (xdc_Char)0x61,  /* [3527] */
    (xdc_Char)0x69,  /* [3528] */
    (xdc_Char)0x6c,  /* [3529] */
    (xdc_Char)0x61,  /* [3530] */
    (xdc_Char)0x62,  /* [3531] */
    (xdc_Char)0x6c,  /* [3532] */
    (xdc_Char)0x65,  /* [3533] */
    (xdc_Char)0x3a,  /* [3534] */
    (xdc_Char)0x20,  /* [3535] */
    (xdc_Char)0x54,  /* [3536] */
    (xdc_Char)0x69,  /* [3537] */
    (xdc_Char)0x6d,  /* [3538] */
    (xdc_Char)0x65,  /* [3539] */
    (xdc_Char)0x72,  /* [3540] */
    (xdc_Char)0x20,  /* [3541] */
    (xdc_Char)0x6e,  /* [3542] */
    (xdc_Char)0x6f,  /* [3543] */
    (xdc_Char)0x74,  /* [3544] */
    (xdc_Char)0x20,  /* [3545] */
    (xdc_Char)0x61,  /* [3546] */
    (xdc_Char)0x76,  /* [3547] */
    (xdc_Char)0x61,  /* [3548] */
    (xdc_Char)0x69,  /* [3549] */
    (xdc_Char)0x6c,  /* [3550] */
    (xdc_Char)0x61,  /* [3551] */
    (xdc_Char)0x62,  /* [3552] */
    (xdc_Char)0x6c,  /* [3553] */
    (xdc_Char)0x65,  /* [3554] */
    (xdc_Char)0x20,  /* [3555] */
    (xdc_Char)0x25,  /* [3556] */
    (xdc_Char)0x64,  /* [3557] */
    (xdc_Char)0x0,  /* [3558] */
    (xdc_Char)0x45,  /* [3559] */
    (xdc_Char)0x5f,  /* [3560] */
    (xdc_Char)0x63,  /* [3561] */
    (xdc_Char)0x61,  /* [3562] */
    (xdc_Char)0x6e,  /* [3563] */
    (xdc_Char)0x6e,  /* [3564] */
    (xdc_Char)0x6f,  /* [3565] */
    (xdc_Char)0x74,  /* [3566] */
    (xdc_Char)0x53,  /* [3567] */
    (xdc_Char)0x75,  /* [3568] */
    (xdc_Char)0x70,  /* [3569] */
    (xdc_Char)0x70,  /* [3570] */
    (xdc_Char)0x6f,  /* [3571] */
    (xdc_Char)0x72,  /* [3572] */
    (xdc_Char)0x74,  /* [3573] */
    (xdc_Char)0x3a,  /* [3574] */
    (xdc_Char)0x20,  /* [3575] */
    (xdc_Char)0x54,  /* [3576] */
    (xdc_Char)0x69,  /* [3577] */
    (xdc_Char)0x6d,  /* [3578] */
    (xdc_Char)0x65,  /* [3579] */
    (xdc_Char)0x72,  /* [3580] */
    (xdc_Char)0x20,  /* [3581] */
    (xdc_Char)0x63,  /* [3582] */
    (xdc_Char)0x61,  /* [3583] */
    (xdc_Char)0x6e,  /* [3584] */
    (xdc_Char)0x6e,  /* [3585] */
    (xdc_Char)0x6f,  /* [3586] */
    (xdc_Char)0x74,  /* [3587] */
    (xdc_Char)0x20,  /* [3588] */
    (xdc_Char)0x73,  /* [3589] */
    (xdc_Char)0x75,  /* [3590] */
    (xdc_Char)0x70,  /* [3591] */
    (xdc_Char)0x70,  /* [3592] */
    (xdc_Char)0x6f,  /* [3593] */
    (xdc_Char)0x72,  /* [3594] */
    (xdc_Char)0x74,  /* [3595] */
    (xdc_Char)0x20,  /* [3596] */
    (xdc_Char)0x72,  /* [3597] */
    (xdc_Char)0x65,  /* [3598] */
    (xdc_Char)0x71,  /* [3599] */
    (xdc_Char)0x75,  /* [3600] */
    (xdc_Char)0x65,  /* [3601] */
    (xdc_Char)0x73,  /* [3602] */
    (xdc_Char)0x74,  /* [3603] */
    (xdc_Char)0x65,  /* [3604] */
    (xdc_Char)0x64,  /* [3605] */
    (xdc_Char)0x20,  /* [3606] */
    (xdc_Char)0x70,  /* [3607] */
    (xdc_Char)0x65,  /* [3608] */
    (xdc_Char)0x72,  /* [3609] */
    (xdc_Char)0x69,  /* [3610] */
    (xdc_Char)0x6f,  /* [3611] */
    (xdc_Char)0x64,  /* [3612] */
    (xdc_Char)0x20,  /* [3613] */
    (xdc_Char)0x25,  /* [3614] */
    (xdc_Char)0x64,  /* [3615] */
    (xdc_Char)0x0,  /* [3616] */
    (xdc_Char)0x72,  /* [3617] */
    (xdc_Char)0x65,  /* [3618] */
    (xdc_Char)0x71,  /* [3619] */
    (xdc_Char)0x75,  /* [3620] */
    (xdc_Char)0x65,  /* [3621] */
    (xdc_Char)0x73,  /* [3622] */
    (xdc_Char)0x74,  /* [3623] */
    (xdc_Char)0x65,  /* [3624] */
    (xdc_Char)0x64,  /* [3625] */
    (xdc_Char)0x20,  /* [3626] */
    (xdc_Char)0x73,  /* [3627] */
    (xdc_Char)0x69,  /* [3628] */
    (xdc_Char)0x7a,  /* [3629] */
    (xdc_Char)0x65,  /* [3630] */
    (xdc_Char)0x20,  /* [3631] */
    (xdc_Char)0x69,  /* [3632] */
    (xdc_Char)0x73,  /* [3633] */
    (xdc_Char)0x20,  /* [3634] */
    (xdc_Char)0x74,  /* [3635] */
    (xdc_Char)0x6f,  /* [3636] */
    (xdc_Char)0x6f,  /* [3637] */
    (xdc_Char)0x20,  /* [3638] */
    (xdc_Char)0x62,  /* [3639] */
    (xdc_Char)0x69,  /* [3640] */
    (xdc_Char)0x67,  /* [3641] */
    (xdc_Char)0x3a,  /* [3642] */
    (xdc_Char)0x20,  /* [3643] */
    (xdc_Char)0x68,  /* [3644] */
    (xdc_Char)0x61,  /* [3645] */
    (xdc_Char)0x6e,  /* [3646] */
    (xdc_Char)0x64,  /* [3647] */
    (xdc_Char)0x6c,  /* [3648] */
    (xdc_Char)0x65,  /* [3649] */
    (xdc_Char)0x3d,  /* [3650] */
    (xdc_Char)0x30,  /* [3651] */
    (xdc_Char)0x78,  /* [3652] */
    (xdc_Char)0x25,  /* [3653] */
    (xdc_Char)0x78,  /* [3654] */
    (xdc_Char)0x2c,  /* [3655] */
    (xdc_Char)0x20,  /* [3656] */
    (xdc_Char)0x73,  /* [3657] */
    (xdc_Char)0x69,  /* [3658] */
    (xdc_Char)0x7a,  /* [3659] */
    (xdc_Char)0x65,  /* [3660] */
    (xdc_Char)0x3d,  /* [3661] */
    (xdc_Char)0x25,  /* [3662] */
    (xdc_Char)0x75,  /* [3663] */
    (xdc_Char)0x0,  /* [3664] */
    (xdc_Char)0x6f,  /* [3665] */
    (xdc_Char)0x75,  /* [3666] */
    (xdc_Char)0x74,  /* [3667] */
    (xdc_Char)0x20,  /* [3668] */
    (xdc_Char)0x6f,  /* [3669] */
    (xdc_Char)0x66,  /* [3670] */
    (xdc_Char)0x20,  /* [3671] */
    (xdc_Char)0x6d,  /* [3672] */
    (xdc_Char)0x65,  /* [3673] */
    (xdc_Char)0x6d,  /* [3674] */
    (xdc_Char)0x6f,  /* [3675] */
    (xdc_Char)0x72,  /* [3676] */
    (xdc_Char)0x79,  /* [3677] */
    (xdc_Char)0x3a,  /* [3678] */
    (xdc_Char)0x20,  /* [3679] */
    (xdc_Char)0x68,  /* [3680] */
    (xdc_Char)0x61,  /* [3681] */
    (xdc_Char)0x6e,  /* [3682] */
    (xdc_Char)0x64,  /* [3683] */
    (xdc_Char)0x6c,  /* [3684] */
    (xdc_Char)0x65,  /* [3685] */
    (xdc_Char)0x3d,  /* [3686] */
    (xdc_Char)0x30,  /* [3687] */
    (xdc_Char)0x78,  /* [3688] */
    (xdc_Char)0x25,  /* [3689] */
    (xdc_Char)0x78,  /* [3690] */
    (xdc_Char)0x2c,  /* [3691] */
    (xdc_Char)0x20,  /* [3692] */
    (xdc_Char)0x73,  /* [3693] */
    (xdc_Char)0x69,  /* [3694] */
    (xdc_Char)0x7a,  /* [3695] */
    (xdc_Char)0x65,  /* [3696] */
    (xdc_Char)0x3d,  /* [3697] */
    (xdc_Char)0x25,  /* [3698] */
    (xdc_Char)0x75,  /* [3699] */
    (xdc_Char)0x0,  /* [3700] */
    (xdc_Char)0x3c,  /* [3701] */
    (xdc_Char)0x2d,  /* [3702] */
    (xdc_Char)0x2d,  /* [3703] */
    (xdc_Char)0x20,  /* [3704] */
    (xdc_Char)0x63,  /* [3705] */
    (xdc_Char)0x6f,  /* [3706] */
    (xdc_Char)0x6e,  /* [3707] */
    (xdc_Char)0x73,  /* [3708] */
    (xdc_Char)0x74,  /* [3709] */
    (xdc_Char)0x72,  /* [3710] */
    (xdc_Char)0x75,  /* [3711] */
    (xdc_Char)0x63,  /* [3712] */
    (xdc_Char)0x74,  /* [3713] */
    (xdc_Char)0x3a,  /* [3714] */
    (xdc_Char)0x20,  /* [3715] */
    (xdc_Char)0x25,  /* [3716] */
    (xdc_Char)0x70,  /* [3717] */
    (xdc_Char)0x28,  /* [3718] */
    (xdc_Char)0x27,  /* [3719] */
    (xdc_Char)0x25,  /* [3720] */
    (xdc_Char)0x73,  /* [3721] */
    (xdc_Char)0x27,  /* [3722] */
    (xdc_Char)0x29,  /* [3723] */
    (xdc_Char)0x0,  /* [3724] */
    (xdc_Char)0x3c,  /* [3725] */
    (xdc_Char)0x2d,  /* [3726] */
    (xdc_Char)0x2d,  /* [3727] */
    (xdc_Char)0x20,  /* [3728] */
    (xdc_Char)0x63,  /* [3729] */
    (xdc_Char)0x72,  /* [3730] */
    (xdc_Char)0x65,  /* [3731] */
    (xdc_Char)0x61,  /* [3732] */
    (xdc_Char)0x74,  /* [3733] */
    (xdc_Char)0x65,  /* [3734] */
    (xdc_Char)0x3a,  /* [3735] */
    (xdc_Char)0x20,  /* [3736] */
    (xdc_Char)0x25,  /* [3737] */
    (xdc_Char)0x70,  /* [3738] */
    (xdc_Char)0x28,  /* [3739] */
    (xdc_Char)0x27,  /* [3740] */
    (xdc_Char)0x25,  /* [3741] */
    (xdc_Char)0x73,  /* [3742] */
    (xdc_Char)0x27,  /* [3743] */
    (xdc_Char)0x29,  /* [3744] */
    (xdc_Char)0x0,  /* [3745] */
    (xdc_Char)0x2d,  /* [3746] */
    (xdc_Char)0x2d,  /* [3747] */
    (xdc_Char)0x3e,  /* [3748] */
    (xdc_Char)0x20,  /* [3749] */
    (xdc_Char)0x64,  /* [3750] */
    (xdc_Char)0x65,  /* [3751] */
    (xdc_Char)0x73,  /* [3752] */
    (xdc_Char)0x74,  /* [3753] */
    (xdc_Char)0x72,  /* [3754] */
    (xdc_Char)0x75,  /* [3755] */
    (xdc_Char)0x63,  /* [3756] */
    (xdc_Char)0x74,  /* [3757] */
    (xdc_Char)0x3a,  /* [3758] */
    (xdc_Char)0x20,  /* [3759] */
    (xdc_Char)0x28,  /* [3760] */
    (xdc_Char)0x25,  /* [3761] */
    (xdc_Char)0x70,  /* [3762] */
    (xdc_Char)0x29,  /* [3763] */
    (xdc_Char)0x0,  /* [3764] */
    (xdc_Char)0x2d,  /* [3765] */
    (xdc_Char)0x2d,  /* [3766] */
    (xdc_Char)0x3e,  /* [3767] */
    (xdc_Char)0x20,  /* [3768] */
    (xdc_Char)0x64,  /* [3769] */
    (xdc_Char)0x65,  /* [3770] */
    (xdc_Char)0x6c,  /* [3771] */
    (xdc_Char)0x65,  /* [3772] */
    (xdc_Char)0x74,  /* [3773] */
    (xdc_Char)0x65,  /* [3774] */
    (xdc_Char)0x3a,  /* [3775] */
    (xdc_Char)0x20,  /* [3776] */
    (xdc_Char)0x28,  /* [3777] */
    (xdc_Char)0x25,  /* [3778] */
    (xdc_Char)0x70,  /* [3779] */
    (xdc_Char)0x29,  /* [3780] */
    (xdc_Char)0x0,  /* [3781] */
    (xdc_Char)0x45,  /* [3782] */
    (xdc_Char)0x52,  /* [3783] */
    (xdc_Char)0x52,  /* [3784] */
    (xdc_Char)0x4f,  /* [3785] */
    (xdc_Char)0x52,  /* [3786] */
    (xdc_Char)0x3a,  /* [3787] */
    (xdc_Char)0x20,  /* [3788] */
    (xdc_Char)0x25,  /* [3789] */
    (xdc_Char)0x24,  /* [3790] */
    (xdc_Char)0x46,  /* [3791] */
    (xdc_Char)0x25,  /* [3792] */
    (xdc_Char)0x24,  /* [3793] */
    (xdc_Char)0x53,  /* [3794] */
    (xdc_Char)0x0,  /* [3795] */
    (xdc_Char)0x57,  /* [3796] */
    (xdc_Char)0x41,  /* [3797] */
    (xdc_Char)0x52,  /* [3798] */
    (xdc_Char)0x4e,  /* [3799] */
    (xdc_Char)0x49,  /* [3800] */
    (xdc_Char)0x4e,  /* [3801] */
    (xdc_Char)0x47,  /* [3802] */
    (xdc_Char)0x3a,  /* [3803] */
    (xdc_Char)0x20,  /* [3804] */
    (xdc_Char)0x25,  /* [3805] */
    (xdc_Char)0x24,  /* [3806] */
    (xdc_Char)0x46,  /* [3807] */
    (xdc_Char)0x25,  /* [3808] */
    (xdc_Char)0x24,  /* [3809] */
    (xdc_Char)0x53,  /* [3810] */
    (xdc_Char)0x0,  /* [3811] */
    (xdc_Char)0x25,  /* [3812] */
    (xdc_Char)0x24,  /* [3813] */
    (xdc_Char)0x46,  /* [3814] */
    (xdc_Char)0x25,  /* [3815] */
    (xdc_Char)0x24,  /* [3816] */
    (xdc_Char)0x53,  /* [3817] */
    (xdc_Char)0x0,  /* [3818] */
    (xdc_Char)0x53,  /* [3819] */
    (xdc_Char)0x74,  /* [3820] */
    (xdc_Char)0x61,  /* [3821] */
    (xdc_Char)0x72,  /* [3822] */
    (xdc_Char)0x74,  /* [3823] */
    (xdc_Char)0x3a,  /* [3824] */
    (xdc_Char)0x20,  /* [3825] */
    (xdc_Char)0x25,  /* [3826] */
    (xdc_Char)0x24,  /* [3827] */
    (xdc_Char)0x53,  /* [3828] */
    (xdc_Char)0x0,  /* [3829] */
    (xdc_Char)0x53,  /* [3830] */
    (xdc_Char)0x74,  /* [3831] */
    (xdc_Char)0x6f,  /* [3832] */
    (xdc_Char)0x70,  /* [3833] */
    (xdc_Char)0x3a,  /* [3834] */
    (xdc_Char)0x20,  /* [3835] */
    (xdc_Char)0x25,  /* [3836] */
    (xdc_Char)0x24,  /* [3837] */
    (xdc_Char)0x53,  /* [3838] */
    (xdc_Char)0x0,  /* [3839] */
    (xdc_Char)0x53,  /* [3840] */
    (xdc_Char)0x74,  /* [3841] */
    (xdc_Char)0x61,  /* [3842] */
    (xdc_Char)0x72,  /* [3843] */
    (xdc_Char)0x74,  /* [3844] */
    (xdc_Char)0x49,  /* [3845] */
    (xdc_Char)0x6e,  /* [3846] */
    (xdc_Char)0x73,  /* [3847] */
    (xdc_Char)0x74,  /* [3848] */
    (xdc_Char)0x61,  /* [3849] */
    (xdc_Char)0x6e,  /* [3850] */
    (xdc_Char)0x63,  /* [3851] */
    (xdc_Char)0x65,  /* [3852] */
    (xdc_Char)0x3a,  /* [3853] */
    (xdc_Char)0x20,  /* [3854] */
    (xdc_Char)0x25,  /* [3855] */
    (xdc_Char)0x24,  /* [3856] */
    (xdc_Char)0x53,  /* [3857] */
    (xdc_Char)0x0,  /* [3858] */
    (xdc_Char)0x53,  /* [3859] */
    (xdc_Char)0x74,  /* [3860] */
    (xdc_Char)0x6f,  /* [3861] */
    (xdc_Char)0x70,  /* [3862] */
    (xdc_Char)0x49,  /* [3863] */
    (xdc_Char)0x6e,  /* [3864] */
    (xdc_Char)0x73,  /* [3865] */
    (xdc_Char)0x74,  /* [3866] */
    (xdc_Char)0x61,  /* [3867] */
    (xdc_Char)0x6e,  /* [3868] */
    (xdc_Char)0x63,  /* [3869] */
    (xdc_Char)0x65,  /* [3870] */
    (xdc_Char)0x3a,  /* [3871] */
    (xdc_Char)0x20,  /* [3872] */
    (xdc_Char)0x25,  /* [3873] */
    (xdc_Char)0x24,  /* [3874] */
    (xdc_Char)0x53,  /* [3875] */
    (xdc_Char)0x0,  /* [3876] */
    (xdc_Char)0x4c,  /* [3877] */
    (xdc_Char)0x4d,  /* [3878] */
    (xdc_Char)0x5f,  /* [3879] */
    (xdc_Char)0x62,  /* [3880] */
    (xdc_Char)0x65,  /* [3881] */
    (xdc_Char)0x67,  /* [3882] */
    (xdc_Char)0x69,  /* [3883] */
    (xdc_Char)0x6e,  /* [3884] */
    (xdc_Char)0x3a,  /* [3885] */
    (xdc_Char)0x20,  /* [3886] */
    (xdc_Char)0x68,  /* [3887] */
    (xdc_Char)0x77,  /* [3888] */
    (xdc_Char)0x69,  /* [3889] */
    (xdc_Char)0x3a,  /* [3890] */
    (xdc_Char)0x20,  /* [3891] */
    (xdc_Char)0x30,  /* [3892] */
    (xdc_Char)0x78,  /* [3893] */
    (xdc_Char)0x25,  /* [3894] */
    (xdc_Char)0x78,  /* [3895] */
    (xdc_Char)0x2c,  /* [3896] */
    (xdc_Char)0x20,  /* [3897] */
    (xdc_Char)0x66,  /* [3898] */
    (xdc_Char)0x75,  /* [3899] */
    (xdc_Char)0x6e,  /* [3900] */
    (xdc_Char)0x63,  /* [3901] */
    (xdc_Char)0x3a,  /* [3902] */
    (xdc_Char)0x20,  /* [3903] */
    (xdc_Char)0x30,  /* [3904] */
    (xdc_Char)0x78,  /* [3905] */
    (xdc_Char)0x25,  /* [3906] */
    (xdc_Char)0x78,  /* [3907] */
    (xdc_Char)0x2c,  /* [3908] */
    (xdc_Char)0x20,  /* [3909] */
    (xdc_Char)0x70,  /* [3910] */
    (xdc_Char)0x72,  /* [3911] */
    (xdc_Char)0x65,  /* [3912] */
    (xdc_Char)0x54,  /* [3913] */
    (xdc_Char)0x68,  /* [3914] */
    (xdc_Char)0x72,  /* [3915] */
    (xdc_Char)0x65,  /* [3916] */
    (xdc_Char)0x61,  /* [3917] */
    (xdc_Char)0x64,  /* [3918] */
    (xdc_Char)0x3a,  /* [3919] */
    (xdc_Char)0x20,  /* [3920] */
    (xdc_Char)0x25,  /* [3921] */
    (xdc_Char)0x64,  /* [3922] */
    (xdc_Char)0x2c,  /* [3923] */
    (xdc_Char)0x20,  /* [3924] */
    (xdc_Char)0x69,  /* [3925] */
    (xdc_Char)0x6e,  /* [3926] */
    (xdc_Char)0x74,  /* [3927] */
    (xdc_Char)0x4e,  /* [3928] */
    (xdc_Char)0x75,  /* [3929] */
    (xdc_Char)0x6d,  /* [3930] */
    (xdc_Char)0x3a,  /* [3931] */
    (xdc_Char)0x20,  /* [3932] */
    (xdc_Char)0x25,  /* [3933] */
    (xdc_Char)0x64,  /* [3934] */
    (xdc_Char)0x2c,  /* [3935] */
    (xdc_Char)0x20,  /* [3936] */
    (xdc_Char)0x69,  /* [3937] */
    (xdc_Char)0x72,  /* [3938] */
    (xdc_Char)0x70,  /* [3939] */
    (xdc_Char)0x3a,  /* [3940] */
    (xdc_Char)0x20,  /* [3941] */
    (xdc_Char)0x30,  /* [3942] */
    (xdc_Char)0x78,  /* [3943] */
    (xdc_Char)0x25,  /* [3944] */
    (xdc_Char)0x78,  /* [3945] */
    (xdc_Char)0x0,  /* [3946] */
    (xdc_Char)0x4c,  /* [3947] */
    (xdc_Char)0x44,  /* [3948] */
    (xdc_Char)0x5f,  /* [3949] */
    (xdc_Char)0x65,  /* [3950] */
    (xdc_Char)0x6e,  /* [3951] */
    (xdc_Char)0x64,  /* [3952] */
    (xdc_Char)0x3a,  /* [3953] */
    (xdc_Char)0x20,  /* [3954] */
    (xdc_Char)0x68,  /* [3955] */
    (xdc_Char)0x77,  /* [3956] */
    (xdc_Char)0x69,  /* [3957] */
    (xdc_Char)0x3a,  /* [3958] */
    (xdc_Char)0x20,  /* [3959] */
    (xdc_Char)0x30,  /* [3960] */
    (xdc_Char)0x78,  /* [3961] */
    (xdc_Char)0x25,  /* [3962] */
    (xdc_Char)0x78,  /* [3963] */
    (xdc_Char)0x0,  /* [3964] */
    (xdc_Char)0x4c,  /* [3965] */
    (xdc_Char)0x57,  /* [3966] */
    (xdc_Char)0x5f,  /* [3967] */
    (xdc_Char)0x64,  /* [3968] */
    (xdc_Char)0x65,  /* [3969] */
    (xdc_Char)0x6c,  /* [3970] */
    (xdc_Char)0x61,  /* [3971] */
    (xdc_Char)0x79,  /* [3972] */
    (xdc_Char)0x65,  /* [3973] */
    (xdc_Char)0x64,  /* [3974] */
    (xdc_Char)0x3a,  /* [3975] */
    (xdc_Char)0x20,  /* [3976] */
    (xdc_Char)0x64,  /* [3977] */
    (xdc_Char)0x65,  /* [3978] */
    (xdc_Char)0x6c,  /* [3979] */
    (xdc_Char)0x61,  /* [3980] */
    (xdc_Char)0x79,  /* [3981] */
    (xdc_Char)0x3a,  /* [3982] */
    (xdc_Char)0x20,  /* [3983] */
    (xdc_Char)0x25,  /* [3984] */
    (xdc_Char)0x64,  /* [3985] */
    (xdc_Char)0x0,  /* [3986] */
    (xdc_Char)0x4c,  /* [3987] */
    (xdc_Char)0x4d,  /* [3988] */
    (xdc_Char)0x5f,  /* [3989] */
    (xdc_Char)0x74,  /* [3990] */
    (xdc_Char)0x69,  /* [3991] */
    (xdc_Char)0x63,  /* [3992] */
    (xdc_Char)0x6b,  /* [3993] */
    (xdc_Char)0x3a,  /* [3994] */
    (xdc_Char)0x20,  /* [3995] */
    (xdc_Char)0x74,  /* [3996] */
    (xdc_Char)0x69,  /* [3997] */
    (xdc_Char)0x63,  /* [3998] */
    (xdc_Char)0x6b,  /* [3999] */
    (xdc_Char)0x3a,  /* [4000] */
    (xdc_Char)0x20,  /* [4001] */
    (xdc_Char)0x25,  /* [4002] */
    (xdc_Char)0x64,  /* [4003] */
    (xdc_Char)0x0,  /* [4004] */
    (xdc_Char)0x4c,  /* [4005] */
    (xdc_Char)0x4d,  /* [4006] */
    (xdc_Char)0x5f,  /* [4007] */
    (xdc_Char)0x62,  /* [4008] */
    (xdc_Char)0x65,  /* [4009] */
    (xdc_Char)0x67,  /* [4010] */
    (xdc_Char)0x69,  /* [4011] */
    (xdc_Char)0x6e,  /* [4012] */
    (xdc_Char)0x3a,  /* [4013] */
    (xdc_Char)0x20,  /* [4014] */
    (xdc_Char)0x63,  /* [4015] */
    (xdc_Char)0x6c,  /* [4016] */
    (xdc_Char)0x6b,  /* [4017] */
    (xdc_Char)0x3a,  /* [4018] */
    (xdc_Char)0x20,  /* [4019] */
    (xdc_Char)0x30,  /* [4020] */
    (xdc_Char)0x78,  /* [4021] */
    (xdc_Char)0x25,  /* [4022] */
    (xdc_Char)0x78,  /* [4023] */
    (xdc_Char)0x2c,  /* [4024] */
    (xdc_Char)0x20,  /* [4025] */
    (xdc_Char)0x66,  /* [4026] */
    (xdc_Char)0x75,  /* [4027] */
    (xdc_Char)0x6e,  /* [4028] */
    (xdc_Char)0x63,  /* [4029] */
    (xdc_Char)0x3a,  /* [4030] */
    (xdc_Char)0x20,  /* [4031] */
    (xdc_Char)0x30,  /* [4032] */
    (xdc_Char)0x78,  /* [4033] */
    (xdc_Char)0x25,  /* [4034] */
    (xdc_Char)0x78,  /* [4035] */
    (xdc_Char)0x0,  /* [4036] */
    (xdc_Char)0x4c,  /* [4037] */
    (xdc_Char)0x4d,  /* [4038] */
    (xdc_Char)0x5f,  /* [4039] */
    (xdc_Char)0x70,  /* [4040] */
    (xdc_Char)0x6f,  /* [4041] */
    (xdc_Char)0x73,  /* [4042] */
    (xdc_Char)0x74,  /* [4043] */
    (xdc_Char)0x3a,  /* [4044] */
    (xdc_Char)0x20,  /* [4045] */
    (xdc_Char)0x73,  /* [4046] */
    (xdc_Char)0x65,  /* [4047] */
    (xdc_Char)0x6d,  /* [4048] */
    (xdc_Char)0x3a,  /* [4049] */
    (xdc_Char)0x20,  /* [4050] */
    (xdc_Char)0x30,  /* [4051] */
    (xdc_Char)0x78,  /* [4052] */
    (xdc_Char)0x25,  /* [4053] */
    (xdc_Char)0x78,  /* [4054] */
    (xdc_Char)0x2c,  /* [4055] */
    (xdc_Char)0x20,  /* [4056] */
    (xdc_Char)0x63,  /* [4057] */
    (xdc_Char)0x6f,  /* [4058] */
    (xdc_Char)0x75,  /* [4059] */
    (xdc_Char)0x6e,  /* [4060] */
    (xdc_Char)0x74,  /* [4061] */
    (xdc_Char)0x3a,  /* [4062] */
    (xdc_Char)0x20,  /* [4063] */
    (xdc_Char)0x25,  /* [4064] */
    (xdc_Char)0x64,  /* [4065] */
    (xdc_Char)0x0,  /* [4066] */
    (xdc_Char)0x4c,  /* [4067] */
    (xdc_Char)0x4d,  /* [4068] */
    (xdc_Char)0x5f,  /* [4069] */
    (xdc_Char)0x70,  /* [4070] */
    (xdc_Char)0x65,  /* [4071] */
    (xdc_Char)0x6e,  /* [4072] */
    (xdc_Char)0x64,  /* [4073] */
    (xdc_Char)0x3a,  /* [4074] */
    (xdc_Char)0x20,  /* [4075] */
    (xdc_Char)0x73,  /* [4076] */
    (xdc_Char)0x65,  /* [4077] */
    (xdc_Char)0x6d,  /* [4078] */
    (xdc_Char)0x3a,  /* [4079] */
    (xdc_Char)0x20,  /* [4080] */
    (xdc_Char)0x30,  /* [4081] */
    (xdc_Char)0x78,  /* [4082] */
    (xdc_Char)0x25,  /* [4083] */
    (xdc_Char)0x78,  /* [4084] */
    (xdc_Char)0x2c,  /* [4085] */
    (xdc_Char)0x20,  /* [4086] */
    (xdc_Char)0x63,  /* [4087] */
    (xdc_Char)0x6f,  /* [4088] */
    (xdc_Char)0x75,  /* [4089] */
    (xdc_Char)0x6e,  /* [4090] */
    (xdc_Char)0x74,  /* [4091] */
    (xdc_Char)0x3a,  /* [4092] */
    (xdc_Char)0x20,  /* [4093] */
    (xdc_Char)0x25,  /* [4094] */
    (xdc_Char)0x64,  /* [4095] */
    (xdc_Char)0x2c,  /* [4096] */
    (xdc_Char)0x20,  /* [4097] */
    (xdc_Char)0x74,  /* [4098] */
    (xdc_Char)0x69,  /* [4099] */
    (xdc_Char)0x6d,  /* [4100] */
    (xdc_Char)0x65,  /* [4101] */
    (xdc_Char)0x6f,  /* [4102] */
    (xdc_Char)0x75,  /* [4103] */
    (xdc_Char)0x74,  /* [4104] */
    (xdc_Char)0x3a,  /* [4105] */
    (xdc_Char)0x20,  /* [4106] */
    (xdc_Char)0x25,  /* [4107] */
    (xdc_Char)0x64,  /* [4108] */
    (xdc_Char)0x0,  /* [4109] */
    (xdc_Char)0x4c,  /* [4110] */
    (xdc_Char)0x4d,  /* [4111] */
    (xdc_Char)0x5f,  /* [4112] */
    (xdc_Char)0x62,  /* [4113] */
    (xdc_Char)0x65,  /* [4114] */
    (xdc_Char)0x67,  /* [4115] */
    (xdc_Char)0x69,  /* [4116] */
    (xdc_Char)0x6e,  /* [4117] */
    (xdc_Char)0x3a,  /* [4118] */
    (xdc_Char)0x20,  /* [4119] */
    (xdc_Char)0x73,  /* [4120] */
    (xdc_Char)0x77,  /* [4121] */
    (xdc_Char)0x69,  /* [4122] */
    (xdc_Char)0x3a,  /* [4123] */
    (xdc_Char)0x20,  /* [4124] */
    (xdc_Char)0x30,  /* [4125] */
    (xdc_Char)0x78,  /* [4126] */
    (xdc_Char)0x25,  /* [4127] */
    (xdc_Char)0x78,  /* [4128] */
    (xdc_Char)0x2c,  /* [4129] */
    (xdc_Char)0x20,  /* [4130] */
    (xdc_Char)0x66,  /* [4131] */
    (xdc_Char)0x75,  /* [4132] */
    (xdc_Char)0x6e,  /* [4133] */
    (xdc_Char)0x63,  /* [4134] */
    (xdc_Char)0x3a,  /* [4135] */
    (xdc_Char)0x20,  /* [4136] */
    (xdc_Char)0x30,  /* [4137] */
    (xdc_Char)0x78,  /* [4138] */
    (xdc_Char)0x25,  /* [4139] */
    (xdc_Char)0x78,  /* [4140] */
    (xdc_Char)0x2c,  /* [4141] */
    (xdc_Char)0x20,  /* [4142] */
    (xdc_Char)0x70,  /* [4143] */
    (xdc_Char)0x72,  /* [4144] */
    (xdc_Char)0x65,  /* [4145] */
    (xdc_Char)0x54,  /* [4146] */
    (xdc_Char)0x68,  /* [4147] */
    (xdc_Char)0x72,  /* [4148] */
    (xdc_Char)0x65,  /* [4149] */
    (xdc_Char)0x61,  /* [4150] */
    (xdc_Char)0x64,  /* [4151] */
    (xdc_Char)0x3a,  /* [4152] */
    (xdc_Char)0x20,  /* [4153] */
    (xdc_Char)0x25,  /* [4154] */
    (xdc_Char)0x64,  /* [4155] */
    (xdc_Char)0x0,  /* [4156] */
    (xdc_Char)0x4c,  /* [4157] */
    (xdc_Char)0x44,  /* [4158] */
    (xdc_Char)0x5f,  /* [4159] */
    (xdc_Char)0x65,  /* [4160] */
    (xdc_Char)0x6e,  /* [4161] */
    (xdc_Char)0x64,  /* [4162] */
    (xdc_Char)0x3a,  /* [4163] */
    (xdc_Char)0x20,  /* [4164] */
    (xdc_Char)0x73,  /* [4165] */
    (xdc_Char)0x77,  /* [4166] */
    (xdc_Char)0x69,  /* [4167] */
    (xdc_Char)0x3a,  /* [4168] */
    (xdc_Char)0x20,  /* [4169] */
    (xdc_Char)0x30,  /* [4170] */
    (xdc_Char)0x78,  /* [4171] */
    (xdc_Char)0x25,  /* [4172] */
    (xdc_Char)0x78,  /* [4173] */
    (xdc_Char)0x0,  /* [4174] */
    (xdc_Char)0x4c,  /* [4175] */
    (xdc_Char)0x4d,  /* [4176] */
    (xdc_Char)0x5f,  /* [4177] */
    (xdc_Char)0x70,  /* [4178] */
    (xdc_Char)0x6f,  /* [4179] */
    (xdc_Char)0x73,  /* [4180] */
    (xdc_Char)0x74,  /* [4181] */
    (xdc_Char)0x3a,  /* [4182] */
    (xdc_Char)0x20,  /* [4183] */
    (xdc_Char)0x73,  /* [4184] */
    (xdc_Char)0x77,  /* [4185] */
    (xdc_Char)0x69,  /* [4186] */
    (xdc_Char)0x3a,  /* [4187] */
    (xdc_Char)0x20,  /* [4188] */
    (xdc_Char)0x30,  /* [4189] */
    (xdc_Char)0x78,  /* [4190] */
    (xdc_Char)0x25,  /* [4191] */
    (xdc_Char)0x78,  /* [4192] */
    (xdc_Char)0x2c,  /* [4193] */
    (xdc_Char)0x20,  /* [4194] */
    (xdc_Char)0x66,  /* [4195] */
    (xdc_Char)0x75,  /* [4196] */
    (xdc_Char)0x6e,  /* [4197] */
    (xdc_Char)0x63,  /* [4198] */
    (xdc_Char)0x3a,  /* [4199] */
    (xdc_Char)0x20,  /* [4200] */
    (xdc_Char)0x30,  /* [4201] */
    (xdc_Char)0x78,  /* [4202] */
    (xdc_Char)0x25,  /* [4203] */
    (xdc_Char)0x78,  /* [4204] */
    (xdc_Char)0x2c,  /* [4205] */
    (xdc_Char)0x20,  /* [4206] */
    (xdc_Char)0x70,  /* [4207] */
    (xdc_Char)0x72,  /* [4208] */
    (xdc_Char)0x69,  /* [4209] */
    (xdc_Char)0x3a,  /* [4210] */
    (xdc_Char)0x20,  /* [4211] */
    (xdc_Char)0x25,  /* [4212] */
    (xdc_Char)0x64,  /* [4213] */
    (xdc_Char)0x0,  /* [4214] */
    (xdc_Char)0x4c,  /* [4215] */
    (xdc_Char)0x4d,  /* [4216] */
    (xdc_Char)0x5f,  /* [4217] */
    (xdc_Char)0x73,  /* [4218] */
    (xdc_Char)0x77,  /* [4219] */
    (xdc_Char)0x69,  /* [4220] */
    (xdc_Char)0x74,  /* [4221] */
    (xdc_Char)0x63,  /* [4222] */
    (xdc_Char)0x68,  /* [4223] */
    (xdc_Char)0x3a,  /* [4224] */
    (xdc_Char)0x20,  /* [4225] */
    (xdc_Char)0x6f,  /* [4226] */
    (xdc_Char)0x6c,  /* [4227] */
    (xdc_Char)0x64,  /* [4228] */
    (xdc_Char)0x74,  /* [4229] */
    (xdc_Char)0x73,  /* [4230] */
    (xdc_Char)0x6b,  /* [4231] */
    (xdc_Char)0x3a,  /* [4232] */
    (xdc_Char)0x20,  /* [4233] */
    (xdc_Char)0x30,  /* [4234] */
    (xdc_Char)0x78,  /* [4235] */
    (xdc_Char)0x25,  /* [4236] */
    (xdc_Char)0x78,  /* [4237] */
    (xdc_Char)0x2c,  /* [4238] */
    (xdc_Char)0x20,  /* [4239] */
    (xdc_Char)0x6f,  /* [4240] */
    (xdc_Char)0x6c,  /* [4241] */
    (xdc_Char)0x64,  /* [4242] */
    (xdc_Char)0x66,  /* [4243] */
    (xdc_Char)0x75,  /* [4244] */
    (xdc_Char)0x6e,  /* [4245] */
    (xdc_Char)0x63,  /* [4246] */
    (xdc_Char)0x3a,  /* [4247] */
    (xdc_Char)0x20,  /* [4248] */
    (xdc_Char)0x30,  /* [4249] */
    (xdc_Char)0x78,  /* [4250] */
    (xdc_Char)0x25,  /* [4251] */
    (xdc_Char)0x78,  /* [4252] */
    (xdc_Char)0x2c,  /* [4253] */
    (xdc_Char)0x20,  /* [4254] */
    (xdc_Char)0x6e,  /* [4255] */
    (xdc_Char)0x65,  /* [4256] */
    (xdc_Char)0x77,  /* [4257] */
    (xdc_Char)0x74,  /* [4258] */
    (xdc_Char)0x73,  /* [4259] */
    (xdc_Char)0x6b,  /* [4260] */
    (xdc_Char)0x3a,  /* [4261] */
    (xdc_Char)0x20,  /* [4262] */
    (xdc_Char)0x30,  /* [4263] */
    (xdc_Char)0x78,  /* [4264] */
    (xdc_Char)0x25,  /* [4265] */
    (xdc_Char)0x78,  /* [4266] */
    (xdc_Char)0x2c,  /* [4267] */
    (xdc_Char)0x20,  /* [4268] */
    (xdc_Char)0x6e,  /* [4269] */
    (xdc_Char)0x65,  /* [4270] */
    (xdc_Char)0x77,  /* [4271] */
    (xdc_Char)0x66,  /* [4272] */
    (xdc_Char)0x75,  /* [4273] */
    (xdc_Char)0x6e,  /* [4274] */
    (xdc_Char)0x63,  /* [4275] */
    (xdc_Char)0x3a,  /* [4276] */
    (xdc_Char)0x20,  /* [4277] */
    (xdc_Char)0x30,  /* [4278] */
    (xdc_Char)0x78,  /* [4279] */
    (xdc_Char)0x25,  /* [4280] */
    (xdc_Char)0x78,  /* [4281] */
    (xdc_Char)0x0,  /* [4282] */
    (xdc_Char)0x4c,  /* [4283] */
    (xdc_Char)0x4d,  /* [4284] */
    (xdc_Char)0x5f,  /* [4285] */
    (xdc_Char)0x73,  /* [4286] */
    (xdc_Char)0x6c,  /* [4287] */
    (xdc_Char)0x65,  /* [4288] */
    (xdc_Char)0x65,  /* [4289] */
    (xdc_Char)0x70,  /* [4290] */
    (xdc_Char)0x3a,  /* [4291] */
    (xdc_Char)0x20,  /* [4292] */
    (xdc_Char)0x74,  /* [4293] */
    (xdc_Char)0x73,  /* [4294] */
    (xdc_Char)0x6b,  /* [4295] */
    (xdc_Char)0x3a,  /* [4296] */
    (xdc_Char)0x20,  /* [4297] */
    (xdc_Char)0x30,  /* [4298] */
    (xdc_Char)0x78,  /* [4299] */
    (xdc_Char)0x25,  /* [4300] */
    (xdc_Char)0x78,  /* [4301] */
    (xdc_Char)0x2c,  /* [4302] */
    (xdc_Char)0x20,  /* [4303] */
    (xdc_Char)0x66,  /* [4304] */
    (xdc_Char)0x75,  /* [4305] */
    (xdc_Char)0x6e,  /* [4306] */
    (xdc_Char)0x63,  /* [4307] */
    (xdc_Char)0x3a,  /* [4308] */
    (xdc_Char)0x20,  /* [4309] */
    (xdc_Char)0x30,  /* [4310] */
    (xdc_Char)0x78,  /* [4311] */
    (xdc_Char)0x25,  /* [4312] */
    (xdc_Char)0x78,  /* [4313] */
    (xdc_Char)0x2c,  /* [4314] */
    (xdc_Char)0x20,  /* [4315] */
    (xdc_Char)0x74,  /* [4316] */
    (xdc_Char)0x69,  /* [4317] */
    (xdc_Char)0x6d,  /* [4318] */
    (xdc_Char)0x65,  /* [4319] */
    (xdc_Char)0x6f,  /* [4320] */
    (xdc_Char)0x75,  /* [4321] */
    (xdc_Char)0x74,  /* [4322] */
    (xdc_Char)0x3a,  /* [4323] */
    (xdc_Char)0x20,  /* [4324] */
    (xdc_Char)0x25,  /* [4325] */
    (xdc_Char)0x64,  /* [4326] */
    (xdc_Char)0x0,  /* [4327] */
    (xdc_Char)0x4c,  /* [4328] */
    (xdc_Char)0x44,  /* [4329] */
    (xdc_Char)0x5f,  /* [4330] */
    (xdc_Char)0x72,  /* [4331] */
    (xdc_Char)0x65,  /* [4332] */
    (xdc_Char)0x61,  /* [4333] */
    (xdc_Char)0x64,  /* [4334] */
    (xdc_Char)0x79,  /* [4335] */
    (xdc_Char)0x3a,  /* [4336] */
    (xdc_Char)0x20,  /* [4337] */
    (xdc_Char)0x74,  /* [4338] */
    (xdc_Char)0x73,  /* [4339] */
    (xdc_Char)0x6b,  /* [4340] */
    (xdc_Char)0x3a,  /* [4341] */
    (xdc_Char)0x20,  /* [4342] */
    (xdc_Char)0x30,  /* [4343] */
    (xdc_Char)0x78,  /* [4344] */
    (xdc_Char)0x25,  /* [4345] */
    (xdc_Char)0x78,  /* [4346] */
    (xdc_Char)0x2c,  /* [4347] */
    (xdc_Char)0x20,  /* [4348] */
    (xdc_Char)0x66,  /* [4349] */
    (xdc_Char)0x75,  /* [4350] */
    (xdc_Char)0x6e,  /* [4351] */
    (xdc_Char)0x63,  /* [4352] */
    (xdc_Char)0x3a,  /* [4353] */
    (xdc_Char)0x20,  /* [4354] */
    (xdc_Char)0x30,  /* [4355] */
    (xdc_Char)0x78,  /* [4356] */
    (xdc_Char)0x25,  /* [4357] */
    (xdc_Char)0x78,  /* [4358] */
    (xdc_Char)0x2c,  /* [4359] */
    (xdc_Char)0x20,  /* [4360] */
    (xdc_Char)0x70,  /* [4361] */
    (xdc_Char)0x72,  /* [4362] */
    (xdc_Char)0x69,  /* [4363] */
    (xdc_Char)0x3a,  /* [4364] */
    (xdc_Char)0x20,  /* [4365] */
    (xdc_Char)0x25,  /* [4366] */
    (xdc_Char)0x64,  /* [4367] */
    (xdc_Char)0x0,  /* [4368] */
    (xdc_Char)0x4c,  /* [4369] */
    (xdc_Char)0x44,  /* [4370] */
    (xdc_Char)0x5f,  /* [4371] */
    (xdc_Char)0x62,  /* [4372] */
    (xdc_Char)0x6c,  /* [4373] */
    (xdc_Char)0x6f,  /* [4374] */
    (xdc_Char)0x63,  /* [4375] */
    (xdc_Char)0x6b,  /* [4376] */
    (xdc_Char)0x3a,  /* [4377] */
    (xdc_Char)0x20,  /* [4378] */
    (xdc_Char)0x74,  /* [4379] */
    (xdc_Char)0x73,  /* [4380] */
    (xdc_Char)0x6b,  /* [4381] */
    (xdc_Char)0x3a,  /* [4382] */
    (xdc_Char)0x20,  /* [4383] */
    (xdc_Char)0x30,  /* [4384] */
    (xdc_Char)0x78,  /* [4385] */
    (xdc_Char)0x25,  /* [4386] */
    (xdc_Char)0x78,  /* [4387] */
    (xdc_Char)0x2c,  /* [4388] */
    (xdc_Char)0x20,  /* [4389] */
    (xdc_Char)0x66,  /* [4390] */
    (xdc_Char)0x75,  /* [4391] */
    (xdc_Char)0x6e,  /* [4392] */
    (xdc_Char)0x63,  /* [4393] */
    (xdc_Char)0x3a,  /* [4394] */
    (xdc_Char)0x20,  /* [4395] */
    (xdc_Char)0x30,  /* [4396] */
    (xdc_Char)0x78,  /* [4397] */
    (xdc_Char)0x25,  /* [4398] */
    (xdc_Char)0x78,  /* [4399] */
    (xdc_Char)0x0,  /* [4400] */
    (xdc_Char)0x4c,  /* [4401] */
    (xdc_Char)0x4d,  /* [4402] */
    (xdc_Char)0x5f,  /* [4403] */
    (xdc_Char)0x79,  /* [4404] */
    (xdc_Char)0x69,  /* [4405] */
    (xdc_Char)0x65,  /* [4406] */
    (xdc_Char)0x6c,  /* [4407] */
    (xdc_Char)0x64,  /* [4408] */
    (xdc_Char)0x3a,  /* [4409] */
    (xdc_Char)0x20,  /* [4410] */
    (xdc_Char)0x74,  /* [4411] */
    (xdc_Char)0x73,  /* [4412] */
    (xdc_Char)0x6b,  /* [4413] */
    (xdc_Char)0x3a,  /* [4414] */
    (xdc_Char)0x20,  /* [4415] */
    (xdc_Char)0x30,  /* [4416] */
    (xdc_Char)0x78,  /* [4417] */
    (xdc_Char)0x25,  /* [4418] */
    (xdc_Char)0x78,  /* [4419] */
    (xdc_Char)0x2c,  /* [4420] */
    (xdc_Char)0x20,  /* [4421] */
    (xdc_Char)0x66,  /* [4422] */
    (xdc_Char)0x75,  /* [4423] */
    (xdc_Char)0x6e,  /* [4424] */
    (xdc_Char)0x63,  /* [4425] */
    (xdc_Char)0x3a,  /* [4426] */
    (xdc_Char)0x20,  /* [4427] */
    (xdc_Char)0x30,  /* [4428] */
    (xdc_Char)0x78,  /* [4429] */
    (xdc_Char)0x25,  /* [4430] */
    (xdc_Char)0x78,  /* [4431] */
    (xdc_Char)0x2c,  /* [4432] */
    (xdc_Char)0x20,  /* [4433] */
    (xdc_Char)0x63,  /* [4434] */
    (xdc_Char)0x75,  /* [4435] */
    (xdc_Char)0x72,  /* [4436] */
    (xdc_Char)0x72,  /* [4437] */
    (xdc_Char)0x54,  /* [4438] */
    (xdc_Char)0x68,  /* [4439] */
    (xdc_Char)0x72,  /* [4440] */
    (xdc_Char)0x65,  /* [4441] */
    (xdc_Char)0x61,  /* [4442] */
    (xdc_Char)0x64,  /* [4443] */
    (xdc_Char)0x3a,  /* [4444] */
    (xdc_Char)0x20,  /* [4445] */
    (xdc_Char)0x25,  /* [4446] */
    (xdc_Char)0x64,  /* [4447] */
    (xdc_Char)0x0,  /* [4448] */
    (xdc_Char)0x4c,  /* [4449] */
    (xdc_Char)0x4d,  /* [4450] */
    (xdc_Char)0x5f,  /* [4451] */
    (xdc_Char)0x73,  /* [4452] */
    (xdc_Char)0x65,  /* [4453] */
    (xdc_Char)0x74,  /* [4454] */
    (xdc_Char)0x50,  /* [4455] */
    (xdc_Char)0x72,  /* [4456] */
    (xdc_Char)0x69,  /* [4457] */
    (xdc_Char)0x3a,  /* [4458] */
    (xdc_Char)0x20,  /* [4459] */
    (xdc_Char)0x74,  /* [4460] */
    (xdc_Char)0x73,  /* [4461] */
    (xdc_Char)0x6b,  /* [4462] */
    (xdc_Char)0x3a,  /* [4463] */
    (xdc_Char)0x20,  /* [4464] */
    (xdc_Char)0x30,  /* [4465] */
    (xdc_Char)0x78,  /* [4466] */
    (xdc_Char)0x25,  /* [4467] */
    (xdc_Char)0x78,  /* [4468] */
    (xdc_Char)0x2c,  /* [4469] */
    (xdc_Char)0x20,  /* [4470] */
    (xdc_Char)0x66,  /* [4471] */
    (xdc_Char)0x75,  /* [4472] */
    (xdc_Char)0x6e,  /* [4473] */
    (xdc_Char)0x63,  /* [4474] */
    (xdc_Char)0x3a,  /* [4475] */
    (xdc_Char)0x20,  /* [4476] */
    (xdc_Char)0x30,  /* [4477] */
    (xdc_Char)0x78,  /* [4478] */
    (xdc_Char)0x25,  /* [4479] */
    (xdc_Char)0x78,  /* [4480] */
    (xdc_Char)0x2c,  /* [4481] */
    (xdc_Char)0x20,  /* [4482] */
    (xdc_Char)0x6f,  /* [4483] */
    (xdc_Char)0x6c,  /* [4484] */
    (xdc_Char)0x64,  /* [4485] */
    (xdc_Char)0x50,  /* [4486] */
    (xdc_Char)0x72,  /* [4487] */
    (xdc_Char)0x69,  /* [4488] */
    (xdc_Char)0x3a,  /* [4489] */
    (xdc_Char)0x20,  /* [4490] */
    (xdc_Char)0x25,  /* [4491] */
    (xdc_Char)0x64,  /* [4492] */
    (xdc_Char)0x2c,  /* [4493] */
    (xdc_Char)0x20,  /* [4494] */
    (xdc_Char)0x6e,  /* [4495] */
    (xdc_Char)0x65,  /* [4496] */
    (xdc_Char)0x77,  /* [4497] */
    (xdc_Char)0x50,  /* [4498] */
    (xdc_Char)0x72,  /* [4499] */
    (xdc_Char)0x69,  /* [4500] */
    (xdc_Char)0x20,  /* [4501] */
    (xdc_Char)0x25,  /* [4502] */
    (xdc_Char)0x64,  /* [4503] */
    (xdc_Char)0x0,  /* [4504] */
    (xdc_Char)0x4c,  /* [4505] */
    (xdc_Char)0x44,  /* [4506] */
    (xdc_Char)0x5f,  /* [4507] */
    (xdc_Char)0x65,  /* [4508] */
    (xdc_Char)0x78,  /* [4509] */
    (xdc_Char)0x69,  /* [4510] */
    (xdc_Char)0x74,  /* [4511] */
    (xdc_Char)0x3a,  /* [4512] */
    (xdc_Char)0x20,  /* [4513] */
    (xdc_Char)0x74,  /* [4514] */
    (xdc_Char)0x73,  /* [4515] */
    (xdc_Char)0x6b,  /* [4516] */
    (xdc_Char)0x3a,  /* [4517] */
    (xdc_Char)0x20,  /* [4518] */
    (xdc_Char)0x30,  /* [4519] */
    (xdc_Char)0x78,  /* [4520] */
    (xdc_Char)0x25,  /* [4521] */
    (xdc_Char)0x78,  /* [4522] */
    (xdc_Char)0x2c,  /* [4523] */
    (xdc_Char)0x20,  /* [4524] */
    (xdc_Char)0x66,  /* [4525] */
    (xdc_Char)0x75,  /* [4526] */
    (xdc_Char)0x6e,  /* [4527] */
    (xdc_Char)0x63,  /* [4528] */
    (xdc_Char)0x3a,  /* [4529] */
    (xdc_Char)0x20,  /* [4530] */
    (xdc_Char)0x30,  /* [4531] */
    (xdc_Char)0x78,  /* [4532] */
    (xdc_Char)0x25,  /* [4533] */
    (xdc_Char)0x78,  /* [4534] */
    (xdc_Char)0x0,  /* [4535] */
    (xdc_Char)0x4c,  /* [4536] */
    (xdc_Char)0x4d,  /* [4537] */
    (xdc_Char)0x5f,  /* [4538] */
    (xdc_Char)0x73,  /* [4539] */
    (xdc_Char)0x65,  /* [4540] */
    (xdc_Char)0x74,  /* [4541] */
    (xdc_Char)0x41,  /* [4542] */
    (xdc_Char)0x66,  /* [4543] */
    (xdc_Char)0x66,  /* [4544] */
    (xdc_Char)0x69,  /* [4545] */
    (xdc_Char)0x6e,  /* [4546] */
    (xdc_Char)0x69,  /* [4547] */
    (xdc_Char)0x74,  /* [4548] */
    (xdc_Char)0x79,  /* [4549] */
    (xdc_Char)0x3a,  /* [4550] */
    (xdc_Char)0x20,  /* [4551] */
    (xdc_Char)0x74,  /* [4552] */
    (xdc_Char)0x73,  /* [4553] */
    (xdc_Char)0x6b,  /* [4554] */
    (xdc_Char)0x3a,  /* [4555] */
    (xdc_Char)0x20,  /* [4556] */
    (xdc_Char)0x30,  /* [4557] */
    (xdc_Char)0x78,  /* [4558] */
    (xdc_Char)0x25,  /* [4559] */
    (xdc_Char)0x78,  /* [4560] */
    (xdc_Char)0x2c,  /* [4561] */
    (xdc_Char)0x20,  /* [4562] */
    (xdc_Char)0x66,  /* [4563] */
    (xdc_Char)0x75,  /* [4564] */
    (xdc_Char)0x6e,  /* [4565] */
    (xdc_Char)0x63,  /* [4566] */
    (xdc_Char)0x3a,  /* [4567] */
    (xdc_Char)0x20,  /* [4568] */
    (xdc_Char)0x30,  /* [4569] */
    (xdc_Char)0x78,  /* [4570] */
    (xdc_Char)0x25,  /* [4571] */
    (xdc_Char)0x78,  /* [4572] */
    (xdc_Char)0x2c,  /* [4573] */
    (xdc_Char)0x20,  /* [4574] */
    (xdc_Char)0x6f,  /* [4575] */
    (xdc_Char)0x6c,  /* [4576] */
    (xdc_Char)0x64,  /* [4577] */
    (xdc_Char)0x43,  /* [4578] */
    (xdc_Char)0x6f,  /* [4579] */
    (xdc_Char)0x72,  /* [4580] */
    (xdc_Char)0x65,  /* [4581] */
    (xdc_Char)0x3a,  /* [4582] */
    (xdc_Char)0x20,  /* [4583] */
    (xdc_Char)0x25,  /* [4584] */
    (xdc_Char)0x64,  /* [4585] */
    (xdc_Char)0x2c,  /* [4586] */
    (xdc_Char)0x20,  /* [4587] */
    (xdc_Char)0x6f,  /* [4588] */
    (xdc_Char)0x6c,  /* [4589] */
    (xdc_Char)0x64,  /* [4590] */
    (xdc_Char)0x41,  /* [4591] */
    (xdc_Char)0x66,  /* [4592] */
    (xdc_Char)0x66,  /* [4593] */
    (xdc_Char)0x69,  /* [4594] */
    (xdc_Char)0x6e,  /* [4595] */
    (xdc_Char)0x69,  /* [4596] */
    (xdc_Char)0x74,  /* [4597] */
    (xdc_Char)0x79,  /* [4598] */
    (xdc_Char)0x20,  /* [4599] */
    (xdc_Char)0x25,  /* [4600] */
    (xdc_Char)0x64,  /* [4601] */
    (xdc_Char)0x2c,  /* [4602] */
    (xdc_Char)0x20,  /* [4603] */
    (xdc_Char)0x6e,  /* [4604] */
    (xdc_Char)0x65,  /* [4605] */
    (xdc_Char)0x77,  /* [4606] */
    (xdc_Char)0x41,  /* [4607] */
    (xdc_Char)0x66,  /* [4608] */
    (xdc_Char)0x66,  /* [4609] */
    (xdc_Char)0x69,  /* [4610] */
    (xdc_Char)0x6e,  /* [4611] */
    (xdc_Char)0x69,  /* [4612] */
    (xdc_Char)0x74,  /* [4613] */
    (xdc_Char)0x79,  /* [4614] */
    (xdc_Char)0x20,  /* [4615] */
    (xdc_Char)0x25,  /* [4616] */
    (xdc_Char)0x64,  /* [4617] */
    (xdc_Char)0x0,  /* [4618] */
    (xdc_Char)0x4c,  /* [4619] */
    (xdc_Char)0x44,  /* [4620] */
    (xdc_Char)0x5f,  /* [4621] */
    (xdc_Char)0x73,  /* [4622] */
    (xdc_Char)0x63,  /* [4623] */
    (xdc_Char)0x68,  /* [4624] */
    (xdc_Char)0x65,  /* [4625] */
    (xdc_Char)0x64,  /* [4626] */
    (xdc_Char)0x75,  /* [4627] */
    (xdc_Char)0x6c,  /* [4628] */
    (xdc_Char)0x65,  /* [4629] */
    (xdc_Char)0x3a,  /* [4630] */
    (xdc_Char)0x20,  /* [4631] */
    (xdc_Char)0x63,  /* [4632] */
    (xdc_Char)0x6f,  /* [4633] */
    (xdc_Char)0x72,  /* [4634] */
    (xdc_Char)0x65,  /* [4635] */
    (xdc_Char)0x49,  /* [4636] */
    (xdc_Char)0x64,  /* [4637] */
    (xdc_Char)0x3a,  /* [4638] */
    (xdc_Char)0x20,  /* [4639] */
    (xdc_Char)0x25,  /* [4640] */
    (xdc_Char)0x64,  /* [4641] */
    (xdc_Char)0x2c,  /* [4642] */
    (xdc_Char)0x20,  /* [4643] */
    (xdc_Char)0x77,  /* [4644] */
    (xdc_Char)0x6f,  /* [4645] */
    (xdc_Char)0x72,  /* [4646] */
    (xdc_Char)0x6b,  /* [4647] */
    (xdc_Char)0x46,  /* [4648] */
    (xdc_Char)0x6c,  /* [4649] */
    (xdc_Char)0x61,  /* [4650] */
    (xdc_Char)0x67,  /* [4651] */
    (xdc_Char)0x3a,  /* [4652] */
    (xdc_Char)0x20,  /* [4653] */
    (xdc_Char)0x25,  /* [4654] */
    (xdc_Char)0x64,  /* [4655] */
    (xdc_Char)0x2c,  /* [4656] */
    (xdc_Char)0x20,  /* [4657] */
    (xdc_Char)0x63,  /* [4658] */
    (xdc_Char)0x75,  /* [4659] */
    (xdc_Char)0x72,  /* [4660] */
    (xdc_Char)0x53,  /* [4661] */
    (xdc_Char)0x65,  /* [4662] */
    (xdc_Char)0x74,  /* [4663] */
    (xdc_Char)0x4c,  /* [4664] */
    (xdc_Char)0x6f,  /* [4665] */
    (xdc_Char)0x63,  /* [4666] */
    (xdc_Char)0x61,  /* [4667] */
    (xdc_Char)0x6c,  /* [4668] */
    (xdc_Char)0x3a,  /* [4669] */
    (xdc_Char)0x20,  /* [4670] */
    (xdc_Char)0x25,  /* [4671] */
    (xdc_Char)0x64,  /* [4672] */
    (xdc_Char)0x2c,  /* [4673] */
    (xdc_Char)0x20,  /* [4674] */
    (xdc_Char)0x63,  /* [4675] */
    (xdc_Char)0x75,  /* [4676] */
    (xdc_Char)0x72,  /* [4677] */
    (xdc_Char)0x53,  /* [4678] */
    (xdc_Char)0x65,  /* [4679] */
    (xdc_Char)0x74,  /* [4680] */
    (xdc_Char)0x58,  /* [4681] */
    (xdc_Char)0x3a,  /* [4682] */
    (xdc_Char)0x20,  /* [4683] */
    (xdc_Char)0x25,  /* [4684] */
    (xdc_Char)0x64,  /* [4685] */
    (xdc_Char)0x2c,  /* [4686] */
    (xdc_Char)0x20,  /* [4687] */
    (xdc_Char)0x63,  /* [4688] */
    (xdc_Char)0x75,  /* [4689] */
    (xdc_Char)0x72,  /* [4690] */
    (xdc_Char)0x4d,  /* [4691] */
    (xdc_Char)0x61,  /* [4692] */
    (xdc_Char)0x73,  /* [4693] */
    (xdc_Char)0x6b,  /* [4694] */
    (xdc_Char)0x4c,  /* [4695] */
    (xdc_Char)0x6f,  /* [4696] */
    (xdc_Char)0x63,  /* [4697] */
    (xdc_Char)0x61,  /* [4698] */
    (xdc_Char)0x6c,  /* [4699] */
    (xdc_Char)0x3a,  /* [4700] */
    (xdc_Char)0x20,  /* [4701] */
    (xdc_Char)0x25,  /* [4702] */
    (xdc_Char)0x64,  /* [4703] */
    (xdc_Char)0x0,  /* [4704] */
    (xdc_Char)0x4c,  /* [4705] */
    (xdc_Char)0x44,  /* [4706] */
    (xdc_Char)0x5f,  /* [4707] */
    (xdc_Char)0x6e,  /* [4708] */
    (xdc_Char)0x6f,  /* [4709] */
    (xdc_Char)0x57,  /* [4710] */
    (xdc_Char)0x6f,  /* [4711] */
    (xdc_Char)0x72,  /* [4712] */
    (xdc_Char)0x6b,  /* [4713] */
    (xdc_Char)0x3a,  /* [4714] */
    (xdc_Char)0x20,  /* [4715] */
    (xdc_Char)0x63,  /* [4716] */
    (xdc_Char)0x6f,  /* [4717] */
    (xdc_Char)0x72,  /* [4718] */
    (xdc_Char)0x65,  /* [4719] */
    (xdc_Char)0x49,  /* [4720] */
    (xdc_Char)0x64,  /* [4721] */
    (xdc_Char)0x3a,  /* [4722] */
    (xdc_Char)0x20,  /* [4723] */
    (xdc_Char)0x25,  /* [4724] */
    (xdc_Char)0x64,  /* [4725] */
    (xdc_Char)0x2c,  /* [4726] */
    (xdc_Char)0x20,  /* [4727] */
    (xdc_Char)0x63,  /* [4728] */
    (xdc_Char)0x75,  /* [4729] */
    (xdc_Char)0x72,  /* [4730] */
    (xdc_Char)0x53,  /* [4731] */
    (xdc_Char)0x65,  /* [4732] */
    (xdc_Char)0x74,  /* [4733] */
    (xdc_Char)0x4c,  /* [4734] */
    (xdc_Char)0x6f,  /* [4735] */
    (xdc_Char)0x63,  /* [4736] */
    (xdc_Char)0x61,  /* [4737] */
    (xdc_Char)0x6c,  /* [4738] */
    (xdc_Char)0x3a,  /* [4739] */
    (xdc_Char)0x20,  /* [4740] */
    (xdc_Char)0x25,  /* [4741] */
    (xdc_Char)0x64,  /* [4742] */
    (xdc_Char)0x2c,  /* [4743] */
    (xdc_Char)0x20,  /* [4744] */
    (xdc_Char)0x63,  /* [4745] */
    (xdc_Char)0x75,  /* [4746] */
    (xdc_Char)0x72,  /* [4747] */
    (xdc_Char)0x53,  /* [4748] */
    (xdc_Char)0x65,  /* [4749] */
    (xdc_Char)0x74,  /* [4750] */
    (xdc_Char)0x58,  /* [4751] */
    (xdc_Char)0x3a,  /* [4752] */
    (xdc_Char)0x20,  /* [4753] */
    (xdc_Char)0x25,  /* [4754] */
    (xdc_Char)0x3a,  /* [4755] */
    (xdc_Char)0x64,  /* [4756] */
    (xdc_Char)0x2c,  /* [4757] */
    (xdc_Char)0x20,  /* [4758] */
    (xdc_Char)0x63,  /* [4759] */
    (xdc_Char)0x75,  /* [4760] */
    (xdc_Char)0x72,  /* [4761] */
    (xdc_Char)0x4d,  /* [4762] */
    (xdc_Char)0x61,  /* [4763] */
    (xdc_Char)0x73,  /* [4764] */
    (xdc_Char)0x6b,  /* [4765] */
    (xdc_Char)0x4c,  /* [4766] */
    (xdc_Char)0x6f,  /* [4767] */
    (xdc_Char)0x63,  /* [4768] */
    (xdc_Char)0x61,  /* [4769] */
    (xdc_Char)0x6c,  /* [4770] */
    (xdc_Char)0x3a,  /* [4771] */
    (xdc_Char)0x20,  /* [4772] */
    (xdc_Char)0x25,  /* [4773] */
    (xdc_Char)0x64,  /* [4774] */
    (xdc_Char)0x0,  /* [4775] */
    (xdc_Char)0x78,  /* [4776] */
    (xdc_Char)0x64,  /* [4777] */
    (xdc_Char)0x63,  /* [4778] */
    (xdc_Char)0x2e,  /* [4779] */
    (xdc_Char)0x0,  /* [4780] */
    (xdc_Char)0x72,  /* [4781] */
    (xdc_Char)0x75,  /* [4782] */
    (xdc_Char)0x6e,  /* [4783] */
    (xdc_Char)0x74,  /* [4784] */
    (xdc_Char)0x69,  /* [4785] */
    (xdc_Char)0x6d,  /* [4786] */
    (xdc_Char)0x65,  /* [4787] */
    (xdc_Char)0x2e,  /* [4788] */
    (xdc_Char)0x0,  /* [4789] */
    (xdc_Char)0x41,  /* [4790] */
    (xdc_Char)0x73,  /* [4791] */
    (xdc_Char)0x73,  /* [4792] */
    (xdc_Char)0x65,  /* [4793] */
    (xdc_Char)0x72,  /* [4794] */
    (xdc_Char)0x74,  /* [4795] */
    (xdc_Char)0x0,  /* [4796] */
    (xdc_Char)0x43,  /* [4797] */
    (xdc_Char)0x6f,  /* [4798] */
    (xdc_Char)0x72,  /* [4799] */
    (xdc_Char)0x65,  /* [4800] */
    (xdc_Char)0x0,  /* [4801] */
    (xdc_Char)0x44,  /* [4802] */
    (xdc_Char)0x65,  /* [4803] */
    (xdc_Char)0x66,  /* [4804] */
    (xdc_Char)0x61,  /* [4805] */
    (xdc_Char)0x75,  /* [4806] */
    (xdc_Char)0x6c,  /* [4807] */
    (xdc_Char)0x74,  /* [4808] */
    (xdc_Char)0x73,  /* [4809] */
    (xdc_Char)0x0,  /* [4810] */
    (xdc_Char)0x44,  /* [4811] */
    (xdc_Char)0x69,  /* [4812] */
    (xdc_Char)0x61,  /* [4813] */
    (xdc_Char)0x67,  /* [4814] */
    (xdc_Char)0x73,  /* [4815] */
    (xdc_Char)0x0,  /* [4816] */
    (xdc_Char)0x45,  /* [4817] */
    (xdc_Char)0x72,  /* [4818] */
    (xdc_Char)0x72,  /* [4819] */
    (xdc_Char)0x6f,  /* [4820] */
    (xdc_Char)0x72,  /* [4821] */
    (xdc_Char)0x0,  /* [4822] */
    (xdc_Char)0x47,  /* [4823] */
    (xdc_Char)0x61,  /* [4824] */
    (xdc_Char)0x74,  /* [4825] */
    (xdc_Char)0x65,  /* [4826] */
    (xdc_Char)0x0,  /* [4827] */
    (xdc_Char)0x4c,  /* [4828] */
    (xdc_Char)0x6f,  /* [4829] */
    (xdc_Char)0x67,  /* [4830] */
    (xdc_Char)0x0,  /* [4831] */
    (xdc_Char)0x4d,  /* [4832] */
    (xdc_Char)0x61,  /* [4833] */
    (xdc_Char)0x69,  /* [4834] */
    (xdc_Char)0x6e,  /* [4835] */
    (xdc_Char)0x0,  /* [4836] */
    (xdc_Char)0x4d,  /* [4837] */
    (xdc_Char)0x65,  /* [4838] */
    (xdc_Char)0x6d,  /* [4839] */
    (xdc_Char)0x6f,  /* [4840] */
    (xdc_Char)0x72,  /* [4841] */
    (xdc_Char)0x79,  /* [4842] */
    (xdc_Char)0x0,  /* [4843] */
    (xdc_Char)0x52,  /* [4844] */
    (xdc_Char)0x65,  /* [4845] */
    (xdc_Char)0x67,  /* [4846] */
    (xdc_Char)0x69,  /* [4847] */
    (xdc_Char)0x73,  /* [4848] */
    (xdc_Char)0x74,  /* [4849] */
    (xdc_Char)0x72,  /* [4850] */
    (xdc_Char)0x79,  /* [4851] */
    (xdc_Char)0x0,  /* [4852] */
    (xdc_Char)0x53,  /* [4853] */
    (xdc_Char)0x74,  /* [4854] */
    (xdc_Char)0x61,  /* [4855] */
    (xdc_Char)0x72,  /* [4856] */
    (xdc_Char)0x74,  /* [4857] */
    (xdc_Char)0x75,  /* [4858] */
    (xdc_Char)0x70,  /* [4859] */
    (xdc_Char)0x0,  /* [4860] */
    (xdc_Char)0x53,  /* [4861] */
    (xdc_Char)0x79,  /* [4862] */
    (xdc_Char)0x73,  /* [4863] */
    (xdc_Char)0x74,  /* [4864] */
    (xdc_Char)0x65,  /* [4865] */
    (xdc_Char)0x6d,  /* [4866] */
    (xdc_Char)0x0,  /* [4867] */
    (xdc_Char)0x53,  /* [4868] */
    (xdc_Char)0x79,  /* [4869] */
    (xdc_Char)0x73,  /* [4870] */
    (xdc_Char)0x4d,  /* [4871] */
    (xdc_Char)0x69,  /* [4872] */
    (xdc_Char)0x6e,  /* [4873] */
    (xdc_Char)0x0,  /* [4874] */
    (xdc_Char)0x54,  /* [4875] */
    (xdc_Char)0x65,  /* [4876] */
    (xdc_Char)0x78,  /* [4877] */
    (xdc_Char)0x74,  /* [4878] */
    (xdc_Char)0x0,  /* [4879] */
    (xdc_Char)0x54,  /* [4880] */
    (xdc_Char)0x69,  /* [4881] */
    (xdc_Char)0x6d,  /* [4882] */
    (xdc_Char)0x65,  /* [4883] */
    (xdc_Char)0x73,  /* [4884] */
    (xdc_Char)0x74,  /* [4885] */
    (xdc_Char)0x61,  /* [4886] */
    (xdc_Char)0x6d,  /* [4887] */
    (xdc_Char)0x70,  /* [4888] */
    (xdc_Char)0x0,  /* [4889] */
    (xdc_Char)0x74,  /* [4890] */
    (xdc_Char)0x69,  /* [4891] */
    (xdc_Char)0x2e,  /* [4892] */
    (xdc_Char)0x0,  /* [4893] */
    (xdc_Char)0x73,  /* [4894] */
    (xdc_Char)0x79,  /* [4895] */
    (xdc_Char)0x73,  /* [4896] */
    (xdc_Char)0x62,  /* [4897] */
    (xdc_Char)0x69,  /* [4898] */
    (xdc_Char)0x6f,  /* [4899] */
    (xdc_Char)0x73,  /* [4900] */
    (xdc_Char)0x2e,  /* [4901] */
    (xdc_Char)0x0,  /* [4902] */
    (xdc_Char)0x66,  /* [4903] */
    (xdc_Char)0x61,  /* [4904] */
    (xdc_Char)0x6d,  /* [4905] */
    (xdc_Char)0x69,  /* [4906] */
    (xdc_Char)0x6c,  /* [4907] */
    (xdc_Char)0x79,  /* [4908] */
    (xdc_Char)0x2e,  /* [4909] */
    (xdc_Char)0x0,  /* [4910] */
    (xdc_Char)0x63,  /* [4911] */
    (xdc_Char)0x36,  /* [4912] */
    (xdc_Char)0x34,  /* [4913] */
    (xdc_Char)0x70,  /* [4914] */
    (xdc_Char)0x2e,  /* [4915] */
    (xdc_Char)0x0,  /* [4916] */
    (xdc_Char)0x45,  /* [4917] */
    (xdc_Char)0x76,  /* [4918] */
    (xdc_Char)0x65,  /* [4919] */
    (xdc_Char)0x6e,  /* [4920] */
    (xdc_Char)0x74,  /* [4921] */
    (xdc_Char)0x43,  /* [4922] */
    (xdc_Char)0x6f,  /* [4923] */
    (xdc_Char)0x6d,  /* [4924] */
    (xdc_Char)0x62,  /* [4925] */
    (xdc_Char)0x69,  /* [4926] */
    (xdc_Char)0x6e,  /* [4927] */
    (xdc_Char)0x65,  /* [4928] */
    (xdc_Char)0x72,  /* [4929] */
    (xdc_Char)0x0,  /* [4930] */
    (xdc_Char)0x45,  /* [4931] */
    (xdc_Char)0x78,  /* [4932] */
    (xdc_Char)0x63,  /* [4933] */
    (xdc_Char)0x65,  /* [4934] */
    (xdc_Char)0x70,  /* [4935] */
    (xdc_Char)0x74,  /* [4936] */
    (xdc_Char)0x69,  /* [4937] */
    (xdc_Char)0x6f,  /* [4938] */
    (xdc_Char)0x6e,  /* [4939] */
    (xdc_Char)0x0,  /* [4940] */
    (xdc_Char)0x48,  /* [4941] */
    (xdc_Char)0x77,  /* [4942] */
    (xdc_Char)0x69,  /* [4943] */
    (xdc_Char)0x0,  /* [4944] */
    (xdc_Char)0x54,  /* [4945] */
    (xdc_Char)0x69,  /* [4946] */
    (xdc_Char)0x6d,  /* [4947] */
    (xdc_Char)0x65,  /* [4948] */
    (xdc_Char)0x73,  /* [4949] */
    (xdc_Char)0x74,  /* [4950] */
    (xdc_Char)0x61,  /* [4951] */
    (xdc_Char)0x6d,  /* [4952] */
    (xdc_Char)0x70,  /* [4953] */
    (xdc_Char)0x50,  /* [4954] */
    (xdc_Char)0x72,  /* [4955] */
    (xdc_Char)0x6f,  /* [4956] */
    (xdc_Char)0x76,  /* [4957] */
    (xdc_Char)0x69,  /* [4958] */
    (xdc_Char)0x64,  /* [4959] */
    (xdc_Char)0x65,  /* [4960] */
    (xdc_Char)0x72,  /* [4961] */
    (xdc_Char)0x0,  /* [4962] */
    (xdc_Char)0x42,  /* [4963] */
    (xdc_Char)0x49,  /* [4964] */
    (xdc_Char)0x4f,  /* [4965] */
    (xdc_Char)0x53,  /* [4966] */
    (xdc_Char)0x0,  /* [4967] */
    (xdc_Char)0x63,  /* [4968] */
    (xdc_Char)0x36,  /* [4969] */
    (xdc_Char)0x36,  /* [4970] */
    (xdc_Char)0x2e,  /* [4971] */
    (xdc_Char)0x0,  /* [4972] */
    (xdc_Char)0x74,  /* [4973] */
    (xdc_Char)0x63,  /* [4974] */
    (xdc_Char)0x69,  /* [4975] */
    (xdc_Char)0x36,  /* [4976] */
    (xdc_Char)0x36,  /* [4977] */
    (xdc_Char)0x78,  /* [4978] */
    (xdc_Char)0x78,  /* [4979] */
    (xdc_Char)0x2e,  /* [4980] */
    (xdc_Char)0x0,  /* [4981] */
    (xdc_Char)0x43,  /* [4982] */
    (xdc_Char)0x70,  /* [4983] */
    (xdc_Char)0x49,  /* [4984] */
    (xdc_Char)0x6e,  /* [4985] */
    (xdc_Char)0x74,  /* [4986] */
    (xdc_Char)0x63,  /* [4987] */
    (xdc_Char)0x0,  /* [4988] */
    (xdc_Char)0x68,  /* [4989] */
    (xdc_Char)0x61,  /* [4990] */
    (xdc_Char)0x6c,  /* [4991] */
    (xdc_Char)0x2e,  /* [4992] */
    (xdc_Char)0x0,  /* [4993] */
    (xdc_Char)0x54,  /* [4994] */
    (xdc_Char)0x69,  /* [4995] */
    (xdc_Char)0x6d,  /* [4996] */
    (xdc_Char)0x65,  /* [4997] */
    (xdc_Char)0x72,  /* [4998] */
    (xdc_Char)0x0,  /* [4999] */
    (xdc_Char)0x6b,  /* [5000] */
    (xdc_Char)0x6e,  /* [5001] */
    (xdc_Char)0x6c,  /* [5002] */
    (xdc_Char)0x2e,  /* [5003] */
    (xdc_Char)0x0,  /* [5004] */
    (xdc_Char)0x43,  /* [5005] */
    (xdc_Char)0x6c,  /* [5006] */
    (xdc_Char)0x6f,  /* [5007] */
    (xdc_Char)0x63,  /* [5008] */
    (xdc_Char)0x6b,  /* [5009] */
    (xdc_Char)0x0,  /* [5010] */
    (xdc_Char)0x49,  /* [5011] */
    (xdc_Char)0x64,  /* [5012] */
    (xdc_Char)0x6c,  /* [5013] */
    (xdc_Char)0x65,  /* [5014] */
    (xdc_Char)0x0,  /* [5015] */
    (xdc_Char)0x49,  /* [5016] */
    (xdc_Char)0x6e,  /* [5017] */
    (xdc_Char)0x74,  /* [5018] */
    (xdc_Char)0x72,  /* [5019] */
    (xdc_Char)0x69,  /* [5020] */
    (xdc_Char)0x6e,  /* [5021] */
    (xdc_Char)0x73,  /* [5022] */
    (xdc_Char)0x69,  /* [5023] */
    (xdc_Char)0x63,  /* [5024] */
    (xdc_Char)0x73,  /* [5025] */
    (xdc_Char)0x0,  /* [5026] */
    (xdc_Char)0x51,  /* [5027] */
    (xdc_Char)0x75,  /* [5028] */
    (xdc_Char)0x65,  /* [5029] */
    (xdc_Char)0x75,  /* [5030] */
    (xdc_Char)0x65,  /* [5031] */
    (xdc_Char)0x0,  /* [5032] */
    (xdc_Char)0x53,  /* [5033] */
    (xdc_Char)0x65,  /* [5034] */
    (xdc_Char)0x6d,  /* [5035] */
    (xdc_Char)0x61,  /* [5036] */
    (xdc_Char)0x70,  /* [5037] */
    (xdc_Char)0x68,  /* [5038] */
    (xdc_Char)0x6f,  /* [5039] */
    (xdc_Char)0x72,  /* [5040] */
    (xdc_Char)0x65,  /* [5041] */
    (xdc_Char)0x0,  /* [5042] */
    (xdc_Char)0x53,  /* [5043] */
    (xdc_Char)0x77,  /* [5044] */
    (xdc_Char)0x69,  /* [5045] */
    (xdc_Char)0x0,  /* [5046] */
    (xdc_Char)0x54,  /* [5047] */
    (xdc_Char)0x61,  /* [5048] */
    (xdc_Char)0x73,  /* [5049] */
    (xdc_Char)0x6b,  /* [5050] */
    (xdc_Char)0x0,  /* [5051] */
    (xdc_Char)0x43,  /* [5052] */
    (xdc_Char)0x61,  /* [5053] */
    (xdc_Char)0x63,  /* [5054] */
    (xdc_Char)0x68,  /* [5055] */
    (xdc_Char)0x65,  /* [5056] */
    (xdc_Char)0x0,  /* [5057] */
    (xdc_Char)0x67,  /* [5058] */
    (xdc_Char)0x61,  /* [5059] */
    (xdc_Char)0x74,  /* [5060] */
    (xdc_Char)0x65,  /* [5061] */
    (xdc_Char)0x73,  /* [5062] */
    (xdc_Char)0x2e,  /* [5063] */
    (xdc_Char)0x0,  /* [5064] */
    (xdc_Char)0x47,  /* [5065] */
    (xdc_Char)0x61,  /* [5066] */
    (xdc_Char)0x74,  /* [5067] */
    (xdc_Char)0x65,  /* [5068] */
    (xdc_Char)0x48,  /* [5069] */
    (xdc_Char)0x77,  /* [5070] */
    (xdc_Char)0x69,  /* [5071] */
    (xdc_Char)0x0,  /* [5072] */
    (xdc_Char)0x47,  /* [5073] */
    (xdc_Char)0x61,  /* [5074] */
    (xdc_Char)0x74,  /* [5075] */
    (xdc_Char)0x65,  /* [5076] */
    (xdc_Char)0x4d,  /* [5077] */
    (xdc_Char)0x75,  /* [5078] */
    (xdc_Char)0x74,  /* [5079] */
    (xdc_Char)0x65,  /* [5080] */
    (xdc_Char)0x78,  /* [5081] */
    (xdc_Char)0x0,  /* [5082] */
    (xdc_Char)0x63,  /* [5083] */
    (xdc_Char)0x36,  /* [5084] */
    (xdc_Char)0x32,  /* [5085] */
    (xdc_Char)0x2e,  /* [5086] */
    (xdc_Char)0x0,  /* [5087] */
    (xdc_Char)0x54,  /* [5088] */
    (xdc_Char)0x61,  /* [5089] */
    (xdc_Char)0x73,  /* [5090] */
    (xdc_Char)0x6b,  /* [5091] */
    (xdc_Char)0x53,  /* [5092] */
    (xdc_Char)0x75,  /* [5093] */
    (xdc_Char)0x70,  /* [5094] */
    (xdc_Char)0x70,  /* [5095] */
    (xdc_Char)0x6f,  /* [5096] */
    (xdc_Char)0x72,  /* [5097] */
    (xdc_Char)0x74,  /* [5098] */
    (xdc_Char)0x0,  /* [5099] */
    (xdc_Char)0x49,  /* [5100] */
    (xdc_Char)0x6e,  /* [5101] */
    (xdc_Char)0x74,  /* [5102] */
    (xdc_Char)0x72,  /* [5103] */
    (xdc_Char)0x69,  /* [5104] */
    (xdc_Char)0x6e,  /* [5105] */
    (xdc_Char)0x73,  /* [5106] */
    (xdc_Char)0x69,  /* [5107] */
    (xdc_Char)0x63,  /* [5108] */
    (xdc_Char)0x73,  /* [5109] */
    (xdc_Char)0x53,  /* [5110] */
    (xdc_Char)0x75,  /* [5111] */
    (xdc_Char)0x70,  /* [5112] */
    (xdc_Char)0x70,  /* [5113] */
    (xdc_Char)0x6f,  /* [5114] */
    (xdc_Char)0x72,  /* [5115] */
    (xdc_Char)0x74,  /* [5116] */
    (xdc_Char)0x0,  /* [5117] */
    (xdc_Char)0x74,  /* [5118] */
    (xdc_Char)0x69,  /* [5119] */
    (xdc_Char)0x6d,  /* [5120] */
    (xdc_Char)0x65,  /* [5121] */
    (xdc_Char)0x72,  /* [5122] */
    (xdc_Char)0x73,  /* [5123] */
    (xdc_Char)0x2e,  /* [5124] */
    (xdc_Char)0x0,  /* [5125] */
    (xdc_Char)0x74,  /* [5126] */
    (xdc_Char)0x69,  /* [5127] */
    (xdc_Char)0x6d,  /* [5128] */
    (xdc_Char)0x65,  /* [5129] */
    (xdc_Char)0x72,  /* [5130] */
    (xdc_Char)0x36,  /* [5131] */
    (xdc_Char)0x34,  /* [5132] */
    (xdc_Char)0x2e,  /* [5133] */
    (xdc_Char)0x0,  /* [5134] */
    (xdc_Char)0x74,  /* [5135] */
    (xdc_Char)0x63,  /* [5136] */
    (xdc_Char)0x69,  /* [5137] */
    (xdc_Char)0x36,  /* [5138] */
    (xdc_Char)0x34,  /* [5139] */
    (xdc_Char)0x38,  /* [5140] */
    (xdc_Char)0x38,  /* [5141] */
    (xdc_Char)0x2e,  /* [5142] */
    (xdc_Char)0x0,  /* [5143] */
    (xdc_Char)0x54,  /* [5144] */
    (xdc_Char)0x69,  /* [5145] */
    (xdc_Char)0x6d,  /* [5146] */
    (xdc_Char)0x65,  /* [5147] */
    (xdc_Char)0x72,  /* [5148] */
    (xdc_Char)0x53,  /* [5149] */
    (xdc_Char)0x75,  /* [5150] */
    (xdc_Char)0x70,  /* [5151] */
    (xdc_Char)0x70,  /* [5152] */
    (xdc_Char)0x6f,  /* [5153] */
    (xdc_Char)0x72,  /* [5154] */
    (xdc_Char)0x74,  /* [5155] */
    (xdc_Char)0x0,  /* [5156] */
    (xdc_Char)0x68,  /* [5157] */
    (xdc_Char)0x65,  /* [5158] */
    (xdc_Char)0x61,  /* [5159] */
    (xdc_Char)0x70,  /* [5160] */
    (xdc_Char)0x73,  /* [5161] */
    (xdc_Char)0x2e,  /* [5162] */
    (xdc_Char)0x0,  /* [5163] */
    (xdc_Char)0x48,  /* [5164] */
    (xdc_Char)0x65,  /* [5165] */
    (xdc_Char)0x61,  /* [5166] */
    (xdc_Char)0x70,  /* [5167] */
    (xdc_Char)0x4d,  /* [5168] */
    (xdc_Char)0x65,  /* [5169] */
    (xdc_Char)0x6d,  /* [5170] */
    (xdc_Char)0x0,  /* [5171] */
    (xdc_Char)0x74,  /* [5172] */
    (xdc_Char)0x69,  /* [5173] */
    (xdc_Char)0x2e,  /* [5174] */
    (xdc_Char)0x73,  /* [5175] */
    (xdc_Char)0x79,  /* [5176] */
    (xdc_Char)0x73,  /* [5177] */
    (xdc_Char)0x62,  /* [5178] */
    (xdc_Char)0x69,  /* [5179] */
    (xdc_Char)0x6f,  /* [5180] */
    (xdc_Char)0x73,  /* [5181] */
    (xdc_Char)0x2e,  /* [5182] */
    (xdc_Char)0x6b,  /* [5183] */
    (xdc_Char)0x6e,  /* [5184] */
    (xdc_Char)0x6c,  /* [5185] */
    (xdc_Char)0x2e,  /* [5186] */
    (xdc_Char)0x54,  /* [5187] */
    (xdc_Char)0x61,  /* [5188] */
    (xdc_Char)0x73,  /* [5189] */
    (xdc_Char)0x6b,  /* [5190] */
    (xdc_Char)0x2e,  /* [5191] */
    (xdc_Char)0x49,  /* [5192] */
    (xdc_Char)0x64,  /* [5193] */
    (xdc_Char)0x6c,  /* [5194] */
    (xdc_Char)0x65,  /* [5195] */
    (xdc_Char)0x54,  /* [5196] */
    (xdc_Char)0x61,  /* [5197] */
    (xdc_Char)0x73,  /* [5198] */
    (xdc_Char)0x6b,  /* [5199] */
    (xdc_Char)0x0,  /* [5200] */
};

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[53] = {
    {
        (xdc_Bits16)0x0,  /* left */
        (xdc_Bits16)0x0,  /* right */
    },  /* [0] */
    {
        (xdc_Bits16)0x12a8,  /* left */
        (xdc_Bits16)0x12ad,  /* right */
    },  /* [1] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12b6,  /* right */
    },  /* [2] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12bd,  /* right */
    },  /* [3] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12c2,  /* right */
    },  /* [4] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12cb,  /* right */
    },  /* [5] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12d1,  /* right */
    },  /* [6] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12d7,  /* right */
    },  /* [7] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12dc,  /* right */
    },  /* [8] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12e0,  /* right */
    },  /* [9] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12e5,  /* right */
    },  /* [10] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12ec,  /* right */
    },  /* [11] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12f5,  /* right */
    },  /* [12] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x12fd,  /* right */
    },  /* [13] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1304,  /* right */
    },  /* [14] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x130b,  /* right */
    },  /* [15] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1310,  /* right */
    },  /* [16] */
    {
        (xdc_Bits16)0x131a,  /* left */
        (xdc_Bits16)0x131e,  /* right */
    },  /* [17] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1327,  /* right */
    },  /* [18] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x132f,  /* right */
    },  /* [19] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x1335,  /* right */
    },  /* [20] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x1343,  /* right */
    },  /* [21] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x134d,  /* right */
    },  /* [22] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x1351,  /* right */
    },  /* [23] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1363,  /* right */
    },  /* [24] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1368,  /* right */
    },  /* [25] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x136d,  /* right */
    },  /* [26] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1376,  /* right */
    },  /* [27] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x137d,  /* right */
    },  /* [28] */
    {
        (xdc_Bits16)0x801c,  /* left */
        (xdc_Bits16)0x134d,  /* right */
    },  /* [29] */
    {
        (xdc_Bits16)0x801c,  /* left */
        (xdc_Bits16)0x1382,  /* right */
    },  /* [30] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1388,  /* right */
    },  /* [31] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x138d,  /* right */
    },  /* [32] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x1393,  /* right */
    },  /* [33] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x1398,  /* right */
    },  /* [34] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x13a3,  /* right */
    },  /* [35] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x13a9,  /* right */
    },  /* [36] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x13b3,  /* right */
    },  /* [37] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x13b7,  /* right */
    },  /* [38] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x13bc,  /* right */
    },  /* [39] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x13c2,  /* right */
    },  /* [40] */
    {
        (xdc_Bits16)0x8028,  /* left */
        (xdc_Bits16)0x13c9,  /* right */
    },  /* [41] */
    {
        (xdc_Bits16)0x8028,  /* left */
        (xdc_Bits16)0x13d1,  /* right */
    },  /* [42] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x13db,  /* right */
    },  /* [43] */
    {
        (xdc_Bits16)0x802b,  /* left */
        (xdc_Bits16)0x13e0,  /* right */
    },  /* [44] */
    {
        (xdc_Bits16)0x802b,  /* left */
        (xdc_Bits16)0x13ec,  /* right */
    },  /* [45] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x13fe,  /* right */
    },  /* [46] */
    {
        (xdc_Bits16)0x802e,  /* left */
        (xdc_Bits16)0x1406,  /* right */
    },  /* [47] */
    {
        (xdc_Bits16)0x802f,  /* left */
        (xdc_Bits16)0x1382,  /* right */
    },  /* [48] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x140f,  /* right */
    },  /* [49] */
    {
        (xdc_Bits16)0x8031,  /* left */
        (xdc_Bits16)0x1418,  /* right */
    },  /* [50] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1425,  /* right */
    },  /* [51] */
    {
        (xdc_Bits16)0x8033,  /* left */
        (xdc_Bits16)0x142c,  /* right */
    },  /* [52] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Text_Module__diagsEnabled xdc_runtime_Text_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Text_Module__diagsIncluded xdc_runtime_Text_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Text_Module__diagsMask xdc_runtime_Text_Module__diagsMask__C = ((CT__xdc_runtime_Text_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Text_Module__gateObj xdc_runtime_Text_Module__gateObj__C = ((CT__xdc_runtime_Text_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Text_Module__gatePrms xdc_runtime_Text_Module__gatePrms__C = ((CT__xdc_runtime_Text_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Text_Module__id xdc_runtime_Text_Module__id__C = (xdc_Bits16)0x800f;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerDefined xdc_runtime_Text_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerObj xdc_runtime_Text_Module__loggerObj__C = ((CT__xdc_runtime_Text_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn0 xdc_runtime_Text_Module__loggerFxn0__C = ((CT__xdc_runtime_Text_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn1 xdc_runtime_Text_Module__loggerFxn1__C = ((CT__xdc_runtime_Text_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn2 xdc_runtime_Text_Module__loggerFxn2__C = ((CT__xdc_runtime_Text_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn4 xdc_runtime_Text_Module__loggerFxn4__C = ((CT__xdc_runtime_Text_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn8 xdc_runtime_Text_Module__loggerFxn8__C = ((CT__xdc_runtime_Text_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Text_Module__startupDoneFxn xdc_runtime_Text_Module__startupDoneFxn__C = ((CT__xdc_runtime_Text_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Text_Object__count xdc_runtime_Text_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Text_Object__heap xdc_runtime_Text_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Text_Object__sizeof xdc_runtime_Text_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Text_Object__table xdc_runtime_Text_Object__table__C = 0;

/* nameUnknown__C */
__FAR__ const CT__xdc_runtime_Text_nameUnknown xdc_runtime_Text_nameUnknown__C = "{unknown-instance-name}";

/* nameEmpty__C */
__FAR__ const CT__xdc_runtime_Text_nameEmpty xdc_runtime_Text_nameEmpty__C = "{empty-instance-name}";

/* nameStatic__C */
__FAR__ const CT__xdc_runtime_Text_nameStatic xdc_runtime_Text_nameStatic__C = "{static-instance-name}";

/* isLoaded__C */
__FAR__ const CT__xdc_runtime_Text_isLoaded xdc_runtime_Text_isLoaded__C = 1;

/* charTab__C */
__FAR__ const CT__xdc_runtime_Text_charTab xdc_runtime_Text_charTab__C = ((CT__xdc_runtime_Text_charTab)xdc_runtime_Text_charTab__A);

/* nodeTab__C */
__FAR__ const CT__xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__C = ((CT__xdc_runtime_Text_nodeTab)xdc_runtime_Text_nodeTab__A);

/* charCnt__C */
__FAR__ const CT__xdc_runtime_Text_charCnt xdc_runtime_Text_charCnt__C = (xdc_Int16)0x1451;

/* nodeCnt__C */
__FAR__ const CT__xdc_runtime_Text_nodeCnt xdc_runtime_Text_nodeCnt__C = (xdc_Int16)0x35;

/* unnamedModsLastId__C */
__FAR__ const CT__xdc_runtime_Text_unnamedModsLastId xdc_runtime_Text_unnamedModsLastId__C = (xdc_UInt16)0x4000;

/* registryModsLastId__C */
__FAR__ const CT__xdc_runtime_Text_registryModsLastId xdc_runtime_Text_registryModsLastId__C = (xdc_UInt16)0x7fff;

/* visitRopeFxn__C */
__FAR__ const CT__xdc_runtime_Text_visitRopeFxn xdc_runtime_Text_visitRopeFxn__C = ((CT__xdc_runtime_Text_visitRopeFxn)((xdc_Fxn)xdc_runtime_Text_visitRope__I));

/* visitRopeFxn2__C */
__FAR__ const CT__xdc_runtime_Text_visitRopeFxn2 xdc_runtime_Text_visitRopeFxn2__C = ((CT__xdc_runtime_Text_visitRopeFxn2)((xdc_Fxn)xdc_runtime_Text_visitRope2__I));


/*
 * ======== xdc.runtime.Timestamp INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsEnabled xdc_runtime_Timestamp_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsIncluded xdc_runtime_Timestamp_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsMask xdc_runtime_Timestamp_Module__diagsMask__C = ((CT__xdc_runtime_Timestamp_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__gateObj xdc_runtime_Timestamp_Module__gateObj__C = ((CT__xdc_runtime_Timestamp_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__gatePrms xdc_runtime_Timestamp_Module__gatePrms__C = ((CT__xdc_runtime_Timestamp_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__id xdc_runtime_Timestamp_Module__id__C = (xdc_Bits16)0x8010;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerDefined xdc_runtime_Timestamp_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerObj xdc_runtime_Timestamp_Module__loggerObj__C = ((CT__xdc_runtime_Timestamp_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn0 xdc_runtime_Timestamp_Module__loggerFxn0__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn1 xdc_runtime_Timestamp_Module__loggerFxn1__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn2 xdc_runtime_Timestamp_Module__loggerFxn2__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn4 xdc_runtime_Timestamp_Module__loggerFxn4__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn8 xdc_runtime_Timestamp_Module__loggerFxn8__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__startupDoneFxn xdc_runtime_Timestamp_Module__startupDoneFxn__C = ((CT__xdc_runtime_Timestamp_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Timestamp_Object__count xdc_runtime_Timestamp_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Timestamp_Object__heap xdc_runtime_Timestamp_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Timestamp_Object__sizeof xdc_runtime_Timestamp_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Timestamp_Object__table xdc_runtime_Timestamp_Object__table__C = 0;


/*
 * ======== xdc.runtime.Timestamp_SupportProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.family.c64p.EventCombiner FUNCTION STUBS ========
 */

/* disableEvent__E */
xdc_Void ti_sysbios_family_c64p_EventCombiner_disableEvent__E( xdc_UInt evt ) 
{
    ti_sysbios_family_c64p_EventCombiner_disableEvent__F(evt);
}

/* enableEvent__E */
xdc_Void ti_sysbios_family_c64p_EventCombiner_enableEvent__E( xdc_UInt evt ) 
{
    ti_sysbios_family_c64p_EventCombiner_enableEvent__F(evt);
}

/* dispatch__E */
xdc_Void ti_sysbios_family_c64p_EventCombiner_dispatch__E( xdc_UInt evt ) 
{
    ti_sysbios_family_c64p_EventCombiner_dispatch__F(evt);
}

/* dispatchPlug__E */
xdc_Void ti_sysbios_family_c64p_EventCombiner_dispatchPlug__E( xdc_UInt evt, ti_sysbios_family_c64p_EventCombiner_FuncPtr fxn, xdc_UArg arg, xdc_Bool unmask ) 
{
    ti_sysbios_family_c64p_EventCombiner_dispatchPlug__F(evt, fxn, arg, unmask);
}

/* unused__E */
xdc_Void ti_sysbios_family_c64p_EventCombiner_unused__E( xdc_UArg arg ) 
{
    ti_sysbios_family_c64p_EventCombiner_unused__F(arg);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_EventCombiner_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_EventCombiner_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_Exception_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_Exception_Module_startup__F(state);
}


/*
 * ======== ti.sysbios.family.c64p.Hwi FUNCTION STUBS ========
 */

/* getStackInfo__E */
xdc_Bool ti_sysbios_family_c64p_Hwi_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo* stkInfo, xdc_Bool computeStackDepth ) 
{
    return ti_sysbios_family_c64p_Hwi_getStackInfo__F(stkInfo, computeStackDepth);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_Hwi_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_Hwi_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_TimestampProvider_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_TimestampProvider_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c66_Cache_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c66_Cache_Module_startup__F(state);
}


/*
 * ======== ti.sysbios.family.c66.tci66xx.CpIntc FUNCTION STUBS ========
 */

/* clearSysInt__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_clearSysInt__E( xdc_UInt id, xdc_UInt sysInt ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_clearSysInt__F(id, sysInt);
}

/* disableAllHostInts__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_disableAllHostInts__E( xdc_UInt id ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_disableAllHostInts__F(id);
}

/* disableHostInt__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_disableHostInt__E( xdc_UInt id, xdc_UInt hostInt ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_disableHostInt__F(id, hostInt);
}

/* disableSysInt__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_disableSysInt__E( xdc_UInt id, xdc_UInt sysInt ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_disableSysInt__F(id, sysInt);
}

/* dispatch__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_dispatch__E( xdc_UInt hostInt ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_dispatch__F(hostInt);
}

/* dispatchPlug__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_dispatchPlug__E( xdc_UInt sysInt, ti_sysbios_family_c66_tci66xx_CpIntc_FuncPtr fxn, xdc_UArg arg, xdc_Bool unmask ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_dispatchPlug__F(sysInt, fxn, arg, unmask);
}

/* enableAllHostInts__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_enableAllHostInts__E( xdc_UInt id ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_enableAllHostInts__F(id);
}

/* enableHostInt__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_enableHostInt__E( xdc_UInt id, xdc_UInt hostInt ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_enableHostInt__F(id, hostInt);
}

/* enableSysInt__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_enableSysInt__E( xdc_UInt id, xdc_UInt sysInt ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_enableSysInt__F(id, sysInt);
}

/* getEventId__E */
xdc_Int ti_sysbios_family_c66_tci66xx_CpIntc_getEventId__E( xdc_UInt hostInt ) 
{
    return ti_sysbios_family_c66_tci66xx_CpIntc_getEventId__F(hostInt);
}

/* getHostInt__E */
xdc_Int ti_sysbios_family_c66_tci66xx_CpIntc_getHostInt__E( xdc_UInt eventId ) 
{
    return ti_sysbios_family_c66_tci66xx_CpIntc_getHostInt__F(eventId);
}

/* mapSysIntToHostInt__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_mapSysIntToHostInt__E( xdc_UInt id, xdc_UInt sysInt, xdc_UInt hostInt ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_mapSysIntToHostInt__F(id, sysInt, hostInt);
}

/* postSysInt__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_postSysInt__E( xdc_UInt id, xdc_UInt sysInt ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_postSysInt__F(id, sysInt);
}

/* unused__E */
xdc_Void ti_sysbios_family_c66_tci66xx_CpIntc_unused__E( xdc_UArg arg ) 
{
    ti_sysbios_family_c66_tci66xx_CpIntc_unused__F(arg);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c66_tci66xx_CpIntc_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c66_tci66xx_CpIntc_Module_startup__F(state);
}


/*
 * ======== ti.sysbios.gates.GateHwi FUNCTION STUBS ========
 */

/* query__E */
xdc_Bool ti_sysbios_gates_GateHwi_query__E( xdc_Int qual ) 
{
    return ti_sysbios_gates_GateHwi_query__F(qual);
}


/*
 * ======== ti.sysbios.gates.GateMutex FUNCTION STUBS ========
 */

/* query__E */
xdc_Bool ti_sysbios_gates_GateMutex_query__E( xdc_Int qual ) 
{
    return ti_sysbios_gates_GateMutex_query__F(qual);
}


/*
 * ======== ti.sysbios.hal.Hwi FUNCTION STUBS ========
 */

/* getStackInfo__E */
xdc_Bool ti_sysbios_hal_Hwi_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo* stkInfo, xdc_Bool computeStackDepth ) 
{
    return ti_sysbios_hal_Hwi_getStackInfo__F(stkInfo, computeStackDepth);
}

/* Module_startup */
xdc_Int ti_sysbios_hal_Hwi_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_hal_Hwi_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_hal_Timer_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_hal_Timer_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_knl_Clock_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_knl_Clock_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_knl_Swi_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_knl_Swi_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_knl_Task_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_knl_Task_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_timers_timer64_Timer_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_timers_timer64_Timer_Module_startup__F(state);
}


/*
 * ======== xdc.runtime.Diags FUNCTION STUBS ========
 */

/* setMask__E */
xdc_Void xdc_runtime_Diags_setMask__E( xdc_String control ) 
{
    xdc_runtime_Diags_setMask__F(control);
}


/*
 * ======== xdc.runtime.Error FUNCTION STUBS ========
 */

/* check__E */
xdc_Bool xdc_runtime_Error_check__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_check__F(eb);
}

/* getData__E */
xdc_runtime_Error_Data* xdc_runtime_Error_getData__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getData__F(eb);
}

/* getCode__E */
xdc_UInt16 xdc_runtime_Error_getCode__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getCode__F(eb);
}

/* getId__E */
xdc_runtime_Error_Id xdc_runtime_Error_getId__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getId__F(eb);
}

/* getMsg__E */
xdc_String xdc_runtime_Error_getMsg__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getMsg__F(eb);
}

/* getSite__E */
xdc_runtime_Types_Site* xdc_runtime_Error_getSite__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getSite__F(eb);
}

/* init__E */
xdc_Void xdc_runtime_Error_init__E( xdc_runtime_Error_Block* eb ) 
{
    xdc_runtime_Error_init__F(eb);
}

/* print__E */
xdc_Void xdc_runtime_Error_print__E( xdc_runtime_Error_Block* eb ) 
{
    xdc_runtime_Error_print__F(eb);
}

/* raiseX__E */
xdc_Void xdc_runtime_Error_raiseX__E( xdc_runtime_Error_Block* eb, xdc_runtime_Types_ModuleId mod, xdc_String file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 ) 
{
    xdc_runtime_Error_raiseX__F(eb, mod, file, line, id, arg1, arg2);
}


/*
 * ======== xdc.runtime.Gate FUNCTION STUBS ========
 */

/* enterSystem__E */
xdc_IArg xdc_runtime_Gate_enterSystem__E( void ) 
{
    return xdc_runtime_Gate_enterSystem__F();
}

/* leaveSystem__E */
xdc_Void xdc_runtime_Gate_leaveSystem__E( xdc_IArg key ) 
{
    xdc_runtime_Gate_leaveSystem__F(key);
}


/*
 * ======== xdc.runtime.Log FUNCTION STUBS ========
 */

/* doPrint__E */
xdc_Void xdc_runtime_Log_doPrint__E( xdc_runtime_Log_EventRec* evRec ) 
{
    xdc_runtime_Log_doPrint__F(evRec);
}


/*
 * ======== xdc.runtime.Memory FUNCTION STUBS ========
 */

/* alloc__E */
xdc_Ptr xdc_runtime_Memory_alloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Memory_alloc__F(heap, size, align, eb);
}

/* calloc__E */
xdc_Ptr xdc_runtime_Memory_calloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Memory_calloc__F(heap, size, align, eb);
}

/* free__E */
xdc_Void xdc_runtime_Memory_free__E( xdc_runtime_IHeap_Handle heap, xdc_Ptr block, xdc_SizeT size ) 
{
    xdc_runtime_Memory_free__F(heap, block, size);
}

/* getStats__E */
xdc_Void xdc_runtime_Memory_getStats__E( xdc_runtime_IHeap_Handle heap, xdc_runtime_Memory_Stats* stats ) 
{
    xdc_runtime_Memory_getStats__F(heap, stats);
}

/* query__E */
xdc_Bool xdc_runtime_Memory_query__E( xdc_runtime_IHeap_Handle heap, xdc_Int qual ) 
{
    return xdc_runtime_Memory_query__F(heap, qual);
}

/* getMaxDefaultTypeAlign__E */
xdc_SizeT xdc_runtime_Memory_getMaxDefaultTypeAlign__E( void ) 
{
    return xdc_runtime_Memory_getMaxDefaultTypeAlign__F();
}

/* valloc__E */
xdc_Ptr xdc_runtime_Memory_valloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_Char value, xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Memory_valloc__F(heap, size, align, value, eb);
}


/*
 * ======== xdc.runtime.Registry FUNCTION STUBS ========
 */

/* addModule__E */
xdc_runtime_Registry_Result xdc_runtime_Registry_addModule__E( xdc_runtime_Registry_Desc* desc, xdc_String modName ) 
{
    return xdc_runtime_Registry_addModule__F(desc, modName);
}

/* findByName__E */
xdc_runtime_Registry_Desc* xdc_runtime_Registry_findByName__E( xdc_String modName ) 
{
    return xdc_runtime_Registry_findByName__F(modName);
}

/* findByNamePattern__E */
xdc_runtime_Registry_Desc* xdc_runtime_Registry_findByNamePattern__E( xdc_String namePat, xdc_Int len, xdc_runtime_Registry_Desc* prev ) 
{
    return xdc_runtime_Registry_findByNamePattern__F(namePat, len, prev);
}

/* findById__E */
xdc_runtime_Registry_Desc* xdc_runtime_Registry_findById__E( xdc_runtime_Types_ModuleId mid ) 
{
    return xdc_runtime_Registry_findById__F(mid);
}

/* getMask__E */
xdc_Bool xdc_runtime_Registry_getMask__E( xdc_String name, xdc_runtime_Types_DiagsMask* mask ) 
{
    return xdc_runtime_Registry_getMask__F(name, mask);
}

/* isMember__E */
xdc_Bool xdc_runtime_Registry_isMember__E( xdc_runtime_Types_ModuleId mid ) 
{
    return xdc_runtime_Registry_isMember__F(mid);
}

/* getNextModule__E */
xdc_runtime_Registry_Desc* xdc_runtime_Registry_getNextModule__E( xdc_runtime_Registry_Desc* desc ) 
{
    return xdc_runtime_Registry_getNextModule__F(desc);
}

/* getModuleName__E */
xdc_String xdc_runtime_Registry_getModuleName__E( xdc_runtime_Registry_Desc* desc ) 
{
    return xdc_runtime_Registry_getModuleName__F(desc);
}

/* getModuleId__E */
xdc_runtime_Types_ModuleId xdc_runtime_Registry_getModuleId__E( xdc_runtime_Registry_Desc* desc ) 
{
    return xdc_runtime_Registry_getModuleId__F(desc);
}


/*
 * ======== xdc.runtime.Startup FUNCTION STUBS ========
 */

/* exec__E */
xdc_Void xdc_runtime_Startup_exec__E( void ) 
{
    xdc_runtime_Startup_exec__F();
}

/* rtsDone__E */
xdc_Bool xdc_runtime_Startup_rtsDone__E( void ) 
{
    return xdc_runtime_Startup_rtsDone__F();
}


/*
 * ======== xdc.runtime.SysMin FUNCTION STUBS ========
 */

/* abort__E */
xdc_Void xdc_runtime_SysMin_abort__E( xdc_String str ) 
{
    xdc_runtime_SysMin_abort__F(str);
}

/* exit__E */
xdc_Void xdc_runtime_SysMin_exit__E( xdc_Int stat ) 
{
    xdc_runtime_SysMin_exit__F(stat);
}

/* flush__E */
xdc_Void xdc_runtime_SysMin_flush__E( void ) 
{
    xdc_runtime_SysMin_flush__F();
}

/* putch__E */
xdc_Void xdc_runtime_SysMin_putch__E( xdc_Char ch ) 
{
    xdc_runtime_SysMin_putch__F(ch);
}

/* ready__E */
xdc_Bool xdc_runtime_SysMin_ready__E( void ) 
{
    return xdc_runtime_SysMin_ready__F();
}

/* Module_startup */
xdc_Int xdc_runtime_SysMin_Module_startup__E( xdc_Int state )
{
    return xdc_runtime_SysMin_Module_startup__F(state);
}


/*
 * ======== xdc.runtime.System FUNCTION STUBS ========
 */

/* abort__E */
xdc_Void xdc_runtime_System_abort__E( xdc_String str ) 
{
    xdc_runtime_System_abort__F(str);
}

/* atexit__E */
xdc_Bool xdc_runtime_System_atexit__E( xdc_runtime_System_AtexitHandler handler ) 
{
    return xdc_runtime_System_atexit__F(handler);
}

/* exit__E */
xdc_Void xdc_runtime_System_exit__E( xdc_Int stat ) 
{
    xdc_runtime_System_exit__F(stat);
}

/* putch__E */
xdc_Void xdc_runtime_System_putch__E( xdc_Char ch ) 
{
    xdc_runtime_System_putch__F(ch);
}

/* flush__E */
xdc_Void xdc_runtime_System_flush__E( void ) 
{
    xdc_runtime_System_flush__F();
}

/* printf_va__E */
xdc_Int xdc_runtime_System_printf_va__E( xdc_String fmt, va_list __va ) 
{
    return xdc_runtime_System_printf_va__F(fmt, __va);
}

/* printf__E */
xdc_Int xdc_runtime_System_printf__E( xdc_String fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_printf_va__F(fmt, __va);

    va_end(__va);
    return __ret;
}

/* aprintf_va__E */
xdc_Int xdc_runtime_System_aprintf_va__E( xdc_String fmt, va_list __va ) 
{
    return xdc_runtime_System_aprintf_va__F(fmt, __va);
}

/* aprintf__E */
xdc_Int xdc_runtime_System_aprintf__E( xdc_String fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_aprintf_va__F(fmt, __va);

    va_end(__va);
    return __ret;
}

/* sprintf_va__E */
xdc_Int xdc_runtime_System_sprintf_va__E( xdc_Char buf[], xdc_String fmt, va_list __va ) 
{
    return xdc_runtime_System_sprintf_va__F(buf, fmt, __va);
}

/* sprintf__E */
xdc_Int xdc_runtime_System_sprintf__E( xdc_Char buf[], xdc_String fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_sprintf_va__F(buf, fmt, __va);

    va_end(__va);
    return __ret;
}

/* asprintf_va__E */
xdc_Int xdc_runtime_System_asprintf_va__E( xdc_Char buf[], xdc_String fmt, va_list __va ) 
{
    return xdc_runtime_System_asprintf_va__F(buf, fmt, __va);
}

/* asprintf__E */
xdc_Int xdc_runtime_System_asprintf__E( xdc_Char buf[], xdc_String fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_asprintf_va__F(buf, fmt, __va);

    va_end(__va);
    return __ret;
}

/* vprintf__E */
xdc_Int xdc_runtime_System_vprintf__E( xdc_String fmt, xdc_VaList va ) 
{
    return xdc_runtime_System_vprintf__F(fmt, va);
}

/* avprintf__E */
xdc_Int xdc_runtime_System_avprintf__E( xdc_String fmt, xdc_VaList va ) 
{
    return xdc_runtime_System_avprintf__F(fmt, va);
}

/* vsprintf__E */
xdc_Int xdc_runtime_System_vsprintf__E( xdc_Char buf[], xdc_String fmt, xdc_VaList va ) 
{
    return xdc_runtime_System_vsprintf__F(buf, fmt, va);
}

/* avsprintf__E */
xdc_Int xdc_runtime_System_avsprintf__E( xdc_Char buf[], xdc_String fmt, xdc_VaList va ) 
{
    return xdc_runtime_System_avsprintf__F(buf, fmt, va);
}

/* Module_startup */
xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state )
{
    return xdc_runtime_System_Module_startup__F(state);
}


/*
 * ======== xdc.runtime.Text FUNCTION STUBS ========
 */

/* cordText__E */
xdc_String xdc_runtime_Text_cordText__E( xdc_runtime_Text_CordAddr cord ) 
{
    return xdc_runtime_Text_cordText__F(cord);
}

/* ropeText__E */
xdc_String xdc_runtime_Text_ropeText__E( xdc_runtime_Text_RopeId rope ) 
{
    return xdc_runtime_Text_ropeText__F(rope);
}

/* matchRope__E */
xdc_Int xdc_runtime_Text_matchRope__E( xdc_runtime_Text_RopeId rope, xdc_String pat, xdc_Int* lenp ) 
{
    return xdc_runtime_Text_matchRope__F(rope, pat, lenp);
}

/* putLab__E */
xdc_Int xdc_runtime_Text_putLab__E( xdc_runtime_Types_Label* lab, xdc_Char** bufp, xdc_Int len ) 
{
    return xdc_runtime_Text_putLab__F(lab, bufp, len);
}

/* putMod__E */
xdc_Int xdc_runtime_Text_putMod__E( xdc_runtime_Types_ModuleId mid, xdc_Char** bufp, xdc_Int len ) 
{
    return xdc_runtime_Text_putMod__F(mid, bufp, len);
}

/* putSite__E */
xdc_Int xdc_runtime_Text_putSite__E( xdc_runtime_Types_Site* site, xdc_Char** bufp, xdc_Int len ) 
{
    return xdc_runtime_Text_putSite__F(site, bufp, len);
}


/*
 * ======== xdc.runtime.Timestamp FUNCTION STUBS ========
 */

/* get32__E */
xdc_Bits32 xdc_runtime_Timestamp_get32__E( void ) 
{
    return xdc_runtime_Timestamp_get32__F();
}

/* get64__E */
xdc_Void xdc_runtime_Timestamp_get64__E( xdc_runtime_Types_Timestamp64* result ) 
{
    xdc_runtime_Timestamp_get64__F(result);
}

/* getFreq__E */
xdc_Void xdc_runtime_Timestamp_getFreq__E( xdc_runtime_Types_FreqHz* freq ) 
{
    xdc_runtime_Timestamp_getFreq__F(freq);
}


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateMutex */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateMutex_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_BIOS_RtsGateProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_BIOS_RtsGateProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_gates_GateMutex_Object__create__S(oa, osz, aa, (ti_sysbios_gates_GateMutex___ParamsPtr)pa, sizeof(xdc_runtime_IGateProvider_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_BIOS_RtsGateProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_BIOS_RtsGateProxy_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateMutex_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_BIOS_RtsGateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_gates_GateMutex_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateMutex_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_BIOS_RtsGateProxy_enter__E( ti_sysbios_BIOS_RtsGateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateMutex_enter((ti_sysbios_gates_GateMutex_Handle)__inst);
}

/* leave__E */
xdc_Void ti_sysbios_BIOS_RtsGateProxy_leave__E( ti_sysbios_BIOS_RtsGateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateMutex_leave((ti_sysbios_gates_GateMutex_Handle)__inst, key);
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c64p.Hwi */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_Hwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_family_c64p_Hwi_Object__create__S(oa, osz, aa, (ti_sysbios_family_c64p_Hwi___ParamsPtr)pa, sizeof(ti_sysbios_interfaces_IHwi_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_family_c64p_Hwi_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Hwi_HwiProxy_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_c64p_Hwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_family_c64p_Hwi_Handle__label__S(obj, lab);
}

/* getStackInfo__E */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo* stkInfo, xdc_Bool computeStackDepth )
{
    return ti_sysbios_family_c64p_Hwi_getStackInfo(stkInfo, computeStackDepth);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_startup__E( void )
{
    ti_sysbios_family_c64p_Hwi_startup();
}

/* disable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disable__E( void )
{
    return ti_sysbios_family_c64p_Hwi_disable();
}

/* enable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enable__E( void )
{
    return ti_sysbios_family_c64p_Hwi_enable();
}

/* restore__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restore__E( xdc_UInt key )
{
    ti_sysbios_family_c64p_Hwi_restore(key);
}

/* switchFromBootStack__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E( void )
{
    ti_sysbios_family_c64p_Hwi_switchFromBootStack();
}

/* post__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_post__E( xdc_UInt intNum )
{
    ti_sysbios_family_c64p_Hwi_post(intNum);
}

/* getTaskSP__E */
xdc_Char* ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E( void )
{
    return ti_sysbios_family_c64p_Hwi_getTaskSP();
}

/* disableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_c64p_Hwi_disableInterrupt(intNum);
}

/* enableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_c64p_Hwi_enableInterrupt(intNum);
}

/* restoreInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key )
{
    ti_sysbios_family_c64p_Hwi_restoreInterrupt(intNum, key);
}

/* clearInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E( xdc_UInt intNum )
{
    ti_sysbios_family_c64p_Hwi_clearInterrupt(intNum);
}

/* getFunc__E */
ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_getFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_UArg* arg )
{
    return ti_sysbios_family_c64p_Hwi_getFunc((ti_sysbios_family_c64p_Hwi_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_c64p_Hwi_setFunc((ti_sysbios_family_c64p_Hwi_Handle)__inst, fxn, arg);
}

/* getHookContext__E */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id )
{
    return ti_sysbios_family_c64p_Hwi_getHookContext((ti_sysbios_family_c64p_Hwi_Handle)__inst, id);
}

/* setHookContext__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id, xdc_Ptr hookContext )
{
    ti_sysbios_family_c64p_Hwi_setHookContext((ti_sysbios_family_c64p_Hwi_Handle)__inst, id, hookContext);
}

/* getIrp__E */
ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_HwiProxy_getIrp__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst )
{
    return ti_sysbios_family_c64p_Hwi_getIrp((ti_sysbios_family_c64p_Hwi_Handle)__inst);
}


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.timers.timer64.Timer */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Timer_TimerProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_timers_timer64_Timer_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Timer_TimerProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_hal_Timer_TimerProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_timers_timer64_Timer_Object__create__S(oa, osz, aa, (ti_sysbios_timers_timer64_Timer___ParamsPtr)pa, sizeof(ti_sysbios_interfaces_ITimer_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_hal_Timer_TimerProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_timers_timer64_Timer_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Timer_TimerProxy_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_timers_timer64_Timer_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Timer_TimerProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_timers_timer64_Timer_Handle__label__S(obj, lab);
}

/* getNumTimers__E */
xdc_UInt ti_sysbios_hal_Timer_TimerProxy_getNumTimers__E( void )
{
    return ti_sysbios_timers_timer64_Timer_getNumTimers();
}

/* getStatus__E */
ti_sysbios_interfaces_ITimer_Status ti_sysbios_hal_Timer_TimerProxy_getStatus__E( xdc_UInt id )
{
    return ti_sysbios_timers_timer64_Timer_getStatus(id);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_startup__E( void )
{
    ti_sysbios_timers_timer64_Timer_startup();
}

/* getMaxTicks__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getMaxTicks__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 periodCounts )
{
    return ti_sysbios_timers_timer64_Timer_getMaxTicks((ti_sysbios_timers_timer64_Timer_Handle)__inst, periodCounts);
}

/* setNextTick__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setNextTick__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 newPeriod, xdc_UInt32 countsPerTick )
{
    ti_sysbios_timers_timer64_Timer_setNextTick((ti_sysbios_timers_timer64_Timer_Handle)__inst, newPeriod, countsPerTick);
}

/* start__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_start__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    ti_sysbios_timers_timer64_Timer_start((ti_sysbios_timers_timer64_Timer_Handle)__inst);
}

/* stop__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_stop__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    ti_sysbios_timers_timer64_Timer_stop((ti_sysbios_timers_timer64_Timer_Handle)__inst);
}

/* setPeriod__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setPeriod__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 period )
{
    ti_sysbios_timers_timer64_Timer_setPeriod((ti_sysbios_timers_timer64_Timer_Handle)__inst, period);
}

/* setPeriodMicroSecs__E */
xdc_Bool ti_sysbios_hal_Timer_TimerProxy_setPeriodMicroSecs__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 microsecs )
{
    return ti_sysbios_timers_timer64_Timer_setPeriodMicroSecs((ti_sysbios_timers_timer64_Timer_Handle)__inst, microsecs);
}

/* getPeriod__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getPeriod__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_timers_timer64_Timer_getPeriod((ti_sysbios_timers_timer64_Timer_Handle)__inst);
}

/* getCount__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getCount__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_timers_timer64_Timer_getCount((ti_sysbios_timers_timer64_Timer_Handle)__inst);
}

/* getFreq__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_getFreq__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_runtime_Types_FreqHz* freq )
{
    ti_sysbios_timers_timer64_Timer_getFreq((ti_sysbios_timers_timer64_Timer_Handle)__inst, freq);
}

/* getFunc__E */
ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_hal_Timer_TimerProxy_getFunc__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UArg* arg )
{
    return ti_sysbios_timers_timer64_Timer_getFunc((ti_sysbios_timers_timer64_Timer_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setFunc__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_timers_timer64_Timer_setFunc((ti_sysbios_timers_timer64_Timer_Handle)__inst, fxn, arg);
}

/* trigger__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_trigger__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 cycles )
{
    ti_sysbios_timers_timer64_Timer_trigger((ti_sysbios_timers_timer64_Timer_Handle)__inst, cycles);
}

/* getExpiredCounts__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getExpiredCounts__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_timers_timer64_Timer_getExpiredCounts((ti_sysbios_timers_timer64_Timer_Handle)__inst);
}


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateMutex */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateMutex_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_gates_GateMutex_Object__create__S(oa, osz, aa, (ti_sysbios_gates_GateMutex___ParamsPtr)pa, sizeof(xdc_runtime_IGateProvider_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateMutex_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_gates_GateMutex_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateMutex_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_heaps_HeapMem_Module_GateProxy_enter__E( ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateMutex_enter((ti_sysbios_gates_GateMutex_Handle)__inst);
}

/* leave__E */
xdc_Void ti_sysbios_heaps_HeapMem_Module_GateProxy_leave__E( ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateMutex_leave((ti_sysbios_gates_GateMutex_Handle)__inst, key);
}


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c62.IntrinsicsSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDone__S();
}

/* maxbit__E */
xdc_UInt ti_sysbios_knl_Intrinsics_SupportProxy_maxbit__E( xdc_UInt bits )
{
    return ti_sysbios_family_c62_IntrinsicsSupport_maxbit(bits);
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c62.TaskSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c62_TaskSupport_Module__startupDone__S();
}

/* start__E */
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_start__E( xdc_Ptr curTask, ti_sysbios_interfaces_ITaskSupport_FuncPtr enter, ti_sysbios_interfaces_ITaskSupport_FuncPtr exit, xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_family_c62_TaskSupport_start(curTask, enter, exit, eb);
}

/* swap__E */
xdc_Void ti_sysbios_knl_Task_SupportProxy_swap__E( xdc_Ptr* oldtskContext, xdc_Ptr* newtskContext )
{
    ti_sysbios_family_c62_TaskSupport_swap(oldtskContext, newtskContext);
}

/* checkStack__E */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_checkStack__E( xdc_Char* stack, xdc_SizeT size )
{
    return ti_sysbios_family_c62_TaskSupport_checkStack(stack, size);
}

/* stackUsed__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_stackUsed__E( xdc_Char* stack, xdc_SizeT size )
{
    return ti_sysbios_family_c62_TaskSupport_stackUsed(stack, size);
}

/* getStackAlignment__E */
xdc_UInt ti_sysbios_knl_Task_SupportProxy_getStackAlignment__E( void )
{
    return ti_sysbios_family_c62_TaskSupport_getStackAlignment();
}

/* getDefaultStackSize__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_getDefaultStackSize__E( void )
{
    return ti_sysbios_family_c62_TaskSupport_getDefaultStackSize();
}


/*
 * ======== ti.sysbios.timers.timer64.Timer_TimerSupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c64p.tci6488.TimerSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_timers_timer64_Timer_TimerSupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_tci6488_TimerSupport_Module__startupDone__S();
}

/* enable__E */
xdc_Void ti_sysbios_timers_timer64_Timer_TimerSupportProxy_enable__E( xdc_UInt timerId, xdc_runtime_Error_Block* eb )
{
    ti_sysbios_family_c64p_tci6488_TimerSupport_enable(timerId, eb);
}


/*
 * ======== xdc.runtime.Main_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Main_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const xdc_runtime_Main_Module_GateProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_gates_GateHwi_Object__create__S(oa, osz, aa, (ti_sysbios_gates_GateHwi___ParamsPtr)pa, sizeof(xdc_runtime_IGateProvider_Params), eb);
}

/* Object__delete__S */
void xdc_runtime_Main_Module_GateProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_Main_Module_GateProxy_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* xdc_runtime_Main_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_Main_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E( xdc_runtime_Main_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)__inst);
}

/* leave__E */
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E( xdc_runtime_Main_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)__inst, key);
}


/*
 * ======== xdc.runtime.Memory_HeapProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.heaps.HeapMem */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Memory_HeapProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_heaps_HeapMem_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const xdc_runtime_Memory_HeapProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_heaps_HeapMem_Object__create__S(oa, osz, aa, (ti_sysbios_heaps_HeapMem___ParamsPtr)pa, sizeof(xdc_runtime_IHeap_Params), eb);
}

/* Object__delete__S */
void xdc_runtime_Memory_HeapProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_heaps_HeapMem_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_Memory_HeapProxy_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_heaps_HeapMem_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* xdc_runtime_Memory_HeapProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_heaps_HeapMem_Handle__label__S(obj, lab);
}

/* alloc__E */
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb )
{
    return xdc_runtime_IHeap_alloc((xdc_runtime_IHeap_Handle)__inst, size, align, eb);
}

/* free__E */
xdc_Void xdc_runtime_Memory_HeapProxy_free__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_Ptr block, xdc_SizeT size )
{
    xdc_runtime_IHeap_free((xdc_runtime_IHeap_Handle)__inst, block, size);
}

/* isBlocking__E */
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E( xdc_runtime_Memory_HeapProxy_Handle __inst )
{
    return xdc_runtime_IHeap_isBlocking((xdc_runtime_IHeap_Handle)__inst);
}

/* getStats__E */
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_runtime_Memory_Stats* stats )
{
    xdc_runtime_IHeap_getStats((xdc_runtime_IHeap_Handle)__inst, stats);
}


/*
 * ======== xdc.runtime.System_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_System_Module_GateProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const xdc_runtime_System_Module_GateProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_gates_GateHwi_Object__create__S(oa, osz, aa, (ti_sysbios_gates_GateHwi___ParamsPtr)pa, sizeof(xdc_runtime_IGateProvider_Params), eb);
}

/* Object__delete__S */
void xdc_runtime_System_Module_GateProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_System_Module_GateProxy_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* xdc_runtime_System_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_System_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E( xdc_runtime_System_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)__inst);
}

/* leave__E */
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E( xdc_runtime_System_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)__inst, key);
}


/*
 * ======== xdc.runtime.System_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO xdc.runtime.SysMin */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_SupportProxy_Module__startupDone__S( void ) 
{
    return xdc_runtime_SysMin_Module__startupDone__S();
}

/* abort__E */
xdc_Void xdc_runtime_System_SupportProxy_abort__E( xdc_String str )
{
    xdc_runtime_SysMin_abort(str);
}

/* exit__E */
xdc_Void xdc_runtime_System_SupportProxy_exit__E( xdc_Int stat )
{
    xdc_runtime_SysMin_exit(stat);
}

/* flush__E */
xdc_Void xdc_runtime_System_SupportProxy_flush__E( void )
{
    xdc_runtime_SysMin_flush();
}

/* putch__E */
xdc_Void xdc_runtime_System_SupportProxy_putch__E( xdc_Char ch )
{
    xdc_runtime_SysMin_putch(ch);
}

/* ready__E */
xdc_Bool xdc_runtime_System_SupportProxy_ready__E( void )
{
    return xdc_runtime_SysMin_ready();
}


/*
 * ======== xdc.runtime.Timestamp_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c64p.TimestampProvider */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__S();
}

/* get32__E */
xdc_Bits32 xdc_runtime_Timestamp_SupportProxy_get32__E( void )
{
    return ti_sysbios_family_c64p_TimestampProvider_get32();
}

/* get64__E */
xdc_Void xdc_runtime_Timestamp_SupportProxy_get64__E( xdc_runtime_Types_Timestamp64* result )
{
    ti_sysbios_family_c64p_TimestampProvider_get64(result);
}

/* getFreq__E */
xdc_Void xdc_runtime_Timestamp_SupportProxy_getFreq__E( xdc_runtime_Types_FreqHz* freq )
{
    ti_sysbios_family_c64p_TimestampProvider_getFreq(freq);
}


/*
 * ======== ti.sysbios.family.c64p.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_c64p_Hwi_Object2__ s0; char c; } ti_sysbios_family_c64p_Hwi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c64p_Hwi_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_family_c64p_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_c64p_Hwi___S1) - sizeof(ti_sysbios_family_c64p_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_c64p_Hwi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_family_c64p_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_c64p_Hwi_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.gates.GateHwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_gates_GateHwi_Object2__ s0; char c; } ti_sysbios_gates_GateHwi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateHwi_Object__DESC__C = {
    (Ptr)&ti_sysbios_gates_GateHwi_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_gates_GateHwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_gates_GateHwi___S1) - sizeof(ti_sysbios_gates_GateHwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_gates_GateHwi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_gates_GateHwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_gates_GateHwi_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.gates.GateMutex OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_gates_GateMutex_Object2__ s0; char c; } ti_sysbios_gates_GateMutex___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateMutex_Object__DESC__C = {
    (Ptr)&ti_sysbios_gates_GateMutex_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_gates_GateMutex_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_gates_GateMutex___S1) - sizeof(ti_sysbios_gates_GateMutex_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_gates_GateMutex_Object2__), /* objSize */
    (Ptr)&ti_sysbios_gates_GateMutex_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_gates_GateMutex_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.hal.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_hal_Hwi_Object2__ s0; char c; } ti_sysbios_hal_Hwi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Hwi_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_hal_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_hal_Hwi___S1) - sizeof(ti_sysbios_hal_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_hal_Hwi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_hal_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_hal_Hwi_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.hal.Timer OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_hal_Timer_Object2__ s0; char c; } ti_sysbios_hal_Timer___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Timer_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_hal_Timer_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_hal_Timer___S1) - sizeof(ti_sysbios_hal_Timer_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_hal_Timer_Object2__), /* objSize */
    (Ptr)&ti_sysbios_hal_Timer_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_hal_Timer_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.heaps.HeapMem OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_heaps_HeapMem_Object2__ s0; char c; } ti_sysbios_heaps_HeapMem___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_heaps_HeapMem_Object__DESC__C = {
    (Ptr)&ti_sysbios_heaps_HeapMem_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_heaps_HeapMem_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_heaps_HeapMem___S1) - sizeof(ti_sysbios_heaps_HeapMem_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_heaps_HeapMem_Object2__), /* objSize */
    (Ptr)&ti_sysbios_heaps_HeapMem_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_heaps_HeapMem_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Clock OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Clock_Object2__ s0; char c; } ti_sysbios_knl_Clock___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Clock_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Clock_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Clock___S1) - sizeof(ti_sysbios_knl_Clock_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Clock_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Clock_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Clock_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Queue OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Queue_Object2__ s0; char c; } ti_sysbios_knl_Queue___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Queue_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Queue_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Queue___S1) - sizeof(ti_sysbios_knl_Queue_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Queue_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Queue_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Queue_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Semaphore OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Semaphore_Object2__ s0; char c; } ti_sysbios_knl_Semaphore___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Semaphore_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Semaphore_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Semaphore___S1) - sizeof(ti_sysbios_knl_Semaphore_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Semaphore_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Semaphore_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Semaphore_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Swi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Swi_Object2__ s0; char c; } ti_sysbios_knl_Swi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Swi_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Swi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Swi___S1) - sizeof(ti_sysbios_knl_Swi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Swi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Swi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Swi_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Task OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Task_Object2__ s0; char c; } ti_sysbios_knl_Task___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Task_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Task_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Task___S1) - sizeof(ti_sysbios_knl_Task_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Task_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Task_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Task_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.timers.timer64.Timer OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_timers_timer64_Timer_Object2__ s0; char c; } ti_sysbios_timers_timer64_Timer___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_timers_timer64_Timer_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_timers_timer64_Timer_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_timers_timer64_Timer___S1) - sizeof(ti_sysbios_timers_timer64_Timer_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_timers_timer64_Timer_Object2__), /* objSize */
    (Ptr)&ti_sysbios_timers_timer64_Timer_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_timers_timer64_Timer_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.BIOS SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_BIOS_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.BIOS_RtsGateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_BIOS_RtsGateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_BIOS_RtsGateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_BIOS_RtsGateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_BIOS_RtsGateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_BIOS_RtsGateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_BIOS_RtsGateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_BIOS_RtsGateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_BIOS_RtsGateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_query
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_BIOS_RtsGateProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_gates_GateMutex_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.family.c62.IntrinsicsSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c62.TaskSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c62_TaskSupport_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c64p.EventCombiner SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_EventCombiner_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_EventCombiner_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c64p.Exception SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_Exception_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_Exception_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c64p.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_c64p_Hwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_c64p_Hwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_c64p_Hwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_c64p_Hwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_c64p_Hwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_c64p_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_c64p_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_c64p_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_c64p_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_c64p_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_Hwi_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_family_c64p_Hwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32790;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_family_c64p_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_family_c64p_Hwi_Object__*)oa) + i;
    }

    if (ti_sysbios_family_c64p_Hwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_family_c64p_Hwi_Object__*)ti_sysbios_family_c64p_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_c64p_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_c64p_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_c64p_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_family_c64p_Hwi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_family_c64p_Hwi_Params prms;
    ti_sysbios_family_c64p_Hwi_Object* obj;
    int iStat;

    ti_sysbios_family_c64p_Hwi_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_c64p_Hwi_Instance_init__F(obj, args->intNum, args->hwiFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, *((ti_sysbios_family_c64p_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_family_c64p_Hwi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c64p.tci6488.TimerSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_tci6488_TimerSupport_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c66.Cache SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c66_Cache_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c66_Cache_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c66.tci66xx.CpIntc SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c66_tci66xx_CpIntc_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c66_tci66xx_CpIntc_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.gates.GateHwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_gates_GateHwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_gates_GateHwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_gates_GateHwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_gates_GateHwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_gates_GateHwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_gates_GateHwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_gates_GateHwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_gates_GateHwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_gates_GateHwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_gates_GateHwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_gates_GateHwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_gates_GateHwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_gates_GateHwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_gates_GateHwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_gates_GateHwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_gates_GateHwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_gates_GateHwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_gates_GateHwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_gates_GateHwi_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_gates_GateHwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32809;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_gates_GateHwi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_gates_GateHwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_gates_GateHwi_Object__*)oa) + i;
    }

    if (ti_sysbios_gates_GateHwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_gates_GateHwi_Object__*)ti_sysbios_gates_GateHwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_gates_GateHwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_gates_GateHwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_gates_GateHwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_gates_GateHwi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_gates_GateHwi_Params prms;
    ti_sysbios_gates_GateHwi_Object* obj;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateHwi_Instance_init__F(obj, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_gates_GateHwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_gates_GateHwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, *((ti_sysbios_gates_GateHwi_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_gates_GateHwi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.gates.GateMutex SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_gates_GateMutex_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_gates_GateMutex_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_gates_GateMutex_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_gates_GateMutex_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_gates_GateMutex_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_gates_GateMutex_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_gates_GateMutex_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_gates_GateMutex_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_gates_GateMutex_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_gates_GateMutex_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_gates_GateMutex_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_gates_GateMutex_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_gates_GateMutex_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_gates_GateMutex_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_gates_GateMutex_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_gates_GateMutex_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_gates_GateMutex_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_gates_GateMutex_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_gates_GateMutex_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_gates_GateMutex_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32810;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_gates_GateMutex_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_gates_GateMutex_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_gates_GateMutex_Object__*)oa) + i;
    }

    if (ti_sysbios_gates_GateMutex_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_gates_GateMutex_Object__*)ti_sysbios_gates_GateMutex_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_gates_GateMutex_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_gates_GateMutex_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_gates_GateMutex_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_gates_GateMutex___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_gates_GateMutex_Params prms;
    ti_sysbios_gates_GateMutex_Object* obj;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateMutex_Instance_init__F(obj, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_gates_GateMutex_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_gates_GateMutex_Instance_finalize__F, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_gates_GateMutex_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, *((ti_sysbios_gates_GateMutex_Object**)instp), (xdc_Fxn)ti_sysbios_gates_GateMutex_Instance_finalize__F, -1, FALSE);
    *((ti_sysbios_gates_GateMutex_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.hal.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Hwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Hwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Hwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Hwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Hwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Hwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Hwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Hwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__S( void ) 
{
    return ti_sysbios_hal_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Hwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32797;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_hal_Hwi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_hal_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_hal_Hwi_Object__*)oa) + i;
    }

    if (ti_sysbios_hal_Hwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_hal_Hwi_Object__*)ti_sysbios_hal_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_hal_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_hal_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_hal_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_hal_Hwi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_hal_Hwi_Params prms;
    ti_sysbios_hal_Hwi_Object* obj;
    int iStat;

    ti_sysbios_hal_Hwi_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_hal_Hwi_Instance_init__F(obj, args->intNum, args->hwiFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_hal_Hwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_hal_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, *((ti_sysbios_hal_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_hal_Hwi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Hwi_HwiProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Hwi_HwiProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Hwi_HwiProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Hwi_HwiProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Hwi_HwiProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Hwi_HwiProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Hwi_HwiProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Hwi_HwiProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_query
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S( void )
{
    return 0;
}



/*
 * ======== ti.sysbios.hal.Timer SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Timer_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Timer_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Timer_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Timer_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Timer_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Timer_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Timer_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Timer_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Timer_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Timer_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Timer_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Timer_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Timer_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Timer_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Timer_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Timer_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Timer_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Timer_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Timer_Module__startupDone__S( void ) 
{
    return ti_sysbios_hal_Timer_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Timer_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32798;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_hal_Timer_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_hal_Timer_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_hal_Timer_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_hal_Timer_Object__*)oa) + i;
    }

    if (ti_sysbios_hal_Timer_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_hal_Timer_Object__*)ti_sysbios_hal_Timer_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_hal_Timer_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_hal_Timer_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_hal_Timer_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_hal_Timer_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_hal_Timer_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Timer_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_hal_Timer___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_hal_Timer_Params prms;
    ti_sysbios_hal_Timer_Object* obj;
    int iStat;

    ti_sysbios_hal_Timer_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_Timer_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_hal_Timer_Instance_init__F(obj, args->id, args->tickFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Timer_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_hal_Timer_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Timer_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_hal_Timer_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Timer_Object__DESC__C, *((ti_sysbios_hal_Timer_Object**)instp), (xdc_Fxn)ti_sysbios_hal_Timer_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_hal_Timer_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Timer_TimerProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Timer_TimerProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Timer_TimerProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Timer_TimerProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Timer_TimerProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Timer_TimerProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Timer_TimerProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Timer_TimerProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_query
xdc_Bool ti_sysbios_hal_Timer_TimerProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_hal_Timer_TimerProxy_Proxy__delegate__S( void )
{
    return 0;
}



/*
 * ======== ti.sysbios.heaps.HeapMem SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_heaps_HeapMem_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_heaps_HeapMem_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_heaps_HeapMem_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_heaps_HeapMem_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_heaps_HeapMem_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_heaps_HeapMem_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_heaps_HeapMem_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_heaps_HeapMem_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_heaps_HeapMem_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_heaps_HeapMem_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_heaps_HeapMem_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_heaps_HeapMem_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_heaps_HeapMem_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32820;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_heaps_HeapMem_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_heaps_HeapMem_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_heaps_HeapMem_Object__*)oa) + i;
    }

    if (ti_sysbios_heaps_HeapMem_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_heaps_HeapMem_Object__*)ti_sysbios_heaps_HeapMem_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_heaps_HeapMem_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_heaps_HeapMem_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_heaps_HeapMem_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_heaps_HeapMem___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_heaps_HeapMem_Params prms;
    ti_sysbios_heaps_HeapMem_Object* obj;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_heaps_HeapMem_Instance_init__F(obj, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_heaps_HeapMem_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_heaps_HeapMem_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, *((ti_sysbios_heaps_HeapMem_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_heaps_HeapMem_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_query
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_heaps_HeapMem_Module_GateProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_gates_GateMutex_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.knl.Clock SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Clock_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Clock_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Clock_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Clock_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Clock_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Clock_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Clock_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Clock_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Clock_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Clock_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Clock_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Clock_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Clock_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Clock_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Clock_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Clock_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Clock_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Clock_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__S( void ) 
{
    return ti_sysbios_knl_Clock_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Clock_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32800;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Clock_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Clock_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Clock_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Clock_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Clock_Object__*)ti_sysbios_knl_Clock_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Clock_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Clock_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Clock_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Clock___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Clock_Params prms;
    ti_sysbios_knl_Clock_Object* obj;

    ti_sysbios_knl_Clock_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Clock_Instance_init__F(obj, args->clockFxn, args->timeout, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Clock_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Clock_Instance_finalize__F, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Clock_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, *((ti_sysbios_knl_Clock_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Clock_Instance_finalize__F, -1, FALSE);
    *((ti_sysbios_knl_Clock_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Idle SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Idle_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.knl.Intrinsics SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_knl_Intrinsics_SupportProxy_Proxy__delegate__S( void )
{
    return 0;
}


/*
 * ======== ti.sysbios.knl.Queue SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Queue_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Queue_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Queue_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Queue_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Queue_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Queue_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Queue_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Queue_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Queue_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Queue_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Queue_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Queue_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Queue_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Queue_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Queue_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Queue_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Queue_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Queue_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Queue_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Queue_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32803;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Queue_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Queue_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Queue_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Queue_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Queue_Object__*)ti_sysbios_knl_Queue_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Queue_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Queue_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Queue_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Queue___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Queue_Params prms;
    ti_sysbios_knl_Queue_Object* obj;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Queue_Instance_init__F(obj, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Queue_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Queue_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, *((ti_sysbios_knl_Queue_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_knl_Queue_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Semaphore SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Semaphore_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Semaphore_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Semaphore_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Semaphore_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Semaphore_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Semaphore_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Semaphore_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Semaphore_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Semaphore_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Semaphore_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Semaphore_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Semaphore_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Semaphore_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Semaphore_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Semaphore_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32804;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Semaphore_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Semaphore_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Semaphore_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Semaphore_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Semaphore_Object__*)ti_sysbios_knl_Semaphore_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Semaphore_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Semaphore_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Semaphore_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Semaphore___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Semaphore_Params prms;
    ti_sysbios_knl_Semaphore_Object* obj;

    ti_sysbios_knl_Semaphore_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Semaphore_Instance_init__F(obj, args->count, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Semaphore_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Semaphore_Instance_finalize__F, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Semaphore_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, *((ti_sysbios_knl_Semaphore_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Semaphore_Instance_finalize__F, -1, FALSE);
    *((ti_sysbios_knl_Semaphore_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Swi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Swi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Swi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Swi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Swi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Swi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Swi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Swi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Swi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Swi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Swi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Swi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Swi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Swi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Swi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Swi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Swi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Swi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Swi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__S( void ) 
{
    return ti_sysbios_knl_Swi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Swi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32805;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Swi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Swi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Swi_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Swi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Swi_Object__*)ti_sysbios_knl_Swi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Swi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Swi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Swi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Swi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Swi_Params prms;
    ti_sysbios_knl_Swi_Object* obj;
    int iStat;

    ti_sysbios_knl_Swi_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Swi_Instance_init__F(obj, args->fxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Swi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Swi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, *((ti_sysbios_knl_Swi_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_knl_Swi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Task SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Task_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Task_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Task_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Task_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Task_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Task_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Task_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Task_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Task_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Task_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Task_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Task_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Task_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Task_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Task_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Task_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Task_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Task_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__S( void ) 
{
    return ti_sysbios_knl_Task_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Task_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32806;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Task_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Task_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Task_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Task_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Task_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Task_Object__*)ti_sysbios_knl_Task_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Task_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Task_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Task_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Task_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Task_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Task_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Task___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Task_Params prms;
    ti_sysbios_knl_Task_Object* obj;
    int iStat;

    ti_sysbios_knl_Task_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Task_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Task_Instance_init__F(obj, args->fxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Task_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Task_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, *((ti_sysbios_knl_Task_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_knl_Task_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool ti_sysbios_knl_Task_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_Proxy__delegate__S( void )
{
    return 0;
}


/*
 * ======== ti.sysbios.timers.timer64.Timer SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_timers_timer64_Timer_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_timers_timer64_Timer_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_timers_timer64_Timer_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_timers_timer64_Timer_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_timers_timer64_Timer_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_timers_timer64_Timer_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_timers_timer64_Timer_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_timers_timer64_Timer_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_timers_timer64_Timer_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_timers_timer64_Timer_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_timers_timer64_Timer_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_timers_timer64_Timer_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_timers_timer64_Timer_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_timers_timer64_Timer_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_timers_timer64_Timer_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_timers_timer64_Timer_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_timers_timer64_Timer_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_timers_timer64_Timer_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_timers_timer64_Timer_Module__startupDone__S( void ) 
{
    return ti_sysbios_timers_timer64_Timer_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_timers_timer64_Timer_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32816;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_timers_timer64_Timer_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_timers_timer64_Timer_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_timers_timer64_Timer_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_timers_timer64_Timer_Object__*)oa) + i;
    }

    if (ti_sysbios_timers_timer64_Timer_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_timers_timer64_Timer_Object__*)ti_sysbios_timers_timer64_Timer_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_timers_timer64_Timer_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_timers_timer64_Timer_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_timers_timer64_Timer_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_timers_timer64_Timer_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_timers_timer64_Timer_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_timers_timer64_Timer_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_timers_timer64_Timer___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_timers_timer64_Timer_Params prms;
    ti_sysbios_timers_timer64_Timer_Object* obj;
    int iStat;

    ti_sysbios_timers_timer64_Timer_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_timers_timer64_Timer_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_timers_timer64_Timer_Instance_init__F(obj, args->id, args->tickFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_timer64_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_timers_timer64_Timer_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_timers_timer64_Timer_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_timer64_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_timers_timer64_Timer_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_timers_timer64_Timer_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_timer64_Timer_Object__DESC__C, *((ti_sysbios_timers_timer64_Timer_Object**)instp), (xdc_Fxn)ti_sysbios_timers_timer64_Timer_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_timers_timer64_Timer_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.timers.timer64.Timer_TimerSupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool ti_sysbios_timers_timer64_Timer_TimerSupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_timers_timer64_Timer_TimerSupportProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_family_c64p_tci6488_TimerSupport_Module__FXNS__C;
}


/*
 * ======== xdc.runtime.Assert SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Assert_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Core SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Core_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Defaults SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Defaults_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Diags SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Diags_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Error SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Error_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Gate SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Gate_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Log SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Log_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Main SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Main_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Main_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Main_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Main_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Main_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Main_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Main_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Main_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Main_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Main_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Main_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Main_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Main_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Main_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Main_Module_GateProxy_Module_GateProxy_query
xdc_Bool xdc_runtime_Main_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.Memory SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Memory_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Memory_HeapProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Memory_HeapProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Memory_HeapProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Memory_HeapProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Memory_HeapProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Memory_HeapProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Memory_HeapProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Memory_HeapProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Memory_HeapProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Memory_HeapProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Memory_HeapProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Memory_HeapProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Memory_HeapProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Memory_HeapProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Memory_HeapProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Memory_HeapProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Memory_HeapProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Memory_HeapProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Memory_HeapProxy_Module_GateProxy_query
xdc_Bool xdc_runtime_Memory_HeapProxy_Proxy__abstract__S( void )
{
    return 1;
}
xdc_Ptr xdc_runtime_Memory_HeapProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_heaps_HeapMem_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.Registry SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Registry_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Startup SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Startup_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.SysMin SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_SysMin_Module__startupDone__S( void ) 
{
    return xdc_runtime_SysMin_Module__startupDone__F();
}



/*
 * ======== xdc.runtime.System SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_Module__startupDone__S( void ) 
{
    return xdc_runtime_System_Module__startupDone__F();
}



/*
 * ======== xdc.runtime.System_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_System_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_System_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_System_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_System_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_System_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_System_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_System_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_System_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_System_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_System_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_System_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_System_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_System_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_System_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_System_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_System_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_System_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_System_Module_GateProxy_Module_GateProxy_query
xdc_Bool xdc_runtime_System_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_System_Module_GateProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.System_SupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool xdc_runtime_System_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_System_SupportProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&xdc_runtime_SysMin_Module__FXNS__C;
}


/*
 * ======== xdc.runtime.Text SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Text_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Timestamp SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Timestamp_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Timestamp_SupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool xdc_runtime_Timestamp_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S( void )
{
    return 0;
}


/*
 * ======== INITIALIZATION ENTRY POINT ========
 */

extern int __xdc__init(void);
#ifdef __GNUC__
#if __GNUC__ >= 4
    __attribute__ ((externally_visible))
#endif
#endif
__FAR__ int (* volatile __xdc__init__addr)(void) = &__xdc__init;


/*
 * ======== PROGRAM GLOBALS ========
 */


/*
 * ======== CONSTANTS ========
 */

#pragma DATA_SECTION(xdc_runtime_IModule_Interface__BASE__C, ".const:xdc_runtime_IModule_Interface__BASE__C");
#pragma DATA_SECTION(ti_sysbios_interfaces_ITimerSupport_Interface__BASE__C, ".const:ti_sysbios_interfaces_ITimerSupport_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_IGateProvider_Interface__BASE__C, ".const:xdc_runtime_IGateProvider_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_IHeap_Interface__BASE__C, ".const:xdc_runtime_IHeap_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_ISystemSupport_Interface__BASE__C, ".const:xdc_runtime_ISystemSupport_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_ITimestampClient_Interface__BASE__C, ".const:xdc_runtime_ITimestampClient_Interface__BASE__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__FXNS__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__FXNS__C, ".const:ti_sysbios_gates_GateHwi_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__FXNS__C, ".const:ti_sysbios_gates_GateMutex_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__FXNS__C, ".const:ti_sysbios_heaps_HeapMem_Module__FXNS__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__FXNS__C, ".const:xdc_runtime_SysMin_Module__FXNS__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__FXNS__C, ".const:xdc_runtime_Timestamp_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__PARAMS__C, ".const:ti_sysbios_family_c64p_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__PARAMS__C, ".const:ti_sysbios_gates_GateHwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__PARAMS__C, ".const:ti_sysbios_gates_GateMutex_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__PARAMS__C, ".const:ti_sysbios_hal_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__PARAMS__C, ".const:ti_sysbios_hal_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__PARAMS__C, ".const:ti_sysbios_heaps_HeapMem_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__PARAMS__C, ".const:ti_sysbios_knl_Clock_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__PARAMS__C, ".const:ti_sysbios_knl_Queue_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__PARAMS__C, ".const:ti_sysbios_knl_Semaphore_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__PARAMS__C, ".const:ti_sysbios_knl_Swi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__PARAMS__C, ".const:ti_sysbios_knl_Task_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Object__PARAMS__C, ".const:ti_sysbios_timers_timer64_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Instance_State_sem__O, ".const:ti_sysbios_gates_GateMutex_Instance_State_sem__O");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module_State_clockQ__O, ".const:ti_sysbios_knl_Clock_Module_State_clockQ__O");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Instance_State_pendQ__O, ".const:ti_sysbios_knl_Semaphore_Instance_State_pendQ__O");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module_State_inactiveQ__O, ".const:ti_sysbios_knl_Task_Module_State_inactiveQ__O");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module_State_terminatedQ__O, ".const:ti_sysbios_knl_Task_Module_State_terminatedQ__O");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsEnabled__C, ".const:ti_sysbios_BIOS_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsIncluded__C, ".const:ti_sysbios_BIOS_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsMask__C, ".const:ti_sysbios_BIOS_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__gateObj__C, ".const:ti_sysbios_BIOS_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__gatePrms__C, ".const:ti_sysbios_BIOS_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__id__C, ".const:ti_sysbios_BIOS_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerDefined__C, ".const:ti_sysbios_BIOS_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerObj__C, ".const:ti_sysbios_BIOS_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn0__C, ".const:ti_sysbios_BIOS_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn1__C, ".const:ti_sysbios_BIOS_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn2__C, ".const:ti_sysbios_BIOS_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn4__C, ".const:ti_sysbios_BIOS_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn8__C, ".const:ti_sysbios_BIOS_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__startupDoneFxn__C, ".const:ti_sysbios_BIOS_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__count__C, ".const:ti_sysbios_BIOS_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__heap__C, ".const:ti_sysbios_BIOS_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__sizeof__C, ".const:ti_sysbios_BIOS_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__table__C, ".const:ti_sysbios_BIOS_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_smpEnabled__C, ".const:ti_sysbios_BIOS_smpEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_cpuFreq__C, ".const:ti_sysbios_BIOS_cpuFreq__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_taskEnabled__C, ".const:ti_sysbios_BIOS_taskEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_swiEnabled__C, ".const:ti_sysbios_BIOS_swiEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_clockEnabled__C, ".const:ti_sysbios_BIOS_clockEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_heapSize__C, ".const:ti_sysbios_BIOS_heapSize__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_heapSection__C, ".const:ti_sysbios_BIOS_heapSection__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_heapTrackEnabled__C, ".const:ti_sysbios_BIOS_heapTrackEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_installedErrorHook__C, ".const:ti_sysbios_BIOS_installedErrorHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__gateObj__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__id__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__count__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__heap__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__sizeof__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__table__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_defaultStackSize__C, ".const:ti_sysbios_family_c62_TaskSupport_defaultStackSize__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_stackAlignment__C, ".const:ti_sysbios_family_c62_TaskSupport_stackAlignment__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__gateObj__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__id__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Object__count__C, ".const:ti_sysbios_family_c64p_EventCombiner_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Object__heap__C, ".const:ti_sysbios_family_c64p_EventCombiner_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Object__sizeof__C, ".const:ti_sysbios_family_c64p_EventCombiner_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Object__table__C, ".const:ti_sysbios_family_c64p_EventCombiner_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_E_unpluggedEvent__C, ".const:ti_sysbios_family_c64p_EventCombiner_E_unpluggedEvent__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_EVTMASK__C, ".const:ti_sysbios_family_c64p_EventCombiner_EVTMASK__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__gateObj__C, ".const:ti_sysbios_family_c64p_Exception_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_Exception_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__id__C, ".const:ti_sysbios_family_c64p_Exception_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__count__C, ".const:ti_sysbios_family_c64p_Exception_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__heap__C, ".const:ti_sysbios_family_c64p_Exception_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__sizeof__C, ".const:ti_sysbios_family_c64p_Exception_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__table__C, ".const:ti_sysbios_family_c64p_Exception_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_E_exceptionMin__C, ".const:ti_sysbios_family_c64p_Exception_E_exceptionMin__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_E_exceptionMax__C, ".const:ti_sysbios_family_c64p_Exception_E_exceptionMax__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_enableExternalMPC__C, ".const:ti_sysbios_family_c64p_Exception_enableExternalMPC__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_enablePrint__C, ".const:ti_sysbios_family_c64p_Exception_enablePrint__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_exceptionHook__C, ".const:ti_sysbios_family_c64p_Exception_exceptionHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_internalHook__C, ".const:ti_sysbios_family_c64p_Exception_internalHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_externalHook__C, ".const:ti_sysbios_family_c64p_Exception_externalHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_nmiHook__C, ".const:ti_sysbios_family_c64p_Exception_nmiHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_returnHook__C, ".const:ti_sysbios_family_c64p_Exception_returnHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__DESC__C, ".const:ti_sysbios_family_c64p_Hwi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__PARAMS__C, ".const:ti_sysbios_family_c64p_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__gateObj__C, ".const:ti_sysbios_family_c64p_Hwi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_Hwi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__id__C, ".const:ti_sysbios_family_c64p_Hwi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__count__C, ".const:ti_sysbios_family_c64p_Hwi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__heap__C, ".const:ti_sysbios_family_c64p_Hwi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__sizeof__C, ".const:ti_sysbios_family_c64p_Hwi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__table__C, ".const:ti_sysbios_family_c64p_Hwi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C, ".const:ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_E_handleNotFound__C, ".const:ti_sysbios_family_c64p_Hwi_E_handleNotFound__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_LM_begin__C, ".const:ti_sysbios_family_c64p_Hwi_LM_begin__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_LD_end__C, ".const:ti_sysbios_family_c64p_Hwi_LD_end__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_enableException__C, ".const:ti_sysbios_family_c64p_Hwi_enableException__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_swiDisable__C, ".const:ti_sysbios_family_c64p_Hwi_swiDisable__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C, ".const:ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_taskDisable__C, ".const:ti_sysbios_family_c64p_Hwi_taskDisable__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C, ".const:ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_hooks__C, ".const:ti_sysbios_family_c64p_Hwi_hooks__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__id__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__count__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__heap__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__table__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gateObj__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__id__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Object__count__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Object__heap__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Object__sizeof__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tci6488_TimerSupport_Object__table__C, ".const:ti_sysbios_family_c64p_tci6488_TimerSupport_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__diagsEnabled__C, ".const:ti_sysbios_family_c66_Cache_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__diagsIncluded__C, ".const:ti_sysbios_family_c66_Cache_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__diagsMask__C, ".const:ti_sysbios_family_c66_Cache_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__gateObj__C, ".const:ti_sysbios_family_c66_Cache_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__gatePrms__C, ".const:ti_sysbios_family_c66_Cache_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__id__C, ".const:ti_sysbios_family_c66_Cache_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerDefined__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerObj__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn0__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn1__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn2__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn4__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn8__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c66_Cache_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Object__count__C, ".const:ti_sysbios_family_c66_Cache_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Object__heap__C, ".const:ti_sysbios_family_c66_Cache_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Object__sizeof__C, ".const:ti_sysbios_family_c66_Cache_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Object__table__C, ".const:ti_sysbios_family_c66_Cache_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_initSize__C, ".const:ti_sysbios_family_c66_Cache_initSize__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_atomicBlockSize__C, ".const:ti_sysbios_family_c66_Cache_atomicBlockSize__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_marvalues__C, ".const:ti_sysbios_family_c66_Cache_marvalues__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_0__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_0__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_1__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_1__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_2__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_2__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_3__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_3__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_4__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_4__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_5__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_5__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_6__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_6__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_7__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId_7__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_eventId__A, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_eventId__A");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsEnabled__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsIncluded__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsMask__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__gateObj__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__gatePrms__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__id__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerDefined__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerObj__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn0__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn1__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn2__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn4__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn8__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Object__count__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Object__heap__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Object__sizeof__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_Object__table__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_E_unpluggedSysInt__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_E_unpluggedSysInt__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_numSysInts__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_numSysInts__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_numEvents__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_numEvents__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_numStatusRegs__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_numStatusRegs__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_sysIntToHostInt__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_hostIntToEventId__C");
#pragma DATA_SECTION(ti_sysbios_family_c66_tci66xx_CpIntc_eventId__C, ".const:ti_sysbios_family_c66_tci66xx_CpIntc_eventId__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__DESC__C, ".const:ti_sysbios_gates_GateHwi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__PARAMS__C, ".const:ti_sysbios_gates_GateHwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsEnabled__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsIncluded__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsMask__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__gateObj__C, ".const:ti_sysbios_gates_GateHwi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__gatePrms__C, ".const:ti_sysbios_gates_GateHwi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__id__C, ".const:ti_sysbios_gates_GateHwi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerDefined__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerObj__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn0__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn1__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn2__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn4__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn8__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C, ".const:ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__count__C, ".const:ti_sysbios_gates_GateHwi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__heap__C, ".const:ti_sysbios_gates_GateHwi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__sizeof__C, ".const:ti_sysbios_gates_GateHwi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__table__C, ".const:ti_sysbios_gates_GateHwi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__DESC__C, ".const:ti_sysbios_gates_GateMutex_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__PARAMS__C, ".const:ti_sysbios_gates_GateMutex_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsEnabled__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsIncluded__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsMask__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__gateObj__C, ".const:ti_sysbios_gates_GateMutex_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__gatePrms__C, ".const:ti_sysbios_gates_GateMutex_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__id__C, ".const:ti_sysbios_gates_GateMutex_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerDefined__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerObj__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn0__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn1__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn2__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn4__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn8__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C, ".const:ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__count__C, ".const:ti_sysbios_gates_GateMutex_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__heap__C, ".const:ti_sysbios_gates_GateMutex_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__sizeof__C, ".const:ti_sysbios_gates_GateMutex_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__table__C, ".const:ti_sysbios_gates_GateMutex_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_A_badContext__C, ".const:ti_sysbios_gates_GateMutex_A_badContext__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__DESC__C, ".const:ti_sysbios_hal_Hwi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__PARAMS__C, ".const:ti_sysbios_hal_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsEnabled__C, ".const:ti_sysbios_hal_Hwi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsIncluded__C, ".const:ti_sysbios_hal_Hwi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsMask__C, ".const:ti_sysbios_hal_Hwi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__gateObj__C, ".const:ti_sysbios_hal_Hwi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__gatePrms__C, ".const:ti_sysbios_hal_Hwi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__id__C, ".const:ti_sysbios_hal_Hwi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerDefined__C, ".const:ti_sysbios_hal_Hwi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerObj__C, ".const:ti_sysbios_hal_Hwi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn0__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn1__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn2__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn4__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn8__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_Hwi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__count__C, ".const:ti_sysbios_hal_Hwi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__heap__C, ".const:ti_sysbios_hal_Hwi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__sizeof__C, ".const:ti_sysbios_hal_Hwi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__table__C, ".const:ti_sysbios_hal_Hwi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherSwiSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherSwiSupport__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherTaskSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherTaskSupport__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_E_stackOverflow__C, ".const:ti_sysbios_hal_Hwi_E_stackOverflow__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__DESC__C, ".const:ti_sysbios_hal_Timer_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__PARAMS__C, ".const:ti_sysbios_hal_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__diagsEnabled__C, ".const:ti_sysbios_hal_Timer_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__diagsIncluded__C, ".const:ti_sysbios_hal_Timer_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__diagsMask__C, ".const:ti_sysbios_hal_Timer_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__gateObj__C, ".const:ti_sysbios_hal_Timer_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__gatePrms__C, ".const:ti_sysbios_hal_Timer_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__id__C, ".const:ti_sysbios_hal_Timer_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerDefined__C, ".const:ti_sysbios_hal_Timer_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerObj__C, ".const:ti_sysbios_hal_Timer_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn0__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn1__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn2__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn4__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn8__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_Timer_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__count__C, ".const:ti_sysbios_hal_Timer_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__heap__C, ".const:ti_sysbios_hal_Timer_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__sizeof__C, ".const:ti_sysbios_hal_Timer_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__table__C, ".const:ti_sysbios_hal_Timer_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__DESC__C, ".const:ti_sysbios_heaps_HeapMem_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__PARAMS__C, ".const:ti_sysbios_heaps_HeapMem_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsMask__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__gateObj__C, ".const:ti_sysbios_heaps_HeapMem_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__gatePrms__C, ".const:ti_sysbios_heaps_HeapMem_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__id__C, ".const:ti_sysbios_heaps_HeapMem_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerDefined__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerObj__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C, ".const:ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__count__C, ".const:ti_sysbios_heaps_HeapMem_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__heap__C, ".const:ti_sysbios_heaps_HeapMem_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__sizeof__C, ".const:ti_sysbios_heaps_HeapMem_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__table__C, ".const:ti_sysbios_heaps_HeapMem_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_zeroBlock__C, ".const:ti_sysbios_heaps_HeapMem_A_zeroBlock__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_heapSize__C, ".const:ti_sysbios_heaps_HeapMem_A_heapSize__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_align__C, ".const:ti_sysbios_heaps_HeapMem_A_align__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_E_memory__C, ".const:ti_sysbios_heaps_HeapMem_E_memory__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_invalidFree__C, ".const:ti_sysbios_heaps_HeapMem_A_invalidFree__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_reqAlign__C, ".const:ti_sysbios_heaps_HeapMem_reqAlign__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__DESC__C, ".const:ti_sysbios_knl_Clock_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__PARAMS__C, ".const:ti_sysbios_knl_Clock_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Clock_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Clock_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsMask__C, ".const:ti_sysbios_knl_Clock_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__gateObj__C, ".const:ti_sysbios_knl_Clock_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__gatePrms__C, ".const:ti_sysbios_knl_Clock_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__id__C, ".const:ti_sysbios_knl_Clock_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerDefined__C, ".const:ti_sysbios_knl_Clock_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerObj__C, ".const:ti_sysbios_knl_Clock_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Clock_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__count__C, ".const:ti_sysbios_knl_Clock_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__heap__C, ".const:ti_sysbios_knl_Clock_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__sizeof__C, ".const:ti_sysbios_knl_Clock_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__table__C, ".const:ti_sysbios_knl_Clock_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LW_delayed__C, ".const:ti_sysbios_knl_Clock_LW_delayed__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_tick__C, ".const:ti_sysbios_knl_Clock_LM_tick__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_begin__C, ".const:ti_sysbios_knl_Clock_LM_begin__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_clockDisabled__C, ".const:ti_sysbios_knl_Clock_A_clockDisabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_badThreadType__C, ".const:ti_sysbios_knl_Clock_A_badThreadType__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickSource__C, ".const:ti_sysbios_knl_Clock_tickSource__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickMode__C, ".const:ti_sysbios_knl_Clock_tickMode__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_timerId__C, ".const:ti_sysbios_knl_Clock_timerId__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickPeriod__C, ".const:ti_sysbios_knl_Clock_tickPeriod__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_funcList__A, ".const:ti_sysbios_knl_Idle_funcList__A");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_coreList__A, ".const:ti_sysbios_knl_Idle_coreList__A");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Idle_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Idle_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsMask__C, ".const:ti_sysbios_knl_Idle_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__gateObj__C, ".const:ti_sysbios_knl_Idle_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__gatePrms__C, ".const:ti_sysbios_knl_Idle_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__id__C, ".const:ti_sysbios_knl_Idle_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerDefined__C, ".const:ti_sysbios_knl_Idle_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerObj__C, ".const:ti_sysbios_knl_Idle_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Idle_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__count__C, ".const:ti_sysbios_knl_Idle_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__heap__C, ".const:ti_sysbios_knl_Idle_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__sizeof__C, ".const:ti_sysbios_knl_Idle_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__table__C, ".const:ti_sysbios_knl_Idle_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_funcList__C, ".const:ti_sysbios_knl_Idle_funcList__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_coreList__C, ".const:ti_sysbios_knl_Idle_coreList__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsMask__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__gateObj__C, ".const:ti_sysbios_knl_Intrinsics_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__gatePrms__C, ".const:ti_sysbios_knl_Intrinsics_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__id__C, ".const:ti_sysbios_knl_Intrinsics_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerDefined__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerObj__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__count__C, ".const:ti_sysbios_knl_Intrinsics_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__heap__C, ".const:ti_sysbios_knl_Intrinsics_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__sizeof__C, ".const:ti_sysbios_knl_Intrinsics_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__table__C, ".const:ti_sysbios_knl_Intrinsics_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__DESC__C, ".const:ti_sysbios_knl_Queue_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__PARAMS__C, ".const:ti_sysbios_knl_Queue_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Queue_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Queue_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsMask__C, ".const:ti_sysbios_knl_Queue_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__gateObj__C, ".const:ti_sysbios_knl_Queue_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__gatePrms__C, ".const:ti_sysbios_knl_Queue_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__id__C, ".const:ti_sysbios_knl_Queue_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerDefined__C, ".const:ti_sysbios_knl_Queue_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerObj__C, ".const:ti_sysbios_knl_Queue_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Queue_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__count__C, ".const:ti_sysbios_knl_Queue_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__heap__C, ".const:ti_sysbios_knl_Queue_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__sizeof__C, ".const:ti_sysbios_knl_Queue_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__table__C, ".const:ti_sysbios_knl_Queue_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__DESC__C, ".const:ti_sysbios_knl_Semaphore_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__PARAMS__C, ".const:ti_sysbios_knl_Semaphore_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsMask__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__gateObj__C, ".const:ti_sysbios_knl_Semaphore_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__gatePrms__C, ".const:ti_sysbios_knl_Semaphore_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__id__C, ".const:ti_sysbios_knl_Semaphore_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerDefined__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerObj__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__count__C, ".const:ti_sysbios_knl_Semaphore_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__heap__C, ".const:ti_sysbios_knl_Semaphore_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__sizeof__C, ".const:ti_sysbios_knl_Semaphore_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__table__C, ".const:ti_sysbios_knl_Semaphore_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_post__C, ".const:ti_sysbios_knl_Semaphore_LM_post__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_pend__C, ".const:ti_sysbios_knl_Semaphore_LM_pend__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_noEvents__C, ".const:ti_sysbios_knl_Semaphore_A_noEvents__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_invTimeout__C, ".const:ti_sysbios_knl_Semaphore_A_invTimeout__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_badContext__C, ".const:ti_sysbios_knl_Semaphore_A_badContext__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_overflow__C, ".const:ti_sysbios_knl_Semaphore_A_overflow__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_supportsEvents__C, ".const:ti_sysbios_knl_Semaphore_supportsEvents__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_eventPost__C, ".const:ti_sysbios_knl_Semaphore_eventPost__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_eventSync__C, ".const:ti_sysbios_knl_Semaphore_eventSync__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__DESC__C, ".const:ti_sysbios_knl_Swi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__PARAMS__C, ".const:ti_sysbios_knl_Swi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Swi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Swi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsMask__C, ".const:ti_sysbios_knl_Swi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__gateObj__C, ".const:ti_sysbios_knl_Swi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__gatePrms__C, ".const:ti_sysbios_knl_Swi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__id__C, ".const:ti_sysbios_knl_Swi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerDefined__C, ".const:ti_sysbios_knl_Swi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerObj__C, ".const:ti_sysbios_knl_Swi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Swi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__count__C, ".const:ti_sysbios_knl_Swi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__heap__C, ".const:ti_sysbios_knl_Swi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__sizeof__C, ".const:ti_sysbios_knl_Swi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__table__C, ".const:ti_sysbios_knl_Swi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_begin__C, ".const:ti_sysbios_knl_Swi_LM_begin__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LD_end__C, ".const:ti_sysbios_knl_Swi_LD_end__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_post__C, ".const:ti_sysbios_knl_Swi_LM_post__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_swiDisabled__C, ".const:ti_sysbios_knl_Swi_A_swiDisabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_badPriority__C, ".const:ti_sysbios_knl_Swi_A_badPriority__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_numPriorities__C, ".const:ti_sysbios_knl_Swi_numPriorities__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_hooks__C, ".const:ti_sysbios_knl_Swi_hooks__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_taskDisable__C, ".const:ti_sysbios_knl_Swi_taskDisable__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_taskRestore__C, ".const:ti_sysbios_knl_Swi_taskRestore__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_numConstructedSwis__C, ".const:ti_sysbios_knl_Swi_numConstructedSwis__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__DESC__C, ".const:ti_sysbios_knl_Task_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__PARAMS__C, ".const:ti_sysbios_knl_Task_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_hooks__A, ".const:ti_sysbios_knl_Task_hooks__A");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Task_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Task_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsMask__C, ".const:ti_sysbios_knl_Task_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__gateObj__C, ".const:ti_sysbios_knl_Task_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__gatePrms__C, ".const:ti_sysbios_knl_Task_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__id__C, ".const:ti_sysbios_knl_Task_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerDefined__C, ".const:ti_sysbios_knl_Task_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerObj__C, ".const:ti_sysbios_knl_Task_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Task_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__count__C, ".const:ti_sysbios_knl_Task_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__heap__C, ".const:ti_sysbios_knl_Task_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__sizeof__C, ".const:ti_sysbios_knl_Task_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__table__C, ".const:ti_sysbios_knl_Task_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_switch__C, ".const:ti_sysbios_knl_Task_LM_switch__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_sleep__C, ".const:ti_sysbios_knl_Task_LM_sleep__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_ready__C, ".const:ti_sysbios_knl_Task_LD_ready__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_block__C, ".const:ti_sysbios_knl_Task_LD_block__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_yield__C, ".const:ti_sysbios_knl_Task_LM_yield__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setPri__C, ".const:ti_sysbios_knl_Task_LM_setPri__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_exit__C, ".const:ti_sysbios_knl_Task_LD_exit__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setAffinity__C, ".const:ti_sysbios_knl_Task_LM_setAffinity__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_schedule__C, ".const:ti_sysbios_knl_Task_LM_schedule__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_noWork__C, ".const:ti_sysbios_knl_Task_LM_noWork__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_stackOverflow__C, ".const:ti_sysbios_knl_Task_E_stackOverflow__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_spOutOfBounds__C, ".const:ti_sysbios_knl_Task_E_spOutOfBounds__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_deleteNotAllowed__C, ".const:ti_sysbios_knl_Task_E_deleteNotAllowed__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badThreadType__C, ".const:ti_sysbios_knl_Task_A_badThreadType__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTaskState__C, ".const:ti_sysbios_knl_Task_A_badTaskState__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_noPendElem__C, ".const:ti_sysbios_knl_Task_A_noPendElem__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_taskDisabled__C, ".const:ti_sysbios_knl_Task_A_taskDisabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badPriority__C, ".const:ti_sysbios_knl_Task_A_badPriority__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTimeout__C, ".const:ti_sysbios_knl_Task_A_badTimeout__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badAffinity__C, ".const:ti_sysbios_knl_Task_A_badAffinity__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_numPriorities__C, ".const:ti_sysbios_knl_Task_numPriorities__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_defaultStackSize__C, ".const:ti_sysbios_knl_Task_defaultStackSize__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_defaultStackHeap__C, ".const:ti_sysbios_knl_Task_defaultStackHeap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_allBlockedFunc__C, ".const:ti_sysbios_knl_Task_allBlockedFunc__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_initStackFlag__C, ".const:ti_sysbios_knl_Task_initStackFlag__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_deleteTerminatedTasks__C, ".const:ti_sysbios_knl_Task_deleteTerminatedTasks__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_hooks__C, ".const:ti_sysbios_knl_Task_hooks__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_numConstructedTasks__C, ".const:ti_sysbios_knl_Task_numConstructedTasks__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_startupHookFunc__C, ".const:ti_sysbios_knl_Task_startupHookFunc__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Object__DESC__C, ".const:ti_sysbios_timers_timer64_Timer_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Object__PARAMS__C, ".const:ti_sysbios_timers_timer64_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_timerSettings__A, ".const:ti_sysbios_timers_timer64_Timer_timerSettings__A");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__diagsEnabled__C, ".const:ti_sysbios_timers_timer64_Timer_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__diagsIncluded__C, ".const:ti_sysbios_timers_timer64_Timer_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__diagsMask__C, ".const:ti_sysbios_timers_timer64_Timer_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__gateObj__C, ".const:ti_sysbios_timers_timer64_Timer_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__gatePrms__C, ".const:ti_sysbios_timers_timer64_Timer_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__id__C, ".const:ti_sysbios_timers_timer64_Timer_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__loggerDefined__C, ".const:ti_sysbios_timers_timer64_Timer_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__loggerObj__C, ".const:ti_sysbios_timers_timer64_Timer_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__loggerFxn0__C, ".const:ti_sysbios_timers_timer64_Timer_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__loggerFxn1__C, ".const:ti_sysbios_timers_timer64_Timer_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__loggerFxn2__C, ".const:ti_sysbios_timers_timer64_Timer_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__loggerFxn4__C, ".const:ti_sysbios_timers_timer64_Timer_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__loggerFxn8__C, ".const:ti_sysbios_timers_timer64_Timer_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Module__startupDoneFxn__C, ".const:ti_sysbios_timers_timer64_Timer_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Object__count__C, ".const:ti_sysbios_timers_timer64_Timer_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Object__heap__C, ".const:ti_sysbios_timers_timer64_Timer_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Object__sizeof__C, ".const:ti_sysbios_timers_timer64_Timer_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_Object__table__C, ".const:ti_sysbios_timers_timer64_Timer_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_A_notAvailable__C, ".const:ti_sysbios_timers_timer64_Timer_A_notAvailable__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_E_invalidTimer__C, ".const:ti_sysbios_timers_timer64_Timer_E_invalidTimer__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_E_notAvailable__C, ".const:ti_sysbios_timers_timer64_Timer_E_notAvailable__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_E_cannotSupport__C, ".const:ti_sysbios_timers_timer64_Timer_E_cannotSupport__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_anyMask__C, ".const:ti_sysbios_timers_timer64_Timer_anyMask__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_defaultHalf__C, ".const:ti_sysbios_timers_timer64_Timer_defaultHalf__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_timerSettings__C, ".const:ti_sysbios_timers_timer64_Timer_timerSettings__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_startupNeeded__C, ".const:ti_sysbios_timers_timer64_Timer_startupNeeded__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_freqDivisor__C, ".const:ti_sysbios_timers_timer64_Timer_freqDivisor__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_numTimerDevices__C, ".const:ti_sysbios_timers_timer64_Timer_numTimerDevices__C");
#pragma DATA_SECTION(ti_sysbios_timers_timer64_Timer_numLocalTimers__C, ".const:ti_sysbios_timers_timer64_Timer_numLocalTimers__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsEnabled__C, ".const:xdc_runtime_Assert_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsIncluded__C, ".const:xdc_runtime_Assert_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsMask__C, ".const:xdc_runtime_Assert_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__gateObj__C, ".const:xdc_runtime_Assert_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__gatePrms__C, ".const:xdc_runtime_Assert_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__id__C, ".const:xdc_runtime_Assert_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerDefined__C, ".const:xdc_runtime_Assert_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerObj__C, ".const:xdc_runtime_Assert_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn0__C, ".const:xdc_runtime_Assert_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn1__C, ".const:xdc_runtime_Assert_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn2__C, ".const:xdc_runtime_Assert_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn4__C, ".const:xdc_runtime_Assert_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn8__C, ".const:xdc_runtime_Assert_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__startupDoneFxn__C, ".const:xdc_runtime_Assert_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Object__count__C, ".const:xdc_runtime_Assert_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Object__heap__C, ".const:xdc_runtime_Assert_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Object__sizeof__C, ".const:xdc_runtime_Assert_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Object__table__C, ".const:xdc_runtime_Assert_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Assert_E_assertFailed__C, ".const:xdc_runtime_Assert_E_assertFailed__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsEnabled__C, ".const:xdc_runtime_Core_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsIncluded__C, ".const:xdc_runtime_Core_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsMask__C, ".const:xdc_runtime_Core_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__gateObj__C, ".const:xdc_runtime_Core_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__gatePrms__C, ".const:xdc_runtime_Core_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__id__C, ".const:xdc_runtime_Core_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerDefined__C, ".const:xdc_runtime_Core_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerObj__C, ".const:xdc_runtime_Core_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn0__C, ".const:xdc_runtime_Core_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn1__C, ".const:xdc_runtime_Core_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn2__C, ".const:xdc_runtime_Core_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn4__C, ".const:xdc_runtime_Core_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn8__C, ".const:xdc_runtime_Core_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__startupDoneFxn__C, ".const:xdc_runtime_Core_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Core_Object__count__C, ".const:xdc_runtime_Core_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Core_Object__heap__C, ".const:xdc_runtime_Core_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Core_Object__sizeof__C, ".const:xdc_runtime_Core_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Core_Object__table__C, ".const:xdc_runtime_Core_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Core_A_initializedParams__C, ".const:xdc_runtime_Core_A_initializedParams__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsEnabled__C, ".const:xdc_runtime_Defaults_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsIncluded__C, ".const:xdc_runtime_Defaults_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsMask__C, ".const:xdc_runtime_Defaults_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__gateObj__C, ".const:xdc_runtime_Defaults_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__gatePrms__C, ".const:xdc_runtime_Defaults_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__id__C, ".const:xdc_runtime_Defaults_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerDefined__C, ".const:xdc_runtime_Defaults_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerObj__C, ".const:xdc_runtime_Defaults_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn0__C, ".const:xdc_runtime_Defaults_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn1__C, ".const:xdc_runtime_Defaults_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn2__C, ".const:xdc_runtime_Defaults_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn4__C, ".const:xdc_runtime_Defaults_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn8__C, ".const:xdc_runtime_Defaults_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__startupDoneFxn__C, ".const:xdc_runtime_Defaults_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__count__C, ".const:xdc_runtime_Defaults_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__heap__C, ".const:xdc_runtime_Defaults_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__sizeof__C, ".const:xdc_runtime_Defaults_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__table__C, ".const:xdc_runtime_Defaults_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsEnabled__C, ".const:xdc_runtime_Diags_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsIncluded__C, ".const:xdc_runtime_Diags_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsMask__C, ".const:xdc_runtime_Diags_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__gateObj__C, ".const:xdc_runtime_Diags_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__gatePrms__C, ".const:xdc_runtime_Diags_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__id__C, ".const:xdc_runtime_Diags_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerDefined__C, ".const:xdc_runtime_Diags_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerObj__C, ".const:xdc_runtime_Diags_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn0__C, ".const:xdc_runtime_Diags_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn1__C, ".const:xdc_runtime_Diags_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn2__C, ".const:xdc_runtime_Diags_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn4__C, ".const:xdc_runtime_Diags_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn8__C, ".const:xdc_runtime_Diags_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__startupDoneFxn__C, ".const:xdc_runtime_Diags_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Object__count__C, ".const:xdc_runtime_Diags_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Object__heap__C, ".const:xdc_runtime_Diags_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Object__sizeof__C, ".const:xdc_runtime_Diags_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Object__table__C, ".const:xdc_runtime_Diags_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Diags_setMaskEnabled__C, ".const:xdc_runtime_Diags_setMaskEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Diags_dictBase__C, ".const:xdc_runtime_Diags_dictBase__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsEnabled__C, ".const:xdc_runtime_Error_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsIncluded__C, ".const:xdc_runtime_Error_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsMask__C, ".const:xdc_runtime_Error_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__gateObj__C, ".const:xdc_runtime_Error_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__gatePrms__C, ".const:xdc_runtime_Error_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__id__C, ".const:xdc_runtime_Error_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerDefined__C, ".const:xdc_runtime_Error_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerObj__C, ".const:xdc_runtime_Error_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn0__C, ".const:xdc_runtime_Error_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn1__C, ".const:xdc_runtime_Error_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn2__C, ".const:xdc_runtime_Error_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn4__C, ".const:xdc_runtime_Error_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn8__C, ".const:xdc_runtime_Error_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__startupDoneFxn__C, ".const:xdc_runtime_Error_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Error_Object__count__C, ".const:xdc_runtime_Error_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Error_Object__heap__C, ".const:xdc_runtime_Error_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Error_Object__sizeof__C, ".const:xdc_runtime_Error_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Error_Object__table__C, ".const:xdc_runtime_Error_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Error_E_generic__C, ".const:xdc_runtime_Error_E_generic__C");
#pragma DATA_SECTION(xdc_runtime_Error_E_memory__C, ".const:xdc_runtime_Error_E_memory__C");
#pragma DATA_SECTION(xdc_runtime_Error_E_msgCode__C, ".const:xdc_runtime_Error_E_msgCode__C");
#pragma DATA_SECTION(xdc_runtime_Error_policy__C, ".const:xdc_runtime_Error_policy__C");
#pragma DATA_SECTION(xdc_runtime_Error_raiseHook__C, ".const:xdc_runtime_Error_raiseHook__C");
#pragma DATA_SECTION(xdc_runtime_Error_maxDepth__C, ".const:xdc_runtime_Error_maxDepth__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsEnabled__C, ".const:xdc_runtime_Gate_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsIncluded__C, ".const:xdc_runtime_Gate_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsMask__C, ".const:xdc_runtime_Gate_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__gateObj__C, ".const:xdc_runtime_Gate_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__gatePrms__C, ".const:xdc_runtime_Gate_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__id__C, ".const:xdc_runtime_Gate_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerDefined__C, ".const:xdc_runtime_Gate_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerObj__C, ".const:xdc_runtime_Gate_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn0__C, ".const:xdc_runtime_Gate_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn1__C, ".const:xdc_runtime_Gate_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn2__C, ".const:xdc_runtime_Gate_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn4__C, ".const:xdc_runtime_Gate_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn8__C, ".const:xdc_runtime_Gate_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__startupDoneFxn__C, ".const:xdc_runtime_Gate_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Object__count__C, ".const:xdc_runtime_Gate_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Object__heap__C, ".const:xdc_runtime_Gate_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Object__sizeof__C, ".const:xdc_runtime_Gate_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Object__table__C, ".const:xdc_runtime_Gate_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsEnabled__C, ".const:xdc_runtime_Log_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsIncluded__C, ".const:xdc_runtime_Log_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsMask__C, ".const:xdc_runtime_Log_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__gateObj__C, ".const:xdc_runtime_Log_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__gatePrms__C, ".const:xdc_runtime_Log_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__id__C, ".const:xdc_runtime_Log_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerDefined__C, ".const:xdc_runtime_Log_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerObj__C, ".const:xdc_runtime_Log_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn0__C, ".const:xdc_runtime_Log_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn1__C, ".const:xdc_runtime_Log_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn2__C, ".const:xdc_runtime_Log_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn4__C, ".const:xdc_runtime_Log_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn8__C, ".const:xdc_runtime_Log_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__startupDoneFxn__C, ".const:xdc_runtime_Log_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Log_Object__count__C, ".const:xdc_runtime_Log_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Log_Object__heap__C, ".const:xdc_runtime_Log_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Log_Object__sizeof__C, ".const:xdc_runtime_Log_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Log_Object__table__C, ".const:xdc_runtime_Log_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_construct__C, ".const:xdc_runtime_Log_L_construct__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_create__C, ".const:xdc_runtime_Log_L_create__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_destruct__C, ".const:xdc_runtime_Log_L_destruct__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_delete__C, ".const:xdc_runtime_Log_L_delete__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_error__C, ".const:xdc_runtime_Log_L_error__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_warning__C, ".const:xdc_runtime_Log_L_warning__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_info__C, ".const:xdc_runtime_Log_L_info__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_start__C, ".const:xdc_runtime_Log_L_start__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_stop__C, ".const:xdc_runtime_Log_L_stop__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_startInstance__C, ".const:xdc_runtime_Log_L_startInstance__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_stopInstance__C, ".const:xdc_runtime_Log_L_stopInstance__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsEnabled__C, ".const:xdc_runtime_Main_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsIncluded__C, ".const:xdc_runtime_Main_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsMask__C, ".const:xdc_runtime_Main_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__gateObj__C, ".const:xdc_runtime_Main_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__gatePrms__C, ".const:xdc_runtime_Main_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__id__C, ".const:xdc_runtime_Main_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerDefined__C, ".const:xdc_runtime_Main_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerObj__C, ".const:xdc_runtime_Main_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn0__C, ".const:xdc_runtime_Main_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn1__C, ".const:xdc_runtime_Main_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn2__C, ".const:xdc_runtime_Main_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn4__C, ".const:xdc_runtime_Main_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn8__C, ".const:xdc_runtime_Main_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__startupDoneFxn__C, ".const:xdc_runtime_Main_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Main_Object__count__C, ".const:xdc_runtime_Main_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Main_Object__heap__C, ".const:xdc_runtime_Main_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Main_Object__sizeof__C, ".const:xdc_runtime_Main_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Main_Object__table__C, ".const:xdc_runtime_Main_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsEnabled__C, ".const:xdc_runtime_Memory_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsIncluded__C, ".const:xdc_runtime_Memory_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsMask__C, ".const:xdc_runtime_Memory_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__gateObj__C, ".const:xdc_runtime_Memory_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__gatePrms__C, ".const:xdc_runtime_Memory_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__id__C, ".const:xdc_runtime_Memory_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerDefined__C, ".const:xdc_runtime_Memory_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerObj__C, ".const:xdc_runtime_Memory_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn0__C, ".const:xdc_runtime_Memory_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn1__C, ".const:xdc_runtime_Memory_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn2__C, ".const:xdc_runtime_Memory_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn4__C, ".const:xdc_runtime_Memory_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn8__C, ".const:xdc_runtime_Memory_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__startupDoneFxn__C, ".const:xdc_runtime_Memory_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Object__count__C, ".const:xdc_runtime_Memory_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Object__heap__C, ".const:xdc_runtime_Memory_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Object__sizeof__C, ".const:xdc_runtime_Memory_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Object__table__C, ".const:xdc_runtime_Memory_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Memory_defaultHeapInstance__C, ".const:xdc_runtime_Memory_defaultHeapInstance__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsEnabled__C, ".const:xdc_runtime_Registry_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsIncluded__C, ".const:xdc_runtime_Registry_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsMask__C, ".const:xdc_runtime_Registry_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__gateObj__C, ".const:xdc_runtime_Registry_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__gatePrms__C, ".const:xdc_runtime_Registry_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__id__C, ".const:xdc_runtime_Registry_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerDefined__C, ".const:xdc_runtime_Registry_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerObj__C, ".const:xdc_runtime_Registry_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn0__C, ".const:xdc_runtime_Registry_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn1__C, ".const:xdc_runtime_Registry_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn2__C, ".const:xdc_runtime_Registry_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn4__C, ".const:xdc_runtime_Registry_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn8__C, ".const:xdc_runtime_Registry_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__startupDoneFxn__C, ".const:xdc_runtime_Registry_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Object__count__C, ".const:xdc_runtime_Registry_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Object__heap__C, ".const:xdc_runtime_Registry_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Object__sizeof__C, ".const:xdc_runtime_Registry_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Object__table__C, ".const:xdc_runtime_Registry_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Startup_firstFxns__A, ".const:xdc_runtime_Startup_firstFxns__A");
#pragma DATA_SECTION(xdc_runtime_Startup_lastFxns__A, ".const:xdc_runtime_Startup_lastFxns__A");
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__A, ".const:xdc_runtime_Startup_sfxnTab__A");
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__A, ".const:xdc_runtime_Startup_sfxnRts__A");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsEnabled__C, ".const:xdc_runtime_Startup_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsIncluded__C, ".const:xdc_runtime_Startup_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsMask__C, ".const:xdc_runtime_Startup_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__gateObj__C, ".const:xdc_runtime_Startup_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__gatePrms__C, ".const:xdc_runtime_Startup_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__id__C, ".const:xdc_runtime_Startup_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerDefined__C, ".const:xdc_runtime_Startup_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerObj__C, ".const:xdc_runtime_Startup_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn0__C, ".const:xdc_runtime_Startup_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn1__C, ".const:xdc_runtime_Startup_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn2__C, ".const:xdc_runtime_Startup_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn4__C, ".const:xdc_runtime_Startup_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn8__C, ".const:xdc_runtime_Startup_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__startupDoneFxn__C, ".const:xdc_runtime_Startup_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Object__count__C, ".const:xdc_runtime_Startup_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Object__heap__C, ".const:xdc_runtime_Startup_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Object__sizeof__C, ".const:xdc_runtime_Startup_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Object__table__C, ".const:xdc_runtime_Startup_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Startup_maxPasses__C, ".const:xdc_runtime_Startup_maxPasses__C");
#pragma DATA_SECTION(xdc_runtime_Startup_firstFxns__C, ".const:xdc_runtime_Startup_firstFxns__C");
#pragma DATA_SECTION(xdc_runtime_Startup_lastFxns__C, ".const:xdc_runtime_Startup_lastFxns__C");
#pragma DATA_SECTION(xdc_runtime_Startup_startModsFxn__C, ".const:xdc_runtime_Startup_startModsFxn__C");
#pragma DATA_SECTION(xdc_runtime_Startup_execImpl__C, ".const:xdc_runtime_Startup_execImpl__C");
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__C, ".const:xdc_runtime_Startup_sfxnTab__C");
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__C, ".const:xdc_runtime_Startup_sfxnRts__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsEnabled__C, ".const:xdc_runtime_SysMin_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsIncluded__C, ".const:xdc_runtime_SysMin_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsMask__C, ".const:xdc_runtime_SysMin_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__gateObj__C, ".const:xdc_runtime_SysMin_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__gatePrms__C, ".const:xdc_runtime_SysMin_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__id__C, ".const:xdc_runtime_SysMin_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerDefined__C, ".const:xdc_runtime_SysMin_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerObj__C, ".const:xdc_runtime_SysMin_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn0__C, ".const:xdc_runtime_SysMin_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn1__C, ".const:xdc_runtime_SysMin_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn2__C, ".const:xdc_runtime_SysMin_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn4__C, ".const:xdc_runtime_SysMin_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn8__C, ".const:xdc_runtime_SysMin_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__startupDoneFxn__C, ".const:xdc_runtime_SysMin_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__count__C, ".const:xdc_runtime_SysMin_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__heap__C, ".const:xdc_runtime_SysMin_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__sizeof__C, ".const:xdc_runtime_SysMin_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__table__C, ".const:xdc_runtime_SysMin_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_bufSize__C, ".const:xdc_runtime_SysMin_bufSize__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_flushAtExit__C, ".const:xdc_runtime_SysMin_flushAtExit__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_outputFxn__C, ".const:xdc_runtime_SysMin_outputFxn__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_outputFunc__C, ".const:xdc_runtime_SysMin_outputFunc__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsEnabled__C, ".const:xdc_runtime_System_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsIncluded__C, ".const:xdc_runtime_System_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsMask__C, ".const:xdc_runtime_System_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__gateObj__C, ".const:xdc_runtime_System_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__gatePrms__C, ".const:xdc_runtime_System_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__id__C, ".const:xdc_runtime_System_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerDefined__C, ".const:xdc_runtime_System_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerObj__C, ".const:xdc_runtime_System_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn0__C, ".const:xdc_runtime_System_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn1__C, ".const:xdc_runtime_System_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn2__C, ".const:xdc_runtime_System_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn4__C, ".const:xdc_runtime_System_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn8__C, ".const:xdc_runtime_System_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__startupDoneFxn__C, ".const:xdc_runtime_System_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_System_Object__count__C, ".const:xdc_runtime_System_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_System_Object__heap__C, ".const:xdc_runtime_System_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_System_Object__sizeof__C, ".const:xdc_runtime_System_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_System_Object__table__C, ".const:xdc_runtime_System_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_System_A_cannotFitIntoArg__C, ".const:xdc_runtime_System_A_cannotFitIntoArg__C");
#pragma DATA_SECTION(xdc_runtime_System_maxAtexitHandlers__C, ".const:xdc_runtime_System_maxAtexitHandlers__C");
#pragma DATA_SECTION(xdc_runtime_System_extendFxn__C, ".const:xdc_runtime_System_extendFxn__C");
#pragma DATA_SECTION(xdc_runtime_Text_charTab__A, ".const:xdc_runtime_Text_charTab__A");
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__A, ".const:xdc_runtime_Text_nodeTab__A");
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsEnabled__C, ".const:xdc_runtime_Text_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsIncluded__C, ".const:xdc_runtime_Text_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsMask__C, ".const:xdc_runtime_Text_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__gateObj__C, ".const:xdc_runtime_Text_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__gatePrms__C, ".const:xdc_runtime_Text_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__id__C, ".const:xdc_runtime_Text_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerDefined__C, ".const:xdc_runtime_Text_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerObj__C, ".const:xdc_runtime_Text_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn0__C, ".const:xdc_runtime_Text_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn1__C, ".const:xdc_runtime_Text_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn2__C, ".const:xdc_runtime_Text_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn4__C, ".const:xdc_runtime_Text_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn8__C, ".const:xdc_runtime_Text_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__startupDoneFxn__C, ".const:xdc_runtime_Text_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Text_Object__count__C, ".const:xdc_runtime_Text_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Text_Object__heap__C, ".const:xdc_runtime_Text_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Text_Object__sizeof__C, ".const:xdc_runtime_Text_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Text_Object__table__C, ".const:xdc_runtime_Text_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Text_nameUnknown__C, ".const:xdc_runtime_Text_nameUnknown__C");
#pragma DATA_SECTION(xdc_runtime_Text_nameEmpty__C, ".const:xdc_runtime_Text_nameEmpty__C");
#pragma DATA_SECTION(xdc_runtime_Text_nameStatic__C, ".const:xdc_runtime_Text_nameStatic__C");
#pragma DATA_SECTION(xdc_runtime_Text_isLoaded__C, ".const:xdc_runtime_Text_isLoaded__C");
#pragma DATA_SECTION(xdc_runtime_Text_charTab__C, ".const:xdc_runtime_Text_charTab__C");
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__C, ".const:xdc_runtime_Text_nodeTab__C");
#pragma DATA_SECTION(xdc_runtime_Text_charCnt__C, ".const:xdc_runtime_Text_charCnt__C");
#pragma DATA_SECTION(xdc_runtime_Text_nodeCnt__C, ".const:xdc_runtime_Text_nodeCnt__C");
#pragma DATA_SECTION(xdc_runtime_Text_unnamedModsLastId__C, ".const:xdc_runtime_Text_unnamedModsLastId__C");
#pragma DATA_SECTION(xdc_runtime_Text_registryModsLastId__C, ".const:xdc_runtime_Text_registryModsLastId__C");
#pragma DATA_SECTION(xdc_runtime_Text_visitRopeFxn__C, ".const:xdc_runtime_Text_visitRopeFxn__C");
#pragma DATA_SECTION(xdc_runtime_Text_visitRopeFxn2__C, ".const:xdc_runtime_Text_visitRopeFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsEnabled__C, ".const:xdc_runtime_Timestamp_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsIncluded__C, ".const:xdc_runtime_Timestamp_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsMask__C, ".const:xdc_runtime_Timestamp_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__gateObj__C, ".const:xdc_runtime_Timestamp_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__gatePrms__C, ".const:xdc_runtime_Timestamp_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__id__C, ".const:xdc_runtime_Timestamp_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerDefined__C, ".const:xdc_runtime_Timestamp_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerObj__C, ".const:xdc_runtime_Timestamp_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn0__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn1__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn2__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn4__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn8__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__startupDoneFxn__C, ".const:xdc_runtime_Timestamp_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__count__C, ".const:xdc_runtime_Timestamp_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__heap__C, ".const:xdc_runtime_Timestamp_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__sizeof__C, ".const:xdc_runtime_Timestamp_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__table__C, ".const:xdc_runtime_Timestamp_Object__table__C");

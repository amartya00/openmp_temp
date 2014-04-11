/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y30
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class ti_omp_utils
{
    static final String VERS = "@(#) xdc-y30\n";

    static final Proto.Elm $$T_Bool = Proto.Elm.newBool();
    static final Proto.Elm $$T_Num = Proto.Elm.newNum();
    static final Proto.Elm $$T_Str = Proto.Elm.newStr();
    static final Proto.Elm $$T_Obj = Proto.Elm.newObj();

    static final Proto.Fxn $$T_Met = new Proto.Fxn(null, null, 0, -1, false);
    static final Proto.Map $$T_Map = new Proto.Map($$T_Obj);
    static final Proto.Arr $$T_Vec = new Proto.Arr($$T_Obj);

    static final XScriptO $$DEFAULT = Value.DEFAULT;
    static final Object $$UNDEF = Undefined.instance;

    static final Proto.Obj $$Package = (Proto.Obj)Global.get("$$Package");
    static final Proto.Obj $$Module = (Proto.Obj)Global.get("$$Module");
    static final Proto.Obj $$Instance = (Proto.Obj)Global.get("$$Instance");
    static final Proto.Obj $$Params = (Proto.Obj)Global.get("$$Params");

    static final Object $$objFldGet = Global.get("$$objFldGet");
    static final Object $$objFldSet = Global.get("$$objFldSet");
    static final Object $$proxyGet = Global.get("$$proxyGet");
    static final Object $$proxySet = Global.get("$$proxySet");
    static final Object $$delegGet = Global.get("$$delegGet");
    static final Object $$delegSet = Global.get("$$delegSet");

    Scriptable xdcO;
    Session ses;
    Value.Obj om;

    boolean isROV;
    boolean isCFG;

    Proto.Obj pkgP;
    Value.Obj pkgV;

    ArrayList<Object> imports = new ArrayList<Object>();
    ArrayList<Object> loggables = new ArrayList<Object>();
    ArrayList<Object> mcfgs = new ArrayList<Object>();
    ArrayList<Object> icfgs = new ArrayList<Object>();
    ArrayList<String> inherits = new ArrayList<String>();
    ArrayList<Object> proxies = new ArrayList<Object>();
    ArrayList<Object> sizes = new ArrayList<Object>();
    ArrayList<Object> tdefs = new ArrayList<Object>();

    void $$IMPORTS()
    {
        Global.callFxn("loadPackage", xdcO, "ti.omp");
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
        Global.callFxn("loadPackage", xdcO, "xdc.runtime");
        Global.callFxn("loadPackage", xdcO, "ti.sysbios.knl");
        Global.callFxn("loadPackage", xdcO, "xdc.rov");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.ipc");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.utils");
        Global.callFxn("loadPackage", xdcO, "ti.omp.navigator");
        Global.callFxn("loadPackage", xdcO, "ti.sysbios.timers.timer64");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.omp.utils.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.omp.utils", new Value.Obj("ti.omp.utils", pkgP));
    }

    void ThreadLocal$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.omp.utils.ThreadLocal.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.omp.utils.ThreadLocal", new Value.Obj("ti.omp.utils.ThreadLocal", po));
        pkgV.bind("ThreadLocal", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.omp.utils.ThreadLocal$$KeyValueView", new Proto.Obj());
        om.bind("ti.omp.utils.ThreadLocal.KeyValueView", new Proto.Str(spo, false));
        spo = (Proto.Obj)om.bind("ti.omp.utils.ThreadLocal$$Module_State", new Proto.Obj());
        om.bind("ti.omp.utils.ThreadLocal.Module_State", new Proto.Str(spo, false));
    }

    void ThreadLocalStorage$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.omp.utils.ThreadLocalStorage.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.omp.utils.ThreadLocalStorage", new Value.Obj("ti.omp.utils.ThreadLocalStorage", po));
        pkgV.bind("ThreadLocalStorage", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.omp.utils.ThreadLocalStorage$$Module_State", new Proto.Obj());
        om.bind("ti.omp.utils.ThreadLocalStorage.Module_State", new Proto.Str(spo, false));
    }

    void SemaphoreMP$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.omp.utils.SemaphoreMP.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.omp.utils.SemaphoreMP", new Value.Obj("ti.omp.utils.SemaphoreMP", po));
        pkgV.bind("SemaphoreMP", vo);
        // decls 
        om.bind("ti.omp.utils.SemaphoreMP.Mode", new Proto.Enm("ti.omp.utils.SemaphoreMP.Mode"));
        spo = (Proto.Obj)om.bind("ti.omp.utils.SemaphoreMP$$BasicView", new Proto.Obj());
        om.bind("ti.omp.utils.SemaphoreMP.BasicView", new Proto.Str(spo, false));
        spo = (Proto.Obj)om.bind("ti.omp.utils.SemaphoreMP$$Attrs", new Proto.Obj());
        om.bind("ti.omp.utils.SemaphoreMP.Attrs", new Proto.Str(spo, false));
        spo = (Proto.Obj)om.bind("ti.omp.utils.SemaphoreMP$$PendElem", new Proto.Obj());
        om.bind("ti.omp.utils.SemaphoreMP.PendElem", new Proto.Str(spo, false));
        spo = (Proto.Obj)om.bind("ti.omp.utils.SemaphoreMP$$Instance_State", new Proto.Obj());
        om.bind("ti.omp.utils.SemaphoreMP.Instance_State", new Proto.Str(spo, false));
        spo = (Proto.Obj)om.bind("ti.omp.utils.SemaphoreMP$$Module_State", new Proto.Obj());
        om.bind("ti.omp.utils.SemaphoreMP.Module_State", new Proto.Str(spo, false));
        // insts 
        Object insP = om.bind("ti.omp.utils.SemaphoreMP.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.omp.utils.SemaphoreMP$$Object", new Proto.Obj());
        Object objP = om.bind("ti.omp.utils.SemaphoreMP.Object", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.omp.utils.SemaphoreMP$$Params", new Proto.Obj());
        om.bind("ti.omp.utils.SemaphoreMP.Params", new Proto.Str(po, false));
        om.bind("ti.omp.utils.SemaphoreMP.Handle", insP);
        if (isROV) {
            om.bind("ti.omp.utils.SemaphoreMP.Object", om.findStrict("ti.omp.utils.SemaphoreMP.Instance_State", "ti.omp.utils"));
        }//isROV
    }

    void OpenMP$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.omp.utils.OpenMP.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.omp.utils.OpenMP", new Value.Obj("ti.omp.utils.OpenMP", po));
        pkgV.bind("OpenMP", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.omp.utils.OpenMP$$Module_State", new Proto.Obj());
        om.bind("ti.omp.utils.OpenMP.Module_State", new Proto.Str(spo, false));
    }

    void HeapOMP$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.omp.utils.HeapOMP.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.omp.utils.HeapOMP", new Value.Obj("ti.omp.utils.HeapOMP", po));
        pkgV.bind("HeapOMP", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.omp.utils.HeapOMP$$Instance_State", new Proto.Obj());
        om.bind("ti.omp.utils.HeapOMP.Instance_State", new Proto.Str(spo, false));
        // insts 
        Object insP = om.bind("ti.omp.utils.HeapOMP.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.omp.utils.HeapOMP$$Object", new Proto.Obj());
        Object objP = om.bind("ti.omp.utils.HeapOMP.Object", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.omp.utils.HeapOMP$$Params", new Proto.Obj());
        om.bind("ti.omp.utils.HeapOMP.Params", new Proto.Str(po, false));
        om.bind("ti.omp.utils.HeapOMP.Handle", insP);
        if (isROV) {
            om.bind("ti.omp.utils.HeapOMP.Object", om.findStrict("ti.omp.utils.HeapOMP.Instance_State", "ti.omp.utils"));
        }//isROV
    }

    void ThreadLocal$$CONSTS()
    {
        // module ThreadLocal
        om.bind("ti.omp.utils.ThreadLocal.MAXKEYS", 16L);
        om.bind("ti.omp.utils.ThreadLocal.key_create", new Extern("ti_omp_utils_ThreadLocal_key_create__E", "xdc_Int(*)(xdc_UInt*,xdc_Void(*)(xdc_Void*))", true, false));
        om.bind("ti.omp.utils.ThreadLocal.key_delete", new Extern("ti_omp_utils_ThreadLocal_key_delete__E", "xdc_Int(*)(xdc_UInt)", true, false));
        om.bind("ti.omp.utils.ThreadLocal.setspecific", new Extern("ti_omp_utils_ThreadLocal_setspecific__E", "xdc_Int(*)(xdc_UInt,xdc_Void*)", true, false));
        om.bind("ti.omp.utils.ThreadLocal.getspecific", new Extern("ti_omp_utils_ThreadLocal_getspecific__E", "xdc_Void*(*)(xdc_UInt)", true, false));
        om.bind("ti.omp.utils.ThreadLocal.createFxn", new Extern("ti_omp_utils_ThreadLocal_createFxn__E", "xdc_Void(*)(ti_sysbios_knl_Task_Handle,xdc_runtime_Error_Block*)", true, false));
        om.bind("ti.omp.utils.ThreadLocal.exitFxn", new Extern("ti_omp_utils_ThreadLocal_exitFxn__E", "xdc_Void(*)(ti_sysbios_knl_Task_Handle)", true, false));
        om.bind("ti.omp.utils.ThreadLocal.registerFxn", new Extern("ti_omp_utils_ThreadLocal_registerFxn__E", "xdc_Void(*)(xdc_Int)", true, false));
    }

    void ThreadLocalStorage$$CONSTS()
    {
        // module ThreadLocalStorage
        om.bind("ti.omp.utils.ThreadLocalStorage.createFxn", new Extern("ti_omp_utils_ThreadLocalStorage_createFxn__E", "xdc_Void(*)(ti_sysbios_knl_Task_Handle,xdc_runtime_Error_Block*)", true, false));
        om.bind("ti.omp.utils.ThreadLocalStorage.switchFxn", new Extern("ti_omp_utils_ThreadLocalStorage_switchFxn__E", "xdc_Void(*)(ti_sysbios_knl_Task_Handle,ti_sysbios_knl_Task_Handle)", true, false));
        om.bind("ti.omp.utils.ThreadLocalStorage.deleteFxn", new Extern("ti_omp_utils_ThreadLocalStorage_deleteFxn__E", "xdc_Void(*)(ti_sysbios_knl_Task_Handle)", true, false));
        om.bind("ti.omp.utils.ThreadLocalStorage.registerFxn", new Extern("ti_omp_utils_ThreadLocalStorage_registerFxn__E", "xdc_Void(*)(xdc_Int)", true, false));
    }

    void SemaphoreMP$$CONSTS()
    {
        // module SemaphoreMP
        om.bind("ti.omp.utils.SemaphoreMP.Mode_COUNTING", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.omp.utils.SemaphoreMP.Mode", "ti.omp.utils"), "ti.omp.utils.SemaphoreMP.Mode_COUNTING", 0));
        om.bind("ti.omp.utils.SemaphoreMP.Mode_BINARY", xdc.services.intern.xsr.Enum.make((Proto.Enm)om.findStrict("ti.omp.utils.SemaphoreMP.Mode", "ti.omp.utils"), "ti.omp.utils.SemaphoreMP.Mode_BINARY", 1));
        om.bind("ti.omp.utils.SemaphoreMP.CREATED", 0xabcd1234L);
        om.bind("ti.omp.utils.SemaphoreMP.open", new Extern("ti_omp_utils_SemaphoreMP_open__E", "xdc_Int(*)(xdc_String,ti_omp_utils_SemaphoreMP_Handle*)", true, false));
        om.bind("ti.omp.utils.SemaphoreMP.openByAddr", new Extern("ti_omp_utils_SemaphoreMP_openByAddr__E", "xdc_Int(*)(xdc_Ptr,ti_omp_utils_SemaphoreMP_Handle*)", true, false));
        om.bind("ti.omp.utils.SemaphoreMP.close", new Extern("ti_omp_utils_SemaphoreMP_close__E", "xdc_Void(*)(ti_omp_utils_SemaphoreMP_Handle*)", true, false));
        om.bind("ti.omp.utils.SemaphoreMP.sharedMemReq", new Extern("ti_omp_utils_SemaphoreMP_sharedMemReq__E", "xdc_SizeT(*)(ti_omp_utils_SemaphoreMP_Params*)", true, false));
        om.bind("ti.omp.utils.SemaphoreMP.start", new Extern("ti_omp_utils_SemaphoreMP_start__E", "xdc_Void(*)(xdc_Void)", true, false));
        om.bind("ti.omp.utils.SemaphoreMP.cbFxn", new Extern("ti_omp_utils_SemaphoreMP_cbFxn__I", "xdc_Void(*)(xdc_UInt16,xdc_UInt16,xdc_UInt32,xdc_UArg,xdc_UInt32)", true, false));
        om.bind("ti.omp.utils.SemaphoreMP.registerEvent", new Extern("ti_omp_utils_SemaphoreMP_registerEvent__I", "xdc_Int(*)(xdc_UArg,xdc_UInt16)", true, false));
    }

    void OpenMP$$CONSTS()
    {
        // module OpenMP
        om.bind("ti.omp.utils.OpenMP.createThread", new Extern("ti_omp_utils_OpenMP_createThread__E", "xdc_Void(*)(xdc_Fxn,xdc_Ptr,xdc_SizeT)", true, false));
        om.bind("ti.omp.utils.OpenMP.exitThread", new Extern("ti_omp_utils_OpenMP_exitThread__E", "xdc_Void(*)(xdc_Void*)", true, false));
        om.bind("ti.omp.utils.OpenMP.mainTaskExit", new Extern("ti_omp_utils_OpenMP_mainTaskExit__E", "xdc_Void(*)(xdc_Void*)", true, false));
        om.bind("ti.omp.utils.OpenMP.useSharedHeap", new Extern("ti_omp_utils_OpenMP_useSharedHeap__E", "xdc_Bool(*)(xdc_Void)", true, false));
        om.bind("ti.omp.utils.OpenMP.getTimerCount", new Extern("ti_omp_utils_OpenMP_getTimerCount__E", "xdc_UInt32(*)(xdc_Void)", true, false));
        om.bind("ti.omp.utils.OpenMP.getTimerFreq", new Extern("ti_omp_utils_OpenMP_getTimerFreq__E", "xdc_Void(*)(xdc_runtime_Types_FreqHz*)", true, false));
        om.bind("ti.omp.utils.OpenMP.masterTask", new Extern("ti_omp_utils_OpenMP_masterTask__I", "xdc_Void(*)(xdc_UArg,xdc_UArg)", true, false));
        om.bind("ti.omp.utils.OpenMP.threadSpawnLoop", new Extern("ti_omp_utils_OpenMP_threadSpawnLoop__I", "xdc_Void(*)(xdc_Void)", true, false));
        om.bind("ti.omp.utils.OpenMP.mainTask", new Extern("ti_omp_utils_OpenMP_mainTask__I", "xdc_Void(*)(xdc_UArg,xdc_UArg)", true, false));
        om.bind("ti.omp.utils.OpenMP.setProcId", new Extern("ti_omp_utils_OpenMP_setProcId__I", "xdc_Void(*)(xdc_Void)", true, false));
    }

    void HeapOMP$$CONSTS()
    {
        // module HeapOMP
    }

    void ThreadLocal$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void ThreadLocalStorage$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void SemaphoreMP$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        if (isCFG) {
            sb = new StringBuilder();
            sb.append("ti$omp$utils$SemaphoreMP$$__initObject = function( inst ) {\n");
                sb.append("if (!this.$used) {\n");
                    sb.append("throw new Error(\"Function ti.omp.utils.SemaphoreMP.create() called before xdc.useModule('ti.omp.utils.SemaphoreMP')\");\n");
                sb.append("}\n");
                sb.append("var name = xdc.module('xdc.runtime.Text').defineRopeCord(inst.instance.name);\n");
                sb.append("inst.$object.$$bind('__name', name);\n");
                sb.append("this.instance$static$init.$fxn.apply(inst, [inst.$object, inst.$args.count, inst, inst.$module]);\n");
                sb.append("inst.$seal();\n");
            sb.append("};\n");
            Global.eval(sb.toString());
            fxn = (Proto.Fxn)om.bind("ti.omp.utils.SemaphoreMP$$create", new Proto.Fxn(om.findStrict("ti.omp.utils.SemaphoreMP.Module", "ti.omp.utils"), om.findStrict("ti.omp.utils.SemaphoreMP.Instance", "ti.omp.utils"), 2, 1, false));
                        fxn.addArg(0, "count", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF);
                        fxn.addArg(1, "__params", (Proto)om.findStrict("ti.omp.utils.SemaphoreMP.Params", "ti.omp.utils"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$omp$utils$SemaphoreMP$$create = function( count, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.omp.utils.SemaphoreMP'];\n");
                sb.append("var __inst = xdc.om['ti.omp.utils.SemaphoreMP.Instance'].$$make();\n");
                sb.append("__inst.$$bind('$package', xdc.om['ti.omp.utils']);\n");
                sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
                sb.append("__inst.$$bind('$category', 'Instance');\n");
                sb.append("__inst.$$bind('$args', {count:count});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$instances.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', new xdc.om['ti.omp.utils.SemaphoreMP'].Instance_State);\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("var save = xdc.om.$curpkg;\n");
                sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
                sb.append("__mod.instance$meta$init.$fxn.apply(__inst, [count]);\n");
                sb.append("xdc.om.$$bind('$curpkg', save);\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.omp.utils.SemaphoreMP'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return __inst;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
        if (isCFG) {
            fxn = (Proto.Fxn)om.bind("ti.omp.utils.SemaphoreMP$$construct", new Proto.Fxn(om.findStrict("ti.omp.utils.SemaphoreMP.Module", "ti.omp.utils"), null, 3, 1, false));
                        fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.omp.utils.SemaphoreMP$$Object", "ti.omp.utils"), null);
                        fxn.addArg(1, "count", Proto.Elm.newCNum("(xdc_Int)"), $$UNDEF);
                        fxn.addArg(2, "__params", (Proto)om.findStrict("ti.omp.utils.SemaphoreMP.Params", "ti.omp.utils"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$omp$utils$SemaphoreMP$$construct = function( __obj, count, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.omp.utils.SemaphoreMP'];\n");
                sb.append("var __inst = __obj;\n");
                sb.append("__inst.$$bind('$args', {count:count});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$objects.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', xdc.om['ti.omp.utils.SemaphoreMP'].Instance_State.$$make(__inst.$$parent, __inst.$name));\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.omp.utils.SemaphoreMP'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return null;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
    }

    void OpenMP$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void HeapOMP$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        if (isCFG) {
            sb = new StringBuilder();
            sb.append("ti$omp$utils$HeapOMP$$__initObject = function( inst ) {\n");
                sb.append("if (!this.$used) {\n");
                    sb.append("throw new Error(\"Function ti.omp.utils.HeapOMP.create() called before xdc.useModule('ti.omp.utils.HeapOMP')\");\n");
                sb.append("}\n");
                sb.append("var name = xdc.module('xdc.runtime.Text').defineRopeCord(inst.instance.name);\n");
                sb.append("inst.$object.$$bind('__name', name);\n");
                sb.append("this.instance$static$init.$fxn.apply(inst, [inst.$object, inst, inst.$module]);\n");
                sb.append("inst.$seal();\n");
            sb.append("};\n");
            Global.eval(sb.toString());
            fxn = (Proto.Fxn)om.bind("ti.omp.utils.HeapOMP$$create", new Proto.Fxn(om.findStrict("ti.omp.utils.HeapOMP.Module", "ti.omp.utils"), om.findStrict("ti.omp.utils.HeapOMP.Instance", "ti.omp.utils"), 1, 0, false));
                        fxn.addArg(0, "__params", (Proto)om.findStrict("ti.omp.utils.HeapOMP.Params", "ti.omp.utils"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$omp$utils$HeapOMP$$create = function( __params ) {\n");
                sb.append("var __mod = xdc.om['ti.omp.utils.HeapOMP'];\n");
                sb.append("var __inst = xdc.om['ti.omp.utils.HeapOMP.Instance'].$$make();\n");
                sb.append("__inst.$$bind('$package', xdc.om['ti.omp.utils']);\n");
                sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
                sb.append("__inst.$$bind('$category', 'Instance');\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$instances.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', new xdc.om['ti.omp.utils.HeapOMP'].Instance_State);\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("var save = xdc.om.$curpkg;\n");
                sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
                sb.append("__mod.instance$meta$init.$fxn.apply(__inst, []);\n");
                sb.append("xdc.om.$$bind('$curpkg', save);\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.omp.utils.HeapOMP'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return __inst;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
        if (isCFG) {
            fxn = (Proto.Fxn)om.bind("ti.omp.utils.HeapOMP$$construct", new Proto.Fxn(om.findStrict("ti.omp.utils.HeapOMP.Module", "ti.omp.utils"), null, 2, 0, false));
                        fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.omp.utils.HeapOMP$$Object", "ti.omp.utils"), null);
                        fxn.addArg(1, "__params", (Proto)om.findStrict("ti.omp.utils.HeapOMP.Params", "ti.omp.utils"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$omp$utils$HeapOMP$$construct = function( __obj, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.omp.utils.HeapOMP'];\n");
                sb.append("var __inst = __obj;\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$objects.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', xdc.om['ti.omp.utils.HeapOMP'].Instance_State.$$make(__inst.$$parent, __inst.$name));\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.omp.utils.HeapOMP'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return null;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
    }

    void ThreadLocal$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void ThreadLocalStorage$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void SemaphoreMP$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void OpenMP$$FUNCTIONS()
    {
        Proto.Fxn fxn;

        // fxn OpenMP.setNumProcessors
        fxn = (Proto.Fxn)om.bind("ti.omp.utils.OpenMP$$setNumProcessors", new Proto.Fxn(om.findStrict("ti.omp.utils.OpenMP.Module", "ti.omp.utils"), null, 1, 1, false));
                fxn.addArg(0, "numProcessors", Proto.Elm.newCNum("(xdc_UInt16)"), $$UNDEF);
        // fxn OpenMP.setMaxProcessors
        fxn = (Proto.Fxn)om.bind("ti.omp.utils.OpenMP$$setMaxProcessors", new Proto.Fxn(om.findStrict("ti.omp.utils.OpenMP.Module", "ti.omp.utils"), null, 0, 0, false));
    }

    void HeapOMP$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void ThreadLocal$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.omp.utils.ThreadLocal.Module_State", "ti.omp.utils");
        sizes.clear();
        sizes.add(Global.newArray("contextId", "UInt"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.omp.utils.ThreadLocal.Module_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.omp.utils.ThreadLocal.Module_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.omp.utils.ThreadLocal.Module_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void ThreadLocalStorage$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.omp.utils.ThreadLocalStorage.Module_State", "ti.omp.utils");
        sizes.clear();
        sizes.add(Global.newArray("contextId", "UInt"));
        sizes.add(Global.newArray("heapOmpHandle", "UPtr"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.omp.utils.ThreadLocalStorage.Module_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.omp.utils.ThreadLocalStorage.Module_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.omp.utils.ThreadLocalStorage.Module_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void SemaphoreMP$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.omp.utils.SemaphoreMP.Attrs", "ti.omp.utils");
        sizes.clear();
        sizes.add(Global.newArray("status", "UInt32"));
        sizes.add(Global.newArray("gateMPAddr", "UInt32"));
        sizes.add(Global.newArray("count", "UInt16"));
        sizes.add(Global.newArray("mode", "UInt16"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.omp.utils.SemaphoreMP.Attrs']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.omp.utils.SemaphoreMP.Attrs']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.omp.utils.SemaphoreMP.Attrs'], fld); }");
        so.bind("$offsetof", fxn);
        so = (Proto.Str)om.findStrict("ti.omp.utils.SemaphoreMP.PendElem", "ti.omp.utils");
        sizes.clear();
        sizes.add(Global.newArray("elem", "Sti.sdo.ipc.ListMP;Elem"));
        sizes.add(Global.newArray("procId", "UInt16"));
        sizes.add(Global.newArray("task", "UInt32"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.omp.utils.SemaphoreMP.PendElem']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.omp.utils.SemaphoreMP.PendElem']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.omp.utils.SemaphoreMP.PendElem'], fld); }");
        so.bind("$offsetof", fxn);
        so = (Proto.Str)om.findStrict("ti.omp.utils.SemaphoreMP.Instance_State", "ti.omp.utils");
        sizes.clear();
        sizes.add(Global.newArray("attrs", "UPtr"));
        sizes.add(Global.newArray("mode", "Nti.omp.utils.SemaphoreMP.Mode;;;"));
        sizes.add(Global.newArray("gate", "UPtr"));
        sizes.add(Global.newArray("objType", "Nti.sdo.ipc.Ipc.ObjType;;0x1;0x2;0x4;0x8;0x10;0x20"));
        sizes.add(Global.newArray("nsKey", "UPtr"));
        sizes.add(Global.newArray("cacheEnabled", "UShort"));
        sizes.add(Global.newArray("regionId", "UInt16"));
        sizes.add(Global.newArray("allocSize", "USize"));
        sizes.add(Global.newArray("pendQ", "UPtr"));
        sizes.add(Global.newArray("QMSS_sem_Hnd", "UInt32"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.omp.utils.SemaphoreMP.Instance_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.omp.utils.SemaphoreMP.Instance_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.omp.utils.SemaphoreMP.Instance_State'], fld); }");
        so.bind("$offsetof", fxn);
        so = (Proto.Str)om.findStrict("ti.omp.utils.SemaphoreMP.Module_State", "ti.omp.utils");
        sizes.clear();
        sizes.add(Global.newArray("nameServer", "UPtr"));
        sizes.add(Global.newArray("pendElemKey", "UInt"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.omp.utils.SemaphoreMP.Module_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.omp.utils.SemaphoreMP.Module_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.omp.utils.SemaphoreMP.Module_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void OpenMP$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.omp.utils.OpenMP.Module_State", "ti.omp.utils");
        sizes.clear();
        sizes.add(Global.newArray("masterTaskSem", "UPtr"));
        sizes.add(Global.newArray("threadSpawnQ", "UInt32"));
        sizes.add(Global.newArray("useSharedHeap", "UShort"));
        sizes.add(Global.newArray("gate", "UPtr"));
        sizes.add(Global.newArray("sharedTimer", "UPtr"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.omp.utils.OpenMP.Module_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.omp.utils.OpenMP.Module_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.omp.utils.OpenMP.Module_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void HeapOMP$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.omp.utils.HeapOMP.Instance_State", "ti.omp.utils");
        sizes.clear();
        sizes.add(Global.newArray("__fxns", "UPtr"));
        sizes.add(Global.newArray("sharedRegionId", "TInt16"));
        sizes.add(Global.newArray("localHeap", "UPtr"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.omp.utils.HeapOMP.Instance_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.omp.utils.HeapOMP.Instance_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.omp.utils.HeapOMP.Instance_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void ThreadLocal$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/utils/ThreadLocal.xs");
        om.bind("ti.omp.utils.ThreadLocal$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocal.Module", "ti.omp.utils");
        po.init("ti.omp.utils.ThreadLocal.Module", om.findStrict("xdc.runtime.IModule.Module", "ti.omp.utils"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("MAXKEYS", Proto.Elm.newCNum("(xdc_Int)"), 16L, "rh");
        if (isCFG) {
            po.addFld("rovViewInfo", (Proto)om.findStrict("xdc.rov.ViewInfo.Instance", "ti.omp.utils"), $$UNDEF, "wh");
            po.addFld("A_invalidKey", (Proto)om.findStrict("xdc.runtime.Assert$$Id", "ti.omp.utils"), Global.newObject("msg", "A_invalidKey: Invalid key encountered"), "w");
            po.addFld("A_invalidContext", (Proto)om.findStrict("xdc.runtime.Assert$$Id", "ti.omp.utils"), Global.newObject("msg", "A_invalidContext: Must be called from Task context"), "w");
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.omp.utils.ThreadLocal$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.omp.utils.ThreadLocal$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.omp.utils.ThreadLocal$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.omp.utils.ThreadLocal$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        // struct ThreadLocal.KeyValueView
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocal$$KeyValueView", "ti.omp.utils");
        po.init("ti.omp.utils.ThreadLocal.KeyValueView", null);
                po.addFld("$hostonly", $$T_Num, 1, "r");
                po.addFld("key", Proto.Elm.newCNum("(xdc_UInt)"), $$UNDEF, "w");
                po.addFld("value", new Proto.Adr("xdc_UArg", "Pv"), $$UNDEF, "w");
        // typedef ThreadLocal.Key
        om.bind("ti.omp.utils.ThreadLocal.Key", Proto.Elm.newCNum("(xdc_UInt)"));
        // typedef ThreadLocal.DestructFxn
        om.bind("ti.omp.utils.ThreadLocal.DestructFxn", new Proto.Adr("xdc_Void(*)(xdc_Void*)", "PFv"));
        // struct ThreadLocal.Module_State
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocal$$Module_State", "ti.omp.utils");
        po.init("ti.omp.utils.ThreadLocal.Module_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("contextId", Proto.Elm.newCNum("(xdc_UInt)"), $$UNDEF, "w");
    }

    void ThreadLocalStorage$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/utils/ThreadLocalStorage.xs");
        om.bind("ti.omp.utils.ThreadLocalStorage$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocalStorage.Module", "ti.omp.utils");
        po.init("ti.omp.utils.ThreadLocalStorage.Module", om.findStrict("xdc.runtime.IModule.Module", "ti.omp.utils"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("heapOmpHandle", (Proto)om.findStrict("xdc.runtime.IHeap.Handle", "ti.omp.utils"), null, "w");
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.omp.utils.ThreadLocalStorage$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.omp.utils.ThreadLocalStorage$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.omp.utils.ThreadLocalStorage$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.omp.utils.ThreadLocalStorage$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        // struct ThreadLocalStorage.Module_State
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocalStorage$$Module_State", "ti.omp.utils");
        po.init("ti.omp.utils.ThreadLocalStorage.Module_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("contextId", Proto.Elm.newCNum("(xdc_UInt)"), $$UNDEF, "w");
                po.addFld("heapOmpHandle", (Proto)om.findStrict("xdc.runtime.IHeap.Handle", "ti.omp.utils"), $$UNDEF, "w");
    }

    void SemaphoreMP$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/utils/SemaphoreMP.xs");
        om.bind("ti.omp.utils.SemaphoreMP$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP.Module", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.Module", om.findStrict("xdc.runtime.IModule.Module", "ti.omp.utils"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("CREATED", Proto.Elm.newCNum("(xdc_UInt32)"), 0xabcd1234L, "rh");
        if (isCFG) {
            po.addFld("rovViewInfo", (Proto)om.findStrict("xdc.rov.ViewInfo.Instance", "ti.omp.utils"), $$UNDEF, "wh");
            po.addFld("A_invTimeout", (Proto)om.findStrict("xdc.runtime.Assert$$Id", "ti.omp.utils"), Global.newObject("msg", "A_invTimeout: Can't use BIOS_EVENT_ACQUIRED with this Semaphore."), "w");
            po.addFld("A_badContext", (Proto)om.findStrict("xdc.runtime.Assert$$Id", "ti.omp.utils"), Global.newObject("msg", "A_badContext: bad calling context. Must be called from a Task."), "w");
            po.addFld("notifyEventId", Proto.Elm.newCNum("(xdc_UInt)"), 6L, "w");
            po.addFld("maxRuntimeEntries", Proto.Elm.newCNum("(xdc_UInt)"), (Global.eval("~0")), "wh");
            po.addFld("maxNameLen", Proto.Elm.newCNum("(xdc_UInt)"), 32L, "wh");
            po.addFld("tableSection", $$T_Str, null, "wh");
            po.addFld("nameSrvPrms", (Proto)om.findStrict("ti.sdo.utils.NameServer.Params", "ti.omp.utils"), $$DEFAULT, "wh");
        }//isCFG
        if (isCFG) {
                        po.addFxn("create", (Proto.Fxn)om.findStrict("ti.omp.utils.SemaphoreMP$$create", "ti.omp.utils"), Global.get("ti$omp$utils$SemaphoreMP$$create"));
                        po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.omp.utils.SemaphoreMP$$construct", "ti.omp.utils"), Global.get("ti$omp$utils$SemaphoreMP$$construct"));
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.omp.utils.SemaphoreMP$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.omp.utils.SemaphoreMP$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("ti.omp.utils.SemaphoreMP$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.omp.utils.SemaphoreMP$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.omp.utils.SemaphoreMP$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$static$init");
        if (fxn != null) om.bind("ti.omp.utils.SemaphoreMP$$instance$static$init", true);
        if (fxn != null) po.addFxn("instance$static$init", $$T_Met, fxn);
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP.Instance", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.Instance", $$Instance);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("CREATED", Proto.Elm.newCNum("(xdc_UInt32)"), 0xabcd1234L, "rh");
        if (isCFG) {
            po.addFld("mode", (Proto)om.findStrict("ti.omp.utils.SemaphoreMP.Mode", "ti.omp.utils"), om.find("ti.omp.utils.SemaphoreMP.Mode_COUNTING"), "w");
            po.addFld("gate", (Proto)om.findStrict("ti.sdo.ipc.GateMP.Handle", "ti.omp.utils"), null, "w");
            po.addFld("openFlag", $$T_Bool, false, "w");
            po.addFld("sharedAddr", new Proto.Adr("xdc_Ptr", "Pv"), null, "w");
            po.addFld("name", $$T_Str, null, "w");
            po.addFld("regionId", Proto.Elm.newCNum("(xdc_UInt16)"), 0L, "w");
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.omp.utils"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$Params", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.Params", $$Params);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("CREATED", Proto.Elm.newCNum("(xdc_UInt32)"), 0xabcd1234L, "rh");
        if (isCFG) {
            po.addFld("mode", (Proto)om.findStrict("ti.omp.utils.SemaphoreMP.Mode", "ti.omp.utils"), om.find("ti.omp.utils.SemaphoreMP.Mode_COUNTING"), "w");
            po.addFld("gate", (Proto)om.findStrict("ti.sdo.ipc.GateMP.Handle", "ti.omp.utils"), null, "w");
            po.addFld("openFlag", $$T_Bool, false, "w");
            po.addFld("sharedAddr", new Proto.Adr("xdc_Ptr", "Pv"), null, "w");
            po.addFld("name", $$T_Str, null, "w");
            po.addFld("regionId", Proto.Elm.newCNum("(xdc_UInt16)"), 0L, "w");
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.omp.utils"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$Object", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.Object", om.findStrict("ti.omp.utils.SemaphoreMP.Instance", "ti.omp.utils"));
        // struct SemaphoreMP.BasicView
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$BasicView", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.BasicView", null);
                po.addFld("$hostonly", $$T_Num, 1, "r");
                po.addFld("name", $$T_Str, $$UNDEF, "w");
                po.addFld("objType", $$T_Str, $$UNDEF, "w");
                po.addFld("gate", new Proto.Adr("xdc_Ptr", "Pv"), $$UNDEF, "w");
                po.addFld("mode", $$T_Str, $$UNDEF, "w");
                po.addFld("count", Proto.Elm.newCNum("(xdc_UInt)"), $$UNDEF, "w");
                po.addFld("pendedTasks", new Proto.Arr($$T_Str, false), $$DEFAULT, "w");
        // struct SemaphoreMP.Attrs
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$Attrs", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.Attrs", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("status", Proto.Elm.newCNum("(xdc_Bits32)"), $$UNDEF, "w");
                po.addFld("gateMPAddr", Proto.Elm.newCNum("(xdc_Bits32)"), $$UNDEF, "w");
                po.addFld("count", Proto.Elm.newCNum("(xdc_Bits16)"), $$UNDEF, "w");
                po.addFld("mode", Proto.Elm.newCNum("(xdc_Bits16)"), $$UNDEF, "w");
        // struct SemaphoreMP.PendElem
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$PendElem", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.PendElem", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("elem", (Proto)om.findStrict("ti.sdo.ipc.ListMP.Elem", "ti.omp.utils"), $$DEFAULT, "w");
                po.addFld("procId", Proto.Elm.newCNum("(xdc_Bits16)"), $$UNDEF, "w");
                po.addFld("task", Proto.Elm.newCNum("(xdc_Bits32)"), $$UNDEF, "w");
        // struct SemaphoreMP.Instance_State
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$Instance_State", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.Instance_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("attrs", new Proto.Adr("ti_omp_utils_SemaphoreMP_Attrs*", "PS"), $$UNDEF, "w");
                po.addFld("mode", (Proto)om.findStrict("ti.omp.utils.SemaphoreMP.Mode", "ti.omp.utils"), $$UNDEF, "w");
                po.addFld("gate", (Proto)om.findStrict("ti.sdo.ipc.GateMP.Handle", "ti.omp.utils"), $$UNDEF, "w");
                po.addFld("objType", (Proto)om.findStrict("ti.sdo.ipc.Ipc.ObjType", "ti.omp.utils"), $$UNDEF, "w");
                po.addFld("nsKey", new Proto.Adr("xdc_Ptr", "Pv"), $$UNDEF, "w");
                po.addFld("cacheEnabled", $$T_Bool, $$UNDEF, "w");
                po.addFld("regionId", Proto.Elm.newCNum("(xdc_UInt16)"), $$UNDEF, "w");
                po.addFld("allocSize", Proto.Elm.newCNum("(xdc_SizeT)"), $$UNDEF, "w");
                po.addFld("pendQ", (Proto)om.findStrict("ti.sdo.ipc.ListMP.Handle", "ti.omp.utils"), $$UNDEF, "w");
                po.addFld("QMSS_sem_Hnd", Proto.Elm.newCNum("(xdc_UInt32)"), $$UNDEF, "w");
        // struct SemaphoreMP.Module_State
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$Module_State", "ti.omp.utils");
        po.init("ti.omp.utils.SemaphoreMP.Module_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("nameServer", (Proto)om.findStrict("ti.sdo.utils.NameServer.Handle", "ti.omp.utils"), $$UNDEF, "w");
                po.addFld("pendElemKey", Proto.Elm.newCNum("(xdc_UInt)"), $$UNDEF, "w");
    }

    void OpenMP$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/utils/OpenMP.xs");
        om.bind("ti.omp.utils.OpenMP$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.omp.utils.OpenMP.Module", "ti.omp.utils");
        po.init("ti.omp.utils.OpenMP.Module", om.findStrict("xdc.runtime.IModule.Module", "ti.omp.utils"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("masterFxn", new Proto.Adr("xdc_Void(*)(xdc_Void)", "PFv"), "&main", "w");
            po.addFld("singleThreadPerCore", $$T_Bool, true, "w");
            po.addFld("qmssInit", $$T_Bool, true, "w");
            po.addFld("qmssMemRegion", Proto.Elm.newCNum("(xdc_Int32)"), Global.eval("-1"), "w");
            po.addFld("qmssStartIndex", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("qmssDestQueueNum", Proto.Elm.newCNum("(xdc_Int32)"), Global.eval("-1"), "w");
            po.addFld("stackSize", Proto.Elm.newCNum("(xdc_SizeT)"), 8192L, "w");
            po.addFld("ipcHeapSize", Proto.Elm.newCNum("(xdc_SizeT)"), 0x80000L, "w");
            po.addFld("stackRegionId", Proto.Elm.newCNum("(xdc_Int)"), 0L, "w");
            po.addFld("internalOsal", $$T_Bool, true, "w");
            po.addFld("cppiHwSem", Proto.Elm.newCNum("(xdc_UInt)"), 3L, "w");
            po.addFld("qmssHwSem", Proto.Elm.newCNum("(xdc_UInt)"), 4L, "w");
            po.addFld("ompHwSem", Proto.Elm.newCNum("(xdc_UInt)"), 5L, "w");
            po.addFld("mpaxIndex", Proto.Elm.newCNum("(xdc_UInt)"), 3L, "w");
            po.addFld("mpaxRaddr", Proto.Elm.newCNum("(xdc_UInt32)"), 0x0C000000L, "w");
            po.addFld("autoDnldCore", $$T_Bool, true, "w");
            po.addFld("threadPriority", Proto.Elm.newCNum("(xdc_Int)"), 1L, "w");
            po.addFld("noncachedMsmcAlias", Proto.Elm.newCNum("(xdc_UInt32)"), 0xa0000000L, "w");
            po.addFld("baseIdOfCluster", Proto.Elm.newCNum("(xdc_UInt)"), 0L, "w");
            po.addFld("enableMemoryConsistency", $$T_Bool, true, "w");
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.omp.utils.OpenMP$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.omp.utils.OpenMP$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.omp.utils.OpenMP$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.omp.utils.OpenMP$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
                po.addFxn("setNumProcessors", (Proto.Fxn)om.findStrict("ti.omp.utils.OpenMP$$setNumProcessors", "ti.omp.utils"), Global.get(cap, "setNumProcessors"));
                po.addFxn("setMaxProcessors", (Proto.Fxn)om.findStrict("ti.omp.utils.OpenMP$$setMaxProcessors", "ti.omp.utils"), Global.get(cap, "setMaxProcessors"));
        // typedef OpenMP.FuncPtr
        om.bind("ti.omp.utils.OpenMP.FuncPtr", new Proto.Adr("xdc_Void(*)(xdc_Void)", "PFv"));
        // struct OpenMP.Module_State
        po = (Proto.Obj)om.findStrict("ti.omp.utils.OpenMP$$Module_State", "ti.omp.utils");
        po.init("ti.omp.utils.OpenMP.Module_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("masterTaskSem", (Proto)om.findStrict("ti.omp.utils.SemaphoreMP.Handle", "ti.omp.utils"), $$UNDEF, "w");
                po.addFld("threadSpawnQ", Proto.Elm.newCNum("(xdc_UInt32)"), $$UNDEF, "w");
                po.addFld("useSharedHeap", $$T_Bool, $$UNDEF, "w");
                po.addFld("gate", (Proto)om.findStrict("ti.sdo.ipc.GateMP.Handle", "ti.omp.utils"), $$UNDEF, "w");
                po.addFld("sharedTimer", (Proto)om.findStrict("ti.sysbios.timers.timer64.Timer.Handle", "ti.omp.utils"), $$UNDEF, "w");
    }

    void HeapOMP$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/utils/HeapOMP.xs");
        om.bind("ti.omp.utils.HeapOMP$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.omp.utils.HeapOMP.Module", "ti.omp.utils");
        po.init("ti.omp.utils.HeapOMP.Module", om.findStrict("xdc.runtime.IHeap.Module", "ti.omp.utils"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("localHeapSize", Proto.Elm.newCNum("(xdc_SizeT)"), 0L, "w");
            po.addFld("sharedHeapSize", Proto.Elm.newCNum("(xdc_SizeT)"), 0L, "w");
            po.addFld("sharedRegionId", Proto.Elm.newCNum("(xdc_Int16)"), 0xFFFFL, "w");
        }//isCFG
        if (isCFG) {
                        po.addFxn("create", (Proto.Fxn)om.findStrict("ti.omp.utils.HeapOMP$$create", "ti.omp.utils"), Global.get("ti$omp$utils$HeapOMP$$create"));
                        po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.omp.utils.HeapOMP$$construct", "ti.omp.utils"), Global.get("ti$omp$utils$HeapOMP$$construct"));
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.omp.utils.HeapOMP$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.omp.utils.HeapOMP$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("ti.omp.utils.HeapOMP$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.omp.utils.HeapOMP$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.omp.utils.HeapOMP$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$static$init");
        if (fxn != null) om.bind("ti.omp.utils.HeapOMP$$instance$static$init", true);
        if (fxn != null) po.addFxn("instance$static$init", $$T_Met, fxn);
        po = (Proto.Obj)om.findStrict("ti.omp.utils.HeapOMP.Instance", "ti.omp.utils");
        po.init("ti.omp.utils.HeapOMP.Instance", om.findStrict("xdc.runtime.IHeap.Instance", "ti.omp.utils"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("sRegionId", Proto.Elm.newCNum("(xdc_Int16)"), 0xFFFFL, "w");
            po.addFld("localHeap", (Proto)om.findStrict("xdc.runtime.IHeap.Handle", "ti.omp.utils"), null, "w");
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.omp.utils"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.omp.utils.HeapOMP$$Params", "ti.omp.utils");
        po.init("ti.omp.utils.HeapOMP.Params", om.findStrict("xdc.runtime.IHeap$$Params", "ti.omp.utils"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("sRegionId", Proto.Elm.newCNum("(xdc_Int16)"), 0xFFFFL, "w");
            po.addFld("localHeap", (Proto)om.findStrict("xdc.runtime.IHeap.Handle", "ti.omp.utils"), null, "w");
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.omp.utils"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.omp.utils.HeapOMP$$Object", "ti.omp.utils");
        po.init("ti.omp.utils.HeapOMP.Object", om.findStrict("ti.omp.utils.HeapOMP.Instance", "ti.omp.utils"));
        // struct HeapOMP.Instance_State
        po = (Proto.Obj)om.findStrict("ti.omp.utils.HeapOMP$$Instance_State", "ti.omp.utils");
        po.init("ti.omp.utils.HeapOMP.Instance_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("sharedRegionId", Proto.Elm.newCNum("(xdc_Int16)"), $$UNDEF, "w");
                po.addFld("localHeap", (Proto)om.findStrict("xdc.runtime.IHeap.Handle", "ti.omp.utils"), $$UNDEF, "w");
    }

    void ThreadLocal$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.ThreadLocal", "ti.omp.utils");
        vo.bind("Module_State$fetchDesc", Global.newObject("type", "ti.omp.utils.ThreadLocal.Module_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocal$$Module_State", "ti.omp.utils");
    }

    void ThreadLocalStorage$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.ThreadLocalStorage", "ti.omp.utils");
        vo.bind("Module_State$fetchDesc", Global.newObject("type", "ti.omp.utils.ThreadLocalStorage.Module_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocalStorage$$Module_State", "ti.omp.utils");
    }

    void SemaphoreMP$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.SemaphoreMP", "ti.omp.utils");
        vo.bind("Attrs$fetchDesc", Global.newObject("type", "ti.omp.utils.SemaphoreMP.Attrs", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$Attrs", "ti.omp.utils");
        vo.bind("PendElem$fetchDesc", Global.newObject("type", "ti.omp.utils.SemaphoreMP.PendElem", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$PendElem", "ti.omp.utils");
        vo.bind("Instance_State$fetchDesc", Global.newObject("type", "ti.omp.utils.SemaphoreMP.Instance_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$Instance_State", "ti.omp.utils");
        po.bind("attrs$fetchDesc", Global.newObject("type", "ti.omp.utils.SemaphoreMP.Attrs", "isScalar", false));
        vo.bind("Module_State$fetchDesc", Global.newObject("type", "ti.omp.utils.SemaphoreMP.Module_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP$$Module_State", "ti.omp.utils");
    }

    void OpenMP$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.OpenMP", "ti.omp.utils");
        vo.bind("Module_State$fetchDesc", Global.newObject("type", "ti.omp.utils.OpenMP.Module_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.omp.utils.OpenMP$$Module_State", "ti.omp.utils");
    }

    void HeapOMP$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.HeapOMP", "ti.omp.utils");
        po = (Proto.Obj)om.findStrict("ti.omp.utils.HeapOMP$$Instance_State", "ti.omp.utils");
        po.addFld("__fxns", new Proto.Adr("xdc_Ptr", "Pv"), $$UNDEF, "w");
        vo.bind("Instance_State$fetchDesc", Global.newObject("type", "ti.omp.utils.HeapOMP.Instance_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.omp.utils.HeapOMP$$Instance_State", "ti.omp.utils");
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.omp.utils.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.omp.utils"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/utils/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.omp.utils"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.omp.utils"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.omp.utils"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.omp.utils"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.omp.utils"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.omp.utils"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.omp.utils", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.omp.utils");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.omp.utils.");
        pkgV.bind("$vers", Global.newArray("2, 0, 0, 0"));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        imports.add(Global.newArray("ti.omp", Global.newArray()));
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.omp.utils'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/release/ti.omp.utils.ae66',\n");
            sb.append("'lib/debug/ti.omp.utils.ae66',\n");
            sb.append("'lib/release/ti.omp.utils.C6678.ae66',\n");
            sb.append("'lib/release/ti.omp.utils.C6670.ae66',\n");
            sb.append("'lib/debug/ti.omp.utils.C6678.ae66',\n");
            sb.append("'lib/debug/ti.omp.utils.C6670.ae66',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/release/ti.omp.utils.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/debug/ti.omp.utils.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/release/ti.omp.utils.C6678.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/release/ti.omp.utils.C6670.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/debug/ti.omp.utils.C6678.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/debug/ti.omp.utils.C6670.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void ThreadLocal$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.ThreadLocal", "ti.omp.utils");
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocal.Module", "ti.omp.utils");
        vo.init2(po, "ti.omp.utils.ThreadLocal", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.omp.utils.ThreadLocal$$capsule", "ti.omp.utils"));
        vo.bind("$package", om.findStrict("ti.omp.utils", "ti.omp.utils"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        vo.bind("KeyValueView", om.findStrict("ti.omp.utils.ThreadLocal.KeyValueView", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.ThreadLocal.KeyValueView", "ti.omp.utils"));
        mcfgs.add("A_invalidKey");
        mcfgs.add("A_invalidContext");
        vo.bind("Key", om.findStrict("ti.omp.utils.ThreadLocal.Key", "ti.omp.utils"));
        vo.bind("DestructFxn", om.findStrict("ti.omp.utils.ThreadLocal.DestructFxn", "ti.omp.utils"));
        vo.bind("Module_State", om.findStrict("ti.omp.utils.ThreadLocal.Module_State", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.ThreadLocal.Module_State", "ti.omp.utils"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.omp.utils")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 0);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", 1);
        }//isCFG
        vo.bind("key_create", om.findStrict("ti.omp.utils.ThreadLocal.key_create", "ti.omp.utils"));
        vo.bind("key_delete", om.findStrict("ti.omp.utils.ThreadLocal.key_delete", "ti.omp.utils"));
        vo.bind("setspecific", om.findStrict("ti.omp.utils.ThreadLocal.setspecific", "ti.omp.utils"));
        vo.bind("getspecific", om.findStrict("ti.omp.utils.ThreadLocal.getspecific", "ti.omp.utils"));
        vo.bind("createFxn", om.findStrict("ti.omp.utils.ThreadLocal.createFxn", "ti.omp.utils"));
        vo.bind("exitFxn", om.findStrict("ti.omp.utils.ThreadLocal.exitFxn", "ti.omp.utils"));
        vo.bind("registerFxn", om.findStrict("ti.omp.utils.ThreadLocal.registerFxn", "ti.omp.utils"));
        vo.bind("$$fxntab", Global.newArray("ti_omp_utils_ThreadLocal_Module__startupDone__E", "ti_omp_utils_ThreadLocal_key_create__E", "ti_omp_utils_ThreadLocal_key_delete__E", "ti_omp_utils_ThreadLocal_setspecific__E", "ti_omp_utils_ThreadLocal_getspecific__E", "ti_omp_utils_ThreadLocal_createFxn__E", "ti_omp_utils_ThreadLocal_exitFxn__E", "ti_omp_utils_ThreadLocal_registerFxn__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray("A_invalidKey", "A_invalidContext"));
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "createFxn", "entry", "%p, %p", "exit", ""));
        loggables.add(Global.newObject("name", "exitFxn", "entry", "%p", "exit", ""));
        loggables.add(Global.newObject("name", "registerFxn", "entry", "%d", "exit", ""));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("ThreadLocal", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("ThreadLocal");
    }

    void ThreadLocalStorage$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.ThreadLocalStorage", "ti.omp.utils");
        po = (Proto.Obj)om.findStrict("ti.omp.utils.ThreadLocalStorage.Module", "ti.omp.utils");
        vo.init2(po, "ti.omp.utils.ThreadLocalStorage", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.omp.utils.ThreadLocalStorage$$capsule", "ti.omp.utils"));
        vo.bind("$package", om.findStrict("ti.omp.utils", "ti.omp.utils"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        mcfgs.add("heapOmpHandle");
        vo.bind("Module_State", om.findStrict("ti.omp.utils.ThreadLocalStorage.Module_State", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.ThreadLocalStorage.Module_State", "ti.omp.utils"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.omp.utils")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 0);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", 1);
        }//isCFG
        vo.bind("createFxn", om.findStrict("ti.omp.utils.ThreadLocalStorage.createFxn", "ti.omp.utils"));
        vo.bind("switchFxn", om.findStrict("ti.omp.utils.ThreadLocalStorage.switchFxn", "ti.omp.utils"));
        vo.bind("deleteFxn", om.findStrict("ti.omp.utils.ThreadLocalStorage.deleteFxn", "ti.omp.utils"));
        vo.bind("registerFxn", om.findStrict("ti.omp.utils.ThreadLocalStorage.registerFxn", "ti.omp.utils"));
        vo.bind("$$fxntab", Global.newArray("ti_omp_utils_ThreadLocalStorage_Module__startupDone__E", "ti_omp_utils_ThreadLocalStorage_createFxn__E", "ti_omp_utils_ThreadLocalStorage_switchFxn__E", "ti_omp_utils_ThreadLocalStorage_deleteFxn__E", "ti_omp_utils_ThreadLocalStorage_registerFxn__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "createFxn", "entry", "%p, %p", "exit", ""));
        loggables.add(Global.newObject("name", "switchFxn", "entry", "%p, %p", "exit", ""));
        loggables.add(Global.newObject("name", "deleteFxn", "entry", "%p", "exit", ""));
        loggables.add(Global.newObject("name", "registerFxn", "entry", "%d", "exit", ""));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("ThreadLocalStorage", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("ThreadLocalStorage");
    }

    void SemaphoreMP$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.SemaphoreMP", "ti.omp.utils");
        po = (Proto.Obj)om.findStrict("ti.omp.utils.SemaphoreMP.Module", "ti.omp.utils");
        vo.init2(po, "ti.omp.utils.SemaphoreMP", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.omp.utils.SemaphoreMP$$capsule", "ti.omp.utils"));
        vo.bind("Instance", om.findStrict("ti.omp.utils.SemaphoreMP.Instance", "ti.omp.utils"));
        vo.bind("Params", om.findStrict("ti.omp.utils.SemaphoreMP.Params", "ti.omp.utils"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.omp.utils.SemaphoreMP.Params", "ti.omp.utils")).newInstance());
        vo.bind("Handle", om.findStrict("ti.omp.utils.SemaphoreMP.Handle", "ti.omp.utils"));
        vo.bind("$package", om.findStrict("ti.omp.utils", "ti.omp.utils"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        vo.bind("Mode", om.findStrict("ti.omp.utils.SemaphoreMP.Mode", "ti.omp.utils"));
        vo.bind("BasicView", om.findStrict("ti.omp.utils.SemaphoreMP.BasicView", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.SemaphoreMP.BasicView", "ti.omp.utils"));
        mcfgs.add("A_invTimeout");
        mcfgs.add("A_badContext");
        mcfgs.add("notifyEventId");
        icfgs.add("nameSrvPrms");
        vo.bind("Attrs", om.findStrict("ti.omp.utils.SemaphoreMP.Attrs", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.SemaphoreMP.Attrs", "ti.omp.utils"));
        vo.bind("PendElem", om.findStrict("ti.omp.utils.SemaphoreMP.PendElem", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.SemaphoreMP.PendElem", "ti.omp.utils"));
        vo.bind("Instance_State", om.findStrict("ti.omp.utils.SemaphoreMP.Instance_State", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.SemaphoreMP.Instance_State", "ti.omp.utils"));
        vo.bind("Module_State", om.findStrict("ti.omp.utils.SemaphoreMP.Module_State", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.SemaphoreMP.Module_State", "ti.omp.utils"));
        vo.bind("Mode_COUNTING", om.findStrict("ti.omp.utils.SemaphoreMP.Mode_COUNTING", "ti.omp.utils"));
        vo.bind("Mode_BINARY", om.findStrict("ti.omp.utils.SemaphoreMP.Mode_BINARY", "ti.omp.utils"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.omp.utils")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", om.has("ti.omp.utils.SemaphoreMP$$instance$static$init", null) ? 1 : 0);
            vo.bind("__initObject", Global.get("ti$omp$utils$SemaphoreMP$$__initObject"));
        }//isCFG
        vo.bind("open", om.findStrict("ti.omp.utils.SemaphoreMP.open", "ti.omp.utils"));
        vo.bind("openByAddr", om.findStrict("ti.omp.utils.SemaphoreMP.openByAddr", "ti.omp.utils"));
        vo.bind("close", om.findStrict("ti.omp.utils.SemaphoreMP.close", "ti.omp.utils"));
        vo.bind("sharedMemReq", om.findStrict("ti.omp.utils.SemaphoreMP.sharedMemReq", "ti.omp.utils"));
        vo.bind("start", om.findStrict("ti.omp.utils.SemaphoreMP.start", "ti.omp.utils"));
        vo.bind("cbFxn", om.findStrict("ti.omp.utils.SemaphoreMP.cbFxn", "ti.omp.utils"));
        vo.bind("registerEvent", om.findStrict("ti.omp.utils.SemaphoreMP.registerEvent", "ti.omp.utils"));
        vo.bind("$$fxntab", Global.newArray("ti_omp_utils_SemaphoreMP_Handle__label__E", "ti_omp_utils_SemaphoreMP_Module__startupDone__E", "ti_omp_utils_SemaphoreMP_Object__create__E", "ti_omp_utils_SemaphoreMP_Object__delete__E", "ti_omp_utils_SemaphoreMP_Object__destruct__E", "ti_omp_utils_SemaphoreMP_Object__get__E", "ti_omp_utils_SemaphoreMP_Object__first__E", "ti_omp_utils_SemaphoreMP_Object__next__E", "ti_omp_utils_SemaphoreMP_Params__init__E", "ti_omp_utils_SemaphoreMP_open__E", "ti_omp_utils_SemaphoreMP_openByAddr__E", "ti_omp_utils_SemaphoreMP_close__E", "ti_omp_utils_SemaphoreMP_sharedMemReq__E", "ti_omp_utils_SemaphoreMP_start__E", "ti_omp_utils_SemaphoreMP_getCount__E", "ti_omp_utils_SemaphoreMP_pend__E", "ti_omp_utils_SemaphoreMP_post__E", "ti_omp_utils_SemaphoreMP_reset__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray("A_invTimeout", "A_badContext"));
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.setElem("", true);
        atmap.setElem("", true);
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.omp.utils.SemaphoreMP.Object", "ti.omp.utils"));
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "open", "entry", "\"%s\", %p", "exit", "%d"));
        loggables.add(Global.newObject("name", "openByAddr", "entry", "%p, %p", "exit", "%d"));
        loggables.add(Global.newObject("name", "close", "entry", "%p", "exit", ""));
        loggables.add(Global.newObject("name", "sharedMemReq", "entry", "%p", "exit", "0x%x"));
        loggables.add(Global.newObject("name", "start", "entry", "", "exit", ""));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("SemaphoreMP", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("SemaphoreMP");
    }

    void OpenMP$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.OpenMP", "ti.omp.utils");
        po = (Proto.Obj)om.findStrict("ti.omp.utils.OpenMP.Module", "ti.omp.utils");
        vo.init2(po, "ti.omp.utils.OpenMP", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.omp.utils.OpenMP$$capsule", "ti.omp.utils"));
        vo.bind("$package", om.findStrict("ti.omp.utils", "ti.omp.utils"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        vo.bind("FuncPtr", om.findStrict("ti.omp.utils.OpenMP.FuncPtr", "ti.omp.utils"));
        mcfgs.add("masterFxn");
        mcfgs.add("singleThreadPerCore");
        mcfgs.add("qmssInit");
        mcfgs.add("qmssMemRegion");
        mcfgs.add("qmssStartIndex");
        mcfgs.add("qmssDestQueueNum");
        mcfgs.add("stackSize");
        mcfgs.add("ipcHeapSize");
        mcfgs.add("stackRegionId");
        mcfgs.add("internalOsal");
        mcfgs.add("cppiHwSem");
        mcfgs.add("qmssHwSem");
        mcfgs.add("ompHwSem");
        mcfgs.add("mpaxIndex");
        mcfgs.add("mpaxRaddr");
        mcfgs.add("autoDnldCore");
        mcfgs.add("threadPriority");
        mcfgs.add("noncachedMsmcAlias");
        mcfgs.add("baseIdOfCluster");
        mcfgs.add("enableMemoryConsistency");
        vo.bind("Module_State", om.findStrict("ti.omp.utils.OpenMP.Module_State", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.OpenMP.Module_State", "ti.omp.utils"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.omp.utils")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 0);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", 1);
        }//isCFG
        vo.bind("createThread", om.findStrict("ti.omp.utils.OpenMP.createThread", "ti.omp.utils"));
        vo.bind("exitThread", om.findStrict("ti.omp.utils.OpenMP.exitThread", "ti.omp.utils"));
        vo.bind("mainTaskExit", om.findStrict("ti.omp.utils.OpenMP.mainTaskExit", "ti.omp.utils"));
        vo.bind("useSharedHeap", om.findStrict("ti.omp.utils.OpenMP.useSharedHeap", "ti.omp.utils"));
        vo.bind("getTimerCount", om.findStrict("ti.omp.utils.OpenMP.getTimerCount", "ti.omp.utils"));
        vo.bind("getTimerFreq", om.findStrict("ti.omp.utils.OpenMP.getTimerFreq", "ti.omp.utils"));
        vo.bind("masterTask", om.findStrict("ti.omp.utils.OpenMP.masterTask", "ti.omp.utils"));
        vo.bind("threadSpawnLoop", om.findStrict("ti.omp.utils.OpenMP.threadSpawnLoop", "ti.omp.utils"));
        vo.bind("mainTask", om.findStrict("ti.omp.utils.OpenMP.mainTask", "ti.omp.utils"));
        vo.bind("setProcId", om.findStrict("ti.omp.utils.OpenMP.setProcId", "ti.omp.utils"));
        vo.bind("$$fxntab", Global.newArray("ti_omp_utils_OpenMP_Module__startupDone__E", "ti_omp_utils_OpenMP_createThread__E", "ti_omp_utils_OpenMP_exitThread__E", "ti_omp_utils_OpenMP_mainTaskExit__E", "ti_omp_utils_OpenMP_useSharedHeap__E", "ti_omp_utils_OpenMP_getTimerCount__E", "ti_omp_utils_OpenMP_getTimerFreq__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "exitThread", "entry", "%p", "exit", ""));
        loggables.add(Global.newObject("name", "mainTaskExit", "entry", "%p", "exit", ""));
        loggables.add(Global.newObject("name", "useSharedHeap", "entry", "", "exit", "%d"));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("OpenMP", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("OpenMP");
    }

    void HeapOMP$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.utils.HeapOMP", "ti.omp.utils");
        po = (Proto.Obj)om.findStrict("ti.omp.utils.HeapOMP.Module", "ti.omp.utils");
        vo.init2(po, "ti.omp.utils.HeapOMP", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.omp.utils.HeapOMP$$capsule", "ti.omp.utils"));
        vo.bind("Instance", om.findStrict("ti.omp.utils.HeapOMP.Instance", "ti.omp.utils"));
        vo.bind("Params", om.findStrict("ti.omp.utils.HeapOMP.Params", "ti.omp.utils"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.omp.utils.HeapOMP.Params", "ti.omp.utils")).newInstance());
        vo.bind("Handle", om.findStrict("ti.omp.utils.HeapOMP.Handle", "ti.omp.utils"));
        vo.bind("$package", om.findStrict("ti.omp.utils", "ti.omp.utils"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        mcfgs.add("localHeapSize");
        mcfgs.add("sharedHeapSize");
        mcfgs.add("sharedRegionId");
        vo.bind("Instance_State", om.findStrict("ti.omp.utils.HeapOMP.Instance_State", "ti.omp.utils"));
        tdefs.add(om.findStrict("ti.omp.utils.HeapOMP.Instance_State", "ti.omp.utils"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.omp.utils")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", om.has("ti.omp.utils.HeapOMP$$instance$static$init", null) ? 1 : 0);
            vo.bind("__initObject", Global.get("ti$omp$utils$HeapOMP$$__initObject"));
        }//isCFG
        vo.bind("$$fxntab", Global.newArray("ti_omp_utils_HeapOMP_Handle__label__E", "ti_omp_utils_HeapOMP_Module__startupDone__E", "ti_omp_utils_HeapOMP_Object__create__E", "ti_omp_utils_HeapOMP_Object__delete__E", "ti_omp_utils_HeapOMP_Object__destruct__E", "ti_omp_utils_HeapOMP_Object__get__E", "ti_omp_utils_HeapOMP_Object__first__E", "ti_omp_utils_HeapOMP_Object__next__E", "ti_omp_utils_HeapOMP_Params__init__E", "ti_omp_utils_HeapOMP_isBlocking__E", "ti_omp_utils_HeapOMP_getStats__E", "ti_omp_utils_HeapOMP_alloc__E", "ti_omp_utils_HeapOMP_free__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.omp.utils.HeapOMP.Object", "ti.omp.utils"));
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "isBlocking", "entry", "%p", "exit", "%d"));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("HeapOMP", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("HeapOMP");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
            Object srcP = ((XScriptO)om.findStrict("xdc.runtime.IInstance", "ti.omp.utils")).findStrict("PARAMS", "ti.omp.utils");
            Scriptable dstP;

            dstP = (Scriptable)((XScriptO)om.findStrict("ti.omp.utils.SemaphoreMP", "ti.omp.utils")).findStrict("PARAMS", "ti.omp.utils");
            Global.put(dstP, "instance", srcP);
            dstP = (Scriptable)((XScriptO)om.findStrict("ti.omp.utils.HeapOMP", "ti.omp.utils")).findStrict("PARAMS", "ti.omp.utils");
            Global.put(dstP, "instance", srcP);
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.omp.utils.ThreadLocal", "ti.omp.utils"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.omp.utils.ThreadLocalStorage", "ti.omp.utils"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.omp.utils.SemaphoreMP", "ti.omp.utils"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.omp.utils.OpenMP", "ti.omp.utils"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.omp.utils.HeapOMP", "ti.omp.utils"));
        if (isCFG) {
            vo = (Value.Obj)om.findStrict("ti.omp.utils.ThreadLocal", "ti.omp.utils");
            Global.put(vo, "rovViewInfo", Global.callFxn("create", (Scriptable)om.find("xdc.rov.ViewInfo"), Global.newObject("viewMap", Global.newArray(new Object[]{Global.newArray(new Object[]{"Thread local data", Global.newObject("type", om.find("xdc.rov.ViewInfo.MODULE_DATA"), "viewInitFxn", "viewKeyValues", "structName", "KeyValueView")})}))));
        }//isCFG
        if (isCFG) {
            vo = (Value.Obj)om.findStrict("ti.omp.utils.SemaphoreMP", "ti.omp.utils");
            Global.put(vo, "rovViewInfo", Global.callFxn("create", (Scriptable)om.find("xdc.rov.ViewInfo"), Global.newObject("viewMap", Global.newArray(new Object[]{Global.newArray(new Object[]{"Basic", Global.newObject("type", om.find("xdc.rov.ViewInfo.INSTANCE"), "viewInitFxn", "viewInitBasic", "structName", "BasicView")})}))));
        }//isCFG
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.omp.utils.ThreadLocal")).bless();
        ((Value.Obj)om.getv("ti.omp.utils.ThreadLocalStorage")).bless();
        ((Value.Obj)om.getv("ti.omp.utils.SemaphoreMP")).bless();
        ((Value.Obj)om.getv("ti.omp.utils.OpenMP")).bless();
        ((Value.Obj)om.getv("ti.omp.utils.HeapOMP")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.omp.utils")).add(pkgV);
    }

    public void exec( Scriptable xdcO, Session ses )
    {
        this.xdcO = xdcO;
        this.ses = ses;
        om = (Value.Obj)xdcO.get("om", null);

        Object o = om.geto("$name");
        String s = o instanceof String ? (String)o : null;
        isCFG = s != null && s.equals("cfg");
        isROV = s != null && s.equals("rov");

        $$IMPORTS();
        $$OBJECTS();
        ThreadLocal$$OBJECTS();
        ThreadLocalStorage$$OBJECTS();
        SemaphoreMP$$OBJECTS();
        OpenMP$$OBJECTS();
        HeapOMP$$OBJECTS();
        ThreadLocal$$CONSTS();
        ThreadLocalStorage$$CONSTS();
        SemaphoreMP$$CONSTS();
        OpenMP$$CONSTS();
        HeapOMP$$CONSTS();
        ThreadLocal$$CREATES();
        ThreadLocalStorage$$CREATES();
        SemaphoreMP$$CREATES();
        OpenMP$$CREATES();
        HeapOMP$$CREATES();
        ThreadLocal$$FUNCTIONS();
        ThreadLocalStorage$$FUNCTIONS();
        SemaphoreMP$$FUNCTIONS();
        OpenMP$$FUNCTIONS();
        HeapOMP$$FUNCTIONS();
        ThreadLocal$$SIZES();
        ThreadLocalStorage$$SIZES();
        SemaphoreMP$$SIZES();
        OpenMP$$SIZES();
        HeapOMP$$SIZES();
        ThreadLocal$$TYPES();
        ThreadLocalStorage$$TYPES();
        SemaphoreMP$$TYPES();
        OpenMP$$TYPES();
        HeapOMP$$TYPES();
        if (isROV) {
            ThreadLocal$$ROV();
            ThreadLocalStorage$$ROV();
            SemaphoreMP$$ROV();
            OpenMP$$ROV();
            HeapOMP$$ROV();
        }//isROV
        $$SINGLETONS();
        ThreadLocal$$SINGLETONS();
        ThreadLocalStorage$$SINGLETONS();
        SemaphoreMP$$SINGLETONS();
        OpenMP$$SINGLETONS();
        HeapOMP$$SINGLETONS();
        $$INITIALIZATION();
    }
}

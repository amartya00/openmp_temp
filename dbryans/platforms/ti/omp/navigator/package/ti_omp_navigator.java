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

public class ti_omp_navigator
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
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.omp.navigator.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.omp.navigator", new Value.Obj("ti.omp.navigator", pkgP));
    }

    void Navigator$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.omp.navigator.Navigator.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.omp.navigator.Navigator", new Value.Obj("ti.omp.navigator.Navigator", po));
        pkgV.bind("Navigator", vo);
        // decls 
    }

    void Navigator$$CONSTS()
    {
        // module Navigator
        om.bind("ti.omp.navigator.Navigator.init_Navigator", new Extern("ti_omp_navigator_Navigator_init_Navigator__E", "xdc_Void(*)(xdc_Void)", true, false));
        om.bind("ti.omp.navigator.Navigator.queue_pop_elem", new Extern("ti_omp_navigator_Navigator_queue_pop_elem__E", "xdc_Ptr(*)(xdc_UInt32)", true, false));
        om.bind("ti.omp.navigator.Navigator.queue_pop_elem_wait", new Extern("ti_omp_navigator_Navigator_queue_pop_elem_wait__E", "xdc_Ptr(*)(xdc_UInt32)", true, false));
        om.bind("ti.omp.navigator.Navigator.Queue_get_num_elem", new Extern("ti_omp_navigator_Navigator_Queue_get_num_elem__E", "xdc_UInt32(*)(xdc_UInt32)", true, false));
        om.bind("ti.omp.navigator.Navigator.queue_push_elem", new Extern("ti_omp_navigator_Navigator_queue_push_elem__E", "xdc_Void(*)(xdc_UInt32,xdc_UInt32)", true, false));
        om.bind("ti.omp.navigator.Navigator.Barrier_wait", new Extern("ti_omp_navigator_Navigator_Barrier_wait__E", "xdc_Void(*)(xdc_UInt32,xdc_UInt32)", true, false));
        om.bind("ti.omp.navigator.Navigator.Queue_Barrier_wait", new Extern("ti_omp_navigator_Navigator_Queue_Barrier_wait__E", "xdc_Void(*)(xdc_UInt32*)", true, false));
        om.bind("ti.omp.navigator.Navigator.wait_for_release", new Extern("ti_omp_navigator_Navigator_wait_for_release__E", "xdc_Void(*)(xdc_UInt32*)", true, false));
        om.bind("ti.omp.navigator.Navigator.wait_threads_release", new Extern("ti_omp_navigator_Navigator_wait_threads_release__E", "xdc_Void(*)(xdc_UInt32*)", true, false));
        om.bind("ti.omp.navigator.Navigator.Close_Queue", new Extern("ti_omp_navigator_Navigator_Close_Queue__E", "xdc_Void(*)(xdc_UInt32)", true, false));
        om.bind("ti.omp.navigator.Navigator.sysExit", new Extern("ti_omp_navigator_Navigator_sysExit__E", "xdc_Void(*)(xdc_Void)", true, false));
        om.bind("ti.omp.navigator.Navigator.Create_Queue", new Extern("ti_omp_navigator_Navigator_Create_Queue__E", "xdc_UInt32(*)(xdc_Void)", true, false));
    }

    void Navigator$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void Navigator$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void Navigator$$SIZES()
    {
        Proto.Str so;
        Object fxn;

    }

    void Navigator$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/navigator/Navigator.xs");
        om.bind("ti.omp.navigator.Navigator$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.omp.navigator.Navigator.Module", "ti.omp.navigator");
        po.init("ti.omp.navigator.Navigator.Module", om.findStrict("xdc.runtime.IModule.Module", "ti.omp.navigator"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.omp.navigator.Navigator$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.omp.navigator.Navigator$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.omp.navigator.Navigator$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.omp.navigator.Navigator$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        // typedef Navigator.Nav_Ptr
        om.bind("ti.omp.navigator.Navigator.Nav_Ptr", new Proto.Adr("xdc_Void(*)(xdc_UArg,xdc_UArg)", "PFv"));
    }

    void Navigator$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.navigator.Navigator", "ti.omp.navigator");
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.omp.navigator.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.omp.navigator"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/navigator/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.omp.navigator"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.omp.navigator"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.omp.navigator"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.omp.navigator"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.omp.navigator"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.omp.navigator"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.omp.navigator", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.omp.navigator");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.omp.navigator.");
        pkgV.bind("$vers", Global.newArray("2, 0, 0, 0"));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        imports.add(Global.newArray("ti.omp", Global.newArray()));
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.omp.navigator'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/release/ti.omp.navigator.ae66',\n");
            sb.append("'lib/debug/ti.omp.navigator.ae66',\n");
            sb.append("'lib/release/ti.omp.navigatorOsal.ae66',\n");
            sb.append("'lib/debug/ti.omp.navigatorOsal.ae66',\n");
            sb.append("'lib/release/ti.omp.navigator.C6678.ae66',\n");
            sb.append("'lib/release/ti.omp.navigator.C6670.ae66',\n");
            sb.append("'lib/debug/ti.omp.navigator.C6678.ae66',\n");
            sb.append("'lib/debug/ti.omp.navigator.C6670.ae66',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/release/ti.omp.navigator.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/debug/ti.omp.navigator.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/release/ti.omp.navigatorOsal.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/debug/ti.omp.navigatorOsal.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/release/ti.omp.navigator.C6678.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/release/ti.omp.navigator.C6670.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/debug/ti.omp.navigator.C6678.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/debug/ti.omp.navigator.C6670.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void Navigator$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.navigator.Navigator", "ti.omp.navigator");
        po = (Proto.Obj)om.findStrict("ti.omp.navigator.Navigator.Module", "ti.omp.navigator");
        vo.init2(po, "ti.omp.navigator.Navigator", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.omp.navigator.Navigator$$capsule", "ti.omp.navigator"));
        vo.bind("$package", om.findStrict("ti.omp.navigator", "ti.omp.navigator"));
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
        vo.bind("Nav_Ptr", om.findStrict("ti.omp.navigator.Navigator.Nav_Ptr", "ti.omp.navigator"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.omp.navigator")).add(vo);
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
        vo.bind("init_Navigator", om.findStrict("ti.omp.navigator.Navigator.init_Navigator", "ti.omp.navigator"));
        vo.bind("queue_pop_elem", om.findStrict("ti.omp.navigator.Navigator.queue_pop_elem", "ti.omp.navigator"));
        vo.bind("queue_pop_elem_wait", om.findStrict("ti.omp.navigator.Navigator.queue_pop_elem_wait", "ti.omp.navigator"));
        vo.bind("Queue_get_num_elem", om.findStrict("ti.omp.navigator.Navigator.Queue_get_num_elem", "ti.omp.navigator"));
        vo.bind("queue_push_elem", om.findStrict("ti.omp.navigator.Navigator.queue_push_elem", "ti.omp.navigator"));
        vo.bind("Barrier_wait", om.findStrict("ti.omp.navigator.Navigator.Barrier_wait", "ti.omp.navigator"));
        vo.bind("Queue_Barrier_wait", om.findStrict("ti.omp.navigator.Navigator.Queue_Barrier_wait", "ti.omp.navigator"));
        vo.bind("wait_for_release", om.findStrict("ti.omp.navigator.Navigator.wait_for_release", "ti.omp.navigator"));
        vo.bind("wait_threads_release", om.findStrict("ti.omp.navigator.Navigator.wait_threads_release", "ti.omp.navigator"));
        vo.bind("Close_Queue", om.findStrict("ti.omp.navigator.Navigator.Close_Queue", "ti.omp.navigator"));
        vo.bind("sysExit", om.findStrict("ti.omp.navigator.Navigator.sysExit", "ti.omp.navigator"));
        vo.bind("Create_Queue", om.findStrict("ti.omp.navigator.Navigator.Create_Queue", "ti.omp.navigator"));
        vo.bind("$$fxntab", Global.newArray("ti_omp_navigator_Navigator_Module__startupDone__E", "ti_omp_navigator_Navigator_init_Navigator__E", "ti_omp_navigator_Navigator_queue_pop_elem__E", "ti_omp_navigator_Navigator_queue_pop_elem_wait__E", "ti_omp_navigator_Navigator_Queue_get_num_elem__E", "ti_omp_navigator_Navigator_queue_push_elem__E", "ti_omp_navigator_Navigator_Barrier_wait__E", "ti_omp_navigator_Navigator_Queue_Barrier_wait__E", "ti_omp_navigator_Navigator_wait_for_release__E", "ti_omp_navigator_Navigator_wait_threads_release__E", "ti_omp_navigator_Navigator_Close_Queue__E", "ti_omp_navigator_Navigator_sysExit__E", "ti_omp_navigator_Navigator_Create_Queue__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "init_Navigator", "entry", "", "exit", ""));
        loggables.add(Global.newObject("name", "queue_pop_elem", "entry", "0x%x", "exit", "%p"));
        loggables.add(Global.newObject("name", "queue_pop_elem_wait", "entry", "0x%x", "exit", "%p"));
        loggables.add(Global.newObject("name", "Queue_get_num_elem", "entry", "0x%x", "exit", "0x%x"));
        loggables.add(Global.newObject("name", "queue_push_elem", "entry", "0x%x, 0x%x", "exit", ""));
        loggables.add(Global.newObject("name", "Barrier_wait", "entry", "0x%x, 0x%x", "exit", ""));
        loggables.add(Global.newObject("name", "Queue_Barrier_wait", "entry", "%p", "exit", ""));
        loggables.add(Global.newObject("name", "wait_for_release", "entry", "%p", "exit", ""));
        loggables.add(Global.newObject("name", "wait_threads_release", "entry", "%p", "exit", ""));
        loggables.add(Global.newObject("name", "Close_Queue", "entry", "0x%x", "exit", ""));
        loggables.add(Global.newObject("name", "sysExit", "entry", "", "exit", ""));
        loggables.add(Global.newObject("name", "Create_Queue", "entry", "", "exit", "0x%x"));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("Navigator", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Navigator");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.omp.navigator.Navigator", "ti.omp.navigator"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.omp.navigator.Navigator")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.omp.navigator")).add(pkgV);
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
        Navigator$$OBJECTS();
        Navigator$$CONSTS();
        Navigator$$CREATES();
        Navigator$$FUNCTIONS();
        Navigator$$SIZES();
        Navigator$$TYPES();
        if (isROV) {
            Navigator$$ROV();
        }//isROV
        $$SINGLETONS();
        Navigator$$SINGLETONS();
        $$INITIALIZATION();
    }
}

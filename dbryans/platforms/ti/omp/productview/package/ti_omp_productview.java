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

public class ti_omp_productview
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
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
        Global.callFxn("loadPackage", xdcO, "xdc.tools.product");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.omp.productview.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.omp.productview", new Value.Obj("ti.omp.productview", pkgP));
    }

    void OmpProductView$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.omp.productview.OmpProductView.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.omp.productview.OmpProductView", new Value.Obj("ti.omp.productview.OmpProductView", po));
        pkgV.bind("OmpProductView", vo);
        // decls 
        om.bind("ti.omp.productview.OmpProductView.ProductElemDesc", om.findStrict("xdc.tools.product.IProductView.ProductElemDesc", "ti.omp.productview"));
    }

    void OmpProductView$$CONSTS()
    {
        // module OmpProductView
    }

    void OmpProductView$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void OmpProductView$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void OmpProductView$$SIZES()
    {
    }

    void OmpProductView$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/omp/productview/OmpProductView.xs");
        om.bind("ti.omp.productview.OmpProductView$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.omp.productview.OmpProductView.Module", "ti.omp.productview");
        po.init("ti.omp.productview.OmpProductView.Module", om.findStrict("xdc.tools.product.IProductView.Module", "ti.omp.productview"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("ti_omp_utils_OpenMP", (Proto)om.findStrict("ti.omp.productview.OmpProductView.ProductElemDesc", "ti.omp.productview"), $$DEFAULT, "wh");
        po.addFld("ompProduct", (Proto)om.findStrict("ti.omp.productview.OmpProductView.ProductElemDesc", "ti.omp.productview"), $$DEFAULT, "wh");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.omp.productview.OmpProductView$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.omp.productview.OmpProductView$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.omp.productview.OmpProductView$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
                fxn = Global.get(cap, "getProductDescriptor");
                if (fxn != null) po.addFxn("getProductDescriptor", (Proto.Fxn)om.findStrict("xdc.tools.product.IProductView$$getProductDescriptor", "ti.omp.productview"), fxn);
    }

    void OmpProductView$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.omp.productview.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.omp.productview"));
        pkgP.bind("$capsule", $$UNDEF);
        pkgV.init2(pkgP, "ti.omp.productview", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.omp.productview");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.omp.productview.");
        pkgV.bind("$vers", Global.newArray());
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.omp.productview'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void OmpProductView$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.omp.productview.OmpProductView", "ti.omp.productview");
        po = (Proto.Obj)om.findStrict("ti.omp.productview.OmpProductView.Module", "ti.omp.productview");
        vo.init2(po, "ti.omp.productview.OmpProductView", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.omp.productview.OmpProductView$$capsule", "ti.omp.productview"));
        vo.bind("$package", om.findStrict("ti.omp.productview", "ti.omp.productview"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("ProductElemDesc", om.findStrict("xdc.tools.product.IProductView.ProductElemDesc", "ti.omp.productview"));
        tdefs.add(om.findStrict("xdc.tools.product.IProductView.ProductElemDesc", "ti.omp.productview"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.tools.product");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.omp.productview")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.omp.productview.OmpProductView$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        pkgV.bind("OmpProductView", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("OmpProductView");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.omp.productview.OmpProductView", "ti.omp.productview"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.omp.productview.OmpProductView")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.omp.productview")).add(pkgV);
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
        OmpProductView$$OBJECTS();
        OmpProductView$$CONSTS();
        OmpProductView$$CREATES();
        OmpProductView$$FUNCTIONS();
        OmpProductView$$SIZES();
        OmpProductView$$TYPES();
        if (isROV) {
            OmpProductView$$ROV();
        }//isROV
        $$SINGLETONS();
        OmpProductView$$SINGLETONS();
        $$INITIALIZATION();
    }
}

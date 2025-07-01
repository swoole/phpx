namespace php {
class XSLTProcessor {
    Object _this;
  public:
    Variant importStylesheet(const Variant &stylesheet);
    Variant transformToDoc(const Variant &document, const Variant &return_class = {});
    Variant transformToUri(const Variant &document, const Variant &uri);
    Variant transformToXml(const Variant &document);
    Variant setParameter(const Variant &_namespace, const Variant &name, const Variant &value = {});
    Variant getParameter(const Variant &_namespace, const Variant &name);
    Variant removeParameter(const Variant &_namespace, const Variant &name);
    Variant hasExsltSupport();
    Variant registerPHPFunctions(const Variant &functions = {});
    Variant setProfiling(const Variant &filename);
    Variant setSecurityPrefs(const Variant &preferences);
    Variant getSecurityPrefs();
};

}

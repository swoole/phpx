namespace php {
class XSLTProcessor {
  private:
    Variant _this;
  public:
    Variant importStylesheet(const std::initializer_list<Variant> &args);
    Variant transformToDoc(const std::initializer_list<Variant> &args);
    Variant transformToUri(const std::initializer_list<Variant> &args);
    Variant transformToXml(const std::initializer_list<Variant> &args);
    Variant setParameter(const std::initializer_list<Variant> &args);
    Variant getParameter(const std::initializer_list<Variant> &args);
    Variant removeParameter(const std::initializer_list<Variant> &args);
    Variant hasExsltSupport();
    Variant registerPHPFunctions(const std::initializer_list<Variant> &args);
    Variant setProfiling(const std::initializer_list<Variant> &args);
    Variant setSecurityPrefs(const std::initializer_list<Variant> &args);
    Variant getSecurityPrefs();
};

}

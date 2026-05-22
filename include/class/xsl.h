#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class XSLTProcessor;

class XSLTProcessor {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit XSLTProcessor(const Object &obj) : this_(obj) {}
    XSLTProcessor();
    Variant importStylesheet(const Variant &stylesheet);
    Variant transformToDoc(const Variant &document, const Variant &return_class = nullptr);
    Variant transformToUri(const Variant &document, const Variant &uri);
    Variant transformToXml(const Variant &document);
    Variant setParameter(const Variant &namespace_, const Variant &name, const Variant &value = nullptr);
    Variant getParameter(const Variant &namespace_, const Variant &name);
    Variant removeParameter(const Variant &namespace_, const Variant &name);
    Variant hasExsltSupport();
    Variant registerPHPFunctions(const Variant &functions = nullptr);
    Variant registerPHPFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable);
    Variant setProfiling(const Variant &filename);
    Variant setSecurityPrefs(const Variant &preferences);
    Variant getSecurityPrefs();
};

}  // namespace php

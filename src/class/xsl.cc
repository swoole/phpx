#include "phpx.h"
#include "phpx_class.h"
#include "class/xsl.h"

namespace php {
XSLTProcessor::XSLTProcessor() {
    this_ = newObject(LITERAL_STRING[2734]);
}
Variant XSLTProcessor::importStylesheet(const Variant &stylesheet) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2735]);
    }
    return this_.call(_method_fn, {stylesheet});
}
Variant XSLTProcessor::transformToDoc(const Variant &document, const Variant &return_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2736]);
    }
    return this_.call(_method_fn, {document, return_class});
}
Variant XSLTProcessor::transformToUri(const Variant &document, const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2737]);
    }
    return this_.call(_method_fn, {document, uri});
}
Variant XSLTProcessor::transformToXml(const Variant &document) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2738]);
    }
    return this_.call(_method_fn, {document});
}
Variant XSLTProcessor::setParameter(const Variant &namespace_, const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2739]);
    }
    return this_.call(_method_fn, {namespace_, name, value});
}
Variant XSLTProcessor::getParameter(const Variant &namespace_, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2740]);
    }
    return this_.call(_method_fn, {namespace_, name});
}
Variant XSLTProcessor::removeParameter(const Variant &namespace_, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2741]);
    }
    return this_.call(_method_fn, {namespace_, name});
}
Variant XSLTProcessor::hasExsltSupport() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2742]);
    }
    return this_.call(_method_fn, {});
}
Variant XSLTProcessor::registerPHPFunctions(const Variant &functions) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2743]);
    }
    return this_.call(_method_fn, {functions});
}
Variant XSLTProcessor::registerPHPFunctionNS(const Variant &namespace_u_r_i,
                                             const Variant &name,
                                             const Variant &callable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2744]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, name, callable});
}
Variant XSLTProcessor::setProfiling(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2745]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XSLTProcessor::setSecurityPrefs(const Variant &preferences) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2746]);
    }
    return this_.call(_method_fn, {preferences});
}
Variant XSLTProcessor::getSecurityPrefs() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2747]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

#include "phpx.h"
#include "class/xsl.h"

namespace php {
XSLTProcessor::XSLTProcessor() {
    this_ = newObject(LITERAL_STRING[2570]);
}
Variant XSLTProcessor::importStylesheet(const Variant &stylesheet) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2571]);
    }
    return this_.call(_method_fn, {stylesheet});
}
Variant XSLTProcessor::transformToDoc(const Variant &document, const Variant &return_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2572]);
    }
    return this_.call(_method_fn, {document, return_class});
}
Variant XSLTProcessor::transformToUri(const Variant &document, const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2573]);
    }
    return this_.call(_method_fn, {document, uri});
}
Variant XSLTProcessor::transformToXml(const Variant &document) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2574]);
    }
    return this_.call(_method_fn, {document});
}
Variant XSLTProcessor::setParameter(const Variant &_namespace, const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2575]);
    }
    return this_.call(_method_fn, {_namespace, name, value});
}
Variant XSLTProcessor::getParameter(const Variant &_namespace, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2576]);
    }
    return this_.call(_method_fn, {_namespace, name});
}
Variant XSLTProcessor::removeParameter(const Variant &_namespace, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2577]);
    }
    return this_.call(_method_fn, {_namespace, name});
}
Variant XSLTProcessor::hasExsltSupport() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2578]);
    }
    return this_.call(_method_fn, {});
}
Variant XSLTProcessor::registerPHPFunctions(const Variant &functions) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2579]);
    }
    return this_.call(_method_fn, {functions});
}
Variant XSLTProcessor::registerPHPFunctionNS(const Variant &namespace_u_r_i,
                                             const Variant &name,
                                             const Variant &callable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2580]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, name, callable});
}
Variant XSLTProcessor::setProfiling(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2581]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XSLTProcessor::setSecurityPrefs(const Variant &preferences) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2582]);
    }
    return this_.call(_method_fn, {preferences});
}
Variant XSLTProcessor::getSecurityPrefs() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2583]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

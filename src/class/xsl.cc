#include "phpx.h"
#include "class/xsl.h"

namespace php {
XSLTProcessor::XSLTProcessor() {
    this_ = newObject(LITERAL_STRING[3448]);
}
Variant XSLTProcessor::importStylesheet(const Variant &stylesheet) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3449]);
    }
    return this_.call(_method_fn, {stylesheet});
}
Variant XSLTProcessor::transformToDoc(const Variant &document, const Variant &return_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3450]);
    }
    return this_.call(_method_fn, {document, return_class});
}
Variant XSLTProcessor::transformToUri(const Variant &document, const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3451]);
    }
    return this_.call(_method_fn, {document, uri});
}
Variant XSLTProcessor::transformToXml(const Variant &document) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3452]);
    }
    return this_.call(_method_fn, {document});
}
Variant XSLTProcessor::setParameter(const Variant &namespace_, const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3453]);
    }
    return this_.call(_method_fn, {namespace_, name, value});
}
Variant XSLTProcessor::getParameter(const Variant &namespace_, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3454]);
    }
    return this_.call(_method_fn, {namespace_, name});
}
Variant XSLTProcessor::removeParameter(const Variant &namespace_, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3455]);
    }
    return this_.call(_method_fn, {namespace_, name});
}
Variant XSLTProcessor::hasExsltSupport() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3456]);
    }
    return this_.call(_method_fn, {});
}
Variant XSLTProcessor::registerPHPFunctions(const Variant &functions) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3457]);
    }
    return this_.call(_method_fn, {functions});
}
Variant XSLTProcessor::registerPHPFunctionNS(const Variant &namespace_u_r_i,
                                             const Variant &name,
                                             const Variant &callable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3458]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, name, callable});
}
Variant XSLTProcessor::setProfiling(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3459]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XSLTProcessor::setSecurityPrefs(const Variant &preferences) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3460]);
    }
    return this_.call(_method_fn, {preferences});
}
Variant XSLTProcessor::getSecurityPrefs() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3461]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

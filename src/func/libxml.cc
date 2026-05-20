#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant libxml_set_streams_context(const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[673]);
    }
    return call(fn, {context});
}
Variant libxml_use_internal_errors(const Variant &use_errors) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[674]);
    }
    return call(fn, {use_errors});
}
LibXMLError libxml_get_last_error() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[675]);
    }
    auto _rv = call(fn, {});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "libxml_get_last_error() returned false");
    }
    return LibXMLError(Object(std::move(_rv)));
}
Variant libxml_get_errors() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[676]);
    }
    return call(fn, {});
}
Variant libxml_clear_errors() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[677]);
    }
    return call(fn, {});
}
Variant libxml_disable_entity_loader(const Variant &disable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[678]);
    }
    return call(fn, {disable});
}
Variant libxml_set_external_entity_loader(const Variant &resolver_function) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[679]);
    }
    return call(fn, {resolver_function});
}
Variant libxml_get_external_entity_loader() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[680]);
    }
    return call(fn, {});
}
}  // namespace php

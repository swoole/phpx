#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant json_encode(const Variant &value, const Variant &flags, const Variant &depth) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[701]);
    }
    return call(_fn, {value, flags, depth});
}
Variant json_decode(const Variant &json, const Variant &associative, const Variant &depth, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[702]);
    }
    return call(_fn, {json, associative, depth, flags});
}
Variant json_validate(const Variant &json, const Variant &depth, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[703]);
    }
    return call(_fn, {json, depth, flags});
}
Variant json_last_error() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[704]);
    }
    return call(_fn, {});
}
Variant json_last_error_msg() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[705]);
    }
    return call(_fn, {});
}
}  // namespace php

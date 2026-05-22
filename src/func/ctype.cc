#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant ctype_alnum(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[191]);
    }
    return call(_fn, {text});
}
Variant ctype_alpha(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[192]);
    }
    return call(_fn, {text});
}
Variant ctype_cntrl(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[193]);
    }
    return call(_fn, {text});
}
Variant ctype_digit(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[194]);
    }
    return call(_fn, {text});
}
Variant ctype_lower(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[195]);
    }
    return call(_fn, {text});
}
Variant ctype_graph(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[196]);
    }
    return call(_fn, {text});
}
Variant ctype_print(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[197]);
    }
    return call(_fn, {text});
}
Variant ctype_punct(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[198]);
    }
    return call(_fn, {text});
}
Variant ctype_space(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[199]);
    }
    return call(_fn, {text});
}
Variant ctype_upper(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[200]);
    }
    return call(_fn, {text});
}
Variant ctype_xdigit(const Variant &text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[201]);
    }
    return call(_fn, {text});
}
}  // namespace php

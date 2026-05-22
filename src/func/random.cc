#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant lcg_value() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1236]);
    }
    return call(_fn, {});
}
Variant mt_srand(const Variant &seed, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1237]);
    }
    return call(_fn, {seed, mode});
}
Variant srand(const Variant &seed, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1238]);
    }
    return call(_fn, {seed, mode});
}
Variant rand(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1239]);
    }
    return call(_fn, {min, max});
}
Variant mt_rand(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1240]);
    }
    return call(_fn, {min, max});
}
Variant mt_getrandmax() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1241]);
    }
    return call(_fn, {});
}
Variant getrandmax() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1242]);
    }
    return call(_fn, {});
}
Variant random_bytes(const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1243]);
    }
    return call(_fn, {length});
}
Variant random_int(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1244]);
    }
    return call(_fn, {min, max});
}
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant lcg_value() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1203]);
    }
    return call(fn, {});
}
Variant mt_srand(const Variant &seed, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1204]);
    }
    return call(fn, {seed, mode});
}
Variant srand(const Variant &seed, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1205]);
    }
    return call(fn, {seed, mode});
}
Variant rand(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1206]);
    }
    return call(fn, {min, max});
}
Variant mt_rand(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1207]);
    }
    return call(fn, {min, max});
}
Variant mt_getrandmax() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1208]);
    }
    return call(fn, {});
}
Variant getrandmax() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1209]);
    }
    return call(fn, {});
}
Variant random_bytes(const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1210]);
    }
    return call(fn, {length});
}
Variant random_int(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1211]);
    }
    return call(fn, {min, max});
}
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant lcg_value() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1236]);
    }
    return call(fn, {});
}
Variant mt_srand(const Variant &seed, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1237]);
    }
    return call(fn, {seed, mode});
}
Variant srand(const Variant &seed, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1238]);
    }
    return call(fn, {seed, mode});
}
Variant rand(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1239]);
    }
    return call(fn, {min, max});
}
Variant mt_rand(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1240]);
    }
    return call(fn, {min, max});
}
Variant mt_getrandmax() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1241]);
    }
    return call(fn, {});
}
Variant getrandmax() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1242]);
    }
    return call(fn, {});
}
Variant random_bytes(const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1243]);
    }
    return call(fn, {length});
}
Variant random_int(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1244]);
    }
    return call(fn, {min, max});
}
}  // namespace php

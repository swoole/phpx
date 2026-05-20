#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant lcg_value() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1067]);
    }
    return call(fn, {});
}
Variant mt_srand(const Variant &seed, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1068]);
    }
    return call(fn, {seed, mode});
}
Variant srand(const Variant &seed, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1069]);
    }
    return call(fn, {seed, mode});
}
Variant rand(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1070]);
    }
    return call(fn, {min, max});
}
Variant mt_rand(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1071]);
    }
    return call(fn, {min, max});
}
Variant mt_getrandmax() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1072]);
    }
    return call(fn, {});
}
Variant getrandmax() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1073]);
    }
    return call(fn, {});
}
Variant random_bytes(const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1074]);
    }
    return call(fn, {length});
}
Variant random_int(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1075]);
    }
    return call(fn, {min, max});
}
}  // namespace php

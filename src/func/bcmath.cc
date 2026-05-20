#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant bcadd(const Variant &num1, const Variant &num2, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[0]);
    }
    return call(fn, {num1, num2, scale});
}
Variant bcsub(const Variant &num1, const Variant &num2, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1]);
    }
    return call(fn, {num1, num2, scale});
}
Variant bcmul(const Variant &num1, const Variant &num2, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2]);
    }
    return call(fn, {num1, num2, scale});
}
Variant bcdiv(const Variant &num1, const Variant &num2, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3]);
    }
    return call(fn, {num1, num2, scale});
}
Variant bcmod(const Variant &num1, const Variant &num2, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[4]);
    }
    return call(fn, {num1, num2, scale});
}
Variant bcdivmod(const Variant &num1, const Variant &num2, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[5]);
    }
    return call(fn, {num1, num2, scale});
}
Variant bcpowmod(const Variant &num, const Variant &exponent, const Variant &modulus, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[6]);
    }
    return call(fn, {num, exponent, modulus, scale});
}
Variant bcpow(const Variant &num, const Variant &exponent, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[7]);
    }
    return call(fn, {num, exponent, scale});
}
Variant bcsqrt(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[8]);
    }
    return call(fn, {num, scale});
}
Variant bccomp(const Variant &num1, const Variant &num2, const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[9]);
    }
    return call(fn, {num1, num2, scale});
}
Variant bcscale(const Variant &scale) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[10]);
    }
    return call(fn, {scale});
}
Variant bcfloor(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[11]);
    }
    return call(fn, {num});
}
Variant bcceil(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[12]);
    }
    return call(fn, {num});
}
Variant bcround(const Variant &num, const Variant &precision, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[13]);
    }
    return call(fn, {num, precision, mode});
}
}  // namespace php

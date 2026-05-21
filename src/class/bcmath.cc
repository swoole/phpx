#include "phpx.h"
#include "phpx_class.h"
#include "class/bcmath.h"

namespace php {
BcMath_Number::BcMath_Number(const Variant &num) {
    this_ = newObject(LITERAL_STRING[15], {num});
}
Variant BcMath_Number::add(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant BcMath_Number::sub(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant BcMath_Number::mul(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[18]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant BcMath_Number::div(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[19]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant BcMath_Number::mod(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[20]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant BcMath_Number::divmod(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[21]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant BcMath_Number::powmod(const Variant &exponent, const Variant &modulus, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[22]);
    }
    return this_.call(_method_fn, {exponent, modulus, scale});
}
Variant BcMath_Number::pow(const Variant &exponent, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[23]);
    }
    return this_.call(_method_fn, {exponent, scale});
}
Variant BcMath_Number::sqrt(const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[24]);
    }
    return this_.call(_method_fn, {scale});
}
Variant BcMath_Number::floor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[25]);
    }
    return this_.call(_method_fn, {});
}
Variant BcMath_Number::ceil() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[26]);
    }
    return this_.call(_method_fn, {});
}
Variant BcMath_Number::round(const Variant &precision, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[27]);
    }
    return this_.call(_method_fn, {precision, mode});
}
Variant BcMath_Number::compare(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[28]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant BcMath_Number::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant BcMath_Number::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant BcMath_Number::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
}  // namespace php

#include "phpx.h"
#include "class/bcmath.h"

namespace php::BcMath {
Number::Number(const Variant &num) {
    this_ = newObject(LITERAL_STRING[15], {num});
}
Variant Number::add(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant Number::sub(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant Number::mul(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[18]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant Number::div(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[19]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant Number::mod(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[20]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant Number::divmod(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[21]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant Number::powmod(const Variant &exponent, const Variant &modulus, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[22]);
    }
    return this_.call(_method_fn, {exponent, modulus, scale});
}
Variant Number::pow(const Variant &exponent, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[23]);
    }
    return this_.call(_method_fn, {exponent, scale});
}
Variant Number::sqrt(const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[24]);
    }
    return this_.call(_method_fn, {scale});
}
Variant Number::floor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[25]);
    }
    return this_.call(_method_fn, {});
}
Variant Number::ceil() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[26]);
    }
    return this_.call(_method_fn, {});
}
Variant Number::round(const Variant &precision, const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[27]);
    }
    return this_.call(_method_fn, {precision, mode});
}
Variant Number::compare(const Variant &num, const Variant &scale) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[28]);
    }
    return this_.call(_method_fn, {num, scale});
}
Variant Number::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant Number::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant Number::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
}  // namespace php::BcMath

#include "phpx.h"
#include "phpx_class.h"
#include "class/standard.h"

namespace php {
__PHP_Incomplete_Class::__PHP_Incomplete_Class() {
    this_ = newObject(LITERAL_STRING[2718]);
}
AssertionError::AssertionError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2719], {message, code, previous});
}
RoundingMode::RoundingMode() {
    this_ = newObject(LITERAL_STRING[2720]);
}
Variant RoundingMode::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2720], LITERAL_STRING[361]);
    }
    return php::call(_method_fn, {});
}
php_user_filter::php_user_filter() {
    this_ = newObject(LITERAL_STRING[2722]);
}
Variant php_user_filter::filter(const Variant &in,
                                const Variant &out,
                                const Reference &consumed,
                                const Variant &closing) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2723]);
    }
    return this_.call(_method_fn, {in, out, &consumed, closing});
}
Variant php_user_filter::onCreate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2724]);
    }
    return this_.call(_method_fn, {});
}
Variant php_user_filter::onClose() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2725]);
    }
    return this_.call(_method_fn, {});
}
StreamBucket::StreamBucket() {
    this_ = newObject(LITERAL_STRING[2726]);
}
Directory::Directory() {
    this_ = newObject(LITERAL_STRING[2727]);
}
Variant Directory::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
Variant Directory::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant Directory::read() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1842]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

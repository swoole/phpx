#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant cal_days_in_month(const Variant &calendar, const Variant &month, const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[42]);
    }
    return call(_fn, {calendar, month, year});
}
Variant cal_from_jd(const Variant &julian_day, const Variant &calendar) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[43]);
    }
    return call(_fn, {julian_day, calendar});
}
Variant cal_info(const Variant &calendar) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[44]);
    }
    return call(_fn, {calendar});
}
Variant cal_to_jd(const Variant &calendar, const Variant &month, const Variant &day, const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[45]);
    }
    return call(_fn, {calendar, month, day, year});
}
Variant easter_date(const Variant &year, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[46]);
    }
    return call(_fn, {year, mode});
}
Variant easter_days(const Variant &year, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[47]);
    }
    return call(_fn, {year, mode});
}
Variant frenchtojd(const Variant &month, const Variant &day, const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[48]);
    }
    return call(_fn, {month, day, year});
}
Variant gregoriantojd(const Variant &month, const Variant &day, const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[49]);
    }
    return call(_fn, {month, day, year});
}
Variant jddayofweek(const Variant &julian_day, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[50]);
    }
    return call(_fn, {julian_day, mode});
}
Variant jdmonthname(const Variant &julian_day, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[51]);
    }
    return call(_fn, {julian_day, mode});
}
Variant jdtofrench(const Variant &julian_day) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[52]);
    }
    return call(_fn, {julian_day});
}
Variant jdtogregorian(const Variant &julian_day) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[53]);
    }
    return call(_fn, {julian_day});
}
Variant jdtojewish(const Variant &julian_day, const Variant &hebrew, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[54]);
    }
    return call(_fn, {julian_day, hebrew, flags});
}
Variant jdtojulian(const Variant &julian_day) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[55]);
    }
    return call(_fn, {julian_day});
}
Variant jdtounix(const Variant &julian_day) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[56]);
    }
    return call(_fn, {julian_day});
}
Variant jewishtojd(const Variant &month, const Variant &day, const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[57]);
    }
    return call(_fn, {month, day, year});
}
Variant juliantojd(const Variant &month, const Variant &day, const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[58]);
    }
    return call(_fn, {month, day, year});
}
Variant unixtojd(const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[59]);
    }
    return call(_fn, {timestamp});
}
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant class_implements(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2014]);
    }
    return call(_fn, {object_or_class, autoload});
}
Variant class_parents(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2015]);
    }
    return call(_fn, {object_or_class, autoload});
}
Variant class_uses(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2016]);
    }
    return call(_fn, {object_or_class, autoload});
}
Variant spl_autoload(const Variant &class_, const Variant &file_extensions) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2017]);
    }
    return call(_fn, {class_, file_extensions});
}
Variant spl_autoload_call(const Variant &class_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2018]);
    }
    return call(_fn, {class_});
}
Variant spl_autoload_extensions(const Variant &file_extensions) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2019]);
    }
    return call(_fn, {file_extensions});
}
Variant spl_autoload_functions() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2020]);
    }
    return call(_fn, {});
}
Variant spl_autoload_register(const Variant &callback, const Variant &throw_, const Variant &prepend) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2021]);
    }
    return call(_fn, {callback, throw_, prepend});
}
Variant spl_autoload_unregister(const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2022]);
    }
    return call(_fn, {callback});
}
Variant spl_classes() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2023]);
    }
    return call(_fn, {});
}
Variant spl_object_hash(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2024]);
    }
    return call(_fn, {object});
}
Variant spl_object_id(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2025]);
    }
    return call(_fn, {object});
}
Variant iterator_apply(const Variant &iterator, const Variant &callback, const Variant &args) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2026]);
    }
    return call(_fn, {iterator, callback, args});
}
Variant iterator_count(const Variant &iterator) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2027]);
    }
    return call(_fn, {iterator});
}
Variant iterator_to_array(const Variant &iterator, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2028]);
    }
    return call(_fn, {iterator, preserve_keys});
}
}  // namespace php

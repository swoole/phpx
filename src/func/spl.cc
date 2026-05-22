#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant class_implements(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2014]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant class_parents(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2015]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant class_uses(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2016]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant spl_autoload(const Variant &class_, const Variant &file_extensions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2017]);
    }
    return call(fn, {class_, file_extensions});
}
Variant spl_autoload_call(const Variant &class_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2018]);
    }
    return call(fn, {class_});
}
Variant spl_autoload_extensions(const Variant &file_extensions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2019]);
    }
    return call(fn, {file_extensions});
}
Variant spl_autoload_functions() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2020]);
    }
    return call(fn, {});
}
Variant spl_autoload_register(const Variant &callback, const Variant &throw_, const Variant &prepend) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2021]);
    }
    return call(fn, {callback, throw_, prepend});
}
Variant spl_autoload_unregister(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2022]);
    }
    return call(fn, {callback});
}
Variant spl_classes() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2023]);
    }
    return call(fn, {});
}
Variant spl_object_hash(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2024]);
    }
    return call(fn, {object});
}
Variant spl_object_id(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2025]);
    }
    return call(fn, {object});
}
Variant iterator_apply(const Variant &iterator, const Variant &callback, const Variant &args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2026]);
    }
    return call(fn, {iterator, callback, args});
}
Variant iterator_count(const Variant &iterator) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2027]);
    }
    return call(fn, {iterator});
}
Variant iterator_to_array(const Variant &iterator, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2028]);
    }
    return call(fn, {iterator, preserve_keys});
}
}  // namespace php

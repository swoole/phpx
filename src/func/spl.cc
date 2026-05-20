#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant class_implements(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1734]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant class_parents(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1735]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant class_uses(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1736]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant spl_autoload(const Variant &_class, const Variant &file_extensions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1737]);
    }
    return call(fn, {_class, file_extensions});
}
Variant spl_autoload_call(const Variant &_class) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1738]);
    }
    return call(fn, {_class});
}
Variant spl_autoload_extensions(const Variant &file_extensions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1739]);
    }
    return call(fn, {file_extensions});
}
Variant spl_autoload_functions() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1740]);
    }
    return call(fn, {});
}
Variant spl_autoload_register(const Variant &callback, const Variant &_throw, const Variant &prepend) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1741]);
    }
    return call(fn, {callback, _throw, prepend});
}
Variant spl_autoload_unregister(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1742]);
    }
    return call(fn, {callback});
}
Variant spl_classes() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1743]);
    }
    return call(fn, {});
}
Variant spl_object_hash(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1744]);
    }
    return call(fn, {object});
}
Variant spl_object_id(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1745]);
    }
    return call(fn, {object});
}
Variant iterator_apply(const Variant &iterator, const Variant &callback, const Variant &args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1746]);
    }
    return call(fn, {iterator, callback, args});
}
Variant iterator_count(const Variant &iterator) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1747]);
    }
    return call(fn, {iterator});
}
Variant iterator_to_array(const Variant &iterator, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1748]);
    }
    return call(fn, {iterator, preserve_keys});
}
}  // namespace php

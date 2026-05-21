#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant class_implements(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1870]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant class_parents(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1871]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant class_uses(const Variant &object_or_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1872]);
    }
    return call(fn, {object_or_class, autoload});
}
Variant spl_autoload(const Variant &class_, const Variant &file_extensions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1873]);
    }
    return call(fn, {class_, file_extensions});
}
Variant spl_autoload_call(const Variant &class_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1874]);
    }
    return call(fn, {class_});
}
Variant spl_autoload_extensions(const Variant &file_extensions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1875]);
    }
    return call(fn, {file_extensions});
}
Variant spl_autoload_functions() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1876]);
    }
    return call(fn, {});
}
Variant spl_autoload_register(const Variant &callback, const Variant &throw_, const Variant &prepend) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1877]);
    }
    return call(fn, {callback, throw_, prepend});
}
Variant spl_autoload_unregister(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1878]);
    }
    return call(fn, {callback});
}
Variant spl_classes() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1879]);
    }
    return call(fn, {});
}
Variant spl_object_hash(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1880]);
    }
    return call(fn, {object});
}
Variant spl_object_id(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1881]);
    }
    return call(fn, {object});
}
Variant iterator_apply(const Variant &iterator, const Variant &callback, const Variant &args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1882]);
    }
    return call(fn, {iterator, callback, args});
}
Variant iterator_count(const Variant &iterator) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1883]);
    }
    return call(fn, {iterator});
}
Variant iterator_to_array(const Variant &iterator, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1884]);
    }
    return call(fn, {iterator, preserve_keys});
}
}  // namespace php

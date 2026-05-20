#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant json_encode(const Variant &value, const Variant &flags, const Variant &depth) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[667]);
    }
    return call(fn, {value, flags, depth});
}
Variant json_decode(const Variant &json, const Variant &associative, const Variant &depth, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[668]);
    }
    return call(fn, {json, associative, depth, flags});
}
Variant json_validate(const Variant &json, const Variant &depth, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[669]);
    }
    return call(fn, {json, depth, flags});
}
Variant json_last_error() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[670]);
    }
    return call(fn, {});
}
Variant json_last_error_msg() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[671]);
    }
    return call(fn, {});
}
}  // namespace php

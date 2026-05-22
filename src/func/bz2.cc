#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant bzopen(const Variant &file, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[32]);
    }
    return call(fn, {file, mode});
}
Variant bzread(const Variant &bz, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[33]);
    }
    return call(fn, {bz, length});
}
Variant bzwrite(const Variant &bz, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[34]);
    }
    return call(fn, {bz, data, length});
}
Variant bzflush(const Variant &bz) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[35]);
    }
    return call(fn, {bz});
}
Variant bzclose(const Variant &bz) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[36]);
    }
    return call(fn, {bz});
}
Variant bzerrno(const Variant &bz) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[37]);
    }
    return call(fn, {bz});
}
Variant bzerrstr(const Variant &bz) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[38]);
    }
    return call(fn, {bz});
}
Variant bzerror(const Variant &bz) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[39]);
    }
    return call(fn, {bz});
}
Variant bzcompress(const Variant &data, const Variant &block_size, const Variant &work_factor) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[40]);
    }
    return call(fn, {data, block_size, work_factor});
}
Variant bzdecompress(const Variant &data, const Variant &use_less_memory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[41]);
    }
    return call(fn, {data, use_less_memory});
}
}  // namespace php

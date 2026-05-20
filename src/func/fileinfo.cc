#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant finfo_open(const Variant &flags, const Variant &magic_database) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[523]);
    }
    return call(fn, {flags, magic_database});
}
Variant finfo_close(const finfo &finfo) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[524]);
    }
    return call(fn, {finfo.getObject()});
}
Variant finfo_close(const Variant &finfo) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[524]);
    }
    return call(fn, {finfo});
}
Variant finfo_set_flags(const finfo &finfo, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[525]);
    }
    return call(fn, {finfo.getObject(), flags});
}
Variant finfo_set_flags(const Variant &finfo, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[525]);
    }
    return call(fn, {finfo, flags});
}
Variant finfo_file(const finfo &finfo, const Variant &filename, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[526]);
    }
    return call(fn, {finfo.getObject(), filename, flags, context});
}
Variant finfo_file(const Variant &finfo, const Variant &filename, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[526]);
    }
    return call(fn, {finfo, filename, flags, context});
}
Variant finfo_buffer(const finfo &finfo, const Variant &string, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[527]);
    }
    return call(fn, {finfo.getObject(), string, flags, context});
}
Variant finfo_buffer(const Variant &finfo, const Variant &string, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[527]);
    }
    return call(fn, {finfo, string, flags, context});
}
Variant mime_content_type(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[528]);
    }
    return call(fn, {filename});
}
}  // namespace php

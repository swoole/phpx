#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant zip_open(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2892]);
    }
    return call(fn, {filename});
}
Variant zip_close(const Variant &zip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2893]);
    }
    return call(fn, {zip});
}
Variant zip_read(const Variant &zip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2894]);
    }
    return call(fn, {zip});
}
Variant zip_entry_open(const Variant &zip_dp, const Variant &zip_entry, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2895]);
    }
    return call(fn, {zip_dp, zip_entry, mode});
}
Variant zip_entry_close(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2896]);
    }
    return call(fn, {zip_entry});
}
Variant zip_entry_read(const Variant &zip_entry, const Variant &len) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2897]);
    }
    return call(fn, {zip_entry, len});
}
Variant zip_entry_name(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2898]);
    }
    return call(fn, {zip_entry});
}
Variant zip_entry_compressedsize(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2899]);
    }
    return call(fn, {zip_entry});
}
Variant zip_entry_filesize(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2900]);
    }
    return call(fn, {zip_entry});
}
Variant zip_entry_compressionmethod(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2901]);
    }
    return call(fn, {zip_entry});
}
}  // namespace php

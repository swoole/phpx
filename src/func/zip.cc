#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant zip_open(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3462]);
    }
    return call(fn, {filename});
}
Variant zip_close(const Variant &zip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3463]);
    }
    return call(fn, {zip});
}
Variant zip_read(const Variant &zip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3464]);
    }
    return call(fn, {zip});
}
Variant zip_entry_open(const Variant &zip_dp, const Variant &zip_entry, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3465]);
    }
    return call(fn, {zip_dp, zip_entry, mode});
}
Variant zip_entry_close(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3466]);
    }
    return call(fn, {zip_entry});
}
Variant zip_entry_read(const Variant &zip_entry, const Variant &len) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3467]);
    }
    return call(fn, {zip_entry, len});
}
Variant zip_entry_name(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3468]);
    }
    return call(fn, {zip_entry});
}
Variant zip_entry_compressedsize(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3469]);
    }
    return call(fn, {zip_entry});
}
Variant zip_entry_filesize(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3470]);
    }
    return call(fn, {zip_entry});
}
Variant zip_entry_compressionmethod(const Variant &zip_entry) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[3471]);
    }
    return call(fn, {zip_entry});
}
}  // namespace php

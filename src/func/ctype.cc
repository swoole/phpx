#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant ctype_alnum(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[163]);
    }
    return call(fn, {text});
}
Variant ctype_alpha(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[164]);
    }
    return call(fn, {text});
}
Variant ctype_cntrl(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[165]);
    }
    return call(fn, {text});
}
Variant ctype_digit(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[166]);
    }
    return call(fn, {text});
}
Variant ctype_lower(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[167]);
    }
    return call(fn, {text});
}
Variant ctype_graph(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[168]);
    }
    return call(fn, {text});
}
Variant ctype_print(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[169]);
    }
    return call(fn, {text});
}
Variant ctype_punct(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[170]);
    }
    return call(fn, {text});
}
Variant ctype_space(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[171]);
    }
    return call(fn, {text});
}
Variant ctype_upper(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[172]);
    }
    return call(fn, {text});
}
Variant ctype_xdigit(const Variant &text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[173]);
    }
    return call(fn, {text});
}
}  // namespace php

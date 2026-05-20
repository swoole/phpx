#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant preg_match(const Variant &pattern,
                   const Variant &subject,
                   const Reference &matches,
                   const Variant &flags,
                   const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[846]);
    }
    return call(fn, {pattern, subject, &matches, flags, offset});
}
Variant preg_match_all(const Variant &pattern,
                       const Variant &subject,
                       const Reference &matches,
                       const Variant &flags,
                       const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[847]);
    }
    return call(fn, {pattern, subject, &matches, flags, offset});
}
Variant preg_replace(const Variant &pattern,
                     const Variant &replacement,
                     const Variant &subject,
                     const Variant &limit,
                     const Reference &count) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[848]);
    }
    return call(fn, {pattern, replacement, subject, limit, &count});
}
Variant preg_filter(const Variant &pattern,
                    const Variant &replacement,
                    const Variant &subject,
                    const Variant &limit,
                    const Reference &count) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[849]);
    }
    return call(fn, {pattern, replacement, subject, limit, &count});
}
Variant preg_replace_callback(const Variant &pattern,
                              const Variant &callback,
                              const Variant &subject,
                              const Variant &limit,
                              const Reference &count,
                              const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[850]);
    }
    return call(fn, {pattern, callback, subject, limit, &count, flags});
}
Variant preg_replace_callback_array(const Variant &pattern,
                                    const Variant &subject,
                                    const Variant &limit,
                                    const Reference &count,
                                    const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[851]);
    }
    return call(fn, {pattern, subject, limit, &count, flags});
}
Variant preg_split(const Variant &pattern, const Variant &subject, const Variant &limit, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[852]);
    }
    return call(fn, {pattern, subject, limit, flags});
}
Variant preg_quote(const Variant &str, const Variant &delimiter) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[853]);
    }
    return call(fn, {str, delimiter});
}
Variant preg_grep(const Variant &pattern, const Variant &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[854]);
    }
    return call(fn, {pattern, array, flags});
}
Variant preg_last_error() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[855]);
    }
    return call(fn, {});
}
Variant preg_last_error_msg() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[856]);
    }
    return call(fn, {});
}
}  // namespace php

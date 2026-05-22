#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant hash(const Variant &algo, const Variant &data, const Variant &binary, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[637]);
    }
    return call(fn, {algo, data, binary, options});
}
Variant hash_file(const Variant &algo, const Variant &filename, const Variant &binary, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[638]);
    }
    return call(fn, {algo, filename, binary, options});
}
Variant hash_hmac(const Variant &algo, const Variant &data, const Variant &key, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[639]);
    }
    return call(fn, {algo, data, key, binary});
}
Variant hash_hmac_file(const Variant &algo, const Variant &filename, const Variant &key, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[640]);
    }
    return call(fn, {algo, filename, key, binary});
}
Variant hash_init(const Variant &algo, const Variant &flags, const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[641]);
    }
    return call(fn, {algo, flags, key, options});
}
Variant hash_update(const HashContext &context, const Variant &data) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[642]);
    }
    return call(fn, {context.getObject(), data});
}
Variant hash_update(const Variant &context, const Variant &data) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[642]);
    }
    return call(fn, {context, data});
}
Variant hash_update_stream(const HashContext &context, const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[643]);
    }
    return call(fn, {context.getObject(), stream, length});
}
Variant hash_update_stream(const Variant &context, const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[643]);
    }
    return call(fn, {context, stream, length});
}
Variant hash_update_file(const HashContext &context, const Variant &filename, const Variant &stream_context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[644]);
    }
    return call(fn, {context.getObject(), filename, stream_context});
}
Variant hash_update_file(const Variant &context, const Variant &filename, const Variant &stream_context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[644]);
    }
    return call(fn, {context, filename, stream_context});
}
Variant hash_final(const HashContext &context, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[645]);
    }
    return call(fn, {context.getObject(), binary});
}
Variant hash_final(const Variant &context, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[645]);
    }
    return call(fn, {context, binary});
}
Variant hash_copy(const HashContext &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[646]);
    }
    return call(fn, {context.getObject()});
}
Variant hash_copy(const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[646]);
    }
    return call(fn, {context});
}
Variant hash_algos() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[647]);
    }
    return call(fn, {});
}
Variant hash_hmac_algos() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[648]);
    }
    return call(fn, {});
}
Variant hash_pbkdf2(const Variant &algo,
                    const Variant &password,
                    const Variant &salt,
                    const Variant &iterations,
                    const Variant &length,
                    const Variant &binary,
                    const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[649]);
    }
    return call(fn, {algo, password, salt, iterations, length, binary, options});
}
Variant hash_equals(const Variant &known_string, const Variant &user_string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[650]);
    }
    return call(fn, {known_string, user_string});
}
Variant hash_hkdf(
    const Variant &algo, const Variant &key, const Variant &length, const Variant &info, const Variant &salt) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[651]);
    }
    return call(fn, {algo, key, length, info, salt});
}
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant hash(const Variant &algo, const Variant &data, const Variant &binary, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[675]);
    }
    return call(_fn, {algo, data, binary, options});
}
Variant hash_file(const Variant &algo, const Variant &filename, const Variant &binary, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[676]);
    }
    return call(_fn, {algo, filename, binary, options});
}
Variant hash_hmac(const Variant &algo, const Variant &data, const Variant &key, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[677]);
    }
    return call(_fn, {algo, data, key, binary});
}
Variant hash_hmac_file(const Variant &algo, const Variant &filename, const Variant &key, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[678]);
    }
    return call(_fn, {algo, filename, key, binary});
}
Variant hash_init(const Variant &algo, const Variant &flags, const Variant &key, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[679]);
    }
    return call(_fn, {algo, flags, key, options});
}
Variant hash_update(const HashContext &context, const Variant &data) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[680]);
    }
    return call(_fn, {context.getObject(), data});
}
Variant hash_update(const Variant &context, const Variant &data) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[680]);
    }
    return call(_fn, {context, data});
}
Variant hash_update_stream(const HashContext &context, const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[681]);
    }
    return call(_fn, {context.getObject(), stream, length});
}
Variant hash_update_stream(const Variant &context, const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[681]);
    }
    return call(_fn, {context, stream, length});
}
Variant hash_update_file(const HashContext &context, const Variant &filename, const Variant &stream_context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[682]);
    }
    return call(_fn, {context.getObject(), filename, stream_context});
}
Variant hash_update_file(const Variant &context, const Variant &filename, const Variant &stream_context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[682]);
    }
    return call(_fn, {context, filename, stream_context});
}
Variant hash_final(const HashContext &context, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[683]);
    }
    return call(_fn, {context.getObject(), binary});
}
Variant hash_final(const Variant &context, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[683]);
    }
    return call(_fn, {context, binary});
}
Variant hash_copy(const HashContext &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[684]);
    }
    return call(_fn, {context.getObject()});
}
Variant hash_copy(const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[684]);
    }
    return call(_fn, {context});
}
Variant hash_algos() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[685]);
    }
    return call(_fn, {});
}
Variant hash_hmac_algos() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[686]);
    }
    return call(_fn, {});
}
Variant hash_pbkdf2(const Variant &algo,
                    const Variant &password,
                    const Variant &salt,
                    const Variant &iterations,
                    const Variant &length,
                    const Variant &binary,
                    const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[687]);
    }
    return call(_fn, {algo, password, salt, iterations, length, binary, options});
}
Variant hash_equals(const Variant &known_string, const Variant &user_string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[688]);
    }
    return call(_fn, {known_string, user_string});
}
Variant hash_hkdf(
    const Variant &algo, const Variant &key, const Variant &length, const Variant &info, const Variant &salt) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[689]);
    }
    return call(_fn, {algo, key, length, info, salt});
}
}  // namespace php

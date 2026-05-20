#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant session_name(const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1652]);
    }
    return call(fn, {name});
}
Variant session_module_name(const Variant &module) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1653]);
    }
    return call(fn, {module});
}
Variant session_save_path(const Variant &path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1654]);
    }
    return call(fn, {path});
}
Variant session_id(const Variant &id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1655]);
    }
    return call(fn, {id});
}
Variant session_create_id(const Variant &prefix) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1656]);
    }
    return call(fn, {prefix});
}
Variant session_regenerate_id(const Variant &delete_old_session) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1657]);
    }
    return call(fn, {delete_old_session});
}
Variant session_decode(const Variant &data) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1658]);
    }
    return call(fn, {data});
}
Variant session_encode() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1659]);
    }
    return call(fn, {});
}
Variant session_destroy() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1660]);
    }
    return call(fn, {});
}
Variant session_unset() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1661]);
    }
    return call(fn, {});
}
Variant session_gc() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1662]);
    }
    return call(fn, {});
}
Variant session_get_cookie_params() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1663]);
    }
    return call(fn, {});
}
Variant session_write_close() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1664]);
    }
    return call(fn, {});
}
Variant session_abort() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1665]);
    }
    return call(fn, {});
}
Variant session_reset() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1666]);
    }
    return call(fn, {});
}
Variant session_status() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1667]);
    }
    return call(fn, {});
}
Variant session_register_shutdown() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1668]);
    }
    return call(fn, {});
}
Variant session_commit() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1669]);
    }
    return call(fn, {});
}
Variant session_set_save_handler(const Variant &open,
                                 const Variant &close,
                                 const Variant &read,
                                 const Variant &write,
                                 const Variant &destroy,
                                 const Variant &gc,
                                 const Variant &create_sid,
                                 const Variant &validate_sid,
                                 const Variant &update_timestamp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1670]);
    }
    return call(fn, {open, close, read, write, destroy, gc, create_sid, validate_sid, update_timestamp});
}
Variant session_cache_limiter(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1671]);
    }
    return call(fn, {value});
}
Variant session_cache_expire(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1672]);
    }
    return call(fn, {value});
}
Variant session_set_cookie_params(const Variant &lifetime_or_options,
                                  const Variant &path,
                                  const Variant &domain,
                                  const Variant &secure,
                                  const Variant &httponly) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1673]);
    }
    return call(fn, {lifetime_or_options, path, domain, secure, httponly});
}
Variant session_start(const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1674]);
    }
    return call(fn, {options});
}
}  // namespace php

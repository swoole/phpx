#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant session_name(const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1818]);
    }
    return call(fn, {name});
}
Variant session_module_name(const Variant &module) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1819]);
    }
    return call(fn, {module});
}
Variant session_save_path(const Variant &path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1820]);
    }
    return call(fn, {path});
}
Variant session_id(const Variant &id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1821]);
    }
    return call(fn, {id});
}
Variant session_create_id(const Variant &prefix) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1822]);
    }
    return call(fn, {prefix});
}
Variant session_regenerate_id(const Variant &delete_old_session) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1823]);
    }
    return call(fn, {delete_old_session});
}
Variant session_decode(const Variant &data) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1824]);
    }
    return call(fn, {data});
}
Variant session_encode() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1825]);
    }
    return call(fn, {});
}
Variant session_destroy() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1826]);
    }
    return call(fn, {});
}
Variant session_unset() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1827]);
    }
    return call(fn, {});
}
Variant session_gc() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1828]);
    }
    return call(fn, {});
}
Variant session_get_cookie_params() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1829]);
    }
    return call(fn, {});
}
Variant session_write_close() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1830]);
    }
    return call(fn, {});
}
Variant session_abort() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1831]);
    }
    return call(fn, {});
}
Variant session_reset() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1832]);
    }
    return call(fn, {});
}
Variant session_status() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1833]);
    }
    return call(fn, {});
}
Variant session_register_shutdown() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1834]);
    }
    return call(fn, {});
}
Variant session_commit() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1835]);
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
        fn = getFunction(LITERAL_STRING[1836]);
    }
    return call(fn, {open, close, read, write, destroy, gc, create_sid, validate_sid, update_timestamp});
}
Variant session_cache_limiter(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1837]);
    }
    return call(fn, {value});
}
Variant session_cache_expire(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1838]);
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
        fn = getFunction(LITERAL_STRING[1839]);
    }
    return call(fn, {lifetime_or_options, path, domain, secure, httponly});
}
Variant session_start(const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1840]);
    }
    return call(fn, {options});
}
}  // namespace php

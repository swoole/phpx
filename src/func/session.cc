#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant session_name(const Variant &name) {
    return call(LITERAL_STRING[1592], {name});
}
Variant session_module_name(const Variant &module) {
    return call(LITERAL_STRING[1593], {module});
}
Variant session_save_path(const Variant &path) {
    return call(LITERAL_STRING[1594], {path});
}
Variant session_id(const Variant &id) {
    return call(LITERAL_STRING[1595], {id});
}
Variant session_create_id(const Variant &prefix) {
    return call(LITERAL_STRING[1596], {prefix});
}
Variant session_regenerate_id(const Variant &delete_old_session) {
    return call(LITERAL_STRING[1597], {delete_old_session});
}
Variant session_decode(const Variant &data) {
    return call(LITERAL_STRING[1598], {data});
}
Variant session_encode() {
    return call(LITERAL_STRING[1599], {});
}
Variant session_destroy() {
    return call(LITERAL_STRING[1600], {});
}
Variant session_unset() {
    return call(LITERAL_STRING[1601], {});
}
Variant session_gc() {
    return call(LITERAL_STRING[1602], {});
}
Variant session_get_cookie_params() {
    return call(LITERAL_STRING[1603], {});
}
Variant session_write_close() {
    return call(LITERAL_STRING[1604], {});
}
Variant session_abort() {
    return call(LITERAL_STRING[1605], {});
}
Variant session_reset() {
    return call(LITERAL_STRING[1606], {});
}
Variant session_status() {
    return call(LITERAL_STRING[1607], {});
}
Variant session_register_shutdown() {
    return call(LITERAL_STRING[1608], {});
}
Variant session_commit() {
    return call(LITERAL_STRING[1609], {});
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
    return call(LITERAL_STRING[1610],
                {open, close, read, write, destroy, gc, create_sid, validate_sid, update_timestamp});
}
Variant session_cache_limiter(const Variant &value) {
    return call(LITERAL_STRING[1611], {value});
}
Variant session_cache_expire(const Variant &value) {
    return call(LITERAL_STRING[1612], {value});
}
Variant session_set_cookie_params(const Variant &lifetime_or_options,
                                  const Variant &path,
                                  const Variant &domain,
                                  const Variant &secure,
                                  const Variant &httponly) {
    return call(LITERAL_STRING[1613], {lifetime_or_options, path, domain, secure, httponly});
}
Variant session_start(const Variant &options) {
    return call(LITERAL_STRING[1614], {options});
}
}  // namespace php

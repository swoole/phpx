#include "phpx.h"

namespace php {
Variant session_name(const Variant &name) {
    return call("session_name", {name});
}
Variant session_module_name(const Variant &module) {
    return call("session_module_name", {module});
}
Variant session_save_path(const Variant &path) {
    return call("session_save_path", {path});
}
Variant session_id(const Variant &id) {
    return call("session_id", {id});
}
Variant session_create_id(const Variant &prefix) {
    return call("session_create_id", {prefix});
}
Variant session_regenerate_id(const Variant &delete_old_session) {
    return call("session_regenerate_id", {delete_old_session});
}
Variant session_decode(const Variant &data) {
    return call("session_decode", {data});
}
Variant session_encode() {
    return call("session_encode", {});
}
Variant session_destroy() {
    return call("session_destroy", {});
}
Variant session_unset() {
    return call("session_unset", {});
}
Variant session_gc() {
    return call("session_gc", {});
}
Variant session_get_cookie_params() {
    return call("session_get_cookie_params", {});
}
Variant session_write_close() {
    return call("session_write_close", {});
}
Variant session_abort() {
    return call("session_abort", {});
}
Variant session_reset() {
    return call("session_reset", {});
}
Variant session_status() {
    return call("session_status", {});
}
Variant session_register_shutdown() {
    return call("session_register_shutdown", {});
}
Variant session_commit() {
    return call("session_commit", {});
}
Variant session_set_save_handler(const Variant &open, const Variant &close, const Variant &read, const Variant &write, const Variant &destroy, const Variant &gc, const Variant &create_sid, const Variant &validate_sid, const Variant &update_timestamp) {
    return call("session_set_save_handler", {open, close, read, write, destroy, gc, create_sid, validate_sid, update_timestamp});
}
Variant session_cache_limiter(const Variant &value) {
    return call("session_cache_limiter", {value});
}
Variant session_cache_expire(const Variant &value) {
    return call("session_cache_expire", {value});
}
Variant session_set_cookie_params(const Variant &lifetime_or_options, const Variant &path, const Variant &domain, const Variant &secure, const Variant &httponly) {
    return call("session_set_cookie_params", {lifetime_or_options, path, domain, secure, httponly});
}
Variant session_start(const Variant &options) {
    return call("session_start", {options});
}
}

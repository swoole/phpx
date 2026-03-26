#include "phpx.h"

namespace php {
Variant curl_close(const Variant &handle) {
    return call("curl_close", {handle});
}
Variant curl_copy_handle(const Variant &handle) {
    return call("curl_copy_handle", {handle});
}
Variant curl_errno(const Variant &handle) {
    return call("curl_errno", {handle});
}
Variant curl_error(const Variant &handle) {
    return call("curl_error", {handle});
}
Variant curl_escape(const Variant &handle, const Variant &string) {
    return call("curl_escape", {handle, string});
}
Variant curl_unescape(const Variant &handle, const Variant &string) {
    return call("curl_unescape", {handle, string});
}
Variant curl_multi_setopt(const Variant &multi_handle, const Variant &option, const Variant &value) {
    return call("curl_multi_setopt", {multi_handle, option, value});
}
Variant curl_exec(const Variant &handle) {
    return call("curl_exec", {handle});
}
Variant curl_file_create(const Variant &filename, const Variant &mime_type, const Variant &posted_filename) {
    return call("curl_file_create", {filename, mime_type, posted_filename});
}
Variant curl_getinfo(const Variant &handle, const Variant &option) {
    return call("curl_getinfo", {handle, option});
}
Variant curl_init(const Variant &url) {
    return call("curl_init", {url});
}
Variant curl_upkeep(const Variant &handle) {
    return call("curl_upkeep", {handle});
}
Variant curl_multi_add_handle(const Variant &multi_handle, const Variant &handle) {
    return call("curl_multi_add_handle", {multi_handle, handle});
}
Variant curl_multi_close(const Variant &multi_handle) {
    return call("curl_multi_close", {multi_handle});
}
Variant curl_multi_errno(const Variant &multi_handle) {
    return call("curl_multi_errno", {multi_handle});
}
Variant curl_multi_exec(const Variant &multi_handle, const Reference &still_running) {
    return call("curl_multi_exec", {multi_handle, &still_running});
}
Variant curl_multi_getcontent(const Variant &handle) {
    return call("curl_multi_getcontent", {handle});
}
Variant curl_multi_info_read(const Variant &multi_handle, const Reference &queued_messages) {
    return call("curl_multi_info_read", {multi_handle, &queued_messages});
}
Variant curl_multi_init() {
    return call("curl_multi_init", {});
}
Variant curl_multi_remove_handle(const Variant &multi_handle, const Variant &handle) {
    return call("curl_multi_remove_handle", {multi_handle, handle});
}
Variant curl_multi_select(const Variant &multi_handle, const Variant &timeout) {
    return call("curl_multi_select", {multi_handle, timeout});
}
Variant curl_multi_strerror(const Variant &error_code) {
    return call("curl_multi_strerror", {error_code});
}
Variant curl_pause(const Variant &handle, const Variant &flags) {
    return call("curl_pause", {handle, flags});
}
Variant curl_reset(const Variant &handle) {
    return call("curl_reset", {handle});
}
Variant curl_setopt_array(const Variant &handle, const Variant &options) {
    return call("curl_setopt_array", {handle, options});
}
Variant curl_setopt(const Variant &handle, const Variant &option, const Variant &value) {
    return call("curl_setopt", {handle, option, value});
}
Variant curl_share_close(const Variant &share_handle) {
    return call("curl_share_close", {share_handle});
}
Variant curl_share_errno(const Variant &share_handle) {
    return call("curl_share_errno", {share_handle});
}
Variant curl_share_init() {
    return call("curl_share_init", {});
}
Variant curl_share_setopt(const Variant &share_handle, const Variant &option, const Variant &value) {
    return call("curl_share_setopt", {share_handle, option, value});
}
Variant curl_share_strerror(const Variant &error_code) {
    return call("curl_share_strerror", {error_code});
}
Variant curl_strerror(const Variant &error_code) {
    return call("curl_strerror", {error_code});
}
Variant curl_version() {
    return call("curl_version", {});
}
}

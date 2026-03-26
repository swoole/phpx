#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant curl_close(const Variant &handle) {
    return call(LITERAL_STRING[168], {handle});
}
Variant curl_copy_handle(const Variant &handle) {
    return call(LITERAL_STRING[169], {handle});
}
Variant curl_errno(const Variant &handle) {
    return call(LITERAL_STRING[170], {handle});
}
Variant curl_error(const Variant &handle) {
    return call(LITERAL_STRING[171], {handle});
}
Variant curl_escape(const Variant &handle, const Variant &string) {
    return call(LITERAL_STRING[172], {handle, string});
}
Variant curl_unescape(const Variant &handle, const Variant &string) {
    return call(LITERAL_STRING[173], {handle, string});
}
Variant curl_multi_setopt(const Variant &multi_handle, const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[174], {multi_handle, option, value});
}
Variant curl_exec(const Variant &handle) {
    return call(LITERAL_STRING[175], {handle});
}
Variant curl_file_create(const Variant &filename, const Variant &mime_type, const Variant &posted_filename) {
    return call(LITERAL_STRING[176], {filename, mime_type, posted_filename});
}
Variant curl_getinfo(const Variant &handle, const Variant &option) {
    return call(LITERAL_STRING[177], {handle, option});
}
Variant curl_init(const Variant &url) {
    return call(LITERAL_STRING[178], {url});
}
Variant curl_upkeep(const Variant &handle) {
    return call(LITERAL_STRING[179], {handle});
}
Variant curl_multi_add_handle(const Variant &multi_handle, const Variant &handle) {
    return call(LITERAL_STRING[180], {multi_handle, handle});
}
Variant curl_multi_close(const Variant &multi_handle) {
    return call(LITERAL_STRING[181], {multi_handle});
}
Variant curl_multi_errno(const Variant &multi_handle) {
    return call(LITERAL_STRING[182], {multi_handle});
}
Variant curl_multi_exec(const Variant &multi_handle, const Reference &still_running) {
    return call(LITERAL_STRING[183], {multi_handle, &still_running});
}
Variant curl_multi_getcontent(const Variant &handle) {
    return call(LITERAL_STRING[184], {handle});
}
Variant curl_multi_info_read(const Variant &multi_handle, const Reference &queued_messages) {
    return call(LITERAL_STRING[185], {multi_handle, &queued_messages});
}
Variant curl_multi_init() {
    return call(LITERAL_STRING[186], {});
}
Variant curl_multi_remove_handle(const Variant &multi_handle, const Variant &handle) {
    return call(LITERAL_STRING[187], {multi_handle, handle});
}
Variant curl_multi_select(const Variant &multi_handle, const Variant &timeout) {
    return call(LITERAL_STRING[188], {multi_handle, timeout});
}
Variant curl_multi_strerror(const Variant &error_code) {
    return call(LITERAL_STRING[189], {error_code});
}
Variant curl_pause(const Variant &handle, const Variant &flags) {
    return call(LITERAL_STRING[190], {handle, flags});
}
Variant curl_reset(const Variant &handle) {
    return call(LITERAL_STRING[191], {handle});
}
Variant curl_setopt_array(const Variant &handle, const Variant &options) {
    return call(LITERAL_STRING[192], {handle, options});
}
Variant curl_setopt(const Variant &handle, const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[193], {handle, option, value});
}
Variant curl_share_close(const Variant &share_handle) {
    return call(LITERAL_STRING[194], {share_handle});
}
Variant curl_share_errno(const Variant &share_handle) {
    return call(LITERAL_STRING[195], {share_handle});
}
Variant curl_share_init() {
    return call(LITERAL_STRING[196], {});
}
Variant curl_share_setopt(const Variant &share_handle, const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[197], {share_handle, option, value});
}
Variant curl_share_strerror(const Variant &error_code) {
    return call(LITERAL_STRING[198], {error_code});
}
Variant curl_strerror(const Variant &error_code) {
    return call(LITERAL_STRING[199], {error_code});
}
Variant curl_version() {
    return call(LITERAL_STRING[200], {});
}
}  // namespace php

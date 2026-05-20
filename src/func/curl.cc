#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant curl_close(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[174]);
    }
    return call(fn, {handle});
}
Variant curl_copy_handle(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[175]);
    }
    return call(fn, {handle});
}
Variant curl_errno(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[176]);
    }
    return call(fn, {handle});
}
Variant curl_error(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[177]);
    }
    return call(fn, {handle});
}
Variant curl_escape(const Variant &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[178]);
    }
    return call(fn, {handle, string});
}
Variant curl_unescape(const Variant &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[179]);
    }
    return call(fn, {handle, string});
}
Variant curl_multi_setopt(const Variant &multi_handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[180]);
    }
    return call(fn, {multi_handle, option, value});
}
Variant curl_exec(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[181]);
    }
    return call(fn, {handle});
}
Variant curl_file_create(const Variant &filename, const Variant &mime_type, const Variant &posted_filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[182]);
    }
    return call(fn, {filename, mime_type, posted_filename});
}
Variant curl_getinfo(const Variant &handle, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[183]);
    }
    return call(fn, {handle, option});
}
Variant curl_init(const Variant &url) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[184]);
    }
    return call(fn, {url});
}
Variant curl_upkeep(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[185]);
    }
    return call(fn, {handle});
}
Variant curl_multi_add_handle(const Variant &multi_handle, const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[186]);
    }
    return call(fn, {multi_handle, handle});
}
Variant curl_multi_close(const Variant &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[187]);
    }
    return call(fn, {multi_handle});
}
Variant curl_multi_errno(const Variant &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[188]);
    }
    return call(fn, {multi_handle});
}
Variant curl_multi_exec(const Variant &multi_handle, const Reference &still_running) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[189]);
    }
    return call(fn, {multi_handle, &still_running});
}
Variant curl_multi_getcontent(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[190]);
    }
    return call(fn, {handle});
}
Variant curl_multi_info_read(const Variant &multi_handle, const Reference &queued_messages) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[191]);
    }
    return call(fn, {multi_handle, &queued_messages});
}
Variant curl_multi_init() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[192]);
    }
    return call(fn, {});
}
Variant curl_multi_remove_handle(const Variant &multi_handle, const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[193]);
    }
    return call(fn, {multi_handle, handle});
}
Variant curl_multi_select(const Variant &multi_handle, const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[194]);
    }
    return call(fn, {multi_handle, timeout});
}
Variant curl_multi_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[195]);
    }
    return call(fn, {error_code});
}
Variant curl_pause(const Variant &handle, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[196]);
    }
    return call(fn, {handle, flags});
}
Variant curl_reset(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[197]);
    }
    return call(fn, {handle});
}
Variant curl_setopt_array(const Variant &handle, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[198]);
    }
    return call(fn, {handle, options});
}
Variant curl_setopt(const Variant &handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[199]);
    }
    return call(fn, {handle, option, value});
}
Variant curl_share_close(const Variant &share_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[200]);
    }
    return call(fn, {share_handle});
}
Variant curl_share_errno(const Variant &share_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[201]);
    }
    return call(fn, {share_handle});
}
Variant curl_share_init() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[202]);
    }
    return call(fn, {});
}
Variant curl_share_setopt(const Variant &share_handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[203]);
    }
    return call(fn, {share_handle, option, value});
}
Variant curl_share_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[204]);
    }
    return call(fn, {error_code});
}
Variant curl_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[205]);
    }
    return call(fn, {error_code});
}
Variant curl_version() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[206]);
    }
    return call(fn, {});
}
}  // namespace php

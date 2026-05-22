#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant curl_close(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[202]);
    }
    return call(fn, {handle.getObject()});
}
Variant curl_close(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[202]);
    }
    return call(fn, {handle});
}
CurlHandle curl_copy_handle(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[203]);
    }
    auto _rv = call(fn, {handle.getObject()});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "curl_copy_handle() returned false");
    }
    return CurlHandle(Object(std::move(_rv)));
}
Variant curl_copy_handle(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[203]);
    }
    return call(fn, {handle});
}
Variant curl_errno(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[204]);
    }
    return call(fn, {handle.getObject()});
}
Variant curl_errno(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[204]);
    }
    return call(fn, {handle});
}
Variant curl_error(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[205]);
    }
    return call(fn, {handle.getObject()});
}
Variant curl_error(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[205]);
    }
    return call(fn, {handle});
}
Variant curl_escape(const CurlHandle &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[206]);
    }
    return call(fn, {handle.getObject(), string});
}
Variant curl_escape(const Variant &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[206]);
    }
    return call(fn, {handle, string});
}
Variant curl_unescape(const CurlHandle &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[207]);
    }
    return call(fn, {handle.getObject(), string});
}
Variant curl_unescape(const Variant &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[207]);
    }
    return call(fn, {handle, string});
}
Variant curl_multi_setopt(const CurlMultiHandle &multi_handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[208]);
    }
    return call(fn, {multi_handle.getObject(), option, value});
}
Variant curl_multi_setopt(const Variant &multi_handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[208]);
    }
    return call(fn, {multi_handle, option, value});
}
Variant curl_exec(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[209]);
    }
    return call(fn, {handle.getObject()});
}
Variant curl_exec(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[209]);
    }
    return call(fn, {handle});
}
Variant curl_file_create(const Variant &filename, const Variant &mime_type, const Variant &posted_filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[210]);
    }
    return call(fn, {filename, mime_type, posted_filename});
}
Variant curl_getinfo(const CurlHandle &handle, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[211]);
    }
    return call(fn, {handle.getObject(), option});
}
Variant curl_getinfo(const Variant &handle, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[211]);
    }
    return call(fn, {handle, option});
}
CurlHandle curl_init(const Variant &url) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[212]);
    }
    auto _rv = call(fn, {url});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "curl_init() returned false");
    }
    return CurlHandle(Object(std::move(_rv)));
}
Variant curl_upkeep(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[213]);
    }
    return call(fn, {handle.getObject()});
}
Variant curl_upkeep(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[213]);
    }
    return call(fn, {handle});
}
Variant curl_multi_add_handle(const CurlMultiHandle &multi_handle, const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[214]);
    }
    return call(fn, {multi_handle.getObject(), handle.getObject()});
}
Variant curl_multi_add_handle(const Variant &multi_handle, const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[214]);
    }
    return call(fn, {multi_handle, handle});
}
Variant curl_multi_close(const CurlMultiHandle &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[215]);
    }
    return call(fn, {multi_handle.getObject()});
}
Variant curl_multi_close(const Variant &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[215]);
    }
    return call(fn, {multi_handle});
}
Variant curl_multi_errno(const CurlMultiHandle &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[216]);
    }
    return call(fn, {multi_handle.getObject()});
}
Variant curl_multi_errno(const Variant &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[216]);
    }
    return call(fn, {multi_handle});
}
Variant curl_multi_exec(const CurlMultiHandle &multi_handle, const Reference &still_running) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[217]);
    }
    return call(fn, {multi_handle.getObject(), &still_running});
}
Variant curl_multi_exec(const Variant &multi_handle, const Reference &still_running) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[217]);
    }
    return call(fn, {multi_handle, &still_running});
}
Variant curl_multi_getcontent(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[218]);
    }
    return call(fn, {handle.getObject()});
}
Variant curl_multi_getcontent(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[218]);
    }
    return call(fn, {handle});
}
Variant curl_multi_info_read(const CurlMultiHandle &multi_handle, const Reference &queued_messages) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[219]);
    }
    return call(fn, {multi_handle.getObject(), &queued_messages});
}
Variant curl_multi_info_read(const Variant &multi_handle, const Reference &queued_messages) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[219]);
    }
    return call(fn, {multi_handle, &queued_messages});
}
CurlMultiHandle curl_multi_init() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[220]);
    }
    return CurlMultiHandle(Object(call(fn, {})));
}
Variant curl_multi_remove_handle(const CurlMultiHandle &multi_handle, const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[221]);
    }
    return call(fn, {multi_handle.getObject(), handle.getObject()});
}
Variant curl_multi_remove_handle(const Variant &multi_handle, const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[221]);
    }
    return call(fn, {multi_handle, handle});
}
Variant curl_multi_select(const CurlMultiHandle &multi_handle, const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[222]);
    }
    return call(fn, {multi_handle.getObject(), timeout});
}
Variant curl_multi_select(const Variant &multi_handle, const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[222]);
    }
    return call(fn, {multi_handle, timeout});
}
Variant curl_multi_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[223]);
    }
    return call(fn, {error_code});
}
Variant curl_pause(const CurlHandle &handle, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[224]);
    }
    return call(fn, {handle.getObject(), flags});
}
Variant curl_pause(const Variant &handle, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[224]);
    }
    return call(fn, {handle, flags});
}
Variant curl_reset(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[225]);
    }
    return call(fn, {handle.getObject()});
}
Variant curl_reset(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[225]);
    }
    return call(fn, {handle});
}
Variant curl_setopt_array(const CurlHandle &handle, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[226]);
    }
    return call(fn, {handle.getObject(), options});
}
Variant curl_setopt_array(const Variant &handle, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[226]);
    }
    return call(fn, {handle, options});
}
Variant curl_setopt(const CurlHandle &handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[227]);
    }
    return call(fn, {handle.getObject(), option, value});
}
Variant curl_setopt(const Variant &handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[227]);
    }
    return call(fn, {handle, option, value});
}
Variant curl_share_close(const CurlShareHandle &share_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[228]);
    }
    return call(fn, {share_handle.getObject()});
}
Variant curl_share_close(const Variant &share_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[228]);
    }
    return call(fn, {share_handle});
}
Variant curl_share_errno(const CurlShareHandle &share_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[229]);
    }
    return call(fn, {share_handle.getObject()});
}
Variant curl_share_errno(const Variant &share_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[229]);
    }
    return call(fn, {share_handle});
}
CurlShareHandle curl_share_init() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[230]);
    }
    return CurlShareHandle(Object(call(fn, {})));
}
Variant curl_share_setopt(const CurlShareHandle &share_handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[231]);
    }
    return call(fn, {share_handle.getObject(), option, value});
}
Variant curl_share_setopt(const Variant &share_handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[231]);
    }
    return call(fn, {share_handle, option, value});
}
Variant curl_share_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[232]);
    }
    return call(fn, {error_code});
}
Variant curl_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[233]);
    }
    return call(fn, {error_code});
}
Variant curl_version() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[234]);
    }
    return call(fn, {});
}
}  // namespace php

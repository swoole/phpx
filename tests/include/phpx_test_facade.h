#pragma once

#include "phpx.h"

// A deliberately small, test-only facade. PHPX no longer exposes generated
// wrappers for PHP functions and classes as part of its public API. These
// helpers keep the core tests readable while exercising the public call API.
// This header is only added to the phpx-tests target and is never installed.
namespace php {

template <typename... Values>
inline Variant array_push(const Reference &array, const Values &...values) {
    return call("array_push", {array, values...});
}

inline Variant array_flip(const Variant &array) {
    return call("array_flip", {array});
}

inline Variant class_exists(const Variant &class_name, const Variant &autoload = true) {
    return call("class_exists", {class_name, autoload});
}

inline Variant define(const Variant &name, const Variant &value, const Variant &case_insensitive = false) {
    return call("define", {name, value, case_insensitive});
}

inline Variant file_put_contents(const Variant &filename,
                                 const Variant &data,
                                 const Variant &flags = 0,
                                 const Variant &context = nullptr) {
    return call("file_put_contents", {filename, data, flags, context});
}

inline Variant fmod(const Variant &num1, const Variant &num2) {
    return call("fmod", {num1, num2});
}

inline Variant fopen(const Variant &filename,
                     const Variant &mode,
                     const Variant &use_include_path = false,
                     const Variant &context = nullptr) {
    return call("fopen", {filename, mode, use_include_path, context});
}

inline Variant hash(const Variant &algorithm,
                    const Variant &data,
                    const Variant &binary = false,
                    const Variant &options = Array{}) {
    return call("hash", {algorithm, data, binary, options});
}

inline Variant http_build_query(const Variant &data,
                                const Variant &numeric_prefix = "",
                                const Variant &arg_separator = nullptr,
                                const Variant &encoding_type = 1) {
    return call("http_build_query", {data, numeric_prefix, arg_separator, encoding_type});
}

inline Variant in_array(const Variant &needle, const Variant &haystack, const Variant &strict = false) {
    return call("in_array", {needle, haystack, strict});
}

inline Variant ini_get(const Variant &option) {
    return call("ini_get", {option});
}

inline Variant is_dir(const Variant &filename) {
    return call("is_dir", {filename});
}

inline Variant json_decode(const Variant &json,
                           const Variant &associative = nullptr,
                           const Variant &depth = 512,
                           const Variant &flags = 0) {
    return call("json_decode", {json, associative, depth, flags});
}

inline Variant json_encode(const Variant &value, const Variant &flags = 0, const Variant &depth = 512) {
    return call("json_encode", {value, flags, depth});
}

inline Variant json_last_error() {
    return call("json_last_error");
}

inline Variant md5(const Variant &string, const Variant &binary = false) {
    return call("md5", {string, binary});
}

inline Variant ob_get_clean() {
    return call("ob_get_clean");
}

inline Variant ob_start(const Variant &callback = nullptr, const Variant &chunk_size = 0, const Variant &flags = 112) {
    return call("ob_start", {callback, chunk_size, flags});
}

inline Variant parse_str(const Variant &string, const Reference &result) {
    return call("parse_str", {string, result});
}

inline Variant random_bytes(const Variant &length) {
    return call("random_bytes", {length});
}

inline Variant random_int(const Variant &min, const Variant &max) {
    return call("random_int", {min, max});
}

inline Variant sha1(const Variant &string, const Variant &binary = false) {
    return call("sha1", {string, binary});
}

inline Variant sort(const Reference &array, const Variant &flags = 0) {
    return call("sort", {array, flags});
}

inline Variant str_contains(const Variant &haystack, const Variant &needle) {
    return call("str_contains", {haystack, needle});
}

template <typename... Values>
inline Variant var_dump(const Variant &value, const Values &...values) {
    return call("var_dump", {value, values...});
}

inline Variant curl_init(const Variant &url = nullptr) {
    return call("curl_init", {url});
}

inline Variant curl_setopt(const Variant &handle, const Variant &option, const Variant &value) {
    return call("curl_setopt", {handle, option, value});
}

inline Variant curl_exec(const Variant &handle) {
    return call("curl_exec", {handle});
}

inline Variant curl_close(const Variant &handle) {
    return call("curl_close", {handle});
}

}  // namespace php

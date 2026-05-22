#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant iconv_strlen(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[653]);
    }
    return call(fn, {string, encoding});
}
Variant iconv_substr(const Variant &string, const Variant &offset, const Variant &length, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[654]);
    }
    return call(fn, {string, offset, length, encoding});
}
Variant iconv_strpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[655]);
    }
    return call(fn, {haystack, needle, offset, encoding});
}
Variant iconv_strrpos(const Variant &haystack, const Variant &needle, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[656]);
    }
    return call(fn, {haystack, needle, encoding});
}
Variant iconv_mime_encode(const Variant &field_name, const Variant &field_value, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[657]);
    }
    return call(fn, {field_name, field_value, options});
}
Variant iconv_mime_decode(const Variant &string, const Variant &mode, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[658]);
    }
    return call(fn, {string, mode, encoding});
}
Variant iconv_mime_decode_headers(const Variant &headers, const Variant &mode, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[659]);
    }
    return call(fn, {headers, mode, encoding});
}
Variant iconv(const Variant &from_encoding, const Variant &to_encoding, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[660]);
    }
    return call(fn, {from_encoding, to_encoding, string});
}
Variant iconv_set_encoding(const Variant &type, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[661]);
    }
    return call(fn, {type, encoding});
}
Variant iconv_get_encoding(const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[662]);
    }
    return call(fn, {type});
}
}  // namespace php

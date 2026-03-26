#include "phpx.h"

namespace php {
Variant iconv_strlen(const Variant &string, const Variant &encoding) {
    return call("iconv_strlen", {string, encoding});
}
Variant iconv_substr(const Variant &string, const Variant &offset, const Variant &length, const Variant &encoding) {
    return call("iconv_substr", {string, offset, length, encoding});
}
Variant iconv_strpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call("iconv_strpos", {haystack, needle, offset, encoding});
}
Variant iconv_strrpos(const Variant &haystack, const Variant &needle, const Variant &encoding) {
    return call("iconv_strrpos", {haystack, needle, encoding});
}
Variant iconv_mime_encode(const Variant &field_name, const Variant &field_value, const Variant &options) {
    return call("iconv_mime_encode", {field_name, field_value, options});
}
Variant iconv_mime_decode(const Variant &string, const Variant &mode, const Variant &encoding) {
    return call("iconv_mime_decode", {string, mode, encoding});
}
Variant iconv_mime_decode_headers(const Variant &headers, const Variant &mode, const Variant &encoding) {
    return call("iconv_mime_decode_headers", {headers, mode, encoding});
}
Variant iconv(const Variant &from_encoding, const Variant &to_encoding, const Variant &string) {
    return call("iconv", {from_encoding, to_encoding, string});
}
Variant iconv_set_encoding(const Variant &type, const Variant &encoding) {
    return call("iconv_set_encoding", {type, encoding});
}
Variant iconv_get_encoding(const Variant &type) {
    return call("iconv_get_encoding", {type});
}
}

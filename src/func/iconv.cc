#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant iconv_strlen(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[624], {string, encoding});
}
Variant iconv_substr(const Variant &string, const Variant &offset, const Variant &length, const Variant &encoding) {
    return call(LITERAL_STRING[625], {string, offset, length, encoding});
}
Variant iconv_strpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call(LITERAL_STRING[626], {haystack, needle, offset, encoding});
}
Variant iconv_strrpos(const Variant &haystack, const Variant &needle, const Variant &encoding) {
    return call(LITERAL_STRING[627], {haystack, needle, encoding});
}
Variant iconv_mime_encode(const Variant &field_name, const Variant &field_value, const Variant &options) {
    return call(LITERAL_STRING[628], {field_name, field_value, options});
}
Variant iconv_mime_decode(const Variant &string, const Variant &mode, const Variant &encoding) {
    return call(LITERAL_STRING[629], {string, mode, encoding});
}
Variant iconv_mime_decode_headers(const Variant &headers, const Variant &mode, const Variant &encoding) {
    return call(LITERAL_STRING[630], {headers, mode, encoding});
}
Variant iconv(const Variant &from_encoding, const Variant &to_encoding, const Variant &string) {
    return call(LITERAL_STRING[631], {from_encoding, to_encoding, string});
}
Variant iconv_set_encoding(const Variant &type, const Variant &encoding) {
    return call(LITERAL_STRING[632], {type, encoding});
}
Variant iconv_get_encoding(const Variant &type) {
    return call(LITERAL_STRING[633], {type});
}
}  // namespace php

#include "phpx.h"

namespace php {
Variant mb_language(const Variant &language) {
    return call("mb_language", {language});
}
Variant mb_internal_encoding(const Variant &encoding) {
    return call("mb_internal_encoding", {encoding});
}
Variant mb_http_input(const Variant &type) {
    return call("mb_http_input", {type});
}
Variant mb_http_output(const Variant &encoding) {
    return call("mb_http_output", {encoding});
}
Variant mb_detect_order(const Variant &encoding) {
    return call("mb_detect_order", {encoding});
}
Variant mb_substitute_character(const Variant &substitute_character) {
    return call("mb_substitute_character", {substitute_character});
}
Variant mb_preferred_mime_name(const Variant &encoding) {
    return call("mb_preferred_mime_name", {encoding});
}
Variant mb_parse_str(const Variant &string, const Reference &result) {
    return call("mb_parse_str", {string, &result});
}
Variant mb_output_handler(const Variant &string, const Variant &status) {
    return call("mb_output_handler", {string, status});
}
Variant mb_str_split(const Variant &string, const Variant &length, const Variant &encoding) {
    return call("mb_str_split", {string, length, encoding});
}
Variant mb_strlen(const Variant &string, const Variant &encoding) {
    return call("mb_strlen", {string, encoding});
}
Variant mb_strpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call("mb_strpos", {haystack, needle, offset, encoding});
}
Variant mb_strrpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call("mb_strrpos", {haystack, needle, offset, encoding});
}
Variant mb_stripos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call("mb_stripos", {haystack, needle, offset, encoding});
}
Variant mb_strripos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call("mb_strripos", {haystack, needle, offset, encoding});
}
Variant mb_strstr(const Variant &haystack, const Variant &needle, const Variant &before_needle, const Variant &encoding) {
    return call("mb_strstr", {haystack, needle, before_needle, encoding});
}
Variant mb_strrchr(const Variant &haystack, const Variant &needle, const Variant &before_needle, const Variant &encoding) {
    return call("mb_strrchr", {haystack, needle, before_needle, encoding});
}
Variant mb_stristr(const Variant &haystack, const Variant &needle, const Variant &before_needle, const Variant &encoding) {
    return call("mb_stristr", {haystack, needle, before_needle, encoding});
}
Variant mb_strrichr(const Variant &haystack, const Variant &needle, const Variant &before_needle, const Variant &encoding) {
    return call("mb_strrichr", {haystack, needle, before_needle, encoding});
}
Variant mb_substr_count(const Variant &haystack, const Variant &needle, const Variant &encoding) {
    return call("mb_substr_count", {haystack, needle, encoding});
}
Variant mb_substr(const Variant &string, const Variant &start, const Variant &length, const Variant &encoding) {
    return call("mb_substr", {string, start, length, encoding});
}
Variant mb_strcut(const Variant &string, const Variant &start, const Variant &length, const Variant &encoding) {
    return call("mb_strcut", {string, start, length, encoding});
}
Variant mb_strwidth(const Variant &string, const Variant &encoding) {
    return call("mb_strwidth", {string, encoding});
}
Variant mb_strimwidth(const Variant &string, const Variant &start, const Variant &width, const Variant &trim_marker, const Variant &encoding) {
    return call("mb_strimwidth", {string, start, width, trim_marker, encoding});
}
Variant mb_convert_encoding(const Variant &string, const Variant &to_encoding, const Variant &from_encoding) {
    return call("mb_convert_encoding", {string, to_encoding, from_encoding});
}
Variant mb_convert_case(const Variant &string, const Variant &mode, const Variant &encoding) {
    return call("mb_convert_case", {string, mode, encoding});
}
Variant mb_strtoupper(const Variant &string, const Variant &encoding) {
    return call("mb_strtoupper", {string, encoding});
}
Variant mb_strtolower(const Variant &string, const Variant &encoding) {
    return call("mb_strtolower", {string, encoding});
}
Variant mb_ucfirst(const Variant &string, const Variant &encoding) {
    return call("mb_ucfirst", {string, encoding});
}
Variant mb_lcfirst(const Variant &string, const Variant &encoding) {
    return call("mb_lcfirst", {string, encoding});
}
Variant mb_trim(const Variant &string, const Variant &characters, const Variant &encoding) {
    return call("mb_trim", {string, characters, encoding});
}
Variant mb_ltrim(const Variant &string, const Variant &characters, const Variant &encoding) {
    return call("mb_ltrim", {string, characters, encoding});
}
Variant mb_rtrim(const Variant &string, const Variant &characters, const Variant &encoding) {
    return call("mb_rtrim", {string, characters, encoding});
}
Variant mb_detect_encoding(const Variant &string, const Variant &encodings, const Variant &strict) {
    return call("mb_detect_encoding", {string, encodings, strict});
}
Variant mb_list_encodings() {
    return call("mb_list_encodings", {});
}
Variant mb_encoding_aliases(const Variant &encoding) {
    return call("mb_encoding_aliases", {encoding});
}
Variant mb_encode_mimeheader(const Variant &string, const Variant &charset, const Variant &transfer_encoding, const Variant &newline, const Variant &indent) {
    return call("mb_encode_mimeheader", {string, charset, transfer_encoding, newline, indent});
}
Variant mb_decode_mimeheader(const Variant &string) {
    return call("mb_decode_mimeheader", {string});
}
Variant mb_convert_kana(const Variant &string, const Variant &mode, const Variant &encoding) {
    return call("mb_convert_kana", {string, mode, encoding});
}
Variant mb_encode_numericentity(const Variant &string, const Variant &map, const Variant &encoding, const Variant &hex) {
    return call("mb_encode_numericentity", {string, map, encoding, hex});
}
Variant mb_decode_numericentity(const Variant &string, const Variant &map, const Variant &encoding) {
    return call("mb_decode_numericentity", {string, map, encoding});
}
Variant mb_send_mail(const Variant &to, const Variant &subject, const Variant &message, const Variant &additional_headers, const Variant &additional_params) {
    return call("mb_send_mail", {to, subject, message, additional_headers, additional_params});
}
Variant mb_get_info(const Variant &type) {
    return call("mb_get_info", {type});
}
Variant mb_check_encoding(const Variant &value, const Variant &encoding) {
    return call("mb_check_encoding", {value, encoding});
}
Variant mb_scrub(const Variant &string, const Variant &encoding) {
    return call("mb_scrub", {string, encoding});
}
Variant mb_ord(const Variant &string, const Variant &encoding) {
    return call("mb_ord", {string, encoding});
}
Variant mb_chr(const Variant &codepoint, const Variant &encoding) {
    return call("mb_chr", {codepoint, encoding});
}
Variant mb_str_pad(const Variant &string, const Variant &length, const Variant &pad_string, const Variant &pad_type, const Variant &encoding) {
    return call("mb_str_pad", {string, length, pad_string, pad_type, encoding});
}
Variant mb_regex_encoding(const Variant &encoding) {
    return call("mb_regex_encoding", {encoding});
}
Variant mb_ereg(const Variant &pattern, const Variant &string, const Reference &matches) {
    return call("mb_ereg", {pattern, string, &matches});
}
Variant mb_eregi(const Variant &pattern, const Variant &string, const Reference &matches) {
    return call("mb_eregi", {pattern, string, &matches});
}
Variant mb_ereg_replace(const Variant &pattern, const Variant &replacement, const Variant &string, const Variant &options) {
    return call("mb_ereg_replace", {pattern, replacement, string, options});
}
Variant mb_eregi_replace(const Variant &pattern, const Variant &replacement, const Variant &string, const Variant &options) {
    return call("mb_eregi_replace", {pattern, replacement, string, options});
}
Variant mb_ereg_replace_callback(const Variant &pattern, const Variant &callback, const Variant &string, const Variant &options) {
    return call("mb_ereg_replace_callback", {pattern, callback, string, options});
}
Variant mb_split(const Variant &pattern, const Variant &string, const Variant &limit) {
    return call("mb_split", {pattern, string, limit});
}
Variant mb_ereg_match(const Variant &pattern, const Variant &string, const Variant &options) {
    return call("mb_ereg_match", {pattern, string, options});
}
Variant mb_ereg_search(const Variant &pattern, const Variant &options) {
    return call("mb_ereg_search", {pattern, options});
}
Variant mb_ereg_search_pos(const Variant &pattern, const Variant &options) {
    return call("mb_ereg_search_pos", {pattern, options});
}
Variant mb_ereg_search_regs(const Variant &pattern, const Variant &options) {
    return call("mb_ereg_search_regs", {pattern, options});
}
Variant mb_ereg_search_init(const Variant &string, const Variant &pattern, const Variant &options) {
    return call("mb_ereg_search_init", {string, pattern, options});
}
Variant mb_ereg_search_getregs() {
    return call("mb_ereg_search_getregs", {});
}
Variant mb_ereg_search_getpos() {
    return call("mb_ereg_search_getpos", {});
}
Variant mb_ereg_search_setpos(const Variant &offset) {
    return call("mb_ereg_search_setpos", {offset});
}
Variant mb_regex_set_options(const Variant &options) {
    return call("mb_regex_set_options", {options});
}
}

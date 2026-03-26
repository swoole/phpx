#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant mb_language(const Variant &language) {
    return call(LITERAL_STRING[648], {language});
}
Variant mb_internal_encoding(const Variant &encoding) {
    return call(LITERAL_STRING[649], {encoding});
}
Variant mb_http_input(const Variant &type) {
    return call(LITERAL_STRING[650], {type});
}
Variant mb_http_output(const Variant &encoding) {
    return call(LITERAL_STRING[651], {encoding});
}
Variant mb_detect_order(const Variant &encoding) {
    return call(LITERAL_STRING[652], {encoding});
}
Variant mb_substitute_character(const Variant &substitute_character) {
    return call(LITERAL_STRING[653], {substitute_character});
}
Variant mb_preferred_mime_name(const Variant &encoding) {
    return call(LITERAL_STRING[654], {encoding});
}
Variant mb_parse_str(const Variant &string, const Reference &result) {
    return call(LITERAL_STRING[655], {string, &result});
}
Variant mb_output_handler(const Variant &string, const Variant &status) {
    return call(LITERAL_STRING[656], {string, status});
}
Variant mb_str_split(const Variant &string, const Variant &length, const Variant &encoding) {
    return call(LITERAL_STRING[657], {string, length, encoding});
}
Variant mb_strlen(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[658], {string, encoding});
}
Variant mb_strpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call(LITERAL_STRING[659], {haystack, needle, offset, encoding});
}
Variant mb_strrpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call(LITERAL_STRING[660], {haystack, needle, offset, encoding});
}
Variant mb_stripos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call(LITERAL_STRING[661], {haystack, needle, offset, encoding});
}
Variant mb_strripos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    return call(LITERAL_STRING[662], {haystack, needle, offset, encoding});
}
Variant mb_strstr(const Variant &haystack,
                  const Variant &needle,
                  const Variant &before_needle,
                  const Variant &encoding) {
    return call(LITERAL_STRING[663], {haystack, needle, before_needle, encoding});
}
Variant mb_strrchr(const Variant &haystack,
                   const Variant &needle,
                   const Variant &before_needle,
                   const Variant &encoding) {
    return call(LITERAL_STRING[664], {haystack, needle, before_needle, encoding});
}
Variant mb_stristr(const Variant &haystack,
                   const Variant &needle,
                   const Variant &before_needle,
                   const Variant &encoding) {
    return call(LITERAL_STRING[665], {haystack, needle, before_needle, encoding});
}
Variant mb_strrichr(const Variant &haystack,
                    const Variant &needle,
                    const Variant &before_needle,
                    const Variant &encoding) {
    return call(LITERAL_STRING[666], {haystack, needle, before_needle, encoding});
}
Variant mb_substr_count(const Variant &haystack, const Variant &needle, const Variant &encoding) {
    return call(LITERAL_STRING[667], {haystack, needle, encoding});
}
Variant mb_substr(const Variant &string, const Variant &start, const Variant &length, const Variant &encoding) {
    return call(LITERAL_STRING[668], {string, start, length, encoding});
}
Variant mb_strcut(const Variant &string, const Variant &start, const Variant &length, const Variant &encoding) {
    return call(LITERAL_STRING[669], {string, start, length, encoding});
}
Variant mb_strwidth(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[670], {string, encoding});
}
Variant mb_strimwidth(const Variant &string,
                      const Variant &start,
                      const Variant &width,
                      const Variant &trim_marker,
                      const Variant &encoding) {
    return call(LITERAL_STRING[671], {string, start, width, trim_marker, encoding});
}
Variant mb_convert_encoding(const Variant &string, const Variant &to_encoding, const Variant &from_encoding) {
    return call(LITERAL_STRING[672], {string, to_encoding, from_encoding});
}
Variant mb_convert_case(const Variant &string, const Variant &mode, const Variant &encoding) {
    return call(LITERAL_STRING[673], {string, mode, encoding});
}
Variant mb_strtoupper(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[674], {string, encoding});
}
Variant mb_strtolower(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[675], {string, encoding});
}
Variant mb_ucfirst(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[676], {string, encoding});
}
Variant mb_lcfirst(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[677], {string, encoding});
}
Variant mb_trim(const Variant &string, const Variant &characters, const Variant &encoding) {
    return call(LITERAL_STRING[678], {string, characters, encoding});
}
Variant mb_ltrim(const Variant &string, const Variant &characters, const Variant &encoding) {
    return call(LITERAL_STRING[679], {string, characters, encoding});
}
Variant mb_rtrim(const Variant &string, const Variant &characters, const Variant &encoding) {
    return call(LITERAL_STRING[680], {string, characters, encoding});
}
Variant mb_detect_encoding(const Variant &string, const Variant &encodings, const Variant &strict) {
    return call(LITERAL_STRING[681], {string, encodings, strict});
}
Variant mb_list_encodings() {
    return call(LITERAL_STRING[682], {});
}
Variant mb_encoding_aliases(const Variant &encoding) {
    return call(LITERAL_STRING[683], {encoding});
}
Variant mb_encode_mimeheader(const Variant &string,
                             const Variant &charset,
                             const Variant &transfer_encoding,
                             const Variant &newline,
                             const Variant &indent) {
    return call(LITERAL_STRING[684], {string, charset, transfer_encoding, newline, indent});
}
Variant mb_decode_mimeheader(const Variant &string) {
    return call(LITERAL_STRING[685], {string});
}
Variant mb_convert_kana(const Variant &string, const Variant &mode, const Variant &encoding) {
    return call(LITERAL_STRING[686], {string, mode, encoding});
}
Variant mb_encode_numericentity(const Variant &string,
                                const Variant &map,
                                const Variant &encoding,
                                const Variant &hex) {
    return call(LITERAL_STRING[688], {string, map, encoding, hex});
}
Variant mb_decode_numericentity(const Variant &string, const Variant &map, const Variant &encoding) {
    return call(LITERAL_STRING[689], {string, map, encoding});
}
Variant mb_send_mail(const Variant &to,
                     const Variant &subject,
                     const Variant &message,
                     const Variant &additional_headers,
                     const Variant &additional_params) {
    return call(LITERAL_STRING[690], {to, subject, message, additional_headers, additional_params});
}
Variant mb_get_info(const Variant &type) {
    return call(LITERAL_STRING[691], {type});
}
Variant mb_check_encoding(const Variant &value, const Variant &encoding) {
    return call(LITERAL_STRING[692], {value, encoding});
}
Variant mb_scrub(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[693], {string, encoding});
}
Variant mb_ord(const Variant &string, const Variant &encoding) {
    return call(LITERAL_STRING[694], {string, encoding});
}
Variant mb_chr(const Variant &codepoint, const Variant &encoding) {
    return call(LITERAL_STRING[695], {codepoint, encoding});
}
Variant mb_str_pad(const Variant &string,
                   const Variant &length,
                   const Variant &pad_string,
                   const Variant &pad_type,
                   const Variant &encoding) {
    return call(LITERAL_STRING[696], {string, length, pad_string, pad_type, encoding});
}
Variant mb_regex_encoding(const Variant &encoding) {
    return call(LITERAL_STRING[697], {encoding});
}
Variant mb_ereg(const Variant &pattern, const Variant &string, const Reference &matches) {
    return call(LITERAL_STRING[698], {pattern, string, &matches});
}
Variant mb_eregi(const Variant &pattern, const Variant &string, const Reference &matches) {
    return call(LITERAL_STRING[699], {pattern, string, &matches});
}
Variant mb_ereg_replace(const Variant &pattern,
                        const Variant &replacement,
                        const Variant &string,
                        const Variant &options) {
    return call(LITERAL_STRING[700], {pattern, replacement, string, options});
}
Variant mb_eregi_replace(const Variant &pattern,
                         const Variant &replacement,
                         const Variant &string,
                         const Variant &options) {
    return call(LITERAL_STRING[701], {pattern, replacement, string, options});
}
Variant mb_ereg_replace_callback(const Variant &pattern,
                                 const Variant &callback,
                                 const Variant &string,
                                 const Variant &options) {
    return call(LITERAL_STRING[702], {pattern, callback, string, options});
}
Variant mb_split(const Variant &pattern, const Variant &string, const Variant &limit) {
    return call(LITERAL_STRING[703], {pattern, string, limit});
}
Variant mb_ereg_match(const Variant &pattern, const Variant &string, const Variant &options) {
    return call(LITERAL_STRING[704], {pattern, string, options});
}
Variant mb_ereg_search(const Variant &pattern, const Variant &options) {
    return call(LITERAL_STRING[705], {pattern, options});
}
Variant mb_ereg_search_pos(const Variant &pattern, const Variant &options) {
    return call(LITERAL_STRING[706], {pattern, options});
}
Variant mb_ereg_search_regs(const Variant &pattern, const Variant &options) {
    return call(LITERAL_STRING[707], {pattern, options});
}
Variant mb_ereg_search_init(const Variant &string, const Variant &pattern, const Variant &options) {
    return call(LITERAL_STRING[708], {string, pattern, options});
}
Variant mb_ereg_search_getregs() {
    return call(LITERAL_STRING[709], {});
}
Variant mb_ereg_search_getpos() {
    return call(LITERAL_STRING[710], {});
}
Variant mb_ereg_search_setpos(const Variant &offset) {
    return call(LITERAL_STRING[711], {offset});
}
Variant mb_regex_set_options(const Variant &options) {
    return call(LITERAL_STRING[712], {options});
}
}  // namespace php

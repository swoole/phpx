#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant mb_language(const Variant &language) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[678]);
    }
    return call(fn, {language});
}
Variant mb_internal_encoding(const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[679]);
    }
    return call(fn, {encoding});
}
Variant mb_http_input(const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[680]);
    }
    return call(fn, {type});
}
Variant mb_http_output(const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[681]);
    }
    return call(fn, {encoding});
}
Variant mb_detect_order(const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[682]);
    }
    return call(fn, {encoding});
}
Variant mb_substitute_character(const Variant &substitute_character) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[683]);
    }
    return call(fn, {substitute_character});
}
Variant mb_preferred_mime_name(const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[684]);
    }
    return call(fn, {encoding});
}
Variant mb_parse_str(const Variant &string, const Reference &result) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[685]);
    }
    return call(fn, {string, &result});
}
Variant mb_output_handler(const Variant &string, const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[686]);
    }
    return call(fn, {string, status});
}
Variant mb_str_split(const Variant &string, const Variant &length, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[687]);
    }
    return call(fn, {string, length, encoding});
}
Variant mb_strlen(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[688]);
    }
    return call(fn, {string, encoding});
}
Variant mb_strpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[689]);
    }
    return call(fn, {haystack, needle, offset, encoding});
}
Variant mb_strrpos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[690]);
    }
    return call(fn, {haystack, needle, offset, encoding});
}
Variant mb_stripos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[691]);
    }
    return call(fn, {haystack, needle, offset, encoding});
}
Variant mb_strripos(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[692]);
    }
    return call(fn, {haystack, needle, offset, encoding});
}
Variant mb_strstr(const Variant &haystack,
                  const Variant &needle,
                  const Variant &before_needle,
                  const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[693]);
    }
    return call(fn, {haystack, needle, before_needle, encoding});
}
Variant mb_strrchr(const Variant &haystack,
                   const Variant &needle,
                   const Variant &before_needle,
                   const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[694]);
    }
    return call(fn, {haystack, needle, before_needle, encoding});
}
Variant mb_stristr(const Variant &haystack,
                   const Variant &needle,
                   const Variant &before_needle,
                   const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[695]);
    }
    return call(fn, {haystack, needle, before_needle, encoding});
}
Variant mb_strrichr(const Variant &haystack,
                    const Variant &needle,
                    const Variant &before_needle,
                    const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[696]);
    }
    return call(fn, {haystack, needle, before_needle, encoding});
}
Variant mb_substr_count(const Variant &haystack, const Variant &needle, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[697]);
    }
    return call(fn, {haystack, needle, encoding});
}
Variant mb_substr(const Variant &string, const Variant &start, const Variant &length, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[698]);
    }
    return call(fn, {string, start, length, encoding});
}
Variant mb_strcut(const Variant &string, const Variant &start, const Variant &length, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[699]);
    }
    return call(fn, {string, start, length, encoding});
}
Variant mb_strwidth(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[700]);
    }
    return call(fn, {string, encoding});
}
Variant mb_strimwidth(const Variant &string,
                      const Variant &start,
                      const Variant &width,
                      const Variant &trim_marker,
                      const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[701]);
    }
    return call(fn, {string, start, width, trim_marker, encoding});
}
Variant mb_convert_encoding(const Variant &string, const Variant &to_encoding, const Variant &from_encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[702]);
    }
    return call(fn, {string, to_encoding, from_encoding});
}
Variant mb_convert_case(const Variant &string, const Variant &mode, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[703]);
    }
    return call(fn, {string, mode, encoding});
}
Variant mb_strtoupper(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[704]);
    }
    return call(fn, {string, encoding});
}
Variant mb_strtolower(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[705]);
    }
    return call(fn, {string, encoding});
}
Variant mb_ucfirst(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[706]);
    }
    return call(fn, {string, encoding});
}
Variant mb_lcfirst(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[707]);
    }
    return call(fn, {string, encoding});
}
Variant mb_trim(const Variant &string, const Variant &characters, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[708]);
    }
    return call(fn, {string, characters, encoding});
}
Variant mb_ltrim(const Variant &string, const Variant &characters, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[709]);
    }
    return call(fn, {string, characters, encoding});
}
Variant mb_rtrim(const Variant &string, const Variant &characters, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[710]);
    }
    return call(fn, {string, characters, encoding});
}
Variant mb_detect_encoding(const Variant &string, const Variant &encodings, const Variant &strict) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[711]);
    }
    return call(fn, {string, encodings, strict});
}
Variant mb_list_encodings() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[712]);
    }
    return call(fn, {});
}
Variant mb_encoding_aliases(const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[713]);
    }
    return call(fn, {encoding});
}
Variant mb_encode_mimeheader(const Variant &string,
                             const Variant &charset,
                             const Variant &transfer_encoding,
                             const Variant &newline,
                             const Variant &indent) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[714]);
    }
    return call(fn, {string, charset, transfer_encoding, newline, indent});
}
Variant mb_decode_mimeheader(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[715]);
    }
    return call(fn, {string});
}
Variant mb_convert_kana(const Variant &string, const Variant &mode, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[716]);
    }
    return call(fn, {string, mode, encoding});
}
Variant mb_encode_numericentity(const Variant &string,
                                const Variant &map,
                                const Variant &encoding,
                                const Variant &hex) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[718]);
    }
    return call(fn, {string, map, encoding, hex});
}
Variant mb_decode_numericentity(const Variant &string, const Variant &map, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[719]);
    }
    return call(fn, {string, map, encoding});
}
Variant mb_send_mail(const Variant &to,
                     const Variant &subject,
                     const Variant &message,
                     const Variant &additional_headers,
                     const Variant &additional_params) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[720]);
    }
    return call(fn, {to, subject, message, additional_headers, additional_params});
}
Variant mb_get_info(const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[721]);
    }
    return call(fn, {type});
}
Variant mb_check_encoding(const Variant &value, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[722]);
    }
    return call(fn, {value, encoding});
}
Variant mb_scrub(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[723]);
    }
    return call(fn, {string, encoding});
}
Variant mb_ord(const Variant &string, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[724]);
    }
    return call(fn, {string, encoding});
}
Variant mb_chr(const Variant &codepoint, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[725]);
    }
    return call(fn, {codepoint, encoding});
}
Variant mb_str_pad(const Variant &string,
                   const Variant &length,
                   const Variant &pad_string,
                   const Variant &pad_type,
                   const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[726]);
    }
    return call(fn, {string, length, pad_string, pad_type, encoding});
}
Variant mb_regex_encoding(const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[727]);
    }
    return call(fn, {encoding});
}
Variant mb_ereg(const Variant &pattern, const Variant &string, const Reference &matches) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[728]);
    }
    return call(fn, {pattern, string, &matches});
}
Variant mb_eregi(const Variant &pattern, const Variant &string, const Reference &matches) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[729]);
    }
    return call(fn, {pattern, string, &matches});
}
Variant mb_ereg_replace(const Variant &pattern,
                        const Variant &replacement,
                        const Variant &string,
                        const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[730]);
    }
    return call(fn, {pattern, replacement, string, options});
}
Variant mb_eregi_replace(const Variant &pattern,
                         const Variant &replacement,
                         const Variant &string,
                         const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[731]);
    }
    return call(fn, {pattern, replacement, string, options});
}
Variant mb_ereg_replace_callback(const Variant &pattern,
                                 const Variant &callback,
                                 const Variant &string,
                                 const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[732]);
    }
    return call(fn, {pattern, callback, string, options});
}
Variant mb_split(const Variant &pattern, const Variant &string, const Variant &limit) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[733]);
    }
    return call(fn, {pattern, string, limit});
}
Variant mb_ereg_match(const Variant &pattern, const Variant &string, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[734]);
    }
    return call(fn, {pattern, string, options});
}
Variant mb_ereg_search(const Variant &pattern, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[735]);
    }
    return call(fn, {pattern, options});
}
Variant mb_ereg_search_pos(const Variant &pattern, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[736]);
    }
    return call(fn, {pattern, options});
}
Variant mb_ereg_search_regs(const Variant &pattern, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[737]);
    }
    return call(fn, {pattern, options});
}
Variant mb_ereg_search_init(const Variant &string, const Variant &pattern, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[738]);
    }
    return call(fn, {string, pattern, options});
}
Variant mb_ereg_search_getregs() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[739]);
    }
    return call(fn, {});
}
Variant mb_ereg_search_getpos() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[740]);
    }
    return call(fn, {});
}
Variant mb_ereg_search_setpos(const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[741]);
    }
    return call(fn, {offset});
}
Variant mb_regex_set_options(const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[742]);
    }
    return call(fn, {options});
}
}  // namespace php

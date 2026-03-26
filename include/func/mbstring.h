#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant mb_language(const Variant &language = {});
Variant mb_internal_encoding(const Variant &encoding = {});
Variant mb_http_input(const Variant &type = {});
Variant mb_http_output(const Variant &encoding = {});
Variant mb_detect_order(const Variant &encoding = {});
Variant mb_substitute_character(const Variant &substitute_character = {});
Variant mb_preferred_mime_name(const Variant &encoding);
Variant mb_parse_str(const Variant &string, const Reference &result);
Variant mb_output_handler(const Variant &string, const Variant &status);
Variant mb_str_split(const Variant &string, const Variant &length = 1, const Variant &encoding = {});
Variant mb_strlen(const Variant &string, const Variant &encoding = {});
Variant mb_strpos(const Variant &haystack,
                  const Variant &needle,
                  const Variant &offset = 0,
                  const Variant &encoding = {});
Variant mb_strrpos(const Variant &haystack,
                   const Variant &needle,
                   const Variant &offset = 0,
                   const Variant &encoding = {});
Variant mb_stripos(const Variant &haystack,
                   const Variant &needle,
                   const Variant &offset = 0,
                   const Variant &encoding = {});
Variant mb_strripos(const Variant &haystack,
                    const Variant &needle,
                    const Variant &offset = 0,
                    const Variant &encoding = {});
Variant mb_strstr(const Variant &haystack,
                  const Variant &needle,
                  const Variant &before_needle = false,
                  const Variant &encoding = {});
Variant mb_strrchr(const Variant &haystack,
                   const Variant &needle,
                   const Variant &before_needle = false,
                   const Variant &encoding = {});
Variant mb_stristr(const Variant &haystack,
                   const Variant &needle,
                   const Variant &before_needle = false,
                   const Variant &encoding = {});
Variant mb_strrichr(const Variant &haystack,
                    const Variant &needle,
                    const Variant &before_needle = false,
                    const Variant &encoding = {});
Variant mb_substr_count(const Variant &haystack, const Variant &needle, const Variant &encoding = {});
Variant mb_substr(const Variant &string,
                  const Variant &start,
                  const Variant &length = {},
                  const Variant &encoding = {});
Variant mb_strcut(const Variant &string,
                  const Variant &start,
                  const Variant &length = {},
                  const Variant &encoding = {});
Variant mb_strwidth(const Variant &string, const Variant &encoding = {});
Variant mb_strimwidth(const Variant &string,
                      const Variant &start,
                      const Variant &width,
                      const Variant &trim_marker = "",
                      const Variant &encoding = {});
Variant mb_convert_encoding(const Variant &string, const Variant &to_encoding, const Variant &from_encoding = {});
Variant mb_convert_case(const Variant &string, const Variant &mode, const Variant &encoding = {});
Variant mb_strtoupper(const Variant &string, const Variant &encoding = {});
Variant mb_strtolower(const Variant &string, const Variant &encoding = {});
Variant mb_ucfirst(const Variant &string, const Variant &encoding = {});
Variant mb_lcfirst(const Variant &string, const Variant &encoding = {});
Variant mb_trim(const Variant &string, const Variant &characters = {}, const Variant &encoding = {});
Variant mb_ltrim(const Variant &string, const Variant &characters = {}, const Variant &encoding = {});
Variant mb_rtrim(const Variant &string, const Variant &characters = {}, const Variant &encoding = {});
Variant mb_detect_encoding(const Variant &string, const Variant &encodings = {}, const Variant &strict = false);
Variant mb_list_encodings();
Variant mb_encoding_aliases(const Variant &encoding);
Variant mb_encode_mimeheader(const Variant &string,
                             const Variant &charset = {},
                             const Variant &transfer_encoding = {},
                             const Variant &newline = "\r\n",
                             const Variant &indent = 0);
Variant mb_decode_mimeheader(const Variant &string);
Variant mb_convert_kana(const Variant &string, const Variant &mode = "KV", const Variant &encoding = {});
template <typename... Args>
Variant mb_convert_variables(const Variant &to_encoding,
                             const Variant &from_encoding,
                             const Reference &var,
                             const Args &...vars) {
    return call(LITERAL_STRING[687], {to_encoding, from_encoding, &var, vars...});
}
Variant mb_encode_numericentity(const Variant &string,
                                const Variant &map,
                                const Variant &encoding = {},
                                const Variant &hex = false);
Variant mb_decode_numericentity(const Variant &string, const Variant &map, const Variant &encoding = {});
Variant mb_send_mail(const Variant &to,
                     const Variant &subject,
                     const Variant &message,
                     const Variant &additional_headers = Array{},
                     const Variant &additional_params = {});
Variant mb_get_info(const Variant &type = "all");
Variant mb_check_encoding(const Variant &value = {}, const Variant &encoding = {});
Variant mb_scrub(const Variant &string, const Variant &encoding = {});
Variant mb_ord(const Variant &string, const Variant &encoding = {});
Variant mb_chr(const Variant &codepoint, const Variant &encoding = {});
Variant mb_str_pad(const Variant &string,
                   const Variant &length,
                   const Variant &pad_string = " ",
                   const Variant &pad_type = 1,
                   const Variant &encoding = {});
Variant mb_regex_encoding(const Variant &encoding = {});
Variant mb_ereg(const Variant &pattern, const Variant &string, const Reference &matches = {});
Variant mb_eregi(const Variant &pattern, const Variant &string, const Reference &matches = {});
Variant mb_ereg_replace(const Variant &pattern,
                        const Variant &replacement,
                        const Variant &string,
                        const Variant &options = {});
Variant mb_eregi_replace(const Variant &pattern,
                         const Variant &replacement,
                         const Variant &string,
                         const Variant &options = {});
Variant mb_ereg_replace_callback(const Variant &pattern,
                                 const Variant &callback,
                                 const Variant &string,
                                 const Variant &options = {});
Variant mb_split(const Variant &pattern, const Variant &string, const Variant &limit = -1);
Variant mb_ereg_match(const Variant &pattern, const Variant &string, const Variant &options = {});
Variant mb_ereg_search(const Variant &pattern = {}, const Variant &options = {});
Variant mb_ereg_search_pos(const Variant &pattern = {}, const Variant &options = {});
Variant mb_ereg_search_regs(const Variant &pattern = {}, const Variant &options = {});
Variant mb_ereg_search_init(const Variant &string, const Variant &pattern = {}, const Variant &options = {});
Variant mb_ereg_search_getregs();
Variant mb_ereg_search_getpos();
Variant mb_ereg_search_setpos(const Variant &offset);
Variant mb_regex_set_options(const Variant &options = {});
}  // namespace php

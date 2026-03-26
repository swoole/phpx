namespace php {
Variant iconv_strlen(const Variant &string, const Variant &encoding = {});
Variant iconv_substr(const Variant &string, const Variant &offset, const Variant &length = {}, const Variant &encoding = {});
Variant iconv_strpos(const Variant &haystack, const Variant &needle, const Variant &offset = 0, const Variant &encoding = {});
Variant iconv_strrpos(const Variant &haystack, const Variant &needle, const Variant &encoding = {});
Variant iconv_mime_encode(const Variant &field_name, const Variant &field_value, const Variant &options = Array{});
Variant iconv_mime_decode(const Variant &string, const Variant &mode = 0, const Variant &encoding = {});
Variant iconv_mime_decode_headers(const Variant &headers, const Variant &mode = 0, const Variant &encoding = {});
Variant iconv(const Variant &from_encoding, const Variant &to_encoding, const Variant &string);
Variant iconv_set_encoding(const Variant &type, const Variant &encoding);
Variant iconv_get_encoding(const Variant &type = "all");
}

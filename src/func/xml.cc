#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant xml_parser_create(const Variant &encoding) {
    return call(LITERAL_STRING[2360], {encoding});
}
Variant xml_parser_create_ns(const Variant &encoding, const Variant &separator) {
    return call(LITERAL_STRING[2361], {encoding, separator});
}
Variant xml_set_object(const Variant &parser, const Variant &object) {
    return call(LITERAL_STRING[2362], {parser, object});
}
Variant xml_set_element_handler(const Variant &parser, const Variant &start_handler, const Variant &end_handler) {
    return call(LITERAL_STRING[2363], {parser, start_handler, end_handler});
}
Variant xml_set_character_data_handler(const Variant &parser, const Variant &handler) {
    return call(LITERAL_STRING[2364], {parser, handler});
}
Variant xml_set_processing_instruction_handler(const Variant &parser, const Variant &handler) {
    return call(LITERAL_STRING[2365], {parser, handler});
}
Variant xml_set_default_handler(const Variant &parser, const Variant &handler) {
    return call(LITERAL_STRING[2366], {parser, handler});
}
Variant xml_set_unparsed_entity_decl_handler(const Variant &parser, const Variant &handler) {
    return call(LITERAL_STRING[2367], {parser, handler});
}
Variant xml_set_notation_decl_handler(const Variant &parser, const Variant &handler) {
    return call(LITERAL_STRING[2368], {parser, handler});
}
Variant xml_set_external_entity_ref_handler(const Variant &parser, const Variant &handler) {
    return call(LITERAL_STRING[2369], {parser, handler});
}
Variant xml_set_start_namespace_decl_handler(const Variant &parser, const Variant &handler) {
    return call(LITERAL_STRING[2370], {parser, handler});
}
Variant xml_set_end_namespace_decl_handler(const Variant &parser, const Variant &handler) {
    return call(LITERAL_STRING[2371], {parser, handler});
}
Variant xml_parse(const Variant &parser, const Variant &data, const Variant &is_final) {
    return call(LITERAL_STRING[2372], {parser, data, is_final});
}
Variant xml_parse_into_struct(const Variant &parser,
                              const Variant &data,
                              const Reference &values,
                              const Reference &index) {
    return call(LITERAL_STRING[2373], {parser, data, &values, &index});
}
Variant xml_get_error_code(const Variant &parser) {
    return call(LITERAL_STRING[2374], {parser});
}
Variant xml_error_string(const Variant &error_code) {
    return call(LITERAL_STRING[2375], {error_code});
}
Variant xml_get_current_line_number(const Variant &parser) {
    return call(LITERAL_STRING[2376], {parser});
}
Variant xml_get_current_column_number(const Variant &parser) {
    return call(LITERAL_STRING[2377], {parser});
}
Variant xml_get_current_byte_index(const Variant &parser) {
    return call(LITERAL_STRING[2378], {parser});
}
Variant xml_parser_free(const Variant &parser) {
    return call(LITERAL_STRING[2379], {parser});
}
Variant xml_parser_set_option(const Variant &parser, const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[2380], {parser, option, value});
}
Variant xml_parser_get_option(const Variant &parser, const Variant &option) {
    return call(LITERAL_STRING[2381], {parser, option});
}
}  // namespace php

#include "phpx.h"

namespace php {
Variant xml_parser_create(const Variant &encoding) {
    return call("xml_parser_create", {encoding});
}
Variant xml_parser_create_ns(const Variant &encoding, const Variant &separator) {
    return call("xml_parser_create_ns", {encoding, separator});
}
Variant xml_set_object(const Variant &parser, const Variant &object) {
    return call("xml_set_object", {parser, object});
}
Variant xml_set_element_handler(const Variant &parser, const Variant &start_handler, const Variant &end_handler) {
    return call("xml_set_element_handler", {parser, start_handler, end_handler});
}
Variant xml_set_character_data_handler(const Variant &parser, const Variant &handler) {
    return call("xml_set_character_data_handler", {parser, handler});
}
Variant xml_set_processing_instruction_handler(const Variant &parser, const Variant &handler) {
    return call("xml_set_processing_instruction_handler", {parser, handler});
}
Variant xml_set_default_handler(const Variant &parser, const Variant &handler) {
    return call("xml_set_default_handler", {parser, handler});
}
Variant xml_set_unparsed_entity_decl_handler(const Variant &parser, const Variant &handler) {
    return call("xml_set_unparsed_entity_decl_handler", {parser, handler});
}
Variant xml_set_notation_decl_handler(const Variant &parser, const Variant &handler) {
    return call("xml_set_notation_decl_handler", {parser, handler});
}
Variant xml_set_external_entity_ref_handler(const Variant &parser, const Variant &handler) {
    return call("xml_set_external_entity_ref_handler", {parser, handler});
}
Variant xml_set_start_namespace_decl_handler(const Variant &parser, const Variant &handler) {
    return call("xml_set_start_namespace_decl_handler", {parser, handler});
}
Variant xml_set_end_namespace_decl_handler(const Variant &parser, const Variant &handler) {
    return call("xml_set_end_namespace_decl_handler", {parser, handler});
}
Variant xml_parse(const Variant &parser, const Variant &data, const Variant &is_final) {
    return call("xml_parse", {parser, data, is_final});
}
Variant xml_parse_into_struct(const Variant &parser, const Variant &data, const Reference &values, const Reference &index) {
    return call("xml_parse_into_struct", {parser, data, &values, &index});
}
Variant xml_get_error_code(const Variant &parser) {
    return call("xml_get_error_code", {parser});
}
Variant xml_error_string(const Variant &error_code) {
    return call("xml_error_string", {error_code});
}
Variant xml_get_current_line_number(const Variant &parser) {
    return call("xml_get_current_line_number", {parser});
}
Variant xml_get_current_column_number(const Variant &parser) {
    return call("xml_get_current_column_number", {parser});
}
Variant xml_get_current_byte_index(const Variant &parser) {
    return call("xml_get_current_byte_index", {parser});
}
Variant xml_parser_free(const Variant &parser) {
    return call("xml_parser_free", {parser});
}
Variant xml_parser_set_option(const Variant &parser, const Variant &option, const Variant &value) {
    return call("xml_parser_set_option", {parser, option, value});
}
Variant xml_parser_get_option(const Variant &parser, const Variant &option) {
    return call("xml_parser_get_option", {parser, option});
}
}

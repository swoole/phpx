namespace php {
Variant xml_parser_create(const Variant &encoding = {});
Variant xml_parser_create_ns(const Variant &encoding = {}, const Variant &separator = ":");
Variant xml_set_object(const Variant &parser, const Variant &object);
Variant xml_set_element_handler(const Variant &parser, const Variant &start_handler, const Variant &end_handler);
Variant xml_set_character_data_handler(const Variant &parser, const Variant &handler);
Variant xml_set_processing_instruction_handler(const Variant &parser, const Variant &handler);
Variant xml_set_default_handler(const Variant &parser, const Variant &handler);
Variant xml_set_unparsed_entity_decl_handler(const Variant &parser, const Variant &handler);
Variant xml_set_notation_decl_handler(const Variant &parser, const Variant &handler);
Variant xml_set_external_entity_ref_handler(const Variant &parser, const Variant &handler);
Variant xml_set_start_namespace_decl_handler(const Variant &parser, const Variant &handler);
Variant xml_set_end_namespace_decl_handler(const Variant &parser, const Variant &handler);
Variant xml_parse(const Variant &parser, const Variant &data, const Variant &is_final = false);
Variant xml_parse_into_struct(const Variant &parser, const Variant &data, const Reference &values, const Reference &index = {});
Variant xml_get_error_code(const Variant &parser);
Variant xml_error_string(const Variant &error_code);
Variant xml_get_current_line_number(const Variant &parser);
Variant xml_get_current_column_number(const Variant &parser);
Variant xml_get_current_byte_index(const Variant &parser);
Variant xml_parser_free(const Variant &parser);
Variant xml_parser_set_option(const Variant &parser, const Variant &option, const Variant &value);
Variant xml_parser_get_option(const Variant &parser, const Variant &option);
}

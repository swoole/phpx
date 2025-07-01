#include "phpx.h"

namespace php {
Variant xml_parser_create{ZEND_STRL("xml_parser_create"), true};
Variant xml_parser_create_ns{ZEND_STRL("xml_parser_create_ns"), true};
Variant xml_set_object{ZEND_STRL("xml_set_object"), true};
Variant xml_set_element_handler{ZEND_STRL("xml_set_element_handler"), true};
Variant xml_set_character_data_handler{ZEND_STRL("xml_set_character_data_handler"), true};
Variant xml_set_processing_instruction_handler{ZEND_STRL("xml_set_processing_instruction_handler"), true};
Variant xml_set_default_handler{ZEND_STRL("xml_set_default_handler"), true};
Variant xml_set_unparsed_entity_decl_handler{ZEND_STRL("xml_set_unparsed_entity_decl_handler"), true};
Variant xml_set_notation_decl_handler{ZEND_STRL("xml_set_notation_decl_handler"), true};
Variant xml_set_external_entity_ref_handler{ZEND_STRL("xml_set_external_entity_ref_handler"), true};
Variant xml_set_start_namespace_decl_handler{ZEND_STRL("xml_set_start_namespace_decl_handler"), true};
Variant xml_set_end_namespace_decl_handler{ZEND_STRL("xml_set_end_namespace_decl_handler"), true};
Variant xml_parse{ZEND_STRL("xml_parse"), true};
Variant xml_parse_into_struct{ZEND_STRL("xml_parse_into_struct"), true};
Variant xml_get_error_code{ZEND_STRL("xml_get_error_code"), true};
Variant xml_error_string{ZEND_STRL("xml_error_string"), true};
Variant xml_get_current_line_number{ZEND_STRL("xml_get_current_line_number"), true};
Variant xml_get_current_column_number{ZEND_STRL("xml_get_current_column_number"), true};
Variant xml_get_current_byte_index{ZEND_STRL("xml_get_current_byte_index"), true};
Variant xml_parser_free{ZEND_STRL("xml_parser_free"), true};
Variant xml_parser_set_option{ZEND_STRL("xml_parser_set_option"), true};
Variant xml_parser_get_option{ZEND_STRL("xml_parser_get_option"), true};
}

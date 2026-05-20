#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
XMLParser xml_parser_create(const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2428]);
    }
    return XMLParser(Object(call(fn, {encoding})));
}
XMLParser xml_parser_create_ns(const Variant &encoding, const Variant &separator) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2429]);
    }
    return XMLParser(Object(call(fn, {encoding, separator})));
}
Variant xml_set_object(const XMLParser &parser, const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2430]);
    }
    return call(fn, {parser.getObject(), object});
}
Variant xml_set_object(const Variant &parser, const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2430]);
    }
    return call(fn, {parser, object});
}
Variant xml_set_element_handler(const XMLParser &parser, const Variant &start_handler, const Variant &end_handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2431]);
    }
    return call(fn, {parser.getObject(), start_handler, end_handler});
}
Variant xml_set_element_handler(const Variant &parser, const Variant &start_handler, const Variant &end_handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2431]);
    }
    return call(fn, {parser, start_handler, end_handler});
}
Variant xml_set_character_data_handler(const XMLParser &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2432]);
    }
    return call(fn, {parser.getObject(), handler});
}
Variant xml_set_character_data_handler(const Variant &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2432]);
    }
    return call(fn, {parser, handler});
}
Variant xml_set_processing_instruction_handler(const XMLParser &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2433]);
    }
    return call(fn, {parser.getObject(), handler});
}
Variant xml_set_processing_instruction_handler(const Variant &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2433]);
    }
    return call(fn, {parser, handler});
}
Variant xml_set_default_handler(const XMLParser &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2434]);
    }
    return call(fn, {parser.getObject(), handler});
}
Variant xml_set_default_handler(const Variant &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2434]);
    }
    return call(fn, {parser, handler});
}
Variant xml_set_unparsed_entity_decl_handler(const XMLParser &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2435]);
    }
    return call(fn, {parser.getObject(), handler});
}
Variant xml_set_unparsed_entity_decl_handler(const Variant &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2435]);
    }
    return call(fn, {parser, handler});
}
Variant xml_set_notation_decl_handler(const XMLParser &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2436]);
    }
    return call(fn, {parser.getObject(), handler});
}
Variant xml_set_notation_decl_handler(const Variant &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2436]);
    }
    return call(fn, {parser, handler});
}
Variant xml_set_external_entity_ref_handler(const XMLParser &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2437]);
    }
    return call(fn, {parser.getObject(), handler});
}
Variant xml_set_external_entity_ref_handler(const Variant &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2437]);
    }
    return call(fn, {parser, handler});
}
Variant xml_set_start_namespace_decl_handler(const XMLParser &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2438]);
    }
    return call(fn, {parser.getObject(), handler});
}
Variant xml_set_start_namespace_decl_handler(const Variant &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2438]);
    }
    return call(fn, {parser, handler});
}
Variant xml_set_end_namespace_decl_handler(const XMLParser &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2439]);
    }
    return call(fn, {parser.getObject(), handler});
}
Variant xml_set_end_namespace_decl_handler(const Variant &parser, const Variant &handler) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2439]);
    }
    return call(fn, {parser, handler});
}
Variant xml_parse(const XMLParser &parser, const Variant &data, const Variant &is_final) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2440]);
    }
    return call(fn, {parser.getObject(), data, is_final});
}
Variant xml_parse(const Variant &parser, const Variant &data, const Variant &is_final) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2440]);
    }
    return call(fn, {parser, data, is_final});
}
Variant xml_parse_into_struct(const XMLParser &parser,
                              const Variant &data,
                              const Reference &values,
                              const Reference &index) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2441]);
    }
    return call(fn, {parser.getObject(), data, &values, &index});
}
Variant xml_parse_into_struct(const Variant &parser,
                              const Variant &data,
                              const Reference &values,
                              const Reference &index) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2441]);
    }
    return call(fn, {parser, data, &values, &index});
}
Variant xml_get_error_code(const XMLParser &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2442]);
    }
    return call(fn, {parser.getObject()});
}
Variant xml_get_error_code(const Variant &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2442]);
    }
    return call(fn, {parser});
}
Variant xml_error_string(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2443]);
    }
    return call(fn, {error_code});
}
Variant xml_get_current_line_number(const XMLParser &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2444]);
    }
    return call(fn, {parser.getObject()});
}
Variant xml_get_current_line_number(const Variant &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2444]);
    }
    return call(fn, {parser});
}
Variant xml_get_current_column_number(const XMLParser &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2445]);
    }
    return call(fn, {parser.getObject()});
}
Variant xml_get_current_column_number(const Variant &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2445]);
    }
    return call(fn, {parser});
}
Variant xml_get_current_byte_index(const XMLParser &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2446]);
    }
    return call(fn, {parser.getObject()});
}
Variant xml_get_current_byte_index(const Variant &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2446]);
    }
    return call(fn, {parser});
}
Variant xml_parser_free(const XMLParser &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2447]);
    }
    return call(fn, {parser.getObject()});
}
Variant xml_parser_free(const Variant &parser) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2447]);
    }
    return call(fn, {parser});
}
Variant xml_parser_set_option(const XMLParser &parser, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2448]);
    }
    return call(fn, {parser.getObject(), option, value});
}
Variant xml_parser_set_option(const Variant &parser, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2448]);
    }
    return call(fn, {parser, option, value});
}
Variant xml_parser_get_option(const XMLParser &parser, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2449]);
    }
    return call(fn, {parser.getObject(), option});
}
Variant xml_parser_get_option(const Variant &parser, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2449]);
    }
    return call(fn, {parser, option});
}
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
XMLWriter xmlwriter_open_uri(const Variant &uri) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2480]);
    }
    auto _rv = call(fn, {uri});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "xmlwriter_open_uri() returned false");
    }
    return XMLWriter(Object(std::move(_rv)));
}
XMLWriter xmlwriter_open_memory() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2481]);
    }
    auto _rv = call(fn, {});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "xmlwriter_open_memory() returned false");
    }
    return XMLWriter(Object(std::move(_rv)));
}
Variant xmlwriter_set_indent(const XMLWriter &writer, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2482]);
    }
    return call(fn, {writer.getObject(), enable});
}
Variant xmlwriter_set_indent(const Variant &writer, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2482]);
    }
    return call(fn, {writer, enable});
}
Variant xmlwriter_set_indent_string(const XMLWriter &writer, const Variant &indentation) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2483]);
    }
    return call(fn, {writer.getObject(), indentation});
}
Variant xmlwriter_set_indent_string(const Variant &writer, const Variant &indentation) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2483]);
    }
    return call(fn, {writer, indentation});
}
Variant xmlwriter_start_comment(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2484]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_start_comment(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2484]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_end_comment(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2485]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_comment(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2485]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_start_attribute(const XMLWriter &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2486]);
    }
    return call(fn, {writer.getObject(), name});
}
Variant xmlwriter_start_attribute(const Variant &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2486]);
    }
    return call(fn, {writer, name});
}
Variant xmlwriter_end_attribute(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2487]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_attribute(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2487]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_attribute(const XMLWriter &writer, const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2488]);
    }
    return call(fn, {writer.getObject(), name, value});
}
Variant xmlwriter_write_attribute(const Variant &writer, const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2488]);
    }
    return call(fn, {writer, name, value});
}
Variant xmlwriter_start_attribute_ns(const XMLWriter &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2489]);
    }
    return call(fn, {writer.getObject(), prefix, name, _namespace});
}
Variant xmlwriter_start_attribute_ns(const Variant &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2489]);
    }
    return call(fn, {writer, prefix, name, _namespace});
}
Variant xmlwriter_write_attribute_ns(const XMLWriter &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace,
                                     const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2490]);
    }
    return call(fn, {writer.getObject(), prefix, name, _namespace, value});
}
Variant xmlwriter_write_attribute_ns(const Variant &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace,
                                     const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2490]);
    }
    return call(fn, {writer, prefix, name, _namespace, value});
}
Variant xmlwriter_start_element(const XMLWriter &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2491]);
    }
    return call(fn, {writer.getObject(), name});
}
Variant xmlwriter_start_element(const Variant &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2491]);
    }
    return call(fn, {writer, name});
}
Variant xmlwriter_end_element(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2492]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_element(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2492]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_full_end_element(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2493]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_full_end_element(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2493]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_start_element_ns(const XMLWriter &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2494]);
    }
    return call(fn, {writer.getObject(), prefix, name, _namespace});
}
Variant xmlwriter_start_element_ns(const Variant &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2494]);
    }
    return call(fn, {writer, prefix, name, _namespace});
}
Variant xmlwriter_write_element(const XMLWriter &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2495]);
    }
    return call(fn, {writer.getObject(), name, content});
}
Variant xmlwriter_write_element(const Variant &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2495]);
    }
    return call(fn, {writer, name, content});
}
Variant xmlwriter_write_element_ns(const XMLWriter &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace,
                                   const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2496]);
    }
    return call(fn, {writer.getObject(), prefix, name, _namespace, content});
}
Variant xmlwriter_write_element_ns(const Variant &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace,
                                   const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2496]);
    }
    return call(fn, {writer, prefix, name, _namespace, content});
}
Variant xmlwriter_start_pi(const XMLWriter &writer, const Variant &target) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2497]);
    }
    return call(fn, {writer.getObject(), target});
}
Variant xmlwriter_start_pi(const Variant &writer, const Variant &target) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2497]);
    }
    return call(fn, {writer, target});
}
Variant xmlwriter_end_pi(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2498]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_pi(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2498]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_pi(const XMLWriter &writer, const Variant &target, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2499]);
    }
    return call(fn, {writer.getObject(), target, content});
}
Variant xmlwriter_write_pi(const Variant &writer, const Variant &target, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2499]);
    }
    return call(fn, {writer, target, content});
}
Variant xmlwriter_start_cdata(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2500]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_start_cdata(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2500]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_end_cdata(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2501]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_cdata(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2501]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_cdata(const XMLWriter &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2502]);
    }
    return call(fn, {writer.getObject(), content});
}
Variant xmlwriter_write_cdata(const Variant &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2502]);
    }
    return call(fn, {writer, content});
}
Variant xmlwriter_text(const XMLWriter &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2503]);
    }
    return call(fn, {writer.getObject(), content});
}
Variant xmlwriter_text(const Variant &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2503]);
    }
    return call(fn, {writer, content});
}
Variant xmlwriter_write_raw(const XMLWriter &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2504]);
    }
    return call(fn, {writer.getObject(), content});
}
Variant xmlwriter_write_raw(const Variant &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2504]);
    }
    return call(fn, {writer, content});
}
Variant xmlwriter_start_document(const XMLWriter &writer,
                                 const Variant &version,
                                 const Variant &encoding,
                                 const Variant &standalone) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2505]);
    }
    return call(fn, {writer.getObject(), version, encoding, standalone});
}
Variant xmlwriter_start_document(const Variant &writer,
                                 const Variant &version,
                                 const Variant &encoding,
                                 const Variant &standalone) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2505]);
    }
    return call(fn, {writer, version, encoding, standalone});
}
Variant xmlwriter_end_document(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2506]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_document(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2506]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_comment(const XMLWriter &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2507]);
    }
    return call(fn, {writer.getObject(), content});
}
Variant xmlwriter_write_comment(const Variant &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2507]);
    }
    return call(fn, {writer, content});
}
Variant xmlwriter_start_dtd(const XMLWriter &writer,
                            const Variant &qualified_name,
                            const Variant &public_id,
                            const Variant &system_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2508]);
    }
    return call(fn, {writer.getObject(), qualified_name, public_id, system_id});
}
Variant xmlwriter_start_dtd(const Variant &writer,
                            const Variant &qualified_name,
                            const Variant &public_id,
                            const Variant &system_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2508]);
    }
    return call(fn, {writer, qualified_name, public_id, system_id});
}
Variant xmlwriter_end_dtd(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2509]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_dtd(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2509]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_dtd(const XMLWriter &writer,
                            const Variant &name,
                            const Variant &public_id,
                            const Variant &system_id,
                            const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2510]);
    }
    return call(fn, {writer.getObject(), name, public_id, system_id, content});
}
Variant xmlwriter_write_dtd(const Variant &writer,
                            const Variant &name,
                            const Variant &public_id,
                            const Variant &system_id,
                            const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2510]);
    }
    return call(fn, {writer, name, public_id, system_id, content});
}
Variant xmlwriter_start_dtd_element(const XMLWriter &writer, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2511]);
    }
    return call(fn, {writer.getObject(), qualified_name});
}
Variant xmlwriter_start_dtd_element(const Variant &writer, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2511]);
    }
    return call(fn, {writer, qualified_name});
}
Variant xmlwriter_end_dtd_element(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2512]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_dtd_element(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2512]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_dtd_element(const XMLWriter &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2513]);
    }
    return call(fn, {writer.getObject(), name, content});
}
Variant xmlwriter_write_dtd_element(const Variant &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2513]);
    }
    return call(fn, {writer, name, content});
}
Variant xmlwriter_start_dtd_attlist(const XMLWriter &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2514]);
    }
    return call(fn, {writer.getObject(), name});
}
Variant xmlwriter_start_dtd_attlist(const Variant &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2514]);
    }
    return call(fn, {writer, name});
}
Variant xmlwriter_end_dtd_attlist(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2515]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_dtd_attlist(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2515]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_dtd_attlist(const XMLWriter &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2516]);
    }
    return call(fn, {writer.getObject(), name, content});
}
Variant xmlwriter_write_dtd_attlist(const Variant &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2516]);
    }
    return call(fn, {writer, name, content});
}
Variant xmlwriter_start_dtd_entity(const XMLWriter &writer, const Variant &name, const Variant &is_param) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2517]);
    }
    return call(fn, {writer.getObject(), name, is_param});
}
Variant xmlwriter_start_dtd_entity(const Variant &writer, const Variant &name, const Variant &is_param) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2517]);
    }
    return call(fn, {writer, name, is_param});
}
Variant xmlwriter_end_dtd_entity(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2518]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_dtd_entity(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2518]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_dtd_entity(const XMLWriter &writer,
                                   const Variant &name,
                                   const Variant &content,
                                   const Variant &is_param,
                                   const Variant &public_id,
                                   const Variant &system_id,
                                   const Variant &notation_data) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2519]);
    }
    return call(fn, {writer.getObject(), name, content, is_param, public_id, system_id, notation_data});
}
Variant xmlwriter_write_dtd_entity(const Variant &writer,
                                   const Variant &name,
                                   const Variant &content,
                                   const Variant &is_param,
                                   const Variant &public_id,
                                   const Variant &system_id,
                                   const Variant &notation_data) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2519]);
    }
    return call(fn, {writer, name, content, is_param, public_id, system_id, notation_data});
}
Variant xmlwriter_output_memory(const XMLWriter &writer, const Variant &flush) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2520]);
    }
    return call(fn, {writer.getObject(), flush});
}
Variant xmlwriter_output_memory(const Variant &writer, const Variant &flush) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2520]);
    }
    return call(fn, {writer, flush});
}
Variant xmlwriter_flush(const XMLWriter &writer, const Variant &empty) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2521]);
    }
    return call(fn, {writer.getObject(), empty});
}
Variant xmlwriter_flush(const Variant &writer, const Variant &empty) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2521]);
    }
    return call(fn, {writer, empty});
}
}  // namespace php

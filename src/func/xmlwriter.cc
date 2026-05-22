#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
XMLWriter xmlwriter_open_uri(const Variant &uri) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2788]);
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
        fn = getFunction(LITERAL_STRING[2789]);
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
        fn = getFunction(LITERAL_STRING[2790]);
    }
    return call(fn, {writer.getObject(), enable});
}
Variant xmlwriter_set_indent(const Variant &writer, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2790]);
    }
    return call(fn, {writer, enable});
}
Variant xmlwriter_set_indent_string(const XMLWriter &writer, const Variant &indentation) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2791]);
    }
    return call(fn, {writer.getObject(), indentation});
}
Variant xmlwriter_set_indent_string(const Variant &writer, const Variant &indentation) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2791]);
    }
    return call(fn, {writer, indentation});
}
Variant xmlwriter_start_comment(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2792]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_start_comment(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2792]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_end_comment(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2793]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_comment(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2793]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_start_attribute(const XMLWriter &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2794]);
    }
    return call(fn, {writer.getObject(), name});
}
Variant xmlwriter_start_attribute(const Variant &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2794]);
    }
    return call(fn, {writer, name});
}
Variant xmlwriter_end_attribute(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2795]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_attribute(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2795]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_attribute(const XMLWriter &writer, const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2796]);
    }
    return call(fn, {writer.getObject(), name, value});
}
Variant xmlwriter_write_attribute(const Variant &writer, const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2796]);
    }
    return call(fn, {writer, name, value});
}
Variant xmlwriter_start_attribute_ns(const XMLWriter &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &namespace_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2797]);
    }
    return call(fn, {writer.getObject(), prefix, name, namespace_});
}
Variant xmlwriter_start_attribute_ns(const Variant &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &namespace_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2797]);
    }
    return call(fn, {writer, prefix, name, namespace_});
}
Variant xmlwriter_write_attribute_ns(const XMLWriter &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &namespace_,
                                     const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2798]);
    }
    return call(fn, {writer.getObject(), prefix, name, namespace_, value});
}
Variant xmlwriter_write_attribute_ns(const Variant &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &namespace_,
                                     const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2798]);
    }
    return call(fn, {writer, prefix, name, namespace_, value});
}
Variant xmlwriter_start_element(const XMLWriter &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2799]);
    }
    return call(fn, {writer.getObject(), name});
}
Variant xmlwriter_start_element(const Variant &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2799]);
    }
    return call(fn, {writer, name});
}
Variant xmlwriter_end_element(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2800]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_element(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2800]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_full_end_element(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2801]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_full_end_element(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2801]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_start_element_ns(const XMLWriter &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &namespace_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2802]);
    }
    return call(fn, {writer.getObject(), prefix, name, namespace_});
}
Variant xmlwriter_start_element_ns(const Variant &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &namespace_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2802]);
    }
    return call(fn, {writer, prefix, name, namespace_});
}
Variant xmlwriter_write_element(const XMLWriter &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2803]);
    }
    return call(fn, {writer.getObject(), name, content});
}
Variant xmlwriter_write_element(const Variant &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2803]);
    }
    return call(fn, {writer, name, content});
}
Variant xmlwriter_write_element_ns(const XMLWriter &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &namespace_,
                                   const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2804]);
    }
    return call(fn, {writer.getObject(), prefix, name, namespace_, content});
}
Variant xmlwriter_write_element_ns(const Variant &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &namespace_,
                                   const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2804]);
    }
    return call(fn, {writer, prefix, name, namespace_, content});
}
Variant xmlwriter_start_pi(const XMLWriter &writer, const Variant &target) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2805]);
    }
    return call(fn, {writer.getObject(), target});
}
Variant xmlwriter_start_pi(const Variant &writer, const Variant &target) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2805]);
    }
    return call(fn, {writer, target});
}
Variant xmlwriter_end_pi(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2806]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_pi(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2806]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_pi(const XMLWriter &writer, const Variant &target, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2807]);
    }
    return call(fn, {writer.getObject(), target, content});
}
Variant xmlwriter_write_pi(const Variant &writer, const Variant &target, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2807]);
    }
    return call(fn, {writer, target, content});
}
Variant xmlwriter_start_cdata(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2808]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_start_cdata(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2808]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_end_cdata(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2809]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_cdata(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2809]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_cdata(const XMLWriter &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2810]);
    }
    return call(fn, {writer.getObject(), content});
}
Variant xmlwriter_write_cdata(const Variant &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2810]);
    }
    return call(fn, {writer, content});
}
Variant xmlwriter_text(const XMLWriter &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2811]);
    }
    return call(fn, {writer.getObject(), content});
}
Variant xmlwriter_text(const Variant &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2811]);
    }
    return call(fn, {writer, content});
}
Variant xmlwriter_write_raw(const XMLWriter &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2812]);
    }
    return call(fn, {writer.getObject(), content});
}
Variant xmlwriter_write_raw(const Variant &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2812]);
    }
    return call(fn, {writer, content});
}
Variant xmlwriter_start_document(const XMLWriter &writer,
                                 const Variant &version,
                                 const Variant &encoding,
                                 const Variant &standalone) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2813]);
    }
    return call(fn, {writer.getObject(), version, encoding, standalone});
}
Variant xmlwriter_start_document(const Variant &writer,
                                 const Variant &version,
                                 const Variant &encoding,
                                 const Variant &standalone) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2813]);
    }
    return call(fn, {writer, version, encoding, standalone});
}
Variant xmlwriter_end_document(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2814]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_document(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2814]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_comment(const XMLWriter &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2815]);
    }
    return call(fn, {writer.getObject(), content});
}
Variant xmlwriter_write_comment(const Variant &writer, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2815]);
    }
    return call(fn, {writer, content});
}
Variant xmlwriter_start_dtd(const XMLWriter &writer,
                            const Variant &qualified_name,
                            const Variant &public_id,
                            const Variant &system_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2816]);
    }
    return call(fn, {writer.getObject(), qualified_name, public_id, system_id});
}
Variant xmlwriter_start_dtd(const Variant &writer,
                            const Variant &qualified_name,
                            const Variant &public_id,
                            const Variant &system_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2816]);
    }
    return call(fn, {writer, qualified_name, public_id, system_id});
}
Variant xmlwriter_end_dtd(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2817]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_dtd(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2817]);
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
        fn = getFunction(LITERAL_STRING[2818]);
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
        fn = getFunction(LITERAL_STRING[2818]);
    }
    return call(fn, {writer, name, public_id, system_id, content});
}
Variant xmlwriter_start_dtd_element(const XMLWriter &writer, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2819]);
    }
    return call(fn, {writer.getObject(), qualified_name});
}
Variant xmlwriter_start_dtd_element(const Variant &writer, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2819]);
    }
    return call(fn, {writer, qualified_name});
}
Variant xmlwriter_end_dtd_element(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2820]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_dtd_element(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2820]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_dtd_element(const XMLWriter &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2821]);
    }
    return call(fn, {writer.getObject(), name, content});
}
Variant xmlwriter_write_dtd_element(const Variant &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2821]);
    }
    return call(fn, {writer, name, content});
}
Variant xmlwriter_start_dtd_attlist(const XMLWriter &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2822]);
    }
    return call(fn, {writer.getObject(), name});
}
Variant xmlwriter_start_dtd_attlist(const Variant &writer, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2822]);
    }
    return call(fn, {writer, name});
}
Variant xmlwriter_end_dtd_attlist(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2823]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_dtd_attlist(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2823]);
    }
    return call(fn, {writer});
}
Variant xmlwriter_write_dtd_attlist(const XMLWriter &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2824]);
    }
    return call(fn, {writer.getObject(), name, content});
}
Variant xmlwriter_write_dtd_attlist(const Variant &writer, const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2824]);
    }
    return call(fn, {writer, name, content});
}
Variant xmlwriter_start_dtd_entity(const XMLWriter &writer, const Variant &name, const Variant &is_param) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2825]);
    }
    return call(fn, {writer.getObject(), name, is_param});
}
Variant xmlwriter_start_dtd_entity(const Variant &writer, const Variant &name, const Variant &is_param) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2825]);
    }
    return call(fn, {writer, name, is_param});
}
Variant xmlwriter_end_dtd_entity(const XMLWriter &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2826]);
    }
    return call(fn, {writer.getObject()});
}
Variant xmlwriter_end_dtd_entity(const Variant &writer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2826]);
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
        fn = getFunction(LITERAL_STRING[2827]);
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
        fn = getFunction(LITERAL_STRING[2827]);
    }
    return call(fn, {writer, name, content, is_param, public_id, system_id, notation_data});
}
Variant xmlwriter_output_memory(const XMLWriter &writer, const Variant &flush) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2828]);
    }
    return call(fn, {writer.getObject(), flush});
}
Variant xmlwriter_output_memory(const Variant &writer, const Variant &flush) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2828]);
    }
    return call(fn, {writer, flush});
}
Variant xmlwriter_flush(const XMLWriter &writer, const Variant &empty) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2829]);
    }
    return call(fn, {writer.getObject(), empty});
}
Variant xmlwriter_flush(const Variant &writer, const Variant &empty) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2829]);
    }
    return call(fn, {writer, empty});
}
}  // namespace php

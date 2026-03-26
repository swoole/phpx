#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant xmlwriter_open_uri(const Variant &uri) {
    return call(LITERAL_STRING[2407], {uri});
}
Variant xmlwriter_open_memory() {
    return call(LITERAL_STRING[2408], {});
}
Variant xmlwriter_set_indent(const Variant &writer, const Variant &enable) {
    return call(LITERAL_STRING[2409], {writer, enable});
}
Variant xmlwriter_set_indent_string(const Variant &writer, const Variant &indentation) {
    return call(LITERAL_STRING[2410], {writer, indentation});
}
Variant xmlwriter_start_comment(const Variant &writer) {
    return call(LITERAL_STRING[2411], {writer});
}
Variant xmlwriter_end_comment(const Variant &writer) {
    return call(LITERAL_STRING[2412], {writer});
}
Variant xmlwriter_start_attribute(const Variant &writer, const Variant &name) {
    return call(LITERAL_STRING[2413], {writer, name});
}
Variant xmlwriter_end_attribute(const Variant &writer) {
    return call(LITERAL_STRING[2414], {writer});
}
Variant xmlwriter_write_attribute(const Variant &writer, const Variant &name, const Variant &value) {
    return call(LITERAL_STRING[2415], {writer, name, value});
}
Variant xmlwriter_start_attribute_ns(const Variant &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace) {
    return call(LITERAL_STRING[2416], {writer, prefix, name, _namespace});
}
Variant xmlwriter_write_attribute_ns(const Variant &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace,
                                     const Variant &value) {
    return call(LITERAL_STRING[2417], {writer, prefix, name, _namespace, value});
}
Variant xmlwriter_start_element(const Variant &writer, const Variant &name) {
    return call(LITERAL_STRING[2418], {writer, name});
}
Variant xmlwriter_end_element(const Variant &writer) {
    return call(LITERAL_STRING[2419], {writer});
}
Variant xmlwriter_full_end_element(const Variant &writer) {
    return call(LITERAL_STRING[2420], {writer});
}
Variant xmlwriter_start_element_ns(const Variant &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace) {
    return call(LITERAL_STRING[2421], {writer, prefix, name, _namespace});
}
Variant xmlwriter_write_element(const Variant &writer, const Variant &name, const Variant &content) {
    return call(LITERAL_STRING[2422], {writer, name, content});
}
Variant xmlwriter_write_element_ns(const Variant &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace,
                                   const Variant &content) {
    return call(LITERAL_STRING[2423], {writer, prefix, name, _namespace, content});
}
Variant xmlwriter_start_pi(const Variant &writer, const Variant &target) {
    return call(LITERAL_STRING[2424], {writer, target});
}
Variant xmlwriter_end_pi(const Variant &writer) {
    return call(LITERAL_STRING[2425], {writer});
}
Variant xmlwriter_write_pi(const Variant &writer, const Variant &target, const Variant &content) {
    return call(LITERAL_STRING[2426], {writer, target, content});
}
Variant xmlwriter_start_cdata(const Variant &writer) {
    return call(LITERAL_STRING[2427], {writer});
}
Variant xmlwriter_end_cdata(const Variant &writer) {
    return call(LITERAL_STRING[2428], {writer});
}
Variant xmlwriter_write_cdata(const Variant &writer, const Variant &content) {
    return call(LITERAL_STRING[2429], {writer, content});
}
Variant xmlwriter_text(const Variant &writer, const Variant &content) {
    return call(LITERAL_STRING[2430], {writer, content});
}
Variant xmlwriter_write_raw(const Variant &writer, const Variant &content) {
    return call(LITERAL_STRING[2431], {writer, content});
}
Variant xmlwriter_start_document(const Variant &writer,
                                 const Variant &version,
                                 const Variant &encoding,
                                 const Variant &standalone) {
    return call(LITERAL_STRING[2432], {writer, version, encoding, standalone});
}
Variant xmlwriter_end_document(const Variant &writer) {
    return call(LITERAL_STRING[2433], {writer});
}
Variant xmlwriter_write_comment(const Variant &writer, const Variant &content) {
    return call(LITERAL_STRING[2434], {writer, content});
}
Variant xmlwriter_start_dtd(const Variant &writer,
                            const Variant &qualified_name,
                            const Variant &public_id,
                            const Variant &system_id) {
    return call(LITERAL_STRING[2435], {writer, qualified_name, public_id, system_id});
}
Variant xmlwriter_end_dtd(const Variant &writer) {
    return call(LITERAL_STRING[2436], {writer});
}
Variant xmlwriter_write_dtd(const Variant &writer,
                            const Variant &name,
                            const Variant &public_id,
                            const Variant &system_id,
                            const Variant &content) {
    return call(LITERAL_STRING[2437], {writer, name, public_id, system_id, content});
}
Variant xmlwriter_start_dtd_element(const Variant &writer, const Variant &qualified_name) {
    return call(LITERAL_STRING[2438], {writer, qualified_name});
}
Variant xmlwriter_end_dtd_element(const Variant &writer) {
    return call(LITERAL_STRING[2439], {writer});
}
Variant xmlwriter_write_dtd_element(const Variant &writer, const Variant &name, const Variant &content) {
    return call(LITERAL_STRING[2440], {writer, name, content});
}
Variant xmlwriter_start_dtd_attlist(const Variant &writer, const Variant &name) {
    return call(LITERAL_STRING[2441], {writer, name});
}
Variant xmlwriter_end_dtd_attlist(const Variant &writer) {
    return call(LITERAL_STRING[2442], {writer});
}
Variant xmlwriter_write_dtd_attlist(const Variant &writer, const Variant &name, const Variant &content) {
    return call(LITERAL_STRING[2443], {writer, name, content});
}
Variant xmlwriter_start_dtd_entity(const Variant &writer, const Variant &name, const Variant &is_param) {
    return call(LITERAL_STRING[2444], {writer, name, is_param});
}
Variant xmlwriter_end_dtd_entity(const Variant &writer) {
    return call(LITERAL_STRING[2445], {writer});
}
Variant xmlwriter_write_dtd_entity(const Variant &writer,
                                   const Variant &name,
                                   const Variant &content,
                                   const Variant &is_param,
                                   const Variant &public_id,
                                   const Variant &system_id,
                                   const Variant &notation_data) {
    return call(LITERAL_STRING[2446], {writer, name, content, is_param, public_id, system_id, notation_data});
}
Variant xmlwriter_output_memory(const Variant &writer, const Variant &flush) {
    return call(LITERAL_STRING[2447], {writer, flush});
}
Variant xmlwriter_flush(const Variant &writer, const Variant &empty) {
    return call(LITERAL_STRING[2448], {writer, empty});
}
}  // namespace php

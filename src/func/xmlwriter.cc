#include "phpx.h"

namespace php {
Variant xmlwriter_open_uri(const Variant &uri) {
    return call("xmlwriter_open_uri", {uri});
}
Variant xmlwriter_open_memory() {
    return call("xmlwriter_open_memory", {});
}
Variant xmlwriter_set_indent(const Variant &writer, const Variant &enable) {
    return call("xmlwriter_set_indent", {writer, enable});
}
Variant xmlwriter_set_indent_string(const Variant &writer, const Variant &indentation) {
    return call("xmlwriter_set_indent_string", {writer, indentation});
}
Variant xmlwriter_start_comment(const Variant &writer) {
    return call("xmlwriter_start_comment", {writer});
}
Variant xmlwriter_end_comment(const Variant &writer) {
    return call("xmlwriter_end_comment", {writer});
}
Variant xmlwriter_start_attribute(const Variant &writer, const Variant &name) {
    return call("xmlwriter_start_attribute", {writer, name});
}
Variant xmlwriter_end_attribute(const Variant &writer) {
    return call("xmlwriter_end_attribute", {writer});
}
Variant xmlwriter_write_attribute(const Variant &writer, const Variant &name, const Variant &value) {
    return call("xmlwriter_write_attribute", {writer, name, value});
}
Variant xmlwriter_start_attribute_ns(const Variant &writer, const Variant &prefix, const Variant &name, const Variant &_namespace) {
    return call("xmlwriter_start_attribute_ns", {writer, prefix, name, _namespace});
}
Variant xmlwriter_write_attribute_ns(const Variant &writer, const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &value) {
    return call("xmlwriter_write_attribute_ns", {writer, prefix, name, _namespace, value});
}
Variant xmlwriter_start_element(const Variant &writer, const Variant &name) {
    return call("xmlwriter_start_element", {writer, name});
}
Variant xmlwriter_end_element(const Variant &writer) {
    return call("xmlwriter_end_element", {writer});
}
Variant xmlwriter_full_end_element(const Variant &writer) {
    return call("xmlwriter_full_end_element", {writer});
}
Variant xmlwriter_start_element_ns(const Variant &writer, const Variant &prefix, const Variant &name, const Variant &_namespace) {
    return call("xmlwriter_start_element_ns", {writer, prefix, name, _namespace});
}
Variant xmlwriter_write_element(const Variant &writer, const Variant &name, const Variant &content) {
    return call("xmlwriter_write_element", {writer, name, content});
}
Variant xmlwriter_write_element_ns(const Variant &writer, const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &content) {
    return call("xmlwriter_write_element_ns", {writer, prefix, name, _namespace, content});
}
Variant xmlwriter_start_pi(const Variant &writer, const Variant &target) {
    return call("xmlwriter_start_pi", {writer, target});
}
Variant xmlwriter_end_pi(const Variant &writer) {
    return call("xmlwriter_end_pi", {writer});
}
Variant xmlwriter_write_pi(const Variant &writer, const Variant &target, const Variant &content) {
    return call("xmlwriter_write_pi", {writer, target, content});
}
Variant xmlwriter_start_cdata(const Variant &writer) {
    return call("xmlwriter_start_cdata", {writer});
}
Variant xmlwriter_end_cdata(const Variant &writer) {
    return call("xmlwriter_end_cdata", {writer});
}
Variant xmlwriter_write_cdata(const Variant &writer, const Variant &content) {
    return call("xmlwriter_write_cdata", {writer, content});
}
Variant xmlwriter_text(const Variant &writer, const Variant &content) {
    return call("xmlwriter_text", {writer, content});
}
Variant xmlwriter_write_raw(const Variant &writer, const Variant &content) {
    return call("xmlwriter_write_raw", {writer, content});
}
Variant xmlwriter_start_document(const Variant &writer, const Variant &version, const Variant &encoding, const Variant &standalone) {
    return call("xmlwriter_start_document", {writer, version, encoding, standalone});
}
Variant xmlwriter_end_document(const Variant &writer) {
    return call("xmlwriter_end_document", {writer});
}
Variant xmlwriter_write_comment(const Variant &writer, const Variant &content) {
    return call("xmlwriter_write_comment", {writer, content});
}
Variant xmlwriter_start_dtd(const Variant &writer, const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    return call("xmlwriter_start_dtd", {writer, qualified_name, public_id, system_id});
}
Variant xmlwriter_end_dtd(const Variant &writer) {
    return call("xmlwriter_end_dtd", {writer});
}
Variant xmlwriter_write_dtd(const Variant &writer, const Variant &name, const Variant &public_id, const Variant &system_id, const Variant &content) {
    return call("xmlwriter_write_dtd", {writer, name, public_id, system_id, content});
}
Variant xmlwriter_start_dtd_element(const Variant &writer, const Variant &qualified_name) {
    return call("xmlwriter_start_dtd_element", {writer, qualified_name});
}
Variant xmlwriter_end_dtd_element(const Variant &writer) {
    return call("xmlwriter_end_dtd_element", {writer});
}
Variant xmlwriter_write_dtd_element(const Variant &writer, const Variant &name, const Variant &content) {
    return call("xmlwriter_write_dtd_element", {writer, name, content});
}
Variant xmlwriter_start_dtd_attlist(const Variant &writer, const Variant &name) {
    return call("xmlwriter_start_dtd_attlist", {writer, name});
}
Variant xmlwriter_end_dtd_attlist(const Variant &writer) {
    return call("xmlwriter_end_dtd_attlist", {writer});
}
Variant xmlwriter_write_dtd_attlist(const Variant &writer, const Variant &name, const Variant &content) {
    return call("xmlwriter_write_dtd_attlist", {writer, name, content});
}
Variant xmlwriter_start_dtd_entity(const Variant &writer, const Variant &name, const Variant &is_param) {
    return call("xmlwriter_start_dtd_entity", {writer, name, is_param});
}
Variant xmlwriter_end_dtd_entity(const Variant &writer) {
    return call("xmlwriter_end_dtd_entity", {writer});
}
Variant xmlwriter_write_dtd_entity(const Variant &writer, const Variant &name, const Variant &content, const Variant &is_param, const Variant &public_id, const Variant &system_id, const Variant &notation_data) {
    return call("xmlwriter_write_dtd_entity", {writer, name, content, is_param, public_id, system_id, notation_data});
}
Variant xmlwriter_output_memory(const Variant &writer, const Variant &flush) {
    return call("xmlwriter_output_memory", {writer, flush});
}
Variant xmlwriter_flush(const Variant &writer, const Variant &empty) {
    return call("xmlwriter_flush", {writer, empty});
}
}

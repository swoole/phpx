#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
XMLWriter xmlwriter_open_uri(const Variant &uri);
XMLWriter xmlwriter_open_memory();
Variant xmlwriter_set_indent(const XMLWriter &writer, const Variant &enable);
Variant xmlwriter_set_indent(const Variant &writer, const Variant &enable);
Variant xmlwriter_set_indent_string(const XMLWriter &writer, const Variant &indentation);
Variant xmlwriter_set_indent_string(const Variant &writer, const Variant &indentation);
Variant xmlwriter_start_comment(const XMLWriter &writer);
Variant xmlwriter_start_comment(const Variant &writer);
Variant xmlwriter_end_comment(const XMLWriter &writer);
Variant xmlwriter_end_comment(const Variant &writer);
Variant xmlwriter_start_attribute(const XMLWriter &writer, const Variant &name);
Variant xmlwriter_start_attribute(const Variant &writer, const Variant &name);
Variant xmlwriter_end_attribute(const XMLWriter &writer);
Variant xmlwriter_end_attribute(const Variant &writer);
Variant xmlwriter_write_attribute(const XMLWriter &writer, const Variant &name, const Variant &value);
Variant xmlwriter_write_attribute(const Variant &writer, const Variant &name, const Variant &value);
Variant xmlwriter_start_attribute_ns(const XMLWriter &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace);
Variant xmlwriter_start_attribute_ns(const Variant &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace);
Variant xmlwriter_write_attribute_ns(const XMLWriter &writer,
                                     const Variant &prefix,
                                     const Variant &name,
                                     const Variant &_namespace,
                                     const Variant &value);
Variant xmlwriter_write_attribute_ns(
    const Variant &writer, const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &value);
Variant xmlwriter_start_element(const XMLWriter &writer, const Variant &name);
Variant xmlwriter_start_element(const Variant &writer, const Variant &name);
Variant xmlwriter_end_element(const XMLWriter &writer);
Variant xmlwriter_end_element(const Variant &writer);
Variant xmlwriter_full_end_element(const XMLWriter &writer);
Variant xmlwriter_full_end_element(const Variant &writer);
Variant xmlwriter_start_element_ns(const XMLWriter &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace);
Variant xmlwriter_start_element_ns(const Variant &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace);
Variant xmlwriter_write_element(const XMLWriter &writer, const Variant &name, const Variant &content = {});
Variant xmlwriter_write_element(const Variant &writer, const Variant &name, const Variant &content = {});
Variant xmlwriter_write_element_ns(const XMLWriter &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace,
                                   const Variant &content = {});
Variant xmlwriter_write_element_ns(const Variant &writer,
                                   const Variant &prefix,
                                   const Variant &name,
                                   const Variant &_namespace,
                                   const Variant &content = {});
Variant xmlwriter_start_pi(const XMLWriter &writer, const Variant &target);
Variant xmlwriter_start_pi(const Variant &writer, const Variant &target);
Variant xmlwriter_end_pi(const XMLWriter &writer);
Variant xmlwriter_end_pi(const Variant &writer);
Variant xmlwriter_write_pi(const XMLWriter &writer, const Variant &target, const Variant &content);
Variant xmlwriter_write_pi(const Variant &writer, const Variant &target, const Variant &content);
Variant xmlwriter_start_cdata(const XMLWriter &writer);
Variant xmlwriter_start_cdata(const Variant &writer);
Variant xmlwriter_end_cdata(const XMLWriter &writer);
Variant xmlwriter_end_cdata(const Variant &writer);
Variant xmlwriter_write_cdata(const XMLWriter &writer, const Variant &content);
Variant xmlwriter_write_cdata(const Variant &writer, const Variant &content);
Variant xmlwriter_text(const XMLWriter &writer, const Variant &content);
Variant xmlwriter_text(const Variant &writer, const Variant &content);
Variant xmlwriter_write_raw(const XMLWriter &writer, const Variant &content);
Variant xmlwriter_write_raw(const Variant &writer, const Variant &content);
Variant xmlwriter_start_document(const XMLWriter &writer,
                                 const Variant &version = "1.0",
                                 const Variant &encoding = {},
                                 const Variant &standalone = {});
Variant xmlwriter_start_document(const Variant &writer,
                                 const Variant &version = "1.0",
                                 const Variant &encoding = {},
                                 const Variant &standalone = {});
Variant xmlwriter_end_document(const XMLWriter &writer);
Variant xmlwriter_end_document(const Variant &writer);
Variant xmlwriter_write_comment(const XMLWriter &writer, const Variant &content);
Variant xmlwriter_write_comment(const Variant &writer, const Variant &content);
Variant xmlwriter_start_dtd(const XMLWriter &writer,
                            const Variant &qualified_name,
                            const Variant &public_id = {},
                            const Variant &system_id = {});
Variant xmlwriter_start_dtd(const Variant &writer,
                            const Variant &qualified_name,
                            const Variant &public_id = {},
                            const Variant &system_id = {});
Variant xmlwriter_end_dtd(const XMLWriter &writer);
Variant xmlwriter_end_dtd(const Variant &writer);
Variant xmlwriter_write_dtd(const XMLWriter &writer,
                            const Variant &name,
                            const Variant &public_id = {},
                            const Variant &system_id = {},
                            const Variant &content = {});
Variant xmlwriter_write_dtd(const Variant &writer,
                            const Variant &name,
                            const Variant &public_id = {},
                            const Variant &system_id = {},
                            const Variant &content = {});
Variant xmlwriter_start_dtd_element(const XMLWriter &writer, const Variant &qualified_name);
Variant xmlwriter_start_dtd_element(const Variant &writer, const Variant &qualified_name);
Variant xmlwriter_end_dtd_element(const XMLWriter &writer);
Variant xmlwriter_end_dtd_element(const Variant &writer);
Variant xmlwriter_write_dtd_element(const XMLWriter &writer, const Variant &name, const Variant &content);
Variant xmlwriter_write_dtd_element(const Variant &writer, const Variant &name, const Variant &content);
Variant xmlwriter_start_dtd_attlist(const XMLWriter &writer, const Variant &name);
Variant xmlwriter_start_dtd_attlist(const Variant &writer, const Variant &name);
Variant xmlwriter_end_dtd_attlist(const XMLWriter &writer);
Variant xmlwriter_end_dtd_attlist(const Variant &writer);
Variant xmlwriter_write_dtd_attlist(const XMLWriter &writer, const Variant &name, const Variant &content);
Variant xmlwriter_write_dtd_attlist(const Variant &writer, const Variant &name, const Variant &content);
Variant xmlwriter_start_dtd_entity(const XMLWriter &writer, const Variant &name, const Variant &is_param);
Variant xmlwriter_start_dtd_entity(const Variant &writer, const Variant &name, const Variant &is_param);
Variant xmlwriter_end_dtd_entity(const XMLWriter &writer);
Variant xmlwriter_end_dtd_entity(const Variant &writer);
Variant xmlwriter_write_dtd_entity(const XMLWriter &writer,
                                   const Variant &name,
                                   const Variant &content,
                                   const Variant &is_param = false,
                                   const Variant &public_id = {},
                                   const Variant &system_id = {},
                                   const Variant &notation_data = {});
Variant xmlwriter_write_dtd_entity(const Variant &writer,
                                   const Variant &name,
                                   const Variant &content,
                                   const Variant &is_param = false,
                                   const Variant &public_id = {},
                                   const Variant &system_id = {},
                                   const Variant &notation_data = {});
Variant xmlwriter_output_memory(const XMLWriter &writer, const Variant &flush = true);
Variant xmlwriter_output_memory(const Variant &writer, const Variant &flush = true);
Variant xmlwriter_flush(const XMLWriter &writer, const Variant &empty = true);
Variant xmlwriter_flush(const Variant &writer, const Variant &empty = true);
}  // namespace php

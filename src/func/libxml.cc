#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant libxml_set_streams_context(const Variant &context) {
    return call(LITERAL_STRING[640], {context});
}
Variant libxml_use_internal_errors(const Variant &use_errors) {
    return call(LITERAL_STRING[641], {use_errors});
}
Variant libxml_get_last_error() {
    return call(LITERAL_STRING[642], {});
}
Variant libxml_get_errors() {
    return call(LITERAL_STRING[643], {});
}
Variant libxml_clear_errors() {
    return call(LITERAL_STRING[644], {});
}
Variant libxml_disable_entity_loader(const Variant &disable) {
    return call(LITERAL_STRING[645], {disable});
}
Variant libxml_set_external_entity_loader(const Variant &resolver_function) {
    return call(LITERAL_STRING[646], {resolver_function});
}
Variant libxml_get_external_entity_loader() {
    return call(LITERAL_STRING[647], {});
}
}  // namespace php

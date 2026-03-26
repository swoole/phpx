#include "phpx.h"

namespace php {
Variant libxml_set_streams_context(const Variant &context) {
    return call("libxml_set_streams_context", {context});
}
Variant libxml_use_internal_errors(const Variant &use_errors) {
    return call("libxml_use_internal_errors", {use_errors});
}
Variant libxml_get_last_error() {
    return call("libxml_get_last_error", {});
}
Variant libxml_get_errors() {
    return call("libxml_get_errors", {});
}
Variant libxml_clear_errors() {
    return call("libxml_clear_errors", {});
}
Variant libxml_disable_entity_loader(const Variant &disable) {
    return call("libxml_disable_entity_loader", {disable});
}
Variant libxml_set_external_entity_loader(const Variant &resolver_function) {
    return call("libxml_set_external_entity_loader", {resolver_function});
}
Variant libxml_get_external_entity_loader() {
    return call("libxml_get_external_entity_loader", {});
}
}

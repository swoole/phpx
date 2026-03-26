#include "phpx.h"

namespace php {
Variant simplexml_load_file(const Variant &filename, const Variant &class_name, const Variant &options, const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return call("simplexml_load_file", {filename, class_name, options, namespace_or_prefix, is_prefix});
}
Variant simplexml_load_string(const Variant &data, const Variant &class_name, const Variant &options, const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return call("simplexml_load_string", {data, class_name, options, namespace_or_prefix, is_prefix});
}
Variant simplexml_import_dom(const Variant &node, const Variant &class_name) {
    return call("simplexml_import_dom", {node, class_name});
}
}

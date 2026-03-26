#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant simplexml_load_file(const Variant &filename,
                            const Variant &class_name,
                            const Variant &options,
                            const Variant &namespace_or_prefix,
                            const Variant &is_prefix) {
    return call(LITERAL_STRING[1621], {filename, class_name, options, namespace_or_prefix, is_prefix});
}
Variant simplexml_load_string(const Variant &data,
                              const Variant &class_name,
                              const Variant &options,
                              const Variant &namespace_or_prefix,
                              const Variant &is_prefix) {
    return call(LITERAL_STRING[1622], {data, class_name, options, namespace_or_prefix, is_prefix});
}
Variant simplexml_import_dom(const Variant &node, const Variant &class_name) {
    return call(LITERAL_STRING[1623], {node, class_name});
}
}  // namespace php

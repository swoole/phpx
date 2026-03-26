#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant simplexml_load_file(const Variant &filename,
                            const Variant &class_name = "SimpleXMLElement",
                            const Variant &options = 0,
                            const Variant &namespace_or_prefix = "",
                            const Variant &is_prefix = false);
Variant simplexml_load_string(const Variant &data,
                              const Variant &class_name = "SimpleXMLElement",
                              const Variant &options = 0,
                              const Variant &namespace_or_prefix = "",
                              const Variant &is_prefix = false);
Variant simplexml_import_dom(const Variant &node, const Variant &class_name = "SimpleXMLElement");
}  // namespace php

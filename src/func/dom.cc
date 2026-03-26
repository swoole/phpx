#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant dom_import_simplexml(const Variant &node) {
    return call(LITERAL_STRING[309], {node});
}
Variant Dom_import_simplexml(const Variant &node) {
    return call(LITERAL_STRING[310], {node});
}
}  // namespace php

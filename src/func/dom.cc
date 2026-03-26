#include "phpx.h"

namespace php {
Variant dom_import_simplexml(const Variant &node) {
    return call("dom_import_simplexml", {node});
}
Variant Dom_import_simplexml(const Variant &node) {
    return call("Dom_import_simplexml", {node});
}
}

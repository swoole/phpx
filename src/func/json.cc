#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant json_encode(const Variant &value, const Variant &flags, const Variant &depth) {
    return call(LITERAL_STRING[634], {value, flags, depth});
}
Variant json_decode(const Variant &json, const Variant &associative, const Variant &depth, const Variant &flags) {
    return call(LITERAL_STRING[635], {json, associative, depth, flags});
}
Variant json_validate(const Variant &json, const Variant &depth, const Variant &flags) {
    return call(LITERAL_STRING[636], {json, depth, flags});
}
Variant json_last_error() {
    return call(LITERAL_STRING[637], {});
}
Variant json_last_error_msg() {
    return call(LITERAL_STRING[638], {});
}
}  // namespace php

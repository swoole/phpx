#include "phpx.h"

namespace php {
Variant json_encode(const Variant &value, const Variant &flags, const Variant &depth) {
    return call("json_encode", {value, flags, depth});
}
Variant json_decode(const Variant &json, const Variant &associative, const Variant &depth, const Variant &flags) {
    return call("json_decode", {json, associative, depth, flags});
}
Variant json_validate(const Variant &json, const Variant &depth, const Variant &flags) {
    return call("json_validate", {json, depth, flags});
}
Variant json_last_error() {
    return call("json_last_error", {});
}
Variant json_last_error_msg() {
    return call("json_last_error_msg", {});
}
}

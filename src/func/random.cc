#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant lcg_value() {
    return call(LITERAL_STRING[1010], {});
}
Variant mt_srand(const Variant &seed, const Variant &mode) {
    return call(LITERAL_STRING[1011], {seed, mode});
}
Variant srand(const Variant &seed, const Variant &mode) {
    return call(LITERAL_STRING[1012], {seed, mode});
}
Variant rand(const Variant &min, const Variant &max) {
    return call(LITERAL_STRING[1013], {min, max});
}
Variant mt_rand(const Variant &min, const Variant &max) {
    return call(LITERAL_STRING[1014], {min, max});
}
Variant mt_getrandmax() {
    return call(LITERAL_STRING[1015], {});
}
Variant getrandmax() {
    return call(LITERAL_STRING[1016], {});
}
Variant random_bytes(const Variant &length) {
    return call(LITERAL_STRING[1017], {length});
}
Variant random_int(const Variant &min, const Variant &max) {
    return call(LITERAL_STRING[1018], {min, max});
}
}  // namespace php

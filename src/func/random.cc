#include "phpx.h"

namespace php {
Variant lcg_value() {
    return call("lcg_value", {});
}
Variant mt_srand(const Variant &seed, const Variant &mode) {
    return call("mt_srand", {seed, mode});
}
Variant srand(const Variant &seed, const Variant &mode) {
    return call("srand", {seed, mode});
}
Variant rand(const Variant &min, const Variant &max) {
    return call("rand", {min, max});
}
Variant mt_rand(const Variant &min, const Variant &max) {
    return call("mt_rand", {min, max});
}
Variant mt_getrandmax() {
    return call("mt_getrandmax", {});
}
Variant getrandmax() {
    return call("getrandmax", {});
}
Variant random_bytes(const Variant &length) {
    return call("random_bytes", {length});
}
Variant random_int(const Variant &min, const Variant &max) {
    return call("random_int", {min, max});
}
}

#include "phpx.h"

namespace php {
Variant ctype_alnum(const Variant &text) {
    return call("ctype_alnum", {text});
}
Variant ctype_alpha(const Variant &text) {
    return call("ctype_alpha", {text});
}
Variant ctype_cntrl(const Variant &text) {
    return call("ctype_cntrl", {text});
}
Variant ctype_digit(const Variant &text) {
    return call("ctype_digit", {text});
}
Variant ctype_lower(const Variant &text) {
    return call("ctype_lower", {text});
}
Variant ctype_graph(const Variant &text) {
    return call("ctype_graph", {text});
}
Variant ctype_print(const Variant &text) {
    return call("ctype_print", {text});
}
Variant ctype_punct(const Variant &text) {
    return call("ctype_punct", {text});
}
Variant ctype_space(const Variant &text) {
    return call("ctype_space", {text});
}
Variant ctype_upper(const Variant &text) {
    return call("ctype_upper", {text});
}
Variant ctype_xdigit(const Variant &text) {
    return call("ctype_xdigit", {text});
}
}

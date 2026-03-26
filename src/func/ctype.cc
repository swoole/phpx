#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant ctype_alnum(const Variant &text) {
    return call(LITERAL_STRING[157], {text});
}
Variant ctype_alpha(const Variant &text) {
    return call(LITERAL_STRING[158], {text});
}
Variant ctype_cntrl(const Variant &text) {
    return call(LITERAL_STRING[159], {text});
}
Variant ctype_digit(const Variant &text) {
    return call(LITERAL_STRING[160], {text});
}
Variant ctype_lower(const Variant &text) {
    return call(LITERAL_STRING[161], {text});
}
Variant ctype_graph(const Variant &text) {
    return call(LITERAL_STRING[162], {text});
}
Variant ctype_print(const Variant &text) {
    return call(LITERAL_STRING[163], {text});
}
Variant ctype_punct(const Variant &text) {
    return call(LITERAL_STRING[164], {text});
}
Variant ctype_space(const Variant &text) {
    return call(LITERAL_STRING[165], {text});
}
Variant ctype_upper(const Variant &text) {
    return call(LITERAL_STRING[166], {text});
}
Variant ctype_xdigit(const Variant &text) {
    return call(LITERAL_STRING[167], {text});
}
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant ctype_alnum(const Variant &text);
Variant ctype_alpha(const Variant &text);
Variant ctype_cntrl(const Variant &text);
Variant ctype_digit(const Variant &text);
Variant ctype_lower(const Variant &text);
Variant ctype_graph(const Variant &text);
Variant ctype_print(const Variant &text);
Variant ctype_punct(const Variant &text);
Variant ctype_space(const Variant &text);
Variant ctype_upper(const Variant &text);
Variant ctype_xdigit(const Variant &text);
}  // namespace php

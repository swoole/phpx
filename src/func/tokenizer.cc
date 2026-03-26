#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant token_get_all(const Variant &code, const Variant &flags) {
    return call(LITERAL_STRING[2353], {code, flags});
}
Variant token_name(const Variant &id) {
    return call(LITERAL_STRING[2354], {id});
}
}  // namespace php

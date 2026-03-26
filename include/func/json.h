#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant json_encode(const Variant &value, const Variant &flags = 0, const Variant &depth = 512);
Variant json_decode(const Variant &json,
                    const Variant &associative = {},
                    const Variant &depth = 512,
                    const Variant &flags = 0);
Variant json_validate(const Variant &json, const Variant &depth = 512, const Variant &flags = 0);
Variant json_last_error();
Variant json_last_error_msg();
}  // namespace php

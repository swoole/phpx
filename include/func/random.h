#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant lcg_value();
Variant mt_srand(const Variant &seed = {}, const Variant &mode = 0);
Variant srand(const Variant &seed = {}, const Variant &mode = 0);
Variant rand(const Variant &min = {}, const Variant &max = {});
Variant mt_rand(const Variant &min = {}, const Variant &max = {});
Variant mt_getrandmax();
Variant getrandmax();
Variant random_bytes(const Variant &length);
Variant random_int(const Variant &min, const Variant &max);
}  // namespace php

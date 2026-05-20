#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant token_get_all(const Variant &code, const Variant &flags = 0);
Variant token_name(const Variant &id);
}  // namespace php

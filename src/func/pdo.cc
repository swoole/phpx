#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant pdo_drivers() {
    return call(LITERAL_STRING[819], {});
}
}  // namespace php

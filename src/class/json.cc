#include "phpx.h"
#include "phpx_class.h"
#include "class/json.h"

namespace php {
JsonException::JsonException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[672], {message, code, previous});
}
}  // namespace php

#include "phpx.h"
#include "class/sodium.h"
#include "class/core.h"

namespace php {
SodiumException::SodiumException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2013], {message, code, previous});
}
}  // namespace php

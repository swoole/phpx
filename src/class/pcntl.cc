#include "phpx.h"
#include "class/pcntl.h"

namespace php {
Variant Pcntl_QosClass::cases() {
    return php::call(LITERAL_STRING[806], {});
}
}  // namespace php

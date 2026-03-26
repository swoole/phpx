#include "phpx.h"
#include "class/hash.h"

namespace php {
Variant HashContext::__serialize() {
    return this_.exec(LITERAL_STRING[30], {});
}
Variant HashContext::__unserialize(const Variant &data) {
    return this_.exec(LITERAL_STRING[31], {data});
}
Variant HashContext::__debugInfo() {
    return this_.exec(LITERAL_STRING[126], {});
}
}  // namespace php

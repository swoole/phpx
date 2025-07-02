#include "phpx.h"
#include "class/hash.h"

namespace php {
Variant HashContext::__serialize() {
    return this_.exec("__serialize");
}

Variant HashContext::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}


}

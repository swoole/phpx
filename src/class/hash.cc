#include "phpx.h"
#include "class/hash.h"

namespace php {
Variant HashContext::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant HashContext::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}


}

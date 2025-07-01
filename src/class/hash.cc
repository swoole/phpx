#include "phpx.h"
#include "class/hash.h"

namespace php {
Variant HashContext::__serialize() {
    return _this.exec("__serialize");
}

Variant HashContext::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}


}

#include "phpx.h"

namespace php {
Variant pdo_drivers() {
    return call("pdo_drivers", {});
}
}

#include "phpx.h"

namespace php {
Variant token_get_all(const Variant &code, const Variant &flags) {
    return call("token_get_all", {code, flags});
}
Variant token_name(const Variant &id) {
    return call("token_name", {id});
}
}

#include "phpx.h"
#include "class/session.h"

namespace php {
Variant SessionHandler::open(const Variant &path, const Variant &name) {
    return this_.exec("open", path, name);
}

Variant SessionHandler::close() {
    return this_.exec("close");
}

Variant SessionHandler::read(const Variant &id) {
    return this_.exec("read", id);
}

Variant SessionHandler::write(const Variant &id, const Variant &data) {
    return this_.exec("write", id, data);
}

Variant SessionHandler::destroy(const Variant &id) {
    return this_.exec("destroy", id);
}

Variant SessionHandler::gc(const Variant &max_lifetime) {
    return this_.exec("gc", max_lifetime);
}

Variant SessionHandler::create_sid() {
    return this_.exec("create_sid");
}


}

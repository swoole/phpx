#include "phpx.h"
#include "class/session.h"

namespace php {
Variant SessionHandler::open(const Variant &path, const Variant &name) {
    return std::move(_this.exec("open", path, name));
}

Variant SessionHandler::close() {
    return std::move(_this.exec("close"));
}

Variant SessionHandler::read(const Variant &id) {
    return std::move(_this.exec("read", id));
}

Variant SessionHandler::write(const Variant &id, const Variant &data) {
    return std::move(_this.exec("write", id, data));
}

Variant SessionHandler::destroy(const Variant &id) {
    return std::move(_this.exec("destroy", id));
}

Variant SessionHandler::gc(const Variant &max_lifetime) {
    return std::move(_this.exec("gc", max_lifetime));
}

Variant SessionHandler::create_sid() {
    return std::move(_this.exec("create_sid"));
}


}

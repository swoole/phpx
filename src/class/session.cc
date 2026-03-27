#include "phpx.h"
#include "class/session.h"

namespace php {
Variant SessionHandler::open(const Variant &path, const Variant &name) {
    return this_.call(LITERAL_STRING[1173], {path, name});
}
Variant SessionHandler::close() {
    return this_.call(LITERAL_STRING[1068], {});
}
Variant SessionHandler::read(const Variant &id) {
    return this_.call(LITERAL_STRING[1615], {id});
}
Variant SessionHandler::write(const Variant &id, const Variant &data) {
    return this_.call(LITERAL_STRING[1616], {id, data});
}
Variant SessionHandler::destroy(const Variant &id) {
    return this_.call(LITERAL_STRING[1617], {id});
}
Variant SessionHandler::gc(const Variant &max_lifetime) {
    return this_.call(LITERAL_STRING[1618], {max_lifetime});
}
Variant SessionHandler::create_sid() {
    return this_.call(LITERAL_STRING[1619], {});
}
}  // namespace php

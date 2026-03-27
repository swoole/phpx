#include "phpx.h"
#include "class/fileinfo.h"

namespace php {
finfo::finfo(const Variant &flags, const Variant &magic_database) {
    this_ = newObject(LITERAL_STRING[498], {flags, magic_database});
}
Variant finfo::file(const Variant &filename, const Variant &flags, const Variant &context) {
    return this_.call(LITERAL_STRING[499], {filename, flags, context});
}
Variant finfo::buffer(const Variant &string, const Variant &flags, const Variant &context) {
    return this_.call(LITERAL_STRING[500], {string, flags, context});
}
Variant finfo::set_flags(const Variant &flags) {
    return this_.call(LITERAL_STRING[501], {flags});
}
}  // namespace php

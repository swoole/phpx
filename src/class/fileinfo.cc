#include "phpx.h"
#include "class/fileinfo.h"

namespace php {
finfo::finfo(const Variant &flags, const Variant &magic_database) {
    this_ = newObject("finfo", flags, magic_database);
}

Variant finfo::file(const Variant &filename, const Variant &flags, const Variant &context) {
    return this_.exec("file", filename, flags, context);
}

Variant finfo::buffer(const Variant &string, const Variant &flags, const Variant &context) {
    return this_.exec("buffer", string, flags, context);
}

Variant finfo::set_flags(const Variant &flags) {
    return this_.exec("set_flags", flags);
}


}

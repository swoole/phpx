#include "phpx.h"
#include "class/fileinfo.h"

namespace php {
finfo::finfo(const Variant &flags, const Variant &magic_database) {
    _this = newObject("finfo", flags, magic_database);
}

Variant finfo::file(const Variant &filename, const Variant &flags, const Variant &context) {
    return _this.exec("file", filename, flags, context);
}

Variant finfo::buffer(const Variant &string, const Variant &flags, const Variant &context) {
    return _this.exec("buffer", string, flags, context);
}

Variant finfo::set_flags(const Variant &flags) {
    return _this.exec("set_flags", flags);
}


}

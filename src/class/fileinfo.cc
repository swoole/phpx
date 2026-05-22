#include "phpx.h"
#include "phpx_class.h"
#include "class/fileinfo.h"

namespace php {
finfo::finfo(const Variant &flags, const Variant &magic_database) {
    this_ = newObject(LITERAL_STRING[553], {flags, magic_database});
}
Variant finfo::file(const Variant &filename, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[554]);
    }
    return this_.call(_method_fn, {filename, flags, context});
}
Variant finfo::buffer(const Variant &string, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[555]);
    }
    return this_.call(_method_fn, {string, flags, context});
}
Variant finfo::set_flags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[556]);
    }
    return this_.call(_method_fn, {flags});
}
}  // namespace php

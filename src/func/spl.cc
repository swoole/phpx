#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant class_implements(const Variant &object_or_class, const Variant &autoload) {
    return call(LITERAL_STRING[1672], {object_or_class, autoload});
}
Variant class_parents(const Variant &object_or_class, const Variant &autoload) {
    return call(LITERAL_STRING[1673], {object_or_class, autoload});
}
Variant class_uses(const Variant &object_or_class, const Variant &autoload) {
    return call(LITERAL_STRING[1674], {object_or_class, autoload});
}
Variant spl_autoload(const Variant &_class, const Variant &file_extensions) {
    return call(LITERAL_STRING[1675], {_class, file_extensions});
}
Variant spl_autoload_call(const Variant &_class) {
    return call(LITERAL_STRING[1676], {_class});
}
Variant spl_autoload_extensions(const Variant &file_extensions) {
    return call(LITERAL_STRING[1677], {file_extensions});
}
Variant spl_autoload_functions() {
    return call(LITERAL_STRING[1678], {});
}
Variant spl_autoload_register(const Variant &callback, const Variant &_throw, const Variant &prepend) {
    return call(LITERAL_STRING[1679], {callback, _throw, prepend});
}
Variant spl_autoload_unregister(const Variant &callback) {
    return call(LITERAL_STRING[1680], {callback});
}
Variant spl_classes() {
    return call(LITERAL_STRING[1681], {});
}
Variant spl_object_hash(const Variant &object) {
    return call(LITERAL_STRING[1682], {object});
}
Variant spl_object_id(const Variant &object) {
    return call(LITERAL_STRING[1683], {object});
}
Variant iterator_apply(const Variant &iterator, const Variant &callback, const Variant &args) {
    return call(LITERAL_STRING[1684], {iterator, callback, args});
}
Variant iterator_count(const Variant &iterator) {
    return call(LITERAL_STRING[1685], {iterator});
}
Variant iterator_to_array(const Variant &iterator, const Variant &preserve_keys) {
    return call(LITERAL_STRING[1686], {iterator, preserve_keys});
}
}  // namespace php

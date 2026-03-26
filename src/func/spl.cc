#include "phpx.h"

namespace php {
Variant class_implements(const Variant &object_or_class, const Variant &autoload) {
    return call("class_implements", {object_or_class, autoload});
}
Variant class_parents(const Variant &object_or_class, const Variant &autoload) {
    return call("class_parents", {object_or_class, autoload});
}
Variant class_uses(const Variant &object_or_class, const Variant &autoload) {
    return call("class_uses", {object_or_class, autoload});
}
Variant spl_autoload(const Variant &_class, const Variant &file_extensions) {
    return call("spl_autoload", {_class, file_extensions});
}
Variant spl_autoload_call(const Variant &_class) {
    return call("spl_autoload_call", {_class});
}
Variant spl_autoload_extensions(const Variant &file_extensions) {
    return call("spl_autoload_extensions", {file_extensions});
}
Variant spl_autoload_functions() {
    return call("spl_autoload_functions", {});
}
Variant spl_autoload_register(const Variant &callback, const Variant &_throw, const Variant &prepend) {
    return call("spl_autoload_register", {callback, _throw, prepend});
}
Variant spl_autoload_unregister(const Variant &callback) {
    return call("spl_autoload_unregister", {callback});
}
Variant spl_classes() {
    return call("spl_classes", {});
}
Variant spl_object_hash(const Variant &object) {
    return call("spl_object_hash", {object});
}
Variant spl_object_id(const Variant &object) {
    return call("spl_object_id", {object});
}
Variant iterator_apply(const Variant &iterator, const Variant &callback, const Variant &args) {
    return call("iterator_apply", {iterator, callback, args});
}
Variant iterator_count(const Variant &iterator) {
    return call("iterator_count", {iterator});
}
Variant iterator_to_array(const Variant &iterator, const Variant &preserve_keys) {
    return call("iterator_to_array", {iterator, preserve_keys});
}
}

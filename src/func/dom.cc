#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant dom_import_simplexml(const Variant &node) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[357]);
    }
    return call(_fn, {node});
}
}  // namespace php
namespace php::Dom {
Variant import_simplexml(const Variant &node) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[358]);
    }
    return call(_fn, {node});
}
}  // namespace php::Dom

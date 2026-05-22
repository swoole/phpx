#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant dom_import_simplexml(const Variant &node) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[329]);
    }
    return call(fn, {node});
}
}  // namespace php
namespace php::Dom {
Variant import_simplexml(const Variant &node) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[330]);
    }
    return call(fn, {node});
}
}  // namespace php::Dom

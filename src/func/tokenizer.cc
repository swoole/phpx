#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant token_get_all(const Variant &code, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3298]);
    }
    return call(_fn, {code, flags});
}
Variant token_name(const Variant &id) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3299]);
    }
    return call(_fn, {id});
}
}  // namespace php

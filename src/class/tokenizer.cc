#include "phpx.h"
#include "phpx_class.h"
#include "class/tokenizer.h"

namespace php {
Variant PhpToken::tokenize(const Variant &code, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2581], LITERAL_STRING[2582]);
    }
    return php::call(_method_fn, {code, flags});
}
PhpToken::PhpToken(const Variant &id, const Variant &text, const Variant &line, const Variant &pos) {
    this_ = newObject(LITERAL_STRING[2581], {id, text, line, pos});
}
Variant PhpToken::is(const Variant &kind) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2583]);
    }
    return this_.call(_method_fn, {kind});
}
Variant PhpToken::isIgnorable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2584]);
    }
    return this_.call(_method_fn, {});
}
Variant PhpToken::getTokenName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2585]);
    }
    return this_.call(_method_fn, {});
}
Variant PhpToken::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

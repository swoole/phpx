#include "phpx.h"
#include "class/tokenizer.h"

namespace php {
Variant PhpToken::tokenize(const Variant &code, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3301], LITERAL_STRING[3302]);
    }
    return php::call(_method_fn, {code, flags});
}
PhpToken::PhpToken(const Variant &id, const Variant &text, const Variant &line, const Variant &pos) {
    this_ = newObject(LITERAL_STRING[3301], {id, text, line, pos});
}
Variant PhpToken::is(const Variant &kind) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3303]);
    }
    return this_.call(_method_fn, {kind});
}
Variant PhpToken::isIgnorable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3304]);
    }
    return this_.call(_method_fn, {});
}
Variant PhpToken::getTokenName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3305]);
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

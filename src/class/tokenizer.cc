#include "phpx.h"
#include "class/tokenizer.h"

namespace php {
Variant PhpToken::tokenize(const Variant &code, const Variant &flags) {
    static Variant fn { ZEND_STRL("PhpToken::tokenize"), true };
    return fn(code, flags);
}

PhpToken::PhpToken(const Variant &id, const Variant &text, const Variant &line, const Variant &pos) {
    this_ = newObject("PhpToken", id, text, line, pos);
}

Variant PhpToken::is(const Variant &kind) {
    return this_.exec("is", kind);
}

Variant PhpToken::isIgnorable() {
    return this_.exec("isIgnorable");
}

Variant PhpToken::getTokenName() {
    return this_.exec("getTokenName");
}

Variant PhpToken::__toString() {
    return this_.exec("__toString");
}


}

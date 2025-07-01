#include "phpx.h"
#include "class/tokenizer.h"

namespace php {
Variant PhpToken::tokenize(const Variant &code, const Variant &flags) {
    static Variant fn { ZEND_STRL("PhpToken::tokenize"), true };
    return fn(code, flags);
}

PhpToken::PhpToken(const Variant &id, const Variant &text, const Variant &line, const Variant &pos) {
    _this = newObject("PhpToken", id, text, line, pos);
}

Variant PhpToken::is(const Variant &kind) {
    return _this.exec("is", kind);
}

Variant PhpToken::isIgnorable() {
    return _this.exec("isIgnorable");
}

Variant PhpToken::getTokenName() {
    return _this.exec("getTokenName");
}

Variant PhpToken::__toString() {
    return _this.exec("__toString");
}


}

#include "phpx.h"
#include "class/tokenizer.h"

namespace php {
Variant PhpToken::tokenize(const Variant &code, const Variant &flags) {
    return php::call(LITERAL_STRING[2355], {code, flags});
}
PhpToken::PhpToken(const Variant &id, const Variant &text, const Variant &line, const Variant &pos) {
    this_ = newObject(LITERAL_STRING[2356], {id, text, line, pos});
}
Variant PhpToken::is(const Variant &kind) {
    return this_.call(LITERAL_STRING[2357], {kind});
}
Variant PhpToken::isIgnorable() {
    return this_.call(LITERAL_STRING[2358], {});
}
Variant PhpToken::getTokenName() {
    return this_.call(LITERAL_STRING[2359], {});
}
Variant PhpToken::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
}  // namespace php

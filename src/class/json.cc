#include "phpx.h"
#include "class/json.h"

namespace php {
JsonException::JsonException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[639], {message, code, previous});
}
Variant JsonException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant JsonException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant JsonException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant JsonException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant JsonException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant JsonException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant JsonException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant JsonException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant JsonException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
}  // namespace php

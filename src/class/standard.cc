#include "phpx.h"
#include "class/standard.h"

namespace php {
AssertionError::AssertionError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2345], {message, code, previous});
}
Variant AssertionError::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant AssertionError::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant AssertionError::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant AssertionError::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant AssertionError::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant AssertionError::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant AssertionError::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant AssertionError::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant AssertionError::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant RoundingMode::cases() {
    return php::call(LITERAL_STRING[2346], {});
}
Variant php_user_filter::filter(const Variant &in,
                                const Variant &out,
                                const Reference &consumed,
                                const Variant &closing) {
    return this_.call(LITERAL_STRING[2348], {in, out, &consumed, closing});
}
Variant php_user_filter::onCreate() {
    return this_.call(LITERAL_STRING[2349], {});
}
Variant php_user_filter::onClose() {
    return this_.call(LITERAL_STRING[2350], {});
}
Variant Directory::close() {
    return this_.call(LITERAL_STRING[1068], {});
}
Variant Directory::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant Directory::read() {
    return this_.call(LITERAL_STRING[1615], {});
}
}  // namespace php

#include "phpx.h"
#include "class/standard.h"

namespace php {
AssertionError::AssertionError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("AssertionError", message, code, previous);
}

Variant AssertionError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant AssertionError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant AssertionError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant AssertionError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant AssertionError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant AssertionError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant AssertionError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant AssertionError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant AssertionError::__toString() {
    return std::move(_this.exec("__toString"));
}


Variant php_user_filter::filter(const Variant &in, const Variant &out, const Variant &consumed, const Variant &closing) {
    return std::move(_this.exec("filter", in, out, consumed, closing));
}

Variant php_user_filter::onCreate() {
    return std::move(_this.exec("onCreate"));
}

Variant php_user_filter::onClose() {
    return std::move(_this.exec("onClose"));
}


Variant Directory::close() {
    return std::move(_this.exec("close"));
}

Variant Directory::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant Directory::read() {
    return std::move(_this.exec("read"));
}


}

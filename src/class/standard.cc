#include "phpx.h"
#include "class/standard.h"

namespace php {
AssertionError::AssertionError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("AssertionError", message, code, previous);
}

Variant AssertionError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant AssertionError::getMessage() {
    return _this.exec("getMessage");
}

Variant AssertionError::getCode() {
    return _this.exec("getCode");
}

Variant AssertionError::getFile() {
    return _this.exec("getFile");
}

Variant AssertionError::getLine() {
    return _this.exec("getLine");
}

Variant AssertionError::getTrace() {
    return _this.exec("getTrace");
}

Variant AssertionError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant AssertionError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant AssertionError::__toString() {
    return _this.exec("__toString");
}


Variant php_user_filter::filter(const Variant &in, const Variant &out, const Variant &consumed, const Variant &closing) {
    return _this.exec("filter", in, out, consumed, closing);
}

Variant php_user_filter::onCreate() {
    return _this.exec("onCreate");
}

Variant php_user_filter::onClose() {
    return _this.exec("onClose");
}


Variant Directory::close() {
    return _this.exec("close");
}

Variant Directory::rewind() {
    return _this.exec("rewind");
}

Variant Directory::read() {
    return _this.exec("read");
}


}

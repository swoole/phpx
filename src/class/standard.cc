#include "phpx.h"
#include "class/standard.h"

namespace php {
AssertionError::AssertionError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("AssertionError", message, code, previous);
}

Variant AssertionError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant AssertionError::getMessage() {
    return this_.exec("getMessage");
}

Variant AssertionError::getCode() {
    return this_.exec("getCode");
}

Variant AssertionError::getFile() {
    return this_.exec("getFile");
}

Variant AssertionError::getLine() {
    return this_.exec("getLine");
}

Variant AssertionError::getTrace() {
    return this_.exec("getTrace");
}

Variant AssertionError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant AssertionError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant AssertionError::__toString() {
    return this_.exec("__toString");
}


Variant php_user_filter::filter(const Variant &in, const Variant &out, const Variant &consumed, const Variant &closing) {
    return this_.exec("filter", in, out, consumed, closing);
}

Variant php_user_filter::onCreate() {
    return this_.exec("onCreate");
}

Variant php_user_filter::onClose() {
    return this_.exec("onClose");
}


Variant Directory::close() {
    return this_.exec("close");
}

Variant Directory::rewind() {
    return this_.exec("rewind");
}

Variant Directory::read() {
    return this_.exec("read");
}


}

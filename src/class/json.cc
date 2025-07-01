#include "phpx.h"
#include "class/json.h"

namespace php {
JsonException::JsonException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("JsonException", message, code, previous);
}

Variant JsonException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant JsonException::getMessage() {
    return _this.exec("getMessage");
}

Variant JsonException::getCode() {
    return _this.exec("getCode");
}

Variant JsonException::getFile() {
    return _this.exec("getFile");
}

Variant JsonException::getLine() {
    return _this.exec("getLine");
}

Variant JsonException::getTrace() {
    return _this.exec("getTrace");
}

Variant JsonException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant JsonException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant JsonException::__toString() {
    return _this.exec("__toString");
}


}

#include "phpx.h"
#include "class/json.h"

namespace php {
JsonException::JsonException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("JsonException", message, code, previous);
}

Variant JsonException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant JsonException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant JsonException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant JsonException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant JsonException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant JsonException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant JsonException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant JsonException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant JsonException::__toString() {
    return std::move(_this.exec("__toString"));
}


}

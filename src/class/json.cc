#include "phpx.h"
#include "class/json.h"

namespace php {
JsonException::JsonException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("JsonException", message, code, previous);
}

Variant JsonException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant JsonException::getMessage() {
    return this_.exec("getMessage");
}

Variant JsonException::getCode() {
    return this_.exec("getCode");
}

Variant JsonException::getFile() {
    return this_.exec("getFile");
}

Variant JsonException::getLine() {
    return this_.exec("getLine");
}

Variant JsonException::getTrace() {
    return this_.exec("getTrace");
}

Variant JsonException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant JsonException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant JsonException::__toString() {
    return this_.exec("__toString");
}


}

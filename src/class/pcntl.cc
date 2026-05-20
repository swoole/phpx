#include "phpx.h"
#include "class/pcntl.h"

namespace php {
Pcntl_QosClass::Pcntl_QosClass() {
    this_ = newObject(LITERAL_STRING[843]);
}
Variant Pcntl_QosClass::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[845], LITERAL_STRING[334]);
    }
    return php::call(_method_fn, {});
}
}  // namespace php

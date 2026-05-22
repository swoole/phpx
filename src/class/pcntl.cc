#include "phpx.h"
#include "phpx_class.h"
#include "class/pcntl.h"

namespace php::Pcntl {
QosClass::QosClass() {
    this_ = newObject(LITERAL_STRING[1019]);
}
Variant QosClass::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1019], LITERAL_STRING[333]);
    }
    return php::call(_method_fn, {});
}
}  // namespace php::Pcntl

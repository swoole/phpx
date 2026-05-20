#include "phpx.h"
#include "class/spl.h"

namespace php {
LogicException::LogicException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1749], {message, code, previous});
}
Variant LogicException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant LogicException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant LogicException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant LogicException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant LogicException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant LogicException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant LogicException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant LogicException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant LogicException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
BadFunctionCallException::BadFunctionCallException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1750], {message, code, previous});
}
Variant BadFunctionCallException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant BadFunctionCallException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant BadFunctionCallException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant BadFunctionCallException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant BadFunctionCallException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant BadFunctionCallException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant BadFunctionCallException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant BadFunctionCallException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant BadFunctionCallException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
BadMethodCallException::BadMethodCallException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1751], {message, code, previous});
}
Variant BadMethodCallException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant BadMethodCallException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant BadMethodCallException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant BadMethodCallException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant BadMethodCallException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant BadMethodCallException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant BadMethodCallException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant BadMethodCallException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant BadMethodCallException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
DomainException::DomainException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1752], {message, code, previous});
}
Variant DomainException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant DomainException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant DomainException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant DomainException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant DomainException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant DomainException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant DomainException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant DomainException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant DomainException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
InvalidArgumentException::InvalidArgumentException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1753], {message, code, previous});
}
Variant InvalidArgumentException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant InvalidArgumentException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant InvalidArgumentException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant InvalidArgumentException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant InvalidArgumentException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant InvalidArgumentException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant InvalidArgumentException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant InvalidArgumentException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant InvalidArgumentException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
LengthException::LengthException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1754], {message, code, previous});
}
Variant LengthException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant LengthException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant LengthException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant LengthException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant LengthException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant LengthException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant LengthException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant LengthException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant LengthException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
OutOfRangeException::OutOfRangeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1755], {message, code, previous});
}
Variant OutOfRangeException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfRangeException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfRangeException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfRangeException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfRangeException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfRangeException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfRangeException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfRangeException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfRangeException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
RuntimeException::RuntimeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1756], {message, code, previous});
}
Variant RuntimeException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant RuntimeException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant RuntimeException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant RuntimeException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant RuntimeException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant RuntimeException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant RuntimeException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant RuntimeException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant RuntimeException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
OutOfBoundsException::OutOfBoundsException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1757], {message, code, previous});
}
Variant OutOfBoundsException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfBoundsException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfBoundsException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfBoundsException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfBoundsException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfBoundsException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfBoundsException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfBoundsException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant OutOfBoundsException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
OverflowException::OverflowException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1758], {message, code, previous});
}
Variant OverflowException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant OverflowException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant OverflowException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant OverflowException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant OverflowException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant OverflowException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant OverflowException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant OverflowException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant OverflowException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
RangeException::RangeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1759], {message, code, previous});
}
Variant RangeException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant RangeException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant RangeException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant RangeException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant RangeException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant RangeException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant RangeException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant RangeException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant RangeException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
UnderflowException::UnderflowException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1760], {message, code, previous});
}
Variant UnderflowException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant UnderflowException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant UnderflowException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant UnderflowException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant UnderflowException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant UnderflowException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant UnderflowException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant UnderflowException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant UnderflowException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
UnexpectedValueException::UnexpectedValueException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1761], {message, code, previous});
}
Variant UnexpectedValueException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant UnexpectedValueException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant UnexpectedValueException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant UnexpectedValueException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant UnexpectedValueException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant UnexpectedValueException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant UnexpectedValueException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant UnexpectedValueException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant UnexpectedValueException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
RecursiveIteratorIterator::RecursiveIteratorIterator(const Variant &iterator,
                                                     const Variant &mode,
                                                     const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1762], {iterator, mode, flags});
}
Variant RecursiveIteratorIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::getDepth() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1763]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::getSubIterator(const Variant &level) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1764]);
    }
    return this_.call(_method_fn, {level});
}
Variant RecursiveIteratorIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::beginIteration() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1766]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::endIteration() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1767]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::callHasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1768]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::callGetChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1769]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::beginChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1770]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::endChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1771]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::nextElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1772]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::setMaxDepth(const Variant &max_depth) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1773]);
    }
    return this_.call(_method_fn, {max_depth});
}
Variant RecursiveIteratorIterator::getMaxDepth() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1774]);
    }
    return this_.call(_method_fn, {});
}
IteratorIterator::IteratorIterator(const Variant &iterator, const Variant &_class) {
    this_ = newObject(LITERAL_STRING[1775], {iterator, _class});
}
Variant IteratorIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
CallbackFilterIterator::CallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    this_ = newObject(LITERAL_STRING[1776], {iterator, callback});
}
Variant CallbackFilterIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1777]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
RecursiveCallbackFilterIterator::RecursiveCallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    this_ = newObject(LITERAL_STRING[1778], {iterator, callback});
}
Variant RecursiveCallbackFilterIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1777]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
ParentIterator::ParentIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[1779], {iterator});
}
Variant ParentIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1777]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
LimitIterator::LimitIterator(const Variant &iterator, const Variant &offset, const Variant &limit) {
    this_ = newObject(LITERAL_STRING[1780], {iterator, offset, limit});
}
Variant LimitIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant LimitIterator::getPosition() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1521]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
CachingIterator::CachingIterator(const Variant &iterator, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1781], {iterator, flags});
}
Variant CachingIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::hasNext() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1782]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant CachingIterator::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {key});
}
Variant CachingIterator::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant CachingIterator::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {key});
}
Variant CachingIterator::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {key});
}
Variant CachingIterator::getCache() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1783]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
RecursiveCachingIterator::RecursiveCachingIterator(const Variant &iterator, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1784], {iterator, flags});
}
Variant RecursiveCachingIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::hasNext() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1782]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant RecursiveCachingIterator::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {key});
}
Variant RecursiveCachingIterator::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RecursiveCachingIterator::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {key});
}
Variant RecursiveCachingIterator::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {key});
}
Variant RecursiveCachingIterator::getCache() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1783]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
NoRewindIterator::NoRewindIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[1785], {iterator});
}
Variant NoRewindIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
AppendIterator::AppendIterator() {
    this_ = newObject(LITERAL_STRING[1786], {});
}
Variant AppendIterator::append(const Variant &iterator) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
    }
    return this_.call(_method_fn, {iterator});
}
Variant AppendIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::getIteratorIndex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1787]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::getArrayIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1788]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
InfiniteIterator::InfiniteIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[1789], {iterator});
}
Variant InfiniteIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant InfiniteIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant InfiniteIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant InfiniteIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant InfiniteIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant InfiniteIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
RegexIterator::RegexIterator(const Variant &iterator,
                             const Variant &pattern,
                             const Variant &mode,
                             const Variant &flags,
                             const Variant &preg_flags) {
    this_ = newObject(LITERAL_STRING[1790], {iterator, pattern, mode, flags, preg_flags});
}
Variant RegexIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1777]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::getMode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1170]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::setMode(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1791]);
    }
    return this_.call(_method_fn, {mode});
}
Variant RegexIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant RegexIterator::getRegex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1792]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::getPregFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1793]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::setPregFlags(const Variant &preg_flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1794]);
    }
    return this_.call(_method_fn, {preg_flags});
}
Variant RegexIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
RecursiveRegexIterator::RecursiveRegexIterator(const Variant &iterator,
                                               const Variant &pattern,
                                               const Variant &mode,
                                               const Variant &flags,
                                               const Variant &preg_flags) {
    this_ = newObject(LITERAL_STRING[1795], {iterator, pattern, mode, flags, preg_flags});
}
Variant RecursiveRegexIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1777]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::getMode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1170]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::setMode(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1791]);
    }
    return this_.call(_method_fn, {mode});
}
Variant RecursiveRegexIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant RecursiveRegexIterator::getRegex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1792]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::getPregFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1793]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::setPregFlags(const Variant &preg_flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1794]);
    }
    return this_.call(_method_fn, {preg_flags});
}
Variant RecursiveRegexIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
EmptyIterator::EmptyIterator() {
    this_ = newObject(LITERAL_STRING[1796]);
}
Variant EmptyIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant EmptyIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant EmptyIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant EmptyIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant EmptyIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
RecursiveTreeIterator::RecursiveTreeIterator(const Variant &iterator,
                                             const Variant &flags,
                                             const Variant &caching_iterator_flags,
                                             const Variant &mode) {
    this_ = newObject(LITERAL_STRING[1797], {iterator, flags, caching_iterator_flags, mode});
}
Variant RecursiveTreeIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::getPrefix() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1798]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::setPostfix(const Variant &postfix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1799]);
    }
    return this_.call(_method_fn, {postfix});
}
Variant RecursiveTreeIterator::setPrefixPart(const Variant &part, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1800]);
    }
    return this_.call(_method_fn, {part, value});
}
Variant RecursiveTreeIterator::getEntry() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1801]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::getPostfix() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1802]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::getDepth() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1763]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::getSubIterator(const Variant &level) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1764]);
    }
    return this_.call(_method_fn, {level});
}
Variant RecursiveTreeIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::beginIteration() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1766]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::endIteration() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1767]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::callHasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1768]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::callGetChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1769]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::beginChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1770]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::endChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1771]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::nextElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1772]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::setMaxDepth(const Variant &max_depth) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1773]);
    }
    return this_.call(_method_fn, {max_depth});
}
Variant RecursiveTreeIterator::getMaxDepth() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1774]);
    }
    return this_.call(_method_fn, {});
}
ArrayObject::ArrayObject(const Variant &array, const Variant &flags, const Variant &iterator_class) {
    this_ = newObject(LITERAL_STRING[1803], {array, flags, iterator_class});
}
Variant ArrayObject::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayObject::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayObject::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant ArrayObject::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayObject::append(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
    }
    return this_.call(_method_fn, {value});
}
Variant ArrayObject::getArrayCopy() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1804]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayObject::asort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1805]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayObject::ksort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1806]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayObject::uasort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1807]);
    }
    return this_.call(_method_fn, {callback});
}
Variant ArrayObject::uksort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1808]);
    }
    return this_.call(_method_fn, {callback});
}
Variant ArrayObject::natsort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1809]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::natcasesort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1810]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {data});
}
Variant ArrayObject::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant ArrayObject::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::exchangeArray(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1813]);
    }
    return this_.call(_method_fn, {array});
}
Variant ArrayObject::setIteratorClass(const Variant &iterator_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1814]);
    }
    return this_.call(_method_fn, {iterator_class});
}
Variant ArrayObject::getIteratorClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1815]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
_ArrayIterator::_ArrayIterator(const Variant &array, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1816], {array, flags});
}
Variant _ArrayIterator::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {key});
}
Variant _ArrayIterator::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {key});
}
Variant _ArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant _ArrayIterator::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {key});
}
Variant _ArrayIterator::append(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
    }
    return this_.call(_method_fn, {value});
}
Variant _ArrayIterator::getArrayCopy() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1804]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant _ArrayIterator::asort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1805]);
    }
    return this_.call(_method_fn, {flags});
}
Variant _ArrayIterator::ksort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1806]);
    }
    return this_.call(_method_fn, {flags});
}
Variant _ArrayIterator::uasort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1807]);
    }
    return this_.call(_method_fn, {callback});
}
Variant _ArrayIterator::uksort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1808]);
    }
    return this_.call(_method_fn, {callback});
}
Variant _ArrayIterator::natsort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1809]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::natcasesort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1810]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {data});
}
Variant _ArrayIterator::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant _ArrayIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant _ArrayIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant _ArrayIterator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
RecursiveArrayIterator::RecursiveArrayIterator(const Variant &array, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1817], {array, flags});
}
Variant RecursiveArrayIterator::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {key});
}
Variant RecursiveArrayIterator::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {key});
}
Variant RecursiveArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant RecursiveArrayIterator::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {key});
}
Variant RecursiveArrayIterator::append(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
    }
    return this_.call(_method_fn, {value});
}
Variant RecursiveArrayIterator::getArrayCopy() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1804]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant RecursiveArrayIterator::asort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1805]);
    }
    return this_.call(_method_fn, {flags});
}
Variant RecursiveArrayIterator::ksort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1806]);
    }
    return this_.call(_method_fn, {flags});
}
Variant RecursiveArrayIterator::uasort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1807]);
    }
    return this_.call(_method_fn, {callback});
}
Variant RecursiveArrayIterator::uksort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1808]);
    }
    return this_.call(_method_fn, {callback});
}
Variant RecursiveArrayIterator::natsort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1809]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::natcasesort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1810]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {data});
}
Variant RecursiveArrayIterator::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant RecursiveArrayIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant RecursiveArrayIterator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
SplFileInfo::SplFileInfo(const Variant &filename) {
    this_ = newObject(LITERAL_STRING[1818], {filename});
}
Variant SplFileInfo::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant SplFileInfo::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplFileInfo::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant SplFileInfo::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplFileInfo::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplFileInfo::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
DirectoryIterator::DirectoryIterator(const Variant &directory) {
    this_ = newObject(LITERAL_STRING[1819], {directory});
}
Variant DirectoryIterator::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant DirectoryIterator::isDot() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[978]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant DirectoryIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant DirectoryIterator::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant DirectoryIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant DirectoryIterator::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant DirectoryIterator::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant DirectoryIterator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
FilesystemIterator::FilesystemIterator(const Variant &directory, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1820], {directory, flags});
}
Variant FilesystemIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant FilesystemIterator::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant FilesystemIterator::isDot() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[978]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant FilesystemIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant FilesystemIterator::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant FilesystemIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant FilesystemIterator::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant FilesystemIterator::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant FilesystemIterator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
RecursiveDirectoryIterator::RecursiveDirectoryIterator(const Variant &directory, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1821], {directory, flags});
}
Variant RecursiveDirectoryIterator::hasChildren(const Variant &allow_links) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {allow_links});
}
Variant RecursiveDirectoryIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getSubPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[972]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getSubPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[973]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant RecursiveDirectoryIterator::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant RecursiveDirectoryIterator::isDot() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[978]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant RecursiveDirectoryIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant RecursiveDirectoryIterator::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant RecursiveDirectoryIterator::openFile(const Variant &mode,
                                             const Variant &use_include_path,
                                             const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant RecursiveDirectoryIterator::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant RecursiveDirectoryIterator::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant RecursiveDirectoryIterator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
GlobIterator::GlobIterator(const Variant &pattern, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1822], {pattern, flags});
}
Variant GlobIterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant GlobIterator::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant GlobIterator::isDot() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[978]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant GlobIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant GlobIterator::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant GlobIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant GlobIterator::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant GlobIterator::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant GlobIterator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant GlobIterator::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
SplFileObject::SplFileObject(const Variant &filename,
                             const Variant &mode,
                             const Variant &use_include_path,
                             const Variant &context) {
    this_ = newObject(LITERAL_STRING[1823], {filename, mode, use_include_path, context});
}
Variant SplFileObject::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::eof() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1824]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fgets() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1825]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fread(const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1826]);
    }
    return this_.call(_method_fn, {length});
}
Variant SplFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1827]);
    }
    return this_.call(_method_fn, {separator, enclosure, escape});
}
Variant SplFileObject::fputcsv(const Variant &fields,
                               const Variant &separator,
                               const Variant &enclosure,
                               const Variant &escape,
                               const Variant &eol) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1828]);
    }
    return this_.call(_method_fn, {fields, separator, enclosure, escape, eol});
}
Variant SplFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1829]);
    }
    return this_.call(_method_fn, {separator, enclosure, escape});
}
Variant SplFileObject::getCsvControl() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1830]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::flock(const Variant &operation, const Reference &would_block) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1831]);
    }
    return this_.call(_method_fn, {operation, &would_block});
}
Variant SplFileObject::fflush() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1832]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::ftell() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1833]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fseek(const Variant &offset, const Variant &whence) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1834]);
    }
    return this_.call(_method_fn, {offset, whence});
}
Variant SplFileObject::fgetc() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1835]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fpassthru() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1836]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fwrite(const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1838]);
    }
    return this_.call(_method_fn, {data, length});
}
Variant SplFileObject::fstat() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1839]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::ftruncate(const Variant &size) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1840]);
    }
    return this_.call(_method_fn, {size});
}
Variant SplFileObject::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant SplFileObject::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::setMaxLineLen(const Variant &max_length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1841]);
    }
    return this_.call(_method_fn, {max_length});
}
Variant SplFileObject::getMaxLineLen() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1842]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::seek(const Variant &line) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {line});
}
Variant SplFileObject::getCurrentLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1843]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant SplFileObject::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplFileObject::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant SplFileObject::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplFileObject::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplFileObject::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
SplTempFileObject::SplTempFileObject(const Variant &max_memory) {
    this_ = newObject(LITERAL_STRING[1844], {max_memory});
}
Variant SplTempFileObject::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::eof() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1824]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::fgets() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1825]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::fread(const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1826]);
    }
    return this_.call(_method_fn, {length});
}
Variant SplTempFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1827]);
    }
    return this_.call(_method_fn, {separator, enclosure, escape});
}
Variant SplTempFileObject::fputcsv(const Variant &fields,
                                   const Variant &separator,
                                   const Variant &enclosure,
                                   const Variant &escape,
                                   const Variant &eol) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1828]);
    }
    return this_.call(_method_fn, {fields, separator, enclosure, escape, eol});
}
Variant SplTempFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1829]);
    }
    return this_.call(_method_fn, {separator, enclosure, escape});
}
Variant SplTempFileObject::getCsvControl() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1830]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::flock(const Variant &operation, const Reference &would_block) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1831]);
    }
    return this_.call(_method_fn, {operation, &would_block});
}
Variant SplTempFileObject::fflush() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1832]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::ftell() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1833]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::fseek(const Variant &offset, const Variant &whence) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1834]);
    }
    return this_.call(_method_fn, {offset, whence});
}
Variant SplTempFileObject::fgetc() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1835]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::fpassthru() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1836]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::fwrite(const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1838]);
    }
    return this_.call(_method_fn, {data, length});
}
Variant SplTempFileObject::fstat() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1839]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::ftruncate(const Variant &size) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1840]);
    }
    return this_.call(_method_fn, {size});
}
Variant SplTempFileObject::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant SplTempFileObject::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::setMaxLineLen(const Variant &max_length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1841]);
    }
    return this_.call(_method_fn, {max_length});
}
Variant SplTempFileObject::getMaxLineLen() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1842]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::seek(const Variant &line) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {line});
}
Variant SplTempFileObject::getCurrentLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1843]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant SplTempFileObject::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplTempFileObject::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplTempFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant SplTempFileObject::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplTempFileObject::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant SplTempFileObject::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant SplTempFileObject::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
SplDoublyLinkedList::SplDoublyLinkedList() {
    this_ = newObject(LITERAL_STRING[1845]);
}
Variant SplDoublyLinkedList::add(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplDoublyLinkedList::pop() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1846]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::shift() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1847]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::push(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1848]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplDoublyLinkedList::unshift(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1849]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplDoublyLinkedList::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1850]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::bottom() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1851]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1852]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::setIteratorMode(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1853]);
    }
    return this_.call(_method_fn, {mode});
}
Variant SplDoublyLinkedList::getIteratorMode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1854]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::offsetExists(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplDoublyLinkedList::offsetGet(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplDoublyLinkedList::offsetSet(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplDoublyLinkedList::offsetUnset(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplDoublyLinkedList::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::prev() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1855]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplDoublyLinkedList::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
SplQueue::SplQueue() {
    this_ = newObject(LITERAL_STRING[1856]);
}
Variant SplQueue::enqueue(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1857]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplQueue::dequeue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1858]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::add(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplQueue::pop() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1846]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::shift() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1847]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::push(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1848]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplQueue::unshift(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1849]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplQueue::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1850]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::bottom() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1851]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1852]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::setIteratorMode(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1853]);
    }
    return this_.call(_method_fn, {mode});
}
Variant SplQueue::getIteratorMode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1854]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::offsetExists(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplQueue::offsetGet(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplQueue::offsetSet(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplQueue::offsetUnset(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplQueue::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::prev() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1855]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplQueue::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant SplQueue::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
SplStack::SplStack() {
    this_ = newObject(LITERAL_STRING[1859]);
}
Variant SplStack::add(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplStack::pop() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1846]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::shift() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1847]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::push(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1848]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplStack::unshift(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1849]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplStack::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1850]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::bottom() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1851]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1852]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::setIteratorMode(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1853]);
    }
    return this_.call(_method_fn, {mode});
}
Variant SplStack::getIteratorMode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1854]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::offsetExists(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplStack::offsetGet(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplStack::offsetSet(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplStack::offsetUnset(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplStack::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::prev() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1855]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplStack::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant SplStack::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
SplMinHeap::SplMinHeap() {
    this_ = newObject(LITERAL_STRING[1860]);
}
Variant SplMinHeap::extract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1861]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::insert(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1862]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplMinHeap::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1850]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1852]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::recoverFromCorruption() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1863]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::isCorrupted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1864]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
SplMaxHeap::SplMaxHeap() {
    this_ = newObject(LITERAL_STRING[1865]);
}
Variant SplMaxHeap::extract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1861]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::insert(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1862]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplMaxHeap::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1850]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1852]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::recoverFromCorruption() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1863]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::isCorrupted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1864]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
SplPriorityQueue::SplPriorityQueue() {
    this_ = newObject(LITERAL_STRING[1866]);
}
Variant SplPriorityQueue::compare(const Variant &priority1, const Variant &priority2) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[28]);
    }
    return this_.call(_method_fn, {priority1, priority2});
}
Variant SplPriorityQueue::insert(const Variant &value, const Variant &priority) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1862]);
    }
    return this_.call(_method_fn, {value, priority});
}
Variant SplPriorityQueue::setExtractFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1867]);
    }
    return this_.call(_method_fn, {flags});
}
Variant SplPriorityQueue::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1850]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::extract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1861]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1852]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::recoverFromCorruption() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1863]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::isCorrupted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1864]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::getExtractFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1868]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
SplFixedArray::SplFixedArray(const Variant &size) {
    this_ = newObject(LITERAL_STRING[1869], {size});
}
Variant SplFixedArray::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplFixedArray::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::toArray() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1870]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::fromArray(const Variant &array, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1869], LITERAL_STRING[1872]);
    }
    return php::call(_method_fn, {array, preserve_keys});
}
Variant SplFixedArray::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::setSize(const Variant &size) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1873]);
    }
    return this_.call(_method_fn, {size});
}
Variant SplFixedArray::offsetExists(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplFixedArray::offsetGet(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplFixedArray::offsetSet(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplFixedArray::offsetUnset(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplFixedArray::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::jsonSerialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1874]);
    }
    return this_.call(_method_fn, {});
}
SplObjectStorage::SplObjectStorage() {
    this_ = newObject(LITERAL_STRING[1875]);
}
Variant SplObjectStorage::attach(const Variant &object, const Variant &info) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1876]);
    }
    return this_.call(_method_fn, {object, info});
}
Variant SplObjectStorage::detach(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1877]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::contains(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::addAll(const SplObjectStorage &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1878]);
    }
    return this_.call(_method_fn, {storage.getObject()});
}
Variant SplObjectStorage::addAll(const Variant &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1878]);
    }
    return this_.call(_method_fn, {storage});
}
Variant SplObjectStorage::removeAll(const SplObjectStorage &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1879]);
    }
    return this_.call(_method_fn, {storage.getObject()});
}
Variant SplObjectStorage::removeAll(const Variant &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1879]);
    }
    return this_.call(_method_fn, {storage});
}
Variant SplObjectStorage::removeAllExcept(const SplObjectStorage &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1880]);
    }
    return this_.call(_method_fn, {storage.getObject()});
}
Variant SplObjectStorage::removeAllExcept(const Variant &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1880]);
    }
    return this_.call(_method_fn, {storage});
}
Variant SplObjectStorage::getInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1881]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::setInfo(const Variant &info) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1882]);
    }
    return this_.call(_method_fn, {info});
}
Variant SplObjectStorage::count(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {mode});
}
Variant SplObjectStorage::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant SplObjectStorage::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplObjectStorage::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::offsetExists(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::offsetGet(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::offsetSet(const Variant &object, const Variant &info) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {object, info});
}
Variant SplObjectStorage::offsetUnset(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::getHash(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1883]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplObjectStorage::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
MultipleIterator::MultipleIterator(const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1884], {flags});
}
Variant MultipleIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant MultipleIterator::attachIterator(const Variant &iterator, const Variant &info) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1885]);
    }
    return this_.call(_method_fn, {iterator, info});
}
Variant MultipleIterator::detachIterator(const Variant &iterator) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1886]);
    }
    return this_.call(_method_fn, {iterator});
}
Variant MultipleIterator::containsIterator(const Variant &iterator) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1887]);
    }
    return this_.call(_method_fn, {iterator});
}
Variant MultipleIterator::countIterators() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1888]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

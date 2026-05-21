#include "phpx.h"
#include "phpx_class.h"
#include "class/core.h"

namespace php {
Variant InternalIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant InternalIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant InternalIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant InternalIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant InternalIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[96], {message, code, previous});
}
Variant Exception::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant Exception::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant Exception::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant Exception::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant Exception::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant Exception::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant Exception::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant Exception::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant Exception::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
ErrorException::ErrorException(const Variant &message,
                               const Variant &code,
                               const Variant &severity,
                               const Variant &filename,
                               const Variant &line,
                               const Variant &previous) {
    this_ = newObject(LITERAL_STRING[105], {message, code, severity, filename, line, previous});
}
Variant ErrorException::getSeverity() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[106]);
    }
    return this_.call(_method_fn, {});
}
Error::Error(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[107], {message, code, previous});
}
Variant Error::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant Error::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant Error::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant Error::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant Error::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant Error::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant Error::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant Error::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant Error::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
CompileError::CompileError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[108], {message, code, previous});
}
ParseError::ParseError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[109], {message, code, previous});
}
TypeError::TypeError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[110], {message, code, previous});
}
ArgumentCountError::ArgumentCountError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[111], {message, code, previous});
}
ValueError::ValueError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[112], {message, code, previous});
}
ArithmeticError::ArithmeticError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[113], {message, code, previous});
}
DivisionByZeroError::DivisionByZeroError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[114], {message, code, previous});
}
UnhandledMatchError::UnhandledMatchError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[115], {message, code, previous});
}
RequestParseBodyException::RequestParseBodyException(const Variant &message,
                                                     const Variant &code,
                                                     const Variant &previous) {
    this_ = newObject(LITERAL_STRING[116], {message, code, previous});
}
Variant Closure::bind(const Closure &closure, const Variant &new_this, const Variant &new_scope) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[118], LITERAL_STRING[119]);
    }
    return php::call(_method_fn, {closure.getObject(), new_this, new_scope});
}
Variant Closure::bind(const Variant &closure, const Variant &new_this, const Variant &new_scope) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[118], LITERAL_STRING[119]);
    }
    return php::call(_method_fn, {closure, new_this, new_scope});
}
Variant Closure::bindTo(const Variant &new_this, const Variant &new_scope) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {new_this, new_scope});
}
Variant Closure::fromCallable(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[118], LITERAL_STRING[123]);
    }
    return php::call(_method_fn, {callback});
}
Variant Closure::__invoke() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[124]);
    }
    return this_.call(_method_fn, {});
}
Generator::Generator() {
    this_ = newObject(LITERAL_STRING[125]);
}
Variant Generator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant Generator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant Generator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant Generator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant Generator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant Generator::send(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[126]);
    }
    return this_.call(_method_fn, {value});
}
Variant Generator::throw_(const Variant &exception) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[127]);
    }
    return this_.call(_method_fn, {exception});
}
Variant Generator::getReturn() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[128]);
    }
    return this_.call(_method_fn, {});
}
Variant Generator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
ClosedGeneratorException::ClosedGeneratorException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[130], {message, code, previous});
}
WeakReference::WeakReference() {
    this_ = newObject(LITERAL_STRING[131], {});
}
Variant WeakReference::create(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[131], LITERAL_STRING[133]);
    }
    return php::call(_method_fn, {object});
}
Variant WeakReference::get() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[134]);
    }
    return this_.call(_method_fn, {});
}
WeakMap::WeakMap() {
    this_ = newObject(LITERAL_STRING[135]);
}
Variant WeakMap::offsetGet(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {object});
}
Variant WeakMap::offsetSet(const Variant &object, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {object, value});
}
Variant WeakMap::offsetExists(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {object});
}
Variant WeakMap::offsetUnset(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {object});
}
Variant WeakMap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant WeakMap::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
Attribute::Attribute(const Variant &flags) {
    this_ = newObject(LITERAL_STRING[142], {flags});
}
ReturnTypeWillChange::ReturnTypeWillChange() {
    this_ = newObject(LITERAL_STRING[143], {});
}
AllowDynamicProperties::AllowDynamicProperties() {
    this_ = newObject(LITERAL_STRING[144], {});
}
SensitiveParameter::SensitiveParameter() {
    this_ = newObject(LITERAL_STRING[145], {});
}
SensitiveParameterValue::SensitiveParameterValue(const Variant &value) {
    this_ = newObject(LITERAL_STRING[146], {value});
}
Variant SensitiveParameterValue::getValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[147]);
    }
    return this_.call(_method_fn, {});
}
Variant SensitiveParameterValue::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Override::Override() {
    this_ = newObject(LITERAL_STRING[148], {});
}
Deprecated::Deprecated(const Variant &message, const Variant &since) {
    this_ = newObject(LITERAL_STRING[149], {message, since});
}
Fiber::Fiber(const Variant &callback) {
    this_ = newObject(LITERAL_STRING[150], {callback});
}
Variant Fiber::resume(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[152]);
    }
    return this_.call(_method_fn, {value});
}
Variant Fiber::throw_(const Variant &exception) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[127]);
    }
    return this_.call(_method_fn, {exception});
}
Variant Fiber::isStarted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[153]);
    }
    return this_.call(_method_fn, {});
}
Variant Fiber::isSuspended() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[154]);
    }
    return this_.call(_method_fn, {});
}
Variant Fiber::isRunning() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[155]);
    }
    return this_.call(_method_fn, {});
}
Variant Fiber::isTerminated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[156]);
    }
    return this_.call(_method_fn, {});
}
Variant Fiber::getReturn() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[128]);
    }
    return this_.call(_method_fn, {});
}
Variant Fiber::getCurrent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[150], LITERAL_STRING[158]);
    }
    return php::call(_method_fn, {});
}
Variant Fiber::suspend(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[150], LITERAL_STRING[160]);
    }
    return php::call(_method_fn, {value});
}
FiberError::FiberError() {
    this_ = newObject(LITERAL_STRING[161], {});
}
stdClass::stdClass() {
    this_ = newObject(LITERAL_STRING[162]);
}
}  // namespace php

#include "phpx.h"
#include "class/core.h"

namespace php {
Variant InternalIterator::current() {
    return std::move(_this.exec("current"));
}

Variant InternalIterator::key() {
    return std::move(_this.exec("key"));
}

Variant InternalIterator::next() {
    return std::move(_this.exec("next"));
}

Variant InternalIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant InternalIterator::rewind() {
    return std::move(_this.exec("rewind"));
}


Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("Exception", message, code, previous);
}

Variant Exception::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant Exception::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant Exception::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant Exception::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant Exception::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant Exception::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant Exception::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant Exception::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant Exception::__toString() {
    return std::move(_this.exec("__toString"));
}


ErrorException::ErrorException(const Variant &message, const Variant &code, const Variant &severity, const Variant &filename, const Variant &line, const Variant &previous) {
    _this = newObject("ErrorException", message, code, severity, filename, line, previous);
}

Variant ErrorException::getSeverity() {
    return std::move(_this.exec("getSeverity"));
}

Variant ErrorException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant ErrorException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant ErrorException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant ErrorException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant ErrorException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant ErrorException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant ErrorException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant ErrorException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant ErrorException::__toString() {
    return std::move(_this.exec("__toString"));
}


Error::Error(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("Error", message, code, previous);
}

Variant Error::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant Error::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant Error::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant Error::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant Error::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant Error::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant Error::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant Error::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant Error::__toString() {
    return std::move(_this.exec("__toString"));
}


CompileError::CompileError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("CompileError", message, code, previous);
}

Variant CompileError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant CompileError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant CompileError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant CompileError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant CompileError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant CompileError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant CompileError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant CompileError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant CompileError::__toString() {
    return std::move(_this.exec("__toString"));
}


ParseError::ParseError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ParseError", message, code, previous);
}

Variant ParseError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant ParseError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant ParseError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant ParseError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant ParseError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant ParseError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant ParseError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant ParseError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant ParseError::__toString() {
    return std::move(_this.exec("__toString"));
}


TypeError::TypeError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("TypeError", message, code, previous);
}

Variant TypeError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant TypeError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant TypeError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant TypeError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant TypeError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant TypeError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant TypeError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant TypeError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant TypeError::__toString() {
    return std::move(_this.exec("__toString"));
}


ArgumentCountError::ArgumentCountError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ArgumentCountError", message, code, previous);
}

Variant ArgumentCountError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant ArgumentCountError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant ArgumentCountError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant ArgumentCountError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant ArgumentCountError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant ArgumentCountError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant ArgumentCountError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant ArgumentCountError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant ArgumentCountError::__toString() {
    return std::move(_this.exec("__toString"));
}


ValueError::ValueError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ValueError", message, code, previous);
}

Variant ValueError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant ValueError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant ValueError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant ValueError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant ValueError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant ValueError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant ValueError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant ValueError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant ValueError::__toString() {
    return std::move(_this.exec("__toString"));
}


ArithmeticError::ArithmeticError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ArithmeticError", message, code, previous);
}

Variant ArithmeticError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant ArithmeticError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant ArithmeticError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant ArithmeticError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant ArithmeticError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant ArithmeticError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant ArithmeticError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant ArithmeticError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant ArithmeticError::__toString() {
    return std::move(_this.exec("__toString"));
}


DivisionByZeroError::DivisionByZeroError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("DivisionByZeroError", message, code, previous);
}

Variant DivisionByZeroError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant DivisionByZeroError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant DivisionByZeroError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant DivisionByZeroError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant DivisionByZeroError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant DivisionByZeroError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant DivisionByZeroError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant DivisionByZeroError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant DivisionByZeroError::__toString() {
    return std::move(_this.exec("__toString"));
}


UnhandledMatchError::UnhandledMatchError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("UnhandledMatchError", message, code, previous);
}

Variant UnhandledMatchError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant UnhandledMatchError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant UnhandledMatchError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant UnhandledMatchError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant UnhandledMatchError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant UnhandledMatchError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant UnhandledMatchError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant UnhandledMatchError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant UnhandledMatchError::__toString() {
    return std::move(_this.exec("__toString"));
}


Variant Closure::bind(const Variant &closure, const Variant &new_this, const Variant &new_scope) {
    static Variant fn { ZEND_STRL("Closure::bind"), true };
    return fn(closure, new_this, new_scope);
}

Variant Closure::bindTo(const Variant &new_this, const Variant &new_scope) {
    return std::move(_this.exec("bindTo", new_this, new_scope));
}

Variant Closure::call(const Variant &new_this, const Variant &args) {
    return std::move(_this.exec("call", new_this, args));
}

Variant Closure::fromCallable(const Variant &callback) {
    static Variant fn { ZEND_STRL("Closure::fromCallable"), true };
    return fn(callback);
}

Variant Closure::__invoke() {
    return std::move(_this.exec("__invoke"));
}


Variant Generator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant Generator::valid() {
    return std::move(_this.exec("valid"));
}

Variant Generator::current() {
    return std::move(_this.exec("current"));
}

Variant Generator::key() {
    return std::move(_this.exec("key"));
}

Variant Generator::next() {
    return std::move(_this.exec("next"));
}

Variant Generator::send(const Variant &value) {
    return std::move(_this.exec("send", value));
}

Variant Generator::_throw(const Variant &exception) {
    return std::move(_this.exec("throw", exception));
}

Variant Generator::getReturn() {
    return std::move(_this.exec("getReturn"));
}


ClosedGeneratorException::ClosedGeneratorException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ClosedGeneratorException", message, code, previous);
}

Variant ClosedGeneratorException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant ClosedGeneratorException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant ClosedGeneratorException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant ClosedGeneratorException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant ClosedGeneratorException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant ClosedGeneratorException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant ClosedGeneratorException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant ClosedGeneratorException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant ClosedGeneratorException::__toString() {
    return std::move(_this.exec("__toString"));
}


WeakReference::WeakReference() {
    _this = newObject("WeakReference");
}

Variant WeakReference::create(const Variant &object) {
    static Variant fn { ZEND_STRL("WeakReference::create"), true };
    return fn(object);
}

Variant WeakReference::get() {
    return std::move(_this.exec("get"));
}


Variant WeakMap::offsetGet(const Variant &object) {
    return std::move(_this.exec("offsetGet", object));
}

Variant WeakMap::offsetSet(const Variant &object, const Variant &value) {
    return std::move(_this.exec("offsetSet", object, value));
}

Variant WeakMap::offsetExists(const Variant &object) {
    return std::move(_this.exec("offsetExists", object));
}

Variant WeakMap::offsetUnset(const Variant &object) {
    return std::move(_this.exec("offsetUnset", object));
}

Variant WeakMap::count() {
    return std::move(_this.exec("count"));
}

Variant WeakMap::getIterator() {
    return std::move(_this.exec("getIterator"));
}


Attribute::Attribute(const Variant &flags) {
    _this = newObject("Attribute", flags);
}


ReturnTypeWillChange::ReturnTypeWillChange() {
    _this = newObject("ReturnTypeWillChange");
}


AllowDynamicProperties::AllowDynamicProperties() {
    _this = newObject("AllowDynamicProperties");
}


SensitiveParameter::SensitiveParameter() {
    _this = newObject("SensitiveParameter");
}


SensitiveParameterValue::SensitiveParameterValue(const Variant &value) {
    _this = newObject("SensitiveParameterValue", value);
}

Variant SensitiveParameterValue::getValue() {
    return std::move(_this.exec("getValue"));
}

Variant SensitiveParameterValue::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


Fiber::Fiber(const Variant &callback) {
    _this = newObject("Fiber", callback);
}

Variant Fiber::start(const Variant &args) {
    return std::move(_this.exec("start", args));
}

Variant Fiber::resume(const Variant &value) {
    return std::move(_this.exec("resume", value));
}

Variant Fiber::_throw(const Variant &exception) {
    return std::move(_this.exec("throw", exception));
}

Variant Fiber::isStarted() {
    return std::move(_this.exec("isStarted"));
}

Variant Fiber::isSuspended() {
    return std::move(_this.exec("isSuspended"));
}

Variant Fiber::isRunning() {
    return std::move(_this.exec("isRunning"));
}

Variant Fiber::isTerminated() {
    return std::move(_this.exec("isTerminated"));
}

Variant Fiber::getReturn() {
    return std::move(_this.exec("getReturn"));
}

Variant Fiber::getCurrent() {
    static Variant fn { ZEND_STRL("Fiber::getCurrent"), true };
    return fn();
}

Variant Fiber::suspend(const Variant &value) {
    static Variant fn { ZEND_STRL("Fiber::suspend"), true };
    return fn(value);
}


FiberError::FiberError() {
    _this = newObject("FiberError");
}

Variant FiberError::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant FiberError::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant FiberError::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant FiberError::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant FiberError::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant FiberError::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant FiberError::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant FiberError::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant FiberError::__toString() {
    return std::move(_this.exec("__toString"));
}


}

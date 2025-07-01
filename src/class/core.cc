#include "phpx.h"
#include "class/core.h"

namespace php {
Variant InternalIterator::current() {
    return _this.exec("current");
}

Variant InternalIterator::key() {
    return _this.exec("key");
}

Variant InternalIterator::next() {
    return _this.exec("next");
}

Variant InternalIterator::valid() {
    return _this.exec("valid");
}

Variant InternalIterator::rewind() {
    return _this.exec("rewind");
}


Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("Exception", message, code, previous);
}

Variant Exception::__wakeup() {
    return _this.exec("__wakeup");
}

Variant Exception::getMessage() {
    return _this.exec("getMessage");
}

Variant Exception::getCode() {
    return _this.exec("getCode");
}

Variant Exception::getFile() {
    return _this.exec("getFile");
}

Variant Exception::getLine() {
    return _this.exec("getLine");
}

Variant Exception::getTrace() {
    return _this.exec("getTrace");
}

Variant Exception::getPrevious() {
    return _this.exec("getPrevious");
}

Variant Exception::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant Exception::__toString() {
    return _this.exec("__toString");
}


ErrorException::ErrorException(const Variant &message, const Variant &code, const Variant &severity, const Variant &filename, const Variant &line, const Variant &previous) {
    _this = newObject("ErrorException", message, code, severity, filename, line, previous);
}

Variant ErrorException::getSeverity() {
    return _this.exec("getSeverity");
}

Variant ErrorException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant ErrorException::getMessage() {
    return _this.exec("getMessage");
}

Variant ErrorException::getCode() {
    return _this.exec("getCode");
}

Variant ErrorException::getFile() {
    return _this.exec("getFile");
}

Variant ErrorException::getLine() {
    return _this.exec("getLine");
}

Variant ErrorException::getTrace() {
    return _this.exec("getTrace");
}

Variant ErrorException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant ErrorException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant ErrorException::__toString() {
    return _this.exec("__toString");
}


Error::Error(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("Error", message, code, previous);
}

Variant Error::__wakeup() {
    return _this.exec("__wakeup");
}

Variant Error::getMessage() {
    return _this.exec("getMessage");
}

Variant Error::getCode() {
    return _this.exec("getCode");
}

Variant Error::getFile() {
    return _this.exec("getFile");
}

Variant Error::getLine() {
    return _this.exec("getLine");
}

Variant Error::getTrace() {
    return _this.exec("getTrace");
}

Variant Error::getPrevious() {
    return _this.exec("getPrevious");
}

Variant Error::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant Error::__toString() {
    return _this.exec("__toString");
}


CompileError::CompileError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("CompileError", message, code, previous);
}

Variant CompileError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant CompileError::getMessage() {
    return _this.exec("getMessage");
}

Variant CompileError::getCode() {
    return _this.exec("getCode");
}

Variant CompileError::getFile() {
    return _this.exec("getFile");
}

Variant CompileError::getLine() {
    return _this.exec("getLine");
}

Variant CompileError::getTrace() {
    return _this.exec("getTrace");
}

Variant CompileError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant CompileError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant CompileError::__toString() {
    return _this.exec("__toString");
}


ParseError::ParseError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ParseError", message, code, previous);
}

Variant ParseError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant ParseError::getMessage() {
    return _this.exec("getMessage");
}

Variant ParseError::getCode() {
    return _this.exec("getCode");
}

Variant ParseError::getFile() {
    return _this.exec("getFile");
}

Variant ParseError::getLine() {
    return _this.exec("getLine");
}

Variant ParseError::getTrace() {
    return _this.exec("getTrace");
}

Variant ParseError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant ParseError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant ParseError::__toString() {
    return _this.exec("__toString");
}


TypeError::TypeError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("TypeError", message, code, previous);
}

Variant TypeError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant TypeError::getMessage() {
    return _this.exec("getMessage");
}

Variant TypeError::getCode() {
    return _this.exec("getCode");
}

Variant TypeError::getFile() {
    return _this.exec("getFile");
}

Variant TypeError::getLine() {
    return _this.exec("getLine");
}

Variant TypeError::getTrace() {
    return _this.exec("getTrace");
}

Variant TypeError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant TypeError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant TypeError::__toString() {
    return _this.exec("__toString");
}


ArgumentCountError::ArgumentCountError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ArgumentCountError", message, code, previous);
}

Variant ArgumentCountError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant ArgumentCountError::getMessage() {
    return _this.exec("getMessage");
}

Variant ArgumentCountError::getCode() {
    return _this.exec("getCode");
}

Variant ArgumentCountError::getFile() {
    return _this.exec("getFile");
}

Variant ArgumentCountError::getLine() {
    return _this.exec("getLine");
}

Variant ArgumentCountError::getTrace() {
    return _this.exec("getTrace");
}

Variant ArgumentCountError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant ArgumentCountError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant ArgumentCountError::__toString() {
    return _this.exec("__toString");
}


ValueError::ValueError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ValueError", message, code, previous);
}

Variant ValueError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant ValueError::getMessage() {
    return _this.exec("getMessage");
}

Variant ValueError::getCode() {
    return _this.exec("getCode");
}

Variant ValueError::getFile() {
    return _this.exec("getFile");
}

Variant ValueError::getLine() {
    return _this.exec("getLine");
}

Variant ValueError::getTrace() {
    return _this.exec("getTrace");
}

Variant ValueError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant ValueError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant ValueError::__toString() {
    return _this.exec("__toString");
}


ArithmeticError::ArithmeticError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ArithmeticError", message, code, previous);
}

Variant ArithmeticError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant ArithmeticError::getMessage() {
    return _this.exec("getMessage");
}

Variant ArithmeticError::getCode() {
    return _this.exec("getCode");
}

Variant ArithmeticError::getFile() {
    return _this.exec("getFile");
}

Variant ArithmeticError::getLine() {
    return _this.exec("getLine");
}

Variant ArithmeticError::getTrace() {
    return _this.exec("getTrace");
}

Variant ArithmeticError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant ArithmeticError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant ArithmeticError::__toString() {
    return _this.exec("__toString");
}


DivisionByZeroError::DivisionByZeroError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("DivisionByZeroError", message, code, previous);
}

Variant DivisionByZeroError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DivisionByZeroError::getMessage() {
    return _this.exec("getMessage");
}

Variant DivisionByZeroError::getCode() {
    return _this.exec("getCode");
}

Variant DivisionByZeroError::getFile() {
    return _this.exec("getFile");
}

Variant DivisionByZeroError::getLine() {
    return _this.exec("getLine");
}

Variant DivisionByZeroError::getTrace() {
    return _this.exec("getTrace");
}

Variant DivisionByZeroError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant DivisionByZeroError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant DivisionByZeroError::__toString() {
    return _this.exec("__toString");
}


UnhandledMatchError::UnhandledMatchError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("UnhandledMatchError", message, code, previous);
}

Variant UnhandledMatchError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant UnhandledMatchError::getMessage() {
    return _this.exec("getMessage");
}

Variant UnhandledMatchError::getCode() {
    return _this.exec("getCode");
}

Variant UnhandledMatchError::getFile() {
    return _this.exec("getFile");
}

Variant UnhandledMatchError::getLine() {
    return _this.exec("getLine");
}

Variant UnhandledMatchError::getTrace() {
    return _this.exec("getTrace");
}

Variant UnhandledMatchError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant UnhandledMatchError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant UnhandledMatchError::__toString() {
    return _this.exec("__toString");
}


Variant Closure::bind(const Variant &closure, const Variant &new_this, const Variant &new_scope) {
    static Variant fn { ZEND_STRL("Closure::bind"), true };
    return fn(closure, new_this, new_scope);
}

Variant Closure::bindTo(const Variant &new_this, const Variant &new_scope) {
    return _this.exec("bindTo", new_this, new_scope);
}

Variant Closure::call(const Variant &new_this, const Variant &args) {
    return _this.exec("call", new_this, args);
}

Variant Closure::fromCallable(const Variant &callback) {
    static Variant fn { ZEND_STRL("Closure::fromCallable"), true };
    return fn(callback);
}

Variant Closure::__invoke() {
    return _this.exec("__invoke");
}


Variant Generator::rewind() {
    return _this.exec("rewind");
}

Variant Generator::valid() {
    return _this.exec("valid");
}

Variant Generator::current() {
    return _this.exec("current");
}

Variant Generator::key() {
    return _this.exec("key");
}

Variant Generator::next() {
    return _this.exec("next");
}

Variant Generator::send(const Variant &value) {
    return _this.exec("send", value);
}

Variant Generator::_throw(const Variant &exception) {
    return _this.exec("throw", exception);
}

Variant Generator::getReturn() {
    return _this.exec("getReturn");
}


ClosedGeneratorException::ClosedGeneratorException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ClosedGeneratorException", message, code, previous);
}

Variant ClosedGeneratorException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant ClosedGeneratorException::getMessage() {
    return _this.exec("getMessage");
}

Variant ClosedGeneratorException::getCode() {
    return _this.exec("getCode");
}

Variant ClosedGeneratorException::getFile() {
    return _this.exec("getFile");
}

Variant ClosedGeneratorException::getLine() {
    return _this.exec("getLine");
}

Variant ClosedGeneratorException::getTrace() {
    return _this.exec("getTrace");
}

Variant ClosedGeneratorException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant ClosedGeneratorException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant ClosedGeneratorException::__toString() {
    return _this.exec("__toString");
}


WeakReference::WeakReference() {
    _this = newObject("WeakReference");
}

Variant WeakReference::create(const Variant &object) {
    static Variant fn { ZEND_STRL("WeakReference::create"), true };
    return fn(object);
}

Variant WeakReference::get() {
    return _this.exec("get");
}


Variant WeakMap::offsetGet(const Variant &object) {
    return _this.exec("offsetGet", object);
}

Variant WeakMap::offsetSet(const Variant &object, const Variant &value) {
    return _this.exec("offsetSet", object, value);
}

Variant WeakMap::offsetExists(const Variant &object) {
    return _this.exec("offsetExists", object);
}

Variant WeakMap::offsetUnset(const Variant &object) {
    return _this.exec("offsetUnset", object);
}

Variant WeakMap::count() {
    return _this.exec("count");
}

Variant WeakMap::getIterator() {
    return _this.exec("getIterator");
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
    return _this.exec("getValue");
}

Variant SensitiveParameterValue::__debugInfo() {
    return _this.exec("__debugInfo");
}


Fiber::Fiber(const Variant &callback) {
    _this = newObject("Fiber", callback);
}

Variant Fiber::start(const Variant &args) {
    return _this.exec("start", args);
}

Variant Fiber::resume(const Variant &value) {
    return _this.exec("resume", value);
}

Variant Fiber::_throw(const Variant &exception) {
    return _this.exec("throw", exception);
}

Variant Fiber::isStarted() {
    return _this.exec("isStarted");
}

Variant Fiber::isSuspended() {
    return _this.exec("isSuspended");
}

Variant Fiber::isRunning() {
    return _this.exec("isRunning");
}

Variant Fiber::isTerminated() {
    return _this.exec("isTerminated");
}

Variant Fiber::getReturn() {
    return _this.exec("getReturn");
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
    return _this.exec("__wakeup");
}

Variant FiberError::getMessage() {
    return _this.exec("getMessage");
}

Variant FiberError::getCode() {
    return _this.exec("getCode");
}

Variant FiberError::getFile() {
    return _this.exec("getFile");
}

Variant FiberError::getLine() {
    return _this.exec("getLine");
}

Variant FiberError::getTrace() {
    return _this.exec("getTrace");
}

Variant FiberError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant FiberError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant FiberError::__toString() {
    return _this.exec("__toString");
}


}

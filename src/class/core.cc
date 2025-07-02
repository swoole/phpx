#include "phpx.h"
#include "class/core.h"

namespace php {
Variant InternalIterator::current() {
    return this_.exec("current");
}

Variant InternalIterator::key() {
    return this_.exec("key");
}

Variant InternalIterator::next() {
    return this_.exec("next");
}

Variant InternalIterator::valid() {
    return this_.exec("valid");
}

Variant InternalIterator::rewind() {
    return this_.exec("rewind");
}


Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("Exception", message, code, previous);
}

Variant Exception::__wakeup() {
    return this_.exec("__wakeup");
}

Variant Exception::getMessage() {
    return this_.exec("getMessage");
}

Variant Exception::getCode() {
    return this_.exec("getCode");
}

Variant Exception::getFile() {
    return this_.exec("getFile");
}

Variant Exception::getLine() {
    return this_.exec("getLine");
}

Variant Exception::getTrace() {
    return this_.exec("getTrace");
}

Variant Exception::getPrevious() {
    return this_.exec("getPrevious");
}

Variant Exception::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant Exception::__toString() {
    return this_.exec("__toString");
}


ErrorException::ErrorException(const Variant &message, const Variant &code, const Variant &severity, const Variant &filename, const Variant &line, const Variant &previous) {
    this_ = newObject("ErrorException", message, code, severity, filename, line, previous);
}

Variant ErrorException::getSeverity() {
    return this_.exec("getSeverity");
}

Variant ErrorException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant ErrorException::getMessage() {
    return this_.exec("getMessage");
}

Variant ErrorException::getCode() {
    return this_.exec("getCode");
}

Variant ErrorException::getFile() {
    return this_.exec("getFile");
}

Variant ErrorException::getLine() {
    return this_.exec("getLine");
}

Variant ErrorException::getTrace() {
    return this_.exec("getTrace");
}

Variant ErrorException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant ErrorException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant ErrorException::__toString() {
    return this_.exec("__toString");
}


Error::Error(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("Error", message, code, previous);
}

Variant Error::__wakeup() {
    return this_.exec("__wakeup");
}

Variant Error::getMessage() {
    return this_.exec("getMessage");
}

Variant Error::getCode() {
    return this_.exec("getCode");
}

Variant Error::getFile() {
    return this_.exec("getFile");
}

Variant Error::getLine() {
    return this_.exec("getLine");
}

Variant Error::getTrace() {
    return this_.exec("getTrace");
}

Variant Error::getPrevious() {
    return this_.exec("getPrevious");
}

Variant Error::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant Error::__toString() {
    return this_.exec("__toString");
}


CompileError::CompileError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("CompileError", message, code, previous);
}

Variant CompileError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant CompileError::getMessage() {
    return this_.exec("getMessage");
}

Variant CompileError::getCode() {
    return this_.exec("getCode");
}

Variant CompileError::getFile() {
    return this_.exec("getFile");
}

Variant CompileError::getLine() {
    return this_.exec("getLine");
}

Variant CompileError::getTrace() {
    return this_.exec("getTrace");
}

Variant CompileError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant CompileError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant CompileError::__toString() {
    return this_.exec("__toString");
}


ParseError::ParseError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("ParseError", message, code, previous);
}

Variant ParseError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant ParseError::getMessage() {
    return this_.exec("getMessage");
}

Variant ParseError::getCode() {
    return this_.exec("getCode");
}

Variant ParseError::getFile() {
    return this_.exec("getFile");
}

Variant ParseError::getLine() {
    return this_.exec("getLine");
}

Variant ParseError::getTrace() {
    return this_.exec("getTrace");
}

Variant ParseError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant ParseError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant ParseError::__toString() {
    return this_.exec("__toString");
}


TypeError::TypeError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("TypeError", message, code, previous);
}

Variant TypeError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant TypeError::getMessage() {
    return this_.exec("getMessage");
}

Variant TypeError::getCode() {
    return this_.exec("getCode");
}

Variant TypeError::getFile() {
    return this_.exec("getFile");
}

Variant TypeError::getLine() {
    return this_.exec("getLine");
}

Variant TypeError::getTrace() {
    return this_.exec("getTrace");
}

Variant TypeError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant TypeError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant TypeError::__toString() {
    return this_.exec("__toString");
}


ArgumentCountError::ArgumentCountError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("ArgumentCountError", message, code, previous);
}

Variant ArgumentCountError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant ArgumentCountError::getMessage() {
    return this_.exec("getMessage");
}

Variant ArgumentCountError::getCode() {
    return this_.exec("getCode");
}

Variant ArgumentCountError::getFile() {
    return this_.exec("getFile");
}

Variant ArgumentCountError::getLine() {
    return this_.exec("getLine");
}

Variant ArgumentCountError::getTrace() {
    return this_.exec("getTrace");
}

Variant ArgumentCountError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant ArgumentCountError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant ArgumentCountError::__toString() {
    return this_.exec("__toString");
}


ValueError::ValueError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("ValueError", message, code, previous);
}

Variant ValueError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant ValueError::getMessage() {
    return this_.exec("getMessage");
}

Variant ValueError::getCode() {
    return this_.exec("getCode");
}

Variant ValueError::getFile() {
    return this_.exec("getFile");
}

Variant ValueError::getLine() {
    return this_.exec("getLine");
}

Variant ValueError::getTrace() {
    return this_.exec("getTrace");
}

Variant ValueError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant ValueError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant ValueError::__toString() {
    return this_.exec("__toString");
}


ArithmeticError::ArithmeticError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("ArithmeticError", message, code, previous);
}

Variant ArithmeticError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant ArithmeticError::getMessage() {
    return this_.exec("getMessage");
}

Variant ArithmeticError::getCode() {
    return this_.exec("getCode");
}

Variant ArithmeticError::getFile() {
    return this_.exec("getFile");
}

Variant ArithmeticError::getLine() {
    return this_.exec("getLine");
}

Variant ArithmeticError::getTrace() {
    return this_.exec("getTrace");
}

Variant ArithmeticError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant ArithmeticError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant ArithmeticError::__toString() {
    return this_.exec("__toString");
}


DivisionByZeroError::DivisionByZeroError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("DivisionByZeroError", message, code, previous);
}

Variant DivisionByZeroError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DivisionByZeroError::getMessage() {
    return this_.exec("getMessage");
}

Variant DivisionByZeroError::getCode() {
    return this_.exec("getCode");
}

Variant DivisionByZeroError::getFile() {
    return this_.exec("getFile");
}

Variant DivisionByZeroError::getLine() {
    return this_.exec("getLine");
}

Variant DivisionByZeroError::getTrace() {
    return this_.exec("getTrace");
}

Variant DivisionByZeroError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant DivisionByZeroError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant DivisionByZeroError::__toString() {
    return this_.exec("__toString");
}


UnhandledMatchError::UnhandledMatchError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("UnhandledMatchError", message, code, previous);
}

Variant UnhandledMatchError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant UnhandledMatchError::getMessage() {
    return this_.exec("getMessage");
}

Variant UnhandledMatchError::getCode() {
    return this_.exec("getCode");
}

Variant UnhandledMatchError::getFile() {
    return this_.exec("getFile");
}

Variant UnhandledMatchError::getLine() {
    return this_.exec("getLine");
}

Variant UnhandledMatchError::getTrace() {
    return this_.exec("getTrace");
}

Variant UnhandledMatchError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant UnhandledMatchError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant UnhandledMatchError::__toString() {
    return this_.exec("__toString");
}


Variant Closure::bind(const Variant &closure, const Variant &new_this, const Variant &new_scope) {
    static Variant fn { ZEND_STRL("Closure::bind"), true };
    return fn(closure, new_this, new_scope);
}

Variant Closure::bindTo(const Variant &new_this, const Variant &new_scope) {
    return this_.exec("bindTo", new_this, new_scope);
}

Variant Closure::call(const Variant &new_this, const Variant &args) {
    return this_.exec("call", new_this, args);
}

Variant Closure::fromCallable(const Variant &callback) {
    static Variant fn { ZEND_STRL("Closure::fromCallable"), true };
    return fn(callback);
}

Variant Closure::__invoke() {
    return this_.exec("__invoke");
}


Variant Generator::rewind() {
    return this_.exec("rewind");
}

Variant Generator::valid() {
    return this_.exec("valid");
}

Variant Generator::current() {
    return this_.exec("current");
}

Variant Generator::key() {
    return this_.exec("key");
}

Variant Generator::next() {
    return this_.exec("next");
}

Variant Generator::send(const Variant &value) {
    return this_.exec("send", value);
}

Variant Generator::_throw(const Variant &exception) {
    return this_.exec("throw", exception);
}

Variant Generator::getReturn() {
    return this_.exec("getReturn");
}


ClosedGeneratorException::ClosedGeneratorException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("ClosedGeneratorException", message, code, previous);
}

Variant ClosedGeneratorException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant ClosedGeneratorException::getMessage() {
    return this_.exec("getMessage");
}

Variant ClosedGeneratorException::getCode() {
    return this_.exec("getCode");
}

Variant ClosedGeneratorException::getFile() {
    return this_.exec("getFile");
}

Variant ClosedGeneratorException::getLine() {
    return this_.exec("getLine");
}

Variant ClosedGeneratorException::getTrace() {
    return this_.exec("getTrace");
}

Variant ClosedGeneratorException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant ClosedGeneratorException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant ClosedGeneratorException::__toString() {
    return this_.exec("__toString");
}


WeakReference::WeakReference() {
    this_ = newObject("WeakReference");
}

Variant WeakReference::create(const Variant &object) {
    static Variant fn { ZEND_STRL("WeakReference::create"), true };
    return fn(object);
}

Variant WeakReference::get() {
    return this_.exec("get");
}


Variant WeakMap::offsetGet(const Variant &object) {
    return this_.exec("offsetGet", object);
}

Variant WeakMap::offsetSet(const Variant &object, const Variant &value) {
    return this_.exec("offsetSet", object, value);
}

Variant WeakMap::offsetExists(const Variant &object) {
    return this_.exec("offsetExists", object);
}

Variant WeakMap::offsetUnset(const Variant &object) {
    return this_.exec("offsetUnset", object);
}

Variant WeakMap::count() {
    return this_.exec("count");
}

Variant WeakMap::getIterator() {
    return this_.exec("getIterator");
}


Attribute::Attribute(const Variant &flags) {
    this_ = newObject("Attribute", flags);
}


ReturnTypeWillChange::ReturnTypeWillChange() {
    this_ = newObject("ReturnTypeWillChange");
}


AllowDynamicProperties::AllowDynamicProperties() {
    this_ = newObject("AllowDynamicProperties");
}


SensitiveParameter::SensitiveParameter() {
    this_ = newObject("SensitiveParameter");
}


SensitiveParameterValue::SensitiveParameterValue(const Variant &value) {
    this_ = newObject("SensitiveParameterValue", value);
}

Variant SensitiveParameterValue::getValue() {
    return this_.exec("getValue");
}

Variant SensitiveParameterValue::__debugInfo() {
    return this_.exec("__debugInfo");
}


Override::Override() {
    this_ = newObject("Override");
}


Fiber::Fiber(const Variant &callback) {
    this_ = newObject("Fiber", callback);
}

Variant Fiber::start(const Variant &args) {
    return this_.exec("start", args);
}

Variant Fiber::resume(const Variant &value) {
    return this_.exec("resume", value);
}

Variant Fiber::_throw(const Variant &exception) {
    return this_.exec("throw", exception);
}

Variant Fiber::isStarted() {
    return this_.exec("isStarted");
}

Variant Fiber::isSuspended() {
    return this_.exec("isSuspended");
}

Variant Fiber::isRunning() {
    return this_.exec("isRunning");
}

Variant Fiber::isTerminated() {
    return this_.exec("isTerminated");
}

Variant Fiber::getReturn() {
    return this_.exec("getReturn");
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
    this_ = newObject("FiberError");
}

Variant FiberError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant FiberError::getMessage() {
    return this_.exec("getMessage");
}

Variant FiberError::getCode() {
    return this_.exec("getCode");
}

Variant FiberError::getFile() {
    return this_.exec("getFile");
}

Variant FiberError::getLine() {
    return this_.exec("getLine");
}

Variant FiberError::getTrace() {
    return this_.exec("getTrace");
}

Variant FiberError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant FiberError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant FiberError::__toString() {
    return this_.exec("__toString");
}


}

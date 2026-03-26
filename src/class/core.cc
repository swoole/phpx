#include "phpx.h"
#include "class/core.h"

namespace php {
Variant InternalIterator::current() {
    return this_.exec(LITERAL_STRING[90], {});
}
Variant InternalIterator::key() {
    return this_.exec(LITERAL_STRING[91], {});
}
Variant InternalIterator::next() {
    return this_.exec(LITERAL_STRING[92], {});
}
Variant InternalIterator::valid() {
    return this_.exec(LITERAL_STRING[93], {});
}
Variant InternalIterator::rewind() {
    return this_.exec(LITERAL_STRING[94], {});
}
Exception::Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[96], {message, code, previous});
}
Variant Exception::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant Exception::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant Exception::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant Exception::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant Exception::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant Exception::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant Exception::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant Exception::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant Exception::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
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
    return this_.exec(LITERAL_STRING[106], {});
}
Variant ErrorException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant ErrorException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant ErrorException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant ErrorException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant ErrorException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant ErrorException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant ErrorException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant ErrorException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant ErrorException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
Error::Error(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[107], {message, code, previous});
}
Variant Error::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant Error::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant Error::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant Error::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant Error::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant Error::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant Error::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant Error::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant Error::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
CompileError::CompileError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[108], {message, code, previous});
}
Variant CompileError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant CompileError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant CompileError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant CompileError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant CompileError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant CompileError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant CompileError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant CompileError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant CompileError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
ParseError::ParseError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[109], {message, code, previous});
}
Variant ParseError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant ParseError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant ParseError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant ParseError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant ParseError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant ParseError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant ParseError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant ParseError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant ParseError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
TypeError::TypeError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[110], {message, code, previous});
}
Variant TypeError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant TypeError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant TypeError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant TypeError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant TypeError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant TypeError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant TypeError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant TypeError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant TypeError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
ArgumentCountError::ArgumentCountError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[111], {message, code, previous});
}
Variant ArgumentCountError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant ArgumentCountError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant ArgumentCountError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant ArgumentCountError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant ArgumentCountError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant ArgumentCountError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant ArgumentCountError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant ArgumentCountError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant ArgumentCountError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
ValueError::ValueError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[112], {message, code, previous});
}
Variant ValueError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant ValueError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant ValueError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant ValueError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant ValueError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant ValueError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant ValueError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant ValueError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant ValueError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
ArithmeticError::ArithmeticError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[113], {message, code, previous});
}
Variant ArithmeticError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant ArithmeticError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant ArithmeticError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant ArithmeticError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant ArithmeticError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant ArithmeticError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant ArithmeticError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant ArithmeticError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant ArithmeticError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DivisionByZeroError::DivisionByZeroError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[114], {message, code, previous});
}
Variant DivisionByZeroError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DivisionByZeroError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DivisionByZeroError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DivisionByZeroError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DivisionByZeroError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DivisionByZeroError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DivisionByZeroError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DivisionByZeroError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DivisionByZeroError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
UnhandledMatchError::UnhandledMatchError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[115], {message, code, previous});
}
Variant UnhandledMatchError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant UnhandledMatchError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant UnhandledMatchError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant UnhandledMatchError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant UnhandledMatchError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant UnhandledMatchError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant UnhandledMatchError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant UnhandledMatchError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant UnhandledMatchError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
RequestParseBodyException::RequestParseBodyException(const Variant &message,
                                                     const Variant &code,
                                                     const Variant &previous) {
    this_ = newObject(LITERAL_STRING[116], {message, code, previous});
}
Variant RequestParseBodyException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant RequestParseBodyException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant RequestParseBodyException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant RequestParseBodyException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant RequestParseBodyException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant RequestParseBodyException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant RequestParseBodyException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant RequestParseBodyException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant RequestParseBodyException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
Variant Closure::bind(const Variant &closure, const Variant &new_this, const Variant &new_scope) {
    return php::call(LITERAL_STRING[117], {closure, new_this, new_scope});
}
Variant Closure::bindTo(const Variant &new_this, const Variant &new_scope) {
    return this_.exec(LITERAL_STRING[118], {new_this, new_scope});
}
Variant Closure::fromCallable(const Variant &callback) {
    return php::call(LITERAL_STRING[120], {callback});
}
Variant Closure::__invoke() {
    return this_.exec(LITERAL_STRING[121], {});
}
Variant Generator::rewind() {
    return this_.exec(LITERAL_STRING[94], {});
}
Variant Generator::valid() {
    return this_.exec(LITERAL_STRING[93], {});
}
Variant Generator::current() {
    return this_.exec(LITERAL_STRING[90], {});
}
Variant Generator::key() {
    return this_.exec(LITERAL_STRING[91], {});
}
Variant Generator::next() {
    return this_.exec(LITERAL_STRING[92], {});
}
Variant Generator::send(const Variant &value) {
    return this_.exec(LITERAL_STRING[123], {value});
}
Variant Generator::_throw(const Variant &exception) {
    return this_.exec(LITERAL_STRING[124], {exception});
}
Variant Generator::getReturn() {
    return this_.exec(LITERAL_STRING[125], {});
}
Variant Generator::__debugInfo() {
    return this_.exec(LITERAL_STRING[126], {});
}
ClosedGeneratorException::ClosedGeneratorException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[128], {message, code, previous});
}
Variant ClosedGeneratorException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant ClosedGeneratorException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant ClosedGeneratorException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant ClosedGeneratorException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant ClosedGeneratorException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant ClosedGeneratorException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant ClosedGeneratorException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant ClosedGeneratorException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant ClosedGeneratorException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
WeakReference::WeakReference() {
    this_ = newObject(LITERAL_STRING[129], {});
}
Variant WeakReference::create(const Variant &object) {
    return php::call(LITERAL_STRING[130], {object});
}
Variant WeakReference::get() {
    return this_.exec(LITERAL_STRING[131], {});
}
Variant WeakMap::offsetGet(const Variant &object) {
    return this_.exec(LITERAL_STRING[132], {object});
}
Variant WeakMap::offsetSet(const Variant &object, const Variant &value) {
    return this_.exec(LITERAL_STRING[133], {object, value});
}
Variant WeakMap::offsetExists(const Variant &object) {
    return this_.exec(LITERAL_STRING[134], {object});
}
Variant WeakMap::offsetUnset(const Variant &object) {
    return this_.exec(LITERAL_STRING[135], {object});
}
Variant WeakMap::count() {
    return this_.exec(LITERAL_STRING[136], {});
}
Variant WeakMap::getIterator() {
    return this_.exec(LITERAL_STRING[137], {});
}
Attribute::Attribute(const Variant &flags) {
    this_ = newObject(LITERAL_STRING[139], {flags});
}
ReturnTypeWillChange::ReturnTypeWillChange() {
    this_ = newObject(LITERAL_STRING[140], {});
}
AllowDynamicProperties::AllowDynamicProperties() {
    this_ = newObject(LITERAL_STRING[141], {});
}
SensitiveParameter::SensitiveParameter() {
    this_ = newObject(LITERAL_STRING[142], {});
}
SensitiveParameterValue::SensitiveParameterValue(const Variant &value) {
    this_ = newObject(LITERAL_STRING[143], {value});
}
Variant SensitiveParameterValue::getValue() {
    return this_.exec(LITERAL_STRING[144], {});
}
Variant SensitiveParameterValue::__debugInfo() {
    return this_.exec(LITERAL_STRING[126], {});
}
Override::Override() {
    this_ = newObject(LITERAL_STRING[145], {});
}
Deprecated::Deprecated(const Variant &message, const Variant &since) {
    this_ = newObject(LITERAL_STRING[146], {message, since});
}
Fiber::Fiber(const Variant &callback) {
    this_ = newObject(LITERAL_STRING[147], {callback});
}
Variant Fiber::resume(const Variant &value) {
    return this_.exec(LITERAL_STRING[149], {value});
}
Variant Fiber::_throw(const Variant &exception) {
    return this_.exec(LITERAL_STRING[124], {exception});
}
Variant Fiber::isStarted() {
    return this_.exec(LITERAL_STRING[150], {});
}
Variant Fiber::isSuspended() {
    return this_.exec(LITERAL_STRING[151], {});
}
Variant Fiber::isRunning() {
    return this_.exec(LITERAL_STRING[152], {});
}
Variant Fiber::isTerminated() {
    return this_.exec(LITERAL_STRING[153], {});
}
Variant Fiber::getReturn() {
    return this_.exec(LITERAL_STRING[125], {});
}
Variant Fiber::getCurrent() {
    return php::call(LITERAL_STRING[154], {});
}
Variant Fiber::suspend(const Variant &value) {
    return php::call(LITERAL_STRING[155], {value});
}
FiberError::FiberError() {
    this_ = newObject(LITERAL_STRING[156], {});
}
Variant FiberError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant FiberError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant FiberError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant FiberError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant FiberError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant FiberError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant FiberError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant FiberError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant FiberError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
}  // namespace php

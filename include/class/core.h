#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class InternalIterator;
class Exception;
class ErrorException;
class Error;
class CompileError;
class ParseError;
class TypeError;
class ArgumentCountError;
class ValueError;
class ArithmeticError;
class DivisionByZeroError;
class UnhandledMatchError;
class RequestParseBodyException;
class Closure;
class Generator;
class ClosedGeneratorException;
class WeakReference;
class WeakMap;
class Attribute;
class ReturnTypeWillChange;
class AllowDynamicProperties;
class SensitiveParameter;
class SensitiveParameterValue;
class Override;
class Deprecated;
class Fiber;
class FiberError;
class stdClass;

class InternalIterator {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant rewind();
};

class Exception {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class ErrorException : public Exception {
  public:
    ErrorException(const Variant &message = "",
                   const Variant &code = 0,
                   const Variant &severity = 1,
                   const Variant &filename = {},
                   const Variant &line = {},
                   const Variant &previous = {});
    Variant getSeverity();
};

class Error {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Error(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class CompileError : public Error {
  public:
    CompileError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class ParseError : public CompileError {
  public:
    ParseError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class TypeError : public Error {
  public:
    TypeError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class ArgumentCountError : public TypeError {
  public:
    ArgumentCountError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class ValueError : public Error {
  public:
    ValueError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class ArithmeticError : public Error {
  public:
    ArithmeticError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class DivisionByZeroError : public ArithmeticError {
  public:
    DivisionByZeroError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class UnhandledMatchError : public Error {
  public:
    UnhandledMatchError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class RequestParseBodyException : public Exception {
  public:
    RequestParseBodyException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class Closure {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static Variant bind(const Closure &closure, const Variant &new_this, const Variant &new_scope = "static");
    static Variant bind(const Variant &closure, const Variant &new_this, const Variant &new_scope = "static");
    Variant bindTo(const Variant &new_this, const Variant &new_scope = "static");
    template <typename... Args>
    Variant call(const Variant &new_this, const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[149]);
        }
        return this_.call(_method_fn, {new_this, args...});
    }
    static Variant fromCallable(const Variant &callback);
    Variant __invoke();
};

class Generator {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Generator(const Object &obj) : this_(obj) {}
    Generator();
    Variant rewind();
    Variant valid();
    Variant current();
    Variant key();
    Variant next();
    Variant send(const Variant &value);
    Variant throw_(const Variant &exception);
    Variant getReturn();
    Variant __debugInfo();
};

class ClosedGeneratorException : public Exception {
  public:
    ClosedGeneratorException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class WeakReference {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    WeakReference();
    static Variant create(const Variant &object);
    Variant get();
};

class WeakMap {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit WeakMap(const Object &obj) : this_(obj) {}
    WeakMap();
    Variant offsetGet(const Variant &object);
    Variant offsetSet(const Variant &object, const Variant &value);
    Variant offsetExists(const Variant &object);
    Variant offsetUnset(const Variant &object);
    Variant count();
    Variant getIterator();
};

class Attribute {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int TARGET_CLASS_ = 1;
    static constexpr int TARGET_FUNCTION_ = 2;
    static constexpr int TARGET_METHOD_ = 4;
    static constexpr int TARGET_PROPERTY_ = 8;
    static constexpr int TARGET_CLASS_CONSTANT_ = 16;
    static constexpr int TARGET_PARAMETER_ = 32;
    static constexpr int TARGET_ALL_ = 63;
    static constexpr int IS_REPEATABLE_ = 64;

    Attribute(const Variant &flags = 63);
};

class ReturnTypeWillChange {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    ReturnTypeWillChange();
};

class AllowDynamicProperties {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    AllowDynamicProperties();
};

class SensitiveParameter {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    SensitiveParameter();
};

class SensitiveParameterValue {
  protected:
    Object this_;
    SensitiveParameterValue() = default;

  public:
    Object getObject() const {
        return this_;
    }
    SensitiveParameterValue(const Variant &value);
    Variant getValue();
    Variant __debugInfo();
};

class Override {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Override();
};

class Deprecated {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Deprecated(const Variant &message = {}, const Variant &since = {});
};

class Fiber {
  protected:
    Object this_;
    Fiber() = default;

  public:
    Object getObject() const {
        return this_;
    }
    Fiber(const Variant &callback);
    template <typename... Args>
    Variant start(const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[179]);
        }
        return this_.call(_method_fn, {args...});
    }
    Variant resume(const Variant &value = {});
    Variant throw_(const Variant &exception);
    Variant isStarted();
    Variant isSuspended();
    Variant isRunning();
    Variant isTerminated();
    Variant getReturn();
    static Variant getCurrent();
    static Variant suspend(const Variant &value = {});
};

class FiberError : public Error {
  public:
    FiberError();
};

class stdClass {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit stdClass(const Object &obj) : this_(obj) {}
    stdClass();
};

}  // namespace php

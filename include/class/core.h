#include "phpx_literal_string.h"

namespace php {
class InternalIterator {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant rewind();
};

class Exception {
    Object this_;

  public:
    Object getObject() {
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

class ErrorException {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    ErrorException(const Variant &message = "",
                   const Variant &code = 0,
                   const Variant &severity = 1,
                   const Variant &filename = {},
                   const Variant &line = {},
                   const Variant &previous = {});
    Variant getSeverity();
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

class Error {
    Object this_;

  public:
    Object getObject() {
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

class CompileError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    CompileError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class ParseError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    ParseError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class TypeError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    TypeError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class ArgumentCountError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    ArgumentCountError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class ValueError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    ValueError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class ArithmeticError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    ArithmeticError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class DivisionByZeroError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    DivisionByZeroError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class UnhandledMatchError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    UnhandledMatchError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class RequestParseBodyException {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    RequestParseBodyException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class Closure {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    static Variant bind(const Variant &closure, const Variant &new_this, const Variant &new_scope = "static");
    Variant bindTo(const Variant &new_this, const Variant &new_scope = "static");
    template <typename... Args>
    Variant call(const Variant &new_this, const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
        }
        return this_.call(_method_fn, {new_this, args...});
    }
    static Variant fromCallable(const Variant &callback);
    Variant __invoke();
};

class Generator {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    Generator();
    Variant rewind();
    Variant valid();
    Variant current();
    Variant key();
    Variant next();
    Variant send(const Variant &value);
    Variant _throw(const Variant &exception);
    Variant getReturn();
    Variant __debugInfo();
};

class ClosedGeneratorException {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    ClosedGeneratorException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class WeakReference {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    WeakReference();
    static Variant create(const Variant &object);
    Variant get();
};

class WeakMap {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    WeakMap();
    Variant offsetGet(const Variant &object);
    Variant offsetSet(const Variant &object, const Variant &value);
    Variant offsetExists(const Variant &object);
    Variant offsetUnset(const Variant &object);
    Variant count();
    Variant getIterator();
};

class Attribute {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    Attribute(const Variant &flags = 63);
};

class ReturnTypeWillChange {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    ReturnTypeWillChange();
};

class AllowDynamicProperties {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    AllowDynamicProperties();
};

class SensitiveParameter {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    SensitiveParameter();
};

class SensitiveParameterValue {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    SensitiveParameterValue(const Variant &value);
    Variant getValue();
    Variant __debugInfo();
};

class Override {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    Override();
};

class Deprecated {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    Deprecated(const Variant &message = {}, const Variant &since = {});
};

class Fiber {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    Fiber(const Variant &callback);
    template <typename... Args>
    Variant start(const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[151]);
        }
        return this_.call(_method_fn, {args...});
    }
    Variant resume(const Variant &value = {});
    Variant _throw(const Variant &exception);
    Variant isStarted();
    Variant isSuspended();
    Variant isRunning();
    Variant isTerminated();
    Variant getReturn();
    static Variant getCurrent();
    static Variant suspend(const Variant &value = {});
};

class FiberError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    FiberError();
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

class stdClass {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    stdClass();
};

}  // namespace php

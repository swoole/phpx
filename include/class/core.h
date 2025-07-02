namespace php {
class InternalIterator {
    Object this_;
  public:
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant rewind();
};

class Exception {
    Object this_;
  public:
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
    ErrorException(const Variant &message = "", const Variant &code = 0, const Variant &severity = 1, const Variant &filename = {}, const Variant &line = {}, const Variant &previous = {});
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

class Closure {
    Object this_;
  public:
    static Variant bind(const Variant &closure, const Variant &new_this, const Variant &new_scope = "static");
    Variant bindTo(const Variant &new_this, const Variant &new_scope = "static");
    Variant call(const Variant &new_this, const Variant &args = {});
    static Variant fromCallable(const Variant &callback);
    Variant __invoke();
};

class Generator {
    Object this_;
  public:
    Variant rewind();
    Variant valid();
    Variant current();
    Variant key();
    Variant next();
    Variant send(const Variant &value);
    Variant _throw(const Variant &exception);
    Variant getReturn();
};

class ClosedGeneratorException {
    Object this_;
  public:
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
    WeakReference();
    static Variant create(const Variant &object);
    Variant get();
};

class WeakMap {
    Object this_;
  public:
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
    Attribute(const Variant &flags = 63);
};

class ReturnTypeWillChange {
    Object this_;
  public:
    ReturnTypeWillChange();
};

class AllowDynamicProperties {
    Object this_;
  public:
    AllowDynamicProperties();
};

class SensitiveParameter {
    Object this_;
  public:
    SensitiveParameter();
};

class SensitiveParameterValue {
    Object this_;
  public:
    SensitiveParameterValue(const Variant &value);
    Variant getValue();
    Variant __debugInfo();
};

class Override {
    Object this_;
  public:
    Override();
};

class Fiber {
    Object this_;
  public:
    Fiber(const Variant &callback);
    Variant start(const Variant &args = {});
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

}

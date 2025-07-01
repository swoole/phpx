namespace php {
class InternalIterator {
    Object _this;
  public:
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant rewind();
};

class Exception {
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
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
    Object _this;
  public:
    static Variant bind(const Variant &closure, const Variant &new_this, const Variant &new_scope = "static");
    Variant bindTo(const Variant &new_this, const Variant &new_scope = "static");
    Variant call(const Variant &new_this, const Variant &args = {});
    static Variant fromCallable(const Variant &callback);
    Variant __invoke();
};

class Generator {
    Object _this;
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
    Object _this;
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
    Object _this;
  public:
    WeakReference();
    static Variant create(const Variant &object);
    Variant get();
};

class WeakMap {
    Object _this;
  public:
    Variant offsetGet(const Variant &object);
    Variant offsetSet(const Variant &object, const Variant &value);
    Variant offsetExists(const Variant &object);
    Variant offsetUnset(const Variant &object);
    Variant count();
    Variant getIterator();
};

class Attribute {
    Object _this;
  public:
    Attribute(const Variant &flags = 63);
};

class ReturnTypeWillChange {
    Object _this;
  public:
    ReturnTypeWillChange();
};

class AllowDynamicProperties {
    Object _this;
  public:
    AllowDynamicProperties();
};

class SensitiveParameter {
    Object _this;
  public:
    SensitiveParameter();
};

class SensitiveParameterValue {
    Object _this;
  public:
    SensitiveParameterValue(const Variant &value);
    Variant getValue();
    Variant __debugInfo();
};

class Fiber {
    Object _this;
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
    Object _this;
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

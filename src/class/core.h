namespace php {
class InternalIterator {
  private:
    Variant _this;
  public:
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant rewind();
};

class Exception {
  private:
    Variant _this;
  public:
    Exception(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    ErrorException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    Error(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    CompileError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    ParseError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    TypeError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    ArgumentCountError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    ValueError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    ArithmeticError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    DivisionByZeroError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    UnhandledMatchError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    static Variant bind(const std::initializer_list<Variant> &args);
    Variant bindTo(const std::initializer_list<Variant> &args);
    Variant call(const std::initializer_list<Variant> &args);
    static Variant fromCallable(const std::initializer_list<Variant> &args);
    Variant __invoke();
};

class Generator {
  private:
    Variant _this;
  public:
    Variant rewind();
    Variant valid();
    Variant current();
    Variant key();
    Variant next();
    Variant send(const std::initializer_list<Variant> &args);
    Variant _throw(const std::initializer_list<Variant> &args);
    Variant getReturn();
};

class ClosedGeneratorException {
  private:
    Variant _this;
  public:
    ClosedGeneratorException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    WeakReference();
    static Variant create(const std::initializer_list<Variant> &args);
    Variant get();
};

class WeakMap {
  private:
    Variant _this;
  public:
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant count();
    Variant getIterator();
};

class Attribute {
  private:
    Variant _this;
  public:
    Attribute(const std::initializer_list<Variant> &args);
};

class ReturnTypeWillChange {
  private:
    Variant _this;
  public:
    ReturnTypeWillChange();
};

class AllowDynamicProperties {
  private:
    Variant _this;
  public:
    AllowDynamicProperties();
};

class SensitiveParameter {
  private:
    Variant _this;
  public:
    SensitiveParameter();
};

class SensitiveParameterValue {
  private:
    Variant _this;
  public:
    SensitiveParameterValue(const std::initializer_list<Variant> &args);
    Variant getValue();
    Variant __debugInfo();
};

class Fiber {
  private:
    Variant _this;
  public:
    Fiber(const std::initializer_list<Variant> &args);
    Variant start(const std::initializer_list<Variant> &args);
    Variant resume(const std::initializer_list<Variant> &args);
    Variant _throw(const std::initializer_list<Variant> &args);
    Variant isStarted();
    Variant isSuspended();
    Variant isRunning();
    Variant isTerminated();
    Variant getReturn();
    static Variant getCurrent();
    static Variant suspend(const std::initializer_list<Variant> &args);
};

class FiberError {
  private:
    Variant _this;
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

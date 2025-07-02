namespace php {
class AssertionError {
    Object this_;
  public:
    AssertionError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class php_user_filter {
    Object this_;
  public:
    Variant filter(const Variant &in, const Variant &out, const Variant &consumed, const Variant &closing);
    Variant onCreate();
    Variant onClose();
};

class Directory {
    Object this_;
  public:
    Variant close();
    Variant rewind();
    Variant read();
};

}

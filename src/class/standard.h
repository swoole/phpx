namespace php {
class AssertionError {
  private:
    Variant _this;
  public:
    AssertionError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    Variant filter(const std::initializer_list<Variant> &args);
    Variant onCreate();
    Variant onClose();
};

class Directory {
  private:
    Variant _this;
  public:
    Variant close();
    Variant rewind();
    Variant read();
};

}

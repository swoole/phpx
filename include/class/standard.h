#include "phpx_literal_string.h"

namespace php {
class __PHP_Incomplete_Class {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    __PHP_Incomplete_Class();
};

class AssertionError {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
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

class RoundingMode {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    RoundingMode();
    static Variant cases();
};

class php_user_filter {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    php_user_filter();
    Variant filter(const Variant &in, const Variant &out, const Reference &consumed, const Variant &closing);
    Variant onCreate();
    Variant onClose();
};

class StreamBucket {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    StreamBucket();
};

class Directory {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    Directory();
    Variant close();
    Variant rewind();
    Variant read();
};

}  // namespace php

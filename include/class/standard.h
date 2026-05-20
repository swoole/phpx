#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class __PHP_Incomplete_Class {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit __PHP_Incomplete_Class(const Object &obj) : this_(obj) {}
    __PHP_Incomplete_Class();
};

class AssertionError {
    Object this_;

  public:
    Object getObject() const {
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
    Object getObject() const {
        return this_;
    }
    explicit RoundingMode(const Object &obj) : this_(obj) {}
    RoundingMode();
    static Variant cases();
};

class php_user_filter {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit php_user_filter(const Object &obj) : this_(obj) {}
    php_user_filter();
    Variant filter(const Variant &in, const Variant &out, const Reference &consumed, const Variant &closing);
    Variant onCreate();
    Variant onClose();
};

class StreamBucket {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit StreamBucket(const Object &obj) : this_(obj) {}
    StreamBucket();
};

class Directory {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Directory(const Object &obj) : this_(obj) {}
    Directory();
    Variant close();
    Variant rewind();
    Variant read();
};

}  // namespace php

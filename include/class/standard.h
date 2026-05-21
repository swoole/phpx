#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
class __PHP_Incomplete_Class;
class AssertionError;
class RoundingMode;
class php_user_filter;
class StreamBucket;
class Directory;

class __PHP_Incomplete_Class {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit __PHP_Incomplete_Class(const Object &obj) : this_(obj) {}
    __PHP_Incomplete_Class();
};

class AssertionError : public Error {
  public:
    AssertionError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class RoundingMode {
  protected:
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
  protected:
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
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit StreamBucket(const Object &obj) : this_(obj) {}
    StreamBucket();
};

class Directory {
  protected:
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

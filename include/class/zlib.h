#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class InflateContext;
class DeflateContext;

class InflateContext {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit InflateContext(const Object &obj) : this_(obj) {}
    InflateContext();
};

class DeflateContext {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DeflateContext(const Object &obj) : this_(obj) {}
    DeflateContext();
};

}  // namespace php

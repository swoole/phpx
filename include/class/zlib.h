#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class InflateContext {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit InflateContext(const Object &obj) : this_(obj) {}
    InflateContext();
};

class DeflateContext {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DeflateContext(const Object &obj) : this_(obj) {}
    DeflateContext();
};

}  // namespace php

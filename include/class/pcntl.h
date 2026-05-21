#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class Pcntl_QosClass;

class Pcntl_QosClass {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Pcntl_QosClass(const Object &obj) : this_(obj) {}
    Pcntl_QosClass();
    static Variant cases();
};

}  // namespace php

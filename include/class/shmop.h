#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class Shmop;

class Shmop {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Shmop(const Object &obj) : this_(obj) {}
    Shmop();
};

}  // namespace php

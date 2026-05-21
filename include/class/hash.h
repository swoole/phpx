#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class HashContext;

class HashContext {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

}  // namespace php

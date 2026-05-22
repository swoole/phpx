#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class finfo;

class finfo {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    finfo(const Variant &flags = 0, const Variant &magic_database = nullptr);
    Variant file(const Variant &filename, const Variant &flags = 0, const Variant &context = nullptr);
    Variant buffer(const Variant &string, const Variant &flags = 0, const Variant &context = nullptr);
    Variant set_flags(const Variant &flags);
};

}  // namespace php

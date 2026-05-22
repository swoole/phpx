#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
namespace Pcntl {
class QosClass;
}

namespace Pcntl {

class QosClass {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit QosClass(const Object &obj) : this_(obj) {}
    QosClass();
    static Variant cases();
};

}  // namespace Pcntl
}  // namespace php

#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class LibXMLError {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit LibXMLError(const Object &obj) : this_(obj) {}
    LibXMLError();
};

}  // namespace php

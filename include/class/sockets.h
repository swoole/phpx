#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class Socket {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Socket(const Object &obj) : this_(obj) {}
    Socket();
};

class AddressInfo {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit AddressInfo(const Object &obj) : this_(obj) {}
    AddressInfo();
};

}  // namespace php

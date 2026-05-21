#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class Socket;
class AddressInfo;

class Socket {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Socket(const Object &obj) : this_(obj) {}
    Socket();
};

class AddressInfo {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit AddressInfo(const Object &obj) : this_(obj) {}
    AddressInfo();
};

}  // namespace php

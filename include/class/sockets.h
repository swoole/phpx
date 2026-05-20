#include "phpx_literal_string.h"

namespace php {
class Socket {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    Socket();
};

class AddressInfo {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    AddressInfo();
};

}  // namespace php

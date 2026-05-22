#include "phpx.h"
#include "phpx_class.h"
#include "class/sockets.h"

namespace php {
Socket::Socket() {
    this_ = newObject(LITERAL_STRING[1862]);
}
AddressInfo::AddressInfo() {
    this_ = newObject(LITERAL_STRING[1863]);
}
}  // namespace php

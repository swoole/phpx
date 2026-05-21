#include "phpx.h"
#include "phpx_class.h"
#include "class/sockets.h"

namespace php {
Socket::Socket() {
    this_ = newObject(LITERAL_STRING[1868]);
}
AddressInfo::AddressInfo() {
    this_ = newObject(LITERAL_STRING[1869]);
}
}  // namespace php

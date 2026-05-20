#include "phpx.h"
#include "class/sockets.h"

namespace php {
Socket::Socket() {
    this_ = newObject(LITERAL_STRING[1732]);
}
AddressInfo::AddressInfo() {
    this_ = newObject(LITERAL_STRING[1733]);
}
}  // namespace php

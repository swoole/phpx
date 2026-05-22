#include "phpx.h"
#include "class/sockets.h"

namespace php {
Socket::Socket() {
    this_ = newObject(LITERAL_STRING[1907]);
}
AddressInfo::AddressInfo() {
    this_ = newObject(LITERAL_STRING[1908]);
}
}  // namespace php

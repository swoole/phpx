#include "phpx.h"
#include "class/shmop.h"

namespace php {
Shmop::Shmop() {
    this_ = newObject(LITERAL_STRING[1853]);
}
}  // namespace php

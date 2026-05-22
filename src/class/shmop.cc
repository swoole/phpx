#include "phpx.h"
#include "phpx_class.h"
#include "class/shmop.h"

namespace php {
Shmop::Shmop() {
    this_ = newObject(LITERAL_STRING[1853]);
}
}  // namespace php

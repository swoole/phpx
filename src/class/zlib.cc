#include "phpx.h"
#include "class/zlib.h"

namespace php {
InflateContext::InflateContext() {
    this_ = newObject(LITERAL_STRING[2614]);
}
DeflateContext::DeflateContext() {
    this_ = newObject(LITERAL_STRING[2615]);
}
}  // namespace php

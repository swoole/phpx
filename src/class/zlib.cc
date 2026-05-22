#include "phpx.h"
#include "class/zlib.h"

namespace php {
InflateContext::InflateContext() {
    this_ = newObject(LITERAL_STRING[3550]);
}
DeflateContext::DeflateContext() {
    this_ = newObject(LITERAL_STRING[3551]);
}
}  // namespace php

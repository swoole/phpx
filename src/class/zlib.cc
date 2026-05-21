#include "phpx.h"
#include "phpx_class.h"
#include "class/zlib.h"

namespace php {
InflateContext::InflateContext() {
    this_ = newObject(LITERAL_STRING[2778]);
}
DeflateContext::DeflateContext() {
    this_ = newObject(LITERAL_STRING[2779]);
}
}  // namespace php

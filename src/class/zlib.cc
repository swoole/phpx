#include "phpx.h"
#include "phpx_class.h"
#include "class/zlib.h"

namespace php {
InflateContext::InflateContext() {
    this_ = newObject(LITERAL_STRING[2980]);
}
DeflateContext::DeflateContext() {
    this_ = newObject(LITERAL_STRING[2981]);
}
}  // namespace php

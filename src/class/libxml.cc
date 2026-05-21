#include "phpx.h"
#include "phpx_class.h"
#include "class/libxml.h"

namespace php {
LibXMLError::LibXMLError() {
    this_ = newObject(LITERAL_STRING[681]);
}
}  // namespace php

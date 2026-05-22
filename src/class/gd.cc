#include "phpx.h"
#include "phpx_class.h"
#include "class/gd.h"

namespace php {
GdImage::GdImage() {
    this_ = newObject(LITERAL_STRING[663]);
}
GdFont::GdFont() {
    this_ = newObject(LITERAL_STRING[664]);
}
}  // namespace php

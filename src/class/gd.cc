#include "phpx.h"
#include "phpx_class.h"
#include "class/gd.h"

namespace php {
GdImage::GdImage() {
    this_ = newObject(LITERAL_STRING[635]);
}
GdFont::GdFont() {
    this_ = newObject(LITERAL_STRING[636]);
}
}  // namespace php

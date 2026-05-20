#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class GdImage {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit GdImage(const Object &obj) : this_(obj) {}
    GdImage();
};

class GdFont {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit GdFont(const Object &obj) : this_(obj) {}
    GdFont();
};

}  // namespace php

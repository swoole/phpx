#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class GdImage;
class GdFont;

class GdImage {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit GdImage(const Object &obj) : this_(obj) {}
    GdImage();
};

class GdFont {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit GdFont(const Object &obj) : this_(obj) {}
    GdFont();
};

}  // namespace php

#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class XMLParser;

class XMLParser {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit XMLParser(const Object &obj) : this_(obj) {}
    XMLParser();
};

}  // namespace php

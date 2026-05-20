#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class XMLParser {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit XMLParser(const Object &obj) : this_(obj) {}
    XMLParser();
};

}  // namespace php

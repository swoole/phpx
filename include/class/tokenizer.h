#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class PhpToken;

class PhpToken {
  protected:
    Object this_;
    PhpToken() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static Variant tokenize(const Variant &code, const Variant &flags = 0);
    PhpToken(const Variant &id, const Variant &text, const Variant &line = -1, const Variant &pos = -1);
    Variant is(const Variant &kind);
    Variant isIgnorable();
    Variant getTokenName();
    Variant __toString();
};

}  // namespace php

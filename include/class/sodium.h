#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
class SodiumException;

class SodiumException : public Exception {
  public:
    SodiumException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

}  // namespace php

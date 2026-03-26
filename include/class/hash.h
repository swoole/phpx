#include "phpx_literal_string.h"

namespace php {
class HashContext {
    Object this_;

  public:
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

}  // namespace php

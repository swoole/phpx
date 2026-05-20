#include "phpx_literal_string.h"

namespace php {
class InflateContext {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    InflateContext();
};

class DeflateContext {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    DeflateContext();
};

}  // namespace php

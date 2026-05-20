#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class SessionHandler {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit SessionHandler(const Object &obj) : this_(obj) {}
    SessionHandler();
    Variant open(const Variant &path, const Variant &name);
    Variant close();
    Variant read(const Variant &id);
    Variant write(const Variant &id, const Variant &data);
    Variant destroy(const Variant &id);
    Variant gc(const Variant &max_lifetime);
    Variant create_sid();
};

}  // namespace php

#pragma once

#include "phpx.h"

// Minimal class facade used only by the Google tests. It is not installed.
namespace php {

class DateTime {
  public:
    static Variant createFromFormat(const Variant &format,
                                    const Variant &datetime,
                                    const Variant &timezone = nullptr) {
        return callStaticMethod("DateTime", "createFromFormat", {format, datetime, timezone});
    }
};

class Redis {
  public:
    explicit Redis(const Variant &options = {}) : object_(newObject("Redis", {options})) {}

    Variant connect(const Variant &host,
                    const Variant &port = 6379,
                    const Variant &timeout = 0,
                    const Variant &reserved = nullptr,
                    const Variant &retry_interval = 0,
                    const Variant &read_timeout = 0,
                    const Variant &context = nullptr) {
        return object_.call(
            "connect", {host, port, timeout, reserved, retry_interval, read_timeout, context});
    }

    Variant set(const Variant &key, const Variant &value, const Variant &options = nullptr) {
        return object_.call("set", {key, value, options});
    }

    Variant get(const Variant &key) {
        return object_.call("get", {key});
    }

  private:
    Object object_;
};

}  // namespace php

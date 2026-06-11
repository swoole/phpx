/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP math functions               |
  +----------------------------------------------------------------------+
*/

#include "php_std_math.h"

#include <cmath>

namespace php::std {

Float round(const Variant &value, Int precision, Int mode) {
    double val;
    if (value.isNumeric()) {
        val = value.toFloat();
    } else {
        return 0.0;
    }
    return static_cast<Float>(_php_math_round(val, static_cast<int>(precision), static_cast<int>(mode)));
}

Variant max(const Variant &arg) {
    if (!arg.isArray()) {
        return arg;
    }
    Array values = arg.toArray();
    if (values.count() == 0) {
        php::throwException(zend_ce_value_error, "max(): Argument must contain at least one element");
        return Variant();
    }
    Variant result = values.get(static_cast<zend_ulong>(0));
    for (const auto &item : values) {
        Variant cur = item.value;
        if (zend_compare(cur.unwrap_ptr(), result.unwrap_ptr()) > 0) {
            result = cur;
        }
    }
    return result;
}

Variant min(const Variant &arg) {
    if (!arg.isArray()) {
        return arg;
    }
    Array values = arg.toArray();
    if (values.count() == 0) {
        php::throwException(zend_ce_value_error, "min(): Argument must contain at least one element");
        return Variant();
    }
    Variant result = values.get(static_cast<zend_ulong>(0));
    for (const auto &item : values) {
        Variant cur = item.value;
        if (zend_compare(cur.unwrap_ptr(), result.unwrap_ptr()) < 0) {
            result = cur;
        }
    }
    return result;
}

}  // namespace php::std

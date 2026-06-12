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

}  // namespace php::std

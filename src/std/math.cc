/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP math functions               |
  +----------------------------------------------------------------------+
*/

#include "std/math.h"

#include <cmath>

namespace php::fn {

Float round(const Variant &value, Int precision, Int mode) {
    double val;
    if (value.isNumeric()) {
        val = value.toFloat();
    } else {
        php::throwException(zend_ce_type_error, "round(): Argument #1 ($num) must be of type int|float");
        return 0.0;
    }
    return static_cast<Float>(_php_math_round(val, static_cast<int>(precision), static_cast<int>(mode)));
}

}  // namespace php::fn

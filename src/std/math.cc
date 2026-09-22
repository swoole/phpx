/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP math functions               |
  +----------------------------------------------------------------------+
*/

#include "std/math.h"

#include <climits>
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
    switch (mode) {
    case PHP_ROUND_HALF_UP:
    case PHP_ROUND_HALF_DOWN:
    case PHP_ROUND_HALF_EVEN:
    case PHP_ROUND_HALF_ODD:
    case PHP_ROUND_AWAY_FROM_ZERO:
    case PHP_ROUND_TOWARD_ZERO:
    case PHP_ROUND_CEILING:
    case PHP_ROUND_FLOOR:
        break;
    default:
        php::throwException(zend_ce_value_error,
                            "round(): Argument #3 ($mode) must be a valid rounding mode (RoundingMode::*)");
        return 0.0;
    }

    const int places = precision > INT_MAX ? INT_MAX : (precision < INT_MIN ? INT_MIN : static_cast<int>(precision));
    return static_cast<Float>(_php_math_round(val, places, static_cast<int>(mode)));
}

}  // namespace php::fn

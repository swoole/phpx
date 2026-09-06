/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - Direct C++ wrappers for PHP date/time functions          |
  +----------------------------------------------------------------------+
*/

#include "std/datetime.h"

namespace php::fn {

static String format_date(const String &format, const Variant &timestamp, bool localtime) {
    time_t ts;
    if (timestamp.isNull()) {
        ts = php_time();
    } else {
        ts = static_cast<time_t>(timestamp.toInt());
    }
    zend_string *result = php_format_date(format.data(), format.length(), ts, localtime);
    if (!result) {
        return String();
    }
    return String(result, Ctor::Move);
}

String date(const String &format, const Variant &timestamp) {
    return format_date(format, timestamp, true);
}

String gmdate(const String &format, const Variant &timestamp) {
    return format_date(format, timestamp, false);
}

Variant strtotime(const String &datetime, const Variant &baseTimestamp) {
    if (!baseTimestamp.isNull()) {
        zend_long base = static_cast<zend_long>(baseTimestamp.toInt());
        zend_long result = php_parse_date(datetime.data(), &base);
        if (result == -1) {
            return Variant(false);
        }
        return Variant(static_cast<Int>(result));
    }
    zend_long result = php_parse_date(datetime.data(), nullptr);
    if (result == -1) {
        return Variant(false);
    }
    return Variant(static_cast<Int>(result));
}

}  // namespace php::fn

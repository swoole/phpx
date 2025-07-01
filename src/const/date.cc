#include "phpx.h"

namespace php {
Variant DATE_ATOM { ZEND_STRL("Y-m-d\\TH:i:sP"), true };
Variant DATE_COOKIE { ZEND_STRL("l, d-M-Y H:i:s T"), true };
Variant DATE_ISO8601 { ZEND_STRL("Y-m-d\\TH:i:sO"), true };
Variant DATE_ISO8601_EXPANDED { ZEND_STRL("X-m-d\\TH:i:sP"), true };
Variant DATE_RFC822 { ZEND_STRL("D, d M y H:i:s O"), true };
Variant DATE_RFC850 { ZEND_STRL("l, d-M-y H:i:s T"), true };
Variant DATE_RFC1036 { ZEND_STRL("D, d M y H:i:s O"), true };
Variant DATE_RFC1123 { ZEND_STRL("D, d M Y H:i:s O"), true };
Variant DATE_RFC7231 { ZEND_STRL("D, d M Y H:i:s \\G\\M\\T"), true };
Variant DATE_RFC2822 { ZEND_STRL("D, d M Y H:i:s O"), true };
Variant DATE_RFC3339 { ZEND_STRL("Y-m-d\\TH:i:sP"), true };
Variant DATE_RFC3339_EXTENDED { ZEND_STRL("Y-m-d\\TH:i:s.vP"), true };
Variant DATE_RSS { ZEND_STRL("D, d M Y H:i:s O"), true };
Variant DATE_W3C { ZEND_STRL("Y-m-d\\TH:i:sP"), true };
Variant SUNFUNCS_RET_TIMESTAMP { 0 };
Variant SUNFUNCS_RET_STRING { 1 };
Variant SUNFUNCS_RET_DOUBLE { 2 };
}

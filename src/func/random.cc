#include "phpx.h"

namespace php {
Variant lcg_value{ZEND_STRL("lcg_value"), true};
Variant mt_srand{ZEND_STRL("mt_srand"), true};
Variant srand{ZEND_STRL("srand"), true};
Variant rand{ZEND_STRL("rand"), true};
Variant mt_rand{ZEND_STRL("mt_rand"), true};
Variant mt_getrandmax{ZEND_STRL("mt_getrandmax"), true};
Variant getrandmax{ZEND_STRL("getrandmax"), true};
Variant random_bytes{ZEND_STRL("random_bytes"), true};
Variant random_int{ZEND_STRL("random_int"), true};
}

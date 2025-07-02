#include "phpx.h"

namespace php {
Variant hash{ZEND_STRL("hash"), true};
Variant hash_file{ZEND_STRL("hash_file"), true};
Variant hash_hmac{ZEND_STRL("hash_hmac"), true};
Variant hash_hmac_file{ZEND_STRL("hash_hmac_file"), true};
Variant hash_init{ZEND_STRL("hash_init"), true};
Variant hash_update{ZEND_STRL("hash_update"), true};
Variant hash_update_stream{ZEND_STRL("hash_update_stream"), true};
Variant hash_update_file{ZEND_STRL("hash_update_file"), true};
Variant hash_final{ZEND_STRL("hash_final"), true};
Variant hash_copy{ZEND_STRL("hash_copy"), true};
Variant hash_algos{ZEND_STRL("hash_algos"), true};
Variant hash_hmac_algos{ZEND_STRL("hash_hmac_algos"), true};
Variant hash_pbkdf2{ZEND_STRL("hash_pbkdf2"), true};
Variant hash_equals{ZEND_STRL("hash_equals"), true};
Variant hash_hkdf{ZEND_STRL("hash_hkdf"), true};
}

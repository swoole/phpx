#include "phpx.h"

namespace php {
Variant preg_match{ZEND_STRL("preg_match"), true};
Variant preg_match_all{ZEND_STRL("preg_match_all"), true};
Variant preg_replace{ZEND_STRL("preg_replace"), true};
Variant preg_filter{ZEND_STRL("preg_filter"), true};
Variant preg_replace_callback{ZEND_STRL("preg_replace_callback"), true};
Variant preg_replace_callback_array{ZEND_STRL("preg_replace_callback_array"), true};
Variant preg_split{ZEND_STRL("preg_split"), true};
Variant preg_quote{ZEND_STRL("preg_quote"), true};
Variant preg_grep{ZEND_STRL("preg_grep"), true};
Variant preg_last_error{ZEND_STRL("preg_last_error"), true};
Variant preg_last_error_msg{ZEND_STRL("preg_last_error_msg"), true};
}

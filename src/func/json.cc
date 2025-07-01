#include "phpx.h"

namespace php {
Variant json_encode{ZEND_STRL("json_encode"), true};
Variant json_decode{ZEND_STRL("json_decode"), true};
Variant json_last_error{ZEND_STRL("json_last_error"), true};
Variant json_last_error_msg{ZEND_STRL("json_last_error_msg"), true};
}

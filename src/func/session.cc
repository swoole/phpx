#include "phpx.h"

namespace php {
Variant session_name{ZEND_STRL("session_name"), true};
Variant session_module_name{ZEND_STRL("session_module_name"), true};
Variant session_save_path{ZEND_STRL("session_save_path"), true};
Variant session_id{ZEND_STRL("session_id"), true};
Variant session_create_id{ZEND_STRL("session_create_id"), true};
Variant session_regenerate_id{ZEND_STRL("session_regenerate_id"), true};
Variant session_decode{ZEND_STRL("session_decode"), true};
Variant session_encode{ZEND_STRL("session_encode"), true};
Variant session_destroy{ZEND_STRL("session_destroy"), true};
Variant session_unset{ZEND_STRL("session_unset"), true};
Variant session_gc{ZEND_STRL("session_gc"), true};
Variant session_get_cookie_params{ZEND_STRL("session_get_cookie_params"), true};
Variant session_write_close{ZEND_STRL("session_write_close"), true};
Variant session_abort{ZEND_STRL("session_abort"), true};
Variant session_reset{ZEND_STRL("session_reset"), true};
Variant session_status{ZEND_STRL("session_status"), true};
Variant session_register_shutdown{ZEND_STRL("session_register_shutdown"), true};
Variant session_commit{ZEND_STRL("session_commit"), true};
Variant session_set_save_handler{ZEND_STRL("session_set_save_handler"), true};
Variant session_cache_limiter{ZEND_STRL("session_cache_limiter"), true};
Variant session_cache_expire{ZEND_STRL("session_cache_expire"), true};
Variant session_set_cookie_params{ZEND_STRL("session_set_cookie_params"), true};
Variant session_start{ZEND_STRL("session_start"), true};
}

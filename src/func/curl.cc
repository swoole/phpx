#include "phpx.h"

namespace php {
Variant curl_close{ZEND_STRL("curl_close"), true};
Variant curl_copy_handle{ZEND_STRL("curl_copy_handle"), true};
Variant curl_errno{ZEND_STRL("curl_errno"), true};
Variant curl_error{ZEND_STRL("curl_error"), true};
Variant curl_escape{ZEND_STRL("curl_escape"), true};
Variant curl_unescape{ZEND_STRL("curl_unescape"), true};
Variant curl_multi_setopt{ZEND_STRL("curl_multi_setopt"), true};
Variant curl_exec{ZEND_STRL("curl_exec"), true};
Variant curl_file_create{ZEND_STRL("curl_file_create"), true};
Variant curl_getinfo{ZEND_STRL("curl_getinfo"), true};
Variant curl_init{ZEND_STRL("curl_init"), true};
Variant curl_upkeep{ZEND_STRL("curl_upkeep"), true};
Variant curl_multi_add_handle{ZEND_STRL("curl_multi_add_handle"), true};
Variant curl_multi_close{ZEND_STRL("curl_multi_close"), true};
Variant curl_multi_errno{ZEND_STRL("curl_multi_errno"), true};
Variant curl_multi_exec{ZEND_STRL("curl_multi_exec"), true};
Variant curl_multi_getcontent{ZEND_STRL("curl_multi_getcontent"), true};
Variant curl_multi_info_read{ZEND_STRL("curl_multi_info_read"), true};
Variant curl_multi_init{ZEND_STRL("curl_multi_init"), true};
Variant curl_multi_remove_handle{ZEND_STRL("curl_multi_remove_handle"), true};
Variant curl_multi_select{ZEND_STRL("curl_multi_select"), true};
Variant curl_multi_strerror{ZEND_STRL("curl_multi_strerror"), true};
Variant curl_pause{ZEND_STRL("curl_pause"), true};
Variant curl_reset{ZEND_STRL("curl_reset"), true};
Variant curl_setopt_array{ZEND_STRL("curl_setopt_array"), true};
Variant curl_setopt{ZEND_STRL("curl_setopt"), true};
Variant curl_share_close{ZEND_STRL("curl_share_close"), true};
Variant curl_share_errno{ZEND_STRL("curl_share_errno"), true};
Variant curl_share_init{ZEND_STRL("curl_share_init"), true};
Variant curl_share_setopt{ZEND_STRL("curl_share_setopt"), true};
Variant curl_share_strerror{ZEND_STRL("curl_share_strerror"), true};
Variant curl_strerror{ZEND_STRL("curl_strerror"), true};
Variant curl_version{ZEND_STRL("curl_version"), true};
}

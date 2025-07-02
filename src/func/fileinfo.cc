#include "phpx.h"

namespace php {
Variant finfo_open{ZEND_STRL("finfo_open"), true};
Variant finfo_close{ZEND_STRL("finfo_close"), true};
Variant finfo_set_flags{ZEND_STRL("finfo_set_flags"), true};
Variant finfo_file{ZEND_STRL("finfo_file"), true};
Variant finfo_buffer{ZEND_STRL("finfo_buffer"), true};
Variant mime_content_type{ZEND_STRL("mime_content_type"), true};
}

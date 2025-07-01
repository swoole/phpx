#include "phpx.h"

namespace php {
Variant iconv_strlen{ZEND_STRL("iconv_strlen"), true};
Variant iconv_substr{ZEND_STRL("iconv_substr"), true};
Variant iconv_strpos{ZEND_STRL("iconv_strpos"), true};
Variant iconv_strrpos{ZEND_STRL("iconv_strrpos"), true};
Variant iconv_mime_encode{ZEND_STRL("iconv_mime_encode"), true};
Variant iconv_mime_decode{ZEND_STRL("iconv_mime_decode"), true};
Variant iconv_mime_decode_headers{ZEND_STRL("iconv_mime_decode_headers"), true};
Variant iconv{ZEND_STRL("iconv"), true};
Variant iconv_set_encoding{ZEND_STRL("iconv_set_encoding"), true};
Variant iconv_get_encoding{ZEND_STRL("iconv_get_encoding"), true};
}

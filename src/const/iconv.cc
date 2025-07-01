#include "phpx.h"

namespace php {
Variant ICONV_IMPL { ZEND_STRL("glibc"), true };
Variant ICONV_VERSION { ZEND_STRL("2.35"), true };
Variant ICONV_MIME_DECODE_STRICT { 1 };
Variant ICONV_MIME_DECODE_CONTINUE_ON_ERROR { 2 };
}

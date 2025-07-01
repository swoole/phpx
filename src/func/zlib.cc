#include "phpx.h"

namespace php {
Variant ob_gzhandler{ZEND_STRL("ob_gzhandler"), true};
Variant zlib_get_coding_type{ZEND_STRL("zlib_get_coding_type"), true};
Variant gzfile{ZEND_STRL("gzfile"), true};
Variant gzopen{ZEND_STRL("gzopen"), true};
Variant readgzfile{ZEND_STRL("readgzfile"), true};
Variant zlib_encode{ZEND_STRL("zlib_encode"), true};
Variant zlib_decode{ZEND_STRL("zlib_decode"), true};
Variant gzdeflate{ZEND_STRL("gzdeflate"), true};
Variant gzencode{ZEND_STRL("gzencode"), true};
Variant gzcompress{ZEND_STRL("gzcompress"), true};
Variant gzinflate{ZEND_STRL("gzinflate"), true};
Variant gzdecode{ZEND_STRL("gzdecode"), true};
Variant gzuncompress{ZEND_STRL("gzuncompress"), true};
Variant gzwrite{ZEND_STRL("gzwrite"), true};
Variant gzputs{ZEND_STRL("gzputs"), true};
Variant gzrewind{ZEND_STRL("gzrewind"), true};
Variant gzclose{ZEND_STRL("gzclose"), true};
Variant gzeof{ZEND_STRL("gzeof"), true};
Variant gzgetc{ZEND_STRL("gzgetc"), true};
Variant gzpassthru{ZEND_STRL("gzpassthru"), true};
Variant gzseek{ZEND_STRL("gzseek"), true};
Variant gztell{ZEND_STRL("gztell"), true};
Variant gzread{ZEND_STRL("gzread"), true};
Variant gzgets{ZEND_STRL("gzgets"), true};
Variant deflate_init{ZEND_STRL("deflate_init"), true};
Variant deflate_add{ZEND_STRL("deflate_add"), true};
Variant inflate_init{ZEND_STRL("inflate_init"), true};
Variant inflate_add{ZEND_STRL("inflate_add"), true};
Variant inflate_get_status{ZEND_STRL("inflate_get_status"), true};
Variant inflate_get_read_len{ZEND_STRL("inflate_get_read_len"), true};
}

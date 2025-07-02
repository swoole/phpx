#include "phpx.h"

namespace php {
Variant FORCE_GZIP { 31 };
Variant FORCE_DEFLATE { 15 };
Variant ZLIB_ENCODING_RAW { -15 };
Variant ZLIB_ENCODING_GZIP { 31 };
Variant ZLIB_ENCODING_DEFLATE { 15 };
Variant ZLIB_NO_FLUSH { 0 };
Variant ZLIB_PARTIAL_FLUSH { 1 };
Variant ZLIB_SYNC_FLUSH { 2 };
Variant ZLIB_FULL_FLUSH { 3 };
Variant ZLIB_BLOCK { 5 };
Variant ZLIB_FINISH { 4 };
Variant ZLIB_FILTERED { 1 };
Variant ZLIB_HUFFMAN_ONLY { 2 };
Variant ZLIB_RLE { 3 };
Variant ZLIB_FIXED { 4 };
Variant ZLIB_DEFAULT_STRATEGY { 0 };
Variant ZLIB_VERSION { ZEND_STRL("1.2.11"), true };
Variant ZLIB_VERNUM { 4784 };
Variant ZLIB_OK { 0 };
Variant ZLIB_STREAM_END { 1 };
Variant ZLIB_NEED_DICT { 2 };
Variant ZLIB_ERRNO { -1 };
Variant ZLIB_STREAM_ERROR { -2 };
Variant ZLIB_DATA_ERROR { -3 };
Variant ZLIB_MEM_ERROR { -4 };
Variant ZLIB_BUF_ERROR { -5 };
Variant ZLIB_VERSION_ERROR { -6 };
}

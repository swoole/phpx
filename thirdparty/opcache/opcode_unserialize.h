/* Adapted from PHP's ext/opcache file-cache format (PHP License 3.01). */
#ifndef TYPEPHP_OPCODE_UNSERIALIZE_H
#define TYPEPHP_OPCODE_UNSERIALIZE_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(PHP_WIN32) && defined(__clang__) && !defined(PHP_NANO)
/* C decoders cannot include phpx.h. Apply the same MSVC PHP allocator
 * compatibility before php.h includes zend_alloc.h. */
#include "Zend/zend_portability.h"
#undef HAVE_BUILTIN_CONSTANT_P
#endif
#include "php.h"

typedef struct {
    const unsigned char *data;
    size_t size;
} typephp_opcode_blob;

/* The returned op_array is executed and destroyed by Zend's normal include path. */
zend_op_array *typephp_opcache_load(const typephp_opcode_blob *blob);

#ifdef __cplusplus
}
#endif

#endif

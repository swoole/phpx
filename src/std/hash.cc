/*
  +----------------------------------------------------------------------+
  | AOT Stdlib - PHP hash wrappers                                       |
  +----------------------------------------------------------------------+
*/

#include "std/hash.h"

namespace php::fn {

Variant md5(const String &value, bool raw_output) {
    PHP_MD5_CTX context;
    unsigned char digest[16];

    PHP_MD5Init(&context);
    PHP_MD5Update(&context, reinterpret_cast<const unsigned char *>(value.data()), value.length());
    PHP_MD5Final(digest, &context);

    if (raw_output) {
        return Variant(String(reinterpret_cast<char *>(digest), sizeof(digest)));
    }

    char hex[33];
    make_digest_ex(hex, digest, sizeof(digest));
    return Variant(String(hex, sizeof(hex) - 1));
}

Variant sha1(const String &value, bool raw_output) {
    PHP_SHA1_CTX context;
    unsigned char digest[20];

    PHP_SHA1Init(&context);
    PHP_SHA1Update(&context, reinterpret_cast<const unsigned char *>(value.data()), value.length());
    PHP_SHA1Final(digest, &context);

    if (raw_output) {
        return Variant(String(reinterpret_cast<char *>(digest), sizeof(digest)));
    }

    char hex[41];
    make_sha1_digest(hex, digest);
    return Variant(String(hex, sizeof(hex) - 1));
}

Variant hash(const String &algo, const String &data, bool raw_output) {
    const php_hash_ops *ops = php_hash_fetch_ops(algo.str());
    if (ops == nullptr) {
        php_error_docref(nullptr, E_WARNING, "Unknown hashing algorithm: %s", algo.data());
        return Variant(false);
    }

    void *context = php_hash_alloc_context(ops);
    ops->hash_init(context, nullptr);
    ops->hash_update(context, reinterpret_cast<const unsigned char *>(data.data()), data.length());

    auto *digest = static_cast<unsigned char *>(emalloc(ops->digest_size));
    ops->hash_final(digest, context);
#if PHP_VERSION_ID >= 80600
    php_hash_free_context(ops, context);
#else
    efree(context);
#endif

    if (raw_output) {
        String result(reinterpret_cast<char *>(digest), ops->digest_size);
        efree(digest);
        return Variant(result);
    }

    const size_t hex_len = ops->digest_size * 2;
    auto *hex = static_cast<char *>(emalloc(hex_len + 1));
#if PHP_VERSION_ID >= 80600
    zend_bin2hex(hex, digest, ops->digest_size);
#else
    php_hash_bin2hex(hex, digest, ops->digest_size);
#endif
    hex[hex_len] = '\0';
    efree(digest);

    String result(hex, hex_len);
    efree(hex);
    return Variant(result);
}

}  // namespace php::fn

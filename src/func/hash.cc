#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant hash(const Variant &algo, const Variant &data, const Variant &binary, const Variant &options) {
    return call(LITERAL_STRING[608], {algo, data, binary, options});
}
Variant hash_file(const Variant &algo, const Variant &filename, const Variant &binary, const Variant &options) {
    return call(LITERAL_STRING[609], {algo, filename, binary, options});
}
Variant hash_hmac(const Variant &algo, const Variant &data, const Variant &key, const Variant &binary) {
    return call(LITERAL_STRING[610], {algo, data, key, binary});
}
Variant hash_hmac_file(const Variant &algo, const Variant &filename, const Variant &key, const Variant &binary) {
    return call(LITERAL_STRING[611], {algo, filename, key, binary});
}
Variant hash_init(const Variant &algo, const Variant &flags, const Variant &key, const Variant &options) {
    return call(LITERAL_STRING[612], {algo, flags, key, options});
}
Variant hash_update(const Variant &context, const Variant &data) {
    return call(LITERAL_STRING[613], {context, data});
}
Variant hash_update_stream(const Variant &context, const Variant &stream, const Variant &length) {
    return call(LITERAL_STRING[614], {context, stream, length});
}
Variant hash_update_file(const Variant &context, const Variant &filename, const Variant &stream_context) {
    return call(LITERAL_STRING[615], {context, filename, stream_context});
}
Variant hash_final(const Variant &context, const Variant &binary) {
    return call(LITERAL_STRING[616], {context, binary});
}
Variant hash_copy(const Variant &context) {
    return call(LITERAL_STRING[617], {context});
}
Variant hash_algos() {
    return call(LITERAL_STRING[618], {});
}
Variant hash_hmac_algos() {
    return call(LITERAL_STRING[619], {});
}
Variant hash_pbkdf2(const Variant &algo,
                    const Variant &password,
                    const Variant &salt,
                    const Variant &iterations,
                    const Variant &length,
                    const Variant &binary,
                    const Variant &options) {
    return call(LITERAL_STRING[620], {algo, password, salt, iterations, length, binary, options});
}
Variant hash_equals(const Variant &known_string, const Variant &user_string) {
    return call(LITERAL_STRING[621], {known_string, user_string});
}
Variant hash_hkdf(
    const Variant &algo, const Variant &key, const Variant &length, const Variant &info, const Variant &salt) {
    return call(LITERAL_STRING[622], {algo, key, length, info, salt});
}
}  // namespace php

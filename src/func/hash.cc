#include "phpx.h"

namespace php {
Variant hash(const Variant &algo, const Variant &data, const Variant &binary, const Variant &options) {
    return call("hash", {algo, data, binary, options});
}
Variant hash_file(const Variant &algo, const Variant &filename, const Variant &binary, const Variant &options) {
    return call("hash_file", {algo, filename, binary, options});
}
Variant hash_hmac(const Variant &algo, const Variant &data, const Variant &key, const Variant &binary) {
    return call("hash_hmac", {algo, data, key, binary});
}
Variant hash_hmac_file(const Variant &algo, const Variant &filename, const Variant &key, const Variant &binary) {
    return call("hash_hmac_file", {algo, filename, key, binary});
}
Variant hash_init(const Variant &algo, const Variant &flags, const Variant &key, const Variant &options) {
    return call("hash_init", {algo, flags, key, options});
}
Variant hash_update(const Variant &context, const Variant &data) {
    return call("hash_update", {context, data});
}
Variant hash_update_stream(const Variant &context, const Variant &stream, const Variant &length) {
    return call("hash_update_stream", {context, stream, length});
}
Variant hash_update_file(const Variant &context, const Variant &filename, const Variant &stream_context) {
    return call("hash_update_file", {context, filename, stream_context});
}
Variant hash_final(const Variant &context, const Variant &binary) {
    return call("hash_final", {context, binary});
}
Variant hash_copy(const Variant &context) {
    return call("hash_copy", {context});
}
Variant hash_algos() {
    return call("hash_algos", {});
}
Variant hash_hmac_algos() {
    return call("hash_hmac_algos", {});
}
Variant hash_pbkdf2(const Variant &algo, const Variant &password, const Variant &salt, const Variant &iterations, const Variant &length, const Variant &binary, const Variant &options) {
    return call("hash_pbkdf2", {algo, password, salt, iterations, length, binary, options});
}
Variant hash_equals(const Variant &known_string, const Variant &user_string) {
    return call("hash_equals", {known_string, user_string});
}
Variant hash_hkdf(const Variant &algo, const Variant &key, const Variant &length, const Variant &info, const Variant &salt) {
    return call("hash_hkdf", {algo, key, length, info, salt});
}
}

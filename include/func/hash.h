#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant hash(const Variant &algo, const Variant &data, const Variant &binary = false, const Variant &options = Array{});
Variant hash_file(const Variant &algo,
                  const Variant &filename,
                  const Variant &binary = false,
                  const Variant &options = Array{});
Variant hash_hmac(const Variant &algo, const Variant &data, const Variant &key, const Variant &binary = false);
Variant hash_hmac_file(const Variant &algo, const Variant &filename, const Variant &key, const Variant &binary = false);
Variant hash_init(const Variant &algo,
                  const Variant &flags = 0,
                  const Variant &key = "",
                  const Variant &options = Array{});
Variant hash_update(const Variant &context, const Variant &data);
Variant hash_update_stream(const Variant &context, const Variant &stream, const Variant &length = -1);
Variant hash_update_file(const Variant &context, const Variant &filename, const Variant &stream_context = {});
Variant hash_final(const Variant &context, const Variant &binary = false);
Variant hash_copy(const Variant &context);
Variant hash_algos();
Variant hash_hmac_algos();
Variant hash_pbkdf2(const Variant &algo,
                    const Variant &password,
                    const Variant &salt,
                    const Variant &iterations,
                    const Variant &length = 0,
                    const Variant &binary = false,
                    const Variant &options = Array{});
Variant hash_equals(const Variant &known_string, const Variant &user_string);
Variant hash_hkdf(const Variant &algo,
                  const Variant &key,
                  const Variant &length = 0,
                  const Variant &info = "",
                  const Variant &salt = "");
}  // namespace php

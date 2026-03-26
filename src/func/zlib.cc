#include "phpx.h"

namespace php {
Variant ob_gzhandler(const Variant &data, const Variant &flags) {
    return call("ob_gzhandler", {data, flags});
}
Variant zlib_get_coding_type() {
    return call("zlib_get_coding_type", {});
}
Variant gzfile(const Variant &filename, const Variant &use_include_path) {
    return call("gzfile", {filename, use_include_path});
}
Variant gzopen(const Variant &filename, const Variant &mode, const Variant &use_include_path) {
    return call("gzopen", {filename, mode, use_include_path});
}
Variant readgzfile(const Variant &filename, const Variant &use_include_path) {
    return call("readgzfile", {filename, use_include_path});
}
Variant zlib_encode(const Variant &data, const Variant &encoding, const Variant &level) {
    return call("zlib_encode", {data, encoding, level});
}
Variant zlib_decode(const Variant &data, const Variant &max_length) {
    return call("zlib_decode", {data, max_length});
}
Variant gzdeflate(const Variant &data, const Variant &level, const Variant &encoding) {
    return call("gzdeflate", {data, level, encoding});
}
Variant gzencode(const Variant &data, const Variant &level, const Variant &encoding) {
    return call("gzencode", {data, level, encoding});
}
Variant gzcompress(const Variant &data, const Variant &level, const Variant &encoding) {
    return call("gzcompress", {data, level, encoding});
}
Variant gzinflate(const Variant &data, const Variant &max_length) {
    return call("gzinflate", {data, max_length});
}
Variant gzdecode(const Variant &data, const Variant &max_length) {
    return call("gzdecode", {data, max_length});
}
Variant gzuncompress(const Variant &data, const Variant &max_length) {
    return call("gzuncompress", {data, max_length});
}
Variant gzwrite(const Variant &stream, const Variant &data, const Variant &length) {
    return call("gzwrite", {stream, data, length});
}
Variant gzputs(const Variant &stream, const Variant &data, const Variant &length) {
    return call("gzputs", {stream, data, length});
}
Variant gzrewind(const Variant &stream) {
    return call("gzrewind", {stream});
}
Variant gzclose(const Variant &stream) {
    return call("gzclose", {stream});
}
Variant gzeof(const Variant &stream) {
    return call("gzeof", {stream});
}
Variant gzgetc(const Variant &stream) {
    return call("gzgetc", {stream});
}
Variant gzpassthru(const Variant &stream) {
    return call("gzpassthru", {stream});
}
Variant gzseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    return call("gzseek", {stream, offset, whence});
}
Variant gztell(const Variant &stream) {
    return call("gztell", {stream});
}
Variant gzread(const Variant &stream, const Variant &length) {
    return call("gzread", {stream, length});
}
Variant gzgets(const Variant &stream, const Variant &length) {
    return call("gzgets", {stream, length});
}
Variant deflate_init(const Variant &encoding, const Variant &options) {
    return call("deflate_init", {encoding, options});
}
Variant deflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    return call("deflate_add", {context, data, flush_mode});
}
Variant inflate_init(const Variant &encoding, const Variant &options) {
    return call("inflate_init", {encoding, options});
}
Variant inflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    return call("inflate_add", {context, data, flush_mode});
}
Variant inflate_get_status(const Variant &context) {
    return call("inflate_get_status", {context});
}
Variant inflate_get_read_len(const Variant &context) {
    return call("inflate_get_read_len", {context});
}
}

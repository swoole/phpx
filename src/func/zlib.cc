#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant ob_gzhandler(const Variant &data, const Variant &flags) {
    return call(LITERAL_STRING[2508], {data, flags});
}
Variant zlib_get_coding_type() {
    return call(LITERAL_STRING[2509], {});
}
Variant gzfile(const Variant &filename, const Variant &use_include_path) {
    return call(LITERAL_STRING[2510], {filename, use_include_path});
}
Variant gzopen(const Variant &filename, const Variant &mode, const Variant &use_include_path) {
    return call(LITERAL_STRING[2511], {filename, mode, use_include_path});
}
Variant readgzfile(const Variant &filename, const Variant &use_include_path) {
    return call(LITERAL_STRING[2512], {filename, use_include_path});
}
Variant zlib_encode(const Variant &data, const Variant &encoding, const Variant &level) {
    return call(LITERAL_STRING[2513], {data, encoding, level});
}
Variant zlib_decode(const Variant &data, const Variant &max_length) {
    return call(LITERAL_STRING[2514], {data, max_length});
}
Variant gzdeflate(const Variant &data, const Variant &level, const Variant &encoding) {
    return call(LITERAL_STRING[2515], {data, level, encoding});
}
Variant gzencode(const Variant &data, const Variant &level, const Variant &encoding) {
    return call(LITERAL_STRING[2516], {data, level, encoding});
}
Variant gzcompress(const Variant &data, const Variant &level, const Variant &encoding) {
    return call(LITERAL_STRING[2517], {data, level, encoding});
}
Variant gzinflate(const Variant &data, const Variant &max_length) {
    return call(LITERAL_STRING[2518], {data, max_length});
}
Variant gzdecode(const Variant &data, const Variant &max_length) {
    return call(LITERAL_STRING[2519], {data, max_length});
}
Variant gzuncompress(const Variant &data, const Variant &max_length) {
    return call(LITERAL_STRING[2520], {data, max_length});
}
Variant gzwrite(const Variant &stream, const Variant &data, const Variant &length) {
    return call(LITERAL_STRING[2521], {stream, data, length});
}
Variant gzputs(const Variant &stream, const Variant &data, const Variant &length) {
    return call(LITERAL_STRING[2522], {stream, data, length});
}
Variant gzrewind(const Variant &stream) {
    return call(LITERAL_STRING[2523], {stream});
}
Variant gzclose(const Variant &stream) {
    return call(LITERAL_STRING[2524], {stream});
}
Variant gzeof(const Variant &stream) {
    return call(LITERAL_STRING[2525], {stream});
}
Variant gzgetc(const Variant &stream) {
    return call(LITERAL_STRING[2526], {stream});
}
Variant gzpassthru(const Variant &stream) {
    return call(LITERAL_STRING[2527], {stream});
}
Variant gzseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    return call(LITERAL_STRING[2528], {stream, offset, whence});
}
Variant gztell(const Variant &stream) {
    return call(LITERAL_STRING[2529], {stream});
}
Variant gzread(const Variant &stream, const Variant &length) {
    return call(LITERAL_STRING[2530], {stream, length});
}
Variant gzgets(const Variant &stream, const Variant &length) {
    return call(LITERAL_STRING[2531], {stream, length});
}
Variant deflate_init(const Variant &encoding, const Variant &options) {
    return call(LITERAL_STRING[2532], {encoding, options});
}
Variant deflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    return call(LITERAL_STRING[2533], {context, data, flush_mode});
}
Variant inflate_init(const Variant &encoding, const Variant &options) {
    return call(LITERAL_STRING[2534], {encoding, options});
}
Variant inflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    return call(LITERAL_STRING[2535], {context, data, flush_mode});
}
Variant inflate_get_status(const Variant &context) {
    return call(LITERAL_STRING[2536], {context});
}
Variant inflate_get_read_len(const Variant &context) {
    return call(LITERAL_STRING[2537], {context});
}
}  // namespace php

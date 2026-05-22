#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant ob_gzhandler(const Variant &data, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2742]);
    }
    return call(fn, {data, flags});
}
Variant zlib_get_coding_type() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2743]);
    }
    return call(fn, {});
}
Variant gzfile(const Variant &filename, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2744]);
    }
    return call(fn, {filename, use_include_path});
}
Variant gzopen(const Variant &filename, const Variant &mode, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2745]);
    }
    return call(fn, {filename, mode, use_include_path});
}
Variant readgzfile(const Variant &filename, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2746]);
    }
    return call(fn, {filename, use_include_path});
}
Variant zlib_encode(const Variant &data, const Variant &encoding, const Variant &level) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2747]);
    }
    return call(fn, {data, encoding, level});
}
Variant zlib_decode(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2748]);
    }
    return call(fn, {data, max_length});
}
Variant gzdeflate(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2749]);
    }
    return call(fn, {data, level, encoding});
}
Variant gzencode(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2750]);
    }
    return call(fn, {data, level, encoding});
}
Variant gzcompress(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2751]);
    }
    return call(fn, {data, level, encoding});
}
Variant gzinflate(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2752]);
    }
    return call(fn, {data, max_length});
}
Variant gzdecode(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2753]);
    }
    return call(fn, {data, max_length});
}
Variant gzuncompress(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2754]);
    }
    return call(fn, {data, max_length});
}
Variant gzwrite(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2755]);
    }
    return call(fn, {stream, data, length});
}
Variant gzputs(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2756]);
    }
    return call(fn, {stream, data, length});
}
Variant gzrewind(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2757]);
    }
    return call(fn, {stream});
}
Variant gzclose(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2758]);
    }
    return call(fn, {stream});
}
Variant gzeof(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2759]);
    }
    return call(fn, {stream});
}
Variant gzgetc(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2760]);
    }
    return call(fn, {stream});
}
Variant gzpassthru(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2761]);
    }
    return call(fn, {stream});
}
Variant gzseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2762]);
    }
    return call(fn, {stream, offset, whence});
}
Variant gztell(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2763]);
    }
    return call(fn, {stream});
}
Variant gzread(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2764]);
    }
    return call(fn, {stream, length});
}
Variant gzgets(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2765]);
    }
    return call(fn, {stream, length});
}
DeflateContext deflate_init(const Variant &encoding, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2766]);
    }
    auto _rv = call(fn, {encoding, options});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "deflate_init() returned false");
    }
    return DeflateContext(Object(std::move(_rv)));
}
Variant deflate_add(const DeflateContext &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2767]);
    }
    return call(fn, {context.getObject(), data, flush_mode});
}
Variant deflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2767]);
    }
    return call(fn, {context, data, flush_mode});
}
InflateContext inflate_init(const Variant &encoding, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2768]);
    }
    auto _rv = call(fn, {encoding, options});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "inflate_init() returned false");
    }
    return InflateContext(Object(std::move(_rv)));
}
Variant inflate_add(const InflateContext &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2769]);
    }
    return call(fn, {context.getObject(), data, flush_mode});
}
Variant inflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2769]);
    }
    return call(fn, {context, data, flush_mode});
}
Variant inflate_get_status(const InflateContext &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2770]);
    }
    return call(fn, {context.getObject()});
}
Variant inflate_get_status(const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2770]);
    }
    return call(fn, {context});
}
Variant inflate_get_read_len(const InflateContext &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2771]);
    }
    return call(fn, {context.getObject()});
}
Variant inflate_get_read_len(const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2771]);
    }
    return call(fn, {context});
}
}  // namespace php

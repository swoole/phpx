#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant ob_gzhandler(const Variant &data, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2584]);
    }
    return call(fn, {data, flags});
}
Variant zlib_get_coding_type() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2585]);
    }
    return call(fn, {});
}
Variant gzfile(const Variant &filename, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2586]);
    }
    return call(fn, {filename, use_include_path});
}
Variant gzopen(const Variant &filename, const Variant &mode, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2587]);
    }
    return call(fn, {filename, mode, use_include_path});
}
Variant readgzfile(const Variant &filename, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2588]);
    }
    return call(fn, {filename, use_include_path});
}
Variant zlib_encode(const Variant &data, const Variant &encoding, const Variant &level) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2589]);
    }
    return call(fn, {data, encoding, level});
}
Variant zlib_decode(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2590]);
    }
    return call(fn, {data, max_length});
}
Variant gzdeflate(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2591]);
    }
    return call(fn, {data, level, encoding});
}
Variant gzencode(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2592]);
    }
    return call(fn, {data, level, encoding});
}
Variant gzcompress(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2593]);
    }
    return call(fn, {data, level, encoding});
}
Variant gzinflate(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2594]);
    }
    return call(fn, {data, max_length});
}
Variant gzdecode(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2595]);
    }
    return call(fn, {data, max_length});
}
Variant gzuncompress(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2596]);
    }
    return call(fn, {data, max_length});
}
Variant gzwrite(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2597]);
    }
    return call(fn, {stream, data, length});
}
Variant gzputs(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2598]);
    }
    return call(fn, {stream, data, length});
}
Variant gzrewind(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2599]);
    }
    return call(fn, {stream});
}
Variant gzclose(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2600]);
    }
    return call(fn, {stream});
}
Variant gzeof(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2601]);
    }
    return call(fn, {stream});
}
Variant gzgetc(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2602]);
    }
    return call(fn, {stream});
}
Variant gzpassthru(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2603]);
    }
    return call(fn, {stream});
}
Variant gzseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2604]);
    }
    return call(fn, {stream, offset, whence});
}
Variant gztell(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2605]);
    }
    return call(fn, {stream});
}
Variant gzread(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2606]);
    }
    return call(fn, {stream, length});
}
Variant gzgets(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2607]);
    }
    return call(fn, {stream, length});
}
Variant deflate_init(const Variant &encoding, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2608]);
    }
    return call(fn, {encoding, options});
}
Variant deflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2609]);
    }
    return call(fn, {context, data, flush_mode});
}
Variant inflate_init(const Variant &encoding, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2610]);
    }
    return call(fn, {encoding, options});
}
Variant inflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2611]);
    }
    return call(fn, {context, data, flush_mode});
}
Variant inflate_get_status(const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2612]);
    }
    return call(fn, {context});
}
Variant inflate_get_read_len(const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2613]);
    }
    return call(fn, {context});
}
}  // namespace php

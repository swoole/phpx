#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant ob_gzhandler(const Variant &data, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3520]);
    }
    return call(_fn, {data, flags});
}
Variant zlib_get_coding_type() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3521]);
    }
    return call(_fn, {});
}
Variant gzfile(const Variant &filename, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3522]);
    }
    return call(_fn, {filename, use_include_path});
}
Variant gzopen(const Variant &filename, const Variant &mode, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3523]);
    }
    return call(_fn, {filename, mode, use_include_path});
}
Variant readgzfile(const Variant &filename, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3524]);
    }
    return call(_fn, {filename, use_include_path});
}
Variant zlib_encode(const Variant &data, const Variant &encoding, const Variant &level) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3525]);
    }
    return call(_fn, {data, encoding, level});
}
Variant zlib_decode(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3526]);
    }
    return call(_fn, {data, max_length});
}
Variant gzdeflate(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3527]);
    }
    return call(_fn, {data, level, encoding});
}
Variant gzencode(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3528]);
    }
    return call(_fn, {data, level, encoding});
}
Variant gzcompress(const Variant &data, const Variant &level, const Variant &encoding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3529]);
    }
    return call(_fn, {data, level, encoding});
}
Variant gzinflate(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3530]);
    }
    return call(_fn, {data, max_length});
}
Variant gzdecode(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3531]);
    }
    return call(_fn, {data, max_length});
}
Variant gzuncompress(const Variant &data, const Variant &max_length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3532]);
    }
    return call(_fn, {data, max_length});
}
Variant gzwrite(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3533]);
    }
    return call(_fn, {stream, data, length});
}
Variant gzputs(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3534]);
    }
    return call(_fn, {stream, data, length});
}
Variant gzrewind(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3535]);
    }
    return call(_fn, {stream});
}
Variant gzclose(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3536]);
    }
    return call(_fn, {stream});
}
Variant gzeof(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3537]);
    }
    return call(_fn, {stream});
}
Variant gzgetc(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3538]);
    }
    return call(_fn, {stream});
}
Variant gzpassthru(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3539]);
    }
    return call(_fn, {stream});
}
Variant gzseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3540]);
    }
    return call(_fn, {stream, offset, whence});
}
Variant gztell(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3541]);
    }
    return call(_fn, {stream});
}
Variant gzread(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3542]);
    }
    return call(_fn, {stream, length});
}
Variant gzgets(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3543]);
    }
    return call(_fn, {stream, length});
}
DeflateContext deflate_init(const Variant &encoding, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3544]);
    }
    auto _rv = call(_fn, {encoding, options});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "deflate_init() returned false");
    }
    return DeflateContext(Object(std::move(_rv)));
}
Variant deflate_add(const DeflateContext &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3545]);
    }
    return call(_fn, {context.getObject(), data, flush_mode});
}
Variant deflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3545]);
    }
    return call(_fn, {context, data, flush_mode});
}
InflateContext inflate_init(const Variant &encoding, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3546]);
    }
    auto _rv = call(_fn, {encoding, options});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "inflate_init() returned false");
    }
    return InflateContext(Object(std::move(_rv)));
}
Variant inflate_add(const InflateContext &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3547]);
    }
    return call(_fn, {context.getObject(), data, flush_mode});
}
Variant inflate_add(const Variant &context, const Variant &data, const Variant &flush_mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3547]);
    }
    return call(_fn, {context, data, flush_mode});
}
Variant inflate_get_status(const InflateContext &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3548]);
    }
    return call(_fn, {context.getObject()});
}
Variant inflate_get_status(const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3548]);
    }
    return call(_fn, {context});
}
Variant inflate_get_read_len(const InflateContext &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3549]);
    }
    return call(_fn, {context.getObject()});
}
Variant inflate_get_read_len(const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[3549]);
    }
    return call(_fn, {context});
}
}  // namespace php

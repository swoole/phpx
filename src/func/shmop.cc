#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Shmop shmop_open(const Variant &key, const Variant &mode, const Variant &permissions, const Variant &size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1847]);
    }
    auto _rv = call(_fn, {key, mode, permissions, size});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "shmop_open() returned false");
    }
    return Shmop(Object(std::move(_rv)));
}
Variant shmop_read(const Shmop &shmop, const Variant &offset, const Variant &size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1848]);
    }
    return call(_fn, {shmop.getObject(), offset, size});
}
Variant shmop_read(const Variant &shmop, const Variant &offset, const Variant &size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1848]);
    }
    return call(_fn, {shmop, offset, size});
}
Variant shmop_close(const Shmop &shmop) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1849]);
    }
    return call(_fn, {shmop.getObject()});
}
Variant shmop_close(const Variant &shmop) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1849]);
    }
    return call(_fn, {shmop});
}
Variant shmop_size(const Shmop &shmop) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1850]);
    }
    return call(_fn, {shmop.getObject()});
}
Variant shmop_size(const Variant &shmop) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1850]);
    }
    return call(_fn, {shmop});
}
Variant shmop_write(const Shmop &shmop, const Variant &data, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1851]);
    }
    return call(_fn, {shmop.getObject(), data, offset});
}
Variant shmop_write(const Variant &shmop, const Variant &data, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1851]);
    }
    return call(_fn, {shmop, data, offset});
}
Variant shmop_delete(const Shmop &shmop) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1852]);
    }
    return call(_fn, {shmop.getObject()});
}
Variant shmop_delete(const Variant &shmop) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1852]);
    }
    return call(_fn, {shmop});
}
}  // namespace php

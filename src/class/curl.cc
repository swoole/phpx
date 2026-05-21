#include "phpx.h"
#include "phpx_class.h"
#include "class/curl.h"

namespace php {
CurlHandle::CurlHandle() {
    this_ = newObject(LITERAL_STRING[207]);
}
CurlMultiHandle::CurlMultiHandle() {
    this_ = newObject(LITERAL_STRING[208]);
}
CurlShareHandle::CurlShareHandle() {
    this_ = newObject(LITERAL_STRING[209]);
}
CURLFile::CURLFile(const Variant &filename, const Variant &mime_type, const Variant &posted_filename) {
    this_ = newObject(LITERAL_STRING[210], {filename, mime_type, posted_filename});
}
Variant CURLFile::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant CURLFile::getMimeType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[212]);
    }
    return this_.call(_method_fn, {});
}
Variant CURLFile::getPostFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[213]);
    }
    return this_.call(_method_fn, {});
}
Variant CURLFile::setMimeType(const Variant &mime_type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[214]);
    }
    return this_.call(_method_fn, {mime_type});
}
Variant CURLFile::setPostFilename(const Variant &posted_filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[215]);
    }
    return this_.call(_method_fn, {posted_filename});
}
CURLStringFile::CURLStringFile(const Variant &data, const Variant &postname, const Variant &mime) {
    this_ = newObject(LITERAL_STRING[216], {data, postname, mime});
}
}  // namespace php

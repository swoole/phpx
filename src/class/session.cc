#include "phpx.h"
#include "phpx_class.h"
#include "class/session.h"

namespace php {
SessionHandler::SessionHandler() {
    this_ = newObject(LITERAL_STRING[1809]);
}
Variant SessionHandler::open(const Variant &path, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1364]);
    }
    return this_.call(_method_fn, {path, name});
}
Variant SessionHandler::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[861]);
    }
    return this_.call(_method_fn, {});
}
Variant SessionHandler::read(const Variant &id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1810]);
    }
    return this_.call(_method_fn, {id});
}
Variant SessionHandler::write(const Variant &id, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {id, data});
}
Variant SessionHandler::destroy(const Variant &id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {id});
}
Variant SessionHandler::gc(const Variant &max_lifetime) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1813]);
    }
    return this_.call(_method_fn, {max_lifetime});
}
Variant SessionHandler::create_sid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1814]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

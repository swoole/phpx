#include "phpx.h"
#include "class/xmlreader.h"

namespace php {
XMLReader::XMLReader() {
    this_ = newObject(LITERAL_STRING[2451]);
}
Variant XMLReader::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1126]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::getAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::getAttributeNo(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2452]);
    }
    return this_.call(_method_fn, {index});
}
Variant XMLReader::getAttributeNs(const Variant &name, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2453]);
    }
    return this_.call(_method_fn, {name, _namespace});
}
Variant XMLReader::getParserProperty(const Variant &property) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2454]);
    }
    return this_.call(_method_fn, {property});
}
Variant XMLReader::isValid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2455]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::lookupNamespace(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2456]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant XMLReader::moveToAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2457]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::moveToAttributeNo(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2458]);
    }
    return this_.call(_method_fn, {index});
}
Variant XMLReader::moveToAttributeNs(const Variant &name, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2459]);
    }
    return this_.call(_method_fn, {name, _namespace});
}
Variant XMLReader::moveToElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2460]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::moveToFirstAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2461]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::moveToNextAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2462]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::read() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1676]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::next(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::open(const Variant &uri, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2451], LITERAL_STRING[1230]);
    }
    return php::call(_method_fn, {uri, encoding, flags});
}
Variant XMLReader::fromUri(const Variant &uri, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2451], LITERAL_STRING[2465]);
    }
    return php::call(_method_fn, {uri, encoding, flags});
}
Variant XMLReader::fromStream(const Variant &stream,
                              const Variant &encoding,
                              const Variant &flags,
                              const Variant &document_uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2451], LITERAL_STRING[2467]);
    }
    return php::call(_method_fn, {stream, encoding, flags, document_uri});
}
Variant XMLReader::readInnerXml() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2468]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::readOuterXml() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2469]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::readString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2470]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::setSchema(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2471]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLReader::setParserProperty(const Variant &property, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2472]);
    }
    return this_.call(_method_fn, {property, value});
}
Variant XMLReader::setRelaxNGSchema(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2473]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLReader::setRelaxNGSchemaSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2474]);
    }
    return this_.call(_method_fn, {source});
}
Variant XMLReader::XML(const Variant &source, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2451], LITERAL_STRING[2476]);
    }
    return php::call(_method_fn, {source, encoding, flags});
}
Variant XMLReader::fromString(const Variant &source, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2451], LITERAL_STRING[2478]);
    }
    return php::call(_method_fn, {source, encoding, flags});
}
Variant XMLReader::expand(const Variant &base_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2479]);
    }
    return this_.call(_method_fn, {base_node});
}
}  // namespace php

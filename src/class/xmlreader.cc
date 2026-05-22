#include "phpx.h"
#include "phpx_class.h"
#include "class/xmlreader.h"

namespace php {
XMLReader::XMLReader() {
    this_ = newObject(LITERAL_STRING[3329]);
}
Variant XMLReader::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::getAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[484]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::getAttributeNo(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3330]);
    }
    return this_.call(_method_fn, {index});
}
Variant XMLReader::getAttributeNs(const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3331]);
    }
    return this_.call(_method_fn, {name, namespace_});
}
Variant XMLReader::getParserProperty(const Variant &property) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3332]);
    }
    return this_.call(_method_fn, {property});
}
Variant XMLReader::isValid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3333]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::lookupNamespace(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3334]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant XMLReader::moveToAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3335]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::moveToAttributeNo(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3336]);
    }
    return this_.call(_method_fn, {index});
}
Variant XMLReader::moveToAttributeNs(const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3337]);
    }
    return this_.call(_method_fn, {name, namespace_});
}
Variant XMLReader::moveToElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3338]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::moveToFirstAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3339]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::moveToNextAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3340]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::read() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1842]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::next(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::open(const Variant &uri, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3329], LITERAL_STRING[1396]);
    }
    return php::call(_method_fn, {uri, encoding, flags});
}
Variant XMLReader::fromUri(const Variant &uri, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3329], LITERAL_STRING[3343]);
    }
    return php::call(_method_fn, {uri, encoding, flags});
}
Variant XMLReader::fromStream(const Variant &stream,
                              const Variant &encoding,
                              const Variant &flags,
                              const Variant &document_uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3329], LITERAL_STRING[3345]);
    }
    return php::call(_method_fn, {stream, encoding, flags, document_uri});
}
Variant XMLReader::readInnerXml() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3346]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::readOuterXml() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3347]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::readString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3348]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::setSchema(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3349]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLReader::setParserProperty(const Variant &property, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3350]);
    }
    return this_.call(_method_fn, {property, value});
}
Variant XMLReader::setRelaxNGSchema(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3351]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLReader::setRelaxNGSchemaSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3352]);
    }
    return this_.call(_method_fn, {source});
}
Variant XMLReader::XML(const Variant &source, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3329], LITERAL_STRING[3354]);
    }
    return php::call(_method_fn, {source, encoding, flags});
}
Variant XMLReader::fromString(const Variant &source, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3329], LITERAL_STRING[3356]);
    }
    return php::call(_method_fn, {source, encoding, flags});
}
DOMNode XMLReader::expand(const Variant &base_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3357]);
    }
    auto _rv = this_.call(_method_fn, {base_node});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "XMLReader::expand() returned false");
    }
    return DOMNode(Object(std::move(_rv)));
}
}  // namespace php

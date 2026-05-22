#include "phpx.h"
#include "phpx_class.h"
#include "class/xmlreader.h"

namespace php {
XMLReader::XMLReader() {
    this_ = newObject(LITERAL_STRING[2609]);
}
Variant XMLReader::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[857]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::getAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[456]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::getAttributeNo(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2610]);
    }
    return this_.call(_method_fn, {index});
}
Variant XMLReader::getAttributeNs(const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2611]);
    }
    return this_.call(_method_fn, {name, namespace_});
}
Variant XMLReader::getParserProperty(const Variant &property) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2612]);
    }
    return this_.call(_method_fn, {property});
}
Variant XMLReader::isValid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2613]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::lookupNamespace(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2614]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant XMLReader::moveToAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2615]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::moveToAttributeNo(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2616]);
    }
    return this_.call(_method_fn, {index});
}
Variant XMLReader::moveToAttributeNs(const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2617]);
    }
    return this_.call(_method_fn, {name, namespace_});
}
Variant XMLReader::moveToElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2618]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::moveToFirstAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2619]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::moveToNextAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2620]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::read() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1804]);
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
        _method_fn = php::getMethod(LITERAL_STRING[2609], LITERAL_STRING[1358]);
    }
    return php::call(_method_fn, {uri, encoding, flags});
}
Variant XMLReader::fromUri(const Variant &uri, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2609], LITERAL_STRING[2623]);
    }
    return php::call(_method_fn, {uri, encoding, flags});
}
Variant XMLReader::fromStream(const Variant &stream,
                              const Variant &encoding,
                              const Variant &flags,
                              const Variant &document_uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2609], LITERAL_STRING[2625]);
    }
    return php::call(_method_fn, {stream, encoding, flags, document_uri});
}
Variant XMLReader::readInnerXml() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2626]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::readOuterXml() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2627]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::readString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2628]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::setSchema(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2629]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLReader::setParserProperty(const Variant &property, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2630]);
    }
    return this_.call(_method_fn, {property, value});
}
Variant XMLReader::setRelaxNGSchema(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2631]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLReader::setRelaxNGSchemaSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2632]);
    }
    return this_.call(_method_fn, {source});
}
Variant XMLReader::XML(const Variant &source, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2609], LITERAL_STRING[2634]);
    }
    return php::call(_method_fn, {source, encoding, flags});
}
Variant XMLReader::fromString(const Variant &source, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2609], LITERAL_STRING[2636]);
    }
    return php::call(_method_fn, {source, encoding, flags});
}
DOMNode XMLReader::expand(const Variant &base_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2637]);
    }
    auto _rv = this_.call(_method_fn, {base_node});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "XMLReader::expand() returned false");
    }
    return DOMNode(Object(std::move(_rv)));
}
}  // namespace php

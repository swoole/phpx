#include "phpx.h"
#include "phpx_class.h"
#include "class/xmlreader.h"

namespace php {
XMLReader::XMLReader() {
    this_ = newObject(LITERAL_STRING[2759]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2760]);
    }
    return this_.call(_method_fn, {index});
}
Variant XMLReader::getAttributeNs(const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2761]);
    }
    return this_.call(_method_fn, {name, namespace_});
}
Variant XMLReader::getParserProperty(const Variant &property) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2762]);
    }
    return this_.call(_method_fn, {property});
}
Variant XMLReader::isValid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2763]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::lookupNamespace(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2764]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant XMLReader::moveToAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2765]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLReader::moveToAttributeNo(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2766]);
    }
    return this_.call(_method_fn, {index});
}
Variant XMLReader::moveToAttributeNs(const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2767]);
    }
    return this_.call(_method_fn, {name, namespace_});
}
Variant XMLReader::moveToElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2768]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::moveToFirstAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2769]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::moveToNextAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2770]);
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
        _method_fn = php::getMethod(LITERAL_STRING[2759], LITERAL_STRING[1396]);
    }
    return php::call(_method_fn, {uri, encoding, flags});
}
Variant XMLReader::fromUri(const Variant &uri, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2759], LITERAL_STRING[2773]);
    }
    return php::call(_method_fn, {uri, encoding, flags});
}
Variant XMLReader::fromStream(const Variant &stream,
                              const Variant &encoding,
                              const Variant &flags,
                              const Variant &document_uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2759], LITERAL_STRING[2775]);
    }
    return php::call(_method_fn, {stream, encoding, flags, document_uri});
}
Variant XMLReader::readInnerXml() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2776]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::readOuterXml() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2777]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::readString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2778]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLReader::setSchema(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2779]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLReader::setParserProperty(const Variant &property, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2780]);
    }
    return this_.call(_method_fn, {property, value});
}
Variant XMLReader::setRelaxNGSchema(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2781]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLReader::setRelaxNGSchemaSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2782]);
    }
    return this_.call(_method_fn, {source});
}
Variant XMLReader::XML(const Variant &source, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2759], LITERAL_STRING[2784]);
    }
    return php::call(_method_fn, {source, encoding, flags});
}
Variant XMLReader::fromString(const Variant &source, const Variant &encoding, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2759], LITERAL_STRING[2786]);
    }
    return php::call(_method_fn, {source, encoding, flags});
}
DOMNode XMLReader::expand(const Variant &base_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2787]);
    }
    auto _rv = this_.call(_method_fn, {base_node});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "XMLReader::expand() returned false");
    }
    return DOMNode(Object(std::move(_rv)));
}
}  // namespace php

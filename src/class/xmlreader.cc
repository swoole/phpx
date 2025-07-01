#include "phpx.h"
#include "class/xmlreader.h"

namespace php {
Variant XMLReader::close() {
    return std::move(_this.exec("close"));
}

Variant XMLReader::getAttribute(const Variant &name) {
    return std::move(_this.exec("getAttribute", name));
}

Variant XMLReader::getAttributeNo(const Variant &index) {
    return std::move(_this.exec("getAttributeNo", index));
}

Variant XMLReader::getAttributeNs(const Variant &name, const Variant &_namespace) {
    return std::move(_this.exec("getAttributeNs", name, _namespace));
}

Variant XMLReader::getParserProperty(const Variant &property) {
    return std::move(_this.exec("getParserProperty", property));
}

Variant XMLReader::isValid() {
    return std::move(_this.exec("isValid"));
}

Variant XMLReader::lookupNamespace(const Variant &prefix) {
    return std::move(_this.exec("lookupNamespace", prefix));
}

Variant XMLReader::moveToAttribute(const Variant &name) {
    return std::move(_this.exec("moveToAttribute", name));
}

Variant XMLReader::moveToAttributeNo(const Variant &index) {
    return std::move(_this.exec("moveToAttributeNo", index));
}

Variant XMLReader::moveToAttributeNs(const Variant &name, const Variant &_namespace) {
    return std::move(_this.exec("moveToAttributeNs", name, _namespace));
}

Variant XMLReader::moveToElement() {
    return std::move(_this.exec("moveToElement"));
}

Variant XMLReader::moveToFirstAttribute() {
    return std::move(_this.exec("moveToFirstAttribute"));
}

Variant XMLReader::moveToNextAttribute() {
    return std::move(_this.exec("moveToNextAttribute"));
}

Variant XMLReader::read() {
    return std::move(_this.exec("read"));
}

Variant XMLReader::next(const Variant &name) {
    return std::move(_this.exec("next", name));
}

Variant XMLReader::open(const Variant &uri, const Variant &encoding, const Variant &flags) {
    static Variant fn { ZEND_STRL("XMLReader::open"), true };
    return fn(uri, encoding, flags);
}

Variant XMLReader::readInnerXml() {
    return std::move(_this.exec("readInnerXml"));
}

Variant XMLReader::readOuterXml() {
    return std::move(_this.exec("readOuterXml"));
}

Variant XMLReader::readString() {
    return std::move(_this.exec("readString"));
}

Variant XMLReader::setSchema(const Variant &filename) {
    return std::move(_this.exec("setSchema", filename));
}

Variant XMLReader::setParserProperty(const Variant &property, const Variant &value) {
    return std::move(_this.exec("setParserProperty", property, value));
}

Variant XMLReader::setRelaxNGSchema(const Variant &filename) {
    return std::move(_this.exec("setRelaxNGSchema", filename));
}

Variant XMLReader::setRelaxNGSchemaSource(const Variant &source) {
    return std::move(_this.exec("setRelaxNGSchemaSource", source));
}

Variant XMLReader::XML(const Variant &source, const Variant &encoding, const Variant &flags) {
    static Variant fn { ZEND_STRL("XMLReader::XML"), true };
    return fn(source, encoding, flags);
}

Variant XMLReader::expand(const Variant &base_node) {
    return std::move(_this.exec("expand", base_node));
}


}

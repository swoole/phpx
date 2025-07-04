#include "phpx.h"
#include "class/xmlreader.h"

namespace php {
Variant XMLReader::close() {
    return this_.exec("close");
}

Variant XMLReader::getAttribute(const Variant &name) {
    return this_.exec("getAttribute", name);
}

Variant XMLReader::getAttributeNo(const Variant &index) {
    return this_.exec("getAttributeNo", index);
}

Variant XMLReader::getAttributeNs(const Variant &name, const Variant &_namespace) {
    return this_.exec("getAttributeNs", name, _namespace);
}

Variant XMLReader::getParserProperty(const Variant &property) {
    return this_.exec("getParserProperty", property);
}

Variant XMLReader::isValid() {
    return this_.exec("isValid");
}

Variant XMLReader::lookupNamespace(const Variant &prefix) {
    return this_.exec("lookupNamespace", prefix);
}

Variant XMLReader::moveToAttribute(const Variant &name) {
    return this_.exec("moveToAttribute", name);
}

Variant XMLReader::moveToAttributeNo(const Variant &index) {
    return this_.exec("moveToAttributeNo", index);
}

Variant XMLReader::moveToAttributeNs(const Variant &name, const Variant &_namespace) {
    return this_.exec("moveToAttributeNs", name, _namespace);
}

Variant XMLReader::moveToElement() {
    return this_.exec("moveToElement");
}

Variant XMLReader::moveToFirstAttribute() {
    return this_.exec("moveToFirstAttribute");
}

Variant XMLReader::moveToNextAttribute() {
    return this_.exec("moveToNextAttribute");
}

Variant XMLReader::read() {
    return this_.exec("read");
}

Variant XMLReader::next(const Variant &name) {
    return this_.exec("next", name);
}

Variant XMLReader::open(const Variant &uri, const Variant &encoding, const Variant &flags) {
    static Variant fn { ZEND_STRL("XMLReader::open"), true };
    return fn(uri, encoding, flags);
}

Variant XMLReader::readInnerXml() {
    return this_.exec("readInnerXml");
}

Variant XMLReader::readOuterXml() {
    return this_.exec("readOuterXml");
}

Variant XMLReader::readString() {
    return this_.exec("readString");
}

Variant XMLReader::setSchema(const Variant &filename) {
    return this_.exec("setSchema", filename);
}

Variant XMLReader::setParserProperty(const Variant &property, const Variant &value) {
    return this_.exec("setParserProperty", property, value);
}

Variant XMLReader::setRelaxNGSchema(const Variant &filename) {
    return this_.exec("setRelaxNGSchema", filename);
}

Variant XMLReader::setRelaxNGSchemaSource(const Variant &source) {
    return this_.exec("setRelaxNGSchemaSource", source);
}

Variant XMLReader::XML(const Variant &source, const Variant &encoding, const Variant &flags) {
    static Variant fn { ZEND_STRL("XMLReader::XML"), true };
    return fn(source, encoding, flags);
}

Variant XMLReader::expand(const Variant &base_node) {
    return this_.exec("expand", base_node);
}


}

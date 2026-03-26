#include "phpx.h"
#include "class/xmlreader.h"

namespace php {
Variant XMLReader::close() {
    return this_.exec(LITERAL_STRING[1068], {});
}
Variant XMLReader::getAttribute(const Variant &name) {
    return this_.exec(LITERAL_STRING[430], {name});
}
Variant XMLReader::getAttributeNo(const Variant &index) {
    return this_.exec(LITERAL_STRING[2382], {index});
}
Variant XMLReader::getAttributeNs(const Variant &name, const Variant &_namespace) {
    return this_.exec(LITERAL_STRING[2383], {name, _namespace});
}
Variant XMLReader::getParserProperty(const Variant &property) {
    return this_.exec(LITERAL_STRING[2384], {property});
}
Variant XMLReader::isValid() {
    return this_.exec(LITERAL_STRING[2385], {});
}
Variant XMLReader::lookupNamespace(const Variant &prefix) {
    return this_.exec(LITERAL_STRING[2386], {prefix});
}
Variant XMLReader::moveToAttribute(const Variant &name) {
    return this_.exec(LITERAL_STRING[2387], {name});
}
Variant XMLReader::moveToAttributeNo(const Variant &index) {
    return this_.exec(LITERAL_STRING[2388], {index});
}
Variant XMLReader::moveToAttributeNs(const Variant &name, const Variant &_namespace) {
    return this_.exec(LITERAL_STRING[2389], {name, _namespace});
}
Variant XMLReader::moveToElement() {
    return this_.exec(LITERAL_STRING[2390], {});
}
Variant XMLReader::moveToFirstAttribute() {
    return this_.exec(LITERAL_STRING[2391], {});
}
Variant XMLReader::moveToNextAttribute() {
    return this_.exec(LITERAL_STRING[2392], {});
}
Variant XMLReader::read() {
    return this_.exec(LITERAL_STRING[1615], {});
}
Variant XMLReader::next(const Variant &name) {
    return this_.exec(LITERAL_STRING[92], {name});
}
Variant XMLReader::open(const Variant &uri, const Variant &encoding, const Variant &flags) {
    return php::call(LITERAL_STRING[2393], {uri, encoding, flags});
}
Variant XMLReader::fromUri(const Variant &uri, const Variant &encoding, const Variant &flags) {
    return php::call(LITERAL_STRING[2394], {uri, encoding, flags});
}
Variant XMLReader::fromStream(const Variant &stream,
                              const Variant &encoding,
                              const Variant &flags,
                              const Variant &document_uri) {
    return php::call(LITERAL_STRING[2395], {stream, encoding, flags, document_uri});
}
Variant XMLReader::readInnerXml() {
    return this_.exec(LITERAL_STRING[2396], {});
}
Variant XMLReader::readOuterXml() {
    return this_.exec(LITERAL_STRING[2397], {});
}
Variant XMLReader::readString() {
    return this_.exec(LITERAL_STRING[2398], {});
}
Variant XMLReader::setSchema(const Variant &filename) {
    return this_.exec(LITERAL_STRING[2399], {filename});
}
Variant XMLReader::setParserProperty(const Variant &property, const Variant &value) {
    return this_.exec(LITERAL_STRING[2400], {property, value});
}
Variant XMLReader::setRelaxNGSchema(const Variant &filename) {
    return this_.exec(LITERAL_STRING[2401], {filename});
}
Variant XMLReader::setRelaxNGSchemaSource(const Variant &source) {
    return this_.exec(LITERAL_STRING[2402], {source});
}
Variant XMLReader::XML(const Variant &source, const Variant &encoding, const Variant &flags) {
    return php::call(LITERAL_STRING[2403], {source, encoding, flags});
}
Variant XMLReader::fromString(const Variant &source, const Variant &encoding, const Variant &flags) {
    return php::call(LITERAL_STRING[2404], {source, encoding, flags});
}
Variant XMLReader::expand(const Variant &base_node) {
    return this_.exec(LITERAL_STRING[2405], {base_node});
}
}  // namespace php

#include "phpx.h"
#include "class/simplexml.h"

namespace php {
Variant SimpleXMLElement::xpath(const Variant &expression) {
    return this_.call(LITERAL_STRING[1624], {expression});
}
Variant SimpleXMLElement::registerXPathNamespace(const Variant &prefix, const Variant &_namespace) {
    return this_.call(LITERAL_STRING[1625], {prefix, _namespace});
}
Variant SimpleXMLElement::asXML(const Variant &filename) {
    return this_.call(LITERAL_STRING[1626], {filename});
}
Variant SimpleXMLElement::saveXML(const Variant &filename) {
    return this_.call(LITERAL_STRING[380], {filename});
}
Variant SimpleXMLElement::getNamespaces(const Variant &recursive) {
    return this_.call(LITERAL_STRING[1627], {recursive});
}
Variant SimpleXMLElement::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    return this_.call(LITERAL_STRING[1628], {recursive, from_root});
}
Variant SimpleXMLElement::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return this_.call(LITERAL_STRING[1629], {namespace_or_prefix, is_prefix});
}
Variant SimpleXMLElement::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return this_.call(LITERAL_STRING[1630], {namespace_or_prefix, is_prefix});
}
SimpleXMLElement::SimpleXMLElement(const Variant &data,
                                   const Variant &options,
                                   const Variant &data_is_u_r_l,
                                   const Variant &namespace_or_prefix,
                                   const Variant &is_prefix) {
    this_ = newObject(LITERAL_STRING[1631], {data, options, data_is_u_r_l, namespace_or_prefix, is_prefix});
}
Variant SimpleXMLElement::addChild(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return this_.call(LITERAL_STRING[1632], {qualified_name, value, _namespace});
}
Variant SimpleXMLElement::addAttribute(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return this_.call(LITERAL_STRING[1633], {qualified_name, value, _namespace});
}
Variant SimpleXMLElement::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant SimpleXMLElement::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant SimpleXMLElement::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SimpleXMLElement::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SimpleXMLElement::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SimpleXMLElement::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SimpleXMLElement::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SimpleXMLElement::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SimpleXMLElement::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant SimpleXMLElement::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
Variant SimpleXMLIterator::xpath(const Variant &expression) {
    return this_.call(LITERAL_STRING[1624], {expression});
}
Variant SimpleXMLIterator::registerXPathNamespace(const Variant &prefix, const Variant &_namespace) {
    return this_.call(LITERAL_STRING[1625], {prefix, _namespace});
}
Variant SimpleXMLIterator::asXML(const Variant &filename) {
    return this_.call(LITERAL_STRING[1626], {filename});
}
Variant SimpleXMLIterator::saveXML(const Variant &filename) {
    return this_.call(LITERAL_STRING[380], {filename});
}
Variant SimpleXMLIterator::getNamespaces(const Variant &recursive) {
    return this_.call(LITERAL_STRING[1627], {recursive});
}
Variant SimpleXMLIterator::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    return this_.call(LITERAL_STRING[1628], {recursive, from_root});
}
Variant SimpleXMLIterator::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return this_.call(LITERAL_STRING[1629], {namespace_or_prefix, is_prefix});
}
Variant SimpleXMLIterator::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return this_.call(LITERAL_STRING[1630], {namespace_or_prefix, is_prefix});
}
SimpleXMLIterator::SimpleXMLIterator(const Variant &data,
                                     const Variant &options,
                                     const Variant &data_is_u_r_l,
                                     const Variant &namespace_or_prefix,
                                     const Variant &is_prefix) {
    this_ = newObject(LITERAL_STRING[1634], {data, options, data_is_u_r_l, namespace_or_prefix, is_prefix});
}
Variant SimpleXMLIterator::addChild(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return this_.call(LITERAL_STRING[1632], {qualified_name, value, _namespace});
}
Variant SimpleXMLIterator::addAttribute(const Variant &qualified_name,
                                        const Variant &value,
                                        const Variant &_namespace) {
    return this_.call(LITERAL_STRING[1633], {qualified_name, value, _namespace});
}
Variant SimpleXMLIterator::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant SimpleXMLIterator::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant SimpleXMLIterator::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SimpleXMLIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SimpleXMLIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SimpleXMLIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SimpleXMLIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SimpleXMLIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SimpleXMLIterator::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant SimpleXMLIterator::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
}  // namespace php

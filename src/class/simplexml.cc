#include "phpx.h"
#include "class/simplexml.h"

namespace php {
Variant SimpleXMLElement::xpath(const Variant &expression) {
    return _this.exec("xpath", expression);
}

Variant SimpleXMLElement::registerXPathNamespace(const Variant &prefix, const Variant &_namespace) {
    return _this.exec("registerXPathNamespace", prefix, _namespace);
}

Variant SimpleXMLElement::asXML(const Variant &filename) {
    return _this.exec("asXML", filename);
}

Variant SimpleXMLElement::saveXML(const Variant &filename) {
    return _this.exec("saveXML", filename);
}

Variant SimpleXMLElement::getNamespaces(const Variant &recursive) {
    return _this.exec("getNamespaces", recursive);
}

Variant SimpleXMLElement::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    return _this.exec("getDocNamespaces", recursive, from_root);
}

Variant SimpleXMLElement::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return _this.exec("children", namespace_or_prefix, is_prefix);
}

Variant SimpleXMLElement::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return _this.exec("attributes", namespace_or_prefix, is_prefix);
}

SimpleXMLElement::SimpleXMLElement(const Variant &data, const Variant &options, const Variant &data_is_u_r_l, const Variant &namespace_or_prefix, const Variant &is_prefix) {
    _this = newObject("SimpleXMLElement", data, options, data_is_u_r_l, namespace_or_prefix, is_prefix);
}

Variant SimpleXMLElement::addChild(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return _this.exec("addChild", qualified_name, value, _namespace);
}

Variant SimpleXMLElement::addAttribute(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return _this.exec("addAttribute", qualified_name, value, _namespace);
}

Variant SimpleXMLElement::getName() {
    return _this.exec("getName");
}

Variant SimpleXMLElement::__toString() {
    return _this.exec("__toString");
}

Variant SimpleXMLElement::count() {
    return _this.exec("count");
}

Variant SimpleXMLElement::rewind() {
    return _this.exec("rewind");
}

Variant SimpleXMLElement::valid() {
    return _this.exec("valid");
}

Variant SimpleXMLElement::current() {
    return _this.exec("current");
}

Variant SimpleXMLElement::key() {
    return _this.exec("key");
}

Variant SimpleXMLElement::next() {
    return _this.exec("next");
}

Variant SimpleXMLElement::hasChildren() {
    return _this.exec("hasChildren");
}

Variant SimpleXMLElement::getChildren() {
    return _this.exec("getChildren");
}


Variant SimpleXMLIterator::xpath(const Variant &expression) {
    return _this.exec("xpath", expression);
}

Variant SimpleXMLIterator::registerXPathNamespace(const Variant &prefix, const Variant &_namespace) {
    return _this.exec("registerXPathNamespace", prefix, _namespace);
}

Variant SimpleXMLIterator::asXML(const Variant &filename) {
    return _this.exec("asXML", filename);
}

Variant SimpleXMLIterator::saveXML(const Variant &filename) {
    return _this.exec("saveXML", filename);
}

Variant SimpleXMLIterator::getNamespaces(const Variant &recursive) {
    return _this.exec("getNamespaces", recursive);
}

Variant SimpleXMLIterator::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    return _this.exec("getDocNamespaces", recursive, from_root);
}

Variant SimpleXMLIterator::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return _this.exec("children", namespace_or_prefix, is_prefix);
}

Variant SimpleXMLIterator::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return _this.exec("attributes", namespace_or_prefix, is_prefix);
}

SimpleXMLIterator::SimpleXMLIterator(const Variant &data, const Variant &options, const Variant &data_is_u_r_l, const Variant &namespace_or_prefix, const Variant &is_prefix) {
    _this = newObject("SimpleXMLIterator", data, options, data_is_u_r_l, namespace_or_prefix, is_prefix);
}

Variant SimpleXMLIterator::addChild(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return _this.exec("addChild", qualified_name, value, _namespace);
}

Variant SimpleXMLIterator::addAttribute(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return _this.exec("addAttribute", qualified_name, value, _namespace);
}

Variant SimpleXMLIterator::getName() {
    return _this.exec("getName");
}

Variant SimpleXMLIterator::__toString() {
    return _this.exec("__toString");
}

Variant SimpleXMLIterator::count() {
    return _this.exec("count");
}

Variant SimpleXMLIterator::rewind() {
    return _this.exec("rewind");
}

Variant SimpleXMLIterator::valid() {
    return _this.exec("valid");
}

Variant SimpleXMLIterator::current() {
    return _this.exec("current");
}

Variant SimpleXMLIterator::key() {
    return _this.exec("key");
}

Variant SimpleXMLIterator::next() {
    return _this.exec("next");
}

Variant SimpleXMLIterator::hasChildren() {
    return _this.exec("hasChildren");
}

Variant SimpleXMLIterator::getChildren() {
    return _this.exec("getChildren");
}


}

#include "phpx.h"
#include "class/simplexml.h"

namespace php {
Variant SimpleXMLElement::xpath(const Variant &expression) {
    return this_.exec("xpath", expression);
}

Variant SimpleXMLElement::registerXPathNamespace(const Variant &prefix, const Variant &_namespace) {
    return this_.exec("registerXPathNamespace", prefix, _namespace);
}

Variant SimpleXMLElement::asXML(const Variant &filename) {
    return this_.exec("asXML", filename);
}

Variant SimpleXMLElement::saveXML(const Variant &filename) {
    return this_.exec("saveXML", filename);
}

Variant SimpleXMLElement::getNamespaces(const Variant &recursive) {
    return this_.exec("getNamespaces", recursive);
}

Variant SimpleXMLElement::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    return this_.exec("getDocNamespaces", recursive, from_root);
}

Variant SimpleXMLElement::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return this_.exec("children", namespace_or_prefix, is_prefix);
}

Variant SimpleXMLElement::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return this_.exec("attributes", namespace_or_prefix, is_prefix);
}

SimpleXMLElement::SimpleXMLElement(const Variant &data, const Variant &options, const Variant &data_is_u_r_l, const Variant &namespace_or_prefix, const Variant &is_prefix) {
    this_ = newObject("SimpleXMLElement", data, options, data_is_u_r_l, namespace_or_prefix, is_prefix);
}

Variant SimpleXMLElement::addChild(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return this_.exec("addChild", qualified_name, value, _namespace);
}

Variant SimpleXMLElement::addAttribute(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return this_.exec("addAttribute", qualified_name, value, _namespace);
}

Variant SimpleXMLElement::getName() {
    return this_.exec("getName");
}

Variant SimpleXMLElement::__toString() {
    return this_.exec("__toString");
}

Variant SimpleXMLElement::count() {
    return this_.exec("count");
}

Variant SimpleXMLElement::rewind() {
    return this_.exec("rewind");
}

Variant SimpleXMLElement::valid() {
    return this_.exec("valid");
}

Variant SimpleXMLElement::current() {
    return this_.exec("current");
}

Variant SimpleXMLElement::key() {
    return this_.exec("key");
}

Variant SimpleXMLElement::next() {
    return this_.exec("next");
}

Variant SimpleXMLElement::hasChildren() {
    return this_.exec("hasChildren");
}

Variant SimpleXMLElement::getChildren() {
    return this_.exec("getChildren");
}


Variant SimpleXMLIterator::xpath(const Variant &expression) {
    return this_.exec("xpath", expression);
}

Variant SimpleXMLIterator::registerXPathNamespace(const Variant &prefix, const Variant &_namespace) {
    return this_.exec("registerXPathNamespace", prefix, _namespace);
}

Variant SimpleXMLIterator::asXML(const Variant &filename) {
    return this_.exec("asXML", filename);
}

Variant SimpleXMLIterator::saveXML(const Variant &filename) {
    return this_.exec("saveXML", filename);
}

Variant SimpleXMLIterator::getNamespaces(const Variant &recursive) {
    return this_.exec("getNamespaces", recursive);
}

Variant SimpleXMLIterator::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    return this_.exec("getDocNamespaces", recursive, from_root);
}

Variant SimpleXMLIterator::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return this_.exec("children", namespace_or_prefix, is_prefix);
}

Variant SimpleXMLIterator::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    return this_.exec("attributes", namespace_or_prefix, is_prefix);
}

SimpleXMLIterator::SimpleXMLIterator(const Variant &data, const Variant &options, const Variant &data_is_u_r_l, const Variant &namespace_or_prefix, const Variant &is_prefix) {
    this_ = newObject("SimpleXMLIterator", data, options, data_is_u_r_l, namespace_or_prefix, is_prefix);
}

Variant SimpleXMLIterator::addChild(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return this_.exec("addChild", qualified_name, value, _namespace);
}

Variant SimpleXMLIterator::addAttribute(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    return this_.exec("addAttribute", qualified_name, value, _namespace);
}

Variant SimpleXMLIterator::getName() {
    return this_.exec("getName");
}

Variant SimpleXMLIterator::__toString() {
    return this_.exec("__toString");
}

Variant SimpleXMLIterator::count() {
    return this_.exec("count");
}

Variant SimpleXMLIterator::rewind() {
    return this_.exec("rewind");
}

Variant SimpleXMLIterator::valid() {
    return this_.exec("valid");
}

Variant SimpleXMLIterator::current() {
    return this_.exec("current");
}

Variant SimpleXMLIterator::key() {
    return this_.exec("key");
}

Variant SimpleXMLIterator::next() {
    return this_.exec("next");
}

Variant SimpleXMLIterator::hasChildren() {
    return this_.exec("hasChildren");
}

Variant SimpleXMLIterator::getChildren() {
    return this_.exec("getChildren");
}


}

#include "phpx.h"
#include "class/dom.h"

namespace php {
DOMException::DOMException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("DOMException", message, code, previous);
}

Variant DOMException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMException::getMessage() {
    return this_.exec("getMessage");
}

Variant DOMException::getCode() {
    return this_.exec("getCode");
}

Variant DOMException::getFile() {
    return this_.exec("getFile");
}

Variant DOMException::getLine() {
    return this_.exec("getLine");
}

Variant DOMException::getTrace() {
    return this_.exec("getTrace");
}

Variant DOMException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant DOMException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant DOMException::__toString() {
    return this_.exec("__toString");
}


Variant DOMImplementation::getFeature(const Variant &feature, const Variant &version) {
    return this_.exec("getFeature", feature, version);
}

Variant DOMImplementation::hasFeature(const Variant &feature, const Variant &version) {
    return this_.exec("hasFeature", feature, version);
}

Variant DOMImplementation::createDocumentType(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    return this_.exec("createDocumentType", qualified_name, public_id, system_id);
}

Variant DOMImplementation::createDocument(const Variant &_namespace, const Variant &qualified_name, const Variant &doctype) {
    return this_.exec("createDocument", _namespace, qualified_name, doctype);
}


Variant DOMNode::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMNode::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMNode::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMNode::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMNode::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMNode::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMNode::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMNode::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMNode::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMNode::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMNode::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMNode::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMNode::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMNode::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMNode::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMNode::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMNode::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMNode::normalize() {
    return this_.exec("normalize");
}

Variant DOMNode::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMNode::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMNode::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMNode::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


Variant DOMNameSpaceNode::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMNameSpaceNode::__wakeup() {
    return this_.exec("__wakeup");
}


DOMDocumentFragment::DOMDocumentFragment() {
    this_ = newObject("DOMDocumentFragment");
}

Variant DOMDocumentFragment::appendXML(const Variant &data) {
    return this_.exec("appendXML", data);
}

Variant DOMDocumentFragment::append(const Variant &nodes) {
    return this_.exec("append", nodes);
}

Variant DOMDocumentFragment::prepend(const Variant &nodes) {
    return this_.exec("prepend", nodes);
}

Variant DOMDocumentFragment::replaceChildren(const Variant &nodes) {
    return this_.exec("replaceChildren", nodes);
}

Variant DOMDocumentFragment::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMDocumentFragment::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMDocumentFragment::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMDocumentFragment::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocumentFragment::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocumentFragment::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMDocumentFragment::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMDocumentFragment::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMDocumentFragment::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMDocumentFragment::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMDocumentFragment::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMDocumentFragment::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMDocumentFragment::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMDocumentFragment::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMDocumentFragment::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMDocumentFragment::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMDocumentFragment::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMDocumentFragment::normalize() {
    return this_.exec("normalize");
}

Variant DOMDocumentFragment::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMDocumentFragment::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMDocumentFragment::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMDocumentFragment::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMDocument::DOMDocument(const Variant &version, const Variant &encoding) {
    this_ = newObject("DOMDocument", version, encoding);
}

Variant DOMDocument::createAttribute(const Variant &local_name) {
    return this_.exec("createAttribute", local_name);
}

Variant DOMDocument::createAttributeNS(const Variant &_namespace, const Variant &qualified_name) {
    return this_.exec("createAttributeNS", _namespace, qualified_name);
}

Variant DOMDocument::createCDATASection(const Variant &data) {
    return this_.exec("createCDATASection", data);
}

Variant DOMDocument::createComment(const Variant &data) {
    return this_.exec("createComment", data);
}

Variant DOMDocument::createDocumentFragment() {
    return this_.exec("createDocumentFragment");
}

Variant DOMDocument::createElement(const Variant &local_name, const Variant &value) {
    return this_.exec("createElement", local_name, value);
}

Variant DOMDocument::createElementNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    return this_.exec("createElementNS", _namespace, qualified_name, value);
}

Variant DOMDocument::createEntityReference(const Variant &name) {
    return this_.exec("createEntityReference", name);
}

Variant DOMDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    return this_.exec("createProcessingInstruction", target, data);
}

Variant DOMDocument::createTextNode(const Variant &data) {
    return this_.exec("createTextNode", data);
}

Variant DOMDocument::getElementById(const Variant &element_id) {
    return this_.exec("getElementById", element_id);
}

Variant DOMDocument::getElementsByTagName(const Variant &qualified_name) {
    return this_.exec("getElementsByTagName", qualified_name);
}

Variant DOMDocument::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getElementsByTagNameNS", _namespace, local_name);
}

Variant DOMDocument::importNode(const Variant &node, const Variant &deep) {
    return this_.exec("importNode", node, deep);
}

Variant DOMDocument::load(const Variant &filename, const Variant &options) {
    return this_.exec("load", filename, options);
}

Variant DOMDocument::loadXML(const Variant &source, const Variant &options) {
    return this_.exec("loadXML", source, options);
}

Variant DOMDocument::normalizeDocument() {
    return this_.exec("normalizeDocument");
}

Variant DOMDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    return this_.exec("registerNodeClass", base_class, extended_class);
}

Variant DOMDocument::save(const Variant &filename, const Variant &options) {
    return this_.exec("save", filename, options);
}

Variant DOMDocument::loadHTML(const Variant &source, const Variant &options) {
    return this_.exec("loadHTML", source, options);
}

Variant DOMDocument::loadHTMLFile(const Variant &filename, const Variant &options) {
    return this_.exec("loadHTMLFile", filename, options);
}

Variant DOMDocument::saveHTML(const Variant &node) {
    return this_.exec("saveHTML", node);
}

Variant DOMDocument::saveHTMLFile(const Variant &filename) {
    return this_.exec("saveHTMLFile", filename);
}

Variant DOMDocument::saveXML(const Variant &node, const Variant &options) {
    return this_.exec("saveXML", node, options);
}

Variant DOMDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    return this_.exec("schemaValidate", filename, flags);
}

Variant DOMDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    return this_.exec("schemaValidateSource", source, flags);
}

Variant DOMDocument::relaxNGValidate(const Variant &filename) {
    return this_.exec("relaxNGValidate", filename);
}

Variant DOMDocument::relaxNGValidateSource(const Variant &source) {
    return this_.exec("relaxNGValidateSource", source);
}

Variant DOMDocument::validate() {
    return this_.exec("validate");
}

Variant DOMDocument::xinclude(const Variant &options) {
    return this_.exec("xinclude", options);
}

Variant DOMDocument::adoptNode(const Variant &node) {
    return this_.exec("adoptNode", node);
}

Variant DOMDocument::append(const Variant &nodes) {
    return this_.exec("append", nodes);
}

Variant DOMDocument::prepend(const Variant &nodes) {
    return this_.exec("prepend", nodes);
}

Variant DOMDocument::replaceChildren(const Variant &nodes) {
    return this_.exec("replaceChildren", nodes);
}

Variant DOMDocument::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMDocument::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMDocument::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMDocument::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocument::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocument::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMDocument::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMDocument::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMDocument::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMDocument::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMDocument::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMDocument::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMDocument::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMDocument::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMDocument::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMDocument::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMDocument::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMDocument::normalize() {
    return this_.exec("normalize");
}

Variant DOMDocument::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMDocument::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMDocument::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMDocument::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


Variant DOMNodeList::count() {
    return this_.exec("count");
}

Variant DOMNodeList::getIterator() {
    return this_.exec("getIterator");
}

Variant DOMNodeList::item(const Variant &index) {
    return this_.exec("item", index);
}


Variant DOMNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    return this_.exec("getNamedItem", qualified_name);
}

Variant DOMNamedNodeMap::getNamedItemNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getNamedItemNS", _namespace, local_name);
}

Variant DOMNamedNodeMap::item(const Variant &index) {
    return this_.exec("item", index);
}

Variant DOMNamedNodeMap::count() {
    return this_.exec("count");
}

Variant DOMNamedNodeMap::getIterator() {
    return this_.exec("getIterator");
}


Variant DOMCharacterData::appendData(const Variant &data) {
    return this_.exec("appendData", data);
}

Variant DOMCharacterData::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", offset, count);
}

Variant DOMCharacterData::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", offset, data);
}

Variant DOMCharacterData::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", offset, count);
}

Variant DOMCharacterData::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", offset, count, data);
}

Variant DOMCharacterData::replaceWith(const Variant &nodes) {
    return this_.exec("replaceWith", nodes);
}

Variant DOMCharacterData::remove() {
    return this_.exec("remove");
}

Variant DOMCharacterData::before(const Variant &nodes) {
    return this_.exec("before", nodes);
}

Variant DOMCharacterData::after(const Variant &nodes) {
    return this_.exec("after", nodes);
}

Variant DOMCharacterData::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMCharacterData::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMCharacterData::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMCharacterData::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMCharacterData::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMCharacterData::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMCharacterData::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMCharacterData::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMCharacterData::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMCharacterData::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMCharacterData::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMCharacterData::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMCharacterData::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMCharacterData::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMCharacterData::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMCharacterData::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMCharacterData::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMCharacterData::normalize() {
    return this_.exec("normalize");
}

Variant DOMCharacterData::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMCharacterData::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMCharacterData::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMCharacterData::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMAttr::DOMAttr(const Variant &name, const Variant &value) {
    this_ = newObject("DOMAttr", name, value);
}

Variant DOMAttr::isId() {
    return this_.exec("isId");
}

Variant DOMAttr::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMAttr::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMAttr::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMAttr::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMAttr::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMAttr::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMAttr::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMAttr::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMAttr::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMAttr::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMAttr::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMAttr::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMAttr::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMAttr::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMAttr::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMAttr::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMAttr::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMAttr::normalize() {
    return this_.exec("normalize");
}

Variant DOMAttr::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMAttr::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMAttr::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMAttr::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMElement::DOMElement(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    this_ = newObject("DOMElement", qualified_name, value, _namespace);
}

Variant DOMElement::getAttribute(const Variant &qualified_name) {
    return this_.exec("getAttribute", qualified_name);
}

Variant DOMElement::getAttributeNames() {
    return this_.exec("getAttributeNames");
}

Variant DOMElement::getAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getAttributeNS", _namespace, local_name);
}

Variant DOMElement::getAttributeNode(const Variant &qualified_name) {
    return this_.exec("getAttributeNode", qualified_name);
}

Variant DOMElement::getAttributeNodeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getAttributeNodeNS", _namespace, local_name);
}

Variant DOMElement::getElementsByTagName(const Variant &qualified_name) {
    return this_.exec("getElementsByTagName", qualified_name);
}

Variant DOMElement::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getElementsByTagNameNS", _namespace, local_name);
}

Variant DOMElement::hasAttribute(const Variant &qualified_name) {
    return this_.exec("hasAttribute", qualified_name);
}

Variant DOMElement::hasAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("hasAttributeNS", _namespace, local_name);
}

Variant DOMElement::removeAttribute(const Variant &qualified_name) {
    return this_.exec("removeAttribute", qualified_name);
}

Variant DOMElement::removeAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("removeAttributeNS", _namespace, local_name);
}

Variant DOMElement::removeAttributeNode(const Variant &attr) {
    return this_.exec("removeAttributeNode", attr);
}

Variant DOMElement::setAttribute(const Variant &qualified_name, const Variant &value) {
    return this_.exec("setAttribute", qualified_name, value);
}

Variant DOMElement::setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    return this_.exec("setAttributeNS", _namespace, qualified_name, value);
}

Variant DOMElement::setAttributeNode(const Variant &attr) {
    return this_.exec("setAttributeNode", attr);
}

Variant DOMElement::setAttributeNodeNS(const Variant &attr) {
    return this_.exec("setAttributeNodeNS", attr);
}

Variant DOMElement::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    return this_.exec("setIdAttribute", qualified_name, is_id);
}

Variant DOMElement::setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id) {
    return this_.exec("setIdAttributeNS", _namespace, qualified_name, is_id);
}

Variant DOMElement::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    return this_.exec("setIdAttributeNode", attr, is_id);
}

Variant DOMElement::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    return this_.exec("toggleAttribute", qualified_name, force);
}

Variant DOMElement::remove() {
    return this_.exec("remove");
}

Variant DOMElement::before(const Variant &nodes) {
    return this_.exec("before", nodes);
}

Variant DOMElement::after(const Variant &nodes) {
    return this_.exec("after", nodes);
}

Variant DOMElement::replaceWith(const Variant &nodes) {
    return this_.exec("replaceWith", nodes);
}

Variant DOMElement::append(const Variant &nodes) {
    return this_.exec("append", nodes);
}

Variant DOMElement::prepend(const Variant &nodes) {
    return this_.exec("prepend", nodes);
}

Variant DOMElement::replaceChildren(const Variant &nodes) {
    return this_.exec("replaceChildren", nodes);
}

Variant DOMElement::insertAdjacentElement(const Variant &where, const Variant &element) {
    return this_.exec("insertAdjacentElement", where, element);
}

Variant DOMElement::insertAdjacentText(const Variant &where, const Variant &data) {
    return this_.exec("insertAdjacentText", where, data);
}

Variant DOMElement::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMElement::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMElement::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMElement::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMElement::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMElement::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMElement::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMElement::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMElement::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMElement::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMElement::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMElement::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMElement::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMElement::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMElement::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMElement::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMElement::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMElement::normalize() {
    return this_.exec("normalize");
}

Variant DOMElement::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMElement::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMElement::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMElement::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMText::DOMText(const Variant &data) {
    this_ = newObject("DOMText", data);
}

Variant DOMText::isWhitespaceInElementContent() {
    return this_.exec("isWhitespaceInElementContent");
}

Variant DOMText::isElementContentWhitespace() {
    return this_.exec("isElementContentWhitespace");
}

Variant DOMText::splitText(const Variant &offset) {
    return this_.exec("splitText", offset);
}

Variant DOMText::appendData(const Variant &data) {
    return this_.exec("appendData", data);
}

Variant DOMText::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", offset, count);
}

Variant DOMText::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", offset, data);
}

Variant DOMText::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", offset, count);
}

Variant DOMText::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", offset, count, data);
}

Variant DOMText::replaceWith(const Variant &nodes) {
    return this_.exec("replaceWith", nodes);
}

Variant DOMText::remove() {
    return this_.exec("remove");
}

Variant DOMText::before(const Variant &nodes) {
    return this_.exec("before", nodes);
}

Variant DOMText::after(const Variant &nodes) {
    return this_.exec("after", nodes);
}

Variant DOMText::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMText::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMText::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMText::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMText::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMText::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMText::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMText::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMText::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMText::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMText::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMText::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMText::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMText::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMText::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMText::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMText::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMText::normalize() {
    return this_.exec("normalize");
}

Variant DOMText::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMText::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMText::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMText::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMComment::DOMComment(const Variant &data) {
    this_ = newObject("DOMComment", data);
}

Variant DOMComment::appendData(const Variant &data) {
    return this_.exec("appendData", data);
}

Variant DOMComment::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", offset, count);
}

Variant DOMComment::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", offset, data);
}

Variant DOMComment::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", offset, count);
}

Variant DOMComment::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", offset, count, data);
}

Variant DOMComment::replaceWith(const Variant &nodes) {
    return this_.exec("replaceWith", nodes);
}

Variant DOMComment::remove() {
    return this_.exec("remove");
}

Variant DOMComment::before(const Variant &nodes) {
    return this_.exec("before", nodes);
}

Variant DOMComment::after(const Variant &nodes) {
    return this_.exec("after", nodes);
}

Variant DOMComment::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMComment::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMComment::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMComment::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMComment::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMComment::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMComment::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMComment::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMComment::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMComment::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMComment::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMComment::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMComment::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMComment::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMComment::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMComment::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMComment::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMComment::normalize() {
    return this_.exec("normalize");
}

Variant DOMComment::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMComment::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMComment::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMComment::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMCdataSection::DOMCdataSection(const Variant &data) {
    this_ = newObject("DOMCdataSection", data);
}

Variant DOMCdataSection::isWhitespaceInElementContent() {
    return this_.exec("isWhitespaceInElementContent");
}

Variant DOMCdataSection::isElementContentWhitespace() {
    return this_.exec("isElementContentWhitespace");
}

Variant DOMCdataSection::splitText(const Variant &offset) {
    return this_.exec("splitText", offset);
}

Variant DOMCdataSection::appendData(const Variant &data) {
    return this_.exec("appendData", data);
}

Variant DOMCdataSection::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", offset, count);
}

Variant DOMCdataSection::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", offset, data);
}

Variant DOMCdataSection::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", offset, count);
}

Variant DOMCdataSection::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", offset, count, data);
}

Variant DOMCdataSection::replaceWith(const Variant &nodes) {
    return this_.exec("replaceWith", nodes);
}

Variant DOMCdataSection::remove() {
    return this_.exec("remove");
}

Variant DOMCdataSection::before(const Variant &nodes) {
    return this_.exec("before", nodes);
}

Variant DOMCdataSection::after(const Variant &nodes) {
    return this_.exec("after", nodes);
}

Variant DOMCdataSection::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMCdataSection::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMCdataSection::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMCdataSection::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMCdataSection::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMCdataSection::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMCdataSection::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMCdataSection::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMCdataSection::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMCdataSection::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMCdataSection::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMCdataSection::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMCdataSection::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMCdataSection::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMCdataSection::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMCdataSection::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMCdataSection::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMCdataSection::normalize() {
    return this_.exec("normalize");
}

Variant DOMCdataSection::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMCdataSection::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMCdataSection::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMCdataSection::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


Variant DOMDocumentType::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMDocumentType::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMDocumentType::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMDocumentType::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocumentType::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocumentType::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMDocumentType::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMDocumentType::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMDocumentType::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMDocumentType::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMDocumentType::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMDocumentType::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMDocumentType::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMDocumentType::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMDocumentType::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMDocumentType::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMDocumentType::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMDocumentType::normalize() {
    return this_.exec("normalize");
}

Variant DOMDocumentType::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMDocumentType::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMDocumentType::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMDocumentType::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


Variant DOMNotation::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMNotation::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMNotation::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMNotation::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMNotation::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMNotation::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMNotation::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMNotation::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMNotation::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMNotation::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMNotation::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMNotation::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMNotation::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMNotation::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMNotation::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMNotation::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMNotation::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMNotation::normalize() {
    return this_.exec("normalize");
}

Variant DOMNotation::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMNotation::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMNotation::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMNotation::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


Variant DOMEntity::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMEntity::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMEntity::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMEntity::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMEntity::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMEntity::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMEntity::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMEntity::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMEntity::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMEntity::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMEntity::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMEntity::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMEntity::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMEntity::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMEntity::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMEntity::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMEntity::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMEntity::normalize() {
    return this_.exec("normalize");
}

Variant DOMEntity::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMEntity::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMEntity::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMEntity::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMEntityReference::DOMEntityReference(const Variant &name) {
    this_ = newObject("DOMEntityReference", name);
}

Variant DOMEntityReference::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMEntityReference::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMEntityReference::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMEntityReference::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMEntityReference::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMEntityReference::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMEntityReference::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMEntityReference::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMEntityReference::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMEntityReference::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMEntityReference::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMEntityReference::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMEntityReference::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMEntityReference::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMEntityReference::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMEntityReference::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMEntityReference::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMEntityReference::normalize() {
    return this_.exec("normalize");
}

Variant DOMEntityReference::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMEntityReference::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMEntityReference::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMEntityReference::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMProcessingInstruction::DOMProcessingInstruction(const Variant &name, const Variant &value) {
    this_ = newObject("DOMProcessingInstruction", name, value);
}

Variant DOMProcessingInstruction::__sleep() {
    return this_.exec("__sleep");
}

Variant DOMProcessingInstruction::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DOMProcessingInstruction::appendChild(const Variant &node) {
    return this_.exec("appendChild", node);
}

Variant DOMProcessingInstruction::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMProcessingInstruction::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMProcessingInstruction::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", deep);
}

Variant DOMProcessingInstruction::getLineNo() {
    return this_.exec("getLineNo");
}

Variant DOMProcessingInstruction::getNodePath() {
    return this_.exec("getNodePath");
}

Variant DOMProcessingInstruction::hasAttributes() {
    return this_.exec("hasAttributes");
}

Variant DOMProcessingInstruction::hasChildNodes() {
    return this_.exec("hasChildNodes");
}

Variant DOMProcessingInstruction::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", node, child);
}

Variant DOMProcessingInstruction::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", _namespace);
}

Variant DOMProcessingInstruction::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", other_node);
}

Variant DOMProcessingInstruction::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", other_node);
}

Variant DOMProcessingInstruction::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", feature, version);
}

Variant DOMProcessingInstruction::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", prefix);
}

Variant DOMProcessingInstruction::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", _namespace);
}

Variant DOMProcessingInstruction::normalize() {
    return this_.exec("normalize");
}

Variant DOMProcessingInstruction::removeChild(const Variant &child) {
    return this_.exec("removeChild", child);
}

Variant DOMProcessingInstruction::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", node, child);
}

Variant DOMProcessingInstruction::contains(const Variant &other) {
    return this_.exec("contains", other);
}

Variant DOMProcessingInstruction::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", options);
}


DOMXPath::DOMXPath(const Variant &document, const Variant &register_node_n_s) {
    this_ = newObject("DOMXPath", document, register_node_n_s);
}

Variant DOMXPath::evaluate(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    return this_.exec("evaluate", expression, context_node, register_node_n_s);
}

Variant DOMXPath::query(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    return this_.exec("query", expression, context_node, register_node_n_s);
}

Variant DOMXPath::registerNamespace(const Variant &prefix, const Variant &_namespace) {
    return this_.exec("registerNamespace", prefix, _namespace);
}

Variant DOMXPath::registerPhpFunctions(const Variant &restrict) {
    return this_.exec("registerPhpFunctions", restrict);
}


}

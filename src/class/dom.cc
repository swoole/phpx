#include "phpx.h"
#include "class/dom.h"

namespace php {
DOMException::DOMException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("DOMException", message, code, previous);
}

Variant DOMException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMException::getMessage() {
    return _this.exec("getMessage");
}

Variant DOMException::getCode() {
    return _this.exec("getCode");
}

Variant DOMException::getFile() {
    return _this.exec("getFile");
}

Variant DOMException::getLine() {
    return _this.exec("getLine");
}

Variant DOMException::getTrace() {
    return _this.exec("getTrace");
}

Variant DOMException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant DOMException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant DOMException::__toString() {
    return _this.exec("__toString");
}


Variant DOMImplementation::getFeature(const Variant &feature, const Variant &version) {
    return _this.exec("getFeature", feature, version);
}

Variant DOMImplementation::hasFeature(const Variant &feature, const Variant &version) {
    return _this.exec("hasFeature", feature, version);
}

Variant DOMImplementation::createDocumentType(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    return _this.exec("createDocumentType", qualified_name, public_id, system_id);
}

Variant DOMImplementation::createDocument(const Variant &_namespace, const Variant &qualified_name, const Variant &doctype) {
    return _this.exec("createDocument", _namespace, qualified_name, doctype);
}


Variant DOMNode::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMNode::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMNode::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMNode::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMNode::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMNode::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMNode::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMNode::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMNode::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMNode::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMNode::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMNode::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMNode::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMNode::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMNode::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMNode::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMNode::normalize() {
    return _this.exec("normalize");
}

Variant DOMNode::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMNode::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


Variant DOMNameSpaceNode::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMNameSpaceNode::__wakeup() {
    return _this.exec("__wakeup");
}


DOMDocumentFragment::DOMDocumentFragment() {
    _this = newObject("DOMDocumentFragment");
}

Variant DOMDocumentFragment::appendXML(const Variant &data) {
    return _this.exec("appendXML", data);
}

Variant DOMDocumentFragment::append(const Variant &nodes) {
    return _this.exec("append", nodes);
}

Variant DOMDocumentFragment::prepend(const Variant &nodes) {
    return _this.exec("prepend", nodes);
}

Variant DOMDocumentFragment::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMDocumentFragment::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMDocumentFragment::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMDocumentFragment::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocumentFragment::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocumentFragment::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMDocumentFragment::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMDocumentFragment::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMDocumentFragment::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMDocumentFragment::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMDocumentFragment::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMDocumentFragment::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMDocumentFragment::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMDocumentFragment::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMDocumentFragment::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMDocumentFragment::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMDocumentFragment::normalize() {
    return _this.exec("normalize");
}

Variant DOMDocumentFragment::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMDocumentFragment::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMDocument::DOMDocument(const Variant &version, const Variant &encoding) {
    _this = newObject("DOMDocument", version, encoding);
}

Variant DOMDocument::createAttribute(const Variant &local_name) {
    return _this.exec("createAttribute", local_name);
}

Variant DOMDocument::createAttributeNS(const Variant &_namespace, const Variant &qualified_name) {
    return _this.exec("createAttributeNS", _namespace, qualified_name);
}

Variant DOMDocument::createCDATASection(const Variant &data) {
    return _this.exec("createCDATASection", data);
}

Variant DOMDocument::createComment(const Variant &data) {
    return _this.exec("createComment", data);
}

Variant DOMDocument::createDocumentFragment() {
    return _this.exec("createDocumentFragment");
}

Variant DOMDocument::createElement(const Variant &local_name, const Variant &value) {
    return _this.exec("createElement", local_name, value);
}

Variant DOMDocument::createElementNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    return _this.exec("createElementNS", _namespace, qualified_name, value);
}

Variant DOMDocument::createEntityReference(const Variant &name) {
    return _this.exec("createEntityReference", name);
}

Variant DOMDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    return _this.exec("createProcessingInstruction", target, data);
}

Variant DOMDocument::createTextNode(const Variant &data) {
    return _this.exec("createTextNode", data);
}

Variant DOMDocument::getElementById(const Variant &element_id) {
    return _this.exec("getElementById", element_id);
}

Variant DOMDocument::getElementsByTagName(const Variant &qualified_name) {
    return _this.exec("getElementsByTagName", qualified_name);
}

Variant DOMDocument::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return _this.exec("getElementsByTagNameNS", _namespace, local_name);
}

Variant DOMDocument::importNode(const Variant &node, const Variant &deep) {
    return _this.exec("importNode", node, deep);
}

Variant DOMDocument::load(const Variant &filename, const Variant &options) {
    return _this.exec("load", filename, options);
}

Variant DOMDocument::loadXML(const Variant &source, const Variant &options) {
    return _this.exec("loadXML", source, options);
}

Variant DOMDocument::normalizeDocument() {
    return _this.exec("normalizeDocument");
}

Variant DOMDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    return _this.exec("registerNodeClass", base_class, extended_class);
}

Variant DOMDocument::save(const Variant &filename, const Variant &options) {
    return _this.exec("save", filename, options);
}

Variant DOMDocument::loadHTML(const Variant &source, const Variant &options) {
    return _this.exec("loadHTML", source, options);
}

Variant DOMDocument::loadHTMLFile(const Variant &filename, const Variant &options) {
    return _this.exec("loadHTMLFile", filename, options);
}

Variant DOMDocument::saveHTML(const Variant &node) {
    return _this.exec("saveHTML", node);
}

Variant DOMDocument::saveHTMLFile(const Variant &filename) {
    return _this.exec("saveHTMLFile", filename);
}

Variant DOMDocument::saveXML(const Variant &node, const Variant &options) {
    return _this.exec("saveXML", node, options);
}

Variant DOMDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    return _this.exec("schemaValidate", filename, flags);
}

Variant DOMDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    return _this.exec("schemaValidateSource", source, flags);
}

Variant DOMDocument::relaxNGValidate(const Variant &filename) {
    return _this.exec("relaxNGValidate", filename);
}

Variant DOMDocument::relaxNGValidateSource(const Variant &source) {
    return _this.exec("relaxNGValidateSource", source);
}

Variant DOMDocument::validate() {
    return _this.exec("validate");
}

Variant DOMDocument::xinclude(const Variant &options) {
    return _this.exec("xinclude", options);
}

Variant DOMDocument::adoptNode(const Variant &node) {
    return _this.exec("adoptNode", node);
}

Variant DOMDocument::append(const Variant &nodes) {
    return _this.exec("append", nodes);
}

Variant DOMDocument::prepend(const Variant &nodes) {
    return _this.exec("prepend", nodes);
}

Variant DOMDocument::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMDocument::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMDocument::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMDocument::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocument::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocument::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMDocument::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMDocument::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMDocument::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMDocument::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMDocument::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMDocument::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMDocument::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMDocument::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMDocument::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMDocument::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMDocument::normalize() {
    return _this.exec("normalize");
}

Variant DOMDocument::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMDocument::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


Variant DOMNodeList::count() {
    return _this.exec("count");
}

Variant DOMNodeList::getIterator() {
    return _this.exec("getIterator");
}

Variant DOMNodeList::item(const Variant &index) {
    return _this.exec("item", index);
}


Variant DOMNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    return _this.exec("getNamedItem", qualified_name);
}

Variant DOMNamedNodeMap::getNamedItemNS(const Variant &_namespace, const Variant &local_name) {
    return _this.exec("getNamedItemNS", _namespace, local_name);
}

Variant DOMNamedNodeMap::item(const Variant &index) {
    return _this.exec("item", index);
}

Variant DOMNamedNodeMap::count() {
    return _this.exec("count");
}

Variant DOMNamedNodeMap::getIterator() {
    return _this.exec("getIterator");
}


Variant DOMCharacterData::appendData(const Variant &data) {
    return _this.exec("appendData", data);
}

Variant DOMCharacterData::substringData(const Variant &offset, const Variant &count) {
    return _this.exec("substringData", offset, count);
}

Variant DOMCharacterData::insertData(const Variant &offset, const Variant &data) {
    return _this.exec("insertData", offset, data);
}

Variant DOMCharacterData::deleteData(const Variant &offset, const Variant &count) {
    return _this.exec("deleteData", offset, count);
}

Variant DOMCharacterData::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return _this.exec("replaceData", offset, count, data);
}

Variant DOMCharacterData::replaceWith(const Variant &nodes) {
    return _this.exec("replaceWith", nodes);
}

Variant DOMCharacterData::remove() {
    return _this.exec("remove");
}

Variant DOMCharacterData::before(const Variant &nodes) {
    return _this.exec("before", nodes);
}

Variant DOMCharacterData::after(const Variant &nodes) {
    return _this.exec("after", nodes);
}

Variant DOMCharacterData::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMCharacterData::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMCharacterData::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMCharacterData::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMCharacterData::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMCharacterData::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMCharacterData::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMCharacterData::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMCharacterData::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMCharacterData::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMCharacterData::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMCharacterData::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMCharacterData::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMCharacterData::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMCharacterData::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMCharacterData::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMCharacterData::normalize() {
    return _this.exec("normalize");
}

Variant DOMCharacterData::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMCharacterData::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMAttr::DOMAttr(const Variant &name, const Variant &value) {
    _this = newObject("DOMAttr", name, value);
}

Variant DOMAttr::isId() {
    return _this.exec("isId");
}

Variant DOMAttr::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMAttr::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMAttr::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMAttr::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMAttr::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMAttr::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMAttr::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMAttr::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMAttr::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMAttr::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMAttr::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMAttr::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMAttr::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMAttr::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMAttr::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMAttr::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMAttr::normalize() {
    return _this.exec("normalize");
}

Variant DOMAttr::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMAttr::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMElement::DOMElement(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    _this = newObject("DOMElement", qualified_name, value, _namespace);
}

Variant DOMElement::getAttribute(const Variant &qualified_name) {
    return _this.exec("getAttribute", qualified_name);
}

Variant DOMElement::getAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return _this.exec("getAttributeNS", _namespace, local_name);
}

Variant DOMElement::getAttributeNode(const Variant &qualified_name) {
    return _this.exec("getAttributeNode", qualified_name);
}

Variant DOMElement::getAttributeNodeNS(const Variant &_namespace, const Variant &local_name) {
    return _this.exec("getAttributeNodeNS", _namespace, local_name);
}

Variant DOMElement::getElementsByTagName(const Variant &qualified_name) {
    return _this.exec("getElementsByTagName", qualified_name);
}

Variant DOMElement::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return _this.exec("getElementsByTagNameNS", _namespace, local_name);
}

Variant DOMElement::hasAttribute(const Variant &qualified_name) {
    return _this.exec("hasAttribute", qualified_name);
}

Variant DOMElement::hasAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return _this.exec("hasAttributeNS", _namespace, local_name);
}

Variant DOMElement::removeAttribute(const Variant &qualified_name) {
    return _this.exec("removeAttribute", qualified_name);
}

Variant DOMElement::removeAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return _this.exec("removeAttributeNS", _namespace, local_name);
}

Variant DOMElement::removeAttributeNode(const Variant &attr) {
    return _this.exec("removeAttributeNode", attr);
}

Variant DOMElement::setAttribute(const Variant &qualified_name, const Variant &value) {
    return _this.exec("setAttribute", qualified_name, value);
}

Variant DOMElement::setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    return _this.exec("setAttributeNS", _namespace, qualified_name, value);
}

Variant DOMElement::setAttributeNode(const Variant &attr) {
    return _this.exec("setAttributeNode", attr);
}

Variant DOMElement::setAttributeNodeNS(const Variant &attr) {
    return _this.exec("setAttributeNodeNS", attr);
}

Variant DOMElement::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    return _this.exec("setIdAttribute", qualified_name, is_id);
}

Variant DOMElement::setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id) {
    return _this.exec("setIdAttributeNS", _namespace, qualified_name, is_id);
}

Variant DOMElement::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    return _this.exec("setIdAttributeNode", attr, is_id);
}

Variant DOMElement::remove() {
    return _this.exec("remove");
}

Variant DOMElement::before(const Variant &nodes) {
    return _this.exec("before", nodes);
}

Variant DOMElement::after(const Variant &nodes) {
    return _this.exec("after", nodes);
}

Variant DOMElement::replaceWith(const Variant &nodes) {
    return _this.exec("replaceWith", nodes);
}

Variant DOMElement::append(const Variant &nodes) {
    return _this.exec("append", nodes);
}

Variant DOMElement::prepend(const Variant &nodes) {
    return _this.exec("prepend", nodes);
}

Variant DOMElement::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMElement::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMElement::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMElement::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMElement::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMElement::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMElement::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMElement::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMElement::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMElement::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMElement::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMElement::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMElement::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMElement::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMElement::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMElement::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMElement::normalize() {
    return _this.exec("normalize");
}

Variant DOMElement::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMElement::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMText::DOMText(const Variant &data) {
    _this = newObject("DOMText", data);
}

Variant DOMText::isWhitespaceInElementContent() {
    return _this.exec("isWhitespaceInElementContent");
}

Variant DOMText::isElementContentWhitespace() {
    return _this.exec("isElementContentWhitespace");
}

Variant DOMText::splitText(const Variant &offset) {
    return _this.exec("splitText", offset);
}

Variant DOMText::appendData(const Variant &data) {
    return _this.exec("appendData", data);
}

Variant DOMText::substringData(const Variant &offset, const Variant &count) {
    return _this.exec("substringData", offset, count);
}

Variant DOMText::insertData(const Variant &offset, const Variant &data) {
    return _this.exec("insertData", offset, data);
}

Variant DOMText::deleteData(const Variant &offset, const Variant &count) {
    return _this.exec("deleteData", offset, count);
}

Variant DOMText::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return _this.exec("replaceData", offset, count, data);
}

Variant DOMText::replaceWith(const Variant &nodes) {
    return _this.exec("replaceWith", nodes);
}

Variant DOMText::remove() {
    return _this.exec("remove");
}

Variant DOMText::before(const Variant &nodes) {
    return _this.exec("before", nodes);
}

Variant DOMText::after(const Variant &nodes) {
    return _this.exec("after", nodes);
}

Variant DOMText::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMText::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMText::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMText::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMText::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMText::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMText::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMText::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMText::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMText::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMText::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMText::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMText::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMText::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMText::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMText::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMText::normalize() {
    return _this.exec("normalize");
}

Variant DOMText::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMText::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMComment::DOMComment(const Variant &data) {
    _this = newObject("DOMComment", data);
}

Variant DOMComment::appendData(const Variant &data) {
    return _this.exec("appendData", data);
}

Variant DOMComment::substringData(const Variant &offset, const Variant &count) {
    return _this.exec("substringData", offset, count);
}

Variant DOMComment::insertData(const Variant &offset, const Variant &data) {
    return _this.exec("insertData", offset, data);
}

Variant DOMComment::deleteData(const Variant &offset, const Variant &count) {
    return _this.exec("deleteData", offset, count);
}

Variant DOMComment::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return _this.exec("replaceData", offset, count, data);
}

Variant DOMComment::replaceWith(const Variant &nodes) {
    return _this.exec("replaceWith", nodes);
}

Variant DOMComment::remove() {
    return _this.exec("remove");
}

Variant DOMComment::before(const Variant &nodes) {
    return _this.exec("before", nodes);
}

Variant DOMComment::after(const Variant &nodes) {
    return _this.exec("after", nodes);
}

Variant DOMComment::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMComment::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMComment::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMComment::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMComment::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMComment::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMComment::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMComment::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMComment::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMComment::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMComment::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMComment::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMComment::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMComment::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMComment::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMComment::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMComment::normalize() {
    return _this.exec("normalize");
}

Variant DOMComment::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMComment::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMCdataSection::DOMCdataSection(const Variant &data) {
    _this = newObject("DOMCdataSection", data);
}

Variant DOMCdataSection::isWhitespaceInElementContent() {
    return _this.exec("isWhitespaceInElementContent");
}

Variant DOMCdataSection::isElementContentWhitespace() {
    return _this.exec("isElementContentWhitespace");
}

Variant DOMCdataSection::splitText(const Variant &offset) {
    return _this.exec("splitText", offset);
}

Variant DOMCdataSection::appendData(const Variant &data) {
    return _this.exec("appendData", data);
}

Variant DOMCdataSection::substringData(const Variant &offset, const Variant &count) {
    return _this.exec("substringData", offset, count);
}

Variant DOMCdataSection::insertData(const Variant &offset, const Variant &data) {
    return _this.exec("insertData", offset, data);
}

Variant DOMCdataSection::deleteData(const Variant &offset, const Variant &count) {
    return _this.exec("deleteData", offset, count);
}

Variant DOMCdataSection::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return _this.exec("replaceData", offset, count, data);
}

Variant DOMCdataSection::replaceWith(const Variant &nodes) {
    return _this.exec("replaceWith", nodes);
}

Variant DOMCdataSection::remove() {
    return _this.exec("remove");
}

Variant DOMCdataSection::before(const Variant &nodes) {
    return _this.exec("before", nodes);
}

Variant DOMCdataSection::after(const Variant &nodes) {
    return _this.exec("after", nodes);
}

Variant DOMCdataSection::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMCdataSection::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMCdataSection::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMCdataSection::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMCdataSection::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMCdataSection::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMCdataSection::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMCdataSection::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMCdataSection::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMCdataSection::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMCdataSection::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMCdataSection::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMCdataSection::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMCdataSection::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMCdataSection::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMCdataSection::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMCdataSection::normalize() {
    return _this.exec("normalize");
}

Variant DOMCdataSection::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMCdataSection::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


Variant DOMDocumentType::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMDocumentType::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMDocumentType::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMDocumentType::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocumentType::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMDocumentType::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMDocumentType::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMDocumentType::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMDocumentType::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMDocumentType::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMDocumentType::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMDocumentType::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMDocumentType::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMDocumentType::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMDocumentType::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMDocumentType::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMDocumentType::normalize() {
    return _this.exec("normalize");
}

Variant DOMDocumentType::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMDocumentType::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


Variant DOMNotation::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMNotation::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMNotation::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMNotation::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMNotation::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMNotation::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMNotation::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMNotation::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMNotation::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMNotation::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMNotation::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMNotation::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMNotation::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMNotation::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMNotation::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMNotation::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMNotation::normalize() {
    return _this.exec("normalize");
}

Variant DOMNotation::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMNotation::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


Variant DOMEntity::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMEntity::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMEntity::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMEntity::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMEntity::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMEntity::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMEntity::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMEntity::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMEntity::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMEntity::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMEntity::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMEntity::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMEntity::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMEntity::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMEntity::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMEntity::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMEntity::normalize() {
    return _this.exec("normalize");
}

Variant DOMEntity::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMEntity::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMEntityReference::DOMEntityReference(const Variant &name) {
    _this = newObject("DOMEntityReference", name);
}

Variant DOMEntityReference::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMEntityReference::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMEntityReference::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMEntityReference::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMEntityReference::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMEntityReference::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMEntityReference::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMEntityReference::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMEntityReference::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMEntityReference::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMEntityReference::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMEntityReference::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMEntityReference::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMEntityReference::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMEntityReference::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMEntityReference::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMEntityReference::normalize() {
    return _this.exec("normalize");
}

Variant DOMEntityReference::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMEntityReference::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMProcessingInstruction::DOMProcessingInstruction(const Variant &name, const Variant &value) {
    _this = newObject("DOMProcessingInstruction", name, value);
}

Variant DOMProcessingInstruction::__sleep() {
    return _this.exec("__sleep");
}

Variant DOMProcessingInstruction::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DOMProcessingInstruction::appendChild(const Variant &node) {
    return _this.exec("appendChild", node);
}

Variant DOMProcessingInstruction::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14N", exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMProcessingInstruction::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return _this.exec("C14NFile", uri, exclusive, with_comments, xpath, ns_prefixes);
}

Variant DOMProcessingInstruction::cloneNode(const Variant &deep) {
    return _this.exec("cloneNode", deep);
}

Variant DOMProcessingInstruction::getLineNo() {
    return _this.exec("getLineNo");
}

Variant DOMProcessingInstruction::getNodePath() {
    return _this.exec("getNodePath");
}

Variant DOMProcessingInstruction::hasAttributes() {
    return _this.exec("hasAttributes");
}

Variant DOMProcessingInstruction::hasChildNodes() {
    return _this.exec("hasChildNodes");
}

Variant DOMProcessingInstruction::insertBefore(const Variant &node, const Variant &child) {
    return _this.exec("insertBefore", node, child);
}

Variant DOMProcessingInstruction::isDefaultNamespace(const Variant &_namespace) {
    return _this.exec("isDefaultNamespace", _namespace);
}

Variant DOMProcessingInstruction::isSameNode(const Variant &other_node) {
    return _this.exec("isSameNode", other_node);
}

Variant DOMProcessingInstruction::isSupported(const Variant &feature, const Variant &version) {
    return _this.exec("isSupported", feature, version);
}

Variant DOMProcessingInstruction::lookupNamespaceURI(const Variant &prefix) {
    return _this.exec("lookupNamespaceURI", prefix);
}

Variant DOMProcessingInstruction::lookupPrefix(const Variant &_namespace) {
    return _this.exec("lookupPrefix", _namespace);
}

Variant DOMProcessingInstruction::normalize() {
    return _this.exec("normalize");
}

Variant DOMProcessingInstruction::removeChild(const Variant &child) {
    return _this.exec("removeChild", child);
}

Variant DOMProcessingInstruction::replaceChild(const Variant &node, const Variant &child) {
    return _this.exec("replaceChild", node, child);
}


DOMXPath::DOMXPath(const Variant &document, const Variant &register_node_n_s) {
    _this = newObject("DOMXPath", document, register_node_n_s);
}

Variant DOMXPath::evaluate(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    return _this.exec("evaluate", expression, context_node, register_node_n_s);
}

Variant DOMXPath::query(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    return _this.exec("query", expression, context_node, register_node_n_s);
}

Variant DOMXPath::registerNamespace(const Variant &prefix, const Variant &_namespace) {
    return _this.exec("registerNamespace", prefix, _namespace);
}

Variant DOMXPath::registerPhpFunctions(const Variant &restrict) {
    return _this.exec("registerPhpFunctions", restrict);
}


}

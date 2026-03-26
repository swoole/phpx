#include "phpx.h"
#include "class/dom.h"

namespace php {
Variant Dom_AdjacentPosition::cases() {
    static Variant fn { ZEND_STRL("Dom_AdjacentPosition::cases"), true };
    return fn({});
}

Variant Dom_AdjacentPosition::from(const Variant &value) {
    static Variant fn { ZEND_STRL("Dom_AdjacentPosition::from"), true };
    return fn({value});
}

Variant Dom_AdjacentPosition::tryFrom(const Variant &value) {
    static Variant fn { ZEND_STRL("Dom_AdjacentPosition::tryFrom"), true };
    return fn({value});
}


DOMException::DOMException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("DOMException", {message, code, previous});
}

Variant DOMException::__wakeup() {
    return this_.exec("__wakeup", {});
}

Variant DOMException::getMessage() {
    return this_.exec("getMessage", {});
}

Variant DOMException::getCode() {
    return this_.exec("getCode", {});
}

Variant DOMException::getFile() {
    return this_.exec("getFile", {});
}

Variant DOMException::getLine() {
    return this_.exec("getLine", {});
}

Variant DOMException::getTrace() {
    return this_.exec("getTrace", {});
}

Variant DOMException::getPrevious() {
    return this_.exec("getPrevious", {});
}

Variant DOMException::getTraceAsString() {
    return this_.exec("getTraceAsString", {});
}

Variant DOMException::__toString() {
    return this_.exec("__toString", {});
}


dom_domexception::dom_domexception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("DOMException", {message, code, previous});
}

Variant dom_domexception::__wakeup() {
    return this_.exec("__wakeup", {});
}

Variant dom_domexception::getMessage() {
    return this_.exec("getMessage", {});
}

Variant dom_domexception::getCode() {
    return this_.exec("getCode", {});
}

Variant dom_domexception::getFile() {
    return this_.exec("getFile", {});
}

Variant dom_domexception::getLine() {
    return this_.exec("getLine", {});
}

Variant dom_domexception::getTrace() {
    return this_.exec("getTrace", {});
}

Variant dom_domexception::getPrevious() {
    return this_.exec("getPrevious", {});
}

Variant dom_domexception::getTraceAsString() {
    return this_.exec("getTraceAsString", {});
}

Variant dom_domexception::__toString() {
    return this_.exec("__toString", {});
}


Variant DOMImplementation::hasFeature(const Variant &feature, const Variant &version) {
    return this_.exec("hasFeature", {feature, version});
}

Variant DOMImplementation::createDocumentType(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    return this_.exec("createDocumentType", {qualified_name, public_id, system_id});
}

Variant DOMImplementation::createDocument(const Variant &_namespace, const Variant &qualified_name, const Variant &doctype) {
    return this_.exec("createDocument", {_namespace, qualified_name, doctype});
}


Variant Dom_Implementation::createDocumentType(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    return this_.exec("createDocumentType", {qualified_name, public_id, system_id});
}

Variant Dom_Implementation::createDocument(const Variant &_namespace, const Variant &qualified_name, const Variant &doctype) {
    return this_.exec("createDocument", {_namespace, qualified_name, doctype});
}

Variant Dom_Implementation::createHTMLDocument(const Variant &title) {
    return this_.exec("createHTMLDocument", {title});
}


Variant DOMNode::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMNode::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMNode::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMNode::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMNode::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMNode::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMNode::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMNode::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMNode::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMNode::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMNode::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMNode::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMNode::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMNode::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMNode::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMNode::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMNode::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMNode::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMNode::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMNode::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMNode::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMNode::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMNode::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_Node::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_Node::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_Node::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_Node::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_Node::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_Node::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_Node::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_Node::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_Node::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_Node::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_Node::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_Node::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_Node::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_Node::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_Node::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_Node::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_Node::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_Node::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Node::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Node::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_Node::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant DOMNameSpaceNode::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMNameSpaceNode::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMDocumentFragment::DOMDocumentFragment() {
    this_ = newObject("DOMDocumentFragment", {});
}

Variant DOMDocumentFragment::appendXML(const Variant &data) {
    return this_.exec("appendXML", {data});
}




Variant DOMDocumentFragment::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMDocumentFragment::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMDocumentFragment::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMDocumentFragment::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMDocumentFragment::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMDocumentFragment::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMDocumentFragment::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMDocumentFragment::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMDocumentFragment::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMDocumentFragment::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMDocumentFragment::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMDocumentFragment::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMDocumentFragment::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMDocumentFragment::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMDocumentFragment::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMDocumentFragment::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMDocumentFragment::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMDocumentFragment::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMDocumentFragment::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMDocumentFragment::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMDocumentFragment::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMDocumentFragment::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMDocumentFragment::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_DocumentFragment::appendXml(const Variant &data) {
    return this_.exec("appendXml", {data});
}




Variant Dom_DocumentFragment::querySelector(const Variant &selectors) {
    return this_.exec("querySelector", {selectors});
}

Variant Dom_DocumentFragment::querySelectorAll(const Variant &selectors) {
    return this_.exec("querySelectorAll", {selectors});
}

Variant Dom_DocumentFragment::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_DocumentFragment::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_DocumentFragment::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_DocumentFragment::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_DocumentFragment::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_DocumentFragment::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_DocumentFragment::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_DocumentFragment::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_DocumentFragment::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_DocumentFragment::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_DocumentFragment::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_DocumentFragment::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_DocumentFragment::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_DocumentFragment::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_DocumentFragment::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_DocumentFragment::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_DocumentFragment::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_DocumentFragment::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_DocumentFragment::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_DocumentFragment::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_DocumentFragment::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMDocument::DOMDocument(const Variant &version, const Variant &encoding) {
    this_ = newObject("DOMDocument", {version, encoding});
}

Variant DOMDocument::createAttribute(const Variant &local_name) {
    return this_.exec("createAttribute", {local_name});
}

Variant DOMDocument::createAttributeNS(const Variant &_namespace, const Variant &qualified_name) {
    return this_.exec("createAttributeNS", {_namespace, qualified_name});
}

Variant DOMDocument::createCDATASection(const Variant &data) {
    return this_.exec("createCDATASection", {data});
}

Variant DOMDocument::createComment(const Variant &data) {
    return this_.exec("createComment", {data});
}

Variant DOMDocument::createDocumentFragment() {
    return this_.exec("createDocumentFragment", {});
}

Variant DOMDocument::createElement(const Variant &local_name, const Variant &value) {
    return this_.exec("createElement", {local_name, value});
}

Variant DOMDocument::createElementNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    return this_.exec("createElementNS", {_namespace, qualified_name, value});
}

Variant DOMDocument::createEntityReference(const Variant &name) {
    return this_.exec("createEntityReference", {name});
}

Variant DOMDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    return this_.exec("createProcessingInstruction", {target, data});
}

Variant DOMDocument::createTextNode(const Variant &data) {
    return this_.exec("createTextNode", {data});
}

Variant DOMDocument::getElementById(const Variant &element_id) {
    return this_.exec("getElementById", {element_id});
}

Variant DOMDocument::getElementsByTagName(const Variant &qualified_name) {
    return this_.exec("getElementsByTagName", {qualified_name});
}

Variant DOMDocument::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getElementsByTagNameNS", {_namespace, local_name});
}

Variant DOMDocument::importNode(const Variant &node, const Variant &deep) {
    return this_.exec("importNode", {node, deep});
}

Variant DOMDocument::load(const Variant &filename, const Variant &options) {
    return this_.exec("load", {filename, options});
}

Variant DOMDocument::loadXML(const Variant &source, const Variant &options) {
    return this_.exec("loadXML", {source, options});
}

Variant DOMDocument::normalizeDocument() {
    return this_.exec("normalizeDocument", {});
}

Variant DOMDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    return this_.exec("registerNodeClass", {base_class, extended_class});
}

Variant DOMDocument::save(const Variant &filename, const Variant &options) {
    return this_.exec("save", {filename, options});
}

Variant DOMDocument::loadHTML(const Variant &source, const Variant &options) {
    return this_.exec("loadHTML", {source, options});
}

Variant DOMDocument::loadHTMLFile(const Variant &filename, const Variant &options) {
    return this_.exec("loadHTMLFile", {filename, options});
}

Variant DOMDocument::saveHTML(const Variant &node) {
    return this_.exec("saveHTML", {node});
}

Variant DOMDocument::saveHTMLFile(const Variant &filename) {
    return this_.exec("saveHTMLFile", {filename});
}

Variant DOMDocument::saveXML(const Variant &node, const Variant &options) {
    return this_.exec("saveXML", {node, options});
}

Variant DOMDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    return this_.exec("schemaValidate", {filename, flags});
}

Variant DOMDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    return this_.exec("schemaValidateSource", {source, flags});
}

Variant DOMDocument::relaxNGValidate(const Variant &filename) {
    return this_.exec("relaxNGValidate", {filename});
}

Variant DOMDocument::relaxNGValidateSource(const Variant &source) {
    return this_.exec("relaxNGValidateSource", {source});
}

Variant DOMDocument::validate() {
    return this_.exec("validate", {});
}

Variant DOMDocument::xinclude(const Variant &options) {
    return this_.exec("xinclude", {options});
}

Variant DOMDocument::adoptNode(const Variant &node) {
    return this_.exec("adoptNode", {node});
}




Variant DOMDocument::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMDocument::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMDocument::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMDocument::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMDocument::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMDocument::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMDocument::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMDocument::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMDocument::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMDocument::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMDocument::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMDocument::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMDocument::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMDocument::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMDocument::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMDocument::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMDocument::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMDocument::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMDocument::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMDocument::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMDocument::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMDocument::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMDocument::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_HTMLDocument::createEmpty(const Variant &encoding) {
    static Variant fn { ZEND_STRL("Dom_HTMLDocument::createEmpty"), true };
    return fn({encoding});
}

Variant Dom_HTMLDocument::createFromFile(const Variant &path, const Variant &options, const Variant &override_encoding) {
    static Variant fn { ZEND_STRL("Dom_HTMLDocument::createFromFile"), true };
    return fn({path, options, override_encoding});
}

Variant Dom_HTMLDocument::createFromString(const Variant &source, const Variant &options, const Variant &override_encoding) {
    static Variant fn { ZEND_STRL("Dom_HTMLDocument::createFromString"), true };
    return fn({source, options, override_encoding});
}

Variant Dom_HTMLDocument::saveXml(const Variant &node, const Variant &options) {
    return this_.exec("saveXml", {node, options});
}

Variant Dom_HTMLDocument::saveXmlFile(const Variant &filename, const Variant &options) {
    return this_.exec("saveXmlFile", {filename, options});
}

Variant Dom_HTMLDocument::saveHtml(const Variant &node) {
    return this_.exec("saveHtml", {node});
}

Variant Dom_HTMLDocument::saveHtmlFile(const Variant &filename) {
    return this_.exec("saveHtmlFile", {filename});
}

Variant Dom_HTMLDocument::debugGetTemplateCount() {
    return this_.exec("debugGetTemplateCount", {});
}

Variant Dom_HTMLDocument::getElementsByTagName(const Variant &qualified_name) {
    return this_.exec("getElementsByTagName", {qualified_name});
}

Variant Dom_HTMLDocument::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getElementsByTagNameNS", {_namespace, local_name});
}

Variant Dom_HTMLDocument::createElement(const Variant &local_name) {
    return this_.exec("createElement", {local_name});
}

Variant Dom_HTMLDocument::createElementNS(const Variant &_namespace, const Variant &qualified_name) {
    return this_.exec("createElementNS", {_namespace, qualified_name});
}

Variant Dom_HTMLDocument::createDocumentFragment() {
    return this_.exec("createDocumentFragment", {});
}

Variant Dom_HTMLDocument::createTextNode(const Variant &data) {
    return this_.exec("createTextNode", {data});
}

Variant Dom_HTMLDocument::createCDATASection(const Variant &data) {
    return this_.exec("createCDATASection", {data});
}

Variant Dom_HTMLDocument::createComment(const Variant &data) {
    return this_.exec("createComment", {data});
}

Variant Dom_HTMLDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    return this_.exec("createProcessingInstruction", {target, data});
}

Variant Dom_HTMLDocument::importNode(const Variant &node, const Variant &deep) {
    return this_.exec("importNode", {node, deep});
}

Variant Dom_HTMLDocument::adoptNode(const Variant &node) {
    return this_.exec("adoptNode", {node});
}

Variant Dom_HTMLDocument::createAttribute(const Variant &local_name) {
    return this_.exec("createAttribute", {local_name});
}

Variant Dom_HTMLDocument::createAttributeNS(const Variant &_namespace, const Variant &qualified_name) {
    return this_.exec("createAttributeNS", {_namespace, qualified_name});
}

Variant Dom_HTMLDocument::getElementById(const Variant &element_id) {
    return this_.exec("getElementById", {element_id});
}

Variant Dom_HTMLDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    return this_.exec("registerNodeClass", {base_class, extended_class});
}

Variant Dom_HTMLDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    return this_.exec("schemaValidate", {filename, flags});
}

Variant Dom_HTMLDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    return this_.exec("schemaValidateSource", {source, flags});
}

Variant Dom_HTMLDocument::relaxNgValidate(const Variant &filename) {
    return this_.exec("relaxNgValidate", {filename});
}

Variant Dom_HTMLDocument::relaxNgValidateSource(const Variant &source) {
    return this_.exec("relaxNgValidateSource", {source});
}




Variant Dom_HTMLDocument::importLegacyNode(const Variant &node, const Variant &deep) {
    return this_.exec("importLegacyNode", {node, deep});
}

Variant Dom_HTMLDocument::querySelector(const Variant &selectors) {
    return this_.exec("querySelector", {selectors});
}

Variant Dom_HTMLDocument::querySelectorAll(const Variant &selectors) {
    return this_.exec("querySelectorAll", {selectors});
}

Variant Dom_HTMLDocument::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_HTMLDocument::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_HTMLDocument::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_HTMLDocument::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_HTMLDocument::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_HTMLDocument::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_HTMLDocument::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_HTMLDocument::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_HTMLDocument::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_HTMLDocument::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_HTMLDocument::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_HTMLDocument::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_HTMLDocument::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_HTMLDocument::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_HTMLDocument::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_HTMLDocument::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_HTMLDocument::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_HTMLDocument::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_HTMLDocument::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_HTMLDocument::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_HTMLDocument::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_XMLDocument::createEmpty(const Variant &version, const Variant &encoding) {
    static Variant fn { ZEND_STRL("Dom_XMLDocument::createEmpty"), true };
    return fn({version, encoding});
}

Variant Dom_XMLDocument::createFromFile(const Variant &path, const Variant &options, const Variant &override_encoding) {
    static Variant fn { ZEND_STRL("Dom_XMLDocument::createFromFile"), true };
    return fn({path, options, override_encoding});
}

Variant Dom_XMLDocument::createFromString(const Variant &source, const Variant &options, const Variant &override_encoding) {
    static Variant fn { ZEND_STRL("Dom_XMLDocument::createFromString"), true };
    return fn({source, options, override_encoding});
}

Variant Dom_XMLDocument::createEntityReference(const Variant &name) {
    return this_.exec("createEntityReference", {name});
}

Variant Dom_XMLDocument::validate() {
    return this_.exec("validate", {});
}

Variant Dom_XMLDocument::xinclude(const Variant &options) {
    return this_.exec("xinclude", {options});
}

Variant Dom_XMLDocument::saveXml(const Variant &node, const Variant &options) {
    return this_.exec("saveXml", {node, options});
}

Variant Dom_XMLDocument::saveXmlFile(const Variant &filename, const Variant &options) {
    return this_.exec("saveXmlFile", {filename, options});
}

Variant Dom_XMLDocument::getElementsByTagName(const Variant &qualified_name) {
    return this_.exec("getElementsByTagName", {qualified_name});
}

Variant Dom_XMLDocument::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getElementsByTagNameNS", {_namespace, local_name});
}

Variant Dom_XMLDocument::createElement(const Variant &local_name) {
    return this_.exec("createElement", {local_name});
}

Variant Dom_XMLDocument::createElementNS(const Variant &_namespace, const Variant &qualified_name) {
    return this_.exec("createElementNS", {_namespace, qualified_name});
}

Variant Dom_XMLDocument::createDocumentFragment() {
    return this_.exec("createDocumentFragment", {});
}

Variant Dom_XMLDocument::createTextNode(const Variant &data) {
    return this_.exec("createTextNode", {data});
}

Variant Dom_XMLDocument::createCDATASection(const Variant &data) {
    return this_.exec("createCDATASection", {data});
}

Variant Dom_XMLDocument::createComment(const Variant &data) {
    return this_.exec("createComment", {data});
}

Variant Dom_XMLDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    return this_.exec("createProcessingInstruction", {target, data});
}

Variant Dom_XMLDocument::importNode(const Variant &node, const Variant &deep) {
    return this_.exec("importNode", {node, deep});
}

Variant Dom_XMLDocument::adoptNode(const Variant &node) {
    return this_.exec("adoptNode", {node});
}

Variant Dom_XMLDocument::createAttribute(const Variant &local_name) {
    return this_.exec("createAttribute", {local_name});
}

Variant Dom_XMLDocument::createAttributeNS(const Variant &_namespace, const Variant &qualified_name) {
    return this_.exec("createAttributeNS", {_namespace, qualified_name});
}

Variant Dom_XMLDocument::getElementById(const Variant &element_id) {
    return this_.exec("getElementById", {element_id});
}

Variant Dom_XMLDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    return this_.exec("registerNodeClass", {base_class, extended_class});
}

Variant Dom_XMLDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    return this_.exec("schemaValidate", {filename, flags});
}

Variant Dom_XMLDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    return this_.exec("schemaValidateSource", {source, flags});
}

Variant Dom_XMLDocument::relaxNgValidate(const Variant &filename) {
    return this_.exec("relaxNgValidate", {filename});
}

Variant Dom_XMLDocument::relaxNgValidateSource(const Variant &source) {
    return this_.exec("relaxNgValidateSource", {source});
}




Variant Dom_XMLDocument::importLegacyNode(const Variant &node, const Variant &deep) {
    return this_.exec("importLegacyNode", {node, deep});
}

Variant Dom_XMLDocument::querySelector(const Variant &selectors) {
    return this_.exec("querySelector", {selectors});
}

Variant Dom_XMLDocument::querySelectorAll(const Variant &selectors) {
    return this_.exec("querySelectorAll", {selectors});
}

Variant Dom_XMLDocument::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_XMLDocument::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_XMLDocument::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_XMLDocument::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_XMLDocument::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_XMLDocument::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_XMLDocument::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_XMLDocument::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_XMLDocument::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_XMLDocument::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_XMLDocument::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_XMLDocument::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_XMLDocument::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_XMLDocument::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_XMLDocument::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_XMLDocument::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_XMLDocument::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_XMLDocument::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_XMLDocument::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_XMLDocument::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_XMLDocument::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant DOMNodeList::count() {
    return this_.exec("count", {});
}

Variant DOMNodeList::getIterator() {
    return this_.exec("getIterator", {});
}

Variant DOMNodeList::item(const Variant &index) {
    return this_.exec("item", {index});
}


Variant Dom_NodeList::count() {
    return this_.exec("count", {});
}

Variant Dom_NodeList::getIterator() {
    return this_.exec("getIterator", {});
}

Variant Dom_NodeList::item(const Variant &index) {
    return this_.exec("item", {index});
}


Variant DOMNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    return this_.exec("getNamedItem", {qualified_name});
}

Variant DOMNamedNodeMap::getNamedItemNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getNamedItemNS", {_namespace, local_name});
}

Variant DOMNamedNodeMap::item(const Variant &index) {
    return this_.exec("item", {index});
}

Variant DOMNamedNodeMap::count() {
    return this_.exec("count", {});
}

Variant DOMNamedNodeMap::getIterator() {
    return this_.exec("getIterator", {});
}


Variant Dom_NamedNodeMap::item(const Variant &index) {
    return this_.exec("item", {index});
}

Variant Dom_NamedNodeMap::getNamedItem(const Variant &qualified_name) {
    return this_.exec("getNamedItem", {qualified_name});
}

Variant Dom_NamedNodeMap::getNamedItemNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getNamedItemNS", {_namespace, local_name});
}

Variant Dom_NamedNodeMap::count() {
    return this_.exec("count", {});
}

Variant Dom_NamedNodeMap::getIterator() {
    return this_.exec("getIterator", {});
}


Variant Dom_DtdNamedNodeMap::item(const Variant &index) {
    return this_.exec("item", {index});
}

Variant Dom_DtdNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    return this_.exec("getNamedItem", {qualified_name});
}

Variant Dom_DtdNamedNodeMap::getNamedItemNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getNamedItemNS", {_namespace, local_name});
}

Variant Dom_DtdNamedNodeMap::count() {
    return this_.exec("count", {});
}

Variant Dom_DtdNamedNodeMap::getIterator() {
    return this_.exec("getIterator", {});
}


Variant Dom_HTMLCollection::item(const Variant &index) {
    return this_.exec("item", {index});
}

Variant Dom_HTMLCollection::namedItem(const Variant &key) {
    return this_.exec("namedItem", {key});
}

Variant Dom_HTMLCollection::count() {
    return this_.exec("count", {});
}

Variant Dom_HTMLCollection::getIterator() {
    return this_.exec("getIterator", {});
}


Variant DOMCharacterData::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant DOMCharacterData::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant DOMCharacterData::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant DOMCharacterData::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant DOMCharacterData::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}


Variant DOMCharacterData::remove() {
    return this_.exec("remove", {});
}



Variant DOMCharacterData::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMCharacterData::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMCharacterData::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMCharacterData::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMCharacterData::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMCharacterData::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMCharacterData::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMCharacterData::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMCharacterData::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMCharacterData::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMCharacterData::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMCharacterData::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMCharacterData::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMCharacterData::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMCharacterData::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMCharacterData::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMCharacterData::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMCharacterData::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMCharacterData::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMCharacterData::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMCharacterData::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMCharacterData::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMCharacterData::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_CharacterData::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant Dom_CharacterData::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant Dom_CharacterData::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant Dom_CharacterData::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant Dom_CharacterData::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}

Variant Dom_CharacterData::remove() {
    return this_.exec("remove", {});
}




Variant Dom_CharacterData::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_CharacterData::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_CharacterData::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_CharacterData::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_CharacterData::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_CharacterData::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_CharacterData::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_CharacterData::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_CharacterData::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_CharacterData::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_CharacterData::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_CharacterData::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_CharacterData::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_CharacterData::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_CharacterData::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_CharacterData::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_CharacterData::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_CharacterData::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_CharacterData::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_CharacterData::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_CharacterData::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMAttr::DOMAttr(const Variant &name, const Variant &value) {
    this_ = newObject("DOMAttr", {name, value});
}

Variant DOMAttr::isId() {
    return this_.exec("isId", {});
}

Variant DOMAttr::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMAttr::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMAttr::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMAttr::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMAttr::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMAttr::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMAttr::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMAttr::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMAttr::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMAttr::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMAttr::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMAttr::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMAttr::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMAttr::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMAttr::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMAttr::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMAttr::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMAttr::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMAttr::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMAttr::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMAttr::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMAttr::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMAttr::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_Attr::isId() {
    return this_.exec("isId", {});
}

Variant Dom_Attr::rename(const Variant &namespace_u_r_i, const Variant &qualified_name) {
    return this_.exec("rename", {namespace_u_r_i, qualified_name});
}

Variant Dom_Attr::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_Attr::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_Attr::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_Attr::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_Attr::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_Attr::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_Attr::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_Attr::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_Attr::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_Attr::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_Attr::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_Attr::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_Attr::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_Attr::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_Attr::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_Attr::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_Attr::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_Attr::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Attr::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Attr::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_Attr::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMElement::DOMElement(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    this_ = newObject("DOMElement", {qualified_name, value, _namespace});
}

Variant DOMElement::getAttribute(const Variant &qualified_name) {
    return this_.exec("getAttribute", {qualified_name});
}

Variant DOMElement::getAttributeNames() {
    return this_.exec("getAttributeNames", {});
}

Variant DOMElement::getAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getAttributeNS", {_namespace, local_name});
}

Variant DOMElement::getAttributeNode(const Variant &qualified_name) {
    return this_.exec("getAttributeNode", {qualified_name});
}

Variant DOMElement::getAttributeNodeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getAttributeNodeNS", {_namespace, local_name});
}

Variant DOMElement::getElementsByTagName(const Variant &qualified_name) {
    return this_.exec("getElementsByTagName", {qualified_name});
}

Variant DOMElement::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getElementsByTagNameNS", {_namespace, local_name});
}

Variant DOMElement::hasAttribute(const Variant &qualified_name) {
    return this_.exec("hasAttribute", {qualified_name});
}

Variant DOMElement::hasAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("hasAttributeNS", {_namespace, local_name});
}

Variant DOMElement::removeAttribute(const Variant &qualified_name) {
    return this_.exec("removeAttribute", {qualified_name});
}

Variant DOMElement::removeAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("removeAttributeNS", {_namespace, local_name});
}

Variant DOMElement::removeAttributeNode(const Variant &attr) {
    return this_.exec("removeAttributeNode", {attr});
}

Variant DOMElement::setAttribute(const Variant &qualified_name, const Variant &value) {
    return this_.exec("setAttribute", {qualified_name, value});
}

Variant DOMElement::setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    return this_.exec("setAttributeNS", {_namespace, qualified_name, value});
}

Variant DOMElement::setAttributeNode(const Variant &attr) {
    return this_.exec("setAttributeNode", {attr});
}

Variant DOMElement::setAttributeNodeNS(const Variant &attr) {
    return this_.exec("setAttributeNodeNS", {attr});
}

Variant DOMElement::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    return this_.exec("setIdAttribute", {qualified_name, is_id});
}

Variant DOMElement::setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id) {
    return this_.exec("setIdAttributeNS", {_namespace, qualified_name, is_id});
}

Variant DOMElement::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    return this_.exec("setIdAttributeNode", {attr, is_id});
}

Variant DOMElement::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    return this_.exec("toggleAttribute", {qualified_name, force});
}

Variant DOMElement::remove() {
    return this_.exec("remove", {});
}







Variant DOMElement::insertAdjacentElement(const Variant &where, const Variant &element) {
    return this_.exec("insertAdjacentElement", {where, element});
}

Variant DOMElement::insertAdjacentText(const Variant &where, const Variant &data) {
    return this_.exec("insertAdjacentText", {where, data});
}

Variant DOMElement::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMElement::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMElement::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMElement::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMElement::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMElement::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMElement::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMElement::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMElement::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMElement::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMElement::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMElement::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMElement::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMElement::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMElement::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMElement::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMElement::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMElement::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMElement::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMElement::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMElement::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMElement::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMElement::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_Element::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant Dom_Element::getAttributeNames() {
    return this_.exec("getAttributeNames", {});
}

Variant Dom_Element::getAttribute(const Variant &qualified_name) {
    return this_.exec("getAttribute", {qualified_name});
}

Variant Dom_Element::getAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getAttributeNS", {_namespace, local_name});
}

Variant Dom_Element::setAttribute(const Variant &qualified_name, const Variant &value) {
    return this_.exec("setAttribute", {qualified_name, value});
}

Variant Dom_Element::setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    return this_.exec("setAttributeNS", {_namespace, qualified_name, value});
}

Variant Dom_Element::removeAttribute(const Variant &qualified_name) {
    return this_.exec("removeAttribute", {qualified_name});
}

Variant Dom_Element::removeAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("removeAttributeNS", {_namespace, local_name});
}

Variant Dom_Element::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    return this_.exec("toggleAttribute", {qualified_name, force});
}

Variant Dom_Element::hasAttribute(const Variant &qualified_name) {
    return this_.exec("hasAttribute", {qualified_name});
}

Variant Dom_Element::hasAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("hasAttributeNS", {_namespace, local_name});
}

Variant Dom_Element::getAttributeNode(const Variant &qualified_name) {
    return this_.exec("getAttributeNode", {qualified_name});
}

Variant Dom_Element::getAttributeNodeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getAttributeNodeNS", {_namespace, local_name});
}

Variant Dom_Element::setAttributeNode(const Variant &attr) {
    return this_.exec("setAttributeNode", {attr});
}

Variant Dom_Element::setAttributeNodeNS(const Variant &attr) {
    return this_.exec("setAttributeNodeNS", {attr});
}

Variant Dom_Element::removeAttributeNode(const Variant &attr) {
    return this_.exec("removeAttributeNode", {attr});
}

Variant Dom_Element::getElementsByTagName(const Variant &qualified_name) {
    return this_.exec("getElementsByTagName", {qualified_name});
}

Variant Dom_Element::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getElementsByTagNameNS", {_namespace, local_name});
}

Variant Dom_Element::insertAdjacentElement(const Variant &where, const Variant &element) {
    return this_.exec("insertAdjacentElement", {where, element});
}

Variant Dom_Element::insertAdjacentText(const Variant &where, const Variant &data) {
    return this_.exec("insertAdjacentText", {where, data});
}

Variant Dom_Element::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    return this_.exec("setIdAttribute", {qualified_name, is_id});
}

Variant Dom_Element::setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id) {
    return this_.exec("setIdAttributeNS", {_namespace, qualified_name, is_id});
}

Variant Dom_Element::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    return this_.exec("setIdAttributeNode", {attr, is_id});
}

Variant Dom_Element::remove() {
    return this_.exec("remove", {});
}







Variant Dom_Element::querySelector(const Variant &selectors) {
    return this_.exec("querySelector", {selectors});
}

Variant Dom_Element::querySelectorAll(const Variant &selectors) {
    return this_.exec("querySelectorAll", {selectors});
}

Variant Dom_Element::closest(const Variant &selectors) {
    return this_.exec("closest", {selectors});
}

Variant Dom_Element::matches(const Variant &selectors) {
    return this_.exec("matches", {selectors});
}

Variant Dom_Element::getInScopeNamespaces() {
    return this_.exec("getInScopeNamespaces", {});
}

Variant Dom_Element::getDescendantNamespaces() {
    return this_.exec("getDescendantNamespaces", {});
}

Variant Dom_Element::rename(const Variant &namespace_u_r_i, const Variant &qualified_name) {
    return this_.exec("rename", {namespace_u_r_i, qualified_name});
}

Variant Dom_Element::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_Element::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_Element::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_Element::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_Element::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_Element::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_Element::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_Element::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_Element::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_Element::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_Element::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_Element::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_Element::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_Element::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_Element::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_Element::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_Element::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_Element::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Element::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Element::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_Element::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_HTMLElement::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant Dom_HTMLElement::getAttributeNames() {
    return this_.exec("getAttributeNames", {});
}

Variant Dom_HTMLElement::getAttribute(const Variant &qualified_name) {
    return this_.exec("getAttribute", {qualified_name});
}

Variant Dom_HTMLElement::getAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getAttributeNS", {_namespace, local_name});
}

Variant Dom_HTMLElement::setAttribute(const Variant &qualified_name, const Variant &value) {
    return this_.exec("setAttribute", {qualified_name, value});
}

Variant Dom_HTMLElement::setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    return this_.exec("setAttributeNS", {_namespace, qualified_name, value});
}

Variant Dom_HTMLElement::removeAttribute(const Variant &qualified_name) {
    return this_.exec("removeAttribute", {qualified_name});
}

Variant Dom_HTMLElement::removeAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("removeAttributeNS", {_namespace, local_name});
}

Variant Dom_HTMLElement::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    return this_.exec("toggleAttribute", {qualified_name, force});
}

Variant Dom_HTMLElement::hasAttribute(const Variant &qualified_name) {
    return this_.exec("hasAttribute", {qualified_name});
}

Variant Dom_HTMLElement::hasAttributeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("hasAttributeNS", {_namespace, local_name});
}

Variant Dom_HTMLElement::getAttributeNode(const Variant &qualified_name) {
    return this_.exec("getAttributeNode", {qualified_name});
}

Variant Dom_HTMLElement::getAttributeNodeNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getAttributeNodeNS", {_namespace, local_name});
}

Variant Dom_HTMLElement::setAttributeNode(const Variant &attr) {
    return this_.exec("setAttributeNode", {attr});
}

Variant Dom_HTMLElement::setAttributeNodeNS(const Variant &attr) {
    return this_.exec("setAttributeNodeNS", {attr});
}

Variant Dom_HTMLElement::removeAttributeNode(const Variant &attr) {
    return this_.exec("removeAttributeNode", {attr});
}

Variant Dom_HTMLElement::getElementsByTagName(const Variant &qualified_name) {
    return this_.exec("getElementsByTagName", {qualified_name});
}

Variant Dom_HTMLElement::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    return this_.exec("getElementsByTagNameNS", {_namespace, local_name});
}

Variant Dom_HTMLElement::insertAdjacentElement(const Variant &where, const Variant &element) {
    return this_.exec("insertAdjacentElement", {where, element});
}

Variant Dom_HTMLElement::insertAdjacentText(const Variant &where, const Variant &data) {
    return this_.exec("insertAdjacentText", {where, data});
}

Variant Dom_HTMLElement::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    return this_.exec("setIdAttribute", {qualified_name, is_id});
}

Variant Dom_HTMLElement::setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id) {
    return this_.exec("setIdAttributeNS", {_namespace, qualified_name, is_id});
}

Variant Dom_HTMLElement::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    return this_.exec("setIdAttributeNode", {attr, is_id});
}

Variant Dom_HTMLElement::remove() {
    return this_.exec("remove", {});
}







Variant Dom_HTMLElement::querySelector(const Variant &selectors) {
    return this_.exec("querySelector", {selectors});
}

Variant Dom_HTMLElement::querySelectorAll(const Variant &selectors) {
    return this_.exec("querySelectorAll", {selectors});
}

Variant Dom_HTMLElement::closest(const Variant &selectors) {
    return this_.exec("closest", {selectors});
}

Variant Dom_HTMLElement::matches(const Variant &selectors) {
    return this_.exec("matches", {selectors});
}

Variant Dom_HTMLElement::getInScopeNamespaces() {
    return this_.exec("getInScopeNamespaces", {});
}

Variant Dom_HTMLElement::getDescendantNamespaces() {
    return this_.exec("getDescendantNamespaces", {});
}

Variant Dom_HTMLElement::rename(const Variant &namespace_u_r_i, const Variant &qualified_name) {
    return this_.exec("rename", {namespace_u_r_i, qualified_name});
}

Variant Dom_HTMLElement::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_HTMLElement::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_HTMLElement::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_HTMLElement::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_HTMLElement::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_HTMLElement::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_HTMLElement::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_HTMLElement::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_HTMLElement::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_HTMLElement::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_HTMLElement::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_HTMLElement::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_HTMLElement::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_HTMLElement::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_HTMLElement::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_HTMLElement::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_HTMLElement::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_HTMLElement::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_HTMLElement::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_HTMLElement::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_HTMLElement::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMText::DOMText(const Variant &data) {
    this_ = newObject("DOMText", {data});
}

Variant DOMText::isWhitespaceInElementContent() {
    return this_.exec("isWhitespaceInElementContent", {});
}

Variant DOMText::isElementContentWhitespace() {
    return this_.exec("isElementContentWhitespace", {});
}

Variant DOMText::splitText(const Variant &offset) {
    return this_.exec("splitText", {offset});
}

Variant DOMText::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant DOMText::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant DOMText::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant DOMText::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant DOMText::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}


Variant DOMText::remove() {
    return this_.exec("remove", {});
}



Variant DOMText::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMText::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMText::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMText::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMText::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMText::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMText::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMText::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMText::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMText::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMText::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMText::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMText::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMText::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMText::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMText::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMText::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMText::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMText::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMText::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMText::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMText::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMText::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_Text::splitText(const Variant &offset) {
    return this_.exec("splitText", {offset});
}

Variant Dom_Text::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant Dom_Text::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant Dom_Text::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant Dom_Text::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant Dom_Text::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}

Variant Dom_Text::remove() {
    return this_.exec("remove", {});
}




Variant Dom_Text::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_Text::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_Text::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_Text::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_Text::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_Text::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_Text::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_Text::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_Text::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_Text::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_Text::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_Text::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_Text::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_Text::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_Text::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_Text::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_Text::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_Text::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Text::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Text::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_Text::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMComment::DOMComment(const Variant &data) {
    this_ = newObject("DOMComment", {data});
}

Variant DOMComment::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant DOMComment::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant DOMComment::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant DOMComment::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant DOMComment::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}


Variant DOMComment::remove() {
    return this_.exec("remove", {});
}



Variant DOMComment::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMComment::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMComment::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMComment::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMComment::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMComment::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMComment::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMComment::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMComment::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMComment::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMComment::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMComment::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMComment::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMComment::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMComment::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMComment::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMComment::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMComment::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMComment::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMComment::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMComment::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMComment::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMComment::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_Comment::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant Dom_Comment::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant Dom_Comment::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant Dom_Comment::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant Dom_Comment::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}

Variant Dom_Comment::remove() {
    return this_.exec("remove", {});
}




Variant Dom_Comment::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_Comment::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_Comment::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_Comment::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_Comment::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_Comment::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_Comment::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_Comment::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_Comment::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_Comment::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_Comment::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_Comment::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_Comment::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_Comment::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_Comment::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_Comment::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_Comment::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_Comment::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Comment::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Comment::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_Comment::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMCdataSection::DOMCdataSection(const Variant &data) {
    this_ = newObject("DOMCdataSection", {data});
}

Variant DOMCdataSection::isWhitespaceInElementContent() {
    return this_.exec("isWhitespaceInElementContent", {});
}

Variant DOMCdataSection::isElementContentWhitespace() {
    return this_.exec("isElementContentWhitespace", {});
}

Variant DOMCdataSection::splitText(const Variant &offset) {
    return this_.exec("splitText", {offset});
}

Variant DOMCdataSection::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant DOMCdataSection::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant DOMCdataSection::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant DOMCdataSection::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant DOMCdataSection::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}


Variant DOMCdataSection::remove() {
    return this_.exec("remove", {});
}



Variant DOMCdataSection::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMCdataSection::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMCdataSection::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMCdataSection::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMCdataSection::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMCdataSection::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMCdataSection::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMCdataSection::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMCdataSection::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMCdataSection::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMCdataSection::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMCdataSection::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMCdataSection::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMCdataSection::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMCdataSection::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMCdataSection::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMCdataSection::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMCdataSection::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMCdataSection::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMCdataSection::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMCdataSection::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMCdataSection::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMCdataSection::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_CDATASection::splitText(const Variant &offset) {
    return this_.exec("splitText", {offset});
}

Variant Dom_CDATASection::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant Dom_CDATASection::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant Dom_CDATASection::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant Dom_CDATASection::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant Dom_CDATASection::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}

Variant Dom_CDATASection::remove() {
    return this_.exec("remove", {});
}




Variant Dom_CDATASection::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_CDATASection::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_CDATASection::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_CDATASection::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_CDATASection::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_CDATASection::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_CDATASection::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_CDATASection::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_CDATASection::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_CDATASection::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_CDATASection::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_CDATASection::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_CDATASection::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_CDATASection::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_CDATASection::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_CDATASection::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_CDATASection::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_CDATASection::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_CDATASection::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_CDATASection::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_CDATASection::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant DOMDocumentType::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMDocumentType::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMDocumentType::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMDocumentType::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMDocumentType::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMDocumentType::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMDocumentType::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMDocumentType::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMDocumentType::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMDocumentType::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMDocumentType::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMDocumentType::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMDocumentType::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMDocumentType::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMDocumentType::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMDocumentType::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMDocumentType::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMDocumentType::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMDocumentType::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMDocumentType::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMDocumentType::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMDocumentType::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMDocumentType::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_DocumentType::remove() {
    return this_.exec("remove", {});
}




Variant Dom_DocumentType::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_DocumentType::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_DocumentType::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_DocumentType::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_DocumentType::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_DocumentType::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_DocumentType::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_DocumentType::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_DocumentType::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_DocumentType::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_DocumentType::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_DocumentType::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_DocumentType::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_DocumentType::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_DocumentType::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_DocumentType::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_DocumentType::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_DocumentType::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_DocumentType::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_DocumentType::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_DocumentType::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant DOMNotation::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMNotation::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMNotation::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMNotation::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMNotation::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMNotation::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMNotation::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMNotation::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMNotation::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMNotation::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMNotation::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMNotation::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMNotation::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMNotation::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMNotation::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMNotation::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMNotation::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMNotation::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMNotation::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMNotation::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMNotation::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMNotation::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMNotation::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_Notation::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_Notation::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_Notation::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_Notation::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_Notation::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_Notation::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_Notation::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_Notation::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_Notation::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_Notation::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_Notation::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_Notation::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_Notation::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_Notation::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_Notation::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_Notation::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_Notation::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_Notation::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Notation::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Notation::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_Notation::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant DOMEntity::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMEntity::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMEntity::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMEntity::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMEntity::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMEntity::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMEntity::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMEntity::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMEntity::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMEntity::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMEntity::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMEntity::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMEntity::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMEntity::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMEntity::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMEntity::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMEntity::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMEntity::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMEntity::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMEntity::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMEntity::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMEntity::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMEntity::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_Entity::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_Entity::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_Entity::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_Entity::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_Entity::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_Entity::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_Entity::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_Entity::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_Entity::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_Entity::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_Entity::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_Entity::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_Entity::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_Entity::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_Entity::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_Entity::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_Entity::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_Entity::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Entity::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_Entity::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_Entity::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMEntityReference::DOMEntityReference(const Variant &name) {
    this_ = newObject("DOMEntityReference", {name});
}

Variant DOMEntityReference::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMEntityReference::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMEntityReference::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMEntityReference::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMEntityReference::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMEntityReference::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMEntityReference::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMEntityReference::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMEntityReference::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMEntityReference::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMEntityReference::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMEntityReference::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMEntityReference::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMEntityReference::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMEntityReference::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMEntityReference::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMEntityReference::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMEntityReference::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMEntityReference::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMEntityReference::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMEntityReference::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMEntityReference::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMEntityReference::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_EntityReference::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_EntityReference::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_EntityReference::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_EntityReference::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_EntityReference::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_EntityReference::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_EntityReference::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_EntityReference::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_EntityReference::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_EntityReference::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_EntityReference::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_EntityReference::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_EntityReference::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_EntityReference::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_EntityReference::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_EntityReference::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_EntityReference::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_EntityReference::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_EntityReference::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_EntityReference::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_EntityReference::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMProcessingInstruction::DOMProcessingInstruction(const Variant &name, const Variant &value) {
    this_ = newObject("DOMProcessingInstruction", {name, value});
}

Variant DOMProcessingInstruction::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant DOMProcessingInstruction::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMProcessingInstruction::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant DOMProcessingInstruction::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant DOMProcessingInstruction::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant DOMProcessingInstruction::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant DOMProcessingInstruction::hasAttributes() {
    return this_.exec("hasAttributes", {});
}

Variant DOMProcessingInstruction::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant DOMProcessingInstruction::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant DOMProcessingInstruction::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant DOMProcessingInstruction::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant DOMProcessingInstruction::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant DOMProcessingInstruction::isSupported(const Variant &feature, const Variant &version) {
    return this_.exec("isSupported", {feature, version});
}

Variant DOMProcessingInstruction::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant DOMProcessingInstruction::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant DOMProcessingInstruction::normalize() {
    return this_.exec("normalize", {});
}

Variant DOMProcessingInstruction::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant DOMProcessingInstruction::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant DOMProcessingInstruction::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant DOMProcessingInstruction::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant DOMProcessingInstruction::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant DOMProcessingInstruction::__sleep() {
    return this_.exec("__sleep", {});
}

Variant DOMProcessingInstruction::__wakeup() {
    return this_.exec("__wakeup", {});
}


Variant Dom_ProcessingInstruction::substringData(const Variant &offset, const Variant &count) {
    return this_.exec("substringData", {offset, count});
}

Variant Dom_ProcessingInstruction::appendData(const Variant &data) {
    return this_.exec("appendData", {data});
}

Variant Dom_ProcessingInstruction::insertData(const Variant &offset, const Variant &data) {
    return this_.exec("insertData", {offset, data});
}

Variant Dom_ProcessingInstruction::deleteData(const Variant &offset, const Variant &count) {
    return this_.exec("deleteData", {offset, count});
}

Variant Dom_ProcessingInstruction::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    return this_.exec("replaceData", {offset, count, data});
}

Variant Dom_ProcessingInstruction::remove() {
    return this_.exec("remove", {});
}




Variant Dom_ProcessingInstruction::getRootNode(const Variant &options) {
    return this_.exec("getRootNode", {options});
}

Variant Dom_ProcessingInstruction::hasChildNodes() {
    return this_.exec("hasChildNodes", {});
}

Variant Dom_ProcessingInstruction::normalize() {
    return this_.exec("normalize", {});
}

Variant Dom_ProcessingInstruction::cloneNode(const Variant &deep) {
    return this_.exec("cloneNode", {deep});
}

Variant Dom_ProcessingInstruction::isEqualNode(const Variant &other_node) {
    return this_.exec("isEqualNode", {other_node});
}

Variant Dom_ProcessingInstruction::isSameNode(const Variant &other_node) {
    return this_.exec("isSameNode", {other_node});
}

Variant Dom_ProcessingInstruction::compareDocumentPosition(const Variant &other) {
    return this_.exec("compareDocumentPosition", {other});
}

Variant Dom_ProcessingInstruction::contains(const Variant &other) {
    return this_.exec("contains", {other});
}

Variant Dom_ProcessingInstruction::lookupPrefix(const Variant &_namespace) {
    return this_.exec("lookupPrefix", {_namespace});
}

Variant Dom_ProcessingInstruction::lookupNamespaceURI(const Variant &prefix) {
    return this_.exec("lookupNamespaceURI", {prefix});
}

Variant Dom_ProcessingInstruction::isDefaultNamespace(const Variant &_namespace) {
    return this_.exec("isDefaultNamespace", {_namespace});
}

Variant Dom_ProcessingInstruction::insertBefore(const Variant &node, const Variant &child) {
    return this_.exec("insertBefore", {node, child});
}

Variant Dom_ProcessingInstruction::appendChild(const Variant &node) {
    return this_.exec("appendChild", {node});
}

Variant Dom_ProcessingInstruction::replaceChild(const Variant &node, const Variant &child) {
    return this_.exec("replaceChild", {node, child});
}

Variant Dom_ProcessingInstruction::removeChild(const Variant &child) {
    return this_.exec("removeChild", {child});
}

Variant Dom_ProcessingInstruction::getLineNo() {
    return this_.exec("getLineNo", {});
}

Variant Dom_ProcessingInstruction::getNodePath() {
    return this_.exec("getNodePath", {});
}

Variant Dom_ProcessingInstruction::C14N(const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14N", {exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_ProcessingInstruction::C14NFile(const Variant &uri, const Variant &exclusive, const Variant &with_comments, const Variant &xpath, const Variant &ns_prefixes) {
    return this_.exec("C14NFile", {uri, exclusive, with_comments, xpath, ns_prefixes});
}

Variant Dom_ProcessingInstruction::__sleep() {
    return this_.exec("__sleep", {});
}

Variant Dom_ProcessingInstruction::__wakeup() {
    return this_.exec("__wakeup", {});
}


DOMXPath::DOMXPath(const Variant &document, const Variant &register_node_n_s) {
    this_ = newObject("DOMXPath", {document, register_node_n_s});
}

Variant DOMXPath::evaluate(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    return this_.exec("evaluate", {expression, context_node, register_node_n_s});
}

Variant DOMXPath::query(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    return this_.exec("query", {expression, context_node, register_node_n_s});
}

Variant DOMXPath::registerNamespace(const Variant &prefix, const Variant &_namespace) {
    return this_.exec("registerNamespace", {prefix, _namespace});
}

Variant DOMXPath::registerPhpFunctions(const Variant &restrict) {
    return this_.exec("registerPhpFunctions", {restrict});
}

Variant DOMXPath::registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable) {
    return this_.exec("registerPhpFunctionNS", {namespace_u_r_i, name, callable});
}

Variant DOMXPath::quote(const Variant &str) {
    static Variant fn { ZEND_STRL("DOMXPath::quote"), true };
    return fn({str});
}


Dom_XPath::Dom_XPath(const Variant &document, const Variant &register_node_n_s) {
    this_ = newObject("Dom\\XPath", {document, register_node_n_s});
}

Variant Dom_XPath::evaluate(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    return this_.exec("evaluate", {expression, context_node, register_node_n_s});
}

Variant Dom_XPath::query(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    return this_.exec("query", {expression, context_node, register_node_n_s});
}

Variant Dom_XPath::registerNamespace(const Variant &prefix, const Variant &_namespace) {
    return this_.exec("registerNamespace", {prefix, _namespace});
}

Variant Dom_XPath::registerPhpFunctions(const Variant &restrict) {
    return this_.exec("registerPhpFunctions", {restrict});
}

Variant Dom_XPath::registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable) {
    return this_.exec("registerPhpFunctionNS", {namespace_u_r_i, name, callable});
}

Variant Dom_XPath::quote(const Variant &str) {
    static Variant fn { ZEND_STRL("Dom_XPath::quote"), true };
    return fn({str});
}


Variant Dom_TokenList::item(const Variant &index) {
    return this_.exec("item", {index});
}

Variant Dom_TokenList::contains(const Variant &token) {
    return this_.exec("contains", {token});
}



Variant Dom_TokenList::toggle(const Variant &token, const Variant &force) {
    return this_.exec("toggle", {token, force});
}

Variant Dom_TokenList::replace(const Variant &token, const Variant &new_token) {
    return this_.exec("replace", {token, new_token});
}

Variant Dom_TokenList::supports(const Variant &token) {
    return this_.exec("supports", {token});
}

Variant Dom_TokenList::count() {
    return this_.exec("count", {});
}

Variant Dom_TokenList::getIterator() {
    return this_.exec("getIterator", {});
}


}

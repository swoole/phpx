#include "phpx.h"
#include "class/dom.h"

namespace php {
Dom_AdjacentPosition::Dom_AdjacentPosition() {
    this_ = newObject(LITERAL_STRING[331]);
}
Variant Dom_AdjacentPosition::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[333], LITERAL_STRING[334]);
    }
    return php::call(_method_fn, {});
}
Variant Dom_AdjacentPosition::from(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[333], LITERAL_STRING[336]);
    }
    return php::call(_method_fn, {value});
}
Variant Dom_AdjacentPosition::tryFrom(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[333], LITERAL_STRING[338]);
    }
    return php::call(_method_fn, {value});
}
DOMException::DOMException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[339], {message, code, previous});
}
Variant DOMException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
dom_domexception::dom_domexception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[339], {message, code, previous});
}
Variant dom_domexception::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant dom_domexception::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant dom_domexception::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant dom_domexception::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant dom_domexception::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant dom_domexception::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant dom_domexception::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant dom_domexception::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant dom_domexception::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
DOMImplementation::DOMImplementation() {
    this_ = newObject(LITERAL_STRING[340]);
}
Variant DOMImplementation::hasFeature(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[341]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMImplementation::createDocumentType(const Variant &qualified_name,
                                              const Variant &public_id,
                                              const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[342]);
    }
    return this_.call(_method_fn, {qualified_name, public_id, system_id});
}
Variant DOMImplementation::createDocument(const Variant &_namespace,
                                          const Variant &qualified_name,
                                          const Variant &doctype) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[343]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, doctype});
}
Dom_Implementation::Dom_Implementation() {
    this_ = newObject(LITERAL_STRING[344]);
}
Variant Dom_Implementation::createDocumentType(const Variant &qualified_name,
                                               const Variant &public_id,
                                               const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[342]);
    }
    return this_.call(_method_fn, {qualified_name, public_id, system_id});
}
Variant Dom_Implementation::createDocument(const Variant &_namespace,
                                           const Variant &qualified_name,
                                           const Variant &doctype) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[343]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, doctype});
}
Variant Dom_Implementation::createHTMLDocument(const Variant &title) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[345]);
    }
    return this_.call(_method_fn, {title});
}
DOMNode::DOMNode() {
    this_ = newObject(LITERAL_STRING[346]);
}
Variant DOMNode::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMNode::C14N(const Variant &exclusive,
                      const Variant &with_comments,
                      const Variant &xpath,
                      const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMNode::C14NFile(const Variant &uri,
                          const Variant &exclusive,
                          const Variant &with_comments,
                          const Variant &xpath,
                          const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMNode::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMNode::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMNode::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMNode::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMNode::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMNode::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMNode::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMNode::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMNode::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMNode::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMNode::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMNode::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMNode::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMNode::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Node::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_Node::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Node::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Node::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_Node::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Node::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Node::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Node::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Node::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Node::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_Node::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Node::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Node::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_Node::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Node::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_Node::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Node::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Node::C14N(const Variant &exclusive,
                       const Variant &with_comments,
                       const Variant &xpath,
                       const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Node::C14NFile(const Variant &uri,
                           const Variant &exclusive,
                           const Variant &with_comments,
                           const Variant &xpath,
                           const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Node::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Node::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMNameSpaceNode::DOMNameSpaceNode() {
    this_ = newObject(LITERAL_STRING[370]);
}
Variant DOMNameSpaceNode::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNameSpaceNode::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMDocumentFragment::DOMDocumentFragment() {
    this_ = newObject(LITERAL_STRING[371], {});
}
Variant DOMDocumentFragment::appendXML(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMDocumentFragment::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMDocumentFragment::C14N(const Variant &exclusive,
                                  const Variant &with_comments,
                                  const Variant &xpath,
                                  const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMDocumentFragment::C14NFile(const Variant &uri,
                                      const Variant &exclusive,
                                      const Variant &with_comments,
                                      const Variant &xpath,
                                      const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMDocumentFragment::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMDocumentFragment::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentFragment::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentFragment::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentFragment::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentFragment::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMDocumentFragment::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMDocumentFragment::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMDocumentFragment::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMDocumentFragment::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMDocumentFragment::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMDocumentFragment::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMDocumentFragment::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentFragment::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMDocumentFragment::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMDocumentFragment::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMDocumentFragment::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMDocumentFragment::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMDocumentFragment::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentFragment::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_DocumentFragment::Dom_DocumentFragment() {
    this_ = newObject(LITERAL_STRING[376]);
}
Variant Dom_DocumentFragment::appendXml(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[377]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_DocumentFragment::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_DocumentFragment::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_DocumentFragment::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_DocumentFragment::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentFragment::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentFragment::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_DocumentFragment::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_DocumentFragment::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_DocumentFragment::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_DocumentFragment::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_DocumentFragment::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_DocumentFragment::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_DocumentFragment::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_DocumentFragment::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_DocumentFragment::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_DocumentFragment::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_DocumentFragment::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_DocumentFragment::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentFragment::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentFragment::C14N(const Variant &exclusive,
                                   const Variant &with_comments,
                                   const Variant &xpath,
                                   const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_DocumentFragment::C14NFile(const Variant &uri,
                                       const Variant &exclusive,
                                       const Variant &with_comments,
                                       const Variant &xpath,
                                       const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_DocumentFragment::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentFragment::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMDocument::DOMDocument(const Variant &version, const Variant &encoding) {
    this_ = newObject(LITERAL_STRING[380], {version, encoding});
}
Variant DOMDocument::createAttribute(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant DOMDocument::createAttributeNS(const Variant &_namespace, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name});
}
Variant DOMDocument::createCDATASection(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMDocument::createComment(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMDocument::createDocumentFragment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::createElement(const Variant &local_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[386]);
    }
    return this_.call(_method_fn, {local_name, value});
}
Variant DOMDocument::createElementNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, value});
}
Variant DOMDocument::createEntityReference(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[388]);
    }
    return this_.call(_method_fn, {name});
}
Variant DOMDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return this_.call(_method_fn, {target, data});
}
Variant DOMDocument::createTextNode(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMDocument::getElementById(const Variant &element_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {element_id});
}
Variant DOMDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMDocument::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant DOMDocument::importNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant DOMDocument::load(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[395]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant DOMDocument::loadXML(const Variant &source, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[396]);
    }
    return this_.call(_method_fn, {source, options});
}
Variant DOMDocument::normalizeDocument() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[397]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[398]);
    }
    return this_.call(_method_fn, {base_class, extended_class});
}
Variant DOMDocument::save(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[399]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant DOMDocument::loadHTML(const Variant &source, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[400]);
    }
    return this_.call(_method_fn, {source, options});
}
Variant DOMDocument::loadHTMLFile(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[401]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant DOMDocument::saveHTML(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[402]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMDocument::saveHTMLFile(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[403]);
    }
    return this_.call(_method_fn, {filename});
}
Variant DOMDocument::saveXML(const Variant &node, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[404]);
    }
    return this_.call(_method_fn, {node, options});
}
Variant DOMDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[405]);
    }
    return this_.call(_method_fn, {filename, flags});
}
Variant DOMDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[406]);
    }
    return this_.call(_method_fn, {source, flags});
}
Variant DOMDocument::relaxNGValidate(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[407]);
    }
    return this_.call(_method_fn, {filename});
}
Variant DOMDocument::relaxNGValidateSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[408]);
    }
    return this_.call(_method_fn, {source});
}
Variant DOMDocument::validate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[409]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::xinclude(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[410]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMDocument::adoptNode(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMDocument::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMDocument::C14N(const Variant &exclusive,
                          const Variant &with_comments,
                          const Variant &xpath,
                          const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMDocument::C14NFile(const Variant &uri,
                              const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMDocument::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMDocument::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMDocument::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMDocument::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMDocument::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMDocument::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMDocument::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMDocument::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMDocument::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMDocument::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMDocument::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMDocument::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMDocument::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMDocument::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_HTMLDocument::Dom_HTMLDocument() {
    this_ = newObject(LITERAL_STRING[412]);
}
Variant Dom_HTMLDocument::createEmpty(const Variant &encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[414], LITERAL_STRING[415]);
    }
    return php::call(_method_fn, {encoding});
}
Variant Dom_HTMLDocument::createFromFile(const Variant &path,
                                         const Variant &options,
                                         const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[414], LITERAL_STRING[417]);
    }
    return php::call(_method_fn, {path, options, override_encoding});
}
Variant Dom_HTMLDocument::createFromString(const Variant &source,
                                           const Variant &options,
                                           const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[414], LITERAL_STRING[419]);
    }
    return php::call(_method_fn, {source, options, override_encoding});
}
Variant Dom_HTMLDocument::saveXml(const Variant &node, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[420]);
    }
    return this_.call(_method_fn, {node, options});
}
Variant Dom_HTMLDocument::saveXmlFile(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[421]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant Dom_HTMLDocument::saveHtml(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[422]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_HTMLDocument::saveHtmlFile(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[423]);
    }
    return this_.call(_method_fn, {filename});
}
Variant Dom_HTMLDocument::debugGetTemplateCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[424]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_HTMLDocument::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_HTMLDocument::createElement(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[386]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Dom_HTMLDocument::createElementNS(const Variant &_namespace, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name});
}
Variant Dom_HTMLDocument::createDocumentFragment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLDocument::createTextNode(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_HTMLDocument::createCDATASection(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_HTMLDocument::createComment(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_HTMLDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return this_.call(_method_fn, {target, data});
}
Variant Dom_HTMLDocument::importNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant Dom_HTMLDocument::adoptNode(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_HTMLDocument::createAttribute(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Dom_HTMLDocument::createAttributeNS(const Variant &_namespace, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name});
}
Variant Dom_HTMLDocument::getElementById(const Variant &element_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {element_id});
}
Variant Dom_HTMLDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[398]);
    }
    return this_.call(_method_fn, {base_class, extended_class});
}
Variant Dom_HTMLDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[405]);
    }
    return this_.call(_method_fn, {filename, flags});
}
Variant Dom_HTMLDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[406]);
    }
    return this_.call(_method_fn, {source, flags});
}
Variant Dom_HTMLDocument::relaxNgValidate(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[425]);
    }
    return this_.call(_method_fn, {filename});
}
Variant Dom_HTMLDocument::relaxNgValidateSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[426]);
    }
    return this_.call(_method_fn, {source});
}
Variant Dom_HTMLDocument::importLegacyNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[427]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant Dom_HTMLDocument::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_HTMLDocument::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_HTMLDocument::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_HTMLDocument::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLDocument::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLDocument::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_HTMLDocument::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_HTMLDocument::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_HTMLDocument::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_HTMLDocument::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_HTMLDocument::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_HTMLDocument::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_HTMLDocument::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_HTMLDocument::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_HTMLDocument::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_HTMLDocument::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_HTMLDocument::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_HTMLDocument::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLDocument::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLDocument::C14N(const Variant &exclusive,
                               const Variant &with_comments,
                               const Variant &xpath,
                               const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_HTMLDocument::C14NFile(const Variant &uri,
                                   const Variant &exclusive,
                                   const Variant &with_comments,
                                   const Variant &xpath,
                                   const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_HTMLDocument::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLDocument::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_XMLDocument::Dom_XMLDocument() {
    this_ = newObject(LITERAL_STRING[428]);
}
Variant Dom_XMLDocument::createEmpty(const Variant &version, const Variant &encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[430], LITERAL_STRING[415]);
    }
    return php::call(_method_fn, {version, encoding});
}
Variant Dom_XMLDocument::createFromFile(const Variant &path, const Variant &options, const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[430], LITERAL_STRING[417]);
    }
    return php::call(_method_fn, {path, options, override_encoding});
}
Variant Dom_XMLDocument::createFromString(const Variant &source,
                                          const Variant &options,
                                          const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[430], LITERAL_STRING[419]);
    }
    return php::call(_method_fn, {source, options, override_encoding});
}
Variant Dom_XMLDocument::createEntityReference(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[388]);
    }
    return this_.call(_method_fn, {name});
}
Variant Dom_XMLDocument::validate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[409]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_XMLDocument::xinclude(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[410]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_XMLDocument::saveXml(const Variant &node, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[420]);
    }
    return this_.call(_method_fn, {node, options});
}
Variant Dom_XMLDocument::saveXmlFile(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[421]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant Dom_XMLDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_XMLDocument::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_XMLDocument::createElement(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[386]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Dom_XMLDocument::createElementNS(const Variant &_namespace, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name});
}
Variant Dom_XMLDocument::createDocumentFragment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_XMLDocument::createTextNode(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_XMLDocument::createCDATASection(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_XMLDocument::createComment(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_XMLDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return this_.call(_method_fn, {target, data});
}
Variant Dom_XMLDocument::importNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant Dom_XMLDocument::adoptNode(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_XMLDocument::createAttribute(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Dom_XMLDocument::createAttributeNS(const Variant &_namespace, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name});
}
Variant Dom_XMLDocument::getElementById(const Variant &element_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {element_id});
}
Variant Dom_XMLDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[398]);
    }
    return this_.call(_method_fn, {base_class, extended_class});
}
Variant Dom_XMLDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[405]);
    }
    return this_.call(_method_fn, {filename, flags});
}
Variant Dom_XMLDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[406]);
    }
    return this_.call(_method_fn, {source, flags});
}
Variant Dom_XMLDocument::relaxNgValidate(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[425]);
    }
    return this_.call(_method_fn, {filename});
}
Variant Dom_XMLDocument::relaxNgValidateSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[426]);
    }
    return this_.call(_method_fn, {source});
}
Variant Dom_XMLDocument::importLegacyNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[427]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant Dom_XMLDocument::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_XMLDocument::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_XMLDocument::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_XMLDocument::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_XMLDocument::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_XMLDocument::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_XMLDocument::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_XMLDocument::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_XMLDocument::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_XMLDocument::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_XMLDocument::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_XMLDocument::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_XMLDocument::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_XMLDocument::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_XMLDocument::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_XMLDocument::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_XMLDocument::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_XMLDocument::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_XMLDocument::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_XMLDocument::C14N(const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_XMLDocument::C14NFile(const Variant &uri,
                                  const Variant &exclusive,
                                  const Variant &with_comments,
                                  const Variant &xpath,
                                  const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_XMLDocument::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_XMLDocument::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMNodeList::DOMNodeList() {
    this_ = newObject(LITERAL_STRING[433]);
}
Variant DOMNodeList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNodeList::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNodeList::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return this_.call(_method_fn, {index});
}
Dom_NodeList::Dom_NodeList() {
    this_ = newObject(LITERAL_STRING[435]);
}
Variant Dom_NodeList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_NodeList::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_NodeList::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return this_.call(_method_fn, {index});
}
DOMNamedNodeMap::DOMNamedNodeMap() {
    this_ = newObject(LITERAL_STRING[436]);
}
Variant DOMNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[437]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMNamedNodeMap::getNamedItemNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant DOMNamedNodeMap::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return this_.call(_method_fn, {index});
}
Variant DOMNamedNodeMap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNamedNodeMap::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
Dom_NamedNodeMap::Dom_NamedNodeMap() {
    this_ = newObject(LITERAL_STRING[439]);
}
Variant Dom_NamedNodeMap::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return this_.call(_method_fn, {index});
}
Variant Dom_NamedNodeMap::getNamedItem(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[437]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_NamedNodeMap::getNamedItemNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_NamedNodeMap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_NamedNodeMap::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
Dom_DtdNamedNodeMap::Dom_DtdNamedNodeMap() {
    this_ = newObject(LITERAL_STRING[440]);
}
Variant Dom_DtdNamedNodeMap::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return this_.call(_method_fn, {index});
}
Variant Dom_DtdNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[437]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_DtdNamedNodeMap::getNamedItemNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_DtdNamedNodeMap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DtdNamedNodeMap::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
Dom_HTMLCollection::Dom_HTMLCollection() {
    this_ = newObject(LITERAL_STRING[441]);
}
Variant Dom_HTMLCollection::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return this_.call(_method_fn, {index});
}
Variant Dom_HTMLCollection::namedItem(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[442]);
    }
    return this_.call(_method_fn, {key});
}
Variant Dom_HTMLCollection::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLCollection::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
DOMCharacterData::DOMCharacterData() {
    this_ = newObject(LITERAL_STRING[443]);
}
Variant DOMCharacterData::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMCharacterData::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMCharacterData::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant DOMCharacterData::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMCharacterData::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant DOMCharacterData::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCharacterData::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMCharacterData::C14N(const Variant &exclusive,
                               const Variant &with_comments,
                               const Variant &xpath,
                               const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMCharacterData::C14NFile(const Variant &uri,
                                   const Variant &exclusive,
                                   const Variant &with_comments,
                                   const Variant &xpath,
                                   const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMCharacterData::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMCharacterData::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCharacterData::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCharacterData::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCharacterData::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCharacterData::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMCharacterData::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMCharacterData::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMCharacterData::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMCharacterData::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMCharacterData::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMCharacterData::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMCharacterData::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCharacterData::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMCharacterData::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMCharacterData::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMCharacterData::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMCharacterData::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMCharacterData::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCharacterData::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_CharacterData::Dom_CharacterData() {
    this_ = newObject(LITERAL_STRING[453]);
}
Variant Dom_CharacterData::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_CharacterData::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_CharacterData::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant Dom_CharacterData::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_CharacterData::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant Dom_CharacterData::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CharacterData::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_CharacterData::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CharacterData::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CharacterData::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_CharacterData::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_CharacterData::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_CharacterData::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_CharacterData::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_CharacterData::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_CharacterData::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_CharacterData::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_CharacterData::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_CharacterData::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_CharacterData::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_CharacterData::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_CharacterData::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CharacterData::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CharacterData::C14N(const Variant &exclusive,
                                const Variant &with_comments,
                                const Variant &xpath,
                                const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_CharacterData::C14NFile(const Variant &uri,
                                    const Variant &exclusive,
                                    const Variant &with_comments,
                                    const Variant &xpath,
                                    const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_CharacterData::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CharacterData::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMAttr::DOMAttr(const Variant &name, const Variant &value) {
    this_ = newObject(LITERAL_STRING[454], {name, value});
}
Variant DOMAttr::isId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[455]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMAttr::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMAttr::C14N(const Variant &exclusive,
                      const Variant &with_comments,
                      const Variant &xpath,
                      const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMAttr::C14NFile(const Variant &uri,
                          const Variant &exclusive,
                          const Variant &with_comments,
                          const Variant &xpath,
                          const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMAttr::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMAttr::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMAttr::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMAttr::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMAttr::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMAttr::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMAttr::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMAttr::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMAttr::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMAttr::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMAttr::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMAttr::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMAttr::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMAttr::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMAttr::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMAttr::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMAttr::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMAttr::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMAttr::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMAttr::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_Attr::Dom_Attr() {
    this_ = newObject(LITERAL_STRING[456]);
}
Variant Dom_Attr::isId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[455]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Attr::rename(const Variant &namespace_u_r_i, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[457]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, qualified_name});
}
Variant Dom_Attr::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_Attr::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Attr::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Attr::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_Attr::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Attr::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Attr::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Attr::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Attr::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Attr::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_Attr::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Attr::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Attr::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_Attr::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Attr::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_Attr::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Attr::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Attr::C14N(const Variant &exclusive,
                       const Variant &with_comments,
                       const Variant &xpath,
                       const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Attr::C14NFile(const Variant &uri,
                           const Variant &exclusive,
                           const Variant &with_comments,
                           const Variant &xpath,
                           const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Attr::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Attr::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMElement::DOMElement(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    this_ = newObject(LITERAL_STRING[458], {qualified_name, value, _namespace});
}
Variant DOMElement::getAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::getAttributeNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[460]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::getAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[461]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant DOMElement::getAttributeNode(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[462]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::getAttributeNodeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[463]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant DOMElement::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant DOMElement::hasAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[464]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::hasAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[465]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant DOMElement::removeAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[466]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::removeAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[467]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant DOMElement::removeAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[468]);
    }
    return this_.call(_method_fn, {attr});
}
Variant DOMElement::setAttribute(const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[469]);
    }
    return this_.call(_method_fn, {qualified_name, value});
}
Variant DOMElement::setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[470]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, value});
}
Variant DOMElement::setAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return this_.call(_method_fn, {attr});
}
Variant DOMElement::setAttributeNodeNS(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[472]);
    }
    return this_.call(_method_fn, {attr});
}
Variant DOMElement::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[473]);
    }
    return this_.call(_method_fn, {qualified_name, is_id});
}
Variant DOMElement::setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[474]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, is_id});
}
Variant DOMElement::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {attr, is_id});
}
Variant DOMElement::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[476]);
    }
    return this_.call(_method_fn, {qualified_name, force});
}
Variant DOMElement::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::insertAdjacentElement(const Variant &where, const Variant &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[477]);
    }
    return this_.call(_method_fn, {where, element});
}
Variant DOMElement::insertAdjacentText(const Variant &where, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[478]);
    }
    return this_.call(_method_fn, {where, data});
}
Variant DOMElement::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMElement::C14N(const Variant &exclusive,
                         const Variant &with_comments,
                         const Variant &xpath,
                         const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMElement::C14NFile(const Variant &uri,
                             const Variant &exclusive,
                             const Variant &with_comments,
                             const Variant &xpath,
                             const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMElement::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMElement::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMElement::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMElement::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMElement::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMElement::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMElement::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMElement::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMElement::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMElement::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMElement::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMElement::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMElement::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMElement::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_Element::Dom_Element() {
    this_ = newObject(LITERAL_STRING[479]);
}
Variant Dom_Element::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::getAttributeNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[460]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::getAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_Element::getAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[461]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_Element::setAttribute(const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[469]);
    }
    return this_.call(_method_fn, {qualified_name, value});
}
Variant Dom_Element::setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[470]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, value});
}
Variant Dom_Element::removeAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[466]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_Element::removeAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[467]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_Element::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[476]);
    }
    return this_.call(_method_fn, {qualified_name, force});
}
Variant Dom_Element::hasAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[464]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_Element::hasAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[465]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_Element::getAttributeNode(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[462]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_Element::getAttributeNodeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[463]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_Element::setAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return this_.call(_method_fn, {attr});
}
Variant Dom_Element::setAttributeNodeNS(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[472]);
    }
    return this_.call(_method_fn, {attr});
}
Variant Dom_Element::removeAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[468]);
    }
    return this_.call(_method_fn, {attr});
}
Variant Dom_Element::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_Element::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_Element::insertAdjacentElement(const Variant &where, const Variant &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[477]);
    }
    return this_.call(_method_fn, {where, element});
}
Variant Dom_Element::insertAdjacentText(const Variant &where, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[478]);
    }
    return this_.call(_method_fn, {where, data});
}
Variant Dom_Element::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[473]);
    }
    return this_.call(_method_fn, {qualified_name, is_id});
}
Variant Dom_Element::setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[474]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, is_id});
}
Variant Dom_Element::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {attr, is_id});
}
Variant Dom_Element::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_Element::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_Element::closest(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[480]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_Element::matches(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[481]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_Element::getInScopeNamespaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[482]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::getDescendantNamespaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[483]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::rename(const Variant &namespace_u_r_i, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[457]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, qualified_name});
}
Variant Dom_Element::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_Element::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_Element::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Element::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Element::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Element::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Element::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Element::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_Element::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Element::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Element::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_Element::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Element::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_Element::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::C14N(const Variant &exclusive,
                          const Variant &with_comments,
                          const Variant &xpath,
                          const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Element::C14NFile(const Variant &uri,
                              const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Element::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Element::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_HTMLElement::Dom_HTMLElement() {
    this_ = newObject(LITERAL_STRING[484]);
}
Variant Dom_HTMLElement::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::getAttributeNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[460]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::getAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_HTMLElement::getAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[461]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_HTMLElement::setAttribute(const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[469]);
    }
    return this_.call(_method_fn, {qualified_name, value});
}
Variant Dom_HTMLElement::setAttributeNS(const Variant &_namespace,
                                        const Variant &qualified_name,
                                        const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[470]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, value});
}
Variant Dom_HTMLElement::removeAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[466]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_HTMLElement::removeAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[467]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_HTMLElement::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[476]);
    }
    return this_.call(_method_fn, {qualified_name, force});
}
Variant Dom_HTMLElement::hasAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[464]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_HTMLElement::hasAttributeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[465]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_HTMLElement::getAttributeNode(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[462]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_HTMLElement::getAttributeNodeNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[463]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_HTMLElement::setAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return this_.call(_method_fn, {attr});
}
Variant Dom_HTMLElement::setAttributeNodeNS(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[472]);
    }
    return this_.call(_method_fn, {attr});
}
Variant Dom_HTMLElement::removeAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[468]);
    }
    return this_.call(_method_fn, {attr});
}
Variant Dom_HTMLElement::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_HTMLElement::getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {_namespace, local_name});
}
Variant Dom_HTMLElement::insertAdjacentElement(const Variant &where, const Variant &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[477]);
    }
    return this_.call(_method_fn, {where, element});
}
Variant Dom_HTMLElement::insertAdjacentText(const Variant &where, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[478]);
    }
    return this_.call(_method_fn, {where, data});
}
Variant Dom_HTMLElement::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[473]);
    }
    return this_.call(_method_fn, {qualified_name, is_id});
}
Variant Dom_HTMLElement::setIdAttributeNS(const Variant &_namespace,
                                          const Variant &qualified_name,
                                          const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[474]);
    }
    return this_.call(_method_fn, {_namespace, qualified_name, is_id});
}
Variant Dom_HTMLElement::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {attr, is_id});
}
Variant Dom_HTMLElement::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_HTMLElement::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_HTMLElement::closest(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[480]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_HTMLElement::matches(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[481]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Dom_HTMLElement::getInScopeNamespaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[482]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::getDescendantNamespaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[483]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::rename(const Variant &namespace_u_r_i, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[457]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, qualified_name});
}
Variant Dom_HTMLElement::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_HTMLElement::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_HTMLElement::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_HTMLElement::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_HTMLElement::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_HTMLElement::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_HTMLElement::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_HTMLElement::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_HTMLElement::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_HTMLElement::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_HTMLElement::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_HTMLElement::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_HTMLElement::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_HTMLElement::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::C14N(const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_HTMLElement::C14NFile(const Variant &uri,
                                  const Variant &exclusive,
                                  const Variant &with_comments,
                                  const Variant &xpath,
                                  const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_HTMLElement::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_HTMLElement::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMText::DOMText(const Variant &data) {
    this_ = newObject(LITERAL_STRING[485], {data});
}
Variant DOMText::isWhitespaceInElementContent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[486]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::isElementContentWhitespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[487]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::splitText(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[488]);
    }
    return this_.call(_method_fn, {offset});
}
Variant DOMText::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMText::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMText::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant DOMText::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMText::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant DOMText::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMText::C14N(const Variant &exclusive,
                      const Variant &with_comments,
                      const Variant &xpath,
                      const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMText::C14NFile(const Variant &uri,
                          const Variant &exclusive,
                          const Variant &with_comments,
                          const Variant &xpath,
                          const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMText::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMText::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMText::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMText::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMText::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMText::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMText::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMText::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMText::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMText::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMText::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMText::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMText::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMText::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_Text::Dom_Text() {
    this_ = newObject(LITERAL_STRING[489]);
}
Variant Dom_Text::splitText(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[488]);
    }
    return this_.call(_method_fn, {offset});
}
Variant Dom_Text::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_Text::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_Text::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant Dom_Text::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_Text::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant Dom_Text::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Text::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_Text::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Text::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Text::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_Text::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Text::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Text::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Text::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Text::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Text::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_Text::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Text::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Text::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_Text::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Text::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_Text::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Text::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Text::C14N(const Variant &exclusive,
                       const Variant &with_comments,
                       const Variant &xpath,
                       const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Text::C14NFile(const Variant &uri,
                           const Variant &exclusive,
                           const Variant &with_comments,
                           const Variant &xpath,
                           const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Text::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Text::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMComment::DOMComment(const Variant &data) {
    this_ = newObject(LITERAL_STRING[490], {data});
}
Variant DOMComment::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMComment::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMComment::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant DOMComment::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMComment::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant DOMComment::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMComment::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMComment::C14N(const Variant &exclusive,
                         const Variant &with_comments,
                         const Variant &xpath,
                         const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMComment::C14NFile(const Variant &uri,
                             const Variant &exclusive,
                             const Variant &with_comments,
                             const Variant &xpath,
                             const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMComment::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMComment::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMComment::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMComment::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMComment::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMComment::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMComment::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMComment::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMComment::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMComment::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMComment::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMComment::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMComment::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMComment::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMComment::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMComment::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMComment::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMComment::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMComment::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMComment::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_Comment::Dom_Comment() {
    this_ = newObject(LITERAL_STRING[491]);
}
Variant Dom_Comment::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_Comment::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_Comment::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant Dom_Comment::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_Comment::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant Dom_Comment::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Comment::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_Comment::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Comment::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Comment::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_Comment::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Comment::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Comment::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Comment::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Comment::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Comment::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_Comment::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Comment::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Comment::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_Comment::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Comment::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_Comment::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Comment::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Comment::C14N(const Variant &exclusive,
                          const Variant &with_comments,
                          const Variant &xpath,
                          const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Comment::C14NFile(const Variant &uri,
                              const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Comment::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Comment::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMCdataSection::DOMCdataSection(const Variant &data) {
    this_ = newObject(LITERAL_STRING[492], {data});
}
Variant DOMCdataSection::isWhitespaceInElementContent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[486]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::isElementContentWhitespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[487]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::splitText(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[488]);
    }
    return this_.call(_method_fn, {offset});
}
Variant DOMCdataSection::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMCdataSection::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMCdataSection::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant DOMCdataSection::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMCdataSection::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant DOMCdataSection::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMCdataSection::C14N(const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMCdataSection::C14NFile(const Variant &uri,
                                  const Variant &exclusive,
                                  const Variant &with_comments,
                                  const Variant &xpath,
                                  const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMCdataSection::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMCdataSection::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMCdataSection::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMCdataSection::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMCdataSection::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMCdataSection::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMCdataSection::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMCdataSection::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMCdataSection::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMCdataSection::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMCdataSection::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMCdataSection::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMCdataSection::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMCdataSection::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMCdataSection::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_CDATASection::Dom_CDATASection() {
    this_ = newObject(LITERAL_STRING[493]);
}
Variant Dom_CDATASection::splitText(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[488]);
    }
    return this_.call(_method_fn, {offset});
}
Variant Dom_CDATASection::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_CDATASection::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_CDATASection::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant Dom_CDATASection::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_CDATASection::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant Dom_CDATASection::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CDATASection::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_CDATASection::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CDATASection::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CDATASection::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_CDATASection::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_CDATASection::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_CDATASection::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_CDATASection::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_CDATASection::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_CDATASection::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_CDATASection::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_CDATASection::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_CDATASection::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_CDATASection::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_CDATASection::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_CDATASection::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CDATASection::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CDATASection::C14N(const Variant &exclusive,
                               const Variant &with_comments,
                               const Variant &xpath,
                               const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_CDATASection::C14NFile(const Variant &uri,
                                   const Variant &exclusive,
                                   const Variant &with_comments,
                                   const Variant &xpath,
                                   const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_CDATASection::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_CDATASection::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMDocumentType::DOMDocumentType() {
    this_ = newObject(LITERAL_STRING[494]);
}
Variant DOMDocumentType::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMDocumentType::C14N(const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMDocumentType::C14NFile(const Variant &uri,
                                  const Variant &exclusive,
                                  const Variant &with_comments,
                                  const Variant &xpath,
                                  const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMDocumentType::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMDocumentType::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentType::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentType::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentType::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentType::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMDocumentType::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMDocumentType::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMDocumentType::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMDocumentType::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMDocumentType::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMDocumentType::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMDocumentType::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentType::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMDocumentType::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMDocumentType::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMDocumentType::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMDocumentType::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMDocumentType::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocumentType::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_DocumentType::Dom_DocumentType() {
    this_ = newObject(LITERAL_STRING[495]);
}
Variant Dom_DocumentType::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentType::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_DocumentType::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentType::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentType::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_DocumentType::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_DocumentType::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_DocumentType::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_DocumentType::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_DocumentType::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_DocumentType::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_DocumentType::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_DocumentType::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_DocumentType::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_DocumentType::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_DocumentType::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_DocumentType::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentType::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentType::C14N(const Variant &exclusive,
                               const Variant &with_comments,
                               const Variant &xpath,
                               const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_DocumentType::C14NFile(const Variant &uri,
                                   const Variant &exclusive,
                                   const Variant &with_comments,
                                   const Variant &xpath,
                                   const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_DocumentType::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_DocumentType::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMNotation::DOMNotation() {
    this_ = newObject(LITERAL_STRING[496]);
}
Variant DOMNotation::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMNotation::C14N(const Variant &exclusive,
                          const Variant &with_comments,
                          const Variant &xpath,
                          const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMNotation::C14NFile(const Variant &uri,
                              const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMNotation::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMNotation::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNotation::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNotation::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNotation::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNotation::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMNotation::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMNotation::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMNotation::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMNotation::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMNotation::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMNotation::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMNotation::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNotation::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMNotation::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMNotation::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMNotation::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMNotation::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMNotation::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNotation::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_Notation::Dom_Notation() {
    this_ = newObject(LITERAL_STRING[497]);
}
Variant Dom_Notation::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_Notation::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Notation::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Notation::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_Notation::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Notation::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Notation::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Notation::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Notation::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Notation::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_Notation::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Notation::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Notation::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_Notation::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Notation::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_Notation::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Notation::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Notation::C14N(const Variant &exclusive,
                           const Variant &with_comments,
                           const Variant &xpath,
                           const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Notation::C14NFile(const Variant &uri,
                               const Variant &exclusive,
                               const Variant &with_comments,
                               const Variant &xpath,
                               const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Notation::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Notation::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMEntity::DOMEntity() {
    this_ = newObject(LITERAL_STRING[498]);
}
Variant DOMEntity::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMEntity::C14N(const Variant &exclusive,
                        const Variant &with_comments,
                        const Variant &xpath,
                        const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMEntity::C14NFile(const Variant &uri,
                            const Variant &exclusive,
                            const Variant &with_comments,
                            const Variant &xpath,
                            const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMEntity::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMEntity::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntity::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntity::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntity::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntity::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMEntity::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMEntity::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMEntity::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMEntity::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMEntity::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMEntity::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMEntity::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntity::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMEntity::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMEntity::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMEntity::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMEntity::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMEntity::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntity::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_Entity::Dom_Entity() {
    this_ = newObject(LITERAL_STRING[499]);
}
Variant Dom_Entity::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_Entity::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Entity::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Entity::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_Entity::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Entity::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Entity::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Entity::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Entity::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Entity::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_Entity::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_Entity::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Entity::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_Entity::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Entity::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_Entity::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Entity::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Entity::C14N(const Variant &exclusive,
                         const Variant &with_comments,
                         const Variant &xpath,
                         const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Entity::C14NFile(const Variant &uri,
                             const Variant &exclusive,
                             const Variant &with_comments,
                             const Variant &xpath,
                             const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_Entity::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_Entity::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMEntityReference::DOMEntityReference(const Variant &name) {
    this_ = newObject(LITERAL_STRING[500], {name});
}
Variant DOMEntityReference::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMEntityReference::C14N(const Variant &exclusive,
                                 const Variant &with_comments,
                                 const Variant &xpath,
                                 const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMEntityReference::C14NFile(const Variant &uri,
                                     const Variant &exclusive,
                                     const Variant &with_comments,
                                     const Variant &xpath,
                                     const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMEntityReference::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMEntityReference::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntityReference::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntityReference::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntityReference::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntityReference::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMEntityReference::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMEntityReference::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMEntityReference::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMEntityReference::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMEntityReference::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMEntityReference::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMEntityReference::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntityReference::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMEntityReference::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMEntityReference::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMEntityReference::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMEntityReference::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMEntityReference::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMEntityReference::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_EntityReference::Dom_EntityReference() {
    this_ = newObject(LITERAL_STRING[501]);
}
Variant Dom_EntityReference::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_EntityReference::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_EntityReference::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_EntityReference::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_EntityReference::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_EntityReference::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_EntityReference::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_EntityReference::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_EntityReference::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_EntityReference::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_EntityReference::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_EntityReference::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_EntityReference::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_EntityReference::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_EntityReference::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_EntityReference::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_EntityReference::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_EntityReference::C14N(const Variant &exclusive,
                                  const Variant &with_comments,
                                  const Variant &xpath,
                                  const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_EntityReference::C14NFile(const Variant &uri,
                                      const Variant &exclusive,
                                      const Variant &with_comments,
                                      const Variant &xpath,
                                      const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_EntityReference::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_EntityReference::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMProcessingInstruction::DOMProcessingInstruction(const Variant &name, const Variant &value) {
    this_ = newObject(LITERAL_STRING[502], {name, value});
}
Variant DOMProcessingInstruction::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMProcessingInstruction::C14N(const Variant &exclusive,
                                       const Variant &with_comments,
                                       const Variant &xpath,
                                       const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMProcessingInstruction::C14NFile(const Variant &uri,
                                           const Variant &exclusive,
                                           const Variant &with_comments,
                                           const Variant &xpath,
                                           const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMProcessingInstruction::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMProcessingInstruction::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMProcessingInstruction::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMProcessingInstruction::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[353]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMProcessingInstruction::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMProcessingInstruction::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMProcessingInstruction::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMProcessingInstruction::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMProcessingInstruction::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMProcessingInstruction::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[359]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMProcessingInstruction::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMProcessingInstruction::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant DOMProcessingInstruction::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMProcessingInstruction::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMProcessingInstruction::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMProcessingInstruction::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMProcessingInstruction::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant DOMProcessingInstruction::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMProcessingInstruction::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMProcessingInstruction::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Dom_ProcessingInstruction::Dom_ProcessingInstruction() {
    this_ = newObject(LITERAL_STRING[503]);
}
Variant Dom_ProcessingInstruction::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[445]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_ProcessingInstruction::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[444]);
    }
    return this_.call(_method_fn, {data});
}
Variant Dom_ProcessingInstruction::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant Dom_ProcessingInstruction::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant Dom_ProcessingInstruction::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant Dom_ProcessingInstruction::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_ProcessingInstruction::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return this_.call(_method_fn, {options});
}
Variant Dom_ProcessingInstruction::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[354]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_ProcessingInstruction::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_ProcessingInstruction::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[350]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Dom_ProcessingInstruction::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_ProcessingInstruction::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_ProcessingInstruction::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_ProcessingInstruction::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_ProcessingInstruction::lookupPrefix(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_ProcessingInstruction::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_ProcessingInstruction::isDefaultNamespace(const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {_namespace});
}
Variant Dom_ProcessingInstruction::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_ProcessingInstruction::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_ProcessingInstruction::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_ProcessingInstruction::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant Dom_ProcessingInstruction::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[351]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_ProcessingInstruction::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[352]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_ProcessingInstruction::C14N(const Variant &exclusive,
                                        const Variant &with_comments,
                                        const Variant &xpath,
                                        const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[348]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_ProcessingInstruction::C14NFile(const Variant &uri,
                                            const Variant &exclusive,
                                            const Variant &with_comments,
                                            const Variant &xpath,
                                            const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[349]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Dom_ProcessingInstruction::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_ProcessingInstruction::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
DOMXPath::DOMXPath(const Variant &document, const Variant &register_node_n_s) {
    this_ = newObject(LITERAL_STRING[504], {document, register_node_n_s});
}
Variant DOMXPath::evaluate(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[505]);
    }
    return this_.call(_method_fn, {expression, context_node, register_node_n_s});
}
Variant DOMXPath::query(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[506]);
    }
    return this_.call(_method_fn, {expression, context_node, register_node_n_s});
}
Variant DOMXPath::registerNamespace(const Variant &prefix, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[507]);
    }
    return this_.call(_method_fn, {prefix, _namespace});
}
Variant DOMXPath::registerPhpFunctions(const Variant &restrict) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[508]);
    }
    return this_.call(_method_fn, {restrict});
}
Variant DOMXPath::registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[509]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, name, callable});
}
Variant DOMXPath::quote(const Variant &str) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[504], LITERAL_STRING[511]);
    }
    return php::call(_method_fn, {str});
}
Dom_XPath::Dom_XPath(const Variant &document, const Variant &register_node_n_s) {
    this_ = newObject(LITERAL_STRING[512], {document, register_node_n_s});
}
Variant Dom_XPath::evaluate(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[505]);
    }
    return this_.call(_method_fn, {expression, context_node, register_node_n_s});
}
Variant Dom_XPath::query(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[506]);
    }
    return this_.call(_method_fn, {expression, context_node, register_node_n_s});
}
Variant Dom_XPath::registerNamespace(const Variant &prefix, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[507]);
    }
    return this_.call(_method_fn, {prefix, _namespace});
}
Variant Dom_XPath::registerPhpFunctions(const Variant &restrict) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[508]);
    }
    return this_.call(_method_fn, {restrict});
}
Variant Dom_XPath::registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[509]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, name, callable});
}
Variant Dom_XPath::quote(const Variant &str) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[514], LITERAL_STRING[511]);
    }
    return php::call(_method_fn, {str});
}
Variant Dom_TokenList::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return this_.call(_method_fn, {index});
}
Variant Dom_TokenList::contains(const Variant &token) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {token});
}
Variant Dom_TokenList::toggle(const Variant &token, const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[515]);
    }
    return this_.call(_method_fn, {token, force});
}
Variant Dom_TokenList::replace(const Variant &token, const Variant &new_token) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[516]);
    }
    return this_.call(_method_fn, {token, new_token});
}
Variant Dom_TokenList::supports(const Variant &token) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[517]);
    }
    return this_.call(_method_fn, {token});
}
Variant Dom_TokenList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant Dom_TokenList::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

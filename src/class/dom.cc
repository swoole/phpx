#include "phpx.h"
#include "phpx_class.h"
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
dom_domexception::dom_domexception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[339], {message, code, previous});
}
DOMNode::DOMNode() {
    this_ = newObject(LITERAL_STRING[346]);
}
Variant DOMNode::appendChild(const DOMNode &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node.getObject()});
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
Variant DOMNode::insertBefore(const DOMNode &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node.getObject(), child});
}
Variant DOMNode::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMNode::isDefaultNamespace(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant DOMNode::isSameNode(const DOMNode &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant DOMNode::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMNode::isEqualNode(const DOMNode &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
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
Variant DOMNode::lookupPrefix(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant DOMNode::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[362]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::removeChild(const DOMNode &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child.getObject()});
}
Variant DOMNode::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMNode::replaceChild(const DOMNode &node, const DOMNode &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
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
DOMNode DOMNode::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[366]);
    }
    return DOMNode(Object(this_.call(_method_fn, {options})));
}
Variant DOMNode::compareDocumentPosition(const DOMNode &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other.getObject()});
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
Variant Dom_Node::isEqualNode(const Dom_Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant Dom_Node::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Node::isSameNode(const Dom_Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant Dom_Node::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_Node::compareDocumentPosition(const Dom_Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant Dom_Node::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Node::contains(const Dom_Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant Dom_Node::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_Node::lookupPrefix(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant Dom_Node::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_Node::isDefaultNamespace(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant Dom_Node::insertBefore(const Dom_Node &node, const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant Dom_Node::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Node::appendChild(const Dom_Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant Dom_Node::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_Node::replaceChild(const Dom_Node &node, const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant Dom_Node::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_Node::removeChild(const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child.getObject()});
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
DOMNode DOMNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[437]);
    }
    return DOMNode(Object(this_.call(_method_fn, {qualified_name})));
}
DOMNode DOMNamedNodeMap::getNamedItemNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return DOMNode(Object(this_.call(_method_fn, {namespace_, local_name})));
}
DOMNode DOMNamedNodeMap::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return DOMNode(Object(this_.call(_method_fn, {index})));
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
Dom_NamedNodeMap::Dom_NamedNodeMap() {
    this_ = newObject(LITERAL_STRING[439]);
}
Dom_Attr Dom_NamedNodeMap::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {index})));
}
Dom_Attr Dom_NamedNodeMap::getNamedItem(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[437]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {qualified_name})));
}
Dom_Attr Dom_NamedNodeMap::getNamedItemNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {namespace_, local_name})));
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
DOMElement::DOMElement(const Variant &qualified_name, const Variant &value, const Variant &namespace_) {
    this_ = newObject(LITERAL_STRING[458], {qualified_name, value, namespace_});
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
Variant DOMElement::getAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[461]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant DOMElement::getAttributeNode(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[462]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::getAttributeNodeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[463]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
DOMNodeList DOMElement::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return DOMNodeList(Object(this_.call(_method_fn, {qualified_name})));
}
DOMNodeList DOMElement::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return DOMNodeList(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Variant DOMElement::hasAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[464]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::hasAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[465]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant DOMElement::removeAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[466]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::removeAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[467]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant DOMElement::removeAttributeNode(const DOMAttr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[468]);
    }
    return this_.call(_method_fn, {attr.getObject()});
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
Variant DOMElement::setAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[470]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, value});
}
Variant DOMElement::setAttributeNode(const DOMAttr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return this_.call(_method_fn, {attr.getObject()});
}
Variant DOMElement::setAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return this_.call(_method_fn, {attr});
}
Variant DOMElement::setAttributeNodeNS(const DOMAttr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[472]);
    }
    return this_.call(_method_fn, {attr.getObject()});
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
Variant DOMElement::setIdAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[474]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, is_id});
}
Variant DOMElement::setIdAttributeNode(const DOMAttr &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {attr.getObject(), is_id});
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
Variant DOMElement::insertAdjacentElement(const Variant &where, const DOMElement &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[477]);
    }
    return this_.call(_method_fn, {where, element.getObject()});
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
Dom_Text::Dom_Text() {
    this_ = newObject(LITERAL_STRING[489]);
}
Dom_Text Dom_Text::splitText(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[488]);
    }
    return Dom_Text(Object(this_.call(_method_fn, {offset})));
}
DOMComment::DOMComment(const Variant &data) {
    this_ = newObject(LITERAL_STRING[490], {data});
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
Variant DOMDocument::createAttributeNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name});
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
Variant DOMDocument::createElementNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, value});
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
DOMNodeList DOMDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return DOMNodeList(Object(this_.call(_method_fn, {qualified_name})));
}
DOMNodeList DOMDocument::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return DOMNodeList(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Variant DOMDocument::importNode(const DOMNode &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
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
DOMNode DOMDocument::adoptNode(const DOMNode &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    auto _rv = this_.call(_method_fn, {node.getObject()});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "DOMDocument::adoptNode() returned false");
    }
    return DOMNode(Object(std::move(_rv)));
}
Variant DOMDocument::adoptNode(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {node});
}
Dom_Comment::Dom_Comment() {
    this_ = newObject(LITERAL_STRING[491]);
}
DOMCdataSection::DOMCdataSection(const Variant &data) {
    this_ = newObject(LITERAL_STRING[492], {data});
}
Dom_CDATASection::Dom_CDATASection() {
    this_ = newObject(LITERAL_STRING[493]);
}
DOMDocumentType::DOMDocumentType() {
    this_ = newObject(LITERAL_STRING[494]);
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
Variant DOMImplementation::createDocument(const Variant &namespace_,
                                          const Variant &qualified_name,
                                          const Variant &doctype) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[343]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, doctype});
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
DOMNotation::DOMNotation() {
    this_ = newObject(LITERAL_STRING[496]);
}
Dom_Notation::Dom_Notation() {
    this_ = newObject(LITERAL_STRING[497]);
}
DOMEntity::DOMEntity() {
    this_ = newObject(LITERAL_STRING[498]);
}
Dom_Entity::Dom_Entity() {
    this_ = newObject(LITERAL_STRING[499]);
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
Variant Dom_DtdNamedNodeMap::getNamedItemNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
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
DOMEntityReference::DOMEntityReference(const Variant &name) {
    this_ = newObject(LITERAL_STRING[500], {name});
}
Dom_EntityReference::Dom_EntityReference() {
    this_ = newObject(LITERAL_STRING[501]);
}
DOMProcessingInstruction::DOMProcessingInstruction(const Variant &name, const Variant &value) {
    this_ = newObject(LITERAL_STRING[502], {name, value});
}
Dom_ProcessingInstruction::Dom_ProcessingInstruction() {
    this_ = newObject(LITERAL_STRING[503]);
}
DOMXPath::DOMXPath(const DOMDocument &document, const Variant &register_node_n_s) {
    this_ = newObject(LITERAL_STRING[504], {document.getObject(), register_node_n_s});
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
Variant DOMXPath::registerNamespace(const Variant &prefix, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[507]);
    }
    return this_.call(_method_fn, {prefix, namespace_});
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
Dom_NodeList Dom_XPath::query(const Variant &expression,
                              const Variant &context_node,
                              const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[506]);
    }
    return Dom_NodeList(Object(this_.call(_method_fn, {expression, context_node, register_node_n_s})));
}
Variant Dom_XPath::registerNamespace(const Variant &prefix, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[507]);
    }
    return this_.call(_method_fn, {prefix, namespace_});
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
Dom_Element Dom_DocumentFragment::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {selectors})));
}
Dom_NodeList Dom_DocumentFragment::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return Dom_NodeList(Object(this_.call(_method_fn, {selectors})));
}
Dom_HTMLCollection::Dom_HTMLCollection() {
    this_ = newObject(LITERAL_STRING[441]);
}
Dom_Element Dom_HTMLCollection::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {index})));
}
Dom_Element Dom_HTMLCollection::namedItem(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[442]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {key})));
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
Variant Dom_Element::getAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[461]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant Dom_Element::setAttribute(const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[469]);
    }
    return this_.call(_method_fn, {qualified_name, value});
}
Variant Dom_Element::setAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[470]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, value});
}
Variant Dom_Element::removeAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[466]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Dom_Element::removeAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[467]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
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
Variant Dom_Element::hasAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[465]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Dom_Attr Dom_Element::getAttributeNode(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[462]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {qualified_name})));
}
Dom_Attr Dom_Element::getAttributeNodeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[463]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Dom_Attr Dom_Element::setAttributeNode(const Dom_Attr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {attr.getObject()})));
}
Variant Dom_Element::setAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return this_.call(_method_fn, {attr});
}
Dom_Attr Dom_Element::setAttributeNodeNS(const Dom_Attr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[472]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {attr.getObject()})));
}
Variant Dom_Element::setAttributeNodeNS(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[472]);
    }
    return this_.call(_method_fn, {attr});
}
Dom_Attr Dom_Element::removeAttributeNode(const Dom_Attr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[468]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {attr.getObject()})));
}
Variant Dom_Element::removeAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[468]);
    }
    return this_.call(_method_fn, {attr});
}
Dom_HTMLCollection Dom_Element::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return Dom_HTMLCollection(Object(this_.call(_method_fn, {qualified_name})));
}
Dom_HTMLCollection Dom_Element::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return Dom_HTMLCollection(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Dom_Element Dom_Element::insertAdjacentElement(const Dom_AdjacentPosition &where, const Dom_Element &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[477]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {where.getObject(), element.getObject()})));
}
Variant Dom_Element::insertAdjacentElement(const Variant &where, const Variant &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[477]);
    }
    return this_.call(_method_fn, {where, element});
}
Variant Dom_Element::insertAdjacentText(const Dom_AdjacentPosition &where, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[478]);
    }
    return this_.call(_method_fn, {where.getObject(), data});
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
Variant Dom_Element::setIdAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[474]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, is_id});
}
Variant Dom_Element::setIdAttributeNode(const Dom_Attr &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {attr.getObject(), is_id});
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
Dom_Element Dom_Element::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {selectors})));
}
Dom_NodeList Dom_Element::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return Dom_NodeList(Object(this_.call(_method_fn, {selectors})));
}
Dom_Element Dom_Element::closest(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[480]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {selectors})));
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
Dom_HTMLDocument::Dom_HTMLDocument() {
    this_ = newObject(LITERAL_STRING[412]);
}
Dom_HTMLDocument Dom_HTMLDocument::createEmpty(const Variant &encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[414], LITERAL_STRING[415]);
    }
    return Dom_HTMLDocument(Object(php::call(_method_fn, {encoding})));
}
Dom_HTMLDocument Dom_HTMLDocument::createFromFile(const Variant &path,
                                                  const Variant &options,
                                                  const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[414], LITERAL_STRING[417]);
    }
    return Dom_HTMLDocument(Object(php::call(_method_fn, {path, options, override_encoding})));
}
Dom_HTMLDocument Dom_HTMLDocument::createFromString(const Variant &source,
                                                    const Variant &options,
                                                    const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[414], LITERAL_STRING[419]);
    }
    return Dom_HTMLDocument(Object(php::call(_method_fn, {source, options, override_encoding})));
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
Dom_HTMLCollection Dom_HTMLDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return Dom_HTMLCollection(Object(this_.call(_method_fn, {qualified_name})));
}
Dom_HTMLCollection Dom_HTMLDocument::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return Dom_HTMLCollection(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Dom_Element Dom_HTMLDocument::createElement(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[386]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {local_name})));
}
Dom_Element Dom_HTMLDocument::createElementNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {namespace_, qualified_name})));
}
Dom_DocumentFragment Dom_HTMLDocument::createDocumentFragment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return Dom_DocumentFragment(Object(this_.call(_method_fn, {})));
}
Dom_Text Dom_HTMLDocument::createTextNode(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return Dom_Text(Object(this_.call(_method_fn, {data})));
}
Dom_CDATASection Dom_HTMLDocument::createCDATASection(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return Dom_CDATASection(Object(this_.call(_method_fn, {data})));
}
Dom_Comment Dom_HTMLDocument::createComment(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return Dom_Comment(Object(this_.call(_method_fn, {data})));
}
Dom_ProcessingInstruction Dom_HTMLDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return Dom_ProcessingInstruction(Object(this_.call(_method_fn, {target, data})));
}
Variant Dom_HTMLDocument::importNode(const Dom_Node &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant Dom_HTMLDocument::importNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant Dom_HTMLDocument::adoptNode(const Dom_Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant Dom_HTMLDocument::adoptNode(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {node});
}
Dom_Attr Dom_HTMLDocument::createAttribute(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {local_name})));
}
Dom_Attr Dom_HTMLDocument::createAttributeNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {namespace_, qualified_name})));
}
Dom_Element Dom_HTMLDocument::getElementById(const Variant &element_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {element_id})));
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
Variant Dom_HTMLDocument::importLegacyNode(const DOMNode &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[427]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant Dom_HTMLDocument::importLegacyNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[427]);
    }
    return this_.call(_method_fn, {node, deep});
}
Dom_Element Dom_HTMLDocument::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {selectors})));
}
Dom_NodeList Dom_HTMLDocument::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return Dom_NodeList(Object(this_.call(_method_fn, {selectors})));
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
Variant Dom_HTMLDocument::isEqualNode(const Dom_Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant Dom_HTMLDocument::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_HTMLDocument::isSameNode(const Dom_Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant Dom_HTMLDocument::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_HTMLDocument::compareDocumentPosition(const Dom_Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant Dom_HTMLDocument::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_HTMLDocument::contains(const Dom_Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant Dom_HTMLDocument::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_HTMLDocument::lookupPrefix(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant Dom_HTMLDocument::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_HTMLDocument::isDefaultNamespace(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant Dom_HTMLDocument::insertBefore(const Dom_Node &node, const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant Dom_HTMLDocument::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_HTMLDocument::appendChild(const Dom_Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant Dom_HTMLDocument::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_HTMLDocument::replaceChild(const Dom_Node &node, const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant Dom_HTMLDocument::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_HTMLDocument::removeChild(const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child.getObject()});
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
Dom_XMLDocument Dom_XMLDocument::createEmpty(const Variant &version, const Variant &encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[430], LITERAL_STRING[415]);
    }
    return Dom_XMLDocument(Object(php::call(_method_fn, {version, encoding})));
}
Dom_XMLDocument Dom_XMLDocument::createFromFile(const Variant &path,
                                                const Variant &options,
                                                const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[430], LITERAL_STRING[417]);
    }
    return Dom_XMLDocument(Object(php::call(_method_fn, {path, options, override_encoding})));
}
Dom_XMLDocument Dom_XMLDocument::createFromString(const Variant &source,
                                                  const Variant &options,
                                                  const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[430], LITERAL_STRING[419]);
    }
    return Dom_XMLDocument(Object(php::call(_method_fn, {source, options, override_encoding})));
}
Dom_EntityReference Dom_XMLDocument::createEntityReference(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[388]);
    }
    return Dom_EntityReference(Object(this_.call(_method_fn, {name})));
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
Dom_HTMLCollection Dom_XMLDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return Dom_HTMLCollection(Object(this_.call(_method_fn, {qualified_name})));
}
Dom_HTMLCollection Dom_XMLDocument::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return Dom_HTMLCollection(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Dom_Element Dom_XMLDocument::createElement(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[386]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {local_name})));
}
Dom_Element Dom_XMLDocument::createElementNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {namespace_, qualified_name})));
}
Dom_DocumentFragment Dom_XMLDocument::createDocumentFragment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return Dom_DocumentFragment(Object(this_.call(_method_fn, {})));
}
Dom_Text Dom_XMLDocument::createTextNode(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return Dom_Text(Object(this_.call(_method_fn, {data})));
}
Dom_CDATASection Dom_XMLDocument::createCDATASection(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return Dom_CDATASection(Object(this_.call(_method_fn, {data})));
}
Dom_Comment Dom_XMLDocument::createComment(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return Dom_Comment(Object(this_.call(_method_fn, {data})));
}
Dom_ProcessingInstruction Dom_XMLDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return Dom_ProcessingInstruction(Object(this_.call(_method_fn, {target, data})));
}
Variant Dom_XMLDocument::importNode(const Dom_Node &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant Dom_XMLDocument::importNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant Dom_XMLDocument::adoptNode(const Dom_Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant Dom_XMLDocument::adoptNode(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {node});
}
Dom_Attr Dom_XMLDocument::createAttribute(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {local_name})));
}
Dom_Attr Dom_XMLDocument::createAttributeNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return Dom_Attr(Object(this_.call(_method_fn, {namespace_, qualified_name})));
}
Dom_Element Dom_XMLDocument::getElementById(const Variant &element_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {element_id})));
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
Variant Dom_XMLDocument::importLegacyNode(const DOMNode &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[427]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant Dom_XMLDocument::importLegacyNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[427]);
    }
    return this_.call(_method_fn, {node, deep});
}
Dom_Element Dom_XMLDocument::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return Dom_Element(Object(this_.call(_method_fn, {selectors})));
}
Dom_NodeList Dom_XMLDocument::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return Dom_NodeList(Object(this_.call(_method_fn, {selectors})));
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
Variant Dom_XMLDocument::isEqualNode(const Dom_Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant Dom_XMLDocument::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[358]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_XMLDocument::isSameNode(const Dom_Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant Dom_XMLDocument::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[357]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Dom_XMLDocument::compareDocumentPosition(const Dom_Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant Dom_XMLDocument::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[367]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_XMLDocument::contains(const Dom_Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant Dom_XMLDocument::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[365]);
    }
    return this_.call(_method_fn, {other});
}
Variant Dom_XMLDocument::lookupPrefix(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[361]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant Dom_XMLDocument::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[360]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Dom_XMLDocument::isDefaultNamespace(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[356]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant Dom_XMLDocument::insertBefore(const Dom_Node &node, const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant Dom_XMLDocument::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[355]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_XMLDocument::appendChild(const Dom_Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant Dom_XMLDocument::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[347]);
    }
    return this_.call(_method_fn, {node});
}
Variant Dom_XMLDocument::replaceChild(const Dom_Node &node, const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant Dom_XMLDocument::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[364]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Dom_XMLDocument::removeChild(const Dom_Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[363]);
    }
    return this_.call(_method_fn, {child.getObject()});
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
Dom_Implementation::Dom_Implementation() {
    this_ = newObject(LITERAL_STRING[344]);
}
Dom_DocumentType Dom_Implementation::createDocumentType(const Variant &qualified_name,
                                                        const Variant &public_id,
                                                        const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[342]);
    }
    return Dom_DocumentType(Object(this_.call(_method_fn, {qualified_name, public_id, system_id})));
}
Dom_XMLDocument Dom_Implementation::createDocument(const Variant &namespace_,
                                                   const Variant &qualified_name,
                                                   const Variant &doctype) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[343]);
    }
    return Dom_XMLDocument(Object(this_.call(_method_fn, {namespace_, qualified_name, doctype})));
}
Dom_HTMLDocument Dom_Implementation::createHTMLDocument(const Variant &title) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[345]);
    }
    return Dom_HTMLDocument(Object(this_.call(_method_fn, {title})));
}
Dom_HTMLElement::Dom_HTMLElement() {
    this_ = newObject(LITERAL_STRING[484]);
}
}  // namespace php

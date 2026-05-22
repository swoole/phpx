#include "phpx.h"
#include "phpx_class.h"
#include "class/dom.h"

namespace php::Dom {
AdjacentPosition::AdjacentPosition() {
    this_ = newObject(LITERAL_STRING[359]);
}
Variant AdjacentPosition::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[359], LITERAL_STRING[361]);
    }
    return php::call(_method_fn, {});
}
Variant AdjacentPosition::from(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[359], LITERAL_STRING[363]);
    }
    return php::call(_method_fn, {value});
}
Variant AdjacentPosition::tryFrom(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[359], LITERAL_STRING[365]);
    }
    return php::call(_method_fn, {value});
}
Variant Node::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {options});
}
Variant Node::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return this_.call(_method_fn, {});
}
Variant Node::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return this_.call(_method_fn, {});
}
Variant Node::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[377]);
    }
    return this_.call(_method_fn, {deep});
}
Variant Node::isEqualNode(const Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant Node::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Node::isSameNode(const Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant Node::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant Node::compareDocumentPosition(const Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant Node::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {other});
}
Variant Node::contains(const Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant Node::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {other});
}
Variant Node::lookupPrefix(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[388]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant Node::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant Node::isDefaultNamespace(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant Node::insertBefore(const Node &node, const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant Node::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Node::appendChild(const Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant Node::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
    }
    return this_.call(_method_fn, {node});
}
Variant Node::replaceChild(const Node &node, const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant Node::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant Node::removeChild(const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {child.getObject()});
}
Variant Node::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {child});
}
Variant Node::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {});
}
Variant Node::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {});
}
Variant Node::C14N(const Variant &exclusive,
                   const Variant &with_comments,
                   const Variant &xpath,
                   const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant Node::C14NFile(const Variant &uri,
                       const Variant &exclusive,
                       const Variant &with_comments,
                       const Variant &xpath,
                       const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[376]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant Node::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[395]);
    }
    return this_.call(_method_fn, {});
}
Variant Node::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
NodeList::NodeList() {
    this_ = newObject(LITERAL_STRING[460]);
}
Variant NodeList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant NodeList::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
Variant NodeList::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {index});
}
CharacterData::CharacterData() {
    this_ = newObject(LITERAL_STRING[478]);
}
Variant CharacterData::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[470]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant CharacterData::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[469]);
    }
    return this_.call(_method_fn, {data});
}
Variant CharacterData::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant CharacterData::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[472]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant CharacterData::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[473]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant CharacterData::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {});
}
Attr::Attr() {
    this_ = newObject(LITERAL_STRING[481]);
}
Variant Attr::isId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[480]);
    }
    return this_.call(_method_fn, {});
}
Variant Attr::rename(const Variant &namespace_u_r_i, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[482]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, qualified_name});
}
NamedNodeMap::NamedNodeMap() {
    this_ = newObject(LITERAL_STRING[464]);
}
Attr NamedNodeMap::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return Attr(Object(this_.call(_method_fn, {index})));
}
Attr NamedNodeMap::getNamedItem(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[462]);
    }
    return Attr(Object(this_.call(_method_fn, {qualified_name})));
}
Attr NamedNodeMap::getNamedItemNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[463]);
    }
    return Attr(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Variant NamedNodeMap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant NamedNodeMap::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
Text::Text() {
    this_ = newObject(LITERAL_STRING[514]);
}
Text Text::splitText(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[513]);
    }
    return Text(Object(this_.call(_method_fn, {offset})));
}
Comment::Comment() {
    this_ = newObject(LITERAL_STRING[516]);
}
CDATASection::CDATASection() {
    this_ = newObject(LITERAL_STRING[518]);
}
DocumentType::DocumentType() {
    this_ = newObject(LITERAL_STRING[520]);
}
Variant DocumentType::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {});
}
Notation::Notation() {
    this_ = newObject(LITERAL_STRING[522]);
}
Entity::Entity() {
    this_ = newObject(LITERAL_STRING[524]);
}
DtdNamedNodeMap::DtdNamedNodeMap() {
    this_ = newObject(LITERAL_STRING[465]);
}
Variant DtdNamedNodeMap::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {index});
}
Variant DtdNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[462]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DtdNamedNodeMap::getNamedItemNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[463]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant DtdNamedNodeMap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant DtdNamedNodeMap::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
EntityReference::EntityReference() {
    this_ = newObject(LITERAL_STRING[526]);
}
ProcessingInstruction::ProcessingInstruction() {
    this_ = newObject(LITERAL_STRING[528]);
}
XPath::XPath(const Variant &document, const Variant &register_node_n_s) {
    this_ = newObject(LITERAL_STRING[537], {document, register_node_n_s});
}
Variant XPath::evaluate(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[530]);
    }
    return this_.call(_method_fn, {expression, context_node, register_node_n_s});
}
NodeList XPath::query(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[531]);
    }
    return NodeList(Object(this_.call(_method_fn, {expression, context_node, register_node_n_s})));
}
Variant XPath::registerNamespace(const Variant &prefix, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[532]);
    }
    return this_.call(_method_fn, {prefix, namespace_});
}
Variant XPath::registerPhpFunctions(const Variant &restrict) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[533]);
    }
    return this_.call(_method_fn, {restrict});
}
Variant XPath::registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[534]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, name, callable});
}
Variant XPath::quote(const Variant &str) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[537], LITERAL_STRING[536]);
    }
    return php::call(_method_fn, {str});
}
Variant TokenList::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {index});
}
Variant TokenList::contains(const Variant &token) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {token});
}
Variant TokenList::toggle(const Variant &token, const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[539]);
    }
    return this_.call(_method_fn, {token, force});
}
Variant TokenList::replace(const Variant &token, const Variant &new_token) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[540]);
    }
    return this_.call(_method_fn, {token, new_token});
}
Variant TokenList::supports(const Variant &token) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[541]);
    }
    return this_.call(_method_fn, {token});
}
Variant TokenList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant TokenList::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
DocumentFragment::DocumentFragment() {
    this_ = newObject(LITERAL_STRING[403]);
}
Variant DocumentFragment::appendXml(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[404]);
    }
    return this_.call(_method_fn, {data});
}
Element DocumentFragment::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[405]);
    }
    return Element(Object(this_.call(_method_fn, {selectors})));
}
NodeList DocumentFragment::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[406]);
    }
    return NodeList(Object(this_.call(_method_fn, {selectors})));
}
HTMLCollection::HTMLCollection() {
    this_ = newObject(LITERAL_STRING[466]);
}
Element HTMLCollection::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return Element(Object(this_.call(_method_fn, {index})));
}
Element HTMLCollection::namedItem(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[467]);
    }
    return Element(Object(this_.call(_method_fn, {key})));
}
Variant HTMLCollection::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant HTMLCollection::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
Element::Element() {
    this_ = newObject(LITERAL_STRING[504]);
}
Variant Element::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[380]);
    }
    return this_.call(_method_fn, {});
}
Variant Element::getAttributeNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[485]);
    }
    return this_.call(_method_fn, {});
}
Variant Element::getAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[484]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Element::getAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[486]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant Element::setAttribute(const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[494]);
    }
    return this_.call(_method_fn, {qualified_name, value});
}
Variant Element::setAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[495]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, value});
}
Variant Element::removeAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[491]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Element::removeAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[492]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant Element::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[501]);
    }
    return this_.call(_method_fn, {qualified_name, force});
}
Variant Element::hasAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[489]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant Element::hasAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[490]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Attr Element::getAttributeNode(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[487]);
    }
    return Attr(Object(this_.call(_method_fn, {qualified_name})));
}
Attr Element::getAttributeNodeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[488]);
    }
    return Attr(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Attr Element::setAttributeNode(const Attr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[496]);
    }
    return Attr(Object(this_.call(_method_fn, {attr.getObject()})));
}
Variant Element::setAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[496]);
    }
    return this_.call(_method_fn, {attr});
}
Attr Element::setAttributeNodeNS(const Attr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[497]);
    }
    return Attr(Object(this_.call(_method_fn, {attr.getObject()})));
}
Variant Element::setAttributeNodeNS(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[497]);
    }
    return this_.call(_method_fn, {attr});
}
Attr Element::removeAttributeNode(const Attr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[493]);
    }
    return Attr(Object(this_.call(_method_fn, {attr.getObject()})));
}
Variant Element::removeAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[493]);
    }
    return this_.call(_method_fn, {attr});
}
HTMLCollection Element::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[419]);
    }
    return HTMLCollection(Object(this_.call(_method_fn, {qualified_name})));
}
HTMLCollection Element::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[420]);
    }
    return HTMLCollection(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Element Element::insertAdjacentElement(const AdjacentPosition &where, const Element &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[502]);
    }
    return Element(Object(this_.call(_method_fn, {where.getObject(), element.getObject()})));
}
Variant Element::insertAdjacentElement(const Variant &where, const Variant &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[502]);
    }
    return this_.call(_method_fn, {where, element});
}
Variant Element::insertAdjacentText(const AdjacentPosition &where, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[503]);
    }
    return this_.call(_method_fn, {where.getObject(), data});
}
Variant Element::insertAdjacentText(const Variant &where, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[503]);
    }
    return this_.call(_method_fn, {where, data});
}
Variant Element::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[498]);
    }
    return this_.call(_method_fn, {qualified_name, is_id});
}
Variant Element::setIdAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[499]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, is_id});
}
Variant Element::setIdAttributeNode(const Attr &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[500]);
    }
    return this_.call(_method_fn, {attr.getObject(), is_id});
}
Variant Element::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[500]);
    }
    return this_.call(_method_fn, {attr, is_id});
}
Variant Element::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {});
}
Element Element::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[405]);
    }
    return Element(Object(this_.call(_method_fn, {selectors})));
}
NodeList Element::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[406]);
    }
    return NodeList(Object(this_.call(_method_fn, {selectors})));
}
Element Element::closest(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[505]);
    }
    return Element(Object(this_.call(_method_fn, {selectors})));
}
Variant Element::matches(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[506]);
    }
    return this_.call(_method_fn, {selectors});
}
Variant Element::getInScopeNamespaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[507]);
    }
    return this_.call(_method_fn, {});
}
Variant Element::getDescendantNamespaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[508]);
    }
    return this_.call(_method_fn, {});
}
Variant Element::rename(const Variant &namespace_u_r_i, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[482]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, qualified_name});
}
HTMLDocument::HTMLDocument() {
    this_ = newObject(LITERAL_STRING[439]);
}
HTMLDocument HTMLDocument::createEmpty(const Variant &encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[439], LITERAL_STRING[441]);
    }
    return HTMLDocument(Object(php::call(_method_fn, {encoding})));
}
HTMLDocument HTMLDocument::createFromFile(const Variant &path,
                                          const Variant &options,
                                          const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[439], LITERAL_STRING[443]);
    }
    return HTMLDocument(Object(php::call(_method_fn, {path, options, override_encoding})));
}
HTMLDocument HTMLDocument::createFromString(const Variant &source,
                                            const Variant &options,
                                            const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[439], LITERAL_STRING[445]);
    }
    return HTMLDocument(Object(php::call(_method_fn, {source, options, override_encoding})));
}
Variant HTMLDocument::saveXml(const Variant &node, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {node, options});
}
Variant HTMLDocument::saveXmlFile(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant HTMLDocument::saveHtml(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
    }
    return this_.call(_method_fn, {node});
}
Variant HTMLDocument::saveHtmlFile(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
    }
    return this_.call(_method_fn, {filename});
}
Variant HTMLDocument::debugGetTemplateCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
    }
    return this_.call(_method_fn, {});
}
HTMLCollection HTMLDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[419]);
    }
    return HTMLCollection(Object(this_.call(_method_fn, {qualified_name})));
}
HTMLCollection HTMLDocument::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[420]);
    }
    return HTMLCollection(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Element HTMLDocument::createElement(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[413]);
    }
    return Element(Object(this_.call(_method_fn, {local_name})));
}
Element HTMLDocument::createElementNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[414]);
    }
    return Element(Object(this_.call(_method_fn, {namespace_, qualified_name})));
}
DocumentFragment HTMLDocument::createDocumentFragment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[412]);
    }
    return DocumentFragment(Object(this_.call(_method_fn, {})));
}
Text HTMLDocument::createTextNode(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[417]);
    }
    return Text(Object(this_.call(_method_fn, {data})));
}
CDATASection HTMLDocument::createCDATASection(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[410]);
    }
    return CDATASection(Object(this_.call(_method_fn, {data})));
}
Comment HTMLDocument::createComment(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return Comment(Object(this_.call(_method_fn, {data})));
}
ProcessingInstruction HTMLDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[416]);
    }
    return ProcessingInstruction(Object(this_.call(_method_fn, {target, data})));
}
Variant HTMLDocument::importNode(const Node &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[421]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant HTMLDocument::importNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[421]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant HTMLDocument::adoptNode(const Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant HTMLDocument::adoptNode(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {node});
}
Attr HTMLDocument::createAttribute(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[408]);
    }
    return Attr(Object(this_.call(_method_fn, {local_name})));
}
Attr HTMLDocument::createAttributeNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[409]);
    }
    return Attr(Object(this_.call(_method_fn, {namespace_, qualified_name})));
}
Element HTMLDocument::getElementById(const Variant &element_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[418]);
    }
    return Element(Object(this_.call(_method_fn, {element_id})));
}
Variant HTMLDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[425]);
    }
    return this_.call(_method_fn, {base_class, extended_class});
}
Variant HTMLDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[432]);
    }
    return this_.call(_method_fn, {filename, flags});
}
Variant HTMLDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[433]);
    }
    return this_.call(_method_fn, {source, flags});
}
Variant HTMLDocument::relaxNgValidate(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
    }
    return this_.call(_method_fn, {filename});
}
Variant HTMLDocument::relaxNgValidateSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
    }
    return this_.call(_method_fn, {source});
}
Variant HTMLDocument::importLegacyNode(const DOMNode &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[453]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant HTMLDocument::importLegacyNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[453]);
    }
    return this_.call(_method_fn, {node, deep});
}
Element HTMLDocument::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[405]);
    }
    return Element(Object(this_.call(_method_fn, {selectors})));
}
NodeList HTMLDocument::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[406]);
    }
    return NodeList(Object(this_.call(_method_fn, {selectors})));
}
Variant HTMLDocument::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {options});
}
Variant HTMLDocument::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return this_.call(_method_fn, {});
}
Variant HTMLDocument::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return this_.call(_method_fn, {});
}
Variant HTMLDocument::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[377]);
    }
    return this_.call(_method_fn, {deep});
}
Variant HTMLDocument::isEqualNode(const Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant HTMLDocument::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant HTMLDocument::isSameNode(const Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant HTMLDocument::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant HTMLDocument::compareDocumentPosition(const Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant HTMLDocument::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {other});
}
Variant HTMLDocument::contains(const Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant HTMLDocument::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {other});
}
Variant HTMLDocument::lookupPrefix(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[388]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant HTMLDocument::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant HTMLDocument::isDefaultNamespace(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant HTMLDocument::insertBefore(const Node &node, const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant HTMLDocument::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant HTMLDocument::appendChild(const Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant HTMLDocument::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
    }
    return this_.call(_method_fn, {node});
}
Variant HTMLDocument::replaceChild(const Node &node, const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant HTMLDocument::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant HTMLDocument::removeChild(const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {child.getObject()});
}
Variant HTMLDocument::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {child});
}
Variant HTMLDocument::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {});
}
Variant HTMLDocument::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {});
}
Variant HTMLDocument::C14N(const Variant &exclusive,
                           const Variant &with_comments,
                           const Variant &xpath,
                           const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant HTMLDocument::C14NFile(const Variant &uri,
                               const Variant &exclusive,
                               const Variant &with_comments,
                               const Variant &xpath,
                               const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[376]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant HTMLDocument::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[395]);
    }
    return this_.call(_method_fn, {});
}
Variant HTMLDocument::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
XMLDocument::XMLDocument() {
    this_ = newObject(LITERAL_STRING[454]);
}
XMLDocument XMLDocument::createEmpty(const Variant &version, const Variant &encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[454], LITERAL_STRING[441]);
    }
    return XMLDocument(Object(php::call(_method_fn, {version, encoding})));
}
XMLDocument XMLDocument::createFromFile(const Variant &path, const Variant &options, const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[454], LITERAL_STRING[443]);
    }
    return XMLDocument(Object(php::call(_method_fn, {path, options, override_encoding})));
}
XMLDocument XMLDocument::createFromString(const Variant &source,
                                          const Variant &options,
                                          const Variant &override_encoding) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[454], LITERAL_STRING[445]);
    }
    return XMLDocument(Object(php::call(_method_fn, {source, options, override_encoding})));
}
EntityReference XMLDocument::createEntityReference(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[415]);
    }
    return EntityReference(Object(this_.call(_method_fn, {name})));
}
Variant XMLDocument::validate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[436]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLDocument::xinclude(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[437]);
    }
    return this_.call(_method_fn, {options});
}
Variant XMLDocument::saveXml(const Variant &node, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
    }
    return this_.call(_method_fn, {node, options});
}
Variant XMLDocument::saveXmlFile(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
    }
    return this_.call(_method_fn, {filename, options});
}
HTMLCollection XMLDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[419]);
    }
    return HTMLCollection(Object(this_.call(_method_fn, {qualified_name})));
}
HTMLCollection XMLDocument::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[420]);
    }
    return HTMLCollection(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Element XMLDocument::createElement(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[413]);
    }
    return Element(Object(this_.call(_method_fn, {local_name})));
}
Element XMLDocument::createElementNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[414]);
    }
    return Element(Object(this_.call(_method_fn, {namespace_, qualified_name})));
}
DocumentFragment XMLDocument::createDocumentFragment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[412]);
    }
    return DocumentFragment(Object(this_.call(_method_fn, {})));
}
Text XMLDocument::createTextNode(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[417]);
    }
    return Text(Object(this_.call(_method_fn, {data})));
}
CDATASection XMLDocument::createCDATASection(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[410]);
    }
    return CDATASection(Object(this_.call(_method_fn, {data})));
}
Comment XMLDocument::createComment(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return Comment(Object(this_.call(_method_fn, {data})));
}
ProcessingInstruction XMLDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[416]);
    }
    return ProcessingInstruction(Object(this_.call(_method_fn, {target, data})));
}
Variant XMLDocument::importNode(const Node &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[421]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant XMLDocument::importNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[421]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant XMLDocument::adoptNode(const Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant XMLDocument::adoptNode(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {node});
}
Attr XMLDocument::createAttribute(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[408]);
    }
    return Attr(Object(this_.call(_method_fn, {local_name})));
}
Attr XMLDocument::createAttributeNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[409]);
    }
    return Attr(Object(this_.call(_method_fn, {namespace_, qualified_name})));
}
Element XMLDocument::getElementById(const Variant &element_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[418]);
    }
    return Element(Object(this_.call(_method_fn, {element_id})));
}
Variant XMLDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[425]);
    }
    return this_.call(_method_fn, {base_class, extended_class});
}
Variant XMLDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[432]);
    }
    return this_.call(_method_fn, {filename, flags});
}
Variant XMLDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[433]);
    }
    return this_.call(_method_fn, {source, flags});
}
Variant XMLDocument::relaxNgValidate(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
    }
    return this_.call(_method_fn, {filename});
}
Variant XMLDocument::relaxNgValidateSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
    }
    return this_.call(_method_fn, {source});
}
Variant XMLDocument::importLegacyNode(const DOMNode &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[453]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant XMLDocument::importLegacyNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[453]);
    }
    return this_.call(_method_fn, {node, deep});
}
Element XMLDocument::querySelector(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[405]);
    }
    return Element(Object(this_.call(_method_fn, {selectors})));
}
NodeList XMLDocument::querySelectorAll(const Variant &selectors) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[406]);
    }
    return NodeList(Object(this_.call(_method_fn, {selectors})));
}
Variant XMLDocument::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return this_.call(_method_fn, {options});
}
Variant XMLDocument::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLDocument::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLDocument::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[377]);
    }
    return this_.call(_method_fn, {deep});
}
Variant XMLDocument::isEqualNode(const Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant XMLDocument::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant XMLDocument::isSameNode(const Node &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant XMLDocument::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant XMLDocument::compareDocumentPosition(const Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant XMLDocument::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {other});
}
Variant XMLDocument::contains(const Node &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant XMLDocument::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {other});
}
Variant XMLDocument::lookupPrefix(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[388]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant XMLDocument::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant XMLDocument::isDefaultNamespace(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant XMLDocument::insertBefore(const Node &node, const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant XMLDocument::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant XMLDocument::appendChild(const Node &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant XMLDocument::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
    }
    return this_.call(_method_fn, {node});
}
Variant XMLDocument::replaceChild(const Node &node, const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant XMLDocument::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant XMLDocument::removeChild(const Node &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {child.getObject()});
}
Variant XMLDocument::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {child});
}
Variant XMLDocument::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLDocument::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLDocument::C14N(const Variant &exclusive,
                          const Variant &with_comments,
                          const Variant &xpath,
                          const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
    }
    return this_.call(_method_fn, {exclusive, with_comments, xpath, ns_prefixes});
}
Variant XMLDocument::C14NFile(const Variant &uri,
                              const Variant &exclusive,
                              const Variant &with_comments,
                              const Variant &xpath,
                              const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[376]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant XMLDocument::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[395]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLDocument::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
Implementation::Implementation() {
    this_ = newObject(LITERAL_STRING[371]);
}
DocumentType Implementation::createDocumentType(const Variant &qualified_name,
                                                const Variant &public_id,
                                                const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[369]);
    }
    return DocumentType(Object(this_.call(_method_fn, {qualified_name, public_id, system_id})));
}
XMLDocument Implementation::createDocument(const Variant &namespace_,
                                           const Variant &qualified_name,
                                           const Variant &doctype) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[370]);
    }
    return XMLDocument(Object(this_.call(_method_fn, {namespace_, qualified_name, doctype})));
}
HTMLDocument Implementation::createHTMLDocument(const Variant &title) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
    }
    return HTMLDocument(Object(this_.call(_method_fn, {title})));
}
HTMLElement::HTMLElement() {
    this_ = newObject(LITERAL_STRING[509]);
}
}  // namespace php::Dom
namespace php {
DOMException::DOMException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[366], {message, code, previous});
}
DOMNode::DOMNode() {
    this_ = newObject(LITERAL_STRING[373]);
}
Variant DOMNode::appendChild(const DOMNode &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
    }
    return this_.call(_method_fn, {node.getObject()});
}
Variant DOMNode::appendChild(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMNode::C14N(const Variant &exclusive,
                      const Variant &with_comments,
                      const Variant &xpath,
                      const Variant &ns_prefixes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[376]);
    }
    return this_.call(_method_fn, {uri, exclusive, with_comments, xpath, ns_prefixes});
}
Variant DOMNode::cloneNode(const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[377]);
    }
    return this_.call(_method_fn, {deep});
}
Variant DOMNode::getLineNo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[378]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::getNodePath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[379]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::hasAttributes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[380]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::hasChildNodes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[381]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::insertBefore(const DOMNode &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {node.getObject(), child});
}
Variant DOMNode::insertBefore(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[382]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMNode::isDefaultNamespace(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[383]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant DOMNode::isSameNode(const DOMNode &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant DOMNode::isSameNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[384]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMNode::isEqualNode(const DOMNode &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {other_node.getObject()});
}
Variant DOMNode::isEqualNode(const Variant &other_node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[385]);
    }
    return this_.call(_method_fn, {other_node});
}
Variant DOMNode::isSupported(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[386]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMNode::lookupNamespaceURI(const Variant &prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[387]);
    }
    return this_.call(_method_fn, {prefix});
}
Variant DOMNode::lookupPrefix(const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[388]);
    }
    return this_.call(_method_fn, {namespace_});
}
Variant DOMNode::normalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[389]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::removeChild(const DOMNode &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {child.getObject()});
}
Variant DOMNode::removeChild(const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[390]);
    }
    return this_.call(_method_fn, {child});
}
Variant DOMNode::replaceChild(const DOMNode &node, const DOMNode &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {node.getObject(), child.getObject()});
}
Variant DOMNode::replaceChild(const Variant &node, const Variant &child) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[391]);
    }
    return this_.call(_method_fn, {node, child});
}
Variant DOMNode::contains(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {other});
}
DOMNode DOMNode::getRootNode(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[393]);
    }
    return DOMNode(Object(this_.call(_method_fn, {options})));
}
Variant DOMNode::compareDocumentPosition(const DOMNode &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {other.getObject()});
}
Variant DOMNode::compareDocumentPosition(const Variant &other) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[394]);
    }
    return this_.call(_method_fn, {other});
}
Variant DOMNode::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[395]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNode::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
DOMNameSpaceNode::DOMNameSpaceNode() {
    this_ = newObject(LITERAL_STRING[397]);
}
Variant DOMNameSpaceNode::__sleep() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[395]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNameSpaceNode::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
DOMDocumentFragment::DOMDocumentFragment() {
    this_ = newObject(LITERAL_STRING[398], {});
}
Variant DOMDocumentFragment::appendXML(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[399]);
    }
    return this_.call(_method_fn, {data});
}
DOMNodeList::DOMNodeList() {
    this_ = newObject(LITERAL_STRING[458]);
}
Variant DOMNodeList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNodeList::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNodeList::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {index});
}
DOMNamedNodeMap::DOMNamedNodeMap() {
    this_ = newObject(LITERAL_STRING[461]);
}
DOMNode DOMNamedNodeMap::getNamedItem(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[462]);
    }
    return DOMNode(Object(this_.call(_method_fn, {qualified_name})));
}
DOMNode DOMNamedNodeMap::getNamedItemNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[463]);
    }
    return DOMNode(Object(this_.call(_method_fn, {namespace_, local_name})));
}
DOMNode DOMNamedNodeMap::item(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return DOMNode(Object(this_.call(_method_fn, {index})));
}
Variant DOMNamedNodeMap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMNamedNodeMap::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
DOMCharacterData::DOMCharacterData() {
    this_ = newObject(LITERAL_STRING[468]);
}
Variant DOMCharacterData::appendData(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[469]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMCharacterData::substringData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[470]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMCharacterData::insertData(const Variant &offset, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[471]);
    }
    return this_.call(_method_fn, {offset, data});
}
Variant DOMCharacterData::deleteData(const Variant &offset, const Variant &count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[472]);
    }
    return this_.call(_method_fn, {offset, count});
}
Variant DOMCharacterData::replaceData(const Variant &offset, const Variant &count, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[473]);
    }
    return this_.call(_method_fn, {offset, count, data});
}
Variant DOMCharacterData::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {});
}
DOMAttr::DOMAttr(const Variant &name, const Variant &value) {
    this_ = newObject(LITERAL_STRING[479], {name, value});
}
Variant DOMAttr::isId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[480]);
    }
    return this_.call(_method_fn, {});
}
DOMElement::DOMElement(const Variant &qualified_name, const Variant &value, const Variant &namespace_) {
    this_ = newObject(LITERAL_STRING[483], {qualified_name, value, namespace_});
}
Variant DOMElement::getAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[484]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::getAttributeNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[485]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::getAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[486]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant DOMElement::getAttributeNode(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[487]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::getAttributeNodeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[488]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
DOMNodeList DOMElement::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[419]);
    }
    return DOMNodeList(Object(this_.call(_method_fn, {qualified_name})));
}
DOMNodeList DOMElement::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[420]);
    }
    return DOMNodeList(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Variant DOMElement::hasAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[489]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::hasAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[490]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant DOMElement::removeAttribute(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[491]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant DOMElement::removeAttributeNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[492]);
    }
    return this_.call(_method_fn, {namespace_, local_name});
}
Variant DOMElement::removeAttributeNode(const DOMAttr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[493]);
    }
    return this_.call(_method_fn, {attr.getObject()});
}
Variant DOMElement::removeAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[493]);
    }
    return this_.call(_method_fn, {attr});
}
Variant DOMElement::setAttribute(const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[494]);
    }
    return this_.call(_method_fn, {qualified_name, value});
}
Variant DOMElement::setAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[495]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, value});
}
Variant DOMElement::setAttributeNode(const DOMAttr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[496]);
    }
    return this_.call(_method_fn, {attr.getObject()});
}
Variant DOMElement::setAttributeNode(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[496]);
    }
    return this_.call(_method_fn, {attr});
}
Variant DOMElement::setAttributeNodeNS(const DOMAttr &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[497]);
    }
    return this_.call(_method_fn, {attr.getObject()});
}
Variant DOMElement::setAttributeNodeNS(const Variant &attr) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[497]);
    }
    return this_.call(_method_fn, {attr});
}
Variant DOMElement::setIdAttribute(const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[498]);
    }
    return this_.call(_method_fn, {qualified_name, is_id});
}
Variant DOMElement::setIdAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[499]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, is_id});
}
Variant DOMElement::setIdAttributeNode(const DOMAttr &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[500]);
    }
    return this_.call(_method_fn, {attr.getObject(), is_id});
}
Variant DOMElement::setIdAttributeNode(const Variant &attr, const Variant &is_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[500]);
    }
    return this_.call(_method_fn, {attr, is_id});
}
Variant DOMElement::toggleAttribute(const Variant &qualified_name, const Variant &force) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[501]);
    }
    return this_.call(_method_fn, {qualified_name, force});
}
Variant DOMElement::remove() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[475]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMElement::insertAdjacentElement(const Variant &where, const DOMElement &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[502]);
    }
    return this_.call(_method_fn, {where, element.getObject()});
}
Variant DOMElement::insertAdjacentElement(const Variant &where, const Variant &element) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[502]);
    }
    return this_.call(_method_fn, {where, element});
}
Variant DOMElement::insertAdjacentText(const Variant &where, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[503]);
    }
    return this_.call(_method_fn, {where, data});
}
DOMText::DOMText(const Variant &data) {
    this_ = newObject(LITERAL_STRING[510], {data});
}
Variant DOMText::isWhitespaceInElementContent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[511]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::isElementContentWhitespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[512]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMText::splitText(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[513]);
    }
    return this_.call(_method_fn, {offset});
}
DOMComment::DOMComment(const Variant &data) {
    this_ = newObject(LITERAL_STRING[515], {data});
}
DOMDocument::DOMDocument(const Variant &version, const Variant &encoding) {
    this_ = newObject(LITERAL_STRING[407], {version, encoding});
}
Variant DOMDocument::createAttribute(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[408]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant DOMDocument::createAttributeNS(const Variant &namespace_, const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[409]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name});
}
Variant DOMDocument::createCDATASection(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[410]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMDocument::createComment(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[411]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMDocument::createDocumentFragment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[412]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::createElement(const Variant &local_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[413]);
    }
    return this_.call(_method_fn, {local_name, value});
}
Variant DOMDocument::createElementNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[414]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, value});
}
Variant DOMDocument::createEntityReference(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[415]);
    }
    return this_.call(_method_fn, {name});
}
Variant DOMDocument::createProcessingInstruction(const Variant &target, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[416]);
    }
    return this_.call(_method_fn, {target, data});
}
Variant DOMDocument::createTextNode(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[417]);
    }
    return this_.call(_method_fn, {data});
}
Variant DOMDocument::getElementById(const Variant &element_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[418]);
    }
    return this_.call(_method_fn, {element_id});
}
DOMNodeList DOMDocument::getElementsByTagName(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[419]);
    }
    return DOMNodeList(Object(this_.call(_method_fn, {qualified_name})));
}
DOMNodeList DOMDocument::getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[420]);
    }
    return DOMNodeList(Object(this_.call(_method_fn, {namespace_, local_name})));
}
Variant DOMDocument::importNode(const DOMNode &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[421]);
    }
    return this_.call(_method_fn, {node.getObject(), deep});
}
Variant DOMDocument::importNode(const Variant &node, const Variant &deep) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[421]);
    }
    return this_.call(_method_fn, {node, deep});
}
Variant DOMDocument::load(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[422]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant DOMDocument::loadXML(const Variant &source, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[423]);
    }
    return this_.call(_method_fn, {source, options});
}
Variant DOMDocument::normalizeDocument() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[424]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::registerNodeClass(const Variant &base_class, const Variant &extended_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[425]);
    }
    return this_.call(_method_fn, {base_class, extended_class});
}
Variant DOMDocument::save(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[426]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant DOMDocument::loadHTML(const Variant &source, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[427]);
    }
    return this_.call(_method_fn, {source, options});
}
Variant DOMDocument::loadHTMLFile(const Variant &filename, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[428]);
    }
    return this_.call(_method_fn, {filename, options});
}
Variant DOMDocument::saveHTML(const Variant &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[429]);
    }
    return this_.call(_method_fn, {node});
}
Variant DOMDocument::saveHTMLFile(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[430]);
    }
    return this_.call(_method_fn, {filename});
}
Variant DOMDocument::saveXML(const Variant &node, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[431]);
    }
    return this_.call(_method_fn, {node, options});
}
Variant DOMDocument::schemaValidate(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[432]);
    }
    return this_.call(_method_fn, {filename, flags});
}
Variant DOMDocument::schemaValidateSource(const Variant &source, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[433]);
    }
    return this_.call(_method_fn, {source, flags});
}
Variant DOMDocument::relaxNGValidate(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[434]);
    }
    return this_.call(_method_fn, {filename});
}
Variant DOMDocument::relaxNGValidateSource(const Variant &source) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[435]);
    }
    return this_.call(_method_fn, {source});
}
Variant DOMDocument::validate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[436]);
    }
    return this_.call(_method_fn, {});
}
Variant DOMDocument::xinclude(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[437]);
    }
    return this_.call(_method_fn, {options});
}
DOMNode DOMDocument::adoptNode(const DOMNode &node) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[438]);
    }
    return this_.call(_method_fn, {node});
}
DOMCdataSection::DOMCdataSection(const Variant &data) {
    this_ = newObject(LITERAL_STRING[517], {data});
}
DOMDocumentType::DOMDocumentType() {
    this_ = newObject(LITERAL_STRING[519]);
}
DOMImplementation::DOMImplementation() {
    this_ = newObject(LITERAL_STRING[367]);
}
Variant DOMImplementation::hasFeature(const Variant &feature, const Variant &version) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[368]);
    }
    return this_.call(_method_fn, {feature, version});
}
Variant DOMImplementation::createDocumentType(const Variant &qualified_name,
                                              const Variant &public_id,
                                              const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[369]);
    }
    return this_.call(_method_fn, {qualified_name, public_id, system_id});
}
Variant DOMImplementation::createDocument(const Variant &namespace_,
                                          const Variant &qualified_name,
                                          const Variant &doctype) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[370]);
    }
    return this_.call(_method_fn, {namespace_, qualified_name, doctype});
}
DOMNotation::DOMNotation() {
    this_ = newObject(LITERAL_STRING[521]);
}
DOMEntity::DOMEntity() {
    this_ = newObject(LITERAL_STRING[523]);
}
DOMEntityReference::DOMEntityReference(const Variant &name) {
    this_ = newObject(LITERAL_STRING[525], {name});
}
DOMProcessingInstruction::DOMProcessingInstruction(const Variant &name, const Variant &value) {
    this_ = newObject(LITERAL_STRING[527], {name, value});
}
DOMXPath::DOMXPath(const DOMDocument &document, const Variant &register_node_n_s) {
    this_ = newObject(LITERAL_STRING[529], {document.getObject(), register_node_n_s});
}
Variant DOMXPath::evaluate(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[530]);
    }
    return this_.call(_method_fn, {expression, context_node, register_node_n_s});
}
Variant DOMXPath::query(const Variant &expression, const Variant &context_node, const Variant &register_node_n_s) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[531]);
    }
    return this_.call(_method_fn, {expression, context_node, register_node_n_s});
}
Variant DOMXPath::registerNamespace(const Variant &prefix, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[532]);
    }
    return this_.call(_method_fn, {prefix, namespace_});
}
Variant DOMXPath::registerPhpFunctions(const Variant &restrict) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[533]);
    }
    return this_.call(_method_fn, {restrict});
}
Variant DOMXPath::registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[534]);
    }
    return this_.call(_method_fn, {namespace_u_r_i, name, callable});
}
Variant DOMXPath::quote(const Variant &str) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[529], LITERAL_STRING[536]);
    }
    return php::call(_method_fn, {str});
}
}  // namespace php

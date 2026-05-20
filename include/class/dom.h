#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class Dom_AdjacentPosition {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_AdjacentPosition(const Object &obj) : this_(obj) {}
    Dom_AdjacentPosition();
    static Variant cases();
    static Variant from(const Variant &value);
    static Variant tryFrom(const Variant &value);
};

class DOMException {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class dom_domexception {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    dom_domexception(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class DOMNode {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMNode(const Object &obj) : this_(obj) {}
    DOMNode();
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Node {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMNameSpaceNode {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMNameSpaceNode(const Object &obj) : this_(obj) {}
    DOMNameSpaceNode();
    Variant __sleep();
    Variant __wakeup();
};

class DOMDocumentFragment {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMDocumentFragment();
    Variant appendXML(const Variant &data);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class DOMDocument {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMDocument(const Variant &version = "1.0", const Variant &encoding = "");
    Variant createAttribute(const Variant &local_name);
    Variant createAttributeNS(const Variant &_namespace, const Variant &qualified_name);
    Variant createCDATASection(const Variant &data);
    Variant createComment(const Variant &data);
    Variant createDocumentFragment();
    Variant createElement(const Variant &local_name, const Variant &value = "");
    Variant createElementNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value = "");
    Variant createEntityReference(const Variant &name);
    Variant createProcessingInstruction(const Variant &target, const Variant &data = "");
    Variant createTextNode(const Variant &data);
    Variant getElementById(const Variant &element_id);
    Variant getElementsByTagName(const Variant &qualified_name);
    Variant getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Variant importNode(const DOMNode &node, const Variant &deep = false);
    Variant importNode(const Variant &node, const Variant &deep = false);
    Variant load(const Variant &filename, const Variant &options = 0);
    Variant loadXML(const Variant &source, const Variant &options = 0);
    Variant normalizeDocument();
    Variant registerNodeClass(const Variant &base_class, const Variant &extended_class);
    Variant save(const Variant &filename, const Variant &options = 0);
    Variant loadHTML(const Variant &source, const Variant &options = 0);
    Variant loadHTMLFile(const Variant &filename, const Variant &options = 0);
    Variant saveHTML(const Variant &node = {});
    Variant saveHTMLFile(const Variant &filename);
    Variant saveXML(const Variant &node = {}, const Variant &options = 0);
    Variant schemaValidate(const Variant &filename, const Variant &flags = 0);
    Variant schemaValidateSource(const Variant &source, const Variant &flags = 0);
    Variant relaxNGValidate(const Variant &filename);
    Variant relaxNGValidateSource(const Variant &source);
    Variant validate();
    Variant xinclude(const Variant &options = 0);
    Variant adoptNode(const DOMNode &node);
    Variant adoptNode(const Variant &node);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class DOMNodeList {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMNodeList(const Object &obj) : this_(obj) {}
    DOMNodeList();
    Variant count();
    Variant getIterator();
    Variant item(const Variant &index);
};

class Dom_NodeList {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_NodeList(const Object &obj) : this_(obj) {}
    Dom_NodeList();
    Variant count();
    Variant getIterator();
    Variant item(const Variant &index);
};

class DOMNamedNodeMap {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMNamedNodeMap(const Object &obj) : this_(obj) {}
    DOMNamedNodeMap();
    Variant getNamedItem(const Variant &qualified_name);
    Variant getNamedItemNS(const Variant &_namespace, const Variant &local_name);
    Variant item(const Variant &index);
    Variant count();
    Variant getIterator();
};

class DOMCharacterData {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMCharacterData(const Object &obj) : this_(obj) {}
    DOMCharacterData();
    Variant appendData(const Variant &data);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_CharacterData {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_CharacterData(const Object &obj) : this_(obj) {}
    Dom_CharacterData();
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMAttr {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMAttr(const Variant &name, const Variant &value = "");
    Variant isId();
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Attr {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_Attr(const Object &obj) : this_(obj) {}
    Dom_Attr();
    Variant isId();
    Variant rename(const Variant &namespace_u_r_i, const Variant &qualified_name);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class Dom_NamedNodeMap {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_NamedNodeMap(const Object &obj) : this_(obj) {}
    Dom_NamedNodeMap();
    Dom_Attr item(const Variant &index);
    Dom_Attr getNamedItem(const Variant &qualified_name);
    Dom_Attr getNamedItemNS(const Variant &_namespace, const Variant &local_name);
    Variant count();
    Variant getIterator();
};

class DOMElement {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMElement(const Variant &qualified_name, const Variant &value = {}, const Variant &_namespace = "");
    Variant getAttribute(const Variant &qualified_name);
    Variant getAttributeNames();
    Variant getAttributeNS(const Variant &_namespace, const Variant &local_name);
    Variant getAttributeNode(const Variant &qualified_name);
    Variant getAttributeNodeNS(const Variant &_namespace, const Variant &local_name);
    Variant getElementsByTagName(const Variant &qualified_name);
    Variant getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Variant hasAttribute(const Variant &qualified_name);
    Variant hasAttributeNS(const Variant &_namespace, const Variant &local_name);
    Variant removeAttribute(const Variant &qualified_name);
    Variant removeAttributeNS(const Variant &_namespace, const Variant &local_name);
    Variant removeAttributeNode(const DOMAttr &attr);
    Variant removeAttributeNode(const Variant &attr);
    Variant setAttribute(const Variant &qualified_name, const Variant &value);
    Variant setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value);
    Variant setAttributeNode(const DOMAttr &attr);
    Variant setAttributeNode(const Variant &attr);
    Variant setAttributeNodeNS(const DOMAttr &attr);
    Variant setAttributeNodeNS(const Variant &attr);
    Variant setIdAttribute(const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNode(const DOMAttr &attr, const Variant &is_id);
    Variant setIdAttributeNode(const Variant &attr, const Variant &is_id);
    Variant toggleAttribute(const Variant &qualified_name, const Variant &force = {});
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant insertAdjacentElement(const Variant &where, const DOMElement &element);
    Variant insertAdjacentElement(const Variant &where, const Variant &element);
    Variant insertAdjacentText(const Variant &where, const Variant &data);
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class DOMText {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMText(const Variant &data = "");
    Variant isWhitespaceInElementContent();
    Variant isElementContentWhitespace();
    Variant splitText(const Variant &offset);
    Variant appendData(const Variant &data);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Text {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_Text(const Object &obj) : this_(obj) {}
    Dom_Text();
    Dom_Text splitText(const Variant &offset);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMComment {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMComment(const Variant &data = "");
    Variant appendData(const Variant &data);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Comment {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_Comment(const Object &obj) : this_(obj) {}
    Dom_Comment();
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMCdataSection {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMCdataSection(const Variant &data);
    Variant isWhitespaceInElementContent();
    Variant isElementContentWhitespace();
    Variant splitText(const Variant &offset);
    Variant appendData(const Variant &data);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_CDATASection {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_CDATASection(const Object &obj) : this_(obj) {}
    Dom_CDATASection();
    Dom_Text splitText(const Variant &offset);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMDocumentType {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMDocumentType(const Object &obj) : this_(obj) {}
    DOMDocumentType();
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class DOMImplementation {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMImplementation(const Object &obj) : this_(obj) {}
    DOMImplementation();
    Variant hasFeature(const Variant &feature, const Variant &version);
    Variant createDocumentType(const Variant &qualified_name,
                               const Variant &public_id = "",
                               const Variant &system_id = "");
    Variant createDocument(const Variant &_namespace = {},
                           const Variant &qualified_name = "",
                           const Variant &doctype = {});
};

class Dom_DocumentType {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_DocumentType(const Object &obj) : this_(obj) {}
    Dom_DocumentType();
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMNotation {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMNotation(const Object &obj) : this_(obj) {}
    DOMNotation();
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Notation {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_Notation(const Object &obj) : this_(obj) {}
    Dom_Notation();
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMEntity {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMEntity(const Object &obj) : this_(obj) {}
    DOMEntity();
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Entity {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_Entity(const Object &obj) : this_(obj) {}
    Dom_Entity();
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class Dom_DtdNamedNodeMap {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_DtdNamedNodeMap(const Object &obj) : this_(obj) {}
    Dom_DtdNamedNodeMap();
    Variant item(const Variant &index);
    Variant getNamedItem(const Variant &qualified_name);
    Variant getNamedItemNS(const Variant &_namespace, const Variant &local_name);
    Variant count();
    Variant getIterator();
};

class DOMEntityReference {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMEntityReference(const Variant &name);
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_EntityReference {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_EntityReference(const Object &obj) : this_(obj) {}
    Dom_EntityReference();
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMProcessingInstruction {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMProcessingInstruction(const Variant &name, const Variant &value = "");
    Variant appendChild(const DOMNode &node);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const DOMNode &node, const Variant &child = {});
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const DOMNode &child);
    Variant removeChild(const Variant &child);
    Variant replaceChild(const DOMNode &node, const DOMNode &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    DOMNode getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const DOMNode &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_ProcessingInstruction {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_ProcessingInstruction(const Object &obj) : this_(obj) {}
    Dom_ProcessingInstruction();
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMXPath {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DOMXPath(const DOMDocument &document, const Variant &register_node_n_s = true);
    Variant evaluate(const Variant &expression,
                     const Variant &context_node = {},
                     const Variant &register_node_n_s = true);
    Variant query(const Variant &expression, const Variant &context_node = {}, const Variant &register_node_n_s = true);
    Variant registerNamespace(const Variant &prefix, const Variant &_namespace);
    Variant registerPhpFunctions(const Variant &restrict = {});
    Variant registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable);
    static Variant quote(const Variant &str);
};

class Dom_XPath {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Dom_XPath(const Variant &document, const Variant &register_node_n_s = true);
    Variant evaluate(const Variant &expression,
                     const Variant &context_node = {},
                     const Variant &register_node_n_s = true);
    Dom_NodeList query(const Variant &expression,
                       const Variant &context_node = {},
                       const Variant &register_node_n_s = true);
    Variant registerNamespace(const Variant &prefix, const Variant &_namespace);
    Variant registerPhpFunctions(const Variant &restrict = {});
    Variant registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable);
    static Variant quote(const Variant &str);
};

class Dom_TokenList {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Variant item(const Variant &index);
    Variant contains(const Variant &token);
    template <typename... Args>
    Variant add(const Args &...tokens) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
        }
        return this_.call(_method_fn, {tokens...});
    }
    template <typename... Args>
    Variant remove(const Args &...tokens) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[450]);
        }
        return this_.call(_method_fn, {tokens...});
    }
    Variant toggle(const Variant &token, const Variant &force = {});
    Variant replace(const Variant &token, const Variant &new_token);
    Variant supports(const Variant &token);
    Variant count();
    Variant getIterator();
};

class Dom_DocumentFragment {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_DocumentFragment(const Object &obj) : this_(obj) {}
    Dom_DocumentFragment();
    Variant appendXml(const Variant &data);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant querySelector(const Variant &selectors);
    Dom_NodeList querySelectorAll(const Variant &selectors);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class Dom_HTMLCollection {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_HTMLCollection(const Object &obj) : this_(obj) {}
    Dom_HTMLCollection();
    Variant item(const Variant &index);
    Variant namedItem(const Variant &key);
    Variant count();
    Variant getIterator();
};

class Dom_Element {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_Element(const Object &obj) : this_(obj) {}
    Dom_Element();
    Variant hasAttributes();
    Variant getAttributeNames();
    Variant getAttribute(const Variant &qualified_name);
    Variant getAttributeNS(const Variant &_namespace, const Variant &local_name);
    Variant setAttribute(const Variant &qualified_name, const Variant &value);
    Variant setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value);
    Variant removeAttribute(const Variant &qualified_name);
    Variant removeAttributeNS(const Variant &_namespace, const Variant &local_name);
    Variant toggleAttribute(const Variant &qualified_name, const Variant &force = {});
    Variant hasAttribute(const Variant &qualified_name);
    Variant hasAttributeNS(const Variant &_namespace, const Variant &local_name);
    Dom_Attr getAttributeNode(const Variant &qualified_name);
    Dom_Attr getAttributeNodeNS(const Variant &_namespace, const Variant &local_name);
    Dom_Attr setAttributeNode(const Dom_Attr &attr);
    Variant setAttributeNode(const Variant &attr);
    Dom_Attr setAttributeNodeNS(const Dom_Attr &attr);
    Variant setAttributeNodeNS(const Variant &attr);
    Dom_Attr removeAttributeNode(const Dom_Attr &attr);
    Variant removeAttributeNode(const Variant &attr);
    Dom_HTMLCollection getElementsByTagName(const Variant &qualified_name);
    Dom_HTMLCollection getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Dom_Element insertAdjacentElement(const Dom_AdjacentPosition &where, const Dom_Element &element);
    Variant insertAdjacentElement(const Variant &where, const Variant &element);
    Variant insertAdjacentText(const Dom_AdjacentPosition &where, const Variant &data);
    Variant insertAdjacentText(const Variant &where, const Variant &data);
    Variant setIdAttribute(const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNode(const Dom_Attr &attr, const Variant &is_id);
    Variant setIdAttributeNode(const Variant &attr, const Variant &is_id);
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Dom_Element querySelector(const Variant &selectors);
    Dom_NodeList querySelectorAll(const Variant &selectors);
    Dom_Element closest(const Variant &selectors);
    Variant matches(const Variant &selectors);
    Variant getInScopeNamespaces();
    Variant getDescendantNamespaces();
    Variant rename(const Variant &namespace_u_r_i, const Variant &qualified_name);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class Dom_HTMLDocument {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_HTMLDocument(const Object &obj) : this_(obj) {}
    Dom_HTMLDocument();
    static Dom_HTMLDocument createEmpty(const Variant &encoding = "UTF-8");
    static Dom_HTMLDocument createFromFile(const Variant &path,
                                           const Variant &options = 0,
                                           const Variant &override_encoding = {});
    static Dom_HTMLDocument createFromString(const Variant &source,
                                             const Variant &options = 0,
                                             const Variant &override_encoding = {});
    Variant saveXml(const Variant &node = {}, const Variant &options = 0);
    Variant saveXmlFile(const Variant &filename, const Variant &options = 0);
    Variant saveHtml(const Variant &node = {});
    Variant saveHtmlFile(const Variant &filename);
    Variant debugGetTemplateCount();
    Dom_HTMLCollection getElementsByTagName(const Variant &qualified_name);
    Dom_HTMLCollection getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Dom_Element createElement(const Variant &local_name);
    Dom_Element createElementNS(const Variant &_namespace, const Variant &qualified_name);
    Dom_DocumentFragment createDocumentFragment();
    Dom_Text createTextNode(const Variant &data);
    Dom_CDATASection createCDATASection(const Variant &data);
    Dom_Comment createComment(const Variant &data);
    Dom_ProcessingInstruction createProcessingInstruction(const Variant &target, const Variant &data);
    Variant importNode(const Dom_Node &node, const Variant &deep = false);
    Variant importNode(const Variant &node, const Variant &deep = false);
    Variant adoptNode(const Dom_Node &node);
    Variant adoptNode(const Variant &node);
    Dom_Attr createAttribute(const Variant &local_name);
    Dom_Attr createAttributeNS(const Variant &_namespace, const Variant &qualified_name);
    Dom_Element getElementById(const Variant &element_id);
    Variant registerNodeClass(const Variant &base_class, const Variant &extended_class);
    Variant schemaValidate(const Variant &filename, const Variant &flags = 0);
    Variant schemaValidateSource(const Variant &source, const Variant &flags = 0);
    Variant relaxNgValidate(const Variant &filename);
    Variant relaxNgValidateSource(const Variant &source);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant importLegacyNode(const DOMNode &node, const Variant &deep = false);
    Variant importLegacyNode(const Variant &node, const Variant &deep = false);
    Dom_Element querySelector(const Variant &selectors);
    Dom_NodeList querySelectorAll(const Variant &selectors);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class Dom_XMLDocument {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_XMLDocument(const Object &obj) : this_(obj) {}
    Dom_XMLDocument();
    static Dom_XMLDocument createEmpty(const Variant &version = "1.0", const Variant &encoding = "UTF-8");
    static Dom_XMLDocument createFromFile(const Variant &path,
                                          const Variant &options = 0,
                                          const Variant &override_encoding = {});
    static Dom_XMLDocument createFromString(const Variant &source,
                                            const Variant &options = 0,
                                            const Variant &override_encoding = {});
    Dom_EntityReference createEntityReference(const Variant &name);
    Variant validate();
    Variant xinclude(const Variant &options = 0);
    Variant saveXml(const Variant &node = {}, const Variant &options = 0);
    Variant saveXmlFile(const Variant &filename, const Variant &options = 0);
    Dom_HTMLCollection getElementsByTagName(const Variant &qualified_name);
    Dom_HTMLCollection getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Dom_Element createElement(const Variant &local_name);
    Dom_Element createElementNS(const Variant &_namespace, const Variant &qualified_name);
    Dom_DocumentFragment createDocumentFragment();
    Dom_Text createTextNode(const Variant &data);
    Dom_CDATASection createCDATASection(const Variant &data);
    Dom_Comment createComment(const Variant &data);
    Dom_ProcessingInstruction createProcessingInstruction(const Variant &target, const Variant &data);
    Variant importNode(const Dom_Node &node, const Variant &deep = false);
    Variant importNode(const Variant &node, const Variant &deep = false);
    Variant adoptNode(const Dom_Node &node);
    Variant adoptNode(const Variant &node);
    Dom_Attr createAttribute(const Variant &local_name);
    Dom_Attr createAttributeNS(const Variant &_namespace, const Variant &qualified_name);
    Dom_Element getElementById(const Variant &element_id);
    Variant registerNodeClass(const Variant &base_class, const Variant &extended_class);
    Variant schemaValidate(const Variant &filename, const Variant &flags = 0);
    Variant schemaValidateSource(const Variant &source, const Variant &flags = 0);
    Variant relaxNgValidate(const Variant &filename);
    Variant relaxNgValidateSource(const Variant &source);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant importLegacyNode(const DOMNode &node, const Variant &deep = false);
    Variant importLegacyNode(const Variant &node, const Variant &deep = false);
    Dom_Element querySelector(const Variant &selectors);
    Dom_NodeList querySelectorAll(const Variant &selectors);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Implementation {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_Implementation(const Object &obj) : this_(obj) {}
    Dom_Implementation();
    Dom_DocumentType createDocumentType(const Variant &qualified_name,
                                        const Variant &public_id,
                                        const Variant &system_id);
    Dom_XMLDocument createDocument(const Variant &_namespace,
                                   const Variant &qualified_name,
                                   const Variant &doctype = {});
    Dom_HTMLDocument createHTMLDocument(const Variant &title = {});
};

class Dom_HTMLElement {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Dom_HTMLElement(const Object &obj) : this_(obj) {}
    Dom_HTMLElement();
    Variant hasAttributes();
    Variant getAttributeNames();
    Variant getAttribute(const Variant &qualified_name);
    Variant getAttributeNS(const Variant &_namespace, const Variant &local_name);
    Variant setAttribute(const Variant &qualified_name, const Variant &value);
    Variant setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value);
    Variant removeAttribute(const Variant &qualified_name);
    Variant removeAttributeNS(const Variant &_namespace, const Variant &local_name);
    Variant toggleAttribute(const Variant &qualified_name, const Variant &force = {});
    Variant hasAttribute(const Variant &qualified_name);
    Variant hasAttributeNS(const Variant &_namespace, const Variant &local_name);
    Dom_Attr getAttributeNode(const Variant &qualified_name);
    Dom_Attr getAttributeNodeNS(const Variant &_namespace, const Variant &local_name);
    Dom_Attr setAttributeNode(const Dom_Attr &attr);
    Variant setAttributeNode(const Variant &attr);
    Dom_Attr setAttributeNodeNS(const Dom_Attr &attr);
    Variant setAttributeNodeNS(const Variant &attr);
    Dom_Attr removeAttributeNode(const Dom_Attr &attr);
    Variant removeAttributeNode(const Variant &attr);
    Dom_HTMLCollection getElementsByTagName(const Variant &qualified_name);
    Dom_HTMLCollection getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Dom_Element insertAdjacentElement(const Dom_AdjacentPosition &where, const Dom_Element &element);
    Variant insertAdjacentElement(const Variant &where, const Variant &element);
    Variant insertAdjacentText(const Dom_AdjacentPosition &where, const Variant &data);
    Variant insertAdjacentText(const Variant &where, const Variant &data);
    Variant setIdAttribute(const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNode(const Dom_Attr &attr, const Variant &is_id);
    Variant setIdAttributeNode(const Variant &attr, const Variant &is_id);
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[451]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[452]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[375]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Dom_Element querySelector(const Variant &selectors);
    Dom_NodeList querySelectorAll(const Variant &selectors);
    Dom_Element closest(const Variant &selectors);
    Variant matches(const Variant &selectors);
    Variant getInScopeNamespaces();
    Variant getDescendantNamespaces();
    Variant rename(const Variant &namespace_u_r_i, const Variant &qualified_name);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Dom_Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Dom_Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Dom_Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Dom_Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Dom_Node &node, const Dom_Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Dom_Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Dom_Node &node, const Dom_Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Dom_Node &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false,
                 const Variant &with_comments = false,
                 const Variant &xpath = {},
                 const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri,
                     const Variant &exclusive = false,
                     const Variant &with_comments = false,
                     const Variant &xpath = {},
                     const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

}  // namespace php

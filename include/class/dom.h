#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
namespace Dom {
class AdjacentPosition;
class Node;
class NodeList;
class CharacterData;
class Attr;
class NamedNodeMap;
class Text;
class Comment;
class CDATASection;
class DocumentType;
class Notation;
class Entity;
class DtdNamedNodeMap;
class EntityReference;
class ProcessingInstruction;
class XPath;
class TokenList;
class DocumentFragment;
class HTMLCollection;
class Element;
class HTMLDocument;
class XMLDocument;
class Implementation;
class HTMLElement;
}  // namespace Dom
class DOMException;
class DOMNode;
class DOMNameSpaceNode;
class DOMDocumentFragment;
class DOMNodeList;
class DOMNamedNodeMap;
class DOMCharacterData;
class DOMAttr;
class DOMElement;
class DOMText;
class DOMComment;
class DOMDocument;
class DOMCdataSection;
class DOMDocumentType;
class DOMImplementation;
class DOMNotation;
class DOMEntity;
class DOMEntityReference;
class DOMProcessingInstruction;
class DOMXPath;

namespace Dom {

class AdjacentPosition {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit AdjacentPosition(const Object &obj) : this_(obj) {}
    AdjacentPosition();
    static Variant cases();
    static Variant from(const Variant &value);
    static Variant tryFrom(const Variant &value);
};

class Node {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int DOCUMENT_POSITION_DISCONNECTED = 1;
    static constexpr int DOCUMENT_POSITION_PRECEDING = 2;
    static constexpr int DOCUMENT_POSITION_FOLLOWING = 4;
    static constexpr int DOCUMENT_POSITION_CONTAINS = 8;
    static constexpr int DOCUMENT_POSITION_CONTAINED_BY = 16;
    static constexpr int DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 32;

    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &namespace_);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &namespace_);
    Variant insertBefore(const Node &node, const Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Node &node, const Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Node &child);
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

class NodeList {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit NodeList(const Object &obj) : this_(obj) {}
    NodeList();
    Variant count();
    Variant getIterator();
    Variant item(const Variant &index);
};

class CharacterData : public Node {
  public:
    explicit CharacterData(const Object &obj) {
        this_ = obj;
    }
    CharacterData();
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
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
        }
        return this_.call(_method_fn, {nodes...});
    }
};

class Attr : public Node {
  public:
    explicit Attr(const Object &obj) {
        this_ = obj;
    }
    Attr();
    Variant isId();
    Variant rename(const Variant &namespace_u_r_i, const Variant &qualified_name);
};

class NamedNodeMap {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit NamedNodeMap(const Object &obj) : this_(obj) {}
    NamedNodeMap();
    Attr item(const Variant &index);
    Attr getNamedItem(const Variant &qualified_name);
    Attr getNamedItemNS(const Variant &namespace_, const Variant &local_name);
    Variant count();
    Variant getIterator();
};

class Text : public CharacterData {
  public:
    explicit Text(const Object &obj) : CharacterData(obj) {}
    Text();
    Text splitText(const Variant &offset);
};

class Comment : public CharacterData {
  public:
    explicit Comment(const Object &obj) : CharacterData(obj) {}
    Comment();
};

class CDATASection : public Text {
  public:
    explicit CDATASection(const Object &obj) : Text(obj) {}
    CDATASection();
};

class DocumentType : public Node {
  public:
    explicit DocumentType(const Object &obj) {
        this_ = obj;
    }
    DocumentType();
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
        }
        return this_.call(_method_fn, {nodes...});
    }
};

class Notation : public Node {
  public:
    explicit Notation(const Object &obj) {
        this_ = obj;
    }
    Notation();
};

class Entity : public Node {
  public:
    explicit Entity(const Object &obj) {
        this_ = obj;
    }
    Entity();
};

class DtdNamedNodeMap {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DtdNamedNodeMap(const Object &obj) : this_(obj) {}
    DtdNamedNodeMap();
    Variant item(const Variant &index);
    Variant getNamedItem(const Variant &qualified_name);
    Variant getNamedItemNS(const Variant &namespace_, const Variant &local_name);
    Variant count();
    Variant getIterator();
};

class EntityReference : public Node {
  public:
    explicit EntityReference(const Object &obj) {
        this_ = obj;
    }
    EntityReference();
};

class ProcessingInstruction : public CharacterData {
  public:
    explicit ProcessingInstruction(const Object &obj) : CharacterData(obj) {}
    ProcessingInstruction();
};

class XPath {
  protected:
    Object this_;
    XPath() = default;

  public:
    Object getObject() const {
        return this_;
    }
    XPath(const Variant &document, const Variant &register_node_n_s = true);
    Variant evaluate(const Variant &expression,
                     const Variant &context_node = {},
                     const Variant &register_node_n_s = true);
    NodeList query(const Variant &expression,
                   const Variant &context_node = {},
                   const Variant &register_node_n_s = true);
    Variant registerNamespace(const Variant &prefix, const Variant &namespace_);
    Variant registerPhpFunctions(const Variant &restrict = {});
    Variant registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable);
    static Variant quote(const Variant &str);
};

class TokenList {
  protected:
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
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[447]);
        }
        return this_.call(_method_fn, {tokens...});
    }
    Variant toggle(const Variant &token, const Variant &force = {});
    Variant replace(const Variant &token, const Variant &new_token);
    Variant supports(const Variant &token);
    Variant count();
    Variant getIterator();
};

class DocumentFragment : public Node {
  public:
    explicit DocumentFragment(const Object &obj) {
        this_ = obj;
    }
    DocumentFragment();
    Variant appendXml(const Variant &data);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Element querySelector(const Variant &selectors);
    NodeList querySelectorAll(const Variant &selectors);
};

class HTMLCollection {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit HTMLCollection(const Object &obj) : this_(obj) {}
    HTMLCollection();
    Element item(const Variant &index);
    Element namedItem(const Variant &key);
    Variant count();
    Variant getIterator();
};

class Element : public Node {
  public:
    explicit Element(const Object &obj) {
        this_ = obj;
    }
    Element();
    Variant hasAttributes();
    Variant getAttributeNames();
    Variant getAttribute(const Variant &qualified_name);
    Variant getAttributeNS(const Variant &namespace_, const Variant &local_name);
    Variant setAttribute(const Variant &qualified_name, const Variant &value);
    Variant setAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value);
    Variant removeAttribute(const Variant &qualified_name);
    Variant removeAttributeNS(const Variant &namespace_, const Variant &local_name);
    Variant toggleAttribute(const Variant &qualified_name, const Variant &force = {});
    Variant hasAttribute(const Variant &qualified_name);
    Variant hasAttributeNS(const Variant &namespace_, const Variant &local_name);
    Attr getAttributeNode(const Variant &qualified_name);
    Attr getAttributeNodeNS(const Variant &namespace_, const Variant &local_name);
    Attr setAttributeNode(const Attr &attr);
    Variant setAttributeNode(const Variant &attr);
    Attr setAttributeNodeNS(const Attr &attr);
    Variant setAttributeNodeNS(const Variant &attr);
    Attr removeAttributeNode(const Attr &attr);
    Variant removeAttributeNode(const Variant &attr);
    HTMLCollection getElementsByTagName(const Variant &qualified_name);
    HTMLCollection getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name);
    Element insertAdjacentElement(const AdjacentPosition &where, const Element &element);
    Variant insertAdjacentElement(const Variant &where, const Variant &element);
    Variant insertAdjacentText(const AdjacentPosition &where, const Variant &data);
    Variant insertAdjacentText(const Variant &where, const Variant &data);
    Variant setIdAttribute(const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNode(const Attr &attr, const Variant &is_id);
    Variant setIdAttributeNode(const Variant &attr, const Variant &is_id);
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Element querySelector(const Variant &selectors);
    NodeList querySelectorAll(const Variant &selectors);
    Element closest(const Variant &selectors);
    Variant matches(const Variant &selectors);
    Variant getInScopeNamespaces();
    Variant getDescendantNamespaces();
    Variant rename(const Variant &namespace_u_r_i, const Variant &qualified_name);
};

class HTMLDocument {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit HTMLDocument(const Object &obj) : this_(obj) {}
    HTMLDocument();
    static HTMLDocument createEmpty(const Variant &encoding = "UTF-8");
    static HTMLDocument createFromFile(const Variant &path,
                                       const Variant &options = 0,
                                       const Variant &override_encoding = {});
    static HTMLDocument createFromString(const Variant &source,
                                         const Variant &options = 0,
                                         const Variant &override_encoding = {});
    Variant saveXml(const Variant &node = {}, const Variant &options = 0);
    Variant saveXmlFile(const Variant &filename, const Variant &options = 0);
    Variant saveHtml(const Variant &node = {});
    Variant saveHtmlFile(const Variant &filename);
    Variant debugGetTemplateCount();
    HTMLCollection getElementsByTagName(const Variant &qualified_name);
    HTMLCollection getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name);
    Element createElement(const Variant &local_name);
    Element createElementNS(const Variant &namespace_, const Variant &qualified_name);
    DocumentFragment createDocumentFragment();
    Text createTextNode(const Variant &data);
    CDATASection createCDATASection(const Variant &data);
    Comment createComment(const Variant &data);
    ProcessingInstruction createProcessingInstruction(const Variant &target, const Variant &data);
    Variant importNode(const Node &node, const Variant &deep = false);
    Variant importNode(const Variant &node, const Variant &deep = false);
    Variant adoptNode(const Node &node);
    Variant adoptNode(const Variant &node);
    Attr createAttribute(const Variant &local_name);
    Attr createAttributeNS(const Variant &namespace_, const Variant &qualified_name);
    Element getElementById(const Variant &element_id);
    Variant registerNodeClass(const Variant &base_class, const Variant &extended_class);
    Variant schemaValidate(const Variant &filename, const Variant &flags = 0);
    Variant schemaValidateSource(const Variant &source, const Variant &flags = 0);
    Variant relaxNgValidate(const Variant &filename);
    Variant relaxNgValidateSource(const Variant &source);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant importLegacyNode(const DOMNode &node, const Variant &deep = false);
    Variant importLegacyNode(const Variant &node, const Variant &deep = false);
    Element querySelector(const Variant &selectors);
    NodeList querySelectorAll(const Variant &selectors);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &namespace_);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &namespace_);
    Variant insertBefore(const Node &node, const Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Node &node, const Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Node &child);
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

class XMLDocument {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit XMLDocument(const Object &obj) : this_(obj) {}
    XMLDocument();
    static XMLDocument createEmpty(const Variant &version = "1.0", const Variant &encoding = "UTF-8");
    static XMLDocument createFromFile(const Variant &path,
                                      const Variant &options = 0,
                                      const Variant &override_encoding = {});
    static XMLDocument createFromString(const Variant &source,
                                        const Variant &options = 0,
                                        const Variant &override_encoding = {});
    EntityReference createEntityReference(const Variant &name);
    Variant validate();
    Variant xinclude(const Variant &options = 0);
    Variant saveXml(const Variant &node = {}, const Variant &options = 0);
    Variant saveXmlFile(const Variant &filename, const Variant &options = 0);
    HTMLCollection getElementsByTagName(const Variant &qualified_name);
    HTMLCollection getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name);
    Element createElement(const Variant &local_name);
    Element createElementNS(const Variant &namespace_, const Variant &qualified_name);
    DocumentFragment createDocumentFragment();
    Text createTextNode(const Variant &data);
    CDATASection createCDATASection(const Variant &data);
    Comment createComment(const Variant &data);
    ProcessingInstruction createProcessingInstruction(const Variant &target, const Variant &data);
    Variant importNode(const Node &node, const Variant &deep = false);
    Variant importNode(const Variant &node, const Variant &deep = false);
    Variant adoptNode(const Node &node);
    Variant adoptNode(const Variant &node);
    Attr createAttribute(const Variant &local_name);
    Attr createAttributeNS(const Variant &namespace_, const Variant &qualified_name);
    Element getElementById(const Variant &element_id);
    Variant registerNodeClass(const Variant &base_class, const Variant &extended_class);
    Variant schemaValidate(const Variant &filename, const Variant &flags = 0);
    Variant schemaValidateSource(const Variant &source, const Variant &flags = 0);
    Variant relaxNgValidate(const Variant &filename);
    Variant relaxNgValidateSource(const Variant &source);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant importLegacyNode(const DOMNode &node, const Variant &deep = false);
    Variant importLegacyNode(const Variant &node, const Variant &deep = false);
    Element querySelector(const Variant &selectors);
    NodeList querySelectorAll(const Variant &selectors);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Node &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Node &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Node &other);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Node &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &namespace_);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &namespace_);
    Variant insertBefore(const Node &node, const Node &child);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Node &node);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Node &node, const Node &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Node &child);
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

class Implementation {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Implementation(const Object &obj) : this_(obj) {}
    Implementation();
    DocumentType createDocumentType(const Variant &qualified_name, const Variant &public_id, const Variant &system_id);
    XMLDocument createDocument(const Variant &namespace_, const Variant &qualified_name, const Variant &doctype = {});
    HTMLDocument createHTMLDocument(const Variant &title = {});
};

class HTMLElement : public Element {
  public:
    explicit HTMLElement(const Object &obj) : Element(obj) {}
    HTMLElement();
};

}  // namespace Dom

class DOMException : public Exception {
  public:
    DOMException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class DOMNode {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMNode(const Object &obj) : this_(obj) {}
    static constexpr int DOCUMENT_POSITION_DISCONNECTED = 1;
    static constexpr int DOCUMENT_POSITION_PRECEDING = 2;
    static constexpr int DOCUMENT_POSITION_FOLLOWING = 4;
    static constexpr int DOCUMENT_POSITION_CONTAINS = 8;
    static constexpr int DOCUMENT_POSITION_CONTAINED_BY = 16;
    static constexpr int DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 32;

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
    Variant isDefaultNamespace(const Variant &namespace_);
    Variant isSameNode(const DOMNode &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const DOMNode &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &namespace_);
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

class DOMNameSpaceNode {
  protected:
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

class DOMDocumentFragment : public DOMNode {
  public:
    DOMDocumentFragment();
    Variant appendXML(const Variant &data);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
};

class DOMNodeList {
  protected:
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

class DOMNamedNodeMap {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit DOMNamedNodeMap(const Object &obj) : this_(obj) {}
    DOMNamedNodeMap();
    DOMNode getNamedItem(const Variant &qualified_name);
    DOMNode getNamedItemNS(const Variant &namespace_, const Variant &local_name);
    DOMNode item(const Variant &index);
    Variant count();
    Variant getIterator();
};

class DOMCharacterData : public DOMNode {
  public:
    explicit DOMCharacterData(const Object &obj) : DOMNode(obj) {}
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
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
};

class DOMAttr : public DOMNode {
  protected:
    DOMAttr() = default;

  public:
    DOMAttr(const Variant &name, const Variant &value = "");
    Variant isId();
};

class DOMElement : public DOMNode {
  protected:
    DOMElement() = default;

  public:
    DOMElement(const Variant &qualified_name, const Variant &value = {}, const Variant &namespace_ = "");
    Variant getAttribute(const Variant &qualified_name);
    Variant getAttributeNames();
    Variant getAttributeNS(const Variant &namespace_, const Variant &local_name);
    Variant getAttributeNode(const Variant &qualified_name);
    Variant getAttributeNodeNS(const Variant &namespace_, const Variant &local_name);
    DOMNodeList getElementsByTagName(const Variant &qualified_name);
    DOMNodeList getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name);
    Variant hasAttribute(const Variant &qualified_name);
    Variant hasAttributeNS(const Variant &namespace_, const Variant &local_name);
    Variant removeAttribute(const Variant &qualified_name);
    Variant removeAttributeNS(const Variant &namespace_, const Variant &local_name);
    Variant removeAttributeNode(const DOMAttr &attr);
    Variant removeAttributeNode(const Variant &attr);
    Variant setAttribute(const Variant &qualified_name, const Variant &value);
    Variant setAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value);
    Variant setAttributeNode(const DOMAttr &attr);
    Variant setAttributeNode(const Variant &attr);
    Variant setAttributeNodeNS(const DOMAttr &attr);
    Variant setAttributeNodeNS(const Variant &attr);
    Variant setIdAttribute(const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNS(const Variant &namespace_, const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNode(const DOMAttr &attr, const Variant &is_id);
    Variant setIdAttributeNode(const Variant &attr, const Variant &is_id);
    Variant toggleAttribute(const Variant &qualified_name, const Variant &force = {});
    Variant remove();
    template <typename... Args>
    Variant before(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[448]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant after(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[449]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[446]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    Variant insertAdjacentElement(const Variant &where, const DOMElement &element);
    Variant insertAdjacentElement(const Variant &where, const Variant &element);
    Variant insertAdjacentText(const Variant &where, const Variant &data);
};

class DOMText : public DOMCharacterData {
  public:
    DOMText(const Variant &data = "");
    Variant isWhitespaceInElementContent();
    Variant isElementContentWhitespace();
    Variant splitText(const Variant &offset);
};

class DOMComment : public DOMCharacterData {
  public:
    DOMComment(const Variant &data = "");
};

class DOMDocument : public DOMNode {
  public:
    DOMDocument(const Variant &version = "1.0", const Variant &encoding = "");
    Variant createAttribute(const Variant &local_name);
    Variant createAttributeNS(const Variant &namespace_, const Variant &qualified_name);
    Variant createCDATASection(const Variant &data);
    Variant createComment(const Variant &data);
    Variant createDocumentFragment();
    Variant createElement(const Variant &local_name, const Variant &value = "");
    Variant createElementNS(const Variant &namespace_, const Variant &qualified_name, const Variant &value = "");
    Variant createEntityReference(const Variant &name);
    Variant createProcessingInstruction(const Variant &target, const Variant &data = "");
    Variant createTextNode(const Variant &data);
    Variant getElementById(const Variant &element_id);
    DOMNodeList getElementsByTagName(const Variant &qualified_name);
    DOMNodeList getElementsByTagNameNS(const Variant &namespace_, const Variant &local_name);
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
    DOMNode adoptNode(const DOMNode &node);
    Variant adoptNode(const Variant &node);
    template <typename... Args>
    Variant append(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[372]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[373]);
        }
        return this_.call(_method_fn, {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args &...nodes) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[374]);
        }
        return this_.call(_method_fn, {nodes...});
    }
};

class DOMCdataSection : public DOMText {
  protected:
    DOMCdataSection() = default;

  public:
    DOMCdataSection(const Variant &data);
};

class DOMDocumentType : public DOMNode {
  public:
    explicit DOMDocumentType(const Object &obj) : DOMNode(obj) {}
    DOMDocumentType();
};

class DOMImplementation {
  protected:
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
    Variant createDocument(const Variant &namespace_ = {},
                           const Variant &qualified_name = "",
                           const Variant &doctype = {});
};

class DOMNotation : public DOMNode {
  public:
    explicit DOMNotation(const Object &obj) : DOMNode(obj) {}
    DOMNotation();
};

class DOMEntity : public DOMNode {
  public:
    explicit DOMEntity(const Object &obj) : DOMNode(obj) {}
    DOMEntity();
};

class DOMEntityReference : public DOMNode {
  protected:
    DOMEntityReference() = default;

  public:
    DOMEntityReference(const Variant &name);
};

class DOMProcessingInstruction : public DOMNode {
  protected:
    DOMProcessingInstruction() = default;

  public:
    DOMProcessingInstruction(const Variant &name, const Variant &value = "");
};

class DOMXPath {
  protected:
    Object this_;
    DOMXPath() = default;

  public:
    Object getObject() const {
        return this_;
    }
    DOMXPath(const DOMDocument &document, const Variant &register_node_n_s = true);
    Variant evaluate(const Variant &expression,
                     const Variant &context_node = {},
                     const Variant &register_node_n_s = true);
    Variant query(const Variant &expression, const Variant &context_node = {}, const Variant &register_node_n_s = true);
    Variant registerNamespace(const Variant &prefix, const Variant &namespace_);
    Variant registerPhpFunctions(const Variant &restrict = {});
    Variant registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable);
    static Variant quote(const Variant &str);
};

}  // namespace php

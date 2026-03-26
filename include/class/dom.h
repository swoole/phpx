namespace php {
class Dom_AdjacentPosition {
    Object this_;
  public:
    static Variant cases();
    static Variant from(const Variant &value);
    static Variant tryFrom(const Variant &value);
};

class DOMException {
    Object this_;
  public:
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

class DOMImplementation {
    Object this_;
  public:
    Variant hasFeature(const Variant &feature, const Variant &version);
    Variant createDocumentType(const Variant &qualified_name, const Variant &public_id = "", const Variant &system_id = "");
    Variant createDocument(const Variant &_namespace = {}, const Variant &qualified_name = "", const Variant &doctype = {});
};

class Dom_Implementation {
    Object this_;
  public:
    Variant createDocumentType(const Variant &qualified_name, const Variant &public_id, const Variant &system_id);
    Variant createDocument(const Variant &_namespace, const Variant &qualified_name, const Variant &doctype = {});
    Variant createHTMLDocument(const Variant &title = {});
};

class DOMNode {
    Object this_;
  public:
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Node {
    Object this_;
  public:
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMNameSpaceNode {
    Object this_;
  public:
    Variant __sleep();
    Variant __wakeup();
};

class DOMDocumentFragment {
    Object this_;
  public:
    DOMDocumentFragment();
    Variant appendXML(const Variant &data);
    template <typename... Args>
    Variant append(const Args&... nodes) {
        return call("append", {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args&... nodes) {
        return call("prepend", {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args&... nodes) {
        return call("replaceChildren", {nodes...});
    }
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_DocumentFragment {
    Object this_;
  public:
    Variant appendXml(const Variant &data);
    template <typename... Args>
    Variant append(const Args&... nodes) {
        return call("append", {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args&... nodes) {
        return call("prepend", {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args&... nodes) {
        return call("replaceChildren", {nodes...});
    }
    Variant querySelector(const Variant &selectors);
    Variant querySelectorAll(const Variant &selectors);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMDocument {
    Object this_;
  public:
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
    Variant adoptNode(const Variant &node);
    template <typename... Args>
    Variant append(const Args&... nodes) {
        return call("append", {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args&... nodes) {
        return call("prepend", {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args&... nodes) {
        return call("replaceChildren", {nodes...});
    }
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_HTMLDocument {
    Object this_;
  public:
    static Variant createEmpty(const Variant &encoding = "UTF-8");
    static Variant createFromFile(const Variant &path, const Variant &options = 0, const Variant &override_encoding = {});
    static Variant createFromString(const Variant &source, const Variant &options = 0, const Variant &override_encoding = {});
    Variant saveXml(const Variant &node = {}, const Variant &options = 0);
    Variant saveXmlFile(const Variant &filename, const Variant &options = 0);
    Variant saveHtml(const Variant &node = {});
    Variant saveHtmlFile(const Variant &filename);
    Variant debugGetTemplateCount();
    Variant getElementsByTagName(const Variant &qualified_name);
    Variant getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Variant createElement(const Variant &local_name);
    Variant createElementNS(const Variant &_namespace, const Variant &qualified_name);
    Variant createDocumentFragment();
    Variant createTextNode(const Variant &data);
    Variant createCDATASection(const Variant &data);
    Variant createComment(const Variant &data);
    Variant createProcessingInstruction(const Variant &target, const Variant &data);
    Variant importNode(const Variant &node, const Variant &deep = false);
    Variant adoptNode(const Variant &node);
    Variant createAttribute(const Variant &local_name);
    Variant createAttributeNS(const Variant &_namespace, const Variant &qualified_name);
    Variant getElementById(const Variant &element_id);
    Variant registerNodeClass(const Variant &base_class, const Variant &extended_class);
    Variant schemaValidate(const Variant &filename, const Variant &flags = 0);
    Variant schemaValidateSource(const Variant &source, const Variant &flags = 0);
    Variant relaxNgValidate(const Variant &filename);
    Variant relaxNgValidateSource(const Variant &source);
    template <typename... Args>
    Variant append(const Args&... nodes) {
        return call("append", {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args&... nodes) {
        return call("prepend", {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args&... nodes) {
        return call("replaceChildren", {nodes...});
    }
    Variant importLegacyNode(const Variant &node, const Variant &deep = false);
    Variant querySelector(const Variant &selectors);
    Variant querySelectorAll(const Variant &selectors);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class Dom_XMLDocument {
    Object this_;
  public:
    static Variant createEmpty(const Variant &version = "1.0", const Variant &encoding = "UTF-8");
    static Variant createFromFile(const Variant &path, const Variant &options = 0, const Variant &override_encoding = {});
    static Variant createFromString(const Variant &source, const Variant &options = 0, const Variant &override_encoding = {});
    Variant createEntityReference(const Variant &name);
    Variant validate();
    Variant xinclude(const Variant &options = 0);
    Variant saveXml(const Variant &node = {}, const Variant &options = 0);
    Variant saveXmlFile(const Variant &filename, const Variant &options = 0);
    Variant getElementsByTagName(const Variant &qualified_name);
    Variant getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Variant createElement(const Variant &local_name);
    Variant createElementNS(const Variant &_namespace, const Variant &qualified_name);
    Variant createDocumentFragment();
    Variant createTextNode(const Variant &data);
    Variant createCDATASection(const Variant &data);
    Variant createComment(const Variant &data);
    Variant createProcessingInstruction(const Variant &target, const Variant &data);
    Variant importNode(const Variant &node, const Variant &deep = false);
    Variant adoptNode(const Variant &node);
    Variant createAttribute(const Variant &local_name);
    Variant createAttributeNS(const Variant &_namespace, const Variant &qualified_name);
    Variant getElementById(const Variant &element_id);
    Variant registerNodeClass(const Variant &base_class, const Variant &extended_class);
    Variant schemaValidate(const Variant &filename, const Variant &flags = 0);
    Variant schemaValidateSource(const Variant &source, const Variant &flags = 0);
    Variant relaxNgValidate(const Variant &filename);
    Variant relaxNgValidateSource(const Variant &source);
    template <typename... Args>
    Variant append(const Args&... nodes) {
        return call("append", {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args&... nodes) {
        return call("prepend", {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args&... nodes) {
        return call("replaceChildren", {nodes...});
    }
    Variant importLegacyNode(const Variant &node, const Variant &deep = false);
    Variant querySelector(const Variant &selectors);
    Variant querySelectorAll(const Variant &selectors);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMNodeList {
    Object this_;
  public:
    Variant count();
    Variant getIterator();
    Variant item(const Variant &index);
};

class Dom_NodeList {
    Object this_;
  public:
    Variant count();
    Variant getIterator();
    Variant item(const Variant &index);
};

class DOMNamedNodeMap {
    Object this_;
  public:
    Variant getNamedItem(const Variant &qualified_name);
    Variant getNamedItemNS(const Variant &_namespace, const Variant &local_name);
    Variant item(const Variant &index);
    Variant count();
    Variant getIterator();
};

class Dom_NamedNodeMap {
    Object this_;
  public:
    Variant item(const Variant &index);
    Variant getNamedItem(const Variant &qualified_name);
    Variant getNamedItemNS(const Variant &_namespace, const Variant &local_name);
    Variant count();
    Variant getIterator();
};

class Dom_DtdNamedNodeMap {
    Object this_;
  public:
    Variant item(const Variant &index);
    Variant getNamedItem(const Variant &qualified_name);
    Variant getNamedItemNS(const Variant &_namespace, const Variant &local_name);
    Variant count();
    Variant getIterator();
};

class Dom_HTMLCollection {
    Object this_;
  public:
    Variant item(const Variant &index);
    Variant namedItem(const Variant &key);
    Variant count();
    Variant getIterator();
};

class DOMCharacterData {
    Object this_;
  public:
    Variant appendData(const Variant &data);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_CharacterData {
    Object this_;
  public:
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMAttr {
    Object this_;
  public:
    DOMAttr(const Variant &name, const Variant &value = "");
    Variant isId();
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Attr {
    Object this_;
  public:
    Variant isId();
    Variant rename(const Variant &namespace_u_r_i, const Variant &qualified_name);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMElement {
    Object this_;
  public:
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
    Variant removeAttributeNode(const Variant &attr);
    Variant setAttribute(const Variant &qualified_name, const Variant &value);
    Variant setAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &value);
    Variant setAttributeNode(const Variant &attr);
    Variant setAttributeNodeNS(const Variant &attr);
    Variant setIdAttribute(const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNode(const Variant &attr, const Variant &is_id);
    Variant toggleAttribute(const Variant &qualified_name, const Variant &force = {});
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    template <typename... Args>
    Variant append(const Args&... nodes) {
        return call("append", {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args&... nodes) {
        return call("prepend", {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args&... nodes) {
        return call("replaceChildren", {nodes...});
    }
    Variant insertAdjacentElement(const Variant &where, const Variant &element);
    Variant insertAdjacentText(const Variant &where, const Variant &data);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Element {
    Object this_;
  public:
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
    Variant getAttributeNode(const Variant &qualified_name);
    Variant getAttributeNodeNS(const Variant &_namespace, const Variant &local_name);
    Variant setAttributeNode(const Variant &attr);
    Variant setAttributeNodeNS(const Variant &attr);
    Variant removeAttributeNode(const Variant &attr);
    Variant getElementsByTagName(const Variant &qualified_name);
    Variant getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Variant insertAdjacentElement(const Variant &where, const Variant &element);
    Variant insertAdjacentText(const Variant &where, const Variant &data);
    Variant setIdAttribute(const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNode(const Variant &attr, const Variant &is_id);
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    template <typename... Args>
    Variant append(const Args&... nodes) {
        return call("append", {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args&... nodes) {
        return call("prepend", {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args&... nodes) {
        return call("replaceChildren", {nodes...});
    }
    Variant querySelector(const Variant &selectors);
    Variant querySelectorAll(const Variant &selectors);
    Variant closest(const Variant &selectors);
    Variant matches(const Variant &selectors);
    Variant getInScopeNamespaces();
    Variant getDescendantNamespaces();
    Variant rename(const Variant &namespace_u_r_i, const Variant &qualified_name);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class Dom_HTMLElement {
    Object this_;
  public:
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
    Variant getAttributeNode(const Variant &qualified_name);
    Variant getAttributeNodeNS(const Variant &_namespace, const Variant &local_name);
    Variant setAttributeNode(const Variant &attr);
    Variant setAttributeNodeNS(const Variant &attr);
    Variant removeAttributeNode(const Variant &attr);
    Variant getElementsByTagName(const Variant &qualified_name);
    Variant getElementsByTagNameNS(const Variant &_namespace, const Variant &local_name);
    Variant insertAdjacentElement(const Variant &where, const Variant &element);
    Variant insertAdjacentText(const Variant &where, const Variant &data);
    Variant setIdAttribute(const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNS(const Variant &_namespace, const Variant &qualified_name, const Variant &is_id);
    Variant setIdAttributeNode(const Variant &attr, const Variant &is_id);
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    template <typename... Args>
    Variant append(const Args&... nodes) {
        return call("append", {nodes...});
    }
    template <typename... Args>
    Variant prepend(const Args&... nodes) {
        return call("prepend", {nodes...});
    }
    template <typename... Args>
    Variant replaceChildren(const Args&... nodes) {
        return call("replaceChildren", {nodes...});
    }
    Variant querySelector(const Variant &selectors);
    Variant querySelectorAll(const Variant &selectors);
    Variant closest(const Variant &selectors);
    Variant matches(const Variant &selectors);
    Variant getInScopeNamespaces();
    Variant getDescendantNamespaces();
    Variant rename(const Variant &namespace_u_r_i, const Variant &qualified_name);
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMText {
    Object this_;
  public:
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
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Text {
    Object this_;
  public:
    Variant splitText(const Variant &offset);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMComment {
    Object this_;
  public:
    DOMComment(const Variant &data = "");
    Variant appendData(const Variant &data);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Comment {
    Object this_;
  public:
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMCdataSection {
    Object this_;
  public:
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
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_CDATASection {
    Object this_;
  public:
    Variant splitText(const Variant &offset);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMDocumentType {
    Object this_;
  public:
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_DocumentType {
    Object this_;
  public:
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMNotation {
    Object this_;
  public:
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Notation {
    Object this_;
  public:
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMEntity {
    Object this_;
  public:
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_Entity {
    Object this_;
  public:
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMEntityReference {
    Object this_;
  public:
    DOMEntityReference(const Variant &name);
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_EntityReference {
    Object this_;
  public:
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMProcessingInstruction {
    Object this_;
  public:
    DOMProcessingInstruction(const Variant &name, const Variant &value = "");
    Variant appendChild(const Variant &node);
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant cloneNode(const Variant &deep = false);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const Variant &node, const Variant &child = {});
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant isSameNode(const Variant &other_node);
    Variant isEqualNode(const Variant &other_node);
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant contains(const Variant &other);
    Variant getRootNode(const Variant &options = {});
    Variant compareDocumentPosition(const Variant &other);
    Variant __sleep();
    Variant __wakeup();
};

class Dom_ProcessingInstruction {
    Object this_;
  public:
    Variant substringData(const Variant &offset, const Variant &count);
    Variant appendData(const Variant &data);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant remove();
    template <typename... Args>
    Variant before(const Args&... nodes) {
        return call("before", {nodes...});
    }
    template <typename... Args>
    Variant after(const Args&... nodes) {
        return call("after", {nodes...});
    }
    template <typename... Args>
    Variant replaceWith(const Args&... nodes) {
        return call("replaceWith", {nodes...});
    }
    Variant getRootNode(const Variant &options = Array{});
    Variant hasChildNodes();
    Variant normalize();
    Variant cloneNode(const Variant &deep = false);
    Variant isEqualNode(const Variant &other_node);
    Variant isSameNode(const Variant &other_node);
    Variant compareDocumentPosition(const Variant &other);
    Variant contains(const Variant &other);
    Variant lookupPrefix(const Variant &_namespace);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant isDefaultNamespace(const Variant &_namespace);
    Variant insertBefore(const Variant &node, const Variant &child);
    Variant appendChild(const Variant &node);
    Variant replaceChild(const Variant &node, const Variant &child);
    Variant removeChild(const Variant &child);
    Variant getLineNo();
    Variant getNodePath();
    Variant C14N(const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant C14NFile(const Variant &uri, const Variant &exclusive = false, const Variant &with_comments = false, const Variant &xpath = {}, const Variant &ns_prefixes = {});
    Variant __sleep();
    Variant __wakeup();
};

class DOMXPath {
    Object this_;
  public:
    DOMXPath(const Variant &document, const Variant &register_node_n_s = true);
    Variant evaluate(const Variant &expression, const Variant &context_node = {}, const Variant &register_node_n_s = true);
    Variant query(const Variant &expression, const Variant &context_node = {}, const Variant &register_node_n_s = true);
    Variant registerNamespace(const Variant &prefix, const Variant &_namespace);
    Variant registerPhpFunctions(const Variant &restrict = {});
    Variant registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable);
    static Variant quote(const Variant &str);
};

class Dom_XPath {
    Object this_;
  public:
    Dom_XPath(const Variant &document, const Variant &register_node_n_s = true);
    Variant evaluate(const Variant &expression, const Variant &context_node = {}, const Variant &register_node_n_s = true);
    Variant query(const Variant &expression, const Variant &context_node = {}, const Variant &register_node_n_s = true);
    Variant registerNamespace(const Variant &prefix, const Variant &_namespace);
    Variant registerPhpFunctions(const Variant &restrict = {});
    Variant registerPhpFunctionNS(const Variant &namespace_u_r_i, const Variant &name, const Variant &callable);
    static Variant quote(const Variant &str);
};

class Dom_TokenList {
    Object this_;
  public:
    Variant item(const Variant &index);
    Variant contains(const Variant &token);
    template <typename... Args>
    Variant add(const Args&... tokens) {
        return call("add", {tokens...});
    }
    template <typename... Args>
    Variant remove(const Args&... tokens) {
        return call("remove", {tokens...});
    }
    Variant toggle(const Variant &token, const Variant &force = {});
    Variant replace(const Variant &token, const Variant &new_token);
    Variant supports(const Variant &token);
    Variant count();
    Variant getIterator();
};

}

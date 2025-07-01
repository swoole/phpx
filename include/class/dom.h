namespace php {
class DOMException {
    Object _this;
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

class DOMImplementation {
    Object _this;
  public:
    Variant getFeature(const Variant &feature, const Variant &version);
    Variant hasFeature(const Variant &feature, const Variant &version);
    Variant createDocumentType(const Variant &qualified_name, const Variant &public_id = "", const Variant &system_id = "");
    Variant createDocument(const Variant &_namespace = {}, const Variant &qualified_name = "", const Variant &doctype = {});
};

class DOMNode {
    Object _this;
  public:
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMNameSpaceNode {
    Object _this;
  public:
    Variant __sleep();
    Variant __wakeup();
};

class DOMDocumentFragment {
    Object _this;
  public:
    DOMDocumentFragment();
    Variant appendXML(const Variant &data);
    Variant append(const Variant &nodes = {});
    Variant prepend(const Variant &nodes = {});
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMDocument {
    Object _this;
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
    Variant append(const Variant &nodes = {});
    Variant prepend(const Variant &nodes = {});
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMNodeList {
    Object _this;
  public:
    Variant count();
    Variant getIterator();
    Variant item(const Variant &index);
};

class DOMNamedNodeMap {
    Object _this;
  public:
    Variant getNamedItem(const Variant &qualified_name);
    Variant getNamedItemNS(const Variant &_namespace, const Variant &local_name);
    Variant item(const Variant &index);
    Variant count();
    Variant getIterator();
};

class DOMCharacterData {
    Object _this;
  public:
    Variant appendData(const Variant &data);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant replaceWith(const Variant &nodes = {});
    Variant remove();
    Variant before(const Variant &nodes = {});
    Variant after(const Variant &nodes = {});
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMAttr {
    Object _this;
  public:
    DOMAttr(const Variant &name, const Variant &value = "");
    Variant isId();
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMElement {
    Object _this;
  public:
    DOMElement(const Variant &qualified_name, const Variant &value = {}, const Variant &_namespace = "");
    Variant getAttribute(const Variant &qualified_name);
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
    Variant remove();
    Variant before(const Variant &nodes = {});
    Variant after(const Variant &nodes = {});
    Variant replaceWith(const Variant &nodes = {});
    Variant append(const Variant &nodes = {});
    Variant prepend(const Variant &nodes = {});
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMText {
    Object _this;
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
    Variant replaceWith(const Variant &nodes = {});
    Variant remove();
    Variant before(const Variant &nodes = {});
    Variant after(const Variant &nodes = {});
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMComment {
    Object _this;
  public:
    DOMComment(const Variant &data = "");
    Variant appendData(const Variant &data);
    Variant substringData(const Variant &offset, const Variant &count);
    Variant insertData(const Variant &offset, const Variant &data);
    Variant deleteData(const Variant &offset, const Variant &count);
    Variant replaceData(const Variant &offset, const Variant &count, const Variant &data);
    Variant replaceWith(const Variant &nodes = {});
    Variant remove();
    Variant before(const Variant &nodes = {});
    Variant after(const Variant &nodes = {});
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMCdataSection {
    Object _this;
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
    Variant replaceWith(const Variant &nodes = {});
    Variant remove();
    Variant before(const Variant &nodes = {});
    Variant after(const Variant &nodes = {});
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMDocumentType {
    Object _this;
  public:
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMNotation {
    Object _this;
  public:
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMEntity {
    Object _this;
  public:
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMEntityReference {
    Object _this;
  public:
    DOMEntityReference(const Variant &name);
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMProcessingInstruction {
    Object _this;
  public:
    DOMProcessingInstruction(const Variant &name, const Variant &value = "");
    Variant __sleep();
    Variant __wakeup();
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
    Variant isSupported(const Variant &feature, const Variant &version);
    Variant lookupNamespaceURI(const Variant &prefix);
    Variant lookupPrefix(const Variant &_namespace);
    Variant normalize();
    Variant removeChild(const Variant &child);
    Variant replaceChild(const Variant &node, const Variant &child);
};

class DOMXPath {
    Object _this;
  public:
    DOMXPath(const Variant &document, const Variant &register_node_n_s = true);
    Variant evaluate(const Variant &expression, const Variant &context_node = {}, const Variant &register_node_n_s = true);
    Variant query(const Variant &expression, const Variant &context_node = {}, const Variant &register_node_n_s = true);
    Variant registerNamespace(const Variant &prefix, const Variant &_namespace);
    Variant registerPhpFunctions(const Variant &restrict = {});
};

}

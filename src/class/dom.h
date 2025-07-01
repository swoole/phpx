namespace php {
class DOMException {
  private:
    Variant _this;
  public:
    DOMException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    Variant getFeature(const std::initializer_list<Variant> &args);
    Variant hasFeature(const std::initializer_list<Variant> &args);
    Variant createDocumentType(const std::initializer_list<Variant> &args);
    Variant createDocument(const std::initializer_list<Variant> &args);
};

class DOMNode {
  private:
    Variant _this;
  public:
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMNameSpaceNode {
  private:
    Variant _this;
  public:
    Variant __sleep();
    Variant __wakeup();
};

class DOMDocumentFragment {
  private:
    Variant _this;
  public:
    DOMDocumentFragment();
    Variant appendXML(const std::initializer_list<Variant> &args);
    Variant append(const std::initializer_list<Variant> &args);
    Variant prepend(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMDocument {
  private:
    Variant _this;
  public:
    DOMDocument(const std::initializer_list<Variant> &args);
    Variant createAttribute(const std::initializer_list<Variant> &args);
    Variant createAttributeNS(const std::initializer_list<Variant> &args);
    Variant createCDATASection(const std::initializer_list<Variant> &args);
    Variant createComment(const std::initializer_list<Variant> &args);
    Variant createDocumentFragment();
    Variant createElement(const std::initializer_list<Variant> &args);
    Variant createElementNS(const std::initializer_list<Variant> &args);
    Variant createEntityReference(const std::initializer_list<Variant> &args);
    Variant createProcessingInstruction(const std::initializer_list<Variant> &args);
    Variant createTextNode(const std::initializer_list<Variant> &args);
    Variant getElementById(const std::initializer_list<Variant> &args);
    Variant getElementsByTagName(const std::initializer_list<Variant> &args);
    Variant getElementsByTagNameNS(const std::initializer_list<Variant> &args);
    Variant importNode(const std::initializer_list<Variant> &args);
    Variant load(const std::initializer_list<Variant> &args);
    Variant loadXML(const std::initializer_list<Variant> &args);
    Variant normalizeDocument();
    Variant registerNodeClass(const std::initializer_list<Variant> &args);
    Variant save(const std::initializer_list<Variant> &args);
    Variant loadHTML(const std::initializer_list<Variant> &args);
    Variant loadHTMLFile(const std::initializer_list<Variant> &args);
    Variant saveHTML(const std::initializer_list<Variant> &args);
    Variant saveHTMLFile(const std::initializer_list<Variant> &args);
    Variant saveXML(const std::initializer_list<Variant> &args);
    Variant schemaValidate(const std::initializer_list<Variant> &args);
    Variant schemaValidateSource(const std::initializer_list<Variant> &args);
    Variant relaxNGValidate(const std::initializer_list<Variant> &args);
    Variant relaxNGValidateSource(const std::initializer_list<Variant> &args);
    Variant validate();
    Variant xinclude(const std::initializer_list<Variant> &args);
    Variant adoptNode(const std::initializer_list<Variant> &args);
    Variant append(const std::initializer_list<Variant> &args);
    Variant prepend(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMNodeList {
  private:
    Variant _this;
  public:
    Variant count();
    Variant getIterator();
    Variant item(const std::initializer_list<Variant> &args);
};

class DOMNamedNodeMap {
  private:
    Variant _this;
  public:
    Variant getNamedItem(const std::initializer_list<Variant> &args);
    Variant getNamedItemNS(const std::initializer_list<Variant> &args);
    Variant item(const std::initializer_list<Variant> &args);
    Variant count();
    Variant getIterator();
};

class DOMCharacterData {
  private:
    Variant _this;
  public:
    Variant appendData(const std::initializer_list<Variant> &args);
    Variant substringData(const std::initializer_list<Variant> &args);
    Variant insertData(const std::initializer_list<Variant> &args);
    Variant deleteData(const std::initializer_list<Variant> &args);
    Variant replaceData(const std::initializer_list<Variant> &args);
    Variant replaceWith(const std::initializer_list<Variant> &args);
    Variant remove();
    Variant before(const std::initializer_list<Variant> &args);
    Variant after(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMAttr {
  private:
    Variant _this;
  public:
    DOMAttr(const std::initializer_list<Variant> &args);
    Variant isId();
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMElement {
  private:
    Variant _this;
  public:
    DOMElement(const std::initializer_list<Variant> &args);
    Variant getAttribute(const std::initializer_list<Variant> &args);
    Variant getAttributeNS(const std::initializer_list<Variant> &args);
    Variant getAttributeNode(const std::initializer_list<Variant> &args);
    Variant getAttributeNodeNS(const std::initializer_list<Variant> &args);
    Variant getElementsByTagName(const std::initializer_list<Variant> &args);
    Variant getElementsByTagNameNS(const std::initializer_list<Variant> &args);
    Variant hasAttribute(const std::initializer_list<Variant> &args);
    Variant hasAttributeNS(const std::initializer_list<Variant> &args);
    Variant removeAttribute(const std::initializer_list<Variant> &args);
    Variant removeAttributeNS(const std::initializer_list<Variant> &args);
    Variant removeAttributeNode(const std::initializer_list<Variant> &args);
    Variant setAttribute(const std::initializer_list<Variant> &args);
    Variant setAttributeNS(const std::initializer_list<Variant> &args);
    Variant setAttributeNode(const std::initializer_list<Variant> &args);
    Variant setAttributeNodeNS(const std::initializer_list<Variant> &args);
    Variant setIdAttribute(const std::initializer_list<Variant> &args);
    Variant setIdAttributeNS(const std::initializer_list<Variant> &args);
    Variant setIdAttributeNode(const std::initializer_list<Variant> &args);
    Variant remove();
    Variant before(const std::initializer_list<Variant> &args);
    Variant after(const std::initializer_list<Variant> &args);
    Variant replaceWith(const std::initializer_list<Variant> &args);
    Variant append(const std::initializer_list<Variant> &args);
    Variant prepend(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMText {
  private:
    Variant _this;
  public:
    DOMText(const std::initializer_list<Variant> &args);
    Variant isWhitespaceInElementContent();
    Variant isElementContentWhitespace();
    Variant splitText(const std::initializer_list<Variant> &args);
    Variant appendData(const std::initializer_list<Variant> &args);
    Variant substringData(const std::initializer_list<Variant> &args);
    Variant insertData(const std::initializer_list<Variant> &args);
    Variant deleteData(const std::initializer_list<Variant> &args);
    Variant replaceData(const std::initializer_list<Variant> &args);
    Variant replaceWith(const std::initializer_list<Variant> &args);
    Variant remove();
    Variant before(const std::initializer_list<Variant> &args);
    Variant after(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMComment {
  private:
    Variant _this;
  public:
    DOMComment(const std::initializer_list<Variant> &args);
    Variant appendData(const std::initializer_list<Variant> &args);
    Variant substringData(const std::initializer_list<Variant> &args);
    Variant insertData(const std::initializer_list<Variant> &args);
    Variant deleteData(const std::initializer_list<Variant> &args);
    Variant replaceData(const std::initializer_list<Variant> &args);
    Variant replaceWith(const std::initializer_list<Variant> &args);
    Variant remove();
    Variant before(const std::initializer_list<Variant> &args);
    Variant after(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMCdataSection {
  private:
    Variant _this;
  public:
    DOMCdataSection(const std::initializer_list<Variant> &args);
    Variant isWhitespaceInElementContent();
    Variant isElementContentWhitespace();
    Variant splitText(const std::initializer_list<Variant> &args);
    Variant appendData(const std::initializer_list<Variant> &args);
    Variant substringData(const std::initializer_list<Variant> &args);
    Variant insertData(const std::initializer_list<Variant> &args);
    Variant deleteData(const std::initializer_list<Variant> &args);
    Variant replaceData(const std::initializer_list<Variant> &args);
    Variant replaceWith(const std::initializer_list<Variant> &args);
    Variant remove();
    Variant before(const std::initializer_list<Variant> &args);
    Variant after(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMDocumentType {
  private:
    Variant _this;
  public:
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMNotation {
  private:
    Variant _this;
  public:
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMEntity {
  private:
    Variant _this;
  public:
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMEntityReference {
  private:
    Variant _this;
  public:
    DOMEntityReference(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMProcessingInstruction {
  private:
    Variant _this;
  public:
    DOMProcessingInstruction(const std::initializer_list<Variant> &args);
    Variant __sleep();
    Variant __wakeup();
    Variant appendChild(const std::initializer_list<Variant> &args);
    Variant C14N(const std::initializer_list<Variant> &args);
    Variant C14NFile(const std::initializer_list<Variant> &args);
    Variant cloneNode(const std::initializer_list<Variant> &args);
    Variant getLineNo();
    Variant getNodePath();
    Variant hasAttributes();
    Variant hasChildNodes();
    Variant insertBefore(const std::initializer_list<Variant> &args);
    Variant isDefaultNamespace(const std::initializer_list<Variant> &args);
    Variant isSameNode(const std::initializer_list<Variant> &args);
    Variant isSupported(const std::initializer_list<Variant> &args);
    Variant lookupNamespaceURI(const std::initializer_list<Variant> &args);
    Variant lookupPrefix(const std::initializer_list<Variant> &args);
    Variant normalize();
    Variant removeChild(const std::initializer_list<Variant> &args);
    Variant replaceChild(const std::initializer_list<Variant> &args);
};

class DOMXPath {
  private:
    Variant _this;
  public:
    DOMXPath(const std::initializer_list<Variant> &args);
    Variant evaluate(const std::initializer_list<Variant> &args);
    Variant query(const std::initializer_list<Variant> &args);
    Variant registerNamespace(const std::initializer_list<Variant> &args);
    Variant registerPhpFunctions(const std::initializer_list<Variant> &args);
};

}

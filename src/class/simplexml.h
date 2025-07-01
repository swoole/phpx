namespace php {
class SimpleXMLElement {
  private:
    Variant _this;
  public:
    Variant xpath(const std::initializer_list<Variant> &args);
    Variant registerXPathNamespace(const std::initializer_list<Variant> &args);
    Variant asXML(const std::initializer_list<Variant> &args);
    Variant saveXML(const std::initializer_list<Variant> &args);
    Variant getNamespaces(const std::initializer_list<Variant> &args);
    Variant getDocNamespaces(const std::initializer_list<Variant> &args);
    Variant children(const std::initializer_list<Variant> &args);
    Variant attributes(const std::initializer_list<Variant> &args);
    SimpleXMLElement(const std::initializer_list<Variant> &args);
    Variant addChild(const std::initializer_list<Variant> &args);
    Variant addAttribute(const std::initializer_list<Variant> &args);
    Variant getName();
    Variant __toString();
    Variant count();
    Variant rewind();
    Variant valid();
    Variant current();
    Variant key();
    Variant next();
    Variant hasChildren();
    Variant getChildren();
};

class SimpleXMLIterator {
  private:
    Variant _this;
  public:
    Variant xpath(const std::initializer_list<Variant> &args);
    Variant registerXPathNamespace(const std::initializer_list<Variant> &args);
    Variant asXML(const std::initializer_list<Variant> &args);
    Variant saveXML(const std::initializer_list<Variant> &args);
    Variant getNamespaces(const std::initializer_list<Variant> &args);
    Variant getDocNamespaces(const std::initializer_list<Variant> &args);
    Variant children(const std::initializer_list<Variant> &args);
    Variant attributes(const std::initializer_list<Variant> &args);
    SimpleXMLIterator(const std::initializer_list<Variant> &args);
    Variant addChild(const std::initializer_list<Variant> &args);
    Variant addAttribute(const std::initializer_list<Variant> &args);
    Variant getName();
    Variant __toString();
    Variant count();
    Variant rewind();
    Variant valid();
    Variant current();
    Variant key();
    Variant next();
    Variant hasChildren();
    Variant getChildren();
};

}

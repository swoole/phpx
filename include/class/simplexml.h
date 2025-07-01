namespace php {
class SimpleXMLElement {
    Object _this;
  public:
    Variant xpath(const Variant &expression);
    Variant registerXPathNamespace(const Variant &prefix, const Variant &_namespace);
    Variant asXML(const Variant &filename = {});
    Variant saveXML(const Variant &filename = {});
    Variant getNamespaces(const Variant &recursive = false);
    Variant getDocNamespaces(const Variant &recursive = false, const Variant &from_root = true);
    Variant children(const Variant &namespace_or_prefix = {}, const Variant &is_prefix = false);
    Variant attributes(const Variant &namespace_or_prefix = {}, const Variant &is_prefix = false);
    SimpleXMLElement(const Variant &data, const Variant &options = 0, const Variant &data_is_u_r_l = false, const Variant &namespace_or_prefix = "", const Variant &is_prefix = false);
    Variant addChild(const Variant &qualified_name, const Variant &value = {}, const Variant &_namespace = {});
    Variant addAttribute(const Variant &qualified_name, const Variant &value, const Variant &_namespace = {});
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
    Object _this;
  public:
    Variant xpath(const Variant &expression);
    Variant registerXPathNamespace(const Variant &prefix, const Variant &_namespace);
    Variant asXML(const Variant &filename = {});
    Variant saveXML(const Variant &filename = {});
    Variant getNamespaces(const Variant &recursive = false);
    Variant getDocNamespaces(const Variant &recursive = false, const Variant &from_root = true);
    Variant children(const Variant &namespace_or_prefix = {}, const Variant &is_prefix = false);
    Variant attributes(const Variant &namespace_or_prefix = {}, const Variant &is_prefix = false);
    SimpleXMLIterator(const Variant &data, const Variant &options = 0, const Variant &data_is_u_r_l = false, const Variant &namespace_or_prefix = "", const Variant &is_prefix = false);
    Variant addChild(const Variant &qualified_name, const Variant &value = {}, const Variant &_namespace = {});
    Variant addAttribute(const Variant &qualified_name, const Variant &value, const Variant &_namespace = {});
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

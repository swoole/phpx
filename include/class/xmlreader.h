namespace php {
class XMLReader {
    Object this_;
  public:
    Variant close();
    Variant getAttribute(const Variant &name);
    Variant getAttributeNo(const Variant &index);
    Variant getAttributeNs(const Variant &name, const Variant &_namespace);
    Variant getParserProperty(const Variant &property);
    Variant isValid();
    Variant lookupNamespace(const Variant &prefix);
    Variant moveToAttribute(const Variant &name);
    Variant moveToAttributeNo(const Variant &index);
    Variant moveToAttributeNs(const Variant &name, const Variant &_namespace);
    Variant moveToElement();
    Variant moveToFirstAttribute();
    Variant moveToNextAttribute();
    Variant read();
    Variant next(const Variant &name = {});
    static Variant open(const Variant &uri, const Variant &encoding = {}, const Variant &flags = 0);
    Variant readInnerXml();
    Variant readOuterXml();
    Variant readString();
    Variant setSchema(const Variant &filename);
    Variant setParserProperty(const Variant &property, const Variant &value);
    Variant setRelaxNGSchema(const Variant &filename);
    Variant setRelaxNGSchemaSource(const Variant &source);
    static Variant XML(const Variant &source, const Variant &encoding = {}, const Variant &flags = 0);
    Variant expand(const Variant &base_node = {});
};

}

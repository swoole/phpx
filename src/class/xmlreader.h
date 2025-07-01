namespace php {
class XMLReader {
  private:
    Variant _this;
  public:
    Variant close();
    Variant getAttribute(const std::initializer_list<Variant> &args);
    Variant getAttributeNo(const std::initializer_list<Variant> &args);
    Variant getAttributeNs(const std::initializer_list<Variant> &args);
    Variant getParserProperty(const std::initializer_list<Variant> &args);
    Variant isValid();
    Variant lookupNamespace(const std::initializer_list<Variant> &args);
    Variant moveToAttribute(const std::initializer_list<Variant> &args);
    Variant moveToAttributeNo(const std::initializer_list<Variant> &args);
    Variant moveToAttributeNs(const std::initializer_list<Variant> &args);
    Variant moveToElement();
    Variant moveToFirstAttribute();
    Variant moveToNextAttribute();
    Variant read();
    Variant next(const std::initializer_list<Variant> &args);
    static Variant open(const std::initializer_list<Variant> &args);
    Variant readInnerXml();
    Variant readOuterXml();
    Variant readString();
    Variant setSchema(const std::initializer_list<Variant> &args);
    Variant setParserProperty(const std::initializer_list<Variant> &args);
    Variant setRelaxNGSchema(const std::initializer_list<Variant> &args);
    Variant setRelaxNGSchemaSource(const std::initializer_list<Variant> &args);
    static Variant XML(const std::initializer_list<Variant> &args);
    Variant expand(const std::initializer_list<Variant> &args);
};

}

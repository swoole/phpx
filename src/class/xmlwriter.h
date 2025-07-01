namespace php {
class XMLWriter {
  private:
    Variant _this;
  public:
    Variant openUri(const std::initializer_list<Variant> &args);
    Variant openMemory();
    Variant setIndent(const std::initializer_list<Variant> &args);
    Variant setIndentString(const std::initializer_list<Variant> &args);
    Variant startComment();
    Variant endComment();
    Variant startAttribute(const std::initializer_list<Variant> &args);
    Variant endAttribute();
    Variant writeAttribute(const std::initializer_list<Variant> &args);
    Variant startAttributeNs(const std::initializer_list<Variant> &args);
    Variant writeAttributeNs(const std::initializer_list<Variant> &args);
    Variant startElement(const std::initializer_list<Variant> &args);
    Variant endElement();
    Variant fullEndElement();
    Variant startElementNs(const std::initializer_list<Variant> &args);
    Variant writeElement(const std::initializer_list<Variant> &args);
    Variant writeElementNs(const std::initializer_list<Variant> &args);
    Variant startPi(const std::initializer_list<Variant> &args);
    Variant endPi();
    Variant writePi(const std::initializer_list<Variant> &args);
    Variant startCdata();
    Variant endCdata();
    Variant writeCdata(const std::initializer_list<Variant> &args);
    Variant text(const std::initializer_list<Variant> &args);
    Variant writeRaw(const std::initializer_list<Variant> &args);
    Variant startDocument(const std::initializer_list<Variant> &args);
    Variant endDocument();
    Variant writeComment(const std::initializer_list<Variant> &args);
    Variant startDtd(const std::initializer_list<Variant> &args);
    Variant endDtd();
    Variant writeDtd(const std::initializer_list<Variant> &args);
    Variant startDtdElement(const std::initializer_list<Variant> &args);
    Variant endDtdElement();
    Variant writeDtdElement(const std::initializer_list<Variant> &args);
    Variant startDtdAttlist(const std::initializer_list<Variant> &args);
    Variant endDtdAttlist();
    Variant writeDtdAttlist(const std::initializer_list<Variant> &args);
    Variant startDtdEntity(const std::initializer_list<Variant> &args);
    Variant endDtdEntity();
    Variant writeDtdEntity(const std::initializer_list<Variant> &args);
    Variant outputMemory(const std::initializer_list<Variant> &args);
    Variant flush(const std::initializer_list<Variant> &args);
};

}

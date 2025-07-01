namespace php {
class XMLWriter {
    Object _this;
  public:
    Variant openUri(const Variant &uri);
    Variant openMemory();
    Variant setIndent(const Variant &enable);
    Variant setIndentString(const Variant &indentation);
    Variant startComment();
    Variant endComment();
    Variant startAttribute(const Variant &name);
    Variant endAttribute();
    Variant writeAttribute(const Variant &name, const Variant &value);
    Variant startAttributeNs(const Variant &prefix, const Variant &name, const Variant &_namespace);
    Variant writeAttributeNs(const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &value);
    Variant startElement(const Variant &name);
    Variant endElement();
    Variant fullEndElement();
    Variant startElementNs(const Variant &prefix, const Variant &name, const Variant &_namespace);
    Variant writeElement(const Variant &name, const Variant &content = {});
    Variant writeElementNs(const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &content = {});
    Variant startPi(const Variant &target);
    Variant endPi();
    Variant writePi(const Variant &target, const Variant &content);
    Variant startCdata();
    Variant endCdata();
    Variant writeCdata(const Variant &content);
    Variant text(const Variant &content);
    Variant writeRaw(const Variant &content);
    Variant startDocument(const Variant &version = "1.0", const Variant &encoding = {}, const Variant &standalone = {});
    Variant endDocument();
    Variant writeComment(const Variant &content);
    Variant startDtd(const Variant &qualified_name, const Variant &public_id = {}, const Variant &system_id = {});
    Variant endDtd();
    Variant writeDtd(const Variant &name, const Variant &public_id = {}, const Variant &system_id = {}, const Variant &content = {});
    Variant startDtdElement(const Variant &qualified_name);
    Variant endDtdElement();
    Variant writeDtdElement(const Variant &name, const Variant &content);
    Variant startDtdAttlist(const Variant &name);
    Variant endDtdAttlist();
    Variant writeDtdAttlist(const Variant &name, const Variant &content);
    Variant startDtdEntity(const Variant &name, const Variant &is_param);
    Variant endDtdEntity();
    Variant writeDtdEntity(const Variant &name, const Variant &content, const Variant &is_param = false, const Variant &public_id = {}, const Variant &system_id = {}, const Variant &notation_data = {});
    Variant outputMemory(const Variant &flush = true);
    Variant flush(const Variant &empty = true);
};

}

#include "phpx.h"
#include "class/xmlwriter.h"

namespace php {
Variant XMLWriter::openUri(const Variant &uri) {
    return std::move(_this.exec("openUri", uri));
}

Variant XMLWriter::openMemory() {
    return std::move(_this.exec("openMemory"));
}

Variant XMLWriter::setIndent(const Variant &enable) {
    return std::move(_this.exec("setIndent", enable));
}

Variant XMLWriter::setIndentString(const Variant &indentation) {
    return std::move(_this.exec("setIndentString", indentation));
}

Variant XMLWriter::startComment() {
    return std::move(_this.exec("startComment"));
}

Variant XMLWriter::endComment() {
    return std::move(_this.exec("endComment"));
}

Variant XMLWriter::startAttribute(const Variant &name) {
    return std::move(_this.exec("startAttribute", name));
}

Variant XMLWriter::endAttribute() {
    return std::move(_this.exec("endAttribute"));
}

Variant XMLWriter::writeAttribute(const Variant &name, const Variant &value) {
    return std::move(_this.exec("writeAttribute", name, value));
}

Variant XMLWriter::startAttributeNs(const Variant &prefix, const Variant &name, const Variant &_namespace) {
    return std::move(_this.exec("startAttributeNs", prefix, name, _namespace));
}

Variant XMLWriter::writeAttributeNs(const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &value) {
    return std::move(_this.exec("writeAttributeNs", prefix, name, _namespace, value));
}

Variant XMLWriter::startElement(const Variant &name) {
    return std::move(_this.exec("startElement", name));
}

Variant XMLWriter::endElement() {
    return std::move(_this.exec("endElement"));
}

Variant XMLWriter::fullEndElement() {
    return std::move(_this.exec("fullEndElement"));
}

Variant XMLWriter::startElementNs(const Variant &prefix, const Variant &name, const Variant &_namespace) {
    return std::move(_this.exec("startElementNs", prefix, name, _namespace));
}

Variant XMLWriter::writeElement(const Variant &name, const Variant &content) {
    return std::move(_this.exec("writeElement", name, content));
}

Variant XMLWriter::writeElementNs(const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &content) {
    return std::move(_this.exec("writeElementNs", prefix, name, _namespace, content));
}

Variant XMLWriter::startPi(const Variant &target) {
    return std::move(_this.exec("startPi", target));
}

Variant XMLWriter::endPi() {
    return std::move(_this.exec("endPi"));
}

Variant XMLWriter::writePi(const Variant &target, const Variant &content) {
    return std::move(_this.exec("writePi", target, content));
}

Variant XMLWriter::startCdata() {
    return std::move(_this.exec("startCdata"));
}

Variant XMLWriter::endCdata() {
    return std::move(_this.exec("endCdata"));
}

Variant XMLWriter::writeCdata(const Variant &content) {
    return std::move(_this.exec("writeCdata", content));
}

Variant XMLWriter::text(const Variant &content) {
    return std::move(_this.exec("text", content));
}

Variant XMLWriter::writeRaw(const Variant &content) {
    return std::move(_this.exec("writeRaw", content));
}

Variant XMLWriter::startDocument(const Variant &version, const Variant &encoding, const Variant &standalone) {
    return std::move(_this.exec("startDocument", version, encoding, standalone));
}

Variant XMLWriter::endDocument() {
    return std::move(_this.exec("endDocument"));
}

Variant XMLWriter::writeComment(const Variant &content) {
    return std::move(_this.exec("writeComment", content));
}

Variant XMLWriter::startDtd(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    return std::move(_this.exec("startDtd", qualified_name, public_id, system_id));
}

Variant XMLWriter::endDtd() {
    return std::move(_this.exec("endDtd"));
}

Variant XMLWriter::writeDtd(const Variant &name, const Variant &public_id, const Variant &system_id, const Variant &content) {
    return std::move(_this.exec("writeDtd", name, public_id, system_id, content));
}

Variant XMLWriter::startDtdElement(const Variant &qualified_name) {
    return std::move(_this.exec("startDtdElement", qualified_name));
}

Variant XMLWriter::endDtdElement() {
    return std::move(_this.exec("endDtdElement"));
}

Variant XMLWriter::writeDtdElement(const Variant &name, const Variant &content) {
    return std::move(_this.exec("writeDtdElement", name, content));
}

Variant XMLWriter::startDtdAttlist(const Variant &name) {
    return std::move(_this.exec("startDtdAttlist", name));
}

Variant XMLWriter::endDtdAttlist() {
    return std::move(_this.exec("endDtdAttlist"));
}

Variant XMLWriter::writeDtdAttlist(const Variant &name, const Variant &content) {
    return std::move(_this.exec("writeDtdAttlist", name, content));
}

Variant XMLWriter::startDtdEntity(const Variant &name, const Variant &is_param) {
    return std::move(_this.exec("startDtdEntity", name, is_param));
}

Variant XMLWriter::endDtdEntity() {
    return std::move(_this.exec("endDtdEntity"));
}

Variant XMLWriter::writeDtdEntity(const Variant &name, const Variant &content, const Variant &is_param, const Variant &public_id, const Variant &system_id, const Variant &notation_data) {
    return std::move(_this.exec("writeDtdEntity", name, content, is_param, public_id, system_id, notation_data));
}

Variant XMLWriter::outputMemory(const Variant &flush) {
    return std::move(_this.exec("outputMemory", flush));
}

Variant XMLWriter::flush(const Variant &empty) {
    return std::move(_this.exec("flush", empty));
}


}

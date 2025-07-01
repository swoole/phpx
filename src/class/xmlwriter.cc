#include "phpx.h"
#include "class/xmlwriter.h"

namespace php {
Variant XMLWriter::openUri(const Variant &uri) {
    return this_.exec("openUri", uri);
}

Variant XMLWriter::openMemory() {
    return this_.exec("openMemory");
}

Variant XMLWriter::setIndent(const Variant &enable) {
    return this_.exec("setIndent", enable);
}

Variant XMLWriter::setIndentString(const Variant &indentation) {
    return this_.exec("setIndentString", indentation);
}

Variant XMLWriter::startComment() {
    return this_.exec("startComment");
}

Variant XMLWriter::endComment() {
    return this_.exec("endComment");
}

Variant XMLWriter::startAttribute(const Variant &name) {
    return this_.exec("startAttribute", name);
}

Variant XMLWriter::endAttribute() {
    return this_.exec("endAttribute");
}

Variant XMLWriter::writeAttribute(const Variant &name, const Variant &value) {
    return this_.exec("writeAttribute", name, value);
}

Variant XMLWriter::startAttributeNs(const Variant &prefix, const Variant &name, const Variant &_namespace) {
    return this_.exec("startAttributeNs", prefix, name, _namespace);
}

Variant XMLWriter::writeAttributeNs(const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &value) {
    return this_.exec("writeAttributeNs", prefix, name, _namespace, value);
}

Variant XMLWriter::startElement(const Variant &name) {
    return this_.exec("startElement", name);
}

Variant XMLWriter::endElement() {
    return this_.exec("endElement");
}

Variant XMLWriter::fullEndElement() {
    return this_.exec("fullEndElement");
}

Variant XMLWriter::startElementNs(const Variant &prefix, const Variant &name, const Variant &_namespace) {
    return this_.exec("startElementNs", prefix, name, _namespace);
}

Variant XMLWriter::writeElement(const Variant &name, const Variant &content) {
    return this_.exec("writeElement", name, content);
}

Variant XMLWriter::writeElementNs(const Variant &prefix, const Variant &name, const Variant &_namespace, const Variant &content) {
    return this_.exec("writeElementNs", prefix, name, _namespace, content);
}

Variant XMLWriter::startPi(const Variant &target) {
    return this_.exec("startPi", target);
}

Variant XMLWriter::endPi() {
    return this_.exec("endPi");
}

Variant XMLWriter::writePi(const Variant &target, const Variant &content) {
    return this_.exec("writePi", target, content);
}

Variant XMLWriter::startCdata() {
    return this_.exec("startCdata");
}

Variant XMLWriter::endCdata() {
    return this_.exec("endCdata");
}

Variant XMLWriter::writeCdata(const Variant &content) {
    return this_.exec("writeCdata", content);
}

Variant XMLWriter::text(const Variant &content) {
    return this_.exec("text", content);
}

Variant XMLWriter::writeRaw(const Variant &content) {
    return this_.exec("writeRaw", content);
}

Variant XMLWriter::startDocument(const Variant &version, const Variant &encoding, const Variant &standalone) {
    return this_.exec("startDocument", version, encoding, standalone);
}

Variant XMLWriter::endDocument() {
    return this_.exec("endDocument");
}

Variant XMLWriter::writeComment(const Variant &content) {
    return this_.exec("writeComment", content);
}

Variant XMLWriter::startDtd(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    return this_.exec("startDtd", qualified_name, public_id, system_id);
}

Variant XMLWriter::endDtd() {
    return this_.exec("endDtd");
}

Variant XMLWriter::writeDtd(const Variant &name, const Variant &public_id, const Variant &system_id, const Variant &content) {
    return this_.exec("writeDtd", name, public_id, system_id, content);
}

Variant XMLWriter::startDtdElement(const Variant &qualified_name) {
    return this_.exec("startDtdElement", qualified_name);
}

Variant XMLWriter::endDtdElement() {
    return this_.exec("endDtdElement");
}

Variant XMLWriter::writeDtdElement(const Variant &name, const Variant &content) {
    return this_.exec("writeDtdElement", name, content);
}

Variant XMLWriter::startDtdAttlist(const Variant &name) {
    return this_.exec("startDtdAttlist", name);
}

Variant XMLWriter::endDtdAttlist() {
    return this_.exec("endDtdAttlist");
}

Variant XMLWriter::writeDtdAttlist(const Variant &name, const Variant &content) {
    return this_.exec("writeDtdAttlist", name, content);
}

Variant XMLWriter::startDtdEntity(const Variant &name, const Variant &is_param) {
    return this_.exec("startDtdEntity", name, is_param);
}

Variant XMLWriter::endDtdEntity() {
    return this_.exec("endDtdEntity");
}

Variant XMLWriter::writeDtdEntity(const Variant &name, const Variant &content, const Variant &is_param, const Variant &public_id, const Variant &system_id, const Variant &notation_data) {
    return this_.exec("writeDtdEntity", name, content, is_param, public_id, system_id, notation_data);
}

Variant XMLWriter::outputMemory(const Variant &flush) {
    return this_.exec("outputMemory", flush);
}

Variant XMLWriter::flush(const Variant &empty) {
    return this_.exec("flush", empty);
}


}

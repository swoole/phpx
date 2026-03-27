#include "phpx.h"
#include "class/xmlwriter.h"

namespace php {
Variant XMLWriter::openUri(const Variant &uri) {
    return this_.call(LITERAL_STRING[2449], {uri});
}
Variant XMLWriter::toUri(const Variant &uri) {
    return php::call(LITERAL_STRING[2450], {uri});
}
Variant XMLWriter::openMemory() {
    return this_.call(LITERAL_STRING[2451], {});
}
Variant XMLWriter::toMemory() {
    return php::call(LITERAL_STRING[2452], {});
}
Variant XMLWriter::toStream(const Variant &stream) {
    return php::call(LITERAL_STRING[2453], {stream});
}
Variant XMLWriter::setIndent(const Variant &enable) {
    return this_.call(LITERAL_STRING[2454], {enable});
}
Variant XMLWriter::setIndentString(const Variant &indentation) {
    return this_.call(LITERAL_STRING[2455], {indentation});
}
Variant XMLWriter::startComment() {
    return this_.call(LITERAL_STRING[2456], {});
}
Variant XMLWriter::endComment() {
    return this_.call(LITERAL_STRING[2457], {});
}
Variant XMLWriter::startAttribute(const Variant &name) {
    return this_.call(LITERAL_STRING[2458], {name});
}
Variant XMLWriter::endAttribute() {
    return this_.call(LITERAL_STRING[2459], {});
}
Variant XMLWriter::writeAttribute(const Variant &name, const Variant &value) {
    return this_.call(LITERAL_STRING[2460], {name, value});
}
Variant XMLWriter::startAttributeNs(const Variant &prefix, const Variant &name, const Variant &_namespace) {
    return this_.call(LITERAL_STRING[2461], {prefix, name, _namespace});
}
Variant XMLWriter::writeAttributeNs(const Variant &prefix,
                                    const Variant &name,
                                    const Variant &_namespace,
                                    const Variant &value) {
    return this_.call(LITERAL_STRING[2462], {prefix, name, _namespace, value});
}
Variant XMLWriter::startElement(const Variant &name) {
    return this_.call(LITERAL_STRING[2463], {name});
}
Variant XMLWriter::endElement() {
    return this_.call(LITERAL_STRING[2464], {});
}
Variant XMLWriter::fullEndElement() {
    return this_.call(LITERAL_STRING[2465], {});
}
Variant XMLWriter::startElementNs(const Variant &prefix, const Variant &name, const Variant &_namespace) {
    return this_.call(LITERAL_STRING[2466], {prefix, name, _namespace});
}
Variant XMLWriter::writeElement(const Variant &name, const Variant &content) {
    return this_.call(LITERAL_STRING[2467], {name, content});
}
Variant XMLWriter::writeElementNs(const Variant &prefix,
                                  const Variant &name,
                                  const Variant &_namespace,
                                  const Variant &content) {
    return this_.call(LITERAL_STRING[2468], {prefix, name, _namespace, content});
}
Variant XMLWriter::startPi(const Variant &target) {
    return this_.call(LITERAL_STRING[2469], {target});
}
Variant XMLWriter::endPi() {
    return this_.call(LITERAL_STRING[2470], {});
}
Variant XMLWriter::writePi(const Variant &target, const Variant &content) {
    return this_.call(LITERAL_STRING[2471], {target, content});
}
Variant XMLWriter::startCdata() {
    return this_.call(LITERAL_STRING[2472], {});
}
Variant XMLWriter::endCdata() {
    return this_.call(LITERAL_STRING[2473], {});
}
Variant XMLWriter::writeCdata(const Variant &content) {
    return this_.call(LITERAL_STRING[2474], {content});
}
Variant XMLWriter::text(const Variant &content) {
    return this_.call(LITERAL_STRING[2475], {content});
}
Variant XMLWriter::writeRaw(const Variant &content) {
    return this_.call(LITERAL_STRING[2476], {content});
}
Variant XMLWriter::startDocument(const Variant &version, const Variant &encoding, const Variant &standalone) {
    return this_.call(LITERAL_STRING[2477], {version, encoding, standalone});
}
Variant XMLWriter::endDocument() {
    return this_.call(LITERAL_STRING[2478], {});
}
Variant XMLWriter::writeComment(const Variant &content) {
    return this_.call(LITERAL_STRING[2479], {content});
}
Variant XMLWriter::startDtd(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    return this_.call(LITERAL_STRING[2480], {qualified_name, public_id, system_id});
}
Variant XMLWriter::endDtd() {
    return this_.call(LITERAL_STRING[2481], {});
}
Variant XMLWriter::writeDtd(const Variant &name,
                            const Variant &public_id,
                            const Variant &system_id,
                            const Variant &content) {
    return this_.call(LITERAL_STRING[2482], {name, public_id, system_id, content});
}
Variant XMLWriter::startDtdElement(const Variant &qualified_name) {
    return this_.call(LITERAL_STRING[2483], {qualified_name});
}
Variant XMLWriter::endDtdElement() {
    return this_.call(LITERAL_STRING[2484], {});
}
Variant XMLWriter::writeDtdElement(const Variant &name, const Variant &content) {
    return this_.call(LITERAL_STRING[2485], {name, content});
}
Variant XMLWriter::startDtdAttlist(const Variant &name) {
    return this_.call(LITERAL_STRING[2486], {name});
}
Variant XMLWriter::endDtdAttlist() {
    return this_.call(LITERAL_STRING[2487], {});
}
Variant XMLWriter::writeDtdAttlist(const Variant &name, const Variant &content) {
    return this_.call(LITERAL_STRING[2488], {name, content});
}
Variant XMLWriter::startDtdEntity(const Variant &name, const Variant &is_param) {
    return this_.call(LITERAL_STRING[2489], {name, is_param});
}
Variant XMLWriter::endDtdEntity() {
    return this_.call(LITERAL_STRING[2490], {});
}
Variant XMLWriter::writeDtdEntity(const Variant &name,
                                  const Variant &content,
                                  const Variant &is_param,
                                  const Variant &public_id,
                                  const Variant &system_id,
                                  const Variant &notation_data) {
    return this_.call(LITERAL_STRING[2491], {name, content, is_param, public_id, system_id, notation_data});
}
Variant XMLWriter::outputMemory(const Variant &flush) {
    return this_.call(LITERAL_STRING[2492], {flush});
}
Variant XMLWriter::flush(const Variant &empty) {
    return this_.call(LITERAL_STRING[1950], {empty});
}
}  // namespace php

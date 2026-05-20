#include "phpx.h"
#include "class/xmlwriter.h"

namespace php {
XMLWriter::XMLWriter() {
    this_ = newObject(LITERAL_STRING[2522]);
}
Variant XMLWriter::openUri(const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2523]);
    }
    return this_.call(_method_fn, {uri});
}
Variant XMLWriter::toUri(const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2522], LITERAL_STRING[2525]);
    }
    return php::call(_method_fn, {uri});
}
Variant XMLWriter::openMemory() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2526]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::toMemory() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2522], LITERAL_STRING[2528]);
    }
    return php::call(_method_fn, {});
}
Variant XMLWriter::toStream(const Variant &stream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2522], LITERAL_STRING[2530]);
    }
    return php::call(_method_fn, {stream});
}
Variant XMLWriter::setIndent(const Variant &enable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2531]);
    }
    return this_.call(_method_fn, {enable});
}
Variant XMLWriter::setIndentString(const Variant &indentation) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2532]);
    }
    return this_.call(_method_fn, {indentation});
}
Variant XMLWriter::startComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2533]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::endComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2534]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::startAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2535]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2536]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeAttribute(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2537]);
    }
    return this_.call(_method_fn, {name, value});
}
Variant XMLWriter::startAttributeNs(const Variant &prefix, const Variant &name, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2538]);
    }
    return this_.call(_method_fn, {prefix, name, _namespace});
}
Variant XMLWriter::writeAttributeNs(const Variant &prefix,
                                    const Variant &name,
                                    const Variant &_namespace,
                                    const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2539]);
    }
    return this_.call(_method_fn, {prefix, name, _namespace, value});
}
Variant XMLWriter::startElement(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2540]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2541]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::fullEndElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2542]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::startElementNs(const Variant &prefix, const Variant &name, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2543]);
    }
    return this_.call(_method_fn, {prefix, name, _namespace});
}
Variant XMLWriter::writeElement(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2544]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::writeElementNs(const Variant &prefix,
                                  const Variant &name,
                                  const Variant &_namespace,
                                  const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2545]);
    }
    return this_.call(_method_fn, {prefix, name, _namespace, content});
}
Variant XMLWriter::startPi(const Variant &target) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2546]);
    }
    return this_.call(_method_fn, {target});
}
Variant XMLWriter::endPi() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2547]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writePi(const Variant &target, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2548]);
    }
    return this_.call(_method_fn, {target, content});
}
Variant XMLWriter::startCdata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2549]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::endCdata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2550]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeCdata(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2551]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::text(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2552]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::writeRaw(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2553]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::startDocument(const Variant &version, const Variant &encoding, const Variant &standalone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2554]);
    }
    return this_.call(_method_fn, {version, encoding, standalone});
}
Variant XMLWriter::endDocument() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2555]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeComment(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2556]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::startDtd(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2557]);
    }
    return this_.call(_method_fn, {qualified_name, public_id, system_id});
}
Variant XMLWriter::endDtd() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2558]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtd(const Variant &name,
                            const Variant &public_id,
                            const Variant &system_id,
                            const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2559]);
    }
    return this_.call(_method_fn, {name, public_id, system_id, content});
}
Variant XMLWriter::startDtdElement(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2560]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant XMLWriter::endDtdElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2561]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdElement(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2562]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::startDtdAttlist(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2563]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endDtdAttlist() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2564]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdAttlist(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2565]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::startDtdEntity(const Variant &name, const Variant &is_param) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2566]);
    }
    return this_.call(_method_fn, {name, is_param});
}
Variant XMLWriter::endDtdEntity() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2567]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdEntity(const Variant &name,
                                  const Variant &content,
                                  const Variant &is_param,
                                  const Variant &public_id,
                                  const Variant &system_id,
                                  const Variant &notation_data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2568]);
    }
    return this_.call(_method_fn, {name, content, is_param, public_id, system_id, notation_data});
}
Variant XMLWriter::outputMemory(const Variant &flush) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2569]);
    }
    return this_.call(_method_fn, {flush});
}
Variant XMLWriter::flush(const Variant &empty) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2015]);
    }
    return this_.call(_method_fn, {empty});
}
}  // namespace php

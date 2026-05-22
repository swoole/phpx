#include "phpx.h"
#include "phpx_class.h"
#include "class/xmlwriter.h"

namespace php {
XMLWriter::XMLWriter() {
    this_ = newObject(LITERAL_STRING[3400]);
}
Variant XMLWriter::openUri(const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3401]);
    }
    return this_.call(_method_fn, {uri});
}
Variant XMLWriter::toUri(const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3400], LITERAL_STRING[3403]);
    }
    return php::call(_method_fn, {uri});
}
Variant XMLWriter::openMemory() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3404]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::toMemory() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3400], LITERAL_STRING[3406]);
    }
    return php::call(_method_fn, {});
}
Variant XMLWriter::toStream(const Variant &stream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3400], LITERAL_STRING[3408]);
    }
    return php::call(_method_fn, {stream});
}
Variant XMLWriter::setIndent(const Variant &enable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3409]);
    }
    return this_.call(_method_fn, {enable});
}
Variant XMLWriter::setIndentString(const Variant &indentation) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3410]);
    }
    return this_.call(_method_fn, {indentation});
}
Variant XMLWriter::startComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3411]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::endComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3412]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::startAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3413]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3414]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeAttribute(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3415]);
    }
    return this_.call(_method_fn, {name, value});
}
Variant XMLWriter::startAttributeNs(const Variant &prefix, const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3416]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_});
}
Variant XMLWriter::writeAttributeNs(const Variant &prefix,
                                    const Variant &name,
                                    const Variant &namespace_,
                                    const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3417]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_, value});
}
Variant XMLWriter::startElement(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3418]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3419]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::fullEndElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3420]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::startElementNs(const Variant &prefix, const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3421]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_});
}
Variant XMLWriter::writeElement(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3422]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::writeElementNs(const Variant &prefix,
                                  const Variant &name,
                                  const Variant &namespace_,
                                  const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3423]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_, content});
}
Variant XMLWriter::startPi(const Variant &target) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3424]);
    }
    return this_.call(_method_fn, {target});
}
Variant XMLWriter::endPi() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3425]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writePi(const Variant &target, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3426]);
    }
    return this_.call(_method_fn, {target, content});
}
Variant XMLWriter::startCdata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3427]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::endCdata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3428]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeCdata(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3429]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::text(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3430]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::writeRaw(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3431]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::startDocument(const Variant &version, const Variant &encoding, const Variant &standalone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3432]);
    }
    return this_.call(_method_fn, {version, encoding, standalone});
}
Variant XMLWriter::endDocument() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3433]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeComment(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3434]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::startDtd(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3435]);
    }
    return this_.call(_method_fn, {qualified_name, public_id, system_id});
}
Variant XMLWriter::endDtd() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3436]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtd(const Variant &name,
                            const Variant &public_id,
                            const Variant &system_id,
                            const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3437]);
    }
    return this_.call(_method_fn, {name, public_id, system_id, content});
}
Variant XMLWriter::startDtdElement(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3438]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant XMLWriter::endDtdElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3439]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdElement(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3440]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::startDtdAttlist(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3441]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endDtdAttlist() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3442]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdAttlist(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3443]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::startDtdEntity(const Variant &name, const Variant &is_param) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3444]);
    }
    return this_.call(_method_fn, {name, is_param});
}
Variant XMLWriter::endDtdEntity() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3445]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3446]);
    }
    return this_.call(_method_fn, {name, content, is_param, public_id, system_id, notation_data});
}
Variant XMLWriter::outputMemory(const Variant &flush) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3447]);
    }
    return this_.call(_method_fn, {flush});
}
Variant XMLWriter::flush(const Variant &empty) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2324]);
    }
    return this_.call(_method_fn, {empty});
}
}  // namespace php

#include "phpx.h"
#include "phpx_class.h"
#include "class/xmlwriter.h"

namespace php {
XMLWriter::XMLWriter() {
    this_ = newObject(LITERAL_STRING[2830]);
}
Variant XMLWriter::openUri(const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2831]);
    }
    return this_.call(_method_fn, {uri});
}
Variant XMLWriter::toUri(const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2830], LITERAL_STRING[2833]);
    }
    return php::call(_method_fn, {uri});
}
Variant XMLWriter::openMemory() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2834]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::toMemory() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2830], LITERAL_STRING[2836]);
    }
    return php::call(_method_fn, {});
}
Variant XMLWriter::toStream(const Variant &stream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2830], LITERAL_STRING[2838]);
    }
    return php::call(_method_fn, {stream});
}
Variant XMLWriter::setIndent(const Variant &enable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2839]);
    }
    return this_.call(_method_fn, {enable});
}
Variant XMLWriter::setIndentString(const Variant &indentation) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2840]);
    }
    return this_.call(_method_fn, {indentation});
}
Variant XMLWriter::startComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2841]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::endComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2842]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::startAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2843]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2844]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeAttribute(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2845]);
    }
    return this_.call(_method_fn, {name, value});
}
Variant XMLWriter::startAttributeNs(const Variant &prefix, const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2846]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_});
}
Variant XMLWriter::writeAttributeNs(const Variant &prefix,
                                    const Variant &name,
                                    const Variant &namespace_,
                                    const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2847]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_, value});
}
Variant XMLWriter::startElement(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2848]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2849]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::fullEndElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2850]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::startElementNs(const Variant &prefix, const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2851]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_});
}
Variant XMLWriter::writeElement(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2852]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::writeElementNs(const Variant &prefix,
                                  const Variant &name,
                                  const Variant &namespace_,
                                  const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2853]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_, content});
}
Variant XMLWriter::startPi(const Variant &target) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2854]);
    }
    return this_.call(_method_fn, {target});
}
Variant XMLWriter::endPi() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2855]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writePi(const Variant &target, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2856]);
    }
    return this_.call(_method_fn, {target, content});
}
Variant XMLWriter::startCdata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2857]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::endCdata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2858]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeCdata(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2859]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::text(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2860]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::writeRaw(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2861]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::startDocument(const Variant &version, const Variant &encoding, const Variant &standalone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2862]);
    }
    return this_.call(_method_fn, {version, encoding, standalone});
}
Variant XMLWriter::endDocument() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2863]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeComment(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2864]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::startDtd(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2865]);
    }
    return this_.call(_method_fn, {qualified_name, public_id, system_id});
}
Variant XMLWriter::endDtd() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2866]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtd(const Variant &name,
                            const Variant &public_id,
                            const Variant &system_id,
                            const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2867]);
    }
    return this_.call(_method_fn, {name, public_id, system_id, content});
}
Variant XMLWriter::startDtdElement(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2868]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant XMLWriter::endDtdElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2869]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdElement(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2870]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::startDtdAttlist(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2871]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endDtdAttlist() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2872]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdAttlist(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2873]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::startDtdEntity(const Variant &name, const Variant &is_param) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2874]);
    }
    return this_.call(_method_fn, {name, is_param});
}
Variant XMLWriter::endDtdEntity() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2875]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2876]);
    }
    return this_.call(_method_fn, {name, content, is_param, public_id, system_id, notation_data});
}
Variant XMLWriter::outputMemory(const Variant &flush) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2877]);
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

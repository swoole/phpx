#include "phpx.h"
#include "phpx_class.h"
#include "class/xmlwriter.h"

namespace php {
XMLWriter::XMLWriter() {
    this_ = newObject(LITERAL_STRING[2686]);
}
Variant XMLWriter::openUri(const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2687]);
    }
    return this_.call(_method_fn, {uri});
}
Variant XMLWriter::toUri(const Variant &uri) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2686], LITERAL_STRING[2689]);
    }
    return php::call(_method_fn, {uri});
}
Variant XMLWriter::openMemory() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2690]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::toMemory() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2686], LITERAL_STRING[2692]);
    }
    return php::call(_method_fn, {});
}
Variant XMLWriter::toStream(const Variant &stream) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2686], LITERAL_STRING[2694]);
    }
    return php::call(_method_fn, {stream});
}
Variant XMLWriter::setIndent(const Variant &enable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2695]);
    }
    return this_.call(_method_fn, {enable});
}
Variant XMLWriter::setIndentString(const Variant &indentation) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2696]);
    }
    return this_.call(_method_fn, {indentation});
}
Variant XMLWriter::startComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2697]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::endComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2698]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::startAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2699]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endAttribute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2700]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeAttribute(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2701]);
    }
    return this_.call(_method_fn, {name, value});
}
Variant XMLWriter::startAttributeNs(const Variant &prefix, const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2702]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_});
}
Variant XMLWriter::writeAttributeNs(const Variant &prefix,
                                    const Variant &name,
                                    const Variant &namespace_,
                                    const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2703]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_, value});
}
Variant XMLWriter::startElement(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2704]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2705]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::fullEndElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2706]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::startElementNs(const Variant &prefix, const Variant &name, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2707]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_});
}
Variant XMLWriter::writeElement(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2708]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::writeElementNs(const Variant &prefix,
                                  const Variant &name,
                                  const Variant &namespace_,
                                  const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2709]);
    }
    return this_.call(_method_fn, {prefix, name, namespace_, content});
}
Variant XMLWriter::startPi(const Variant &target) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2710]);
    }
    return this_.call(_method_fn, {target});
}
Variant XMLWriter::endPi() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2711]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writePi(const Variant &target, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2712]);
    }
    return this_.call(_method_fn, {target, content});
}
Variant XMLWriter::startCdata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2713]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::endCdata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2714]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeCdata(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2715]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::text(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2716]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::writeRaw(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2717]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::startDocument(const Variant &version, const Variant &encoding, const Variant &standalone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2718]);
    }
    return this_.call(_method_fn, {version, encoding, standalone});
}
Variant XMLWriter::endDocument() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2719]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeComment(const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2720]);
    }
    return this_.call(_method_fn, {content});
}
Variant XMLWriter::startDtd(const Variant &qualified_name, const Variant &public_id, const Variant &system_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2721]);
    }
    return this_.call(_method_fn, {qualified_name, public_id, system_id});
}
Variant XMLWriter::endDtd() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2722]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtd(const Variant &name,
                            const Variant &public_id,
                            const Variant &system_id,
                            const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2723]);
    }
    return this_.call(_method_fn, {name, public_id, system_id, content});
}
Variant XMLWriter::startDtdElement(const Variant &qualified_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2724]);
    }
    return this_.call(_method_fn, {qualified_name});
}
Variant XMLWriter::endDtdElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2725]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdElement(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2726]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::startDtdAttlist(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2727]);
    }
    return this_.call(_method_fn, {name});
}
Variant XMLWriter::endDtdAttlist() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2728]);
    }
    return this_.call(_method_fn, {});
}
Variant XMLWriter::writeDtdAttlist(const Variant &name, const Variant &content) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2729]);
    }
    return this_.call(_method_fn, {name, content});
}
Variant XMLWriter::startDtdEntity(const Variant &name, const Variant &is_param) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2730]);
    }
    return this_.call(_method_fn, {name, is_param});
}
Variant XMLWriter::endDtdEntity() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2731]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2732]);
    }
    return this_.call(_method_fn, {name, content, is_param, public_id, system_id, notation_data});
}
Variant XMLWriter::outputMemory(const Variant &flush) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2733]);
    }
    return this_.call(_method_fn, {flush});
}
Variant XMLWriter::flush(const Variant &empty) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2180]);
    }
    return this_.call(_method_fn, {empty});
}
}  // namespace php

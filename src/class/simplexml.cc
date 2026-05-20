#include "phpx.h"
#include "class/simplexml.h"

namespace php {
Variant SimpleXMLElement::xpath(const Variant &expression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1684]);
    }
    return this_.call(_method_fn, {expression});
}
Variant SimpleXMLElement::registerXPathNamespace(const Variant &prefix, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1685]);
    }
    return this_.call(_method_fn, {prefix, _namespace});
}
Variant SimpleXMLElement::asXML(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1686]);
    }
    return this_.call(_method_fn, {filename});
}
Variant SimpleXMLElement::saveXML(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[404]);
    }
    return this_.call(_method_fn, {filename});
}
Variant SimpleXMLElement::getNamespaces(const Variant &recursive) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1687]);
    }
    return this_.call(_method_fn, {recursive});
}
Variant SimpleXMLElement::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1688]);
    }
    return this_.call(_method_fn, {recursive, from_root});
}
Variant SimpleXMLElement::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1689]);
    }
    return this_.call(_method_fn, {namespace_or_prefix, is_prefix});
}
Variant SimpleXMLElement::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1690]);
    }
    return this_.call(_method_fn, {namespace_or_prefix, is_prefix});
}
SimpleXMLElement::SimpleXMLElement(const Variant &data,
                                   const Variant &options,
                                   const Variant &data_is_u_r_l,
                                   const Variant &namespace_or_prefix,
                                   const Variant &is_prefix) {
    this_ = newObject(LITERAL_STRING[1691], {data, options, data_is_u_r_l, namespace_or_prefix, is_prefix});
}
Variant SimpleXMLElement::addChild(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1692]);
    }
    return this_.call(_method_fn, {qualified_name, value, _namespace});
}
Variant SimpleXMLElement::addAttribute(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1693]);
    }
    return this_.call(_method_fn, {qualified_name, value, _namespace});
}
Variant SimpleXMLElement::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::xpath(const Variant &expression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1684]);
    }
    return this_.call(_method_fn, {expression});
}
Variant SimpleXMLIterator::registerXPathNamespace(const Variant &prefix, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1685]);
    }
    return this_.call(_method_fn, {prefix, _namespace});
}
Variant SimpleXMLIterator::asXML(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1686]);
    }
    return this_.call(_method_fn, {filename});
}
Variant SimpleXMLIterator::saveXML(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[404]);
    }
    return this_.call(_method_fn, {filename});
}
Variant SimpleXMLIterator::getNamespaces(const Variant &recursive) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1687]);
    }
    return this_.call(_method_fn, {recursive});
}
Variant SimpleXMLIterator::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1688]);
    }
    return this_.call(_method_fn, {recursive, from_root});
}
Variant SimpleXMLIterator::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1689]);
    }
    return this_.call(_method_fn, {namespace_or_prefix, is_prefix});
}
Variant SimpleXMLIterator::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1690]);
    }
    return this_.call(_method_fn, {namespace_or_prefix, is_prefix});
}
SimpleXMLIterator::SimpleXMLIterator(const Variant &data,
                                     const Variant &options,
                                     const Variant &data_is_u_r_l,
                                     const Variant &namespace_or_prefix,
                                     const Variant &is_prefix) {
    this_ = newObject(LITERAL_STRING[1694], {data, options, data_is_u_r_l, namespace_or_prefix, is_prefix});
}
Variant SimpleXMLIterator::addChild(const Variant &qualified_name, const Variant &value, const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1692]);
    }
    return this_.call(_method_fn, {qualified_name, value, _namespace});
}
Variant SimpleXMLIterator::addAttribute(const Variant &qualified_name,
                                        const Variant &value,
                                        const Variant &_namespace) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1693]);
    }
    return this_.call(_method_fn, {qualified_name, value, _namespace});
}
Variant SimpleXMLIterator::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

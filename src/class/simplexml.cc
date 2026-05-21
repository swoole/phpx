#include "phpx.h"
#include "phpx_class.h"
#include "class/simplexml.h"

namespace php {
Variant SimpleXMLElement::xpath(const Variant &expression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1818]);
    }
    return this_.call(_method_fn, {expression});
}
Variant SimpleXMLElement::registerXPathNamespace(const Variant &prefix, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1819]);
    }
    return this_.call(_method_fn, {prefix, namespace_});
}
Variant SimpleXMLElement::asXML(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1820]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1821]);
    }
    return this_.call(_method_fn, {recursive});
}
Variant SimpleXMLElement::getDocNamespaces(const Variant &recursive, const Variant &from_root) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1822]);
    }
    return this_.call(_method_fn, {recursive, from_root});
}
Variant SimpleXMLElement::children(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1823]);
    }
    return this_.call(_method_fn, {namespace_or_prefix, is_prefix});
}
Variant SimpleXMLElement::attributes(const Variant &namespace_or_prefix, const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1824]);
    }
    return this_.call(_method_fn, {namespace_or_prefix, is_prefix});
}
SimpleXMLElement::SimpleXMLElement(const Variant &data,
                                   const Variant &options,
                                   const Variant &data_is_u_r_l,
                                   const Variant &namespace_or_prefix,
                                   const Variant &is_prefix) {
    this_ = newObject(LITERAL_STRING[1825], {data, options, data_is_u_r_l, namespace_or_prefix, is_prefix});
}
Variant SimpleXMLElement::addChild(const Variant &qualified_name, const Variant &value, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1826]);
    }
    return this_.call(_method_fn, {qualified_name, value, namespace_});
}
Variant SimpleXMLElement::addAttribute(const Variant &qualified_name, const Variant &value, const Variant &namespace_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1827]);
    }
    return this_.call(_method_fn, {qualified_name, value, namespace_});
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1828]);
    }
    return this_.call(_method_fn, {});
}
Variant SimpleXMLElement::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1829]);
    }
    return this_.call(_method_fn, {});
}
SimpleXMLIterator::SimpleXMLIterator(const Variant &data,
                                     const Variant &options,
                                     const Variant &data_is_u_r_l,
                                     const Variant &namespace_or_prefix,
                                     const Variant &is_prefix) {
    this_ = newObject(LITERAL_STRING[1830], {data, options, data_is_u_r_l, namespace_or_prefix, is_prefix});
}
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant simplexml_load_file(const Variant &filename,
                            const Variant &class_name,
                            const Variant &options,
                            const Variant &namespace_or_prefix,
                            const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1854]);
    }
    return call(_fn, {filename, class_name, options, namespace_or_prefix, is_prefix});
}
Variant simplexml_load_string(const Variant &data,
                              const Variant &class_name,
                              const Variant &options,
                              const Variant &namespace_or_prefix,
                              const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1855]);
    }
    return call(_fn, {data, class_name, options, namespace_or_prefix, is_prefix});
}
Variant simplexml_import_dom(const Variant &node, const Variant &class_name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1856]);
    }
    return call(_fn, {node, class_name});
}
}  // namespace php

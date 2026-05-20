#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant simplexml_load_file(const Variant &filename,
                            const Variant &class_name,
                            const Variant &options,
                            const Variant &namespace_or_prefix,
                            const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1681]);
    }
    return call(fn, {filename, class_name, options, namespace_or_prefix, is_prefix});
}
Variant simplexml_load_string(const Variant &data,
                              const Variant &class_name,
                              const Variant &options,
                              const Variant &namespace_or_prefix,
                              const Variant &is_prefix) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1682]);
    }
    return call(fn, {data, class_name, options, namespace_or_prefix, is_prefix});
}
Variant simplexml_import_dom(const Variant &node, const Variant &class_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1683]);
    }
    return call(fn, {node, class_name});
}
}  // namespace php

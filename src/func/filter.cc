#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant filter_has_var(const Variant &input_type, const Variant &var_name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[557]);
    }
    return call(_fn, {input_type, var_name});
}
Variant filter_input(const Variant &type, const Variant &var_name, const Variant &filter, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[558]);
    }
    return call(_fn, {type, var_name, filter, options});
}
Variant filter_var(const Variant &value, const Variant &filter, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[559]);
    }
    return call(_fn, {value, filter, options});
}
Variant filter_input_array(const Variant &type, const Variant &options, const Variant &add_empty) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[560]);
    }
    return call(_fn, {type, options, add_empty});
}
Variant filter_var_array(const Variant &array, const Variant &options, const Variant &add_empty) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[561]);
    }
    return call(_fn, {array, options, add_empty});
}
Variant filter_list() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[562]);
    }
    return call(_fn, {});
}
Variant filter_id(const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[563]);
    }
    return call(_fn, {name});
}
}  // namespace php

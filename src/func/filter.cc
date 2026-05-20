#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant filter_has_var(const Variant &input_type, const Variant &var_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[533]);
    }
    return call(fn, {input_type, var_name});
}
Variant filter_input(const Variant &type, const Variant &var_name, const Variant &filter, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[534]);
    }
    return call(fn, {type, var_name, filter, options});
}
Variant filter_var(const Variant &value, const Variant &filter, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[535]);
    }
    return call(fn, {value, filter, options});
}
Variant filter_input_array(const Variant &type, const Variant &options, const Variant &add_empty) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[536]);
    }
    return call(fn, {type, options, add_empty});
}
Variant filter_var_array(const Variant &array, const Variant &options, const Variant &add_empty) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[537]);
    }
    return call(fn, {array, options, add_empty});
}
Variant filter_list() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[538]);
    }
    return call(fn, {});
}
Variant filter_id(const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[539]);
    }
    return call(fn, {name});
}
}  // namespace php

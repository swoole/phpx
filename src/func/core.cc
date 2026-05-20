#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant die(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[32]);
    }
    return call(fn, {status});
}
Variant zend_version() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[33]);
    }
    return call(fn, {});
}
Variant func_num_args() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[34]);
    }
    return call(fn, {});
}
Variant func_get_arg(const Variant &position) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[35]);
    }
    return call(fn, {position});
}
Variant func_get_args() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[36]);
    }
    return call(fn, {});
}
Variant strcmp(const Variant &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[37]);
    }
    return call(fn, {string1, string2});
}
Variant strncmp(const Variant &string1, const Variant &string2, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[38]);
    }
    return call(fn, {string1, string2, length});
}
Variant strcasecmp(const Variant &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[39]);
    }
    return call(fn, {string1, string2});
}
Variant strncasecmp(const Variant &string1, const Variant &string2, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[40]);
    }
    return call(fn, {string1, string2, length});
}
Variant error_reporting(const Variant &error_level) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[41]);
    }
    return call(fn, {error_level});
}
Variant define(const Variant &constant_name, const Variant &value, const Variant &case_insensitive) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[42]);
    }
    return call(fn, {constant_name, value, case_insensitive});
}
Variant defined(const Variant &constant_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[43]);
    }
    return call(fn, {constant_name});
}
Variant get_class(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[44]);
    }
    return call(fn, {object});
}
Variant get_called_class() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[45]);
    }
    return call(fn, {});
}
Variant get_parent_class(const Variant &object_or_class) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[46]);
    }
    return call(fn, {object_or_class});
}
Variant is_subclass_of(const Variant &object_or_class, const Variant &_class, const Variant &allow_string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[47]);
    }
    return call(fn, {object_or_class, _class, allow_string});
}
Variant is_a(const Variant &object_or_class, const Variant &_class, const Variant &allow_string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[48]);
    }
    return call(fn, {object_or_class, _class, allow_string});
}
Variant get_class_vars(const Variant &_class) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[49]);
    }
    return call(fn, {_class});
}
Variant get_object_vars(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[50]);
    }
    return call(fn, {object});
}
Variant get_mangled_object_vars(const Variant &object) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[51]);
    }
    return call(fn, {object});
}
Variant get_class_methods(const Variant &object_or_class) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[52]);
    }
    return call(fn, {object_or_class});
}
Variant method_exists(const Variant &object_or_class, const Variant &method) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[53]);
    }
    return call(fn, {object_or_class, method});
}
Variant property_exists(const Variant &object_or_class, const Variant &property) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[54]);
    }
    return call(fn, {object_or_class, property});
}
Variant class_exists(const Variant &_class, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[55]);
    }
    return call(fn, {_class, autoload});
}
Variant interface_exists(const Variant &interface, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[56]);
    }
    return call(fn, {interface, autoload});
}
Variant trait_exists(const Variant &trait, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[57]);
    }
    return call(fn, {trait, autoload});
}
Variant enum_exists(const Variant &_enum, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[58]);
    }
    return call(fn, {_enum, autoload});
}
Variant function_exists(const Variant &function) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[59]);
    }
    return call(fn, {function});
}
Variant class_alias(const Variant &_class, const Variant &alias, const Variant &autoload) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[60]);
    }
    return call(fn, {_class, alias, autoload});
}
Variant get_included_files() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[61]);
    }
    return call(fn, {});
}
Variant get_required_files() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[62]);
    }
    return call(fn, {});
}
Variant trigger_error(const Variant &message, const Variant &error_level) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[63]);
    }
    return call(fn, {message, error_level});
}
Variant user_error(const Variant &message, const Variant &error_level) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[64]);
    }
    return call(fn, {message, error_level});
}
Variant set_error_handler(const Variant &callback, const Variant &error_levels) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[65]);
    }
    return call(fn, {callback, error_levels});
}
Variant restore_error_handler() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[66]);
    }
    return call(fn, {});
}
Variant set_exception_handler(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[67]);
    }
    return call(fn, {callback});
}
Variant restore_exception_handler() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[68]);
    }
    return call(fn, {});
}
Variant get_declared_classes() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[69]);
    }
    return call(fn, {});
}
Variant get_declared_traits() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[70]);
    }
    return call(fn, {});
}
Variant get_declared_interfaces() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[71]);
    }
    return call(fn, {});
}
Variant get_defined_functions(const Variant &exclude_disabled) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[72]);
    }
    return call(fn, {exclude_disabled});
}
Variant get_defined_vars() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[73]);
    }
    return call(fn, {});
}
Variant get_resource_type(const Variant &resource) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[74]);
    }
    return call(fn, {resource});
}
Variant get_resource_id(const Variant &resource) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[75]);
    }
    return call(fn, {resource});
}
Variant get_resources(const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[76]);
    }
    return call(fn, {type});
}
Variant get_loaded_extensions(const Variant &zend_extensions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[77]);
    }
    return call(fn, {zend_extensions});
}
Variant get_defined_constants(const Variant &categorize) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[78]);
    }
    return call(fn, {categorize});
}
Variant debug_backtrace(const Variant &options, const Variant &limit) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[79]);
    }
    return call(fn, {options, limit});
}
Variant debug_print_backtrace(const Variant &options, const Variant &limit) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[80]);
    }
    return call(fn, {options, limit});
}
Variant extension_loaded(const Variant &extension) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[81]);
    }
    return call(fn, {extension});
}
Variant get_extension_funcs(const Variant &extension) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[82]);
    }
    return call(fn, {extension});
}
Variant zend_thread_id() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[83]);
    }
    return call(fn, {});
}
Variant gc_mem_caches() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[84]);
    }
    return call(fn, {});
}
Variant gc_collect_cycles() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[85]);
    }
    return call(fn, {});
}
Variant gc_enabled() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[86]);
    }
    return call(fn, {});
}
Variant gc_enable() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[87]);
    }
    return call(fn, {});
}
Variant gc_disable() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[88]);
    }
    return call(fn, {});
}
Variant gc_status() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[89]);
    }
    return call(fn, {});
}
}  // namespace php

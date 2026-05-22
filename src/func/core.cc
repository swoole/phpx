#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant die(const Variant &status) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[60]);
    }
    return call(_fn, {status});
}
Variant zend_version() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[61]);
    }
    return call(_fn, {});
}
Variant func_num_args() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[62]);
    }
    return call(_fn, {});
}
Variant func_get_arg(const Variant &position) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[63]);
    }
    return call(_fn, {position});
}
Variant func_get_args() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[64]);
    }
    return call(_fn, {});
}
Variant strcmp(const Variant &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[65]);
    }
    return call(_fn, {string1, string2});
}
Variant strncmp(const Variant &string1, const Variant &string2, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[66]);
    }
    return call(_fn, {string1, string2, length});
}
Variant strcasecmp(const Variant &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[67]);
    }
    return call(_fn, {string1, string2});
}
Variant strncasecmp(const Variant &string1, const Variant &string2, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[68]);
    }
    return call(_fn, {string1, string2, length});
}
Variant error_reporting(const Variant &error_level) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[69]);
    }
    return call(_fn, {error_level});
}
Variant define(const Variant &constant_name, const Variant &value, const Variant &case_insensitive) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[70]);
    }
    return call(_fn, {constant_name, value, case_insensitive});
}
Variant defined(const Variant &constant_name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[71]);
    }
    return call(_fn, {constant_name});
}
Variant get_class(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[72]);
    }
    return call(_fn, {object});
}
Variant get_called_class() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[73]);
    }
    return call(_fn, {});
}
Variant get_parent_class(const Variant &object_or_class) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[74]);
    }
    return call(_fn, {object_or_class});
}
Variant is_subclass_of(const Variant &object_or_class, const Variant &class_, const Variant &allow_string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[75]);
    }
    return call(_fn, {object_or_class, class_, allow_string});
}
Variant is_a(const Variant &object_or_class, const Variant &class_, const Variant &allow_string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[76]);
    }
    return call(_fn, {object_or_class, class_, allow_string});
}
Variant get_class_vars(const Variant &class_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[77]);
    }
    return call(_fn, {class_});
}
Variant get_object_vars(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[78]);
    }
    return call(_fn, {object});
}
Variant get_mangled_object_vars(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[79]);
    }
    return call(_fn, {object});
}
Variant get_class_methods(const Variant &object_or_class) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[80]);
    }
    return call(_fn, {object_or_class});
}
Variant method_exists(const Variant &object_or_class, const Variant &method) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[81]);
    }
    return call(_fn, {object_or_class, method});
}
Variant property_exists(const Variant &object_or_class, const Variant &property) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[82]);
    }
    return call(_fn, {object_or_class, property});
}
Variant class_exists(const Variant &class_, const Variant &autoload) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[83]);
    }
    return call(_fn, {class_, autoload});
}
Variant interface_exists(const Variant &interface, const Variant &autoload) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[84]);
    }
    return call(_fn, {interface, autoload});
}
Variant trait_exists(const Variant &trait, const Variant &autoload) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[85]);
    }
    return call(_fn, {trait, autoload});
}
Variant enum_exists(const Variant &enum_, const Variant &autoload) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[86]);
    }
    return call(_fn, {enum_, autoload});
}
Variant function_exists(const Variant &function) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[87]);
    }
    return call(_fn, {function});
}
Variant class_alias(const Variant &class_, const Variant &alias, const Variant &autoload) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[88]);
    }
    return call(_fn, {class_, alias, autoload});
}
Variant get_included_files() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[89]);
    }
    return call(_fn, {});
}
Variant get_required_files() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[90]);
    }
    return call(_fn, {});
}
Variant trigger_error(const Variant &message, const Variant &error_level) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[91]);
    }
    return call(_fn, {message, error_level});
}
Variant user_error(const Variant &message, const Variant &error_level) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[92]);
    }
    return call(_fn, {message, error_level});
}
Variant set_error_handler(const Variant &callback, const Variant &error_levels) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[93]);
    }
    return call(_fn, {callback, error_levels});
}
Variant restore_error_handler() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[94]);
    }
    return call(_fn, {});
}
Variant set_exception_handler(const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[95]);
    }
    return call(_fn, {callback});
}
Variant restore_exception_handler() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[96]);
    }
    return call(_fn, {});
}
Variant get_declared_classes() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[97]);
    }
    return call(_fn, {});
}
Variant get_declared_traits() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[98]);
    }
    return call(_fn, {});
}
Variant get_declared_interfaces() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[99]);
    }
    return call(_fn, {});
}
Variant get_defined_functions(const Variant &exclude_disabled) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[100]);
    }
    return call(_fn, {exclude_disabled});
}
Variant get_defined_vars() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[101]);
    }
    return call(_fn, {});
}
Variant get_resource_type(const Variant &resource) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[102]);
    }
    return call(_fn, {resource});
}
Variant get_resource_id(const Variant &resource) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[103]);
    }
    return call(_fn, {resource});
}
Variant get_resources(const Variant &type) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[104]);
    }
    return call(_fn, {type});
}
Variant get_loaded_extensions(const Variant &zend_extensions) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[105]);
    }
    return call(_fn, {zend_extensions});
}
Variant get_defined_constants(const Variant &categorize) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[106]);
    }
    return call(_fn, {categorize});
}
Variant debug_backtrace(const Variant &options, const Variant &limit) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[107]);
    }
    return call(_fn, {options, limit});
}
Variant debug_print_backtrace(const Variant &options, const Variant &limit) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[108]);
    }
    return call(_fn, {options, limit});
}
Variant extension_loaded(const Variant &extension) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[109]);
    }
    return call(_fn, {extension});
}
Variant get_extension_funcs(const Variant &extension) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[110]);
    }
    return call(_fn, {extension});
}
Variant zend_thread_id() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[111]);
    }
    return call(_fn, {});
}
Variant gc_mem_caches() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[112]);
    }
    return call(_fn, {});
}
Variant gc_collect_cycles() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[113]);
    }
    return call(_fn, {});
}
Variant gc_enabled() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[114]);
    }
    return call(_fn, {});
}
Variant gc_enable() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[115]);
    }
    return call(_fn, {});
}
Variant gc_disable() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[116]);
    }
    return call(_fn, {});
}
Variant gc_status() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[117]);
    }
    return call(_fn, {});
}
}  // namespace php

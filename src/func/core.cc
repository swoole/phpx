#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant die(const Variant &status) {
    return call(LITERAL_STRING[32], {status});
}
Variant zend_version() {
    return call(LITERAL_STRING[33], {});
}
Variant func_num_args() {
    return call(LITERAL_STRING[34], {});
}
Variant func_get_arg(const Variant &position) {
    return call(LITERAL_STRING[35], {position});
}
Variant func_get_args() {
    return call(LITERAL_STRING[36], {});
}
Variant strcmp(const Variant &string1, const Variant &string2) {
    return call(LITERAL_STRING[37], {string1, string2});
}
Variant strncmp(const Variant &string1, const Variant &string2, const Variant &length) {
    return call(LITERAL_STRING[38], {string1, string2, length});
}
Variant strcasecmp(const Variant &string1, const Variant &string2) {
    return call(LITERAL_STRING[39], {string1, string2});
}
Variant strncasecmp(const Variant &string1, const Variant &string2, const Variant &length) {
    return call(LITERAL_STRING[40], {string1, string2, length});
}
Variant error_reporting(const Variant &error_level) {
    return call(LITERAL_STRING[41], {error_level});
}
Variant define(const Variant &constant_name, const Variant &value, const Variant &case_insensitive) {
    return call(LITERAL_STRING[42], {constant_name, value, case_insensitive});
}
Variant defined(const Variant &constant_name) {
    return call(LITERAL_STRING[43], {constant_name});
}
Variant get_class(const Variant &object) {
    return call(LITERAL_STRING[44], {object});
}
Variant get_called_class() {
    return call(LITERAL_STRING[45], {});
}
Variant get_parent_class(const Variant &object_or_class) {
    return call(LITERAL_STRING[46], {object_or_class});
}
Variant is_subclass_of(const Variant &object_or_class, const Variant &_class, const Variant &allow_string) {
    return call(LITERAL_STRING[47], {object_or_class, _class, allow_string});
}
Variant is_a(const Variant &object_or_class, const Variant &_class, const Variant &allow_string) {
    return call(LITERAL_STRING[48], {object_or_class, _class, allow_string});
}
Variant get_class_vars(const Variant &_class) {
    return call(LITERAL_STRING[49], {_class});
}
Variant get_object_vars(const Variant &object) {
    return call(LITERAL_STRING[50], {object});
}
Variant get_mangled_object_vars(const Variant &object) {
    return call(LITERAL_STRING[51], {object});
}
Variant get_class_methods(const Variant &object_or_class) {
    return call(LITERAL_STRING[52], {object_or_class});
}
Variant method_exists(const Variant &object_or_class, const Variant &method) {
    return call(LITERAL_STRING[53], {object_or_class, method});
}
Variant property_exists(const Variant &object_or_class, const Variant &property) {
    return call(LITERAL_STRING[54], {object_or_class, property});
}
Variant class_exists(const Variant &_class, const Variant &autoload) {
    return call(LITERAL_STRING[55], {_class, autoload});
}
Variant interface_exists(const Variant &interface, const Variant &autoload) {
    return call(LITERAL_STRING[56], {interface, autoload});
}
Variant trait_exists(const Variant &trait, const Variant &autoload) {
    return call(LITERAL_STRING[57], {trait, autoload});
}
Variant enum_exists(const Variant &_enum, const Variant &autoload) {
    return call(LITERAL_STRING[58], {_enum, autoload});
}
Variant function_exists(const Variant &function) {
    return call(LITERAL_STRING[59], {function});
}
Variant class_alias(const Variant &_class, const Variant &alias, const Variant &autoload) {
    return call(LITERAL_STRING[60], {_class, alias, autoload});
}
Variant get_included_files() {
    return call(LITERAL_STRING[61], {});
}
Variant get_required_files() {
    return call(LITERAL_STRING[62], {});
}
Variant trigger_error(const Variant &message, const Variant &error_level) {
    return call(LITERAL_STRING[63], {message, error_level});
}
Variant user_error(const Variant &message, const Variant &error_level) {
    return call(LITERAL_STRING[64], {message, error_level});
}
Variant set_error_handler(const Variant &callback, const Variant &error_levels) {
    return call(LITERAL_STRING[65], {callback, error_levels});
}
Variant restore_error_handler() {
    return call(LITERAL_STRING[66], {});
}
Variant set_exception_handler(const Variant &callback) {
    return call(LITERAL_STRING[67], {callback});
}
Variant restore_exception_handler() {
    return call(LITERAL_STRING[68], {});
}
Variant get_declared_classes() {
    return call(LITERAL_STRING[69], {});
}
Variant get_declared_traits() {
    return call(LITERAL_STRING[70], {});
}
Variant get_declared_interfaces() {
    return call(LITERAL_STRING[71], {});
}
Variant get_defined_functions(const Variant &exclude_disabled) {
    return call(LITERAL_STRING[72], {exclude_disabled});
}
Variant get_defined_vars() {
    return call(LITERAL_STRING[73], {});
}
Variant get_resource_type(const Variant &resource) {
    return call(LITERAL_STRING[74], {resource});
}
Variant get_resource_id(const Variant &resource) {
    return call(LITERAL_STRING[75], {resource});
}
Variant get_resources(const Variant &type) {
    return call(LITERAL_STRING[76], {type});
}
Variant get_loaded_extensions(const Variant &zend_extensions) {
    return call(LITERAL_STRING[77], {zend_extensions});
}
Variant get_defined_constants(const Variant &categorize) {
    return call(LITERAL_STRING[78], {categorize});
}
Variant debug_backtrace(const Variant &options, const Variant &limit) {
    return call(LITERAL_STRING[79], {options, limit});
}
Variant debug_print_backtrace(const Variant &options, const Variant &limit) {
    return call(LITERAL_STRING[80], {options, limit});
}
Variant extension_loaded(const Variant &extension) {
    return call(LITERAL_STRING[81], {extension});
}
Variant get_extension_funcs(const Variant &extension) {
    return call(LITERAL_STRING[82], {extension});
}
Variant zend_thread_id() {
    return call(LITERAL_STRING[83], {});
}
Variant gc_mem_caches() {
    return call(LITERAL_STRING[84], {});
}
Variant gc_collect_cycles() {
    return call(LITERAL_STRING[85], {});
}
Variant gc_enabled() {
    return call(LITERAL_STRING[86], {});
}
Variant gc_enable() {
    return call(LITERAL_STRING[87], {});
}
Variant gc_disable() {
    return call(LITERAL_STRING[88], {});
}
Variant gc_status() {
    return call(LITERAL_STRING[89], {});
}
}  // namespace php

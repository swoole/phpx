#include "phpx.h"

namespace php {
Variant die(const Variant &status) {
    return call("die", {status});
}
Variant zend_version() {
    return call("zend_version", {});
}
Variant func_num_args() {
    return call("func_num_args", {});
}
Variant func_get_arg(const Variant &position) {
    return call("func_get_arg", {position});
}
Variant func_get_args() {
    return call("func_get_args", {});
}
Variant strcmp(const Variant &string1, const Variant &string2) {
    return call("strcmp", {string1, string2});
}
Variant strncmp(const Variant &string1, const Variant &string2, const Variant &length) {
    return call("strncmp", {string1, string2, length});
}
Variant strcasecmp(const Variant &string1, const Variant &string2) {
    return call("strcasecmp", {string1, string2});
}
Variant strncasecmp(const Variant &string1, const Variant &string2, const Variant &length) {
    return call("strncasecmp", {string1, string2, length});
}
Variant error_reporting(const Variant &error_level) {
    return call("error_reporting", {error_level});
}
Variant define(const Variant &constant_name, const Variant &value, const Variant &case_insensitive) {
    return call("define", {constant_name, value, case_insensitive});
}
Variant defined(const Variant &constant_name) {
    return call("defined", {constant_name});
}
Variant get_class(const Variant &object) {
    return call("get_class", {object});
}
Variant get_called_class() {
    return call("get_called_class", {});
}
Variant get_parent_class(const Variant &object_or_class) {
    return call("get_parent_class", {object_or_class});
}
Variant is_subclass_of(const Variant &object_or_class, const Variant &_class, const Variant &allow_string) {
    return call("is_subclass_of", {object_or_class, _class, allow_string});
}
Variant is_a(const Variant &object_or_class, const Variant &_class, const Variant &allow_string) {
    return call("is_a", {object_or_class, _class, allow_string});
}
Variant get_class_vars(const Variant &_class) {
    return call("get_class_vars", {_class});
}
Variant get_object_vars(const Variant &object) {
    return call("get_object_vars", {object});
}
Variant get_mangled_object_vars(const Variant &object) {
    return call("get_mangled_object_vars", {object});
}
Variant get_class_methods(const Variant &object_or_class) {
    return call("get_class_methods", {object_or_class});
}
Variant method_exists(const Variant &object_or_class, const Variant &method) {
    return call("method_exists", {object_or_class, method});
}
Variant property_exists(const Variant &object_or_class, const Variant &property) {
    return call("property_exists", {object_or_class, property});
}
Variant class_exists(const Variant &_class, const Variant &autoload) {
    return call("class_exists", {_class, autoload});
}
Variant interface_exists(const Variant &interface, const Variant &autoload) {
    return call("interface_exists", {interface, autoload});
}
Variant trait_exists(const Variant &trait, const Variant &autoload) {
    return call("trait_exists", {trait, autoload});
}
Variant enum_exists(const Variant &_enum, const Variant &autoload) {
    return call("enum_exists", {_enum, autoload});
}
Variant function_exists(const Variant &function) {
    return call("function_exists", {function});
}
Variant class_alias(const Variant &_class, const Variant &alias, const Variant &autoload) {
    return call("class_alias", {_class, alias, autoload});
}
Variant get_included_files() {
    return call("get_included_files", {});
}
Variant get_required_files() {
    return call("get_required_files", {});
}
Variant trigger_error(const Variant &message, const Variant &error_level) {
    return call("trigger_error", {message, error_level});
}
Variant user_error(const Variant &message, const Variant &error_level) {
    return call("user_error", {message, error_level});
}
Variant set_error_handler(const Variant &callback, const Variant &error_levels) {
    return call("set_error_handler", {callback, error_levels});
}
Variant restore_error_handler() {
    return call("restore_error_handler", {});
}
Variant set_exception_handler(const Variant &callback) {
    return call("set_exception_handler", {callback});
}
Variant restore_exception_handler() {
    return call("restore_exception_handler", {});
}
Variant get_declared_classes() {
    return call("get_declared_classes", {});
}
Variant get_declared_traits() {
    return call("get_declared_traits", {});
}
Variant get_declared_interfaces() {
    return call("get_declared_interfaces", {});
}
Variant get_defined_functions(const Variant &exclude_disabled) {
    return call("get_defined_functions", {exclude_disabled});
}
Variant get_defined_vars() {
    return call("get_defined_vars", {});
}
Variant get_resource_type(const Variant &resource) {
    return call("get_resource_type", {resource});
}
Variant get_resource_id(const Variant &resource) {
    return call("get_resource_id", {resource});
}
Variant get_resources(const Variant &type) {
    return call("get_resources", {type});
}
Variant get_loaded_extensions(const Variant &zend_extensions) {
    return call("get_loaded_extensions", {zend_extensions});
}
Variant get_defined_constants(const Variant &categorize) {
    return call("get_defined_constants", {categorize});
}
Variant debug_backtrace(const Variant &options, const Variant &limit) {
    return call("debug_backtrace", {options, limit});
}
Variant debug_print_backtrace(const Variant &options, const Variant &limit) {
    return call("debug_print_backtrace", {options, limit});
}
Variant extension_loaded(const Variant &extension) {
    return call("extension_loaded", {extension});
}
Variant get_extension_funcs(const Variant &extension) {
    return call("get_extension_funcs", {extension});
}
Variant zend_thread_id() {
    return call("zend_thread_id", {});
}
Variant gc_mem_caches() {
    return call("gc_mem_caches", {});
}
Variant gc_collect_cycles() {
    return call("gc_collect_cycles", {});
}
Variant gc_enabled() {
    return call("gc_enabled", {});
}
Variant gc_enable() {
    return call("gc_enable", {});
}
Variant gc_disable() {
    return call("gc_disable", {});
}
Variant gc_status() {
    return call("gc_status", {});
}
}

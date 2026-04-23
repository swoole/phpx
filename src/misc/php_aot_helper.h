#include <phpx.h>
#include <phpx_helper.h>

#include <zend_attributes.h>

extern zend_class_entry *php_get_class(int class_id, const php::Str &class_name);
extern zend_function *php_get_func(int func_id, const php::Str &func_name);
extern zend_function *php_get_method(int func_id,
                                     const php::Str &method_name,
                                     int class_id,
                                     const php::Str &class_name);
extern uint32_t php_get_prop(int prop_id, const php::Str &prop_name, int class_id, const php::Str &class_name);

namespace php {
struct Scope {
    zend_class_entry *ce;
    zend_execute_data *frame;
};
};  // namespace php

extern const char *php_get_called_class(php::Object &this_);
extern zend_class_entry *php_get_called_ce(php::Object &this_);
extern php::Scope php_switch_scope(php::Object &this_);
extern void php_restore_scope(php::Scope &ori_scope);

static inline auto php_std_create_object(zend_class_entry *ce) {
    auto obj = zend_objects_new(ce);
    object_properties_init(obj, ce);
    return obj;
}

static inline auto php_get_create_object_fn(zend_class_entry *ce) {
    return ce->create_object ? ce->create_object : php_std_create_object;
}

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

/**
 * Create a deep copy from $GLOBALS. $GLOBALS is a special INDIRECT zval
 * pointing to &EG(symbol_table), whose refcount MUST NOT be directly
 * manipulated. Use zend_array_dup to create a proper separated copy.
 */
static inline php::Var php_globals_array() {
    return php::Var(zend_array_dup(&EG(symbol_table)), php::Ctor::Move);
}

namespace php {
struct Scope {
    zend_class_entry *ce;
    zend_execute_data *frame;
};
template <typename T>
static inline T &toStdContainer(Var &var, uint32_t type_id) {
    auto *box = var.toBox<StdContainerBox<T>>();
    if (UNEXPECTED(box->getTypeInfo() != type_id)) {
        throwException(zend_ce_type_error, "std container type mismatch");
    }
    return box->container;
}
};  // namespace php

extern const char *php_get_called_class(php::Object &this_);
extern zend_class_entry *php_get_called_ce(php::Object &this_);
extern php::Scope php_switch_scope(php::Object &this_);
extern void php_restore_scope(php::Scope &ori_scope);

extern inline php::Var php_deindirect(const php::Var &var) {
    return php::Var{var.const_ptr(), php::Ctor::CopyRef};
}

static inline auto php_std_create_object(zend_class_entry *ce) {
    auto obj = zend_objects_new(ce);
    object_properties_init(obj, ce);
    return obj;
}

static inline auto php_get_create_object_fn(zend_class_entry *ce) {
    return ce->create_object ? ce->create_object : php_std_create_object;
}

/**
 * Custom unset_property handler that resets typed properties to their
 * type-appropriate default values instead of making them uninitialized.
 * Only simple scalar/array types (int, float, bool, string, array) and
 * direct object property slots are handled; union/object types and static
 * properties fall through to std behavior. Existing reference containers are
 * preserved by resetting their inner value.
 */
extern void php_aot_unset_typed_property(zend_object *object, zend_string *member, void **cache_slot);

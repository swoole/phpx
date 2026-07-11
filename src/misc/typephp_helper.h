#include <phpx.h>
#include <phpx_helper.h>

#include <zend_attributes.h>
#include <cstdlib>

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

static inline Variant aotExit() {
    std::exit(0);
    return null;
}

static inline Variant aotExit(const Variant &status) {
    if (status.isInt()) {
        std::exit(status.toInt());
    }
    echo(toString(status));
    std::exit(0);
    return null;
}

static inline Variant throwValue(const Variant &e) {
    if (!e.isObject()) {
        throwError("Can only throw objects");
        return null;
    }
    return throwException(Object(e));
}

static inline void appendCallExtraNamedArgs(Array &args) {
    zend_array *named_args = getCallExtraNamedArgs();
    if (named_args == nullptr) {
        return;
    }
    zend_string *key;
    zval *value;
    ZEND_HASH_MAP_FOREACH_STR_KEY_VAL(named_args, key, value) {
        if (key) {
            args.set(key, Variant(value, Ctor::CopyRef));
        }
    }
    ZEND_HASH_FOREACH_END();
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
extern void typephp_unset_typed_property(zend_object *object, zend_string *member, void **cache_slot);

/** Install TypePHP's cross-version property hook and asymmetric-set handlers. */
extern void typephp_install_property_handlers(zend_class_entry *class_entry, zend_object_handlers *handlers);

/** Attach per-class handlers after create_object on PHP versions before 8.4. */
extern zend_object *typephp_attach_property_handlers(zend_object *object, zend_object_handlers *handlers);

/** Write a dynamic property while preserving the AOT source-level class scope. */
extern void typephp_write_property_scoped(const php::Variant &object,
                                          const php::Variant &member,
                                          const php::Variant &value,
                                          zend_class_entry *scope);

/**
 * Return a typed C++ reference into a static-property (or object-property) zval's
 * value slot, used by the AOT local-ref hoisting optimizer. If the slot was
 * turned into a PHP reference (IS_REFERENCE), alias the referenced value so the
 * hoisted local keeps pointing at the live storage.
 */
static inline php::Int &typephp_static_int_ref(zval *slot) {
    return Z_LVAL_P(Z_ISREF_P(slot) ? Z_REFVAL_P(slot) : slot);
}

static inline php::Float &typephp_static_float_ref(zval *slot) {
    return Z_DVAL_P(Z_ISREF_P(slot) ? Z_REFVAL_P(slot) : slot);
}

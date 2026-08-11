#pragma once

#include <phpx.h>
#include <phpx_helper.h>

#include <zend_attributes.h>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#ifdef ZTS
#include <atomic>
#endif

#if defined(_WIN32)
#define TYPEPHP_SYMBOL_EXPORT __declspec(dllexport)
#define TYPEPHP_SYMBOL_IMPORT __declspec(dllimport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#define TYPEPHP_SYMBOL_EXPORT __attribute__((visibility("default")))
#define TYPEPHP_SYMBOL_IMPORT __attribute__((visibility("default")))
#else
#define TYPEPHP_SYMBOL_EXPORT
#define TYPEPHP_SYMBOL_IMPORT
#endif

using typephp_attribute_value_factory = php::Var (*)(php::Bool describe);

/** Mark one persistent attribute argument for request-time value materialization. */
void typephp_attribute_set_lazy_value_argument(zend_attribute *attribute,
                                               uint32_t argument_index,
                                               typephp_attribute_value_factory factory);

/** Install/uninstall TypePHP's ReflectionAttribute lazy-argument handlers. */
zend_result typephp_install_reflection_attribute_handlers();
void typephp_uninstall_reflection_attribute_handlers();

#if defined(__GNUC__) || defined(__clang__)
#define TYPEPHP_HOT_ATTRIBUTE __attribute__((hot))
#define TYPEPHP_COLD_ATTRIBUTE __attribute__((cold))
#else
#define TYPEPHP_HOT_ATTRIBUTE
#define TYPEPHP_COLD_ATTRIBUTE
#endif

namespace php {

/**
 * One module-lifetime cache slot for a symbol resolved after PHP startup.
 * ZTS publishes the value atomically; NTS deliberately remains a plain value.
 */
#ifdef ZTS
template <typename T>
using PersistentCacheSlot = std::atomic<T>;
#else
template <typename T>
using PersistentCacheSlot = T;
#endif

template <typename T, typename Resolver>
static inline T getPersistentCache(PersistentCacheSlot<T> &slot, Resolver &&resolver) {
#ifdef ZTS
    T value = slot.load(std::memory_order_acquire);
    if (UNEXPECTED(value == T{})) {
        T resolved = resolver();
        T expected{};
        if (slot.compare_exchange_strong(expected, resolved, std::memory_order_release, std::memory_order_acquire)) {
            value = resolved;
        } else {
            value = expected;
        }
    }
    return value;
#else
    if (UNEXPECTED(slot == T{})) {
        slot = resolver();
    }
    return slot;
#endif
}

template <typename T>
static inline void resetPersistentCache(PersistentCacheSlot<T> &slot) {
#ifdef ZTS
    slot.store(T{}, std::memory_order_relaxed);
#else
    slot = T{};
#endif
}

}  // namespace php

extern zend_class_entry *php_get_class(int class_id, const php::Str &class_name);
extern zend_function *php_get_func(int func_id, const php::Str &func_name);
extern zend_function *php_get_method(int func_id,
                                     const php::Str &method_name,
                                     int class_id,
                                     const php::Str &class_name);

/* Persistent (MINIT-registered, module-lifetime) symbol caches. They are initialized
 * lazily after PHP startup — once disable_functions/disable_classes have finalized
 * the runtime tables — and are never cleared at request shutdown. There is no
 * dynamic propMap: property offset caches only cover declared properties of
 * compiled/internal classes, which are stable for the module lifetime. */
extern zend_class_entry *php_get_persistent_class(int class_id, const php::Str &class_name);
extern zend_function *php_get_persistent_func(int func_id, const php::Str &func_name);
extern zend_function *php_get_persistent_method(int func_id,
                                                const php::Str &method_name,
                                                int class_id,
                                                const php::Str &class_name);
extern uint32_t php_get_persistent_prop(int prop_id,
                                        const php::Str &prop_name,
                                        int class_id,
                                        const php::Str &class_name);

/** Invoke the lexical parent constructor as part of a new-expression chain. */
static inline php::Variant typephp_call_parent_constructor(php::Object &object,
                                                           zend_function *constructor,
                                                           php::Args &args,
                                                           zend_array *named_args = nullptr) {
    php::Variant retval;
    zend_call_known_function(constructor,
                             object.checkedObject("Call to parent constructor"),
                             object.ce(),
                             retval.ptr(),
                             args.count(),
                             args.ptr(),
                             named_args);
    php::throwErrorIfOccurred();
    return retval;
}

static inline php::Variant typephp_call_parent_constructor(php::Object &object, zend_function *constructor) {
    php::Args args;
    return typephp_call_parent_constructor(object, constructor, args);
}

static inline php::Variant typephp_call_parent_constructor(php::Object &object,
                                                           zend_function *constructor,
                                                           const php::ArgList &args,
                                                           zend_array *named_args = nullptr) {
    php::Args call_args(args);
    return typephp_call_parent_constructor(object, constructor, call_args, named_args);
}

static inline php::Variant typephp_call_parent_constructor(php::Object &object,
                                                           zend_function *constructor,
                                                           php::Array &args,
                                                           zend_array *named_args = nullptr) {
    php::Args call_args(args);
    return typephp_call_parent_constructor(object, constructor, call_args, named_args);
}

/** Invoke the lexical parent clone hook as part of a clone-expression chain. */
static inline php::Variant typephp_call_parent_clone(php::Object &object, zend_function *clone_method) {
    php::Variant retval;
    zend_call_known_function(clone_method,
                             object.checkedObject("Call to parent clone method"),
                             object.ce(),
                             retval.ptr(),
                             0,
                             nullptr,
                             nullptr);
    php::throwErrorIfOccurred();
    return retval;
}

/**
 * Create a deep copy from $GLOBALS. $GLOBALS is a special INDIRECT zval
 * pointing to &EG(symbol_table), whose refcount MUST NOT be directly
 * manipulated. Use zend_array_dup to create a proper separated copy.
 */
static inline php::Var php_globals_array() {
    return php::Var(zend_array_dup(&EG(symbol_table)), php::Ctor::Move);
}

namespace php {
/**
 * Temporarily exposes the called class through the nearest user-code frame.
 *
 * TypePHP uses this only when argument unpacking hides the callback position
 * from the compiler. Ordinary callable resolution uses CallableScope instead.
 */
class UserCodeScopeGuard final {
  public:
    explicit UserCodeScopeGuard(const CallableScope &scope);
    ~UserCodeScopeGuard() noexcept;

    UserCodeScopeGuard(const UserCodeScopeGuard &) = delete;
    UserCodeScopeGuard &operator=(const UserCodeScopeGuard &) = delete;
    UserCodeScopeGuard(UserCodeScopeGuard &&) = delete;
    UserCodeScopeGuard &operator=(UserCodeScopeGuard &&) = delete;

  private:
    zend_function *function_ = nullptr;
    zend_class_entry *previous_scope_ = nullptr;
};
[[noreturn]] static inline void throwStdContainerTypeMismatch() {
    throwException(zend_ce_type_error, "std container type mismatch");
    std::abort();
}
template <typename T>
static inline T &toStdContainer(Var &var, uint32_t type_id) {
    auto *base_box = var.toBox<Box>();
    if (UNEXPECTED(base_box->getTypeInfo() != type_id)) {
        throwStdContainerTypeMismatch();
    }
    auto *box = dynamic_cast<StdContainerBox<T> *>(base_box);
    if (UNEXPECTED(box == nullptr)) {
        throwStdContainerTypeMismatch();
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

extern php::Str php_get_called_class(php::Object &this_);
extern zend_class_entry *php_get_called_ce(php::Object &this_);
static inline php::CallableScope php_get_callable_scope(zend_function *caller_function,
                                                        php::Object &this_) {
    auto *called_scope = php_get_called_ce(this_);
    return php::CallableScope{
        caller_function,
        called_scope,
        this_.isObject() ? this_.object() : nullptr,
    };
}
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

/**
 * Create an AOT object and initialize its runtime property defaults without
 * exposing PHP-version-specific handler ordering to generated code.
 *
 * On PHP < 8.4 the saved allocator must always be used, then the per-class
 * handlers are attached before initialization. On PHP >= 8.4 a class may use
 * the standard allocator directly, but must delegate to the saved allocator
 * when an ancestor owns runtime initialization or custom object storage.
 */
template <typename Initializer>
static inline zend_object *typephp_create_object_with_defaults(zend_class_entry *class_type,
                                                               zend_object *(*base_create_object)(zend_class_entry *),
                                                               zend_object_handlers *handlers,
                                                               bool delegate_to_base_on_php84,
                                                               Initializer &&initializer) {
#if PHP_VERSION_ID < 80400
    (void) delegate_to_base_on_php84;
    auto *object = base_create_object(class_type);
    typephp_attach_property_handlers(object, handlers);

    php::FakeScopeGuard fake_scope_guard{object->ce};
    initializer(object);
    return object;
#else
    zend_object *object;
    if (delegate_to_base_on_php84) {
        object = base_create_object(class_type);
    } else {
        object = zend_objects_new(class_type);
        object_properties_init(object, class_type);
    }

    object->handlers = const_cast<zend_object_handlers *>(zend_get_std_object_handlers());
    try {
        initializer(object);
    } catch (...) {
        object->handlers = handlers;
        throw;
    }
    object->handlers = handlers;
    return object;
#endif
}

/** Write a dynamic property while preserving the AOT source-level class scope. */
extern void typephp_write_property_scoped(const php::Variant &object,
                                          const php::Variant &member,
                                          const php::Variant &value,
                                          zend_class_entry *scope);

/** Read a dynamic property using the lexical scope supplied by an AOT trait wrapper. */
extern php::Variant typephp_read_property_scoped(const php::Variant &object,
                                                 const php::Variant &member,
                                                 zend_class_entry *scope,
                                                 php::AttrMode mode);

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

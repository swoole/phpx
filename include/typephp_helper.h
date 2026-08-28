#pragma once

#include <phpx.h>
#include <phpx_helper.h>

#include <zend_attributes.h>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <string_view>
#ifdef ZTS
#include <atomic>
#endif

// Generic Zend/PHPX wrappers belong to namespace php. Helpers implementing
// TypePHP-only semantics use the typephp_ prefix. A global php_* helper can
// collide with the compiled symbol of a user-defined global PHP function.

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
PHPX_API void typephp_attribute_set_lazy_value_argument(zend_attribute *attribute,
                                                        uint32_t argument_index,
                                                        typephp_attribute_value_factory factory);

/** Install/uninstall TypePHP's ReflectionAttribute lazy-argument handlers. */
PHPX_API zend_result typephp_install_reflection_attribute_handlers();
PHPX_API void typephp_uninstall_reflection_attribute_handlers();

/** Attach TypePHP-lowered concrete hooks to an internal class property. */
PHPX_API void typephp_register_property_hooks(zend_class_entry *class_entry,
                                              zend_property_info *property_info,
                                              std::string_view getter,
                                              std::string_view setter);

/** Attach abstract hook metadata emitted for a TypePHP interface property. */
PHPX_API void typephp_register_abstract_property_hooks(zend_class_entry *class_entry,
                                                       zend_property_info *property_info,
                                                       bool getter,
                                                       bool setter);

/** Prepare an inherited property-info entry for a TypePHP redeclaration. */
PHPX_API void typephp_prepare_property_redeclaration(zend_class_entry *class_entry, zend_string *name);

/** Inherit hook kinds omitted by a TypePHP child property declaration. */
PHPX_API void typephp_finalize_property_hook_inheritance(zend_class_entry *class_entry);

/** Resolve the hook targeted by a TypePHP parent::$property::get()/set() call. */
PHPX_API zend_function *typephp_get_parent_property_hook(zend_class_entry *parent_class_entry,
                                                         const php::String &property,
                                                         zend_property_hook_kind kind);

#if defined(__GNUC__) || defined(__clang__)
#define TYPEPHP_HOT_ATTRIBUTE __attribute__((hot))
#define TYPEPHP_COLD_ATTRIBUTE __attribute__((cold))
#else
#define TYPEPHP_HOT_ATTRIBUTE
#define TYPEPHP_COLD_ATTRIBUTE
#endif

namespace php {

/**
 * Validate an indexed list write against PHP's real append position.
 *
 * HashTable::nNextFreeElement deliberately does not shrink when elements are
 * unset. It is therefore the correct upper boundary for a write that may
 * either update an earlier numeric key or append without skipping the key PHP
 * itself would choose for `$array[]`.
 */
static inline Int safeArrayIndex(Int index, const Variant &array) {
    const zval *value = array.unwrap_ptr();
    if (UNEXPECTED(!zval_is_array(value))) {
        throwError("Array index validation expects an array, %s given", array.typeStr());
        return -1;
    }

    Int next_index = zend_hash_next_free_element(Z_ARRVAL_P(value));
    // zend_hash_next_index_insert() maps the uninitialized sentinel to the
    // first normal list index. Do the same without mutating the HashTable.
    if (next_index == ZEND_LONG_MIN) {
        next_index = 0;
    }
    if (UNEXPECTED(index < 0 || index > next_index)) {
        throwError(
            "Array index out of bounds: index " ZEND_LONG_FMT ", append index " ZEND_LONG_FMT, index, next_index);
        return -1;
    }
    return index;
}

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

/**
 * Create a deep copy from $GLOBALS. $GLOBALS is a special INDIRECT zval
 * pointing to &EG(symbol_table), whose refcount MUST NOT be directly
 * manipulated. Use zend_array_dup to create a proper separated copy.
 */
static inline Var globalsArray() {
    return Var(zend_array_dup(&EG(symbol_table)), Ctor::Move);
}

/**
 * Temporarily exposes the called class through the nearest user-code frame.
 *
 * TypePHP uses this only when argument unpacking hides the callback position
 * from the compiler. Ordinary callable resolution uses CallableScope instead.
 */
class PHPX_API UserCodeScopeGuard final {
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

PHPX_API Str getCalledClass(Object &this_);
PHPX_API zend_class_entry *getCalledCe(Object &this_);
static inline CallableScope getCallableScope(zend_function *caller_function, Object &this_) {
    auto *called_scope = getCalledCe(this_);
    return CallableScope{
        caller_function,
        called_scope,
        this_.isObject() ? this_.object() : nullptr,
    };
}
inline Var deindirect(const Var &var) {
    return Var{var.const_ptr(), Ctor::CopyRef};
}

static inline auto stdCreateObject(zend_class_entry *ce) {
    auto obj = zend_objects_new(ce);
    object_properties_init(obj, ce);
    return obj;
}

static inline auto getCreateObjectFn(zend_class_entry *ce) {
    return ce->create_object ? ce->create_object : stdCreateObject;
}

}  // namespace php

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
 * Custom unset_property handler that resets typed properties to their
 * type-appropriate default values instead of making them uninitialized.
 * Only simple scalar/array types (int, float, bool, string, array) and
 * direct object property slots are handled; union/object types and static
 * properties fall through to std behavior. Existing reference containers are
 * preserved by resetting their inner value.
 */
PHPX_API void typephp_unset_typed_property(zend_object *object, zend_string *member, void **cache_slot);

/**
 * Install TypePHP's property hook and asymmetric-set handlers. On PHP 8.5+
 * this also installs a clone-with handler that preserves the handler table and
 * applies updated properties using the lexical calling scope.
 */
PHPX_API void typephp_install_property_handlers(zend_class_entry *class_entry, zend_object_handlers *handlers);

/**
 * Create an AOT object and initialize its runtime property defaults. A class
 * delegates to the saved allocator when an ancestor owns runtime
 * initialization or custom object storage.
 */
template <typename Initializer>
static inline zend_object *typephp_create_object_with_defaults(zend_class_entry *class_type,
                                                               zend_object *(*base_create_object)(zend_class_entry *),
                                                               bool delegate_to_base,
                                                               Initializer &&initializer) {
    const auto *handlers = class_type->default_object_handlers;
    zend_object *object;
    if (delegate_to_base) {
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
}

/** Write a dynamic property while preserving the AOT source-level class scope. */
PHPX_API void typephp_write_property_scoped(const php::Variant &object,
                                            const php::Variant &member,
                                            const php::Variant &value,
                                            zend_class_entry *scope);

/**
 * Bind an object property to an existing PHP reference while preserving
 * declared-property type sources and runtime property-handler semantics.
 */
PHPX_API void typephp_rebind_property_reference(const php::Variant &object,
                                                const php::Variant &member,
                                                const php::Variant &reference,
                                                zend_class_entry *scope);

/** Read a dynamic property using the lexical scope supplied by an AOT trait wrapper. */
PHPX_API php::Variant typephp_read_property_scoped(const php::Variant &object,
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

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

/** Direct trait-use metadata emitted for one TypePHP class or trait. */
struct typephp_trait_metadata_entry {
    std::string_view name;
    const std::string_view *traits;
    size_t trait_count;
    bool is_trait;
};

/**
 * Register immutable TypePHP trait-use metadata for one extension module.
 *
 * TypePHP traits remain compile-time AST templates and deliberately have no
 * zend_class_entry. This side table lets SPL class_uses() recover their direct
 * trait list without exposing incomplete runtime trait classes.
 */
PHPX_API zend_result typephp_register_trait_metadata(int module_number,
                                                     const typephp_trait_metadata_entry *entries,
                                                     size_t entry_count) noexcept;

/** Remove every trait metadata entry owned by an extension module. */
PHPX_API void typephp_unregister_trait_metadata(int module_number) noexcept;

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
 * Release a generated temporary argument array both after a successful full
 * expression and while a C++ exception unwinds into the surrounding PHP
 * try/catch lowering.
 */
class ArrayCleanupGuard {
    Array *array_;

  public:
    explicit ArrayCleanupGuard(Array &array) noexcept : array_(&array) {}
    ArrayCleanupGuard(const ArrayCleanupGuard &) = delete;
    ArrayCleanupGuard &operator=(const ArrayCleanupGuard &) = delete;

    ~ArrayCleanupGuard() {
        if (array_ != nullptr) {
            array_->clean();
        }
    }

    void cleanup() {
        array_->clean();
        array_ = nullptr;
    }
};

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
 * One request-local Zend object-handler cache entry.
 *
 * Zend treats three adjacent pointers as one polymorphic property cache: the
 * runtime class entry, an encoded property offset/sentinel, and optional
 * property metadata. Keep the representation opaque so generated code can
 * only pass it back to the standard object handlers, never dereference a
 * cached offset itself.
 */
class PropertyCacheSlot final {
    void *slots_[3]{};

  public:
    PropertyCacheSlot() = default;
    PropertyCacheSlot(const PropertyCacheSlot &) = delete;
    PropertyCacheSlot &operator=(const PropertyCacheSlot &) = delete;

    void **data() noexcept {
        return slots_;
    }

    void reset() noexcept {
        slots_[0] = nullptr;
        slots_[1] = nullptr;
        slots_[2] = nullptr;
    }
};

static_assert(sizeof(PropertyCacheSlot) == sizeof(void *) * 3);

/**
 * Request-local cache owned by one TypePHP dynamic function-call site.
 *
 * The first stable string callable stays in the inline entry. A call site
 * that observes several names is promoted to a private HashTable, avoiding a
 * process-global cache and preventing one extension from retaining another
 * extension's request functions. Object-bearing callables are never stored.
 */
class PHPX_API FunctionCallCacheSlot final {
    zend_string *name_ = nullptr;
    zend_fcall_info_cache cache_{};
    zend_array *polymorphic_cache_ = nullptr;

    Variant callImpl(const Variant &func,
                     uint32_t param_count,
                     zval *params,
                     zend_array *named_args);

  public:
    FunctionCallCacheSlot() = default;
    ~FunctionCallCacheSlot();
    FunctionCallCacheSlot(const FunctionCallCacheSlot &) = delete;
    FunctionCallCacheSlot &operator=(const FunctionCallCacheSlot &) = delete;

    void reset() noexcept;
    Variant call(const Variant &func) {
        return callImpl(func, 0, nullptr, nullptr);
    }
    Variant call(const Variant &func, Args &args, zend_array *named_args = nullptr) {
        return callImpl(func, args.count(), args.ptr(), named_args);
    }
    Variant call(const Variant &func, FixedArgs args, zend_array *named_args = nullptr) {
        return callImpl(func, args.count(), args.ptr(), named_args);
    }
};

/** Request-local monomorphic cache for one dynamic method-call site. */
class PHPX_API MethodCallCacheSlot final {
    zend_class_entry *class_entry_ = nullptr;
    zend_string *name_ = nullptr;
    zend_function *function_ = nullptr;
    zend_class_entry *called_scope_ = nullptr;
    zend_class_entry *lexical_scope_guard_ = nullptr;
    zend_class_entry *called_scope_guard_ = nullptr;
    zend_class_entry *this_scope_guard_ = nullptr;
    bool scoped_ = false;
    bool polymorphic_ = false;

    Variant callImpl(const Variant &object,
                     const Variant &method,
                     uint32_t param_count,
                     zval *params,
                     zend_array *named_args);
    Variant callScopedImpl(const Variant &object,
                           const Variant &method,
                           const CallableScope &scope,
                           uint32_t param_count,
                           zval *params,
                           zend_array *named_args);

  public:
    MethodCallCacheSlot() = default;
    ~MethodCallCacheSlot();
    MethodCallCacheSlot(const MethodCallCacheSlot &) = delete;
    MethodCallCacheSlot &operator=(const MethodCallCacheSlot &) = delete;

    void reset() noexcept;
    Variant call(const Variant &object, const Variant &method) {
        return callImpl(object, method, 0, nullptr, nullptr);
    }
    Variant call(const Variant &object, const Variant &method, Args &args, zend_array *named_args = nullptr) {
        return callImpl(object, method, args.count(), args.ptr(), named_args);
    }
    Variant call(const Variant &object, const Variant &method, FixedArgs args, zend_array *named_args = nullptr) {
        return callImpl(object, method, args.count(), args.ptr(), named_args);
    }
    Variant callScoped(const Variant &object,
                       const Variant &method,
                       const CallableScope &scope) {
        return callScopedImpl(object, method, scope, 0, nullptr, nullptr);
    }
    Variant callScoped(const Variant &object,
                       const Variant &method,
                       const CallableScope &scope,
                       Args &args,
                       zend_array *named_args = nullptr) {
        return callScopedImpl(object, method, scope, args.count(), args.ptr(), named_args);
    }
    Variant callScoped(const Variant &object,
                       const Variant &method,
                       const CallableScope &scope,
                       FixedArgs args,
                       zend_array *named_args = nullptr) {
        return callScopedImpl(object, method, scope, args.count(), args.ptr(), named_args);
    }
};

/** Exception-safe owner of Zend's per-object magic-property recursion guard. */
class MagicPropertyGuard final {
    zend_object *object_ = nullptr;
    uint32_t *guard_ = nullptr;
    uint32_t flag_ = 0;
    bool active_ = false;

  public:
    MagicPropertyGuard(zend_object *object, zend_string *member, uint32_t flag) noexcept
        : object_(object), guard_(zend_get_property_guard(object, member)), flag_(flag) {}

    MagicPropertyGuard(const MagicPropertyGuard &) = delete;
    MagicPropertyGuard &operator=(const MagicPropertyGuard &) = delete;

    bool enter() noexcept {
        if (UNEXPECTED((*guard_ & flag_) != 0)) {
            return false;
        }
        GC_ADDREF(object_);
        *guard_ |= flag_;
        active_ = true;
        return true;
    }

    ~MagicPropertyGuard() noexcept {
        if (active_) {
            *guard_ &= ~flag_;
            OBJ_RELEASE(object_);
        }
    }
};

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

/**
 * Hot AOT equivalents of php::getCalledCe()/getCalledClass(). Keep these in
 * the TypePHP helper layer so generated code can inline the representation
 * check without exposing Zend macros at each call site.
 */
static inline zend_class_entry *typephp_get_called_ce(php::Object &this_) noexcept {
    if (EXPECTED(this_.isObject())) {
        return this_.ce();
    }
    return static_cast<zend_class_entry *>(Z_PTR_P(this_.ptr()));
}

static inline php::Str typephp_get_called_class(php::Object &this_) {
    zend_class_entry *called_scope = typephp_get_called_ce(this_);
    return called_scope == nullptr ? php::Str("") : php::Str(called_scope->name);
}

static inline php::Str typephp_get_called_class(zend_class_entry *called_scope) {
    return called_scope == nullptr ? php::Str("") : php::Str(called_scope->name);
}

/**
 * Read a statically resolved TypePHP static-property slot by its cached
 * offset. This is semantically identical to php::getStaticProperty(ce,
 * offset), but is inline because static property access is emitted in hot
 * generated paths. zval_wrap() deliberately preserves PHP references.
 */
static inline zval *typephp_get_static_property_slot(zend_class_entry *ce, uint32_t offset) {
    if (UNEXPECTED(CE_STATIC_MEMBERS(ce) == nullptr)) {
        zend_class_init_statics(ce);
    }
    zval *slot = CE_STATIC_MEMBERS(ce) + offset;
    ZVAL_DEINDIRECT(slot);
    return slot;
}

static inline zval *typephp_get_static_property_slot(zend_class_entry *ce, const php::String &property) {
    zval *slot = zend_read_static_property_ex(ce, property.str(), true);
    php::throwErrorIfOccurred();
    return slot;
}

static inline php::Variant typephp_get_static_property(zend_class_entry *ce, uint32_t offset) {
    zval *slot = typephp_get_static_property_slot(ce, offset);
    return php::Variant{slot, php::zval_wrap(slot)};
}

/**
 * Lazily resolve one static-property slot into a generated function local.
 * The resolver is not evaluated on a hit, so lookup disappears from hot loops
 * without moving static-member initialization ahead of the PHP access itself.
 * Only the final storage address is cached. A fresh lightweight Variant view is
 * returned so the property's current value/reference state is always observed.
 */
template <typename Resolver>
static zend_always_inline php::Variant typephp_get_static_property_cached(zval *&cached_slot,
                                                                          Resolver &&resolver) {
    if (UNEXPECTED(cached_slot == nullptr)) {
        cached_slot = resolver();
    }
    return php::Variant{cached_slot, php::zval_wrap(cached_slot)};
}

/**
 * Fast isset/coalesce lookup for a value statically known to be an array.
 * Unusual key types stay on PHPX's general operation-chain path so this
 * helper changes cost, not semantics.
 */
static inline bool typephp_array_isset(const php::Variant &array,
                                       const php::Variant &key,
                                       php::Variant *result = nullptr) {
    const zval *root = array.unwrap_ptr();
    if (UNEXPECTED(Z_TYPE_P(root) != IS_ARRAY)) {
        if (result == nullptr) {
            return php::exists(array, {{php::ArrayDimFetch, key}});
        }
        return php::exists(array, {{php::ArrayDimFetch, key}}, *result);
    }

    zval *value;
    if (EXPECTED(key.isString())) {
        value = zend_symtable_find(Z_ARRVAL_P(root), Z_STR_P(key.unwrap_ptr()));
    } else if (key.isInt() || key.isBool() || key.isFloat()) {
        value = zend_hash_index_find(Z_ARRVAL_P(root), static_cast<zend_ulong>(key.toInt()));
    } else {
        if (result == nullptr) {
            return php::exists(array, {{php::ArrayDimFetch, key}});
        }
        return php::exists(array, {{php::ArrayDimFetch, key}}, *result);
    }

    if (UNEXPECTED(value == nullptr)) {
        if (result != nullptr) {
            *result = nullptr;
        }
        return false;
    }
    if (result != nullptr) {
        *result = value;
    }
    ZVAL_DEREF(value);
    return Z_TYPE_P(value) != IS_NULL && Z_TYPE_P(value) != IS_UNDEF;
}

static inline php::Variant typephp_call_cached(const php::Variant &func,
                                               php::FunctionCallCacheSlot &cache,
                                               php::Args &args,
                                               zend_array *named_args = nullptr) {
    return cache.call(func, args, named_args);
}

static zend_always_inline php::Variant typephp_call_cached(const php::Variant &func,
                                                            php::FunctionCallCacheSlot &cache,
                                                            php::FixedArgs args,
                                                            zend_array *named_args = nullptr) {
    return cache.call(func, args, named_args);
}

static inline php::Variant typephp_call_cached(const php::Variant &func,
                                               php::FunctionCallCacheSlot &cache,
                                               const php::ArgList &args,
                                               zend_array *named_args = nullptr) {
    php::Args call_args(args);
    return cache.call(func, call_args, named_args);
}

static inline php::Variant typephp_call_cached(const php::Variant &func,
                                               php::FunctionCallCacheSlot &cache) {
    return cache.call(func);
}

static inline php::Variant typephp_call_method_cached(const php::Variant &object,
                                                      const php::Variant &method,
                                                      php::MethodCallCacheSlot &cache,
                                                      php::Args &args,
                                                      zend_array *named_args = nullptr) {
    return cache.call(object, method, args, named_args);
}

static zend_always_inline php::Variant typephp_call_method_cached(const php::Variant &object,
                                                                  const php::Variant &method,
                                                                  php::MethodCallCacheSlot &cache,
                                                                  php::FixedArgs args,
                                                                  zend_array *named_args = nullptr) {
    return cache.call(object, method, args, named_args);
}

static inline php::Variant typephp_call_method_cached(const php::Variant &object,
                                                      const php::Variant &method,
                                                      php::MethodCallCacheSlot &cache,
                                                      const php::ArgList &args,
                                                      zend_array *named_args = nullptr) {
    php::Args call_args(args);
    return cache.call(object, method, call_args, named_args);
}

static inline php::Variant typephp_call_method_cached(const php::Variant &object,
                                                      const php::Variant &method,
                                                      php::MethodCallCacheSlot &cache) {
    return cache.call(object, method);
}

static inline php::Variant typephp_call_method_scoped_cached(const php::Variant &object,
                                                             const php::Variant &method,
                                                             const php::CallableScope &scope,
                                                             php::MethodCallCacheSlot &cache,
                                                             php::Args &args,
                                                             zend_array *named_args = nullptr) {
    return cache.callScoped(object, method, scope, args, named_args);
}

static zend_always_inline php::Variant typephp_call_method_scoped_cached(
    const php::Variant &object,
    const php::Variant &method,
    const php::CallableScope &scope,
    php::MethodCallCacheSlot &cache,
    php::FixedArgs args,
    zend_array *named_args = nullptr) {
    return cache.callScoped(object, method, scope, args, named_args);
}

static inline php::Variant typephp_call_method_scoped_cached(const php::Variant &object,
                                                             const php::Variant &method,
                                                             const php::CallableScope &scope,
                                                             php::MethodCallCacheSlot &cache,
                                                             const php::ArgList &args,
                                                             zend_array *named_args = nullptr) {
    php::Args call_args(args);
    return cache.callScoped(object, method, scope, call_args, named_args);
}

static inline php::Variant typephp_call_method_scoped_cached(const php::Variant &object,
                                                             const php::Variant &method,
                                                             const php::CallableScope &scope,
                                                             php::MethodCallCacheSlot &cache) {
    return cache.callScoped(object, method, scope);
}

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

static inline php::Variant typephp_call_parent_constructor(php::Object &object,
                                                           zend_function *constructor,
                                                           const php::ArgList &args,
                                                           zend_array *named_args = nullptr) {
    php::Args call_args(args);
    return typephp_call_parent_constructor(object, constructor, call_args, named_args);
}

static inline php::Variant typephp_call_parent_constructor(php::Object &object, zend_function *constructor) {
    php::Args args;
    return typephp_call_parent_constructor(object, constructor, args);
}

static inline php::Variant typephp_call_parent_constructor(php::Object &object,
                                                           zend_function *constructor,
                                                           php::FixedArgs args,
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
 * Read one dynamic dimension for TypePHP's null-coalescing assignment.
 *
 * ArrayAccess requires offsetExists() followed by offsetGet(), because an
 * existing null value still selects the assignment branch. Arrays, strings,
 * and unsupported scalar values retain PHPX's normal exists() behavior.
 * Keeping this dispatch here prevents generated code from duplicating the
 * ArrayAccess protocol without exposing Zend dimension-handler details.
 */
static inline bool typephp_coalesce_dimension_read(const php::Variant &container,
                                                   const php::Variant &key,
                                                   php::Variant &result) {
    if (container.isObject()) {
        if (!container.offsetExists(key)) {
            return false;
        }
        result = container.offsetGet(key);
        return !result.isNull();
    }
    return php::exists(container, {{php::ArrayDimFetch, key}}, result);
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
 * Write a statically named property through its normal object handler while
 * supplying one request-local cache entry dedicated to this write site.
 */
PHPX_API void typephp_write_property_cached(const php::Variant &object,
                                            const php::String &member,
                                            const php::Variant &value,
                                            zend_class_entry *scope,
                                            php::PropertyCacheSlot &cache);

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
 * Read a statically named property through its normal object handler while
 * supplying one request-local cache entry dedicated to this read site.
 */
PHPX_API php::Variant typephp_read_property_cached(const php::Variant &object,
                                                   const php::String &member,
                                                   php::AttrMode mode,
                                                   php::PropertyCacheSlot &cache);

/**
 * Directly invoke a statically proven TypePHP __get() implementation only
 * while the runtime object remains the exact simple object anticipated by the
 * compiler. Every dynamic or custom-handler case falls back to Zend.
 */
template <typename Getter>
static inline php::Variant typephp_read_magic_property_direct(
    const php::Variant &object,
    const php::String &member,
    zend_class_entry *expected_class,
    php::PropertyCacheSlot &cache,
    Getter &&getter) {
    if (EXPECTED(object.isObject())) {
        zend_object *zobj = object.object();
        const zend_object_handlers *standard_handlers = zend_get_std_object_handlers();
        if (EXPECTED(zobj->ce == expected_class)
            && EXPECTED(zobj->handlers->read_property == standard_handlers->read_property)
            && EXPECTED(!zend_lazy_object_must_init(zobj))
            && EXPECTED(zend_hash_find(&zobj->ce->properties_info, member.str()) == nullptr)
            && EXPECTED(zobj->properties == nullptr || zend_hash_find(zobj->properties, member.str()) == nullptr)) {
            php::MagicPropertyGuard guard{zobj, member.str(), ZEND_GUARD_PROPERTY_GET};
            if (EXPECTED(guard.enter())) {
                return getter();
            }
        }
    }
    return typephp_read_property_cached(object, member, php::AttrMode::Get, cache);
}

/** Guarded direct counterpart for a statically proven TypePHP __set(). */
template <typename Setter>
static inline void typephp_write_magic_property_direct(
    const php::Variant &object,
    const php::String &member,
    const php::Variant &value,
    zend_class_entry *scope,
    zend_class_entry *expected_class,
    php::PropertyCacheSlot &cache,
    Setter &&setter) {
    if (EXPECTED(object.isObject())) {
        zend_object *zobj = object.object();
        const zend_object_handlers *standard_handlers = zend_get_std_object_handlers();
        if (EXPECTED(zobj->ce == expected_class)
            && EXPECTED(zobj->handlers->write_property == standard_handlers->write_property)
            && EXPECTED(!zend_lazy_object_must_init(zobj))
            && EXPECTED(zend_hash_find(&zobj->ce->properties_info, member.str()) == nullptr)
            && EXPECTED(zobj->properties == nullptr || zend_hash_find(zobj->properties, member.str()) == nullptr)) {
            php::MagicPropertyGuard guard{zobj, member.str(), ZEND_GUARD_PROPERTY_SET};
            if (EXPECTED(guard.enter())) {
                setter();
                return;
            }
        }
    }
    typephp_write_property_cached(object, member, value, scope, cache);
}

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

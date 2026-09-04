#include <typephp_helper.h>

namespace {

constexpr uint32_t NON_CACHEABLE_CALL_FLAGS = ZEND_ACC_CALL_VIA_TRAMPOLINE | ZEND_ACC_NEVER_CACHE;

void freeCallCacheEntry(zval *value) {
    efree(Z_PTR_P(value));
}

zend_fcall_info_cache *copyCallCacheEntry(const zend_fcall_info_cache &cache) {
    auto *copy = static_cast<zend_fcall_info_cache *>(emalloc(sizeof(cache)));
    *copy = cache;
    return copy;
}

php::Variant invokeCached(const php::Variant &callable,
                          zend_object *object,
                          zend_fcall_info_cache *cache,
                          uint32_t param_count,
                          zval *params,
                          zend_array *named_args) {
    php::Variant retval{};
    zend_fcall_info fci{};
    fci.size = sizeof(fci);
    fci.object = object;
    php::zval_copy_value(&fci.function_name, callable.const_ptr());
    fci.retval = retval.ptr();
    fci.param_count = param_count;
    fci.params = params;
    fci.named_params = named_args;
    zend_call_function(&fci, cache);
    php::throwErrorIfOccurred();
    return retval;
}

zend_fcall_info_cache resolveCallable(const php::Variant &callable, zend_object *object) {
    zend_fcall_info_cache cache{};
    char *error = nullptr;
    if (UNEXPECTED(!zend_is_callable_ex(NO_CONST_V(callable), object, 0, nullptr, &cache, &error))) {
        auto *callable_name = zend_get_callable_name_ex(NO_CONST_V(callable), object);
        zend_throw_error(nullptr,
                         "Invalid callback %s%s%s",
                         ZSTR_VAL(callable_name),
                         error == nullptr ? "" : ", ",
                         error == nullptr ? "" : error);
        if (error != nullptr) {
            efree(error);
        }
        zend_string_release_ex(callable_name, false);
        php::throwErrorIfOccurred();
    }
    return cache;
}

bool isRelativeStaticCallable(zend_string *name) {
    const char *value = ZSTR_VAL(name);
    const size_t length = ZSTR_LEN(name);
    return (length >= 6 && zend_binary_strcasecmp(value, 6, "self::", 6) == 0) ||
           (length >= 8 && zend_binary_strcasecmp(value, 8, "parent::", 8) == 0) ||
           (length >= 8 && zend_binary_strcasecmp(value, 8, "static::", 8) == 0);
}

}  // namespace

php::FunctionCallCacheSlot::~FunctionCallCacheSlot() {
    reset();
}

void php::FunctionCallCacheSlot::reset() noexcept {
    if (name_ != nullptr) {
        zend_string_release(name_);
        name_ = nullptr;
    }
    cache_ = {};
    if (polymorphic_cache_ != nullptr) {
        zend_hash_destroy(polymorphic_cache_);
        efree(polymorphic_cache_);
        polymorphic_cache_ = nullptr;
    }
}

php::MethodCallCacheSlot::~MethodCallCacheSlot() {
    reset();
}

void php::MethodCallCacheSlot::reset() noexcept {
    if (name_ != nullptr) {
        zend_string_release(name_);
        name_ = nullptr;
    }
    class_entry_ = nullptr;
    function_ = nullptr;
    called_scope_ = nullptr;
    polymorphic_ = false;
}

php::Variant php::FunctionCallCacheSlot::call(const Variant &func,
                                              uint32_t param_count,
                                              zval *params,
                                              zend_array *named_args) {
    if (UNEXPECTED(!func.isString())) {
        zend_fcall_info_cache resolved = resolveCallable(func, nullptr);
        return invokeCached(func, resolved.object, &resolved, param_count, params, named_args);
    }

    zend_string *name = Z_STR_P(func.const_ptr());
    if (polymorphic_cache_ != nullptr) {
        auto *cached = static_cast<zend_fcall_info_cache *>(zend_hash_find_ptr(polymorphic_cache_, name));
        if (EXPECTED(cached != nullptr)) {
            return invokeCached(func, nullptr, cached, param_count, params, named_args);
        }
    } else if (EXPECTED(name_ != nullptr && zend_string_equals(name_, name))) {
        return invokeCached(func, nullptr, &cache_, param_count, params, named_args);
    }

    // self/parent/static depend on the runtime called scope. Do not retain a
    // resolution which may be reused when an inherited AOT method is invoked
    // with a different late-bound class.
    if (UNEXPECTED(isRelativeStaticCallable(name))) {
        zend_fcall_info_cache resolved = resolveCallable(func, nullptr);
        return invokeCached(func, resolved.object, &resolved, param_count, params, named_args);
    }

    zend_fcall_info_cache resolved = resolveCallable(func, nullptr);
    if (EXPECTED(resolved.object == nullptr &&
                 !(resolved.function_handler->common.fn_flags & NON_CACHEABLE_CALL_FLAGS))) {
        if (name_ == nullptr && polymorphic_cache_ == nullptr) {
            name_ = zend_string_copy(name);
            cache_ = resolved;
        } else {
            if (polymorphic_cache_ == nullptr) {
                polymorphic_cache_ = static_cast<zend_array *>(emalloc(sizeof(zend_array)));
                zend_hash_init(polymorphic_cache_, 2, nullptr, freeCallCacheEntry, false);
                zend_hash_add_ptr(polymorphic_cache_, name_, copyCallCacheEntry(cache_));
                zend_string_release(name_);
                name_ = nullptr;
                cache_ = {};
            }
            zend_hash_update_ptr(polymorphic_cache_, name, copyCallCacheEntry(resolved));
        }
    }

    return invokeCached(func, resolved.object, &resolved, param_count, params, named_args);
}

php::Variant php::MethodCallCacheSlot::call(
    const Variant &object, const Variant &method, uint32_t param_count, zval *params, zend_array *named_args) {
    if (UNEXPECTED(!object.isObject())) {
        php::throwError("call method `%s` on %s", method.toCString(), object.typeStr());
        return {};
    }

    zend_object *zend_object = Z_OBJ_P(object.const_ptr());
    if (UNEXPECTED(!method.isString()) || UNEXPECTED(polymorphic_)) {
        zend_fcall_info_cache resolved = resolveCallable(method, zend_object);
        return invokeCached(method, zend_object, &resolved, param_count, params, named_args);
    }

    zend_string *name = Z_STR_P(method.const_ptr());
    if (EXPECTED(class_entry_ == zend_object->ce && name_ != nullptr && zend_string_equals(name_, name))) {
        zend_fcall_info_cache resolved{};
        resolved.function_handler = function_;
        resolved.called_scope = called_scope_;
        resolved.object = zend_object;
        return invokeCached(method, zend_object, &resolved, param_count, params, named_args);
    }

    if (UNEXPECTED(name_ != nullptr)) {
        reset();
        polymorphic_ = true;
        zend_fcall_info_cache resolved = resolveCallable(method, zend_object);
        return invokeCached(method, zend_object, &resolved, param_count, params, named_args);
    }

    zend_fcall_info_cache resolved = resolveCallable(method, zend_object);
    if (EXPECTED(!(resolved.function_handler->common.fn_flags & NON_CACHEABLE_CALL_FLAGS))) {
        class_entry_ = zend_object->ce;
        name_ = zend_string_copy(name);
        function_ = resolved.function_handler;
        called_scope_ = resolved.called_scope;
    }
    return invokeCached(method, zend_object, &resolved, param_count, params, named_args);
}

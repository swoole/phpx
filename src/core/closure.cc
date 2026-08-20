/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

#include "zend_closures.h"

#include <new>

namespace php {

static void freeClosureFunction(zend_function *function) {
    if (function->common.arg_info != nullptr) {
        auto *arg_info = const_cast<zend_internal_arg_info *>(
            reinterpret_cast<const zend_internal_arg_info *>(function->common.arg_info));
        for (uint32_t i = 0; i < function->common.num_args; i++) {
            efree(const_cast<char *>(arg_info[i].name));
        }
        efree(arg_info);
    }
    efree(function);
}

struct ClosureState {
    Object this_;
    ClosureFn fn_;
    Args vars_;
    zend_function *zf_;

    ClosureState(const ClosureFn &fn, const Object &_this, const ArgList &uses, zend_function *zf)
        : this_(_this), fn_(fn), vars_(uses), zf_(zf) {}

    ~ClosureState() {
        freeClosureFunction(zf_);
    }
};

struct ClosureCarrier {
    alignas(ClosureState) unsigned char state_storage[sizeof(ClosureState)];
    zend_object std;

    ClosureState *state() {
        return std::launder(reinterpret_cast<ClosureState *>(state_storage));
    }
};

static_assert(std::is_standard_layout_v<ClosureCarrier>);

static zend_object_handlers closure_carrier_handlers;
static bool closure_carrier_handlers_initialized = false;

static inline ClosureCarrier *closure_carrier_from_obj(zend_object *object) {
    return reinterpret_cast<ClosureCarrier *>(
        reinterpret_cast<char *>(object) - XtOffsetOf(ClosureCarrier, std));
}

static HashTable *closure_carrier_get_gc(zend_object *object, zval **table, int *n) {
    auto *state = closure_carrier_from_obj(object)->state();
    auto *gc_buffer = zend_get_gc_buffer_create();

    // ClosureState lives outside Zend's property table. Expose the bound
    // object and captured variables so cyclic closures remain collectable.
    zend_get_gc_buffer_add_zval(gc_buffer, state->this_.ptr());
    zval *capture = state->vars_.ptr();
    for (uint32_t i = 0; i < state->vars_.count(); i++) {
        zend_get_gc_buffer_add_zval(gc_buffer, capture + i);
    }
    zend_get_gc_buffer_use(gc_buffer, table, n);

    // ClosureCarrier is private implementation storage and never has PHP
    // properties. All of its GC-visible edges are returned through table.
    return nullptr;
}

static void closure_carrier_free(zend_object *object) {
    auto *carrier = closure_carrier_from_obj(object);
    zend_object_std_dtor(&carrier->std);
    carrier->state()->~ClosureState();
}

static zend_object *newClosureCarrier(const ClosureFn &fn,
                                      const Object &_this,
                                      const ArgList &uses,
                                      zend_function *zf) {
    if (UNEXPECTED(!closure_carrier_handlers_initialized)) {
        memcpy(&closure_carrier_handlers, &std_object_handlers, sizeof(zend_object_handlers));
        closure_carrier_handlers.offset = XtOffsetOf(ClosureCarrier, std);
        closure_carrier_handlers.free_obj = closure_carrier_free;
        closure_carrier_handlers.get_gc = closure_carrier_get_gc;
        closure_carrier_handlers.clone_obj = nullptr;
        closure_carrier_handlers_initialized = true;
    }

    auto *carrier = static_cast<ClosureCarrier *>(
        zend_object_alloc(sizeof(ClosureCarrier), zend_standard_class_def));
    try {
        new (carrier->state_storage) ClosureState(fn, _this, uses, zf);
    } catch (...) {
        efree(carrier);
        freeClosureFunction(zf);
        throw;
    }
    zend_object_std_init(&carrier->std, zend_standard_class_def);
    object_properties_init(&carrier->std, zend_standard_class_def);
    carrier->std.handlers = &closure_carrier_handlers;
    return &carrier->std;
}

Object newClosure(const ClosureFn &fn,
                  const ArgList &uses,
                  const Object &_this,
                  zend_class_entry *scope,
                  std::initializer_list<const char *> parameter_names) {
    auto func = (zend_function *) emalloc(sizeof(zend_internal_function));
    memset(func, 0, sizeof(zend_internal_function));

    String fnName("{closure}");
    func->type = ZEND_INTERNAL_FUNCTION;
    func->internal_function.handler = [](INTERNAL_FUNCTION_PARAMETERS) {
        try {
            if (UNEXPECTED(Z_TYPE(execute_data->This) != IS_OBJECT
                           || Z_OBJ(execute_data->This)->handlers != &closure_carrier_handlers)) {
                throwError("Closure::call(), Closure::bind(), and Closure::bindTo() are not supported");
                return;
            }
            auto *state = closure_carrier_from_obj(Z_OBJ_P(ZEND_THIS))->state();
            auto rv = state->fn_(INTERNAL_FUNCTION_PARAM_PASSTHRU, state->this_, state->vars_);
            zval *retval = rv.direct_ptr();
            if (Z_ISREF_P(retval) && !(EX(func)->common.fn_flags & ZEND_ACC_RETURN_REFERENCE)) {
                ZVAL_COPY_DEREF(return_value, retval);
            } else {
                rv.moveTo(return_value);
            }
        } catch (zend_object *) {
            // The PHP exception is already stored in EG(exception). Returning
            // normally lets ZendVM release its callback frame before the outer
            // PHPX call boundary converts it back to a C++ exception.
        }
    };
    func->internal_function.function_name = fnName.str();
    if (parameter_names.size() != 0) {
        const auto count = static_cast<uint32_t>(parameter_names.size());
        auto *arg_info = static_cast<zend_internal_arg_info *>(ecalloc(count, sizeof(zend_internal_arg_info)));
        uint32_t index = 0;
        for (const auto &parameter_name : parameter_names) {
            arg_info[index].name = estrdup(parameter_name);
            arg_info[index].type = ZEND_TYPE_INIT_NONE(0);
            index++;
        }
        func->common.arg_info = reinterpret_cast<zend_arg_info *>(arg_info);
        func->common.num_args = count;
    }
    // The carrier is only an implementation detail used to keep the C++
    // callback state alive. Visibility and self:: resolution must use the
    // lexical PHP class in which the closure was declared.
    auto *lexical_scope = scope ? scope : zend_standard_class_def;
    auto *called_scope = _this.isNull() ? scope : _this.ce();
    func->common.scope = lexical_scope;

    zval carrier;
    ZVAL_OBJ(&carrier, newClosureCarrier(fn, _this, uses, func));

    zval closure;
    zend_create_fake_closure(&closure, func, lexical_scope, called_scope, &carrier);
    zval_ptr_dtor(&carrier);

    return {&closure, Ctor::Move};
}

static bool isRelativeCallableClass(const zval *callable) {
    const zval *class_name = nullptr;
    if (Z_TYPE_P(callable) == IS_STRING) {
        const char *separator = static_cast<const char *>(
            php_memnstr(Z_STRVAL_P(callable), "::", 2, Z_STRVAL_P(callable) + Z_STRLEN_P(callable)));
        if (separator == nullptr) {
            return false;
        }
        const size_t length = static_cast<size_t>(separator - Z_STRVAL_P(callable));
        return (length == 4 && zend_binary_strcasecmp(Z_STRVAL_P(callable), length, "self", 4) == 0)
            || (length == 6 && zend_binary_strcasecmp(Z_STRVAL_P(callable), length, "parent", 6) == 0)
            || (length == 6 && zend_binary_strcasecmp(Z_STRVAL_P(callable), length, "static", 6) == 0);
    }
    if (Z_TYPE_P(callable) == IS_ARRAY) {
        class_name = zend_hash_index_find(Z_ARRVAL_P(callable), 0);
        if (class_name == nullptr) {
            return false;
        }
        ZVAL_DEREF(class_name);
        if (Z_TYPE_P(class_name) != IS_STRING) {
            return false;
        }
        return zend_string_equals_literal_ci(Z_STR_P(class_name), "self")
            || zend_string_equals_literal_ci(Z_STR_P(class_name), "parent")
            || zend_string_equals_literal_ci(Z_STR_P(class_name), "static");
    }
    return false;
}

static bool canReuseResolvedCallable(const Variant &callable, const zend_fcall_info_cache &cache) {
    if (cache.function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) {
        return false;
    }
    if (cache.function_handler->common.scope != nullptr
        && !(cache.function_handler->common.fn_flags & ZEND_ACC_PUBLIC)) {
        return false;
    }
    return !isRelativeCallableClass(callable.unwrap_ptr());
}

Variant normalizeCallableClass(const Variant &callable, const CallableScope &scope) {
    if (!callable.isArray()) {
        return {callable};
    }

    Array callback(callable);
    if (callback.count() != 2) {
        return {callable};
    }

    Variant class_name = callback.get(0);
    if (!class_name.isString()) {
        return {callable};
    }

    zend_class_entry *target = nullptr;
    zend_string *relative_name = Z_STR_P(class_name.const_ptr());
    if (zend_string_equals_literal_ci(relative_name, "self")) {
        target = scope.lexicalScope();
    } else if (zend_string_equals_literal_ci(relative_name, "parent")) {
        auto *lexical_scope = scope.lexicalScope();
        target = lexical_scope ? lexical_scope->parent : nullptr;
    } else if (zend_string_equals_literal_ci(relative_name, "static")) {
        target = scope.calledScope();
    } else {
        return {callable};
    }

    // Leave an invalid relative target unchanged so Zend produces its native
    // callback diagnostic (for example parent without a parent class).
    if (target == nullptr) {
        return {callable};
    }

    Array normalized(callable);
    normalized.set(static_cast<zend_ulong>(0), Str(target->name));
    return normalized;
}

void normalizeCallableClass(Args &args, size_t index, const CallableScope &scope) {
    if (args.exists(index)) {
        args.set(index, normalizeCallableClass(args.get(index), scope));
    }
}

static Variant makeScopedCallableImpl(const Variant &callable,
                                      const CallableScope &scope,
                                      bool reuse_public_callable) {
    if (UNEXPECTED(!scope.isValid())) {
        throwError("Explicit callable scope must not be null");
        return {};
    }

    if (callable.isObject() && instanceof_function(callable.ce(), zend_ce_closure)) {
        return {callable};
    }

    zend_fcall_info_cache cache{};
    char *error = nullptr;
    zval callable_value;
    ZVAL_COPY_VALUE(&callable_value, callable.unwrap_ptr());
    if (!scope.resolve(&callable_value, nullptr, &cache, &error)) {
        auto callable_name = zend_get_callable_name(&callable_value);
        std::string message = "Invalid callback ";
        message.append(ZSTR_VAL(callable_name), ZSTR_LEN(callable_name));
        if (error != nullptr) {
            message.append(", ");
            message.append(error);
        }
        zend_string_release(callable_name);
        if (error != nullptr) {
            efree(error);
        }
        throwError("%s", message.c_str());
        return {};
    }

    // Public callbacks with an absolute target resolve identically without the
    // caller's lexical scope. Preserve their original representation and avoid
    // allocating a fake Closure on every internal-function invocation.
    if (reuse_public_callable && canReuseResolvedCallable(callable, cache)) {
        zend_release_fcall_info_cache(&cache);
        return {callable};
    }

    if (!(cache.function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE)) {
        zval closure;
        if (cache.object != nullptr) {
            zval instance;
            ZVAL_OBJ(&instance, cache.object);
            zend_create_fake_closure(
                &closure,
                cache.function_handler,
                cache.function_handler->common.scope,
                cache.called_scope,
                &instance);
        } else {
            zend_create_fake_closure(
                &closure,
                cache.function_handler,
                cache.function_handler->common.scope,
                cache.called_scope,
                nullptr);
        }
        return {&closure, Ctor::Move};
    }

    // Magic __call()/__callStatic() resolution returns a temporary Zend
    // trampoline. Keep the uncommon path small and safe by forwarding it
    // through scoped resolution instead of duplicating zend_closures.c's
    // private trampoline-to-closure implementation.
    zend_release_fcall_info_cache(&cache);
    ClosureFn forward = [](INTERNAL_FUNCTION_PARAMETERS, Object &, Args &captures) -> Variant {
        Args args(ZEND_NUM_ARGS());
        for (uint32_t i = 0; i < ZEND_NUM_ARGS(); i++) {
            args.append(ZEND_CALL_ARG(execute_data, i + 1));
        }
        zend_array *named_args = nullptr;
        if (ZEND_CALL_INFO(execute_data) & ZEND_CALL_HAS_EXTRA_NAMED_PARAMS) {
            named_args = execute_data->extra_named_params;
        }
        CallableScope scope{
            execute_data->func,
            zend_get_called_scope(execute_data),
            zend_get_this_object(execute_data),
        };
        return callScoped(captures.get(0), scope, args, named_args);
    };

    Object bound_this;
    if (scope.thisObject() != nullptr) {
        zval object;
        ZVAL_OBJ(&object, scope.thisObject());
        bound_this = Object(&object);
    }
    return newClosure(forward, {callable}, bound_this, scope.lexicalScope());
}

Variant prepareScopedCallback(const Variant &callable, const CallableScope &scope) {
    return makeScopedCallableImpl(callable, scope, true);
}

Object makeScopedCallable(const Variant &callable, const CallableScope &scope) {
    return Object(makeScopedCallableImpl(callable, scope, false));
}

}  // namespace php

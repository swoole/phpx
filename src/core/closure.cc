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
        auto *state = closure_carrier_from_obj(Z_OBJ_P(ZEND_THIS))->state();
        auto rv = state->fn_(INTERNAL_FUNCTION_PARAM_PASSTHRU, state->this_, state->vars_);
        zval *retval = rv.direct_ptr();
        if (Z_ISREF_P(retval) && !(EX(func)->common.fn_flags & ZEND_ACC_RETURN_REFERENCE)) {
            ZVAL_COPY_DEREF(return_value, retval);
        } else {
            rv.moveTo(return_value);
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
}  // namespace php

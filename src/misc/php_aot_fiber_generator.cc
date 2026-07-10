#include "php_aot_fiber_generator.h"

#include <phpx_helper.h>

extern "C" {
#include <Zend/zend_fibers.h>
#include <Zend/zend_generators.h>
}

zend_class_entry *typephp_fiber_generator_ce = nullptr;

static const php::Str &typephp_fiber_str_callback() {
    static const php::Str name{ZEND_STRL("__typephp_callback"), true};
    return name;
}

static const php::Str &typephp_fiber_str_fiber() {
    static const php::Str name{ZEND_STRL("__typephp_fiber"), true};
    return name;
}

static const php::Str &typephp_fiber_str_current() {
    static const php::Str name{ZEND_STRL("__typephp_current"), true};
    return name;
}

static const php::Str &typephp_fiber_str_key() {
    static const php::Str name{ZEND_STRL("__typephp_key"), true};
    return name;
}

static const php::Str &typephp_fiber_str_valid() {
    static const php::Str name{ZEND_STRL("__typephp_valid"), true};
    return name;
}

static const php::Str &typephp_fiber_str_started() {
    static const php::Str name{ZEND_STRL("__typephp_started"), true};
    return name;
}

static const php::Str &typephp_fiber_str_fiber_class() {
    static const php::Str name{ZEND_STRL("Fiber"), true};
    return name;
}

static const php::Str &typephp_fiber_str_start() {
    static const php::Str name{ZEND_STRL("start"), true};
    return name;
}

static const php::Str &typephp_fiber_str_resume() {
    static const php::Str name{ZEND_STRL("resume"), true};
    return name;
}

static const php::Str &typephp_fiber_str_throw() {
    static const php::Str name{ZEND_STRL("throw"), true};
    return name;
}

static const php::Str &typephp_fiber_str_is_terminated() {
    static const php::Str name{ZEND_STRL("isTerminated"), true};
    return name;
}

static const php::Str &typephp_fiber_str_get_iterator() {
    static const php::Str name{ZEND_STRL("getIterator"), true};
    return name;
}

static const php::Str &typephp_fiber_str_rewind() {
    static const php::Str name{ZEND_STRL("rewind"), true};
    return name;
}

static const php::Str &typephp_fiber_str_valid_method() {
    static const php::Str name{ZEND_STRL("valid"), true};
    return name;
}

static const php::Str &typephp_fiber_str_current_method() {
    static const php::Str name{ZEND_STRL("current"), true};
    return name;
}

static const php::Str &typephp_fiber_str_key_method() {
    static const php::Str name{ZEND_STRL("key"), true};
    return name;
}

static const php::Str &typephp_fiber_str_next() {
    static const php::Str name{ZEND_STRL("next"), true};
    return name;
}

static const php::Str &typephp_fiber_str_send() {
    static const php::Str name{ZEND_STRL("send"), true};
    return name;
}

static const php::Str &typephp_fiber_str_get_return() {
    static const php::Str name{ZEND_STRL("getReturn"), true};
    return name;
}

static const php::Str &typephp_fiber_str_payload_value() {
    static const php::Str name{ZEND_STRL("value"), true};
    return name;
}

static const php::Str &typephp_fiber_str_payload_key() {
    static const php::Str name{ZEND_STRL("key"), true};
    return name;
}

static const php::Str &typephp_fiber_str_payload_has_key() {
    static const php::Str name{ZEND_STRL("has_key"), true};
    return name;
}

php::Var typephp_fiber_suspend(const php::Var &value, bool *closed) {
    zend_fiber *fiber = EG(active_fiber);
    if (closed != nullptr) {
        *closed = false;
    }
    if (UNEXPECTED(fiber == nullptr)) {
        php::throwException(zend_ce_error, "Cannot suspend outside of a fiber");
        if (closed != nullptr) {
            *closed = true;
        }
        return php::null;
    }
    if (UNEXPECTED(fiber->flags & ZEND_FIBER_FLAG_DESTROYED)) {
        php::throwException(zend_ce_error, "Cannot suspend in a force-closed fiber");
        if (closed != nullptr) {
            *closed = true;
        }
        return php::null;
    }
    if (UNEXPECTED(zend_fiber_switch_blocked())) {
        php::throwException(zend_ce_error, "Cannot switch fibers in current execution context");
        if (closed != nullptr) {
            *closed = true;
        }
        return php::null;
    }

    zval retval;
    ZVAL_NULL(&retval);
    fiber->stack_bottom->prev_execute_data = nullptr;
    zend_fiber_suspend(fiber, NO_CONST_V(value), &retval);
    zval_ptr_dtor(&retval);
    if (UNEXPECTED(EG(active_fiber) == nullptr || (fiber->flags & ZEND_FIBER_FLAG_DESTROYED))) {
        if (EG(exception) != nullptr) {
            zend_clear_exception();
        }
        if (closed != nullptr) {
            *closed = true;
        }
        return php::null;
    }
    return php::Var(&retval, php::Ctor::Move);
}

static php::Array typephp_fiber_yield_payload(const php::Var &value, const php::Var &key, bool has_key) {
    if (has_key) {
        return php::Array(php::StdStrKeyMap{{"key", key}, {"value", value}, {"has_key", true}});
    }
    return php::Array(php::StdStrKeyMap{{"value", value}, {"has_key", false}});
}

bool typephp_fiber_yield(const php::Var &value) {
    bool closed = false;
    typephp_fiber_suspend(value, &closed);
    return closed;
}

php::Var typephp_fiber_yield_from(const php::Var &iterable, bool *closed) {
    bool local_closed = false;
    if (closed == nullptr) {
        closed = &local_closed;
    }
    *closed = false;

    if (iterable.isArray()) {
        php::Array array = iterable;
        for (auto it = array.begin(); it != array.end(); ++it) {
            typephp_fiber_suspend(typephp_fiber_yield_payload(it.value(), it.key(), true), closed);
            if (*closed) {
                return php::null;
            }
        }
        return php::null;
    }

    if (!iterable.isObject()) {
        php::throwException(zend_ce_type_error, "Can use \"yield from\" only with arrays and Traversables");
        return php::null;
    }

    php::Object iterator = iterable;
    php::Object aggregate;
    if (iterator.instanceOf(zend_ce_aggregate)) {
        do {
            aggregate = iterator;
            php::Var next_iterable = aggregate.call(typephp_fiber_str_get_iterator());
            if (UNEXPECTED(!next_iterable.isObject())) {
                php::throwException(
                    zend_ce_exception,
                    "Objects returned by IteratorAggregate::getIterator() must be traversable or implement interface Iterator");
                return php::null;
            }
            iterator = next_iterable;
            if (UNEXPECTED(!iterator.instanceOf(zend_ce_iterator) && !iterator.instanceOf(zend_ce_aggregate))) {
                php::throwException(
                    zend_ce_exception,
                    "Objects returned by IteratorAggregate::getIterator() must be traversable or implement interface Iterator");
                return php::null;
            }
        } while (iterator.instanceOf(zend_ce_aggregate));
    }

    if (!iterator.instanceOf(zend_ce_iterator)) {
        php::throwException(zend_ce_type_error, "Can use \"yield from\" only with arrays and Traversables");
        return php::null;
    }

    bool is_generator = iterator.instanceOf(typephp_fiber_generator_ce) || iterator.instanceOf(zend_ce_generator);
    iterator.call(typephp_fiber_str_rewind());
    while (iterator.call(typephp_fiber_str_valid_method()).toBool()) {
        php::Var key = iterator.call(typephp_fiber_str_key_method());
        php::Var value = iterator.call(typephp_fiber_str_current_method());
        php::Var resume_value = typephp_fiber_suspend(typephp_fiber_yield_payload(value, key, true), closed);
        if (*closed) {
            return php::null;
        }
        if (is_generator && !resume_value.isNull()) {
            iterator.call(typephp_fiber_str_send(), php::ArgList{resume_value});
        } else {
            iterator.call(typephp_fiber_str_next());
        }
    }

    if (is_generator) {
        return iterator.call(typephp_fiber_str_get_return());
    }
    return php::null;
}

static void typephp_fiber_generator_advance(
    php::Object &this_,
    const php::Var *send_value = nullptr,
    const php::Var *throw_value = nullptr) {
    php::Var result;
    if (!this_.get(typephp_fiber_str_started()).toBool()) {
        php::Object fiber = php::newObject(typephp_fiber_str_fiber_class(), {this_.get(typephp_fiber_str_callback())});
        this_.set(typephp_fiber_str_fiber(), fiber);
        this_.set(typephp_fiber_str_started(), true);
        result = fiber.call(typephp_fiber_str_start());
    } else if (throw_value != nullptr) {
        php::Object fiber = this_.get(typephp_fiber_str_fiber());
        result = fiber.call(typephp_fiber_str_throw(), php::ArgList{*throw_value});
    } else if (send_value != nullptr) {
        php::Object fiber = this_.get(typephp_fiber_str_fiber());
        result = fiber.call(typephp_fiber_str_resume(), php::ArgList{*send_value});
    } else {
        php::Object fiber = this_.get(typephp_fiber_str_fiber());
        result = fiber.call(typephp_fiber_str_resume());
    }

    php::Object fiber = this_.get(typephp_fiber_str_fiber());
    if (fiber.call(typephp_fiber_str_is_terminated()).toBool()) {
        this_.set(typephp_fiber_str_valid(), false);
        this_.set(typephp_fiber_str_current(), nullptr);
        this_.set(typephp_fiber_str_key(), nullptr);
        return;
    }

    php::Array yielded = result;
    this_.set(typephp_fiber_str_valid(), true);
    this_.set(typephp_fiber_str_current(), yielded.get(typephp_fiber_str_payload_value()));
    if (yielded.get(typephp_fiber_str_payload_has_key()).toBool()) {
        this_.set(typephp_fiber_str_key(), yielded.get(typephp_fiber_str_payload_key()));
    } else {
        php::Var key = this_.get(typephp_fiber_str_key());
        this_.set(typephp_fiber_str_key(), key.isNull() ? php::Var(0) : key.toInt() + 1);
    }
}

ZEND_METHOD(TypePHP_FiberGenerator, __construct) {
    php::Object this_(&execute_data->This);
    this_.set(typephp_fiber_str_callback(), php::getCallArg(0));
    this_.set(typephp_fiber_str_fiber(), nullptr);
    this_.set(typephp_fiber_str_current(), nullptr);
    this_.set(typephp_fiber_str_key(), nullptr);
    this_.set(typephp_fiber_str_valid(), false);
    this_.set(typephp_fiber_str_started(), false);
}

ZEND_METHOD(TypePHP_FiberGenerator, rewind) {
    php::Object this_(&execute_data->This);
    if (this_.get(typephp_fiber_str_started()).toBool()) {
        return;
    }
    typephp_fiber_generator_advance(this_);
}

ZEND_METHOD(TypePHP_FiberGenerator, next) {
    php::Object this_(&execute_data->This);
    typephp_fiber_generator_advance(this_);
}

ZEND_METHOD(TypePHP_FiberGenerator, send) {
    php::Object this_(&execute_data->This);
    php::Var value = php::getCallArg(0, php::null);
    if (!this_.get(typephp_fiber_str_started()).toBool()) {
        typephp_fiber_generator_advance(this_);
    }
    typephp_fiber_generator_advance(this_, &value);
    auto retval = this_.get(typephp_fiber_str_current());
    ZVAL_COPY_DEREF(return_value, retval.ptr());
}

ZEND_METHOD(TypePHP_FiberGenerator, throw) {
    php::Object this_(&execute_data->This);
    php::Var exception = php::getCallArg(0);
    typephp_fiber_generator_advance(this_, nullptr, &exception);
    auto retval = this_.get(typephp_fiber_str_current());
    ZVAL_COPY_DEREF(return_value, retval.ptr());
}

ZEND_METHOD(TypePHP_FiberGenerator, getReturn) {
    php::Object this_(&execute_data->This);
    if (!this_.get(typephp_fiber_str_started()).toBool() || this_.get(typephp_fiber_str_valid()).toBool()) {
        php::throwException(zend_ce_exception, "Cannot get return value of a generator that hasn't returned");
        return;
    }
    php::Object fiber = this_.get(typephp_fiber_str_fiber());
    auto retval = fiber.call(typephp_fiber_str_get_return());
    ZVAL_COPY_DEREF(return_value, retval.ptr());
}

ZEND_METHOD(TypePHP_FiberGenerator, valid) {
    php::Object this_(&execute_data->This);
    if (!this_.get(typephp_fiber_str_started()).toBool()) {
        typephp_fiber_generator_advance(this_);
    }
    auto retval = this_.get(typephp_fiber_str_valid());
    ZVAL_COPY_DEREF(return_value, retval.ptr());
}

ZEND_METHOD(TypePHP_FiberGenerator, current) {
    php::Object this_(&execute_data->This);
    if (!this_.get(typephp_fiber_str_started()).toBool()) {
        typephp_fiber_generator_advance(this_);
    }
    auto retval = this_.get(typephp_fiber_str_current());
    ZVAL_COPY_DEREF(return_value, retval.ptr());
}

ZEND_METHOD(TypePHP_FiberGenerator, key) {
    php::Object this_(&execute_data->This);
    if (!this_.get(typephp_fiber_str_started()).toBool()) {
        typephp_fiber_generator_advance(this_);
    }
    auto retval = this_.get(typephp_fiber_str_key());
    ZVAL_COPY_DEREF(return_value, retval.ptr());
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_typephp_fiber_generator_void, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_typephp_fiber_generator_construct, 0, 0, 1)
    ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_typephp_fiber_generator_send, 0, 0, 1)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_typephp_fiber_generator_throw, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

static const zend_function_entry typephp_fiber_generator_methods[] = {
    ZEND_ME(TypePHP_FiberGenerator, __construct, arginfo_typephp_fiber_generator_construct, ZEND_ACC_PUBLIC)
    ZEND_ME(TypePHP_FiberGenerator, rewind, arginfo_typephp_fiber_generator_void, ZEND_ACC_PUBLIC)
    ZEND_ME(TypePHP_FiberGenerator, next, arginfo_typephp_fiber_generator_void, ZEND_ACC_PUBLIC)
    ZEND_ME(TypePHP_FiberGenerator, valid, arginfo_typephp_fiber_generator_void, ZEND_ACC_PUBLIC)
    ZEND_ME(TypePHP_FiberGenerator, current, arginfo_typephp_fiber_generator_void, ZEND_ACC_PUBLIC)
    ZEND_ME(TypePHP_FiberGenerator, key, arginfo_typephp_fiber_generator_void, ZEND_ACC_PUBLIC)
    ZEND_ME(TypePHP_FiberGenerator, send, arginfo_typephp_fiber_generator_send, ZEND_ACC_PUBLIC)
    ZEND_ME(TypePHP_FiberGenerator, throw, arginfo_typephp_fiber_generator_throw, ZEND_ACC_PUBLIC)
    ZEND_ME(TypePHP_FiberGenerator, getReturn, arginfo_typephp_fiber_generator_void, ZEND_ACC_PUBLIC)
    ZEND_FE_END
};

void typephp_register_fiber_generator_class() {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "TypePHP\\FiberGenerator", typephp_fiber_generator_methods);
    typephp_fiber_generator_ce = zend_register_internal_class(&ce);
    zend_class_implements(typephp_fiber_generator_ce, 1, zend_ce_iterator);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("__typephp_callback"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("__typephp_fiber"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("__typephp_current"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("__typephp_key"), ZEND_ACC_PRIVATE);
    zend_declare_property_bool(typephp_fiber_generator_ce, ZEND_STRL("__typephp_valid"), false, ZEND_ACC_PRIVATE);
    zend_declare_property_bool(typephp_fiber_generator_ce, ZEND_STRL("__typephp_started"), false, ZEND_ACC_PRIVATE);
}

#include "typephp_fiber_generator.h"

#include <phpx_helper.h>

#include <limits>
#include <unordered_set>

extern "C" {
#include <Zend/zend_fibers.h>
#include <Zend/zend_generators.h>
}

zend_class_entry *typephp_fiber_generator_ce = nullptr;

static const php::Str &typephp_fiber_str_callback() {
    static const php::Str name{ZEND_STRL("callback"), true};
    return name;
}

static const php::Str &typephp_fiber_str_fiber() {
    static const php::Str name{ZEND_STRL("fiber"), true};
    return name;
}

static const php::Str &typephp_fiber_str_current() {
    static const php::Str name{ZEND_STRL("current"), true};
    return name;
}

static const php::Str &typephp_fiber_str_key() {
    static const php::Str name{ZEND_STRL("key"), true};
    return name;
}

static const php::Str &typephp_fiber_str_valid() {
    static const php::Str name{ZEND_STRL("valid"), true};
    return name;
}

static const php::Str &typephp_fiber_str_state() {
    static const php::Str name{ZEND_STRL("state"), true};
    return name;
}

static const php::Str &typephp_fiber_str_yield_count() {
    static const php::Str name{ZEND_STRL("yield_count"), true};
    return name;
}

static const php::Str &typephp_fiber_str_next_index() {
    static const php::Str name{ZEND_STRL("next_index"), true};
    return name;
}

static const php::Str &typephp_fiber_str_return_value() {
    static const php::Str name{ZEND_STRL("return_value"), true};
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
    if (UNEXPECTED(EG(active_fiber) == nullptr || (fiber->flags & ZEND_FIBER_FLAG_DESTROYED))) {
        zval_ptr_dtor(&retval);
        if (EG(exception) != nullptr) {
            php::throwErrorIfOccurred();
        }
        if (closed != nullptr) {
            *closed = true;
        }
        return php::null;
    }
    php::throwErrorIfOccurred();
    return php::Var(&retval, php::Ctor::Move);
}

static php::Array typephp_fiber_yield_payload(const php::Var &value, const php::Var &key, bool has_key) {
    if (has_key) {
        return php::Array(php::StdStrKeyMap{{"key", key}, {"value", value}, {"has_key", true}});
    }
    return php::Array(php::StdStrKeyMap{{"value", value}, {"has_key", false}});
}

void typephp_fiber_rethrow(const php::Var &exception) {
    zval throwable;
    ZVAL_COPY(&throwable, NO_CONST_V(exception));
    zend_throw_exception_internal(Z_OBJ(throwable));
    php::throwErrorIfOccurred();
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
    std::unordered_set<zend_object *> seen_aggregates;
    if (iterator.instanceOf(zend_ce_aggregate)) {
        do {
            aggregate = iterator;
            if (UNEXPECTED(!seen_aggregates.insert(aggregate.object()).second)) {
                php::throwException(zend_ce_exception,
                                    "Objects returned by IteratorAggregate::getIterator() must be traversable or "
                                    "implement interface Iterator");
                return php::null;
            }
            php::Var next_iterable = aggregate.call(typephp_fiber_str_get_iterator());
            if (UNEXPECTED(!next_iterable.isObject())) {
                php::throwException(zend_ce_exception,
                                    "Objects returned by IteratorAggregate::getIterator() must be traversable or "
                                    "implement interface Iterator");
                return php::null;
            }
            iterator = next_iterable;
            if (UNEXPECTED(!iterator.instanceOf(zend_ce_iterator) && !iterator.instanceOf(zend_ce_aggregate))) {
                php::throwException(zend_ce_exception,
                                    "Objects returned by IteratorAggregate::getIterator() must be traversable or "
                                    "implement interface Iterator");
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
        php::Var value = iterator.call(typephp_fiber_str_current_method());
        php::Var key = iterator.call(typephp_fiber_str_key_method());
        php::Var resume_value;
        bool delegated_throw = false;
        try {
            resume_value = typephp_fiber_suspend(typephp_fiber_yield_payload(value, key, true), closed);
        } catch (zend_object *) {
            php::Object exception = php::catchException();
            if (!is_generator) {
                typephp_fiber_rethrow(exception);
                return php::null;
            }
            iterator.call(typephp_fiber_str_throw(), php::ArgList{exception});
            delegated_throw = true;
        }
        if (*closed) {
            return php::null;
        }
        if (delegated_throw) {
            continue;
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

enum TypephpFiberGeneratorState : zend_long {
    TYPEPHP_FIBER_GENERATOR_NEW = 0,
    TYPEPHP_FIBER_GENERATOR_SUSPENDED = 1,
    TYPEPHP_FIBER_GENERATOR_RUNNING = 2,
    TYPEPHP_FIBER_GENERATOR_CLOSED_RETURNED = 3,
    TYPEPHP_FIBER_GENERATOR_CLOSED_FAILED = 4,
};

static void typephp_fiber_generator_initialize(php::Object &this_, const php::Var &callback) {
    this_.set(typephp_fiber_str_callback(), callback);
    this_.set(typephp_fiber_str_fiber(), nullptr);
    this_.set(typephp_fiber_str_current(), nullptr);
    this_.set(typephp_fiber_str_key(), nullptr);
    this_.set(typephp_fiber_str_valid(), false);
    this_.set(typephp_fiber_str_state(), static_cast<zend_long>(TYPEPHP_FIBER_GENERATOR_NEW));
    this_.set(typephp_fiber_str_yield_count(), 0);
    this_.set(typephp_fiber_str_next_index(), 0);
    this_.set(typephp_fiber_str_return_value(), nullptr);
}

php::Object typephp_new_fiber_generator(const php::Var &callback) {
    php::Object object;
    if (UNEXPECTED(object_init_ex(object.ptr(), typephp_fiber_generator_ce) != SUCCESS)) {
        php::throwErrorIfOccurred();
        return {};
    }
    php::throwErrorIfOccurred();
    typephp_fiber_generator_initialize(object, callback);
    return object;
}

static TypephpFiberGeneratorState typephp_fiber_generator_state(const php::Object &this_) {
    return static_cast<TypephpFiberGeneratorState>(this_.get(typephp_fiber_str_state()).toInt());
}

static bool typephp_fiber_generator_is_closed(TypephpFiberGeneratorState state) {
    return state == TYPEPHP_FIBER_GENERATOR_CLOSED_RETURNED || state == TYPEPHP_FIBER_GENERATOR_CLOSED_FAILED;
}

static void typephp_fiber_generator_close(php::Object &this_, bool returned) {
    php::Var return_value;
    if (returned) {
        php::Var fiber_value = this_.get(typephp_fiber_str_fiber());
        if (fiber_value.isObject()) {
            php::Object fiber = fiber_value;
            return_value = fiber.call(typephp_fiber_str_get_return());
        }
    }
    TypephpFiberGeneratorState state =
        returned ? TYPEPHP_FIBER_GENERATOR_CLOSED_RETURNED : TYPEPHP_FIBER_GENERATOR_CLOSED_FAILED;
    this_.set(typephp_fiber_str_state(), static_cast<zend_long>(state));
    this_.set(typephp_fiber_str_valid(), false);
    this_.set(typephp_fiber_str_current(), nullptr);
    this_.set(typephp_fiber_str_key(), nullptr);
    this_.set(typephp_fiber_str_return_value(), return_value);
    // A terminated Fiber retains its callback and captured arguments. Cache
    // the return value above, then release the execution context immediately.
    this_.set(typephp_fiber_str_callback(), nullptr);
    this_.set(typephp_fiber_str_fiber(), nullptr);
}

static zend_long typephp_fiber_generator_next_index(zend_long key) {
    if (key == std::numeric_limits<zend_long>::max()) {
        return std::numeric_limits<zend_long>::min();
    }
    return key + 1;
}

static void typephp_fiber_generator_update_key(php::Object &this_, const php::Array &yielded) {
    if (yielded.get(typephp_fiber_str_payload_has_key()).toBool()) {
        php::Var key = yielded.get(typephp_fiber_str_payload_key());
        this_.set(typephp_fiber_str_key(), key);
        if (key.isInt()) {
            zend_long next_index = this_.get(typephp_fiber_str_next_index()).toInt();
            zend_long integer_key = key.toInt();
            if (integer_key >= next_index) {
                this_.set(typephp_fiber_str_next_index(), typephp_fiber_generator_next_index(integer_key));
            }
        }
        return;
    }

    zend_long next_index = this_.get(typephp_fiber_str_next_index()).toInt();
    this_.set(typephp_fiber_str_key(), next_index);
    this_.set(typephp_fiber_str_next_index(), typephp_fiber_generator_next_index(next_index));
}

static void typephp_fiber_generator_advance(php::Object &this_,
                                            const php::Var *send_value = nullptr,
                                            const php::Var *throw_value = nullptr) {
    TypephpFiberGeneratorState state = typephp_fiber_generator_state(this_);
    if (typephp_fiber_generator_is_closed(state)) {
        return;
    }
    if (UNEXPECTED(state == TYPEPHP_FIBER_GENERATOR_RUNNING)) {
        php::throwException(zend_ce_error, "Cannot resume an already running generator");
        return;
    }

    php::Var result;
    try {
        if (state == TYPEPHP_FIBER_GENERATOR_NEW) {
            php::Object fiber =
                php::newObject(typephp_fiber_str_fiber_class(), {this_.get(typephp_fiber_str_callback())});
            this_.set(typephp_fiber_str_fiber(), fiber);
            this_.set(typephp_fiber_str_state(), static_cast<zend_long>(TYPEPHP_FIBER_GENERATOR_RUNNING));
            result = fiber.call(typephp_fiber_str_start());
        } else if (throw_value != nullptr) {
            php::Object fiber = this_.get(typephp_fiber_str_fiber());
            this_.set(typephp_fiber_str_state(), static_cast<zend_long>(TYPEPHP_FIBER_GENERATOR_RUNNING));
            result = fiber.call(typephp_fiber_str_throw(), php::ArgList{*throw_value});
        } else if (send_value != nullptr) {
            php::Object fiber = this_.get(typephp_fiber_str_fiber());
            this_.set(typephp_fiber_str_state(), static_cast<zend_long>(TYPEPHP_FIBER_GENERATOR_RUNNING));
            result = fiber.call(typephp_fiber_str_resume(), php::ArgList{*send_value});
        } else {
            php::Object fiber = this_.get(typephp_fiber_str_fiber());
            this_.set(typephp_fiber_str_state(), static_cast<zend_long>(TYPEPHP_FIBER_GENERATOR_RUNNING));
            result = fiber.call(typephp_fiber_str_resume());
        }
    } catch (zend_object *) {
        php::Object exception = php::catchException();
        typephp_fiber_generator_close(this_, false);
        typephp_fiber_rethrow(exception);
        return;
    }

    php::Object fiber = this_.get(typephp_fiber_str_fiber());
    if (fiber.call(typephp_fiber_str_is_terminated()).toBool()) {
        typephp_fiber_generator_close(this_, true);
        return;
    }

    php::Array yielded = result;
    this_.set(typephp_fiber_str_state(), static_cast<zend_long>(TYPEPHP_FIBER_GENERATOR_SUSPENDED));
    this_.set(typephp_fiber_str_valid(), true);
    this_.set(typephp_fiber_str_current(), yielded.get(typephp_fiber_str_payload_value()));
    typephp_fiber_generator_update_key(this_, yielded);
    this_.set(typephp_fiber_str_yield_count(), this_.get(typephp_fiber_str_yield_count()).toInt() + 1);
}

ZEND_METHOD(FiberGenerator, __construct) {
    php::throwException(zend_ce_error, "FiberGenerator cannot be directly constructed");
}

ZEND_METHOD(FiberGenerator, rewind) {
    php::Object this_(&execute_data->This);
    TypephpFiberGeneratorState state = typephp_fiber_generator_state(this_);
    if (state == TYPEPHP_FIBER_GENERATOR_NEW) {
        typephp_fiber_generator_advance(this_);
        return;
    }
    if (state == TYPEPHP_FIBER_GENERATOR_SUSPENDED && this_.get(typephp_fiber_str_yield_count()).toInt() > 1) {
        php::throwException(zend_ce_exception, "Cannot rewind a generator that was already run");
    }
}

ZEND_METHOD(FiberGenerator, next) {
    php::Object this_(&execute_data->This);
    bool was_new = typephp_fiber_generator_state(this_) == TYPEPHP_FIBER_GENERATOR_NEW;
    typephp_fiber_generator_advance(this_);
    if (was_new && typephp_fiber_generator_state(this_) == TYPEPHP_FIBER_GENERATOR_SUSPENDED) {
        typephp_fiber_generator_advance(this_);
    }
}

ZEND_METHOD(FiberGenerator, send) {
    php::Object this_(&execute_data->This);
    php::Var value = php::getCallArg(0, php::null);
    if (typephp_fiber_generator_state(this_) == TYPEPHP_FIBER_GENERATOR_NEW) {
        typephp_fiber_generator_advance(this_);
    }
    typephp_fiber_generator_advance(this_, &value);
    auto retval = this_.get(typephp_fiber_str_current());
    ZVAL_COPY_DEREF(return_value, retval.direct_ptr());
}

ZEND_METHOD(FiberGenerator, throw) {
    php::Object this_(&execute_data->This);
    if (typephp_fiber_generator_is_closed(typephp_fiber_generator_state(this_))) {
        zval *exception = ZEND_CALL_ARG(execute_data, 1);
        Z_TRY_ADDREF_P(exception);
        zend_throw_exception_object(exception);
        return;
    }
    php::Var exception(ZEND_CALL_ARG(execute_data, 1), php::Ctor::Indirect);
    if (typephp_fiber_generator_state(this_) == TYPEPHP_FIBER_GENERATOR_NEW) {
        typephp_fiber_generator_advance(this_);
        if (typephp_fiber_generator_state(this_) == TYPEPHP_FIBER_GENERATOR_CLOSED_RETURNED) {
            zval *throwable = ZEND_CALL_ARG(execute_data, 1);
            Z_TRY_ADDREF_P(throwable);
            zend_throw_exception_object(throwable);
            return;
        }
    }
    typephp_fiber_generator_advance(this_, nullptr, &exception);
    auto retval = this_.get(typephp_fiber_str_current());
    ZVAL_COPY_DEREF(return_value, retval.direct_ptr());
}

ZEND_METHOD(FiberGenerator, getReturn) {
    php::Object this_(&execute_data->This);
    if (typephp_fiber_generator_state(this_) != TYPEPHP_FIBER_GENERATOR_CLOSED_RETURNED) {
        php::throwException(zend_ce_exception, "Cannot get return value of a generator that hasn't returned");
        return;
    }
    auto retval = this_.get(typephp_fiber_str_return_value());
    ZVAL_COPY_DEREF(return_value, retval.direct_ptr());
}

ZEND_METHOD(FiberGenerator, valid) {
    php::Object this_(&execute_data->This);
    if (typephp_fiber_generator_state(this_) == TYPEPHP_FIBER_GENERATOR_NEW) {
        typephp_fiber_generator_advance(this_);
    }
    auto retval = this_.get(typephp_fiber_str_valid());
    ZVAL_COPY_DEREF(return_value, retval.direct_ptr());
}

ZEND_METHOD(FiberGenerator, current) {
    php::Object this_(&execute_data->This);
    if (typephp_fiber_generator_state(this_) == TYPEPHP_FIBER_GENERATOR_NEW) {
        typephp_fiber_generator_advance(this_);
    }
    auto retval = this_.get(typephp_fiber_str_current());
    ZVAL_COPY_DEREF(return_value, retval.direct_ptr());
}

ZEND_METHOD(FiberGenerator, key) {
    php::Object this_(&execute_data->This);
    if (typephp_fiber_generator_state(this_) == TYPEPHP_FIBER_GENERATOR_NEW) {
        typephp_fiber_generator_advance(this_);
    }
    auto retval = this_.get(typephp_fiber_str_key());
    ZVAL_COPY_DEREF(return_value, retval.direct_ptr());
}

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_typephp_fiber_generator_void, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_typephp_fiber_generator_bool, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_typephp_fiber_generator_mixed, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_typephp_fiber_generator_construct, 0, 0, 1)
ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_typephp_fiber_generator_send, 0, 1, IS_MIXED, 0)
ZEND_ARG_TYPE_INFO(0, value, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_typephp_fiber_generator_throw, 0, 1, IS_MIXED, 0)
ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

static const zend_function_entry typephp_fiber_generator_methods[] = {
    ZEND_ME(FiberGenerator, __construct, arginfo_typephp_fiber_generator_construct, ZEND_ACC_PRIVATE)
        ZEND_ME(FiberGenerator, rewind, arginfo_typephp_fiber_generator_void, ZEND_ACC_PUBLIC)
            ZEND_ME(FiberGenerator, next, arginfo_typephp_fiber_generator_void, ZEND_ACC_PUBLIC)
                ZEND_ME(FiberGenerator, valid, arginfo_typephp_fiber_generator_bool, ZEND_ACC_PUBLIC)
                    ZEND_ME(FiberGenerator, current, arginfo_typephp_fiber_generator_mixed, ZEND_ACC_PUBLIC) ZEND_ME(
                        FiberGenerator, key, arginfo_typephp_fiber_generator_mixed, ZEND_ACC_PUBLIC)
                        ZEND_ME(FiberGenerator, send, arginfo_typephp_fiber_generator_send, ZEND_ACC_PUBLIC) ZEND_ME(
                            FiberGenerator, throw, arginfo_typephp_fiber_generator_throw, ZEND_ACC_PUBLIC)
                            ZEND_ME(FiberGenerator, getReturn, arginfo_typephp_fiber_generator_mixed, ZEND_ACC_PUBLIC)
                                ZEND_FE_END};

void typephp_register_fiber_generator_class() {
    static zend_object_handlers object_handlers;
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "FiberGenerator", typephp_fiber_generator_methods);
    typephp_fiber_generator_ce = zend_register_internal_class_with_flags(
        &ce, nullptr, ZEND_ACC_FINAL | ZEND_ACC_NO_DYNAMIC_PROPERTIES | ZEND_ACC_NOT_SERIALIZABLE);
    object_handlers = *zend_get_std_object_handlers();
    object_handlers.clone_obj = nullptr;
    typephp_fiber_generator_ce->default_object_handlers = &object_handlers;
    zend_class_implements(typephp_fiber_generator_ce, 1, zend_ce_iterator);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("callback"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("fiber"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("current"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("key"), ZEND_ACC_PRIVATE);
    zend_declare_property_bool(typephp_fiber_generator_ce, ZEND_STRL("valid"), false, ZEND_ACC_PRIVATE);
    zend_declare_property_long(
        typephp_fiber_generator_ce, ZEND_STRL("state"), TYPEPHP_FIBER_GENERATOR_NEW, ZEND_ACC_PRIVATE);
    zend_declare_property_long(typephp_fiber_generator_ce, ZEND_STRL("yield_count"), 0, ZEND_ACC_PRIVATE);
    zend_declare_property_long(typephp_fiber_generator_ce, ZEND_STRL("next_index"), 0, ZEND_ACC_PRIVATE);
    zend_declare_property_null(typephp_fiber_generator_ce, ZEND_STRL("return_value"), ZEND_ACC_PRIVATE);
}

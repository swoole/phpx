/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | VM-less TypePHP process entry for the php-nano source runtime.       |
  +----------------------------------------------------------------------+
*/

#include "php_nano_extension.h"

extern "C" {
#include <zend_exceptions.h>
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <limits>

namespace {

constexpr uint32_t INVALID_ARGUMENT_OFFSET = std::numeric_limits<uint32_t>::max();

uint32_t argument_offset_by_name(
    const zend_function *function, const zend_string *name) noexcept
{
    if (function->common.arg_info != nullptr) {
        for (uint32_t index = 0; index < function->common.num_args; ++index) {
            const zend_arg_info *info = &function->common.arg_info[index];
            if (info->name != nullptr && zend_string_equals(name, info->name)) {
                return index;
            }
        }
    }
    return (function->common.fn_flags & ZEND_ACC_VARIADIC) != 0
        ? function->common.num_args
        : INVALID_ARGUMENT_OFFSET;
}

bool calculate_frame_argument_count(
    const zend_function *function,
    uint32_t positional_count,
    HashTable *named_params,
    uint32_t *frame_count)
{
    uint32_t count = positional_count;
    bool saw_named = false;
    zend_string *name;
    ZEND_HASH_FOREACH_STR_KEY(named_params, name) {
        if (name == nullptr) {
            if (saw_named) {
                zend_throw_error(nullptr, "Cannot use positional argument after named argument");
                return false;
            }
            if (count == std::numeric_limits<uint32_t>::max()) {
                zend_throw_error(nullptr, "Too many arguments");
                return false;
            }
            ++count;
            continue;
        }

        saw_named = true;
        const uint32_t offset = argument_offset_by_name(function, name);
        if (offset == INVALID_ARGUMENT_OFFSET) {
            zend_throw_error(nullptr, "Unknown named parameter $%s", ZSTR_VAL(name));
            return false;
        }
        if (offset < function->common.num_args && count <= offset) {
            count = offset + 1;
        }
    } ZEND_HASH_FOREACH_END();

    *frame_count = count;
    return true;
}

void release_call_frame(zend_execute_data *call, uint32_t argument_count) noexcept
{
    for (uint32_t index = 0; index < argument_count; ++index) {
        zval *argument = ZEND_CALL_ARG(call, index + 1);
        if (!Z_ISUNDEF_P(argument)) {
            zval_ptr_dtor(argument);
        }
    }
    if ((ZEND_CALL_INFO(call) & ZEND_CALL_HAS_EXTRA_NAMED_PARAMS) != 0) {
        zend_array_release(call->extra_named_params);
    }
    efree(call);
}

bool copy_call_argument(
    zend_execute_data *call,
    zval *target,
    zval *source,
    const zend_function *function,
    uint32_t argument_number)
{
    if (Z_ISUNDEF_P(source)) {
        ZVAL_UNDEF(target);
        ZEND_ADD_CALL_FLAG(call, ZEND_CALL_MAY_HAVE_UNDEF);
        return true;
    }

    bool must_wrap = false;
    if (ARG_SHOULD_BE_SENT_BY_REF(function, argument_number)) {
        if (!Z_ISREF_P(source) && !ARG_MAY_BE_SENT_BY_REF(function, argument_number)) {
            zend_param_must_be_ref(function, argument_number);
            must_wrap = true;
            if (EG(exception) != nullptr) {
                return false;
            }
        }
    } else if (Z_ISREF_P(source)
        && (function->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) == 0) {
        // A reference variable passed to a by-value parameter is separated at
        // the call boundary. __call() trampolines are the Zend exception.
        source = Z_REFVAL_P(source);
    }

    if (!must_wrap) {
        ZVAL_COPY(target, source);
    } else {
        Z_TRY_ADDREF_P(source);
        ZVAL_NEW_REF(target, source);
    }
    return true;
}

bool copy_named_arguments(
    zend_execute_data *call,
    const zend_function *function,
    uint32_t positional_count,
    HashTable *named_params)
{
    uint32_t next_positional = positional_count;
    zend_string *name;
    zval *source;
    ZEND_HASH_FOREACH_STR_KEY_VAL(named_params, name, source) {
        if (name == nullptr) {
            ++next_positional;
            if (!copy_call_argument(
                    call,
                    ZEND_CALL_ARG(call, next_positional),
                    source,
                    function,
                    next_positional)) {
                return false;
            }
            continue;
        }

        const uint32_t offset = argument_offset_by_name(function, name);
        if (offset == function->common.num_args) {
            if ((ZEND_CALL_INFO(call) & ZEND_CALL_HAS_EXTRA_NAMED_PARAMS) == 0) {
                ZEND_ADD_CALL_FLAG(call, ZEND_CALL_HAS_EXTRA_NAMED_PARAMS);
                call->extra_named_params = zend_new_array(0);
            }
            zval copy;
            if (!copy_call_argument(
                    call, &copy, source, function, function->common.num_args + 1)) {
                return false;
            }
            if (zend_hash_add_new(call->extra_named_params, name, &copy) == nullptr) {
                zval_ptr_dtor(&copy);
                zend_throw_error(
                    nullptr, "Named parameter $%s overwrites previous argument", ZSTR_VAL(name));
                return false;
            }
            continue;
        }

        zval *target = ZEND_CALL_ARG(call, offset + 1);
        if (!Z_ISUNDEF_P(target)) {
            zend_throw_error(
                nullptr, "Named parameter $%s overwrites previous argument", ZSTR_VAL(name));
            return false;
        }
        if (!copy_call_argument(call, target, source, function, offset + 1)) {
            return false;
        }
    } ZEND_HASH_FOREACH_END();
    return true;
}

bool fill_default_arguments(zend_execute_data *call, const zend_function *function)
{
    const uint32_t argument_count = ZEND_CALL_NUM_ARGS(call);
    for (uint32_t index = 0;
         index < argument_count && index < function->common.num_args;
         ++index) {
        zval *argument = ZEND_CALL_ARG(call, index + 1);
        if (!Z_ISUNDEF_P(argument)) {
            continue;
        }

        if (index < function->common.required_num_args) {
            zend_argument_error(zend_ce_argument_count_error, index + 1, "not passed");
            return false;
        }

        if ((function->common.fn_flags & ZEND_ACC_USER_ARG_INFO) != 0) {
            ZEND_ADD_CALL_FLAG(call, ZEND_CALL_MAY_HAVE_UNDEF);
            continue;
        }

        const zend_arg_info *info = &function->common.arg_info[index];
        zval default_value;
        if (zend_get_default_from_internal_arg_info(&default_value, info) == FAILURE) {
            zend_argument_error(
                zend_ce_argument_count_error,
                index + 1,
                "must be passed explicitly, because the default value is not available in PHP Nano");
            return false;
        }
        ZVAL_COPY_VALUE(argument, &default_value);
        if ((ZEND_ARG_SEND_MODE(info) & ZEND_SEND_BY_REF) != 0) {
            ZVAL_NEW_REF(argument, argument);
        }
    }
    return true;
}

zend_result invoke_internal_handler(
    zend_function *function,
    zend_object *object,
    zend_class_entry *called_scope,
    zval *retval,
    uint32_t param_count,
    zval *params,
    HashTable *named_params);

zend_result invoke_call_trampoline(
    zend_function *trampoline,
    zend_object *object,
    zend_class_entry *called_scope,
    zval *retval,
    uint32_t param_count,
    zval *params,
    HashTable *named_params)
{
    zend_function *magic = object != nullptr
        ? object->ce->__call
        : (called_scope != nullptr ? called_scope->__callstatic : nullptr);
    if (magic == nullptr || magic->type != ZEND_INTERNAL_FUNCTION) {
        zend_throw_error(nullptr, "PHP Nano can only invoke AOT __call handlers");
        return SUCCESS;
    }

    zval magic_params[2];
    ZVAL_STR_COPY(&magic_params[0], trampoline->common.function_name);
    const uint32_t named_count = named_params == nullptr
        ? 0
        : zend_hash_num_elements(named_params);
    array_init_size(&magic_params[1], param_count + named_count);

    for (uint32_t index = 0; index < param_count; ++index) {
        zval copy;
        ZVAL_COPY(&copy, &params[index]);
        zend_hash_next_index_insert(Z_ARRVAL(magic_params[1]), &copy);
    }
    if (named_params != nullptr) {
        zend_string *name;
        zval *source;
        ZEND_HASH_FOREACH_STR_KEY_VAL(named_params, name, source) {
            zval copy;
            ZVAL_COPY(&copy, source);
            zval *inserted = name == nullptr
                ? zend_hash_next_index_insert(Z_ARRVAL(magic_params[1]), &copy)
                : zend_hash_add_new(Z_ARRVAL(magic_params[1]), name, &copy);
            if (inserted == nullptr) {
                zval_ptr_dtor(&copy);
                zval_ptr_dtor(&magic_params[1]);
                zval_ptr_dtor(&magic_params[0]);
                zend_throw_error(nullptr, "Named argument overwrites a previous __call argument");
                return SUCCESS;
            }
        } ZEND_HASH_FOREACH_END();
    }

    const zend_result result = invoke_internal_handler(
        magic, object, called_scope, retval, 2, magic_params, nullptr);
    zval_ptr_dtor(&magic_params[1]);
    zval_ptr_dtor(&magic_params[0]);
    return result;
}

zend_result invoke_internal_handler(
    zend_function *function,
    zend_object *object,
    zend_class_entry *called_scope,
    zval *retval,
    uint32_t param_count,
    zval *params,
    HashTable *named_params)
{
    if (retval == nullptr || function == nullptr) {
        return FAILURE;
    }
    ZVAL_UNDEF(retval);
    if (function->type == ZEND_USER_FUNCTION
        && (function->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) != 0) {
        return invoke_call_trampoline(
            function, object, called_scope, retval, param_count, params, named_params);
    }
    if (function->type != ZEND_INTERNAL_FUNCTION ||
        function->internal_function.handler == nullptr ||
        (function->common.fn_flags & ZEND_ACC_ABSTRACT) != 0) {
        zend_throw_error(nullptr, "PHP Nano can only invoke AOT/internal functions");
        return SUCCESS;
    }
    uint32_t frame_argument_count = param_count;
    if (named_params != nullptr && zend_hash_num_elements(named_params) != 0 &&
        !calculate_frame_argument_count(
            function, param_count, named_params, &frame_argument_count)) {
        return SUCCESS;
    }

    const size_t frame_slots = static_cast<size_t>(ZEND_CALL_FRAME_SLOT) + frame_argument_count;
    auto *call = static_cast<zend_execute_data *>(ecalloc(frame_slots, sizeof(zval)));
    if (call == nullptr) {
        return FAILURE;
    }

    call->func = function;
    call->return_value = retval;
    call->prev_execute_data = EG(current_execute_data);
    call->symbol_table = nullptr;
    call->run_time_cache = nullptr;
    call->extra_named_params = nullptr;
    Z_PTR(call->This) = (function->common.fn_flags & ZEND_ACC_STATIC) != 0 || object == nullptr
        ? static_cast<void *>(called_scope)
        : static_cast<void *>(object);
    ZEND_CALL_INFO(call) = ZEND_CALL_TOP_FUNCTION | ZEND_CALL_DYNAMIC |
        (((function->common.fn_flags & ZEND_ACC_STATIC) == 0 && object != nullptr)
            ? ZEND_CALL_HAS_THIS : 0);
    ZEND_CALL_NUM_ARGS(call) = frame_argument_count;

    for (uint32_t index = 0; index < param_count; ++index) {
        if (!copy_call_argument(
                call,
                ZEND_CALL_ARG(call, index + 1),
                &params[index],
                function,
                index + 1)) {
            release_call_frame(call, frame_argument_count);
            return SUCCESS;
        }
    }

    if (named_params != nullptr && zend_hash_num_elements(named_params) != 0 &&
        !copy_named_arguments(call, function, param_count, named_params)) {
        release_call_frame(call, frame_argument_count);
        return SUCCESS;
    }

    ZVAL_NULL(retval);
    EG(current_execute_data) = call;
    if (fill_default_arguments(call, function)) {
        function->internal_function.handler(call, retval);
    }
    EG(current_execute_data) = call->prev_execute_data;

    release_call_frame(call, frame_argument_count);

    if (EG(exception) != nullptr) {
        zval_ptr_dtor(retval);
        ZVAL_UNDEF(retval);
    }
    return SUCCESS;
}

} // namespace

extern "C" ZEND_API zend_result zend_call_function(
    zend_fcall_info *fci, zend_fcall_info_cache *fci_cache)
{
    if (fci == nullptr || fci->retval == nullptr) {
        return FAILURE;
    }
    zend_fcall_info_cache resolved{};
    if (fci_cache == nullptr || fci_cache->function_handler == nullptr) {
        char *error = nullptr;
        if (!zend_is_callable_ex(
                &fci->function_name, fci->object, 0, nullptr, &resolved, &error)) {
            zend_string *name = zend_get_callable_name_ex(&fci->function_name, fci->object);
            zend_throw_error(nullptr, "Invalid callback %s%s%s",
                ZSTR_VAL(name), error == nullptr ? "" : ", ", error == nullptr ? "" : error);
            zend_string_release(name);
            if (error != nullptr) {
                efree(error);
            }
            ZVAL_UNDEF(fci->retval);
            return SUCCESS;
        }
        fci_cache = &resolved;
    }
    const bool release_call_trampoline =
        fci_cache->function_handler->type == ZEND_USER_FUNCTION
        && (fci_cache->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) != 0;
    const zend_result result = invoke_internal_handler(
        fci_cache->function_handler,
        fci_cache->object != nullptr ? fci_cache->object : fci->object,
        fci_cache->called_scope,
        fci->retval,
        fci->param_count,
        fci->params,
        fci->named_params);
    if (release_call_trampoline) {
        zend_release_fcall_info_cache(fci_cache);
    }
    return result;
}

extern "C" ZEND_API void zend_call_known_function_ex(
    zend_function *function,
    zend_object *object,
    zend_class_entry *called_scope,
    zval *retval,
    uint32_t param_count,
    zval *params,
    HashTable *named_params,
    uint32_t consumed_args)
{
    (void) consumed_args;
    zval temporary;
    zval *target = retval != nullptr ? retval : &temporary;
    (void) invoke_internal_handler(
        function, object, called_scope, target, param_count, params, named_params);
    if (retval == nullptr && !Z_ISUNDEF(temporary)) {
        zval_ptr_dtor(&temporary);
    }
}

extern "C" int typephp_nano_project_main();

int main(int argc, char **argv)
{
    php_nano_set_cli_arguments(argc, argv);
    if (php_nano_startup_composer_extensions() != SUCCESS) {
        std::fputs("Unable to start PHP Nano extensions\n", stderr);
        return 1;
    }

    int exit_code = 1;
    try {
        exit_code = typephp_nano_project_main();
    } catch (const std::exception &exception) {
        std::fprintf(stderr, "Unhandled TypePHP exception: %s\n", exception.what());
    } catch (...) {
        std::fputs("Unhandled TypePHP exception\n", stderr);
    }

    php_nano_shutdown_composer_extensions();
    return exit_code;
}

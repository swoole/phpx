/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | VM-less TypePHP process entry for the php-nano source runtime.       |
  +----------------------------------------------------------------------+
*/

#include "php_nano_extension.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>

namespace {

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
    if (function->type != ZEND_INTERNAL_FUNCTION ||
        function->internal_function.handler == nullptr ||
        (function->common.fn_flags & ZEND_ACC_ABSTRACT) != 0) {
        zend_throw_error(nullptr, "PHP Nano can only invoke AOT/internal functions");
        return SUCCESS;
    }
    if (named_params != nullptr && zend_hash_num_elements(named_params) != 0) {
        zend_throw_error(nullptr, "Named arguments are not enabled in PHP Nano yet");
        return SUCCESS;
    }

    const size_t frame_slots = static_cast<size_t>(ZEND_CALL_FRAME_SLOT) + param_count;
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
    ZEND_CALL_NUM_ARGS(call) = param_count;

    for (uint32_t index = 0; index < param_count; ++index) {
        ZVAL_COPY(ZEND_CALL_ARG(call, index + 1), &params[index]);
    }

    ZVAL_NULL(retval);
    EG(current_execute_data) = call;
    function->internal_function.handler(call, retval);
    EG(current_execute_data) = call->prev_execute_data;

    for (uint32_t index = 0; index < param_count; ++index) {
        zval_ptr_dtor(ZEND_CALL_ARG(call, index + 1));
    }
    efree(call);

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
    return invoke_internal_handler(
        fci_cache->function_handler,
        fci_cache->object != nullptr ? fci_cache->object : fci->object,
        fci_cache->called_scope,
        fci->retval,
        fci->param_count,
        fci->params,
        fci->named_params);
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

int main()
{
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

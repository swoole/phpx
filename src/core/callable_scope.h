#pragma once

#include "phpx.h"

namespace php::detail {

/**
 * A synthetic Zend user frame used only while resolving a callable.
 *
 * The frame is never installed in EG(current_execute_data), so resolving
 * visibility cannot leak scope to unrelated calls or other threads.
 */
class CallableScopeFrame final {
  public:
    explicit CallableScopeFrame(const CallableScope &scope) {
        ZEND_ASSERT(scope.caller_function != nullptr);
        ZEND_ASSERT(scope.lexicalScope() != nullptr);

        uint32_t call_info = ZEND_CALL_TOP_FUNCTION;
        void *object_or_called_scope = scope.called_scope
            ? static_cast<void *>(scope.called_scope)
            : static_cast<void *>(scope.lexicalScope());
        if (scope.this_object != nullptr) {
            call_info |= ZEND_CALL_HAS_THIS;
            object_or_called_scope = scope.this_object;
        }
        zend_vm_init_call_frame(
            &frame_, call_info, scope.caller_function, 0, object_or_called_scope);
    }

    bool resolve(zval *callable,
                 zend_object *object,
                 zend_fcall_info_cache *cache,
                 char **error) {
        return zend_is_callable_at_frame(callable, object, &frame_, 0, cache, error);
    }

  private:
    zend_execute_data frame_{};
};

}  // namespace php::detail

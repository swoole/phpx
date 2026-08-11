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
    explicit CallableScopeFrame(zend_class_entry *scope) {
        function_.type = ZEND_USER_FUNCTION;
        function_.common.scope = scope;
        zend_vm_init_call_frame(
            &frame_, ZEND_CALL_TOP_FUNCTION, &function_, 0, scope);
    }

    bool resolve(zval *callable,
                 zend_object *object,
                 zend_fcall_info_cache *cache,
                 char **error) {
        return zend_is_callable_at_frame(callable, object, &frame_, 0, cache, error);
    }

  private:
    zend_function function_{};
    zend_execute_data frame_{};
};

}  // namespace php::detail

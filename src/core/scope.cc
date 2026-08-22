#include <typephp_helper.h>

php::Str php::getCalledClass(php::Object &this_) {
    auto ce = getCalledCe(this_);
    if (ce) {
        return php::Str(ce->name);
    }
    return php::Str("");
}

zend_class_entry *php::getCalledCe(php::Object &this_) {
    if (this_.isObject()) {
        return this_.ce();
    }
    return static_cast<zend_class_entry *>(Z_PTR_P(this_.ptr()));
}

namespace {

zend_execute_data *get_user_code_frame() {
    zend_execute_data *frame = EG(current_execute_data);
    while (frame && (!frame->func || !ZEND_USER_CODE(frame->func->type))) {
        frame = frame->prev_execute_data;
    }
    return frame;
}

}  // namespace

php::UserCodeScopeGuard::UserCodeScopeGuard(const CallableScope &scope) {
    auto *frame = get_user_code_frame();
    if (UNEXPECTED(frame == nullptr || frame->func == nullptr)) {
        php::throwError("A user-code frame is required for scoped dynamic callback calls");
        return;
    }
    function_ = frame->func;
    previous_scope_ = function_->common.scope;
    function_->common.scope = scope.lexicalScope();
}

php::UserCodeScopeGuard::~UserCodeScopeGuard() noexcept {
    if (function_ != nullptr) {
        function_->common.scope = previous_scope_;
    }
}

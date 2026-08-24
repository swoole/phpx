#include "phpx_test.h"
#include "phpx_fake_scope_guard.h"
#include "typephp_helper.h"

using namespace php;

TEST(scope_guard, fake_scope_is_restored) {
    auto *original_scope = FakeScopeGuard::current();
    auto *outer_scope = getClassEntrySafe("stdClass");
    auto *inner_scope = getClassEntrySafe("ArrayObject");

    {
        FakeScopeGuard outer_guard{outer_scope};
        ASSERT_EQ(FakeScopeGuard::current(), outer_scope);

        {
            FakeScopeGuard inner_guard{inner_scope};
            ASSERT_EQ(FakeScopeGuard::current(), inner_scope);
        }

        ASSERT_EQ(FakeScopeGuard::current(), outer_scope);
    }

    ASSERT_EQ(FakeScopeGuard::current(), original_scope);
}

TEST(scope_guard, fake_scope_is_restored_after_cpp_exception) {
    auto *original_scope = FakeScopeGuard::current();
    auto *temporary_scope = getClassEntrySafe("stdClass");

    try {
        FakeScopeGuard fake_scope_guard{temporary_scope};
        ASSERT_EQ(FakeScopeGuard::current(), temporary_scope);
        throw 1;
    } catch (int) {
    }

    ASSERT_EQ(FakeScopeGuard::current(), original_scope);
}

TEST(scope_guard, explicit_restore_is_idempotent) {
    auto *original_scope = FakeScopeGuard::current();
    auto *temporary_scope = getClassEntrySafe("stdClass");

    {
        FakeScopeGuard fake_scope_guard{temporary_scope};
        fake_scope_guard.restore();
        fake_scope_guard.restore();
        ASSERT_EQ(FakeScopeGuard::current(), original_scope);
    }

    ASSERT_EQ(FakeScopeGuard::current(), original_scope);
}

TEST(scope_guard, scoped_call_exposes_and_restores_lexical_scope) {
    auto *target = getClassEntrySafe("ArrayObject");
    auto *probe = getFunction("phpx_test_lexical_call_scope");

    ASSERT_EQ(detail::getLexicalCallScope(), nullptr);
    Variant result = call(target, probe);
    ASSERT_TRUE(result.isString());
    ASSERT_STREQ(result.toCString(), "ArrayObject");
    ASSERT_EQ(detail::getLexicalCallScope(), nullptr);
}

TEST(scope_guard, scoped_call_restores_lexical_scope_after_exception) {
    auto *target = getClassEntrySafe("ArrayObject");
    auto *strlen_function = getFunction("strlen");

    try {
        call(target, strlen_function);
        FAIL() << "Expected an argument-count exception";
    } catch (zend_object *) {
        catchException();
    }
    ASSERT_EQ(detail::getLexicalCallScope(), nullptr);
}

namespace {

zend_execute_data *find_user_code_frame() {
    auto *frame = EG(current_execute_data);
    while (frame != nullptr && (frame->func == nullptr || !ZEND_USER_CODE(frame->func->type))) {
        frame = frame->prev_execute_data;
    }
    return frame;
}

zend_class_entry *scope_target_class() {
    static zend_class_entry *class_entry = nullptr;
    if (class_entry == nullptr) {
        eval(R"PHP(
            class PhpxUserCodeScopeTarget {
                public function scopeAnchor(): void {}
            }
        )PHP");
        class_entry = getClassEntrySafe("PhpxUserCodeScopeTarget");
    }
    return class_entry;
}

}  // namespace

TEST(scope_guard, called_class_supports_object_and_class_carriers) {
    auto object = newObject("stdClass");
    ASSERT_EQ(getCalledCe(object), object.ce());
    ASSERT_STREQ(getCalledClass(object).data(), "stdClass");

    Object class_carrier;
    auto *class_entry = getClassEntrySafe("ArrayObject");
    ZVAL_PTR(class_carrier.ptr(), class_entry);
    ASSERT_EQ(getCalledCe(class_carrier), class_entry);
    ASSERT_STREQ(getCalledClass(class_carrier).data(), "ArrayObject");
}

TEST(scope_guard, user_code_scope_is_restored) {
    auto *frame = find_user_code_frame();
    ASSERT_NE(frame, nullptr);
    ASSERT_NE(frame->func, nullptr);

    auto *target = scope_target_class();
    auto *original_scope = frame->func->common.scope;
    CallableScope callable_scope{getMethod(target, "scopeAnchor"), target, nullptr};

    {
        UserCodeScopeGuard guard{callable_scope};
        ASSERT_EQ(frame->func->common.scope, target);
    }

    ASSERT_EQ(frame->func->common.scope, original_scope);
}

TEST(scope_guard, user_code_scope_is_restored_after_cpp_exception) {
    auto *frame = find_user_code_frame();
    ASSERT_NE(frame, nullptr);
    auto *target = scope_target_class();
    auto *original_scope = frame->func->common.scope;
    CallableScope callable_scope{getMethod(target, "scopeAnchor"), target, nullptr};

    try {
        UserCodeScopeGuard guard{callable_scope};
        ASSERT_EQ(frame->func->common.scope, target);
        throw 1;
    } catch (int) {
    }

    ASSERT_EQ(frame->func->common.scope, original_scope);
}

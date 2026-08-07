#include "phpx_test.h"
#include "phpx_fake_scope_guard.h"

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

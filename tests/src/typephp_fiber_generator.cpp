#include "phpx_test.h"
#include "typephp_fiber_generator.h"

using namespace php;

TEST(typephp_fiber_generator, suspend_outside_fiber_reports_error) {
    bool closed = false;
    try_call(
        [&]() { (void) typephp_fiber_suspend(1, &closed); },
        "Cannot suspend outside of a fiber");
    ASSERT_TRUE(closed);
}

TEST(typephp_fiber_generator, yield_outside_fiber_reports_error) {
    try_call(
        []() { (void) typephp_fiber_yield(1); },
        "Cannot suspend outside of a fiber");
}

TEST(typephp_fiber_generator, yield_from_empty_array_completes_without_suspending) {
    bool closed = true;
    auto result = typephp_fiber_yield_from(Array{}, &closed);
    ASSERT_FALSE(closed);
    ASSERT_TRUE(result.isNull());
}

TEST(typephp_fiber_generator, rethrow_preserves_throwable) {
    auto exception = newObject("RuntimeException", {"fiber failure"});
    try_call(
        [&]() { typephp_fiber_rethrow(exception); },
        "fiber failure");
}

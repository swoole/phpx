#include "phpx_test.h"
#include "typephp_fiber_generator.h"

using namespace php;

TEST(typephp_fiber_generator, class_is_registered_by_test_module) {
    ASSERT_NE(typephp_fiber_generator_ce, nullptr);
    ASSERT_TRUE(instanceof_function(typephp_fiber_generator_ce, zend_ce_iterator));

    auto *registered_class = typephp_fiber_generator_ce;
    typephp_register_fiber_generator_class();
    ASSERT_EQ(typephp_fiber_generator_ce, registered_class);
    typephp_unregister_fiber_generator_class();
    ASSERT_EQ(typephp_fiber_generator_ce, registered_class);
}

TEST(typephp_fiber_generator, direct_construction_is_rejected) {
    try_call(
        []() { (void) newObject("FiberGenerator", {"phpx_test_generator_sequence"}); },
        "FiberGenerator cannot be directly constructed");
}

TEST(typephp_fiber_generator, sequence_supports_current_key_send_and_return) {
    auto generator = typephp_new_fiber_generator("phpx_test_generator_sequence");

    ASSERT_TRUE(generator.call("valid").toBool());
    ASSERT_EQ(generator.call("current").toInt(), 10);
    ASSERT_EQ(generator.call("key").toInt(), 0);

    ASSERT_STREQ(generator.call("send", {"sent"}).toCString(), "sent");
    ASSERT_EQ(generator.call("key").toInt(), 7);
    try_call(
        [&]() { generator.call("rewind"); },
        "Cannot rewind a generator that was already run");

    generator.call("next");
    ASSERT_FALSE(generator.call("valid").toBool());
    ASSERT_EQ(generator.call("getReturn").toInt(), 42);
}

TEST(typephp_fiber_generator, next_on_new_generator_skips_first_yield) {
    auto generator = typephp_new_fiber_generator("phpx_test_generator_sequence");
    generator.call("next");

    ASSERT_TRUE(generator.call("valid").toBool());
    ASSERT_TRUE(generator.call("current").isNull());
    ASSERT_EQ(generator.call("key").toInt(), 7);
}

TEST(typephp_fiber_generator, get_return_requires_completed_generator) {
    auto generator = typephp_new_fiber_generator("phpx_test_generator_sequence");
    try_call(
        [&]() { (void) generator.call("getReturn"); },
        "Cannot get return value of a generator that hasn't returned");
}

TEST(typephp_fiber_generator, throwing_into_suspended_and_closed_generator) {
    auto generator = typephp_new_fiber_generator("phpx_test_generator_sequence");
    ASSERT_EQ(generator.call("current").toInt(), 10);

    try_call(
        [&]() { generator.call("throw", {newObject("RuntimeException", {"delegated failure"})}); },
        "delegated failure");
    ASSERT_FALSE(generator.call("valid").toBool());

    try_call(
        [&]() { generator.call("throw", {newObject("LogicException", {"closed failure"})}); },
        "closed failure");
}

TEST(typephp_fiber_generator, yield_from_array_preserves_keys_and_values) {
    auto generator = typephp_new_fiber_generator("phpx_test_generator_yield_from_array");

    ASSERT_STREQ(generator.call("current").toCString(), "A");
    ASSERT_STREQ(generator.call("key").toCString(), "first");
    generator.call("next");
    ASSERT_STREQ(generator.call("current").toCString(), "B");
    ASSERT_EQ(generator.call("key").toInt(), 3);
    generator.call("next");
    ASSERT_EQ(generator.call("getReturn").toInt(), 21);
}

TEST(typephp_fiber_generator, yield_from_generator_returns_delegated_result) {
    auto generator = typephp_new_fiber_generator("phpx_test_generator_yield_from_generator");

    ASSERT_EQ(generator.call("current").toInt(), 5);
    ASSERT_STREQ(generator.call("key").toCString(), "nested");
    generator.call("next");
    ASSERT_EQ(generator.call("getReturn").toInt(), 77);
}

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

TEST(typephp_fiber_generator, yield_from_rejects_non_iterable_values) {
    try_call(
        []() { (void) typephp_fiber_yield_from(42, nullptr); },
        "Can use \"yield from\" only with arrays and Traversables");
    try_call(
        []() { (void) typephp_fiber_yield_from(newObject("stdClass"), nullptr); },
        "Can use \"yield from\" only with arrays and Traversables");
}

TEST(typephp_fiber_generator, rethrow_preserves_throwable) {
    auto exception = newObject("RuntimeException", {"fiber failure"});
    try_call(
        [&]() { typephp_fiber_rethrow(exception); },
        "fiber failure");
}

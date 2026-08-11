#include "phpx_test.h"
#include "typephp_helper.h"

TEST(persistent_cache, resolves_once_and_resets) {
    php::PersistentCacheSlot<int *> slot{};
    int first = 1;
    int second = 2;
    int calls = 0;

    auto *value = php::getPersistentCache(slot, [&]() {
        calls++;
        return &first;
    });
    ASSERT_EQ(value, &first);

    value = php::getPersistentCache(slot, [&]() {
        calls++;
        return &second;
    });
    ASSERT_EQ(value, &first);
    ASSERT_EQ(calls, 1);

    php::resetPersistentCache(slot);
    value = php::getPersistentCache(slot, [&]() {
        calls++;
        return &second;
    });
    ASSERT_EQ(value, &second);
    ASSERT_EQ(calls, 2);
}

TEST(persistent_cache, supports_integral_sentinel) {
    php::PersistentCacheSlot<uint32_t> slot{};
    int calls = 0;

    auto value = php::getPersistentCache(slot, [&]() {
        calls++;
        return uint32_t{1024};
    });
    ASSERT_EQ(value, 1024u);
    ASSERT_EQ(php::getPersistentCache(slot,
                                      [&]() {
                                          calls++;
                                          return uint32_t{2048};
                                      }),
              1024u);
    ASSERT_EQ(calls, 1);
}

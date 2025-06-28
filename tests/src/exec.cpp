#include "phpx_test.h"

using namespace php;

static const char *g_date = "2009-02-15";

static const Variant is_dir(ZEND_STRL("is_dir"), true);

TEST(exec, func) {
    auto retval = is_dir({"/tmp"});
    ASSERT_TRUE(retval.toBool());

    retval = is_dir({"/tmp-not-exists"});
    ASSERT_FALSE(retval.toBool());
}

TEST(exec, method) {
    auto retval = exec("DateTime::createFromFormat", "j-M-Y", "15-Feb-2009");
    ASSERT_TRUE(retval.isObject());
    Object o(retval);
    auto _date = o.exec("format", "Y-m-d");
    ASSERT_STREQ(_date.toCString(), g_date);
}

TEST(exec, func_with_namespace) {
    auto retval = exec("\\is_dir", "/tmp");
    ASSERT_TRUE(retval.toBool());
}

TEST(exec, redis) {
    auto redis = newObject("redis");
    auto rv = redis.exec("connect", "127.0.0.1", 6379, 2.5);
    ASSERT_TRUE(rv.toBool());
    auto val = "hello phpx";
    auto key = "phpx_test_key";
    redis.exec("set", key, val);
    auto val2 = redis.exec("get", key);

    ASSERT_STREQ(val2.toCString(), val);
}

TEST(exec, array_push) {
    Array arr;
    auto ref = arr.toReference();
    exec("array_push", ref, "php", "java", "go");
    auto v1 = ref.referenceTo();
    ASSERT_EQ(v1.length(), 3);

    exec("array_push", ref, "c++", "rust", "erlang", "node.js");
    auto v2 = ref.referenceTo();
    ASSERT_EQ(v2.length(), 7);

    exec("array_push", ref, "python", "ruby", "lua", "perl", "vue");
    auto v3 = ref.referenceTo();
    ASSERT_EQ(v3.length(), 12);

    exec("array_push", ref, "v1", "v2", "v3", "v4", "v5", "v6");
    auto v4 = ref.referenceTo();
    ASSERT_EQ(v4.length(), 18);

    exec("array_push", ref, "v1", "v2", "v3", "v4", "v5", "v6", "v7");
    auto v5 = ref.referenceTo();
    ASSERT_EQ(v5.length(), 25);

    exec("array_push", ref, "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8");
    auto v6 = ref.referenceTo();
    ASSERT_EQ(v6.length(), 33);

    exec("array_push", ref, "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9");
    auto v7 = ref.referenceTo();
    ASSERT_EQ(v7.length(), 42);
}

#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_class.h"

using namespace php;

static const char *g_date = "2009-02-15";

TEST(exec, func) {
    auto retval = is_dir({"/tmp"});
    ASSERT_TRUE(retval.toBool());

    retval = is_dir({"/tmp-not-exists"});
    ASSERT_FALSE(retval.toBool());
}

TEST(exec, method) {
    auto retval = DateTime::createFromFormat("j-M-Y", "15-Feb-2009");
    ASSERT_TRUE(retval.isObject());
    Object o(retval);
    auto _date = o.exec("format", "Y-m-d");
    ASSERT_STREQ(_date.toCString(), g_date);
}

TEST(exec, redis) {
    Redis redis {};
    Array context{};
    auto ref_context = context.toReference();
    auto rv = redis.connect("127.0.0.1", 6379, 2.5, null, 0, 0, ref_context);
    ASSERT_TRUE(rv.toBool());
    auto val = "hello phpx";
    auto key = "phpx_test_key";
    redis.set(key, val);
    auto val2 = redis.get({key});

    ASSERT_STREQ(val2.toCString(), val);
}

TEST(exec, array_push) {
    Array arr;
    auto ref = arr.toReference();
    array_push(ref, "php", "java", "go");
    auto v1 = ref.referenceTo();
    ASSERT_EQ(v1.length(), 3);

    array_push(ref, "c++", "rust", "erlang", "node.js");
    auto v2 = ref.referenceTo();
    ASSERT_EQ(v2.length(), 7);

    array_push(ref, "python", "ruby", "lua", "perl", "vue");
    auto v3 = ref.referenceTo();
    ASSERT_EQ(v3.length(), 12);
}

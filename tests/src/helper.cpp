#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

TEST(helper, empty_str_to_int) {
    auto i = php::toInt("");
    ASSERT_EQ(i, 0);
}

TEST(helper, type_error_slow_paths) {
    try_call(
        []() { throwArgumentTypeError(123, "Demo::run", 2, "value", "string"); },
        "Demo::run(): Argument #2 ($value) must be of type string, int given");
    try_call(
        []() { throwReturnTypeError(false, "Demo::run", "int", true); },
        "Demo::run(): Return value must be of type int, bool returned");
    try_call(
        []() { throwReturnTypeError(false, "{closure}", "int|string", false); },
        "{closure}(): Return value must be of type int|string, bool given");
}

TEST(helper, exact_call_argument_conversions) {
    ASSERT_EQ(toIntArgExact(42, "Demo::run", 1, "value"), 42);
    ASSERT_DOUBLE_EQ(toFloatArgExact(1.5, "Demo::run", 1, "value"), 1.5);
    ASSERT_DOUBLE_EQ(toFloatArgExact(42, "Demo::run", 1, "value"), 42.0);
    ASSERT_TRUE(toBoolArgExact(true, "Demo::run", 1, "value"));
    ASSERT_EQ(toStringArgExact("value", "Demo::run", 1, "value").toStdString(), "value");

    try_call(
        []() { (void) toIntArgExact("42", "Demo::run", 1, "value"); },
        "Demo::run(): Argument #1 ($value) must be of type int, string given");
    try_call(
        []() { (void) toFloatArgExact("1.5", "Demo::run", 1, "value"); },
        "Demo::run(): Argument #1 ($value) must be of type float, string given");
    try_call(
        []() { (void) toBoolArgExact(1, "Demo::run", 1, "value"); },
        "Demo::run(): Argument #1 ($value) must be of type bool, int given");
    try_call(
        []() { (void) toStringArgExact(42, "Demo::run", 1, "value"); },
        "Demo::run(): Argument #1 ($value) must be of type string, int given");
}

TEST(helper, toInt) {
    auto v = php::toSize("512k");
    ASSERT_EQ(v, 512 * 1024);

    ASSERT_EQ(php::toInt(true), 1);
    ASSERT_EQ(php::toInt(false), 0);

    ASSERT_EQ(php::toFloat(true), 1.0);
    ASSERT_EQ(php::toFloat(false), 0);
}

TEST(helper, toArray) {
    auto o = newObject("ArrayObject");
    o.offsetSet(null, 1987);
    o.offsetSet(null, 2026);
    o.offsetSet(2, 1999);

    auto a2 = toArray(o);
    ASSERT_EQ(a2.length(), 3);
}

TEST(helper, instanceOf) {
    var b = newObject("ArrayObject");
    ASSERT_FALSE(instanceOf(b, "NotExistsClass"));
    ASSERT_TRUE(instanceOf(b, "ArrayObject"));

    ASSERT_FALSE(instanceOf(null, "ArrayObject"));

    Object o;
    auto ce = getClassEntrySafe("ArrayObject");
    ASSERT_FALSE(instanceOf(o, ce));

    o = newObject("ArrayObject");
    ASSERT_TRUE(instanceOf(o, ce));
}

TEST(helper, same) {
    ASSERT_TRUE(php::same(2.0, static_cast<Int>(2L)));
    ASSERT_TRUE(php::same(static_cast<Int>(3L), 3.0));
}

TEST(helper, clone) {
    try_call([]() { clone(null); }, "Attempt to clone on null");
    var o1 = newObject("ArrayObject");
    o1.newItem() = "hello";

    var o2 = clone(o1);
    o1.newItem() = "world";

    ASSERT_EQ(o1.length(), 2);
    ASSERT_EQ(o2.length(), 1);
}

TEST(helper, getEmptyArrayRef) {
    auto ref = getEmptyArrayRef();
    ref.newItem() = "php";
    ref.newItem() = "java";
    ASSERT_EQ(ref.length(), 2);
}

#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(base, error) {
    error(E_WARNING, "php error: %s, ErrorCode: %d", "hello world", 1001);
}

TEST(base, constant) {
    auto c = constant("PHP_VERSION");
    ASSERT_TRUE(c.isString());
    ASSERT_GT(c.length(), 0);
    ASSERT_STREQ(c.toCString(), PHP_VERSION);
}

TEST(base, echo) {
    echo("php error: %s, ErrorCode: %d\n", "hello world", 1001);
}

TEST(base, define) {
    define("test_var1", PHP_VERSION);
    auto c = constant("test_var1");
    ASSERT_TRUE(c.isString());
    ASSERT_GT(c.length(), 0);
    ASSERT_STREQ(c.toCString(), PHP_VERSION);

    define("test_var2", PHP_VERSION_ID);
    c = constant("test_var2");
    ASSERT_TRUE(c.isInt());
    ASSERT_EQ(c.toInt(), PHP_VERSION_ID);

    Array array;
    array.set("PHP_MAJOR_VERSION", PHP_MAJOR_VERSION);
    array.set("PHP_MINOR_VERSION", PHP_MINOR_VERSION);
    define("test_var3", array);
    c = constant("test_var3");
    ASSERT_TRUE(c.isArray());
    ASSERT_EQ(c.length(), 2);

    Array arr2(c);
    ASSERT_EQ(arr2["PHP_MAJOR_VERSION"].toInt(), PHP_MAJOR_VERSION);
}

TEST(base, include) {
    std::string tmp_file = "/tmp/include_test.php";
    std::string tmp_file2 = "/tmp/tmp_file.txt";

    file_put_contents(tmp_file, "<?php file_put_contents('" + tmp_file2 + "', 'hello phpx'); return PHP_VERSION_ID; ?>");
    auto retval = include(tmp_file);
    ASSERT_TRUE(retval.isInt());
    ASSERT_EQ(retval.toInt(), PHP_VERSION_ID);
}

TEST(base, method) {
    auto obj = newObject("DateTimeImmutable");
    ASSERT_TRUE(obj.isObject());
    auto str = obj.exec("format", "Y-m-d H:i:s");
    ASSERT_TRUE(str.isString());
    ASSERT_GT(str.length(), 0);
}

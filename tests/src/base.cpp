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

TEST(base, ini_get) {
    auto v = ini_get("post_max_size");
    ASSERT_GE(v.length(), 2);
    ASSERT_GE(v.toInt(), 8);
}

TEST(base, global) {
    auto server = global("_SERVER");
    ASSERT_TRUE(server.isArray());
    Array array(server);
    ASSERT_TRUE(array.exists("SHELL"));

    auto time = array["REQUEST_TIME"];
    ASSERT_TRUE(time.isInt());
}

TEST(base, equals) {
    Variant v1((zend_long) UINT_MAX);
    auto v2 = random_int(1, 1000000);
    ASSERT_FALSE(v1.equals(v2));
    ASSERT_FALSE(v1.equals(v2, true));

    Variant v3 = std::to_string(UINT_MAX);
    ASSERT_TRUE(v3.equals(v1));
    ASSERT_FALSE(v3.equals(v1, true));
}

TEST(base, static_property) {
    include(get_include_dir() + "/library.php");
    ASSERT_EQ(Class::getStaticProperty("TestClass", "propInt").toInt(), 1990018900);
    ASSERT_STREQ(Class::getStaticProperty("TestClass", "propString").toCString(), "Hello, World!");
    ASSERT_TRUE(Class::setStaticProperty("TestClass", "propString", "phpx test"));
    ASSERT_STREQ(Class::getStaticProperty("TestClass", "propString").toCString(), "phpx test");
}

#if 0
TEST(base, exception) {
    zend_try {
        throwException("RuntimeException", "phpx exception test");
    }
    zend_catch {
        auto e = Object(getException());
        auto msg = e.exec("getMessage");
        ASSERT_TRUE(msg.isString());
        ASSERT_TRUE(str_contains(msg, "phpx exception test").isTrue());
    }
    zend_end_try();
}
#endif

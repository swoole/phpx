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

TEST(base, constant2) {
    define("IA", 6492);
    auto c = constant(nullptr, "IA");
    ASSERT_TRUE(c.isInt());
    ASSERT_EQ(c.toInt(), 6492);

    auto c2 = constant(nullptr, "XXTT1");
    ASSERT_TRUE(c2.isNull());

    auto ce = getClassEntry("DateTime");
    auto c3 = constant(ce, "XXTT2");
    ASSERT_TRUE(c3.isNull());

    try_call([]() { auto c4 = constant("XXTT3"); }, "Undefined constant \"XXTT3\"");
}

TEST(base, echo) {
    echo("php error: %s, ErrorCode: %d\n", "hello world", 1001);

    String s("hello world\n");
    echo(s);

    var b = 2026;
    echo(b);
    echo("\n");
    echo(1987L);
    echo("\n");
    echo(3.1415926);
    echo("\n");
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

TEST(base, include1) {
    std::string tmp_file = "/tmp/include_test.php";
    std::string tmp_file2 = "/tmp/tmp_file.txt";

    file_put_contents(tmp_file,
                      "<?php file_put_contents('" + tmp_file2 + "', 'hello phpx'); return PHP_VERSION_ID; ?>");
    auto retval = include(tmp_file);
    ASSERT_TRUE(retval.isInt());
    ASSERT_EQ(retval.toInt(), PHP_VERSION_ID);
}

TEST(base, include2) {
    auto version = include(get_include_dir() + "/../include/return_const.php", INCLUDE_ONCE);
    ASSERT_STREQ(version.toCString(), PHP_VERSION);

    auto rs1 = include(get_include_dir() + "/../include/return_const.php", INCLUDE_ONCE);
    ASSERT_TRUE(rs1.toBool());

    auto rs2 = include(get_include_dir() + "/../include/return_const.php", REQUIRE_ONCE);
    ASSERT_TRUE(rs2.toBool());

    auto rs3 = include(get_include_dir() + "/../include/not_exists.php", INCLUDE_ONCE);
    ASSERT_FALSE(rs3.toBool());
}

TEST(base, include3) {
    auto rs1 = include(get_include_dir() + "/../include/library.php", INCLUDE_ONCE);
    ASSERT_TRUE(rs1.isInt());
    ASSERT_EQ(rs1.toInt(), 1);

    auto rs2 = include(get_include_dir() + "/../include/library.php", INCLUDE_ONCE);
    ASSERT_TRUE(rs2.isTrue());
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

    auto v2 = global("global_var_not_exists");
    ASSERT_FALSE(v2.toBool());
}

TEST(base, global2) {
    var gv;
    initGlobal("_SERVER", gv);
    ASSERT_TRUE(gv.isArray());

    auto g = global("_SERVER");
    g.offsetSet("test", 1999);

    auto g2 = global("_SERVER");
    ASSERT_EQ(g2.offsetGet("test").toInt(), 1999);

    var a;
    initGlobal("a", a);
    a = 100;
    ASSERT_EQ(global("a").toInt(), 100);

    unsetGlobal("a");
    ASSERT_TRUE(global("a").isNull());

    unsetGlobal("_SERVER");
    ASSERT_TRUE(global("_SERVER").isNull());
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

TEST(base, eval) {
    ob_start();
    eval("print_r(PHP_VERSION);");
    auto rs = ob_get_clean();
    ASSERT_TRUE(rs.isString());
    ASSERT_TRUE(str_contains(rs, PHP_VERSION).toBool());
}

TEST(base, eval2) {
    var rs;
    try {
        rs = eval("$array = [1999, rand()]; throw new Exception('phpx error');");
    } catch (zend_object *ex) {
        ASSERT_TRUE(rs.isNull());
        auto e = catchException();
        auto msg = e.exec("getMessage");
        ASSERT_STREQ(msg.toCString(), "phpx error");
    }
}

TEST(base, exception) {
    bool done = false;

    try {
        auto e = newObject("RuntimeException", "phpx exception test", 1999);
        throwException(e);
    } catch (zend_object *ex) {
        auto e = catchException();
        ASSERT_TRUE(e.getClassName().equals("RuntimeException"));
        auto msg = e.exec("getMessage");

        ASSERT_TRUE(msg.isString());
        ASSERT_TRUE(str_contains(msg, "phpx exception test").isTrue());
        done = true;
    }

    ASSERT_TRUE(done);
}

TEST(base, exception2) {
    auto e = catchException();
    ASSERT_TRUE(e.isNull());
}

TEST(base, atoi) {
    auto i = php::atoi("hello");
    ASSERT_EQ(i, 0);
}

TEST(base, concat) {
    var a("hello");
    var b("world");
    var c = concat(a, b);
    ASSERT_STREQ(c.toCString(), "helloworld");

    var d = concat({a, " ", b, "\n"});
    ASSERT_STREQ(d.toCString(), "hello world\n");

    var e = concat({});
    ASSERT_TRUE(e.isNull());
}

TEST(base, compare) {
    var a("hello");
    var b("world");
    ASSERT_FALSE(equals(a, b));

    var c("hello");
    ASSERT_TRUE(equals(a, c));

    ASSERT_EQ(compare(1, 1), 0);
    ASSERT_EQ(compare(1, 2), -1);
    ASSERT_EQ(compare(2, 1), 1);

    ASSERT_EQ(compare(1.5, 1.5), 0);
    ASSERT_EQ(compare(1.5, 2.5), -1);
    ASSERT_EQ(compare(2.5, 1.5), 1);

    ASSERT_EQ(compare("a", "a"), 0);
    ASSERT_EQ(compare("a", "b"), -1);
    ASSERT_EQ(compare("b", "a"), 1);
}

TEST(base, exit) {
    int count = 1;
    try {
        ::usleep(100000);
        php::exit(250);
    } catch (zend_object *ex) {
        count++;
        auto e = catchException();
        ASSERT_TRUE(zend_is_graceful_exit(e.object()));
    }
    ASSERT_EQ(EG(exit_status), 250);
    ASSERT_EQ(count, 2);
}

TEST(base, exit2) {
    int count = 1;
    try {
        ::usleep(100000);
        php::exit("hello world\n");
    } catch (zend_object *ex) {
        count++;
        auto e = catchException();
        ASSERT_TRUE(zend_is_graceful_exit(e.object()));
    }
    ASSERT_EQ(EG(exit_status), 0);
    ASSERT_EQ(count, 2);
}

TEST(base, getInternalException) {
    auto ce1 = php::getClassEntry("Iterator");
    ASSERT_NE(ce1, nullptr);
    ASSERT_STREQ(ce1->name->val, "Iterator");

    auto ce2 = php::getClassEntry("IteratorAggregate");
    ASSERT_NE(ce2, nullptr);
    ASSERT_STREQ(ce2->name->val, "IteratorAggregate");
}

TEST(base, call_bad_func) {
    try {
        call("func_not_exists");
    } catch (zend_object *ex) {
        auto e = catchException();
        auto msg = e.exec("getMessage");
        ASSERT_TRUE(str_contains(msg, "Invalid callback func_not_exists").toBool());
    }
}

TEST(base, getFunction) {
    auto fn1 = getFunction("var_dump");
    ASSERT_NE(fn1, nullptr);

    try_call([]() { auto fn2 = getFunction("func_not_exists"); }, "function 'func_not_exists' is undefined");

    auto fn3 = getFunction("DateTime::createFromFormat");
    ASSERT_NE(fn3, nullptr);
}

TEST(base, call) {
    auto fn1 = getFunction("php_uname");
    auto rt1 = call(fn1, {"m"});
    ASSERT_STREQ(rt1.toCString(), "x86_64");

    auto fn2 = getFunction("posix_getpid");
    auto rt2 = call(fn2);
    ASSERT_EQ(rt2.toInt(), getpid());
}

TEST(base, staticMethod1) {
    auto ce = getClassEntry("DateTime");
    auto fn = getMethod(ce, "createFromFormat");

    try_call([ce]() { auto fn2 = getMethod(ce, "methodNotExists"); },
             "method 'DateTime::methodNotExists' is undefined");

    auto o = call(ce, fn, {"j-M-Y", "15-Feb-2009"}).toObject();
    auto rs = o.exec("format", {"Y-m-d"});
    ASSERT_STREQ(rs.toCString(), "2009-02-15");
}

TEST(base, staticMethod2) {
    auto ce = getClassEntry("Phar");
    auto fn = getMethod(ce, "getSupportedCompression");
    auto arr = call(ce, fn).toArray();
    ASSERT_TRUE(in_array("GZ", arr));
}

TEST(base, hasStaticProperty) {
    // Include test library file
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    
    ASSERT_TRUE(hasStaticProperty("TestClass", "propInt"));
    ASSERT_TRUE(hasStaticProperty("TestClass", "propString"));
    
    ASSERT_FALSE(hasStaticProperty("TestClass", "nonExistentProp"));
    
    // Test non-existent class - should throw exception
    try_call(
        []() { 
            hasStaticProperty("NonExistentClass", "someProp"); 
        }, 
        "class 'NonExistentClass' is undefined."
    );
    
    // Test empty class name
    try_call(
        []() { 
            hasStaticProperty("", "someProp"); 
        }, 
        "class '' is undefined."
    );
    
    ASSERT_FALSE(hasStaticProperty("stdClass", "anyProp"));
    
    // DateTime has no static properties
    ASSERT_FALSE(hasStaticProperty("DateTime", "ATOM"));
    ASSERT_FALSE(hasStaticProperty("DateTime", "NONEXISTENT_CONSTANT"));
}

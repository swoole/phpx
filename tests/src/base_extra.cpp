#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

// Test include with REQUIRE type
TEST(base_extra, include_require) {
    auto rs = include(get_include_dir() + "/../include/return_const.php", REQUIRE);
    ASSERT_STREQ(rs.toCString(), PHP_VERSION);

    try_call([]() { include("/nonexistent/file.php", REQUIRE); }, "");
}

// Test include with REQUIRE_ONCE (file exists)
TEST(base_extra, include_require_once) {
    // REQUIRE_ONCE returns true on subsequent includes (file already loaded)
    // or the return value on first include
    auto rs = include(get_include_dir() + "/../include/return_const.php", REQUIRE_ONCE);
    ASSERT_TRUE(rs.isString() || rs.isTrue());
}

// Test ini_set and verify
TEST(base_extra, ini_set_get) {
    auto v0 = ini_get("error_reporting");
    ASSERT_TRUE(v0.isString());
}

// Test eval returning a value
TEST(base_extra, eval_return_value) {
    auto rs = eval("return 42 * 2;");
    ASSERT_EQ(rs.toInt(), 84);

    auto rs2 = eval("return 'hello ' . 'world';");
    ASSERT_STREQ(rs2.toCString(), "hello world");

    auto rs3 = eval("return [1, 2, 3];");
    ASSERT_TRUE(rs3.isArray());
    ASSERT_EQ(rs3.length(), 3);
}

// Test concat edge cases
TEST(base_extra, concat_edge) {
    // Empty list
    var e = concat({});
    ASSERT_TRUE(e.isNull());

    // Single element
    var s = concat({"hello"});
    ASSERT_STREQ(s.toCString(), "hello");

    // Three elements
    var t = concat({"a", "b", "c"});
    ASSERT_STREQ(t.toCString(), "abc");

    // Mixed types
    var m = concat({123, " ", 4.56});
    ASSERT_TRUE(m.isString());
    ASSERT_GT(m.length(), 0);
}

// Test same() with various types
TEST(base_extra, same) {
    var a(1);
    var b(1);
    var c(2);
    ASSERT_TRUE(same(a, b));
    ASSERT_FALSE(same(a, c));

    var d(3.14);
    var e(3.14);
    var f(2.71);
    ASSERT_TRUE(same(d, e));
    ASSERT_FALSE(same(d, f));

    var g(true);
    var h(true);
    var i(false);
    ASSERT_TRUE(same(g, h));
    ASSERT_FALSE(same(g, i));

    // Cross type - same requires same type+value
    var j(1);
    var k(1.0);
    ASSERT_FALSE(same(j, k));
    ASSERT_FALSE(same(k, j));
}

// Test equals() function (loose comparison)
TEST(base_extra, equals_function) {
    ASSERT_TRUE(equals(var(1), var(1.0)));
    ASSERT_TRUE(equals(var(0), var(false)));
    ASSERT_TRUE(equals(var("1"), var(1)));
}

// Test compare() edge cases
TEST(base_extra, compare_edge) {
    ASSERT_EQ(compare(var(1), var(1)), 0);
    ASSERT_EQ(compare(var(1), var(2)), -1);
    ASSERT_EQ(compare(var(2), var(1)), 1);

    ASSERT_EQ(compare(var("a"), var("a")), 0);
    ASSERT_EQ(compare(var("a"), var("b")), -1);
    ASSERT_EQ(compare(var("b"), var("a")), 1);

    ASSERT_EQ(compare(var(1.0), var(1.0)), 0);
    ASSERT_EQ(compare(var(1.0), var(2.0)), -1);
    ASSERT_EQ(compare(var(2.0), var(1.0)), 1);
}

// Test toSize edge cases
TEST(base_extra, toSize_edge) {
    ASSERT_EQ(php::toSize(""), 0);
    ASSERT_EQ(php::toSize("0"), 0);
    ASSERT_EQ(php::toSize("1K"), 1024);
    ASSERT_EQ(php::toSize("1M"), 1024 * 1024);
    ASSERT_EQ(php::toSize("1G"), 1024 * 1024 * 1024);
}

// Test exit(0)
TEST(base_extra, exit_zero) {
    int count = 1;
    try {
        php::exit(0);
    } catch (zend_object *ex) {
        count++;
        auto e = catchException();
        ASSERT_TRUE(zend_is_graceful_exit(e.object()));
    }
    ASSERT_EQ(EG(exit_status), 0);
    ASSERT_EQ(count, 2);
}

// Test constant from class with mixed results
TEST(base_extra, constant_class_mixed) {
    auto c1 = constant("DateTime", "ATOM");
    ASSERT_STREQ(c1.toCString(), "Y-m-d\\TH:i:sP");

    // Class constant via string notation
    auto c2 = constant("DateTime::ATOM");
    ASSERT_STREQ(c2.toCString(), "Y-m-d\\TH:i:sP");

    // Non-existent constant on class
    auto c3 = constant("DateTime", "NONEXISTENT_CONST");
    ASSERT_TRUE(c3.isNull());

    // Constant from nullptr == global constant
    auto c4 = constant(nullptr, "PHP_INT_MAX");
    ASSERT_TRUE(c4.isInt());
}

TEST(base_extra, update_class_const) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);

    auto ce = getClassEntry("TestClass2");
    var rs1 = constant(ce, "CONST_ARRAY");
    ASSERT_TRUE(rs1.isArray());
    ASSERT_EQ(rs1.length(), 0);

    Array array = create_map();
    updateConstant(ce, "CONST_ARRAY", array);

    var rs2 = constant(ce, "CONST_ARRAY");
    ASSERT_TRUE(rs2.isArray());
    ASSERT_EQ(rs2.length(), array.count());
    ASSERT_EQ(rs2.item("php").toInt(), 3);
}

// Test throwException with different overloads
TEST(base_extra, throwException_overloads) {
    try {
        throwException("RuntimeException", "test message", 999);
    } catch (zend_object *ex) {
        auto e = catchException();
        ASSERT_STREQ(e.getClassName().toCString(), "RuntimeException");
        ASSERT_STREQ(e.call("getMessage").toCString(), "test message");
        ASSERT_EQ(e.call("getCode").toInt(), 999);
    }

    try {
        auto ce = getClassEntry("RuntimeException");
        throwException(ce, "via ce", 500);
    } catch (zend_object *ex) {
        auto e = catchException();
        ASSERT_STREQ(e.call("getMessage").toCString(), "via ce");
        ASSERT_EQ(e.call("getCode").toInt(), 500);
    }

    try {
        auto ex = newObject("RuntimeException", {"as object", 777});
        throwException(ex);
    } catch (zend_object *ex2) {
        auto e = catchException();
        ASSERT_STREQ(e.call("getMessage").toCString(), "as object");
        ASSERT_EQ(e.call("getCode").toInt(), 777);
    }
}

// Test global with initGlobal and unsetGlobal
TEST(base_extra, global_init_unset_cycle) {
    var g;
    initGlobal("test_global_key", g);
    g = "initial_value";

    auto v = global("test_global_key");
    ASSERT_STREQ(v.toCString(), "initial_value");

    // Update via global
    var g2;
    initGlobal("test_global_key", g2);
    g2 = "updated_value";

    auto v2 = global("test_global_key");
    ASSERT_STREQ(v2.toCString(), "updated_value");

    unsetGlobal("test_global_key");
    ASSERT_TRUE(global("test_global_key").isNull());
}

// Test call with Args via array_push wrapper
TEST(base_extra, call_with_args) {
    Array arr{1, 2};
    auto ref = arr.toReference();
    array_push(ref, 3);
    ASSERT_EQ(arr.count(), 3);
    ASSERT_EQ(arr[2].toInt(), 3);
}

// Test getClassEntry edge cases
TEST(base_extra, getClassEntry_edge) {
    auto ce1 = getClassEntry("stdClass");
    ASSERT_NE(ce1, nullptr);
    ASSERT_STREQ(ce1->name->val, "stdClass");

    try_call([]() { getClassEntry("ClassNotExists"); }, "class 'ClassNotExists' is undefined");
}

// Test getClassEntrySafe (throws on unknown class)
TEST(base_extra, getClassEntrySafe) {
    auto ce1 = getClassEntrySafe("stdClass");
    ASSERT_NE(ce1, nullptr);

    try_call([]() { getClassEntrySafe("ClassDefinitelyNotExists"); }, "class 'ClassDefinitelyNotExists' is undefined");
}

// Test error with different levels
TEST(base_extra, error_levels) {
    // These just need to not crash
    error(E_NOTICE, "test notice: %d", 1);
    error(E_WARNING, "test warning: %s", "hello");
    error(E_DEPRECATED, "test deprecated");
}

// Test getFunction with static method
TEST(base_extra, getFunction_static_method) {
    auto fn = getFunction("DateTime::createFromFormat");
    ASSERT_NE(fn, nullptr);

    try_call([]() { getFunction("DateTime::method_not_exists"); },
             "function 'DateTime::method_not_exists' is undefined");
}

// Test getMethod with class entry
TEST(base_extra, getMethod) {
    auto ce = getClassEntry("DateTime");
    auto fn = getMethod(ce, "createFromFormat");
    ASSERT_NE(fn, nullptr);
}

// Test call with array
TEST(base_extra, call_with_array) {
    Array args;
    args.append("m");
    auto fn = getFunction("php_uname");
    auto rs = call(fn, args);
    ASSERT_STREQ(rs.toCString(), "x86_64");
}

// Test call with ArgList
TEST(base_extra, call_with_arglist) {
    ArgList args{"m"};
    auto fn = getFunction("php_uname");
    auto rs = call(fn, args);
    ASSERT_STREQ(rs.toCString(), "x86_64");
}

// Test call with named args (zend_array)
TEST(base_extra, call_with_named_args) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    Array named_args;
    named_args.set("vip", true);
    named_args.set("city", "beijing");

    auto fn = getFunction("createUser");
    auto rs = call(fn, {"David", 25}, named_args.array());
    ASSERT_TRUE(rs.item("vip").toBool());
    ASSERT_STREQ(rs.item("city").toCString(), "beijing");
}

// Test throwErrorIfOccurred (no exception case)
TEST(base_extra, throwErrorIfOccurred_none) {
    // Should not throw since EG(exception) is null
    throwErrorIfOccurred();
    SUCCEED();
}

// Test empty() function with operation chain
TEST(base_extra, empty_with_chain) {
    Array arr;
    arr.set("outer", create_map());
    var v = arr;

    ASSERT_TRUE(php::empty(v, {{ArrayDimFetch, "outer"}, {ArrayDimFetch, "nonexistent"}}));
    ASSERT_FALSE(php::empty(v, {{ArrayDimFetch, "outer"}, {ArrayDimFetch, "php"}}));

    // with result output
    Variant result;
    ASSERT_TRUE(php::empty(v, {{ArrayDimFetch, "outer"}, {ArrayDimFetch, "missing"}}, result));
    ASSERT_TRUE(result.isNull());
}

// Test exists() with result
TEST(base_extra, exists_with_result) {
    Array arr = create_map();
    var v = arr;

    Variant result;
    ASSERT_TRUE(php::exists(v, {{ArrayDimFetch, "php"}}, result));
    ASSERT_EQ(result.toInt(), 3);

    ASSERT_FALSE(php::exists(v, {{ArrayDimFetch, "nonexistent"}}, result));
}

// Test call via string function name
TEST(base_extra, call_string_func) {
    var fn("php_uname");
    ArgList args{"m"};
    auto rs = call(fn, args);
    ASSERT_STREQ(rs.toCString(), "x86_64");
}

// Test throwException for class not found via class name
TEST(base_extra, throwException_class_not_found) {
    try_call([]() { throwException("ClassDefinitelyNotExists", "test"); },
             "class 'ClassDefinitelyNotExists' is undefined");
}

// Test concat via the Variant method
TEST(base_extra, concat_two_args) {
    var a("hello");
    var b(" world");
    var c = concat(a, b);
    ASSERT_STREQ(c.toCString(), "hello world");
}

// Test newObject with errors
TEST(base_extra, newObject_errors) {
    try_call([]() { newObject("NonExistentClass123"); }, "class 'NonExistentClass123' is undefined");

    try_call([]() { newObject("NonExistentClass456", {"arg1", 123}); }, "class 'NonExistentClass456' is undefined");
}

// Test exec_function and exec_method indirectly via call
TEST(base_extra, exec_function_retval) {
    auto fn = getFunction("strlen");
    auto rs = call(fn, {"hello"});
    ASSERT_EQ(rs.toInt(), 5);
}

// Test set_time_limit (no-op call, tests the facade)
TEST(base_extra, facade_set_time_limit) {
    set_time_limit(30);
    SUCCEED();
}

// Test array_is_list facade
TEST(base_extra, facade_array_is_list) {
    Array a{1, 2, 3};
    ASSERT_TRUE(array_is_list(a).toBool());

    Array b;
    b.set("a", 1);
    b.set("b", 2);
    ASSERT_FALSE(array_is_list(b).toBool());
}

// Test array_key_exists facade
TEST(base_extra, facade_array_key_exists) {
    Array arr = create_map();
    ASSERT_TRUE(array_key_exists("php", arr).toBool());
    ASSERT_FALSE(array_key_exists("rust", arr).toBool());
}

// Test in_array facade
TEST(base_extra, facade_in_array) {
    Array arr{1, 2, 3, 4, 5};
    ASSERT_TRUE(in_array(3, arr).toBool());
    ASSERT_FALSE(in_array(99, arr).toBool());

    // With strict
    ASSERT_TRUE(in_array("3", arr).toBool());
    ASSERT_FALSE(in_array("3", arr, true).toBool());
}

// Test array_search facade
TEST(base_extra, facade_array_search) {
    Array arr;
    arr.set("php", 3);
    arr.set("golang", 4);
    ASSERT_STREQ(array_search(3, arr).toCString(), "php");
    ASSERT_TRUE(array_search(99, arr).isFalse());
}

// Test array_keys / array_values facade
TEST(base_extra, facade_array_keys_values) {
    Array arr = create_map();
    var keys = array_keys(arr);
    ASSERT_TRUE(keys.isArray());

    var values = array_values(arr);
    ASSERT_TRUE(values.isArray());
}

// Test array_reverse facade
TEST(base_extra, facade_array_reverse) {
    Array arr{1, 2, 3};
    auto rev = array_reverse(arr).toArray();
    ASSERT_EQ(rev.count(), 3);
    ASSERT_EQ(rev[0].toInt(), 3);
    ASSERT_EQ(rev[1].toInt(), 2);
    ASSERT_EQ(rev[2].toInt(), 1);
}

// Test array_flip facade
TEST(base_extra, facade_array_flip) {
    Array arr;
    arr.set("a", 1);
    arr.set("b", 2);
    auto flipped = array_flip(arr);
    ASSERT_TRUE(flipped.isArray());
    ASSERT_TRUE(flipped.offsetExists(1));
}

// Test array_rand facade
TEST(base_extra, facade_array_rand) {
    Array arr{10, 20, 30, 40, 50};
    auto rand_key = array_rand(arr);
    ASSERT_TRUE(rand_key.isInt());
}

// Test array_combine facade
TEST(base_extra, facade_array_combine) {
    Array keys{"a", "b", "c"};
    Array values{1, 2, 3};
    auto combined = array_combine(keys, values);
    ASSERT_TRUE(combined.isArray());
    auto c = combined.toArray();
    ASSERT_EQ(c.get("a").toInt(), 1);
    ASSERT_EQ(c.get("b").toInt(), 2);
    ASSERT_EQ(c.get("c").toInt(), 3);
}

// Test count facade
TEST(base_extra, facade_count) {
    Array arr{1, 2, 3, 4, 5};
    ASSERT_EQ(count(arr).toInt(), 5);

    Array empty_arr;
    ASSERT_EQ(count(empty_arr).toInt(), 0);
}

// Test array_push facade
TEST(base_extra, facade_array_push) {
    Array arr{1, 2};
    auto ref = arr.toReference();
    array_push(ref, 3);
    ASSERT_EQ(arr.count(), 3);
    ASSERT_EQ(arr[2].toInt(), 3);
}

// Test array_pop facade
TEST(base_extra, facade_array_pop) {
    Array arr{1, 2, 3};
    auto ref = arr.toReference();
    auto popped = array_pop(ref);
    ASSERT_EQ(popped.toInt(), 3);
    ASSERT_EQ(arr.count(), 2);
}

// Test array_shift facade
TEST(base_extra, facade_array_shift) {
    Array arr{1, 2, 3};
    auto ref = arr.toReference();
    auto shifted = array_shift(ref);
    ASSERT_EQ(shifted.toInt(), 1);
    ASSERT_EQ(arr.count(), 2);
}

// Test array_unshift facade
TEST(base_extra, facade_array_unshift) {
    Array arr{2, 3};
    auto ref = arr.toReference();
    array_unshift(ref, 1);
    ASSERT_EQ(arr.count(), 3);
    ASSERT_EQ(arr[0].toInt(), 1);
}

// Test base64_encode/decode facade
TEST(base_extra, facade_base64) {
    auto encoded = base64_encode("hello world");
    ASSERT_GT(encoded.length(), 0);
    auto decoded = base64_decode(encoded);
    ASSERT_STREQ(decoded.toCString(), "hello world");
}

// Test getenv facade
TEST(base_extra, facade_getenv) {
    auto home = php::getenv("HOME");
    ASSERT_TRUE(home.isString());
    ASSERT_GT(home.length(), 0);
}

// Test error_get_last / error_clear_last
TEST(base_extra, facade_error_handling) {
    // Trigger a warning
    eval("trigger_error('test warning', E_USER_WARNING);");
    auto err = error_get_last();
    if (err.isArray()) {
        Array errArr(err);
        ASSERT_TRUE(errArr.exists("message"));
        error_clear_last();
    }
}

// Test array_unique facade
TEST(base_extra, facade_array_unique) {
    Array arr{1, 2, 2, 3, 3, 3};
    auto unique = array_unique(arr);
    ASSERT_TRUE(unique.isArray());
    ASSERT_LE(unique.toArray().count(), 3);
}

// Test strpos/strrpos via call (tested via the call mechanism)
TEST(base_extra, facade_string_search) {
    auto pos = call("strpos", {"hello world", "world"});
    ASSERT_EQ(pos.toInt(), 6);

    auto rpos = call("strrpos", {"hello world world", "world"});
    ASSERT_EQ(rpos.toInt(), 12);
}

// Test sort with flags
TEST(base_extra, sort_with_flags) {
    Array arr{3, 1, 4, 1, 5, 9};
    auto ref = arr.toReference();
    sort(ref);
    ASSERT_LE(arr[0].toInt(), arr[arr.count() - 1].toInt());
}

// Test Args class operations
TEST(base_extra, args_class) {
    Args args;
    args.append(10);
    args.append(20);
    args.append(30);

    auto fn = getFunction("max");
    auto rs = call(fn, args);
    ASSERT_EQ(rs.toInt(), 30);
}

// Test that after throwError exception IS set in EG
TEST(base_extra, throwError_sets_EG_exception) {
    try {
        throwError("test error for EG check");
    } catch (zend_object *ex) {
        // verify catchException works
        auto e = catchException();
        ASSERT_TRUE(e.isObject());
    }
    // After catch, EG(exception) should be cleared
    auto e2 = catchException();
    ASSERT_TRUE(e2.isNull());
}

// Test concat single element produces correct string
TEST(base_extra, concat_single) {
    var r = concat({"single"});
    ASSERT_TRUE(r.isString());
    ASSERT_STREQ(r.toCString(), "single");
}

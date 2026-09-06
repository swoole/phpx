#include "phpx_test.h"
#include "phpx_std.h"

using namespace php;

TEST(std_core, function_exists) {
    ASSERT_TRUE(fn::function_exists("php_uname"));
    ASSERT_FALSE(fn::function_exists("func_not_exists"));
    ASSERT_TRUE(fn::function_exists("php_uname", true));
    ASSERT_TRUE(fn::function_exists("\\php_uname"));
    ASSERT_TRUE(fn::function_exists("PHP_UNAME"));
}

TEST(std_core, strcmp) {
    ASSERT_EQ(fn::strcmp("hello", "hello"), 0);
    ASSERT_EQ(fn::strcmp("abc", "abd"), -1);
    ASSERT_EQ(fn::strcmp("abd", "abc"), 1);
    ASSERT_GT(fn::strcmp("z", "a"), 0);
    ASSERT_LT(fn::strcmp("a", "z"), 0);
}

TEST(std_core, strcasecmp) {
    ASSERT_EQ(fn::strcasecmp("hello", "HELLO"), 0);
    ASSERT_EQ(fn::strcasecmp("Hello", "hello"), 0);
    ASSERT_GT(fn::strcasecmp("B", "a"), 0);
}

TEST(std_core, strncmp) {
    ASSERT_EQ(fn::strncmp("abcdef", "abcxyz", 3), 0);
    ASSERT_LT(fn::strncmp("abcdef", "abcxyz", 4), 0);
    ASSERT_EQ(fn::strncmp("abc", "abd", 2), 0);
}

TEST(std_core, strncmp_exception) {
    try_call([]() { fn::strncmp("a", "b", -1); },
             "strncmp(): Argument #3 ($length) must be greater than or equal to 0");
}

TEST(std_core, strncasecmp) {
    ASSERT_EQ(fn::strncasecmp("ABCDEF", "abcxyz", 3), 0);
    ASSERT_LT(fn::strncasecmp("ABCDEF", "abcxyz", 4), 0);
}

TEST(std_core, strncasecmp_exception) {
    try_call([]() { fn::strncasecmp("a", "b", -1); },
             "strncasecmp(): Argument #3 ($length) must be greater than or equal to 0");
}

TEST(std_core, class_exists) {
    ASSERT_TRUE(fn::class_exists("ArrayObject"));
    ASSERT_TRUE(fn::class_exists("stdClass"));
    ASSERT_FALSE(fn::class_exists("ClassThatDoesNotExist"));
    ASSERT_FALSE(fn::class_exists("ClassThatDoesNotExist", false));
    ASSERT_TRUE(fn::class_exists("\\ArrayObject", false));

    zend_string *interned = zend_string_init_interned(ZEND_STRL("ArrayObject"), false);
    String cached_name(interned, Ctor::Move);
    ASSERT_TRUE(fn::class_exists(cached_name));
    ASSERT_TRUE(fn::class_exists(cached_name));
}

TEST(std_core, interface_exists) {
    ASSERT_TRUE(fn::interface_exists("Countable"));
    ASSERT_TRUE(fn::interface_exists("Iterator"));
    ASSERT_FALSE(fn::interface_exists("InterfaceThatDoesNotExist"));
}

TEST(std_core, trait_exists) {
    ASSERT_FALSE(fn::trait_exists("ArrayObject"));
    ASSERT_FALSE(fn::trait_exists("TraitThatDoesNotExist"));
}

TEST(std_core, method_exists) {
    var obj = newObject("ArrayObject");
    ASSERT_TRUE(fn::method_exists(obj, "count"));
    ASSERT_TRUE(fn::method_exists(obj, "offsetSet"));
    ASSERT_FALSE(fn::method_exists(obj, "nonexistentMethod"));

    eval(R"PHP(
        class PhpxStdMethodProbe {
            private function hidden(): void {}
            public function __call(string $name, array $args): mixed { return null; }
        }
    )PHP");
    ASSERT_TRUE(fn::method_exists("PhpxStdMethodProbe", "hidden"));
    ASSERT_FALSE(fn::method_exists("MissingPhpxStdClass", "hidden"));
    Object magic = newObject("PhpxStdMethodProbe");
    ASSERT_FALSE(fn::method_exists(magic, "dynamicMethod"));

    Variant closure = eval("return static fn() => null;");
    ASSERT_TRUE(fn::method_exists(closure, "__invoke"));
    ASSERT_TRUE(fn::method_exists("Closure", "__invoke"));
    try_call([]() { fn::method_exists(42, "method"); }, "must be of type object|string");
}

TEST(std_core, property_exists) {
    Object obj = newObject("stdClass");
    obj.setProperty("foo", "bar");
    ASSERT_TRUE(fn::property_exists(obj, "foo"));
    ASSERT_FALSE(fn::property_exists(obj, "baz"));
    ASSERT_TRUE(fn::property_exists("Exception", "message"));
    ASSERT_FALSE(fn::property_exists("MissingPhpxStdClass", "message"));
    try_call([]() { fn::property_exists(42, "value"); }, "must be of type object|string");
}

TEST(std_core, is_a) {
    var obj = newObject("ArrayObject");
    ASSERT_TRUE(fn::is_a(obj, "ArrayObject"));
    ASSERT_TRUE(fn::is_a(obj, "IteratorAggregate"));
    ASSERT_FALSE(fn::is_a(obj, "stdClass"));
    ASSERT_TRUE(fn::is_a("ArrayObject", "ArrayObject", true));
    ASSERT_FALSE(fn::is_a("MissingPhpxStdClass", "ArrayObject", true));
    ASSERT_FALSE(fn::is_a(42, "ArrayObject"));
    ASSERT_FALSE(fn::is_a(obj, "MissingPhpxStdClass"));
}

TEST(std_core, is_subclass_of) {
    // A class is not a subclass of itself
    ASSERT_FALSE(fn::is_subclass_of("ArrayObject", "ArrayObject"));
    ASSERT_FALSE(fn::is_subclass_of("stdClass", "ArrayObject"));
    Object runtime = newObject("RuntimeException");
    ASSERT_TRUE(fn::is_subclass_of(runtime, "Exception"));
    ASSERT_FALSE(fn::is_subclass_of(42, "Exception"));
    ASSERT_FALSE(fn::is_subclass_of("MissingPhpxStdClass", "Exception", true));
    ASSERT_FALSE(fn::is_subclass_of(runtime, "MissingPhpxStdClass"));
}

TEST(std_core, defined) {
    ASSERT_TRUE(fn::defined("PHP_VERSION"));
    ASSERT_TRUE(fn::defined("PHP_INT_MAX"));
    ASSERT_FALSE(fn::defined("NOT_A_REAL_CONSTANT"));
}

TEST(std_core, spl_object_identity) {
    Object first = newObject("stdClass");
    Object second = newObject("stdClass");

    ASSERT_EQ(fn::spl_object_id(first), static_cast<Int>(first.object()->handle));
    ASSERT_NE(fn::spl_object_id(first), fn::spl_object_id(second));
    ASSERT_TRUE(fn::spl_object_hash(first).equals(first.hash()));

    try_call([]() { (void) fn::spl_object_id(42); },
             "spl_object_id(): Argument #1 ($object) must be of type object, int given");
    try_call([]() { (void) fn::spl_object_hash("not an object"); },
             "spl_object_hash(): Argument #1 ($object) must be of type object, string given");
}

TEST(std_core, iterator_array_fast_paths) {
    Array input;
    input.set("name", "phpx");
    input.set(4, 42);

    ASSERT_EQ(fn::iterator_count(input), 2);

    Array preserved = fn::iterator_to_array(input);
    ASSERT_STREQ(preserved.get("name").toCString(), "phpx");
    ASSERT_EQ(preserved.get(4).toInt(), 42);

    Array values = fn::iterator_to_array(input, false);
    ASSERT_STREQ(values.get(0).toCString(), "phpx");
    ASSERT_EQ(values.get(1).toInt(), 42);
}

TEST(std_core, iterator_object_fast_paths) {
    Variant keyed = eval("return (function () { yield 'name' => 'phpx'; yield 4 => 42; })();");
    Array preserved = fn::iterator_to_array(keyed);
    ASSERT_STREQ(preserved.get("name").toCString(), "phpx");
    ASSERT_EQ(preserved.get(4).toInt(), 42);

    Variant values_only = eval("return (function () { yield 'name' => 'phpx'; yield 4 => 42; })();");
    Array values = fn::iterator_to_array(values_only, false);
    ASSERT_STREQ(values.get(0).toCString(), "phpx");
    ASSERT_EQ(values.get(1).toInt(), 42);

    Variant counted = eval("return (function () { yield 1; yield 2; yield 3; })();");
    ASSERT_EQ(fn::iterator_count(counted), 3);
}

TEST(std_core, iterator_helpers_validate_and_propagate_errors) {
    try_call([]() { (void) fn::iterator_count(42); },
             "iterator_count(): Argument #1 ($iterator) must be of type Traversable|array, int given");
    try_call([]() { (void) fn::iterator_to_array(nullptr); },
             "iterator_to_array(): Argument #1 ($iterator) must be of type Traversable|array, null given");

    Variant throwing = eval("return (function () { yield 1; throw new RuntimeException('iterator failed'); })();");
    try_call([&throwing]() { (void) fn::iterator_count(throwing); }, "iterator failed");
}

TEST(std_core, runtime_constant_lookup) {
    ASSERT_STREQ(fn::constant("PHP_VERSION").toCString(), PHP_VERSION);
    ASSERT_EQ(fn::constant("PHP_INT_MAX").toInt(), ZEND_LONG_MAX);
    try_call([]() { (void) fn::constant("PHPX_UNDEFINED_CONSTANT"); },
             "Undefined constant \"PHPX_UNDEFINED_CONSTANT\"");
}

TEST(std_core, define) {
    ASSERT_TRUE(fn::define("MY_TEST_CONSTANT_123", 42));
    ASSERT_TRUE(fn::defined("MY_TEST_CONSTANT_123"));
}

TEST(std_core, define_array) {
    // Simple array constant (exercises _validate_constant_array and _copy_constant_array)
    Array arr;
    arr.set(Variant(0), "a");
    arr.set(Variant(1), "b");
    ASSERT_TRUE(fn::define("MY_TEST_ARR_1", arr));
    ASSERT_TRUE(fn::defined("MY_TEST_ARR_1"));

    // Nested array constant
    Array nested;
    nested.set(Variant(0), arr);
    ASSERT_TRUE(fn::define("MY_TEST_ARR_2", nested));
    ASSERT_TRUE(fn::defined("MY_TEST_ARR_2"));

    Array empty;
    ASSERT_TRUE(fn::define("MY_TEST_EMPTY_ARR", empty));

    Array associative;
    associative.set("name", "phpx");
    ASSERT_TRUE(fn::define("MY_TEST_ASSOC_ARR", associative));
}

TEST(std_core, define_rejects_invalid_and_recursive_constants) {
    try_call(
        []() {
            fn::define("PhpxStdClass::VALUE", 1);
            throwErrorIfOccurred();
        },
        "cannot be a class constant");

    Variant recursive = eval("$value = []; $value['self'] =& $value; return $value;");
    try_call(
        [&recursive]() {
            fn::define("PHPX_RECURSIVE_CONSTANT", recursive);
            throwErrorIfOccurred();
        },
        "cannot be a recursive array");

    ASSERT_TRUE(fn::define("PHPX_CASE_WARNING_CONSTANT", 1, true));
    ASSERT_FALSE(fn::define("PHPX_CASE_WARNING_CONSTANT", 2));
}

TEST(std_core, gettype) {
    auto t1 = fn::gettype(42);
    ASSERT_STREQ(t1.toCString(), "integer");

    auto t2 = fn::gettype("hello");
    ASSERT_STREQ(t2.toCString(), "string");

    auto t3 = fn::gettype(3.14);
    ASSERT_STREQ(t3.toCString(), "double");

    auto t4 = fn::gettype(true);
    ASSERT_STREQ(t4.toCString(), "boolean");

    auto t5 = fn::gettype(Array{});
    ASSERT_STREQ(t5.toCString(), "array");
}

// Type checking functions
TEST(std_core, is_array) {
    ASSERT_TRUE(fn::is_array(Array{1, 2, 3}));
    ASSERT_FALSE(fn::is_array("not an array"));
    ASSERT_FALSE(fn::is_array(42));
}

TEST(std_core, is_string) {
    ASSERT_TRUE(fn::is_string("hello"));
    ASSERT_FALSE(fn::is_string(42));
    ASSERT_FALSE(fn::is_string(Array{}));
}

TEST(std_core, is_object) {
    var obj = newObject("stdClass");
    ASSERT_TRUE(fn::is_object(obj));
    ASSERT_FALSE(fn::is_object("not object"));
    ASSERT_FALSE(fn::is_object(Array{}));
}

TEST(std_core, is_int) {
    ASSERT_TRUE(fn::is_int(42));
    ASSERT_TRUE(fn::is_int(-100));
    ASSERT_FALSE(fn::is_int(3.14));
    ASSERT_FALSE(fn::is_int("42"));
}

TEST(std_core, is_bool) {
    ASSERT_TRUE(fn::is_bool(true));
    ASSERT_TRUE(fn::is_bool(false));
    ASSERT_FALSE(fn::is_bool(1));
    ASSERT_FALSE(fn::is_bool(0));
}

TEST(std_core, is_float) {
    ASSERT_TRUE(fn::is_float(3.14));
    ASSERT_TRUE(fn::is_float(-0.5));
    ASSERT_FALSE(fn::is_float(42));
    ASSERT_FALSE(fn::is_float("3.14"));
}

TEST(std_core, is_scalar) {
    ASSERT_TRUE(fn::is_scalar(42));
    ASSERT_TRUE(fn::is_scalar("hello"));
    ASSERT_TRUE(fn::is_scalar(3.14));
    ASSERT_TRUE(fn::is_scalar(true));
    ASSERT_FALSE(fn::is_scalar(Array{}));
    ASSERT_FALSE(fn::is_scalar(nullptr));
}

TEST(std_core, is_countable) {
    ASSERT_TRUE(fn::is_countable(Array{1, 2}));
    ASSERT_FALSE(fn::is_countable(42));
    auto obj = newObject("ArrayObject");
    ASSERT_TRUE(fn::is_countable(obj));
}

TEST(std_core, is_null) {
    ASSERT_TRUE(fn::is_null(nullptr));
    ASSERT_TRUE(fn::is_null(null));
    ASSERT_FALSE(fn::is_null(0));
    ASSERT_FALSE(fn::is_null(""));
    ASSERT_FALSE(fn::is_null(false));
}

TEST(std_core, is_iterable) {
    ASSERT_TRUE(fn::is_iterable(Array{1, 2}));
    ASSERT_FALSE(fn::is_iterable(42));
    auto obj = newObject("ArrayObject");
    ASSERT_TRUE(fn::is_iterable(obj));
}

TEST(std_core, is_numeric) {
    ASSERT_TRUE(fn::is_numeric(42));
    ASSERT_TRUE(fn::is_numeric(3.14));
    ASSERT_TRUE(fn::is_numeric("42"));
    ASSERT_TRUE(fn::is_numeric("3.14"));
    ASSERT_TRUE(fn::is_numeric("-10"));
    ASSERT_FALSE(fn::is_numeric("hello"));
    ASSERT_FALSE(fn::is_numeric(Array{}));
    ASSERT_FALSE(fn::is_numeric(true));
}

TEST(std_core, is_callable) {
    ASSERT_TRUE(fn::is_callable("php_uname"));
    ASSERT_FALSE(fn::is_callable("not_a_function"));
    ASSERT_TRUE(fn::is_callable("php_uname", true));
    // syntax_only=true only checks syntax; any valid function name passes
    ASSERT_TRUE(fn::is_callable("not_a_function", true));
}

TEST(std_core, get_class_fn) {
    Object obj = newObject("ArrayObject");
    auto cls = fn::get_class(obj);
    ASSERT_STREQ(cls.toCString(), "ArrayObject");
}

TEST(std_core, enum_exists) {
    // Non-enum classes
    ASSERT_FALSE(fn::enum_exists("ArrayObject"));
    ASSERT_FALSE(fn::enum_exists("stdClass"));
    // Non-existent name
    ASSERT_FALSE(fn::enum_exists("NoSuchEnum"));
    // Without autoload
    ASSERT_FALSE(fn::enum_exists("NoSuchEnum", false));
}

TEST(std_core, get_parent_class) {
    // String class name: class with parent
    auto parent1 = fn::get_parent_class("RuntimeException");
    ASSERT_TRUE(parent1.isString());
    ASSERT_STREQ(parent1.toString().toCString(), "Exception");

    // String class name: class without parent
    auto parent2 = fn::get_parent_class("Exception");
    ASSERT_TRUE(parent2.isFalse());

    // Object
    Object obj = newObject("RuntimeException");
    auto parent3 = fn::get_parent_class(obj);
    ASSERT_TRUE(parent3.isString());
    ASSERT_STREQ(parent3.toString().toCString(), "Exception");

    // Class without parent via string
    auto parent4 = fn::get_parent_class("stdClass");
    ASSERT_TRUE(parent4.isFalse());

    ASSERT_TRUE(fn::get_parent_class("MissingPhpxStdClass").isFalse());
    try_call([]() { fn::get_parent_class(42); }, "must be of type object|string");
}

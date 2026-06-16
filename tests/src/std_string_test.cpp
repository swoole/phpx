#include "phpx_test.h"
#include "phpx_std.h"

using namespace php;

TEST(std_string, ord) {
    ASSERT_EQ(fn::ord("A"), 65);
    ASSERT_EQ(fn::ord(""), 0);
    ASSERT_EQ(fn::ord("hello"), 104); // 'h' = 104
}

TEST(std_string, chr) {
    auto s1 = fn::chr(65);
    ASSERT_EQ(s1.length(), 1);
    ASSERT_STREQ(s1.toCString(), "A");

    auto s2 = fn::chr(0);
    ASSERT_STREQ(s2.toCString(), "\0");

    auto s3 = fn::chr(97);
    ASSERT_STREQ(s3.toCString(), "a");
}

TEST(std_string, strlen) {
    var d = 10000;
    ASSERT_EQ(fn::strlen(d), 5);

    ASSERT_EQ(fn::strlen("hello"), 5);
    ASSERT_EQ(fn::strlen(""), 0);
}

TEST(std_string, str_starts_with) {
    ASSERT_TRUE(fn::str_starts_with("hello world", "hello"));
    ASSERT_FALSE(fn::str_starts_with("hello world", "world"));
    ASSERT_TRUE(fn::str_starts_with("hello", ""));
    ASSERT_TRUE(fn::str_starts_with("", ""));
    ASSERT_FALSE(fn::str_starts_with("", "hello"));

    // Var arguments
    var haystack = "php extension";
    ASSERT_TRUE(fn::str_starts_with(haystack, "php"));
}

TEST(std_string, str_ends_with) {
    ASSERT_TRUE(fn::str_ends_with("hello world", "world"));
    ASSERT_FALSE(fn::str_ends_with("hello world", "hello"));
    ASSERT_TRUE(fn::str_ends_with("hello", ""));
    ASSERT_TRUE(fn::str_ends_with("", ""));
    ASSERT_FALSE(fn::str_ends_with("", "world"));

    var haystack = "hello.php";
    ASSERT_TRUE(fn::str_ends_with(haystack, ".php"));
}

TEST(std_string, str_contains) {
    ASSERT_TRUE(fn::str_contains("hello world", "lo wo"));
    ASSERT_FALSE(fn::str_contains("hello world", "php"));
    ASSERT_TRUE(fn::str_contains("hello", ""));
    ASSERT_TRUE(fn::str_contains("", ""));
    ASSERT_FALSE(fn::str_contains("", "x"));

    var haystack = "the quick brown fox";
    ASSERT_TRUE(fn::str_contains(haystack, "quick"));
}

TEST(std_string, lcfirst_ucfirst) {
    auto s1 = fn::lcfirst("Hello");
    ASSERT_STREQ(s1.toCString(), "hello");

    auto s2 = fn::lcfirst("HELLO");
    ASSERT_STREQ(s2.toCString(), "hELLO");

    auto s3 = fn::lcfirst("hello");
    ASSERT_STREQ(s3.toCString(), "hello");

    auto s4 = fn::lcfirst("");
    ASSERT_STREQ(s4.toCString(), "");

    auto s5 = fn::ucfirst("hello");
    ASSERT_STREQ(s5.toCString(), "Hello");

    auto s6 = fn::ucfirst("Hello");
    ASSERT_STREQ(s6.toCString(), "Hello");

    auto s7 = fn::ucfirst("");
    ASSERT_STREQ(s7.toCString(), "");
}

TEST(std_string, strtolower_strtoupper) {
    auto s1 = fn::strtolower("HELLO");
    ASSERT_STREQ(s1.toCString(), "hello");

    auto s2 = fn::strtolower("Hello World");
    ASSERT_STREQ(s2.toCString(), "hello world");

    auto s3 = fn::strtolower("");
    ASSERT_STREQ(s3.toCString(), "");

    auto s4 = fn::strtoupper("hello");
    ASSERT_STREQ(s4.toCString(), "HELLO");

    auto s5 = fn::strtoupper("Hello World");
    ASSERT_STREQ(s5.toCString(), "HELLO WORLD");

    auto s6 = fn::strtoupper("");
    ASSERT_STREQ(s6.toCString(), "");
}

TEST(std_string, trim) {
    auto s1 = fn::trim("  hello  ");
    ASSERT_STREQ(s1.toCString(), "hello");

    auto s2 = fn::trim("\n\t hello \t\n");
    ASSERT_STREQ(s2.toCString(), "hello");

    auto s3 = fn::trim("hello");
    ASSERT_STREQ(s3.toCString(), "hello");

    auto s4 = fn::trim("");
    ASSERT_STREQ(s4.toCString(), "");

    // Custom chars (must pass length explicitly for C-string what)
    auto s5 = fn::trim("/tmp/", "/", 1);
    ASSERT_STREQ(s5.toCString(), "tmp");

    // ltrim
    auto s6 = fn::ltrim("  hello  ");
    ASSERT_STREQ(s6.toCString(), "hello  ");

    // rtrim
    auto s7 = fn::rtrim("  hello  ");
    ASSERT_STREQ(s7.toCString(), "  hello");
}

TEST(std_string, strpos) {
    auto pos1 = fn::strpos("hello world", "world");
    ASSERT_TRUE(pos1.isInt());
    ASSERT_EQ(pos1.toInt(), 6);

    // Not found returns false
    auto pos2 = fn::strpos("hello world", "php");
    ASSERT_TRUE(pos2.isFalse());

    // With offset
    auto pos4 = fn::strpos("hello hello", "hello", 3);
    ASSERT_TRUE(pos4.isInt());
    ASSERT_EQ(pos4.toInt(), 6);
}

TEST(std_string, stripos) {
    auto pos1 = fn::stripos("Hello World", "world");
    ASSERT_TRUE(pos1.isInt());
    ASSERT_EQ(pos1.toInt(), 6);

    auto pos2 = fn::stripos("HELLO", "hello");
    ASSERT_TRUE(pos2.isInt());
    ASSERT_EQ(pos2.toInt(), 0);

    auto pos3 = fn::stripos("hello", "PHP");
    ASSERT_TRUE(pos3.isFalse());
}

TEST(std_string, strrpos) {
    auto pos1 = fn::strrpos("hello hello", "hello");
    ASSERT_TRUE(pos1.isInt());
    ASSERT_EQ(pos1.toInt(), 6);

    auto pos2 = fn::strrpos("hello world", "php");
    ASSERT_TRUE(pos2.isFalse());
}

TEST(std_string, strstr) {
    auto s1 = fn::strstr("hello world", "world");
    ASSERT_STREQ(s1.toString().toCString(), "world");

    auto s2 = fn::strstr("hello world", "php");
    ASSERT_TRUE(s2.isFalse());

    // before_needle = true
    auto s3 = fn::strstr("hello world", " ", true);
    ASSERT_STREQ(s3.toString().toCString(), "hello");
}

TEST(std_string, stristr) {
    auto s1 = fn::stristr("Hello World", "world");
    ASSERT_STREQ(s1.toString().toCString(), "World");

    auto s2 = fn::stristr("hello world", "PHP");
    ASSERT_TRUE(s2.isFalse());
}

TEST(std_string, substr) {
    auto s1 = fn::substr("hello world", 6);
    ASSERT_STREQ(s1.toCString(), "world");

    auto s2 = fn::substr("hello world", 0, 5);
    ASSERT_STREQ(s2.toCString(), "hello");

    auto s3 = fn::substr("hello world", -5);
    ASSERT_STREQ(s3.toCString(), "world");

    auto s4 = fn::substr("hello world", 6, 2);
    ASSERT_STREQ(s4.toCString(), "wo");

    auto s5 = fn::substr("hello world", -5, 3);
    ASSERT_STREQ(s5.toCString(), "wor");
}

TEST(std_string, str_repeat) {
    auto s1 = fn::str_repeat("abc", 3);
    ASSERT_STREQ(s1.toCString(), "abcabcabc");

    auto s2 = fn::str_repeat("x", 0);
    ASSERT_STREQ(s2.toCString(), "");

    auto s3 = fn::str_repeat("", 10);
    ASSERT_STREQ(s3.toCString(), "");
}

TEST(std_string, str_repeat_exception) {
    try_call([]() { fn::str_repeat("x", -1); },
             "str_repeat(): Argument #2 ($times) must be greater than or equal to 0");
}

TEST(std_string, explode_implode) {
    auto parts = fn::explode(",", "a,b,c");
    ASSERT_EQ(parts.length(), 3);
    ASSERT_STREQ(parts.get(0).toString().toCString(), "a");
    ASSERT_STREQ(parts.get(1).toString().toCString(), "b");
    ASSERT_STREQ(parts.get(2).toString().toCString(), "c");

    // With limit
    auto parts2 = fn::explode(",", "a,b,c", 2);
    ASSERT_EQ(parts2.length(), 2);
    ASSERT_STREQ(parts2.get(1).toString().toCString(), "b,c");

    // implode
    auto joined = fn::implode("-", Array{"a", "b", "c"});
    ASSERT_STREQ(joined.toCString(), "a-b-c");

    // join alias
    auto joined2 = fn::join("", Array{"x", "y", "z"});
    ASSERT_STREQ(joined2.toCString(), "xyz");
}

TEST(std_string, dirname_basename) {
    auto d1 = fn::dirname("/var/www/html/index.php");
    ASSERT_STREQ(d1.toCString(), "/var/www/html");

    auto d2 = fn::dirname("/var/www/html");
    ASSERT_STREQ(d2.toCString(), "/var/www");

    auto d3 = fn::dirname("/var/www/html/index.php", 2);
    ASSERT_STREQ(d3.toCString(), "/var/www");

    auto b1 = fn::basename("/var/www/html/index.php");
    ASSERT_STREQ(b1.toCString(), "index.php");

    auto b2 = fn::basename("/var/www/html/index.php", ".php");
    ASSERT_STREQ(b2.toCString(), "index");
}

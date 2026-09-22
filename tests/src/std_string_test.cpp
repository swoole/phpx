#include "phpx_test.h"
#include "phpx_std.h"

#include <limits>
#include <string>

using namespace php;

TEST(std_string, ord) {
    ASSERT_EQ(fn::ord("A"), 65);
    ASSERT_EQ(fn::ord(""), 0);
    ASSERT_EQ(fn::ord("hello"), 104);  // 'h' = 104
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

TEST(std_string, ctype_without_extension_handlers) {
    ASSERT_TRUE(fn::ctype_alnum("Abc123"));
    ASSERT_TRUE(fn::ctype_alpha("AbC"));
    ASSERT_TRUE(fn::ctype_cntrl("\n"));
    ASSERT_TRUE(fn::ctype_digit("0123"));
    ASSERT_TRUE(fn::ctype_lower("abc"));
    ASSERT_TRUE(fn::ctype_graph("!A1"));
    ASSERT_TRUE(fn::ctype_print(" A1!"));
    ASSERT_TRUE(fn::ctype_punct("!?"));
    ASSERT_TRUE(fn::ctype_space(" \t\n"));
    ASSERT_TRUE(fn::ctype_upper("ABC"));
    ASSERT_TRUE(fn::ctype_xdigit("A09f"));

    ASSERT_FALSE(fn::ctype_digit("12a"));
    ASSERT_FALSE(fn::ctype_digit(""));
    ASSERT_TRUE(fn::ctype_digit(49));
    ASSERT_TRUE(fn::ctype_alpha(65));
    ASSERT_TRUE(fn::ctype_digit(1000));
    ASSERT_FALSE(fn::ctype_alpha(1000));
    ASSERT_TRUE(fn::ctype_print(-1000));
    ASSERT_FALSE(fn::ctype_digit(Variant{}));
    ASSERT_FALSE(fn::ctype_digit(false));
    ASSERT_FALSE(fn::ctype_digit(Array{}));
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

TEST(std_string, first_case_conversion_matches_php_and_reuses_unchanged_strings) {
    for (unsigned int byte = 0; byte <= 255; byte++) {
        SCOPED_TRACE(byte);
        std::string bytes{static_cast<char>(byte), '\0', 'A', 'z'};
        String input(bytes);
        auto lower = fn::lcfirst(input);
        auto upper = fn::ucfirst(input);
        EXPECT_EQ(lower.toStdString(), php::call("lcfirst", {input}).toStdString());
        EXPECT_EQ(upper.toStdString(), php::call("ucfirst", {input}).toStdString());
        EXPECT_EQ(input.toStdString(), bytes);
        if (byte < 'A' || byte > 'Z') {
            EXPECT_EQ(lower.str(), input.str());
        }
        if (byte < 'a' || byte > 'z') {
            EXPECT_EQ(upper.str(), input.str());
        }
    }
}

TEST(std_string, unchanged_first_case_results_preserve_copy_on_write) {
    String lower_input("already lower");
    String upper_input("Already upper");
    auto lower = fn::lcfirst(lower_input);
    auto upper = fn::ucfirst(upper_input);
    lower.item(0, true) = "#";
    upper.item(0, true) = "#";
    EXPECT_EQ(lower.toStdString(), "#lready lower");
    EXPECT_EQ(upper.toStdString(), "#lready upper");
    EXPECT_EQ(lower_input.toStdString(), "already lower");
    EXPECT_EQ(upper_input.toStdString(), "Already upper");
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

    ASSERT_EQ(fn::strpos("hello", "").toInt(), 0);
    ASSERT_EQ(fn::strpos("hello", "lo", -3).toInt(), 3);
    try_call([]() { fn::strpos("hello", "h", 6); }, "must be contained in argument #1");
    try_call([]() { fn::strpos("hello", "h", -6); }, "must be contained in argument #1");
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

    ASSERT_EQ(fn::stripos("Hello", "").toInt(), 0);
    ASSERT_EQ(fn::stripos("Hello", "LO", -3).toInt(), 3);
    try_call([]() { fn::stripos("hello", "h", 6); }, "must be contained in argument #1");
    try_call([]() { fn::stripos("hello", "h", -6); }, "must be contained in argument #1");
}

TEST(std_string, strrpos) {
    auto pos1 = fn::strrpos("hello hello", "hello");
    ASSERT_TRUE(pos1.isInt());
    ASSERT_EQ(pos1.toInt(), 6);

    auto pos2 = fn::strrpos("hello world", "php");
    ASSERT_TRUE(pos2.isFalse());

    ASSERT_EQ(fn::strrpos("hello", "").toInt(), 5);
    ASSERT_EQ(fn::strrpos("abcabc", "abc", 1).toInt(), 3);
    ASSERT_EQ(fn::strrpos("abcabc", "abc", -1).toInt(), 3);
    ASSERT_EQ(fn::strrpos("abcabc", "abc", -4).toInt(), 0);
    try_call([]() { fn::strrpos("hello", "h", 6); }, "must be contained in argument #1");
    try_call([]() { fn::strrpos("hello", "h", -6); }, "must be contained in argument #1");
}

TEST(std_string, search_empty_needle_offsets) {
    struct SearchCase {
        Int offset;
        Int forward;
        Int reverse;
    };
    const SearchCase cases[] = {
        {0, 0, 3}, {1, 1, 3}, {3, 3, 3}, {-1, 2, 2}, {-2, 1, 1}, {-3, 0, 0},
    };
    for (const auto &test : cases) {
        SCOPED_TRACE(test.offset);
        auto forward = fn::strpos("abc", "", test.offset);
        auto insensitive = fn::stripos("AbC", "", test.offset);
        auto reverse = fn::strrpos("abc", "", test.offset);
        EXPECT_TRUE(forward.isInt());
        EXPECT_TRUE(insensitive.isInt());
        EXPECT_TRUE(reverse.isInt());
        EXPECT_EQ(forward.toInt(), test.forward);
        EXPECT_EQ(insensitive.toInt(), test.forward);
        EXPECT_EQ(reverse.toInt(), test.reverse);
    }

    EXPECT_EQ(fn::strpos("", "", 0).toInt(), 0);
    EXPECT_EQ(fn::stripos("", "", 0).toInt(), 0);
    EXPECT_EQ(fn::strrpos("", "", 0).toInt(), 0);
}

TEST(std_string, search_empty_needle_invalid_offsets) {
    struct SearchFunction {
        const char *name;
        Variant (*call)(const String &, const String &, Int);
    };
    const SearchFunction functions[] = {
        {"strpos", fn::strpos}, {"stripos", fn::stripos}, {"strrpos", fn::strrpos},
    };
    for (const auto &search : functions) {
        SCOPED_TRACE(search.name);
        for (const char *haystack : {"abc", ""}) {
            SCOPED_TRACE(haystack);
            for (Int offset : {Int(4), Int(-4), std::numeric_limits<Int>::max(), std::numeric_limits<Int>::min()}) {
                SCOPED_TRACE(offset);
                bool caught = false;
                try {
                    search.call(haystack, "", offset);
                } catch (zend_object *) {
                    auto exception = catchException();
                    EXPECT_TRUE(exception.instanceOf("ValueError"));
                    auto message = exception.call("getMessage");
                    EXPECT_NE(std::string(message.toCString()).find("must be contained in argument #1"),
                              std::string::npos);
                    caught = true;
                }
                EXPECT_TRUE(caught);
            }
        }
    }
}

TEST(std_string, strstr) {
    auto s1 = fn::strstr("hello world", "world");
    ASSERT_STREQ(s1.toString().toCString(), "world");

    auto s2 = fn::strstr("hello world", "php");
    ASSERT_TRUE(s2.isFalse());

    // before_needle = true
    auto s3 = fn::strstr("hello world", " ", true);
    ASSERT_STREQ(s3.toString().toCString(), "hello");

    ASSERT_STREQ(fn::strstr("hello", "").toCString(), "hello");
    ASSERT_TRUE(fn::strstr("hello", "", true).toString().empty());
}

TEST(std_string, stristr) {
    auto s1 = fn::stristr("Hello World", "world");
    ASSERT_STREQ(s1.toString().toCString(), "World");

    auto s2 = fn::stristr("hello world", "PHP");
    ASSERT_TRUE(s2.isFalse());

    ASSERT_STREQ(fn::stristr("Hello", "").toCString(), "Hello");
    ASSERT_TRUE(fn::stristr("Hello", "", true).toString().empty());
    ASSERT_STREQ(fn::stristr("Hello World", "world", true).toCString(), "Hello ");
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

    ASSERT_STREQ(fn::substr("hello", -20).toCString(), "hello");
    ASSERT_TRUE(fn::substr("hello", 20).empty());
    ASSERT_TRUE(fn::substr("hello", 3, -3).empty());
    ASSERT_STREQ(fn::substr("hello", 1, -1).toCString(), "ell");
    ASSERT_STREQ(fn::substr("hello", 3, 50).toCString(), "lo");
    ASSERT_STREQ(fn::substr("hello", 1, std::numeric_limits<php::Int>::max()).toCString(), "ello");
    ASSERT_TRUE(fn::substr("hello", 1, std::numeric_limits<php::Int>::min()).empty());
    ASSERT_STREQ(fn::substr("hello", std::numeric_limits<php::Int>::min()).toCString(), "hello");
    ASSERT_TRUE(fn::substr("hello", std::numeric_limits<php::Int>::max()).empty());
}

TEST(std_string, str_repeat) {
    auto s1 = fn::str_repeat("abc", 3);
    ASSERT_STREQ(s1.toCString(), "abcabcabc");

    auto s2 = fn::str_repeat("x", 0);
    ASSERT_STREQ(s2.toCString(), "");

    auto s3 = fn::str_repeat("", 10);
    ASSERT_STREQ(s3.toCString(), "");
}

TEST(std_string, str_repeat_empty_large_count) {
    for (Int count : {Int(0), Int(1), Int(10), Int(ZEND_LONG_MAX)}) {
        SCOPED_TRACE(count);
        EXPECT_TRUE(fn::str_repeat("", count).empty());
        EXPECT_TRUE(php::call("str_repeat", {"", count}).toString().empty());
    }
}

TEST(std_string, str_repeat_empty_negative_count) {
    for (Int count : {Int(-1), Int(ZEND_LONG_MIN)}) {
        SCOPED_TRACE(count);
        bool caught = false;
        try {
            fn::str_repeat("", count);
        } catch (zend_object *) {
            caught = true;
            auto exception = php::catchException();
            EXPECT_EQ(exception.getClassName().toStdString(), "ValueError");
            EXPECT_EQ(exception.call("getMessage").toStdString(),
                      "str_repeat(): Argument #2 ($times) must be greater than or equal to 0");
        }
        EXPECT_TRUE(caught);
    }
}

TEST(std_string, str_repeat_exception) {
    try_call([]() { fn::str_repeat("x", -1); },
             "str_repeat(): Argument #2 ($times) must be greater than or equal to 0");
}

TEST(std_string, implode_propagates_string_conversion_exceptions) {
    eval(R"(
        class PhpxThrowingJoinValue {
            public function __toString(): string {
                throw new RuntimeException('join conversion failed');
            }
        }
    )");
    for (bool singleton : {false, true}) {
        SCOPED_TRACE(singleton);
        Array pieces = eval(singleton ? "return [new PhpxThrowingJoinValue()];"
                                      : "return ['before', new PhpxThrowingJoinValue(), 'after'];");
        for (bool alias : {false, true}) {
            SCOPED_TRACE(alias);
            bool caught = false;
            try {
                if (alias) {
                    fn::join(",", pieces);
                } else {
                    fn::implode(",", pieces);
                }
            } catch (zend_object *) {
                caught = true;
                auto exception = php::catchException();
                EXPECT_EQ(exception.getClassName().toStdString(), "RuntimeException");
                EXPECT_EQ(exception.call("getMessage").toStdString(), "join conversion failed");
            }
            if (EG(exception)) {
                php::catchException();
            }
            EXPECT_TRUE(caught);
        }
    }
}

TEST(std_string, implode_preserves_inputs_during_conversion_callbacks) {
    eval(R"(
        class PhpxMutatingJoinValue {
            public function __toString(): string {
                $GLOBALS['phpx_join_glue'] = 'changed';
                $GLOBALS['phpx_join_pieces'] = [];
                return 'converted';
            }
        }
    )");
    std::string outcomes[2];
    for (int native = 0; native < 2; native++) {
        eval(R"(
            $GLOBALS['phpx_join_glue'] = str_repeat(':', 3);
            $GLOBALS['phpx_join_pieces'] = ['before', new PhpxMutatingJoinValue(), 'after'];
        )");
        String glue(zend_hash_str_find(&EG(symbol_table), ZEND_STRL("phpx_join_glue")), Ctor::Indirect);
        Array pieces(zend_hash_str_find(&EG(symbol_table), ZEND_STRL("phpx_join_pieces")), Ctor::Indirect);
        outcomes[native] = native ? php::call("implode", {glue, pieces}).toStdString()
                                 : fn::implode(glue, pieces).toStdString();
        EXPECT_EQ(outcomes[native], "before:::converted:::after");
        EXPECT_EQ(glue.toStdString(), "changed");
        EXPECT_EQ(pieces.count(), 0);
        eval("unset($GLOBALS['phpx_join_glue'], $GLOBALS['phpx_join_pieces']);");
    }
    EXPECT_EQ(outcomes[0], outcomes[1]);
}

TEST(std_string, implode_propagates_element_destructor_exceptions) {
    eval(R"(
        class PhpxDestructingJoinValue {
            public function __toString(): string {
                $GLOBALS['phpx_destructing_join'] = [];
                return 'converted';
            }
            public function __destruct() {
                throw new RuntimeException('join destruction failed');
            }
        }
    )");
    for (bool singleton : {false, true}) {
        SCOPED_TRACE(singleton);
        eval(singleton ? "$GLOBALS['phpx_destructing_join'] = [new PhpxDestructingJoinValue()];"
                       : "$GLOBALS['phpx_destructing_join'] = ['before', new PhpxDestructingJoinValue(), 'after'];");
        Array pieces(zend_hash_str_find(&EG(symbol_table), ZEND_STRL("phpx_destructing_join")), Ctor::Indirect);
        bool caught = false;
        try {
            fn::implode(",", pieces);
        } catch (zend_object *) {
            caught = true;
            auto exception = php::catchException();
            EXPECT_EQ(exception.getClassName().toStdString(), "RuntimeException");
            EXPECT_EQ(exception.call("getMessage").toStdString(), "join destruction failed");
        }
        if (EG(exception)) {
            php::catchException();
        }
        EXPECT_TRUE(caught);
        eval("unset($GLOBALS['phpx_destructing_join']);");
    }
}

TEST(std_string, implode_propagates_error_handler_exceptions) {
    eval(R"(
        set_error_handler(static function ($severity, $message) {
            throw new ErrorException($message, 0, $severity);
        });
    )");
    bool caught = false;
    try {
        fn::implode(",", Array{Array(), "after"});
    } catch (zend_object *) {
        caught = true;
        auto exception = php::catchException();
        EXPECT_EQ(exception.getClassName().toStdString(), "ErrorException");
        EXPECT_EQ(exception.call("getMessage").toStdString(), "Array to string conversion");
    }
    if (EG(exception)) {
        php::catchException();
    }
    eval("restore_error_handler();");
    EXPECT_TRUE(caught);
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

    ASSERT_EQ(fn::explode(",", "", 1).count(), 1);
    ASSERT_TRUE(fn::explode(",", "", -1).empty());
    ASSERT_STREQ(fn::explode(",", "a,b,c", 1).get(0).toCString(), "a,b,c");
    ASSERT_EQ(fn::explode(",", "a,b,c", -1).count(), 2);
    try_call([]() { fn::explode("", "value"); }, "must not be empty");
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

    ASSERT_TRUE(fn::dirname("").empty());
}

TEST(std_string, dirname_invalid_levels) {
    for (const char *path : {"/var/www/index.php", "a", ""}) {
        SCOPED_TRACE(path);
        for (int levels : {0, -1, std::numeric_limits<int>::min()}) {
            SCOPED_TRACE(levels);
            bool caught = false;
            try {
                fn::dirname(path, levels);
            } catch (zend_object *) {
                auto exception = catchException();
                EXPECT_TRUE(exception.instanceOf("ValueError"));
                EXPECT_STREQ(exception.call("getMessage").toCString(),
                             "dirname(): Argument #2 ($levels) must be greater than or equal to 1");
                caught = true;
            }
            EXPECT_TRUE(caught);
        }
    }
}

#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

// Test equals with const char* and std::string overloads
TEST(string_extra, equals_overloads) {
    String s("hello world");
    ASSERT_TRUE(s.equals("hello world"));
    ASSERT_FALSE(s.equals("goodbye"));

    ASSERT_TRUE(s.equals(std::string("hello world")));
    ASSERT_FALSE(s.equals(std::string("other")));

    // equals with empty string
    String e;
    ASSERT_TRUE(e.equals(""));
    ASSERT_TRUE(e.equals(std::string("")));
}

// Test operator==
TEST(string_extra, operator_eq) {
    String s1("abc");
    String s2("abc");
    String s3("xyz");
    ASSERT_TRUE(s1 == s2);
    ASSERT_FALSE(s1 == s3);
}

// Test offset() method for valid and invalid indices
TEST(string_extra, offset_valid) {
    String s("hello");
    ASSERT_EQ(s.offset(0), 0);
    ASSERT_EQ(s.offset(4), 4);
    ASSERT_EQ(s.offset(-1), 4);    // last char
    ASSERT_EQ(s.offset(-5), 0);    // first char via negative
}

// Test offset() with out-of-range
TEST(string_extra, offset_invalid) {
    String s("hello");
    ASSERT_EQ(s.offset(5), -1);
    ASSERT_EQ(s.offset(10), -1);
    ASSERT_EQ(s.offset(-6), -1);
    ASSERT_EQ(s.offset(-10), -1);

    String e;
    ASSERT_EQ(e.offset(0), -1);
}

// Test offsetGet with negative offset
TEST(string_extra, offsetGet_negative) {
    String s("hello");
    ASSERT_STREQ(s.offsetGet(-1).toCString(), "o");
    ASSERT_STREQ(s.offsetGet(-5).toCString(), "h");
    ASSERT_STREQ(s.offsetGet(-6).toCString(), "");
    ASSERT_STREQ(s.offsetGet(5).toCString(), "");
    ASSERT_STREQ(s.offsetGet(10).toCString(), "");
}

// Test offsetGet with Variant key
TEST(string_extra, offsetGet_variant_key) {
    String s("world");
    var k0(0);
    ASSERT_STREQ(s.offsetGet(k0).toCString(), "w");
    var k1(4);
    ASSERT_STREQ(s.offsetGet(k1).toCString(), "d");
    var k_neg(-1);
    ASSERT_STREQ(s.offsetGet(k_neg).toCString(), "d");
}

// Test offsetSet with negative offset
TEST(string_extra, offsetSet_negative) {
    String s("hello");
    s.offsetSet(-1, "X");
    ASSERT_STREQ(s.toCString(), "hellX");

    s.offsetSet(-2, "Y");
    ASSERT_STREQ(s.toCString(), "helYX");
}

// Test isNumeric edge cases
TEST(string_extra, isNumeric_edge) {
    String s1("0");
    ASSERT_TRUE(s1.isNumeric());
    String s2("-1");
    ASSERT_TRUE(s2.isNumeric());
    String s3("1.5");
    ASSERT_TRUE(s3.isNumeric());
    String s4("");
    ASSERT_FALSE(s4.isNumeric());
    String s5("abc");
    ASSERT_FALSE(s5.isNumeric());
    String s6("12abc");
    ASSERT_FALSE(s6.isNumeric());
    String s7("123abc");
    ASSERT_FALSE(s7.isNumeric());
}

// Test lower/upper with edge cases
TEST(string_extra, lower_upper_edge) {
    String s1("");
    ASSERT_STREQ(s1.lower().toCString(), "");
    ASSERT_STREQ(s1.upper().toCString(), "");

    String s2("AlreadyUPPER");
    auto upper = s2.upper();
    ASSERT_STREQ(upper.toCString(), "ALREADYUPPER");

    String s3("alreadyLOWER");
    auto lower = s3.lower();
    ASSERT_STREQ(lower.toCString(), "alreadylower");

    String s4("MiXeD CaSe 123");
    ASSERT_STREQ(s4.lower().toCString(), "mixed case 123");
    ASSERT_STREQ(s4.upper().toCString(), "MIXED CASE 123");
}

// Test trim with modes
TEST(string_extra, trim_modes) {
    String s1("  hello  ");
    ASSERT_STREQ(s1.trim().toCString(), "hello");

    String s2("  hello  ");
    ASSERT_STREQ(s2.trim(" ", TRIM_LEFT).toCString(), "hello  ");
    ASSERT_STREQ(s2.trim(" ", TRIM_RIGHT).toCString(), "  hello");

    String s3("--hello--");
    ASSERT_STREQ(s3.trim("-").toCString(), "hello");

    String s4("\t\nhello\r\n");
    ASSERT_STREQ(s4.trim().toCString(), "hello");
}

// Test String constructor from zend_string with Ctor::Move
TEST(string_extra, ctor_zend_string_move) {
    zend_string *zs = zend_string_init("moved", 5, 0);
    String s(zs, Ctor::Move);
    ASSERT_STREQ(s.toCString(), "moved");
    // With Move, the String takes ownership - no need to release zs
}

// Test String constructor from std::string
TEST(string_extra, ctor_std_string) {
    std::string std_str = "from std::string";
    String s(std_str);
    ASSERT_STREQ(s.toCString(), "from std::string");
    ASSERT_EQ(s.length(), std_str.length());
}

// Test String constructor from const char* with length
TEST(string_extra, ctor_char_len) {
    String s("hello world", 5);
    ASSERT_EQ(s.length(), 5);
    ASSERT_STREQ(s.toCString(), "hello");
}

// Test String constructor from const char* with length and persistent flag
TEST(string_extra, ctor_char_len_persistent) {
    String s1("persistent", 10, true);
    ASSERT_STREQ(s1.toCString(), "persistent");
    ASSERT_EQ(s1.length(), 10);

    String s2("non-persistent", 14, false);
    ASSERT_STREQ(s2.toCString(), "non-persistent");
    ASSERT_EQ(s2.length(), 14);
}

// Test stripTags with allow tags parameter
TEST(string_extra, stripTags_with_allow) {
    String s("<p>Keep <b>bold</b></p><i>italic</i>");
    auto result = s.stripTags("<b>");
    ASSERT_TRUE(strstr(result.toCString(), "bold") != nullptr);
    ASSERT_TRUE(strstr(result.toCString(), "<b>") != nullptr);
}

// Test stripTags with allow_tag_spaces
TEST(string_extra, stripTags_allow_spaces) {
    String s("<b class='foo'>bold</b>");
    auto result = s.stripTags("<b>", true);
    ASSERT_TRUE(strstr(result.toCString(), "<b class='foo'>") != nullptr);
}

// Test split with various limit values
TEST(string_extra, split_limit_edge) {
    String s("a,b,c,d,e");
    String d(",");

    auto r1 = s.split(d, 1);
    ASSERT_GE(r1.count(), 1);

    auto r2 = s.split(d, 0);
    ASSERT_GE(r2.count(), 1);

    auto r3 = s.split(d, 10);
    ASSERT_EQ(r3.count(), 5);

    auto r4 = s.split(d, -1);
    ASSERT_GE(r4.count(), 1);
}

// Test split single char delimiter
TEST(string_extra, split_single_char) {
    String s("abc");
    String d(",");
    auto r = s.split(d);
    ASSERT_GE(r.count(), 1);
}

// Test hashCode consistency
TEST(string_extra, hashCode_consistency) {
    String s1("hello");
    String s2("hello");
    ASSERT_EQ(s1.hashCode(), s2.hashCode());

    String s3("world");
    ASSERT_NE(s1.hashCode(), s3.hashCode());
}

// Test escape/unescape with different flags
TEST(string_extra, escape_flags) {
    String s("<tag>'\"&");
    auto e1 = s.escape(ENT_QUOTES | ENT_SUBSTITUTE);
    ASSERT_GT(e1.length(), s.length());
    auto u1 = e1.unescape(ENT_QUOTES | ENT_SUBSTITUTE);
    ASSERT_TRUE(u1.equals(s));

    auto e2 = s.escape(ENT_NOQUOTES | ENT_SUBSTITUTE);
    ASSERT_GT(e2.length(), s.length());
}

// Test base64Decode of invalid input
TEST(string_extra, base64_decode_invalid) {
    String s("!!!");
    auto decoded = s.base64Decode();
    // php_base64_decode_str may decode partial content
    ASSERT_TRUE(decoded.isString());
}

// Test base64 round-trip with various strings
TEST(string_extra, base64_roundtrip) {
    String s1("");
    ASSERT_TRUE(s1.base64Encode().base64Decode().equals(s1));

    String s2("hello world");
    ASSERT_TRUE(s2.base64Encode().base64Decode().equals(s2));

    String s3("binary \x00\x01\x02 test", 17);
    auto decoded = s3.base64Encode().base64Decode();
    ASSERT_EQ(decoded.length(), 17);
}

// Test String::format edge cases
TEST(string_extra, format_edge) {
    auto s1 = String::format("%d", 42);
    ASSERT_STREQ(s1.toCString(), "42");

    auto s2 = String::format("%s-%d", "test", 100);
    ASSERT_STREQ(s2.toCString(), "test-100");

    auto s3 = String::format("");
    ASSERT_EQ(s3.length(), 0);
}

// Test length() on constructed strings
TEST(string_extra, length_various) {
    String s1("hello");
    ASSERT_EQ(s1.length(), 5);

    String s2("");
    ASSERT_EQ(s2.length(), 0);

    auto s3 = String::format("%d", 12345);
    ASSERT_EQ(s3.length(), 5);
}

// Test data() accessor
TEST(string_extra, data_accessor) {
    String s("hello");
    ASSERT_STREQ(s.data(), "hello");
    ASSERT_EQ(s.data()[0], 'h');

    String e;
    ASSERT_EQ(e.length(), 0);
}

// Test operator= assignment overloads
TEST(string_extra, assign_overloads) {
    String s;

    s = 42;
    ASSERT_STREQ(s.toCString(), "42");

    s = 3.14;
    ASSERT_TRUE(s.length() >= 3);

    s = true;
    ASSERT_STREQ(s.toCString(), "1");

    s = false;
    ASSERT_STREQ(s.toCString(), "");
}

// Test String copy construction from Variant
TEST(string_extra, copy_from_variant) {
    var v("hello from variant");
    String s(v);
    ASSERT_STREQ(s.toCString(), "hello from variant");

    var num(42);
    String s2(num);
    ASSERT_STREQ(s2.toCString(), "42");
}

// Test move assignment
TEST(string_extra, move_assign) {
    String s1("hello");
    ASSERT_EQ(s1.length(), 5);

    String s2(std::move(s1));
    ASSERT_STREQ(s2.toCString(), "hello");
    ASSERT_EQ(s1.str(), nullptr);
}

// Test zval constructor for String (ensures string conversion)
TEST(string_extra, from_zval_long) {
    zval tmp;
    ZVAL_LONG(&tmp, 2048);
    String s(&tmp);
    ASSERT_STREQ(s.toCString(), "2048");

    zval tmp2;
    ZVAL_DOUBLE(&tmp2, 1.5);
    String s2(&tmp2);
    ASSERT_STREQ(s2.toCString(), "1.5");

    zval tmp3;
    ZVAL_TRUE(&tmp3);
    String s3(&tmp3);
    ASSERT_STREQ(s3.toCString(), "1");

    zval tmp4;
    ZVAL_FALSE(&tmp4);
    String s4(&tmp4);
    ASSERT_STREQ(s4.toCString(), "");
}

// Test operator[] via string offset (PHP string character access behavior)
TEST(string_extra, subscript_via_variant) {
    String s("hello");
    var v = s;
    ASSERT_TRUE(v.isString());
    // access as array dimension
    auto c0 = v.offsetGet(0);
    ASSERT_STREQ(c0.toCString(), "h");
}

// Test addSlashes / stripSlashes roundtrip
TEST(string_extra, slashes_roundtrip) {
    String s("it's a \"test\" with \\backslash\\");
    auto escaped = s.addSlashes();
    auto unescaped = escaped.stripSlashes();
    ASSERT_TRUE(unescaped.equals(s));
}

// Test basename without suffix
TEST(string_extra, basename_no_suffix) {
    String path("/var/www/index.php");
    String no_suffix("");
    ASSERT_STREQ(path.basename(no_suffix).toCString(), "index.php");

    String path2("just_file.txt");
    ASSERT_STREQ(path2.basename(no_suffix).toCString(), "just_file.txt");
}

// Test dirname edge cases
TEST(string_extra, dirname_edge) {
    String path1("/");
    auto d1 = path1.dirname();
    ASSERT_STREQ(d1.toCString(), "/");

    String path2("relative/path/");
    auto d2 = path2.dirname();
    ASSERT_STREQ(d2.toCString(), "relative");

    String path3("justfile");
    auto d3 = path3.dirname();
    ASSERT_STREQ(d3.toCString(), ".");
}

// Test substr with all boundary cases
TEST(string_extra, substr_boundary) {
    String s("0123456789");
    ASSERT_STREQ(s.substr(0, 0).toCString(), "");
    ASSERT_STREQ(s.substr(0, 10).toCString(), "0123456789");
    ASSERT_STREQ(s.substr(0, 100).toCString(), "0123456789");
    // substr(5) uses default length=-1 which excludes the last char
    ASSERT_EQ(s.substr(5).length(), 4);
    ASSERT_STREQ(s.substr(-2, 2).toCString(), "89");
    ASSERT_STREQ(s.substr(100).toCString(), "");
    ASSERT_STREQ(s.substr(0, -1).toCString(), "012345678");
    ASSERT_STREQ(s.substr(0, -5).toCString(), "01234");
    ASSERT_STREQ(s.substr(5, 0).toCString(), "");
}

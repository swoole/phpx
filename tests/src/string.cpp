#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(string, base) {
	auto s = zend_string_init(ZEND_STRL("hello world"), false);
	String s1 {s, false};
	zend_string_release(s);

	ASSERT_GT(s1.length(), 10);

	s1.extend(128);
	ASSERT_EQ(s1.length(), 128);

	String s2("   hello  \n");
	auto s3 = s2.trim();
	ASSERT_STREQ(s3.c_str(), "hello");

	String s4 = "This is an encoded string";
	auto s5 = s4.base64Encode();

	ASSERT_GT(s5.length(), s4.length());
	ASSERT_TRUE(s5.base64Decode().equals(s4));

	String s6 = "I'll \"walk\" the <b>dog</b> now";
	auto s7 = s6.escape();
	ASSERT_GT(s7.length(), s6.length());
	ASSERT_TRUE(s7.unescape().equals(s6));
}

TEST(string, number) {
	String s0(1990);
	ASSERT_TRUE(s0.equals("1990"));
	ASSERT_EQ(s0.toInt(), 1990);

	String s1(19902019L);
	ASSERT_TRUE(s1.equals("19902019"));

	String s2(1990.2019);
	ASSERT_TRUE(s2.equals("1990.2019"));
	ASSERT_EQ(s2.toFloat(), 1990.2019);

	String s3(true);
	ASSERT_TRUE(s3.equals("1"));

	String s4(false);
	ASSERT_TRUE(s4.equals("0"));

	String s5(s1);
	ASSERT_EQ(s5.length(), s1.length());
	ASSERT_STREQ(s1.c_str(), s5.c_str());

	ASSERT_GT(s5.hashCode(), 0);

	auto s6 = String::format("str=%s, float=%f, int=%d\n", "hello", 1990.2019, 1990);
	ASSERT_GT(s6.length(), 32);

	String s7("hello");
	auto s8 = s7.upper();
	ASSERT_STREQ(s8.c_str(), "HELLO");

	auto s9 = s8.lower();
	ASSERT_STREQ(s9.c_str(), s7.c_str());
}

TEST(string, equals) {
    auto s = random_bytes(1000);
    String str(s);
    ASSERT_EQ(str.length(), s.length());
    ASSERT_EQ(str.length(), 1000);
    ASSERT_EQ(str.getRefCount(), 2);

    String str2(str.c_str(), str.length());
    ASSERT_TRUE(str.equals(str2, true));
    ASSERT_EQ(str2.getRefCount(), 1);

    String s3("hello world");
    ASSERT_FALSE(str2.equals(s3, true));
}

TEST(string, substr) {
    String str("Hello, World!");
    ASSERT_EQ(str.substr(0, 5), "Hello");
    ASSERT_EQ(str.substr(7, 5), "World");
    ASSERT_EQ(str.substr(-6, 5), "World");
    ASSERT_EQ(str.substr(7, -1), "World");
    ASSERT_EQ(str.substr(-6, -1), "World");
    ASSERT_EQ(str.substr(0, 20), "Hello, World!");
    ASSERT_EQ(str.substr(20, 5), "");
    ASSERT_EQ(str.substr(-20, 5), "Hello");
    ASSERT_EQ(str.substr(-20, -1), "Hello, World");
}

TEST(string, split) {
    String str("one,two,three,four");
    String dim(",");
    Array result = str.split(dim, 2);
    ASSERT_EQ(result.length(), 2);
    ASSERT_STREQ(result[0].toCString(), "one");
    ASSERT_STREQ(result.get(0).toCString(), "one");
    ASSERT_STREQ(result[1].toCString(), "two,three,four");

    result = str.split(dim);
    ASSERT_EQ(result.length(), 4);
    ASSERT_STREQ(result[0].toCString(), "one");
    ASSERT_STREQ(result[1].toCString(), "two");
    ASSERT_STREQ(result[2].toCString(), "three");
    ASSERT_STREQ(result[3].toCString(), "four");
}

TEST(string, replace) {
    String str("<h1>hello world!</h1>");
    str.stripTags("<br>");
    ASSERT_TRUE(str.equals(std::string("hello world!")));

    auto s1 = "'hello world'";
    String s2("'hello world'");
    auto s3 = s2.addSlashes();
    ASSERT_TRUE(s3.equals(std::string("\\'hello world\\'")));

    s3.stripSlashes();
    ASSERT_TRUE(s3.equals(s1));
}

TEST(string, basename) {
    String path("/path/to/file.txt");
    String suffix(".txt");
    ASSERT_EQ(path.basename(suffix), "file");
    ASSERT_EQ(path.basename(String("")), "file.txt");
    path.print();
}

TEST(string, dirname) {
    String path("/path/to/file.txt");
    ASSERT_EQ(path.dirname(), "/path/to");
    path.print();
}

TEST(string, move_ctor) {
    String s("abc");
    String t(std::move(s));
    EXPECT_STREQ(t.c_str(), "abc");
    EXPECT_EQ(s.ptr(), nullptr);
}

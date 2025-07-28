#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

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

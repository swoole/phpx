#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

TEST(string, match) {
    String str("foobarbaz");
    String pattern("/(foo)(bar)(baz)/");

    auto result = str.match(pattern);
    ASSERT_FALSE(result.empty());
    ASSERT_EQ(result.count(), 4);
    ASSERT_TRUE(result.exists(0));
    ASSERT_STREQ(result[0].toString().toCString(), "foobarbaz");
    ASSERT_STREQ(result[1].toString().toCString(), "foo");
    ASSERT_STREQ(result[2].toString().toCString(), "bar");
    ASSERT_STREQ(result[3].toString().toCString(), "baz");

    // Compare with preg_match
    Array preg_result;
    php::preg_match(pattern, str, preg_result.toReference());
    ASSERT_EQ(result[0].toString(), preg_result[0].toString());
    ASSERT_EQ(result[1].toString(), preg_result[1].toString());
}

TEST(string, match_flags) {
    String str("foobarbaz");
    String pattern("/(foo)(bar)(baz)/");

    auto result = str.match(pattern, 256 /* PREG_OFFSET_CAPTURE */);

    ASSERT_TRUE(result.exists(1));
    Array cap1 = result[1];
    ASSERT_EQ(cap1.count(), 2);
    ASSERT_STREQ(cap1[0].toString().toCString(), "foo");
    ASSERT_EQ(cap1[1].toInt(), 0);
}

TEST(string, match_no_match) {
    String str("hello world");
    String pattern("/xyz/");

    auto result = str.match(pattern);
    ASSERT_TRUE(result.empty());
}

TEST(string, matchAll) {
    String html("<b>bold</b><a href=howdy.html>click me</a>");
    String pattern("/(<([\\w]+)[^>]*>)(.*?)(<\\/\\2>)/");

    auto result = html.matchAll(pattern);
    ASSERT_FALSE(result.empty());
    // PATTERN_ORDER: count = 4 capture groups + 1 full match group = 5
    ASSERT_EQ(result.count(), 5);

    // Group 2: tag names across all matches
    ASSERT_TRUE(result.exists(2));
    Array group2 = result[2];
    ASSERT_EQ(group2.count(), 2);
    ASSERT_STREQ(group2[0].toString().toCString(), "b");
    ASSERT_STREQ(group2[1].toString().toCString(), "a");
}

TEST(string, matchAll_set_order) {
    String html("<b>bold</b><a href=howdy.html>click me</a>");
    String pattern("/(<([\\w]+)[^>]*>)(.*?)(<\\/\\2>)/");

    auto result = html.matchAll(pattern, 2 /* PREG_SET_ORDER */);

    ASSERT_EQ(result.count(), 2);

    // With PREG_SET_ORDER, result[0] is the first full match
    ASSERT_TRUE(result.exists(0));
    Array match0 = result[0];
    ASSERT_STREQ(match0[0].toString().toCString(), "<b>bold</b>");
    ASSERT_STREQ(match0[2].toString().toCString(), "b");
}

TEST(string, matchAll_no_match) {
    String str("hello world");
    String pattern("/xyz/");

    auto result = str.matchAll(pattern);
    // preg_match_all with no matches returns [0 => []]
    ASSERT_FALSE(result.empty());
    ASSERT_TRUE(result.exists(0));
    ASSERT_EQ(result[0].toArray().count(), 0);
}

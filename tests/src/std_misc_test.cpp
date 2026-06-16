#include "phpx_test.h"
#include "phpx_std.h"

using namespace php;

// ========================
// Hashing
// ========================

TEST(std_misc, crc32) {
    auto result = fn::crc32("hello");
    ASSERT_EQ(result, 907060870);
    ASSERT_EQ(fn::crc32(""), 0);
}

TEST(std_misc, md5) {
    auto r1 = fn::md5("");
    ASSERT_TRUE(r1.isString());
    ASSERT_STREQ(r1.toString().toCString(), "d41d8cd98f00b204e9800998ecf8427e");

    // raw output
    auto r2 = fn::md5("abc", true);
    ASSERT_TRUE(r2.isString());
    ASSERT_EQ(r2.toString().length(), 16);
}

TEST(std_misc, sha1) {
    auto r1 = fn::sha1("");
    ASSERT_TRUE(r1.isString());
    ASSERT_STREQ(r1.toString().toCString(), "da39a3ee5e6b4b0d3255bfef95601890afd80709");

    // raw output
    auto r2 = fn::sha1("abc", true);
    ASSERT_TRUE(r2.isString());
    ASSERT_EQ(r2.toString().length(), 20);
}

TEST(std_misc, hash) {
    auto r1 = fn::hash("md5", "hello");
    ASSERT_STREQ(r1.toString().toCString(), "5d41402abc4b2a76b9719d911017c592");

    auto r2 = fn::hash("sha256", "hello");
    ASSERT_STREQ(r2.toString().toCString(),
                 "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824");

    // raw output
    auto r3 = fn::hash("md5", "hello", true);
    ASSERT_EQ(r3.toString().length(), 16);
}

// ========================
// Base64
// ========================

TEST(std_misc, base64_encode_decode) {
    auto encoded = fn::base64_encode("hello");
    ASSERT_STREQ(encoded.toCString(), "aGVsbG8=");

    auto decoded = fn::base64_decode("aGVsbG8=");
    ASSERT_TRUE(decoded.isString());
    ASSERT_STREQ(decoded.toString().toCString(), "hello");

    // Strict mode
    auto strict = fn::base64_decode("aGVsbG8=", true);
    ASSERT_STREQ(strict.toString().toCString(), "hello");

    // Empty string
    auto empty = fn::base64_encode("");
    ASSERT_STREQ(empty.toCString(), "");
}

// ========================
// URL encode/decode
// ========================

TEST(std_misc, urlencode_decode) {
    auto encoded = fn::urlencode("hello world");
    ASSERT_STREQ(encoded.toCString(), "hello+world");

    auto decoded = fn::urldecode("hello+world");
    ASSERT_STREQ(decoded.toCString(), "hello world");

    auto special = fn::urlencode("a=1&b=2");
    ASSERT_STREQ(special.toCString(), "a%3D1%26b%3D2");
}

TEST(std_misc, rawurlencode_decode) {
    auto encoded = fn::rawurlencode("hello world");
    ASSERT_STREQ(encoded.toCString(), "hello%20world");

    auto decoded = fn::rawurldecode("hello%20world");
    ASSERT_STREQ(decoded.toCString(), "hello world");
}

// ========================
// Random functions
// ========================

TEST(std_misc, random_int) {
    auto result = fn::random_int(1, 10);
    ASSERT_GE(result, 1);
    ASSERT_LE(result, 10);

    auto same = fn::random_int(5, 5);
    ASSERT_EQ(same, 5);
}

TEST(std_misc, random_bytes) {
    auto bytes = fn::random_bytes(16);
    ASSERT_EQ(bytes.length(), 16);
}

TEST(std_misc, random_bytes_exception) {
    try_call([]() { fn::random_bytes(0); },
             "random_bytes(): Argument #1 ($length) must be greater than 0");
    try_call([]() { fn::random_bytes(-1); },
             "random_bytes(): Argument #1 ($length) must be greater than 0");
}

TEST(std_misc, mt_rand) {
    auto r1 = fn::mt_rand();
    ASSERT_GE(r1, 0);

    auto r2 = fn::mt_rand(1, 100);
    ASSERT_GE(r2, 1);
    ASSERT_LE(r2, 100);
}

TEST(std_misc, rand_func) {
    auto r1 = fn::rand();
    ASSERT_GE(r1, 0);

    auto r2 = fn::rand(10, 20);
    ASSERT_GE(r2, 10);
    ASSERT_LE(r2, 20);
}

// ========================
// JSON
// ========================

TEST(std_misc, json_encode) {
    Array a{1, 2, 3};
    auto json = fn::json_encode(a);
    ASSERT_TRUE(json.isString());
    ASSERT_STREQ(json.toString().toCString(), "[1,2,3]");

    // Assoc array
    Array obj;
    obj.set(String("key"), "value");
    auto json2 = fn::json_encode(obj);
    ASSERT_STREQ(json2.toString().toCString(), "{\"key\":\"value\"}");

    // Scalar
    auto json3 = fn::json_encode(42);
    ASSERT_STREQ(json3.toString().toCString(), "42");

    auto json4 = fn::json_encode("hello");
    ASSERT_STREQ(json4.toString().toCString(), "\"hello\"");
}

TEST(std_misc, json_decode) {
    auto r1 = fn::json_decode("[1,2,3]");
    ASSERT_TRUE(r1.isArray());
    ASSERT_EQ(r1.length(), 3);

    // Assoc
    auto r2 = fn::json_decode("{\"key\":\"value\"}", true);
    ASSERT_TRUE(r2.isArray());
    ASSERT_STREQ(r2.toArray().get("key").toString().toCString(), "value");

    // Scalar
    auto r3 = fn::json_decode("42");
    ASSERT_TRUE(r3.isInt());
    ASSERT_EQ(r3.toInt(), 42);
}

// ========================
// Serialize
// ========================

TEST(std_misc, serialize_unserialize) {
    auto serialized = fn::serialize(42);
    ASSERT_GT(serialized.length(), 0);

    auto unserialized = fn::unserialize(serialized);
    ASSERT_TRUE(unserialized.isInt());
    ASSERT_EQ(unserialized.toInt(), 42);

    // Array
    Array a{1, 2, 3};
    auto ser = fn::serialize(a);
    auto unser = fn::unserialize(ser);
    ASSERT_TRUE(unser.isArray());
    ASSERT_EQ(unser.length(), 3);
}

// ========================
// print_r
// ========================

TEST(std_misc, print_r_func) {
    auto result = fn::print_r(42, true);
    ASSERT_TRUE(result.isString());
    ASSERT_GT(result.toString().length(), 0);
}

// ========================
// uniqid
// ========================

TEST(std_misc, uniqid_func) {
    auto id1 = fn::uniqid();
    ASSERT_GT(id1.length(), 0);

    auto id2 = fn::uniqid("prefix_");
    ASSERT_GT(id2.length(), 8);
    ASSERT_EQ(strncmp(id2.data(), "prefix_", 7), 0);
}

TEST(std_misc, uniqid_more_entropy) {
    auto id1 = fn::uniqid("", true);
    ASSERT_GT(id1.length(), 13);
}

// ========================
// version_compare
// ========================

TEST(std_misc, version_compare) {
    ASSERT_EQ(fn::version_compare("1.0", "1.0").toInt(), 0);
    ASSERT_EQ(fn::version_compare("2.0", "1.0").toInt(), 1);
    ASSERT_EQ(fn::version_compare("1.0", "2.0").toInt(), -1);

    // With operator
    ASSERT_TRUE(fn::version_compare("1.0", "1.0", "=").toBool());
    ASSERT_TRUE(fn::version_compare("2.0", "1.0", ">").toBool());
    ASSERT_TRUE(fn::version_compare("1.0", "2.0", "<").toBool());
    ASSERT_FALSE(fn::version_compare("1.0", "2.0", ">=").toBool());
}

// ========================
// parse_str
// ========================

TEST(std_misc, parse_str) {
    auto result = fn::parse_str("a=1&b=2");
    ASSERT_TRUE(result.isArray());
    ASSERT_EQ(result.length(), 2);
    ASSERT_STREQ(result.toArray().get("a").toString().toCString(), "1");
    ASSERT_STREQ(result.toArray().get("b").toString().toCString(), "2");
}

// ========================
// DateTime
// ========================

TEST(std_misc, time_func) {
    auto t = fn::time();
    ASSERT_GT(t, 0);
}

TEST(std_misc, date_func) {
    auto d1 = fn::date("Y-m-d");
    ASSERT_GT(d1.length(), 0);

    auto d2 = fn::date("Y-m-d", 0);
    ASSERT_STREQ(d2.toCString(), "1970-01-01");
}

TEST(std_misc, strtotime_func) {
    auto ts1 = fn::strtotime("1970-01-01 00:00:00");
    ASSERT_TRUE(ts1.isInt());
    ASSERT_EQ(ts1.toInt(), 0);

    auto ts2 = fn::strtotime("not a valid date string!!!");
    ASSERT_TRUE(ts2.isFalse());
}

// ========================
// Filesystem (in-memory test, no actual filesystem access needed for exist check)
// ========================

TEST(std_misc, file_exists_func) {
    ASSERT_TRUE(fn::file_exists("/etc/passwd"));
    ASSERT_FALSE(fn::file_exists("/tmp/nonexistent_file_xyz_12345"));
}

TEST(std_misc, is_dir_func) {
    ASSERT_TRUE(fn::is_dir("/etc"));
    ASSERT_FALSE(fn::is_dir("/etc/passwd"));
    ASSERT_FALSE(fn::is_dir("/tmp/nonexistent_dir_xyz"));
}

TEST(std_misc, is_file_func) {
    ASSERT_TRUE(fn::is_file("/etc/passwd"));
    ASSERT_FALSE(fn::is_file("/etc"));
}

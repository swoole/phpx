#include "phpx_test.h"

using namespace php;

TEST(hash, md5) {
    constexpr int l = 1024;
    auto rdata = exec("random_bytes", l);
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    String hash1 = md5(str);
    auto hash2 = exec("md5", rdata);
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}

TEST(hash, sha1) {
    constexpr int l = 1024;
    auto rdata = exec("random_bytes", l);
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    String hash1 = sha1(str);
    auto hash2 = exec("sha1", rdata);
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}

TEST(hash, crc32) {
    constexpr int l = 1024;
    auto rdata = exec("random_bytes", l);
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    String hash1 = crc32(str);
    auto hash2 = exec("hash", "crc32", rdata);
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}

TEST(hash, hash) {
    constexpr int l = 1024;
    auto rdata = exec("random_bytes", l);
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    String hash1 = hash("sha256", str);
    auto hash2 = exec("hash", "sha256", rdata);
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}

TEST(hash, hash_hmac) {
    constexpr int l = 1024;
    auto rdata = exec("random_bytes", l);
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    Variant var_key("secret_key");
    auto key = var_key.toString();
    String hash1 = hash_hmac("sha256", str, key);

    auto hash2 = exec("hash_hmac", "sha256", rdata, var_key);
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}
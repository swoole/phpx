#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

static Variant fn_hash_hmac{ZEND_STRL("hash_hmac"), true};
static Variant fn_hash{ZEND_STRL("hash"), true};
static Variant fn_md5{ZEND_STRL("md5"), true};
static Variant fn_sha1{ZEND_STRL("sha1"), true};

TEST(hash, md5) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    String hash1 = md5(str);
    auto hash2 = fn_md5({rdata});
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}

TEST(hash, sha1) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    String hash1 = sha1(str);
    auto hash2 = fn_sha1({rdata});
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}

TEST(hash, crc32) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    String hash1 = crc32(str);
    auto hash2 = fn_hash("crc32", rdata);
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}

TEST(hash, hash) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    String hash1 = hash("sha256", str);
    auto hash2 = fn_hash("sha256", rdata);
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}

TEST(hash, hash_hmac) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    String str(rdata);
    Variant var_key("secret_key");
    auto key = var_key.toString();
    String hash1 = hash_hmac("sha256", str, key);

    auto hash2 = fn_hash_hmac("sha256", rdata, var_key);
    ASSERT_STREQ(hash1.c_str(), hash2.toCString());
}
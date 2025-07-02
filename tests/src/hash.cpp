#include "phpx_test.h"
#include "phpx_func.h"

using namespace php;

TEST(hash, md5) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    auto hash1 = md5(rdata);
    auto hash2 = hash({"md5", rdata});
    ASSERT_STREQ(hash1.toCString(), hash2.toCString());
}

TEST(hash, sha1) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    auto hash1 = sha1(rdata);
    auto hash2 = hash({ "sha1", rdata});
    ASSERT_STREQ(hash1.toCString(), hash2.toCString());
}

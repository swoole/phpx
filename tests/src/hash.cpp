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

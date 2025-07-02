#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_class.h"
#include "const/curl.h"

using namespace php;

static const char *g_date = "2009-02-15";

TEST(caller, func) {
    auto retval = is_dir({"/tmp"});
    ASSERT_TRUE(retval.toBool());

    retval = is_dir({"/tmp-not-exists"});
    ASSERT_FALSE(retval.toBool());
}

TEST(caller, method) {
    auto retval = DateTime::createFromFormat("j-M-Y", "15-Feb-2009");
    ASSERT_TRUE(retval.isObject());
    Object o(retval);
    auto _date = o.exec("format", "Y-m-d");
    ASSERT_STREQ(_date.toCString(), g_date);
}

TEST(caller, redis) {
    Redis redis {};
    Array context{};
    auto ref_context = context.toReference();
    auto rv = redis.connect("127.0.0.1", 6379, 2.5, null, 0, 0, ref_context);
    ASSERT_TRUE(rv.toBool());
    auto val = "hello phpx";
    auto key = "phpx_test_key";
    redis.set(key, val);
    auto val2 = redis.get({key});

    ASSERT_STREQ(val2.toCString(), val);
}

TEST(caller, curl) {
    auto ch = curl_init();
    auto url = "https://www.gov.cn/";
    Array headerArray = {{"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like "
                          "Gecko) Chrome/58.0.3029.110 Safari/537.3"},
                         {"Accept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3"}};
    curl_setopt(ch, CURLOPT_URL, url);
    curl_setopt(ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt(ch, CURLOPT_SSL_VERIFYHOST, false);
    curl_setopt(ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt(ch, CURLOPT_HTTPHEADER, headerArray);
    auto output = curl_exec(ch);
    curl_close(ch);

    ASSERT_FALSE(output.empty());
    ASSERT_TRUE(str_contains(output, "中国").toBool());
}

TEST(caller, call) {
    auto rs = call(php_uname);
    ASSERT_TRUE(rs.isString());
    ASSERT_TRUE(str_contains(rs, "x86_64").isTrue());

    rs = call(php_uname, {"m"});
    ASSERT_TRUE(rs.isString());
    ASSERT_TRUE(str_contains(rs, "x86_64").isTrue());

    Array arr;
    arr.append("m");
    rs = call(php_uname, arr);
    ASSERT_TRUE(rs.isString());
    ASSERT_TRUE(str_contains(rs, "x86_64").isTrue());
}

TEST(caller, http_build_query) {
    Array arr1;
    arr1.set("hello", "world");
    arr1.set("count", 182);
    auto query = http_build_query(arr1, null, "&", PHP_QUERY_RFC1738);

    ASSERT_TRUE(query.isString());
    ASSERT_GT(query.length(), 10);

    String expected = "hello=world&count=182";
    ASSERT_STREQ(query.toCString(), expected.c_str());
}

TEST(caller, md5) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    auto hash1 = md5(rdata);
    auto hash2 = hash({"md5", rdata});
    ASSERT_STREQ(hash1.toCString(), hash2.toCString());
}

TEST(caller, sha1) {
    constexpr int l = 1024;
    auto rdata = random_bytes({l});
    ASSERT_EQ(rdata.length(), l);
    auto hash1 = sha1(rdata);
    auto hash2 = hash({ "sha1", rdata});
    ASSERT_STREQ(hash1.toCString(), hash2.toCString());
}

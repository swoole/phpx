#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_class.h"
#include "phpx_helper.h"

using namespace php;

TEST(facade, redis) {
    Redis redis{};
    redis.connect("127.0.0.1");

    ASSERT_TRUE(redis.set("key1", "value1"));
    ASSERT_TRUE(redis.set("key2", "value2"));
    ASSERT_TRUE(redis.set("key3", "value3"));

    ASSERT_TRUE(redis.exists("key1"));
    ASSERT_TRUE(redis.exists("key2"));

    ASSERT_TRUE(redis.del("key2", "key3"));

    ASSERT_TRUE(redis.exists("key1"));
    ASSERT_FALSE(redis.exists("key2"));
    ASSERT_FALSE(redis.exists("key3"));
}

TEST(facade, uname) {
    auto m = php_uname("m");
    ASSERT_STREQ(m.toCString(), "x86_64");
}

TEST(facade, pdo) {
    var dsn = "mysql:dbname=test;host=127.0.0.1";
    var user = "root";
    var password = "root";

    PDO dbh(dsn, user, password);
    PDOStatement stmt = dbh.query("show tables", PDO::FETCH_NUM);

    while (var result = stmt.fetch()) {
        ASSERT_TRUE(result.isArray());
        var table_name = result.item(0);
        ASSERT_TRUE(table_name.isString());
    }
}

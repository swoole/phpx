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

/*
  +----------------------------------------------------------------------+
  | Swoole                                                               |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "phpx_embed.h"

//#include <swoole.h>
#include <iostream>

using namespace php;
using namespace std;

void test()
{
    cout << "hello world" << endl;
}

void md5test()
{
    echo("[0]hash=%s\n", md5("hello world").c_str());
    echo("[0]hash_hmac=%s\n", hash_hmac("ripemd160", "The quick brown fox jumped over the lazy dog.", "secret").c_str());

    Variant a("hello world");
    echo("[1]hash=%s\n", php::exec("md5", a).toCString());
    echo("[1]hash=%s\n", php::exec("md5", "hello world").toCString());

    echo("[1]hash_hmac=%s\n",
            php::exec("hash_hmac", "ripemd160", "The quick brown fox jumped over the lazy dog.", "secret").toCString());
}

void testRedis()
{
    cout << "=====================Test Redis==================\n";
    Object redis = php::newObject("redis");
    var_dump(redis);
    auto ret1 = redis.exec("connect", "127.0.0.1", 6379);
    //connect success
    if (ret1.toBool())
    {
        auto ret2 = redis.exec("get", "key");
        printf("value=%s\n", ret2.toCString());
    }
    else
    {
        cout << "connect to redis server failed." << endl;
    }
}

void jsontest()
{
    Array arr;
    arr.append(1234);
    arr.append(1234.02);
    arr.append(1234.03);
    arr.append(1234.04);
    arr.append("1234.05");

    Variant json = arr.jsonEncode();
    Variant arr2 = json.jsonDecode();

    echo("json=%s", json.toCString());
    var_dump(arr2);
}

int main(int argc, char * argv[])
{
    php::VM vm(argc, argv);
    String value = ini_get("output_buffering");
    cout << "ENV:" << value.toInt() << endl;


    testRedis();

    vm.include("index.php");
    auto o = newObject("test");

    var_dump(o);
    return 0;

    Array url_params;
    url_params.set("name", "rango");
    url_params.set("value", 1234);

    Array _arg_list;
    Object redis = php::newObject("redis");
    _arg_list.append(redis);

    Variant func = "var_dump";
    php::call(func, _arg_list);

    auto url_query = http_build_query(url_params);
    var_dump(url_query);


//    jsontest();
    md5test();
    return 0;

    vm.eval("echo 'Hello World!';");
    vm.include("embed.php");

    auto a = constant("SWOOLE_BASE");
    cout << "SWOOLE_BASE = " << a.toInt() << endl;

    auto obj = php::newObject("Test");
    auto ret = obj.exec("getName");

    cout << ret.toString() << endl;

    obj.set("name", "Tianfeng");

    auto ret2 = obj.exec("getName");
    cout << ret2.toString() << endl;

    Array arr;
    arr.append(1234);
    arr.append(1234.02);
    arr.append(1234.03);
    arr.append(1234.04);
    arr.append("1234.05");
    var_dump(arr);

    Array arr2 = arr.slice(0, 2);
    var_dump(arr2);

    String s1 = "hello world";
    String s2 = s1.substr(0, 5);
    cout << "s2=" << s2.c_str() << endl;

//    swoole_add_function("test", (void*) test);

    return 0;
}

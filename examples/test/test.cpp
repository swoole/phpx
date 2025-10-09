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
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#include <string>
#include <iostream>

#include "phpx.h"
#include <ext/spl/spl_iterators.h>
#include <swoole_server.h>

using namespace std;
using namespace php;
using namespace swoole;

void cpp_hello_world(Args &args, Variant &retval);
PHPX_FUNCTION(cpp_hello_world2);
PHPX_FUNCTION(cpp_test);
PHPX_FUNCTION(cpp_test2);
PHPX_FUNCTION(cpp_test3);
PHPX_FUNCTION(cpp_test4);
PHPX_FUNCTION(cpp_test5);
void CppClass_construct(Object &_this, Args &args, Variant &retval);

void CppClass_test(Object &_this, Args &args, Variant &retval);
void CppClass_test2(Object &_this, Args &args, Variant &retval);
void CppClass_count(Object &_this, Args &args, Variant &retval);

int test_get_length(Protocol *protocol, Connection *conn, char *data, uint32_t length);
int dispatch_function(Server *serv, Connection *conn, EventData *data);

PHPX_FUNCTION(cpp_test3)
{
    auto a = args[0];
    cout << "type=" << a.type() << endl;
    a = 456;

    return {};
}

PHPX_FUNCTION(cpp_test4)
{
    Object a = args[0];
    var_dump(a);

    return {};
}

PHPX_FUNCTION(cpp_test5)
{
    Object a = args[0];
    Array array;
    array.append(a);
    array.append(true);
    php::exec("dump", array);

    auto v = a.get("name");
    var_dump(v);

    return {};
}

PHPX_EXTENSION()
{
    Extension *ext = new Extension("test", "0.0.1");
    ext->registerFunction(PHPX_FN(cpp_hello_world));
    ext->registerFunction(PHPX_FN(cpp_hello_world2));
    ext->registerFunction(PHPX_FN(cpp_test));

    ArgInfo *info = new ArgInfo(1);
    info->add("array", nullptr, IS_ARRAY, true);

    ext->registerFunction(PHPX_FN(cpp_test2), info);

    ArgInfo *info3 = new ArgInfo(1);
    info3->add("num", nullptr, IS_LONG, true);

    ext->registerFunction(PHPX_FN(cpp_test3), info3);
    ext->registerFunction(PHPX_FN(cpp_test4));
    ext->registerFunction(PHPX_FN(cpp_test5));

    //depends swoole extension
    ext->require("swoole");

    ext->onStart = [ext]
    {
        swoole_add_function("test_get_length", (void *) test_get_length);
        swoole_add_function("my_dispatch_function", (void *) dispatch_function);

        ext->registerConstant("CPP_CONSTANTS_INT", 1234);

//        Array array;
//        array.append("127.0.0.1");
//        array.append(6379);

//        ext->registerConstant("CPP_CONSTANTS_ARRAY", array);

//        string str("test");
//        ext->registerConstant("CPP_CONSTANTS_STRING", str);

        Class *c = new Class("CppClass");
        /**
         * 注册构造方法
         */
        c->addMethod("__construct", CppClass_construct, CONSTRUCT);
        /**
         * 普通方法
         */
        c->addMethod(PHPX_ME(CppClass, test2));
        /**
         * 静态方法
         */
        c->addMethod(PHPX_ME(CppClass, test), STATIC);
        /**
         * 实现接口
         */
        c->implements(spl_ce_Countable);
        c->addMethod("count", CppClass_count);
        /**
         * 添加默认属性
         */
        c->addProperty("name", 1234);
        /**
         * 添加常量
         */
        c->addConstant("VERSION", "1.9.0");
        /**
         * 注册类
         */
        ext->registerClass(c);

        ArgInfo *argInfo = new ArgInfo(1);
        argInfo->add("name");

        Interface *i = new Interface("CppInterface");
        i->addMethod("getName", argInfo);
        ext->registerInterface(i);
    };

    return ext;
}

void testRedis()
{
    cout << "=====================Test Redis==================\n";
    Object redis = php::newObject("redis");
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

void CppClass_construct(Object &_this, Args &args, Variant &retval)
{
    printf("%s _construct\n", _this.getClassName().data());
    Array arr;
    arr.append(1234);
    _this.set("name", arr);
}

void CppClass_test(Object &_this, Args &args, Variant &retval)
{
    printf("CppClass static method call\n");
    //静态方法, _this为null
    //var_dump(_this);
    //var_dump(args);
    retval = "3.1415926";
}

void CppClass_test2(Object &_this, Args &args, Variant &retval)
{
    printf("CppClass method call\n");
    //var_dump(_this);
    //var_dump(args);
    retval = "3.1415926";
}

void CppClass_count(Object &_this, Args &args, Variant &retval)
{
    retval =  1;
}

void cpp_hello_world(Args &args, Variant &retval)
{
    retval = 1236 + args[0].toInt();
}

PHPX_FUNCTION(cpp_hello_world2)
{
    echo("SWOOLE_BASE=%ld\n", php::constant("SWOOLE_BASE").toInt());
    echo("swoole_table::TYPE_INT=%ld\n", php::constant("swoole_table::TYPE_INT").toInt());
    echo("ini[session.gc_maxlifetime=%d]\n", ini_get("session.gc_maxlifetime").toInt());

    Variant argv = args.toArray();
    var_dump(argv);

    Array arr(retval);
    arr.set("key", "key");
    arr.set("value", 12345);

    /**
     * 读取全局变量
     */
    Variant server = global("_SERVER");
    var_dump(server);
    if (server.isArray())
    {
        Variant shell = Array(server)["SHELL"];
        var_dump(shell);
    }
}

PHPX_FUNCTION(cpp_test)
{
    echo("=====================[01]=======================\n");
    printf("key[0] = %s\n", args[0].toCString());
    printf("key[1] = %ld\n", args[1].toInt());
    printf("key[2] = %f\n", args[2].toFloat());
    if (args.count() == 4)
    {
        printf("key[3] = %s\n", args[3].toCString());
    }
    echo("=====================[02]=======================\n");
    /**
     * 调用PHP代码中的test2函数
     */
    Args array;
    array.append(Variant(0));
    array.append(1234);
    array.append(1234.56);
    array.append(Variant());
    array.append("123456789");
    array.append("tianfenghan");

    Variant _retval = php::call("test2", array);
    /**
     * test2函数返回了数组
     */
    if (_retval.isArray())
    {
        //把变量转成数组
        Array arr(retval);
        for (int i = 0; i < arr.count(); i++)
        {
            printf("key[%d] = %s\n", i, arr[i].toStdString().c_str());
        }
    }
    /**
     * test2函数返回了对象
     */
    else if (_retval.isObject())
    {
        echo("=====================[03]=======================\n");
        //把变量转为对象
        Object obj(_retval);

        if (obj.methodExists("hello"))
        {
            cout << "method [hello] exists\n";
        }
        if (obj.methodExists("abc"))
        {
            cout << "method [abc] exists\n";
        }
        if (obj.propertyExists("name"))
        {
            cout << "property [name] exists\n";
        }
        if (obj.propertyExists("test"))
        {
            cout << "property [test] exists\n";
        }

        Args args2;
        args2.append("Get");
        args2.append("POST");
        Variant _array = array.toArray();
        args2.append(_array);

        Array map;
        map.set("myname", "rango");
        map.set("city", "上海");

        for (auto i = map.begin(); i != map.end(); i++)
        {
            Variant key = i.key();
            Variant value = i.value();
            if (key.isString())
            {
                printf("key=%s, value=%s\n", key.toCString(), value.toCString());
            }
            else
            {
                printf("key=%ld,\n", key.toInt());
            }
        }

        args2.append(map);

        /**
         * 设置对象属性
         */
        obj.set("hello", map);

        /**
         * 调用对象的方法
         */
        Variant retval2 = obj.call("abc", args2);
        if (retval2.isArray())
        {
            //把return的变量转成数组
            Array arr2(retval2);
            cout << "key: " << arr2["key"].toStdString() << ", value: " << arr2["value"].toStdString() << endl;
        }
        /**
         * 读取对象属性
         */
        Variant name = obj.get("name");
        cout << "name property: " << name.toStdString() << endl;

        /**
         * 创建一个Test2类的对象
         */
        Object obj2 = php::create("Test2", args2);
        /**
         * 调用它的hello方法
         */
        obj2.exec("hello");

        testRedis();
    }
    else
    {
        cout << "return value=" << _retval.toStdString() << endl;
    }
}

PHPX_FUNCTION(cpp_test2)
{
    auto a = args[0];
    cout << "type=" << a.type() << endl;
    Array arg_0(a);
    arg_0.set("append", true);

    Array arr(a);
    arr.set("layout", "middle");
    var_dump(arr);
}

int test_get_length(Protocol *protocol, Connection *conn, char *data, uint32_t length)
{
    printf("cpp, size=%d\n", length);
    return 100;
}

int dispatch_function(Server *serv, Connection *conn, EventData *data)
{
    int worker_id = rand() % serv->worker_num;
    printf("cpp, dst_worker_id=%d, type=%d, size=%d\n", worker_id, data->info.type, data->info.len);
    return worker_id;
}

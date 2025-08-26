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
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

BEGIN_EXTERN_C()
#include "extension_arginfo.h"
END_EXTERN_C()

#include <iostream>

using namespace php;
using namespace std;

PHPX_FUNCTION(cpp_ext_test) {
    auto argc = args.count();
    for (int i = 0; i < argc; i++) {
        cout << args[i].type() << endl;
    }
    return 1234;
}

PHPX_FUNCTION(cpp_ext_test2) {
    for (int i = 0; i < args.count(); i++) {
        cout << args[i].type() << endl;
    }
    auto v1 = args[0];
    Array arr(v1);
    arr.set(1, "efg");

    return arr;
    // php::echo("argc=%d\n", args.count());
    // php::error(E_WARNING, "extension warning.");
}

PHPX_FUNCTION(cpp_throw_error) {
    throwException("RuntimeException", "phpx exception: test");
    return {};
}

PHPX_FUNCTION(phpx_test3) {
    // pass
    return {};
}

PHPX_FUNCTION(phpx_test4) {
    auto id = args[0].toInt();
    zend_try {
        switch (id) {
        case 0:
            return include(args[1].toString());
        case 1:
            return include_once(args[1].toString());
        case 2:
            return require(args[1].toString());
        case 3:
            return require_once(args[1].toString());
        default:
            break;
        }
    }
    zend_catch {
        auto e = catchException();
        return e;
    }
    zend_end_try();
    return {};
}

PHPX_FUNCTION(phpx_add) {
    return args[0].toInt() + args[1].toInt();
}

PHPX_METHOD(MyClass, test) {
    cout << "MyClass::test" << endl;
    return 1234.56;
}

PHPX_METHOD(MyClass, pget) {
    String *str = _this.oGet<String>("resource", "ResourceString");
    cout << "[GET] ResourceString: " << str->length() << endl;
    return "hello xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
}

PHPX_METHOD(MyClass, pset) {
    String *str = new String("hello world");
    _this.oSet("resource", "ResourceString", str);
    cout << "[SET] ResourceString: " << str->length() << endl;
    return {};
}

PHPX_METHOD(MyClass, add) {
    return args[0].toInt() + args[1].toInt();
}

PHPX_METHOD(MyClass, count) {
    return 100;
}

void string_dtor(zend_resource *res) {
    auto *s = static_cast<String *>(res->ptr);
    delete s;
}

#define ASSERT_TRUE(rs)  if (!rs) { \
    printf("[PHPX] assert failed, at line %s %d\n", __FILE__, __LINE__); \
    exit(255); \
}

#define ASSERT_FALSE(rs) ASSERT_TRUE(!rs)

PHPX_EXTENSION() {
    auto *extension = new Extension("phpx_test", "1.0.2");

    extension->onStart = [extension]() noexcept {
        printf("onStart\n");
        extension->registerConstant("PHPX_CONST_INT", 10002);
        extension->registerConstant("PHPX_CONST_LONG", 10002L);
        extension->registerConstant("PHPX_CONST_FLOAT", 199.188);
        extension->registerConstant("PHPX_CONST_BOOL", true);
        extension->registerConstant("PHPX_CONST_CSTR", "hello world");
        extension->registerConstant("PHPX_CONST_STR", std::string("hello world"));
        extension->registerConstant("PHPX_CONST_CSTR2", ZEND_STRL("hello world"));

        auto *c = new Class("MyClass");
        c->registerFunctions(class_MyClass_methods);
        c->addConstant("TEST_CONSTANT", 8888);
        c->addConstant("TEST_CONSTANT_STR", "hello world");
        c->addProperty("testProperty", "hello world", ZEND_ACC_PUBLIC);
        c->addProperty("testPropertyInt", 9988, ZEND_ACC_PUBLIC);
        c->addStaticProperty("testStaticProperty", "(static) hello world", ZEND_ACC_PUBLIC);
        c->implements(zend_ce_countable);
        c->alias("MyClassAlias");

        auto *e = new Class("MyException");
        e->extends(zend_ce_exception);
        extension->registerClass(e);

        auto *e2 = new Class("MyRuntimeException");
        e2->extends(e);
        extension->registerClass(e2);

        auto *i = new Interface("MyInterface");
        i->registerFunctions(class_MyInterface_methods);
        extension->registerInterface(i);

        c->implements(i);
        extension->registerClass(c);

        // Attributes and constants cannot be added after class registration.
        // There is a protection mechanism at the bottom
        ASSERT_FALSE(c->addConstant("TEST_CONSTANT_ERRgetClassEntry(", 9000));
        ASSERT_FALSE(c->addProperty("prop4", null, PUBLIC));
        ASSERT_FALSE(c->extends(e->ptr()));
        ASSERT_FALSE(c->extends(e));
        ASSERT_FALSE(c->implements(i));
        ASSERT_FALSE(c->alias("TestClass5"));
        ASSERT_FALSE(c->activate());

        extension->registerResource("ResourceString", string_dtor);
        const auto ce = i->ptr();
        printf("ce=%p\n", ce);

        auto ori_info_header = extension->header;
        auto ori_info_body = extension->body;

        // test print info
        extension->info({"phpx_test support", "enabled", "v1.0.0"},
                {
                    {"test", "hello", "world"},
                });
        extension->printInfo();

        // invalid header size test
        extension->info({"phpx_test support", "enabled", "v1.0.0", "more info"},
        {
            {"test", "hello", "world", "swoole", "is", "best"},
        });
        extension->printInfo();

        // invalid row size test
        extension->info({"phpx_test support", "enabled"},
                        {
                            {"test", "hello", "world", "swoole", "is", "best"},
                        });
        extension->printInfo();

        // reset info
        extension->info(ori_info_header, ori_info_body);
        extension->printInfo();
    };

    extension->onShutdown = [extension]() noexcept { cout << extension->name << "shutdown" << endl; };
    extension->onBeforeRequest = [extension]() noexcept { cout << extension->name << "beforeRequest" << endl; };
    extension->onAfterRequest = [extension]() noexcept { cout << extension->name << "afterRequest" << endl; };

    extension->addIniEntry("phpx.test_val", "9999", PHP_INI_ALL);
    extension->registerFunctions(ext_functions);
    extension->require("redis");
    extension->info({"phpx_test support", "enabled"},
                    {
                        {"author", "Rango"},
                        {"version", extension->version},
                        {"date", "2021-02-05"},
                        {"test", "hello", "world"},
                    });

    return extension;
}

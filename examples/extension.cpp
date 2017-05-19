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

#include "phpx.h"

#include <swoole.h>
#include <iostream>

using namespace php;
using namespace std;

PHPX_FUNCTION(cpp_ext_test)
{
    for (int i = 0; i < args.count(); i++)
    {
        cout << args[i].type() << endl;
    }
    retval = 1234;
}

PHPX_FUNCTION(cpp_ext_test2)
{
    for (int i = 0; i < args.count(); i++)
    {
        cout << args[i].type() << endl;
    }
    auto v1 = args[0];
    Array arr(v1);
    arr.set(1, "efg");

    retval = arr;
    //php::echo("argc=%d\n", args.count());
    //php::error(E_WARNING, "extension warning.");
}

PHPX_METHOD(myClass, test)
{
    cout << "myClass::test" << endl;
    retval = 1234.56;
}

PHPX_METHOD(myClass, pget)
{
    auto res = _this.get("resource");
    auto str = res.toResource<String>("ResourceString");
    cout << "ResourceString: " << str->length() << endl;
    retval = res;
}

PHPX_METHOD(myClass, pset)
{
    auto res = newResource("ResourceString", new String("hello world"));
    _this.set("resource", res);
}

void string_dtor(zend_resource *res)
{
    String *s = static_cast<String *>(res->ptr);
    delete s;
}

PHPX_EXTENSION()
{
    Extension *extension = new Extension("cpp_ext", "0.0.1");

    extension->onStart = [extension]() noexcept
    {
        extension->registerConstant("CPP_EXT_VERSION", 1002);

        Class *c = new Class("myClass");
        c->addMethod("test", myClass_test, STATIC);
        c->addMethod("pget", myClass_pget);
        c->addMethod("pset", myClass_pset);
        extension->registerClass(c);

        swoole_add_function("test", (void*) string_dtor);

        extension->registerResource("ResourceString", string_dtor);
    };

//    extension->onShutdown = [extension]() noexcept
//    {
//        cout << extension->name << "shutdown" << endl;
//    };
//
//    extension->onBeforeRequest = [extension]() noexcept
//    {
//        cout << extension->name << "beforeRequest" << endl;
//    };
//
//    extension->onAfterRequest = [extension]() noexcept
//    {
//        cout << extension->name << "afterRequest" << endl;
//    };

    extension->registerFunction(PHPX_NAME(cpp_ext_test));
    extension->registerFunction(PHPX_NAME(cpp_ext_test2));

    return extension;
}

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
    retval = 1234;
}

PHPX_METHOD(myClass, test)
{
    cout << "myClass::test" << endl;
    retval = 1234;
}

PHPX_EXTENSION
{
    Extension *extension = new Extension("cpp_ext", "0.0.1");

    extension->onStart = [extension]() noexcept
    {
        cout << extension->name << "startup" << endl;
        extension->registerConstant("CPP_EXT_VERSION", 1002);

        Class *c = new Class("myClass");
        c->addMethod("test", myClass_test, STATIC);
        extension->registerClass(c);
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

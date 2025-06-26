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

BEGIN_EXTERN_C()
#if PHP_VERSION_ID < 80000
#include "extension_legacy_arginfo.h"
#else
#include "extension_arginfo.h"
#endif
END_EXTERN_C()

#include <iostream>

using namespace php;
using namespace std;

PHPX_FUNCTION(cpp_ext_test) {
    for (int i = 0; i < args.count(); i++) {
        cout << args[i].type() << endl;
    }
    retval = 1234;
}

PHPX_FUNCTION(cpp_ext_test2) {
    for (int i = 0; i < args.count(); i++) {
        cout << args[i].type() << endl;
    }
    auto v1 = args[0];
    Array arr(v1);
    arr.set(1, "efg");

    retval = arr;
    // php::echo("argc=%d\n", args.count());
    // php::error(E_WARNING, "extension warning.");
}

PHPX_METHOD(MyClass, test) {
    cout << "MyClass::test" << endl;
    retval = 1234.56;
}

PHPX_METHOD(MyClass, pget) {
    String *str = _this.oGet<String>("resource", "ResourceString");
    cout << "[GET] ResourceString: " << str->length() << endl;
    retval = Variant("hello xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
}

PHPX_METHOD(MyClass, pset) {
    String *str = new String("hello world");
    _this.oSet("resource", "ResourceString", str);
    cout << "[SET] ResourceString: " << str->length() << endl;
}

void string_dtor(zend_resource *res) {
    String *s = static_cast<String *>(res->ptr);
    delete s;
}

PHPX_EXTENSION() {
    Extension *extension = new Extension("cpp_ext", "1.0.2");

    extension->onStart = [extension]() noexcept {
        extension->registerConstant("CPP_EXT_VERSION", 10002);

        Class *c = new Class("MyClass");
        c->registerFunctions(class_MyClass_methods);

        extension->registerClass(c);

        Interface *i = new Interface("MyInterface");
        i->registerFunctions(class_MyInterface_methods);
        extension->registerInterface(i);

        extension->registerResource("ResourceString", string_dtor);
    };

    extension->onShutdown = [extension]() noexcept { cout << extension->name << "shutdown" << endl; };
    extension->onBeforeRequest = [extension]() noexcept { cout << extension->name << "beforeRequest" << endl; };
    extension->onAfterRequest = [extension]() noexcept { cout << extension->name << "afterRequest" << endl; };
    extension->registerFunctions(ext_functions);
    extension->info({"cpp_ext support", "enabled"},
                    {
                        {"author", "Rango"},
                        {"version", extension->version},
                        {"date", "2021-02-05"},
                    });

    return extension;
}

/*
  +----------------------------------------------------------------------+
  | PHP-X                                                               |
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

extern "C"
{
#include <ext/hash/php_hash.h>
}

using namespace std;

namespace php
{

Object newObject(const char *name)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        php_error_docref(NULL, E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    object.call("__construct", args);
    return object;
}

/*generator-1*/

/*generator-1*/

/*generator*/
Object newObject(const char *name, Variant v1)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2, Variant v3)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    v7.addRef();
    args.append(v7.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    v7.addRef();
    args.append(v7.ptr());
    v8.addRef();
    args.append(v8.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8, Variant v9)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    v7.addRef();
    args.append(v7.ptr());
    v8.addRef();
    args.append(v8.ptr());
    v9.addRef();
    args.append(v9.ptr());
    object.call("__construct", args);
    return object;
}

Object newObject(const char *name, Variant v1, Variant v2, Variant v3, Variant v4, Variant v5, Variant v6, Variant v7, Variant v8, Variant v9, Variant v10)
{
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE)
    {
        return object;
    }
    Array args;
    v1.addRef();
    args.append(v1.ptr());
    v2.addRef();
    args.append(v2.ptr());
    v3.addRef();
    args.append(v3.ptr());
    v4.addRef();
    args.append(v4.ptr());
    v5.addRef();
    args.append(v5.ptr());
    v6.addRef();
    args.append(v6.ptr());
    v7.addRef();
    args.append(v7.ptr());
    v8.addRef();
    args.append(v8.ptr());
    v9.addRef();
    args.append(v9.ptr());
    v10.addRef();
    args.append(v10.ptr());
    object.call("__construct", args);
    return object;
}
/*generator*/

}



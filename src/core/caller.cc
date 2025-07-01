/*
+----------------------------------------------------------------------+
| PHP-X                                                                |
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

namespace php {
Variant Variant::operator()(const Variant &v1) const {
    Args args;
    args.append(v1);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(const Variant &v1, const Variant &v2) const {
    Args args;
    args.append(v1);
    args.append(v2);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(const Variant &v1, const Variant &v2, const Variant &v3) const {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4) const {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(
    const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4, const Variant &v5) const {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(const Variant &v1,
                            const Variant &v2,
                            const Variant &v3,
                            const Variant &v4,
                            const Variant &v5,
                            const Variant &v6) const {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(const Variant &v1,
                            const Variant &v2,
                            const Variant &v3,
                            const Variant &v4,
                            const Variant &v5,
                            const Variant &v6,
                            const Variant &v7) const {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(const Variant &v1,
                            const Variant &v2,
                            const Variant &v3,
                            const Variant &v4,
                            const Variant &v5,
                            const Variant &v6,
                            const Variant &v7,
                            const Variant &v8) const {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(const Variant &v1,
                            const Variant &v2,
                            const Variant &v3,
                            const Variant &v4,
                            const Variant &v5,
                            const Variant &v6,
                            const Variant &v7,
                            const Variant &v8,
                            const Variant &v9) const {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    args.append(v9);
    return _call(nullptr, const_ptr(), args);
}
Variant Variant::operator()(const Variant &v1,
                            const Variant &v2,
                            const Variant &v3,
                            const Variant &v4,
                            const Variant &v5,
                            const Variant &v6,
                            const Variant &v7,
                            const Variant &v8,
                            const Variant &v9,
                            const Variant &v10) const {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    args.append(v9);
    args.append(v10);
    return _call(nullptr, const_ptr(), args);
}
Object newObject(const char *name, const Variant &v1) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, const Variant &v1, const Variant &v2) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, const Variant &v1, const Variant &v2, const Variant &v3) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    object.call("__construct", args);
    return object;
}
Object newObject(
    const char *name, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4, const Variant &v5) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7,
                 const Variant &v8) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7,
                 const Variant &v8,
                 const Variant &v9) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    args.append(v9);
    object.call("__construct", args);
    return object;
}
Object newObject(const char *name,
                 const Variant &v1,
                 const Variant &v2,
                 const Variant &v3,
                 const Variant &v4,
                 const Variant &v5,
                 const Variant &v6,
                 const Variant &v7,
                 const Variant &v8,
                 const Variant &v9,
                 const Variant &v10) {
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    args.append(v9);
    args.append(v10);
    object.call("__construct", args);
    return object;
}
Variant Object::exec(const Variant &fn, const Variant &v1) {
    Args args;
    args.append(v1);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(const Variant &fn, const Variant &v1, const Variant &v2) {
    Args args;
    args.append(v1);
    args.append(v2);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(const Variant &fn, const Variant &v1, const Variant &v2, const Variant &v3) {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(const Variant &fn, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4) {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(
    const Variant &fn, const Variant &v1, const Variant &v2, const Variant &v3, const Variant &v4, const Variant &v5) {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(const Variant &fn,
                     const Variant &v1,
                     const Variant &v2,
                     const Variant &v3,
                     const Variant &v4,
                     const Variant &v5,
                     const Variant &v6) {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(const Variant &fn,
                     const Variant &v1,
                     const Variant &v2,
                     const Variant &v3,
                     const Variant &v4,
                     const Variant &v5,
                     const Variant &v6,
                     const Variant &v7) {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(const Variant &fn,
                     const Variant &v1,
                     const Variant &v2,
                     const Variant &v3,
                     const Variant &v4,
                     const Variant &v5,
                     const Variant &v6,
                     const Variant &v7,
                     const Variant &v8) {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(const Variant &fn,
                     const Variant &v1,
                     const Variant &v2,
                     const Variant &v3,
                     const Variant &v4,
                     const Variant &v5,
                     const Variant &v6,
                     const Variant &v7,
                     const Variant &v8,
                     const Variant &v9) {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    args.append(v9);
    return _call(ptr(), fn.const_ptr(), args);
}
Variant Object::exec(const Variant &fn,
                     const Variant &v1,
                     const Variant &v2,
                     const Variant &v3,
                     const Variant &v4,
                     const Variant &v5,
                     const Variant &v6,
                     const Variant &v7,
                     const Variant &v8,
                     const Variant &v9,
                     const Variant &v10) {
    Args args;
    args.append(v1);
    args.append(v2);
    args.append(v3);
    args.append(v4);
    args.append(v5);
    args.append(v6);
    args.append(v7);
    args.append(v8);
    args.append(v9);
    args.append(v10);
    return _call(ptr(), fn.const_ptr(), args);
}
}  // namespace php

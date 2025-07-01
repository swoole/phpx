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
| Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
+----------------------------------------------------------------------+
*/

#include "phpx.h"

extern "C" {
#include <ext/hash/php_hash.h>
}

namespace php {
<?php for ($i = 1; $i <= $maxArgc; $i++): ?>
Variant Variant::operator()(<?=self::makeArgs($i)?>) const {
    Args args;
<?php for ($j = 1; $j <= $i; $j++) :?>
    args.append(v<?=$j?>);
<?php endfor; ?>
    return _call(nullptr, const_ptr(), args);
}

Object newObject(const char *name, <?=self::makeArgs($i)?>) {
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
<?php for ($j = 1; $j <= $i; $j++) :?>
    args.append(v<?=$j?>);
<?php endfor; ?>
    object.call("__construct", args);
    return object;
}

Variant Object::exec(const char *func, <?=self::makeArgs($i)?>) {
    Variant _func(func);
    Args args;
<?php for ($j = 1; $j <= $i; $j++) :?>
    args.append(v<?=$j?>);
<?php endfor; ?>
    return _call(ptr(), _func.const_ptr(), args);
}
<?php endfor; ?>
}

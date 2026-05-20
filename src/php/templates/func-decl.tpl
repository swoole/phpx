#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
<?php foreach ($functions as $name => $fn): ?>
<?php if ($fn['variadic']): ?>
template <typename... Args>
Variant <?=$name?>(<?=$fn['args_impl']?>) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(<?=$fn['symbol']?>);
    }
    return call(fn, <?=$fn['call']?>);
}
<?php else: ?>
Variant <?=$name?>(<?=$fn['args']?>);
<?php endif; ?>
<?php endforeach; ?>
}

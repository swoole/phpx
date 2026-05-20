#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

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
<?=($fn['return_type'] ?? 'Variant')?> <?=$name?>(<?=$fn['args']?>);
<?php if (!empty($fn['has_facade_params'])): ?>
Variant <?=$name?>(<?=$fn['args_v']?>);
<?php endif; ?>
<?php endif; ?>
<?php endforeach; ?>
}

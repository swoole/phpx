#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
<?php foreach ($functions as $name => $fn): ?>
<?php if (!$fn['variadic']): ?>
<?=($fn['return_type'] ?? 'Variant')?> <?=$name?>(<?=$fn['args_impl']?>) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(<?=$fn['symbol']?>);
    }
<?php if (!empty($fn['return_body'])): ?>
    <?=$fn['return_body']?>

<?php endif; ?>
<?php if (!empty($fn['return_expr'])): ?>
    return <?=$fn['return_expr']?>;
<?php else: ?>
    return call(fn, <?=$fn['call']?>);
<?php endif; ?>
}
<?php if (!empty($fn['has_facade_params'])): ?>
Variant <?=$name?>(<?=$fn['args_impl_v']?>) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(<?=$fn['symbol']?>);
    }
    return call(fn, <?=$fn['call_v']?>);
}
<?php endif; ?>
<?php endif; ?>
<?php endforeach; ?>
}

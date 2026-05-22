#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

<?php foreach ($groupedFunctions as $nsKey => $nsFuncs): ?>
<?php if ($nsKey === ''): ?>
namespace php {
<?php else: ?>
namespace php::<?=$nsKey?> {
<?php endif; ?>
<?php foreach ($nsFuncs as $shortName => $fn): ?>
<?php if (!$fn['variadic']): ?>
<?=($fn['return_type'] ?? 'Variant')?> <?=$shortName?>(<?=$fn['args_impl']?>) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(<?=$fn['symbol']?>);
    }
<?php if (!empty($fn['return_body'])): ?>
    <?=$fn['return_body']?>

<?php endif; ?>
<?php if (!empty($fn['return_expr'])): ?>
    return <?=$fn['return_expr']?>;
<?php else: ?>
    return call(_fn, <?=$fn['call']?>);
<?php endif; ?>
}
<?php if (!empty($fn['has_facade_params'])): ?>
Variant <?=$shortName?>(<?=$fn['args_impl_v']?>) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(<?=$fn['symbol']?>);
    }
    return call(_fn, <?=$fn['call_v']?>);
}
<?php endif; ?>
<?php endif; ?>
<?php endforeach; ?>
}
<?php endforeach; ?>

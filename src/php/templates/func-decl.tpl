#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
<?php foreach ($groupedFunctions as $nsKey => $nsFuncs): ?>
<?php if ($nsKey !== ''): ?>
namespace <?=$nsKey?> {
<?php endif; ?>

<?php foreach ($nsFuncs as $shortName => $fn): ?>
<?php if ($fn['variadic']): ?>
template <typename... Args>
Variant <?=$shortName?>(<?=$fn['args_impl']?>) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(<?=$fn['symbol']?>);
    }
    return call(fn, <?=$fn['call']?>);
}
<?php else: ?>
<?=($fn['return_type'] ?? 'Variant')?> <?=$shortName?>(<?=$fn['args']?>);
<?php if (!empty($fn['has_facade_params'])): ?>
Variant <?=$shortName?>(<?=$fn['args_v']?>);
<?php endif; ?>
<?php endif; ?>
<?php endforeach; ?>

<?php if ($nsKey !== ''): ?>
}
<?php endif; ?>
<?php endforeach; ?>
}

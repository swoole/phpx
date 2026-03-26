#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
<?php foreach ($functions as $name => $fn): ?>
<?php if ($fn['variadic']): ?>
template <typename... Args>
Variant <?=$name?>(<?=$fn['args_impl']?>) {
    return call(<?=$fn['symbol']?>, <?=$fn['call']?>);
}
<?php else: ?>
Variant <?=$name?>(<?=$fn['args']?>);
<?php endif; ?>
<?php endforeach; ?>
}

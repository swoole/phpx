#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
<?php foreach ($functions as $name => $fn): ?>
<?php if (!$fn['variadic']): ?>
Variant <?=$name?>(<?=$fn['args_impl']?>) {
    return call(<?=$fn['symbol']?>, <?=$fn['call']?>);
}
<?php endif; ?>
<?php endforeach; ?>
}

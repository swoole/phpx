namespace php {
<?php foreach ($functions as $fn): ?>
<?php if ($fn['variadic']): ?>
template <typename... Args>
Variant <?=$fn['name']?>(<?=$fn['args_impl']?>) {
    return call("<?=$fn['name']?>", <?=$fn['call']?>);
}
<?php else: ?>
Variant <?=$fn['name']?>(<?=$fn['args']?>);
<?php endif; ?>
<?php endforeach; ?>
}

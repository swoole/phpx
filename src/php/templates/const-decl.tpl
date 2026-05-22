namespace php {
<?php foreach ($groupedConstants as $nsKey => $nsConsts): ?>
<?php if ($nsKey !== ''): ?>
namespace <?=$nsKey?> {
<?php endif; ?>
<?php foreach ($nsConsts as $name => $repr): ?>
extern Variant <?=$name?>;
<?php endforeach; ?>
<?php if ($nsKey !== ''): ?>
}
<?php endif; ?>
<?php endforeach; ?>
}

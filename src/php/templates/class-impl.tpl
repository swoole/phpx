#include "phpx.h"
#include "class/<?= $ext ?>.h"
<?php if (!empty($classIncludes)): ?>
<?php foreach ($classIncludes as $inc): ?>
#include "class/<?=$inc?>.h"
<?php endforeach; ?>
<?php endif; ?>

<?php foreach ($groupedClasses as $nsKey => $nsClasses): ?>
<?php if ($nsKey === ''): ?>
namespace php {
<?php else: ?>
namespace php::<?=$nsKey?> {
<?php endif; ?>
<?php foreach ($nsClasses as $shortName => $info): ?>
<?php foreach ($info['methods'] as $name => $minfo): ?>
<?php if (!$minfo['variadic']):?>
<?=$minfo['impl_code']?>
<?php if (!empty($minfo['impl_code_v'])): ?>
<?=$minfo['impl_code_v']?>
<?php endif; ?>
<?php endif;?>
<?php endforeach; ?>
<?php endforeach; ?>
}
<?php endforeach; ?>

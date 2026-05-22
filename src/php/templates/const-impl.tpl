#include "phpx.h"

<?php foreach ($groupedConstants as $nsKey => $nsConsts): ?>
<?php if ($nsKey === ''): ?>
namespace php {
<?php else: ?>
namespace php::<?=$nsKey?> {
<?php endif; ?>
<?php foreach ($nsConsts as $name => $repr): ?>
Variant <?=$name?> { <?=$repr?> };
<?php endforeach; ?>
}
<?php endforeach; ?>

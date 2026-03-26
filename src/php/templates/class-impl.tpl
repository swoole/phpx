#include "phpx.h"
#include "class/<?= $ext ?>.h"

namespace php {
<?php foreach ($classes as $className => $info): ?>
<?php foreach ($info['methods'] as $name => $minfo): ?>
<?php if (!$minfo['variadic']):?>
<?=$minfo['impl_code']?>
<?php endif;?>
<?php endforeach; ?>
<?php endforeach; ?>
}

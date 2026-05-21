#include "phpx.h"
#include "phpx_class.h"
#include "class/<?= $ext ?>.h"

namespace php {
<?php foreach ($classes as $className => $info): ?>
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

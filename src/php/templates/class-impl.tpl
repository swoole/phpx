#include "phpx.h"
#include "class/<?= $ext ?>.h"

namespace php {
<?php foreach ($classes as $className => $info): ?>
<?php foreach ($info['methods'] as $name => $minfo): ?>
<?=!$minfo['ctor'] ? 'Variant ' : '' ?><?=$className?>::<?=$name?>(<?=$minfo['args_impl']?>) {
<?php if ($minfo['ctor']): ?>
    _this = newObject(<?=$info['class']?><?=$minfo['call']?>);
<?php elseif ($minfo['static']): ?>
    static Variant fn { ZEND_STRL("<?=$className?>::<?=$name?>"), true };
    return fn(<?=$minfo['call']?>);
<?php else: ?>
    return std::move(_this.exec("<?=$minfo['name']?>"<?=$minfo['call']?>));
<?php endif; ?>
}

<?php endforeach; ?>

<?php endforeach; ?>
}

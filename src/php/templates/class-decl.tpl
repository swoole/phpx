#include "phpx_literal_string.h"

namespace php {
<?php foreach ($classes as $className => $info): ?>
class <?=$className?> {
    Object this_;
  public:
<?php foreach ($info['methods'] as $name => $minfo): ?>
<?php if ($minfo['variadic']): ?>
    template <typename... Args>
    <?=$minfo['impl_code']?>
<?php else: ?>
    <?=$minfo['static'] ? 'static ' : '' ?><?=!$minfo['ctor'] ? 'Variant ' : '' ?><?= $name ?>(<?= $minfo['args'] ?>);
<?php endif; ?>
<?php endforeach; ?>
};

<?php endforeach; ?>
}

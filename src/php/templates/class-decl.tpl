#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
<?php foreach ($classes as $className => $info): ?>
class <?=$className?> {
    Object this_;
  public:
    Object getObject() const {
        return this_;
    }
<?php if (!$info['has_ctor']): ?>
    explicit <?=$className?>(const Object &obj) : this_(obj) {}
<?php endif; ?>
<?php foreach ($info['methods'] as $name => $minfo): ?>
<?php if ($minfo['variadic']): ?>
    template <typename... Args>
    <?=$minfo['impl_code']?>
<?php else: ?>
    <?=$minfo['static'] ? 'static ' : '' ?><?=!$minfo['ctor'] ? ($minfo['return_type'] ?? 'Variant') . ' ' : '' ?><?= $name ?>(<?= $minfo['args'] ?>);
<?php if (!empty($minfo['has_facade_params']) && !$minfo['ctor']): ?>
    Variant <?= $name ?>(<?= $minfo['args_v'] ?>);
<?php endif; ?>
<?php endif; ?>
<?php endforeach; ?>
};

<?php endforeach; ?>
}

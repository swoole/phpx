#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
<?php if (!empty($classIncludes)): ?>
<?php foreach ($classIncludes as $inc): ?>
#include "class/<?=$inc?>.h"
<?php endforeach; ?>
<?php endif; ?>

namespace php {
<?php foreach ($classes as $className => $info): ?>
class <?=$className?>;
<?php endforeach; ?>

<?php foreach ($classes as $className => $info): ?>
class <?=$className?><?php if (!empty($info['extends'])): ?> : public <?=$info['extends']?><?php endif; ?> {
<?php if (empty($info['extends'])): ?>
  protected:
    Object this_;
<?php if (!empty($info['needs_protected_ctor'])): ?>
    <?=$className?>() = default;
<?php endif; ?>
  public:
    Object getObject() const {
        return this_;
    }
<?php if (!$info['has_ctor']): ?>
    explicit <?=$className?>(const Object &obj) : this_(obj) {}
<?php endif; ?>
<?php else: ?>
<?php if (!empty($info['needs_protected_ctor'])): ?>
  protected:
    <?=$className?>() = default;
<?php endif; ?>
  public:
<?php if (!$info['has_ctor'] && !$info['parent_has_ctor']): ?>
    explicit <?=$className?>(const Object &obj) : <?=$info['extends']?>(obj) {}
<?php elseif (!$info['has_ctor'] && $info['parent_has_ctor']): ?>
    explicit <?=$className?>(const Object &obj) {
        this_ = obj;
    }
<?php endif; ?>
<?php endif; ?>
<?php if (!empty($info['constants'])): ?>
<?php foreach ($info['constants'] as $cname => $cinfo): ?>
<?php if (!empty($cinfo['inline_init'])): ?>
    static inline const Variant <?=$cname?>{<?=$cinfo['repr']?>};
<?php else: ?>
    static constexpr <?=$cinfo['type']?> <?=$cname?> = <?=$cinfo['repr']?>;
<?php endif; ?>
<?php endforeach; ?>

<?php endif; ?>
<?php foreach ($info['methods'] as $name => $minfo): ?>
<?php if ($minfo['variadic']): ?>
    template <typename... Args>
    <?=$minfo['impl_code']?>
<?php else: ?>
    <?=$minfo['static'] ? 'static ' : '' ?><?=!$minfo['ctor'] ? ($minfo['return_type'] ?? 'Variant') . ' ' : '' ?><?= $name ?>(<?= $minfo['args'] ?>);
<?php if (!empty($minfo['has_facade_params']) && !$minfo['ctor']): ?>
    <?=$minfo['static'] ? 'static ' : '' ?>Variant <?= $name ?>(<?= $minfo['args_v'] ?>);
<?php endif; ?>
<?php endif; ?>
<?php endforeach; ?>
};

<?php endforeach; ?>
}

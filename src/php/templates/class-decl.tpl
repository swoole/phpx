namespace php {
<?php foreach ($classes as $name => $info): ?>
class <?=$name?> {
    Object this_;
  public:
<?php foreach ($info['methods'] as $name => $minfo): ?>
<?php if ($minfo['variadic']): ?>
    template <typename... Args>
    Variant <?=$name?>(<?=$minfo['args_impl']?>) {
        return call("<?=$name?>", <?=$minfo['call']?>);
    }
<?php else: ?>
    <?=$minfo['static'] ? 'static ' : '' ?><?=!$minfo['ctor'] ? 'Variant ' : '' ?><?= $name ?>(<?= $minfo['args'] ?>);
<?php endif; ?>
<?php endforeach; ?>
};

<?php endforeach; ?>
}

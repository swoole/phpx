namespace php {
<?php foreach ($classes as $name => $info): ?>
class <?=$name?> {
    Object this_;
  public:
<?php foreach ($info['methods'] as $name => $minfo): ?>
    <?=$minfo['static'] ? 'static ' : '' ?><?=!$minfo['ctor'] ? 'Variant ' : '' ?><?= $name ?>(<?= $minfo['args'] ?>);
<?php endforeach; ?>
};

<?php endforeach; ?>
}

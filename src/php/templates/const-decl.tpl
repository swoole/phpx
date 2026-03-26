namespace php {
<?php foreach ($constants as $name => $const): ?>
extern Variant <?=$name?>;
<?php endforeach; ?>
}

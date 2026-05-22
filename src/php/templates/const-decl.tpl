namespace php {
<?php foreach ($constants as $name => $repr): ?>
extern Variant <?=$name?>;
<?php endforeach; ?>
}

#include "phpx.h"

namespace php {
<?php foreach ($constants as $name => $const): ?>
Variant <?=$name?> { <?=$const?> };
<?php endforeach; ?>
}

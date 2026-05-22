#include "phpx.h"

namespace php {
<?php foreach ($constants as $name => $repr): ?>
Variant <?=$name?> { <?=$repr?> };
<?php endforeach; ?>
}

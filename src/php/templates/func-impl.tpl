#include "phpx.h"

namespace php {
<?php foreach ($functions as $fn): ?>
Variant <?=$fn?>{ZEND_STRL("<?=$fn?>"), true};
<?php endforeach; ?>
}

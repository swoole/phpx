#include "phpx.h"

namespace php {
Variant simplexml_load_file{ZEND_STRL("simplexml_load_file"), true};
Variant simplexml_load_string{ZEND_STRL("simplexml_load_string"), true};
Variant simplexml_import_dom{ZEND_STRL("simplexml_import_dom"), true};
}

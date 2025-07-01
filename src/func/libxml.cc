#include "phpx.h"

namespace php {
Variant libxml_set_streams_context{ZEND_STRL("libxml_set_streams_context"), true};
Variant libxml_use_internal_errors{ZEND_STRL("libxml_use_internal_errors"), true};
Variant libxml_get_last_error{ZEND_STRL("libxml_get_last_error"), true};
Variant libxml_get_errors{ZEND_STRL("libxml_get_errors"), true};
Variant libxml_clear_errors{ZEND_STRL("libxml_clear_errors"), true};
Variant libxml_disable_entity_loader{ZEND_STRL("libxml_disable_entity_loader"), true};
Variant libxml_set_external_entity_loader{ZEND_STRL("libxml_set_external_entity_loader"), true};
Variant libxml_get_external_entity_loader{ZEND_STRL("libxml_get_external_entity_loader"), true};
}

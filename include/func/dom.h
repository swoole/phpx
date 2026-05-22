#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant dom_import_simplexml(const Variant &node);

namespace Dom {

Variant import_simplexml(const Variant &node);

}
}  // namespace php

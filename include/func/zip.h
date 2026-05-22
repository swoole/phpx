#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant zip_open(const Variant &filename);
Variant zip_close(const Variant &zip);
Variant zip_read(const Variant &zip);
Variant zip_entry_open(const Variant &zip_dp, const Variant &zip_entry, const Variant &mode = "rb");
Variant zip_entry_close(const Variant &zip_entry);
Variant zip_entry_read(const Variant &zip_entry, const Variant &len = 1024);
Variant zip_entry_name(const Variant &zip_entry);
Variant zip_entry_compressedsize(const Variant &zip_entry);
Variant zip_entry_filesize(const Variant &zip_entry);
Variant zip_entry_compressionmethod(const Variant &zip_entry);

}  // namespace php

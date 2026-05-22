#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant bzopen(const Variant &file, const Variant &mode);
Variant bzread(const Variant &bz, const Variant &length = 1024);
Variant bzwrite(const Variant &bz, const Variant &data, const Variant &length = {});
Variant bzflush(const Variant &bz);
Variant bzclose(const Variant &bz);
Variant bzerrno(const Variant &bz);
Variant bzerrstr(const Variant &bz);
Variant bzerror(const Variant &bz);
Variant bzcompress(const Variant &data, const Variant &block_size = 4, const Variant &work_factor = 0);
Variant bzdecompress(const Variant &data, const Variant &use_less_memory = false);

}  // namespace php

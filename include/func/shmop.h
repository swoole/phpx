#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Shmop shmop_open(const Variant &key, const Variant &mode, const Variant &permissions, const Variant &size);
Variant shmop_read(const Shmop &shmop, const Variant &offset, const Variant &size);
Variant shmop_read(const Variant &shmop, const Variant &offset, const Variant &size);
Variant shmop_close(const Shmop &shmop);
Variant shmop_close(const Variant &shmop);
Variant shmop_size(const Shmop &shmop);
Variant shmop_size(const Variant &shmop);
Variant shmop_write(const Shmop &shmop, const Variant &data, const Variant &offset);
Variant shmop_write(const Variant &shmop, const Variant &data, const Variant &offset);
Variant shmop_delete(const Shmop &shmop);
Variant shmop_delete(const Variant &shmop);

}  // namespace php

#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant finfo_open(const Variant &flags = 0, const Variant &magic_database = {});
Variant finfo_close(const finfo &finfo);
Variant finfo_close(const Variant &finfo);
Variant finfo_set_flags(const finfo &finfo, const Variant &flags);
Variant finfo_set_flags(const Variant &finfo, const Variant &flags);
Variant finfo_file(const finfo &finfo, const Variant &filename, const Variant &flags = 0, const Variant &context = {});
Variant finfo_file(const Variant &finfo,
                   const Variant &filename,
                   const Variant &flags = 0,
                   const Variant &context = {});
Variant finfo_buffer(const finfo &finfo, const Variant &string, const Variant &flags = 0, const Variant &context = {});
Variant finfo_buffer(const Variant &finfo,
                     const Variant &string,
                     const Variant &flags = 0,
                     const Variant &context = {});
Variant mime_content_type(const Variant &filename);

}  // namespace php

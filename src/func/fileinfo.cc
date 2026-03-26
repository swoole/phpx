#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant finfo_open(const Variant &flags, const Variant &magic_database) {
    return call(LITERAL_STRING[492], {flags, magic_database});
}
Variant finfo_close(const Variant &finfo) {
    return call(LITERAL_STRING[493], {finfo});
}
Variant finfo_set_flags(const Variant &finfo, const Variant &flags) {
    return call(LITERAL_STRING[494], {finfo, flags});
}
Variant finfo_file(const Variant &finfo, const Variant &filename, const Variant &flags, const Variant &context) {
    return call(LITERAL_STRING[495], {finfo, filename, flags, context});
}
Variant finfo_buffer(const Variant &finfo, const Variant &string, const Variant &flags, const Variant &context) {
    return call(LITERAL_STRING[496], {finfo, string, flags, context});
}
Variant mime_content_type(const Variant &filename) {
    return call(LITERAL_STRING[497], {filename});
}
}  // namespace php

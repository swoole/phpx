#include "phpx.h"

namespace php {
Variant finfo_open(const Variant &flags, const Variant &magic_database) {
    return call("finfo_open", {flags, magic_database});
}
Variant finfo_close(const Variant &finfo) {
    return call("finfo_close", {finfo});
}
Variant finfo_set_flags(const Variant &finfo, const Variant &flags) {
    return call("finfo_set_flags", {finfo, flags});
}
Variant finfo_file(const Variant &finfo, const Variant &filename, const Variant &flags, const Variant &context) {
    return call("finfo_file", {finfo, filename, flags, context});
}
Variant finfo_buffer(const Variant &finfo, const Variant &string, const Variant &flags, const Variant &context) {
    return call("finfo_buffer", {finfo, string, flags, context});
}
Variant mime_content_type(const Variant &filename) {
    return call("mime_content_type", {filename});
}
}

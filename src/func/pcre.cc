#include "phpx.h"

namespace php {
Variant preg_match(const Variant &pattern, const Variant &subject, const Reference &matches, const Variant &flags, const Variant &offset) {
    return call("preg_match", {pattern, subject, &matches, flags, offset});
}
Variant preg_match_all(const Variant &pattern, const Variant &subject, const Reference &matches, const Variant &flags, const Variant &offset) {
    return call("preg_match_all", {pattern, subject, &matches, flags, offset});
}
Variant preg_replace(const Variant &pattern, const Variant &replacement, const Variant &subject, const Variant &limit, const Reference &count) {
    return call("preg_replace", {pattern, replacement, subject, limit, &count});
}
Variant preg_filter(const Variant &pattern, const Variant &replacement, const Variant &subject, const Variant &limit, const Reference &count) {
    return call("preg_filter", {pattern, replacement, subject, limit, &count});
}
Variant preg_replace_callback(const Variant &pattern, const Variant &callback, const Variant &subject, const Variant &limit, const Reference &count, const Variant &flags) {
    return call("preg_replace_callback", {pattern, callback, subject, limit, &count, flags});
}
Variant preg_replace_callback_array(const Variant &pattern, const Variant &subject, const Variant &limit, const Reference &count, const Variant &flags) {
    return call("preg_replace_callback_array", {pattern, subject, limit, &count, flags});
}
Variant preg_split(const Variant &pattern, const Variant &subject, const Variant &limit, const Variant &flags) {
    return call("preg_split", {pattern, subject, limit, flags});
}
Variant preg_quote(const Variant &str, const Variant &delimiter) {
    return call("preg_quote", {str, delimiter});
}
Variant preg_grep(const Variant &pattern, const Variant &array, const Variant &flags) {
    return call("preg_grep", {pattern, array, flags});
}
Variant preg_last_error() {
    return call("preg_last_error", {});
}
Variant preg_last_error_msg() {
    return call("preg_last_error_msg", {});
}
}

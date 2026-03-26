#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant preg_match(const Variant &pattern,
                   const Variant &subject,
                   const Reference &matches,
                   const Variant &flags,
                   const Variant &offset) {
    return call(LITERAL_STRING[808], {pattern, subject, &matches, flags, offset});
}
Variant preg_match_all(const Variant &pattern,
                       const Variant &subject,
                       const Reference &matches,
                       const Variant &flags,
                       const Variant &offset) {
    return call(LITERAL_STRING[809], {pattern, subject, &matches, flags, offset});
}
Variant preg_replace(const Variant &pattern,
                     const Variant &replacement,
                     const Variant &subject,
                     const Variant &limit,
                     const Reference &count) {
    return call(LITERAL_STRING[810], {pattern, replacement, subject, limit, &count});
}
Variant preg_filter(const Variant &pattern,
                    const Variant &replacement,
                    const Variant &subject,
                    const Variant &limit,
                    const Reference &count) {
    return call(LITERAL_STRING[811], {pattern, replacement, subject, limit, &count});
}
Variant preg_replace_callback(const Variant &pattern,
                              const Variant &callback,
                              const Variant &subject,
                              const Variant &limit,
                              const Reference &count,
                              const Variant &flags) {
    return call(LITERAL_STRING[812], {pattern, callback, subject, limit, &count, flags});
}
Variant preg_replace_callback_array(const Variant &pattern,
                                    const Variant &subject,
                                    const Variant &limit,
                                    const Reference &count,
                                    const Variant &flags) {
    return call(LITERAL_STRING[813], {pattern, subject, limit, &count, flags});
}
Variant preg_split(const Variant &pattern, const Variant &subject, const Variant &limit, const Variant &flags) {
    return call(LITERAL_STRING[814], {pattern, subject, limit, flags});
}
Variant preg_quote(const Variant &str, const Variant &delimiter) {
    return call(LITERAL_STRING[815], {str, delimiter});
}
Variant preg_grep(const Variant &pattern, const Variant &array, const Variant &flags) {
    return call(LITERAL_STRING[816], {pattern, array, flags});
}
Variant preg_last_error() {
    return call(LITERAL_STRING[817], {});
}
Variant preg_last_error_msg() {
    return call(LITERAL_STRING[818], {});
}
}  // namespace php

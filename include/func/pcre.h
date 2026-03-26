#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant preg_match(const Variant &pattern,
                   const Variant &subject,
                   const Reference &matches = {},
                   const Variant &flags = 0,
                   const Variant &offset = 0);
Variant preg_match_all(const Variant &pattern,
                       const Variant &subject,
                       const Reference &matches = {},
                       const Variant &flags = 0,
                       const Variant &offset = 0);
Variant preg_replace(const Variant &pattern,
                     const Variant &replacement,
                     const Variant &subject,
                     const Variant &limit = -1,
                     const Reference &count = {});
Variant preg_filter(const Variant &pattern,
                    const Variant &replacement,
                    const Variant &subject,
                    const Variant &limit = -1,
                    const Reference &count = {});
Variant preg_replace_callback(const Variant &pattern,
                              const Variant &callback,
                              const Variant &subject,
                              const Variant &limit = -1,
                              const Reference &count = {},
                              const Variant &flags = 0);
Variant preg_replace_callback_array(const Variant &pattern,
                                    const Variant &subject,
                                    const Variant &limit = -1,
                                    const Reference &count = {},
                                    const Variant &flags = 0);
Variant preg_split(const Variant &pattern, const Variant &subject, const Variant &limit = -1, const Variant &flags = 0);
Variant preg_quote(const Variant &str, const Variant &delimiter = {});
Variant preg_grep(const Variant &pattern, const Variant &array, const Variant &flags = 0);
Variant preg_last_error();
Variant preg_last_error_msg();
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant filter_has_var(const Variant &input_type, const Variant &var_name) {
    return call(LITERAL_STRING[502], {input_type, var_name});
}
Variant filter_input(const Variant &type, const Variant &var_name, const Variant &filter, const Variant &options) {
    return call(LITERAL_STRING[503], {type, var_name, filter, options});
}
Variant filter_var(const Variant &value, const Variant &filter, const Variant &options) {
    return call(LITERAL_STRING[504], {value, filter, options});
}
Variant filter_input_array(const Variant &type, const Variant &options, const Variant &add_empty) {
    return call(LITERAL_STRING[505], {type, options, add_empty});
}
Variant filter_var_array(const Variant &array, const Variant &options, const Variant &add_empty) {
    return call(LITERAL_STRING[506], {array, options, add_empty});
}
Variant filter_list() {
    return call(LITERAL_STRING[507], {});
}
Variant filter_id(const Variant &name) {
    return call(LITERAL_STRING[508], {name});
}
}  // namespace php

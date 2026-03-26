#include "phpx.h"

namespace php {
Variant filter_has_var(const Variant &input_type, const Variant &var_name) {
    return call("filter_has_var", {input_type, var_name});
}
Variant filter_input(const Variant &type, const Variant &var_name, const Variant &filter, const Variant &options) {
    return call("filter_input", {type, var_name, filter, options});
}
Variant filter_var(const Variant &value, const Variant &filter, const Variant &options) {
    return call("filter_var", {value, filter, options});
}
Variant filter_input_array(const Variant &type, const Variant &options, const Variant &add_empty) {
    return call("filter_input_array", {type, options, add_empty});
}
Variant filter_var_array(const Variant &array, const Variant &options, const Variant &add_empty) {
    return call("filter_var_array", {array, options, add_empty});
}
Variant filter_list() {
    return call("filter_list", {});
}
Variant filter_id(const Variant &name) {
    return call("filter_id", {name});
}
}

namespace php {
Variant filter_has_var(const Variant &input_type, const Variant &var_name);
Variant filter_input(const Variant &type, const Variant &var_name, const Variant &filter = 516, const Variant &options = 0);
Variant filter_var(const Variant &value, const Variant &filter = 516, const Variant &options = 0);
Variant filter_input_array(const Variant &type, const Variant &options = 516, const Variant &add_empty = true);
Variant filter_var_array(const Variant &array, const Variant &options = 516, const Variant &add_empty = true);
Variant filter_list();
Variant filter_id(const Variant &name);
}

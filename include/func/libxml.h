namespace php {
Variant libxml_set_streams_context(const Variant &context);
Variant libxml_use_internal_errors(const Variant &use_errors = {});
Variant libxml_get_last_error();
Variant libxml_get_errors();
Variant libxml_clear_errors();
Variant libxml_disable_entity_loader(const Variant &disable = true);
Variant libxml_set_external_entity_loader(const Variant &resolver_function);
Variant libxml_get_external_entity_loader();
}

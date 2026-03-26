namespace php {
Variant class_implements(const Variant &object_or_class, const Variant &autoload = true);
Variant class_parents(const Variant &object_or_class, const Variant &autoload = true);
Variant class_uses(const Variant &object_or_class, const Variant &autoload = true);
Variant spl_autoload(const Variant &_class, const Variant &file_extensions = {});
Variant spl_autoload_call(const Variant &_class);
Variant spl_autoload_extensions(const Variant &file_extensions = {});
Variant spl_autoload_functions();
Variant spl_autoload_register(const Variant &callback = {}, const Variant &_throw = true, const Variant &prepend = false);
Variant spl_autoload_unregister(const Variant &callback);
Variant spl_classes();
Variant spl_object_hash(const Variant &object);
Variant spl_object_id(const Variant &object);
Variant iterator_apply(const Variant &iterator, const Variant &callback, const Variant &args = {});
Variant iterator_count(const Variant &iterator);
Variant iterator_to_array(const Variant &iterator, const Variant &preserve_keys = true);
}

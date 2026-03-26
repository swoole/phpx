namespace php {
Variant finfo_open(const Variant &flags = 0, const Variant &magic_database = {});
Variant finfo_close(const Variant &finfo);
Variant finfo_set_flags(const Variant &finfo, const Variant &flags);
Variant finfo_file(const Variant &finfo, const Variant &filename, const Variant &flags = 0, const Variant &context = {});
Variant finfo_buffer(const Variant &finfo, const Variant &string, const Variant &flags = 0, const Variant &context = {});
Variant mime_content_type(const Variant &filename);
}

namespace php {
Variant exif_tagname(const Variant &index);
Variant exif_read_data(const Variant &file, const Variant &required_sections = {}, const Variant &as_arrays = false, const Variant &read_thumbnail = false);
Variant exif_thumbnail(const Variant &file, const Reference &width = {}, const Reference &height = {}, const Reference &image_type = {});
Variant exif_imagetype(const Variant &filename);
}

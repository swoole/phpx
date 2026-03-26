#include "phpx.h"

namespace php {
Variant exif_tagname(const Variant &index) {
    return call("exif_tagname", {index});
}
Variant exif_read_data(const Variant &file, const Variant &required_sections, const Variant &as_arrays, const Variant &read_thumbnail) {
    return call("exif_read_data", {file, required_sections, as_arrays, read_thumbnail});
}
Variant exif_thumbnail(const Variant &file, const Reference &width, const Reference &height, const Reference &image_type) {
    return call("exif_thumbnail", {file, &width, &height, &image_type});
}
Variant exif_imagetype(const Variant &filename) {
    return call("exif_imagetype", {filename});
}
}

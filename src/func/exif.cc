#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant exif_tagname(const Variant &index) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[519]);
    }
    return call(fn, {index});
}
Variant exif_read_data(const Variant &file,
                       const Variant &required_sections,
                       const Variant &as_arrays,
                       const Variant &read_thumbnail) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[520]);
    }
    return call(fn, {file, required_sections, as_arrays, read_thumbnail});
}
Variant exif_thumbnail(const Variant &file,
                       const Reference &width,
                       const Reference &height,
                       const Reference &image_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[521]);
    }
    return call(fn, {file, &width, &height, &image_type});
}
Variant exif_imagetype(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[522]);
    }
    return call(fn, {filename});
}
}  // namespace php

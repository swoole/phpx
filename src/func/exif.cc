#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant exif_tagname(const Variant &index) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[543]);
    }
    return call(_fn, {index});
}
Variant exif_read_data(const Variant &file,
                       const Variant &required_sections,
                       const Variant &as_arrays,
                       const Variant &read_thumbnail) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[544]);
    }
    return call(_fn, {file, required_sections, as_arrays, read_thumbnail});
}
Variant exif_thumbnail(const Variant &file,
                       const Reference &width,
                       const Reference &height,
                       const Reference &image_type) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[545]);
    }
    return call(_fn, {file, &width, &height, &image_type});
}
Variant exif_imagetype(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[546]);
    }
    return call(_fn, {filename});
}
}  // namespace php

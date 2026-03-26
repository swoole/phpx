#include "phpx.h"
#include "class/curl.h"

namespace php {
CURLFile::CURLFile(const Variant &filename, const Variant &mime_type, const Variant &posted_filename) {
    this_ = newObject(LITERAL_STRING[201], {filename, mime_type, posted_filename});
}
Variant CURLFile::getFilename() {
    return this_.exec(LITERAL_STRING[202], {});
}
Variant CURLFile::getMimeType() {
    return this_.exec(LITERAL_STRING[203], {});
}
Variant CURLFile::getPostFilename() {
    return this_.exec(LITERAL_STRING[204], {});
}
Variant CURLFile::setMimeType(const Variant &mime_type) {
    return this_.exec(LITERAL_STRING[205], {mime_type});
}
Variant CURLFile::setPostFilename(const Variant &posted_filename) {
    return this_.exec(LITERAL_STRING[206], {posted_filename});
}
CURLStringFile::CURLStringFile(const Variant &data, const Variant &postname, const Variant &mime) {
    this_ = newObject(LITERAL_STRING[207], {data, postname, mime});
}
}  // namespace php

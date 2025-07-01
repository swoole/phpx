#include "phpx.h"
#include "class/curl.h"

namespace php {
CURLFile::CURLFile(const Variant &filename, const Variant &mime_type, const Variant &posted_filename) {
    this_ = newObject("CURLFile", filename, mime_type, posted_filename);
}

Variant CURLFile::getFilename() {
    return this_.exec("getFilename");
}

Variant CURLFile::getMimeType() {
    return this_.exec("getMimeType");
}

Variant CURLFile::getPostFilename() {
    return this_.exec("getPostFilename");
}

Variant CURLFile::setMimeType(const Variant &mime_type) {
    return this_.exec("setMimeType", mime_type);
}

Variant CURLFile::setPostFilename(const Variant &posted_filename) {
    return this_.exec("setPostFilename", posted_filename);
}


CURLStringFile::CURLStringFile(const Variant &data, const Variant &postname, const Variant &mime) {
    this_ = newObject("CURLStringFile", data, postname, mime);
}


}

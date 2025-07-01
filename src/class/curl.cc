#include "phpx.h"
#include "class/curl.h"

namespace php {
CURLFile::CURLFile(const Variant &filename, const Variant &mime_type, const Variant &posted_filename) {
    _this = newObject("CURLFile", filename, mime_type, posted_filename);
}

Variant CURLFile::getFilename() {
    return std::move(_this.exec("getFilename"));
}

Variant CURLFile::getMimeType() {
    return std::move(_this.exec("getMimeType"));
}

Variant CURLFile::getPostFilename() {
    return std::move(_this.exec("getPostFilename"));
}

Variant CURLFile::setMimeType(const Variant &mime_type) {
    return std::move(_this.exec("setMimeType", mime_type));
}

Variant CURLFile::setPostFilename(const Variant &posted_filename) {
    return std::move(_this.exec("setPostFilename", posted_filename));
}


CURLStringFile::CURLStringFile(const Variant &data, const Variant &postname, const Variant &mime) {
    _this = newObject("CURLStringFile", data, postname, mime);
}


}

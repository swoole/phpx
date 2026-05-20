#include "phpx_literal_string.h"

namespace php {
class CurlHandle {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    CurlHandle();
};

class CurlMultiHandle {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    CurlMultiHandle();
};

class CurlShareHandle {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    CurlShareHandle();
};

class CURLFile {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    CURLFile(const Variant &filename, const Variant &mime_type = {}, const Variant &posted_filename = {});
    Variant getFilename();
    Variant getMimeType();
    Variant getPostFilename();
    Variant setMimeType(const Variant &mime_type);
    Variant setPostFilename(const Variant &posted_filename);
};

class CURLStringFile {
    Object this_;

  public:
    Object getObject() {
        return this_;
    }
    CURLStringFile(const Variant &data, const Variant &postname, const Variant &mime = "application/octet-stream");
};

}  // namespace php

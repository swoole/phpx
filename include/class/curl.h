#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class CurlHandle {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit CurlHandle(const Object &obj) : this_(obj) {}
    CurlHandle();
};

class CurlMultiHandle {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit CurlMultiHandle(const Object &obj) : this_(obj) {}
    CurlMultiHandle();
};

class CurlShareHandle {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit CurlShareHandle(const Object &obj) : this_(obj) {}
    CurlShareHandle();
};

class CURLFile {
    Object this_;

  public:
    Object getObject() const {
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
    Object getObject() const {
        return this_;
    }
    CURLStringFile(const Variant &data, const Variant &postname, const Variant &mime = "application/octet-stream");
};

}  // namespace php

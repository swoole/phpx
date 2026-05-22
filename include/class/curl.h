#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class CurlHandle;
class CurlMultiHandle;
class CurlShareHandle;
class CURLFile;
class CURLStringFile;

class CurlHandle {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit CurlHandle(const Object &obj) : this_(obj) {}
    CurlHandle();
};

class CurlMultiHandle {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit CurlMultiHandle(const Object &obj) : this_(obj) {}
    CurlMultiHandle();
};

class CurlShareHandle {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit CurlShareHandle(const Object &obj) : this_(obj) {}
    CurlShareHandle();
};

class CURLFile {
  protected:
    Object this_;
    CURLFile() = default;

  public:
    Object getObject() const {
        return this_;
    }
    CURLFile(const Variant &filename, const Variant &mime_type = nullptr, const Variant &posted_filename = nullptr);
    Variant getFilename();
    Variant getMimeType();
    Variant getPostFilename();
    Variant setMimeType(const Variant &mime_type);
    Variant setPostFilename(const Variant &posted_filename);
};

class CURLStringFile {
  protected:
    Object this_;
    CURLStringFile() = default;

  public:
    Object getObject() const {
        return this_;
    }
    CURLStringFile(const Variant &data, const Variant &postname, const Variant &mime = "application/octet-stream");
};

}  // namespace php

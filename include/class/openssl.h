#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class OpenSSLCertificate;
class OpenSSLCertificateSigningRequest;
class OpenSSLAsymmetricKey;

class OpenSSLCertificate {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit OpenSSLCertificate(const Object &obj) : this_(obj) {}
    OpenSSLCertificate();
};

class OpenSSLCertificateSigningRequest {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit OpenSSLCertificateSigningRequest(const Object &obj) : this_(obj) {}
    OpenSSLCertificateSigningRequest();
};

class OpenSSLAsymmetricKey {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit OpenSSLAsymmetricKey(const Object &obj) : this_(obj) {}
    OpenSSLAsymmetricKey();
};

}  // namespace php

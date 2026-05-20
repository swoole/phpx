#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class OpenSSLCertificate {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit OpenSSLCertificate(const Object &obj) : this_(obj) {}
    OpenSSLCertificate();
};

class OpenSSLCertificateSigningRequest {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit OpenSSLCertificateSigningRequest(const Object &obj) : this_(obj) {}
    OpenSSLCertificateSigningRequest();
};

class OpenSSLAsymmetricKey {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit OpenSSLAsymmetricKey(const Object &obj) : this_(obj) {}
    OpenSSLAsymmetricKey();
};

}  // namespace php

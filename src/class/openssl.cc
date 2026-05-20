#include "phpx.h"
#include "class/openssl.h"

namespace php {
OpenSSLCertificate::OpenSSLCertificate() {
    this_ = newObject(LITERAL_STRING[811]);
}
OpenSSLCertificateSigningRequest::OpenSSLCertificateSigningRequest() {
    this_ = newObject(LITERAL_STRING[812]);
}
OpenSSLAsymmetricKey::OpenSSLAsymmetricKey() {
    this_ = newObject(LITERAL_STRING[813]);
}
}  // namespace php

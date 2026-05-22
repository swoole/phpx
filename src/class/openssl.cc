#include "phpx.h"
#include "class/openssl.h"

namespace php {
OpenSSLCertificate::OpenSSLCertificate() {
    this_ = newObject(LITERAL_STRING[1025]);
}
OpenSSLCertificateSigningRequest::OpenSSLCertificateSigningRequest() {
    this_ = newObject(LITERAL_STRING[1026]);
}
OpenSSLAsymmetricKey::OpenSSLAsymmetricKey() {
    this_ = newObject(LITERAL_STRING[1027]);
}
}  // namespace php

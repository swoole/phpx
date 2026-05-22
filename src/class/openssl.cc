#include "phpx.h"
#include "phpx_class.h"
#include "class/openssl.h"

namespace php {
OpenSSLCertificate::OpenSSLCertificate() {
    this_ = newObject(LITERAL_STRING[987]);
}
OpenSSLCertificateSigningRequest::OpenSSLCertificateSigningRequest() {
    this_ = newObject(LITERAL_STRING[988]);
}
OpenSSLAsymmetricKey::OpenSSLAsymmetricKey() {
    this_ = newObject(LITERAL_STRING[989]);
}
}  // namespace php

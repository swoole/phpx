#include "phpx.h"
#include "phpx_class.h"
#include "class/openssl.h"

namespace php {
OpenSSLCertificate::OpenSSLCertificate() {
    this_ = newObject(LITERAL_STRING[991]);
}
OpenSSLCertificateSigningRequest::OpenSSLCertificateSigningRequest() {
    this_ = newObject(LITERAL_STRING[992]);
}
OpenSSLAsymmetricKey::OpenSSLAsymmetricKey() {
    this_ = newObject(LITERAL_STRING[993]);
}
}  // namespace php

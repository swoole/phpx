#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant openssl_x509_export_to_file(const Variant &certificate,
                                    const Variant &output_filename,
                                    const Variant &no_text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[961]);
    }
    return call(_fn, {certificate, output_filename, no_text});
}
Variant openssl_x509_export(const Variant &certificate, const Reference &output, const Variant &no_text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[962]);
    }
    return call(_fn, {certificate, &output, no_text});
}
Variant openssl_x509_fingerprint(const Variant &certificate, const Variant &digest_algo, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[963]);
    }
    return call(_fn, {certificate, digest_algo, binary});
}
Variant openssl_x509_check_private_key(const Variant &certificate, const Variant &private_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[964]);
    }
    return call(_fn, {certificate, private_key});
}
Variant openssl_x509_verify(const Variant &certificate, const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[965]);
    }
    return call(_fn, {certificate, public_key});
}
Variant openssl_x509_parse(const Variant &certificate, const Variant &short_names) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[966]);
    }
    return call(_fn, {certificate, short_names});
}
Variant openssl_x509_checkpurpose(const Variant &certificate,
                                  const Variant &purpose,
                                  const Variant &ca_info,
                                  const Variant &untrusted_certificates_file) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[967]);
    }
    return call(_fn, {certificate, purpose, ca_info, untrusted_certificates_file});
}
OpenSSLCertificate openssl_x509_read(const Variant &certificate) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[968]);
    }
    auto _rv = call(_fn, {certificate});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_x509_read() returned false");
    }
    return OpenSSLCertificate(Object(std::move(_rv)));
}
Variant openssl_x509_free(const OpenSSLCertificate &certificate) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[969]);
    }
    return call(_fn, {certificate.getObject()});
}
Variant openssl_x509_free(const Variant &certificate) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[969]);
    }
    return call(_fn, {certificate});
}
Variant openssl_pkcs12_export_to_file(const Variant &certificate,
                                      const Variant &output_filename,
                                      const Variant &private_key,
                                      const Variant &passphrase,
                                      const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[970]);
    }
    return call(_fn, {certificate, output_filename, private_key, passphrase, options});
}
Variant openssl_pkcs12_export(const Variant &certificate,
                              const Reference &output,
                              const Variant &private_key,
                              const Variant &passphrase,
                              const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[971]);
    }
    return call(_fn, {certificate, &output, private_key, passphrase, options});
}
Variant openssl_pkcs12_read(const Variant &pkcs12, const Reference &certificates, const Variant &passphrase) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[972]);
    }
    return call(_fn, {pkcs12, &certificates, passphrase});
}
Variant openssl_csr_export_to_file(const Variant &csr, const Variant &output_filename, const Variant &no_text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[973]);
    }
    return call(_fn, {csr, output_filename, no_text});
}
Variant openssl_csr_export(const Variant &csr, const Reference &output, const Variant &no_text) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[974]);
    }
    return call(_fn, {csr, &output, no_text});
}
OpenSSLCertificate openssl_csr_sign(const Variant &csr,
                                    const Variant &ca_certificate,
                                    const Variant &private_key,
                                    const Variant &days,
                                    const Variant &options,
                                    const Variant &serial,
                                    const Variant &serial_hex) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[975]);
    }
    auto _rv = call(_fn, {csr, ca_certificate, private_key, days, options, serial, serial_hex});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_csr_sign() returned false");
    }
    return OpenSSLCertificate(Object(std::move(_rv)));
}
Variant openssl_csr_new(const Variant &distinguished_names,
                        const Reference &private_key,
                        const Variant &options,
                        const Variant &extra_attributes) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[976]);
    }
    return call(_fn, {distinguished_names, &private_key, options, extra_attributes});
}
Variant openssl_csr_get_subject(const Variant &csr, const Variant &short_names) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[977]);
    }
    return call(_fn, {csr, short_names});
}
OpenSSLAsymmetricKey openssl_csr_get_public_key(const Variant &csr, const Variant &short_names) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[978]);
    }
    auto _rv = call(_fn, {csr, short_names});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_csr_get_public_key() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
OpenSSLAsymmetricKey openssl_pkey_new(const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[979]);
    }
    auto _rv = call(_fn, {options});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_pkey_new() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
Variant openssl_pkey_export_to_file(const Variant &key,
                                    const Variant &output_filename,
                                    const Variant &passphrase,
                                    const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[980]);
    }
    return call(_fn, {key, output_filename, passphrase, options});
}
Variant openssl_pkey_export(const Variant &key,
                            const Reference &output,
                            const Variant &passphrase,
                            const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[981]);
    }
    return call(_fn, {key, &output, passphrase, options});
}
OpenSSLAsymmetricKey openssl_pkey_get_public(const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[982]);
    }
    auto _rv = call(_fn, {public_key});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_pkey_get_public() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
OpenSSLAsymmetricKey openssl_get_publickey(const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[983]);
    }
    auto _rv = call(_fn, {public_key});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_get_publickey() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
Variant openssl_pkey_free(const OpenSSLAsymmetricKey &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[984]);
    }
    return call(_fn, {key.getObject()});
}
Variant openssl_pkey_free(const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[984]);
    }
    return call(_fn, {key});
}
Variant openssl_free_key(const OpenSSLAsymmetricKey &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[985]);
    }
    return call(_fn, {key.getObject()});
}
Variant openssl_free_key(const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[985]);
    }
    return call(_fn, {key});
}
OpenSSLAsymmetricKey openssl_pkey_get_private(const Variant &private_key, const Variant &passphrase) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[986]);
    }
    auto _rv = call(_fn, {private_key, passphrase});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_pkey_get_private() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
OpenSSLAsymmetricKey openssl_get_privatekey(const Variant &private_key, const Variant &passphrase) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[987]);
    }
    auto _rv = call(_fn, {private_key, passphrase});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_get_privatekey() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
Variant openssl_pkey_get_details(const OpenSSLAsymmetricKey &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[988]);
    }
    return call(_fn, {key.getObject()});
}
Variant openssl_pkey_get_details(const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[988]);
    }
    return call(_fn, {key});
}
Variant openssl_pbkdf2(const Variant &password,
                       const Variant &salt,
                       const Variant &key_length,
                       const Variant &iterations,
                       const Variant &digest_algo) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[989]);
    }
    return call(_fn, {password, salt, key_length, iterations, digest_algo});
}
Variant openssl_pkcs7_verify(const Variant &input_filename,
                             const Variant &flags,
                             const Variant &signers_certificates_filename,
                             const Variant &ca_info,
                             const Variant &untrusted_certificates_filename,
                             const Variant &content,
                             const Variant &output_filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[990]);
    }
    return call(_fn,
                {input_filename,
                 flags,
                 signers_certificates_filename,
                 ca_info,
                 untrusted_certificates_filename,
                 content,
                 output_filename});
}
Variant openssl_pkcs7_encrypt(const Variant &input_filename,
                              const Variant &output_filename,
                              const Variant &certificate,
                              const Variant &headers,
                              const Variant &flags,
                              const Variant &cipher_algo) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[991]);
    }
    return call(_fn, {input_filename, output_filename, certificate, headers, flags, cipher_algo});
}
Variant openssl_pkcs7_sign(const Variant &input_filename,
                           const Variant &output_filename,
                           const Variant &certificate,
                           const Variant &private_key,
                           const Variant &headers,
                           const Variant &flags,
                           const Variant &untrusted_certificates_filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[992]);
    }
    return call(
        _fn,
        {input_filename, output_filename, certificate, private_key, headers, flags, untrusted_certificates_filename});
}
Variant openssl_pkcs7_decrypt(const Variant &input_filename,
                              const Variant &output_filename,
                              const Variant &certificate,
                              const Variant &private_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[993]);
    }
    return call(_fn, {input_filename, output_filename, certificate, private_key});
}
Variant openssl_pkcs7_read(const Variant &data, const Reference &certificates) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[994]);
    }
    return call(_fn, {data, &certificates});
}
Variant openssl_cms_verify(const Variant &input_filename,
                           const Variant &flags,
                           const Variant &certificates,
                           const Variant &ca_info,
                           const Variant &untrusted_certificates_filename,
                           const Variant &content,
                           const Variant &pk7,
                           const Variant &sigfile,
                           const Variant &encoding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[995]);
    }
    return call(_fn,
                {input_filename,
                 flags,
                 certificates,
                 ca_info,
                 untrusted_certificates_filename,
                 content,
                 pk7,
                 sigfile,
                 encoding});
}
Variant openssl_cms_encrypt(const Variant &input_filename,
                            const Variant &output_filename,
                            const Variant &certificate,
                            const Variant &headers,
                            const Variant &flags,
                            const Variant &encoding,
                            const Variant &cipher_algo) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[996]);
    }
    return call(_fn, {input_filename, output_filename, certificate, headers, flags, encoding, cipher_algo});
}
Variant openssl_cms_sign(const Variant &input_filename,
                         const Variant &output_filename,
                         const Variant &certificate,
                         const Variant &private_key,
                         const Variant &headers,
                         const Variant &flags,
                         const Variant &encoding,
                         const Variant &untrusted_certificates_filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[997]);
    }
    return call(_fn,
                {input_filename,
                 output_filename,
                 certificate,
                 private_key,
                 headers,
                 flags,
                 encoding,
                 untrusted_certificates_filename});
}
Variant openssl_cms_decrypt(const Variant &input_filename,
                            const Variant &output_filename,
                            const Variant &certificate,
                            const Variant &private_key,
                            const Variant &encoding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[998]);
    }
    return call(_fn, {input_filename, output_filename, certificate, private_key, encoding});
}
Variant openssl_cms_read(const Variant &input_filename, const Reference &certificates) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[999]);
    }
    return call(_fn, {input_filename, &certificates});
}
Variant openssl_private_encrypt(const Variant &data,
                                const Reference &encrypted_data,
                                const Variant &private_key,
                                const Variant &padding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1000]);
    }
    return call(_fn, {data, &encrypted_data, private_key, padding});
}
Variant openssl_private_decrypt(const Variant &data,
                                const Reference &decrypted_data,
                                const Variant &private_key,
                                const Variant &padding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1001]);
    }
    return call(_fn, {data, &decrypted_data, private_key, padding});
}
Variant openssl_public_encrypt(const Variant &data,
                               const Reference &encrypted_data,
                               const Variant &public_key,
                               const Variant &padding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1002]);
    }
    return call(_fn, {data, &encrypted_data, public_key, padding});
}
Variant openssl_public_decrypt(const Variant &data,
                               const Reference &decrypted_data,
                               const Variant &public_key,
                               const Variant &padding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1003]);
    }
    return call(_fn, {data, &decrypted_data, public_key, padding});
}
Variant openssl_error_string() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1004]);
    }
    return call(_fn, {});
}
Variant openssl_sign(const Variant &data,
                     const Reference &signature,
                     const Variant &private_key,
                     const Variant &algorithm) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1005]);
    }
    return call(_fn, {data, &signature, private_key, algorithm});
}
Variant openssl_verify(const Variant &data,
                       const Variant &signature,
                       const Variant &public_key,
                       const Variant &algorithm) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1006]);
    }
    return call(_fn, {data, signature, public_key, algorithm});
}
Variant openssl_seal(const Variant &data,
                     const Reference &sealed_data,
                     const Reference &encrypted_keys,
                     const Variant &public_key,
                     const Variant &cipher_algo,
                     const Reference &iv) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1007]);
    }
    return call(_fn, {data, &sealed_data, &encrypted_keys, public_key, cipher_algo, &iv});
}
Variant openssl_open(const Variant &data,
                     const Reference &output,
                     const Variant &encrypted_key,
                     const Variant &private_key,
                     const Variant &cipher_algo,
                     const Variant &iv) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1008]);
    }
    return call(_fn, {data, &output, encrypted_key, private_key, cipher_algo, iv});
}
Variant openssl_get_md_methods(const Variant &aliases) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1009]);
    }
    return call(_fn, {aliases});
}
Variant openssl_get_cipher_methods(const Variant &aliases) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1010]);
    }
    return call(_fn, {aliases});
}
Variant openssl_get_curve_names() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1011]);
    }
    return call(_fn, {});
}
Variant openssl_digest(const Variant &data, const Variant &digest_algo, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1012]);
    }
    return call(_fn, {data, digest_algo, binary});
}
Variant openssl_encrypt(const Variant &data,
                        const Variant &cipher_algo,
                        const Variant &passphrase,
                        const Variant &options,
                        const Variant &iv,
                        const Reference &tag,
                        const Variant &aad,
                        const Variant &tag_length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1013]);
    }
    return call(_fn, {data, cipher_algo, passphrase, options, iv, &tag, aad, tag_length});
}
Variant openssl_decrypt(const Variant &data,
                        const Variant &cipher_algo,
                        const Variant &passphrase,
                        const Variant &options,
                        const Variant &iv,
                        const Variant &tag,
                        const Variant &aad) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1014]);
    }
    return call(_fn, {data, cipher_algo, passphrase, options, iv, tag, aad});
}
Variant openssl_cipher_iv_length(const Variant &cipher_algo) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1015]);
    }
    return call(_fn, {cipher_algo});
}
Variant openssl_cipher_key_length(const Variant &cipher_algo) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1016]);
    }
    return call(_fn, {cipher_algo});
}
Variant openssl_dh_compute_key(const Variant &public_key, const OpenSSLAsymmetricKey &private_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1017]);
    }
    return call(_fn, {public_key, private_key.getObject()});
}
Variant openssl_dh_compute_key(const Variant &public_key, const Variant &private_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1017]);
    }
    return call(_fn, {public_key, private_key});
}
Variant openssl_pkey_derive(const Variant &public_key, const Variant &private_key, const Variant &key_length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1018]);
    }
    return call(_fn, {public_key, private_key, key_length});
}
Variant openssl_random_pseudo_bytes(const Variant &length, const Reference &strong_result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1019]);
    }
    return call(_fn, {length, &strong_result});
}
Variant openssl_spki_new(const OpenSSLAsymmetricKey &private_key,
                         const Variant &challenge,
                         const Variant &digest_algo) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1020]);
    }
    return call(_fn, {private_key.getObject(), challenge, digest_algo});
}
Variant openssl_spki_new(const Variant &private_key, const Variant &challenge, const Variant &digest_algo) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1020]);
    }
    return call(_fn, {private_key, challenge, digest_algo});
}
Variant openssl_spki_verify(const Variant &spki) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1021]);
    }
    return call(_fn, {spki});
}
Variant openssl_spki_export(const Variant &spki) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1022]);
    }
    return call(_fn, {spki});
}
Variant openssl_spki_export_challenge(const Variant &spki) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1023]);
    }
    return call(_fn, {spki});
}
Variant openssl_get_cert_locations() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1024]);
    }
    return call(_fn, {});
}
}  // namespace php

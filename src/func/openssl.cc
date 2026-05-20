#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant openssl_x509_export_to_file(const Variant &certificate,
                                    const Variant &output_filename,
                                    const Variant &no_text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[747]);
    }
    return call(fn, {certificate, output_filename, no_text});
}
Variant openssl_x509_export(const Variant &certificate, const Reference &output, const Variant &no_text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[748]);
    }
    return call(fn, {certificate, &output, no_text});
}
Variant openssl_x509_fingerprint(const Variant &certificate, const Variant &digest_algo, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[749]);
    }
    return call(fn, {certificate, digest_algo, binary});
}
Variant openssl_x509_check_private_key(const Variant &certificate, const Variant &private_key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[750]);
    }
    return call(fn, {certificate, private_key});
}
Variant openssl_x509_verify(const Variant &certificate, const Variant &public_key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[751]);
    }
    return call(fn, {certificate, public_key});
}
Variant openssl_x509_parse(const Variant &certificate, const Variant &short_names) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[752]);
    }
    return call(fn, {certificate, short_names});
}
Variant openssl_x509_checkpurpose(const Variant &certificate,
                                  const Variant &purpose,
                                  const Variant &ca_info,
                                  const Variant &untrusted_certificates_file) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[753]);
    }
    return call(fn, {certificate, purpose, ca_info, untrusted_certificates_file});
}
OpenSSLCertificate openssl_x509_read(const Variant &certificate) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[754]);
    }
    auto _rv = call(fn, {certificate});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_x509_read() returned false");
    }
    return OpenSSLCertificate(Object(std::move(_rv)));
}
Variant openssl_x509_free(const OpenSSLCertificate &certificate) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[755]);
    }
    return call(fn, {certificate.getObject()});
}
Variant openssl_x509_free(const Variant &certificate) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[755]);
    }
    return call(fn, {certificate});
}
Variant openssl_pkcs12_export_to_file(const Variant &certificate,
                                      const Variant &output_filename,
                                      const Variant &private_key,
                                      const Variant &passphrase,
                                      const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[756]);
    }
    return call(fn, {certificate, output_filename, private_key, passphrase, options});
}
Variant openssl_pkcs12_export(const Variant &certificate,
                              const Reference &output,
                              const Variant &private_key,
                              const Variant &passphrase,
                              const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[757]);
    }
    return call(fn, {certificate, &output, private_key, passphrase, options});
}
Variant openssl_pkcs12_read(const Variant &pkcs12, const Reference &certificates, const Variant &passphrase) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[758]);
    }
    return call(fn, {pkcs12, &certificates, passphrase});
}
Variant openssl_csr_export_to_file(const Variant &csr, const Variant &output_filename, const Variant &no_text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[759]);
    }
    return call(fn, {csr, output_filename, no_text});
}
Variant openssl_csr_export(const Variant &csr, const Reference &output, const Variant &no_text) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[760]);
    }
    return call(fn, {csr, &output, no_text});
}
OpenSSLCertificate openssl_csr_sign(const Variant &csr,
                                    const Variant &ca_certificate,
                                    const Variant &private_key,
                                    const Variant &days,
                                    const Variant &options,
                                    const Variant &serial,
                                    const Variant &serial_hex) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[761]);
    }
    auto _rv = call(fn, {csr, ca_certificate, private_key, days, options, serial, serial_hex});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_csr_sign() returned false");
    }
    return OpenSSLCertificate(Object(std::move(_rv)));
}
Variant openssl_csr_new(const Variant &distinguished_names,
                        const Reference &private_key,
                        const Variant &options,
                        const Variant &extra_attributes) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[762]);
    }
    return call(fn, {distinguished_names, &private_key, options, extra_attributes});
}
Variant openssl_csr_get_subject(const Variant &csr, const Variant &short_names) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[763]);
    }
    return call(fn, {csr, short_names});
}
OpenSSLAsymmetricKey openssl_csr_get_public_key(const Variant &csr, const Variant &short_names) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[764]);
    }
    auto _rv = call(fn, {csr, short_names});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_csr_get_public_key() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
OpenSSLAsymmetricKey openssl_pkey_new(const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[765]);
    }
    auto _rv = call(fn, {options});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_pkey_new() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
Variant openssl_pkey_export_to_file(const Variant &key,
                                    const Variant &output_filename,
                                    const Variant &passphrase,
                                    const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[766]);
    }
    return call(fn, {key, output_filename, passphrase, options});
}
Variant openssl_pkey_export(const Variant &key,
                            const Reference &output,
                            const Variant &passphrase,
                            const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[767]);
    }
    return call(fn, {key, &output, passphrase, options});
}
OpenSSLAsymmetricKey openssl_pkey_get_public(const Variant &public_key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[768]);
    }
    auto _rv = call(fn, {public_key});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_pkey_get_public() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
OpenSSLAsymmetricKey openssl_get_publickey(const Variant &public_key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[769]);
    }
    auto _rv = call(fn, {public_key});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_get_publickey() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
Variant openssl_pkey_free(const OpenSSLAsymmetricKey &key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[770]);
    }
    return call(fn, {key.getObject()});
}
Variant openssl_pkey_free(const Variant &key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[770]);
    }
    return call(fn, {key});
}
Variant openssl_free_key(const OpenSSLAsymmetricKey &key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[771]);
    }
    return call(fn, {key.getObject()});
}
Variant openssl_free_key(const Variant &key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[771]);
    }
    return call(fn, {key});
}
OpenSSLAsymmetricKey openssl_pkey_get_private(const Variant &private_key, const Variant &passphrase) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[772]);
    }
    auto _rv = call(fn, {private_key, passphrase});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_pkey_get_private() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
OpenSSLAsymmetricKey openssl_get_privatekey(const Variant &private_key, const Variant &passphrase) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[773]);
    }
    auto _rv = call(fn, {private_key, passphrase});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "openssl_get_privatekey() returned false");
    }
    return OpenSSLAsymmetricKey(Object(std::move(_rv)));
}
Variant openssl_pkey_get_details(const OpenSSLAsymmetricKey &key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[774]);
    }
    return call(fn, {key.getObject()});
}
Variant openssl_pkey_get_details(const Variant &key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[774]);
    }
    return call(fn, {key});
}
Variant openssl_pbkdf2(const Variant &password,
                       const Variant &salt,
                       const Variant &key_length,
                       const Variant &iterations,
                       const Variant &digest_algo) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[775]);
    }
    return call(fn, {password, salt, key_length, iterations, digest_algo});
}
Variant openssl_pkcs7_verify(const Variant &input_filename,
                             const Variant &flags,
                             const Variant &signers_certificates_filename,
                             const Variant &ca_info,
                             const Variant &untrusted_certificates_filename,
                             const Variant &content,
                             const Variant &output_filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[776]);
    }
    return call(fn,
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[777]);
    }
    return call(fn, {input_filename, output_filename, certificate, headers, flags, cipher_algo});
}
Variant openssl_pkcs7_sign(const Variant &input_filename,
                           const Variant &output_filename,
                           const Variant &certificate,
                           const Variant &private_key,
                           const Variant &headers,
                           const Variant &flags,
                           const Variant &untrusted_certificates_filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[778]);
    }
    return call(
        fn,
        {input_filename, output_filename, certificate, private_key, headers, flags, untrusted_certificates_filename});
}
Variant openssl_pkcs7_decrypt(const Variant &input_filename,
                              const Variant &output_filename,
                              const Variant &certificate,
                              const Variant &private_key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[779]);
    }
    return call(fn, {input_filename, output_filename, certificate, private_key});
}
Variant openssl_pkcs7_read(const Variant &data, const Reference &certificates) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[780]);
    }
    return call(fn, {data, &certificates});
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[781]);
    }
    return call(fn,
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[782]);
    }
    return call(fn, {input_filename, output_filename, certificate, headers, flags, encoding, cipher_algo});
}
Variant openssl_cms_sign(const Variant &input_filename,
                         const Variant &output_filename,
                         const Variant &certificate,
                         const Variant &private_key,
                         const Variant &headers,
                         const Variant &flags,
                         const Variant &encoding,
                         const Variant &untrusted_certificates_filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[783]);
    }
    return call(fn,
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[784]);
    }
    return call(fn, {input_filename, output_filename, certificate, private_key, encoding});
}
Variant openssl_cms_read(const Variant &input_filename, const Reference &certificates) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[785]);
    }
    return call(fn, {input_filename, &certificates});
}
Variant openssl_private_encrypt(const Variant &data,
                                const Reference &encrypted_data,
                                const Variant &private_key,
                                const Variant &padding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[786]);
    }
    return call(fn, {data, &encrypted_data, private_key, padding});
}
Variant openssl_private_decrypt(const Variant &data,
                                const Reference &decrypted_data,
                                const Variant &private_key,
                                const Variant &padding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[787]);
    }
    return call(fn, {data, &decrypted_data, private_key, padding});
}
Variant openssl_public_encrypt(const Variant &data,
                               const Reference &encrypted_data,
                               const Variant &public_key,
                               const Variant &padding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[788]);
    }
    return call(fn, {data, &encrypted_data, public_key, padding});
}
Variant openssl_public_decrypt(const Variant &data,
                               const Reference &decrypted_data,
                               const Variant &public_key,
                               const Variant &padding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[789]);
    }
    return call(fn, {data, &decrypted_data, public_key, padding});
}
Variant openssl_error_string() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[790]);
    }
    return call(fn, {});
}
Variant openssl_sign(const Variant &data,
                     const Reference &signature,
                     const Variant &private_key,
                     const Variant &algorithm) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[791]);
    }
    return call(fn, {data, &signature, private_key, algorithm});
}
Variant openssl_verify(const Variant &data,
                       const Variant &signature,
                       const Variant &public_key,
                       const Variant &algorithm) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[792]);
    }
    return call(fn, {data, signature, public_key, algorithm});
}
Variant openssl_seal(const Variant &data,
                     const Reference &sealed_data,
                     const Reference &encrypted_keys,
                     const Variant &public_key,
                     const Variant &cipher_algo,
                     const Reference &iv) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[793]);
    }
    return call(fn, {data, &sealed_data, &encrypted_keys, public_key, cipher_algo, &iv});
}
Variant openssl_open(const Variant &data,
                     const Reference &output,
                     const Variant &encrypted_key,
                     const Variant &private_key,
                     const Variant &cipher_algo,
                     const Variant &iv) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[794]);
    }
    return call(fn, {data, &output, encrypted_key, private_key, cipher_algo, iv});
}
Variant openssl_get_md_methods(const Variant &aliases) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[795]);
    }
    return call(fn, {aliases});
}
Variant openssl_get_cipher_methods(const Variant &aliases) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[796]);
    }
    return call(fn, {aliases});
}
Variant openssl_get_curve_names() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[797]);
    }
    return call(fn, {});
}
Variant openssl_digest(const Variant &data, const Variant &digest_algo, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[798]);
    }
    return call(fn, {data, digest_algo, binary});
}
Variant openssl_encrypt(const Variant &data,
                        const Variant &cipher_algo,
                        const Variant &passphrase,
                        const Variant &options,
                        const Variant &iv,
                        const Reference &tag,
                        const Variant &aad,
                        const Variant &tag_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[799]);
    }
    return call(fn, {data, cipher_algo, passphrase, options, iv, &tag, aad, tag_length});
}
Variant openssl_decrypt(const Variant &data,
                        const Variant &cipher_algo,
                        const Variant &passphrase,
                        const Variant &options,
                        const Variant &iv,
                        const Variant &tag,
                        const Variant &aad) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[800]);
    }
    return call(fn, {data, cipher_algo, passphrase, options, iv, tag, aad});
}
Variant openssl_cipher_iv_length(const Variant &cipher_algo) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[801]);
    }
    return call(fn, {cipher_algo});
}
Variant openssl_cipher_key_length(const Variant &cipher_algo) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[802]);
    }
    return call(fn, {cipher_algo});
}
Variant openssl_dh_compute_key(const Variant &public_key, const OpenSSLAsymmetricKey &private_key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[803]);
    }
    return call(fn, {public_key, private_key.getObject()});
}
Variant openssl_dh_compute_key(const Variant &public_key, const Variant &private_key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[803]);
    }
    return call(fn, {public_key, private_key});
}
Variant openssl_pkey_derive(const Variant &public_key, const Variant &private_key, const Variant &key_length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[804]);
    }
    return call(fn, {public_key, private_key, key_length});
}
Variant openssl_random_pseudo_bytes(const Variant &length, const Reference &strong_result) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[805]);
    }
    return call(fn, {length, &strong_result});
}
Variant openssl_spki_new(const OpenSSLAsymmetricKey &private_key,
                         const Variant &challenge,
                         const Variant &digest_algo) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[806]);
    }
    return call(fn, {private_key.getObject(), challenge, digest_algo});
}
Variant openssl_spki_new(const Variant &private_key, const Variant &challenge, const Variant &digest_algo) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[806]);
    }
    return call(fn, {private_key, challenge, digest_algo});
}
Variant openssl_spki_verify(const Variant &spki) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[807]);
    }
    return call(fn, {spki});
}
Variant openssl_spki_export(const Variant &spki) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[808]);
    }
    return call(fn, {spki});
}
Variant openssl_spki_export_challenge(const Variant &spki) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[809]);
    }
    return call(fn, {spki});
}
Variant openssl_get_cert_locations() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[810]);
    }
    return call(fn, {});
}
}  // namespace php

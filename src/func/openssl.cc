#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant openssl_x509_export_to_file(const Variant &certificate,
                                    const Variant &output_filename,
                                    const Variant &no_text) {
    return call(LITERAL_STRING[713], {certificate, output_filename, no_text});
}
Variant openssl_x509_export(const Variant &certificate, const Reference &output, const Variant &no_text) {
    return call(LITERAL_STRING[714], {certificate, &output, no_text});
}
Variant openssl_x509_fingerprint(const Variant &certificate, const Variant &digest_algo, const Variant &binary) {
    return call(LITERAL_STRING[715], {certificate, digest_algo, binary});
}
Variant openssl_x509_check_private_key(const Variant &certificate, const Variant &private_key) {
    return call(LITERAL_STRING[716], {certificate, private_key});
}
Variant openssl_x509_verify(const Variant &certificate, const Variant &public_key) {
    return call(LITERAL_STRING[717], {certificate, public_key});
}
Variant openssl_x509_parse(const Variant &certificate, const Variant &short_names) {
    return call(LITERAL_STRING[718], {certificate, short_names});
}
Variant openssl_x509_checkpurpose(const Variant &certificate,
                                  const Variant &purpose,
                                  const Variant &ca_info,
                                  const Variant &untrusted_certificates_file) {
    return call(LITERAL_STRING[719], {certificate, purpose, ca_info, untrusted_certificates_file});
}
Variant openssl_x509_read(const Variant &certificate) {
    return call(LITERAL_STRING[720], {certificate});
}
Variant openssl_x509_free(const Variant &certificate) {
    return call(LITERAL_STRING[721], {certificate});
}
Variant openssl_pkcs12_export_to_file(const Variant &certificate,
                                      const Variant &output_filename,
                                      const Variant &private_key,
                                      const Variant &passphrase,
                                      const Variant &options) {
    return call(LITERAL_STRING[722], {certificate, output_filename, private_key, passphrase, options});
}
Variant openssl_pkcs12_export(const Variant &certificate,
                              const Reference &output,
                              const Variant &private_key,
                              const Variant &passphrase,
                              const Variant &options) {
    return call(LITERAL_STRING[723], {certificate, &output, private_key, passphrase, options});
}
Variant openssl_pkcs12_read(const Variant &pkcs12, const Reference &certificates, const Variant &passphrase) {
    return call(LITERAL_STRING[724], {pkcs12, &certificates, passphrase});
}
Variant openssl_csr_export_to_file(const Variant &csr, const Variant &output_filename, const Variant &no_text) {
    return call(LITERAL_STRING[725], {csr, output_filename, no_text});
}
Variant openssl_csr_export(const Variant &csr, const Reference &output, const Variant &no_text) {
    return call(LITERAL_STRING[726], {csr, &output, no_text});
}
Variant openssl_csr_sign(const Variant &csr,
                         const Variant &ca_certificate,
                         const Variant &private_key,
                         const Variant &days,
                         const Variant &options,
                         const Variant &serial,
                         const Variant &serial_hex) {
    return call(LITERAL_STRING[727], {csr, ca_certificate, private_key, days, options, serial, serial_hex});
}
Variant openssl_csr_new(const Variant &distinguished_names,
                        const Reference &private_key,
                        const Variant &options,
                        const Variant &extra_attributes) {
    return call(LITERAL_STRING[728], {distinguished_names, &private_key, options, extra_attributes});
}
Variant openssl_csr_get_subject(const Variant &csr, const Variant &short_names) {
    return call(LITERAL_STRING[729], {csr, short_names});
}
Variant openssl_csr_get_public_key(const Variant &csr, const Variant &short_names) {
    return call(LITERAL_STRING[730], {csr, short_names});
}
Variant openssl_pkey_new(const Variant &options) {
    return call(LITERAL_STRING[731], {options});
}
Variant openssl_pkey_export_to_file(const Variant &key,
                                    const Variant &output_filename,
                                    const Variant &passphrase,
                                    const Variant &options) {
    return call(LITERAL_STRING[732], {key, output_filename, passphrase, options});
}
Variant openssl_pkey_export(const Variant &key,
                            const Reference &output,
                            const Variant &passphrase,
                            const Variant &options) {
    return call(LITERAL_STRING[733], {key, &output, passphrase, options});
}
Variant openssl_pkey_get_public(const Variant &public_key) {
    return call(LITERAL_STRING[734], {public_key});
}
Variant openssl_get_publickey(const Variant &public_key) {
    return call(LITERAL_STRING[735], {public_key});
}
Variant openssl_pkey_free(const Variant &key) {
    return call(LITERAL_STRING[736], {key});
}
Variant openssl_free_key(const Variant &key) {
    return call(LITERAL_STRING[737], {key});
}
Variant openssl_pkey_get_private(const Variant &private_key, const Variant &passphrase) {
    return call(LITERAL_STRING[738], {private_key, passphrase});
}
Variant openssl_get_privatekey(const Variant &private_key, const Variant &passphrase) {
    return call(LITERAL_STRING[739], {private_key, passphrase});
}
Variant openssl_pkey_get_details(const Variant &key) {
    return call(LITERAL_STRING[740], {key});
}
Variant openssl_pbkdf2(const Variant &password,
                       const Variant &salt,
                       const Variant &key_length,
                       const Variant &iterations,
                       const Variant &digest_algo) {
    return call(LITERAL_STRING[741], {password, salt, key_length, iterations, digest_algo});
}
Variant openssl_pkcs7_verify(const Variant &input_filename,
                             const Variant &flags,
                             const Variant &signers_certificates_filename,
                             const Variant &ca_info,
                             const Variant &untrusted_certificates_filename,
                             const Variant &content,
                             const Variant &output_filename) {
    return call(LITERAL_STRING[742],
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
    return call(LITERAL_STRING[743], {input_filename, output_filename, certificate, headers, flags, cipher_algo});
}
Variant openssl_pkcs7_sign(const Variant &input_filename,
                           const Variant &output_filename,
                           const Variant &certificate,
                           const Variant &private_key,
                           const Variant &headers,
                           const Variant &flags,
                           const Variant &untrusted_certificates_filename) {
    return call(
        LITERAL_STRING[744],
        {input_filename, output_filename, certificate, private_key, headers, flags, untrusted_certificates_filename});
}
Variant openssl_pkcs7_decrypt(const Variant &input_filename,
                              const Variant &output_filename,
                              const Variant &certificate,
                              const Variant &private_key) {
    return call(LITERAL_STRING[745], {input_filename, output_filename, certificate, private_key});
}
Variant openssl_pkcs7_read(const Variant &data, const Reference &certificates) {
    return call(LITERAL_STRING[746], {data, &certificates});
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
    return call(LITERAL_STRING[747],
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
    return call(LITERAL_STRING[748],
                {input_filename, output_filename, certificate, headers, flags, encoding, cipher_algo});
}
Variant openssl_cms_sign(const Variant &input_filename,
                         const Variant &output_filename,
                         const Variant &certificate,
                         const Variant &private_key,
                         const Variant &headers,
                         const Variant &flags,
                         const Variant &encoding,
                         const Variant &untrusted_certificates_filename) {
    return call(LITERAL_STRING[749],
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
    return call(LITERAL_STRING[750], {input_filename, output_filename, certificate, private_key, encoding});
}
Variant openssl_cms_read(const Variant &input_filename, const Reference &certificates) {
    return call(LITERAL_STRING[751], {input_filename, &certificates});
}
Variant openssl_private_encrypt(const Variant &data,
                                const Reference &encrypted_data,
                                const Variant &private_key,
                                const Variant &padding) {
    return call(LITERAL_STRING[752], {data, &encrypted_data, private_key, padding});
}
Variant openssl_private_decrypt(const Variant &data,
                                const Reference &decrypted_data,
                                const Variant &private_key,
                                const Variant &padding) {
    return call(LITERAL_STRING[753], {data, &decrypted_data, private_key, padding});
}
Variant openssl_public_encrypt(const Variant &data,
                               const Reference &encrypted_data,
                               const Variant &public_key,
                               const Variant &padding) {
    return call(LITERAL_STRING[754], {data, &encrypted_data, public_key, padding});
}
Variant openssl_public_decrypt(const Variant &data,
                               const Reference &decrypted_data,
                               const Variant &public_key,
                               const Variant &padding) {
    return call(LITERAL_STRING[755], {data, &decrypted_data, public_key, padding});
}
Variant openssl_error_string() {
    return call(LITERAL_STRING[756], {});
}
Variant openssl_sign(const Variant &data,
                     const Reference &signature,
                     const Variant &private_key,
                     const Variant &algorithm) {
    return call(LITERAL_STRING[757], {data, &signature, private_key, algorithm});
}
Variant openssl_verify(const Variant &data,
                       const Variant &signature,
                       const Variant &public_key,
                       const Variant &algorithm) {
    return call(LITERAL_STRING[758], {data, signature, public_key, algorithm});
}
Variant openssl_seal(const Variant &data,
                     const Reference &sealed_data,
                     const Reference &encrypted_keys,
                     const Variant &public_key,
                     const Variant &cipher_algo,
                     const Reference &iv) {
    return call(LITERAL_STRING[759], {data, &sealed_data, &encrypted_keys, public_key, cipher_algo, &iv});
}
Variant openssl_open(const Variant &data,
                     const Reference &output,
                     const Variant &encrypted_key,
                     const Variant &private_key,
                     const Variant &cipher_algo,
                     const Variant &iv) {
    return call(LITERAL_STRING[760], {data, &output, encrypted_key, private_key, cipher_algo, iv});
}
Variant openssl_get_md_methods(const Variant &aliases) {
    return call(LITERAL_STRING[761], {aliases});
}
Variant openssl_get_cipher_methods(const Variant &aliases) {
    return call(LITERAL_STRING[762], {aliases});
}
Variant openssl_get_curve_names() {
    return call(LITERAL_STRING[763], {});
}
Variant openssl_digest(const Variant &data, const Variant &digest_algo, const Variant &binary) {
    return call(LITERAL_STRING[764], {data, digest_algo, binary});
}
Variant openssl_encrypt(const Variant &data,
                        const Variant &cipher_algo,
                        const Variant &passphrase,
                        const Variant &options,
                        const Variant &iv,
                        const Reference &tag,
                        const Variant &aad,
                        const Variant &tag_length) {
    return call(LITERAL_STRING[765], {data, cipher_algo, passphrase, options, iv, &tag, aad, tag_length});
}
Variant openssl_decrypt(const Variant &data,
                        const Variant &cipher_algo,
                        const Variant &passphrase,
                        const Variant &options,
                        const Variant &iv,
                        const Variant &tag,
                        const Variant &aad) {
    return call(LITERAL_STRING[766], {data, cipher_algo, passphrase, options, iv, tag, aad});
}
Variant openssl_cipher_iv_length(const Variant &cipher_algo) {
    return call(LITERAL_STRING[767], {cipher_algo});
}
Variant openssl_cipher_key_length(const Variant &cipher_algo) {
    return call(LITERAL_STRING[768], {cipher_algo});
}
Variant openssl_dh_compute_key(const Variant &public_key, const Variant &private_key) {
    return call(LITERAL_STRING[769], {public_key, private_key});
}
Variant openssl_pkey_derive(const Variant &public_key, const Variant &private_key, const Variant &key_length) {
    return call(LITERAL_STRING[770], {public_key, private_key, key_length});
}
Variant openssl_random_pseudo_bytes(const Variant &length, const Reference &strong_result) {
    return call(LITERAL_STRING[771], {length, &strong_result});
}
Variant openssl_spki_new(const Variant &private_key, const Variant &challenge, const Variant &digest_algo) {
    return call(LITERAL_STRING[772], {private_key, challenge, digest_algo});
}
Variant openssl_spki_verify(const Variant &spki) {
    return call(LITERAL_STRING[773], {spki});
}
Variant openssl_spki_export(const Variant &spki) {
    return call(LITERAL_STRING[774], {spki});
}
Variant openssl_spki_export_challenge(const Variant &spki) {
    return call(LITERAL_STRING[775], {spki});
}
Variant openssl_get_cert_locations() {
    return call(LITERAL_STRING[776], {});
}
}  // namespace php

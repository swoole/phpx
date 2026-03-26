#include "phpx.h"

namespace php {
Variant openssl_x509_export_to_file(const Variant &certificate, const Variant &output_filename, const Variant &no_text) {
    return call("openssl_x509_export_to_file", {certificate, output_filename, no_text});
}
Variant openssl_x509_export(const Variant &certificate, const Reference &output, const Variant &no_text) {
    return call("openssl_x509_export", {certificate, &output, no_text});
}
Variant openssl_x509_fingerprint(const Variant &certificate, const Variant &digest_algo, const Variant &binary) {
    return call("openssl_x509_fingerprint", {certificate, digest_algo, binary});
}
Variant openssl_x509_check_private_key(const Variant &certificate, const Variant &private_key) {
    return call("openssl_x509_check_private_key", {certificate, private_key});
}
Variant openssl_x509_verify(const Variant &certificate, const Variant &public_key) {
    return call("openssl_x509_verify", {certificate, public_key});
}
Variant openssl_x509_parse(const Variant &certificate, const Variant &short_names) {
    return call("openssl_x509_parse", {certificate, short_names});
}
Variant openssl_x509_checkpurpose(const Variant &certificate, const Variant &purpose, const Variant &ca_info, const Variant &untrusted_certificates_file) {
    return call("openssl_x509_checkpurpose", {certificate, purpose, ca_info, untrusted_certificates_file});
}
Variant openssl_x509_read(const Variant &certificate) {
    return call("openssl_x509_read", {certificate});
}
Variant openssl_x509_free(const Variant &certificate) {
    return call("openssl_x509_free", {certificate});
}
Variant openssl_pkcs12_export_to_file(const Variant &certificate, const Variant &output_filename, const Variant &private_key, const Variant &passphrase, const Variant &options) {
    return call("openssl_pkcs12_export_to_file", {certificate, output_filename, private_key, passphrase, options});
}
Variant openssl_pkcs12_export(const Variant &certificate, const Reference &output, const Variant &private_key, const Variant &passphrase, const Variant &options) {
    return call("openssl_pkcs12_export", {certificate, &output, private_key, passphrase, options});
}
Variant openssl_pkcs12_read(const Variant &pkcs12, const Reference &certificates, const Variant &passphrase) {
    return call("openssl_pkcs12_read", {pkcs12, &certificates, passphrase});
}
Variant openssl_csr_export_to_file(const Variant &csr, const Variant &output_filename, const Variant &no_text) {
    return call("openssl_csr_export_to_file", {csr, output_filename, no_text});
}
Variant openssl_csr_export(const Variant &csr, const Reference &output, const Variant &no_text) {
    return call("openssl_csr_export", {csr, &output, no_text});
}
Variant openssl_csr_sign(const Variant &csr, const Variant &ca_certificate, const Variant &private_key, const Variant &days, const Variant &options, const Variant &serial, const Variant &serial_hex) {
    return call("openssl_csr_sign", {csr, ca_certificate, private_key, days, options, serial, serial_hex});
}
Variant openssl_csr_new(const Variant &distinguished_names, const Reference &private_key, const Variant &options, const Variant &extra_attributes) {
    return call("openssl_csr_new", {distinguished_names, &private_key, options, extra_attributes});
}
Variant openssl_csr_get_subject(const Variant &csr, const Variant &short_names) {
    return call("openssl_csr_get_subject", {csr, short_names});
}
Variant openssl_csr_get_public_key(const Variant &csr, const Variant &short_names) {
    return call("openssl_csr_get_public_key", {csr, short_names});
}
Variant openssl_pkey_new(const Variant &options) {
    return call("openssl_pkey_new", {options});
}
Variant openssl_pkey_export_to_file(const Variant &key, const Variant &output_filename, const Variant &passphrase, const Variant &options) {
    return call("openssl_pkey_export_to_file", {key, output_filename, passphrase, options});
}
Variant openssl_pkey_export(const Variant &key, const Reference &output, const Variant &passphrase, const Variant &options) {
    return call("openssl_pkey_export", {key, &output, passphrase, options});
}
Variant openssl_pkey_get_public(const Variant &public_key) {
    return call("openssl_pkey_get_public", {public_key});
}
Variant openssl_get_publickey(const Variant &public_key) {
    return call("openssl_get_publickey", {public_key});
}
Variant openssl_pkey_free(const Variant &key) {
    return call("openssl_pkey_free", {key});
}
Variant openssl_free_key(const Variant &key) {
    return call("openssl_free_key", {key});
}
Variant openssl_pkey_get_private(const Variant &private_key, const Variant &passphrase) {
    return call("openssl_pkey_get_private", {private_key, passphrase});
}
Variant openssl_get_privatekey(const Variant &private_key, const Variant &passphrase) {
    return call("openssl_get_privatekey", {private_key, passphrase});
}
Variant openssl_pkey_get_details(const Variant &key) {
    return call("openssl_pkey_get_details", {key});
}
Variant openssl_pbkdf2(const Variant &password, const Variant &salt, const Variant &key_length, const Variant &iterations, const Variant &digest_algo) {
    return call("openssl_pbkdf2", {password, salt, key_length, iterations, digest_algo});
}
Variant openssl_pkcs7_verify(const Variant &input_filename, const Variant &flags, const Variant &signers_certificates_filename, const Variant &ca_info, const Variant &untrusted_certificates_filename, const Variant &content, const Variant &output_filename) {
    return call("openssl_pkcs7_verify", {input_filename, flags, signers_certificates_filename, ca_info, untrusted_certificates_filename, content, output_filename});
}
Variant openssl_pkcs7_encrypt(const Variant &input_filename, const Variant &output_filename, const Variant &certificate, const Variant &headers, const Variant &flags, const Variant &cipher_algo) {
    return call("openssl_pkcs7_encrypt", {input_filename, output_filename, certificate, headers, flags, cipher_algo});
}
Variant openssl_pkcs7_sign(const Variant &input_filename, const Variant &output_filename, const Variant &certificate, const Variant &private_key, const Variant &headers, const Variant &flags, const Variant &untrusted_certificates_filename) {
    return call("openssl_pkcs7_sign", {input_filename, output_filename, certificate, private_key, headers, flags, untrusted_certificates_filename});
}
Variant openssl_pkcs7_decrypt(const Variant &input_filename, const Variant &output_filename, const Variant &certificate, const Variant &private_key) {
    return call("openssl_pkcs7_decrypt", {input_filename, output_filename, certificate, private_key});
}
Variant openssl_pkcs7_read(const Variant &data, const Reference &certificates) {
    return call("openssl_pkcs7_read", {data, &certificates});
}
Variant openssl_cms_verify(const Variant &input_filename, const Variant &flags, const Variant &certificates, const Variant &ca_info, const Variant &untrusted_certificates_filename, const Variant &content, const Variant &pk7, const Variant &sigfile, const Variant &encoding) {
    return call("openssl_cms_verify", {input_filename, flags, certificates, ca_info, untrusted_certificates_filename, content, pk7, sigfile, encoding});
}
Variant openssl_cms_encrypt(const Variant &input_filename, const Variant &output_filename, const Variant &certificate, const Variant &headers, const Variant &flags, const Variant &encoding, const Variant &cipher_algo) {
    return call("openssl_cms_encrypt", {input_filename, output_filename, certificate, headers, flags, encoding, cipher_algo});
}
Variant openssl_cms_sign(const Variant &input_filename, const Variant &output_filename, const Variant &certificate, const Variant &private_key, const Variant &headers, const Variant &flags, const Variant &encoding, const Variant &untrusted_certificates_filename) {
    return call("openssl_cms_sign", {input_filename, output_filename, certificate, private_key, headers, flags, encoding, untrusted_certificates_filename});
}
Variant openssl_cms_decrypt(const Variant &input_filename, const Variant &output_filename, const Variant &certificate, const Variant &private_key, const Variant &encoding) {
    return call("openssl_cms_decrypt", {input_filename, output_filename, certificate, private_key, encoding});
}
Variant openssl_cms_read(const Variant &input_filename, const Reference &certificates) {
    return call("openssl_cms_read", {input_filename, &certificates});
}
Variant openssl_private_encrypt(const Variant &data, const Reference &encrypted_data, const Variant &private_key, const Variant &padding) {
    return call("openssl_private_encrypt", {data, &encrypted_data, private_key, padding});
}
Variant openssl_private_decrypt(const Variant &data, const Reference &decrypted_data, const Variant &private_key, const Variant &padding) {
    return call("openssl_private_decrypt", {data, &decrypted_data, private_key, padding});
}
Variant openssl_public_encrypt(const Variant &data, const Reference &encrypted_data, const Variant &public_key, const Variant &padding) {
    return call("openssl_public_encrypt", {data, &encrypted_data, public_key, padding});
}
Variant openssl_public_decrypt(const Variant &data, const Reference &decrypted_data, const Variant &public_key, const Variant &padding) {
    return call("openssl_public_decrypt", {data, &decrypted_data, public_key, padding});
}
Variant openssl_error_string() {
    return call("openssl_error_string", {});
}
Variant openssl_sign(const Variant &data, const Reference &signature, const Variant &private_key, const Variant &algorithm) {
    return call("openssl_sign", {data, &signature, private_key, algorithm});
}
Variant openssl_verify(const Variant &data, const Variant &signature, const Variant &public_key, const Variant &algorithm) {
    return call("openssl_verify", {data, signature, public_key, algorithm});
}
Variant openssl_seal(const Variant &data, const Reference &sealed_data, const Reference &encrypted_keys, const Variant &public_key, const Variant &cipher_algo, const Reference &iv) {
    return call("openssl_seal", {data, &sealed_data, &encrypted_keys, public_key, cipher_algo, &iv});
}
Variant openssl_open(const Variant &data, const Reference &output, const Variant &encrypted_key, const Variant &private_key, const Variant &cipher_algo, const Variant &iv) {
    return call("openssl_open", {data, &output, encrypted_key, private_key, cipher_algo, iv});
}
Variant openssl_get_md_methods(const Variant &aliases) {
    return call("openssl_get_md_methods", {aliases});
}
Variant openssl_get_cipher_methods(const Variant &aliases) {
    return call("openssl_get_cipher_methods", {aliases});
}
Variant openssl_get_curve_names() {
    return call("openssl_get_curve_names", {});
}
Variant openssl_digest(const Variant &data, const Variant &digest_algo, const Variant &binary) {
    return call("openssl_digest", {data, digest_algo, binary});
}
Variant openssl_encrypt(const Variant &data, const Variant &cipher_algo, const Variant &passphrase, const Variant &options, const Variant &iv, const Reference &tag, const Variant &aad, const Variant &tag_length) {
    return call("openssl_encrypt", {data, cipher_algo, passphrase, options, iv, &tag, aad, tag_length});
}
Variant openssl_decrypt(const Variant &data, const Variant &cipher_algo, const Variant &passphrase, const Variant &options, const Variant &iv, const Variant &tag, const Variant &aad) {
    return call("openssl_decrypt", {data, cipher_algo, passphrase, options, iv, tag, aad});
}
Variant openssl_cipher_iv_length(const Variant &cipher_algo) {
    return call("openssl_cipher_iv_length", {cipher_algo});
}
Variant openssl_cipher_key_length(const Variant &cipher_algo) {
    return call("openssl_cipher_key_length", {cipher_algo});
}
Variant openssl_dh_compute_key(const Variant &public_key, const Variant &private_key) {
    return call("openssl_dh_compute_key", {public_key, private_key});
}
Variant openssl_pkey_derive(const Variant &public_key, const Variant &private_key, const Variant &key_length) {
    return call("openssl_pkey_derive", {public_key, private_key, key_length});
}
Variant openssl_random_pseudo_bytes(const Variant &length, const Reference &strong_result) {
    return call("openssl_random_pseudo_bytes", {length, &strong_result});
}
Variant openssl_spki_new(const Variant &private_key, const Variant &challenge, const Variant &digest_algo) {
    return call("openssl_spki_new", {private_key, challenge, digest_algo});
}
Variant openssl_spki_verify(const Variant &spki) {
    return call("openssl_spki_verify", {spki});
}
Variant openssl_spki_export(const Variant &spki) {
    return call("openssl_spki_export", {spki});
}
Variant openssl_spki_export_challenge(const Variant &spki) {
    return call("openssl_spki_export_challenge", {spki});
}
Variant openssl_get_cert_locations() {
    return call("openssl_get_cert_locations", {});
}
}

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant sodium_crypto_aead_aes256gcm_is_available() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1909]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_aead_aes256gcm_decrypt(const Variant &ciphertext,
                                             const Variant &additional_data,
                                             const Variant &nonce,
                                             const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1910]);
    }
    return call(_fn, {ciphertext, additional_data, nonce, key});
}
Variant sodium_crypto_aead_aes256gcm_encrypt(const Variant &message,
                                             const Variant &additional_data,
                                             const Variant &nonce,
                                             const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1911]);
    }
    return call(_fn, {message, additional_data, nonce, key});
}
Variant sodium_crypto_aead_aes256gcm_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1912]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_aead_chacha20poly1305_decrypt(const Variant &ciphertext,
                                                    const Variant &additional_data,
                                                    const Variant &nonce,
                                                    const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1913]);
    }
    return call(_fn, {ciphertext, additional_data, nonce, key});
}
Variant sodium_crypto_aead_chacha20poly1305_encrypt(const Variant &message,
                                                    const Variant &additional_data,
                                                    const Variant &nonce,
                                                    const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1914]);
    }
    return call(_fn, {message, additional_data, nonce, key});
}
Variant sodium_crypto_aead_chacha20poly1305_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1915]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_aead_chacha20poly1305_ietf_decrypt(const Variant &ciphertext,
                                                         const Variant &additional_data,
                                                         const Variant &nonce,
                                                         const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1916]);
    }
    return call(_fn, {ciphertext, additional_data, nonce, key});
}
Variant sodium_crypto_aead_chacha20poly1305_ietf_encrypt(const Variant &message,
                                                         const Variant &additional_data,
                                                         const Variant &nonce,
                                                         const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1917]);
    }
    return call(_fn, {message, additional_data, nonce, key});
}
Variant sodium_crypto_aead_chacha20poly1305_ietf_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1918]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_aead_xchacha20poly1305_ietf_decrypt(const Variant &ciphertext,
                                                          const Variant &additional_data,
                                                          const Variant &nonce,
                                                          const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1919]);
    }
    return call(_fn, {ciphertext, additional_data, nonce, key});
}
Variant sodium_crypto_aead_xchacha20poly1305_ietf_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1920]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_aead_xchacha20poly1305_ietf_encrypt(const Variant &message,
                                                          const Variant &additional_data,
                                                          const Variant &nonce,
                                                          const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1921]);
    }
    return call(_fn, {message, additional_data, nonce, key});
}
Variant sodium_crypto_auth(const Variant &message, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1922]);
    }
    return call(_fn, {message, key});
}
Variant sodium_crypto_auth_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1923]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_auth_verify(const Variant &mac, const Variant &message, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1924]);
    }
    return call(_fn, {mac, message, key});
}
Variant sodium_crypto_box(const Variant &message, const Variant &nonce, const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1925]);
    }
    return call(_fn, {message, nonce, key_pair});
}
Variant sodium_crypto_box_keypair() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1926]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_box_seed_keypair(const Variant &seed) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1927]);
    }
    return call(_fn, {seed});
}
Variant sodium_crypto_box_keypair_from_secretkey_and_publickey(const Variant &secret_key, const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1928]);
    }
    return call(_fn, {secret_key, public_key});
}
Variant sodium_crypto_box_open(const Variant &ciphertext, const Variant &nonce, const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1929]);
    }
    return call(_fn, {ciphertext, nonce, key_pair});
}
Variant sodium_crypto_box_publickey(const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1930]);
    }
    return call(_fn, {key_pair});
}
Variant sodium_crypto_box_publickey_from_secretkey(const Variant &secret_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1931]);
    }
    return call(_fn, {secret_key});
}
Variant sodium_crypto_box_seal(const Variant &message, const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1932]);
    }
    return call(_fn, {message, public_key});
}
Variant sodium_crypto_box_seal_open(const Variant &ciphertext, const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1933]);
    }
    return call(_fn, {ciphertext, key_pair});
}
Variant sodium_crypto_box_secretkey(const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1934]);
    }
    return call(_fn, {key_pair});
}
Variant sodium_crypto_core_ristretto255_add(const Variant &p, const Variant &q) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1935]);
    }
    return call(_fn, {p, q});
}
Variant sodium_crypto_core_ristretto255_from_hash(const Variant &s) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1936]);
    }
    return call(_fn, {s});
}
Variant sodium_crypto_core_ristretto255_is_valid_point(const Variant &s) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1937]);
    }
    return call(_fn, {s});
}
Variant sodium_crypto_core_ristretto255_random() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1938]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_core_ristretto255_scalar_add(const Variant &x, const Variant &y) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1939]);
    }
    return call(_fn, {x, y});
}
Variant sodium_crypto_core_ristretto255_scalar_complement(const Variant &s) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1940]);
    }
    return call(_fn, {s});
}
Variant sodium_crypto_core_ristretto255_scalar_invert(const Variant &s) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1941]);
    }
    return call(_fn, {s});
}
Variant sodium_crypto_core_ristretto255_scalar_mul(const Variant &x, const Variant &y) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1942]);
    }
    return call(_fn, {x, y});
}
Variant sodium_crypto_core_ristretto255_scalar_negate(const Variant &s) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1943]);
    }
    return call(_fn, {s});
}
Variant sodium_crypto_core_ristretto255_scalar_random() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1944]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_core_ristretto255_scalar_reduce(const Variant &s) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1945]);
    }
    return call(_fn, {s});
}
Variant sodium_crypto_core_ristretto255_scalar_sub(const Variant &x, const Variant &y) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1946]);
    }
    return call(_fn, {x, y});
}
Variant sodium_crypto_core_ristretto255_sub(const Variant &p, const Variant &q) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1947]);
    }
    return call(_fn, {p, q});
}
Variant sodium_crypto_kx_keypair() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1948]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_kx_publickey(const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1949]);
    }
    return call(_fn, {key_pair});
}
Variant sodium_crypto_kx_secretkey(const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1950]);
    }
    return call(_fn, {key_pair});
}
Variant sodium_crypto_kx_seed_keypair(const Variant &seed) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1951]);
    }
    return call(_fn, {seed});
}
Variant sodium_crypto_kx_client_session_keys(const Variant &client_key_pair, const Variant &server_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1952]);
    }
    return call(_fn, {client_key_pair, server_key});
}
Variant sodium_crypto_kx_server_session_keys(const Variant &server_key_pair, const Variant &client_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1953]);
    }
    return call(_fn, {server_key_pair, client_key});
}
Variant sodium_crypto_generichash(const Variant &message, const Variant &key, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1954]);
    }
    return call(_fn, {message, key, length});
}
Variant sodium_crypto_generichash_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1955]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_generichash_init(const Variant &key, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1956]);
    }
    return call(_fn, {key, length});
}
Variant sodium_crypto_generichash_update(const Reference &state, const Variant &message) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1957]);
    }
    return call(_fn, {&state, message});
}
Variant sodium_crypto_generichash_final(const Reference &state, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1958]);
    }
    return call(_fn, {&state, length});
}
Variant sodium_crypto_kdf_derive_from_key(const Variant &subkey_length,
                                          const Variant &subkey_id,
                                          const Variant &context,
                                          const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1959]);
    }
    return call(_fn, {subkey_length, subkey_id, context, key});
}
Variant sodium_crypto_kdf_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1960]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_pwhash(const Variant &length,
                             const Variant &password,
                             const Variant &salt,
                             const Variant &opslimit,
                             const Variant &memlimit,
                             const Variant &algo) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1961]);
    }
    return call(_fn, {length, password, salt, opslimit, memlimit, algo});
}
Variant sodium_crypto_pwhash_str(const Variant &password, const Variant &opslimit, const Variant &memlimit) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1962]);
    }
    return call(_fn, {password, opslimit, memlimit});
}
Variant sodium_crypto_pwhash_str_verify(const Variant &hash, const Variant &password) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1963]);
    }
    return call(_fn, {hash, password});
}
Variant sodium_crypto_pwhash_str_needs_rehash(const Variant &password,
                                              const Variant &opslimit,
                                              const Variant &memlimit) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1964]);
    }
    return call(_fn, {password, opslimit, memlimit});
}
Variant sodium_crypto_pwhash_scryptsalsa208sha256(const Variant &length,
                                                  const Variant &password,
                                                  const Variant &salt,
                                                  const Variant &opslimit,
                                                  const Variant &memlimit) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1965]);
    }
    return call(_fn, {length, password, salt, opslimit, memlimit});
}
Variant sodium_crypto_pwhash_scryptsalsa208sha256_str(const Variant &password,
                                                      const Variant &opslimit,
                                                      const Variant &memlimit) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1966]);
    }
    return call(_fn, {password, opslimit, memlimit});
}
Variant sodium_crypto_pwhash_scryptsalsa208sha256_str_verify(const Variant &hash, const Variant &password) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1967]);
    }
    return call(_fn, {hash, password});
}
Variant sodium_crypto_scalarmult(const Variant &n, const Variant &p) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1968]);
    }
    return call(_fn, {n, p});
}
Variant sodium_crypto_scalarmult_ristretto255(const Variant &n, const Variant &p) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1969]);
    }
    return call(_fn, {n, p});
}
Variant sodium_crypto_scalarmult_ristretto255_base(const Variant &n) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1970]);
    }
    return call(_fn, {n});
}
Variant sodium_crypto_secretbox(const Variant &message, const Variant &nonce, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1971]);
    }
    return call(_fn, {message, nonce, key});
}
Variant sodium_crypto_secretbox_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1972]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_secretbox_open(const Variant &ciphertext, const Variant &nonce, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1973]);
    }
    return call(_fn, {ciphertext, nonce, key});
}
Variant sodium_crypto_secretstream_xchacha20poly1305_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1974]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_secretstream_xchacha20poly1305_init_push(const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1975]);
    }
    return call(_fn, {key});
}
Variant sodium_crypto_secretstream_xchacha20poly1305_push(const Reference &state,
                                                          const Variant &message,
                                                          const Variant &additional_data,
                                                          const Variant &tag) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1976]);
    }
    return call(_fn, {&state, message, additional_data, tag});
}
Variant sodium_crypto_secretstream_xchacha20poly1305_init_pull(const Variant &header, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1977]);
    }
    return call(_fn, {header, key});
}
Variant sodium_crypto_secretstream_xchacha20poly1305_pull(const Reference &state,
                                                          const Variant &ciphertext,
                                                          const Variant &additional_data) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1978]);
    }
    return call(_fn, {&state, ciphertext, additional_data});
}
Variant sodium_crypto_secretstream_xchacha20poly1305_rekey(const Reference &state) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1979]);
    }
    return call(_fn, {&state});
}
Variant sodium_crypto_shorthash(const Variant &message, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1980]);
    }
    return call(_fn, {message, key});
}
Variant sodium_crypto_shorthash_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1981]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_sign(const Variant &message, const Variant &secret_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1982]);
    }
    return call(_fn, {message, secret_key});
}
Variant sodium_crypto_sign_detached(const Variant &message, const Variant &secret_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1983]);
    }
    return call(_fn, {message, secret_key});
}
Variant sodium_crypto_sign_ed25519_pk_to_curve25519(const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1984]);
    }
    return call(_fn, {public_key});
}
Variant sodium_crypto_sign_ed25519_sk_to_curve25519(const Variant &secret_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1985]);
    }
    return call(_fn, {secret_key});
}
Variant sodium_crypto_sign_keypair() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1986]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_sign_keypair_from_secretkey_and_publickey(const Variant &secret_key, const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1987]);
    }
    return call(_fn, {secret_key, public_key});
}
Variant sodium_crypto_sign_open(const Variant &signed_message, const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1988]);
    }
    return call(_fn, {signed_message, public_key});
}
Variant sodium_crypto_sign_publickey(const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1989]);
    }
    return call(_fn, {key_pair});
}
Variant sodium_crypto_sign_secretkey(const Variant &key_pair) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1990]);
    }
    return call(_fn, {key_pair});
}
Variant sodium_crypto_sign_publickey_from_secretkey(const Variant &secret_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1991]);
    }
    return call(_fn, {secret_key});
}
Variant sodium_crypto_sign_seed_keypair(const Variant &seed) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1992]);
    }
    return call(_fn, {seed});
}
Variant sodium_crypto_sign_verify_detached(const Variant &signature,
                                           const Variant &message,
                                           const Variant &public_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1993]);
    }
    return call(_fn, {signature, message, public_key});
}
Variant sodium_crypto_stream(const Variant &length, const Variant &nonce, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1994]);
    }
    return call(_fn, {length, nonce, key});
}
Variant sodium_crypto_stream_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1995]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_stream_xor(const Variant &message, const Variant &nonce, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1996]);
    }
    return call(_fn, {message, nonce, key});
}
Variant sodium_crypto_stream_xchacha20(const Variant &length, const Variant &nonce, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1997]);
    }
    return call(_fn, {length, nonce, key});
}
Variant sodium_crypto_stream_xchacha20_keygen() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1998]);
    }
    return call(_fn, {});
}
Variant sodium_crypto_stream_xchacha20_xor(const Variant &message, const Variant &nonce, const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1999]);
    }
    return call(_fn, {message, nonce, key});
}
Variant sodium_crypto_stream_xchacha20_xor_ic(const Variant &message,
                                              const Variant &nonce,
                                              const Variant &counter,
                                              const Variant &key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2000]);
    }
    return call(_fn, {message, nonce, counter, key});
}
Variant sodium_add(const Reference &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2001]);
    }
    return call(_fn, {&string1, string2});
}
Variant sodium_compare(const Variant &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2002]);
    }
    return call(_fn, {string1, string2});
}
Variant sodium_increment(const Reference &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2003]);
    }
    return call(_fn, {&string});
}
Variant sodium_memcmp(const Variant &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2004]);
    }
    return call(_fn, {string1, string2});
}
Variant sodium_memzero(const Reference &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2005]);
    }
    return call(_fn, {&string});
}
Variant sodium_pad(const Variant &string, const Variant &block_size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2006]);
    }
    return call(_fn, {string, block_size});
}
Variant sodium_unpad(const Variant &string, const Variant &block_size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2007]);
    }
    return call(_fn, {string, block_size});
}
Variant sodium_bin2hex(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2008]);
    }
    return call(_fn, {string});
}
Variant sodium_hex2bin(const Variant &string, const Variant &ignore) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2009]);
    }
    return call(_fn, {string, ignore});
}
Variant sodium_bin2base64(const Variant &string, const Variant &id) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2010]);
    }
    return call(_fn, {string, id});
}
Variant sodium_base642bin(const Variant &string, const Variant &id, const Variant &ignore) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2011]);
    }
    return call(_fn, {string, id, ignore});
}
Variant sodium_crypto_scalarmult_base(const Variant &secret_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2012]);
    }
    return call(_fn, {secret_key});
}
}  // namespace php

#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant sodium_crypto_aead_aes256gcm_is_available();
Variant sodium_crypto_aead_aes256gcm_decrypt(const Variant &ciphertext,
                                             const Variant &additional_data,
                                             const Variant &nonce,
                                             const Variant &key);
Variant sodium_crypto_aead_aes256gcm_encrypt(const Variant &message,
                                             const Variant &additional_data,
                                             const Variant &nonce,
                                             const Variant &key);
Variant sodium_crypto_aead_aes256gcm_keygen();
Variant sodium_crypto_aead_chacha20poly1305_decrypt(const Variant &ciphertext,
                                                    const Variant &additional_data,
                                                    const Variant &nonce,
                                                    const Variant &key);
Variant sodium_crypto_aead_chacha20poly1305_encrypt(const Variant &message,
                                                    const Variant &additional_data,
                                                    const Variant &nonce,
                                                    const Variant &key);
Variant sodium_crypto_aead_chacha20poly1305_keygen();
Variant sodium_crypto_aead_chacha20poly1305_ietf_decrypt(const Variant &ciphertext,
                                                         const Variant &additional_data,
                                                         const Variant &nonce,
                                                         const Variant &key);
Variant sodium_crypto_aead_chacha20poly1305_ietf_encrypt(const Variant &message,
                                                         const Variant &additional_data,
                                                         const Variant &nonce,
                                                         const Variant &key);
Variant sodium_crypto_aead_chacha20poly1305_ietf_keygen();
Variant sodium_crypto_aead_xchacha20poly1305_ietf_decrypt(const Variant &ciphertext,
                                                          const Variant &additional_data,
                                                          const Variant &nonce,
                                                          const Variant &key);
Variant sodium_crypto_aead_xchacha20poly1305_ietf_keygen();
Variant sodium_crypto_aead_xchacha20poly1305_ietf_encrypt(const Variant &message,
                                                          const Variant &additional_data,
                                                          const Variant &nonce,
                                                          const Variant &key);
Variant sodium_crypto_auth(const Variant &message, const Variant &key);
Variant sodium_crypto_auth_keygen();
Variant sodium_crypto_auth_verify(const Variant &mac, const Variant &message, const Variant &key);
Variant sodium_crypto_box(const Variant &message, const Variant &nonce, const Variant &key_pair);
Variant sodium_crypto_box_keypair();
Variant sodium_crypto_box_seed_keypair(const Variant &seed);
Variant sodium_crypto_box_keypair_from_secretkey_and_publickey(const Variant &secret_key, const Variant &public_key);
Variant sodium_crypto_box_open(const Variant &ciphertext, const Variant &nonce, const Variant &key_pair);
Variant sodium_crypto_box_publickey(const Variant &key_pair);
Variant sodium_crypto_box_publickey_from_secretkey(const Variant &secret_key);
Variant sodium_crypto_box_seal(const Variant &message, const Variant &public_key);
Variant sodium_crypto_box_seal_open(const Variant &ciphertext, const Variant &key_pair);
Variant sodium_crypto_box_secretkey(const Variant &key_pair);
Variant sodium_crypto_core_ristretto255_add(const Variant &p, const Variant &q);
Variant sodium_crypto_core_ristretto255_from_hash(const Variant &s);
Variant sodium_crypto_core_ristretto255_is_valid_point(const Variant &s);
Variant sodium_crypto_core_ristretto255_random();
Variant sodium_crypto_core_ristretto255_scalar_add(const Variant &x, const Variant &y);
Variant sodium_crypto_core_ristretto255_scalar_complement(const Variant &s);
Variant sodium_crypto_core_ristretto255_scalar_invert(const Variant &s);
Variant sodium_crypto_core_ristretto255_scalar_mul(const Variant &x, const Variant &y);
Variant sodium_crypto_core_ristretto255_scalar_negate(const Variant &s);
Variant sodium_crypto_core_ristretto255_scalar_random();
Variant sodium_crypto_core_ristretto255_scalar_reduce(const Variant &s);
Variant sodium_crypto_core_ristretto255_scalar_sub(const Variant &x, const Variant &y);
Variant sodium_crypto_core_ristretto255_sub(const Variant &p, const Variant &q);
Variant sodium_crypto_kx_keypair();
Variant sodium_crypto_kx_publickey(const Variant &key_pair);
Variant sodium_crypto_kx_secretkey(const Variant &key_pair);
Variant sodium_crypto_kx_seed_keypair(const Variant &seed);
Variant sodium_crypto_kx_client_session_keys(const Variant &client_key_pair, const Variant &server_key);
Variant sodium_crypto_kx_server_session_keys(const Variant &server_key_pair, const Variant &client_key);
Variant sodium_crypto_generichash(const Variant &message, const Variant &key = "", const Variant &length = 32);
Variant sodium_crypto_generichash_keygen();
Variant sodium_crypto_generichash_init(const Variant &key = "", const Variant &length = 32);
Variant sodium_crypto_generichash_update(const Reference &state, const Variant &message);
Variant sodium_crypto_generichash_final(const Reference &state, const Variant &length = 32);
Variant sodium_crypto_kdf_derive_from_key(const Variant &subkey_length,
                                          const Variant &subkey_id,
                                          const Variant &context,
                                          const Variant &key);
Variant sodium_crypto_kdf_keygen();
Variant sodium_crypto_pwhash(const Variant &length,
                             const Variant &password,
                             const Variant &salt,
                             const Variant &opslimit,
                             const Variant &memlimit,
                             const Variant &algo = 2);
Variant sodium_crypto_pwhash_str(const Variant &password, const Variant &opslimit, const Variant &memlimit);
Variant sodium_crypto_pwhash_str_verify(const Variant &hash, const Variant &password);
Variant sodium_crypto_pwhash_str_needs_rehash(const Variant &password,
                                              const Variant &opslimit,
                                              const Variant &memlimit);
Variant sodium_crypto_pwhash_scryptsalsa208sha256(const Variant &length,
                                                  const Variant &password,
                                                  const Variant &salt,
                                                  const Variant &opslimit,
                                                  const Variant &memlimit);
Variant sodium_crypto_pwhash_scryptsalsa208sha256_str(const Variant &password,
                                                      const Variant &opslimit,
                                                      const Variant &memlimit);
Variant sodium_crypto_pwhash_scryptsalsa208sha256_str_verify(const Variant &hash, const Variant &password);
Variant sodium_crypto_scalarmult(const Variant &n, const Variant &p);
Variant sodium_crypto_scalarmult_ristretto255(const Variant &n, const Variant &p);
Variant sodium_crypto_scalarmult_ristretto255_base(const Variant &n);
Variant sodium_crypto_secretbox(const Variant &message, const Variant &nonce, const Variant &key);
Variant sodium_crypto_secretbox_keygen();
Variant sodium_crypto_secretbox_open(const Variant &ciphertext, const Variant &nonce, const Variant &key);
Variant sodium_crypto_secretstream_xchacha20poly1305_keygen();
Variant sodium_crypto_secretstream_xchacha20poly1305_init_push(const Variant &key);
Variant sodium_crypto_secretstream_xchacha20poly1305_push(const Reference &state,
                                                          const Variant &message,
                                                          const Variant &additional_data = "",
                                                          const Variant &tag = 0);
Variant sodium_crypto_secretstream_xchacha20poly1305_init_pull(const Variant &header, const Variant &key);
Variant sodium_crypto_secretstream_xchacha20poly1305_pull(const Reference &state,
                                                          const Variant &ciphertext,
                                                          const Variant &additional_data = "");
Variant sodium_crypto_secretstream_xchacha20poly1305_rekey(const Reference &state);
Variant sodium_crypto_shorthash(const Variant &message, const Variant &key);
Variant sodium_crypto_shorthash_keygen();
Variant sodium_crypto_sign(const Variant &message, const Variant &secret_key);
Variant sodium_crypto_sign_detached(const Variant &message, const Variant &secret_key);
Variant sodium_crypto_sign_ed25519_pk_to_curve25519(const Variant &public_key);
Variant sodium_crypto_sign_ed25519_sk_to_curve25519(const Variant &secret_key);
Variant sodium_crypto_sign_keypair();
Variant sodium_crypto_sign_keypair_from_secretkey_and_publickey(const Variant &secret_key, const Variant &public_key);
Variant sodium_crypto_sign_open(const Variant &signed_message, const Variant &public_key);
Variant sodium_crypto_sign_publickey(const Variant &key_pair);
Variant sodium_crypto_sign_secretkey(const Variant &key_pair);
Variant sodium_crypto_sign_publickey_from_secretkey(const Variant &secret_key);
Variant sodium_crypto_sign_seed_keypair(const Variant &seed);
Variant sodium_crypto_sign_verify_detached(const Variant &signature, const Variant &message, const Variant &public_key);
Variant sodium_crypto_stream(const Variant &length, const Variant &nonce, const Variant &key);
Variant sodium_crypto_stream_keygen();
Variant sodium_crypto_stream_xor(const Variant &message, const Variant &nonce, const Variant &key);
Variant sodium_crypto_stream_xchacha20(const Variant &length, const Variant &nonce, const Variant &key);
Variant sodium_crypto_stream_xchacha20_keygen();
Variant sodium_crypto_stream_xchacha20_xor(const Variant &message, const Variant &nonce, const Variant &key);
Variant sodium_crypto_stream_xchacha20_xor_ic(const Variant &message,
                                              const Variant &nonce,
                                              const Variant &counter,
                                              const Variant &key);
Variant sodium_add(const Reference &string1, const Variant &string2);
Variant sodium_compare(const Variant &string1, const Variant &string2);
Variant sodium_increment(const Reference &string);
Variant sodium_memcmp(const Variant &string1, const Variant &string2);
Variant sodium_memzero(const Reference &string);
Variant sodium_pad(const Variant &string, const Variant &block_size);
Variant sodium_unpad(const Variant &string, const Variant &block_size);
Variant sodium_bin2hex(const Variant &string);
Variant sodium_hex2bin(const Variant &string, const Variant &ignore = "");
Variant sodium_bin2base64(const Variant &string, const Variant &id);
Variant sodium_base642bin(const Variant &string, const Variant &id, const Variant &ignore = "");
Variant sodium_crypto_scalarmult_base(const Variant &secret_key);

}  // namespace php

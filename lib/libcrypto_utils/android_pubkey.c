#include <crypto_utils/android_pubkey.h>
#include <openssl/ossl_typ.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/bn.h>

// Better safe than sorry.
#if (ANDROID_PUBKEY_MODULUS_SIZE % 4) != 0
#error RSA modulus size must be multiple of the word size!
#endif

// Size of the RSA modulus in words.
#define ANDROID_PUBKEY_MODULUS_SIZE_WORDS (ANDROID_PUBKEY_MODULUS_SIZE / 4)

typedef struct RSAPublicKey {
    uint32_t modulus_size_words;
    uint32_t n0inv;
    uint8_t modulus[ANDROID_PUBKEY_MODULUS_SIZE];
    uint8_t rr[ANDROID_PUBKEY_MODULUS_SIZE];
    uint32_t exponent;
} RSAPublicKey;

static void reverse_bytes(uint8_t* buffer, size_t size) {
    for (size_t i = 0; i < (size + 1) / 2; ++i) {
        uint8_t tmp = buffer[i];
        buffer[i] = buffer[size - i - 1];
        buffer[size - i - 1] = tmp;
    }
}

bool android_pubkey_decode(const uint8_t* key_buffer, size_t size, RSA** key) {
    const RSAPublicKey* key_struct = (RSAPublicKey*)key_buffer;
    bool ret = false;
    uint8_t modulus_buffer[ANDROID_PUBKEY_MODULUS_SIZE];
    RSA* new_key = RSA_new();
    BIGNUM *n = NULL, *e = NULL;

    if (!new_key) {
        goto cleanup;
    }

    if (size < sizeof(RSAPublicKey) || key_struct->modulus_size_words != ANDROID_PUBKEY_MODULUS_SIZE_WORDS) {
        goto cleanup;
    }

    memcpy(modulus_buffer, key_struct->modulus, sizeof(modulus_buffer));
    reverse_bytes(modulus_buffer, sizeof(modulus_buffer));

    n = BN_bin2bn(modulus_buffer, ANDROID_PUBKEY_MODULUS_SIZE, NULL);
    e = BN_new();

    if (!n || !e || !BN_set_word(e, key_struct->exponent)) {
        goto cleanup;
    }

    if (!RSA_set0_key(new_key, n, e, NULL)) {
        goto cleanup;
    }

    *key = new_key;
    ret = true;

cleanup:
    if (!ret) {
        RSA_free(new_key);
        BN_free(n);
        BN_free(e);
    }
    return ret;
}

static bool android_pubkey_encode_bignum(const BIGNUM* num, uint8_t* buffer) {
    if (!BN_bn2binpad(num, buffer, ANDROID_PUBKEY_MODULUS_SIZE)) {
        return false;
    }

    reverse_bytes(buffer, ANDROID_PUBKEY_MODULUS_SIZE);
    return true;
}

bool android_pubkey_encode(const RSA* key, uint8_t* key_buffer, size_t size) {
    RSAPublicKey* key_struct = (RSAPublicKey*)key_buffer;
    bool ret = false;
    BN_CTX* ctx = BN_CTX_new();
    BIGNUM* r32 = BN_new();
    BIGNUM* n0inv = BN_new();
    BIGNUM* rr = BN_new();
    const BIGNUM *n, *e;

    if (!key) {
        goto cleanup;
    }

    RSA_get0_key(key, &n, &e, NULL);

    if (sizeof(RSAPublicKey) > size || RSA_size(key) != ANDROID_PUBKEY_MODULUS_SIZE) {
        goto cleanup;
    }

    key_struct->modulus_size_words = ANDROID_PUBKEY_MODULUS_SIZE_WORDS;

    if (!ctx || !r32 || !n0inv || !BN_set_bit(r32, 32) ||
        !BN_mod(n0inv, n, r32, ctx) ||
        !BN_mod_inverse(n0inv, n0inv, r32, ctx) ||
        !BN_sub(n0inv, r32, n0inv)) {
        goto cleanup;
    }
    key_struct->n0inv = (uint32_t)BN_get_word(n0inv);

    if (!android_pubkey_encode_bignum(n, key_struct->modulus)) {
        goto cleanup;
    }

    if (!ctx || !rr || !BN_set_bit(rr, ANDROID_PUBKEY_MODULUS_SIZE * 8) ||
        !BN_mod_sqr(rr, rr, n, ctx) ||
        !android_pubkey_encode_bignum(rr, key_struct->rr)) {
        goto cleanup;
    }

    key_struct->exponent = (uint32_t)BN_get_word(e);

    ret = true;

cleanup:
    BN_free(rr);
    BN_free(n0inv);
    BN_free(r32);
    BN_CTX_free(ctx);
    return ret;
}


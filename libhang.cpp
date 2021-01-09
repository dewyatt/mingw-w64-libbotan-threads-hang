#include "libhang.h"
#include <botan/ffi.h>
#include <cassert>

void LIBHANG_API dohang() {
  botan_rng_t rng = NULL;
  assert(botan_rng_init(&rng, NULL) == 0);

  botan_privkey_t rsa_key = NULL;
  assert(botan_privkey_create(&rsa_key, "RSA", "1024", rng) == 0);
  assert(botan_privkey_check_key(rsa_key, rng, 1) == 0);
  botan_privkey_destroy(rsa_key);
  botan_rng_destroy(rng);
}

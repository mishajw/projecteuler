#include "peutil.h"

void peutil::make_prime_sieve(std::vector<bool> &prime_sieve, int size) {
  prime_sieve.resize(size, true);

  for (int i = 2; i <= size / 2; i++) {
    if (!prime_sieve[i]) {
      continue;
    }

    for (int j = i * 2; j < size; j += i) {
      prime_sieve[j] = false;
    }
  }
}


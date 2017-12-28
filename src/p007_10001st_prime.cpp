#include <iostream>

#include "peutil.h"

int main() {
  std::vector<bool> prime_sieve;
  peutil::make_prime_sieve(prime_sieve, 1000000);

  int num_primes = 0;
  for (int i = 0; i < prime_sieve.size(); i++) {
    if (prime_sieve[i]) {
      num_primes++;

      if (num_primes == 10001) {
        printf("%d\n", i);
        break;
      }
    }
  }
}


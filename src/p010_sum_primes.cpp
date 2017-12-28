#include <iostream>
#include <inttypes.h>

#include "peutil.h"

int main() {
  std::vector<bool> prime_sieve;
  peutil::make_prime_sieve(prime_sieve, 2000000);

  uint64_t sum = 0;
  for (int i = 0; i < prime_sieve.size(); i++) {
    if (prime_sieve[i]) {
      sum += i;
    }
  }
  std::cout << sum << std::endl;
}


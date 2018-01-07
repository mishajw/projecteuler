#include <iostream>
#include <cmath>

#include "peutil.h"

int main() {
  std::vector<bool> primes;
  peutil::make_prime_sieve(primes, 1e6);

  int count = 0;
  for (int i = 0; i < primes.size(); i++) {
    if (!primes[i]) {
      continue;
    }

    int num_digits = peutil::get_num_digits(i);

    bool is_circular = true;
    for (int j = 1; j < num_digits; j++) {
      int upper = int(i / std::pow(10, j));
      int lower = i % int(std::pow(10, j));
      int shifted = upper + lower * std::pow(10, num_digits - j);
      if (!primes[shifted]) {
        is_circular = false;
      }
    }

    if (is_circular) {
      count++;
    }
  }

  printf("%d\n", count);
}


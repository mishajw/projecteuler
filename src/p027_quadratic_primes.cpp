#include <iostream>

#include "peutil.h"

constexpr int LIMIT = 150000, AB_LIMIT = 1000;

int main() {
  std::vector<bool> prime_sieve;
  peutil::make_prime_sieve(prime_sieve, LIMIT);

  int max_n = 0;
  int max_ab = 0;

  for (int a = -AB_LIMIT; a < AB_LIMIT; a++) {
    for (int b = -AB_LIMIT; b < AB_LIMIT; b++) {
      int n = 0;
      while (true) {
        int value = n * n + a * n + b;
        if (value < 0 || !prime_sieve[value]) {
          break;
        }
        n++;
      }
      
      if (n > max_n) {
        max_n = n;
        max_ab = a * b;
      }

    }
  }

  printf("%d\n", max_ab);
}


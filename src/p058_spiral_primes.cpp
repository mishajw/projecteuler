#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

#include "peutil.h"

int main() {
  std::vector<bool> primes;
  peutil::make_prime_sieve(primes, 1000000000);

  printf("eh\n");

  int primes_found = 0;
  int primes_checked = 0;
  int i = 1;
  while (true) {
    int first = std::pow(i, 2);
    int last = std::pow(i + 2, 2);

    if (last > primes.size()) {
      break;
    }

    int step = (last - first) / 4;
    int candidates[] = {first + step, first + (step * 2), first + (step * 3), last};

    for (int c : candidates) {
      primes_checked++;
      if (primes[c]) {
        primes_found++;
      }
    }
    
    double percentage_primes = double(primes_found) / double(primes_checked);
    printf("%d %f\n", i, percentage_primes);

    if (percentage_primes < 0.1) {
      break;
    }

    i += 2;
  }
}


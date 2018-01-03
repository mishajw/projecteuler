#include <iostream>
#include <vector>

#include "peutil.h"

static constexpr int FIND = 5000;

typedef std::vector<int>::iterator iter;

int f(int x, iter primes_begin, iter primes_end) {
  if (x == 0) {
    return 1;
  }

  int sum = 0;
  for (iter i = primes_begin; i != primes_end; i++) {
    if (*i > x) {
      break;
    }
    sum += f(x - *i, i, primes_end);
  }
  return sum;
}

int main() {
  std::vector<bool> prime_sieve;
  peutil::make_prime_sieve(prime_sieve, 1000000);

  std::vector<int> primes;
  for (int i = 0; i < prime_sieve.size(); i++) {
    if (prime_sieve[i]) {
      primes.push_back(i);
    }
  }

  int upper = 100;
  int lower = 1;

  while (lower + 1 < upper) {
    int middle = (lower + upper) / 2 + 1;
    int value = f(middle, primes.begin(), primes.end());

    if (value < FIND) {
      lower = middle;
    } else {
      upper = middle;
    }
  }

  printf("%d\n", upper);
}


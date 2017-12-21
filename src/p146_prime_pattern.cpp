// Find all numbers `n` for which...
// `n^2 + 1`, `n^2 + 3`, `n^2 + 7`, `n^2 + 9`, `n^2 + 13`, `n^2 + 27`
// ...are primes, where `n` lower than 150,000,000. Return the sum of this set.

#include <inttypes.h>
#include <iostream>

typedef uint32_t int_t;
typedef uint64_t bigint_t;
static const int_t INCRS[] = {1, 3, 7, 9, 13, 27};

bool is_prime(const bigint_t &x, const int_t &limit) {
  // Not needed, as we never test 2 or 3 for being prime
  // if (x == 2 || x == 3) {
  //   return true;
  // }

  if (!(x % 2) || !(x % 3)) {
    return false;
  }

  int_t i = 5;
  int_t w = 2;
  while (i < limit) {
    if (x % i == 0) {
      return false;
    }
    i += w;
    w = 6 - w;
  }

  return true;
}

bool check_number(const int_t &x) {
  if (!(x % 3) || !(x % 7) || !(x % 13)) {
    return false;
  }

  bigint_t squared = bigint_t(x) * bigint_t(x);
  for (const auto &i : INCRS) {
    if (!is_prime(squared + i, x + 17)) {
      return false;
    }
  }

  return true;
}

int main() {
  int_t total = 0;
  for (int_t x = 10; x <= 300000; x += 2) {
    if (check_number(x)) {
      total += x;
      std::cout << "Found match: " << x << std::endl;
    }

    if (x % 10000 == 0) {
      std::cout << "Checking " << x << std::endl;
    }
  }

  std::cout << total << std::endl;
}


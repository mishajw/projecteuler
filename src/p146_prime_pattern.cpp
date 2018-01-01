#include <iostream>
#include <inttypes.h>
#include <vector>
#include <cmath>

typedef uint64_t int_t;
typedef uint64_t bigint_t;

static const int_t LIMIT = 150000000;
static const int_t INCRS[] = {1, 3, 7, 9, 13, 27};
static const int_t NON_PRIME_INCRS[] = {5, 11, 15, 17, 19, 21, 23, 25};

bool check_are_primes(const std::vector<bigint_t> &xs, const int_t &limit) {
  for (const auto &x : xs) {
    if (!(x % 2) || !(x % 3)) {
      return false;
    }
  }

  int_t i = 5;
  int_t w = 2;
  while (i <= limit) {
    for (const auto &x : xs) {
      if (i * i <= x && x % i == 0) {
        return false;
      }
    }

    i += w;
    w = 6 - w;
  }

  return true;
}

bool is_prime(const bigint_t &x, const int_t &limit) {
  if (!(x % 2) || !(x % 3)) {
    return false;
  }

  int_t i = 5;
  int_t w = 2;
  while (i <= limit) {
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
  bigint_t limit = std::sqrt(squared + 27);

  std::vector<bigint_t> possible_primes;
  for (const auto &i : INCRS) {
    possible_primes.push_back(squared + i);
  }
  bool are_primes = check_are_primes(possible_primes, limit);
  
  if (are_primes) {
    for (const auto &i : NON_PRIME_INCRS) {
      if (is_prime(squared + i, limit)) {
        return false;
      }
    }

    return true;
  } else {
    return false;
  }
}

int main() {
  int_t total = 0;
  for (int_t x = 10; x <= LIMIT; x += 2) {
    if (check_number(x)) {
      total += x;
    }
  }

  std::cout << total << std::endl;
}


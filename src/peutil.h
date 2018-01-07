#ifndef PEUTIL_H_
#define PEUTIL_H_

#include <vector>
#include <cmath>

namespace peutil {

template<typename T=int>
void make_prime_sieve(std::vector<bool> &prime_sieve, T size) {
  prime_sieve.resize(size, true);
  prime_sieve[0] = false;
  prime_sieve[1] = false;

  for (int i = 2; i <= size / 2; i++) {
    if (!prime_sieve[i]) {
      continue;
    }

    for (int j = i * 2; j < size; j += i) {
      prime_sieve[j] = false;
    }
  }
}

template<int base=10>
int get_num_digits(int i) {
  if (i == 0) {
    return 1;
  }

  return std::floor(std::log(i) / std::log(base) + 1);
}

template<int base=10>
int get_digit(int i, int n) {
  return i % int(std::pow(base, n + 1)) / std::pow(base, n);
}

template<typename T>
T get_highest_common_factor(const T a, const T b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  const T quotient = a / b;
  const T remainder = a % b;

  return get_highest_common_factor<T>(b, remainder);
}

template<typename T=int>
void get_prime_factors(std::vector<T> &prime_factors, T n) {
  for (int i = 2; n > 1;) {
    if (n % i == 0) {
      prime_factors.push_back(i);
      n /= i;
    } else {
      i++;
    }
  }
}

}

#endif


#ifndef PEUTIL_H_
#define PEUTIL_H_

#include <vector>

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

int get_num_digits(int i);

}

#endif


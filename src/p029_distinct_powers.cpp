#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#include "peutil.h"

constexpr int LIMIT = 101;

struct Power {
  int a;
  int b;

  Power(int a, int b) : a(a), b(b) {}

  Power pow(int n) const {
    return Power(a, b * n);
  }
};

int main() {
  std::vector<std::vector<int>> all_prime_factors(LIMIT);

  for (int i = 1; i < LIMIT; i++) {
    peutil::get_prime_factors(all_prime_factors[i], i);
  }

  std::set<std::vector<int>> power_prime_factors;

  for (int a = 2; a < LIMIT; a++) {
    for (int b = 2; b < LIMIT; b++) {
      std::vector<int> prime_factors;
      prime_factors.reserve(all_prime_factors[a].size() * b);
      for (int i = 0; i < b; i++) {
        prime_factors.insert(
            prime_factors.end(),
            all_prime_factors[a].begin(),
            all_prime_factors[a].end());
      }
      std::sort(prime_factors.begin(), prime_factors.end());

      power_prime_factors.insert(prime_factors);
    }
  }

  printf("%ld\n", power_prime_factors.size());
}


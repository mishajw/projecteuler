#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <inttypes.h>

#include "peutil.h"

typedef uint64_t int_t;

static const int_t PRIME_LIMIT = 1e9, CHECK_LIMIT = 1e4;

bool are_concatable(int_t x, int_t y, const std::vector<bool> &primes) {
  int x_digits = peutil::get_num_digits(x);
  int y_digits = peutil::get_num_digits(y);

  int_t xy = x * std::pow(10, y_digits) + y;
  int_t yx = y * std::pow(10, x_digits) + x;

  if (xy > PRIME_LIMIT || yx > PRIME_LIMIT) {
    printf("Limit passed with %ld or %ld\n", xy, yx);
    return false;
  }

  return primes[xy] && primes[yx];
}

void get_perms(std::vector<int_t> xs, int_t n, std::vector<std::vector<int_t>> &perms) {
  assert(n >= 1);

  if (n == 1) {
    for (int_t x : xs) {
      perms.push_back(std::vector<int_t>{x});
    }
    return;
  }

  for (int i = 0; i < xs.size(); i++) {
    std::vector<int_t> child_xs(xs);
    child_xs.erase(child_xs.begin() + i);

    std::vector<std::vector<int_t>> child_perms;
    get_perms(child_xs, n - 1, child_perms);

    for (auto &p : child_perms) {
      p.push_back(xs[i]);
      perms.push_back(p);
    }
  }
}

bool check_connected(const std::vector<std::vector<int_t>> &concatable, const std::vector<int_t> &xs) {
  for (int i = 0; i < xs.size(); i++) {
    std::vector<int_t> i_connected = concatable[xs[i]];
    for (int j = i + 1; j < xs.size(); j++) {
      if (std::find(
            i_connected.begin(),
            i_connected.end(),
            xs[j]) == i_connected.end()) {

        return false;
      }
    }
  }

  return true;
}

bool is_connected(
    const std::vector<std::vector<int_t>> &concatable,
    int_t x,
    int n,
    std::vector<int_t> &successful_perm) {

  std::vector<std::vector<int_t>> perms;
  get_perms(concatable[x], n, perms);

  bool found = false;
  for (const auto &p : perms) {
    if (check_connected(concatable, p)) {
      successful_perm.insert(successful_perm.begin(), p.begin(), p.end());
      return true;
    }
  }

  return false;
}

int main() {
  std::vector<bool> primes;
  peutil::make_prime_sieve(primes, PRIME_LIMIT);
  printf("Finished making primes\n");

  std::vector<std::vector<int_t>> concatable;
  concatable.resize(CHECK_LIMIT);

  for (int_t i = 0; i < CHECK_LIMIT; i++) {
    if (i % 1000 == 0) {
      printf("Checking %ld\n", i);
    }

    if (!primes[i]) {
      continue;
    }

    for (int_t j = 0; j < i; j++) {
      if (!primes[j]) {
        continue;
      }

      if (are_concatable(i, j, primes)) {
        concatable[i].push_back(j);
        concatable[j].push_back(i);
      }
    }

    std::vector<int_t> successful_perm;
    if (is_connected(concatable, i, 4, successful_perm)) {
      int_t sum = i;
      std::cout << "Found " << i << " with ";
      for (const auto i : successful_perm) {
        sum += i;
        std::cout << i << " ";
      }
      std::cout << "summing to " << sum << std::endl;

      return 0;
    }
  }

  printf("Done\n");
}


#include <iostream>
#include <inttypes.h>
#include <functional>
#include <cmath>
#include <bitset>

const static int LIMIT = 1000000;

void get_prime_sieve(int size, std::vector<bool> &prime_sieve) {
  prime_sieve.resize(size, true);

  for (int i = 2; i * i < size; i++) {
    if (!prime_sieve[i]) {
      continue;
    }

    for (int j = i * 2; j < size; j += i) {
      prime_sieve[j] = false;
    }
  }
}

int get_digit(int x, int n) {
  return std::floor((x % int(std::pow(10, n + 1))) / std::pow(10, n));
}

int get_num_digits(int x) {
  return std::floor(std::log(x) / std::log(10)) + 1;
}

int remove_mask_value(int x, int mask) {
  int num_digits = get_num_digits(x);
  for (int i = 0; i < num_digits; i++) {
    if ((mask >> i) & 1) {
      x -= get_digit(x, i) * std::pow(10, i);
    }
  }
  return x;
}

int get_increment(int mask) {
  int x = 0;
  for (int i = 0; i < 32; i++) {
    if ((mask >> i) & 1) {
      x += std::pow(10, i);
    }
  }
  return x;
}

int check_with_mask(int x, int mask, const std::vector<bool> &prime_sieve) {
  int without_mask = remove_mask_value(x, mask);
  int prime_count = 0;
  int increment = get_increment(mask);
  int num_digits = get_num_digits(x);
  int first_prime = 0;

  for (int unit = 0; unit <= 9; unit++) {
    int possible_prime = without_mask + (increment * unit);
    if (possible_prime > std::pow(10, num_digits - 1) && prime_sieve[possible_prime]) {
      if (first_prime == 0) {
        first_prime = possible_prime;
      }

      prime_count++;
    }
  }

  if (prime_count >= 8) {
    return first_prime;
  } else {
    return 0;
  }
}

bool check_number(int x, const std::vector<bool> &prime_sieve) {
  int num_digits = get_num_digits(x);

  for (int mask = 1; mask < 1 << num_digits; mask++) {
    int found = check_with_mask(x, mask, prime_sieve);
    if (found) {
      printf("Found %d using %d\n", found, x);
      std::cout << "Mask: "<< std::bitset<32>(mask) << std::endl;
    }
  }

  return false;
}

int main() {
  std::vector<bool> prime_sieve;
  get_prime_sieve(LIMIT, prime_sieve);

  for (int i = 2; i < LIMIT; i++) {
    if (prime_sieve[i]) {
      check_number(i, prime_sieve);
    }
  }
}


#include <iostream>
#include <cmath>

#include "peutil.h"

int factorial(int x) {
  if (x <= 1) {
    return 1;
  }

  return x * factorial(x - 1);
}

int sum_range(int lower, int upper, const std::vector<int> &facs) {
  int total = 0;
  for (int i = lower; i < upper; i++) {
    int digit_total = 0;
    int num_digits = peutil::get_num_digits(i);
    for (int j = 0; j < num_digits; j++) {
      digit_total += facs[peutil::get_digit(i, j)];
    }
    if (digit_total == i) {
      total += i;
    }
  }
  return total;
}

int main() {
  std::vector<int> facs(10);
  for (int i = 0; i < 10; i++) {
    facs[i] = factorial(i);
  }

  int total = 0;
  for (int i = 2;; i++) {
    int lower = std::pow(10, (i - 1)) - 1;
    int upper = std::min(facs[9] * i, int(std::pow(10, i)));

    if (lower > upper) {
      break;
    }
    
    total += sum_range(lower, upper, facs);
  }
  printf("%d\n", total);
}


#include <cmath>

#include "peutil.h"

int peutil::get_num_digits(int i) {
  if (i == 0) {
    return 1;
  }

  return std::floor(std::log10(i) + 1);
}

int peutil::get_digit(int i, int n) {
  return i % int(std::pow(10, n + 1)) / std::pow(10, n);
}


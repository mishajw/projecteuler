#include <cmath>

#include "peutil.h"

int peutil::get_num_digits(int i) {
  if (i == 0) {
    return 1;
  }

  return std::floor(std::log10(i) + 1);
}


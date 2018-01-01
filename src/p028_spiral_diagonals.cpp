#include <iostream>
#include <inttypes.h>
#include <cmath>

#include "peutil.h"

typedef uint64_t int_t;

constexpr int LIMIT = 500;

int main() {
  int_t total = 1;
  for (int_t i = 0; i < LIMIT; i++) {
    int_t index = i * 2 + 1;
    int_t first = std::pow(index, 2);
    int_t last = std::pow(index + 2, 2);
    printf("%ld %ld\n", first, last);

    int_t step = (last - first) / 4;
    total += first + step + first + (step * 2) + first + (step * 3) + last;
    printf("%ld\n", total);
  }

  printf("%ld\n", total);
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <inttypes.h>

#include "peutil.h"

typedef uint64_t int_t;

static const int_t LIMIT = 1e6;

struct Orderable {
  int_t x;
  std::string x_sorted;

  Orderable(const int_t x) : x(x), x_sorted(sort_int(x)) {}

  static std::string sort_int(const int_t x) {
    std::string x_str = std::to_string(x);
    std::sort(x_str.begin(), x_str.end());
    return x_str;
  }
};

int main() {
  std::vector<Orderable> numbers;
  for (int_t i = 0; i < LIMIT; i++) {
    numbers.emplace_back(i * i * i);
  }

  std::sort(
      numbers.begin(),
      numbers.end(),
      [](const Orderable &a, const Orderable &b) {
        return a.x_sorted < b.x_sorted;
      });

  std::string prev_x_sorted;
  int consecutive = 0;
  int_t min_of_consecutive = -1;
  int_t min_of_all = -1;
  for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
    if (iter->x_sorted == prev_x_sorted) {
      consecutive++;

      if (min_of_consecutive == -1 || min_of_consecutive > iter->x) {
        min_of_consecutive = iter->x;
      }

      if (consecutive == 4) {
        if (min_of_all == -1 || min_of_all > min_of_consecutive) {
          min_of_all = min_of_consecutive;
        }
      }
    } else {
      prev_x_sorted = iter->x_sorted;
      consecutive = 0;
      min_of_consecutive = -1;
    }
  }

  printf("Result: %ld\n", min_of_all);
}


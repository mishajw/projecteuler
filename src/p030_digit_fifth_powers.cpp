#include <iostream>
#include <cmath>

#include "peutil.h"

constexpr int LIMIT = 1000000;

int main() {
  std::vector<int> fifth_powers(10);
  for (int i = 0; i < 10; i++) {
    fifth_powers[i] = std::pow(i, 5);
  }

  int total_sum = 0;
  for (int i = 2; i < LIMIT; i++) {
    int num_digits = peutil::get_num_digits(i);

    int sum = 0;
    for (int j = 0; j < num_digits; j++) {
      sum += fifth_powers[peutil::get_digit(i, j)];
    }

    if (sum == i) {
      total_sum += i;
      printf("%d\n", i);
    }
  }

  printf("%d\n", total_sum);
}


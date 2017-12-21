#include <iostream>
#include <cmath>
#include <inttypes.h>
#include <vector>

int get_digit(int x, int n) {
  return std::floor((x % int(std::pow(10, n + 1))) / std::pow(10, n));
}

bool have_same_digits(int x, int y) {
  std::vector<int> x_digits(10, 0), y_digits(10, 0);

  for (int i = 0; i < 16; i++) {
    int x_digit = get_digit(x, i);
    int y_digit = get_digit(y, i);

    x_digits[x_digit]++;
    y_digits[y_digit]++;
  }

  for (int i = 0; i < 10; i++) {
    if (x_digits[i] != y_digits[i]) {
      return false;
    }
  }

  return true;
}

bool check(int x) {
  for (int i = 2; i <= 6; i++) {
    if (!have_same_digits(x, x * i)) {
      return false;
    }
  }

  return true;
}

int main() {
  int i = 1;
  while (true) {
    if (check(i)) {
      printf("Found %d\n", i);
      return 1;
    }

    i++;
  }
}


#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

#include "peutil.h"

void update_found_digits(int x, int num_digits, std::vector<bool> &found_digits) {
  for (int i = 0; i < num_digits; i++) {
    int digit = peutil::get_digit(x, i);
    if (digit == 0) {
      continue;
    }
    found_digits[digit - 1] = true;
  }
}

int main() {
  std::set<int> found;

  for (int xy_total = 2;; xy_total++) {
    bool found_correct_length = false;
    for (int xy_split = 1; xy_split < xy_total; xy_split++) {
      int x = xy_total - xy_split;
      int y = xy_total - x;
      int xy = x * y;

      int x_digits = peutil::get_num_digits(x);
      int y_digits = peutil::get_num_digits(y);
      int xy_digits = peutil::get_num_digits(xy);
      int total_digits = x_digits + y_digits + xy_digits;

      if (total_digits <= 9) {
        found_correct_length = true;
      }
      if (total_digits != 9) {
        continue;
      } 

      std::vector<bool> found_digits(9, false);
      update_found_digits(x, x_digits, found_digits);
      update_found_digits(y, y_digits, found_digits);
      update_found_digits(xy, xy_digits, found_digits);
      if (std::find(found_digits.begin(), found_digits.end(), false) == found_digits.end()) {
        found.insert(xy);
      }
    }

    if (!found_correct_length) {
      break;
    }
  }

  int total = 0;
  for (const auto &x: found) {
    total += x;
  }
  printf("%d\n", total);
}


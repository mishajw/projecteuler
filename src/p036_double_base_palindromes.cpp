#include <iostream>

#include "peutil.h"

template<int base>
bool is_palindrome(int x) {
  int num_digits = peutil::get_num_digits<base>(x);
  for (int i = 0; i < num_digits / 2 + 1; i++) {
    if (peutil::get_digit<base>(x, i) != peutil::get_digit<base>(x, num_digits - i - 1)) {
      return false;
    }
  }
  return true;
}

int main() {
  int total = 0;
  for (int i = 0; i < 1e6; i++) {
    if (is_palindrome<2>(i) && is_palindrome<10>(i)) {
      total += i;
    }
  }
  printf("%d\n", total);
}


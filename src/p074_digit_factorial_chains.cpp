#include <iostream>
#include <vector>
#include <algorithm>

#include "peutil.h"

static constexpr int LIMIT = 1e6;

int fac(int x) {
  if (x <= 1) {
    return 1;
  }

  return x * fac(x - 1);
}

int get_loop_length(int x, const std::vector<int> &factorials, std::vector<int> &history) {
  int num_digits = peutil::get_num_digits(x);
  
  int sum = 0;
  for (int i = 0; i < num_digits; i++) {
    int digit = peutil::get_digit(x, i);
    sum += factorials[digit];
  }

  auto find_iter = std::find(history.begin(), history.end(), sum);
  if (find_iter != history.end()) {
    return history.size();
  } else {
    history.push_back(sum);
    return get_loop_length(sum, factorials, history);
  }
}

int main() {
  std::vector<int> factorials(10);
  for (int i = 0; i < 10; i++) {
    factorials[i] = fac(i);
  }

  int count = 0;
  for (int i = 0; i < LIMIT; i++) {
    std::vector<int> history{i};
    if (get_loop_length(i, factorials, history) == 60) {
      count++;
    }
  }
  printf("%d\n", count);
}


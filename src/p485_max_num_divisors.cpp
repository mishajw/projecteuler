#include <iostream>
#include <vector>

static constexpr int U = 1e8, K = 10;

void create_divisors(int limit, std::vector<std::vector<int>> &divisors) {
  divisors.resize(limit);
  printf("Resized\n");
  for (int i = 2; i < limit / 2 + 1; i++) {
    for (int j = i; j < limit; j += i) {
      divisors[j].push_back(i);
    }
  }
}

int main() {
  std::vector<std::vector<int>> divisors;
  create_divisors(U + K, divisors);
}


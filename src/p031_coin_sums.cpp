#include <iostream>
#include <vector>

int num_ways(int pence, int current_coin, std::vector<int> coins) {
  if (pence == 0) {
    return 1;
  }

  if (pence < current_coin && coins.empty()) {
    return 0;
  }

  int total = 0;

  if (pence >= current_coin) {
    total += num_ways(pence - current_coin, current_coin, coins);
  }

  if (!coins.empty()) {
    int next_coin = coins[0];
    std::vector<int> rest_coins(coins.begin() + 1, coins.end());

    total += num_ways(pence, next_coin, rest_coins);
  }

  return total;
}

int main() {
  printf("%d\n", num_ways(200, 200, {100, 50, 20, 10, 5, 2, 1}));
}


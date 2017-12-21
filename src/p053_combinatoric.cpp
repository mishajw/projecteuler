#include <iostream>
#include <vector>

typedef __uint128_t int_t;

int find(const std::vector<int_t> &previous_layer, int layers_left) {
  if (layers_left == 0) {
    return 0;
  }

  std::vector<int_t> current_layer(previous_layer.size() + 1);

  int count = 0;
  for (int i = 0; i < current_layer.size(); i++) {
    if (i == 0) {
      current_layer[i] = previous_layer[i];
    } else if (i == current_layer.size() - 1) {
      current_layer[i] = previous_layer[i - 1];
    } else {
      current_layer[i] = previous_layer[i - 1] + previous_layer[i];
    }

    if (current_layer[i] > 1000000) {
      count++;
    }
  }

  return count + find(current_layer, layers_left - 1);
}

int main() {
  printf("Found %d\n", find({1}, 100));
}


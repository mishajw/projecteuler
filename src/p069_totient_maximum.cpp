#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

static constexpr int LIMIT = 100000;

void create_indices(int x, const std::vector<int> &divisors, std::vector<int> &indices) {
  // std::vector<int> indices_vector;
  // for (const auto &d : divisors) {
  //   for (int i = x + d; i < LIMIT; i += d) {
  //     indices.push_back(i);
  //   }
  // }
  // indices.insert(indices_vector.begin(), indices_vector.end());
  for (int i = 0; i < 1000000; i++) {
    indices.push_back(i);
  }
}

int main() {
  std::vector<std::vector<bool>> test(LIMIT, std::vector<bool>(LIMIT));

  printf("1\n");
  std::vector<std::vector<int>> divisors(LIMIT);
  for (int i = 2; i < LIMIT; i++) {
    for (int j = i; j < LIMIT; j += i) {
      divisors[j].push_back(i);
    }
  }

  printf("3\n");
  std::vector<int> num_totients(LIMIT);
  std::vector<bool> current_totients(LIMIT, true);
  for (int i = 0; i < LIMIT; i++) {
    if (i%1000==0)
    printf("i: %d, %ld\n", i, divisors[i].size());
    std::fill(current_totients.begin(), current_totients.end(), true);
    
    for (const auto &d : divisors[i]) {
      for (int j = d; j < i; j += d) {
        current_totients[j] = false;
      }
    }

    for (const auto &ct : current_totients) {
      if (ct) {
        num_totients[i]++;
      }
    }
  }

  printf("4\n");
  double max_ratio = 0;
  int max_i = 0;
  for (int i = 0; i < LIMIT; i++) {
    if (num_totients[i] == 0) {
      continue;
    }

    double ratio = double(i) / double(num_totients[i]);
    // printf("%d: %f\n", i, ratio);
    // printf("%d: %d\n", i, num_totients[i]);
    if (max_ratio < ratio) {
      max_ratio = ratio;
      max_i = i;
    }
  }
  printf("%d\n", max_i);
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cassert>
#include <functional>

static constexpr int LIMIT = 1000000;
static constexpr int PYTH_LIMIT = 3000;

struct Cube {
  int x, y, z;
  Cube(int x, int y, int z) {
    if (x < y) {
      int tmp = x; x = y; y = tmp;
    }
    if (y < z) {
      int tmp = y; y = z; z = tmp;
    }
    if (x < y) {
      int tmp = x; x = y; y = tmp;
    }
    this->x = x; this->y = y; this->z = z;
  }

  bool operator<(const Cube &other) const {
    if (this->x != other.x) {
      return this->x < other.x;
    } else if (this->y != other.y) {
      return this->y < other.y;
    } else {
      return this->z < other.z;
    }
  }

  bool operator==(const Cube &other) const {
    return this->x == other.x && this->y == other.y && this->z == other.z;
  }

  int max() const {
    return std::max(x, std::max(y, z));
  }
};

void create_all_pyth(std::function<void(const int&, const int&, const int&)> callback) {
  for (int m = 1; m < PYTH_LIMIT; m++) {
    for (int n = 1; n < m; n++) {
      int pyth_a = m * m - n * n;
      int pyth_b = 2 * m * n;
      int pyth_c = m * m + n * n;
      int max_pyth = std::max(pyth_a, pyth_b);

      for (int k = 1; k * max_pyth < PYTH_LIMIT * 2; k++) {
        callback(pyth_a * k, pyth_b * k, pyth_c * k);
      }
    }
  }
}

void get_possible_cubes(
    int pyth_a,
    int pyth_b,
    std::function<void(const Cube&)> callback) {

  if (pyth_a < pyth_b) {
    int tmp = pyth_a;
    pyth_a = pyth_b;
    pyth_b = tmp;
  }

  for (int c = pyth_a - pyth_b; c <= pyth_b; c++) {
    callback(Cube(c, pyth_a - c, pyth_b));
  }

  for (int c = 1; c < pyth_b; c++) {
    callback(Cube(c, pyth_b - c, pyth_a));
  }
}

int get_distance(int a, int b) {
  return a * a + b * b;
}

int main() {
  std::set<Cube> all_cubes;

  create_all_pyth(
    [&](auto a, auto b, auto c) {
      get_possible_cubes(a, b, [&](const auto &c) {
        all_cubes.insert(c);
      });
    });

  std::vector<Cube> all_cubes_vector(all_cubes.begin(), all_cubes.end());
  std::sort(
      all_cubes_vector.begin(),
      all_cubes_vector.end(),
      [](const Cube &a, const Cube &b) {
        return a.max() < b.max();
      });

  printf("%d\n", all_cubes_vector[LIMIT].max());
}


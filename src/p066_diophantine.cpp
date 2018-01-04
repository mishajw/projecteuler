#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include <cassert>
#include <set>

// using namespace boost::multiprecision;
// typedef number<cpp_int_backend<64, 128, unsigned_magnitude, unchecked, void>> int_t;

using namespace std;
typedef uint64_t int_t;

static const int LIMIT = 1000;
static const int_t POW_LIMIT = pow(2, 32);

int_t integer_sqrt(int_t x) {
  int_t x_sqrt = sqrt(x);

  while (true) {
    if (x_sqrt * x_sqrt > x) {
      x_sqrt--;
    } else if ((x_sqrt + 1) * (x_sqrt + 1) <= x) {
      x_sqrt++;
    } else {
      break;
    }

    printf("%ld, %ld\n", x, x_sqrt);
  }

  return x_sqrt;
}

bool check_y(const int_t d, const int_t y, const std::vector<int_t> square_numbers, int_t &x) {
  if (y > POW_LIMIT) {
    std::cout << "Breaking pow limit with y: " << y << std::endl;
  }

  int_t lhs = d * (y * y) + 1;
  x = integer_sqrt(lhs);

  if (!(x * x <= lhs && (x + 1) * (x + 1) > lhs)) {
    std::cout << x << ", " << lhs << std::endl;
    assert(false);
  }

  if (lhs < y) {
    std::cout << "Breaking pow limit with lhs: " << lhs << std::endl;
  }

  if (x > POW_LIMIT) {
    std::cout << "Breaking pow limit with x: " << x << std::endl;
  }

  return x > 0 && x * x == lhs;
}

bool check(const int_t d, const int_t x) {
  int_t xpow = pow(x, 2);
  if ((xpow - 1) % d != 0) {
    return false;
  }

  int_t lhs = (xpow - 1) / d;
  int_t y = sqrt(lhs);

  return y > 0 && pow(y, 2) == lhs;
}

int main() {
  std::vector<int> valid;
  for (int i = 0; i <= LIMIT; i++) {
    if (pow(floor(sqrt(i)), 2) == i) {
      continue;
    }
    valid.push_back(i);
  }

  std::vector<int_t> square_numbers;
  // for (int_t i = 0; i < POW_LIMIT; i++) {
  //   square_numbers.push_back(i * i);
  //
  //   if (i % 1000000 == 0) {
  //     printf("%f\n", double(i) / double(POW_LIMIT));
  //   }
  // }

  int_t max_x = 0;
  int_t max_d = 0;

  int_t y = 1;
  while (true) {
    for (auto iter = valid.begin(); iter != valid.end();) {
      int_t d = *iter;
      int_t x;
      if (check_y(d, y, square_numbers, x)) {
        // cout << "For d=" << d << ": " << x << ", " << y << std::endl;
        assert(x * x - d * y * y == 1);

        if (x > max_x) {
          max_x = x;
          max_d = d;
        }

        iter = valid.erase(iter);
      } else {
        ++iter;
      }
    }

    size_t num_valid = valid.size();

    if (y % 100000 == 0) {
      std::cout << "Num valid at " << y << ": " << num_valid << std::endl;
      for (const auto &x : valid) {
        std::cout << x << ", ";
      }
      std::cout << std::endl;
    }

    if (num_valid <= 1) {
      break;
    }

    y++;
  }

  std::cout << "Max d, x: " << max_d << ", " << max_x << std::endl;
  for (const auto &d : valid) {
    printf("Found: %d\n", d);
  }
}

// void find_solution(const int_t d, int_t &min_x, int_t &min_y) {
//   // for (int_t x = 1; x < LOOP_LIMIT; x++) {
//   //   int_t xpow = std::pow(x, 2);
//   //   if ((xpow - 1) % d != 0) {
//   //     continue;
//   //   }
//   //
//   //   int_t lhs = (xpow - 1) / d;
//   //   int_t y = std::sqrt(lhs);
//   //   // printf("d %d; xpow %ld; lhs %ld\n", d, xpow, lhs);
//   //
//   //   if (y > 0 && std::pow(y, 2) == lhs) {
//   //     // printf("xpow %ld; lhs %ld\n", xpow, lhs);
//   //     min_x = x;
//   //     min_y = y;
//   //     return;
//   //   }
//   // }
//
//   for (int_t y = 1;; y++) {
//     int_t lhs = d * (y * y) + 1;
//     int_t x = sqrt(lhs);
//
//     if (x > 0 && pow(x, 2) == lhs) {
//       // printf("xpow %ld; lhs %ld\n", xpow, lhs);
//       // printf("y %f; x %f; lhs %f\n", y, x, lhs);
//       min_x = x;
//       min_y = y;
//       return;
//     }
//   }
//
//   printf("Reached loop limit!\n");
// }
//
// int main() {
//   int_t max_x = 0;
//   int_t max_d = 0;
//   for (int_t d = 2; d < LIMIT; d++) {
//     if (pow(sqrt(d), 2) == d) {
//       continue;
//     }
//
//     int_t x = 0, y = 0;
//     find_solution(d, x, y);
//
//     std::cout << d << ": " << x << ", " << y << std::endl;
//
//     if (x > max_x) {
//       max_x = x;
//       max_d = d;
//     }
//   }
//
//   // printf("Found: %ld\n", max_d);
// }


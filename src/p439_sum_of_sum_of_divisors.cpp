#include <iostream>
#include <functional>
#include <inttypes.h>
#include <vector>
#include <set>
#include <cmath>
#include <fstream>

typedef uint64_t int_t;

const static int_t LIMIT = 3;

int_t count_divisor_occurances(int_t x) {
  int_t
    diagonal_count = 0,
    side_count = 0,
    normal_count = 0;

  int_t half_x = std::ceil(float(x) / 2);
  printf("Half %ld: %ld\n", x, half_x);
  for (int_t x = 1; x <= half_x; x++) {
    printf("%ld\n", x);
    for (int_t y = x; y <= half_x; y++) {
      // printf("%ld, %ld\n", x, y);
      
      if ((x * y) % x != 0) {
        continue;
      }

      if (x == y) {
        diagonal_count++;
      } else if (y == half_x) {
        side_count++;
      } else {
        normal_count++;
      }
    }
  }

  int_t square_total = normal_count * 8 + diagonal_count * 4 + side_count * 4;
  // int_t num_squares = LIMIT / x * LIMIT / x;

  // std::cout << square_total << std::endl;
  // std::cout << num_squares << std::endl;

  // return square_total * num_squares;
  return square_total;
}

int main() {
  // for (int_t i = 1; i <= LIMIT; i++) {
  //   int_t divisor_occurances = count_divisor_occurances(i);
  //   std::cout << i << ": " << divisor_occurances << std::endl;
  // }
  count_divisor_occurances(1e11);
}

// void product(std::function<void(int_t, int_t)> callback) {
//   for (int_t i = 0; i < LIMIT; i++) {
//     for (int_t j = 0; j < LIMIT; j++) {
//       callback(i, j);
//     }
//   }
// }
//
// int main() {
//   std::cout << "Creating " << LIMIT << " factors" << std::endl;
//
//   std::vector<std::set<int_t>> divisors(LIMIT);
//   for (int_t i = 1; i < LIMIT; i++) {
//     divisors[i].insert(i);
//
//     for (int_t j = i + i; j < LIMIT; j += i) {
//       divisors[j].insert(divisors[i].begin(), divisors[i].end());
//     }
//   }
//   std::cout << "Done" << std::endl;
//
//   std::ofstream file;
//   file.open("p439_test.csv");
//
//   for (int_t i = 0; i < LIMIT; i++) {
//     for (int_t j = 0; j < LIMIT; j++) {
//       std::set<int_t> current_divisors;
//       for (const int_t &i_div : divisors[i]) {
//         for (const int_t &j_div : divisors[j]) {
//           current_divisors.insert(i_div * j_div);
//         }
//       }
//
//       // std::cout << "Divisors for " << i * j << ": ";
//       // for (const int_t &i : current_divisors) {
//       //   std::cout << i << " ";
//       // }
//       // std::cout << std::endl;
//       
//       if (current_divisors.find(20) != current_divisors.end()) {
//         file << "x ";
//       } else {
//         file << "  ";
//       }
//     }
//     file << "\n";
//   }
//
//   file.close();
// }
//

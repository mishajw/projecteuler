#include <iostream>

#include "peutil.h"

int main() {
  int n_product = 1;
  int d_product = 1;
  for (int d1 = 1; d1 < 10; d1++) {
    int n2 = d1;

    for (int d2 = 0; d2 < 10; d2++) {
      for (int n1 = 1; n1 < 10; n1++) {
        int n = n1 * 10 + n2;
        int d = d1 * 10 + d2;

        if (d <= n) {
          continue;
        }

        if (float(d) / d2 == float(n) / n1) {
          printf("%d / %d\n", n, d);
          n_product *= n;
          d_product *= d;
        }
      }
    }
  }

  int factor = peutil::get_highest_common_factor(n_product, d_product);
  printf("%d\n", d_product / factor);
}


#include <iostream>

double f(double q) {
  double product = 1;
  for (int x = 1; x <= 50; x++) {
    product *= 1.0 - (double(x) / q);
  }
  return product;
}

int main() {
  printf("%f\n", f(50));
}


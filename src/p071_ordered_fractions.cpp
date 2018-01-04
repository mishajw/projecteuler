#include <iostream>

static constexpr int LIMIT = 1e6;
static constexpr double FRACTION = 3.0 / 7.0;

int main() {
  float min_diff = -1;
  int min_numerator = 0;

  for (int i = 0; i < LIMIT; i++) {
    int numerator = double(i) * FRACTION;
    double diff = FRACTION - float(numerator) / i;
    printf("%d / %d\n", numerator, i);
    printf("%f\n", diff);
      
    if (min_diff == -1 || min_diff > diff) {
      min_diff = diff;
      min_numerator = numerator;
    }
  }

  printf("%d\n", min_numerator);
}


#include <iostream>
#include <cmath>

int main() {
  int sum = 0;
  int i = 1;
  int lower;
  do {
    lower = std::ceil(std::pow(10, float(i - 1) / float(i)));
    sum += 10 - lower;
    i++;
  } while (lower != 10);
  printf("Result: %d\n", sum);
}


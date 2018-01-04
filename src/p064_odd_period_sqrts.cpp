#include <iostream>
#include <cmath>
#include <vector>

#include "peutil.h"

static const int LIMIT = 10000, LOOP_LIMIT = 10000;

struct Equation {
  /**
   * Represents c(sqrt(x) + n) / m
   */
  int c, x, n, m;

  Equation(int c, int x, int n, int m) : c(c), x(x), n(n), m(m) {}

  double evaluate() {
    return c * (std::sqrt(x) + n) / m;
  }

  Equation flipped() {
    return Equation(m * c, x, -n, std::pow(c, 2) * (x - std::pow(n, 2)));
  }

  Equation extract(int i) {
    return Equation(c, x, n - i * (m / c), m);
  }

  Equation normalized() {
    int factor = peutil::get_highest_common_factor(c, m);
    return Equation(c / factor, x, n, m / factor);
  }

  bool operator==(const Equation &other) const {
    return
      this->c == other.c && 
      this->x == other.x && 
      this->n == other.n && 
      this->m == other.m;
  }

  void print() {
    printf("%d(sqrt(%d) + %d) / %d\n", c, x, n, m);
  }
};

int get_period_length(int x) {
  int unit_part = std::floor(std::sqrt(x));
  Equation equation(1, x, -unit_part, 1);
  Equation initial_equation = equation;
  int period = 0;

  // printf("sqrt(%d) = %d + 1 / (", x, unit_part);
  
  printf("sqrt(%d) = [%d;(", x, unit_part);

  for (int i = 0; i < LOOP_LIMIT; i++) {
    equation = equation.flipped();
    equation = equation.normalized();

    if (i == 0) {
      initial_equation = equation;
    }

    int current_unit_part = std::floor(equation.evaluate());
    // printf("%d + 1 / (", current_unit_part);
    
    if (i != 0 && equation == initial_equation) {
      period = i;
      break;
    }

    printf("%d,", current_unit_part);

    equation = equation.extract(current_unit_part);
    equation = equation.normalized();
  }

  printf(")], period=%d\n", period);

  if (period == 0) {
    printf("Couldn't find period!\n");
  }

  return period;
}

int main() {
  int count = 0;
  for (int i = 2; i < LIMIT; i++) {
    if (std::pow(std::floor(std::sqrt(i)), 2) == i) {
      continue;
    }

    int period = get_period_length(i);

    if (period % 2 == 1) {
      count++;
    }
  }

  printf("Count: %d\n", count);
}


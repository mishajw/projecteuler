#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

constexpr int LIMIT = 1000;

struct Fraction {
  int numerator;
  int denominator;

  Fraction(int numerator, int denominator) :
    numerator(numerator), denominator(denominator) {}

  bool operator==(const Fraction &other) const {
    return this->numerator == other.numerator && this->denominator == other.denominator;
  }
};

int cycle_length(
    const Fraction &fraction, std::vector<Fraction> &seen_fractions) {

  auto found_fraction = std::find(seen_fractions.begin(), seen_fractions.end(), fraction);
  if (found_fraction != seen_fractions.end()) {
    return std::distance(found_fraction, seen_fractions.end());
  } else {
    seen_fractions.push_back(fraction);
  }

  int divisor = fraction.numerator / fraction.denominator;
  int remainder = fraction.numerator % fraction.denominator;
  

  return cycle_length(Fraction(remainder * 10, fraction.denominator), seen_fractions);
}

int main() {
  int max_length = 0;
  int max_i = 0;
  for (int i = 1; i < LIMIT; i++) {
    std::vector<Fraction> fractions;
    int length = cycle_length(Fraction(1, i), fractions);

    if (max_length < length) {
      max_length = length;
      max_i = i;
    }
  }

  printf("%d\n", max_i);
}


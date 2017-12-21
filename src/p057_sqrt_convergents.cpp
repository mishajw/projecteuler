#include <iostream>
#include <cmath>

typedef __uint128_t int_t;

int_t get_highest_common_factor(const int_t a, const int_t b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  const int_t quotient = a / b;
  const int_t remainder = a % b;
  // printf("a %ld, b %ld, q %ld, r %ld\n", a, b, quotient, remainder);

  return get_highest_common_factor(b, remainder);
}

struct Fraction {
  const int_t numerator, denominator;
  
  Fraction(int_t numerator, int_t denominator) :
    numerator(numerator), denominator(denominator) {}

  Fraction operator+(const int_t &other) const {
    return Fraction(
        this->numerator + (other * this->denominator),
        this->denominator);
  }

  Fraction operator*(const Fraction &other) const {
    return Fraction(
        this->numerator * this->numerator,
        this->denominator * this->denominator);
  }

  Fraction flip() const {
    return Fraction(this->denominator, this->numerator);
  }

  Fraction normalized() const {
    int_t factor = get_highest_common_factor(this->numerator, this->denominator);
    // printf("%ld\n", factor);
    return Fraction(this->numerator / factor, this->denominator / factor);
  }

  // std::string to_string() {
  //   return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
  // }
};

Fraction get_with_depth(int_t depth) {
  if (depth == 0) {
    return Fraction(1, 2);
  }

  Fraction f = get_with_depth(depth - 1) + 2;
  return f.flip().normalized();
}

int main() {
  int count = 0;
  for (unsigned int i = 0; i < 1000; i++) {
    printf("--- %d ---\n", i);
    Fraction f = (get_with_depth(i) + 1).normalized();
    // bool more_digits = false;
    //   std::floor(std::log(f.numerator) / std::log(10)) >
    //   std::floor(std::log(f.denominator) / std::log(10));
    printf("%d\n%lld %lld\n%lld %lld\n", more_digits, f.numerator, f.denominator);

    if (more_digits) {
      count++;
    }
  }

  printf("Count: %d\n", count);
}


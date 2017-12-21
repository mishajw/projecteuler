#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

class DigitNumber {
public:
  DigitNumber(const int x) {
    std::string x_str = std::to_string(x);
    std::reverse(x_str.begin(), x_str.end());
    for (const auto &c : x_str) {
      this->digits.push_back(int(c - '0'));
    }
  }

  DigitNumber operator+(const DigitNumber &other) const {
    assert(this->digits.size() == other.digits.size());

    std::vector<int> new_digits;
    int carry = 0;
    for (int i = 0; i < this->digits.size(); i++) {
      int current = this->digits[i] + other.digits[i] + carry;
      carry = std::floor(current / 10);
      new_digits.push_back(current % 10);
    }

    if (carry != 0) {
      new_digits.push_back(carry);
    }
    
    return DigitNumber(new_digits);
  }

  bool is_palindrome() const {
    for (int i = 0; i < this->digits.size() / 2; i++) {
      if (this->digits[i] != this->digits[this->digits.size() - i - 1]) {
        return false;
      }
    }

    return true;
  }

  DigitNumber reversed() const {
    std::vector<int> new_digits(this->digits);
    std::reverse(new_digits.begin(), new_digits.end());
    return DigitNumber(new_digits);
  }

  std::string to_string() const {
    std::string s;
    for (const auto &d : this->digits) {
      s += std::to_string(d);
    }
    std::reverse(s.begin(), s.end());
    return s;
  }

private:
  std::vector<int> digits;

  DigitNumber(std::vector<int> digits) : digits(digits) {}
};

bool is_lychrel(const DigitNumber &x, int iters_left) {
  if (iters_left <= 0) {
    return true;
  }

  const DigitNumber x_reversed = x.reversed();
  const DigitNumber possible_palindrome = x + x_reversed;
  const bool is_palindrome = possible_palindrome.is_palindrome();

  printf(
      "%d: (%d) %s + %s = %s\n",
      iters_left,
      is_palindrome,
      x.to_string().c_str(),
      x_reversed.to_string().c_str(),
      possible_palindrome.to_string().c_str());

  if (is_palindrome) {
    return false;
  } else {
    return is_lychrel(possible_palindrome, iters_left - 1);
  }
}

int main() {
  int count = 0;
  for (int i = 1; i <= 10000; i++) {
    printf("--- %d ---\n", i);
    if (is_lychrel(i, 50)) {
      count++;
    }
  }

  std::cout << count << std::endl;
}


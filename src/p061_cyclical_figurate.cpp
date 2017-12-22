#include <iostream>
#include <functional>
#include <vector>
#include <cassert>

static const int LOWER_LIMIT = 1000;
static const int UPPER_LIMIT = 10000;

int get_last_two_digits(int x) {
  return x % 100;
}

int get_first_two_digits(int x) {
  return x / 100;
}

std::vector<int> find(
    const std::vector<std::vector<int>> &function_numbers,
    std::vector<int> found_numbers,
    std::vector<int> explored_indices) {

  if (explored_indices.size() == function_numbers.size()) {
    assert(found_numbers.size() == function_numbers.size());

    if (get_first_two_digits(found_numbers[0]) ==
        get_last_two_digits(found_numbers[found_numbers.size() - 1])) {
      return found_numbers;
    }
  }

  int prefix = found_numbers.empty() ?
    -1 :
    get_last_two_digits(found_numbers[found_numbers.size() - 1]);

  for (int i = 0; i < function_numbers.size(); i++) {
    if (std::find(explored_indices.begin(), explored_indices.end(), i) != explored_indices.end()) {
      continue;
    }

    for (int j = 0; j < function_numbers[i].size(); j++) {
      int current_number = function_numbers[i][j];

      if (prefix == -1 || prefix == get_first_two_digits(current_number)) {
        std::vector<int> new_found_numbers = found_numbers;
        new_found_numbers.push_back(current_number);
        std::vector<int> new_explored_indices = explored_indices;
        new_explored_indices.push_back(i);

        std::vector<int> result = find(function_numbers, new_found_numbers, new_explored_indices);
        if (!result.empty()) {
          return result;
        }
      }
    }
  }

  return {};
}

int main() {
  auto functions = std::vector<std::function<int(int)>> {
    [](const int n) { return n * (n + 1) / 2; },
    [](const int n) { return n * n; },
    [](const int n) { return n * (3 * n - 1) / 2; },
    [](const int n) { return n * (2 * n - 1); },
    [](const int n) { return n * (5 * n - 3) / 2; },
    [](const int n) { return n * (3 * n - 2); },
  };

  std::vector<std::vector<int>> function_numbers(functions.size());
  for (int i = 0; i < functions.size(); i++) {
    int j = 0;
    while (true) {
      int value = functions[i](j++);
      if (value < LOWER_LIMIT) {
        continue;
      } else if (value > UPPER_LIMIT) {
        break;
      }

      function_numbers[i].push_back(value);
    }
  }

  std::vector found = find(function_numbers, {}, {});
  std::cout << "Found: ";
  int sum = 0;
  for (const auto &f : found) {
    std::cout << f << " ";
    sum += f;
  }
  std::cout << "sums to " << sum << std::endl;
}


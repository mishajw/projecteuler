#include <iostream>

#include "grid_search.cpp"

int main() {
  std::vector<std::vector<int>> matrix;
  get_matrix("inputs/p082_matrix.txt", matrix);

  std::vector<Point> starts;
  for (int i = 0; i < matrix.size(); i++) {
    starts.emplace_back(i, 0);
  }

  int least_path = find_least_path(
      matrix,
      starts,
      [&](const Point &p) {
        return p.y == matrix[p.x].size() - 1;
      },
      [&](const Point &p) {
        std::vector<Point> children;

        if (p.x < matrix.size() - 1) {
          children.emplace_back(p.x + 1, p.y);
        }

        if (p.x > 0) {
          children.emplace_back(p.x - 1, p.y);
        }

        if (p.y < matrix[p.x].size() - 1) {
          children.emplace_back(p.x, p.y + 1);
        }

        return children;
      });

  std::cout << least_path << std::endl;
}


#include <iostream>

#include "grid_search.cpp"

int main() {
  std::vector<std::vector<int>> matrix;
  get_matrix("inputs/p081_matrix.txt", matrix);

  int least_path = find_least_path(
      matrix,
      {Point(0, 0)},
      [&](const Point &p) {
        return p.x == matrix.size() - 1 && p.y == matrix[p.x].size() - 1;
      },
      [&](const Point &p) {
        std::vector<Point> children;

        if (p.x < matrix.size() - 1) {
          children.emplace_back(p.x + 1, p.y);
        }

        if (p.y < matrix[p.x].size() - 1) {
          children.emplace_back(p.x, p.y + 1);
        }

        return children;
      });

  std::cout << least_path << std::endl;
}


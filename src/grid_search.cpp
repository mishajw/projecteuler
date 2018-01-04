#include <fstream>
#include <queue>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <functional>

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}

  bool operator<(const Point &other) const {
    if (this->x == other.x) {
      return this->y < other.y;
    } else {
      return this->x < other.x;
    }
  }

  bool operator==(const Point &other) const {
    return this->x == other.x && this->y == other.y;
  }
};

void get_matrix(std::string path, std::vector<std::vector<int>> &matrix) {
  std::ifstream file;
  file.open(path);

  while (file.good()) {
    std::string line;
    std::getline(file, line);
    std::stringstream ss_line(line);

    if (line == "") {
      continue;
    }

    std::vector<int> row;
    while (ss_line.good()) {
      std::string cell;
      std::getline(ss_line, cell, ',');
      row.push_back(atoi(cell.c_str()));
    }
    matrix.push_back(row);
  }
}

int find_least_path(
    const std::vector<std::vector<int>> &matrix,
    std::vector<Point> starts,
    std::function<bool(const Point)> success_fn,
    std::function<std::vector<Point>(const Point)> get_children_fn) {

  std::map<Point, int> evaluations;
  const auto evaluations_comp_fn = [&](const Point &a, const Point &b) {
    auto find_a_iter = evaluations.find(a);
    auto find_b_iter = evaluations.find(b);

    if (find_a_iter == evaluations.end() && find_b_iter == evaluations.end()) {
      return a < b;
    } else if (find_a_iter == evaluations.end()) {
      return true;
    } else if (find_b_iter == evaluations.end()) {
      return false;
    } else {
      return find_a_iter->second > find_b_iter->second;
    }
  };
  const auto add_evaluation_fn = [&](const Point &p, int evaluation) {
    auto find_iter = evaluations.find(p);
    if (find_iter == evaluations.end()) {
      evaluations[p] = evaluation;
    } else {
      find_iter->second = std::min(evaluation, find_iter->second);
    }
  };

  std::priority_queue<
    Point,
    std::vector<Point>,
    decltype(evaluations_comp_fn)> to_explore(evaluations_comp_fn);

  std::set<Point> explored;

  for (const auto &p : starts) {
    to_explore.push(p);
    evaluations[p] = matrix[p.x][p.y];
  }

  while (!to_explore.empty()) {
    Point current = to_explore.top();
    int current_evaluation = evaluations[current];
    to_explore.pop();
    if (explored.find(current) == explored.end()) {
      explored.insert(current);
    } else {
      continue;
    }

    if (success_fn(current)) {
      return current_evaluation;
    }

    for (const auto &c : get_children_fn(current)) {
      to_explore.push(c);
      add_evaluation_fn(c, current_evaluation + matrix[c.x][c.y]);
    }
  }

  return 0;
}


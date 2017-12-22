#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#ifndef PATH
#define PATH "inputs/p018_max_path_sum.txt"
#endif

void parse_numbers(std::string numbers_str, std::vector<int> &numbers) {
  std::istringstream numbers_ss(numbers_str);

  for (std::string s; numbers_ss >> s;) {
    numbers.push_back(atoi(s.c_str()));
  }
}

void get_graph(std::vector<std::vector<int>> &graph) {
  std::ifstream file;
  file.open(PATH);

  while (file.good()) {
    std::string line;
    std::vector<int> numbers;

    std::getline(file, line);
    parse_numbers(line, numbers);

    if (numbers.size() > 0) {
      graph.push_back(numbers);
    }
  }
}

int main() {
  std::vector<std::vector<int>> graph;
  get_graph(graph);
  int last_index = graph.size() - 1;

  std::vector<std::vector<int>> best_score;
  for (const auto &l : graph) {
    best_score.emplace_back(l.size());
  }
  
  for (int i = 0; i < graph[last_index].size(); i++) {
    best_score[last_index][i] = graph[last_index][i];
  }

  for (int i = last_index - 1; i >= 0; i--) {
    for (int j = 0; j < graph[i].size(); j++) {
      int left_child = best_score[i + 1][j];
      int right_child = best_score[i + 1][j + 1];

      best_score[i][j] = std::max(left_child, right_child) + graph[i][j];
    }
  }

  printf("Best Scores:\n");
  for (const auto &line : best_score) {
    std::cout << line.size() << ": ";
    for (const auto &i : line) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  printf("Solution: %d\n", best_score[0][0]);
}


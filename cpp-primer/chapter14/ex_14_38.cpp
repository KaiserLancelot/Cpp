//
// Created by kaiser on 18-12-23.
//

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Fun {
 public:
  explicit Fun(std::size_t sz) : sz_{sz} {}
  bool operator()(const std::string &s) { return std::size(s) == sz_; }

 private:
  std::size_t sz_{};
};

int main() {
  std::ifstream ifs{"story"};
  if (!ifs) {
    std::cerr << "can not open file\n";
    std::exit(EXIT_FAILURE);
  }

  std::string word;
  std::vector<std::string> vs;

  while (ifs >> word) {
    vs.push_back(word);
  }

  for (std::size_t i{1}; i < 10; ++i) {
    std::cout << std::count_if(std::begin(vs), std::end(vs), Fun{i}) << '\n';
  }
}
//
// Created by kaiser on 18-12-3.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vs;
  std::string line;
  std::ifstream ifs{"book"};

  if (!ifs) {
    std::cerr << "can't open file\n";
    return EXIT_FAILURE;
  }

  while (std::getline(ifs, line)) {
    vs.push_back(line);
  }

  for (const auto& str : vs) {
    std::istringstream iss{str};
    std::string word;
    while (iss >> word) {
      std::cout << word << '\n';
    }
  }
}

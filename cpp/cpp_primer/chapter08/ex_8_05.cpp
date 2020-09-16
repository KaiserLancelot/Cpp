//
// Created by kaiser on 18-12-3.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream ifs{"book"};

  if (!ifs) {
    std::cerr << "can't open file\n";
    return EXIT_FAILURE;
  }

  std::string word;
  std::vector<std::string> vs;

  while (ifs >> word) {
    vs.push_back(word);
  }

  for (const auto& s : vs) {
    std::cout << s << '\n';
  }
}

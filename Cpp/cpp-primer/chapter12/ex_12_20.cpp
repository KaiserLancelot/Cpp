//
// Created by kaiser on 18-12-19.
//

#include "ex_12_19.h"

#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream ifs{"book"};
  std::string line;
  StrBlob sb;

  while (std::getline(ifs, line)) {
    sb.push_back(line);
  }

  for (auto begin{sb.begin()}; begin.not_equal(sb.end()); begin.incr()) {
    std::cout << begin.deref() << '\n';
  }
}

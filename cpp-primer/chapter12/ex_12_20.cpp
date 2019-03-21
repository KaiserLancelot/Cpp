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
    sb.PushBack(line);
  }

  for (auto begin{sb.begin()}; begin.NotEqual(sb.end()); begin.Incr()) {
    std::cout << begin.Deref() << '\n';
  }
}
//
// Created by kaiser on 19-3-16.
//

#include <iostream>

#include "ex_19_02.h"

int main() {
  StrVec c{"a", "b", "c"};

  std::cout << "The vector holds: ";
  for (const auto &el : c) {
    std::cout << el << ' ';
  }
  std::cout << '\n';

  c.Resize(5);
  std::cout << "After resize up to 5: ";
  for (const auto &el : c) {
    std::cout << el << ' ';
  }
  std::cout << '\n';

  c.Resize(2);
  std::cout << "After resize down to 2: ";
  for (const auto &el : c) {
    std::cout << el << ' ';
  }
  std::cout << '\n';
}
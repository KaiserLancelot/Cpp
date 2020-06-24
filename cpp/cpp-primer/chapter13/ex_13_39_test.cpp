//
// Created by kaiser on 18-12-20.
//

#include "ex_13_39.h"

#include <iostream>

int main() {
  StrVec c;
  c.PushBack("a");
  c.PushBack("b");
  c.PushBack("c");

  std::cout << "The vector holds: ";
  for (const auto &el : c)
    std::cout << el << ' ';
  std::cout << '\n';

  c.Resize(5);
  std::cout << "After resize up to 5: ";
  for (const auto &el : c)
    std::cout << el << ' ';
  std::cout << '\n';

  c.Resize(2);
  std::cout << "After resize down to 2: ";
  for (const auto &el : c)
    std::cout << el << ' ';
  std::cout << '\n';
}

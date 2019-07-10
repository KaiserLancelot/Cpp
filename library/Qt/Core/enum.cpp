//
// Created by kaiser on 19-3-20.
//

#include "enum.h"

#include <iostream>

int main() {
  auto test{Enum::kTest};
  std::cout << ToString(test) << '\n';

  auto test2{Enum2::kTest2};
  std::cout << ToString(test2) << '\n';
}

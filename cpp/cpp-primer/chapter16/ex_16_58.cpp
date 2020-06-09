//
// Created by kaiser on 19-3-6.
//

#include "ex_16_58.h"

#include <iostream>
#include <string>

int main() {
  Vec<std::string> vec;
  vec.EmplaceBack(10, 'c');
  std::cout << vec[0] << '\n';
}
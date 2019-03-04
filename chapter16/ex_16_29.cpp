//
// Created by kaiser on 19-3-4.
//

#include "ex_16_29.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  Blob<int> b(v.begin(), v.end());
  for (auto i : b) {
    std::cout << i << '\n';
  }
}
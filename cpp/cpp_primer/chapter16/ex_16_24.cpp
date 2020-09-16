//
// Created by kaiser on 19-3-4.
//

#include <iostream>
#include <vector>

#include "ex_16_24.h"

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  Blob<int> b(v.begin(), v.end());
  for (auto i : b) {
    std::cout << i << '\n';
  }
}

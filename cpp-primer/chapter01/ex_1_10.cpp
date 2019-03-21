//
// Created by kaiser on 18-11-20.
//

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t val{10};

  while (val >= 0) {
    std::cout << val << ' ';
    --val;
  }
  std::cout << '\n';
}
//
// Created by kaiser on 18-11-27.
//

#include <cstdint>
#include <iostream>
#include <stdexcept>

int main() {
  std::int32_t v1, v2;
  std::cin >> v1 >> v2;

  if (v2 == 0) {
    throw std::runtime_error("divisor is 0");
  }
  std::cout << v1 / v2 << '\n';
}

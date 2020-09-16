//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

std::int32_t abs(std::int32_t val) { return val >= 0 ? val : -val; }

int main() {
  std::cout << abs(2) << '\n';
  std::cout << abs(-2) << '\n';
}

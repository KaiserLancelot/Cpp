//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

std::int32_t CountCalls() {
  static std::int32_t count{};
  return count++;
}

int main() {
  for (std::int32_t i{0}; i < 10; ++i) {
    std::cout << CountCalls() << '\n';
  }
}

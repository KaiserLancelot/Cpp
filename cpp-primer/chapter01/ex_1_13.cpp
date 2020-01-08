//
// Created by kaiser on 18-11-20.
//

#include <cstdint>
#include <iostream>

int main() {
  // ex 1.9
  std::int32_t sum{};

  for (std::int32_t val{50}; val <= 100; ++val) {
    sum += val;
  }

  std::cout << sum << '\n';

  // ex 1.10
  for (std::int32_t val{10}; val >= 0; --val) {
    std::cout << val << ' ';
  }
  std::cout << '\n';

  // ex1.11
  std::int32_t v1, v2;
  std::cin >> v1 >> v2;

  for (; v1 <= v2; ++v1) {
    std::cout << v1 << ' ';
  }
  std::cout << '\n';
}

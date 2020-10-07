#include <cstdint>
#include <iostream>

int main() {
  std::int32_t sum{};

  for (std::int32_t i{-100}; i <= 100; ++i) {
    sum += i;
  }

  std::cout << sum << '\n';
}
